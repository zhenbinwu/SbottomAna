// ===========================================================================
// 
//       Filename:  TriggerAna.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  11/28/16 16:22:52
//       Compiler:  g++ -std=c++11
// 
//         Author:  Zhenbin Wu (benwu)
//          Email:  zhenbin.wu@gmail.com
//        Company:  UIC, CMS@LPC, CDF@FNAL
// 
// ===========================================================================

#include "TriggerAna.h"

//----------------------------------------------------------------------------
//       Class:  TriggerAna
//      Method:  TriggerAna
// Description:  constructor
//----------------------------------------------------------------------------
TriggerAna::TriggerAna (std::string name, NTupleReader* tr_, std::shared_ptr<TFile> &OutFile, std::string spec_)
: ComAna(name, tr_, OutFile, spec_)
{
  InitCutOrder(name);
}  // -----  end of method TriggerAna::TriggerAna  (constructor)  -----

//----------------------------------------------------------------------------
//       Class:  TriggerAna
//      Method:  TriggerAna
// Description:  copy constructor
//----------------------------------------------------------------------------
TriggerAna::TriggerAna ( const TriggerAna &other ): ComAna(other)
{
}  // -----  end of method TriggerAna::TriggerAna  (copy constructor)  -----

//----------------------------------------------------------------------------
//       Class:  TriggerAna
//      Method:  ~TriggerAna
// Description:  destructor
//----------------------------------------------------------------------------
TriggerAna::~TriggerAna ()
{
}  // -----  end of method TriggerAna::-TriggerAna  (destructor)  -----

//----------------------------------------------------------------------------
//       Class:  TriggerAna
//      Method:  operator =
// Description:  assignment operator
//----------------------------------------------------------------------------
  TriggerAna&
TriggerAna::operator = ( const TriggerAna &other )
{
  if ( this != &other ) {
  }
  return *this;
}  // -----  end of method TriggerAna::operator =  (assignment operator)  ---

// ===  FUNCTION  ============================================================
//         Name:  TriggerAna::BookHistograms
//  Description:  
// ===========================================================================
bool TriggerAna::BookHistograms()
{
  his->AddTH1C("TrigMET_Denominator" , "TrigMET_Denominator" , "MET [GeV]" , "Denominator" , 200, 0, 1000);
  his->AddTH1C("TrigMET_Numerator"   , "TrigMET_Numerator"   , "MET [GeV]" , "Numerator"   , 200, 0, 1000);
  his->AddTH1C("TrigMET_HTLess1000_Denominator" , "TrigMET_HTLess1000_Denominator" , "MET [GeV]" , "Denominator" , 200, 0, 1000);
  his->AddTH1C("TrigMET_HTLess1000_Numerator"   , "TrigMET_HTLess1000_Numerator"   , "MET [GeV]" , "Numerator"   , 200, 0, 1000);
  his->AddTH1C("TrigMET_HTMore1000_Denominator" , "TrigMET_HTMore1000_Denominator" , "MET [GeV]" , "Denominator" , 200, 0, 1000);
  his->AddTH1C("TrigMET_HTMore1000_Numerator"   , "TrigMET_HTMore1000_Numerator"   , "MET [GeV]" , "Numerator"   , 200, 0, 1000);

  his->AddTH1C("Trig50Muon_Denominator"      , "Trig50Muon_Denominator"    , "MuonPT [GeV]"     , "Denominator" , 250, 0,  500);
  his->AddTH1C("Trig50Muon_Numerator"        , "Trig50Muon_Numerator"      , "MuonPT [GeV]"     , "Numerator"   , 250, 0,  500);
  his->AddTH1C("Trig50MuonEta50_Denominator" , "Trig50MuonEta50_Denominator" , "MuonEta(PT > 50)" , "Denominator" , 60,  -3, 3);
  his->AddTH1C("Trig50MuonEta50_Numerator"   , "Trig50MuonEta50_Numerator"   , "MuonEta(PT > 50)" , "Numerator"   , 60,  -3, 3);

  his->AddTH1C("TrigMuon_Denominator"      , "TrigMuon_Denominator"    , "MuonPT [GeV]"     , "Denominator" , 250, 0,  500);
  his->AddTH1C("TrigMuon_Numerator"        , "TrigMuon_Numerator"      , "MuonPT [GeV]"     , "Numerator"   , 250, 0,  500);
  his->AddTH1C("TrigMuonEta45_Denominator" , "TrigMuonEta45_Denominator" , "MuonEta(PT > 45)" , "Denominator" , 60,  -3, 3);
  his->AddTH1C("TrigMuonEta45_Numerator"   , "TrigMuonEta45_Numerator"   , "MuonEta(PT > 45)" , "Numerator"   , 60,  -3, 3);
  his->AddTH1C("TrigMuonEta40_Denominator" , "TrigMuonEta40_Denominator" , "MuonEta(PT > 40)" , "Denominator" , 60,  -3, 3);
  his->AddTH1C("TrigMuonEta40_Numerator"   , "TrigMuonEta40_Numerator"   , "MuonEta(PT > 40)" , "Numerator"   , 60,  -3, 3);
  his->AddTH1C("TrigMuonEta50_Denominator" , "TrigMuonEta50_Denominator" , "MuonEta(PT > 50)" , "Denominator" , 60,  -3, 3);
  his->AddTH1C("TrigMuonEta50_Numerator"   , "TrigMuonEta50_Numerator"   , "MuonEta(PT > 50)" , "Numerator"   , 60,  -3, 3);

  his->AddTH1C("TrigEle_Denominator"      , "TrigEle_Denominator"    , "ElePT [GeV]"     , "Denominator" , 250, 0,  500);
  his->AddTH1C("TrigEle_Numerator"        , "TrigEle_Numerator"      , "ElePT [GeV]"     , "Numerator"   , 250, 0,  500);
  his->AddTH1C("TrigEleEta40_Denominator" , "TrigEleEta40_Denominator" , "EleEta(PT > 40)" , "Denominator" , 60,  -3, 3);
  his->AddTH1C("TrigEleEta40_Numerator"   , "TrigEleEta40_Numerator"   , "EleEta(PT > 40)" , "Numerator"   , 60,  -3, 3);
  return true;
}       // -----  end of function TriggerAna::BookHistograms  -----

