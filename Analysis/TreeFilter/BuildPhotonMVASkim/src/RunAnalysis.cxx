#include "include/RunAnalysis.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include <stdlib.h>

#include "include/BranchDefs.h"
#include "include/BranchInit.h"

#include "Core/Util.h"

#include "TFile.h"

int main(int argc, char **argv)
{

    //TH1::AddDirectory(kFALSE);
    CmdOptions options = ParseOptions( argc, argv );

    // Parse the text file and form the configuration object
    AnaConfig ana_config = ParseConfig( options.config_file, options );
    std::cout << "Configured " << ana_config.size() << " analysis modules " << std::endl;

    RunModule runmod;
    ana_config.Run(runmod, options);

    std::cout << "^_^ Finished ^_^" << std::endl;


}

void RunModule::initialize( TChain * chain, TTree * outtree, TFile *outfile,
                            const CmdOptions & options, std::vector<ModuleConfig> &configs ) {

    // *************************
    // initialize trees
    // *************************
    InitINTree(chain);
    InitOUTTree( outtree );
    
    // *************************
    // Set defaults for added output variables
    // *************************
    
    // *************************
    // Declare Branches
    // *************************

    outtree->Branch("phoMvaScore"      , &OUT::phoMvaScore, "phoMvaScore/F");
    outtree->Branch("phoIsEB"          , &OUT::phoIsEB, "phoIsEB/O" );
    outtree->Branch("phoIsEE"          , &OUT::phoIsEE, "phoIsEE/O" );

    BOOST_FOREACH( ModuleConfig & mod_conf, configs ) {

        if( mod_conf.GetName() == "BuildPhoton" ) { 
            std::map<std::string, std::string>::const_iterator citr = mod_conf.GetInitData().find( "TMVAWeightsFileEB" );
            if( citr != mod_conf.GetInitData().end() ) {
                std::string mva_weights_eb = citr->second;  
                TMVAReaderEB = new TMVA::Reader( "!Color:!Silent:Error" );
                TMVAReaderEB->SetVerbose(true);

                TMVAReaderEB->AddVariable("phoPhi", &MVAVars::phoPhi);
                TMVAReaderEB->AddVariable("phoR9", &MVAVars::phoR9);
                TMVAReaderEB->AddVariable("phoSigmaIEtaIEta", &MVAVars::phoSigmaIEtaIEta  );
                TMVAReaderEB->AddVariable("phoSigmaIEtaIPhi", &MVAVars::phoSigmaIEtaIPhi );
                TMVAReaderEB->AddVariable("s13", &MVAVars::s13 );
                TMVAReaderEB->AddVariable("s4ratio", &MVAVars::s4ratio );
                TMVAReaderEB->AddVariable("s25", &MVAVars::s25 );
                TMVAReaderEB->AddVariable("phoSCEta", &MVAVars::phoSCEta );
                TMVAReaderEB->AddVariable("phoSCRawE", &MVAVars::phoSCRawE );
                TMVAReaderEB->AddVariable("phoSCEtaWidth", &MVAVars::phoSCEtaWidth );
                TMVAReaderEB->AddVariable("phoSCPhiWidth", &MVAVars::phoSCPhiWidth );
                TMVAReaderEB->AddVariable("rho2012", &MVAVars::rho2012 );
                TMVAReaderEB->AddVariable("phoPFPhoIso", &MVAVars::phoPFPhoIso );
                TMVAReaderEB->AddVariable("phoPFChIso", &MVAVars::phoPFChIso );
                TMVAReaderEB->AddVariable("phoPFChIsoWorst", &MVAVars::phoPFChIsoWorst );

                TMVAReaderEB->AddSpectator("phoEt", &MVAVars::phoEt);
                TMVAReaderEB->AddSpectator("phoEta", &MVAVars::phoEta);

                TMVAReaderEB->BookMVA("BDT", mva_weights_eb);


            }
            citr = mod_conf.GetInitData().find( "TMVAWeightsFileEE" );
            if( citr != mod_conf.GetInitData().end() ) {
                std::string mva_weights_ee = citr->second;  
                TMVAReaderEE = new TMVA::Reader( "!Color:!Silent:Error" );
                TMVAReaderEE->SetVerbose(true);

                TMVAReaderEE->AddVariable("phoPhi", &MVAVars::phoPhi );
                TMVAReaderEE->AddVariable("phoR9", &MVAVars::phoR9 );
                TMVAReaderEE->AddVariable("phoSigmaIEtaIEta", &MVAVars::phoSigmaIEtaIEta );
                TMVAReaderEE->AddVariable("phoSigmaIEtaIPhi", &MVAVars::phoSigmaIEtaIPhi );
                TMVAReaderEE->AddVariable("s13", &MVAVars::s13 );
                TMVAReaderEE->AddVariable("s4ratio", &MVAVars::s4ratio );
                TMVAReaderEE->AddVariable("s25", &MVAVars::s25 );
                TMVAReaderEE->AddVariable("phoSCEta", &MVAVars::phoSCEta );
                TMVAReaderEE->AddVariable("phoSCRawE", &MVAVars::phoSCRawE );
                TMVAReaderEE->AddVariable("phoSCEtaWidth", &MVAVars::phoSCEtaWidth );
                TMVAReaderEE->AddVariable("phoSCPhiWidth", &MVAVars::phoSCPhiWidth );
                TMVAReaderEE->AddVariable("phoESEn/phoSCRawE", &MVAVars::phoESEnToRawE );
                TMVAReaderEE->AddVariable("phoESEffSigmaRR", &MVAVars::phoESEffSigmaRR );
                TMVAReaderEE->AddVariable("rho2012", &MVAVars::rho2012 );
                TMVAReaderEE->AddVariable("phoPFPhoIso", &MVAVars::phoPFPhoIso );
                TMVAReaderEE->AddVariable("phoPFChIso", &MVAVars::phoPFChIso );
                TMVAReaderEE->AddVariable("phoPFChIsoWorst", &MVAVars::phoPFChIsoWorst );

                TMVAReaderEE->AddSpectator("phoEt", &MVAVars::phoEt);
                TMVAReaderEE->AddSpectator("phoEta", &MVAVars::phoEta);
                TMVAReaderEE->BookMVA("BDT", mva_weights_ee);
            }
        }
    }
}

