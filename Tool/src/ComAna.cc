// ===========================================================================
// 
//       Filename:  ComAna.cc
// 
//    Description:  A common analysis class, aiming for cocmparison between
//    different cutflow and optimization
// 
//        Version:  1.0
//        Created:  08/24/2015 14:56:53
//       Compiler:  g++ -std=c++11
// 
//         Author:  Zhenbin Wu (benwu)
//          Email:  benwu@fnal.gov
//        Company:  Baylor University, CDF@FNAL, CMS@LPC
// 
// ===========================================================================


#include "ComAna.h"

//----------------------------------------------------------------------------
//       Class:  ComAna
//      Method:  ComAna
// Description:  constructor
//----------------------------------------------------------------------------
ComAna::ComAna (std::string name, NTupleReader* tr_, std::shared_ptr<TFile> &OutFile, std::string spec_):
  isData(false), tr(tr_), spec(spec_)
{
  his = new HistTool(OutFile, "Cut", name);
  DefineLabels(spec);
}  // -----  end of method ComAna::ComAna  (constructor)  -----

// ===  FUNCTION  ============================================================
//         Name:  ComAna::DefineLabels
//  Description:  
// ===========================================================================
bool ComAna::DefineLabels(std::string spec)
{
  jetVecLabel = "jetsLVec";
  CSVVecLabel = "recoJetsBtag_0";
  METLabel    = "met";
  METPhiLabel = "metphi";

  Label["nMuons_Base"]            = "nMuons_Base"            ; 
  Label["nElectrons_Base"]        = "nElectrons_Base"        ; 
  Label["nIsoTrks_Base"]          = "nIsoTrks_Base"          ; 
  Label["cntNJetsPt50Eta24"]      = "cntNJetsPt50Eta24"      ; 
  Label["cntNJetsPt30Eta24"]      = "cntNJetsPt30Eta24"      ; 
  Label["dPhiVec"]                = "dPhiVec"                ; 
  Label["cntCSVS"]                = "cntCSVS"                ; 
  Label["jetsLVec_forTagger"]     = "jetsLVec_forTagger"     ; 
  Label["recoJetsBtag_forTagger"] = "recoJetsBtag_forTagger" ; 
  Label["cntNJetsPt30"]           = "cntNJetsPt30"           ; 
  Label["passLeptVeto"]           = "passLeptVeto"           ; 
  Label["passMuonVeto"]           = "passMuonVeto"           ; 
  Label["passEleVeto"]            = "passEleVeto"            ; 
  Label["passIsoTrkVeto"]         = "passIsoTrkVeto"         ; 
  Label["passnJets"]              = "passnJets"              ; 
  Label["passdPhis"]              = "passdPhis"              ; 
  Label["passBJets"]              = "passBJets"              ; 
  Label["passMET"]                = "passMET"                ; 
  Label["passMT2"]                = "passMT2"                ; 
  Label["passHT"]                 = "passHT"                 ; 
  Label["passTagger"]             = "passTagger"             ; 
  Label["passNoiseEventFilter"]   = "passNoiseEventFilter"   ; 
  Label["passBaseline"]           = "passBaseline"           ; 
  Label["passBaselineNoTagMT2"]   = "passBaselineNoTagMT2"   ; 
  Label["passBaselineNoTag"]      = "passBaselineNoTag"      ; 
  Label["nTopCandSortedCnt"]      = "nTopCandSortedCnt"      ; 
  Label["best_lept_brJet_MT"]     = "best_lept_brJet_MT"     ; 
  Label["best_had_brJet_MT"]      = "best_had_brJet_MT"      ; 
  Label["best_had_brJet_mTcomb"]  = "best_had_brJet_mTcomb"  ; 
  Label["best_had_brJet_MT2"]     = "best_had_brJet_MT2"     ; 
  Label["HT"]                     = "HT"                     ; 
  Label["vTops"]                  = "vTops"                  ; 
  Label["mTopJets"]               = "mTopJets"               ; 

  // Z reco variables
  Label["bestRecoZPt"]            = "bestRecoZPt"            ; 
  Label["bestRecoZM"]             = "bestRecoZM"             ; 

  Label["cutMuPt1"]               = "cutMuPt1"               ; 
  Label["cutMuPt2"]               = "cutMuPt2"               ; 
  Label["cutMuVec"]               = "cutMuVec"               ; 
  Label["cutEleVec"]              = "cutEleVec"              ; 
  Label["cutMuActivity"]          = "cutMuActivity"          ; 
  Label["passMuZinvSel"]          = "passMuZinvSel"          ; 
  Label["passDiMuIsoTrig"]        = "passDiMuIsoTrig"        ; 
  Label["passSingleMu45"]         = "passSingleMu45"         ; 
  Label["cleanMetPt"]             = "cleanMetPt"             ; 
  Label["cleanMetPhi"]            = "cleanMetPhi"            ; 
  Label["recoZVec"]               = "recoZVec"               ; 
  Label["ZLepIdx"]                = "ZLepIdx"                ; 
  Label["PassDiMuonTrigger"]      = "PassDiMuonTrigger"      ; 
  Label["PassDiEleTrigger"]       = "PassDiEleTrigger"       ; 
  Label["NTopsB"]                 = "NTopsB"                 ; 

  if (spec != "")
  {
    for(auto &it: Label)
    {
      it.second += spec;
    }
  }
  return true;
}       // -----  end of function ComAna::DefineLabels  -----