// ===  FUNCTION  ============================================================
//         Name:  TriggerAna::InitCutOrder
//  Description:  
// ===========================================================================
bool TriggerAna::InitCutOrder(std::string ana)
{
  //Clear the objects
  CutOrder.clear();
  CutMap.clear();
  HLTstr.clear();

  if (AnaName.find("Stop") != std::string::npos)
  {
    // Use this trigger as denominator
    if (AnaName.find("TrigEle_") != std::string::npos)
      HLTstr.push_back("HLT_Ele27_WPTight_Gsf_v\\d");
    if (AnaName.find("TrigMu_") != std::string::npos)
      HLTstr.push_back("HLT_Ele27_WPTight_Gsf_v\\d");

    //Add name and order of the cutflow
    //Default is the singleEle trigger pass
    CutOrder.push_back("NoCut");
    CutOrder.push_back("Filter");
    CutOrder.push_back("EleTrig");
    CutOrder.push_back("NEle");
    CutOrder.push_back("NMuon");
    CutOrder.push_back("nJets30");
    CutOrder.push_back("nJets50");
    CutOrder.push_back("BJets");
    CutOrder.push_back("HT");
    CutOrder.push_back("WithMuon");
    CutOrder.push_back("dDPhi");

    //Set the cutbit of each cut
    CutMap["NoCut"]   = "00000000000000000";
    CutMap["Filter"]  = "00000000000000001";
    CutMap["EleTrig"] = "00000000000000011";
    CutMap["NEle"]    = "00000000000000111";
    CutMap["NMuon"]   = "00000000000001111";
    CutMap["nJets30"] = "00000000000011111";
    CutMap["nJets50"] = "00000000000111111";
    CutMap["BJets"]   = "00000000001111111";
    CutMap["HT"]      = "00000000011111111";
    CutMap["WithMuon"]= "00000000111110111";
    CutMap["dDPhi"]   = "00000001011111111";
  }

  if (AnaName.find("Muon") != std::string::npos)
  {
    // Use this trigger as denominator
    HLTstr.push_back("HLT_Ele27_WPTight_Gsf_v\\d");

    //Add name and order of the cutflow
    //Default is the singleEle trigger pass
    CutOrder.push_back("NoCut");
    CutOrder.push_back("Filter");
    CutOrder.push_back("EleTrig");
    CutOrder.push_back("NEle");
    CutOrder.push_back("NMuon");
    CutOrder.push_back("nJets30");
    CutOrder.push_back("nJets50");
    CutOrder.push_back("BJets");
    CutOrder.push_back("HT");

    //Set the cutbit of each cut
    CutMap["NoCut"]   = "00000000000000000";
    CutMap["Filter"]  = "00000000000000001";
    CutMap["EleTrig"] = "00000000000000011";
    CutMap["NEle"]    = "00000000000000111";
    CutMap["NMuon"]   = "00000000000001111";
    CutMap["nJets30"] = "00000000000011111";
    CutMap["nJets50"] = "00000000000111111";
    CutMap["BJets"]   = "00000000001111111";
    CutMap["HT"]      = "00000000011111111";
  }

  if (AnaName.find("Ele") != std::string::npos)
  {
    // Use this trigger as denominator
    HLTstr.push_back("HLT_Mu50_v\\d");

    //Add name and order of the cutflow
    //Default is the singleEle trigger pass
    CutOrder.push_back("NoCut");
    CutOrder.push_back("Filter");
    CutOrder.push_back("MuTrig");
    CutOrder.push_back("NMuon");
    CutOrder.push_back("NEle");
    CutOrder.push_back("nJets30");
    CutOrder.push_back("BJets");

    //Set the cutbit of each cut
    CutMap["NoCut"]   = "00000000000000000";
    CutMap["Filter"]  = "00000000000000001";
    CutMap["MuTrig"]  = "00000000000000011";
    CutMap["NMuon"]   = "00000000000000111";
    CutMap["NEle"]    = "00000000000001111";
    CutMap["nJets30"] = "00000000000011111";
    CutMap["BJets"]   = "00000000000111111";
  }

  if (AnaName.find("QCD") != std::string::npos)
  {
    // Use this trigger as denominator
    HLTstr.push_back("HLT_Ele27_WPTight_Gsf_v\\d");

    //Add name and order of the cutflow
    //Default is the singleEle trigger pass
    CutOrder.push_back("NoCut");
    CutOrder.push_back("Filter");
    CutOrder.push_back("EleTrig");
    CutOrder.push_back("NEle");
    CutOrder.push_back("VetoMuon");
    CutOrder.push_back("nJets");
    CutOrder.push_back("InvDPhi");

    //Set the cutbit of each cut

    CutMap["NoCut"]    = "00000000000000000";
    CutMap["Filter"]   = "00000000000000001";
    CutMap["EleTrig"]  = "00000000000000011";
    CutMap["NEle"]     = "00000000000000111";
    CutMap["VetoMuon"] = "00000000000001111";
    CutMap["nJets"]    = "00000000000011111";
    CutMap["InvDPhi"]  = "00000000000111111";
  }

  assert(CutOrder.size() == CutMap.size());

  his->Cutorder(ana, CutOrder, static_cast<unsigned int>(NBITS));
  return true;

}       // -----  end of function TriggerAna::InitCutOrder  -----


