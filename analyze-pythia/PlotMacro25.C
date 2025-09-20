// FinalPlots.C
// ------------
// Takes histograms from analysis files and analyses them, and creates final plots of the desired histograms

// For plotting code examples, see bjohns PlotMacro25.C in linked tarball at https://github.com/bjohns664297/WplusJetsBaseline

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

  // Get the histograms
  // ==================

    // From Leptoquark events
    // ----------------------
    
  TH1F *NjetTrue_LQ_P  = (TH1F*)filePythia->Get("NumberTrueJet");
  TH1F *LeadJetPt_LQ_P = (TH1F*)filePythia->Get("LeadTrueJet_inc_pt");
  TH1F *DimuMass_LQ_P  = (TH1F*)filePythia->Get("TrueDimuon_M");

  std::cout<<"Got histograms for leptoquark events!";

  // Divide histograms by bin size when not uniform
  // ==============================================
  
  LeadJetPt_LQ_P->Scale(1,"width");
  

  // Create Canvas
  // =============
    
  TCanvas *c1 = new TCanvas("c1","Njets shape plot",800,600);
  TCanvas *c2 = new TCanvas("c2","Pt lead jets shape plot",800,600);
  TCanvas *c3 = new TCanvas("c3","Mll shape plot",800,600);
  TCanvas *c4 = new TCanvas("c4","Njets stack plot",800,600);
  TCanvas *c5 = new TCanvas("c5","Pt lead jets stack plot",800,600);
  TCanvas *c6 = new TCanvas("c6","Mll stack plot",800,600);

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


  TH1F *NjetTrue_LQ_unit  = (TH1F*) NjetTrue_LQ_P->Clone();
  float NjetTrue_LQ_scale = NjetTrue_LQ_unit->Integral();
  NjetTrue_LQ_unit->Scale(1./NjetTrue_LQ_scale);

  TH1F *LeadJetPt_LQ_unit  = (TH1F*) LeadJetPt_LQ_P->Clone();
  float LeadJetPt_LQ_scale = LeadJetPt_LQ_unit->Integral();
  LeadJetPt_LQ_unit->Scale(1./LeadJetPt_LQ_scale);
  
  TH1F *DimuMass_LQ_unit  = (TH1F*) DimuMass_LQ_P->Clone();
  float DimuMass_LQ_scale = DimuMass_LQ_unit->Integral();
  DimuMass_LQ_unit->Scale(1./DimuMass_LQ_scale);

  
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
  LeadJetPt_LQ_P->Scale(0.0025);
  DimuMass_LQ_P->Scale(0.0025);

  
  // Create Stack Plots
  // ==================

  THStack* NjetTrue  = new THStack("NjetTrue", "Njets: signal + backrgound");
  THStack* LeadJetPtTrue  = new THStack("LeadJetPtTrue", "LeadJet Pt: signal + backrgound");
  THStack* DimuMassTrue  = new THStack("DimuMassTrue", "Dimuon Mass: signal + backrgound");
  
  // Make plots
  // ==========


    // Shape Comparisons between various processes
    // -------------------------------------------

       // Note: The color code is: 1=black, 2=red, 3=green
  
  // Njets
  
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
  
  c1->Print("./plots/NjetTrue_unit.png");

  // Lead Jet Pt
  
  c2->cd();

  LeadJetPt_LQ_unit->GetXaxis()->SetTitle("p_{T}^{leadjet}");
  LeadJetPt_LQ_unit->GetYaxis()->SetTitle("d#sigma / dp_{T}^{jet}");
  
  LeadJetPt_LQ_unit->SetMarkerStyle(4);
  LeadJetPt_LQ_unit->SetMarkerColor(3);
  LeadJetPt_LQ_unit->SetLineColor(3);
  LeadJetPt_LQ_unit->SetLineWidth(3);
  LeadJetPt_LQ_unit->Draw("P same");

  
  auto legend_C2 = new TLegend(0.6, 0.60, 0.9, 0.89);
  legend_C2->AddEntry(LeadJetPt_LQ_unit,"Leptoquark","f");
  legend_C2->SetTextSize(0.035);
  legend_C2->Draw();

  c2->Print("./plots/LeadJetPt_unit.png");

  
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

  c5->cd();

  gPad->SetLogy(); 

  LeadJetPt_LQ_P->SetFillColor(3);
  LeadJetPtTrue->Add(LeadJetPt_LQ_P, "hist");

  LeadJetPtTrue->Draw();

  LeadJetPtTrue->GetXaxis()->SetTitle("p_{T}^{leadjet}");
  LeadJetPtTrue->GetYaxis()->SetTitle("d#sigma / dp_{T}^{jet}");


  auto legend_C5 = new TLegend(0.6, 0.60, 0.9, 0.89);
  legend_C5->AddEntry(LeadJetPt_LQ_P,"Leptoquark","f");
  legend_C5->SetTextSize(0.035);
  legend_C5->Draw();

  c5->Print("./plots/LeadJetPt.png");

  // ============================================================================================================= //

}