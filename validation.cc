// Use this script to validate addition of tau children to tau decays

// add makefile
// update root path

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include <bits/stdc++.h>

// update path to point to whatever was installed in the setup step
#include "TROOT.h"
#include "TTree.h"
#include "TFile.h"
#include "TRandom3.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TH1D.h"
#include "TGaxis.h"

int main() {
    TFile f("/cluster/tufts/beaucheminlab/svenet01/WplusJetsAnalysis/pythia-outputs/2025/onemil_1p1n_isr_fsr_062526.root"); // read input file
    TTree *input_tree = (TTree*)f.Get("ParticleTree");        // "Get" the ParticleTree tree from the file and assign it to local variable "input_tree" - there are two of these. Is this an issue when calling?

    // initialization of variables counting number of particle of interest

    Int_t nBoson;

    // tau & decay products                                         
    Int_t nTauBorn;
    Int_t nTauChargedPion;     
    Int_t nTauNeutralPion;
    Int_t nTauMuon;
    Int_t nTauMuonAntiNu;
    Int_t nTauMuonNu;
    Int_t nTauElectron;
    Int_t nTauElectronAntiNu;
    Int_t nTauElectronNu;
    Int_t nTauPhoton;
    Int_t nTauTauNu;
    Int_t nTauTauAntiNu;
    Int_t nTauKaonL;
    Int_t nTauKaonS;
    Int_t nTauKaon;

    //antitau & decay products
    Int_t nAntiTauBorn;
    Int_t nAntiTauChargedPion;     
    Int_t nAntiTauNeutralPion;
    Int_t nAntiTauMuon;
    Int_t nAntiTauMuonAntiNu;
    Int_t nAntiTauMuonNu;
    Int_t nAntiTauElectron;
    Int_t nAntiTauElectronAntiNu;
    Int_t nAntiTauElectronNu;
    Int_t nAntiTauPhoton;
    Int_t nAntiTauTauNu;
    Int_t nAntiTauTauAntiNu;
    Int_t nAntiTauKaonL;
    Int_t nAntiTauKaonS;
    Int_t nAntiTauKaon;

    // create pointer and initialize empty vectors

    std::vector<float>* boson_pt = new std::vector<float>();
    std::vector<float>* boson_eta = new std::vector<float>();
    std::vector<float>* boson_phi= new std::vector<float>();
    std::vector<float>* boson_E = new std::vector<float>();

    // tau & decay products   
    std::vector<float>* tau_born_pt = new std::vector<float>();
    std::vector<float>* tau_born_eta = new std::vector<float>();
    std::vector<float>* tau_born_phi = new std::vector<float>();
    std::vector<float>* tau_born_E = new std::vector<float>();
    std::vector<float>* tau_born_charge = new std::vector<float>();
    
    std::vector<float>* tau_charged_pion_pt = new std::vector<float>();
    std::vector<float>* tau_charged_pion_eta = new std::vector<float>();
    std::vector<float>* tau_charged_pion_phi = new std::vector<float>();
    std::vector<float>* tau_charged_pion_E = new std::vector<float>();

    std::vector<float>* tau_neutral_pion_pt = new std::vector<float>();
    std::vector<float>* tau_neutral_pion_eta = new std::vector<float>();
    std::vector<float>* tau_neutral_pion_phi = new std::vector<float>();
    std::vector<float>* tau_neutral_pion_E = new std::vector<float>();

    std::vector<float>* tau_muon_pt = new std::vector<float>();
    std::vector<float>* tau_muon_eta = new std::vector<float>();
    std::vector<float>* tau_muon_phi = new std::vector<float>();
    std::vector<float>* tau_muon_E = new std::vector<float>();

    std::vector<float>* tau_muonantinu_pt = new std::vector<float>();
    std::vector<float>* tau_muonantinu_eta = new std::vector<float>();
    std::vector<float>* tau_muonantinu_phi = new std::vector<float>();
    std::vector<float>* tau_muonantinu_E = new std::vector<float>();

    std::vector<float>* tau_muonnu_pt = new std::vector<float>();
    std::vector<float>* tau_muonnu_eta = new std::vector<float>();
    std::vector<float>* tau_muonnu_phi = new std::vector<float>();
    std::vector<float>* tau_muonnu_E = new std::vector<float>();

    std::vector<float>* tau_electron_pt = new std::vector<float>();
    std::vector<float>* tau_electron_eta = new std::vector<float>();
    std::vector<float>* tau_electron_phi = new std::vector<float>();
    std::vector<float>* tau_electron_E = new std::vector<float>();

    std::vector<float>* tau_electronantinu_pt = new std::vector<float>();
    std::vector<float>* tau_electronantinu_eta = new std::vector<float>();
    std::vector<float>* tau_electronantinu_phi = new std::vector<float>();
    std::vector<float>* tau_electronantinu_E = new std::vector<float>();
    
    std::vector<float>* tau_electronnu_pt = new std::vector<float>();
    std::vector<float>* tau_electronnu_eta = new std::vector<float>();
    std::vector<float>* tau_electronnu_phi = new std::vector<float>();
    std::vector<float>* tau_electronnu_E = new std::vector<float>();

    std::vector<float>* tau_photon_pt = new std::vector<float>();
    std::vector<float>* tau_photon_phi = new std::vector<float>();
    std::vector<float>* tau_photon_eta = new std::vector<float>();
    std::vector<float>* tau_photon_E = new std::vector<float>();

    std::vector<float>* tau_taunu_pt = new std::vector<float>();
    std::vector<float>* tau_taunu_eta = new std::vector<float>();
    std::vector<float>* tau_taunu_phi = new std::vector<float>();
    std::vector<float>* tau_taunu_E = new std::vector<float>();

    std::vector<float>* tau_tauantinu_pt = new std::vector<float>();
    std::vector<float>* tau_tauantinu_eta = new std::vector<float>();
    std::vector<float>* tau_tauantinu_phi = new std::vector<float>();
    std::vector<float>* tau_tauantinu_E = new std::vector<float>();

    std::vector<float>* tau_kaonL_pt = new std::vector<float>();
    std::vector<float>* tau_kaonL_eta = new std::vector<float>();
    std::vector<float>* tau_kaonL_phi = new std::vector<float>();
    std::vector<float>* tau_kaonL_E = new std::vector<float>();

    std::vector<float>* tau_kaonS_pt = new std::vector<float>();
    std::vector<float>* tau_kaonS_eta = new std::vector<float>();
    std::vector<float>* tau_kaonS_phi = new std::vector<float>();
    std::vector<float>* tau_kaonS_E = new std::vector<float>();

    std::vector<float>* tau_kaon_pt = new std::vector<float>();
    std::vector<float>* tau_kaon_eta = new std::vector<float>();
    std::vector<float>* tau_kaon_phi = new std::vector<float>();
    std::vector<float>* tau_kaon_E = new std::vector<float>();

    // antitau & decay products   
    std::vector<float>* antitau_born_pt = new std::vector<float>();
    std::vector<float>* antitau_born_eta = new std::vector<float>();
    std::vector<float>* antitau_born_phi = new std::vector<float>();
    std::vector<float>* antitau_born_E = new std::vector<float>();
    std::vector<float>* antitau_born_charge = new std::vector<float>();
    
    std::vector<float>* antitau_charged_pion_pt = new std::vector<float>();
    std::vector<float>* antitau_charged_pion_eta = new std::vector<float>();
    std::vector<float>* antitau_charged_pion_phi = new std::vector<float>();
    std::vector<float>* antitau_charged_pion_E = new std::vector<float>();

    std::vector<float>* antitau_neutral_pion_pt = new std::vector<float>();
    std::vector<float>* antitau_neutral_pion_eta = new std::vector<float>();
    std::vector<float>* antitau_neutral_pion_phi = new std::vector<float>();
    std::vector<float>* antitau_neutral_pion_E = new std::vector<float>();

    std::vector<float>* antitau_muon_pt = new std::vector<float>();
    std::vector<float>* antitau_muon_eta = new std::vector<float>();
    std::vector<float>* antitau_muon_phi = new std::vector<float>();
    std::vector<float>* antitau_muon_E = new std::vector<float>();

    std::vector<float>* antitau_muonantinu_pt = new std::vector<float>();
    std::vector<float>* antitau_muonantinu_eta = new std::vector<float>();
    std::vector<float>* antitau_muonantinu_phi = new std::vector<float>();
    std::vector<float>* antitau_muonantinu_E = new std::vector<float>();

    std::vector<float>* antitau_muonnu_pt = new std::vector<float>();
    std::vector<float>* antitau_muonnu_eta = new std::vector<float>();
    std::vector<float>* antitau_muonnu_phi = new std::vector<float>();
    std::vector<float>* antitau_muonnu_E = new std::vector<float>();

    std::vector<float>* antitau_electron_pt = new std::vector<float>();
    std::vector<float>* antitau_electron_eta = new std::vector<float>();
    std::vector<float>* antitau_electron_phi = new std::vector<float>();
    std::vector<float>* antitau_electron_E = new std::vector<float>();

    std::vector<float>* antitau_electronantinu_pt = new std::vector<float>();
    std::vector<float>* antitau_electronantinu_eta = new std::vector<float>();
    std::vector<float>* antitau_electronantinu_phi = new std::vector<float>();
    std::vector<float>* antitau_electronantinu_E = new std::vector<float>();
    
    std::vector<float>* antitau_electronnu_pt = new std::vector<float>();
    std::vector<float>* antitau_electronnu_eta = new std::vector<float>();
    std::vector<float>* antitau_electronnu_phi = new std::vector<float>();
    std::vector<float>* antitau_electronnu_E = new std::vector<float>();

    std::vector<float>* antitau_photon_pt = new std::vector<float>();
    std::vector<float>* antitau_photon_phi = new std::vector<float>();
    std::vector<float>* antitau_photon_eta = new std::vector<float>();
    std::vector<float>* antitau_photon_E = new std::vector<float>();

    std::vector<float>* antitau_taunu_pt = new std::vector<float>();
    std::vector<float>* antitau_taunu_eta = new std::vector<float>();
    std::vector<float>* antitau_taunu_phi = new std::vector<float>();
    std::vector<float>* antitau_taunu_E = new std::vector<float>();

    std::vector<float>* antitau_tauantinu_pt = new std::vector<float>();
    std::vector<float>* antitau_tauantinu_eta = new std::vector<float>();
    std::vector<float>* antitau_tauantinu_phi = new std::vector<float>();
    std::vector<float>* antitau_tauantinu_E = new std::vector<float>();

    std::vector<float>* antitau_kaonL_pt = new std::vector<float>();
    std::vector<float>* antitau_kaonL_eta = new std::vector<float>();
    std::vector<float>* antitau_kaonL_phi = new std::vector<float>();
    std::vector<float>* antitau_kaonL_E = new std::vector<float>();

    std::vector<float>* antitau_kaonS_pt = new std::vector<float>();
    std::vector<float>* antitau_kaonS_eta = new std::vector<float>();
    std::vector<float>* antitau_kaonS_phi = new std::vector<float>();
    std::vector<float>* antitau_kaonS_E = new std::vector<float>();

    std::vector<float>* antitau_kaon_pt = new std::vector<float>();
    std::vector<float>* antitau_kaon_eta = new std::vector<float>();
    std::vector<float>* antitau_kaon_phi = new std::vector<float>();
    std::vector<float>* antitau_kaon_E = new std::vector<float>();
   
    // Point to address in tree (for number of particles)
    input_tree->SetBranchAddress("nBoson", &nBoson);

    //tau and decay products
    input_tree->SetBranchAddress("nTauBorn", &nTauBorn);
    input_tree->SetBranchAddress("nTauChargedPion", &nTauChargedPion);
    input_tree->SetBranchAddress("nTauNeutralPion", &nTauNeutralPion);
    input_tree->SetBranchAddress("nTauMuon", &nTauMuon);  
    input_tree->SetBranchAddress("nTauMuonAntiNu", &nTauMuonAntiNu);
    input_tree->SetBranchAddress("nTauMuonNu", &nTauMuonNu);
    input_tree->SetBranchAddress("nTauElectron", &nTauElectron);
    input_tree->SetBranchAddress("nTauElectronAntiNu", &nTauElectronAntiNu);
    input_tree->SetBranchAddress("nTauElectronNu", &nTauElectronNu);
    input_tree->SetBranchAddress("nTauPhoton", &nTauPhoton);
    input_tree->SetBranchAddress("nTauTauNu", &nTauTauNu);
    input_tree->SetBranchAddress("nTauTauAntiNu", &nTauTauAntiNu);
    input_tree->SetBranchAddress("nTauKaonL", &nTauKaonL);
    input_tree->SetBranchAddress("nTauKaonS", &nTauKaonS);
    input_tree->SetBranchAddress("nTauKaon", &nTauKaon);

    //antitau and decay products
    input_tree->SetBranchAddress("nAntiTauBorn", &nAntiTauBorn);
    input_tree->SetBranchAddress("nAntiTauChargedPion", &nAntiTauChargedPion);
    input_tree->SetBranchAddress("nAntiTauNeutralPion", &nAntiTauNeutralPion);
    input_tree->SetBranchAddress("nAntiTauMuon", &nAntiTauMuon);  
    input_tree->SetBranchAddress("nAntiTauMuonAntiNu", &nAntiTauMuonAntiNu);
    input_tree->SetBranchAddress("nAntiTauMuonNu", &nAntiTauMuonNu);
    input_tree->SetBranchAddress("nAntiTauElectron", &nAntiTauElectron);
    input_tree->SetBranchAddress("nAntiTauElectronAntiNu", &nAntiTauElectronAntiNu);
    input_tree->SetBranchAddress("nAntiTauElectronNu", &nAntiTauElectronNu);
    input_tree->SetBranchAddress("nAntiTauPhoton", &nAntiTauPhoton);
    input_tree->SetBranchAddress("nAntiTauTauNu", &nAntiTauTauNu);
    input_tree->SetBranchAddress("nAntiTauTauAntiNu", &nAntiTauTauAntiNu);
    input_tree->SetBranchAddress("nAntiTauKaonL", &nAntiTauKaonL);
    input_tree->SetBranchAddress("nAntiTauKaonS", &nAntiTauKaonS);
    input_tree->SetBranchAddress("nAntiTauKaon", &nAntiTauKaon);


    // Point to address in tree (for pT, eta, phi, E)

    input_tree->SetBranchAddress("boson_pt", &boson_pt);
    input_tree->SetBranchAddress("boson_eta", &boson_eta);
    input_tree->SetBranchAddress("boson_phi", &boson_phi);
    input_tree->SetBranchAddress("boson_E", &boson_E);

    // tau and decay products
    input_tree->SetBranchAddress("tau_born_pt", &tau_born_pt);
    input_tree->SetBranchAddress("tau_born_eta", &tau_born_eta);
    input_tree->SetBranchAddress("tau_born_phi", &tau_born_phi);
    input_tree->SetBranchAddress("tau_born_E", &tau_born_E);
    input_tree->SetBranchAddress("tau_born_charge", &tau_born_charge);

    input_tree->SetBranchAddress("tau_charged_pion_pt", &tau_charged_pion_pt);
    input_tree->SetBranchAddress("tau_charged_pion_eta", &tau_charged_pion_eta);
    input_tree->SetBranchAddress("tau_charged_pion_phi", &tau_charged_pion_phi);
    input_tree->SetBranchAddress("tau_charged_pion_E", &tau_charged_pion_E);

    input_tree->SetBranchAddress("tau_neutral_pion_pt", &tau_neutral_pion_pt);
    input_tree->SetBranchAddress("tau_neutral_pion_eta", &tau_neutral_pion_eta);
    input_tree->SetBranchAddress("tau_neutral_pion_phi", &tau_neutral_pion_phi);
    input_tree->SetBranchAddress("tau_neutral_pion_E", &tau_neutral_pion_E);
    
    input_tree->SetBranchAddress("tau_muon_pt", &tau_muon_pt);
    input_tree->SetBranchAddress("tau_muon_eta", &tau_muon_eta);
    input_tree->SetBranchAddress("tau_muon_phi", &tau_muon_phi);
    input_tree->SetBranchAddress("tau_muon_E", &tau_muon_E);

    input_tree->SetBranchAddress("tau_muonantinu_pt", &tau_muonantinu_pt);
    input_tree->SetBranchAddress("tau_muonantinu_eta", &tau_muonantinu_eta);
    input_tree->SetBranchAddress("tau_muonantinu_phi", &tau_muonantinu_phi);
    input_tree->SetBranchAddress("tau_muonantinu_E", &tau_muonantinu_E);

    input_tree->SetBranchAddress("tau_muonnu_pt", &tau_muonnu_pt);
    input_tree->SetBranchAddress("tau_muonnu_eta", &tau_muonnu_eta);
    input_tree->SetBranchAddress("tau_muonnu_phi", &tau_muonnu_phi);
    input_tree->SetBranchAddress("tau_muonnu_E", &tau_muonnu_E);

    input_tree->SetBranchAddress("tau_electron_pt", &tau_electron_pt);
    input_tree->SetBranchAddress("tau_electron_eta", &tau_electron_eta);
    input_tree->SetBranchAddress("tau_electron_phi", &tau_electron_phi);
    input_tree->SetBranchAddress("tau_electron_E", &tau_electron_E);
    
    input_tree->SetBranchAddress("tau_electronantinu_pt", &tau_electronantinu_pt);
    input_tree->SetBranchAddress("tau_electronantinu_eta", &tau_electronantinu_eta);
    input_tree->SetBranchAddress("tau_electronantinu_phi", &tau_electronantinu_phi);
    input_tree->SetBranchAddress("tau_electronantinu_E", &tau_electronantinu_E);

    input_tree->SetBranchAddress("tau_electronnu_pt", &tau_electronnu_pt);
    input_tree->SetBranchAddress("tau_electronnu_eta", &tau_electronnu_eta);
    input_tree->SetBranchAddress("tau_electronnu_phi", &tau_electronnu_phi);
    input_tree->SetBranchAddress("tau_electronnu_E", &tau_electronnu_E);

    input_tree->SetBranchAddress("tau_photon_pt", &tau_photon_pt);
    input_tree->SetBranchAddress("tau_photon_eta", &tau_photon_eta);
    input_tree->SetBranchAddress("tau_photon_phi", &tau_photon_phi);
    input_tree->SetBranchAddress("tau_photon_E", &tau_photon_E);

    input_tree->SetBranchAddress("tau_taunu_pt", &tau_taunu_pt);
    input_tree->SetBranchAddress("tau_taunu_eta", &tau_taunu_eta);
    input_tree->SetBranchAddress("tau_taunu_phi", &tau_taunu_phi);
    input_tree->SetBranchAddress("tau_taunu_E", &tau_taunu_E);

    input_tree->SetBranchAddress("tau_tauantinu_pt", &tau_tauantinu_pt);
    input_tree->SetBranchAddress("tau_tauantinu_eta", &tau_tauantinu_eta);
    input_tree->SetBranchAddress("tau_tauantinu_phi", &tau_tauantinu_phi);
    input_tree->SetBranchAddress("tau_tauantinu_E", &tau_tauantinu_E);

    input_tree->SetBranchAddress("tau_kaonL_pt", &tau_kaonL_pt);
    input_tree->SetBranchAddress("tau_kaonL_eta", &tau_kaonL_eta);
    input_tree->SetBranchAddress("tau_kaonL_phi", &tau_kaonL_phi);
    input_tree->SetBranchAddress("tau_kaonL_E", &tau_kaonL_E);

    input_tree->SetBranchAddress("tau_kaonS_pt", &tau_kaonS_pt);
    input_tree->SetBranchAddress("tau_kaonS_eta", &tau_kaonS_eta);
    input_tree->SetBranchAddress("tau_kaonS_phi", &tau_kaonS_phi);
    input_tree->SetBranchAddress("tau_kaonS_E", &tau_kaonS_E);

    input_tree->SetBranchAddress("tau_kaon_pt", &tau_kaon_pt);
    input_tree->SetBranchAddress("tau_kaon_eta", &tau_kaon_eta);
    input_tree->SetBranchAddress("tau_kaon_phi", &tau_kaon_phi);
    input_tree->SetBranchAddress("tau_kaon_E", &tau_kaon_E);

    // antitau and decay products
    input_tree->SetBranchAddress("antitau_born_pt", &antitau_born_pt);
    input_tree->SetBranchAddress("antitau_born_eta", &antitau_born_eta);
    input_tree->SetBranchAddress("antitau_born_phi", &antitau_born_phi);
    input_tree->SetBranchAddress("antitau_born_E", &antitau_born_E);
    input_tree->SetBranchAddress("antitau_born_charge", &antitau_born_charge);

    input_tree->SetBranchAddress("antitau_charged_pion_pt", &antitau_charged_pion_pt);
    input_tree->SetBranchAddress("antitau_charged_pion_eta", &antitau_charged_pion_eta);
    input_tree->SetBranchAddress("antitau_charged_pion_phi", &antitau_charged_pion_phi);
    input_tree->SetBranchAddress("antitau_charged_pion_E", &antitau_charged_pion_E);

    input_tree->SetBranchAddress("antitau_neutral_pion_pt", &antitau_neutral_pion_pt);
    input_tree->SetBranchAddress("antitau_neutral_pion_eta", &antitau_neutral_pion_eta);
    input_tree->SetBranchAddress("antitau_neutral_pion_phi", &antitau_neutral_pion_phi);
    input_tree->SetBranchAddress("antitau_neutral_pion_E", &antitau_neutral_pion_E);
    
    input_tree->SetBranchAddress("antitau_muon_pt", &antitau_muon_pt);
    input_tree->SetBranchAddress("antitau_muon_eta", &antitau_muon_eta);
    input_tree->SetBranchAddress("antitau_muon_phi", &antitau_muon_phi);
    input_tree->SetBranchAddress("antitau_muon_E", &antitau_muon_E);

    input_tree->SetBranchAddress("antitau_muonantinu_pt", &antitau_muonantinu_pt);
    input_tree->SetBranchAddress("antitau_muonantinu_eta", &antitau_muonantinu_eta);
    input_tree->SetBranchAddress("antitau_muonantinu_phi", &antitau_muonantinu_phi);
    input_tree->SetBranchAddress("antitau_muonantinu_E", &antitau_muonantinu_E);

    input_tree->SetBranchAddress("antitau_muonnu_pt", &antitau_muonnu_pt);
    input_tree->SetBranchAddress("antitau_muonnu_eta", &antitau_muonnu_eta);
    input_tree->SetBranchAddress("antitau_muonnu_phi", &antitau_muonnu_phi);
    input_tree->SetBranchAddress("antitau_muonnu_E", &antitau_muonnu_E);

    input_tree->SetBranchAddress("antitau_electron_pt", &antitau_electron_pt);
    input_tree->SetBranchAddress("antitau_electron_eta", &antitau_electron_eta);
    input_tree->SetBranchAddress("antitau_electron_phi", &antitau_electron_phi);
    input_tree->SetBranchAddress("antitau_electron_E", &antitau_electron_E);
    
    input_tree->SetBranchAddress("antitau_electronantinu_pt", &antitau_electronantinu_pt);
    input_tree->SetBranchAddress("antitau_electronantinu_eta", &antitau_electronantinu_eta);
    input_tree->SetBranchAddress("antitau_electronantinu_phi", &antitau_electronantinu_phi);
    input_tree->SetBranchAddress("antitau_electronantinu_E", &antitau_electronantinu_E);

    input_tree->SetBranchAddress("antitau_electronnu_pt", &antitau_electronnu_pt);
    input_tree->SetBranchAddress("antitau_electronnu_eta", &antitau_electronnu_eta);
    input_tree->SetBranchAddress("antitau_electronnu_phi", &antitau_electronnu_phi);
    input_tree->SetBranchAddress("antitau_electronnu_E", &antitau_electronnu_E);

    input_tree->SetBranchAddress("antitau_photon_pt", &antitau_photon_pt);
    input_tree->SetBranchAddress("antitau_photon_eta", &antitau_photon_eta);
    input_tree->SetBranchAddress("antitau_photon_phi", &antitau_photon_phi);
    input_tree->SetBranchAddress("antitau_photon_E", &antitau_photon_E);

    input_tree->SetBranchAddress("antitau_taunu_pt", &antitau_taunu_pt);
    input_tree->SetBranchAddress("antitau_taunu_eta", &antitau_taunu_eta);
    input_tree->SetBranchAddress("antitau_taunu_phi", &antitau_taunu_phi);
    input_tree->SetBranchAddress("antitau_taunu_E", &antitau_taunu_E);

    input_tree->SetBranchAddress("antitau_tauantinu_pt", &antitau_tauantinu_pt);
    input_tree->SetBranchAddress("antitau_tauantinu_eta", &antitau_tauantinu_eta);
    input_tree->SetBranchAddress("antitau_tauantinu_phi", &antitau_tauantinu_phi);
    input_tree->SetBranchAddress("antitau_tauantinu_E", &antitau_tauantinu_E);

    input_tree->SetBranchAddress("antitau_kaonL_pt", &antitau_kaonL_pt);
    input_tree->SetBranchAddress("antitau_kaonL_eta", &antitau_kaonL_eta);
    input_tree->SetBranchAddress("antitau_kaonL_phi", &antitau_kaonL_phi);
    input_tree->SetBranchAddress("antitau_kaonL_E", &antitau_kaonL_E);

    input_tree->SetBranchAddress("antitau_kaonS_pt", &antitau_kaonS_pt);
    input_tree->SetBranchAddress("antitau_kaonS_eta", &antitau_kaonS_eta);
    input_tree->SetBranchAddress("antitau_kaonS_phi", &antitau_kaonS_phi);
    input_tree->SetBranchAddress("antitau_kaonS_E", &antitau_kaonS_E);

    input_tree->SetBranchAddress("antitau_kaon_pt", &antitau_kaon_pt);
    input_tree->SetBranchAddress("antitau_kaon_eta", &antitau_kaon_eta);
    input_tree->SetBranchAddress("antitau_kaon_phi", &antitau_kaon_phi);
    input_tree->SetBranchAddress("antitau_kaon_E", &antitau_kaon_E);

    // initialize vectors to store the pT of the difference for plotting
    std::vector<float> delta_z_to_taus_pt_STORE;
    std::vector<float> delta_taus_to_decays_pt_STORE;

    std::vector<float> dx_taus_to_decays_STORE;
    std::vector<float> dy_taus_to_decays_STORE;
    std::vector<float> dz_taus_to_decays_STORE;

    std::vector<float> dx_z_to_taus_STORE;
    std::vector<float> dy_z_to_taus_STORE;
    std::vector<float> dz_z_to_taus_STORE;

    std::vector<float> z_pt_STORE;

    // initialize summary histograms for pT
    TH1* h1 = nullptr; 
    TH1* h2 = nullptr;
    h1 = new TH1D("h1", "Delta pT between Taus and Decay Products", 20, -0.1, 0.1);
    h2 = new TH1D("h2", "Delta pT between Z and Taus", 20, -0.1, 0.1);
    TFile fout1("dpt_taus_decayprods.root", "recreate"); 
    TFile fout2("dpt_z_taus.root", "recreate");

    // initialize summary histograms for taus versus decay products
    TH1* h3 = nullptr; // px
    TH1* h4 = nullptr; // py
    TH1* h5 = nullptr; // pz
    h3 = new TH1D("h3", "Delta px between Taus and Decay Products", 20, -0.00002, 0.00002);
    h3->SetDirectory(nullptr);

    h4 = new TH1D("h4", "Delta py between Taus and Decay Products", 20, -0.00002, 0.00002);
    h4->SetDirectory(nullptr);

    h5 = new TH1D("h5", "Delta pz between Taus and Decay Products", 20, -0.001, 0.001);
    h5->SetDirectory(nullptr);

    TFile fout3("dpx_taus_decayprods.root", "recreate");
    TFile fout4("dpy_taus_decayprods.root", "recreate");
    TFile fout5("dpz_taus_decayprods.root", "recreate");

    // initialize summary histograms for z's versus taus
    TH1* h6 = nullptr; // px
    TH1* h7 = nullptr; // py
    TH1* h8 = nullptr; // pz
    h6 = new TH1D("h6", "Delta px between Z and Taus", 20, -0.00002, 0.00002);
    h6->SetDirectory(nullptr);

    h7 = new TH1D("h7", "Delta py between Z and Taus", 20, -0.00002, 0.00002);
    h7->SetDirectory(nullptr);

    h8 = new TH1D("h8", "Delta pz between Z and Taus", 20, -0.001, 0.001);
    h8->SetDirectory(nullptr);

    TFile fout6("dpx_z_taus.root", "recreate");
    TFile fout7("dpy_z_taus.root", "recreate");
    TFile fout8("dpz_z_taus.root", "recreate");

    //initialize histogram for z pt
    TH1* h9 = nullptr; // zpt
    h9 =  new TH1D("h9", "Z pT", 20, 78, 474);
    h9->SetDirectory(nullptr);
    TFile fout9("z_pt.root", "recreate");

    // TRandom3 rand;  
    int nEntries = input_tree->GetEntries();    

    for ( int i = 0 ; i < nEntries ; i++ ) {        // iterate from 0 to the max number of events you want to select
        input_tree->GetEvent(i);                    // get the information for the specific event

        // std::cout << "================Event " << i << " ================" << std::endl;

        //1p1n-1p1n selection

        if ((nTauChargedPion == 1) && (nTauPhoton == 2) && (nAntiTauChargedPion == 1) && (nAntiTauPhoton == 2) && (nTauTauNu == 1) && (nAntiTauTauAntiNu== 1)) {
            // std::cout << "This event passes 1p1n-1p1n selection!" << std::endl;
        
            // define TLorentz vectors

            TLorentzVector tau_decay_sum_p4; // stores the sum of the 4 vectors of the decay products from the tau
            TLorentzVector antitau_decay_sum_p4; // stores the sum of the 4 vectors of the decay products from the antitau
            TLorentzVector tau_sum_p4; // stores the sum of the 4 vectors of the taus
            
            TLorentzVector z_p4; // stores the 4 vector of the Z
            TLorentzVector tau_born_p4;
            TLorentzVector antitau_born_p4;

            z_p4.SetPtEtaPhiE((*boson_pt)[0], (*boson_eta)[0], (*boson_phi)[0], (*boson_E)[0]);
            tau_born_p4.SetPtEtaPhiE((*tau_born_pt)[0], (*tau_born_eta)[0], (*tau_born_phi)[0], (*tau_born_E)[0]);
            antitau_born_p4.SetPtEtaPhiE((*antitau_born_pt)[0], (*antitau_born_eta)[0], (*antitau_born_phi)[0], (*antitau_born_E)[0]);
            
            tau_sum_p4 += tau_born_p4 + antitau_born_p4; // add the 4 vectors to the running sum of 4 vectors of decay products
            // std::cout << "Sum of taus 4 vec: " << tau_sum_p4.Px() << ", " << tau_sum_p4.Py() << ", " << tau_sum_p4.Pz() << std::endl;
            // std::cout << "Z 4 vec: " << z_p4.Px() << ", " << z_p4.Py() << ", " << z_p4.Pz() << std::endl;

            //loop through tau decay products and add to running sum
            if (nTauChargedPion > 0) {                                       
                for ( size_t i = 0 ; i < (tau_charged_pion_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Charged Pion" << std::endl;

                    TLorentzVector ch_pion_p4;
                    ch_pion_p4.SetPtEtaPhiE((*tau_charged_pion_pt)[i], (*tau_charged_pion_eta)[i], (*tau_charged_pion_phi)[i], (*tau_charged_pion_E)[i]);
                    tau_decay_sum_p4 += ch_pion_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nTauNeutralPion > 0) {                                      
                for ( size_t i = 0 ; i < (tau_neutral_pion_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Neutral Pion" << std::endl;
                    
                    TLorentzVector neut_pion_p4;
                    neut_pion_p4.SetPtEtaPhiE((*tau_neutral_pion_pt)[i], (*tau_neutral_pion_eta)[i], (*tau_neutral_pion_phi)[i], (*tau_neutral_pion_E)[i]);
                    tau_decay_sum_p4 += neut_pion_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }
            
            if (nTauMuon > 0) {                                      
                for ( size_t i = 0 ; i < (tau_muon_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Muon" << std::endl;
                    
                    TLorentzVector tau_muon_p4;
                    tau_muon_p4.SetPtEtaPhiE((*tau_muon_pt)[i], (*tau_muon_eta)[i], (*tau_muon_phi)[i], (*tau_muon_E)[i]);
                    tau_decay_sum_p4 += tau_muon_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nTauMuonAntiNu > 0) {                                      
                for ( size_t i = 0 ; i < (tau_muonantinu_pt->size()) ; i++ ) { 
                    // std::cout << "Muon AntiNeutrino" << std::endl;
                    
                    TLorentzVector tau_muonantinu_p4;
                    tau_muonantinu_p4.SetPtEtaPhiE((*tau_muonantinu_pt)[i], (*tau_muonantinu_eta)[i], (*tau_muonantinu_phi)[i], (*tau_muonantinu_E)[i]);
                    tau_decay_sum_p4 += tau_muonantinu_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nTauMuonNu > 0) {                                      
                for ( size_t i = 0 ; i < (tau_muonnu_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Muon Neutrino" << std::endl;
                    
                    TLorentzVector tau_muonnu_p4;
                    tau_muonnu_p4.SetPtEtaPhiE((*tau_muonnu_pt)[i], (*tau_muonnu_eta)[i], (*tau_muonnu_phi)[i], (*tau_muonnu_E)[i]);
                    tau_decay_sum_p4 += tau_muonnu_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nTauElectron > 0) {                                      
                for ( size_t i = 0 ; i < (tau_electron_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Electron" << std::endl;
                    
                    TLorentzVector tau_electron_p4;
                    tau_electron_p4.SetPtEtaPhiE((*tau_electron_pt)[i], (*tau_electron_eta)[i], (*tau_electron_phi)[i], (*tau_electron_E)[i]);
                    tau_decay_sum_p4 += tau_electron_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nTauElectronAntiNu > 0) {                                      
                for ( size_t i = 0 ; i < (tau_electronantinu_pt->size()) ; i++ ) { 
                    
                    TLorentzVector tau_electronantinu_p4;
                    tau_electronantinu_p4.SetPtEtaPhiE((*tau_electronantinu_pt)[i], (*tau_electronantinu_eta)[i], (*tau_electronantinu_phi)[i], (*tau_electronantinu_E)[i]);
                    tau_decay_sum_p4 += tau_electronantinu_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nTauElectronNu > 0) {                                      
                for ( size_t i = 0 ; i < (tau_electronnu_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Electron Neutrino" << std::endl;
                    
                    TLorentzVector tau_electronnu_p4;
                    tau_electronnu_p4.SetPtEtaPhiE((*tau_electronnu_pt)[i], (*tau_electronnu_eta)[i], (*tau_electronnu_phi)[i], (*tau_electronnu_E)[i]);
                    tau_decay_sum_p4 += tau_electronnu_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nTauPhoton > 0) {                                      
                for ( size_t i = 0 ; i < (tau_photon_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Photon" << std::endl;
                    
                    TLorentzVector tau_photon_p4;
                    tau_photon_p4.SetPtEtaPhiE((*tau_photon_pt)[i], (*tau_photon_eta)[i], (*tau_photon_phi)[i], (*tau_photon_E)[i]);
                    tau_decay_sum_p4 += tau_photon_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nTauTauNu > 0) {                                      
                for ( size_t i = 0 ; i < (tau_taunu_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Tau Neutrino" << std::endl;
                    
                    TLorentzVector tau_taunu_p4;
                    tau_taunu_p4.SetPtEtaPhiE((*tau_taunu_pt)[i], (*tau_taunu_eta)[i], (*tau_taunu_phi)[i], (*tau_taunu_E)[i]);
                    tau_decay_sum_p4 += tau_taunu_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nTauTauAntiNu > 0) {                                      
                for ( size_t i = 0 ; i < (tau_tauantinu_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Tau AntiNeutrino" << std::endl;
                    
                    TLorentzVector tau_tauantinu_p4;
                    tau_tauantinu_p4.SetPtEtaPhiE((*tau_tauantinu_pt)[i], (*tau_tauantinu_eta)[i], (*tau_tauantinu_phi)[i], (*tau_tauantinu_E)[i]);
                    tau_decay_sum_p4 += tau_tauantinu_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nTauKaonL > 0) {                                      
                for ( size_t i = 0 ; i < (tau_kaonL_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Kaon L" << std::endl;
                    
                    TLorentzVector tau_kaonL_p4;
                    tau_kaonL_p4.SetPtEtaPhiE((*tau_kaonL_pt)[i], (*tau_kaonL_eta)[i], (*tau_kaonL_phi)[i], (*tau_kaonL_E)[i]);
                    tau_decay_sum_p4 += tau_kaonL_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nTauKaonS > 0) {                                      
                for ( size_t i = 0 ; i < (tau_kaonS_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Kaon S" << std::endl;
                    
                    TLorentzVector tau_kaonS_p4;
                    tau_kaonS_p4.SetPtEtaPhiE((*tau_kaonS_pt)[i], (*tau_kaonS_eta)[i], (*tau_kaonS_phi)[i], (*tau_kaonS_E)[i]);
                    tau_decay_sum_p4 += tau_kaonS_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nTauKaon > 0) {                                      
                for ( size_t i = 0 ; i < (tau_kaon_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Kaon" << std::endl;
                    
                    TLorentzVector tau_kaon_p4;
                    tau_kaon_p4.SetPtEtaPhiE((*tau_kaon_pt)[i], (*tau_kaon_eta)[i], (*tau_kaon_phi)[i], (*tau_kaon_E)[i]);
                    tau_decay_sum_p4 += tau_kaon_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            //loop through antitau decay products and add to running sum
            if (nAntiTauChargedPion > 0) {                                       
                for ( size_t i = 0 ; i < (antitau_charged_pion_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Charged Pion" << std::endl;

                    TLorentzVector ch_pion_p4;
                    ch_pion_p4.SetPtEtaPhiE((*antitau_charged_pion_pt)[i], (*antitau_charged_pion_eta)[i], (*antitau_charged_pion_phi)[i], (*antitau_charged_pion_E)[i]);
                    antitau_decay_sum_p4 += ch_pion_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nAntiTauNeutralPion > 0) {                                      
                for ( size_t i = 0 ; i < (antitau_neutral_pion_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Neutral Pion" << std::endl;
                    
                    TLorentzVector neut_pion_p4;
                    neut_pion_p4.SetPtEtaPhiE((*antitau_neutral_pion_pt)[i], (*antitau_neutral_pion_eta)[i], (*antitau_neutral_pion_phi)[i], (*antitau_neutral_pion_E)[i]);
                    antitau_decay_sum_p4 += neut_pion_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }
            
            if (nAntiTauMuon > 0) {                                      
                for ( size_t i = 0 ; i < (antitau_muon_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Muon" << std::endl;
                    
                    TLorentzVector antitau_muon_p4;
                    antitau_muon_p4.SetPtEtaPhiE((*antitau_muon_pt)[i], (*antitau_muon_eta)[i], (*antitau_muon_phi)[i], (*antitau_muon_E)[i]);
                    antitau_decay_sum_p4 += antitau_muon_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nAntiTauMuonAntiNu > 0) {                                      
                for ( size_t i = 0 ; i < (antitau_muonantinu_pt->size()) ; i++ ) { 
                    // std::cout << "Muon AntiNeutrino" << std::endl;
                    
                    TLorentzVector antitau_muonantinu_p4;
                    antitau_muonantinu_p4.SetPtEtaPhiE((*antitau_muonantinu_pt)[i], (*antitau_muonantinu_eta)[i], (*antitau_muonantinu_phi)[i], (*antitau_muonantinu_E)[i]);
                    antitau_decay_sum_p4 += antitau_muonantinu_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nAntiTauMuonNu > 0) {                                      
                for ( size_t i = 0 ; i < (antitau_muonnu_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Muon Neutrino" << std::endl;
                    
                    TLorentzVector antitau_muonnu_p4;
                    antitau_muonnu_p4.SetPtEtaPhiE((*antitau_muonnu_pt)[i], (*antitau_muonnu_eta)[i], (*antitau_muonnu_phi)[i], (*antitau_muonnu_E)[i]);
                    antitau_decay_sum_p4 += antitau_muonnu_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nAntiTauElectron > 0) {                                      
                for ( size_t i = 0 ; i < (antitau_electron_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Electron" << std::endl;
                    
                    TLorentzVector antitau_electron_p4;
                    antitau_electron_p4.SetPtEtaPhiE((*antitau_electron_pt)[i], (*antitau_electron_eta)[i], (*antitau_electron_phi)[i], (*antitau_electron_E)[i]);
                    antitau_decay_sum_p4 += antitau_electron_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nAntiTauElectronAntiNu > 0) {                                      
                for ( size_t i = 0 ; i < (antitau_electronantinu_pt->size()) ; i++ ) { 
                    
                    TLorentzVector antitau_electronantinu_p4;
                    antitau_electronantinu_p4.SetPtEtaPhiE((*antitau_electronantinu_pt)[i], (*antitau_electronantinu_eta)[i], (*antitau_electronantinu_phi)[i], (*antitau_electronantinu_E)[i]);
                    antitau_decay_sum_p4 += antitau_electronantinu_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nAntiTauElectronNu > 0) {                                      
                for ( size_t i = 0 ; i < (antitau_electronnu_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Electron Neutrino" << std::endl;
                    
                    TLorentzVector antitau_electronnu_p4;
                    antitau_electronnu_p4.SetPtEtaPhiE((*antitau_electronnu_pt)[i], (*antitau_electronnu_eta)[i], (*antitau_electronnu_phi)[i], (*antitau_electronnu_E)[i]);
                    antitau_decay_sum_p4 += antitau_electronnu_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nAntiTauPhoton > 0) {                                      
                for ( size_t i = 0 ; i < (antitau_photon_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Photon" << std::endl;
                    
                    TLorentzVector antitau_photon_p4;
                    antitau_photon_p4.SetPtEtaPhiE((*antitau_photon_pt)[i], (*antitau_photon_eta)[i], (*antitau_photon_phi)[i], (*antitau_photon_E)[i]);
                    antitau_decay_sum_p4 += antitau_photon_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nAntiTauTauNu > 0) {                                      
                for ( size_t i = 0 ; i < (antitau_taunu_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Tau Neutrino" << std::endl;
                    
                    TLorentzVector antitau_taunu_p4;
                    antitau_taunu_p4.SetPtEtaPhiE((*antitau_taunu_pt)[i], (*antitau_taunu_eta)[i], (*antitau_taunu_phi)[i], (*antitau_taunu_E)[i]);
                    antitau_decay_sum_p4 += antitau_taunu_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nAntiTauTauAntiNu > 0) {                                      
                for ( size_t i = 0 ; i < (antitau_tauantinu_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Tau AntiNeutrino" << std::endl;
                    
                    TLorentzVector antitau_tauantinu_p4;
                    antitau_tauantinu_p4.SetPtEtaPhiE((*antitau_tauantinu_pt)[i], (*antitau_tauantinu_eta)[i], (*antitau_tauantinu_phi)[i], (*antitau_tauantinu_E)[i]);
                    antitau_decay_sum_p4 += antitau_tauantinu_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nAntiTauKaonL > 0) {                                      
                for ( size_t i = 0 ; i < (antitau_kaonL_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Kaon L" << std::endl;
                    
                    TLorentzVector antitau_kaonL_p4;
                    antitau_kaonL_p4.SetPtEtaPhiE((*antitau_kaonL_pt)[i], (*antitau_kaonL_eta)[i], (*antitau_kaonL_phi)[i], (*antitau_kaonL_E)[i]);
                    antitau_decay_sum_p4 += antitau_kaonL_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nAntiTauKaonS > 0) {                                      
                for ( size_t i = 0 ; i < (antitau_kaonS_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Kaon S" << std::endl;
                    
                    TLorentzVector antitau_kaonS_p4;
                    antitau_kaonS_p4.SetPtEtaPhiE((*antitau_kaonS_pt)[i], (*antitau_kaonS_eta)[i], (*antitau_kaonS_phi)[i], (*antitau_kaonS_E)[i]);
                    antitau_decay_sum_p4 += antitau_kaonS_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            if (nAntiTauKaon > 0) {                                      
                for ( size_t i = 0 ; i < (antitau_kaon_pt->size()) ; i++ ) { 
                    
                    // std::cout << "Kaon" << std::endl;
                    
                    TLorentzVector antitau_kaon_p4;
                    antitau_kaon_p4.SetPtEtaPhiE((*antitau_kaon_pt)[i], (*antitau_kaon_eta)[i], (*antitau_kaon_phi)[i], (*antitau_kaon_E)[i]);
                    antitau_decay_sum_p4 += antitau_kaon_p4; // add the 4 vector to the running sum of 4 vectors of decay products
                }
            }

            // do subtraction

            TLorentzVector delta_taus_to_decays_p4 = tau_sum_p4 - tau_decay_sum_p4 - antitau_decay_sum_p4;
            TLorentzVector delta_z_to_taus_p4 = z_p4 - tau_sum_p4;
            
            // get transverse momentum of differences

            float delta_taus_to_decays_pt = delta_taus_to_decays_p4.Pt();
            float delta_z_to_taus_pt = delta_z_to_taus_p4.Pt();

            float delta_taus_to_decays_px = delta_taus_to_decays_p4.Px();
            // std::cout << "delta taus to decays px" << delta_taus_to_decays_px << std::endl;

            float delta_taus_to_decays_py = delta_taus_to_decays_p4.Py();
            // std::cout << "delta taus to decays py" << delta_taus_to_decays_py << std::endl;

            float delta_taus_to_decays_pz = delta_taus_to_decays_p4.Pz();
            // std::cout << "delta taus to decays pz" << delta_taus_to_decays_pz << std::endl;

            float delta_z_to_taus_px = delta_z_to_taus_p4.Px();
            float delta_z_to_taus_py = delta_z_to_taus_p4.Py();
            float delta_z_to_taus_pz = delta_z_to_taus_p4.Pz();

            // get z pt
            float z_pt = z_p4.Pt();

            // push delta pT to a vector (for checking size)

            delta_taus_to_decays_pt_STORE.push_back(delta_taus_to_decays_pt);
            delta_z_to_taus_pt_STORE.push_back(delta_z_to_taus_pt);

            dx_taus_to_decays_STORE.push_back(delta_taus_to_decays_px);
            dy_taus_to_decays_STORE.push_back(delta_taus_to_decays_py);
            dz_taus_to_decays_STORE.push_back(delta_taus_to_decays_pz);

            dx_z_to_taus_STORE.push_back(delta_z_to_taus_px);
            dy_z_to_taus_STORE.push_back(delta_z_to_taus_py);
            dz_z_to_taus_STORE.push_back(delta_z_to_taus_pz);

            z_pt_STORE.push_back(z_pt);

            // fill histograms

            h1->Fill(delta_taus_to_decays_pt);
            h2->Fill(delta_z_to_taus_pt);
            h3->Fill(delta_taus_to_decays_px);

            h4->Fill(delta_taus_to_decays_py);
            h5->Fill(delta_taus_to_decays_pz);

            h6->Fill(delta_z_to_taus_px);
            h7->Fill(delta_z_to_taus_py);
            h8->Fill(delta_z_to_taus_pz);

            h9->Fill(z_pt);
        }
    }

    // plotting 
    fout1.cd();
    h1->GetXaxis()->SetTitle("Delta pT between Taus and Decay Products [GeV]");
    h1->GetYaxis()->SetTitle("Entries");
    h1->Write();
    fout1.Close();
  
    fout2.cd();
    h2->GetXaxis()->SetTitle("Delta pT between Z and Taus [GeV]");
    h2->GetYaxis()->SetTitle("Entries");
    h2->Write();
    fout2.Close();
  
    fout3.cd();
    h3->GetXaxis()->SetTitle("Delta px between Taus and Decay Products [GeV]");
    h3->GetYaxis()->SetTitle("Entries");
    h3->Write();
    fout3.Close();
  
    fout4.cd();
    h4->GetXaxis()->SetTitle("Delta py between Taus and Decay Products [GeV]");
    h4->GetYaxis()->SetTitle("Entries");
    h4->Write();
    fout4.Close();
  
    fout5.cd();
    h5->GetXaxis()->SetTitle("Delta pz between Taus and Decay Products [GeV]");
    h5->GetYaxis()->SetTitle("Entries");
    // TGaxis *axis = new TGaxis();
    // axis->SetMaxDigits(2);
    h5->Write();
    fout5.Close();
 
    fout6.cd();
    h6->GetXaxis()->SetTitle("Delta px between Z and Taus [GeV]");
    h6->GetYaxis()->SetTitle("Entries");
    h6->Write();
    fout6.Close();

    fout7.cd();
    h7->GetXaxis()->SetTitle("Delta py between Z and Taus [GeV]");
    h7->GetYaxis()->SetTitle("Entries");
    h7->Write();
    fout7.Close();
   
    fout8.cd();
    h8->GetXaxis()->SetTitle("Delta pz between Z and Taus [GeV]");
    h8->GetYaxis()->SetTitle("Entries");
    h8->Write();
    fout8.Close();

    fout9.cd();
    h9->GetXaxis()->SetTitle("Z pT [GeV]");
    h9->GetYaxis()->SetTitle("Entries");
    h9->Write();
    fout9.Close();
   
    // std::cout << "size of delta_z_to_taus_pt_STORE: " << delta_z_to_taus_pt_STORE.size() << std::endl;
    // std::cout << "size of delta_taus_to_decays_pt_STORE: " << delta_taus_to_decays_pt_STORE.size() << std::endl;

    auto min_max_z_to_taus_x = minmax_element(dx_z_to_taus_STORE.begin(), dx_z_to_taus_STORE.end());
    auto min_max_z_to_taus_y = minmax_element(dy_z_to_taus_STORE.begin(), dy_z_to_taus_STORE.end());
    auto min_max_z_to_taus_z = minmax_element(dz_z_to_taus_STORE.begin(), dz_z_to_taus_STORE.end());
    
    auto min_max_taus_to_decays_x = minmax_element(dx_taus_to_decays_STORE.begin(), dx_taus_to_decays_STORE.end());
    auto min_max_taus_to_decays_y = minmax_element(dy_taus_to_decays_STORE.begin(), dy_taus_to_decays_STORE.end());
    auto min_max_taus_to_decays_z = minmax_element(dz_taus_to_decays_STORE.begin(), dz_taus_to_decays_STORE.end());

    auto min_max_z_pt = minmax_element(z_pt_STORE.begin(), z_pt_STORE.end());

    std::cout << "min of dx for Z --> taus: " << *min_max_z_to_taus_x.first << std::endl;
    std::cout << "max of dx for Z --> taus: " << *min_max_z_to_taus_x.second << std::endl;

    std::cout << "min of dy for Z --> taus: " << *min_max_z_to_taus_y.first << std::endl;
    std::cout << "max of dy for Z --> taus: " << *min_max_z_to_taus_y.second << std::endl;

    std::cout << "min of dz for Z --> taus: " << *min_max_z_to_taus_z.first << std::endl;
    std::cout << "max of dz for Z --> taus: " << *min_max_z_to_taus_z.second << std::endl;

    std::cout << "min of dx for taus --> decays: " << *min_max_taus_to_decays_x.first << std::endl;
    std::cout << "max of dx for taus --> decays: " << *min_max_taus_to_decays_x.second << std::endl;
    
    std::cout << "min of dy for taus --> decays: " << *min_max_taus_to_decays_y.first << std::endl;
    std::cout << "max of dy for taus --> decays: " << *min_max_taus_to_decays_y.second << std::endl;

    std::cout << "min of dz for taus --> decays: " << *min_max_taus_to_decays_z.first << std::endl;
    std::cout << "max of dz for taus --> decays: " << *min_max_taus_to_decays_z.second << std::endl;

    std::cout << "min of zpt: " << *min_max_z_pt.first << std::endl;
    std::cout << "max of zpt: " << *min_max_z_pt.second << std::endl;
}