// ===  FUNCTION  ============================================================
//         Name:  TriggerAna::CheckCut
//  Description:  
// ===========================================================================
bool TriggerAna::CheckCut()
{
  cutbit.reset();

  if (AnaName.find("Stop") != std::string::npos)
  {
    cutbit.set(0 , tr->getVar<bool>(Label["passNoiseEventFilter"]));
    cutbit.set(1 , PassTrigger());
    cutbit.set(2 , tr->getVec<TLorentzVector>(Label["cutEleVec"]).size() >= 1 && 
        tr->getVec<TLorentzVector>(Label["cutEleVec"]).front().Pt() > 30);
    cutbit.set(3 , tr->getVar<int>(Label["nMuons_Base"]) == 0 );
    cutbit.set(4 , tr->getVar<int>(Label["cntNJetsPt30Eta24"]) > 3 );
    cutbit.set(5 , tr->getVar<int>(Label["cntNJetsPt50Eta24"]) > 1);
    cutbit.set(6 , tr->getVar<bool>(Label["passBJets"]));
    cutbit.set(7 , tr->getVar<bool>(Label["passHT"]));
    cutbit.set(8 , tr->getVar<int>(Label["nMuons_Base"]) >= 1);
    cutbit.set(9 , tr->getVar<bool>(Label["passdPhis"]));
  }

  if (AnaName.find("Muon") != std::string::npos)
  {
    cutbit.set(0 , tr->getVar<bool>(Label["passNoiseEventFilter"]));
    cutbit.set(1 , PassTrigger());
    cutbit.set(2 , tr->getVec<TLorentzVector>(Label["cutEleVec"]).size() >= 1 && 
        tr->getVec<TLorentzVector>(Label["cutEleVec"]).front().Pt() > 30);
    cutbit.set(3 , tr->getVar<int>(Label["nMuons_Base"]) >= 1 );
    cutbit.set(4 , tr->getVar<int>(Label["cntNJetsPt30Eta24"]) > 3 );
    cutbit.set(5 , tr->getVar<int>(Label["cntNJetsPt50Eta24"]) > 1);
    cutbit.set(6 , tr->getVar<bool>(Label["passBJets"]));
    cutbit.set(7 , tr->getVar<bool>(Label["passHT"]));
  }

  if (AnaName.find("Ele") != std::string::npos)
  {
    cutbit.set(0 , tr->getVar<bool>(Label["passNoiseEventFilter"]));
    cutbit.set(1 , PassTrigger());
    cutbit.set(2 , tr->getVec<TLorentzVector>(Label["cutMuVec"]).size() >= 1 && 
        tr->getVec<TLorentzVector>(Label["cutMuVec"]).front().Pt() > 50);
    cutbit.set(3 , tr->getVar<int>(Label["nElectrons_Base"]) >= 1 );
    cutbit.set(4 , tr->getVar<int>(Label["cntNJetsPt30Eta24"]) > 3 );
    cutbit.set(5 , tr->getVar<bool>(Label["passBJets"]));
  }


  if (AnaName.find("QCD") != std::string::npos)
  {
    cutbit.set(0 , tr->getVar<bool>(Label["passNoiseEventFilter"]));
    cutbit.set(1 , PassTrigger());
    cutbit.set(2 , tr->getVec<TLorentzVector>(Label["cutEleVec"]).size() >= 1 && 
        tr->getVec<TLorentzVector>(Label["cutEleVec"]).front().Pt() > 30);
    cutbit.set(3 , tr->getVar<int>(Label["nMuons_Base"]) == 0 );
    cutbit.set(4 , tr->getVar<bool>(Label["passnJets"]));
    cutbit.set(5 , !tr->getVar<bool>(Label["passdPhis"]));
  }

  return true;
}       // -----  end of function TriggerAna::CheckCut  -----