//----------------------------------------------------------------------------
//       Class:  ComAna
//      Method:  ~ComAna
// Description:  destructor
//----------------------------------------------------------------------------
ComAna::~ComAna ()
{
}  // -----  end of method ComAna::-ComAna  (destructor)  -----

//----------------------------------------------------------------------------
//       Class:  ComAna
//      Method:  operator =
// Description:  assignment operator
//----------------------------------------------------------------------------
  ComAna&
ComAna::operator = ( const ComAna &other )
{
  if ( this != &other ) {
  }
  return *this;
}  // -----  end of method ComAna::operator =  (assignment operator)  ---

// ===  FUNCTION  ============================================================
//         Name:  ComAna::BookHistograms
//  Description:  
// ===========================================================================
bool ComAna::BookHistograms()
{
  his->AddTH1C("NBase", "Number of Events passed baseline", 2, 0, 2);
  // Jets
  BookTLVHistos("Jet1");
  BookTLVHistos("Jet2");
  BookTLVHistos("Jet3");
  BookTLVHistos("Jet4");
  Book2TLVHistos("J1J2");

  //  MET
  his->AddTH1C("MET",    "MET",    "#slash{E}_{T} [GeV]",      "Events" , 200, 0,  800);
  his->AddTH1C("METPhi", "METPhi", "#phi #slash{E}_{T} [GeV]", "Events" , 20,  -5, 5);

  // Number of Objects
  his->AddTH1C("NJets"     , "NJets"     , "Number of Jets"   , "Events" , 10 , 0 , 10);
  his->AddTH1C("NRecoTops" , "NRecoTops" , "No. of Reco Tops" , "Events" , 5  , 0 , 5);
  his->AddTH1C("NBJets", "NBJets", "Number of b-Jets"   , "Events" , 4, 0, 4);
  his->AddTH1C("NEles"     , "NEles"     , "Number of Electrons"   , "Events" , 10 , 0 , 10);
  his->AddTH1C("NMuons"     , "NMuons"     , "Number of Muons"   , "Events" , 10 , 0 , 10);
  his->AddTH1C("NIsks"     , "NIsks"     , "Number of IsoTracks"   , "Events" , 10 , 0 , 10);

  // RM from arXiv:1506.00653
  his->AddTH1C("RM"        , "RM"        , "#frac{MET}{ISR Jet}" , "Events"        , 100      , 0  , 1);
  his->AddTH1C("dPhiJ1MET" , "dPhiJ1MET" , "#phi(J1, #slash{E}_{T})" , "Events" , 200 , -5  , 5);

  // Search bins
  his->AddTH1C("MT2", "MT2", "MT2", "Events",  300, 0, 1500);
  
  // Lepton
  if (spec.find("M") != std::string::npos)
  {
    BookTLVHistos("Muon1");
    BookTLVHistos("Muon2");
  }
  if (spec.find("E") != std::string::npos)
  {
    BookTLVHistos("Ele1");
    BookTLVHistos("Ele2");
  }

  return true;
}       // -----  end of function ComAna::BookHistograms  -----

