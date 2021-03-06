import os
#base = '/eos/cms/store/user/jkunkle/Wgamgam/OutputS2TestNoPhJetOlap_2013_11_03'
#base = '/eos/cms/store/user/jkunkle/Wgamgam/RecoOutputOnlyDYNoTrigFilt_2014_02_03'
#base = '/eos/cms/store/user/jkunkle/Wgamgam/RecoOutput_2013_12_07'
#base = '/eos/cms/store/user/jkunkle/Wgamgam/GammaGammaMediumNoEleVetoNoEleIDOlapWithTrig_2014_07_31/'
#base_tmp = '/tmp/tEST/RecoOutputTESTNoCorr_2014_02_05/'
base = '/afs/cern.ch/work/j/jkunkle/private/CMS/Wgamgam/Output/'

jobs = [
        (base, 'job_summer12_Wg'),
        #(base, 'job_summer12_WgPt20-30'),
        #(base, 'job_summer12_WgPt30-50'),
        #(base, 'job_summer12_WgPt50-130'),
        #(base, 'job_summer12_WgPt130'),
        #(base, 'job_summer12_DYJetsToLL'),
        #(base, 'job_summer12_Wjets'),
        #(base, 'job_summer12_ttjets_1l'),
        #(base, 'job_summer12_ttjets_2l'),
        #(base, 'job_summer12_Zg'),
        #(base, 'job_summer12_DiPhotonBorn_Pt-10To25'),
        #(base, 'job_summer12_WH_ZH_125'),
        #(base, 'job_summer12_WWW'),
        #(base, 'job_summer12_WWZ'),
        #(base, 'job_summer12_WW_2l2nu'),
        #(base, 'job_summer12_WWg'),
        #(base, 'job_summer12_WZZ'),
        #(base, 'job_summer12_WZ_3lnu'),
        #(base, 'job_summer12_ZZZ'),
        #(base, 'job_summer12_ZZ_2e2mu'),
        #(base, 'job_summer12_ZZ_2e2tau'),
        #(base, 'job_summer12_ZZ_2l2nu'),
        #(base, 'job_summer12_ZZ_2l2q'),
        #(base, 'job_summer12_ZZ_2mu2tau'),
        #(base, 'job_summer12_ZZ_2q2nu'),
        #(base, 'job_summer12_ZZ_4e'),
        #(base, 'job_summer12_ZZ_4mu'),
        #(base, 'job_summer12_ZZ_4tau'),
        #(base, 'job_summer12_ggZZ_2l2l'),
        #(base, 'job_summer12_ggZZ_4l'),
        #(base, 'job_summer12_ttg'),
        #(base, 'job_summer12_t_s'),
        #(base, 'job_summer12_t_t'),
        #(base, 'job_summer12_t_tW'),
        #(base, 'job_summer12_tbar_s'),
        #(base, 'job_summer12_tbar_t'),
        #(base, 'job_summer12_tbar_tW'),
        #(base, 'job_summer12_Wgg_FSR'),
        #(base, 'job_summer12_WAA_ISR'),
        #(base, 'job_summer12_ttinclusive'),
        #(base, 'job_summer12_diphoton_box_10to25'),
        #(base, 'job_summer12_diphoton_box_250toInf'),
        #(base, 'job_summer12_diphoton_box_25to250'),
        ##(base_tmp, 'DYJetsToLLPhOlap' )
        ##(base_tmp, 'WjetsPhOlap' )
        ##(base_tmp, 'WgPhOlap' )
]

#module_mc   = 'ConfLepGammaFilter.py'
#module_data = 'ConfLepGammaFilter_Data.py'
#output_name = 'LepGamma_2013_11_04'
#sub_base = ['LepGammaLoosePh_2014_03_06', 'DiLeptonLoosePh_2014_03_06']
#sub_base = ['LepGammaPhMVAID_2014_03_28']
#sub_base = ['LepGammaGamma_2014_07_14']
sub_base = ['LepGammaGammaNoPhIDVetoPixSeedBoth_2014_10_15']

command_base = 'python scripts/filter.py  --filesDir %(base)s/%(sub_base)s/%(job)s --fileKey tree.root --outputDir /afs/cern.ch/work/j/jkunkle/private/CMS/Wgamgam/Output/%(sub_base)s/%(job)s%(suffix)s --outputFile tree.root --treeName ggNtuplizer/EventTree --module scripts/%(module)s --nFilesPerJob 1 --nproc %(nproc)d '

nproc=4
module = 'ConfFilter.py'
suffix='PhOlap'

for sb in sub_base :

    for base, job in jobs :

        command = command_base %{ 'base': base , 'sub_base' : sb, 'job' : job, 'module' : module, 'nproc' : nproc, 'suffix': suffix}
        print command
        os.system(command)
    

