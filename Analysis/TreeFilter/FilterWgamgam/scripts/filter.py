
#************************************************************************************
#
# filter.py
#
# Author : Josh Kunkle  (jkunkle@cern.ch)
#

import sys
import os
import re
import math
import subprocess
import multiprocessing
import inspect
import ROOT
from array import array

import core

options = core.ParseArgs()

#*************************************
#Some global definitions
#*************************************

workarea = os.getenv('WorkArea')
if workarea is None :
    print 'Did not locate WorkArea environment variable.  Please set it to the root of the package'
    sys.exit(-1)

def_file_name = workarea + '/FilterWgamgam/FilterWgamgam/BranchDefs.h'
header_file_name = workarea + '/FilterWgamgam/FilterWgamgam/BranchInit.h'
source_file_name = workarea + '/FilterWgamgam/src/BranchInit.cxx'

def main(**kwargs) :

    assert options.files is not None or options.filesDir is not None , 'Must provide a file list via --files or a search directory via --filesDir'
    assert options.outputDir is not None, 'Must provide an output directory via --outputDir'
    assert options.treeName is not None, 'Must provide a tree name via --treeName'

    input_files = []
    if options.files is not None :
        input_files = options.files.split(',')
    elif options.filesDir is not None :
        input_files = core.collect_input_files( options.filesDir )

    # if output file name is not given grab the name from one of the input files
    if options.outputFile is None :
        options.outputFile = input_files[0].split('/')[-1]

    testfile = ROOT.TFile.Open( input_files[0] )
    testtree = testfile.Get( options.treeName )

    branches = core.get_branch_mapping(testtree)

    ImportedModule = core.import_module( options.module )

    remove_filter = []
    keep_filter = []
    if hasattr(ImportedModule, 'get_remove_filter') :
        remove_filter = ImportedModule.get_remove_filter()
    if hasattr(ImportedModule, 'get_keep_filter') :
        keep_filter = ImportedModule.get_keep_filter()

    if not options.noCompile :
        # by default keep all branches
        all_branches = [ br['name'] for br in branches ]
        branches_to_keep =  list(all_branches)
        if options.enableKeepFilter :
            #only keep these branches.  Reset the keep list
            branches_to_keep = []
            for kregex in keep_filter :
                matches = [ re.match( kregex, br['name'] ) for br in branches ]
                successful_matches = filter( lambda x : x is not None, matches )
                branches_to_keep += [ x.group(0) for x in successful_matches]

        if options.enableRemoveFilter :
            for rregex in remove_filter :
                matches = [ re.match( rregex, br['name'] ) for br in branches ]
                successful_matches = filter( lambda x : x is not None, matches )
                branches_to_remove = [ x.group(0) for x in successful_matches]
                print 'rm branches'
                print branches_to_remove
                branches_to_keep = list( set(branches_to_keep) - set(branches_to_remove) )
            
        if options.enableKeepFilter :
            print 'Will keep %d branches from output file : ' %len(branches_to_keep)
            print '\n'.join(branches_to_keep)
        elif options.enableRemoveFilter :
            print 'Will remove %d branches from output file : ' %( len(branches) - len(branches_to_keep))
            print '\n'.join( list( set( all_branches ) - set( branches_to_keep ) ) )

        # Write the c++ files having the branch definitions and 
        # SetBranchAddress calls
        write_branchdef_file(def_file_name, branches, branches_to_keep )

        write_source_file(source_file_name, header_file_name, branches, branches_to_keep )

        # compile
        proc = subprocess.Popen(['make'])
        retcode = proc.wait()
        
        # abort if non-zero return code
        if retcode :
            print 'Compilation failed.  Will not run'
            return

    # Stop here if not running
    if options.noRun :
        return

    # Get the path of the executable.  First try the
    # WorkArea environment variable which will give
    # an absolute path.  If that doesn't exist, try
    # Using the path of this script to get an
    # absolute path
    exe_path = None

    if workarea is not None :
        exe_path = '%s/FilterWgamgam/RunAnalysis' %workarea

    if exe_path is None :
        print ('Did not find executable through the WorkArea environment variable. '
               'Next try using the absolute path of this script' )

        script_loc = os.path.realpath(__file__)
        exe_path = '%s/../RunAnalysis' %os.path.dirname(script_loc)

    if not os.path.isfile(exe_path) :
        print ('ERROR - cannot locate path of executable file.  The path '
               'was determined from the path of this script.  Either set the '
               'WorkArea environment variable to the directory where HWWAnalysisCode '
               'resides, or keep this script in the same location as the executable' )
        sys.exit(-1)

    run_commands = []

    alg_list = []
    ImportedModule.config_analysis(alg_list)

    # --------------------------
    # Handle file splitting.
    # Be default nsplit = 1.  In this case the default 
    # behavior is only one job running over all
    # events
    # --------------------------

    file_evt_list = get_file_evt_map( input_files, options.nsplit, options.treeName )

    if options.nproc > 1 : #multiprocessing!

        nFilesPerJob = int(math.ceil(float(len(input_files))/nsplit))
        if nFilesPerJob == 0 :
            nFilesPerJob = 1
        # split into sub-lists based on the number of jobs.  last job may have fewer files
        jobs = [file_evt_list[i:i+nFilesPerJob] for i in range(0, len(input_files), nFilesPerJob)]

        configs = []
        commands = []
        for idx, file_split in enumerate(jobs) :
            jobid = 'Job_%04d' %idx
            outputDir = options.outputDir + '/' + jobid
            conf_file = '%s/%s_%s.%s' %(outputDir, options.confFileName.split('.')[0], jobid, '.'.join(options.confFileName.split('.')[1:]))
            if not os.path.isdir( outputDir ) :
                os.makedirs( outputDir )
            
            write_config(alg_list, conf_file, options.treeName, outputDir, options.outputFile, file_split, options.storagePath )
            commands.append( make_exe_command( exe_path, conf_file ) )

        pool = multiprocessing.Pool(options.nproc)
        pool.map( os.system, commands )

    else :

        print file_evt_list

        output_file = '%s/%s' %(options.outputDir, options.outputFile )
        if not os.path.isdir( options.outputDir ) and options.outputDir.count('root://') != -1 :
            os.makedirs( options.outputDir )
        write_config( alg_list, options.confFileName, options.treeName, options.outputDir, options.outputFile, file_evt_list, options.storagePath ) 
        command = make_exe_command( exe_path, options.confFileName )

        print command
        os.system(command)