// ===  FUNCTION  ============================================================
//         Name:  ComAna::InitCutOrder
//  Description:  
// ===========================================================================
bool ComAna::InitCutOrder(std::string ana)
{
  (void)ana;
  return true;
}       // -----  end of function ComAna::InitCutOrder  -----

// ===  FUNCTION  ============================================================
//         Name:  ComAna::FillCut
//  Description:  
// ===========================================================================
bool ComAna::FillCut(int NCut)
{
  his->FillTH1(NCut, "NBase", 1);
  // Jet
  his->FillTH1(NCut, "NJets", j30count);
  FillTLVHistos(NCut, "Jet1", Jet1);
  FillTLVHistos(NCut, "Jet2", Jet2);
  FillTLVHistos(NCut, "Jet3", Jet3);
  FillTLVHistos(NCut, "Jet4", Jet4);
  Fill2TLVHistos(NCut, "J1J2", Jet1, Jet2);

  // MET
  his->FillTH1(NCut, "MET", tr->getVar<double>(METLabel) );
  his->FillTH1(NCut, "METPhi", tr->getVar<double>(METPhiLabel) );

  // NTops
  his->FillTH1(NCut, "NRecoTops", tr->getVar<int>(Label["nTopCandSortedCnt"]));
  //his->FillTH1(NCut, "NRecoTops", int(vRecoTops.size()));

  // RM
  if( tr->getVec<TLorentzVector> (jetVecLabel).size() > 0 ) 
  {

    his->FillTH1(NCut, "RM", tr->getVar<double>(METLabel) / tr->getVec<TLorentzVector> (jetVecLabel).at(0).Pt());
    TLorentzVector METLV(0, 0, 0, 0);
    METLV.SetPtEtaPhiE(tr->getVar<double>(METLabel), 0, tr->getVar<double>(METPhiLabel), 0);
    his->FillTH1(NCut, "dPhiJ1MET", tr->getVec<TLorentzVector> (jetVecLabel).at(0).DeltaPhi(METLV));
  }

  his->FillTH1(NCut, "NEles", tr->getVar<int>(Label["nElectrons_Base"]));
  his->FillTH1(NCut, "NMuons", tr->getVar<int>(Label["nMuons_Base"]));
  his->FillTH1(NCut, "NIsks", tr->getVar<int>(Label["nIsoTrks_Base"]));
  his->FillTH1(NCut, "NBJets", tr->getVar<int>(Label["cntCSVS"]));
  his->FillTH1(NCut, "NTops", tr->getVar<int>(Label["nTopCandSortedCnt"]));
  his->FillTH1(NCut, "MT2", tr->getVar<double>(Label["best_had_brJet_MT2"]));
  his->FillTH1(NCut, "MET", tr->getVar<double>(METLabel));

  return true;
}       // -----  end of function ComAna::FillCut  -----

// ===  FUNCTION  ============================================================
//         Name:  ComAna::WriteHistogram
//  Description:  
// ===========================================================================
bool ComAna::WriteHistogram()
{
  his->WriteTH1();
  his->WriteTPro();
  his->WriteTH2();
  return true;
}       // -----  end of function ComAna::WriteHistogram  -----

// ===  FUNCTION  ============================================================
//         Name:  ComAna::DrawHistogram
//  Description:  
// ===========================================================================
bool ComAna::DrawHistogram()
{
  
  return true;
}       // -----  end of function ComAna::DrawHistogram  -----

// ===  FUNCTION  ============================================================
//         Name:  ComAna::CheckCut
//  Description:  
// ===========================================================================
bool ComAna::CheckCut()
{
  return true;
}       // -----  end of function ComAna::CheckCut  -----


// ===  FUNCTION  ============================================================
//         Name:  ComAna::FillCut
//  Description:  
// ===========================================================================
bool ComAna::FillCut()
{
  //RunEvent();
  //FillCut(-1);
  return true;
}       // -----  end of function ComAna::FillCut  -----


// ===  FUNCTION  ============================================================
//         Name:  ComAna::RunEvent
//  Description:  
// ===========================================================================
bool ComAna::RunEvent()
{
  j30count = CountJets(30);
  GetLeadingJets();
  //GetType3TopTagger();

  return true;
}       // -----  end of function ComAna::RunEvent  -----

