// Use this script to validate addition of tau children to tau decays

// add makefile
// update root path

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>

// update path to point to whatever was installed in the setup step
#include "TROOT.h"
#include "TTree.h"
#include "TFile.h"
#include "TRandom3.h"
#include "TLorentzVector.h"
#include "TVector3.h"

int main() {
    TFile f("/cluster/tufts/beaucheminlab/svenet01/WplusJetsAnalysis/pythia-outputs/2025/testing.root"); // read input file
    TTree *input_tree = (TTree*)f.Get("ParticleTree");        // "Get" the ParticleTree tree from the file and assign it to local variable "input_tree" - there are two of these. Is this an issue when calling?

    // initialization of variables counting number of particle of interest
    Int_t nTauMuon;                                             
    Int_t nElectronBorn;                                       
    Int_t nChargedPion;
    Int_t nNeutralPion;
    Int_t nTauMuon;
    Int_t nTauMuonAntiNu
    Int_t nTauMuonNu;
    Int_t nTauElectron;
    Int_t nTauElectronAntiNu;
    Int_t nTauElectronNu;

    // create pointer and initialize empty vectors for tau children
    std::vector<float>* electron_born_pt = new std::vector<float>(); //electron_born used as a test case
    std::vector<float>* electron_born_eta = new std::vector<float>();
    std::vector<float>* electron_born_phi = new std::vector<float>();
    std::vector<float>* electron_born_E = new std::vector<float>();

    std::vector<float>* charged_pion_pt = new std::vector<float>();
    std::vector<float>* charged_pion_eta = new std::vector<float>();
    std::vector<float>* charged_pion_phi = new std::vector<float>();
    std::vector<float>* charged_pion_E = new std::vector<float>();

    std::vector<float>* neutral_pion_pt = new std::vector<float>();
    std::vector<float>* neutral_pion_eta = new std::vector<float>();
    std::vector<float>* neutral_pion_phi = new std::vector<float>();
    std::vector<float>* neutral_pion_E = new std::vector<float>();

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
   
    // Point to address in tree (for number of particles)
    input_tree->SetBranchAddress("nElectronBorn", &nElectronBorn);          // test
    input_tree->SetBranchAddress("nTauMuon", &nTauMuon);                                           
    input_tree->SetBranchAddress("nElectronBorn", &nElectronBorn);                                       
    input_tree->SetBranchAddress("nChargedPion", &nChargedPion);
    input_tree->SetBranchAddress("nNeutralPion", &nNeutralPion);
    input_tree->SetBranchAddress("nTauMuon", &nTauMuon);
    input_tree->SetBranchAddress("nTauMuonAntiNu", &nTauMuonAntiNu);
    input_tree->SetBranchAddress("nTauMuonNu", &nTauMuonNu);
    input_tree->SetBranchAddress("nTauElectron", &nTauElectron);
    input_tree->SetBranchAddress("nTauElectronAntiNu", &nTauElectronAntiNu);
    input_tree->SetBranchAddress("nTauElectronNu", &nTauElectronNu);
    
    // Point to address in tree (for pT, eta, phi, E)
    input_tree->SetBranchAddress("electron_born_pt", &electron_born_pt);    // test
    input_tree->SetBranchAddress("electron_born_eta", &electron_born_eta);
    input_tree->SetBranchAddress("electron_born_phi", &electron_born_phi);
    input_tree->SetBranchAddress("electron_born_E", &electron_born_E);
    
    input_tree->SetBranchAddress("charged_pion_pt", &charged_pion_pt);
    input_tree->SetBranchAddress("charged_pion_eta", &charged_pion_eta);
    input_tree->SetBranchAddress("charged_pion_phi", &charged_pion_phi);
    input_tree->SetBranchAddress("charged_pion_E", &charged_pion_E);

    input_tree->SetBranchAddress("neutral_pion_pt", &neutral_pion_pt);
    input_tree->SetBranchAddress("neutral_pion_eta", &neutral_pion_eta);
    input_tree->SetBranchAddress("neutral_pion_phi", &neutral_pion_phi);
    input_tree->SetBranchAddress("neutral_pion_E", &neutral_pion_E);

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

    input_tree->SetBranchAddress("tau_electronnu_pt", &tau_electronantinu_pt);
    input_tree->SetBranchAddress("tau_electronnu_eta", &tau_electronantinu_eta);
    input_tree->SetBranchAddress("tau_electronnu_phi", &tau_electronantinu_phi);
    input_tree->SetBranchAddress("tau_electronnu_E", &tau_electronantinu_E);

    TRandom3 rand;                                                          // Initialize random number for selecting events

    for ( int randCounter = 0 ; randCounter < 50 ; randCounter++ ) {        // iterate from 0 to the max number of events you want to select
        int i = rand.Uniform(input_tree->GetEntries());                     // chooses a random event from the input tree

        input_tree->GetEvent(i);                                            // get the information for the specific event

        // STEP 1: Initialize pT, eta, phi, E variables to zero (double type)
        // STEP 2: Check size of each n vector, proceed if > 0
        // STEP 3: Add pT, eta, phi, E to floats
        // STEP 4: Repeat for each possible child particle
        
        if (nElectronBorn > 0) {                                            // test
            std::cout << "size of electron_born_pt is: "<< electron_born_pt->size()<<std::endl;
            std::cout << "electron_born (pT, eta, phi, E): " << (*electron_born_pt)[0] << " , " << (*electron_born_eta)[0] << " , " << (*electron_born_phi)[0] << " , " << (*electron_born_E)[0] << std::endl; 
        }

        // Misc print statements
        /*
        std::cout << "charged_pion (pT, eta, phi, E): " << charged_pion_pt << " , " << charged_pion_eta << " , " << charged_pion_phi << " , " << charged_pion_E << std::endl; 
        std::cout << "neutral_pion (pT, eta, phi, E): " << neutral_pion_pt << " , " << neutral_pion_eta << " , " << neutral_pion_phi << " , " << neutral_pion_E << std::endl; 
        std::cout << "tau_muon (pT, eta, phi, E): " << tau_muon_pt << " , " << tau_muon_eta << " , " << tau_muon_phi << " , " << tau_muon_E << std::endl; 
        std::cout << "tau_muonantinu (pT, eta, phi, E): " << tau_muonantinu_pt << " , " << tau_muonantinu_eta << " , " << tau_muonantinu_phi << " , " << tau_muonantinu_E << std::endl; 
        std::cout << "tau_muonnu (pT, eta, phi, E): " << tau_muonnu_pt << " , " << tau_muonnu_eta << " , " << tau_muonnu_phi << " , " << tau_muonnu_E << std::endl; 
        std::cout << "tau_electron (pT, eta, phi, E): " << tau_electron_pt << " , " << tau_electron_eta << " , " << tau_electron_phi << " , " << tau_electron_E << std::endl; 
        std::cout << "tau_electronantinu (pT, eta, phi, E): " << tau_electronantinu_pt << " , " << tau_electronantinu_eta << " , " << tau_electronantinu_phi << " , " << tau_electronantinu_E << std::endl; 
        */
        
    }
    return 0;
}

// once working, do this for all events instead of a small selection