def get_file_evt_map( input_files, nsplit, treeName ) :

    # first split by the number of files
    nFilesPerSplit = int(math.ceil(float(len(input_files))/nsplit))
    if nFilesPerSplit == 0 :
        nFilesPerSplit = 1
    # split into sub-lists based on the number of jobs.  last job may have fewer files

    split_files = [input_files[i:i+nFilesPerSplit] for i in range(0, len(input_files), nFilesPerSplit)]
    print 'SPLIT_FILES'
    print split_files

    # now split by events.  If no further splitting is requested
    # then each file runs over the full set of events
    files_evtsplit = []

    # determine how many times to split each file.  Do this by 
    # adding a split to each file until the number
    # of splits is achieved
    files_nsplit = [ 1 ]*len(split_files)
    n_addtl_split = nsplit - len(split_files) 
    print 'N_ADDTL_SPLIT'
    print n_addtl_split
    files_idx = 0
    for sp in range(0, n_addtl_split ) :
        files_nsplit[files_idx] += 1

        # increment the index
        # if we're at the end of the list go back to the beginning
        files_idx += 1
        if files_idx >= len(files_nsplit) :
            files_idx = 0


    print 'FILES_NSPLIT'
    print files_nsplit

    #get the total number of events for each file
    files_nevt = [0]*len(split_files)
    for idx, files in enumerate(split_files) :
        for file in files :
            tmp = ROOT.TFile.Open(file)
            tree = tmp.Get(treeName)
            files_nevt[idx] += tree.GetEntries()
            tmp.Close()

    # for each file get the range to use
    for files, nsplit, totevt in zip(split_files, files_nsplit, files_nevt) :

        splitlist = []
        split_base = int(totevt)/int(nsplit)
        prev_val = 0
        for splitidx in range(0, nsplit) :
            # at the last entry the upper limit is the number of events
            # this prevents any missed events
            if splitidx == nsplit-1 :
                splitlist.append( (prev_val, totevt) )
            else :
                splitlist.append( (prev_val, prev_val+split_base) )

            prev_val = prev_val + split_base

        files_evtsplit.append(splitlist)

    assert len(files_evtsplit) == len(split_files), 'ERROR - size mismatch.  This should not happen!'

    split_files_evt_match = []
    for flist, evtsplit in zip(split_files, files_evtsplit) :
        split_files_evt_match.append( (flist, evtsplit ))

    return split_files_evt_match
    