// ===  FUNCTION  ============================================================
//         Name:  TriggerAna::FillCut
//  Description:  
// ===========================================================================
bool TriggerAna::FillCut()
{
//----------------------------------------------------------------------------
//  Check cut and fill cut-based plots
//----------------------------------------------------------------------------
  //HLTIdx.clear();
  if (ComAna::IsUpdateHLT()) HLTIdx.clear();
  ComAna::RunEvent();
  CheckCut();
  bool passcuts = false;

  for (unsigned int i = 0; i < CutOrder.size(); ++i)
  {
    std::bitset<NBITS> locbit(CutMap[CutOrder.at(i)]);
    if ( (cutbit & locbit) != locbit) continue;

    his->FillTH1("CutFlow", int(i)); 
    FillMETEff(i);
    FillMuonEff(i);
    FillEleEff(i);
  }

  return true;
}       // -----  end of function TriggerAna::FillCut  -----l

// ===  FUNCTION  ============================================================
//         Name:  TriggerAna::FillMETEff
//  Description:  
// ===========================================================================
bool TriggerAna::FillMETEff(int NCut)
{
  // Denominator
  his->FillTH1(NCut, "TrigMET_Denominator", tr->getVar<double>(METLabel));
  if (tr->getVar<double>(Label["HT"]) > 1000)
    his->FillTH1(NCut, "TrigMET_HTMore1000_Denominator", tr->getVar<double>(METLabel));
  else
    his->FillTH1(NCut, "TrigMET_HTLess1000_Denominator", tr->getVar<double>(METLabel));

  std::vector<std::string> METHLT;
  METHLT.push_back("HLT_PFMET100_PFMHT100_IDTight_v\\d");
  METHLT.push_back("HLT_PFMET110_PFMHT110_IDTight_v\\d");
  METHLT.push_back("HLT_PFMET120_PFMHT120_IDTight_v\\d");
  METHLT.push_back("HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v\\d");
  METHLT.push_back("HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v\\d");
  METHLT.push_back("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v\\d");
  if (PassTrigger(METHLT))
  {
    his->FillTH1(NCut, "TrigMET_Numerator", tr->getVar<double>(METLabel));
    if (tr->getVar<double>(Label["HT"]) > 1000)
      his->FillTH1(NCut, "TrigMET_HTMore1000_Numerator", tr->getVar<double>(METLabel));
    else
      his->FillTH1(NCut, "TrigMET_HTLess1000_Numerator", tr->getVar<double>(METLabel));
  }

  return true;
}       // -----  end of function TriggerAna::FillMETEff  -----

