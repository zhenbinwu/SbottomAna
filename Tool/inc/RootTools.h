// ===========================================================================
// 
//       Filename:  RootTools.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  06/15/2015 11:46:45
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Zhenbin Wu (benwu), benwu@fnal.gov
//        Company:  Baylor University, CDF@FNAL, CMS@LPC
// 
// ===========================================================================

#ifndef  MY_ROOTTOOLS_INC
#define  MY_ROOTTOOLS_INC


#include <unistd.h>
#include <ios>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>

// boost
#include "boost/tokenizer.hpp"
#include "boost/algorithm/string.hpp"

// ROOT
#include "TLorentzVector.h"

// User
#include "TopTaggerAna.h"
#include "VarPerEvent.h"

//SusyAnatool
#include "SusyAnaTools/Tools/samples.h"
#include "SusyAnaTools/Tools/NTupleReader.h"
#include "SusyAnaTools/Tools/baselineDef.h"

std::map<std::string, double> GetXS(std::string name);
int GetCutBin( std::vector<std::string> &CutOrder , std::string name);
double CalMT(TLorentzVector J1, TLorentzVector J2);
double CalMCT(TLorentzVector J1, TLorentzVector J2);
bool PrintEvent(NTupleReader *tr);;
std::vector<TLorentzVector> GetGenParticles(const std::vector<int> pdgid, const NTupleReader *tr);
bool PrintTLorentz(int event, std::string name, std::vector<TLorentzVector> obj);
bool PrintTopEvent( NTupleReader &tr, std::vector<TopDecay> &vTops);

void process_mem_usage(double& vm_usage, double& resident_set);
bool LTVMatch(TLorentzVector &V1, TLorentzVector V2, double dR=0.3);

//template<typename T, typename V> int FindVectorIdX(const T &TeV, const V &t);
int FindVectorIdX(std::vector<std::string> &TeV, std::string t);
int HasTLV(TLorentzVector &obj, std::vector<TLorentzVector> &TLVs);

//**************************************************************************//
//                            Register Functions                            //
//**************************************************************************//
void passBaselineTTZ(NTupleReader &tr);
bool TopWithoutBVeto(NTupleReader &tr, std::string spec);
void passBaselineZinv(NTupleReader &tr);
#endif   // ----- #ifndef MY_ROOTTOOLS_INC  -----