def write_config( alg_list, filename, treeName, outputDir, outputFile, files_list, storage_path ) :

    cfile = open( filename, 'w')

    # first write header information
    jobid = 0
    file_line = 'files : '
    for flist, evtlist in files_list :
        file_line += flist.__str__().replace('\'','').replace(' ', '')
        file_line += '['
        for min, max in evtlist :
            file_line += '%d:(%d-%d),' %( jobid, min, max )
            jobid += 1
        file_line.rstrip(',')
        file_line += '];'

    cfile.write( '%s\n' %file_line )
    cfile.write( 'treeName : %s\n' %( treeName ) )
    cfile.write( 'outputDir : %s\n' %( outputDir ) )
    cfile.write( 'outputFile : %s\n' %( outputFile ) )
    if storage_path != 'None' :
        cfile.write( 'storagePath : %s\n' %storage_path )

    cfile.write( '__Modules__\n' )

    for alg in alg_list :
        conf_string = alg.name + ' : '
        for name, val in inspect.getmembers(alg) :

            if name[0] == '_' : continue

            if name[0:3] == 'cut' :
                # check if this cut is inverted
                inv_str = ''
                if alg.is_inverted(name) :
                    inv_str = '!'
                conf_string += '%s %s[%s] ; ' %(name, inv_str, val)

        cfile.write(conf_string + '\n')

    cfile.close()

def make_exe_command( exe_path, conf_file ) :

    command = [exe_path,
               ' --conf_file %s' %conf_file,
              ]

    return ' '.join(command)


def write_branchdef_file( name, branches, keep_branches=[] ) :

    branch_header = open(name, 'w')
    branch_header.write('#ifndef BRANCHDEFS_H\n')
    branch_header.write('#define BRANCHDEFS_H\n')
    branch_header.write('#include "TTree.h"\n')
    branch_header.write('#include <vector>\n')

    branch_header.write('//Define variables as extern below and declare them in the .cxx file to avoid multiple definitions\n')

    branch_header.write('namespace IN {\n');

    for conf in branches :

        name = conf['name']

        # declare the variable differently for a vector
        if conf['type'].count('vector') :
            modtype = conf['type'].replace('vector', 'std::vector')
            file_entry = ' extern %s\t\t\t\t*%s;\n' %(modtype, name)
        else :
            file_entry = ' extern %s\t\t\t\t%s%s;\n' %(conf['type'], name, conf['arrayStr'])

        branch_header.write(file_entry)

    branch_header.write('};\n');

    branch_header.write('namespace OUT {\n');

    for conf in branches :

        name = conf['name']

        if name not in keep_branches :
            continue

        if conf['type'].count('vector') :
            modtype = conf['type'].replace('vector', 'std::vector')
            file_entry = ' extern %s\t\t\t\t*%s;\n' %(modtype, name)
        else :
            file_entry = ' extern %s\t\t\t\t%s%s;\n' %(conf['type'], name, conf['arrayStr'])

        branch_header.write(file_entry)

    branch_header.write('};\n');
    branch_header.write('#endif\n')

    branch_header.close()


