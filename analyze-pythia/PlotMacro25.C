// FinalPlots.C
// ------------
// Takes histograms from analysis files and analyses them, and creates final plots of the desired histograms

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>
#include "TH1F.h"
#include "TDirectory.h"
#include "TTree.h"
#include "TString.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "TTreeReaderArray.h"
#include <vector>
#include <vector>
#include <math.h>


{

  // Load the analysis files
  // =======================
  //TFile fileLQ("$PWD/analysis.root");

  string ins = "$PWD/analyzed/";
  string combo = "combo";


  // Sam's test file

  TFile *filePythia = nullptr;
  combo = ins + "Wpythia21_test.root";
  filePythia = TFile::Open(combo.c_str(), "READ");

  // W boson files: 

  // TFile *filePythia = nullptr;
  // combo = ins + "WpythiaFidIncNCS.root";
  // filePythia = TFile::Open(combo.c_str(), "READ");

  // TFile *fileDurham = nullptr;
  // combo = ins + "DurhamPythiaS.root";
  // fileDurham = TFile::Open(combo.c_str(), "READ");

  // TFile *fileLund = nullptr;
  // combo = ins + "LundPythiaS.root";
  // fileLund = TFile::Open(combo.c_str(), "READ");

  // TFile *filePhase = nullptr;
  // combo = ins + "PhasePythiaS.root";
  // filePhase = TFile::Open(combo.c_str(), "READ");
  
  /*
  TFile *fileP26 = nullptr;
  combo = ins + "Wpythia26.root";
  fileP26 = TFile::Open(combo.c_str(), "READ");

  TFile *fileP27 = nullptr;
  combo = ins + "Wpythia27.root";
  fileP27 = TFile::Open(combo.c_str(), "READ");

  TFile *fileP28 = nullptr;
  combo = ins + "Wpythia28.root";
  fileP28 = TFile::Open(combo.c_str(), "READ");

  TFile *fileP29 = nullptr;
  combo = ins + "Wpythia29.root";
  fileP29 = TFile::Open(combo.c_str(), "READ");

  TFile *fileP30 = nullptr;
  combo = ins + "Wpythia30.root";
  fileP30 = TFile::Open(combo.c_str(), "READ");

  TFile *fileP31 = nullptr;
  combo = ins + "Wpythia31.root";
  fileP31 = TFile::Open(combo.c_str(), "READ");

  TFile *fileP32 = nullptr;
  combo = ins + "Wpythia32.root";
  fileP32 = TFile::Open(combo.c_str(), "READ");

  // With PTLW merging

  TFile *fileCPythia = nullptr;
  combo = ins + "PTLWpythia21.root";
  fileCPythia = TFile::Open(combo.c_str(), "READ");

  TFile *fileCP23 = nullptr;
  combo = ins + "PTLWpythia23.root";
  fileCP23 = TFile::Open(combo.c_str(), "READ");

  TFile *fileCP24 = nullptr;
  combo = ins + "PTLWpythia24.root";
  fileCP24 = TFile::Open(combo.c_str(), "READ");

  TFile *fileCP25 = nullptr;
  combo = ins + "PTLWpythia25.root";
  fileCP25 = TFile::Open(combo.c_str(), "READ");

  TFile *fileCP26 = nullptr;
  combo = ins + "PTLWpythia26.root";
  fileCP26 = TFile::Open(combo.c_str(), "READ");

  TFile *fileCP27 = nullptr;
  combo = ins + "PTLWpythia27.root";
  fileCP27 = TFile::Open(combo.c_str(), "READ");

  TFile *fileCP28 = nullptr;
  combo = ins + "PTLWpythia28.root";
  fileCP28 = TFile::Open(combo.c_str(), "READ");

  TFile *fileCP29 = nullptr;
  combo = ins + "PTLWpythia29.root";
  fileCP29 = TFile::Open(combo.c_str(), "READ");

  TFile *fileCP30 = nullptr;
  combo = ins + "PTLWpythia30.root";
  fileCP30 = TFile::Open(combo.c_str(), "READ");

  TFile *fileCP31 = nullptr;
  combo = ins + "PTLWpythia31.root";
  fileCP31 = TFile::Open(combo.c_str(), "READ");

  TFile *fileCP32 = nullptr;
  combo = ins + "PTLWpythia32.root";
  fileCP32 = TFile::Open(combo.c_str(), "READ");
  */
  /*

  TFile *fileP1 = nullptr;
  fileP1 = TFile::Open("$PWD/pythia21_1.root", "READ");

  TFile *fileP2 = nullptr;
  fileP2 = TFile::Open("$PWD/pythia21_2.root", "READ");

  TFile *fileP3 = nullptr;
  fileP3 = TFile::Open("$PWD/pythia21_3.root", "READ");

  TFile *fileP4 = nullptr;
  fileP4 = TFile::Open("$PWD/pythia21_4.root", "READ");

  TFile *fileP5 = nullptr;
  fileP5 = TFile::Open("$PWD/pythia21_5.root", "READ");

  TFile *fileP6 = nullptr;
  fileP6 = TFile::Open("$PWD/pythia21_6.root", "READ");

  TFile *fileD = nullptr;
  fileD = TFile::Open("$PWD/dire21.root", "READ");

  TFile *fileV = nullptr;
  fileV = TFile::Open("$PWD/vincia21.root", "READ");

  */

  //Z boson files:

  /*
  TFile *fileZP = nullptr;
  fileZP = TFile::Open("$PWD/Zpythia21_0.root", "READ");

  TFile *fileZP1 = nullptr;
  fileZP1 = TFile::Open("$PWD/Zpythia21_1.root", "READ");

  TFile *fileZP2 = nullptr;
  fileZP2 = TFile::Open("$PWD/Zpythia21_2.root", "READ");

  TFile *fileZP3 = nullptr;
  fileZP3 = TFile::Open("$PWD/Zpythia21_3.root", "READ");

  TFile *fileZP4 = nullptr;
  fileZP4 = TFile::Open("$PWD/Zpythia21_4.root", "READ");

  TFile *fileZP5 = nullptr;
  fileZP5 = TFile::Open("$PWD/Zpythia21_5.root", "READ");

  TFile *fileZP6 = nullptr;
  fileZP6 = TFile::Open("$PWD/Zpythia21_6.root", "READ");
  

  TFile *fileZP21 = nullptr;
  combo = ins + "Zpythia21.root";
  fileZP21 = TFile::Open(combo.c_str(), "READ");

  TFile *fileZP23 = nullptr;
  combo = ins + "Zpythia23.root";
  fileZP23 = TFile::Open(combo.c_str(), "READ");

  TFile *fileZP24 = nullptr;
  combo = ins + "Zpythia24.root";
  fileZP24 = TFile::Open(combo.c_str(), "READ");

  TFile *fileZP25 = nullptr;
  combo = ins + "Zpythia25.root";
  fileZP25 = TFile::Open(combo.c_str(), "READ");

  TFile *fileZP26 = nullptr;
  combo = ins + "Zpythia26.root";
  fileZP26 = TFile::Open(combo.c_str(), "READ");

  TFile *fileZP27 = nullptr;
  combo = ins + "Zpythia27.root";
  fileZP27 = TFile::Open(combo.c_str(), "READ");

  TFile *fileZP28 = nullptr;
  combo = ins + "Zpythia28.root";
  fileZP28 = TFile::Open(combo.c_str(), "READ");

  TFile *fileZP29 = nullptr;
  combo = ins + "Zpythia29.root";
  fileZP29 = TFile::Open(combo.c_str(), "READ");

  TFile *fileZP30 = nullptr;
  combo = ins + "Zpythia30.root";
  fileZP30 = TFile::Open(combo.c_str(), "READ");

  TFile *fileZP31 = nullptr;
  combo = ins + "Zpythia31.root";
  fileZP31 = TFile::Open(combo.c_str(), "READ");

  TFile *fileZP32 = nullptr;
  combo = ins + "Zpythia32.root";
  fileZP32 = TFile::Open(combo.c_str(), "READ");

  // With CKKW merging

  TFile *fileCZP21 = nullptr;
  combo = ins + "CKKZpythia21.root";
  fileCZP21 = TFile::Open(combo.c_str(), "READ");

  TFile *fileCZP23 = nullptr;
  combo = ins + "CKKZpythia23.root";
  fileCZP23 = TFile::Open(combo.c_str(), "READ");

  TFile *fileCZP24 = nullptr;
  combo = ins + "CKKZpythia24.root";
  fileCZP24 = TFile::Open(combo.c_str(), "READ");

  TFile *fileCZP25 = nullptr;
  combo = ins + "CKKZpythia25.root";
  fileCZP25 = TFile::Open(combo.c_str(), "READ");

  TFile *fileCZP26 = nullptr;
  combo = ins + "CKKZpythia26.root";
  fileCZP26 = TFile::Open(combo.c_str(), "READ");

  TFile *fileCZP27 = nullptr;
  combo = ins + "CKKZpythia27.root";
  fileCZP27 = TFile::Open(combo.c_str(), "READ");

  TFile *fileCZP28 = nullptr;
  combo = ins + "CKKZpythia28.root";
  fileCZP28 = TFile::Open(combo.c_str(), "READ");

  TFile *fileCZP29 = nullptr;
  combo = ins + "CKKZpythia29.root";
  fileCZP29 = TFile::Open(combo.c_str(), "READ");

  TFile *fileCZP30 = nullptr;
  combo = ins + "CKKZpythia30.root";
  fileCZP30 = TFile::Open(combo.c_str(), "READ");

  TFile *fileCZP31 = nullptr;
  combo = ins + "CKKZpythia31.root";
  fileCZP31 = TFile::Open(combo.c_str(), "READ");

  TFile *fileCZP32 = nullptr;
  combo = ins + "CKKZpythia32.root";
  fileCZP32 = TFile::Open(combo.c_str(), "READ");
  */

  /*
  TFile *fileZD = nullptr;
  fileZD = TFile::Open("$PWD/Zdire21.root", "READ");

  TFile *fileZV = nullptr;
  fileZV = TFile::Open("$PWD/Zvincia21.root", "READ");


  // Z files with mass changed: 

  TFile *fileZMP = nullptr;
  fileZMP = TFile::Open("$PWD/ZMpythia21_0.root", "READ");

  TFile *fileZMP1 = nullptr;
  fileZMP1 = TFile::Open("$PWD/ZMpythia21_1.root", "READ");

  TFile *fileZMP2 = nullptr;
  fileZMP2 = TFile::Open("$PWD/ZMpythia21_2.root", "READ");

  TFile *fileZMP3 = nullptr;
  fileZMP3 = TFile::Open("$PWD/ZMpythia21_3.root", "READ");

  TFile *fileZMP4 = nullptr;
  fileZMP4 = TFile::Open("$PWD/ZMpythia21_4.root", "READ");

  TFile *fileZMP5 = nullptr;
  fileZMP5 = TFile::Open("$PWD/ZMpythia21_5.root", "READ");

  TFile *fileZMP6 = nullptr;
  fileZMP6 = TFile::Open("$PWD/ZMpythia21_6.root", "READ");




  TFile *fileZMP23 = nullptr;
  fileZMP23 = TFile::Open("$PWD/ZMpythia23.root", "READ");

  TFile *fileZMP24 = nullptr;
  fileZMP24 = TFile::Open("$PWD/ZMpythia24.root", "READ");

  TFile *fileZMP25 = nullptr;
  fileZMP25 = TFile::Open("$PWD/ZMpythia25.root", "READ");

  TFile *fileZMP26 = nullptr;
  fileZMP26 = TFile::Open("$PWD/ZMpythia26.root", "READ");

  TFile *fileZMP27 = nullptr;
  fileZMP27 = TFile::Open("$PWD/ZMpythia27.root", "READ");

  TFile *fileZMP28 = nullptr;
  fileZMP28 = TFile::Open("$PWD/ZMpythia28.root", "READ");

  TFile *fileZMP29 = nullptr;
  fileZMP29 = TFile::Open("$PWD/ZMpythia29.root", "READ");

  TFile *fileZMP30 = nullptr;
  fileZMP30 = TFile::Open("$PWD/ZMpythia30.root", "READ");

  TFile *fileZMP31 = nullptr;
  fileZMP31 = TFile::Open("$PWD/ZMpythia31.root", "READ");

  TFile *fileZMP32 = nullptr;
  fileZMP32 = TFile::Open("$PWD/ZMpythia32.root", "READ");




  TFile *fileZMD = nullptr;
  fileZMD = TFile::Open("$PWD/ZMdire21.root", "READ");

  TFile *fileZMV = nullptr;
  fileZMV = TFile::Open("$PWD/ZMvincia21.root", "READ");  
  */

  // Get the histograms
  // ==================

    // From Leptoquark events
    // ----------------------
    
  TH1F *NjetTrue_LQ_P  = (TH1F*)filePythia->Get("NumberTrueJet");
  TH1F *LeadJetPt_LQ_P = (TH1F*)filePythia->Get("LeadTrueJet_inc_pt");
  TH1F *DimuMass_LQ_P  = (TH1F*)filePythia->Get("TrueDimuon_M");

  std::cout<<"Got histograms for leptoquark events!";

	// BSJ additions:



  // W boson histograms:

  // Truth:
	TH1F *TrueWMT_P = (TH1F*)filePythia->Get("TrueWMT");
	TH1F *TrueWPT_P = (TH1F*)filePythia->Get("TrueWPT");
  TH1F *TrueMet_P = (TH1F*)filePythia->Get("TrueMetHist");
  TH1F *TrueWRap_P = (TH1F*)filePythia->Get("TrueWRap");

  // Reco:
	TH1F *RecoWMT_P = (TH1F*)filePythia->Get("RecoWMT");
	TH1F *RecoWPT_P = (TH1F*)filePythia->Get("RecoWPT");
  TH1F *RecoMet_P = (TH1F*)filePythia->Get("RecoMetHist");

  std::cout<<"Got histograms for W boson events!";

  // W boson histograms with CKKW merge:

  // Truth:
  // TH1F *TruePTLWMT_D = (TH1F*)fileDurham->Get("TrueWMT");
	// TH1F *TruePTLWPT_D = (TH1F*)fileDurham->Get("TrueWPT");
  // TH1F *TruePTLWMet_D = (TH1F*)fileDurham->Get("TrueMetHist");
  // TH1F *TruePTLWRap_D = (TH1F*)fileDurham->Get("TrueWRap");

  // TH1F *TruePTLWMT_L = (TH1F*)fileLund->Get("TrueWMT");
	// TH1F *TruePTLWPT_L = (TH1F*)fileLund->Get("TrueWPT");
  // TH1F *TruePTLWMet_L = (TH1F*)fileLund->Get("TrueMetHist");
  // TH1F *TruePTLWRap_L = (TH1F*)fileLund->Get("TrueWRap");

  // TH1F *TruePTLWMT_K = (TH1F*)filePhase->Get("TrueWMT");
	// TH1F *TruePTLWPT_K = (TH1F*)filePhase->Get("TrueWPT");
  // TH1F *TruePTLWMet_K = (TH1F*)filePhase->Get("TrueMetHist");
  // TH1F *TruePTLWRap_K = (TH1F*)filePhase->Get("TrueWRap");



  // Lepton histograms:

  // Truth: 
  TH1F *TrueLeadLepPt_P = (TH1F*)filePythia->Get("TrueLeadEPt");
  TH1F *TrueLeadLepRap_P = (TH1F*)filePythia->Get("TrueLeadERap");

  // Reco: 
  TH1F *RecoLeadLepPt_P = (TH1F*)filePythia->Get("RecoLeadEPt");

  std::cout<<"Got histograms for lepton events!";

  //TH1F *RecoLeadLepRap_P = (TH1F*)filePythia->Get("RecoLeadERap"); (not implemented in analysis [yet])

  // With CKKW merging:

  // Truth:
  // TH1F *TrueLeadLepPt_D = (TH1F*)fileDurham->Get("TrueLeadEPt");
  // TH1F *TrueLeadLepRap_D = (TH1F*)fileDurham->Get("TrueLeadERap");

  // // Reco:
  // TH1F *RecoLeadLepPt_D = (TH1F*)fileDurham->Get("RecoLeadEPt");

  // // Truth:
  // TH1F *TrueLeadLepPt_L = (TH1F*)fileLund->Get("TrueLeadEPt");
  // TH1F *TrueLeadLepRap_L = (TH1F*)fileLund->Get("TrueLeadERap");

  // // Reco:
  // TH1F *RecoLeadLepPt_L = (TH1F*)fileLund->Get("RecoLeadEPt");

  // // Truth:
  // TH1F *TrueLeadLepPt_K = (TH1F*)filePhase->Get("TrueLeadEPt");
  // TH1F *TrueLeadLepRap_K = (TH1F*)filePhase->Get("TrueLeadERap");

  // // Reco:
  // TH1F *RecoLeadLepPt_K = (TH1F*)filePhase->Get("RecoLeadEPt");


  /*
  TH1F *TrueWPT_LQ_D = (TH1F*)fileD->Get("TrueWPT");
  TH1F *TrueWRap_LQ_D = (TH1F*)fileD->Get("TrueWRap");

  TH1F *TrueWPT_LQ_V = (TH1F*)fileV->Get("TrueWPT");
  TH1F *TrueWRap_LQ_V = (TH1F*)fileV->Get("TrueWRap");


  TH1F *TrueLeadLepPt_LQ_D = (TH1F*)fileD->Get("TrueLeadLepPt");
  TH1F *TrueLeadLepRap_LQ_D = (TH1F*)fileD->Get("TrueLeadLepRap");


  TH1F *TrueLeadLepPt_LQ_V = (TH1F*)fileV->Get("TrueLeadLepPt");
  TH1F *TrueLeadLepRap_LQ_V = (TH1F*)fileV->Get("TrueLeadLepRap");

  TH1F *TrueWPT_LQ_P1 = (TH1F*)fileP1->Get("TrueWPT");
  TH1F *TrueWPT_LQ_P2 = (TH1F*)fileP2->Get("TrueWPT");
  TH1F *TrueWPT_LQ_P3 = (TH1F*)fileP3->Get("TrueWPT");
  TH1F *TrueWPT_LQ_P4 = (TH1F*)fileP4->Get("TrueWPT");
  TH1F *TrueWPT_LQ_P5 = (TH1F*)fileP5->Get("TrueWPT");
  TH1F *TrueWPT_LQ_P6 = (TH1F*)fileP6->Get("TrueWPT");
  */

  /*
  // W+jets pp tunes:
  TH1F *TrueWPT_P23 = (TH1F*)fileP23->Get("TrueWPT");
  TH1F *TrueWPT_P24 = (TH1F*)fileP24->Get("TrueWPT");
  TH1F *TrueWPT_P25 = (TH1F*)fileP25->Get("TrueWPT");
  TH1F *TrueWPT_P26 = (TH1F*)fileP26->Get("TrueWPT");
  TH1F *TrueWPT_P27 = (TH1F*)fileP27->Get("TrueWPT");
  TH1F *TrueWPT_P28 = (TH1F*)fileP28->Get("TrueWPT");
  TH1F *TrueWPT_P29 = (TH1F*)fileP29->Get("TrueWPT");
  TH1F *TrueWPT_P30 = (TH1F*)fileP30->Get("TrueWPT");
  TH1F *TrueWPT_P31 = (TH1F*)fileP31->Get("TrueWPT");
  TH1F *TrueWPT_P32 = (TH1F*)fileP32->Get("TrueWPT");
  */

  /*
  TH1F *TrueWRap_LQ_P1 = (TH1F*)fileP1->Get("TrueWRap");

  TH1F *TrueWRap_LQ_P2 = (TH1F*)fileP2->Get("TrueWRap");

  TH1F *TrueWRap_LQ_P3 = (TH1F*)fileP3->Get("TrueWRap");

  TH1F *TrueWRap_LQ_P4 = (TH1F*)fileP4->Get("TrueWRap");

  TH1F *TrueWRap_LQ_P5 = (TH1F*)fileP5->Get("TrueWRap");

  TH1F *TrueWRap_LQ_P6 = (TH1F*)fileP6->Get("TrueWRap");
  */

  /*
  TH1F *TrueWRap_P23 = (TH1F*)fileP23->Get("TrueWRap");
  TH1F *TrueWRap_P24 = (TH1F*)fileP24->Get("TrueWRap");
  TH1F *TrueWRap_P25 = (TH1F*)fileP25->Get("TrueWRap");
  TH1F *TrueWRap_P26 = (TH1F*)fileP26->Get("TrueWRap");
  TH1F *TrueWRap_P27 = (TH1F*)fileP27->Get("TrueWRap");
  TH1F *TrueWRap_P28 = (TH1F*)fileP28->Get("TrueWRap");
  TH1F *TrueWRap_P29 = (TH1F*)fileP29->Get("TrueWRap");
  TH1F *TrueWRap_P30 = (TH1F*)fileP30->Get("TrueWRap");
  TH1F *TrueWRap_P31 = (TH1F*)fileP31->Get("TrueWRap");
  TH1F *TrueWRap_P32 = (TH1F*)fileP32->Get("TrueWRap");
  */

  // TH1F *LeadJetPt_P = (TH1F*)filePythia->Get("LeadTrueJet_inc_pt");

  // TH1F *LeadJetPt_D = (TH1F*)fileDurham->Get("LeadTrueJet_inc_pt");
  // TH1F *LeadJetPt_L = (TH1F*)fileLund->Get("LeadTrueJet_inc_pt");
  // TH1F *LeadJetPt_K = (TH1F*)filePhase->Get("LeadTrueJet_inc_pt");

  /*
  TH1F *LeadJetPt_LQ_P1 = (TH1F*)fileP1->Get("LeadTrueJet_inc_pt");

  TH1F *LeadJetPt_LQ_P2 = (TH1F*)fileP2->Get("LeadTrueJet_inc_pt");

  TH1F *LeadJetPt_LQ_P3 = (TH1F*)fileP3->Get("LeadTrueJet_inc_pt");

  TH1F *LeadJetPt_LQ_P4 = (TH1F*)fileP4->Get("LeadTrueJet_inc_pt");

  TH1F *LeadJetPt_LQ_P5 = (TH1F*)fileP5->Get("LeadTrueJet_inc_pt");

  TH1F *LeadJetPt_LQ_P6 = (TH1F*)fileP6->Get("LeadTrueJet_inc_pt");


  TH1F *LeadJetPt_LQ_D = (TH1F*)fileD->Get("LeadTrueJet_inc_pt");

  TH1F *LeadJetPt_LQ_V = (TH1F*)fileV->Get("LeadTrueJet_inc_pt");

  */


  // TH1F *LeadJetRap_P = (TH1F*)filePythia->Get("LeadTrueJet_inc_rap");

  // TH1F *LeadJetRap_D = (TH1F*)fileDurham->Get("LeadTrueJet_inc_rap");
  // TH1F *LeadJetRap_L = (TH1F*)fileLund->Get("LeadTrueJet_inc_rap");
  // TH1F *LeadJetRap_K = (TH1F*)filePhase->Get("LeadTrueJet_inc_rap");

  /*
  TH1F *LeadJetRap_LQ_P1 = (TH1F*)fileP1->Get("LeadTrueJet_inc_rap");

  TH1F *LeadJetRap_LQ_P2 = (TH1F*)fileP2->Get("LeadTrueJet_inc_rap");
  
  TH1F *LeadJetRap_LQ_P3 = (TH1F*)fileP3->Get("LeadTrueJet_inc_rap");

  TH1F *LeadJetRap_LQ_P4 = (TH1F*)fileP4->Get("LeadTrueJet_inc_rap");
  
  TH1F *LeadJetRap_LQ_P5 = (TH1F*)fileP5->Get("LeadTrueJet_inc_rap");

  TH1F *LeadJetRap_LQ_P6 = (TH1F*)fileP6->Get("LeadTrueJet_inc_rap");


  TH1F *LeadJetRap_LQ_D = (TH1F*)fileD->Get("LeadTrueJet_inc_rap");

  TH1F *LeadJetRap_LQ_V = (TH1F*)fileV->Get("LeadTrueJet_inc_rap");
  */


  // Z boson histograms:

  // Truth:
  //TH1F *TrueZPt_ZP = (TH1F*)fileZP21->Get("TrueZPt");
  //TH1F *TrueZRap_ZP = (TH1F*)fileZP21->Get("TrueZRap");

  /*
  TH1F *TrueZPt_ZD = (TH1F*)fileZD->Get("TrueZPt");

  TH1F *TrueZPt_ZV = (TH1F*)fileZV->Get("TrueZPt");

  TH1F *TrueZRap_ZD = (TH1F*)fileZD->Get("TrueZRap");

  TH1F *TrueZRap_ZV = (TH1F*)fileZV->Get("TrueZRap");



  TH1F *TrueZPt_ZP1 = (TH1F*)fileZP1->Get("TrueZPt");

  TH1F *TrueZPt_ZP2 = (TH1F*)fileZP2->Get("TrueZPt");

  TH1F *TrueZPt_ZP3 = (TH1F*)fileZP3->Get("TrueZPt");

  TH1F *TrueZPt_ZP4 = (TH1F*)fileZP4->Get("TrueZPt");

  TH1F *TrueZPt_ZP5 = (TH1F*)fileZP5->Get("TrueZPt");

  TH1F *TrueZPt_ZP6 = (TH1F*)fileZP6->Get("TrueZPt");

  TH1F *TrueZRap_ZP1 = (TH1F*)fileZP1->Get("TrueZRap");

  TH1F *TrueZRap_ZP2 = (TH1F*)fileZP2->Get("TrueZRap");

  TH1F *TrueZRap_ZP3 = (TH1F*)fileZP3->Get("TrueZRap");

  TH1F *TrueZRap_ZP4 = (TH1F*)fileZP4->Get("TrueZRap");

  TH1F *TrueZRap_ZP5 = (TH1F*)fileZP5->Get("TrueZRap");

  TH1F *TrueZRap_ZP6 = (TH1F*)fileZP6->Get("TrueZRap");
  */

  // Z+jets pp tunes:
  /*
  TH1F *TrueZPt_ZP23 = (TH1F*)fileZP23->Get("TrueZPt");
  TH1F *TrueZPt_ZP24 = (TH1F*)fileZP24->Get("TrueZPt");
  TH1F *TrueZPt_ZP25 = (TH1F*)fileZP25->Get("TrueZPt");
  TH1F *TrueZPt_ZP26 = (TH1F*)fileZP26->Get("TrueZPt");
  TH1F *TrueZPt_ZP27 = (TH1F*)fileZP27->Get("TrueZPt");
  TH1F *TrueZPt_ZP28 = (TH1F*)fileZP28->Get("TrueZPt");
  TH1F *TrueZPt_ZP29 = (TH1F*)fileZP29->Get("TrueZPt");
  TH1F *TrueZPt_ZP30 = (TH1F*)fileZP30->Get("TrueZPt");
  TH1F *TrueZPt_ZP31 = (TH1F*)fileZP31->Get("TrueZPt");
  TH1F *TrueZPt_ZP32 = (TH1F*)fileZP32->Get("TrueZPt");

  TH1F *TrueZRap_ZP23 = (TH1F*)fileZP23->Get("TrueZRap");
  TH1F *TrueZRap_ZP24 = (TH1F*)fileZP24->Get("TrueZRap");
  TH1F *TrueZRap_ZP25 = (TH1F*)fileZP25->Get("TrueZRap");
  TH1F *TrueZRap_ZP26 = (TH1F*)fileZP26->Get("TrueZRap");
  TH1F *TrueZRap_ZP27 = (TH1F*)fileZP27->Get("TrueZRap");
  TH1F *TrueZRap_ZP28 = (TH1F*)fileZP28->Get("TrueZRap");
  TH1F *TrueZRap_ZP29 = (TH1F*)fileZP29->Get("TrueZRap");
  TH1F *TrueZRap_ZP30 = (TH1F*)fileZP30->Get("TrueZRap");
  TH1F *TrueZRap_ZP31 = (TH1F*)fileZP31->Get("TrueZRap");
  TH1F *TrueZRap_ZP32 = (TH1F*)fileZP32->Get("TrueZRap");
  */

  // Z boson histograms, mass changed: 

  /*
  TH1F *TrueZPt_ZMP = (TH1F*)fileZMP->Get("TrueZPt");
  TH1F *TrueZRap_ZMP = (TH1F*)fileZMP->Get("TrueZRap");
  TH1F *TrueZPt_ZMD = (TH1F*)fileZMD->Get("TrueZPt");
  TH1F *TrueZPt_ZMV = (TH1F*)fileZMV->Get("TrueZPt");
  TH1F *TrueZRap_ZMD = (TH1F*)fileZMD->Get("TrueZRap");
  TH1F *TrueZRap_ZMV = (TH1F*)fileZMV->Get("TrueZRap");



  TH1F *TrueZPt_ZMP1 = (TH1F*)fileZMP1->Get("TrueZPt");
  TH1F *TrueZPt_ZMP2 = (TH1F*)fileZMP2->Get("TrueZPt");
  TH1F *TrueZPt_ZMP3 = (TH1F*)fileZMP3->Get("TrueZPt");
  TH1F *TrueZPt_ZMP4 = (TH1F*)fileZMP4->Get("TrueZPt");
  TH1F *TrueZPt_ZMP5 = (TH1F*)fileZMP5->Get("TrueZPt");
  TH1F *TrueZPt_ZMP6 = (TH1F*)fileZMP6->Get("TrueZPt");
  TH1F *TrueZRap_ZMP1 = (TH1F*)fileZMP1->Get("TrueZRap");
  TH1F *TrueZRap_ZMP2 = (TH1F*)fileZMP2->Get("TrueZRap");
  TH1F *TrueZRap_ZMP3 = (TH1F*)fileZMP3->Get("TrueZRap");
  TH1F *TrueZRap_ZMP4 = (TH1F*)fileZMP4->Get("TrueZRap");
  TH1F *TrueZRap_ZMP5 = (TH1F*)fileZMP5->Get("TrueZRap");
  TH1F *TrueZRap_ZMP6 = (TH1F*)fileZMP6->Get("TrueZRap");



  TH1F *TrueZPt_ZMP23 = (TH1F*)fileZMP23->Get("TrueZPt");
  TH1F *TrueZPt_ZMP24 = (TH1F*)fileZMP24->Get("TrueZPt");
  TH1F *TrueZPt_ZMP25 = (TH1F*)fileZMP25->Get("TrueZPt");
  TH1F *TrueZPt_ZMP26 = (TH1F*)fileZMP26->Get("TrueZPt");
  TH1F *TrueZPt_ZMP27 = (TH1F*)fileZMP27->Get("TrueZPt");
  TH1F *TrueZPt_ZMP28 = (TH1F*)fileZMP28->Get("TrueZPt");
  TH1F *TrueZPt_ZMP29 = (TH1F*)fileZMP29->Get("TrueZPt");
  TH1F *TrueZPt_ZMP30 = (TH1F*)fileZMP30->Get("TrueZPt");
  TH1F *TrueZPt_ZMP31 = (TH1F*)fileZMP31->Get("TrueZPt");
  TH1F *TrueZPt_ZMP32 = (TH1F*)fileZMP32->Get("TrueZPt");



  TH1F *TrueZRap_ZMP23 = (TH1F*)fileZMP23->Get("TrueZRap");
  TH1F *TrueZRap_ZMP24 = (TH1F*)fileZMP24->Get("TrueZRap");
  TH1F *TrueZRap_ZMP25 = (TH1F*)fileZMP25->Get("TrueZRap");
  TH1F *TrueZRap_ZMP26 = (TH1F*)fileZMP26->Get("TrueZRap");
  TH1F *TrueZRap_ZMP27 = (TH1F*)fileZMP27->Get("TrueZRap");
  TH1F *TrueZRap_ZMP28 = (TH1F*)fileZMP28->Get("TrueZRap");
  TH1F *TrueZRap_ZMP29 = (TH1F*)fileZMP29->Get("TrueZRap");
  TH1F *TrueZRap_ZMP30 = (TH1F*)fileZMP30->Get("TrueZRap");
  TH1F *TrueZRap_ZMP31 = (TH1F*)fileZMP31->Get("TrueZRap");
  TH1F *TrueZRap_ZMP32 = (TH1F*)fileZMP32->Get("TrueZRap");
  */
  

  /*
  // Z boson histograms with CKKW merge:
  TH1F *TrueCKKZMT_ZP = (TH1F*)fileCZP21->Get("TrueWMT");
	TH1F *TrueCKKZPT_ZP = (TH1F*)fileCZP21->Get("TrueZPt");
  TH1F *TrueCKKZMet_ZP = (TH1F*)fileCZP21->Get("TrueMetHist");
  TH1F *TrueCKKZRap_ZP = (TH1F*)fileCZP21->Get("TrueZRap");
  */

  // Divide histograms by bin size when not uniform
  // ==============================================
  
  
  //LeadJetPt_LQ_P->Scale(1,"width");
  



  // Create Canvas
  // =============
    
  TCanvas *c1 = new TCanvas("c1","Njets shape plot",800,600);
  
  TCanvas *c2 = new TCanvas("c2","Pt lead jets shape plot",800,600);
  TCanvas *c3 = new TCanvas("c3","Mll shape plot",800,600);
  
  TCanvas *c4 = new TCanvas("c4","Njets stack plot",800,600);
  TCanvas *c5 = new TCanvas("c5","Pt lead jets stack plot",800,600);
  TCanvas *c6 = new TCanvas("c6","Mll stack plot",800,600);


	// BSJ additions:
	TCanvas *c7 = new TCanvas("c7", "True WMT plot", 800, 600);
	TCanvas *c8 = new TCanvas("c8", "Reco WMT plot", 800, 600);
	TCanvas *c9 = new TCanvas("c9", "True Lead Lep Pt plot", 800, 600);
	TCanvas *c10 = new TCanvas("c10", "Reco Lead Lep Pt plot", 800, 600);
	TCanvas *c11 = new TCanvas("c11", "True WPT plot", 800, 600);
  TCanvas *c12 = new TCanvas("c12", "Reco WPT plot", 800, 600);
  TCanvas *c13 = new TCanvas("c13", "True Met plot", 800, 600);
  TCanvas *c14 = new TCanvas("c14", "Reco Met plot", 800, 600);	



  
  gStyle->SetOptStat(0);

  std::cout<<"Created canvases...";


  // Normalize histograms
  // ====================

     // Note 1: To compare shape, we need to normalize histograms to the same integral
     //         (set to 1. for simplicity), but to compare predictions to data, they need
     //         to be normalized to the same luminosity as in data (assume here 100pb-1).
     //         There are therefore two different normalization factors that need to be
     //         calculated.

     // Note 2: We will clone the above histograms to apply without ambiguity to the
     //         normalizations.


  
     // Normalize histograms to unit integral
     // -------------------------------------


  // TH1F *NjetTrue_LQ_unit  = (TH1F*) NjetTrue_LQ_P->Clone();
  // float NjetTrue_LQ_scale = NjetTrue_LQ_unit->Integral();
  // NjetTrue_LQ_unit->Scale(1./NjetTrue_LQ_scale);

  //TH1F *LeadJetPt_LQ_unit  = (TH1F*) LeadJetPt_LQ_P->Clone();
  //float LeadJetPt_LQ_scale = LeadJetPt_LQ_unit->Integral();
  //LeadJetPt_LQ_unit->Scale(1./LeadJetPt_LQ_scale);
  
  // TH1F *DimuMass_LQ_unit  = (TH1F*) DimuMass_LQ_P->Clone();
  // float DimuMass_LQ_scale = DimuMass_LQ_unit->Integral();
  // DimuMass_LQ_unit->Scale(1./DimuMass_LQ_scale);

  

  
  
     // Normalize histograms to data luminosity
     // ---------------------------------------

       // Note: The cross sections are not the same for each processes, and the number
       //       of generated events was arbitrary. This means that the luminosity
       //       corresponding to each channel is not the same. To calculate the weight
       //       to be applied, consider the following example for Zmm:
       //
       //       xsct =  23.86pb, Nevents = 2000 => L = 83.8 pb-1
       //
       //       Let choose to normalize to 100 pb-1 of data => scale_Zmm = 100/83.8 = 1.193
       //
       //       For ttbar: xsect = 3.59pb, Nevents = 2000 => L = 557.1  =>  scale_ttbar = 0.1795
       //       For LQ:    xsect = 0.05pb, Nevents = 2000 => L = 40,000 =>  scale_lq = 0.0025 

  NjetTrue_LQ_P->Scale(0.0025);
  //LeadJetPt_LQ_P->Scale(0.0025);
  DimuMass_LQ_P->Scale(0.0025);

  

  // Create Stack Plots
  // ==================

  THStack* NjetTrue  = new THStack("NjetTrue", "Njets: signal + backrgound");
  //THStack* LeadJetPtTrue  = new THStack("LeadJetPtTrue", "LeadJet Pt: signal + backrgound");
  THStack* DimuMassTrue  = new THStack("DimuMassTrue", "Dimuon Mass: signal + backrgound");


  
  // Make plots
  // ==========


    // Shape Comparisons between various processes
    // -------------------------------------------

       // Note: The color code is: 1=black, 2=red, 3=green
  
  // Njets
  /*
  c1->cd();

  
  
  NjetTrue_LQ_unit->GetXaxis()->SetTitle("Njets");
  NjetTrue_LQ_unit->GetYaxis()->SetTitle("d#sigma / dN_{jets}");
  
  NjetTrue_LQ_unit->SetMarkerStyle(4);
  NjetTrue_LQ_unit->SetMarkerColor(3);
  NjetTrue_LQ_unit->SetLineColor(3);
  NjetTrue_LQ_unit->SetLineWidth(3);
  NjetTrue_LQ_unit->Draw("P same");

  
  auto legend_C1 = new TLegend(0.6, 0.60, 0.9, 0.89);
  legend_C1->AddEntry(NjetTrue_LQ_unit,"Leptoquark","f");
  legend_C1->SetTextSize(0.035);
  legend_C1->Draw();
  
  
  c1->Print("./plots/LeadJetPt_unit.png");

  
  

  // Lead Jet Pt
  
  //c2->cd();

  //LeadJetPt_LQ_unit->GetXaxis()->SetTitle("p_{T}^{leadjet}");
  //LeadJetPt_LQ_unit->GetYaxis()->SetTitle("d#sigma / dp_{T}^{jet}");
  
  //LeadJetPt_LQ_unit->SetMarkerStyle(4);
  //LeadJetPt_LQ_unit->SetMarkerColor(3);
  //LeadJetPt_LQ_unit->SetLineColor(3);
  //LeadJetPt_LQ_unit->SetLineWidth(3);
  //LeadJetPt_LQ_unit->Draw("P same");

  
  //auto legend_C2 = new TLegend(0.6, 0.60, 0.9, 0.89);
  //legend_C2->AddEntry(LeadJetPt_LQ_unit,"Leptoquark","f");
  //legend_C2->SetTextSize(0.035);
  //legend_C2->Draw();

  //c2->Print("./plots/LeadJetPt_unit.png");


  
  // Dimuon Mass
  
  c3->cd();

  DimuMass_LQ_unit->GetXaxis()->SetTitle("M_{#ell#ell}");
  DimuMass_LQ_unit->GetYaxis()->SetTitle("d#sigma / dM_{#ell#ell}");
  
  DimuMass_LQ_unit->SetMarkerStyle(4);
  DimuMass_LQ_unit->SetMarkerColor(3);
  DimuMass_LQ_unit->SetLineColor(3);
  DimuMass_LQ_unit->SetLineWidth(3);
  DimuMass_LQ_unit->Draw("P same");


  auto legend_C3 = new TLegend(0.6, 0.60, 0.9, 0.89);
  legend_C3->AddEntry(DimuMass_LQ_unit,"Leptoquark","f");
  legend_C3->SetTextSize(0.035);
  legend_C3->Draw();

  c3->Print("./plots/DimuMass_unit.png");

  
  
    // Stack plots
    // -----------

  
  // Njets
  
  c4->cd();

  gPad->SetLogy(); 


  NjetTrue_LQ_P->SetFillColor(3);
  NjetTrue->Add(NjetTrue_LQ_P, "hist");

  NjetTrue->Draw();

  NjetTrue->GetXaxis()->SetTitle("Njets");
  NjetTrue->GetYaxis()->SetTitle("d#sigma / dN_{jets}");


  auto legend_C4 = new TLegend(0.6, 0.60, 0.9, 0.89);
  legend_C4->AddEntry(NjetTrue_LQ_P,"Leptoquark","f");
  legend_C4->SetTextSize(0.035);
  legend_C4->Draw();

  c4->Print("./plots/NjetTrue.png");

  

    // Lead Jet Pt

  
  //c5->cd();

  //gPad->SetLogy(); 

  //LeadJetPt_LQ_P->SetFillColor(3);
  //LeadJetPtTrue->Add(LeadJetPt_LQ_P, "hist");

  //LeadJetPtTrue->Draw();

  //LeadJetPtTrue->GetXaxis()->SetTitle("p_{T}^{leadjet}");
  //LeadJetPtTrue->GetYaxis()->SetTitle("d#sigma / dp_{T}^{jet}");


  //auto legend_C5 = new TLegend(0.6, 0.60, 0.9, 0.89);
  //legend_C5->AddEntry(LeadJetPt_LQ_P,"Leptoquark","f");
  //legend_C5->SetTextSize(0.035);
  //legend_C5->Draw();

  //c5->Print("./plots/LeadJetPt.png");



    // Dimuon Mass
  
  //c6->cd();

  //gPad->SetLogy(); 

  //DimuMass_LQ->SetFillColor(3);
  //DimuMassTrue->Add(DimuMass_LQ, "hist");


  //DimuMassTrue->Draw();

  //DimuMassTrue->GetXaxis()->SetTitle("M_{#ell#ell}");
  //DimuMassTrue->GetYaxis()->SetTitle("d#sigma / dM_{#ell#ell}");


  //auto legend_C6 = new TLegend(0.6, 0.60, 0.9, 0.89);
  //legend_C6->AddEntry(DimuMass_LQ,"Leptoquark","f");
  //legend_C6->SetTextSize(0.035);
  //legend_C6->Draw();

  //c6->Print("./plots/DimuMass.png");
  */

  // =========================================================================================== //

	// BSJ additions:

  // Lines for ratio plots
  
  // Pt etc.
  line17 = TLine(0, 1, 250, 1);
  line17.SetLineStyle(kDashed);
  line17.SetLineColor(kRed);
  line18 = TLine(0, 1, 1000, 1);
  line18.SetLineStyle(kDashed);
  line18.SetLineColor(kRed);
  
  // Rapidity
  TLine *lineRap = new TLine(-5, 1, 5, 1);
  lineRap->SetLineStyle(kDashed);
  lineRap->SetLineColor(kRed);
  
  // Boson transverse mass
	c7->cd();
  TrueWMT_P->Scale(1./(TrueWMT_P->Integral()));
  TruePTLWMT_D->Scale(1./(TruePTLWMT_D->Integral()));
  TruePTLWMT_K->Scale(1./(TruePTLWMT_K->Integral()));
  TruePTLWMT_L->Scale(1./(TruePTLWMT_L->Integral()));
	TrueWMT_P->GetXaxis()->SetTitle("Mass");
	TrueWMT_P->GetYaxis()->SetTitle("Count");
  TrueWMT_P->SetLineColor(kRed);
  TruePTLWMT_D->SetLineColor(kBlue);
  TruePTLWMT_K->SetLineColor(kGreen);
  TruePTLWMT_L->SetLineColor(kOrange);
  THStack *hs7 = new THStack("hs7", "W Transverse Mass (T)");
  hs7->Add(TrueWMT_P);
  hs7->Add(TruePTLWMT_D);
  hs7->Add(TruePTLWMT_K);
  hs7->Add(TruePTLWMT_L);
  hs7->Draw("NOSTACK HIST");
  hs7->GetXaxis()->SetTitle("Mass");
  hs7->GetYaxis()->SetTitle("Count (normalized)");
  TLegend *legend7 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend7->AddEntry(TrueWMT_P, "No merge", "pl");
  legend7->AddEntry(TruePTLWMT_D, "KT Durham Merge", "pl");
  legend7->AddEntry(TruePTLWMT_K, "Phase Space Merge", "pl");
  legend7->AddEntry(TruePTLWMT_L, "PT Lund Merge", "pl");
  legend7->Draw();
  c7->Print("./plots/TrueWMtMerge.png");

  /*
	c8->cd();
	RecoWMT_P->Draw("HIST");
	RecoWMT_P->GetXaxis()->SetTitle("Mass");
  RecoWMT_P->GetYaxis()->SetTitle("Count");
	c8->Print("./plots/RecoWMT.png");

	c9->cd();
  TrueLeadLepPt_P->Scale(1./(TrueLeadLepPt_P->Integral()));
	TrueLeadLepPt_P->Draw("HIST");
	TrueLeadLepPt_P->GetXaxis()->SetTitle("Momentum");
  TrueLeadLepPt_P->GetYaxis()->SetTitle("Count");
	c9->Print("./plots/TrueLeadLepPt.png");

	c10->cd();
	RecoLeadLepPt_P->Draw("HIST");
	RecoLeadLepPt_P->GetXaxis()->SetTitle("Momentum");
  RecoLeadLepPt_P->GetYaxis()->SetTitle("Count");
	c10->Print("./plots/RecoLeadLepPt.png");
  */


  // Boson Pt:
	c11->cd();
  THStack *hs11 = new THStack("hs11", "W Boson Pt (T)");

  TrueWPT_P->Scale(1./(TrueWPT_P->Integral()));
  TruePTLWPT_D->Scale(1./(TruePTLWPT_D->Integral()));
  TruePTLWPT_K->Scale(1./(TruePTLWPT_K->Integral()));
  TruePTLWPT_L->Scale(1./(TruePTLWPT_L->Integral()));
  TrueWPT_P->SetLineColor(kRed);
  TrueWPT_P->SetMarkerStyle(20);
  TrueWPT_P->SetMarkerColor(kRed);
  TrueWPT_P->SetMarkerSize(1.0);
	TrueWPT_P->GetXaxis()->SetTitle("Momentum");
  TrueWPT_P->GetYaxis()->SetTitle("Count");
  TruePTLWPT_D->SetLineColor(kBlue);
  TruePTLWPT_D->SetMarkerStyle(22);
  TruePTLWPT_D->SetMarkerColor(kBlue);
  TruePTLWPT_K->SetLineColor(kGreen);
  TruePTLWPT_K->SetMarkerStyle(22);
  TruePTLWPT_K->SetMarkerColor(kGreen);
  TruePTLWPT_L->SetLineColor(kOrange);
  TruePTLWPT_L->SetMarkerStyle(22);
  TruePTLWPT_L->SetMarkerColor(kOrange);

  hs11->Add(TrueWPT_P);
  hs11->Add(TruePTLWPT_D);
  hs11->Add(TruePTLWPT_K);
  hs11->Add(TruePTLWPT_L);
  hs11->Draw("NOSTACK HIST");
  hs11->GetXaxis()->SetTitle("Momentum");
  hs11->GetYaxis()->SetTitle("Count (normalized)");

  TLegend *legend11 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend11->AddEntry(TrueWPT_P, "No merge", "pl");
  legend11->AddEntry(TruePTLWPT_D, "KT Durham Merge", "pl");
  legend11->AddEntry(TruePTLWPT_K, "Phase Space Merge", "pl");
  legend11->AddEntry(TruePTLWPT_L, "PT Lund Merge", "pl");
  legend11->Draw();

	c11->Print("./plots/TrueWPtMerge.png");
  

  /*
	c12->cd();
	RecoWPT_LQ_P->Draw();
	RecoWPT_LQ_P->GetXaxis()->SetTitle("Momentum");
  RecoWPT_LQ_P->GetYaxis()->SetTitle("Count");
	c12->Print("./plots/RecoWPT.png");

  c13->cd();
	TrueMet_LQ_P->Draw();
	TrueMet_LQ_P->GetXaxis()->SetTitle("Energy");
  TrueMet_LQ_P->GetYaxis()->SetTitle("Count");
	c13->Print("./plots/TrueMet.png");

  c14->cd();
	RecoMet_LQ_P->Draw();
	RecoMet_LQ_P->GetXaxis()->SetTitle("Energy");
  RecoMet_LQ_P->GetYaxis()->SetTitle("Count");
	c14->Print("./plots/RecoMet.png");
  */

  // Boson Pt ratio:
  TruePTLWPT_D->Scale(1./(TruePTLWPT_D->Integral()));
  TH1F *PtRatioPTLWtoW_D = (TH1F*)TruePTLWPT_D->Clone("PtRatioPTLWtoW_D");
  PtRatioPTLWtoW_D->Divide(TrueWPT_P);
  TruePTLWPT_K->Scale(1./(TruePTLWPT_K->Integral()));
  TH1F *PtRatioPTLWtoW_K = (TH1F*)TruePTLWPT_K->Clone("PtRatioPTLWtoW_K");
  PtRatioPTLWtoW_K->Divide(TrueWPT_P);
  TruePTLWPT_L->Scale(1./(TruePTLWPT_L->Integral()));
  TH1F *PtRatioPTLWtoW_L = (TH1F*)TruePTLWPT_L->Clone("PtRatioPTLWtoW_L");
  PtRatioPTLWtoW_L->Divide(TrueWPT_P);

  TCanvas *c15 = new TCanvas("c15", "W Pt Ratio Plot", 800, 600);
  c15->cd();
  PtRatioPTLWtoW_D->SetMarkerStyle(20);
  PtRatioPTLWtoW_D->SetMarkerColor(kBlue);
  PtRatioPTLWtoW_D->SetLineColor(kBlue);
  PtRatioPTLWtoW_K->SetMarkerStyle(21);
  PtRatioPTLWtoW_K->SetMarkerColor(kGreen);
  PtRatioPTLWtoW_K->SetLineColor(kGreen);
  PtRatioPTLWtoW_L->SetMarkerStyle(22);
  PtRatioPTLWtoW_L->SetMarkerColor(kOrange);
  PtRatioPTLWtoW_L->SetLineColor(kOrange);
  PtRatioPTLWtoW_D->GetXaxis()->SetTitle("Momentum");
  PtRatioPTLWtoW_D->GetYaxis()->SetTitle("Merge/Standard Ratio");
  PtRatioPTLWtoW_D->SetTitle("W+jets Pt Ratio (T)");

  THStack *hs15 = new THStack("hs15", "W Boson Pt Ratio (T)");
  hs15->Add(PtRatioPTLWtoW_D);
  hs15->Add(PtRatioPTLWtoW_K);
  hs15->Add(PtRatioPTLWtoW_L);
  hs15->Draw("NOSTACK HIST");
  hs15->GetXaxis()->SetTitle("Momentum");
  hs15->GetYaxis()->SetTitle("Count (normalized)");

  TLegend *legend15 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend15->AddEntry(PtRatioPTLWtoW_D, "KT Durham Merge", "pl");
  legend15->AddEntry(PtRatioPTLWtoW_K, "Phase Space Merge", "pl");
  legend15->AddEntry(PtRatioPTLWtoW_L, "PT Lund Merge", "pl");
  legend15->Draw();

  line17.Draw("SAME");
  c15->SetLogy();
  c15->Print("./plots/TrueWPtMergeRatio.png");

  
  // Boson rapidity ratio
  TCanvas *c16 = new TCanvas("c16", "WRap Ratio Plot", 800, 600);
  c16->cd();
  TrueWRap_P->Scale(1./(TrueWRap_P->Integral()));
  TruePTLWRap_D->Scale(1./(TruePTLWRap_D->Integral()));
  TH1F *WRapRatioPTLWtoW_D = (TH1F*)TruePTLWRap_D->Clone("WRapRatioPTLWtoW_D");
  WRapRatioPTLWtoW_D->Divide(TrueWRap_P);
  TruePTLWRap_K->Scale(1./(TruePTLWRap_K->Integral()));
  TH1F *WRapRatioPTLWtoW_K = (TH1F*)TruePTLWRap_K->Clone("WRapRatioPTLWtoW_K");
  WRapRatioPTLWtoW_K->Divide(TrueWRap_P);
  TruePTLWRap_L->Scale(1./(TruePTLWRap_L->Integral()));
  TH1F *WRapRatioPTLWtoW_L = (TH1F*)TruePTLWRap_L->Clone("WRapRatioPTLWtoW_L");
  WRapRatioPTLWtoW_L->Divide(TrueWRap_P);

  WRapRatioPTLWtoW_D->SetMarkerStyle(20);
  WRapRatioPTLWtoW_D->SetMarkerColor(kBlue);
  WRapRatioPTLWtoW_D->SetLineColor(kBlue);
  WRapRatioPTLWtoW_K->SetMarkerStyle(21);
  WRapRatioPTLWtoW_K->SetMarkerColor(kGreen);
  WRapRatioPTLWtoW_K->SetLineColor(kGreen);
  WRapRatioPTLWtoW_L->SetMarkerStyle(22);
  WRapRatioPTLWtoW_L->SetMarkerColor(kOrange);
  WRapRatioPTLWtoW_L->SetLineColor(kOrange);
  WRapRatioPTLWtoW_D->GetXaxis()->SetTitle("Rapidity");
  WRapRatioPTLWtoW_D->GetYaxis()->SetTitle("Merge/Standard Ratio");
  WRapRatioPTLWtoW_D->SetTitle("Boson Rapidity Ratio (T)");

  THStack *hs16 = new THStack("hs16", "W Boson Rapidity Ratio (T)");
  hs16->Add(WRapRatioPTLWtoW_D);
  hs16->Add(WRapRatioPTLWtoW_K);
  hs16->Add(WRapRatioPTLWtoW_L);
  hs16->SetMaximum(2.);
  hs16->Draw("NOSTACK HIST");
  hs16->GetXaxis()->SetTitle("Rapidity");
  hs16->GetYaxis()->SetTitle("Merge/Standard Ratio");

  TLegend *legend16 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend16->AddEntry(WRapRatioPTLWtoW_D, "KT Durham Merge", "pl");
  legend16->AddEntry(WRapRatioPTLWtoW_K, "Phase Space Merge", "pl");
  legend16->AddEntry(WRapRatioPTLWtoW_L, "PT Lund Merge", "pl");
  legend16->Draw();

  lineRap->Draw("SAME");
  c16->Print("./plots/TrueWRapMergeRatio.png");

  
  // Boson rapidity
  TCanvas *c21 = new TCanvas("c21", "W Rapidity", 800, 600);
  c21->cd();

  TrueWRap_P->SetLineColor(kRed);
  TrueWRap_P->GetXaxis()->SetTitle("Rapidity");
  TrueWRap_P->GetYaxis()->SetTitle("Count (normalized)");
  TruePTLWRap_D->SetLineColor(kBlue);
  TruePTLWRap_K->SetLineColor(kGreen);
  TruePTLWRap_L->SetLineColor(kOrange);

  THStack *hs211 = new THStack("hs211", "W Boson Rapidity (T)");
  hs211->Add(TrueWRap_P);
  hs211->Add(TruePTLWRap_D);
  hs211->Add(TruePTLWRap_K);
  hs211->Add(TruePTLWRap_L);
  hs211->Draw("NOSTACK HIST");
  hs211->GetXaxis()->SetTitle("Rapidity");
  hs211->GetYaxis()->SetTitle("Count (normalized)");
  hs211->SetTitle("Boson Rapidity (T)");

  TLegend *legend21 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend21->AddEntry(TrueWRap_P, "No merge", "pl");
  legend21->AddEntry(TruePTLWRap_D, "KT Durham merge", "pl");
  legend21->AddEntry(TruePTLWRap_K, "Phase Space Merge", "pl");
  legend21->AddEntry(TruePTLWRap_L, "PT Lund Merge", "pl");
  legend21->Draw();

  c21->Print("./plots/TrueWRapMerge.png");

  // Boson transverse mass ratio:
  TruePTLWMT_D->Scale(1./(TruePTLWMT_D->Integral()));
  TH1F *MtRatioPTLWtoW_D = (TH1F*)TruePTLWMT_D->Clone("PtRatioPTLWtoW_D");
  MtRatioPTLWtoW_D->Divide(TrueWMT_P);
  TH1F *MtRatioPTLWtoW_K = (TH1F*)TruePTLWMT_K->Clone("PtRatioPTLWtoW_K");
  MtRatioPTLWtoW_K->Divide(TrueWMT_P);
  TH1F *MtRatioPTLWtoW_L = (TH1F*)TruePTLWMT_L->Clone("PtRatioPTLWtoW_L");
  MtRatioPTLWtoW_L->Divide(TrueWMT_P);

  TCanvas *c115 = new TCanvas("c115", "W Mt Ratio Plot", 800, 600);
  c115->cd();
  MtRatioPTLWtoW_D->SetMarkerStyle(20);
  MtRatioPTLWtoW_D->SetMarkerColor(kBlue);
  MtRatioPTLWtoW_D->SetLineColor(kBlue);
  MtRatioPTLWtoW_K->SetMarkerStyle(21);
  MtRatioPTLWtoW_K->SetMarkerColor(kGreen);
  MtRatioPTLWtoW_K->SetLineColor(kGreen);
  MtRatioPTLWtoW_L->SetMarkerStyle(22);
  MtRatioPTLWtoW_L->SetMarkerColor(kOrange);
  MtRatioPTLWtoW_L->SetLineColor(kOrange);
  MtRatioPTLWtoW_D->GetXaxis()->SetTitle("Mass");
  MtRatioPTLWtoW_D->GetYaxis()->SetTitle("Merge/Standard Ratio");
  MtRatioPTLWtoW_D->SetTitle("W Transverse Mass Ratio");

  THStack *hs115 = new THStack("hs211", "W Boson Transverse Mass (T)");
  hs115->Add(MtRatioPTLWtoW_D);
  hs115->Add(MtRatioPTLWtoW_K);
  hs115->Add(MtRatioPTLWtoW_L);
  hs115->Draw("NOSTACK HIST");
  hs115->GetXaxis()->SetTitle("Mass");
  hs115->GetYaxis()->SetTitle("Merge/Standard Ratio");
  hs115->SetTitle("Boson Transverse Mass Ratio (T)");

  TLegend *legend115 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend115->AddEntry(MtRatioPTLWtoW_D, "KT Durham Merge", "pl");
  legend115->AddEntry(MtRatioPTLWtoW_K, "Phase Space Merge", "pl");
  legend115->AddEntry(MtRatioPTLWtoW_L, "PT Lund Merge", "pl");
  legend115->Draw();

  line17.Draw("SAME");
  c115->Print("./plots/TrueWMtMergeRatio.png");


  // ============================================================================================================= //


  // Lepton Plots

  // Momenta
  TCanvas *c100 = new TCanvas("c100", "Lepton Pt (T)", 800, 600);
  c100->cd();
  THStack *hs100 = new THStack("hs100", "W+jets Lepton Pt (T)");

  TrueLeadLepPt_P->Scale(1./(TrueLeadLepPt_P->Integral()));
  TrueLeadLepPt_D->Scale(1./(TrueLeadLepPt_D->Integral()));
  TrueLeadLepPt_K->Scale(1./(TrueLeadLepPt_K->Integral()));
  TrueLeadLepPt_L->Scale(1./(TrueLeadLepPt_L->Integral()));
  TrueLeadLepPt_P->SetMarkerStyle(20);
  TrueLeadLepPt_P->SetMarkerColor(kRed);
  TrueLeadLepPt_P->SetLineColor(kRed);
  TrueLeadLepPt_D->SetMarkerStyle(21);
  TrueLeadLepPt_D->SetMarkerColor(kBlue);
  TrueLeadLepPt_D->SetLineColor(kBlue);
  TrueLeadLepPt_K->SetMarkerStyle(22);
  TrueLeadLepPt_K->SetMarkerColor(kGreen);
  TrueLeadLepPt_K->SetLineColor(kGreen);
  TrueLeadLepPt_L->SetMarkerStyle(23);
  TrueLeadLepPt_L->SetMarkerColor(kOrange);
  TrueLeadLepPt_L->SetLineColor(kOrange);
  TrueLeadLepPt_P->GetXaxis()->SetTitle("Momentum");
  TrueLeadLepPt_P->GetYaxis()->SetTitle("Count (normalized)");

  hs100->Add(TrueLeadLepPt_P);
  hs100->Add(TrueLeadLepPt_D);
  hs100->Add(TrueLeadLepPt_K);
  hs100->Add(TrueLeadLepPt_L);
  hs100->Draw("NOSTACK HIST");
  hs100->GetXaxis()->SetTitle("Transverse Momentum");
  hs100->GetYaxis()->SetTitle("Count (normalized)");

  TLegend *legend100 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend100->AddEntry(TrueLeadLepPt_P, "No Merge", "pl");
  legend100->AddEntry(TrueLeadLepPt_D, "KT Durham Merge", "pl");
  legend100->AddEntry(TrueLeadLepPt_K, "Phase Space Merge", "pl");
  legend100->AddEntry(TrueLeadLepPt_L, "PT Lund Merge", "pl");
  legend100->Draw();

  c100->Print("./plots/TrueLeadLeptonPtMerge.png");


  // Pt Ratio
  TCanvas *c17 = new TCanvas("c17", "Lepton Pt Ratio (T)", 800, 600);
  c17->cd();
  TrueLeadLepPt_P->Scale(1./(TrueLeadLepPt_P->Integral()));
  TH1F *LepPtRatioPTLWtoW_D = (TH1F*)TrueLeadLepPt_D->Clone("LepPtRatioPTLWtoW_D");
  LepPtRatioPTLWtoW_D->Divide(TrueLeadLepPt_P);
  TH1F *LepPtRatioPTLWtoW_K = (TH1F*)TrueLeadLepPt_K->Clone("LepPtRatioPTLWtoW_K");
  LepPtRatioPTLWtoW_K->Divide(TrueLeadLepPt_P);
  TH1F *LepPtRatioPTLWtoW_L = (TH1F*)TrueLeadLepPt_L->Clone("LepPtRatioPTLWtoW_L");
  LepPtRatioPTLWtoW_L->Divide(TrueLeadLepPt_P);

  LepPtRatioPTLWtoW_D->SetMarkerStyle(20);
  LepPtRatioPTLWtoW_D->SetMarkerColor(kBlue);
  LepPtRatioPTLWtoW_D->SetLineColor(kBlue);
  LepPtRatioPTLWtoW_K->SetMarkerStyle(21);
  LepPtRatioPTLWtoW_K->SetMarkerColor(kGreen);
  LepPtRatioPTLWtoW_K->SetLineColor(kGreen);
  LepPtRatioPTLWtoW_L->SetMarkerStyle(22);
  LepPtRatioPTLWtoW_L->SetMarkerColor(kOrange);
  LepPtRatioPTLWtoW_L->SetLineColor(kOrange);
  LepPtRatioPTLWtoW_D->GetXaxis()->SetTitle("Momentum");
  LepPtRatioPTLWtoW_D->GetYaxis()->SetTitle("Ratio");
  LepPtRatioPTLWtoW_D->SetTitle("Lepton Pt Ratio (T)");

  THStack *hs117 = new THStack("hs117", "Lepton Pt Ratio (T)");
  hs117->Add(LepPtRatioPTLWtoW_D);
  hs117->Add(LepPtRatioPTLWtoW_K);
  hs117->Add(LepPtRatioPTLWtoW_L);
  hs117->Draw("NOSTACK HIST");
  hs117->GetXaxis()->SetTitle("Transverse Momentum");
  hs117->GetYaxis()->SetTitle("Merge/Standard Ratio");

  TLegend *legend117 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend117->AddEntry(LepPtRatioPTLWtoW_D, "KT Durham Merge", "pl");
  legend117->AddEntry(LepPtRatioPTLWtoW_K, "Phase Space Merge", "pl");
  legend117->AddEntry(LepPtRatioPTLWtoW_L, "PT Lund Merge", "pl");
  legend117->Draw();

  line17.Draw("SAME");
  c17->Print("./plots/TrueLeadLeptonPtMergeRatio.png");


  // Lepton rapidity ratio
  TCanvas *c116 = new TCanvas("c116", "Lepton Rap Ratio (T)", 800, 600);
  c116->cd();
  TrueLeadLepRap_P->Scale(1./(TrueLeadLepRap_P->Integral()));
  TrueLeadLepRap_D->Scale(1./(TrueLeadLepRap_D->Integral()));
  TH1F *TrueLeptonRapRatioPTLWtoW_D = (TH1F*)TrueLeadLepRap_D->Clone("TrueLeptonRapRatioPTLWtoW_D");
  TrueLeptonRapRatioPTLWtoW_D->Divide(TrueLeadLepRap_P);
  TrueLeadLepRap_K->Scale(1./(TrueLeadLepRap_K->Integral()));
  TH1F *TrueLeptonRapRatioPTLWtoW_K = (TH1F*)TrueLeadLepRap_K->Clone("TrueLeptonRapRatioPTLWtoW_K");
  TrueLeptonRapRatioPTLWtoW_K->Divide(TrueLeadLepRap_P);
  TrueLeadLepRap_L->Scale(1./(TrueLeadLepRap_L->Integral()));
  TH1F *TrueLeptonRapRatioPTLWtoW_L = (TH1F*)TrueLeadLepRap_L->Clone("TrueLeptonRapRatioPTLWtoW_L");
  TrueLeptonRapRatioPTLWtoW_L->Divide(TrueLeadLepRap_P);

  TrueLeptonRapRatioPTLWtoW_D->SetMarkerStyle(20);
  TrueLeptonRapRatioPTLWtoW_D->SetMarkerColor(kBlue);
  TrueLeptonRapRatioPTLWtoW_D->SetLineColor(kBlue);
  TrueLeptonRapRatioPTLWtoW_K->SetMarkerStyle(21);
  TrueLeptonRapRatioPTLWtoW_K->SetMarkerColor(kGreen);
  TrueLeptonRapRatioPTLWtoW_K->SetLineColor(kGreen);
  TrueLeptonRapRatioPTLWtoW_L->SetMarkerStyle(22);
  TrueLeptonRapRatioPTLWtoW_L->SetMarkerColor(kOrange);
  TrueLeptonRapRatioPTLWtoW_L->SetLineColor(kOrange);
  TrueLeptonRapRatioPTLWtoW_D->GetXaxis()->SetTitle("Rapidity");
  TrueLeptonRapRatioPTLWtoW_D->GetYaxis()->SetTitle("Merge/Standard Ratio");
  TrueLeptonRapRatioPTLWtoW_D->SetTitle("Lead Lepton Rapidity Ratio (T)");

  THStack *hs116 = new THStack("hs116", "Lepton Rapidity Ratio (T)");
  hs116->Add(TrueLeptonRapRatioPTLWtoW_D);
  hs116->Add(TrueLeptonRapRatioPTLWtoW_K);
  hs116->Add(TrueLeptonRapRatioPTLWtoW_L);
  hs116->SetMinimum(0.9);
  hs116->Draw("NOSTACK HIST");
  hs116->GetXaxis()->SetTitle("Rapidity");
  hs116->GetYaxis()->SetTitle("Merge/Standard Ratio");

  TLegend *legend116 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend116->AddEntry(TrueLeptonRapRatioPTLWtoW_D, "KT Durham Merge", "pl");
  legend116->AddEntry(TrueLeptonRapRatioPTLWtoW_K, "Phase Space Merge", "pl");
  legend116->AddEntry(TrueLeptonRapRatioPTLWtoW_L, "PT Lund Merge", "pl");
  legend116->Draw();

  lineRap->Draw("SAME");
  c116->Print("./plots/TrueLeadLepRapMergeRatio.png");

  
  // Lepton rapidity
  TCanvas *c121 = new TCanvas("c121", "Lepton Rapidity (T)", 800, 600);
  c121->cd();

  TrueLeadLepRap_P->SetLineColor(kRed);
  TrueLeadLepRap_P->GetXaxis()->SetTitle("Rapidity");
  TrueLeadLepRap_P->GetYaxis()->SetTitle("Count (normalized)");
  TrueLeadLepRap_D->SetLineColor(kBlue);
  TrueLeadLepRap_K->SetLineColor(kGreen);
  TrueLeadLepRap_L->SetLineColor(kOrange);

  THStack *hs121 = new THStack("hs121", "Lepton Rapidity (T)");
  hs121->Add(TrueLeadLepRap_P);
  hs121->Add(TrueLeadLepRap_D);
  hs121->Add(TrueLeadLepRap_K);
  hs121->Add(TrueLeadLepRap_L);
  hs121->SetMinimum(0.035);
  hs121->Draw("NOSTACK HIST");
  hs121->GetXaxis()->SetTitle("Rapidity");
  hs121->GetYaxis()->SetTitle("Count (normalized)");

  TLegend *legend121 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend121->AddEntry(TrueLeadLepRap_P, "No merge", "pl");
  legend121->AddEntry(TrueLeadLepRap_D, "KT Durham Merge", "pl");
  legend121->AddEntry(TrueLeadLepRap_K, "Phase Space Merge", "pl");
  legend121->AddEntry(TrueLeadLepRap_L, "PT Lund Merge", "pl");
  legend121->Draw();

  c121->Print("./plots/TrueLeadLepRapMerge.png");

  // ================================================================================================================ //

  // Lead Jet Plots:

  // Lead Jet Pt

  TCanvas *c111 = new TCanvas("c111", "Lead Jet Pt (T)", 800, 600);
  c111->cd();
  THStack *hs111 = new THStack("hs111", "Lead Jet Pt (T)");

  LeadJetPt_P->Scale(1./(LeadJetPt_P->Integral()));
  LeadJetPt_D->Scale(1./(LeadJetPt_D->Integral()));
  LeadJetPt_K->Scale(1./(LeadJetPt_K->Integral()));
  LeadJetPt_L->Scale(1./(LeadJetPt_L->Integral()));
  LeadJetPt_P->SetLineColor(kRed);
  LeadJetPt_P->SetMarkerStyle(20);
  LeadJetPt_P->SetMarkerColor(kRed);
  LeadJetPt_P->SetMarkerSize(1.0);
	LeadJetPt_P->GetXaxis()->SetTitle("Momentum");
  LeadJetPt_P->GetYaxis()->SetTitle("Count");
  LeadJetPt_D->SetLineColor(kBlue);
  LeadJetPt_D->SetMarkerStyle(22);
  LeadJetPt_D->SetMarkerColor(kBlue);
  LeadJetPt_K->SetLineColor(kGreen);
  LeadJetPt_K->SetMarkerStyle(22);
  LeadJetPt_K->SetMarkerColor(kGreen);
  LeadJetPt_L->SetLineColor(kOrange);
  LeadJetPt_L->SetMarkerStyle(22);
  LeadJetPt_L->SetMarkerColor(kOrange);

  hs111->Add(LeadJetPt_P);
  hs111->Add(LeadJetPt_D);
  hs111->Add(LeadJetPt_K);
  hs111->Add(LeadJetPt_L);
  hs111->Draw("NOSTACK HIST");
  hs111->GetXaxis()->SetTitle("Momentum");
  hs111->GetYaxis()->SetTitle("Count (normalized)");

  TLegend *legend111 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend111->AddEntry(LeadJetPt_P, "No Merge", "pl");
  legend111->AddEntry(LeadJetPt_D, "KT Durham Merge", "pl");
  legend111->AddEntry(LeadJetPt_K, "Phase Space Merge", "pl");
  legend111->AddEntry(LeadJetPt_L, "PT Lund Merge", "pl");
  legend111->Draw();

	c111->Print("./plots/TrueLeadJetPtMerge.png");

  // Lead Jet Pt Ratio

  TH1F *JetPtRatioPTLWtoW_D = (TH1F*)LeadJetPt_D->Clone("JetPtRatioPTLWtoW_D");
  JetPtRatioPTLWtoW_D->Divide(LeadJetPt_P);
  TH1F *JetPtRatioPTLWtoW_K = (TH1F*)LeadJetPt_K->Clone("JetPtRatioPTLWtoW_K");
  JetPtRatioPTLWtoW_K->Divide(LeadJetPt_P);
  TH1F *JetPtRatioPTLWtoW_L = (TH1F*)LeadJetPt_L->Clone("JetPtRatioPTLWtoW_L");
  JetPtRatioPTLWtoW_L->Divide(LeadJetPt_P);

  TCanvas *c118 = new TCanvas("c118", "Jet Pt Ratio Plot", 800, 600);
  c118->cd();
  JetPtRatioPTLWtoW_D->SetMarkerStyle(20);
  JetPtRatioPTLWtoW_D->SetMarkerColor(kBlue);
  JetPtRatioPTLWtoW_D->SetLineColor(kBlue);
  JetPtRatioPTLWtoW_K->SetMarkerStyle(21);
  JetPtRatioPTLWtoW_K->SetMarkerColor(kGreen);
  JetPtRatioPTLWtoW_K->SetLineColor(kGreen);
  JetPtRatioPTLWtoW_L->SetMarkerStyle(22);
  JetPtRatioPTLWtoW_L->SetMarkerColor(kOrange);
  JetPtRatioPTLWtoW_L->SetLineColor(kOrange);
  JetPtRatioPTLWtoW_D->GetXaxis()->SetTitle("Momentum");
  JetPtRatioPTLWtoW_D->GetYaxis()->SetTitle("Merge/Standard Ratio");
  JetPtRatioPTLWtoW_D->SetTitle("W+jets Lead Jet Pt Ratio (T)");

  THStack *hs118 = new THStack("hs118", "Lead Jet Pt Ratio (T)");
  hs118->Add(JetPtRatioPTLWtoW_D);
  hs118->Add(JetPtRatioPTLWtoW_K);
  hs118->Add(JetPtRatioPTLWtoW_L);
  hs118->Draw("NOSTACK HIST");
  hs118->GetXaxis()->SetTitle("Momentum");
  hs118->GetYaxis()->SetTitle("Merge/Standard Ratio");

  TLegend *legend118 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend118->AddEntry(JetPtRatioPTLWtoW_D, "KT Durham Merge", "pl");
  legend118->AddEntry(JetPtRatioPTLWtoW_K, "Phase Space Merge", "pl");
  legend118->AddEntry(JetPtRatioPTLWtoW_L, "PT Lund Merge", "pl");
  legend118->Draw();

  line18.Draw("SAME");
  c118->SetLogy();
  c118->Print("./plots/TrueLeadJetPtMergeRatio.png");


  // Lead Jet Rap

  TCanvas *c311 = new TCanvas("c311", "Lead Jet Rap (T)", 800, 600);
  c311->cd();
  THStack *hs311 = new THStack("hs311", "Lead Jet Rap (T)");

  LeadJetRap_P->Scale(1./(LeadJetRap_P->Integral()));
  LeadJetRap_D->Scale(1./(LeadJetRap_D->Integral()));
  LeadJetRap_K->Scale(1./(LeadJetRap_K->Integral()));
  LeadJetRap_L->Scale(1./(LeadJetRap_L->Integral()));
  LeadJetRap_P->SetLineColor(kRed);
  LeadJetRap_P->SetMarkerStyle(20);
  LeadJetRap_P->SetMarkerColor(kRed);
  LeadJetRap_P->SetMarkerSize(1.0);
	LeadJetRap_P->GetXaxis()->SetTitle("Momentum");
  LeadJetRap_P->GetYaxis()->SetTitle("Count");
  LeadJetRap_D->SetLineColor(kBlue);
  LeadJetRap_D->SetMarkerStyle(22);
  LeadJetRap_D->SetMarkerColor(kBlue);
  LeadJetRap_K->SetLineColor(kGreen);
  LeadJetRap_K->SetMarkerStyle(22);
  LeadJetRap_K->SetMarkerColor(kGreen);
  LeadJetRap_L->SetLineColor(kOrange);
  LeadJetRap_L->SetMarkerStyle(22);
  LeadJetRap_L->SetMarkerColor(kOrange);

  hs311->Add(LeadJetRap_P);
  hs311->Add(LeadJetRap_D);
  hs311->Add(LeadJetRap_K);
  hs311->Add(LeadJetRap_L);
  hs311->Draw("NOSTACK HIST");
  hs311->GetXaxis()->SetTitle("Rapidity");
  hs311->GetYaxis()->SetTitle("Count (normalized)");

  TLegend *legend311 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend311->AddEntry(LeadJetRap_P, "No Merge", "pl");
  legend311->AddEntry(LeadJetRap_D, "KT Durham Merge", "pl");
  legend311->AddEntry(LeadJetRap_K, "Phase Space Merge", "pl");
  legend311->AddEntry(LeadJetRap_L, "PT Lund Merge", "pl");
  legend311->Draw();

	c311->Print("./plots/TrueLeadJetRapMerge.png");

  // Lead Jet Rap Ratio

  TH1F *JetRapRatioPTLWtoW_D = (TH1F*)LeadJetRap_D->Clone("JetRapRatioPTLWtoW_D");
  JetRapRatioPTLWtoW_D->Divide(LeadJetRap_P);
  TH1F *JetRapRatioPTLWtoW_K = (TH1F*)LeadJetRap_K->Clone("JetRapRatioPTLWtoW_K");
  JetRapRatioPTLWtoW_K->Divide(LeadJetRap_P);
  TH1F *JetRapRatioPTLWtoW_L = (TH1F*)LeadJetRap_L->Clone("JetRapRatioPTLWtoW_L");
  JetRapRatioPTLWtoW_L->Divide(LeadJetRap_P);

  TCanvas *c312 = new TCanvas("c117", "Jet Rap Ratio Plot", 800, 600);
  c312->cd();
  JetRapRatioPTLWtoW_D->SetMarkerStyle(20);
  JetRapRatioPTLWtoW_D->SetMarkerColor(kBlue);
  JetRapRatioPTLWtoW_D->SetLineColor(kBlue);
  JetRapRatioPTLWtoW_K->SetMarkerStyle(21);
  JetRapRatioPTLWtoW_K->SetMarkerColor(kGreen);
  JetRapRatioPTLWtoW_K->SetLineColor(kGreen);
  JetRapRatioPTLWtoW_L->SetMarkerStyle(22);
  JetRapRatioPTLWtoW_L->SetMarkerColor(kOrange);
  JetRapRatioPTLWtoW_L->SetLineColor(kOrange);
  JetRapRatioPTLWtoW_D->GetXaxis()->SetTitle("Rapidity");
  JetRapRatioPTLWtoW_D->GetYaxis()->SetTitle("Merge/Standard Ratio");
  JetRapRatioPTLWtoW_D->SetTitle("W+jets Lead Jet Rap Ratio (T)");

  THStack *hs312 = new THStack("hs118", "Lead Jet Rap Ratio (T)");
  hs312->Add(JetRapRatioPTLWtoW_D);
  hs312->Add(JetRapRatioPTLWtoW_K);
  hs312->Add(JetRapRatioPTLWtoW_L);
  hs312->Draw("NOSTACK HIST");
  hs312->GetXaxis()->SetTitle("Rapidity");
  hs312->GetYaxis()->SetTitle("Merge/Standard Ratio");

  TLegend *legend312 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend312->AddEntry(JetRapRatioPTLWtoW_D, "KT Durham Merge", "pl");
  legend312->AddEntry(JetRapRatioPTLWtoW_K, "Phase Space Merge", "pl");
  legend312->AddEntry(JetRapRatioPTLWtoW_L, "PT Lund Merge", "pl");
  legend312->Draw();

  lineRap->Draw("SAME");
  c312->SetLogy();
  c312->Print("./plots/TrueLeadJetRapMergeRatio.png");


  /*
  TCanvas *c18 = new TCanvas("c18", "WRap Ratio Plot", 800, 600);
  c18->cd();

  TrueWPT_LQ_P->SetMarkerStyle(20);
  TrueWPT_LQ_P->SetMarkerColor(kRed);
  TrueWPT_LQ_P->SetLineColor(kRed);
  //TrueWPT_LQ_P->Draw();

  TrueWPT_LQ_P23->Scale(1./(TrueWPT_LQ_P23->Integral()));
  TrueWPT_LQ_P23->SetMarkerStyle(21);
  TrueWPT_LQ_P23->SetMarkerColor(kBlue);
  TrueWPT_LQ_P23->SetLineColor(kBlue);
  //TrueWPT_LQ_P23->Draw("SAME");

  TrueWPT_LQ_P24->Scale(1./(TrueWPT_LQ_P24->Integral()));
  TrueWPT_LQ_P24->SetMarkerStyle(22);
  TrueWPT_LQ_P24->SetMarkerColor(kGreen);
  TrueWPT_LQ_P24->SetLineColor(kGreen);
  //TrueWPT_LQ_P24->Draw("SAME");
  
  TrueWPT_LQ_P25->Scale(1./(TrueWPT_LQ_P25->Integral()));
  TrueWPT_LQ_P25->SetMarkerStyle(23);
  TrueWPT_LQ_P25->SetMarkerColor(kOrange);
  TrueWPT_LQ_P25->SetLineColor(kOrange);
  //TrueWPT_LQ_P25->Draw("SAME");
  //TrueWPT_LQ_P25->GetXaxis()->SetTitle("Momentum");
  //TrueWPT_LQ_P25->GetYaxis()->SetTitle("Count");

  TrueWPT_LQ_P26->Scale(1./(TrueWPT_LQ_P26->Integral()));
  TrueWPT_LQ_P26->SetMarkerStyle(22);
  TrueWPT_LQ_P26->SetMarkerColor(kViolet);
  TrueWPT_LQ_P26->SetLineColor(kViolet);
  //TrueWPT_LQ_P26->Draw("SAME");

  TrueWPT_LQ_P27->Scale(1./(TrueWPT_LQ_P27->Integral()));
  TrueWPT_LQ_P27->SetMarkerStyle(22);
  //TrueWPT_LQ_P27->Draw("SAME");



  
  THStack *hs18 = new THStack("hs18", "W Pt Pythia Tunes");

  hs18->Add(TrueWPT_LQ_P);
  hs18->Add(TrueWPT_LQ_P23);
  hs18->Add(TrueWPT_LQ_P24);
  hs18->Add(TrueWPT_LQ_P25);
  hs18->Add(TrueWPT_LQ_P26);
  hs18->Add(TrueWPT_LQ_P27);
  
  hs18->Draw("NOSTACK HIST");
  hs18->GetXaxis()->SetTitle("Transverse Momentum");


  TLegend *legend18 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend18->AddEntry(TrueWPT_LQ_P, "Pythia 21", "pl");
  legend18->AddEntry(TrueWPT_LQ_P23, "Pythia 23", "pl");
  legend18->AddEntry(TrueWPT_LQ_P24, "Pythia 24", "pl");
  legend18->AddEntry(TrueWPT_LQ_P25, "Pythia 25", "pl");
  legend18->AddEntry(TrueWPT_LQ_P26, "Pythia 26", "pl");
  legend18->AddEntry(TrueWPT_LQ_P27, "Pythia 27", "pl");
  legend18->Draw();

  c18->Print("./plots/PythiaWPtTunes1.png");



  TCanvas *c19 = new TCanvas("c19", "WRap Ratio Plot", 800, 600);
  c19->cd();

  TrueWPT_LQ_P->SetMarkerStyle(20);
  TrueWPT_LQ_P->SetMarkerColor(kRed);
  TrueWPT_LQ_P->SetLineColor(kRed);
  //TrueWPT_LQ_P->Draw();

  TrueWPT_LQ_P28->Scale(1./(TrueWPT_LQ_P28->Integral()));
  TrueWPT_LQ_P28->SetMarkerStyle(21);
  TrueWPT_LQ_P28->SetMarkerColor(kBlue);
  TrueWPT_LQ_P28->SetLineColor(kBlue);
  //TrueWPT_LQ_P28->Draw("SAME");

  TrueWPT_LQ_P29->Scale(1./(TrueWPT_LQ_P29->Integral()));
  TrueWPT_LQ_P29->SetMarkerStyle(22);
  TrueWPT_LQ_P29->SetMarkerColor(kGreen);
  TrueWPT_LQ_P29->SetLineColor(kGreen);
  //TrueWPT_LQ_P29->Draw("SAME");
  
  TrueWPT_LQ_P30->Scale(1./(TrueWPT_LQ_P30->Integral()));
  TrueWPT_LQ_P30->SetMarkerStyle(23);
  TrueWPT_LQ_P30->SetMarkerColor(kOrange);
  TrueWPT_LQ_P30->SetLineColor(kOrange);
  //TrueWPT_LQ_P30->Draw("SAME");
  //TrueWPT_LQ_P30->GetXaxis()->SetTitle("Momentum");
  //TrueWPT_LQ_P30->GetYaxis()->SetTitle("Count");

  TrueWPT_LQ_P31->Scale(1./(TrueWPT_LQ_P31->Integral()));
  TrueWPT_LQ_P31->SetMarkerStyle(22);
  TrueWPT_LQ_P31->SetMarkerColor(kViolet);
  TrueWPT_LQ_P31->SetLineColor(kViolet);
  //TrueWPT_LQ_P31->Draw("SAME");

  TrueWPT_LQ_P32->Scale(1./(TrueWPT_LQ_P32->Integral()));
  TrueWPT_LQ_P32->SetMarkerStyle(22);
  //TrueWPT_LQ_P32->Draw("SAME");

  THStack *hs19 = new THStack("hs19", "W Pt Pythia Tunes 2");

  hs19->Add(TrueWPT_LQ_P);
  hs19->Add(TrueWPT_LQ_P29);
  hs19->Add(TrueWPT_LQ_P29);
  hs19->Add(TrueWPT_LQ_P30);
  hs19->Add(TrueWPT_LQ_P31);
  hs19->Add(TrueWPT_LQ_P32);
  
  hs19->Draw("NOSTACK HIST");
  hs19->GetXaxis()->SetTitle("Transverse Momentum");

  TLegend *legend19 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend19->AddEntry(TrueWPT_LQ_P, "Pythia 21", "pl");
  legend19->AddEntry(TrueWPT_LQ_P28, "Pythia 28", "pl");
  legend19->AddEntry(TrueWPT_LQ_P29, "Pythia 29", "pl");
  legend19->AddEntry(TrueWPT_LQ_P30, "Pythia 30", "pl");
  legend19->AddEntry(TrueWPT_LQ_P31, "Pythia 31", "pl");
  legend19->AddEntry(TrueWPT_LQ_P32, "Pythia 32", "pl");
  legend19->Draw();

  c19->Print("./plots/PythiaWPtTunes2.png");





  TCanvas *c20 = new TCanvas("c20", "Jet Pt Systematics Plot", 800, 600);
  c20->cd();

  LeadJetPt_LQ_Pythia->Scale(1./(LeadJetPt_LQ_Pythia->Integral()));
  LeadJetPt_LQ_Pythia->SetMarkerStyle(20);
  LeadJetPt_LQ_Pythia->SetMarkerColor(kRed);
  LeadJetPt_LQ_Pythia->SetLineColor(kRed);
  LeadJetPt_LQ_Pythia->Draw("P");
  LeadJetPt_LQ_Pythia->GetXaxis()->SetTitle("Momentum");
  LeadJetPt_LQ_Pythia->GetYaxis()->SetTitle("Count");

  LeadJetPt_LQ_P1->Scale(1./(LeadJetPt_LQ_P1->Integral()));
  LeadJetPt_LQ_P1->SetMarkerStyle(21);
  LeadJetPt_LQ_P1->SetMarkerColor(kBlue);
  LeadJetPt_LQ_P1->SetLineColor(kBlue);
  LeadJetPt_LQ_P1->Draw("SAME L");

  LeadJetPt_LQ_P2->Scale(1./(LeadJetPt_LQ_P2->Integral()));
  LeadJetPt_LQ_P2->SetMarkerStyle(22);
  LeadJetPt_LQ_P2->SetMarkerColor(kGreen);
  LeadJetPt_LQ_P2->SetLineColor(kGreen);
  LeadJetPt_LQ_P2->Draw("SAME L");
  
  LeadJetPt_LQ_P3->Scale(1./(LeadJetPt_LQ_P3->Integral()));
  LeadJetPt_LQ_P3->SetMarkerStyle(23);
  LeadJetPt_LQ_P3->SetMarkerColor(kOrange);
  LeadJetPt_LQ_P3->SetLineColor(kOrange);
  LeadJetPt_LQ_P3->Draw("SAME");

  LeadJetPt_LQ_P4->Scale(1./(LeadJetPt_LQ_P4->Integral()));
  LeadJetPt_LQ_P4->SetMarkerStyle(22);
  LeadJetPt_LQ_P4->SetMarkerColor(kViolet);
  LeadJetPt_LQ_P4->SetLineColor(kViolet);
  LeadJetPt_LQ_P4->Draw("SAME");

  LeadJetPt_LQ_P5->Scale(1./(LeadJetPt_LQ_P5->Integral()));
  LeadJetPt_LQ_P5->SetMarkerStyle(22);
  LeadJetPt_LQ_P5->Draw("SAME");

  LeadJetPt_LQ_P6->Scale(1./(LeadJetPt_LQ_P6->Integral()));
  LeadJetPt_LQ_P6->SetMarkerStyle(22);
  LeadJetPt_LQ_P6->SetMarkerColor(kGray);
  LeadJetPt_LQ_P6->SetLineColor(kGray);
  LeadJetPt_LQ_P6->Draw("SAME");

  TLegend *legend20 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend20->AddEntry(LeadJetPt_LQ_Pythia, "Nominal 0", "pl");
  legend20->AddEntry(LeadJetPt_LQ_P1, "Pythia 1", "pl");
  legend20->AddEntry(LeadJetPt_LQ_P2, "Pythia 2", "pl");
  legend20->AddEntry(LeadJetPt_LQ_P3, "Pythia 3", "pl");
  legend20->AddEntry(LeadJetPt_LQ_P4, "Pythia 4", "pl");
  legend20->AddEntry(LeadJetPt_LQ_P5, "Pythia 5", "pl");
  legend20->AddEntry(LeadJetPt_LQ_P6, "Pythia 6", "pl");
  legend20->Draw();

  c20->SetLogy();
  c20->Print("./plots/JetPtSystematics.png");



  TCanvas *c22 = new TCanvas("c22", "Jet Pt Ratios Plot", 800, 600);
  c22->cd();

  TH1F *JetPtRatio1 = (TH1F*)LeadJetPt_LQ_P1->Clone("JetPtRatio1");
  TH1F *JetPtRatio2 = (TH1F*)LeadJetPt_LQ_P2->Clone("JetPtRatio2");
  TH1F *JetPtRatio3 = (TH1F*)LeadJetPt_LQ_P3->Clone("JetPtRatio3");
  TH1F *JetPtRatio4 = (TH1F*)LeadJetPt_LQ_P4->Clone("JetPtRatio4");
  TH1F *JetPtRatio5 = (TH1F*)LeadJetPt_LQ_P5->Clone("JetPtRatio5");
  TH1F *JetPtRatio6 = (TH1F*)LeadJetPt_LQ_P6->Clone("JetPtRatio6");
  JetPtRatio1->Divide(LeadJetPt_LQ_Pythia);
  JetPtRatio2->Divide(LeadJetPt_LQ_Pythia);
  JetPtRatio3->Divide(LeadJetPt_LQ_Pythia);
  JetPtRatio4->Divide(LeadJetPt_LQ_Pythia);
  JetPtRatio5->Divide(LeadJetPt_LQ_Pythia);
  JetPtRatio6->Divide(LeadJetPt_LQ_Pythia);


  JetPtRatio1->SetMarkerStyle(20);
  JetPtRatio1->SetMarkerColor(kBlue);
  JetPtRatio1->SetLineColor(kBlue);
  JetPtRatio1->Draw("P");
  JetPtRatio1->GetXaxis()->SetTitle("Momentum");
  JetPtRatio1->GetYaxis()->SetTitle("Ratio");


  JetPtRatio2->SetMarkerStyle(22);
  JetPtRatio2->SetMarkerColor(kGreen);
  JetPtRatio2->SetLineColor(kGreen);
  JetPtRatio2->Draw("SAME");
  
  JetPtRatio3->SetMarkerStyle(23);
  JetPtRatio3->SetMarkerColor(kOrange);
  JetPtRatio3->SetLineColor(kOrange);
  JetPtRatio3->Draw("SAME");

  JetPtRatio4->SetMarkerStyle(22);
  JetPtRatio4->SetMarkerColor(kViolet);
  JetPtRatio4->SetLineColor(kViolet);
  JetPtRatio4->Draw("SAME");

  JetPtRatio5->SetMarkerStyle(22);
  JetPtRatio5->Draw("SAME");

  JetPtRatio6->SetMarkerStyle(22);
  JetPtRatio6->SetMarkerColor(kGray);
  JetPtRatio6->SetLineColor(kGray);
  JetPtRatio6->Draw("SAME");

  TLegend *legend22 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend22->AddEntry(JetPtRatio1, "Pythia 1", "pl");
  legend22->AddEntry(JetPtRatio2, "Pythia 2", "pl");
  legend22->AddEntry(JetPtRatio3, "Pythia 3", "pl");
  legend22->AddEntry(JetPtRatio4, "Pythia 4", "pl");
  legend22->AddEntry(JetPtRatio5, "Pythia 5", "pl");
  legend22->AddEntry(JetPtRatio6, "Pythia 6", "pl");
  legend22->Draw();

  c22->Print("./plots/JetPtSystematicRatios.png");




  TCanvas *c23 = new TCanvas("c23", "Jet Rap Systematics Plot", 800, 600);
  c23->cd();

  LeadJetRap_LQ_P->Scale(1./(LeadJetRap_LQ_P->Integral()));
  LeadJetRap_LQ_P->SetMarkerStyle(20);
  LeadJetRap_LQ_P->SetMarkerColor(kRed);
  LeadJetRap_LQ_P->SetLineColor(kRed);
  LeadJetRap_LQ_P->Draw("P");
  LeadJetRap_LQ_P->GetXaxis()->SetTitle("Rapidity");
  LeadJetRap_LQ_P->GetYaxis()->SetTitle("Count");

  LeadJetRap_LQ_P1->Scale(1./(LeadJetRap_LQ_P1->Integral()));
  LeadJetRap_LQ_P1->SetMarkerStyle(21);
  LeadJetRap_LQ_P1->SetMarkerColor(kBlue);
  LeadJetRap_LQ_P1->SetLineColor(kBlue);
  LeadJetRap_LQ_P1->Draw("SAME L");

  LeadJetRap_LQ_P2->Scale(1./(LeadJetRap_LQ_P2->Integral()));
  LeadJetRap_LQ_P2->SetMarkerStyle(22);
  LeadJetRap_LQ_P2->SetMarkerColor(kGreen);
  LeadJetRap_LQ_P2->SetLineColor(kGreen);
  LeadJetRap_LQ_P2->Draw("SAME L");
  
  LeadJetRap_LQ_P3->Scale(1./(LeadJetRap_LQ_P3->Integral()));
  LeadJetRap_LQ_P3->SetMarkerStyle(23);
  LeadJetRap_LQ_P3->SetMarkerColor(kOrange);
  LeadJetRap_LQ_P3->SetLineColor(kOrange);
  LeadJetRap_LQ_P3->Draw("SAME");

  LeadJetRap_LQ_P4->Scale(1./(LeadJetRap_LQ_P4->Integral()));
  LeadJetRap_LQ_P4->SetMarkerStyle(22);
  LeadJetRap_LQ_P4->SetMarkerColor(kViolet);
  LeadJetRap_LQ_P4->SetLineColor(kViolet);
  LeadJetRap_LQ_P4->Draw("SAME");

  LeadJetRap_LQ_P5->Scale(1./(LeadJetRap_LQ_P5->Integral()));
  LeadJetRap_LQ_P5->SetMarkerStyle(22);
  LeadJetRap_LQ_P5->Draw("SAME");

  LeadJetRap_LQ_P6->Scale(1./(LeadJetRap_LQ_P6->Integral()));
  LeadJetRap_LQ_P6->SetMarkerStyle(22);
  LeadJetRap_LQ_P6->SetMarkerColor(kGray);
  LeadJetRap_LQ_P6->SetLineColor(kGray);
  LeadJetRap_LQ_P6->Draw("SAME");

  TLegend *legend23 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend23->AddEntry(LeadJetRap_LQ_P, "Nominal 0", "pl");
  legend23->AddEntry(LeadJetRap_LQ_P1, "Pythia 1", "pl");
  legend23->AddEntry(LeadJetRap_LQ_P2, "Pythia 2", "pl");
  legend23->AddEntry(LeadJetRap_LQ_P3, "Pythia 3", "pl");
  legend23->AddEntry(LeadJetRap_LQ_P4, "Pythia 4", "pl");
  legend23->AddEntry(LeadJetRap_LQ_P5, "Pythia 5", "pl");
  legend23->AddEntry(LeadJetRap_LQ_P6, "Pythia 6", "pl");
  legend23->Draw();

  c23->Print("./plots/JetRapSystematics.png");



  TCanvas *c24 = new TCanvas("c24", "Jet Rap Ratios Plot", 800, 600);
  c24->cd();

  TH1F *JetRapRatio1 = (TH1F*)LeadJetRap_LQ_P1->Clone("JetRapRatio1");
  TH1F *JetRapRatio2 = (TH1F*)LeadJetRap_LQ_P2->Clone("JetRapRatio2");
  TH1F *JetRapRatio3 = (TH1F*)LeadJetRap_LQ_P3->Clone("JetRapRatio3");
  TH1F *JetRapRatio4 = (TH1F*)LeadJetRap_LQ_P4->Clone("JetRapRatio4");
  TH1F *JetRapRatio5 = (TH1F*)LeadJetRap_LQ_P5->Clone("JetRapRatio5");
  TH1F *JetRapRatio6 = (TH1F*)LeadJetRap_LQ_P6->Clone("JetRapRatio6");
  JetRapRatio1->Divide(LeadJetRap_LQ_P);
  JetRapRatio2->Divide(LeadJetRap_LQ_P);
  JetRapRatio3->Divide(LeadJetRap_LQ_P);
  JetRapRatio4->Divide(LeadJetRap_LQ_P);
  JetRapRatio5->Divide(LeadJetRap_LQ_P);
  JetRapRatio6->Divide(LeadJetRap_LQ_P);


  JetRapRatio1->SetMarkerStyle(20);
  JetRapRatio1->SetMarkerColor(kBlue);
  JetRapRatio1->SetLineColor(kBlue);
  JetRapRatio1->Draw("P");
  JetRapRatio1->GetXaxis()->SetTitle("Rapidity");
  JetRapRatio1->GetYaxis()->SetTitle("Ratio");


  JetRapRatio2->SetMarkerStyle(22);
  JetRapRatio2->SetMarkerColor(kGreen);
  JetRapRatio2->SetLineColor(kGreen);
  JetRapRatio2->Draw("SAME");
  
  JetRapRatio3->SetMarkerStyle(23);
  JetRapRatio3->SetMarkerColor(kOrange);
  JetRapRatio3->SetLineColor(kOrange);
  JetRapRatio3->Draw("SAME");

  JetRapRatio4->SetMarkerStyle(22);
  JetRapRatio4->SetMarkerColor(kViolet);
  JetRapRatio4->SetLineColor(kViolet);
  JetRapRatio4->Draw("SAME");

  JetRapRatio5->SetMarkerStyle(22);
  JetRapRatio5->Draw("SAME");

  JetRapRatio6->SetMarkerStyle(22);
  JetRapRatio6->SetMarkerColor(kGray);
  JetRapRatio6->SetLineColor(kGray);
  JetRapRatio6->Draw("SAME");

  TLegend *legend24 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend24->AddEntry(JetRapRatio1, "Pythia 1", "pl");
  legend24->AddEntry(JetRapRatio2, "Pythia 2", "pl");
  legend24->AddEntry(JetRapRatio3, "Pythia 3", "pl");
  legend24->AddEntry(JetRapRatio4, "Pythia 4", "pl");
  legend24->AddEntry(JetRapRatio5, "Pythia 5", "pl");
  legend24->AddEntry(JetRapRatio6, "Pythia 6", "pl");
  legend24->Draw();

  c24->Print("./plots/JetRapSystematicRatios.png");

  






  TCanvas *c25 = new TCanvas("c25", "Jet Rap Simulations Plot", 800, 600);
  c25->cd();

  LeadJetRap_LQ_P->SetMarkerStyle(20);
  LeadJetRap_LQ_P->SetMarkerColor(kRed);
  LeadJetRap_LQ_P->SetLineColor(kRed);
  LeadJetRap_LQ_P->Draw("P");
  LeadJetRap_LQ_P->GetXaxis()->SetTitle("Rapidity");
  LeadJetRap_LQ_P->GetYaxis()->SetTitle("Count");

  LeadJetRap_LQ_D->Scale(1./(LeadJetRap_LQ_D->Integral()));
  LeadJetRap_LQ_D->SetMarkerStyle(21);
  LeadJetRap_LQ_D->SetMarkerColor(kBlue);
  LeadJetRap_LQ_D->SetLineColor(kBlue);
  LeadJetRap_LQ_D->Draw("SAME P");

  LeadJetRap_LQ_V->Scale(1./(LeadJetRap_LQ_V->Integral()));
  LeadJetRap_LQ_V->SetMarkerStyle(22);
  LeadJetRap_LQ_V->SetMarkerColor(kGreen);
  LeadJetRap_LQ_V->SetLineColor(kGreen);
  LeadJetRap_LQ_V->Draw("SAME P");

  TLegend *legend25 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend25->AddEntry(LeadJetRap_LQ_P, "Pythia", "pl");
  legend25->AddEntry(LeadJetRap_LQ_D, "Dire", "pl");
  legend25->AddEntry(LeadJetRap_LQ_V, "Vincia", "pl");
  legend25->Draw();

  c25->Print("./plots/JetRapSimulations.png");



  TCanvas *c26 = new TCanvas("c26", "Jet Rap Simulation Ratios Plot", 800, 600);
  c26->cd();

  TH1F *JetRapRatioD = (TH1F*)LeadJetRap_LQ_D->Clone("JetRapRatioD");
  TH1F *JetRapRatioV = (TH1F*)LeadJetRap_LQ_V->Clone("JetRapRatioV");
  
  JetRapRatioD->Divide(LeadJetRap_LQ_P);
  JetRapRatioV->Divide(LeadJetRap_LQ_P);

  JetRapRatioD->SetMarkerStyle(20);
  JetRapRatioD->SetMarkerColor(kBlue);
  JetRapRatioD->SetLineColor(kBlue);
  JetRapRatioD->Draw("P");
  JetRapRatioD->GetXaxis()->SetTitle("Rapidity");
  JetRapRatioD->GetYaxis()->SetTitle("Ratio");


  JetRapRatioV->SetMarkerStyle(22);
  JetRapRatioV->SetMarkerColor(kGreen);
  JetRapRatioV->SetLineColor(kGreen);
  JetRapRatioV->Draw("SAME P");
  

  TLegend *legend26 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend26->AddEntry(JetRapRatioD, "Dire/Pythia", "pl");
  legend26->AddEntry(JetRapRatioV, "Vincia/Pythia", "pl");
  legend26->Draw();

  c26->Print("./plots/JetRapSimulationRatios.png");




  TCanvas *c27 = new TCanvas("c27", "Jet Pt Simulations Plot", 800, 600);
  c27->cd();

  LeadJetPt_LQ_Pythia->SetMarkerStyle(20);
  LeadJetPt_LQ_Pythia->SetMarkerColor(kRed);
  LeadJetPt_LQ_Pythia->SetLineColor(kRed);
  LeadJetPt_LQ_Pythia->Draw("P");
  LeadJetPt_LQ_Pythia->GetXaxis()->SetTitle("Momentum");
  LeadJetPt_LQ_Pythia->GetYaxis()->SetTitle("Count");

  LeadJetPt_LQ_D->Scale(1./(LeadJetPt_LQ_D->Integral()));
  LeadJetPt_LQ_D->SetMarkerStyle(21);
  LeadJetPt_LQ_D->SetMarkerColor(kBlue);
  LeadJetPt_LQ_D->SetLineColor(kBlue);
  LeadJetPt_LQ_D->Draw("SAME P");

  LeadJetPt_LQ_V->Scale(1./(LeadJetPt_LQ_V->Integral()));
  LeadJetPt_LQ_V->SetMarkerStyle(22);
  LeadJetPt_LQ_V->SetMarkerColor(kGreen);
  LeadJetPt_LQ_V->SetLineColor(kGreen);
  LeadJetPt_LQ_V->Draw("SAME P");

  TLegend *legend27 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend27->AddEntry(LeadJetPt_LQ_Pythia, "Pythia", "pl");
  legend27->AddEntry(LeadJetRap_LQ_D, "Dire", "pl");
  legend27->AddEntry(LeadJetRap_LQ_V, "Vincia", "pl");
  legend27->Draw();

  c27->SetLogy();
  c27->Print("./plots/JetPtSimulations.png");



  TCanvas *c28 = new TCanvas("c28", "Jet Pt Simulation Ratios Plot", 800, 600);
  c28->cd();

  TH1F *JetPtRatioD = (TH1F*)LeadJetPt_LQ_D->Clone("JetPtRatioD");
  TH1F *JetPtRatioV = (TH1F*)LeadJetPt_LQ_V->Clone("JetPtRatioV");
  
  JetPtRatioD->Divide(LeadJetPt_LQ_Pythia);
  JetPtRatioV->Divide(LeadJetPt_LQ_Pythia);

  JetPtRatioD->SetMarkerStyle(20);
  JetPtRatioD->SetMarkerColor(kBlue);
  JetPtRatioD->SetLineColor(kBlue);
  JetPtRatioD->Draw("P");
  JetPtRatioD->GetXaxis()->SetTitle("Momentum");
  JetPtRatioD->GetYaxis()->SetTitle("Ratio");


  JetPtRatioV->SetMarkerStyle(22);
  JetPtRatioV->SetMarkerColor(kGreen);
  JetPtRatioV->SetLineColor(kGreen);
  JetPtRatioV->Draw("SAME P");
  

  TLegend *legend28 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend28->AddEntry(JetPtRatioD, "Dire/Pythia", "pl");
  legend28->AddEntry(JetPtRatioV, "Vincia/Pythia", "pl");
  legend28->Draw();

  c28->Print("./plots/JetPtSimulationRatios.png");
  



  TCanvas *c29 = new TCanvas("c29", "Z Boson Transverse Momentum Plot", 800, 600);
  c29->cd();
  TrueZPt_ZP->Scale(1./(TrueZPt_ZP->Integral()));
  TrueZPt_ZD->Scale(1./(TrueZPt_ZD->Integral()));
  TrueZPt_ZV->Scale(1./(TrueZPt_ZV->Integral()));
  TrueZPt_ZP->SetLineColor(kRed);
  TrueZPt_ZP->SetMarkerStyle(20);
  TrueZPt_ZP->SetMarkerColor(kRed);
  TrueZPt_ZP->SetMarkerSize(1.0);
	TrueZPt_ZV->GetXaxis()->SetTitle("Transverse Momentum [GeV/c]");
  TrueZPt_ZV->GetYaxis()->SetTitle("Count");
  TrueZPt_ZD->SetLineColor(kBlue);
  TrueZPt_ZD->SetMarkerStyle(21);
  TrueZPt_ZD->SetMarkerColor(kBlue);
  TrueZPt_ZV->SetLineColor(kGreen);
  TrueZPt_ZV->SetMarkerStyle(22);
  TrueZPt_ZV->SetMarkerColor(kGreen);
  TrueZPt_ZV->Draw("HIST");
  TrueZPt_ZP->Draw("SAME HIST");
  TrueZPt_ZD->Draw("SAME HIST");

  TLegend *legend29 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend29->AddEntry(TrueZPt_ZP, "Pythia", "p");
  legend29->AddEntry(TrueZPt_ZD, "Dire", "p");
  legend29->AddEntry(TrueZPt_ZV, "Vincia", "p");
  legend29->Draw();

	c29->Print("./plots/TrueZPt.png");




  TCanvas *c30 = new TCanvas("c30", "Z Boson Pt Simulation Ratio Plot", 800, 600);
  c30->cd();
  TH1F *ZPtRatioDtoP = (TH1F*)TrueZPt_ZD->Clone("ZPtRatioDtoP");
  TH1F *ZPtRatioVtoP = (TH1F*)TrueZPt_ZV->Clone("ZPtRatioVtoP");
  ZPtRatioDtoP->Divide(TrueZPt_ZP);
  ZPtRatioVtoP->Divide(TrueZPt_ZP);

  THStack *hs30 = new THStack("hs30", "Z Pt Ratios");

  ZPtRatioDtoP->SetMarkerStyle(20);
  ZPtRatioDtoP->SetMarkerColor(kBlue);
  ZPtRatioDtoP->SetLineColor(kBlue);
  ZPtRatioVtoP->SetMarkerStyle(21);
  ZPtRatioVtoP->SetMarkerColor(kGreen);
  ZPtRatioVtoP->SetLineColor(kGreen);
  //ZPtRatioDtoP->Draw("HIST");
  //ZPtRatioVtoP->Draw("SAME HIST");
  //ZPtRatioDtoP->GetXaxis()->SetTitle("Momentum");
  //ZPtRatioDtoP->GetYaxis()->SetTitle("Ratio");
  hs30->Add(ZPtRatioDtoP);
  hs30->Add(ZPtRatioVtoP);
  
  hs30->Draw("NOSTACK HIST");
  hs30->GetXaxis()->SetTitle("Transverse Momentum");

  TLegend *legend30 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend30->AddEntry(ZPtRatioDtoP, "Dire/Pythia", "pl");
  legend30->AddEntry(ZPtRatioVtoP, "Vincia/Pythia", "pl");
  legend30->Draw();

  c30->Print("./plots/ZPtSimulationRatio.png");

    

  TCanvas *c31 = new TCanvas("c31", "Z Boson Rapidity Simulation Ratio Plot", 800, 600);
  c31->cd();
  THStack *hs31 = new THStack("hs31", "Z Rapidity Simulations");

  TrueZRap_ZP->Scale(1./(TrueZRap_ZP->Integral()));
  TrueZRap_ZD->Scale(1./(TrueZRap_ZD->Integral()));
  TrueZRap_ZV->Scale(1./(TrueZRap_ZV->Integral()));
  TrueZRap_ZP->SetLineColor(kRed);
  TrueZRap_ZP->SetMarkerStyle(20);
  TrueZRap_ZP->SetMarkerColor(kRed);
  TrueZRap_ZP->SetMarkerSize(1.0);
  TrueZRap_ZD->SetLineColor(kBlue);
  TrueZRap_ZD->SetMarkerStyle(21);
  TrueZRap_ZD->SetMarkerColor(kBlue);
  TrueZRap_ZV->SetLineColor(kGreen);
  TrueZRap_ZV->SetMarkerStyle(22);
  TrueZRap_ZV->SetMarkerColor(kGreen);

  hs31->Add(TrueZRap_ZP);
  hs31->Add(TrueZRap_ZD);
  hs31->Add(TrueZRap_ZV);
  hs31->Draw("NOSTACK HIST");
  hs31->GetXaxis()->SetTitle("Rapidity");

  TLegend *legend31 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend31->AddEntry(TrueZRap_ZP, "Pythia", "p");
  legend31->AddEntry(TrueZRap_ZD, "Dire", "p");
  legend31->AddEntry(TrueZRap_ZV, "Vincia", "p");
  legend31->Draw();

	c31->Print("./plots/TrueZRap.png");



  TCanvas *c32 = new TCanvas("c32", "Z Boson Rapidity Simulation Ratio Plot", 800, 600);
  c32->cd();
  TH1F *ZRapRatioDtoP = (TH1F*)TrueZRap_ZD->Clone("ZRapRatioDtoP");
  TH1F *ZRapRatioVtoP = (TH1F*)TrueZRap_ZV->Clone("ZRapRatioVtoP");
  ZRapRatioDtoP->Divide(TrueZRap_ZP);
  ZRapRatioVtoP->Divide(TrueZRap_ZP);

  THStack *hs32 = new THStack("hs32", "Z Rapidity Ratios");

  ZRapRatioDtoP->SetMarkerStyle(20);
  ZRapRatioDtoP->SetMarkerColor(kBlue);
  ZRapRatioDtoP->SetLineColor(kBlue);
  ZRapRatioVtoP->SetMarkerStyle(21);
  ZRapRatioVtoP->SetMarkerColor(kGreen);
  ZRapRatioVtoP->SetLineColor(kGreen);
  //ZPtRatioDtoP->Draw("HIST");
  //ZPtRatioVtoP->Draw("SAME HIST");
  //ZPtRatioDtoP->GetXaxis()->SetTitle("Momentum");
  //ZPtRatioDtoP->GetYaxis()->SetTitle("Ratio");
  hs32->Add(ZRapRatioDtoP);
  hs32->Add(ZRapRatioVtoP);
  
  hs32->Draw("NOSTACK HIST");
  hs32->GetXaxis()->SetTitle("Rapidity");
  
  TLegend *legend32 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend32->AddEntry(ZRapRatioDtoP, "Dire/Pythia", "pl");
  legend32->AddEntry(ZRapRatioVtoP, "Vincia/Pythia", "pl");
  legend32->Draw();

  c32->Print("./plots/ZRapSimulationRatio.png");





  TCanvas *c33 = new TCanvas("c33", "Z Pt Tunes Plot", 800, 600);
  c33->cd();

  TrueZPt_ZP->SetMarkerStyle(20);
  TrueZPt_ZP->SetMarkerColor(kRed);
  TrueZPt_ZP->SetLineColor(kRed);
  //TrueZPt_ZP->Draw();

  TrueZPt_ZP23->Scale(1./(TrueZPt_ZP23->Integral()));
  TrueZPt_ZP23->SetMarkerStyle(21);
  TrueZPt_ZP23->SetMarkerColor(kBlue);
  TrueZPt_ZP23->SetLineColor(kBlue);
  //TrueZPt_ZP23->Draw("SAME");

  TrueZPt_ZP24->Scale(1./(TrueZPt_ZP24->Integral()));
  TrueZPt_ZP24->SetMarkerStyle(22);
  TrueZPt_ZP24->SetMarkerColor(kGreen);
  TrueZPt_ZP24->SetLineColor(kGreen);
  //TrueZPt_ZP24->Draw("SAME");
  
  TrueZPt_ZP25->Scale(1./(TrueZPt_ZP25->Integral()));
  TrueZPt_ZP25->SetMarkerStyle(23);
  TrueZPt_ZP25->SetMarkerColor(kOrange);
  TrueZPt_ZP25->SetLineColor(kOrange);
  //TrueZPt_ZP25->Draw("SAME");
  //TrueZPt_ZP25->GetXaxis()->SetTitle("Momentum");
  //TrueZPt_ZP25->GetYaxis()->SetTitle("Count");

  TrueZPt_ZP26->Scale(1./(TrueZPt_ZP26->Integral()));
  TrueZPt_ZP26->SetMarkerStyle(22);
  TrueZPt_ZP26->SetMarkerColor(kViolet);
  TrueZPt_ZP26->SetLineColor(kViolet);
  //TrueZPt_ZP26->Draw("SAME");

  TrueZPt_ZP27->Scale(1./(TrueZPt_ZP27->Integral()));
  TrueZPt_ZP27->SetMarkerStyle(22);
  //TrueZPt_ZP27->Draw("SAME");


  THStack *hs33 = new THStack("hs33", "Z Pt Pythia Tunes");

  hs33->Add(TrueZPt_ZP);
  hs33->Add(TrueZPt_ZP23);
  hs33->Add(TrueZPt_ZP24);
  hs33->Add(TrueZPt_ZP25);
  hs33->Add(TrueZPt_ZP26);
  hs33->Add(TrueZPt_ZP27);
  
  hs33->Draw("NOSTACK HIST");
  hs33->GetXaxis()->SetTitle("Transverse Momentum");

  TLegend *legend33 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend33->AddEntry(TrueZPt_ZP, "Pythia 21", "pl");
  legend33->AddEntry(TrueZPt_ZP23, "Pythia 23", "pl");
  legend33->AddEntry(TrueZPt_ZP24, "Pythia 24", "pl");
  legend33->AddEntry(TrueZPt_ZP25, "Pythia 25", "pl");
  legend33->AddEntry(TrueZPt_ZP26, "Pythia 26", "pl");
  legend33->AddEntry(TrueZPt_ZP27, "Pythia 27", "pl");
  legend33->Draw();

  c33->Print("./plots/PythiaZPtTunes1.png");



  TCanvas *c34 = new TCanvas("c34", "Z Pt Tunes Plot 2", 800, 600);
  c34->cd();

  TrueZPt_ZP->SetMarkerStyle(20);
  TrueZPt_ZP->SetMarkerColor(kRed);
  TrueZPt_ZP->SetLineColor(kRed);
  //TrueZPt_ZP->Draw();

  TrueZPt_ZP28->Scale(1./(TrueZPt_ZP28->Integral()));
  TrueZPt_ZP28->SetMarkerStyle(21);
  TrueZPt_ZP28->SetMarkerColor(kBlue);
  TrueZPt_ZP28->SetLineColor(kBlue);
  //TrueZPt_ZP28->Draw("SAME");

  TrueZPt_ZP29->Scale(1./(TrueZPt_ZP29->Integral()));
  TrueZPt_ZP29->SetMarkerStyle(22);
  TrueZPt_ZP29->SetMarkerColor(kGreen);
  TrueZPt_ZP29->SetLineColor(kGreen);
  //TrueZPt_ZP29->Draw("SAME");
  
  TrueZPt_ZP30->Scale(1./(TrueZPt_ZP30->Integral()));
  TrueZPt_ZP30->SetMarkerStyle(23);
  TrueZPt_ZP30->SetMarkerColor(kOrange);
  TrueZPt_ZP30->SetLineColor(kOrange);
  TrueZPt_ZP30->Draw("SAME");
  TrueZPt_ZP30->GetXaxis()->SetTitle("Momentum");
  //TrueZPt_ZP30->GetYaxis()->SetTitle("Count");

  TrueZPt_ZP31->Scale(1./(TrueZPt_ZP31->Integral()));
  TrueZPt_ZP31->SetMarkerStyle(22);
  TrueZPt_ZP31->SetMarkerColor(kViolet);
  TrueZPt_ZP31->SetLineColor(kViolet);
  //TrueZPt_ZP31->Draw("SAME");

  TrueZPt_ZP32->Scale(1./(TrueZPt_ZP32->Integral()));
  TrueZPt_ZP32->SetMarkerStyle(22);
  //TrueZPt_ZP32->Draw("SAME");

  THStack *hs34 = new THStack("hs34", "Z Pt Pythia Tunes 2");

  hs34->Add(TrueZPt_ZP);
  hs34->Add(TrueZPt_ZP28);
  hs34->Add(TrueZPt_ZP29);
  hs34->Add(TrueZPt_ZP30);
  hs34->Add(TrueZPt_ZP31);
  hs34->Add(TrueZPt_ZP32);
  
  hs34->Draw("NOSTACK HIST");
  hs34->GetXaxis()->SetTitle("Transverse Momentum");

  TLegend *legend34 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend34->AddEntry(TrueWPT_LQ_P, "Pythia 21", "pl");
  legend34->AddEntry(TrueZPt_ZP28, "Pythia 28", "pl");
  legend34->AddEntry(TrueZPt_ZP29, "Pythia 29", "pl");
  legend34->AddEntry(TrueZPt_ZP30, "Pythia 30", "pl");
  legend34->AddEntry(TrueZPt_ZP31, "Pythia 31", "pl");
  legend34->AddEntry(TrueZPt_ZP32, "Pythia 32", "pl");
  legend34->Draw();

  c34->Print("./plots/PythiaZPtTunes2.png");





  TCanvas *c35 = new TCanvas("c35", "Z Pt Systematics Plot", 800, 600);
  c35->cd();

  TrueZPt_ZP->Scale(1./(TrueZPt_ZP->Integral()));
  TrueZPt_ZP->SetMarkerStyle(20);
  TrueZPt_ZP->SetMarkerColor(kRed);
  TrueZPt_ZP->SetLineColor(kRed);
  //TrueZPt_ZP->Draw("P");
  //TrueZPt_ZP->GetXaxis()->SetTitle("Rapidity");
  //TrueZPt_ZP->GetYaxis()->SetTitle("Count");

  TrueZPt_ZP1->Scale(1./(TrueZPt_ZP1->Integral()));
  TrueZPt_ZP1->SetMarkerStyle(21);
  TrueZPt_ZP1->SetMarkerColor(kBlue);
  TrueZPt_ZP1->SetLineColor(kBlue);
  //TrueZPt_ZP1->Draw("SAME L");

  TrueZPt_ZP2->Scale(1./(TrueZPt_ZP2->Integral()));
  TrueZPt_ZP2->SetMarkerStyle(22);
  TrueZPt_ZP2->SetMarkerColor(kGreen);
  TrueZPt_ZP2->SetLineColor(kGreen);
  //TrueZPt_ZP2->Draw("SAME L");
  
  TrueZPt_ZP3->Scale(1./(TrueZPt_ZP3->Integral()));
  TrueZPt_ZP3->SetMarkerStyle(23);
  TrueZPt_ZP3->SetMarkerColor(kOrange);
  TrueZPt_ZP3->SetLineColor(kOrange);
  //TrueZPt_ZP3->Draw("SAME");

  TrueZPt_ZP4->Scale(1./(TrueZPt_ZP4->Integral()));
  TrueZPt_ZP4->SetMarkerStyle(22);
  TrueZPt_ZP4->SetMarkerColor(kViolet);
  TrueZPt_ZP4->SetLineColor(kViolet);
  //TrueZPt_ZP4->Draw("SAME");

  TrueZPt_ZP5->Scale(1./(TrueZPt_ZP5->Integral()));
  TrueZPt_ZP5->SetMarkerStyle(22);
  //TrueZPt_ZP5->Draw("SAME");

  TrueZPt_ZP6->Scale(1./(TrueZPt_ZP6->Integral()));
  TrueZPt_ZP6->SetMarkerStyle(22);
  TrueZPt_ZP6->SetMarkerColor(kGray);
  TrueZPt_ZP6->SetLineColor(kGray);
  //TrueZPt_ZP6->Draw("SAME");

  THStack *hs35 = new THStack("hs35", "Z Pt Pythia Systematics");

  hs35->Add(TrueZPt_ZP);
  hs35->Add(TrueZPt_ZP1);
  hs35->Add(TrueZPt_ZP2);
  hs35->Add(TrueZPt_ZP3);
  hs35->Add(TrueZPt_ZP4);
  hs35->Add(TrueZPt_ZP5);
  hs35->Add(TrueZPt_ZP6);
  
  hs35->Draw("NOSTACK HIST");
  hs35->GetXaxis()->SetTitle("Transverse Momentum");



  TLegend *legend35 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend35->AddEntry(TrueZPt_ZP, "Nominal 0", "pl");
  legend35->AddEntry(TrueZPt_ZP1, "Pythia 1", "pl");
  legend35->AddEntry(TrueZPt_ZP2, "Pythia 2", "pl");
  legend35->AddEntry(TrueZPt_ZP3, "Pythia 3", "pl");
  legend35->AddEntry(TrueZPt_ZP4, "Pythia 4", "pl");
  legend35->AddEntry(TrueZPt_ZP5, "Pythia 5", "pl");
  legend35->AddEntry(TrueZPt_ZP6, "Pythia 6", "pl");
  legend35->Draw();

  c35->Print("./plots/ZPtSystematics.png");



  TCanvas *c36 = new TCanvas("c36", "Z Pt Systematics Ratios", 800, 600);
  c36->cd();

  TH1F *ZPtRatio1 = (TH1F*)TrueZPt_ZP1->Clone("ZPtRatio1");
  TH1F *ZPtRatio2 = (TH1F*)TrueZPt_ZP2->Clone("ZPtRatio2");
  TH1F *ZPtRatio3 = (TH1F*)TrueZPt_ZP3->Clone("ZPtRatio3");
  TH1F *ZPtRatio4 = (TH1F*)TrueZPt_ZP4->Clone("ZPtRatio4");
  TH1F *ZPtRatio5 = (TH1F*)TrueZPt_ZP5->Clone("ZPtRatio5");
  TH1F *ZPtRatio6 = (TH1F*)TrueZPt_ZP6->Clone("ZPtRatio6");
  ZPtRatio1->Divide(TrueZPt_ZP);
  ZPtRatio2->Divide(TrueZPt_ZP);
  ZPtRatio3->Divide(TrueZPt_ZP);
  ZPtRatio4->Divide(TrueZPt_ZP);
  ZPtRatio5->Divide(TrueZPt_ZP);
  ZPtRatio6->Divide(TrueZPt_ZP);


  ZPtRatio1->SetMarkerStyle(20);
  ZPtRatio1->SetMarkerColor(kBlue);
  ZPtRatio1->SetLineColor(kBlue);
  //ZRapRatio1->Draw("P");
  //ZRapRatio1->GetXaxis()->SetTitle("Rapidity");
  //ZRapRatio1->GetYaxis()->SetTitle("Ratio");


  ZPtRatio2->SetMarkerStyle(22);
  ZPtRatio2->SetMarkerColor(kGreen);
  ZPtRatio2->SetLineColor(kGreen);
  //ZRapRatio2->Draw("SAME");
  
  ZPtRatio3->SetMarkerStyle(23);
  ZPtRatio3->SetMarkerColor(kOrange);
  ZPtRatio3->SetLineColor(kOrange);
  //ZRapRatio3->Draw("SAME");

  ZPtRatio4->SetMarkerStyle(22);
  ZPtRatio4->SetMarkerColor(kViolet);
  ZPtRatio4->SetLineColor(kViolet);
  //ZRapRatio4->Draw("SAME");

  ZPtRatio5->SetMarkerStyle(22);
  //ZRapRatio5->Draw("SAME");

  ZPtRatio6->SetMarkerStyle(22);
  ZPtRatio6->SetMarkerColor(kGray);
  ZPtRatio6->SetLineColor(kGray);
  //ZRapRatio6->Draw("SAME");

  THStack *hs36 = new THStack("hs36", "Z Pt Pythia Systematic Ratios");

  hs36->Add(ZPtRatio1);
  hs36->Add(ZPtRatio2);
  hs36->Add(ZPtRatio3);
  hs36->Add(ZPtRatio4);
  hs36->Add(ZPtRatio5);
  hs36->Add(ZPtRatio6);
  
  hs36->Draw("NOSTACK HIST");
  hs36->GetXaxis()->SetTitle("Transverse Momentum");



  TLegend *legend36 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend36->AddEntry(ZPtRatio1, "Pythia 1", "pl");
  legend36->AddEntry(ZPtRatio2, "Pythia 2", "pl");
  legend36->AddEntry(ZPtRatio3, "Pythia 3", "pl");
  legend36->AddEntry(ZPtRatio4, "Pythia 4", "pl");
  legend36->AddEntry(ZPtRatio5, "Pythia 5", "pl");
  legend36->AddEntry(ZPtRatio6, "Pythia 6", "pl");
  legend36->Draw();

  c36->Print("./plots/ZPtSystematicRatios.png");








  TCanvas *c37 = new TCanvas("c37", "W Pt Systematics Plot", 800, 600);
  c37->cd();

  TrueWPT_LQ_P->Scale(1./(TrueWPT_LQ_P->Integral()));
  TrueWPT_LQ_P->SetMarkerStyle(20);
  TrueWPT_LQ_P->SetMarkerColor(kRed);
  TrueWPT_LQ_P->SetLineColor(kRed);
  //TrueZPt_ZP->Draw("P");
  //TrueZPt_ZP->GetXaxis()->SetTitle("Rapidity");
  //TrueZPt_ZP->GetYaxis()->SetTitle("Count");

  TrueWPT_LQ_P1->Scale(1./(TrueWPT_LQ_P1->Integral()));
  TrueWPT_LQ_P1->SetMarkerStyle(21);
  TrueWPT_LQ_P1->SetMarkerColor(kBlue);
  TrueWPT_LQ_P1->SetLineColor(kBlue);
  //TrueZPt_ZP1->Draw("SAME L");

  TrueWPT_LQ_P2->Scale(1./(TrueWPT_LQ_P2->Integral()));
  TrueWPT_LQ_P2->SetMarkerStyle(22);
  TrueWPT_LQ_P2->SetMarkerColor(kGreen);
  TrueWPT_LQ_P2->SetLineColor(kGreen);
  //TrueZPt_ZP2->Draw("SAME L");
  
  TrueWPT_LQ_P3->Scale(1./(TrueWPT_LQ_P3->Integral()));
  TrueWPT_LQ_P3->SetMarkerStyle(23);
  TrueWPT_LQ_P3->SetMarkerColor(kOrange);
  TrueWPT_LQ_P3->SetLineColor(kOrange);
  //TrueZPt_ZP3->Draw("SAME");

  TrueWPT_LQ_P4->Scale(1./(TrueWPT_LQ_P4->Integral()));
  TrueWPT_LQ_P4->SetMarkerStyle(22);
  TrueWPT_LQ_P4->SetMarkerColor(kViolet);
  TrueWPT_LQ_P4->SetLineColor(kViolet);
  //TrueZPt_ZP4->Draw("SAME");

  TrueWPT_LQ_P5->Scale(1./(TrueWPT_LQ_P5->Integral()));
  TrueWPT_LQ_P5->SetMarkerStyle(22);
  //TrueZPt_ZP5->Draw("SAME");

  TrueWPT_LQ_P6->Scale(1./(TrueWPT_LQ_P6->Integral()));
  TrueWPT_LQ_P6->SetMarkerStyle(22);
  TrueWPT_LQ_P6->SetMarkerColor(kGray);
  TrueWPT_LQ_P6->SetLineColor(kGray);
  //TrueZPt_ZP6->Draw("SAME");

  THStack *hs37 = new THStack("hs37", "W Pt Pythia Systematics");

  hs37->Add(TrueWPT_LQ_P);
  hs37->Add(TrueWPT_LQ_P1);
  hs37->Add(TrueWPT_LQ_P2);
  hs37->Add(TrueWPT_LQ_P3);
  hs37->Add(TrueWPT_LQ_P4);
  hs37->Add(TrueWPT_LQ_P5);
  hs37->Add(TrueWPT_LQ_P6);
  
  hs37->Draw("NOSTACK HIST");
  hs37->GetXaxis()->SetTitle("Transverse Momentum [GeV/c]");



  TLegend *legend37 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend37->AddEntry(TrueWPT_LQ_P, "Nominal 0", "pl");
  legend37->AddEntry(TrueWPT_LQ_P1, "Pythia 1", "pl");
  legend37->AddEntry(TrueWPT_LQ_P2, "Pythia 2", "pl");
  legend37->AddEntry(TrueWPT_LQ_P3, "Pythia 3", "pl");
  legend37->AddEntry(TrueWPT_LQ_P4, "Pythia 4", "pl");
  legend37->AddEntry(TrueWPT_LQ_P5, "Pythia 5", "pl");
  legend37->AddEntry(TrueWPT_LQ_P6, "Pythia 6", "pl");
  legend37->Draw();

  c37->Print("./plots/WPtSystematics.png");



  TCanvas *c38 = new TCanvas("c38", "W Pt Systematics Ratios", 800, 600);
  c38->cd();

  TH1F *WPtRatio1 = (TH1F*)TrueWPT_LQ_P1->Clone("WPtRatio1");
  TH1F *WPtRatio2 = (TH1F*)TrueWPT_LQ_P2->Clone("WPtRatio2");
  TH1F *WPtRatio3 = (TH1F*)TrueWPT_LQ_P3->Clone("WPtRatio3");
  TH1F *WPtRatio4 = (TH1F*)TrueWPT_LQ_P4->Clone("WPtRatio4");
  TH1F *WPtRatio5 = (TH1F*)TrueWPT_LQ_P5->Clone("WPtRatio5");
  TH1F *WPtRatio6 = (TH1F*)TrueWPT_LQ_P6->Clone("WPtRatio6");
  WPtRatio1->Divide(TrueWPT_LQ_P);
  WPtRatio2->Divide(TrueWPT_LQ_P);
  WPtRatio3->Divide(TrueWPT_LQ_P);
  WPtRatio4->Divide(TrueWPT_LQ_P);
  WPtRatio5->Divide(TrueWPT_LQ_P);
  WPtRatio6->Divide(TrueWPT_LQ_P);


  WPtRatio1->SetMarkerStyle(20);
  WPtRatio1->SetMarkerColor(kBlue);
  WPtRatio1->SetLineColor(kBlue);
  //ZRapRatio1->Draw("P");
  //ZRapRatio1->GetXaxis()->SetTitle("Rapidity");
  //ZRapRatio1->GetYaxis()->SetTitle("Ratio");


  WPtRatio2->SetMarkerStyle(22);
  WPtRatio2->SetMarkerColor(kGreen);
  WPtRatio2->SetLineColor(kGreen);
  //ZRapRatio2->Draw("SAME");
  
  WPtRatio3->SetMarkerStyle(23);
  WPtRatio3->SetMarkerColor(kOrange);
  WPtRatio3->SetLineColor(kOrange);
  //ZRapRatio3->Draw("SAME");

  WPtRatio4->SetMarkerStyle(22);
  WPtRatio4->SetMarkerColor(kViolet);
  WPtRatio4->SetLineColor(kViolet);
  //ZRapRatio4->Draw("SAME");

  WPtRatio5->SetMarkerStyle(22);
  //ZRapRatio5->Draw("SAME");

  WPtRatio6->SetMarkerStyle(22);
  WPtRatio6->SetMarkerColor(kGray);
  WPtRatio6->SetLineColor(kGray);
  //ZRapRatio6->Draw("SAME");

  THStack *hs38 = new THStack("hs38", "W Pt Pythia Systematic Ratios");

  hs38->Add(WPtRatio1);
  hs38->Add(WPtRatio2);
  hs38->Add(WPtRatio3);
  hs38->Add(WPtRatio4);
  hs38->Add(WPtRatio5);
  hs38->Add(WPtRatio6);
  
  hs38->Draw("NOSTACK HIST");
  hs38->GetXaxis()->SetTitle("Transverse Momentum [GeV/c]");



  TLegend *legend38 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend38->AddEntry(WPtRatio1, "Pythia 1", "pl");
  legend38->AddEntry(WPtRatio2, "Pythia 2", "pl");
  legend38->AddEntry(WPtRatio3, "Pythia 3", "pl");
  legend38->AddEntry(WPtRatio4, "Pythia 4", "pl");
  legend38->AddEntry(WPtRatio5, "Pythia 5", "pl");
  legend38->AddEntry(WPtRatio6, "Pythia 6", "pl");
  legend38->Draw();

  c38->Print("./plots/WPtSystematicRatios.png");


  // Z to W simulation plots:

  TCanvas *c39 = new TCanvas("c39", "Z to W Pt Simulation Ratio Plot", 800, 600);
  c39->cd();
  TH1F *ZWPtRatioPtoP = (TH1F*)TrueZPt_ZP->Clone("ZWPtRatioPtoP");
  TH1F *ZWPtRatioVtoV = (TH1F*)TrueZPt_ZV->Clone("ZWPtRatioVtoV");
  TH1F *ZWPtRatioDtoD = (TH1F*)TrueZPt_ZD->Clone("ZWPtRatioDtoD");
  ZWPtRatioPtoP->Divide(TrueWPT_LQ_P);
  ZWPtRatioVtoV->Divide(TrueWPT_LQ_V);
  ZWPtRatioDtoD->Divide(TrueWPT_LQ_D);

  THStack *hs39 = new THStack("hs39", "Z to W Pt Simulation Ratios");

  ZWPtRatioPtoP->SetMarkerStyle(20);
  ZWPtRatioPtoP->SetMarkerColor(kRed);
  ZWPtRatioPtoP->SetLineColor(kRed);
  ZWPtRatioVtoV->SetMarkerStyle(21);
  ZWPtRatioVtoV->SetMarkerColor(kGreen);
  ZWPtRatioVtoV->SetLineColor(kGreen);
  ZWPtRatioDtoD->SetMarkerStyle(22);
  ZWPtRatioDtoD->SetMarkerColor(kBlue);
  ZWPtRatioDtoD->SetLineColor(kBlue);

  hs39->Add(ZWPtRatioPtoP);
  hs39->Add(ZWPtRatioDtoD);
  hs39->Add(ZWPtRatioVtoV);
  
  hs39->Draw("NOSTACK HIST");
  hs39->GetXaxis()->SetTitle("Transverse Momentum [GeV/c]");

  TLegend *legend39 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend39->AddEntry(ZWPtRatioPtoP, "Pythia", "pl");
  legend39->AddEntry(ZWPtRatioDtoD, "Dire", "pl");
  legend39->AddEntry(ZWPtRatioVtoV, "Vincia", "pl");
  legend39->Draw();

  c39->Print("./plots/ZWPtSimulationRatio.png");




  TCanvas *c40 = new TCanvas("c40", "Z to W Rap Simulation Ratio Plot", 800, 600);
  c40->cd();
  TH1F *ZWRapRatioPtoP = (TH1F*)TrueZRap_ZP->Clone("ZWRapRatioPtoP");
  TH1F *ZWRapRatioVtoV = (TH1F*)TrueZRap_ZV->Clone("ZWRapRatioVtoV");
  TH1F *ZWRapRatioDtoD = (TH1F*)TrueZRap_ZD->Clone("ZWRapRatioDtoD");
  ZWRapRatioPtoP->Divide(TrueWRap_LQ_P);
  ZWRapRatioVtoV->Divide(TrueWRap_LQ_V);
  ZWRapRatioDtoD->Divide(TrueWRap_LQ_D);

  THStack *hs40 = new THStack("hs40", "Z to W Rap Simulation Ratios");

  ZWRapRatioPtoP->SetMarkerStyle(20);
  ZWRapRatioPtoP->SetMarkerColor(kRed);
  ZWRapRatioPtoP->SetLineColor(kRed);
  ZWRapRatioVtoV->SetMarkerStyle(21);
  ZWRapRatioVtoV->SetMarkerColor(kGreen);
  ZWRapRatioVtoV->SetLineColor(kGreen);
  ZWRapRatioDtoD->SetMarkerStyle(22);
  ZWRapRatioDtoD->SetMarkerColor(kBlue);
  ZWRapRatioDtoD->SetLineColor(kBlue);

  hs40->Add(ZWRapRatioPtoP);
  hs40->Add(ZWRapRatioDtoD);
  hs40->Add(ZWRapRatioVtoV);
  
  hs40->Draw("NOSTACK HIST");
  hs40->GetXaxis()->SetTitle("Rapidity");

  TLegend *legend40 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend40->AddEntry(ZWRapRatioPtoP, "Pythia", "pl");
  legend40->AddEntry(ZWRapRatioDtoD, "Dire", "pl");
  legend40->AddEntry(ZWRapRatioVtoV, "Vincia", "pl");
  legend40->Draw();

  c40->Print("./plots/ZWRapSimulationRatio.png");


  // Z to W systematics plots:

  TCanvas *c41 = new TCanvas("c41", "Z to W Pt Systematics Ratios", 800, 600);
  c41->cd();

  TH1F *ZWPtSysRatio0 = (TH1F*)TrueZPt_ZP->Clone("ZWPtSysRatio0");
  TH1F *ZWPtSysRatio1 = (TH1F*)TrueZPt_ZP1->Clone("ZWPtSysRatio1");
  TH1F *ZWPtSysRatio2 = (TH1F*)TrueZPt_ZP2->Clone("ZWPtSysRatio2");
  TH1F *ZWPtSysRatio3 = (TH1F*)TrueZPt_ZP3->Clone("ZWPtSysRatio3");
  TH1F *ZWPtSysRatio4 = (TH1F*)TrueZPt_ZP4->Clone("ZWPtSysRatio4");
  TH1F *ZWPtSysRatio5 = (TH1F*)TrueZPt_ZP5->Clone("ZWPtSysRatio5");
  TH1F *ZWPtSysRatio6 = (TH1F*)TrueZPt_ZP6->Clone("ZWPtSysRatio6");
  ZWPtSysRatio0->Divide(TrueWPT_LQ_P);
  ZWPtSysRatio1->Divide(TrueWPT_LQ_P1);
  ZWPtSysRatio2->Divide(TrueWPT_LQ_P2);
  ZWPtSysRatio3->Divide(TrueWPT_LQ_P3);
  ZWPtSysRatio4->Divide(TrueWPT_LQ_P4);
  ZWPtSysRatio5->Divide(TrueWPT_LQ_P5);
  ZWPtSysRatio6->Divide(TrueWPT_LQ_P6);

  ZWPtSysRatio0->SetMarkerStyle(20);
  ZWPtSysRatio0->SetMarkerColor(kTeal);
  ZWPtSysRatio0->SetLineColor(kTeal);

  ZWPtSysRatio1->SetMarkerStyle(20);
  ZWPtSysRatio1->SetMarkerColor(kBlue);
  ZWPtSysRatio1->SetLineColor(kBlue);

  ZWPtSysRatio2->SetMarkerStyle(22);
  ZWPtSysRatio2->SetMarkerColor(kGreen);
  ZWPtSysRatio2->SetLineColor(kGreen);
  
  ZWPtSysRatio3->SetMarkerStyle(23);
  ZWPtSysRatio3->SetMarkerColor(kOrange);
  ZWPtSysRatio3->SetLineColor(kOrange);

  ZWPtSysRatio4->SetMarkerStyle(22);
  ZWPtSysRatio4->SetMarkerColor(kViolet);
  ZWPtSysRatio4->SetLineColor(kViolet);

  ZWPtSysRatio5->SetMarkerStyle(22);

  ZWPtSysRatio6->SetMarkerStyle(22);
  ZWPtSysRatio6->SetMarkerColor(kGray);
  ZWPtSysRatio6->SetLineColor(kGray);

  THStack *hs41 = new THStack("hs41", "Z to W Pt Pythia Systematic Ratios");

  hs41->Add(ZWPtSysRatio0);
  hs41->Add(ZWPtSysRatio1);
  hs41->Add(ZWPtSysRatio2);
  hs41->Add(ZWPtSysRatio3);
  hs41->Add(ZWPtSysRatio4);
  hs41->Add(ZWPtSysRatio5);
  hs41->Add(ZWPtSysRatio6);
  
  hs41->Draw("NOSTACK HIST");
  hs41->GetXaxis()->SetTitle("Transverse Momentum [GeV/c]");



  TLegend *legend41 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend41->AddEntry(ZWPtSysRatio0, "Nominal Z/W", "pl");
  legend41->AddEntry(ZWPtSysRatio1, "Z P1/W P1", "pl");
  legend41->AddEntry(ZWPtSysRatio2, "Z P2/W P2", "pl");
  legend41->AddEntry(ZWPtSysRatio3, "Z P3/W P3", "pl");
  legend41->AddEntry(ZWPtSysRatio4, "Z P4/W P4", "pl");
  legend41->AddEntry(ZWPtSysRatio5, "Z P5/W P5", "pl");
  legend41->AddEntry(ZWPtSysRatio6, "Z P6/W P6", "pl");
  legend41->Draw();

  c41->Print("./plots/ZWPtSystematicRatios.png");


  TCanvas *c42 = new TCanvas("c42", "Z to W Rap Systematics Ratios", 800, 600);
  c42->cd();

  TH1F *ZWRapSysRatio0 = (TH1F*)TrueZRap_ZP->Clone("ZWRapSysRatio0");
  TH1F *ZWRapSysRatio1 = (TH1F*)TrueZRap_ZP1->Clone("ZWRapSysRatio1");
  TH1F *ZWRapSysRatio2 = (TH1F*)TrueZRap_ZP2->Clone("ZWRapSysRatio2");
  TH1F *ZWRapSysRatio3 = (TH1F*)TrueZRap_ZP3->Clone("ZWRapSysRatio3");
  TH1F *ZWRapSysRatio4 = (TH1F*)TrueZRap_ZP4->Clone("ZWRapSysRatio4");
  TH1F *ZWRapSysRatio5 = (TH1F*)TrueZRap_ZP5->Clone("ZWRapSysRatio5");
  TH1F *ZWRapSysRatio6 = (TH1F*)TrueZRap_ZP6->Clone("ZWRapSysRatio6");
  ZWRapSysRatio0->Divide(TrueWRap_LQ_P);
  ZWRapSysRatio1->Divide(TrueWRap_LQ_P1);
  ZWRapSysRatio2->Divide(TrueWRap_LQ_P2);
  ZWRapSysRatio3->Divide(TrueWRap_LQ_P3);
  ZWRapSysRatio4->Divide(TrueWRap_LQ_P4);
  ZWRapSysRatio5->Divide(TrueWRap_LQ_P5);
  ZWRapSysRatio6->Divide(TrueWRap_LQ_P6);

  ZWRapSysRatio0->SetMarkerStyle(20);
  ZWRapSysRatio0->SetMarkerColor(kTeal);
  ZWRapSysRatio0->SetLineColor(kTeal);

  ZWRapSysRatio1->SetMarkerStyle(20);
  ZWRapSysRatio1->SetMarkerColor(kBlue);
  ZWRapSysRatio1->SetLineColor(kBlue);

  ZWRapSysRatio2->SetMarkerStyle(22);
  ZWRapSysRatio2->SetMarkerColor(kGreen);
  ZWRapSysRatio2->SetLineColor(kGreen);
  
  ZWRapSysRatio3->SetMarkerStyle(23);
  ZWRapSysRatio3->SetMarkerColor(kOrange);
  ZWRapSysRatio3->SetLineColor(kOrange);

  ZWRapSysRatio4->SetMarkerStyle(22);
  ZWRapSysRatio4->SetMarkerColor(kViolet);
  ZWRapSysRatio4->SetLineColor(kViolet);

  ZWRapSysRatio5->SetMarkerStyle(22);

  ZWRapSysRatio6->SetMarkerStyle(22);
  ZWRapSysRatio6->SetMarkerColor(kGray);
  ZWRapSysRatio6->SetLineColor(kGray);

  THStack *hs42 = new THStack("hs42", "Z to W Rap Pythia Systematic Ratios");

  hs42->Add(ZWRapSysRatio0);
  hs42->Add(ZWRapSysRatio1);
  hs42->Add(ZWRapSysRatio2);
  hs42->Add(ZWRapSysRatio3);
  hs42->Add(ZWRapSysRatio4);
  hs42->Add(ZWRapSysRatio5);
  hs42->Add(ZWRapSysRatio6);
  
  hs42->Draw("NOSTACK HIST");
  hs42->GetXaxis()->SetTitle("Rapidity");

  TLegend *legend42 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend42->AddEntry(ZWRapSysRatio0, "Nominal Z/W", "pl");
  legend42->AddEntry(ZWRapSysRatio1, "Z P1/W P1", "pl");
  legend42->AddEntry(ZWRapSysRatio2, "Z P2/W P2", "pl");
  legend42->AddEntry(ZWRapSysRatio3, "Z P3/W P3", "pl");
  legend42->AddEntry(ZWRapSysRatio4, "Z P4/W P4", "pl");
  legend42->AddEntry(ZWRapSysRatio5, "Z P5/W P5", "pl");
  legend42->AddEntry(ZWRapSysRatio6, "Z P6/W P6", "pl");
  legend42->Draw();

  c42->Print("./plots/ZWRapSystematicRatios.png");

  // Z to W tunes plots:

  TCanvas *c43 = new TCanvas("c43", "Z to W Pt Tune Ratios", 800, 600);
  c43->cd();

  TH1F *ZWPtTuneRatio21 = (TH1F*)TrueZPt_ZP->Clone("ZWPtTuneRatio21");
  TH1F *ZWPtTuneRatio23 = (TH1F*)TrueZPt_ZP23->Clone("ZWPtTuneRatio23");
  TH1F *ZWPtTuneRatio24 = (TH1F*)TrueZPt_ZP24->Clone("ZWPtTuneRatio24");
  TH1F *ZWPtTuneRatio25 = (TH1F*)TrueZPt_ZP25->Clone("ZWPtTuneRatio25");
  TH1F *ZWPtTuneRatio26 = (TH1F*)TrueZPt_ZP26->Clone("ZWPtTuneRatio26");
  TH1F *ZWPtTuneRatio27 = (TH1F*)TrueZPt_ZP27->Clone("ZWPtTuneRatio27");
  TH1F *ZWPtTuneRatio28 = (TH1F*)TrueZPt_ZP28->Clone("ZWPtTuneRatio28");
  TH1F *ZWPtTuneRatio29 = (TH1F*)TrueZPt_ZP29->Clone("ZWPtTuneRatio29");
  TH1F *ZWPtTuneRatio30 = (TH1F*)TrueZPt_ZP30->Clone("ZWPtTuneRatio30");
  TH1F *ZWPtTuneRatio31 = (TH1F*)TrueZPt_ZP31->Clone("ZWPtTuneRatio31");
  TH1F *ZWPtTuneRatio32 = (TH1F*)TrueZPt_ZP32->Clone("ZWPtTuneRatio32");
  ZWPtTuneRatio21->Divide(TrueWPT_LQ_P);
  ZWPtTuneRatio23->Divide(TrueWPT_LQ_P23);
  ZWPtTuneRatio24->Divide(TrueWPT_LQ_P24);
  ZWPtTuneRatio25->Divide(TrueWPT_LQ_P25);
  ZWPtTuneRatio26->Divide(TrueWPT_LQ_P26);
  ZWPtTuneRatio27->Divide(TrueWPT_LQ_P27);
  ZWPtTuneRatio28->Divide(TrueWPT_LQ_P28);
  ZWPtTuneRatio29->Divide(TrueWPT_LQ_P29);
  ZWPtTuneRatio30->Divide(TrueWPT_LQ_P30);
  ZWPtTuneRatio31->Divide(TrueWPT_LQ_P31);
  ZWPtTuneRatio32->Divide(TrueWPT_LQ_P32);

  ZWPtTuneRatio21->SetMarkerStyle(20);
  ZWPtTuneRatio21->SetMarkerColor(kBlue);
  ZWPtTuneRatio21->SetLineColor(kBlue);

  ZWPtTuneRatio23->SetMarkerStyle(22);
  ZWPtTuneRatio23->SetMarkerColor(kGreen);
  ZWPtTuneRatio23->SetLineColor(kGreen);
  
  ZWPtTuneRatio24->SetMarkerStyle(23);
  ZWPtTuneRatio24->SetMarkerColor(kOrange);
  ZWPtTuneRatio24->SetLineColor(kOrange);

  ZWPtTuneRatio25->SetMarkerStyle(22);
  ZWPtTuneRatio25->SetMarkerColor(kViolet);
  ZWPtTuneRatio25->SetLineColor(kViolet);

  ZWPtTuneRatio26->SetMarkerStyle(22);
  ZWPtTuneRatio26->SetMarkerColor(kBlack);
  ZWPtTuneRatio26->SetLineColor(kBlack);

  ZWPtTuneRatio27->SetMarkerStyle(22);
  ZWPtTuneRatio27->SetMarkerColor(kGray);
  ZWPtTuneRatio27->SetLineColor(kGray);

  ZWPtTuneRatio28->SetMarkerStyle(22);
  ZWPtTuneRatio28->SetMarkerColor(kRed);
  ZWPtTuneRatio28->SetLineColor(kRed);

  ZWPtTuneRatio29->SetMarkerStyle(22);
  ZWPtTuneRatio29->SetMarkerColor(kYellow);
  ZWPtTuneRatio29->SetLineColor(kYellow);

  ZWPtTuneRatio30->SetMarkerStyle(22);
  ZWPtTuneRatio30->SetMarkerColor(kMagenta);
  ZWPtTuneRatio30->SetLineColor(kMagenta);

  ZWPtTuneRatio31->SetMarkerStyle(22);
  ZWPtTuneRatio31->SetMarkerColor(kCyan);
  ZWPtTuneRatio31->SetLineColor(kCyan);

  ZWPtTuneRatio32->SetMarkerStyle(22);
  ZWPtTuneRatio32->SetMarkerColor(kAzure);
  ZWPtTuneRatio32->SetLineColor(kAzure);

  THStack *hs43 = new THStack("hs43", "Z to W Pt Pythia Tune Ratios");

  hs43->Add(ZWPtTuneRatio21);
  hs43->Add(ZWPtTuneRatio23);
  hs43->Add(ZWPtTuneRatio24);
  hs43->Add(ZWPtTuneRatio25);
  hs43->Add(ZWPtTuneRatio26);
  hs43->Add(ZWPtTuneRatio27);
  hs43->Add(ZWPtTuneRatio28);
  hs43->Add(ZWPtTuneRatio29);
  hs43->Add(ZWPtTuneRatio30);
  hs43->Add(ZWPtTuneRatio31);
  hs43->Add(ZWPtTuneRatio32);
  
  hs43->Draw("NOSTACK HIST");
  hs43->GetXaxis()->SetTitle("Transverse Momentum [GeV/c]");



  TLegend *legend43 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend43->AddEntry(ZWPtTuneRatio21, "Z P21/W P21", "pl");
  legend43->AddEntry(ZWPtTuneRatio23, "Z P23/W P23", "pl");
  legend43->AddEntry(ZWPtTuneRatio24, "Z P24/W P24", "pl");
  legend43->AddEntry(ZWPtTuneRatio25, "Z P25/W P25", "pl");
  legend43->AddEntry(ZWPtTuneRatio26, "Z P26/W P26", "pl");
  legend43->AddEntry(ZWPtTuneRatio27, "Z P27/W P27", "pl");
  legend43->AddEntry(ZWPtTuneRatio28, "Z P28/W P28", "pl");
  legend43->AddEntry(ZWPtTuneRatio29, "Z P29/W P29", "pl");
  legend43->AddEntry(ZWPtTuneRatio30, "Z P30/W P30", "pl");
  legend43->AddEntry(ZWPtTuneRatio31, "Z P31/W P31", "pl");
  legend43->AddEntry(ZWPtTuneRatio32, "Z P32/W P32", "pl");
  legend43->Draw();

  c43->Print("./plots/ZWPtTuneRatios.png");


  TCanvas *c49 = new TCanvas("c49", "Z to W Rap Tune Ratios", 800, 600);
  c49->cd();

  TH1F *ZWRapTuneRatio21 = (TH1F*)TrueZRap_ZP->Clone("ZWRapTuneRatio21");
  TH1F *ZWRapTuneRatio23 = (TH1F*)TrueZRap_ZP23->Clone("ZWRapTuneRatio23");
  TH1F *ZWRapTuneRatio24 = (TH1F*)TrueZRap_ZP24->Clone("ZWRapTuneRatio24");
  TH1F *ZWRapTuneRatio25 = (TH1F*)TrueZRap_ZP25->Clone("ZWRapTuneRatio25");
  TH1F *ZWRapTuneRatio26 = (TH1F*)TrueZRap_ZP26->Clone("ZWRapTuneRatio26");
  TH1F *ZWRapTuneRatio27 = (TH1F*)TrueZRap_ZP27->Clone("ZWRapTuneRatio27");
  TH1F *ZWRapTuneRatio28 = (TH1F*)TrueZRap_ZP28->Clone("ZWRapTuneRatio28");
  TH1F *ZWRapTuneRatio29 = (TH1F*)TrueZRap_ZP29->Clone("ZWRapTuneRatio29");
  TH1F *ZWRapTuneRatio30 = (TH1F*)TrueZRap_ZP30->Clone("ZWRapTuneRatio30");
  TH1F *ZWRapTuneRatio31 = (TH1F*)TrueZRap_ZP31->Clone("ZWRapTuneRatio31");
  TH1F *ZWRapTuneRatio32 = (TH1F*)TrueZRap_ZP32->Clone("ZWRapTuneRatio32");
  ZWRapTuneRatio21->Scale(1./(ZWRapTuneRatio21->Integral()));
  ZWRapTuneRatio23->Scale(1./(ZWRapTuneRatio23->Integral()));
  ZWRapTuneRatio24->Scale(1./(ZWRapTuneRatio24->Integral()));
  ZWRapTuneRatio25->Scale(1./(ZWRapTuneRatio25->Integral()));
  ZWRapTuneRatio26->Scale(1./(ZWRapTuneRatio26->Integral()));
  ZWRapTuneRatio27->Scale(1./(ZWRapTuneRatio27->Integral()));
  ZWRapTuneRatio28->Scale(1./(ZWRapTuneRatio28->Integral()));
  ZWRapTuneRatio29->Scale(1./(ZWRapTuneRatio29->Integral()));
  ZWRapTuneRatio30->Scale(1./(ZWRapTuneRatio30->Integral()));
  ZWRapTuneRatio31->Scale(1./(ZWRapTuneRatio31->Integral()));
  ZWRapTuneRatio32->Scale(1./(ZWRapTuneRatio32->Integral()));
  TrueWRap_LQ_P->Scale(1./(TrueWRap_LQ_P->Integral()));
  TrueWRap_LQ_P23->Scale(1./(TrueWRap_LQ_P23->Integral()));
  TrueWRap_LQ_P24->Scale(1./(TrueWRap_LQ_P24->Integral()));
  TrueWRap_LQ_P25->Scale(1./(TrueWRap_LQ_P25->Integral()));
  TrueWRap_LQ_P26->Scale(1./(TrueWRap_LQ_P26->Integral()));
  TrueWRap_LQ_P27->Scale(1./(TrueWRap_LQ_P27->Integral()));
  TrueWRap_LQ_P28->Scale(1./(TrueWRap_LQ_P28->Integral()));
  TrueWRap_LQ_P29->Scale(1./(TrueWRap_LQ_P29->Integral()));
  TrueWRap_LQ_P30->Scale(1./(TrueWRap_LQ_P30->Integral()));
  TrueWRap_LQ_P31->Scale(1./(TrueWRap_LQ_P31->Integral()));
  TrueWRap_LQ_P32->Scale(1./(TrueWRap_LQ_P32->Integral()));
  ZWRapTuneRatio21->Divide(TrueWRap_LQ_P);
  ZWRapTuneRatio23->Divide(TrueWRap_LQ_P23);
  ZWRapTuneRatio24->Divide(TrueWRap_LQ_P24);
  ZWRapTuneRatio25->Divide(TrueWRap_LQ_P25);
  ZWRapTuneRatio26->Divide(TrueWRap_LQ_P26);
  ZWRapTuneRatio27->Divide(TrueWRap_LQ_P27);
  ZWRapTuneRatio28->Divide(TrueWRap_LQ_P28);
  ZWRapTuneRatio29->Divide(TrueWRap_LQ_P29);
  ZWRapTuneRatio30->Divide(TrueWRap_LQ_P30);
  ZWRapTuneRatio31->Divide(TrueWRap_LQ_P31);
  ZWRapTuneRatio32->Divide(TrueWRap_LQ_P32);

  ZWRapTuneRatio21->SetMarkerStyle(20);
  ZWRapTuneRatio21->SetMarkerColor(kBlue);
  ZWRapTuneRatio21->SetLineColor(kBlue);

  ZWRapTuneRatio23->SetMarkerStyle(22);
  ZWRapTuneRatio23->SetMarkerColor(kGreen);
  ZWRapTuneRatio23->SetLineColor(kGreen);
  
  ZWRapTuneRatio24->SetMarkerStyle(23);
  ZWRapTuneRatio24->SetMarkerColor(kOrange);
  ZWRapTuneRatio24->SetLineColor(kOrange);

  ZWRapTuneRatio25->SetMarkerStyle(22);
  ZWRapTuneRatio25->SetMarkerColor(kViolet);
  ZWRapTuneRatio25->SetLineColor(kViolet);

  ZWRapTuneRatio26->SetMarkerStyle(22);
  ZWRapTuneRatio26->SetMarkerColor(kBlack);
  ZWRapTuneRatio26->SetLineColor(kBlack);

  ZWRapTuneRatio27->SetMarkerStyle(22);
  ZWRapTuneRatio27->SetMarkerColor(kGray);
  ZWRapTuneRatio27->SetLineColor(kGray);

  ZWRapTuneRatio28->SetMarkerStyle(22);
  ZWRapTuneRatio28->SetMarkerColor(kRed);
  ZWRapTuneRatio28->SetLineColor(kRed);

  ZWRapTuneRatio29->SetMarkerStyle(22);
  ZWRapTuneRatio29->SetMarkerColor(kYellow);
  ZWRapTuneRatio29->SetLineColor(kYellow);

  ZWRapTuneRatio30->SetMarkerStyle(22);
  ZWRapTuneRatio30->SetMarkerColor(kMagenta);
  ZWRapTuneRatio30->SetLineColor(kMagenta);

  ZWRapTuneRatio31->SetMarkerStyle(22);
  ZWRapTuneRatio31->SetMarkerColor(kCyan);
  ZWRapTuneRatio31->SetLineColor(kCyan);

  ZWRapTuneRatio32->SetMarkerStyle(22);
  ZWRapTuneRatio32->SetMarkerColor(kAzure);
  ZWRapTuneRatio32->SetLineColor(kAzure);

  THStack *hs49 = new THStack("hs49", "Z to W Rap Pythia Tune Ratios");

  hs49->Add(ZWRapTuneRatio21);
  hs49->Add(ZWRapTuneRatio23);
  hs49->Add(ZWRapTuneRatio24);
  hs49->Add(ZWRapTuneRatio25);
  hs49->Add(ZWRapTuneRatio26);
  hs49->Add(ZWRapTuneRatio27);
  hs49->Add(ZWRapTuneRatio28);
  hs49->Add(ZWRapTuneRatio29);
  hs49->Add(ZWRapTuneRatio30);
  hs49->Add(ZWRapTuneRatio31);
  hs49->Add(ZWRapTuneRatio32);
  
  hs49->Draw("NOSTACK HIST");
  hs49->GetXaxis()->SetTitle("Rapidity");



  TLegend *legend49 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend49->AddEntry(ZWRapTuneRatio21, "Z P21/W P21", "pl");
  legend49->AddEntry(ZWRapTuneRatio23, "Z P23/W P23", "pl");
  legend49->AddEntry(ZWRapTuneRatio24, "Z P24/W P24", "pl");
  legend49->AddEntry(ZWRapTuneRatio25, "Z P25/W P25", "pl");
  legend49->AddEntry(ZWRapTuneRatio26, "Z P26/W P26", "pl");
  legend49->AddEntry(ZWRapTuneRatio27, "Z P27/W P27", "pl");
  legend49->AddEntry(ZWRapTuneRatio28, "Z P28/W P28", "pl");
  legend49->AddEntry(ZWRapTuneRatio29, "Z P29/W P29", "pl");
  legend49->AddEntry(ZWRapTuneRatio30, "Z P30/W P30", "pl");
  legend49->AddEntry(ZWRapTuneRatio31, "Z P31/W P31", "pl");
  legend49->AddEntry(ZWRapTuneRatio32, "Z P32/W P32", "pl");
  legend49->Draw();

  c49->Print("./plots/ZWRapTuneRatios.png");




  // Z to W ratios with Z mass set to W mass:

  // ZM to W Simulation Ratios

  TCanvas *c44 = new TCanvas("c44", "ZM to W Pt Simulation Ratio Plot", 800, 600);
  c44->cd();
  TH1F *ZMWPtRatioPtoP = (TH1F*)TrueZPt_ZMP->Clone("ZMWPtRatioPtoP");
  TH1F *ZMWPtRatioVtoV = (TH1F*)TrueZPt_ZMV->Clone("ZMWPtRatioVtoV");
  TH1F *ZMWPtRatioDtoD = (TH1F*)TrueZPt_ZMD->Clone("ZMWPtRatioDtoD");
  ZMWPtRatioPtoP->Scale(1./(ZMWPtRatioPtoP->Integral()));
  ZMWPtRatioVtoV->Scale(1./(ZMWPtRatioVtoV->Integral()));
  ZMWPtRatioDtoD->Scale(1./(ZMWPtRatioDtoD->Integral()));
  ZMWPtRatioPtoP->Divide(TrueWPT_LQ_P);
  ZMWPtRatioVtoV->Divide(TrueWPT_LQ_V);
  ZMWPtRatioDtoD->Divide(TrueWPT_LQ_D);

  THStack *hs44 = new THStack("hs44", "Z (W mass) to W Pt Simulation Ratios");

  ZMWPtRatioPtoP->SetMarkerStyle(20);
  ZMWPtRatioPtoP->SetMarkerColor(kRed);
  ZMWPtRatioPtoP->SetLineColor(kRed);
  ZMWPtRatioVtoV->SetMarkerStyle(21);
  ZMWPtRatioVtoV->SetMarkerColor(kGreen);
  ZMWPtRatioVtoV->SetLineColor(kGreen);
  ZMWPtRatioDtoD->SetMarkerStyle(22);
  ZMWPtRatioDtoD->SetMarkerColor(kBlue);
  ZMWPtRatioDtoD->SetLineColor(kBlue);

  hs44->Add(ZMWPtRatioPtoP);
  hs44->Add(ZMWPtRatioDtoD);
  hs44->Add(ZMWPtRatioVtoV);
  
  hs44->Draw("NOSTACK HIST");
  hs44->GetXaxis()->SetTitle("Transverse Momentum [GeV/c]");

  TLegend *legend44 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend44->AddEntry(ZMWPtRatioPtoP, "Pythia", "pl");
  legend44->AddEntry(ZMWPtRatioDtoD, "Dire", "pl");
  legend44->AddEntry(ZMWPtRatioVtoV, "Vincia", "pl");
  legend44->Draw();

  c44->Print("./plots/ZMWPtSimulationRatio.png");



  
  TCanvas *c45 = new TCanvas("c45", "Z (W mass) to W Rap Simulation Ratio Plot", 800, 600);
  c45->cd();
  TH1F *ZMWRapRatioPtoP = (TH1F*)TrueZRap_ZMP->Clone("ZMWRapRatioPtoP");
  TH1F *ZMWRapRatioVtoV = (TH1F*)TrueZRap_ZMV->Clone("ZMWRapRatioVtoV");
  TH1F *ZMWRapRatioDtoD = (TH1F*)TrueZRap_ZMD->Clone("ZMWRapRatioDtoD");
  ZMWRapRatioPtoP->Scale(1./(ZMWRapRatioPtoP->Integral()));
  ZMWRapRatioVtoV->Scale(1./(ZMWRapRatioVtoV->Integral()));
  ZMWRapRatioDtoD->Scale(1./(ZMWRapRatioDtoD->Integral()));
  ZMWRapRatioPtoP->Divide(TrueWRap_LQ_P);
  ZMWRapRatioVtoV->Divide(TrueWRap_LQ_V);
  ZMWRapRatioDtoD->Divide(TrueWRap_LQ_D);

  THStack *hs45 = new THStack("hs45", "Z (W mass) to W Rap Simulation Ratios");

  ZMWRapRatioPtoP->SetMarkerStyle(20);
  ZMWRapRatioPtoP->SetMarkerColor(kRed);
  ZMWRapRatioPtoP->SetLineColor(kRed);
  ZMWRapRatioVtoV->SetMarkerStyle(21);
  ZMWRapRatioVtoV->SetMarkerColor(kGreen);
  ZMWRapRatioVtoV->SetLineColor(kGreen);
  ZMWRapRatioDtoD->SetMarkerStyle(22);
  ZMWRapRatioDtoD->SetMarkerColor(kBlue);
  ZMWRapRatioDtoD->SetLineColor(kBlue);

  hs45->Add(ZMWRapRatioPtoP);
  hs45->Add(ZMWRapRatioDtoD);
  hs45->Add(ZMWRapRatioVtoV);
  
  hs45->Draw("NOSTACK HIST");
  hs45->GetXaxis()->SetTitle("Rapidity");

  TLegend *legend45 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend45->AddEntry(ZWRapRatioPtoP, "Pythia", "pl");
  legend45->AddEntry(ZWRapRatioDtoD, "Dire", "pl");
  legend45->AddEntry(ZWRapRatioVtoV, "Vincia", "pl");
  legend45->Draw();

  c45->Print("./plots/ZMWRapSimulationRatio.png");

  
  // Z (W mass) to W systematics plots:

  TCanvas *c46 = new TCanvas("c46", "Z (W mass) to W Pt Systematics Ratios", 800, 600);
  c46->cd();

  TH1F *ZMWPtSysRatio0 = (TH1F*)TrueZPt_ZMP->Clone("ZMWPtSysRatio0");
  TH1F *ZMWPtSysRatio1 = (TH1F*)TrueZPt_ZMP1->Clone("ZMWPtSysRatio1");
  TH1F *ZMWPtSysRatio2 = (TH1F*)TrueZPt_ZMP2->Clone("ZMWPtSysRatio2");
  TH1F *ZMWPtSysRatio3 = (TH1F*)TrueZPt_ZMP3->Clone("ZMWPtSysRatio3");
  TH1F *ZMWPtSysRatio4 = (TH1F*)TrueZPt_ZMP4->Clone("ZMWPtSysRatio4");
  TH1F *ZMWPtSysRatio5 = (TH1F*)TrueZPt_ZMP5->Clone("ZMWPtSysRatio5");
  TH1F *ZMWPtSysRatio6 = (TH1F*)TrueZPt_ZMP6->Clone("ZMWPtSysRatio6");
  ZMWPtSysRatio0->Scale(1./(ZMWPtSysRatio0->Integral()));
  ZMWPtSysRatio1->Scale(1./(ZMWPtSysRatio1->Integral()));
  ZMWPtSysRatio2->Scale(1./(ZMWPtSysRatio2->Integral()));
  ZMWPtSysRatio3->Scale(1./(ZMWPtSysRatio3->Integral()));
  ZMWPtSysRatio4->Scale(1./(ZMWPtSysRatio4->Integral()));
  ZMWPtSysRatio5->Scale(1./(ZMWPtSysRatio5->Integral()));
  ZMWPtSysRatio6->Scale(1./(ZMWPtSysRatio6->Integral()));
  ZMWPtSysRatio0->Divide(TrueWPT_LQ_P);
  ZMWPtSysRatio1->Divide(TrueWPT_LQ_P1);
  ZMWPtSysRatio2->Divide(TrueWPT_LQ_P2);
  ZMWPtSysRatio3->Divide(TrueWPT_LQ_P3);
  ZMWPtSysRatio4->Divide(TrueWPT_LQ_P4);
  ZMWPtSysRatio5->Divide(TrueWPT_LQ_P5);
  ZMWPtSysRatio6->Divide(TrueWPT_LQ_P6);

  ZMWPtSysRatio0->SetMarkerStyle(20);
  ZMWPtSysRatio0->SetMarkerColor(kTeal);
  ZMWPtSysRatio0->SetLineColor(kTeal);

  ZMWPtSysRatio1->SetMarkerStyle(20);
  ZMWPtSysRatio1->SetMarkerColor(kBlue);
  ZMWPtSysRatio1->SetLineColor(kBlue);

  ZMWPtSysRatio2->SetMarkerStyle(22);
  ZMWPtSysRatio2->SetMarkerColor(kGreen);
  ZMWPtSysRatio2->SetLineColor(kGreen);
  
  ZMWPtSysRatio3->SetMarkerStyle(23);
  ZMWPtSysRatio3->SetMarkerColor(kOrange);
  ZMWPtSysRatio3->SetLineColor(kOrange);

  ZMWPtSysRatio4->SetMarkerStyle(22);
  ZMWPtSysRatio4->SetMarkerColor(kViolet);
  ZMWPtSysRatio4->SetLineColor(kViolet);

  ZMWPtSysRatio5->SetMarkerStyle(22);

  ZMWPtSysRatio6->SetMarkerStyle(22);
  ZMWPtSysRatio6->SetMarkerColor(kGray);
  ZMWPtSysRatio6->SetLineColor(kGray);

  THStack *hs46 = new THStack("hs46", "Z (W mass) to W Pt Pythia Systematic Ratios");

  hs46->Add(ZMWPtSysRatio0);
  hs46->Add(ZMWPtSysRatio1);
  hs46->Add(ZMWPtSysRatio2);
  hs46->Add(ZMWPtSysRatio3);
  hs46->Add(ZMWPtSysRatio4);
  hs46->Add(ZMWPtSysRatio5);
  hs46->Add(ZMWPtSysRatio6);
  
  hs46->Draw("NOSTACK HIST");
  hs46->GetXaxis()->SetTitle("Transverse Momentum [GeV/c]");



  TLegend *legend46 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend46->AddEntry(ZMWPtSysRatio0, "Nominal Z/W", "pl");
  legend46->AddEntry(ZMWPtSysRatio1, "Z P1/W P1", "pl");
  legend46->AddEntry(ZMWPtSysRatio2, "Z P2/W P2", "pl");
  legend46->AddEntry(ZMWPtSysRatio3, "Z P3/W P3", "pl");
  legend46->AddEntry(ZMWPtSysRatio4, "Z P4/W P4", "pl");
  legend46->AddEntry(ZMWPtSysRatio5, "Z P5/W P5", "pl");
  legend46->AddEntry(ZMWPtSysRatio6, "Z P6/W P6", "pl");
  legend46->Draw();

  c46->Print("./plots/ZMWPtSystematicRatios.png");


  TCanvas *c47 = new TCanvas("c47", "Z (W mass) to W Rap Systematics Ratios", 800, 600);
  c47->cd();

  TH1F *ZMWRapSysRatio0 = (TH1F*)TrueZRap_ZMP->Clone("ZMWRapSysRatio0");
  TH1F *ZMWRapSysRatio1 = (TH1F*)TrueZRap_ZMP1->Clone("ZMWRapSysRatio1");
  TH1F *ZMWRapSysRatio2 = (TH1F*)TrueZRap_ZMP2->Clone("ZMWRapSysRatio2");
  TH1F *ZMWRapSysRatio3 = (TH1F*)TrueZRap_ZMP3->Clone("ZMWRapSysRatio3");
  TH1F *ZMWRapSysRatio4 = (TH1F*)TrueZRap_ZMP4->Clone("ZMWRapSysRatio4");
  TH1F *ZMWRapSysRatio5 = (TH1F*)TrueZRap_ZMP5->Clone("ZMWRapSysRatio5");
  TH1F *ZMWRapSysRatio6 = (TH1F*)TrueZRap_ZMP6->Clone("ZMWRapSysRatio6");
  ZMWRapSysRatio0->Scale(1./(ZMWRapSysRatio0->Integral()));
  ZMWRapSysRatio1->Scale(1./(ZMWRapSysRatio1->Integral()));
  ZMWRapSysRatio2->Scale(1./(ZMWRapSysRatio2->Integral()));
  ZMWRapSysRatio3->Scale(1./(ZMWRapSysRatio3->Integral()));
  ZMWRapSysRatio4->Scale(1./(ZMWRapSysRatio4->Integral()));
  ZMWRapSysRatio5->Scale(1./(ZMWRapSysRatio5->Integral()));
  ZMWRapSysRatio6->Scale(1./(ZMWRapSysRatio6->Integral()));
  TrueWRap_LQ_P1->Scale(1./(TrueWRap_LQ_P1->Integral()));
  TrueWRap_LQ_P2->Scale(1./(TrueWRap_LQ_P2->Integral()));
  TrueWRap_LQ_P3->Scale(1./(TrueWRap_LQ_P3->Integral()));
  TrueWRap_LQ_P4->Scale(1./(TrueWRap_LQ_P4->Integral()));
  TrueWRap_LQ_P5->Scale(1./(TrueWRap_LQ_P5->Integral()));
  TrueWRap_LQ_P6->Scale(1./(TrueWRap_LQ_P6->Integral()));
  ZMWRapSysRatio0->Divide(TrueWRap_LQ_P);
  ZMWRapSysRatio1->Divide(TrueWRap_LQ_P1);
  ZMWRapSysRatio2->Divide(TrueWRap_LQ_P2);
  ZMWRapSysRatio3->Divide(TrueWRap_LQ_P3);
  ZMWRapSysRatio4->Divide(TrueWRap_LQ_P4);
  ZMWRapSysRatio5->Divide(TrueWRap_LQ_P5);
  ZMWRapSysRatio6->Divide(TrueWRap_LQ_P6);

  ZMWRapSysRatio0->SetMarkerStyle(20);
  ZMWRapSysRatio0->SetMarkerColor(kTeal);
  ZMWRapSysRatio0->SetLineColor(kTeal);

  ZMWRapSysRatio1->SetMarkerStyle(20);
  ZMWRapSysRatio1->SetMarkerColor(kBlue);
  ZMWRapSysRatio1->SetLineColor(kBlue);

  ZMWRapSysRatio2->SetMarkerStyle(22);
  ZMWRapSysRatio2->SetMarkerColor(kGreen);
  ZMWRapSysRatio2->SetLineColor(kGreen);
  
  ZMWRapSysRatio3->SetMarkerStyle(23);
  ZMWRapSysRatio3->SetMarkerColor(kOrange);
  ZMWRapSysRatio3->SetLineColor(kOrange);

  ZMWRapSysRatio4->SetMarkerStyle(22);
  ZMWRapSysRatio4->SetMarkerColor(kViolet);
  ZMWRapSysRatio4->SetLineColor(kViolet);

  ZMWRapSysRatio5->SetMarkerStyle(22);
  ZMWRapSysRatio4->SetMarkerColor(kRed);
  ZMWRapSysRatio4->SetLineColor(kRed);

  ZMWRapSysRatio6->SetMarkerStyle(22);
  ZMWRapSysRatio6->SetMarkerColor(kGray);
  ZMWRapSysRatio6->SetLineColor(kGray);

  THStack *hs47 = new THStack("hs47", "Z (W mass) to W Rap Pythia Systematic Ratios");

  hs47->Add(ZMWRapSysRatio0);
  hs47->Add(ZMWRapSysRatio1);
  hs47->Add(ZMWRapSysRatio2);
  hs47->Add(ZMWRapSysRatio3);
  hs47->Add(ZMWRapSysRatio4);
  hs47->Add(ZMWRapSysRatio5);
  hs47->Add(ZMWRapSysRatio6);
  
  hs47->Draw("NOSTACK HIST");
  hs47->GetXaxis()->SetTitle("Rapidity");

  TLegend *legend47 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend47->AddEntry(ZMWRapSysRatio0, "Nominal Z/W", "pl");
  legend47->AddEntry(ZMWRapSysRatio1, "Z P1/W P1", "pl");
  legend47->AddEntry(ZMWRapSysRatio2, "Z P2/W P2", "pl");
  legend47->AddEntry(ZMWRapSysRatio3, "Z P3/W P3", "pl");
  legend47->AddEntry(ZMWRapSysRatio4, "Z P4/W P4", "pl");
  legend47->AddEntry(ZMWRapSysRatio5, "Z P5/W P5", "pl");
  legend47->AddEntry(ZMWRapSysRatio6, "Z P6/W P6", "pl");
  legend47->Draw();

  c47->Print("./plots/ZMWRapSystematicRatios.png");

  
  // Z (W mass) to W tunes plots:

  TCanvas *c48 = new TCanvas("c48", "Z (W mass) to W Pt Tune Ratios", 800, 600);
  c48->cd();

  TH1F *ZMWPtTuneRatio21 = (TH1F*)TrueZPt_ZMP->Clone("ZMWPtTuneRatio21");
  TH1F *ZMWPtTuneRatio23 = (TH1F*)TrueZPt_ZMP23->Clone("ZMWPtTuneRatio23");
  TH1F *ZMWPtTuneRatio24 = (TH1F*)TrueZPt_ZMP24->Clone("ZMWPtTuneRatio24");
  TH1F *ZMWPtTuneRatio25 = (TH1F*)TrueZPt_ZMP25->Clone("ZMWPtTuneRatio25");
  TH1F *ZMWPtTuneRatio26 = (TH1F*)TrueZPt_ZMP26->Clone("ZMWPtTuneRatio26");
  TH1F *ZMWPtTuneRatio27 = (TH1F*)TrueZPt_ZMP27->Clone("ZMWPtTuneRatio27");
  TH1F *ZMWPtTuneRatio28 = (TH1F*)TrueZPt_ZMP28->Clone("ZMWPtTuneRatio28");
  TH1F *ZMWPtTuneRatio29 = (TH1F*)TrueZPt_ZMP29->Clone("ZMWPtTuneRatio29");
  TH1F *ZMWPtTuneRatio30 = (TH1F*)TrueZPt_ZMP30->Clone("ZMWPtTuneRatio30");
  TH1F *ZMWPtTuneRatio31 = (TH1F*)TrueZPt_ZMP31->Clone("ZMWPtTuneRatio31");
  TH1F *ZMWPtTuneRatio32 = (TH1F*)TrueZPt_ZMP32->Clone("ZMWPtTuneRatio32");
  ZMWPtTuneRatio21->Scale(1./(ZMWPtTuneRatio21->Integral()));
  ZMWPtTuneRatio23->Scale(1./(ZMWPtTuneRatio23->Integral()));
  ZMWPtTuneRatio24->Scale(1./(ZMWPtTuneRatio24->Integral()));
  ZMWPtTuneRatio25->Scale(1./(ZMWPtTuneRatio25->Integral()));
  ZMWPtTuneRatio26->Scale(1./(ZMWPtTuneRatio26->Integral()));
  ZMWPtTuneRatio27->Scale(1./(ZMWPtTuneRatio27->Integral()));
  ZMWPtTuneRatio28->Scale(1./(ZMWPtTuneRatio28->Integral()));
  ZMWPtTuneRatio29->Scale(1./(ZMWPtTuneRatio29->Integral()));
  ZMWPtTuneRatio30->Scale(1./(ZMWPtTuneRatio30->Integral()));
  ZMWPtTuneRatio31->Scale(1./(ZMWPtTuneRatio31->Integral()));
  ZMWPtTuneRatio32->Scale(1./(ZMWPtTuneRatio32->Integral()));
  ZMWPtTuneRatio21->Divide(TrueWPT_LQ_P);
  ZMWPtTuneRatio23->Divide(TrueWPT_LQ_P23);
  ZMWPtTuneRatio24->Divide(TrueWPT_LQ_P24);
  ZMWPtTuneRatio25->Divide(TrueWPT_LQ_P25);
  ZMWPtTuneRatio26->Divide(TrueWPT_LQ_P26);
  ZMWPtTuneRatio27->Divide(TrueWPT_LQ_P27);
  ZMWPtTuneRatio28->Divide(TrueWPT_LQ_P28);
  ZMWPtTuneRatio29->Divide(TrueWPT_LQ_P29);
  ZMWPtTuneRatio30->Divide(TrueWPT_LQ_P30);
  ZMWPtTuneRatio31->Divide(TrueWPT_LQ_P31);
  ZMWPtTuneRatio32->Divide(TrueWPT_LQ_P32);

  ZMWPtTuneRatio21->SetMarkerStyle(20);
  ZMWPtTuneRatio21->SetMarkerColor(kBlue);
  ZMWPtTuneRatio21->SetLineColor(kBlue);

  ZMWPtTuneRatio23->SetMarkerStyle(22);
  ZMWPtTuneRatio23->SetMarkerColor(kGreen);
  ZMWPtTuneRatio23->SetLineColor(kGreen);
  
  ZMWPtTuneRatio24->SetMarkerStyle(23);
  ZMWPtTuneRatio24->SetMarkerColor(kOrange);
  ZMWPtTuneRatio24->SetLineColor(kOrange);

  ZMWPtTuneRatio25->SetMarkerStyle(22);
  ZMWPtTuneRatio25->SetMarkerColor(kViolet);
  ZMWPtTuneRatio25->SetLineColor(kViolet);

  ZMWPtTuneRatio26->SetMarkerStyle(22);
  ZMWPtTuneRatio26->SetMarkerColor(kBlack);
  ZMWPtTuneRatio26->SetLineColor(kBlack);

  ZMWPtTuneRatio27->SetMarkerStyle(22);
  ZMWPtTuneRatio27->SetMarkerColor(kGray);
  ZMWPtTuneRatio27->SetLineColor(kGray);

  ZMWPtTuneRatio28->SetMarkerStyle(22);
  ZMWPtTuneRatio28->SetMarkerColor(kRed);
  ZMWPtTuneRatio28->SetLineColor(kRed);

  ZMWPtTuneRatio29->SetMarkerStyle(22);
  ZMWPtTuneRatio29->SetMarkerColor(kYellow);
  ZMWPtTuneRatio29->SetLineColor(kYellow);

  ZMWPtTuneRatio30->SetMarkerStyle(22);
  ZMWPtTuneRatio30->SetMarkerColor(kMagenta);
  ZMWPtTuneRatio30->SetLineColor(kMagenta);

  ZMWPtTuneRatio31->SetMarkerStyle(22);
  ZMWPtTuneRatio31->SetMarkerColor(kCyan);
  ZMWPtTuneRatio31->SetLineColor(kCyan);

  ZMWPtTuneRatio32->SetMarkerStyle(22);
  ZMWPtTuneRatio32->SetMarkerColor(kAzure);
  ZMWPtTuneRatio32->SetLineColor(kAzure);

  THStack *hs48 = new THStack("hs48", "Z (W mass) to W Pt Pythia Tune Ratios");

  hs48->Add(ZMWPtTuneRatio21);
  hs48->Add(ZMWPtTuneRatio23);
  hs48->Add(ZMWPtTuneRatio24);
  hs48->Add(ZMWPtTuneRatio25);
  hs48->Add(ZMWPtTuneRatio26);
  hs48->Add(ZMWPtTuneRatio27);
  hs48->Add(ZMWPtTuneRatio28);
  hs48->Add(ZMWPtTuneRatio29);
  hs48->Add(ZMWPtTuneRatio30);
  hs48->Add(ZMWPtTuneRatio31);
  hs48->Add(ZMWPtTuneRatio32);
  
  hs48->Draw("NOSTACK HIST");
  hs48->GetXaxis()->SetTitle("Transverse Momentum [GeV/c]");



  TLegend *legend48 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend48->AddEntry(ZMWPtTuneRatio21, "Z P21/W P21", "pl");
  legend48->AddEntry(ZMWPtTuneRatio23, "Z P23/W P23", "pl");
  legend48->AddEntry(ZMWPtTuneRatio24, "Z P24/W P24", "pl");
  legend48->AddEntry(ZMWPtTuneRatio25, "Z P25/W P25", "pl");
  legend48->AddEntry(ZMWPtTuneRatio26, "Z P26/W P26", "pl");
  legend48->AddEntry(ZMWPtTuneRatio27, "Z P27/W P27", "pl");
  legend48->AddEntry(ZMWPtTuneRatio28, "Z P28/W P28", "pl");
  legend48->AddEntry(ZMWPtTuneRatio29, "Z P29/W P29", "pl");
  legend48->AddEntry(ZMWPtTuneRatio30, "Z P30/W P30", "pl");
  legend48->AddEntry(ZMWPtTuneRatio31, "Z P31/W P31", "pl");
  legend48->AddEntry(ZMWPtTuneRatio32, "Z P32/W P32", "pl");
  legend48->Draw();

  c48->Print("./plots/ZMWPtTuneRatios.png");




  TCanvas *c50 = new TCanvas("c50", "Z (W mass) to W Rap Tune Ratios", 800, 600);
  c50->cd();

  TH1F *ZMWRapTuneRatio21 = (TH1F*)TrueZRap_ZMP->Clone("ZMWRapTuneRatio21");
  TH1F *ZMWRapTuneRatio23 = (TH1F*)TrueZRap_ZMP23->Clone("ZMWRapTuneRatio23");
  TH1F *ZMWRapTuneRatio24 = (TH1F*)TrueZRap_ZMP24->Clone("ZMWRapTuneRatio24");
  TH1F *ZMWRapTuneRatio25 = (TH1F*)TrueZRap_ZMP25->Clone("ZMWRapTuneRatio25");
  TH1F *ZMWRapTuneRatio26 = (TH1F*)TrueZRap_ZMP26->Clone("ZMWRapTuneRatio26");
  TH1F *ZMWRapTuneRatio27 = (TH1F*)TrueZRap_ZMP27->Clone("ZMWRapTuneRatio27");
  TH1F *ZMWRapTuneRatio28 = (TH1F*)TrueZRap_ZMP28->Clone("ZMWRapTuneRatio28");
  TH1F *ZMWRapTuneRatio29 = (TH1F*)TrueZRap_ZMP29->Clone("ZMWRapTuneRatio29");
  TH1F *ZMWRapTuneRatio30 = (TH1F*)TrueZRap_ZMP30->Clone("ZMWRapTuneRatio30");
  TH1F *ZMWRapTuneRatio31 = (TH1F*)TrueZRap_ZMP31->Clone("ZMWRapTuneRatio31");
  TH1F *ZMWRapTuneRatio32 = (TH1F*)TrueZRap_ZMP32->Clone("ZMWRapTuneRatio32");
  ZMWRapTuneRatio21->Scale(1./(ZMWRapTuneRatio21->Integral()));
  ZMWRapTuneRatio23->Scale(1./(ZMWRapTuneRatio23->Integral()));
  ZMWRapTuneRatio24->Scale(1./(ZMWRapTuneRatio24->Integral()));
  ZMWRapTuneRatio25->Scale(1./(ZMWRapTuneRatio25->Integral()));
  ZMWRapTuneRatio26->Scale(1./(ZMWRapTuneRatio26->Integral()));
  ZMWRapTuneRatio27->Scale(1./(ZMWRapTuneRatio27->Integral()));
  ZMWRapTuneRatio28->Scale(1./(ZMWRapTuneRatio28->Integral()));
  ZMWRapTuneRatio29->Scale(1./(ZMWRapTuneRatio29->Integral()));
  ZMWRapTuneRatio30->Scale(1./(ZMWRapTuneRatio30->Integral()));
  ZMWRapTuneRatio31->Scale(1./(ZMWRapTuneRatio31->Integral()));
  ZMWRapTuneRatio32->Scale(1./(ZMWRapTuneRatio32->Integral()));
  ZMWRapTuneRatio21->Divide(TrueWRap_LQ_P);
  ZMWRapTuneRatio23->Divide(TrueWRap_LQ_P23);
  ZMWRapTuneRatio24->Divide(TrueWRap_LQ_P24);
  ZMWRapTuneRatio25->Divide(TrueWRap_LQ_P25);
  ZMWRapTuneRatio26->Divide(TrueWRap_LQ_P26);
  ZMWRapTuneRatio27->Divide(TrueWRap_LQ_P27);
  ZMWRapTuneRatio28->Divide(TrueWRap_LQ_P28);
  ZMWRapTuneRatio29->Divide(TrueWRap_LQ_P29);
  ZMWRapTuneRatio30->Divide(TrueWRap_LQ_P30);
  ZMWRapTuneRatio31->Divide(TrueWRap_LQ_P31);
  ZMWRapTuneRatio32->Divide(TrueWRap_LQ_P32);

  ZMWRapTuneRatio21->SetMarkerStyle(20);
  ZMWRapTuneRatio21->SetMarkerColor(kBlue);
  ZMWRapTuneRatio21->SetLineColor(kBlue);

  ZMWRapTuneRatio23->SetMarkerStyle(22);
  ZMWRapTuneRatio23->SetMarkerColor(kGreen);
  ZMWRapTuneRatio23->SetLineColor(kGreen);
  
  ZMWRapTuneRatio24->SetMarkerStyle(23);
  ZMWRapTuneRatio24->SetMarkerColor(kOrange);
  ZMWRapTuneRatio24->SetLineColor(kOrange);

  ZMWRapTuneRatio25->SetMarkerStyle(22);
  ZMWRapTuneRatio25->SetMarkerColor(kViolet);
  ZMWRapTuneRatio25->SetLineColor(kViolet);

  ZMWRapTuneRatio26->SetMarkerStyle(22);
  ZMWRapTuneRatio26->SetMarkerColor(kBlack);
  ZMWRapTuneRatio26->SetLineColor(kBlack);

  ZMWRapTuneRatio27->SetMarkerStyle(22);
  ZMWRapTuneRatio27->SetMarkerColor(kGray);
  ZMWRapTuneRatio27->SetLineColor(kGray);

  ZMWRapTuneRatio28->SetMarkerStyle(22);
  ZMWRapTuneRatio28->SetMarkerColor(kRed);
  ZMWRapTuneRatio28->SetLineColor(kRed);

  ZMWRapTuneRatio29->SetMarkerStyle(22);
  ZMWRapTuneRatio29->SetMarkerColor(kYellow);
  ZMWRapTuneRatio29->SetLineColor(kYellow);

  ZMWRapTuneRatio30->SetMarkerStyle(22);
  ZMWRapTuneRatio30->SetMarkerColor(kMagenta);
  ZMWRapTuneRatio30->SetLineColor(kMagenta);

  ZMWRapTuneRatio31->SetMarkerStyle(22);
  ZMWRapTuneRatio31->SetMarkerColor(kCyan);
  ZMWRapTuneRatio31->SetLineColor(kCyan);

  ZMWRapTuneRatio32->SetMarkerStyle(22);
  ZMWRapTuneRatio32->SetMarkerColor(kAzure);
  ZMWRapTuneRatio32->SetLineColor(kAzure);

  THStack *hs50 = new THStack("hs50", "Z (W mass) to W Rap Pythia Tune Ratios");

  hs50->Add(ZMWRapTuneRatio21);
  hs50->Add(ZMWRapTuneRatio23);
  hs50->Add(ZMWRapTuneRatio24);
  hs50->Add(ZMWRapTuneRatio25);
  hs50->Add(ZMWRapTuneRatio26);
  hs50->Add(ZMWRapTuneRatio27);
  hs50->Add(ZMWRapTuneRatio28);
  hs50->Add(ZMWRapTuneRatio29);
  hs50->Add(ZMWRapTuneRatio30);
  hs50->Add(ZMWRapTuneRatio31);
  hs50->Add(ZMWRapTuneRatio32);
  
  hs50->Draw("NOSTACK HIST");
  hs50->GetXaxis()->SetTitle("Rapidity");



  TLegend *legend50 = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend50->AddEntry(ZMWRapTuneRatio21, "Z P21/W P21", "pl");
  legend50->AddEntry(ZMWRapTuneRatio23, "Z P23/W P23", "pl");
  legend50->AddEntry(ZMWRapTuneRatio24, "Z P24/W P24", "pl");
  legend50->AddEntry(ZMWRapTuneRatio25, "Z P25/W P25", "pl");
  legend50->AddEntry(ZMWRapTuneRatio26, "Z P26/W P26", "pl");
  legend50->AddEntry(ZMWRapTuneRatio27, "Z P27/W P27", "pl");
  legend50->AddEntry(ZMWRapTuneRatio28, "Z P28/W P28", "pl");
  legend50->AddEntry(ZMWRapTuneRatio29, "Z P29/W P29", "pl");
  legend50->AddEntry(ZMWRapTuneRatio30, "Z P30/W P30", "pl");
  legend50->AddEntry(ZMWRapTuneRatio31, "Z P31/W P31", "pl");
  legend50->AddEntry(ZMWRapTuneRatio32, "Z P32/W P32", "pl");
  legend50->Draw();

  c50->Print("./plots/ZMWRapTuneRatios.png");
  
  */
}
