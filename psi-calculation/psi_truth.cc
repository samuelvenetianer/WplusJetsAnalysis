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

int main(int argc, char* argv[]) {

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

        // TAUS

    std::vector<float>* tau_born_pt = new std::vector<float>();
    std::vector<float>* tau_born_eta = new std::vector<float>();
    std::vector<float>* tau_born_phi = new std::vector<float>();
    std::vector<float>* tau_born_E = new std::vector<float>();

    std::vector<float>* antitau_born_pt = new std::vector<float>();
    std::vector<float>* antitau_born_eta = new std::vector<float>();
    std::vector<float>* antitau_born_phi = new std::vector<float>();
    std::vector<float>* antitau_born_E = new std::vector<float>();

        // OTHERS

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

        // TAUS

    input_tree->SetBranchAddress("tau_born_pt", &tau_born_pt);
    input_tree->SetBranchAddress("tau_born_eta", &tau_born_eta);
    input_tree->SetBranchAddress("tau_born_phi", &tau_born_phi);
    input_tree->SetBranchAddress("tau_born_E", &tau_born_E);

    input_tree->SetBranchAddress("antitau_born_pt", &antitau_born_pt);
    input_tree->SetBranchAddress("antitau_born_eta", &antitau_born_eta);
    input_tree->SetBranchAddress("antitau_born_phi", &antitau_born_phi);
    input_tree->SetBranchAddress("antitau_born_E", &antitau_born_E);

        // OTHERS

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

    // initialize vectors to store values for determining max and min
    std::vector<float> psi_truth_STORE;

    std::vector<float> COM_pt_STORE;
    std::vector<float> COM_eta_STORE;
    std::vector<float> COM_phi_STORE;
    std::vector<float> COM_E_STORE;

    std::vector<float> COM_real_pt_STORE;
    std::vector<float> COM_real_eta_STORE;
    std::vector<float> COM_real_phi_STORE;
    std::vector<float> COM_real_E_STORE;


    // initialize summary histograms for psi_truth
    TH1* h1 = nullptr;
    h1 = new TH1D("h1", "Truth Psi", 40, -3.14, 3.14);
    h1->SetDirectory(nullptr);
    TFile fout1("psi.root", "recreate");

    // initialize summary histograms for COM_vis
    TH1* h2 = nullptr;
    h2 = new TH1D("h2", "COM pT", 40, 0, 100);
    h2->SetDirectory(nullptr);
    TFile fout2("com_vis_pt.root", "recreate");

    TH1* h3 = nullptr;
    h3 = new TH1D("h3", "COM eta", 40, -4, 4);
    h3->SetDirectory(nullptr);
    TFile fout3("com_vis_eta.root", "recreate");

    TH1* h4 = nullptr;
    h4 = new TH1D("h4", "COM phi", 40, -3.14, 3.14);
    h4->SetDirectory(nullptr);
    TFile fout4("com_vis_phi.root", "recreate");

    TH1* h5 = nullptr;
    h5 = new TH1D("h5", "COM E", 40, 0, 1500);
    h5->SetDirectory(nullptr);
    TFile fout5("com_vis_E.root", "recreate");

    // initialize summary histograms for COM_real
    TH1* h6 = nullptr;
    h6 = new TH1D("h6", "COM pT", 40, 0, 100);
    h6->SetDirectory(nullptr);
    TFile fout6("com_real_pt.root", "recreate");

    TH1* h7 = nullptr;
    h7 = new TH1D("h7", "COM eta", 40, -4, 4);
    h7->SetDirectory(nullptr);
    TFile fout7("com_real_eta.root", "recreate");

    TH1* h8 = nullptr;
    h8 = new TH1D("h8", "COM phi", 40, -3.14, 3.14);
    h8->SetDirectory(nullptr);
    TFile fout8("com_real_phi.root", "recreate");

    TH1* h9 = nullptr;
    h9 = new TH1D("h9", "COM E", 40, 0, 1500);
    h9->SetDirectory(nullptr);
    TFile fout9("com_real_E.root", "recreate");

    // initialize summary histograms for COM_vis for different Z pT binning
    TH1* h10 = nullptr;
    h10 = new TH1D("h10", "COM pT", 40, 0, 100);
    h10->SetDirectory(nullptr);
    TFile fout10("com_vis_0to20cut.root", "recreate");

    TH1* h11 = nullptr;
    h11 = new TH1D("h11", "COM pT", 40, 0, 100);
    h11->SetDirectory(nullptr);
    TFile fout11("com_vis_20to40cut.root", "recreate");

    TH1* h12 = nullptr;
    h12 = new TH1D("h12", "COM pT", 40, 0, 100);
    h12->SetDirectory(nullptr);
    TFile fout12("com_vis_40to60cut.root", "recreate");

    TH1* h13 = nullptr;
    h13 = new TH1D("h13", "COM pT", 40, 0, 100);
    h13->SetDirectory(nullptr);
    TFile fout13("com_vis_60to80cut.root", "recreate");

    TH1* h14 = nullptr;
    h14 = new TH1D("h14", "COM pT", 40, 0, 100);
    h14->SetDirectory(nullptr);
    TFile fout14("com_vis_80to100cut.root", "recreate");

    // Initialize histograms for COM vis and real Px Py Pz

    TH1* h15 = nullptr;
    h15 = new TH1D("h15", "COM vis px", 40, 0, 100);
    h15->SetDirectory(nullptr);
    TFile fout15("com_vis_px.root", "recreate");

    TH1* h16 = nullptr;
    h16 = new TH1D("h16", "COM vis py", 40, 0, 100);
    h16->SetDirectory(nullptr);
    TFile fout16("com_vis_py.root", "recreate");

    TH1* h17 = nullptr;
    h17 = new TH1D("h17", "COM vis pz", 40, 0, 100);
    h17->SetDirectory(nullptr);
    TFile fout17("com_vis_pz.root", "recreate");

    TH1* h18 = nullptr;
    h18 = new TH1D("h18", "COM real px", 40, 0, 100);
    h18->SetDirectory(nullptr);
    TFile fout18("com_real_px.root", "recreate");

    TH1* h19 = nullptr;
    h19 = new TH1D("h19", "COM real py", 40, 0, 100);
    h19->SetDirectory(nullptr);
    TFile fout19("com_real_py.root", "recreate");

    TH1* h20 = nullptr;
    h20 = new TH1D("h20", "COM real pz", 40, 0, 100);
    h20->SetDirectory(nullptr);
    TFile fout20("com_real_pz.root", "recreate");

    // Initialize histograms for delta px py pz
    TH1* h21 = nullptr;
    h21 = new TH1D("h20", "dx COM vis COM real", 40, 0, 100);
    h21->SetDirectory(nullptr);
    TFile fout21("dx_COM.root", "recreate");

    TH1* h22 = nullptr;
    h22 = new TH1D("h22", "dy COM vis COM real", 40, 0, 100);
    h22->SetDirectory(nullptr);
    TFile fout22("dy_COM.root", "recreate");

    TH1* h23 = nullptr;
    h23 = new TH1D("h23", "dz COM vis COM real", 40, 0, 1000);
    h23->SetDirectory(nullptr);
    TFile fout23("dz_COM.root", "recreate");

    // Initialize hist for psi for various delta px/py

    TH1* h24 = nullptr;
    h24 = new TH1D("h24", "psi for small delta p", 20, -3.14, 3.14);
    h24->SetDirectory(nullptr);
    TFile fout24("small_delta_p.root", "recreate");

    TH1* h25 = nullptr;
    h25 = new TH1D("h25", "psi for large delta p", 20, -3.14, 3.14);
    h25->SetDirectory(nullptr);
    TFile fout25("large_delta_p.root", "recreate");


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

            // std::cout << "Z pT: " << (*boson_pt)[0] << std::endl;

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

            psi_truth_STORE.push_back(psi_truth_result);
            h1->Fill(psi_truth_result);

            const TLorentzVector COM_p4 = COM_vis(
                                tau_ch_pion_p4,
                                antitau_ch_pion_p4,
                                tau_neut_pion_p4,
                                antitau_neut_pion_p4

            );

            const TLorentzVector COM_tautau_p4 = COM_real(
                                (*tau_born_pt)[0],
                                (*tau_born_eta)[0],
                                (*tau_born_phi)[0],
                                (*tau_born_E)[0],
                                (*antitau_born_pt)[0],
                                (*antitau_born_eta)[0],
                                (*antitau_born_phi)[0],
                                (*antitau_born_E)[0]
            );

            float COM_pt = COM_p4.Pt();
            float COM_eta = COM_p4.Eta();
            float COM_phi = COM_p4.Phi();
            float COM_E = COM_p4.E();

            COM_pt_STORE.push_back(COM_pt);
            COM_eta_STORE.push_back(COM_eta);
            COM_phi_STORE.push_back(COM_phi);
            COM_E_STORE.push_back(COM_E);

            float COM_real_pt = COM_tautau_p4.Pt();
            float COM_real_eta = COM_tautau_p4.Eta();
            float COM_real_phi = COM_tautau_p4.Phi();
            float COM_real_E = COM_tautau_p4.E();

            COM_real_pt_STORE.push_back(COM_real_pt);
            COM_real_eta_STORE.push_back(COM_real_eta);
            COM_real_phi_STORE.push_back(COM_real_phi);
            COM_real_E_STORE.push_back(COM_real_E);

            h2->Fill(COM_pt);
            h3->Fill(COM_eta);
            h4->Fill(COM_phi);
            h5->Fill(COM_E);

            h6->Fill(COM_real_pt);
            h7->Fill(COM_real_eta);
            h8->Fill(COM_real_phi);
            h9->Fill(COM_real_E);

            if ((*boson_pt)[0] < 20){
                h10->Fill(COM_pt);
            }
            if (((*boson_pt)[0] > 20) && ((*boson_pt)[0] < 40)){
                h11->Fill(COM_pt);
            }
            if (((*boson_pt)[0] > 40) && ((*boson_pt)[0] < 60)){
                h12->Fill(COM_pt);
            }
            if (((*boson_pt)[0] > 60) && ((*boson_pt)[0] < 80)){
                h13->Fill(COM_pt);
            }
            if (((*boson_pt)[0] > 80) && ((*boson_pt)[0] < 100)){
                h14->Fill(COM_pt);
            }
        
            float COM_vis_px = COM_p4.Px();
            float COM_vis_py = COM_p4.Py();
            float COM_vis_pz = COM_p4.Pz();

            float COM_real_px = COM_tautau_p4.Px();
            float COM_real_py = COM_tautau_p4.Py();
            float COM_real_pz = COM_tautau_p4.Pz();

            float dx_COM = std::abs(COM_vis_px-COM_real_px);
            float dy_COM = std::abs(COM_vis_py-COM_real_py);
            float dz_COM = std::abs(COM_vis_pz-COM_real_pz);
            
            h15->Fill(COM_vis_px);
            h16->Fill(COM_vis_py);
            h17->Fill(COM_vis_pz);

            h18->Fill(COM_real_px);
            h19->Fill(COM_real_py);
            h20->Fill(COM_real_pz);

            h21->Fill(dx_COM);
            h22->Fill(dy_COM);
            h23->Fill(dz_COM);

            // std::cout << "dx, dy, dz: " << dx_COM << " , " << dy_COM << " , " << dz_COM << " , " << std::endl;

            if ((dx_COM < 20) && (dy_COM < 20) ){
                h24->Fill(psi_truth_result);
            }

            if ((dx_COM > 20) && (dy_COM > 20)){
                h25->Fill(psi_truth_result);
            }
             

        }
       
    }  

    auto min_max_psi = minmax_element(psi_truth_STORE.begin(), psi_truth_STORE.end());
    
    auto min_max_COM_pt = minmax_element(COM_pt_STORE.begin(), COM_pt_STORE.end());
    auto min_max_COM_eta = minmax_element(COM_eta_STORE.begin(), COM_eta_STORE.end());
    auto min_max_COM_phi = minmax_element(COM_phi_STORE.begin(), COM_phi_STORE.end());
    auto min_max_COM_E = minmax_element(COM_E_STORE.begin(), COM_E_STORE.end());

    auto min_max_COM_real_pt = minmax_element(COM_real_pt_STORE.begin(), COM_real_pt_STORE.end());
    auto min_max_COM_real_eta = minmax_element(COM_real_eta_STORE.begin(), COM_real_eta_STORE.end());
    auto min_max_COM_real_phi = minmax_element(COM_real_phi_STORE.begin(), COM_real_phi_STORE.end());
    auto min_max_COM_real_E = minmax_element(COM_real_E_STORE.begin(), COM_real_E_STORE.end());

    // std::cout << "Psi (min,max): " << " (" << *min_max_psi.first <<"," << *min_max_psi.second << ")" << std::endl;
    
    // std::cout << "COM pT (min,max): " << " (" << *min_max_COM_pt.first <<"," << *min_max_COM_pt.second << ")" << std::endl;
    // std::cout << "COM eta (min,max): " << " (" << *min_max_COM_eta.first <<"," << *min_max_COM_eta.second << ")" << std::endl;
    // std::cout << "COM phi (min,max): " << " (" << *min_max_COM_phi.first <<"," << *min_max_COM_phi.second << ")" << std::endl;
    // std::cout << "COM E (min,max): " << " (" << *min_max_COM_E.first <<"," << *min_max_COM_E.second << ")" << std::endl;

    // std::cout << "COM real pT (min,max): " << " (" << *min_max_COM_real_pt.first <<"," << *min_max_COM_real_pt.second << ")" << std::endl;
    // std::cout << "COM real eta (min,max): " << " (" << *min_max_COM_real_eta.first <<"," << *min_max_COM_real_eta.second << ")" << std::endl;
    // std::cout << "COM real phi (min,max): " << " (" << *min_max_COM_real_phi.first <<"," << *min_max_COM_real_phi.second << ")" << std::endl;
    // std::cout << "COM real E (min,max): " << " (" << *min_max_COM_real_E.first <<"," << *min_max_COM_real_E.second << ")" << std::endl;

    // fout1.cd();
    // h1->GetXaxis()->SetTitle("Psi Truth");
    // h1->GetYaxis()->SetTitle("Entries");
    // h1->Write();
    // fout1.Close();   

    // fout2.cd();
    // h2->GetXaxis()->SetTitle("COM pT");
    // h2->GetYaxis()->SetTitle("Entries");
    // h2->Write();
    // fout2.Close();    

    // fout3.cd();
    // h3->GetXaxis()->SetTitle("COM eta");
    // h3->GetYaxis()->SetTitle("Entries");
    // h3->Write();
    // fout3.Close();    

    // fout4.cd();
    // h4->GetXaxis()->SetTitle("COM phi");
    // h4->GetYaxis()->SetTitle("Entries");
    // h4->Write();
    // fout4.Close();    

    // fout5.cd();
    // h5->GetXaxis()->SetTitle("COM E");
    // h5->GetYaxis()->SetTitle("Entries");
    // h5->Write();
    // fout5.Close(); 

    // fout6.cd();
    // h6->GetXaxis()->SetTitle("COM real pT");
    // h6->GetYaxis()->SetTitle("Entries");
    // h6->Write();
    // fout6.Close();    

    // fout7.cd();
    // h7->GetXaxis()->SetTitle("COM real eta");
    // h7->GetYaxis()->SetTitle("Entries");
    // h7->Write();
    // fout7.Close();    

    // fout8.cd();
    // h8->GetXaxis()->SetTitle("COM real phi");
    // h8->GetYaxis()->SetTitle("Entries");
    // h8->Write();
    // fout8.Close();    

    // fout9.cd();
    // h9->GetXaxis()->SetTitle("COM real E");
    // h9->GetYaxis()->SetTitle("Entries");
    // h9->Write();
    // fout9.Close();    

    // fout10.cd();
    // h10->GetXaxis()->SetTitle("COM vis for Z pT < 20 GeV");
    // h10->GetYaxis()->SetTitle("Entries");
    // h10->Write();
    // fout10.Close();   

    // fout11.cd();
    // h11->GetXaxis()->SetTitle("COM vis for Z pT 20-40 GeV");
    // h11->GetYaxis()->SetTitle("Entries");
    // h11->Write();
    // fout11.Close();     

    // fout12.cd();
    // h12->GetXaxis()->SetTitle("COM vis for Z pT 20-40 GeV");
    // h12->GetYaxis()->SetTitle("Entries");
    // h12->Write();
    // fout12.Close(); 

    // fout13.cd();
    // h13->GetXaxis()->SetTitle("COM vis for Z pT 20-40 GeV");
    // h13->GetYaxis()->SetTitle("Entries");
    // h13->Write();
    // fout13.Close(); 

    // fout14.cd();
    // h14->GetXaxis()->SetTitle("COM vis for Z pT 20-40 GeV");
    // h14->GetYaxis()->SetTitle("Entries");
    // h14->Write();
    // fout14.Close();      

    // fout15.cd();
    // h15->GetXaxis()->SetTitle("COM vis px");
    // h15->GetYaxis()->SetTitle("Entries");
    // h15->Write();
    // fout15.Close();   

    // fout16.cd();
    // h16->GetXaxis()->SetTitle("COM vis py");
    // h16->GetYaxis()->SetTitle("Entries");
    // h16->Write();
    // fout16.Close();

    // fout17.cd();
    // h17->GetXaxis()->SetTitle("COM vis py");
    // h17->GetYaxis()->SetTitle("Entries");
    // h17->Write();
    // fout17.Close();

    // fout18.cd();
    // h18->GetXaxis()->SetTitle("COM real px");
    // h18->GetYaxis()->SetTitle("Entries");
    // h18->Write();
    // fout18.Close();

    // fout19.cd();
    // h19->GetXaxis()->SetTitle("COM vis py");
    // h19->GetYaxis()->SetTitle("Entries");
    // h19->Write();
    // fout19.Close();

    // fout20.cd();
    // h20->GetXaxis()->SetTitle("COM vis pz");
    // h20->GetYaxis()->SetTitle("Entries");
    // h20->Write();
    // fout20.Close();

    // fout21.cd();
    // h21->GetXaxis()->SetTitle("dx COM");
    // h21->GetYaxis()->SetTitle("Entries");
    // h21->Write();
    // fout21.Close();

    // fout22.cd();
    // h22->GetXaxis()->SetTitle("dy COM");
    // h22->GetYaxis()->SetTitle("Entries");
    // h22->Write();
    // fout22.Close();

    // fout23.cd();
    // h23->GetXaxis()->SetTitle("dz COM");
    // h23->GetYaxis()->SetTitle("Entries");
    // h23->Write();
    // fout23.Close();

    fout24.cd();
    h24->GetXaxis()->SetTitle("Small delta p");
    h24->GetYaxis()->SetTitle("Entries");
    h24->Write();
    fout24.Close();

    fout25.cd();
    h25->GetXaxis()->SetTitle("Large delta p");
    h25->GetYaxis()->SetTitle("Entries");
    h25->Write();
    fout25.Close();

    return 0;
}