def write_source_file(source_file_name, header_file_name, branches, keep_branches=[]) :

    branch_header = open(header_file_name, 'w')
    branch_header.write('#ifndef BRANCHINIT_H\n')
    branch_header.write('#define BRANCHINIT_H\n')
    branch_header.write('#include "TTree.h"\n')
    branch_header.write('#include "TChain.h"\n')
    branch_header.write('void InitINTree( TChain * tree );\n')
    branch_header.write('void InitOUTTree( TTree * tree );\n')
    branch_header.write('void CopyInputVarsToOutput();\n')
    branch_header.write('#endif\n')
    branch_header.close()

    branch_setting = open(source_file_name, 'w')
    branch_setting.write('#include <algorithm>\n')
    branch_setting.write('#include <iostream>\n')
    branch_setting.write('#include "TTree.h"\n')
    branch_setting.write('#include "TChain.h"\n')
    branch_setting.write('#include "FilterWgamgam/BranchInit.h"\n')
    branch_setting.write('#include "FilterWgamgam/BranchDefs.h"\n\n')

    branch_setting.write('namespace IN {\n');
    for conf in branches :

        name = conf['name']

        # declare the variable differently for a vector
        if conf['type'].count('vector') :
            modtype = conf['type'].replace('vector', 'std::vector')
            file_entry = ' %s\t\t\t\t*%s;\n' %(modtype, name)
        else :
            file_entry = ' %s\t\t\t\t%s%s;\n' %(conf['type'], name, conf['arrayStr'])

        branch_setting.write(file_entry)

    branch_setting.write('};\n');

    branch_setting.write('namespace OUT {\n');

    for conf in branches :

        name = conf['name']

        if name not in keep_branches :
            continue

        if conf['type'].count('vector') :
            modtype = conf['type'].replace('vector', 'std::vector')
            file_entry = ' %s\t\t\t\t*%s;\n' %(modtype, name)
        else :
            file_entry = ' %s\t\t\t\t%s%s;\n' %(conf['type'], name, conf['arrayStr'])

        branch_setting.write(file_entry)

    branch_setting.write('};\n');

    branch_setting.write('void InitINTree( TChain * tree) {\n\n')
    counter = -1
    
    for conf in branches :

        name = conf['name']

        counter += 1
        # might need to fix this for variable length arrays
        set_line = '  tree->SetBranchAddress("%s", &IN::%s);\n' %(name, name)
        #if type.count('vector') :
        #else :
        #    set_line = '  tree->SetBranchAddress("%s", &IN::%s);\n' %(name, name)

        branch_setting.write(set_line)

    branch_setting.write('};\n\n')

    branch_setting.write('void InitOUTTree( TTree * tree ) {\n')

    for conf in branches :

        name = conf['name']

        if name not in keep_branches :
            continue

        if conf['type'].count('vector') :
            set_line = '  tree->Branch("%s", &OUT::%s);\n' %(name, name)
        else :
            set_line = '  tree->Branch("%s", &OUT::%s, "%s");\n' %(name, name, conf['leafEntry'])

        branch_setting.write(set_line)

    branch_setting.write('}\n')

    branch_setting.write('void CopyInputVarsToOutput() {\n')

    for conf in branches :

        name = conf['name']

        if name not in keep_branches :
            continue
        if conf['type'].count('vector') :
            set_line = '  OUT::%s = IN::%s;\n' %(name, name)
            branch_setting.write(set_line)
        else :
            if conf['totSize'] > 1 :
                #set_line = '  memcpy(OUT::%s, IN::%s, %d);\n' %(name, name, conf['totSize'])
                if conf['totSize'] < 200 :
                    set_line = '  std::copy(IN::%s, IN::%s+%d, OUT::%s);\n ' %(name, name, conf['totSize'], name)
                    if options.debugCode :
                        set_line = ' std::cout << "Attempt to copy variable %s" << std::endl;\n ' %name + set_line
                else :
                    sizes = conf['sizeEntries']
                    set_line = ''
                    for array_val in generate_array_loop( sizes ) :
                        set_line += '  OUT::%s%s = IN::%s%s;\n ' %(name, array_val, name, array_val)


                    # code crashes when copying large arrays the only solution I've found is to do it manually

                branch_setting.write(set_line)
            else :
                set_line = '  OUT::%s = IN::%s;\n' %(name, name)
                branch_setting.write(set_line)


    branch_setting.write('}\n')

    branch_setting.close()


def generate_array_loop( array_sizes ) :

    def _increment( array_val, array_sizes, depth ) :

        if depth == -1 :
            return array_val
        if array_val[depth] == ( array_sizes[depth] - 1 ) : #at the last value, reset to 0 and increment the previous
            array_val[depth] = 0
            _increment( array_val, array_sizes, depth-1)
        else :
            array_val[depth] += 1

        return array_val


    n_depth = len(array_sizes)
    array_val = [0]*n_depth

    total_size = reduce(lambda x, y: x*y, array_sizes)
    for idx in range(0, total_size) :
        yield '[' + ']['.join([str(x) for x in array_val]) + ']'

        _increment( array_val, array_sizes, n_depth-1 );



class Filter :

    def __init__(self, name) :
        self.invert_list = []
        self.name = name

    def invert(self, name) :
        self.invert_list.append(name)

    def is_inverted(self, name) :
        return name in self.invert_list



if __name__ == '__main__' :
    main()
