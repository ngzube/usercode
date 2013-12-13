import os

base_muon = '/eos/cms/store/user/abelloni/Wgamgam/FilteredSamplesDec13'
base_elec = '/eos/cms/store/user/jkunkle/Wgamgam/FilteredSamplesDec13'
base_data = '/eos/cms/store/group/phys_smp/ggNtuples/data'
base_mc2 = '/eos/cms/store/group/phys_smp/ggNtuples/mc'
base_mc = '/eos/cms/store/group/phys_egamma/cmkuo'

jobs = [
        #(base_muon, 'job_muon_2012a_Jan22rereco'),
        #(base_muon, 'job_muon_2012b_Jan22rereco'),
        #(base_muon, 'job_muon_2012c_Jan22rereco'),
        #(base_muon, 'job_muon_2012d_Jan22rereco'),
        #(base_elec, 'job_electron_2012a_Jan22rereco'),
        #(base_elec, 'job_electron_2012b_Jan22rereco'),
        #(base_data, 'job_electron_2012c_Jan2012rereco', 200),
        #(base_data, 'job_electron_2012d_Jan22rereco', 200),
        #(base_mc, 'job_summer12_DiPhotonBorn_Pt-10To25', 10),
        #(base_mc2, 'job_summer12_DYJetsToLL', 100 ),
        ##(base_mc, 'job_summer12_TTH_100'),
        ##(base_mc, 'job_summer12_TTH_105'),
        ##(base_mc, 'job_summer12_TTH_110'),
        ##(base_mc, 'job_summer12_TTH_115'),
        ##(base_mc, 'job_summer12_TTH_120'),
        ##(base_mc, 'job_summer12_TTH_121'),
        ##(base_mc, 'job_summer12_TTH_123'),
        ##(base_mc, 'job_summer12_TTH_124'),
        ##(base_mc, 'job_summer12_TTH_125'),
        ##(base_mc, 'job_summer12_TTH_126'),
        ##(base_mc, 'job_summer12_TTH_127'),
        ##(base_mc, 'job_summer12_TTH_128'),
        ##(base_mc, 'job_summer12_TTH_130'),
        ##(base_mc, 'job_summer12_TTH_135'),
        ##(base_mc, 'job_summer12_TTH_140'),
        ##(base_mc, 'job_summer12_TTH_145'),
        ##(base_mc, 'job_summer12_TTH_150'),
        ##(base_mc, 'job_summer12_VBF_100'),
        ##(base_mc, 'job_summer12_VBF_105'),
        ##(base_mc, 'job_summer12_VBF_110'),
        ##(base_mc, 'job_summer12_VBF_115'),
        ##(base_mc, 'job_summer12_VBF_120'),
        ##(base_mc, 'job_summer12_VBF_121'),
        ##(base_mc, 'job_summer12_VBF_123'),
        ##(base_mc, 'job_summer12_VBF_124'),
        ##(base_mc, 'job_summer12_VBF_125'),
        ##(base_mc, 'job_summer12_VBF_126'),
        ##(base_mc, 'job_summer12_VBF_127'),
        ##(base_mc, 'job_summer12_VBF_128'),
        ##(base_mc, 'job_summer12_VBF_130'),
        ##(base_mc, 'job_summer12_VBF_135'),
        ##(base_mc, 'job_summer12_VBF_140'),
        ##(base_mc, 'job_summer12_VBF_145'),
        ##(base_mc, 'job_summer12_VBF_150'),
        #(base_mc, 'job_summer12_WAA_ISR', 10),
        ##(base_mc, 'job_summer12_WH_ZH_100'),
        ##(base_mc, 'job_summer12_WH_ZH_105'),
        ##(base_mc, 'job_summer12_WH_ZH_110'),
        ##(base_mc, 'job_summer12_WH_ZH_115'),
        ##(base_mc, 'job_summer12_WH_ZH_120'),
        ##(base_mc, 'job_summer12_WH_ZH_121'),
        ##(base_mc, 'job_summer12_WH_ZH_123'),
        ##(base_mc, 'job_summer12_WH_ZH_124'),
        #(base_mc, 'job_summer12_WH_ZH_125', 10),
        ##(base_mc, 'job_summer12_WH_ZH_126'),
        ##(base_mc, 'job_summer12_WH_ZH_128'),
        ##(base_mc, 'job_summer12_WH_ZH_130'),
        ##(base_mc, 'job_summer12_WH_ZH_135'),
        ##(base_mc, 'job_summer12_WH_ZH_140'),
        ##(base_mc, 'job_summer12_WH_ZH_145'),
        ##(base_mc, 'job_summer12_WH_ZH_150'),
        #(base_mc, 'job_summer12_WWW', 10),
        #(base_mc, 'job_summer12_WWZ', 10),
        #(base_mc, 'job_summer12_WW_2l2nu', 10),
        #(base_mc, 'job_summer12_WWg', 10),
        #(base_mc, 'job_summer12_WZZ', 10),
        (base_mc, 'job_summer12_WZ_2l2q', 10),
        #(base_mc, 'job_summer12_WZ_3lnu', 10),
        #(base_mc, 'job_summer12_Wg', 10),
        #(base_mc, 'job_summer12_Wgg_FSR', 10),
        #(base_mc, 'job_summer12_Wjets', 10),
        #(base_mc, 'job_summer12_ZZZ', 10),
        #(base_mc, 'job_summer12_ZZ_2e2mu', 10),
        #(base_mc, 'job_summer12_ZZ_2e2tau', 10),
        #(base_mc, 'job_summer12_ZZ_2l2nu', 10),
        #(base_mc, 'job_summer12_ZZ_2l2q', 10),
        #(base_mc, 'job_summer12_ZZ_2mu2tau', 10),
        #(base_mc, 'job_summer12_ZZ_2q2nu', 10),
        #(base_mc, 'job_summer12_ZZ_4e', 10),
        #(base_mc, 'job_summer12_ZZ_4mu', 10),
        #(base_mc, 'job_summer12_ZZ_4tau', 10),
        #(base_mc, 'job_summer12_Zg', 10),
        #(base_mc, 'job_summer12_diphoton_box_10to25', 10),
        #(base_mc, 'job_summer12_diphoton_box_250toInf', 10),
        #(base_mc, 'job_summer12_diphoton_box_25to250', 10),
        ##(base_mc, 'job_summer12_ggH_100'),
        ##(base_mc, 'job_summer12_ggH_105'),
        ##(base_mc, 'job_summer12_ggH_110'),
        ##(base_mc, 'job_summer12_ggH_115'),
        ##(base_mc, 'job_summer12_ggH_120'),
        ##(base_mc, 'job_summer12_ggH_121'),
        ##(base_mc, 'job_summer12_ggH_123'),
        ##(base_mc, 'job_summer12_ggH_124'),
        ##(base_mc, 'job_summer12_ggH_125'),
        ##(base_mc, 'job_summer12_ggH_126'),
        ##(base_mc, 'job_summer12_ggH_127'),
        ##(base_mc, 'job_summer12_ggH_128'),
        ##(base_mc, 'job_summer12_ggH_129'),
        ##(base_mc, 'job_summer12_ggH_130'),
        ##(base_mc, 'job_summer12_ggH_135'),
        ##(base_mc, 'job_summer12_ggH_140'),
        ##(base_mc, 'job_summer12_ggH_145'),
        ##(base_mc, 'job_summer12_ggH_150'),
        ##(base_mc, 'job_summer12_ggH_155'),
        ##(base_mc, 'job_summer12_ggH_160'),
        #(base_mc, 'job_summer12_ggZZ_2l2l', 10),
        #(base_mc, 'job_summer12_ggZZ_4l', 10),
        #(base_mc, 'job_summer12_t_s', 20),
        #(base_mc, 'job_summer12_t_t', 20),
        #(base_mc, 'job_summer12_t_tW', 20),
        #(base_mc, 'job_summer12_tbar_s', 20),
        #(base_mc, 'job_summer12_tbar_t', 20),
        #(base_mc, 'job_summer12_tbar_tW', 20),
        #(base_mc, 'job_summer12_ttW', 20),
        #(base_mc, 'job_summer12_ttZ', 20),
        #(base_mc, 'job_summer12_ttg', 20),
        #(base_mc, 'job_summer12_ttinclusive', 100),
        #(base_mc, 'job_summer12_ttjets_1l', 100),
        #(base_mc, 'job_summer12_ttjets_2l', 100),

        ##(base_mc, 'job_summer12_LNuGG_FSR'),
        ##(base_mc, 'job_summer12_LNuGG_ISR'),
        ##(base_mc, 'job_summer12_WJetsToLNu1'),
        ##(base_mc, 'job_summer12_WJetsToLNu2'),
        ##(base_mc, 'job_summer12_WWW'),
        ##(base_mc, 'job_summer12_WWZ'),
        ##(base_mc, 'job_summer12_WW_2l2nu'),
        ##(base_mc, 'job_summer12_WZZ'),
        ##(base_mc, 'job_summer12_WZ_2l2q'),
        ##(base_mc, 'job_summer12_WZ_3lnu'),
        ##(base_mc, 'job_summer12_Wg'),
        ##(base_mc, 'job_summer12_ZZZ'),
        ##(base_mc, 'job_summer12_ZZ_2e2mu'),
        ##(base_mc, 'job_summer12_ZZ_2e2tau'),
        ##(base_mc, 'job_summer12_ZZ_2l2q'),
        ##(base_mc, 'job_summer12_ZZ_2mu2tau'),
        ##(base_mc, 'job_summer12_ZZ_4e'),
        ##(base_mc, 'job_summer12_ZZ_4mu'),
        ##(base_mc, 'job_summer12_ZZ_4tau'),
        ##(base_mc, 'job_summer12_Zg'),
        ##(base_mc, 'job_summer12_gjet_pt20to40_doubleEM'),
        ##(base_mc, 'job_summer12_gjet_pt40_doubleEM'),
        ##(base_mc, 'job_summer12_t_s'),
        ##(base_mc, 'job_summer12_t_t'),
        ##(base_mc, 'job_summer12_t_tW'),
        ##(base_mc, 'job_summer12_tbar_s'),
        ##(base_mc, 'job_summer12_tbar_t'),
        ##(base_mc, 'job_summer12_tbar_tW'),
        ##(base_mc, 'job_summer12_ttW'),
        ##(base_mc, 'job_summer12_ttZ'),
        ##(base_mc, 'job_summer12_ttg'),
        ##(base_mc, 'job_summer12_ttjets_1l'),
        ##(base_mc, 'job_summer12_ttjets_2l'),

]

