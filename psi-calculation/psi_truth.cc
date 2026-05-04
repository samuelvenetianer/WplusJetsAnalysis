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

// include binning file
#include "binning.cc"

float hadhadTruthPsi(
                TLorentzVector tau0_ch,  // tau0_matched_vis_p4
                TLorentzVector tau1_ch,  // tau1_matched_vis_p4
                TLorentzVector tau0_neut,   // tau0_matched_vis_neutral_p4
                TLorentzVector tau1_neut    // tau1_matched_vis_neutral_p4
                ){

    TLorentzVector tau0_char_pion;
    TLorentzVector tau1_char_pion;
    TLorentzVector tau0_neut_pion;
    TLorentzVector tau1_neut_pion;

    tau0_char_pion.SetPtEtaPhiE(tau0_ch.Pt(), tau0_ch.Eta(), tau0_ch.Phi(), tau0_ch.E());
    tau1_char_pion.SetPtEtaPhiE(tau1_ch.Pt(), tau1_ch.Eta(), tau1_ch.Phi(), tau1_ch.E());
    tau0_neut_pion.SetPtEtaPhiE(tau0_neut.Pt(), tau0_neut.Eta(), tau0_neut.Phi(), tau0_neut.E());
    tau1_neut_pion.SetPtEtaPhiE(tau1_neut.Pt(), tau1_neut.Eta(), tau1_neut.Phi(), tau1_neut.E());

    const TLorentzVector COM = tau0_char_pion + tau1_char_pion + tau0_neut_pion + tau1_neut_pion;

    const double upsilon0 = tau0_char_pion.E()/(tau0_char_pion+tau0_neut_pion).E();
    const double upsilon1 = tau1_char_pion.E()/(tau1_char_pion+tau1_neut_pion).E();

    // compute_psi_hh_basic

    TLorentzVector beam;
    beam.SetPxPyPzE(0., 0., 6.5e6, 6.5e6);
    
    const TVector3 boostVector = COM.BoostVector();

    tau0_char_pion.Boost((-1.)*boostVector);
    tau1_char_pion.Boost((-1.)*boostVector);
    beam.Boost((-1.)*boostVector); 

    // rotate system and obtain psi
    
    double phi_tau0_char_pion = tau0_char_pion.Phi();
    double theta_tau0_char_pion = tau0_char_pion.Theta();

    tau0_char_pion.RotateZ((-1.0) * phi_tau0_char_pion);
    tau0_char_pion.RotateY((-1.0) * theta_tau0_char_pion);

    tau1_char_pion.RotateZ((-1.0) * phi_tau0_char_pion);
    tau1_char_pion.RotateY((-1.0) * theta_tau0_char_pion);

    beam.RotateZ((-1.0) * phi_tau0_char_pion);
    beam.RotateY((-1.0) * theta_tau0_char_pion);
    beam.RotateZ((-1.0) * tau1_char_pion.Phi());

    tau0_char_pion.RotateZ((-1.0) * tau1_char_pion.Phi());
    tau1_char_pion.RotateZ((-1.0) * tau1_char_pion.Phi());

    double psi = beam.Phi();

    // perform phase shift if necessary
    if ((upsilon0 < 0.5 && upsilon1 > 0.5) || (upsilon0 > 0.5 && upsilon1 < 0.5))
    {
        psi += (M_PI / 2);
    }
    // correct phase to be witin -pi to pi
    while (psi > M_PI) 
    {
        psi -= 2 * M_PI;
    }
    while (psi < -M_PI) 
    {
        psi += 2 * M_PI;
    }
    
    // std::cout << "Truth Level Psi: " << psi << "\n" << std::endl;

    return psi;

}

const TLorentzVector COM_vis(
                TLorentzVector tau0_ch,  // tau0_matched_vis_p4
                TLorentzVector tau1_ch,  // tau1_matched_vis_p4
                TLorentzVector tau0_neut,   // tau0_matched_vis_neutral_p4
                TLorentzVector tau1_neut    // tau1_matched_vis_neutral_p4
                ){

    TLorentzVector tau0_char_pion;
    TLorentzVector tau1_char_pion;
    TLorentzVector tau0_neut_pion;
    TLorentzVector tau1_neut_pion;

    tau0_char_pion.SetPtEtaPhiE(tau0_ch.Pt(), tau0_ch.Eta(), tau0_ch.Phi(), tau0_ch.E());
    tau1_char_pion.SetPtEtaPhiE(tau1_ch.Pt(), tau1_ch.Eta(), tau1_ch.Phi(), tau1_ch.E());
    tau0_neut_pion.SetPtEtaPhiE(tau0_neut.Pt(), tau0_neut.Eta(), tau0_neut.Phi(), tau0_neut.E());
    tau1_neut_pion.SetPtEtaPhiE(tau1_neut.Pt(), tau1_neut.Eta(), tau1_neut.Phi(), tau1_neut.E());

    const TLorentzVector COM = tau0_char_pion + tau1_char_pion + tau0_neut_pion + tau1_neut_pion;
    // COM_pt = COM.Pt();
    // COM_eta = COM.Eta();
    // COM_phi = COM.Phi();
    // COM_E = COM.E();

    return COM;

}