// ===  FUNCTION  ============================================================
//         Name:  TriggerAna::FillMuonEff
//  Description:  
// ===========================================================================
bool TriggerAna::FillMuonEff(int NCut)
{
  const std::vector<TLorentzVector> &muonsLVec   = tr->getVec<TLorentzVector>(Label["cutMuVec"]);
  if (muonsLVec.empty()) return false;
  double LeadingPt =  -1;
  double LeadingEta40 =  -999;
  double LeadingEta45 =  -999;
  double LeadingEta50 =  -999;
  for(auto i : muonsLVec)
  {
    //if (fabs(i.Eta()) > 2.1) continue;
    if (i.Pt() > LeadingPt)
    {
      LeadingPt = i.Pt();
      if (i.Pt() > 40)
        LeadingEta40 = i.Eta();
      if (i.Pt() > 45)
        LeadingEta45 = i.Eta();
      if (i.Pt() > 50)
        LeadingEta50 = i.Eta();
    }
  }

  his->FillTH1(NCut, "TrigMuon_Denominator", LeadingPt);
  his->FillTH1(NCut, "Trig50Muon_Denominator", LeadingPt);
  his->FillTH1(NCut, "Trig50MuonEta50_Denominator", LeadingEta50);
  his->FillTH1(NCut, "TrigMuonEta40_Denominator", LeadingEta40);
  his->FillTH1(NCut, "TrigMuonEta45_Denominator", LeadingEta45);
  his->FillTH1(NCut, "TrigMuonEta50_Denominator", LeadingEta50);

  std::vector<std::string> MuonHLT;
  MuonHLT.push_back("HLT_Mu50_v\\d");
  MuonHLT.push_back("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v\\d");
  MuonHLT.push_back("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v\\d");
  if (PassTrigger(MuonHLT))
  {
    his->FillTH1(NCut, "Trig50Muon_Numerator", LeadingPt);
    his->FillTH1(NCut, "Trig50MuonEta50_Numerator", LeadingEta50);
  }
  MuonHLT.push_back("HLT_IsoMu24_v\\d");
  MuonHLT.push_back("HLT_IsoTKMu24_v\\d");
  if (PassTrigger(MuonHLT))
  {
    his->FillTH1(NCut, "TrigMuon_Numerator", LeadingPt);
    his->FillTH1(NCut, "TrigMuonEta40_Numerator", LeadingEta40);
    his->FillTH1(NCut, "TrigMuonEta45_Numerator", LeadingEta45);
    his->FillTH1(NCut, "TrigMuonEta50_Numerator", LeadingEta50);
  }
  return true;
}       // -----  end of function TriggerAna::FillMuonEff  -----
// ===  FUNCTION  ============================================================
//         Name:  TriggerAna::FillEleEff
//  Description:  
// ===========================================================================
bool TriggerAna::FillEleEff(int NCut)
{
  
  const std::vector<TLorentzVector> &elesLVec   = tr->getVec<TLorentzVector>(Label["cutEleVec"]);
  if (elesLVec.empty()) return false;
  double LeadingPt =  -1;
  double LeadingEta40 =  -999;

  for(auto i : elesLVec)
  {
    //if (fabs(i.Eta()) > 2.1) continue;
    if (i.Pt() > LeadingPt)
    {
      LeadingPt = i.Pt();
      if (i.Pt() > 40)
        LeadingEta40 = i.Eta();
    }
  }
  his->FillTH1(NCut, "TrigEle_Denominator", LeadingPt);
  his->FillTH1(NCut, "TrigEleEta40_Denominator", LeadingEta40);

  std::vector<std::string> EleHLT;
  EleHLT.push_back("HLT_Ele27_WPTight_Gsf_v\\d");
  EleHLT.push_back("HLT_Ele105_CaloIdVT_GsfTrkIdT_v\\d");
  EleHLT.push_back("HLT_Ele115_CaloIdVT_GsfTrkIdT_v\\d");
  if (PassTrigger(EleHLT))
  {
    his->FillTH1(NCut, "TrigEle_Numerator", LeadingPt);
    his->FillTH1(NCut, "TrigEleEta40_Numerator", LeadingEta40);
  }
  return true;
}       // -----  end of function TriggerAna::FillEleEff  -----
