// Psi Truth calculation for hadhad channel

// standard libraries
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

// link root header files
#include "TROOT.h"
#include "TTree.h"
#include "TFile.h"
#include "TRandom3.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TH1D.h"
#include "TCanvas.h"

// include binning and functions files
#include "binning.cc"
#include "MyFunctions.cc"

// forward declaration of functions from MyFunctions.cc
float hadhadTruthPsi(
                TLorentzVector tau0_ch,  
                TLorentzVector tau1_ch,  
                TLorentzVector tau0_neut,   
                TLorentzVector tau1_neut);

const TLorentzVector COM_vis(
                TLorentzVector tau0_ch,  
                TLorentzVector tau1_ch,  
                TLorentzVector tau0_neut,   
                TLorentzVector tau1_neut);

const TLorentzVector COM_real(
                float tau_pt, 
                float tau_eta,
                float tau_phi,
                float tau_E,
                float antitau_pt,
                float antitau_eta,
                float antitau_phi,
                float antitau_E);

int main() {

    // Specify input file

    std::cout << "Calling input file..." << std::endl;
    TFile f("/cluster/tufts/beaucheminlab/svenet01/WplusJetsAnalysis/pythia-outputs/2025/040726_test.root"); 
    TTree *input_tree = (TTree*)f.Get("ParticleTree");
    
    std::cout << "Initializing maps..." << std::endl;
    std::map<std::string, TH1*> histsByName;
    std::map<std::string, float> variablesByName;
    std::map<std::string, std::vector<float>*> BUFFER_BY_INPUT;
    std::map<std::string, Int_t> BUFFER_BY_INPUT_INT;

    std::cout << "Creating empty hist for: " << std::endl;
    for (const std::string& output:ALL_OUTPUTS){                            // & means reference
        std::cout << "----------" << output << std::endl;
        histsByName[output] = new TH1F("","", binningByVariable.at(output).nBins, binningByVariable.at(output).low, binningByVariable.at(output).high);
        histsByName[output] -> GetXaxis()->SetTitle(binningByVariable.at(output).xaxis);
        histsByName[output] -> GetYaxis()->SetTitle("Entries");
    }

    std::cout << "Setting Branch Address for vectors:" << std::endl;
    for (const std::string& input:ALL_INPUTS){
        BUFFER_BY_INPUT[input] = new std::vector<float>();
        // std::cout << typeid(BUFFER_BY_INPUT[input]).name() << std::endl;
        input_tree->SetBranchAddress(input.c_str(), &BUFFER_BY_INPUT[input]);
        std::cout << "----------" << input.c_str() << std::endl;
    }

    std::cout << "Setting Branch Address for Ints:" << std::endl;
    for (const std::string& input:ALL_INPUTS_INT){
        input_tree->SetBranchAddress(input.c_str(), &BUFFER_BY_INPUT_INT[input]);
        std::cout << "----------" << input.c_str() << std::endl;
    }

    // TRandom3 rand;  
    int nEntries = input_tree->GetEntries(); 
    int forceStop = 100;   

    std::cout << "======Looping through events...======" << std::endl;
    for ( int i = 0 ; i < forceStop ; i++ ) {        
        
        input_tree->GetEvent(i);  

        // Complete calculations
        if (((BUFFER_BY_INPUT_INT["nTauChargedPion"]) == 1) && ((BUFFER_BY_INPUT_INT["nTauPhoton"]) == 2) && ((BUFFER_BY_INPUT_INT["nAntiTauChargedPion"]) == 1) && ((BUFFER_BY_INPUT_INT["nAntiTauPhoton"]) == 2) && ((BUFFER_BY_INPUT_INT["nTauTauNu"]) == 1) && ((BUFFER_BY_INPUT_INT["nAntiTauTauAntiNu"]) == 1)) {
            std::cout << "Event passes 1p1n-1p1n selection!" << std::endl;

            TLorentzVector tau_ch_pion_p4;
            TLorentzVector tau_photon1_p4;
            TLorentzVector tau_photon2_p4;

            TLorentzVector antitau_ch_pion_p4;
            TLorentzVector antitau_photon1_p4;
            TLorentzVector antitau_photon2_p4;

            TLorentzVector tau_neut_pion_p4;
            TLorentzVector antitau_neut_pion_p4;

            tau_ch_pion_p4.SetPtEtaPhiE((*BUFFER_BY_INPUT["tau_charged_pion_pt"])[0], (*BUFFER_BY_INPUT["tau_charged_pion_eta"])[0], (*BUFFER_BY_INPUT["tau_charged_pion_phi"])[0], (*BUFFER_BY_INPUT["tau_charged_pion_E"])[0]);
            tau_photon1_p4.SetPtEtaPhiE((*BUFFER_BY_INPUT["tau_photon_pt"])[0], (*BUFFER_BY_INPUT["tau_photon_eta"])[0], (*BUFFER_BY_INPUT["tau_photon_phi"])[0], (*BUFFER_BY_INPUT["tau_photon_E"])[0]);
            tau_photon2_p4.SetPtEtaPhiE((*BUFFER_BY_INPUT["tau_photon_pt"])[1], (*BUFFER_BY_INPUT["tau_photon_eta"])[1], (*BUFFER_BY_INPUT["tau_photon_phi"])[1], (*BUFFER_BY_INPUT["tau_photon_E"])[1]);
        
            antitau_ch_pion_p4.SetPtEtaPhiE((*BUFFER_BY_INPUT["antitau_charged_pion_pt"])[0], (*BUFFER_BY_INPUT["antitau_charged_pion_eta"])[0], (*BUFFER_BY_INPUT["antitau_charged_pion_phi"])[0], (*BUFFER_BY_INPUT["antitau_charged_pion_E"])[0]);
            antitau_photon1_p4.SetPtEtaPhiE((*BUFFER_BY_INPUT["antitau_photon_pt"])[0], (*BUFFER_BY_INPUT["antitau_photon_eta"])[0], (*BUFFER_BY_INPUT["antitau_photon_phi"])[0], (*BUFFER_BY_INPUT["antitau_photon_E"])[0]);
            antitau_photon2_p4.SetPtEtaPhiE((*BUFFER_BY_INPUT["antitau_photon_pt"])[1], (*BUFFER_BY_INPUT["antitau_photon_eta"])[1], (*BUFFER_BY_INPUT["antitau_photon_phi"])[1], (*BUFFER_BY_INPUT["antitau_photon_E"])[1]);
            
            tau_neut_pion_p4 = tau_photon1_p4 + tau_photon2_p4;
            antitau_neut_pion_p4 = antitau_photon1_p4 + antitau_photon2_p4;

            variablesByName["psi"] = hadhadTruthPsi(
                                            tau_ch_pion_p4,
                                            antitau_ch_pion_p4,
                                            tau_neut_pion_p4,
                                            antitau_neut_pion_p4
                                            );

            std::cout << "psi value: " << variablesByName["psi"] << std::endl;

            TLorentzVector COM_vis_p4 = COM_vis(
                                tau_ch_pion_p4,
                                antitau_ch_pion_p4,
                                tau_neut_pion_p4,
                                antitau_neut_pion_p4

            );

            variablesByName["Z pT vis"] = COM_vis_p4.Pt();
            variablesByName["Z eta vis"] = COM_vis_p4.Eta();
            variablesByName["Z phi vis"] = COM_vis_p4.Phi();
            variablesByName["Z E vis"] = COM_vis_p4.E();
            variablesByName["Z px vis"] = COM_vis_p4.Px();
            variablesByName["Z py vis"] = COM_vis_p4.Py();
            variablesByName["Z pz vis"] = COM_vis_p4.Pz();


            // UPDATE TO BUFFER BY INPUT METHOD

            const TLorentzVector COM_real_p4 = COM_real(
                                (*BUFFER_BY_INPUT["tau_born_pt"])[0],
                                (*BUFFER_BY_INPUT["tau_born_eta"])[0],
                                (*BUFFER_BY_INPUT["tau_born_phi"])[0],
                                (*BUFFER_BY_INPUT["tau_born_E"])[0],
                                (*BUFFER_BY_INPUT["antitau_born_pt"])[0],
                                (*BUFFER_BY_INPUT["antitau_born_eta"])[0],
                                (*BUFFER_BY_INPUT["antitau_born_phi"])[0],
                                (*BUFFER_BY_INPUT["antitau_born_E"])[0]
                                );

            variablesByName["Z pT real"] = COM_real_p4.Pt();
            variablesByName["Z eta real"] = COM_real_p4.Eta();
            variablesByName["Z phi real"] = COM_real_p4.Phi();
            variablesByName["Z E real"] = COM_real_p4.E();

            variablesByName["Z px real"] = COM_real_p4.Px();
            variablesByName["Z py real"] = COM_real_p4.Py();
            variablesByName["Z pz real"] = COM_real_p4.Pz();

            variablesByName["Delta vis real Z px"] = std::abs(COM_vis_p4.Px()-COM_real_p4.Px());
            variablesByName["Delta vis real Z py"] = std::abs(COM_vis_p4.Py()-COM_real_p4.Py());
            variablesByName["Delta vis real Z pz"] = std::abs(COM_vis_p4.Pz()-COM_real_p4.Pz());

            variablesByName["Ratio ZpT vis to ZpT real"]  = COM_vis_p4.Pt()/COM_real_p4.Pt();
            std::cout << "ratio: " << variablesByName["Ratio ZpT vis to ZpT real"] << std::endl;

            // Fill hists for each variable
            
            for (const std::string& output:ALL_OUTPUTS){                            // & means reference
                std::cout << "Filling hist for: " << output << std::endl;
                histsByName[output] -> Fill(variablesByName[output]);
            }
        }
            
    }  

    for (const std::string& output:ALL_OUTPUTS){
        std::cout << "Drawing hist for: " << output << std::endl;
        TCanvas canv;
        histsByName[output] -> Draw();
        canv.Print(binningByVariable.at(output).title);
    }                 

    return 0;
}