// ===  FUNCTION  ============================================================
//         Name:  ComAna::CountJets
//  Description:  
// ===========================================================================
int ComAna::CountJets(double jetPt) const
{
  int jcount = 0;
  for (unsigned int i = 0; i < tr->getVec<TLorentzVector> (jetVecLabel).size(); ++i)
  {
    if (tr->getVec<TLorentzVector> (jetVecLabel).at(i).Pt() > jetPt) 
      jcount++;
  }
  return jcount;
}       // -----  end of function ComAna::CountJets  -----

// ===  FUNCTION  ============================================================
//         Name:  ComAna::GetLeadingJets
//  Description:  
// ===========================================================================
bool ComAna::GetLeadingJets()
{
  Jet1.SetPtEtaPhiE(0.0, 0.0, 0.0, 0.0);
  Jet2.SetPtEtaPhiE(0.0, 0.0, 0.0, 0.0);
  Jet3.SetPtEtaPhiE(0.0, 0.0, 0.0, 0.0);
  Jet4.SetPtEtaPhiE(0.0, 0.0, 0.0, 0.0);

  if (tr->getVec<TLorentzVector> (jetVecLabel).size() > 0)
    Jet1 = tr->getVec<TLorentzVector> (jetVecLabel).at(0);
  
  if (tr->getVec<TLorentzVector> (jetVecLabel).size() > 1)
    Jet2 = tr->getVec<TLorentzVector> (jetVecLabel).at(1);

  if (tr->getVec<TLorentzVector> (jetVecLabel).size() > 2)
    Jet3 = tr->getVec<TLorentzVector> (jetVecLabel).at(2);

  if (tr->getVec<TLorentzVector> (jetVecLabel).size() > 3)
    Jet4 = tr->getVec<TLorentzVector> (jetVecLabel).at(3);

  return true;
}       // -----  end of function ComAna::GetLeadingJets  -----

// ===  FUNCTION  ============================================================
//         Name:  ComAna::BookTLVHistos
//  Description:  
// ===========================================================================
bool ComAna::BookTLVHistos(std::string name) 
{
  std::stringstream ss, ylabel;
  ss << name <<"PT";
  ylabel <<name<<" " << "Events";
  his->AddTH1C(ss.str(), ss.str(), "p_{T} [GeV]", ylabel.str(),  100, 0, 1000);
  ss.str("");
  ss << name <<"Eta";
  his->AddTH1C(ss.str(), ss.str(), "#eta", ylabel.str(),  20, -5, 5);
  ss.str("");
  ss << name <<"Phi";
  his->AddTH1C(ss.str(), ss.str(), "#phi", ylabel.str(),  20, -5, 5);
  ss.str("");
  ss << name <<"Mass";
  his->AddTH1C(ss.str(), ss.str(), "Mass", ylabel.str(),  100, 0, 500);

  return true;
}       // -----  end of function ComAna::BookTLVHistos  -----



// ===  FUNCTION  ============================================================
//         Name:  ComAna::FillTLVHistos
//  Description:  
// ===========================================================================
bool ComAna::FillTLVHistos(int NCut, std::string name, TLorentzVector TLV) 
{
  std::stringstream ss;
  ss << name <<"PT";
  his->FillTH1(NCut, ss.str(), TLV.Pt());
  ss.str("");
  ss << name <<"Eta";
  his->FillTH1(NCut, ss.str(), TLV.Eta());
  ss.str("");
  ss << name <<"Phi";
  his->FillTH1(NCut, ss.str(), TLV.Phi());
  ss.str("");
  ss << name <<"Mass";
  his->FillTH1(NCut, ss.str(), TLV.M());

  return true;
}       // -----  end of function ComAna::BookTLVHistos  -----

