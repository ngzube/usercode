def config_samples(samples) :

    import ROOT

    samples.AddSample('DYJetsToLL'   , path='job_summer12_DYJetsToLL', plotColor=ROOT.kBlue )
    samples.AddSample('Zg'           , path='job_summer12_Zg'    ,  plotColor=ROOT.kRed )
    samples.AddSample('DYJetsToLLPhOlap' , path='job_summer12_DYJetsToLLPhOlap'    ,  plotColor=ROOT.kRed, isActive=False )

    samples.AddSample('electron_2012a_Jan22rereco'   , path='job_electron_2012a_Jan22rereco'    ,  isActive=False, scale=1.0 )
    samples.AddSample('electron_2012b_Jan22rereco'   , path='job_electron_2012b_Jan22rereco'    ,  isActive=False, scale=1.0 )
    samples.AddSample('electron_2012c_Jan2012rereco' , path='job_electron_2012c_Jan2012rereco'  ,  isActive=False, scale=1.0 )
    samples.AddSample('electron_2012d_Jan22rereco'   , path='job_electron_2012d_Jan22rereco'    ,  isActive=False, scale=1.0 )

    samples.AddSample('electron_2012a_Jan22rerecoTightBlind'   , path='job_electron_2012a_Jan22rerecoTightBlind'    ,  isActive=False, scale=1.0 )
    samples.AddSample('electron_2012b_Jan22rerecoTightBlind'   , path='job_electron_2012b_Jan22rerecoTightBlind'    ,  isActive=False, scale=1.0 )
    samples.AddSample('electron_2012c_Jan2012rerecoTightBlind' , path='job_electron_2012c_Jan2012rerecoTightBlind'  ,  isActive=False, scale=1.0 )
    samples.AddSample('electron_2012d_Jan22rerecoTightBlind'   , path='job_electron_2012d_Jan22rerecoTightBlind'    ,  isActive=False, scale=1.0 )

    samples.AddSampleGroup( 'Data', legend_name='Data', 
                            input_samples = [
                                             'electron_2012a_Jan22rereco',
                                             'electron_2012b_Jan22rereco',
                                             'electron_2012c_Jan2012rereco',
                                             'electron_2012d_Jan22rereco',
                                            ],
                           plotColor=ROOT.kBlack,
                           isData=True,
                          )

    
    samples.AddSampleGroup( 'ZjetsZgamma', legend_name='ZjetsZgamma', 
                            input_samples = [
                                             'DYJetsToLLPhOlap',
                                             'Zg',
                            ],
                           plotColor=ROOT.kBlue,
                           )