bool RunModule::execute( std::vector<ModuleConfig> & configs ) {

    // In BranchInit
    CopyInputVarsToOutput();

    // loop over configured modules
    bool save_event = true;
    BOOST_FOREACH( ModuleConfig & mod_conf, configs ) {
        save_event &= ApplyModule( mod_conf );
    }

    return save_event;

}

bool RunModule::ApplyModule( ModuleConfig & config ) const {

    // This bool is used for filtering
    // If a module implements an event filter
    // update this variable and return it
    // to apply the filter
    bool keep_evt = true;

    // This part is a bit hacked.  For each module that
    // you write below, you have to put a call to that
    // function with a matching name here.
    // The name is used to match the name used
    // in the python configuration.
    // There are fancy ways to do this, but it
    // would require the code to be much more complicated
    //
    // Example :
    if( config.GetName() == "BuildPhoton" ) {
        BuildPhoton( config );
    }

    // If the module applies a filter the filter decision
    // is passed back to here.  There is no requirement
    // that a function returns a bool, but
    // if you want the filter to work you need to do this
    //
    // Example :

    return keep_evt;

}

// ***********************************
//  Define modules here
//  The modules can do basically anything
//  that you want, fill trees, fill plots, 
//  caclulate an event filter
// ***********************************
//
// Examples :

void RunModule::BuildPhoton( ModuleConfig & config ) const {


    float r9Corr = IN::phoR9;
    float sceta = IN::phoSCEta;

    if( fabs(sceta) < 1.479 ) {
        r9Corr = 0.000740 + 1.00139*IN::phoR9;
    }
    else {
        r9Corr = -0.000399 + 1.00016*IN::phoR9;
    }

    OUT::phoIsEB=false;
    OUT::phoIsEE=false;
    if( fabs(sceta) < 1.479 ) {
        OUT::phoIsEB = true;
    }
    if( fabs(sceta) > 1.566 ) {
        OUT::phoIsEE = true;
    }

    // Evaluate MVA
    if( TMVAReaderEB != 0 && TMVAReaderEE != 0 ) {

        MVAVars::phoPhi           = IN::phoPhi;
        MVAVars::phoR9            = r9Corr;
        MVAVars::phoSigmaIEtaIEta = IN::phoSigmaIEtaIEta;
        MVAVars::phoSigmaIEtaIPhi = IN::phoSigmaIEtaIPhi;
        MVAVars::s4ratio          = IN::phoE2x2/IN::phoE5x5;
        MVAVars::s13              = IN::phoE1x3/IN::phoE5x5;
        MVAVars::s25              = IN::phoE2x5Max/IN::phoE5x5;
        MVAVars::phoSCEta         = IN::phoSCEta;
        MVAVars::phoSCRawE        = IN::phoSCRawE;
        MVAVars::phoSCEtaWidth    = IN::phoSCEtaWidth;
        MVAVars::phoSCPhiWidth    = IN::phoSCPhiWidth;
        MVAVars::rho2012          = IN::rho2012;
        MVAVars::phoPFPhoIso      = IN::phoPFPhoIso;
        MVAVars::phoPFChIso       = IN::phoPFChIso;
        MVAVars::phoPFChIsoWorst  = IN::phoPFChIsoWorst;
        MVAVars::phoESEnToRawE    = IN::phoESEn/IN::phoSCRawE;
        MVAVars::phoESEffSigmaRR  = IN::phoESEffSigmaRR;

        if( OUT::phoIsEB ) {
            OUT::phoMvaScore = TMVAReaderEB->EvaluateMVA("BDT");
        }
        else if( OUT::phoIsEE ) {
            OUT::phoMvaScore = TMVAReaderEE->EvaluateMVA("BDT");
        }
        else {
            OUT::phoMvaScore = -99;
        }
    }
}