// ===  FUNCTION  ============================================================
//         Name:  ComAna::Book2TLVHistos
//  Description:  
// ===========================================================================
bool ComAna::Book2TLVHistos(std::string name)
{
  std::stringstream ss, ylabel;
  ss << name <<"delPT";
  ylabel <<name<<" " << "Events";
  his->AddTH1C(ss.str(), ss.str(), "p_{T} [GeV]", ylabel.str(),  100, -200, 200);

  ss.str("");
  ss << name <<"dPTRelFrac";
  his->AddTH1C(ss.str(), ss.str(), "Relative Fraction", ylabel.str(),  100, -2, 2);

  ss.str("");
  ss << name <<"dPTObj1Frac";
  his->AddTH1C(ss.str(), ss.str(), "#Delta p_{T} / Obj1 ", ylabel.str(),  100, -2, 2);

  ss.str("");
  ss << name <<"dPTObj1Frac";
  his->AddTH1C(ss.str(), ss.str(), "#Delta p_{T} / Obj2 ", ylabel.str(),  100, -2, 2);

  ss.str("");
  ss << name <<"delEta";
  his->AddTH1C(ss.str(), ss.str(), "#eta", ylabel.str(),  20, -5, 5);
  ss.str("");
  ss << name <<"delPhi";
  his->AddTH1C(ss.str(), ss.str(), "#phi", ylabel.str(),  20, -5, 5);
  ss.str("");
  ss << name <<"delMass";
  his->AddTH1C(ss.str(), ss.str(), "#Delta Mass", ylabel.str(),  50, 0, 50);

  ss.str("");
  ss << name <<"delR";
  his->AddTH1C(ss.str(), ss.str(), "#Delta R", ylabel.str(),  18, 0, 6);

  ss.str("");
  ss << name <<"Mass";
  his->AddTH1C(ss.str(), ss.str(), "Mass", ylabel.str(),  100, 0, 1000);

  ss.str("");
  ss << name <<"MCT";
  his->AddTH1C(ss.str(), ss.str(), "MCT", ylabel.str(),  100, 0, 1000);

  return true;
}       // -----  end of function ComAna::Book2TLVHistos  -----


// ===  FUNCTION  ============================================================
//         Name:  ComAna::Fill2TLVHistos
//  Description:  
// ===========================================================================
bool ComAna::Fill2TLVHistos(int NCut, std::string name, TLorentzVector LV1, TLorentzVector LV2)
{
  std::stringstream ss;
  ss << name <<"delPT";
  his->FillTH1(NCut, ss.str(), LV1.Pt() - LV2.Pt());

  ss.str("");
  ss << name <<"dPTRelFrac";
  his->FillTH1(NCut, ss.str(), (LV1.Pt() - LV2.Pt())/(LV1.Pt() + LV2.Pt()));

  ss.str("");
  ss << name <<"dPTObj1Frac";
  his->FillTH1(NCut, ss.str(), (LV1.Pt() - LV2.Pt())/LV1.Pt());

  ss.str("");
  ss << name <<"dPTObj2Frac";
  his->FillTH1(NCut, ss.str(), (LV1.Pt() - LV2.Pt())/LV2.Pt());

  ss.str("");
  ss << name <<"delEta";
  his->FillTH1(NCut, ss.str(), LV1.Eta() - LV2.Eta());

  ss.str("");
  ss << name <<"delPhi";
  his->FillTH1(NCut, ss.str(), LV1.DeltaPhi(LV2));

  ss.str("");
  ss << name <<"delMass";
  his->FillTH1(NCut, ss.str(), LV1.M() - LV2.M());

  ss.str("");
  ss << name <<"delR";
  his->FillTH1(NCut, ss.str(), LV1.DeltaR(LV2));

  ss.str("");
  ss << name <<"Mass";
  his->FillTH1(NCut, ss.str(), (LV1 + LV2).M());

  ss.str("");
  ss << name <<"MCT";
  his->FillTH1(NCut, ss.str(), CalMCT(LV1, LV2));

  return true;
}       // -----  end of function ComAna::Fill2TLVHistos  -----

// ===  FUNCTION  ============================================================
//         Name:  ComAna::PassType3TopCrite
//  Description:  
// ===========================================================================
bool ComAna::PassType3TopCrite(topTagger::type3TopTagger* type3TopTaggerPtr, std::vector<TLorentzVector>& oriJetsVec,
    std::vector<double>& recoJetsBtagCSVS, int ic) const
{
    double fatJetm123 = type3TopTaggerPtr->fatJetMassVec[ic];
    // Find a top fat jet passing at least one of the three criteria
    std::vector<int> fatJetPassStatusVec;
    int isTopJet = type3TopTaggerPtr->checkTopCriteria(type3TopTaggerPtr->finalCombfatJets[ic], 
        oriJetsVec, recoJetsBtagCSVS, type3TopTaggerPtr->fatJetSubMassVec[ic], fatJetm123, fatJetPassStatusVec);

    if (isTopJet != 1) return false;

    TLorentzVector jjjTop(0, 0, 0, 0);
    for (size_t k = 0; k < type3TopTaggerPtr->finalCombfatJets.at(ic).size(); ++k)
    {
      jjjTop += oriJetsVec.at(type3TopTaggerPtr->finalCombfatJets.at(ic).at(k));
    }
    if (jjjTop.M() < 110 || jjjTop.M() > 240 ) return false;
    return true;
}       // -----  end of function ComAna::PassType3TopCrite  -----


