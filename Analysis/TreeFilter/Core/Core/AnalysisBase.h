#ifndef ANALYSISBASE_H
#define ANALYSISBASE_H

#include <string>
#include <vector>
#include <getopt.h>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>

#include "TTree.h"
#include "TH1F.h"
#include "TChain.h"
//class TTree;
//class TChain;

namespace CutType {

    enum Op {
        
        EQUAL_TO = 0,
        GREATER_THAN = 1,
        LESS_THAN = 2,
        GREATER_THAN_OR_EQUAL_TO = 3,
        LESS_THAN_OR_EQUAL_TO = 4,
        OTHER = 100
    
    };

    enum Type {

      BOOL = 0,
      INT  = 1,
      FLOAT = 2

    };
    
}

class Cut {

    public :

        Cut(CutType::Op in_op, CutType::Type in_type, 
             bool in_val_bool, int in_val_int, float in_val_float);

        void Print() const;
    public :

        CutType::Op   op;
        CutType::Type type;
        bool          val_bool;
        int           val_int;
        float         val_float;
      
};

class CutConfig {

    public :

        CutConfig(const std::string & conf);

        std::string GetName() const { return name; }
        const std::vector<Cut> & GetCuts() const { return cuts; }
        bool GetIsInverted() const { return is_inv; }

        void SetName( const std::string & in_name ) { name = in_name; }

        void SetCuts( const std::vector<Cut> & in_cuts) { cuts = in_cuts; }

        void SetIsInverted( bool in_is_inv ) { is_inv = in_is_inv; }

        CutType::Op attempt_logicalop_parse(const std::string & val, CutType::Type & type,
                                            int & cut_val_int, float &  cut_val_float);

        bool PassBool ( const std::string & cutname, const bool  val ) const ;
        bool PassInt  ( const std::string & cutname, const int   val ) const ;
        bool PassFloat( const std::string & cutname, const float val ) const ;

    public :

        std::string name;
        std::vector<Cut> cuts;
        bool is_inv;

};

class CutFlowModule {

    public :
        
        CutFlowModule( const std::string & _name);
        ~CutFlowModule();

        // allow for a non-zero weight, but
        // for now assume the weight is 1
        void AddCutDecision( const std::string & cutname, bool pass, float weight=1.0);
        void AddCutDecisionFloat( const std::string & cutname, bool pass, float val, float weight=1.0);
        void AddCutDecisionInt( const std::string & cutname, bool pass, int val, float weight=1.0);
        void AddCutDecisionBool( const std::string & cutname, bool pass, bool val, float weight=1.0);

        std::map<std::string, TH1F*> & getHists() { return hists; }
        bool hasHist( const std::string & name ) { return ( hists.find(name) != hists.end() ); }
        TH1F* getHist( const std::string & name ) { return hists[name]; }
        const std::vector<std::string> & getOrder() { return order; }

        void Print() const;

    private :

        std::vector<std::string> order;
        std::map<std::string, float> counts;
        float                        total;
        std::string name;
        std::map<std::string, TH1F*> hists;

};

class ModuleConfig {

    public :

        ModuleConfig(const std::string &_name);

        bool PassBool ( const std::string & cutname, const bool  val );
        bool PassInt  ( const std::string & cutname, const int   val );
        bool PassFloat( const std::string & cutname, const float val );

        std::string GetName() const {return name;}

        const CutConfig & GetCut( const std::string &name ) const ;
        bool HasCut( const std::string &name ) const;

        const std::vector<CutConfig> & GetAllCuts() const { return configs; }

        void AddCutFlow( const std::string & name );
        void AddCut( CutConfig config );
        void AddHist( const std::string & name, int nbin, float xmin, float xmax );

        void PrintCutFlows() const;

        std::vector<CutFlowModule> & getCutFlows() { return cutflows; }

    private :

        std::string name;
        std::vector<CutConfig> configs;

        // For now assume 1 cutflow per module
        // but use a vector in case this
        // needs to be expanded in the future
        std::vector<CutFlowModule> cutflows;

};

struct FileEntry { 

    FileEntry() {}

    std::vector<std::string> files;
    std::vector< std::pair< std::string, std::pair< int, int > > > jobs;

};

struct CmdOptions {

    CmdOptions();

    std::string config_file;
    std::string treeName;
    std::string outputDir;
    std::string outputFile;
    std::string storagePath;
    std::vector< FileEntry > files;
    int nevt;
    bool transferToStorage;

};

CmdOptions ParseOptions(int, char**);

class RunModuleBase {

    public : 

        virtual void Run( TChain * chain, TTree *outtree, std::vector<ModuleConfig> & configs, const CmdOptions & options, int minevt=0, int maxevt=0) const = 0;

};

class AnaConfig {

    public :
       
        AnaConfig();

        void AddModule( ModuleConfig module );

        void Run( const RunModuleBase & base, const CmdOptions & options);

        int size() const { return confs.size(); }

        const ModuleConfig getEntry( unsigned int i ) const ;
        std::vector<ModuleConfig> & getEntries();
    
    public :

        std::vector<ModuleConfig> confs;

};



AnaConfig ParseConfig( const std::string & fname, CmdOptions & options );


std::vector<std::string> Tokenize(const std::string & input, const std::string &sep );


#endif