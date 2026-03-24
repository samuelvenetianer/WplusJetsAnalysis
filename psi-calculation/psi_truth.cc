// Psi Truth calculation for hadhad channel

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

float hadhadTruthPsi(
                TLorentzVector tau0_ch,  // tau0_matched_vis_p4
                TLorentzVector tau1_ch,  // tau1_matched_vis_p4
                TLorentzVector tau0_neut,   // tau0_matched_vis_neutral_p4
                TLorentzVector tau1_neut    // tau1_matched_vis_neutral_p4
                ){

    // implement TRUTH psi calculation

    // std::cout << "Calculating truth level psi..." << std::endl;

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

int main() {

    // Specify input file

    TFile f("/cluster/tufts/beaucheminlab/svenet01/WplusJetsAnalysis/pythia-outputs/2025/032326_cut20GeV.root"); 
    TTree *input_tree = (TTree*)f.Get("ParticleTree");

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

    // create pointers and initialize empty vectors

    std::vector<float>* boson_pt = new std::vector<float>();

    std::vector<float>* tau_charged_pion_pt = new std::vector<float>();
    std::vector<float>* tau_charged_pion_eta = new std::vector<float>();
    std::vector<float>* tau_charged_pion_phi = new std::vector<float>();
    std::vector<float>* tau_charged_pion_E = new std::vector<float>();

    std::vector<float>* tau_neutral_pion_pt = new std::vector<float>();
    std::vector<float>* tau_neutral_pion_eta = new std::vector<float>();
    std::vector<float>* tau_neutral_pion_phi = new std::vector<float>();
    std::vector<float>* tau_neutral_pion_E = new std::vector<float>();

    std::vector<float>* tau_photon_pt = new std::vector<float>();
    std::vector<float>* tau_photon_phi = new std::vector<float>();
    std::vector<float>* tau_photon_eta = new std::vector<float>();
    std::vector<float>* tau_photon_E = new std::vector<float>();
    
    std::vector<float>* antitau_charged_pion_pt = new std::vector<float>();
    std::vector<float>* antitau_charged_pion_eta = new std::vector<float>();
    std::vector<float>* antitau_charged_pion_phi = new std::vector<float>();
    std::vector<float>* antitau_charged_pion_E = new std::vector<float>();

    std::vector<float>* antitau_neutral_pion_pt = new std::vector<float>();
    std::vector<float>* antitau_neutral_pion_eta = new std::vector<float>();
    std::vector<float>* antitau_neutral_pion_phi = new std::vector<float>();
    std::vector<float>* antitau_neutral_pion_E = new std::vector<float>();

    std::vector<float>* antitau_photon_pt = new std::vector<float>();
    std::vector<float>* antitau_photon_phi = new std::vector<float>();
    std::vector<float>* antitau_photon_eta = new std::vector<float>();
    std::vector<float>* antitau_photon_E = new std::vector<float>();

    // Point to address in tree (for number of particles)
    input_tree->SetBranchAddress("nBoson", &nBoson);
    input_tree->SetBranchAddress("nTauChargedPion", &nTauChargedPion);
    input_tree->SetBranchAddress("nTauNeutralPion", &nTauNeutralPion);
    input_tree->SetBranchAddress("nTauPhoton", &nTauPhoton);
    input_tree->SetBranchAddress("nTauTauNu", &nTauTauNu);
    input_tree->SetBranchAddress("nAntiTauChargedPion", &nAntiTauChargedPion);
    input_tree->SetBranchAddress("nAntiTauNeutralPion", &nAntiTauNeutralPion);
    input_tree->SetBranchAddress("nAntiTauPhoton", &nAntiTauPhoton);
    input_tree->SetBranchAddress("nAntiTauTauAntiNu", &nAntiTauTauAntiNu);
    
    // Point to address in tree (for pT, eta, phi, E)

    input_tree->SetBranchAddress("boson_pt", &boson_pt);

    input_tree->SetBranchAddress("tau_charged_pion_pt", &tau_charged_pion_pt);
    input_tree->SetBranchAddress("tau_charged_pion_eta", &tau_charged_pion_eta);
    input_tree->SetBranchAddress("tau_charged_pion_phi", &tau_charged_pion_phi);
    input_tree->SetBranchAddress("tau_charged_pion_E", &tau_charged_pion_E);

    input_tree->SetBranchAddress("tau_neutral_pion_pt", &tau_neutral_pion_pt);
    input_tree->SetBranchAddress("tau_neutral_pion_eta", &tau_neutral_pion_eta);
    input_tree->SetBranchAddress("tau_neutral_pion_phi", &tau_neutral_pion_phi);
    input_tree->SetBranchAddress("tau_neutral_pion_E", &tau_neutral_pion_E);

    input_tree->SetBranchAddress("tau_photon_pt", &tau_photon_pt);
    input_tree->SetBranchAddress("tau_photon_eta", &tau_photon_eta);
    input_tree->SetBranchAddress("tau_photon_phi", &tau_photon_phi);
    input_tree->SetBranchAddress("tau_photon_E", &tau_photon_E);

    input_tree->SetBranchAddress("antitau_charged_pion_pt", &antitau_charged_pion_pt);
    input_tree->SetBranchAddress("antitau_charged_pion_eta", &antitau_charged_pion_eta);
    input_tree->SetBranchAddress("antitau_charged_pion_phi", &antitau_charged_pion_phi);
    input_tree->SetBranchAddress("antitau_charged_pion_E", &antitau_charged_pion_E);

    input_tree->SetBranchAddress("antitau_neutral_pion_pt", &antitau_neutral_pion_pt);
    input_tree->SetBranchAddress("antitau_neutral_pion_eta", &antitau_neutral_pion_eta);
    input_tree->SetBranchAddress("antitau_neutral_pion_phi", &antitau_neutral_pion_phi);
    input_tree->SetBranchAddress("antitau_neutral_pion_E", &antitau_neutral_pion_E);

    input_tree->SetBranchAddress("antitau_photon_pt", &antitau_photon_pt);
    input_tree->SetBranchAddress("antitau_photon_eta", &antitau_photon_eta);
    input_tree->SetBranchAddress("antitau_photon_phi", &antitau_photon_phi);
    input_tree->SetBranchAddress("antitau_photon_E", &antitau_photon_E);

    // initialize vectors to store the pT of the difference for plotting
    std::vector<float> psi_truth_STORE;

    // initialize summary histograms for psi_truth
    TH1* h1 = nullptr;
    h1 = new TH1D("h1", "Truth Psi", 40, -3.14, 3.14);
    h1->SetDirectory(nullptr);
    TFile fout1("truth_psi.root", "recreate");

    // TRandom3 rand;  
    int nEntries = input_tree->GetEntries();    

    for ( int i = 0 ; i < nEntries ; i++ ) {        
        
        input_tree->GetEvent(i);                    

        // std::cout << "================Event " << i << " ================" << std::endl;

        // begin psi calculation if required number of charged and neutral pions exist for 1p1n-1p1n channel

        if ((nTauChargedPion == 1) && (nTauPhoton == 2) && (nAntiTauChargedPion == 1) && (nAntiTauPhoton == 2) && (nTauTauNu == 1) && (nAntiTauTauAntiNu == 1)) {
            // std::cout << "Event " << i << " passes 1p1n-1p1n selection!" << std::endl;
            // std::cout << "Number of (TauChargedPion, nTauPhoton, AntiTauChargedPion, nAntiTauPhoton) = (" << nTauChargedPion << ", " << nTauPhoton << ", " << nAntiTauChargedPion << ", " << nAntiTauPhoton << ")" << std::endl;

            // define TLorentz vectors

            TLorentzVector tau_ch_pion_p4; 
            TLorentzVector tau_photon1_p4;
            TLorentzVector tau_photon2_p4;
            TLorentzVector tau_neut_pion_p4;
            TLorentzVector antitau_ch_pion_p4;
            TLorentzVector antitau_photon1_p4;
            TLorentzVector antitau_photon2_p4;
            TLorentzVector antitau_neut_pion_p4;

            tau_ch_pion_p4.SetPtEtaPhiE((*tau_charged_pion_pt)[0], (*tau_charged_pion_eta)[0], (*tau_charged_pion_phi)[0], (*tau_charged_pion_E)[0]);
            tau_photon1_p4.SetPtEtaPhiE((*tau_photon_pt)[0], (*tau_photon_eta)[0], (*tau_photon_phi)[0], (*tau_photon_E)[0]);
            tau_photon2_p4.SetPtEtaPhiE((*tau_photon_pt)[1], (*tau_photon_eta)[1], (*tau_photon_phi)[1], (*tau_photon_E)[1]);

            antitau_ch_pion_p4.SetPtEtaPhiE((*antitau_charged_pion_pt)[0], (*antitau_charged_pion_eta)[0], (*antitau_charged_pion_phi)[0], (*antitau_charged_pion_E)[0]);
            antitau_photon1_p4.SetPtEtaPhiE((*antitau_photon_pt)[0], (*antitau_photon_eta)[0], (*antitau_photon_phi)[0], (*antitau_photon_E)[0]);
            antitau_photon2_p4.SetPtEtaPhiE((*antitau_photon_pt)[1], (*antitau_photon_eta)[1], (*antitau_photon_phi)[1], (*antitau_photon_E)[1]);

            tau_neut_pion_p4 = tau_photon1_p4 + tau_photon2_p4;
            antitau_neut_pion_p4 = antitau_photon1_p4 + antitau_photon2_p4;

            float psi_truth_result = hadhadTruthPsi(
                                            tau_ch_pion_p4,
                                            antitau_ch_pion_p4,
                                            tau_neut_pion_p4,
                                            antitau_neut_pion_p4
                                            );

            // std::cout << "Truth Level Psi: " << psi_truth_result << "\n" << std::endl;
            psi_truth_STORE.push_back(psi_truth_result);
            h1->Fill(psi_truth_result);

            // if ((*boson_pt)[0] < 20){
            //     std::cout << "Boson pT: " << (*boson_pt)[0] << std::endl;
            //     psi_truth_STORE.push_back(psi_truth_result);
            //     h1->Fill(psi_truth_result);
            // }
            

        }
        // else{
        //     std::cout<< "Nothing passed :(" << std::endl;
        // }
    }  

    auto min_max_psi = minmax_element(psi_truth_STORE.begin(), psi_truth_STORE.end());

    std::cout << "Psi min: " << *min_max_psi.first << std::endl;
    std::cout << "Psi max: " << *min_max_psi.second << std::endl;

    fout1.cd();
    h1->GetXaxis()->SetTitle("Psi Truth");
    h1->GetYaxis()->SetTitle("Entries");
    h1->Write();
    fout1.Close();      

    return 0;
}