// ===  FUNCTION  ============================================================
//         Name:  ComAna::SetEvtWeight
//  Description:  
// ===========================================================================
bool ComAna::SetEvtWeight(double weight)
{
   his->SetWeight(weight);
   IsData();
  return true;
}       // -----  end of function ComAna::SetEvtWeight  -----


// ===  FUNCTION  ============================================================
//         Name:  ComAna::SaveCutHist
//  Description:  
// ===========================================================================
bool ComAna::SaveCutHist(bool choice) const
{
  assert(choice == his->SaveCutHists(choice));
  return choice;
}       // -----  end of function ComAna::SaveCutHist  -----


// ===  FUNCTION  ============================================================
//         Name:  ComAna::IsData
//  Description:  Method to determine Data samples
//  11/19/2015 -> using genHT for now, which is not store in V3 Data
// ===========================================================================
bool ComAna::IsData()
{
  isData = tr->getVar<int>("run")!= 1? true : false;
  return isData;
}       // -----  end of function ComAna::IsData  -----

// ===  FUNCTION  ============================================================
//         Name:  ComAna::PassTrigger
//  Description:  
// ===========================================================================
bool ComAna::PassTrigger()
{
  if (isData)
  {
    std::map<std::string, unsigned int> HLTIdx;
    const std::vector<std::string> &triggerName = tr->getVec<std::string>("TriggerNames");
    const std::vector<int> &triggerPass = tr->getVec<int>("PassTrigger");
    assert(triggerName.size() == triggerPass.size());
    // Get trigger index
    for(auto &hlt : HLTstr)
    {
      auto found = std::find(triggerName.begin(), triggerName.end(), hlt);
      if (found != triggerName.end())
      {
        //std::cout <<  hlt <<"  "<<  found - triggerName.begin()  << std::endl;
        HLTIdx[hlt] = found - triggerName.begin();
      }
    }
    
    bool pass=false;
    for(auto &hlt : HLTIdx)
    {
      //std::cout << pass << " " << hlt.first<< " " << triggerPass.at(hlt.second)<< std::endl;
      pass = pass || triggerPass.at(hlt.second);
    }
    return pass;
  } else{
    bool pass=false;
    for(auto &mctrig : MCTrigstr)
    {
      pass = pass || tr->getVar<bool>(mctrig);

    }
    return pass;
  }

  return false;
}       // -----  end of function ComAna::PassTrigger  -----

// ===  FUNCTION  ============================================================
//         Name:  ComAna::CheckLeadingLeptons
//  Description:  
// ===========================================================================
bool ComAna::CheckLeadingLeptons(int NCut)
{
  
  std::vector<TLorentzVector> cutMuVec;
  std::vector<TLorentzVector> cutEleVec;

  try
  {
    cutMuVec = tr->getVec<TLorentzVector>(Label["cutMuVec"]);
  }
  catch (std::string &var) {
  }

  try
  {
    cutEleVec = tr->getVec<TLorentzVector>(Label["cutEleVec"]);
  }
  catch (std::string &var) {;}

  if (cutMuVec.size() > 0)
  {
    FillTLVHistos(NCut, "Muon1", cutMuVec.at(0));
  }
  if (cutMuVec.size() > 1)
  {
    FillTLVHistos(NCut, "Muon2", cutMuVec.at(1));
  }

  if (cutEleVec.size() > 0)
  {
    FillTLVHistos(NCut, "Ele1", cutEleVec.at(0));
  }

  if (cutEleVec.size() > 1)
  {
    FillTLVHistos(NCut, "Ele2", cutEleVec.at(1));
  }
  return true;
}       // -----  end of function ComAna::CheckLeadingLeptons  -----