const TLorentzVector COM_real(
                float tau_pt, 
                float tau_eta,
                float tau_phi,
                float tau_E,
                float antitau_pt,
                float antitau_eta,
                float antitau_phi,
                float antitau_E
                ){

    TLorentzVector tau_p4;
    TLorentzVector antitau_p4;

    tau_p4.SetPtEtaPhiE(tau_pt, tau_eta, tau_phi, tau_E);
    antitau_p4.SetPtEtaPhiE(antitau_pt, antitau_eta, antitau_phi, antitau_E);

    const TLorentzVector COM_real = tau_p4 + antitau_p4;

    return COM_real;

}

int main() {

    // Specify input file

    std::cout << "Calling input file..." << std::endl;
    TFile f("/cluster/tufts/beaucheminlab/svenet01/WplusJetsAnalysis/pythia-outputs/2025/040726_test.root"); 
    TTree *input_tree = (TTree*)f.Get("ParticleTree");
    
    std::cout << "Initializing maps..." << std::endl;
    std::map<std::string, TH1*> histsByName;
    std::map<std::string, float> variablesByName;
    std::map<std::string, std::vector<float>*> BUFFER_BY_INPUT;
    // std::map<std::string, float> treeValues;

    std::cout << "Creating empty hist for: " << std::endl;
    for (const std::string& output:ALL_OUTPUTS){                            // & means reference
        std::cout << "----------" << output << std::endl;
        histsByName[output] = new TH1F("","", binningByVariable.at(output).nBins, binningByVariable.at(output).low, binningByVariable.at(output).high);
        histsByName[output] -> GetXaxis()->SetTitle(binningByVariable.at(output).xaxis);
        histsByName[output] -> GetYaxis()->SetTitle("Entries");
    }

    // Initialize multiplicity variables for 1p1n-1p1n channel
    
    Int_t nBoson;
    Int_t nTauChargedPion;     
    Int_t nTauNeutralPion;
    Int_t nTauPhoton;
    Int_t nTauTauNu;
    Int_t nAntiTauChargedPion;     
    Int_t nAntiTauNeutralPion;
    Int_t nAntiTauPhoton;
    Int_t nAntiTauTauAntiNu;

    // Point to address in tree for multiplicity variables
    input_tree->SetBranchAddress("nBoson", &nBoson);
    input_tree->SetBranchAddress("nTauChargedPion", &nTauChargedPion);
    input_tree->SetBranchAddress("nTauNeutralPion", &nTauNeutralPion);
    input_tree->SetBranchAddress("nTauPhoton", &nTauPhoton);
    input_tree->SetBranchAddress("nTauTauNu", &nTauTauNu);
    input_tree->SetBranchAddress("nAntiTauChargedPion", &nAntiTauChargedPion);
    input_tree->SetBranchAddress("nAntiTauNeutralPion", &nAntiTauNeutralPion);
    input_tree->SetBranchAddress("nAntiTauPhoton", &nAntiTauPhoton);
    input_tree->SetBranchAddress("nAntiTauTauAntiNu", &nAntiTauTauAntiNu);

    // initialize vectors to store values for determining max and min
    // std::vector<float> psi_truth_STORE;

    // std::vector<float> COM_pt_STORE;
    // std::vector<float> COM_eta_STORE;
    // std::vector<float> COM_phi_STORE;
    // std::vector<float> COM_E_STORE;

    // std::vector<float> COM_real_pt_STORE;
    // std::vector<float> COM_real_eta_STORE;
    // std::vector<float> COM_real_phi_STORE;
    // std::vector<float> COM_real_E_STORE;

    std::cout << "Setting Branch Address for:" << std::endl;
    for (const std::string& input:ALL_INPUTS){
        BUFFER_BY_INPUT[input] = new std::vector<float>();
        // std::cout << typeid(BUFFER_BY_INPUT[input]).name() << std::endl;
        input_tree->SetBranchAddress(input.c_str(), &BUFFER_BY_INPUT[input]);
        std::cout << "----------" << input.c_str() << std::endl;
    }

    // TRandom3 rand;  
    int nEntries = input_tree->GetEntries(); 
    int forceStop = 100;   

    std::cout << "======Looping through events...======" << std::endl;
    for ( int i = 0 ; i < forceStop ; i++ ) {        
        
        input_tree->GetEvent(i);  
        // std::cout << "Event " << i << std::endl;

        // Fill buckets
        if ((nTauChargedPion == 1) && (nTauPhoton == 2) && (nAntiTauChargedPion == 1) && (nAntiTauPhoton == 2) && (nTauTauNu == 1) && (nAntiTauTauAntiNu == 1)) {
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

            // const TLorentzVector COM_real_p4 = COM_real(
            //                     (*tau_born_pt)[0],
            //                     (*tau_born_eta)[0],
            //                     (*tau_born_phi)[0],
            //                     (*tau_born_E)[0],
            //                     (*antitau_born_pt)[0],
            //                     (*antitau_born_eta)[0],
            //                     (*antitau_born_phi)[0],
            //                     (*antitau_born_E)[0]
            // );

            // variablesByName["Z pT real"] = COM_real_p4.Pt();
            // variablesByName["Z eta real"] = COM_real_p4.Eta();
            // variablesByName["Z phi real"] = COM_real_p4.Phi();
            // variablesByName["Z E real"] = COM_real_p4.E();

            // variablesByName["Z px real"] = COM_real_p4.Px();
            // variablesByName["Z py real"] = COM_real_p4.Py();
            // variablesByName["Z pz real"] = COM_real_p4.Pz();

            // variablesByName["Delta vis real Z px"] = std::abs(COM_vis_p4.Px()-COM_real_p4.Px());
            // variablesByName["Delta vis real Z py"] = std::abs(COM_vis_p4.Py()-COM_real_p4.Py());
            // variablesByName["Delta vis real Z pz"] = std::abs(COM_vis_p4.Pz()-COM_real_p4.Pz());

            // variablesByName["Ratio ZpT vis to ZpT real"]  = COM_vis_p4.Pt()/COM_real_p4.Pt();
            // std::cout << "ratio: " << variablesByName["Ratio ZpT vis to ZpT real"] << std::endl;

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

    // auto min_max_psi = minmax_element(psi_truth_STORE.begin(), psi_truth_STORE.end());
    
    // auto min_max_COM_pt = minmax_element(COM_pt_STORE.begin(), COM_pt_STORE.end());
    // auto min_max_COM_eta = minmax_element(COM_eta_STORE.begin(), COM_eta_STORE.end());
    // auto min_max_COM_phi = minmax_element(COM_phi_STORE.begin(), COM_phi_STORE.end());
    // auto min_max_COM_E = minmax_element(COM_E_STORE.begin(), COM_E_STORE.end());

    // auto min_max_COM_real_pt = minmax_element(COM_real_pt_STORE.begin(), COM_real_pt_STORE.end());
    // auto min_max_COM_real_eta = minmax_element(COM_real_eta_STORE.begin(), COM_real_eta_STORE.end());
    // auto min_max_COM_real_phi = minmax_element(COM_real_phi_STORE.begin(), COM_real_phi_STORE.end());
    // auto min_max_COM_real_E = minmax_element(COM_real_E_STORE.begin(), COM_real_E_STORE.end());

    // std::cout << "Psi (min,max): " << " (" << *min_max_psi.first <<"," << *min_max_psi.second << ")" << std::endl;
    
    // std::cout << "COM pT (min,max): " << " (" << *min_max_COM_pt.first <<"," << *min_max_COM_pt.second << ")" << std::endl;
    // std::cout << "COM eta (min,max): " << " (" << *min_max_COM_eta.first <<"," << *min_max_COM_eta.second << ")" << std::endl;
    // std::cout << "COM phi (min,max): " << " (" << *min_max_COM_phi.first <<"," << *min_max_COM_phi.second << ")" << std::endl;
    // std::cout << "COM E (min,max): " << " (" << *min_max_COM_E.first <<"," << *min_max_COM_E.second << ")" << std::endl;

    // std::cout << "COM real pT (min,max): " << " (" << *min_max_COM_real_pt.first <<"," << *min_max_COM_real_pt.second << ")" << std::endl;
    // std::cout << "COM real eta (min,max): " << " (" << *min_max_COM_real_eta.first <<"," << *min_max_COM_real_eta.second << ")" << std::endl;
    // std::cout << "COM real phi (min,max): " << " (" << *min_max_COM_real_phi.first <<"," << *min_max_COM_real_phi.second << ")" << std::endl;
    // std::cout << "COM real E (min,max): " << " (" << *min_max_COM_real_E.first <<"," << *min_max_COM_real_E.second << ")" << std::endl;

    // DON'T THINK I NEED

    // for (const std::string& input:ALL_INPUTS){
    //     std::cout << input << std::endl;
    //     // BUFFER_BY_INPUT[input] = (*BUFFER_BY_INPUT[input])[0];
    //     treeValues[input] = (*BUFFER_BY_INPUT[input])[0]; // something wrong with this line I think
    //     std::cout << (*BUFFER_BY_INPUT[input])[0] << std::endl;
    // }

    //FAILING FOR ETA. EXISTS IN TREE?
    // std::cout << treeValues["boson_pt"] << "," << treeValues["boson_eta"] << "," << treeValues["boson_phi"] << "," << treeValues["boson_E"] << std::endl;
    // std::cout << treeValues["boson_pt"] << std::endl;

    // if ((*BUFFER_BY_INPUT[input]).size() > 0){
    //     std::cout << (*BUFFER_BY_INPUT[input])[0] << std::endl; // star gives me the vector itself
    // }                   

    return 0;
}

