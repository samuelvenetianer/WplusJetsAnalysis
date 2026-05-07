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
#include "MyFunctions.cc" // why need this included here?
#include "MyFunctions.h"

int main() {

    // Specify input file

    std::cout << "Calling input file..." << std::endl;
    TFile f("/cluster/tufts/beaucheminlab/svenet01/WplusJetsAnalysis/pythia-outputs/2025/040726_test.root"); 
    TTree *input_tree = (TTree*)f.Get("ParticleTree");
    
    std::cout << "Initializing maps..." << std::endl;
    std::map<std::string, TH1*> histsByName;
    std::map<std::string, std::vector<float>*> BUFFER_BY_INPUT;
    std::map<std::string, Int_t> BUFFER_BY_INPUT_INT;

    std::map<std::string, float> variablesByName;

    std::cout << "Creating empty hist for: " << std::endl;
    for (const std::string& output:ALL_OUTPUTS){                            // & means reference
        std::cout << "----------" << output << std::endl;
        histsByName[output] = new TH1F(output.c_str(), output.c_str(), binningByVariable.at(output).nBins, binningByVariable.at(output).low, binningByVariable.at(output).high);
        histsByName[output] -> GetXaxis()->SetTitle(binningByVariable.at(output).xaxis);
        histsByName[output] -> GetYaxis()->SetTitle("Entries");
    }

    std::cout << "Setting Branch Address for vectors:" << std::endl;
    for (const std::string& input:ALL_INPUTS){
        BUFFER_BY_INPUT[input] = new std::vector<float>();
        input_tree->SetBranchAddress(input.c_str(), &BUFFER_BY_INPUT[input]);
        std::cout << "----------" << input.c_str() << std::endl;
    }

    std::cout << "Setting Branch Address for Ints:" << std::endl;
    for (const std::string& input:ALL_INPUTS_INT){
        input_tree->SetBranchAddress(input.c_str(), &BUFFER_BY_INPUT_INT[input]);
        std::cout << "----------" << input.c_str() << std::endl;
    }

    int nEntries = input_tree->GetEntries(); 
    // int nEntries = 100;   

    int n1p1nEvents = 0;
    int low_events = 0;
    int med_events = 0;
    int high_events = 0;

    std::cout << "======Looping through events...======" << std::endl;
    for ( int i = 0 ; i < nEntries ; i++ ) {        
        
        input_tree->GetEvent(i);  

        // Complete calculations
        if (((BUFFER_BY_INPUT_INT["nTauChargedPion"]) == 1) && ((BUFFER_BY_INPUT_INT["nTauPhoton"]) == 2) && ((BUFFER_BY_INPUT_INT["nAntiTauChargedPion"]) == 1) && ((BUFFER_BY_INPUT_INT["nAntiTauPhoton"]) == 2) && ((BUFFER_BY_INPUT_INT["nTauTauNu"]) == 1) && ((BUFFER_BY_INPUT_INT["nAntiTauTauAntiNu"]) == 1)) {
            // std::cout << "Event passes 1p1n-1p1n selection!" << std::endl;

            // std::cout << "Num Taus: " << (BUFFER_BY_INPUT_INT["nTauBorn"]) << std::endl;
            // std::cout << "Num AntiTaus: " << (BUFFER_BY_INPUT_INT["nAntiTauBorn"]) << std::endl;

            // Check to make sure there aren't any other decay produts
            int sum_excess_prods = (BUFFER_BY_INPUT_INT["nTauMuon"]) + 
                            (BUFFER_BY_INPUT_INT["nTauMuonAntiNu"]) +
                            (BUFFER_BY_INPUT_INT["nTauMuonNu"]) +
                            (BUFFER_BY_INPUT_INT["nTauElectron"]) +
                            (BUFFER_BY_INPUT_INT["nTauElectronAntiNu"]) +
                            (BUFFER_BY_INPUT_INT["nTauElectronNu"]) +
                            (BUFFER_BY_INPUT_INT["nTauTauAntiNu"]) +
                            (BUFFER_BY_INPUT_INT["nTauKaonL"]) +
                            (BUFFER_BY_INPUT_INT["nTauKaonS"]) +
                            (BUFFER_BY_INPUT_INT["nTauKaon"])+

                            (BUFFER_BY_INPUT_INT["nAntiTauMuon"]) + 
                            (BUFFER_BY_INPUT_INT["nAntiTauMuonAntiNu"]) +
                            (BUFFER_BY_INPUT_INT["nAntiTauMuonNu"]) +
                            (BUFFER_BY_INPUT_INT["nAntiTauElectron"]) +
                            (BUFFER_BY_INPUT_INT["nAntiTauElectronAntiNu"]) +
                            (BUFFER_BY_INPUT_INT["nAntiTauElectronNu"]) +
                            (BUFFER_BY_INPUT_INT["nAntiTauKaonL"]) +
                            (BUFFER_BY_INPUT_INT["nAntiTauKaonS"]) +
                            (BUFFER_BY_INPUT_INT["nAntiTauKaon"]);

            if (sum_excess_prods > 0){
                std::cout << "\n===========STOP! Event " << i << " is not a true 1p1n-1p1n event.===========\n" <<
                    "===========There is(are) "<< sum_excess_prods << " additional decay product(s).\n" << std::endl;
                
                // print table of multiplicity values
                std::cout << std::setw(25) << "Multiplicity"  << std::setw(15) << "Number\n"  << std::endl;

                for (const std::string& input:ALL_INPUTS_INT){
                    if ((BUFFER_BY_INPUT_INT[input]) > 0){
                        std::cout << std::setw(25) << input  << std::setw(15) << (BUFFER_BY_INPUT_INT[input]) <<  std::endl;
                    }
                    
                }
                
                std::cout << "\n" << std::endl;

            }

            else{
            
                std::cout << "Event " << i << " is selected.===========" << std::endl;

                n1p1nEvents += 1;
 
                // Construct neutral pions from photons
                TLorentzVector tau_photon1_p4;
                TLorentzVector tau_photon2_p4;

                TLorentzVector antitau_photon1_p4;
                TLorentzVector antitau_photon2_p4;

                TLorentzVector tau_neut_pion_p4;
                TLorentzVector antitau_neut_pion_p4;

                tau_photon1_p4.SetPtEtaPhiE((*BUFFER_BY_INPUT["tau_photon_pt"])[0], (*BUFFER_BY_INPUT["tau_photon_eta"])[0], (*BUFFER_BY_INPUT["tau_photon_phi"])[0], (*BUFFER_BY_INPUT["tau_photon_E"])[0]);
                tau_photon2_p4.SetPtEtaPhiE((*BUFFER_BY_INPUT["tau_photon_pt"])[1], (*BUFFER_BY_INPUT["tau_photon_eta"])[1], (*BUFFER_BY_INPUT["tau_photon_phi"])[1], (*BUFFER_BY_INPUT["tau_photon_E"])[1]);
            
                antitau_photon1_p4.SetPtEtaPhiE((*BUFFER_BY_INPUT["antitau_photon_pt"])[0], (*BUFFER_BY_INPUT["antitau_photon_eta"])[0], (*BUFFER_BY_INPUT["antitau_photon_phi"])[0], (*BUFFER_BY_INPUT["antitau_photon_E"])[0]);
                antitau_photon2_p4.SetPtEtaPhiE((*BUFFER_BY_INPUT["antitau_photon_pt"])[1], (*BUFFER_BY_INPUT["antitau_photon_eta"])[1], (*BUFFER_BY_INPUT["antitau_photon_phi"])[1], (*BUFFER_BY_INPUT["antitau_photon_E"])[1]);
                
                tau_neut_pion_p4 = tau_photon1_p4 + tau_photon2_p4;
                antitau_neut_pion_p4 = antitau_photon1_p4 + antitau_photon2_p4;

                // Calculate psi and other relevant quantities

                variablesByName["psi truth"] = TruthPsiHadHad(
                                                (*BUFFER_BY_INPUT["tau_charged_pion_pt"])[0],
                                                (*BUFFER_BY_INPUT["tau_charged_pion_eta"])[0],
                                                (*BUFFER_BY_INPUT["tau_charged_pion_phi"])[0],
                                                (*BUFFER_BY_INPUT["tau_charged_pion_E"])[0],

                                                (*BUFFER_BY_INPUT["antitau_charged_pion_pt"])[0],
                                                (*BUFFER_BY_INPUT["antitau_charged_pion_eta"])[0],
                                                (*BUFFER_BY_INPUT["antitau_charged_pion_phi"])[0],
                                                (*BUFFER_BY_INPUT["antitau_charged_pion_E"])[0],

                                                tau_neut_pion_p4.Pt(),
                                                tau_neut_pion_p4.Eta(),
                                                tau_neut_pion_p4.Phi(),
                                                tau_neut_pion_p4.E(),

                                                antitau_neut_pion_p4.Pt(),
                                                antitau_neut_pion_p4.Eta(),
                                                antitau_neut_pion_p4.Phi(),
                                                antitau_neut_pion_p4.E()
                                                );

                // std::cout << "psi value: " << variablesByName["psi"] << std::endl;

                TLorentzVector z_vis_p4 = ZedVis(
                                                (*BUFFER_BY_INPUT["tau_charged_pion_pt"])[0],
                                                (*BUFFER_BY_INPUT["tau_charged_pion_eta"])[0],
                                                (*BUFFER_BY_INPUT["tau_charged_pion_phi"])[0],
                                                (*BUFFER_BY_INPUT["tau_charged_pion_E"])[0],

                                                (*BUFFER_BY_INPUT["antitau_charged_pion_pt"])[0],
                                                (*BUFFER_BY_INPUT["antitau_charged_pion_eta"])[0],
                                                (*BUFFER_BY_INPUT["antitau_charged_pion_phi"])[0],
                                                (*BUFFER_BY_INPUT["antitau_charged_pion_E"])[0],

                                                tau_neut_pion_p4.Pt(),
                                                tau_neut_pion_p4.Eta(),
                                                tau_neut_pion_p4.Phi(),
                                                tau_neut_pion_p4.E(),

                                                antitau_neut_pion_p4.Pt(),
                                                antitau_neut_pion_p4.Eta(),
                                                antitau_neut_pion_p4.Phi(),
                                                antitau_neut_pion_p4.E()
                );

                variablesByName["Z pT vis"] = z_vis_p4.Pt();
                variablesByName["Z eta vis"] = z_vis_p4.Eta();
                variablesByName["Z phi vis"] = z_vis_p4.Phi();
                variablesByName["Z E vis"] = z_vis_p4.E();
                variablesByName["Z px vis"] = z_vis_p4.Px();
                variablesByName["Z py vis"] = z_vis_p4.Py();
                variablesByName["Z pz vis"] = z_vis_p4.Pz();

                const TLorentzVector z_real_p4 = ZedReal(
                                    (*BUFFER_BY_INPUT["tau_born_pt"])[0],
                                    (*BUFFER_BY_INPUT["tau_born_eta"])[0],
                                    (*BUFFER_BY_INPUT["tau_born_phi"])[0],
                                    (*BUFFER_BY_INPUT["tau_born_E"])[0],

                                    (*BUFFER_BY_INPUT["antitau_born_pt"])[0],
                                    (*BUFFER_BY_INPUT["antitau_born_eta"])[0],
                                    (*BUFFER_BY_INPUT["antitau_born_phi"])[0],
                                    (*BUFFER_BY_INPUT["antitau_born_E"])[0]
                                    );

                variablesByName["Z pT real"] = z_real_p4.Pt();
                variablesByName["Z eta real"] = z_real_p4.Eta();
                variablesByName["Z phi real"] = z_real_p4.Phi();
                variablesByName["Z E real"] = z_real_p4.E();

                variablesByName["Z px real"] = z_real_p4.Px();
                variablesByName["Z py real"] = z_real_p4.Py();
                variablesByName["Z pz real"] = z_real_p4.Pz();

                variablesByName["Delta vis real Z px"] = std::abs(z_vis_p4.Px()-z_real_p4.Px());
                variablesByName["Delta vis real Z py"] = std::abs(z_vis_p4.Py()-z_real_p4.Py());
                variablesByName["Delta vis real Z pz"] = std::abs(z_vis_p4.Pz()-z_real_p4.Pz());

                variablesByName["Ratio Z pT visible to real"]  = z_vis_p4.Pt()/z_real_p4.Pt();

                // Calculating sum of pT of visible products
                float sum_pt_vis = (*BUFFER_BY_INPUT["tau_charged_pion_pt"])[0] + (*BUFFER_BY_INPUT["antitau_charged_pion_pt"])[0] + tau_photon1_p4.Pt() + tau_photon2_p4.Pt() + antitau_photon1_p4.Pt() + antitau_photon2_p4.Pt();
                float sum_pt_all = sum_pt_vis + (*BUFFER_BY_INPUT["tau_taunu_pt"])[0] + (*BUFFER_BY_INPUT["antitau_tauantinu_pt"])[0];

                variablesByName["Sum pT real"] = sum_pt_all;
                variablesByName["Sum pT vis"] = sum_pt_vis;
                variablesByName["Ratio Sum pT visible to real"] = sum_pt_vis/sum_pt_all;

                // Fill ratio buckets depending on sum of pT of all decay products
                if (sum_pt_all < 30){
                    variablesByName["Ratio for low pT real"] = sum_pt_vis/sum_pt_all;
                    low_events += 1;
                    variablesByName["Ratio for med pT real"] = -1;
                    variablesByName["Ratio for high pT real"] = -1;
                }

                else if ((sum_pt_all > 30) && (sum_pt_all < 60)){
                    variablesByName["Ratio for med pT real"] = sum_pt_vis/sum_pt_all;
                    med_events += 1;
                    variablesByName["Ratio for low pT real"] = -1;
                    variablesByName["Ratio for high pT real"] = -1;
                }

                else if (sum_pt_all > 60){
                    variablesByName["Ratio for high pT real"] = sum_pt_vis/sum_pt_all;
                    high_events += 1;
                    variablesByName["Ratio for low pT real"] = -1;
                    variablesByName["Ratio for med pT real"] = -1;
                }

                // Add neutrinos as a cross check for vis pT

                TLorentzVector tau_nu_p4;
                TLorentzVector antitau_nu_p4;

                tau_nu_p4.SetPtEtaPhiE((*BUFFER_BY_INPUT["tau_taunu_pt"])[0], (*BUFFER_BY_INPUT["tau_taunu_eta"])[0], (*BUFFER_BY_INPUT["tau_taunu_phi"])[0], (*BUFFER_BY_INPUT["tau_taunu_E"])[0]);
                antitau_nu_p4.SetPtEtaPhiE((*BUFFER_BY_INPUT["antitau_tauantinu_pt"])[0], (*BUFFER_BY_INPUT["antitau_tauantinu_eta"])[0], (*BUFFER_BY_INPUT["antitau_tauantinu_phi"])[0], (*BUFFER_BY_INPUT["antitau_tauantinu_E"])[0]);

                TLorentzVector z_real_from_decay_prod_p4 = z_vis_p4 + tau_nu_p4 + antitau_nu_p4;
                TLorentzVector neutrino_sum = tau_nu_p4 + antitau_nu_p4;

                // Fill hists for each variable
                for (const std::string& output:ALL_OUTPUTS){                            // & means reference
                    histsByName[output] -> Fill(variablesByName[output]);
                }
            }

        }  
    }  

    // Draw hists for each variable
    for (const std::string& output:ALL_OUTPUTS){
        std::cout << binningByVariable.at(output).title << std::endl;
        TFile fout(binningByVariable.at(output).title, "recreate");
        fout.cd();
        histsByName[output] -> Write();
        fout.Close();
        // canv.Print(binningByVariable.at(output).title);
    }     

    std::cout << "\n" << n1p1nEvents << " events out of " << nEntries << " passed 1p1n-1p1n selection." << std::endl; 
    std::cout << "\n" << "low: " <<  low_events << std::endl;   
    std::cout << "\n" << "med: " <<  med_events << std::endl;      
    std::cout << "\n" << "high: " <<  high_events << std::endl;               

    return 0;
}