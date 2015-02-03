// ===========================================================================
// 
//       Filename:  GenParAna.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  01/30/2015 12:19:54 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Zhenbin Wu (benwu), benwu@fnal.gov
//        Company:  University of Illinois at Chicago, CMS@LPC
// 
// ===========================================================================

#ifndef  __GENPARANA_INC__
#define  __GENPARANA_INC__

#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"
#include "DataFormats/Candidate/interface/Candidate.h"

#include "UserCode/SuperTopTagger/interface/HistTool.h"

// Boost
#include <boost/foreach.hpp>

struct GenPrunePacked
{
  const reco::Candidate* Pruned = NULL;
  std::vector<const reco::Candidate*> Packed;
};

struct WDecay
{
  GenPrunePacked Widx_;
  GenPrunePacked Lepidx_;
  GenPrunePacked neuidx_;
  GenPrunePacked had1idx_;
  GenPrunePacked had2idx_;
  bool isLeptonic_ = false;
};

struct TopDecay 
{
  GenPrunePacked topidx_;
  GenPrunePacked bidx_;
  WDecay widx_;
};

// ===========================================================================
//        Class:  GenParAna
//  Description:  
// ===========================================================================
class GenParAna
{
  public:

    // ====================  LIFECYCLE     ===============================
    GenParAna (HistTool* hist_);                             // constructor
    GenParAna ( const GenParAna &other );   // copy constructor
    ~GenParAna ();                            // destructor

    // ====================  ACCESSORS     ===============================
    bool GetGenParticles(edm::Handle<reco::GenParticleCollection> PrunedGenHdl, 
        edm::Handle<std::vector<pat::PackedGenParticle> >  PackedGenHdl);

    bool PrintGenPars(edm::Handle<reco::GenParticleCollection> PrunedGenHdl) const;
    bool GetTopandW(edm::Handle<reco::GenParticleCollection> PrunedGenHdl);
    bool Test() const;

    WDecay GetWDecay(const reco::Candidate*  WPar);
    TopDecay GetTopDecay(const reco::Candidate* TopPar);
    // ====================  MUTATORS      ===============================
    bool PrintTopDecay() const;
    bool PrintWDecay(WDecay wboson) const;
    bool AnaWdiJets() const;
    bool BookHistogram();
    bool GetGenCount();
    int GetLepCount() const;

    // ====================  OPERATORS     ===============================

    GenParAna& operator = ( const GenParAna &other ); // assignment operator

    // ====================  DATA MEMBERS  ===============================
    std::map<std::string, int> GenCounts;
    std::vector<TopDecay> Topidx;
    std::vector<WDecay> Widx;


  protected:
    // ====================  METHODS       ===============================

    // ====================  DATA MEMBERS  ===============================

  private:
    // ====================  METHODS       ===============================
    bool CleanPerEvent();
    GenPrunePacked GetPackedPars(const reco::Candidate* GenPar);
    bool isAncestor(const reco::Candidate* ancestor, const reco::Candidate * particle) const;

    // ====================  DATA MEMBERS  ===============================
    edm::Handle<std::vector<pat::PackedGenParticle> >  LocalPackedGenHdl;
    /// Get the vector of GenParticles per event
    HistTool* hist;

}; // -----  end of class GenParAna  -----
#endif   // ----- #ifndef __GENPARANA_INC__  -----