#command_base = 'python scripts/filter.py  --filesDir root://eoscms/%(base)s/%(job)s/ --fileKey tree.root --outputDir /tmp/jkunkle/%(base)s/%(job)s --outputFile tree.root --treeName ggNtuplizer/EventTree --module scripts/ConfWgamgamReco.py --enableKeepFilter --nFilesPerJob %(nfiles)d --storagePath /eos/cms/store/user/jkunkle/Wgamgam/%(output)s/%(job)s --nproc %(nsplit)d --confFileName %(job)s '

#command_base = 'python scripts/filter.py  --files root://eoscms/%(base)s/%(job)s.root --fileKey tree.root --outputDir /tmp/jkunkle/%(output)s/%(job)s --outputFile tree.root --treeName ggNtuplizer/EventTree --module scripts/ConfWgamgamReco.py --enableKeepFilter --nFilesPerJob %(nfiles)d --storagePath /eos/cms/store/user/jkunkle/Wgamgam/%(output)s/%(job)s --nproc %(nproc)d --confFileName %(job)s.txt '

command_base = 'python scripts/filter.py  --files root://eoscms/%(base)s/%(job)s.root --fileKey tree.root --outputDir /tmp/jkunkle/%(output)s/%(job)s --outputFile tree.root --treeName ggNtuplizer/EventTree --module scripts/ConfWgamgamReco.py --enableKeepFilter --nproc %(nproc)s --confFileName %(job)s.txt --nsplit %(nsplit)d --storagePath /eos/cms/store/user/jkunkle/Wgamgam/%(output)s/%(job)s '

#command_base = 'python scripts/filter.py  --filesDir root://eoscms/%(base)s/%(job)s --fileKey tree.root --outputDir /tmp/jkunkle/%(output)s/%(job)s --outputFile tree.root --treeName ggNtuplizer/EventTree --module scripts/ConfWgamgamReco.py --enableKeepFilter --nFilesPerJob 1 --nproc %(nproc)s --confFileName %(job)s.txt '

output = 'RecoOutputREDO_2013_12_07'
nFilesPerJob = 1
nProc = 5

for base, job, nsplit in jobs :
    command = command_base %{ 'base' : base, 'job' : job, 'nfiles' : nFilesPerJob, 'output' : output, 'nsplit': nsplit, 'nproc' : nProc }
    print command
    os.system(command)
