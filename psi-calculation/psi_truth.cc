// Psi Truth calculation for hadhad channel

// standard libraries
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include <chrono>

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

    const auto start{std::chrono::steady_clock::now()};

    // Specify input file

    std::cout << "Calling input file..." << std::endl;
    TFile f("/cluster/tufts/beaucheminlab/svenet01/WplusJetsAnalysis/pythia-outputs/2025/v3_070226.root"); 
    TTree *input_tree = (TTree*)f.Get("ParticleTree");
    
    std::cout << "Initializing maps..." << std::endl;
    std::map<std::string, TH1*> histsByName;
    std::map<std::string, std::vector<float>*> BUFFER_BY_INPUT;
    std::map<std::string, Int_t> BUFFER_BY_INPUT_INT;
    std::map<std::string, std::vector<int>*> BUFFER_BY_INPUT_VEC_INT;
    std::map<std::string, float> variablesByName;

    std::cout << "Creating empty hist for: " << std::endl;
    for (const std::string& output:ALL_OUTPUTS){                            // & means reference
        std::cout << "----------" << output << std::endl;
        histsByName[output] = new TH1F(output.c_str(), output.c_str(), binningByVariable.at(output).nBins, binningByVariable.at(output).low, binningByVariable.at(output).high);
        histsByName[output] -> GetXaxis()->SetTitle(binningByVariable.at(output).xaxis);
        histsByName[output] -> GetYaxis()->SetTitle("Entries");
    }

    std::cout << "Setting Branch Address for vectors of floats:" << std::endl;
    for (const std::string& input:ALL_INPUTS){
        BUFFER_BY_INPUT[input] = new std::vector<float>();
        input_tree->SetBranchAddress(input.c_str(), &BUFFER_BY_INPUT[input]);
        std::cout << "----------" << input.c_str() << std::endl;
    }

    std::cout << "Setting Branch Address for vectors of ints:" << std::endl;
    for (const std::string& input:ALL_INPUTS_VEC_INT){
        BUFFER_BY_INPUT_VEC_INT[input] = new std::vector<int>();
        input_tree->SetBranchAddress(input.c_str(), &BUFFER_BY_INPUT_VEC_INT[input]);
        std::cout << "----------" << input.c_str() << std::endl;
    }

    std::cout << "Setting Branch Address for Ints:" << std::endl;
    for (const std::string& input:ALL_INPUTS_INT){
        input_tree->SetBranchAddress(input.c_str(), &BUFFER_BY_INPUT_INT[input]);
        std::cout << "----------" << input.c_str() << std::endl;
    }

    int nEntries = input_tree->GetEntries(); 
    std::cout << "num entries: " << nEntries << std::endl;

    // int nEntries = 100;   

    // Initialize counters
    int n1p1nEvents = 0;
    int nOtherEvents = 0;

    int low_pt_count = 0;
    int med_pt_count = 0;
    int high_pt_count = 0;

    std::cout << "======Looping through events...======" << std::endl;
    for ( int i = 0 ; i < nEntries ; i++ ) {        
        
        float remainder = i % 100000;
        if (remainder == 0){
            std::cout << "Events processed: " << i << std::endl;
        }

        input_tree->GetEvent(i);
        
        // Complete calculations
        if (((*BUFFER_BY_INPUT_VEC_INT["boson_ID"]).size() == 1) && ((*BUFFER_BY_INPUT_VEC_INT["boson_ID"])[0] == 23) && ((BUFFER_BY_INPUT_INT["nTauBorn"]) == 1) && ((BUFFER_BY_INPUT_INT["nAntiTauBorn"]) == 1) && ((BUFFER_BY_INPUT_INT["nTauChargedPion"]) == 1) && ((BUFFER_BY_INPUT_INT["nTauPhoton"]) == 2) && ((BUFFER_BY_INPUT_INT["nAntiTauChargedPion"]) == 1) && ((BUFFER_BY_INPUT_INT["nAntiTauPhoton"]) == 2) && ((BUFFER_BY_INPUT_INT["nTauTauNu"]) == 1) && ((BUFFER_BY_INPUT_INT["nAntiTauTauAntiNu"]) == 1) && ((*BUFFER_BY_INPUT["tau_born_pt"])[0] > 25) && ((*BUFFER_BY_INPUT["antitau_born_pt"])[0] > 25)) {

            // Check to make sure there aren't any additional decay produts
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
                // std::cout << std::setw(25) << "Multiplicity"  << std::setw(15) << "Number\n"  << std::endl;
                // for (const std::string& input:ALL_INPUTS_INT){
                //     if ((BUFFER_BY_INPUT_INT[input]) > 0){
                //         std::cout << std::setw(25) << input  << std::setw(15) << (BUFFER_BY_INPUT_INT[input]) <<  std::endl;
                //     }
                // }
                // std::cout << "\n" << std::endl;
            }

            else{
                
                n1p1nEvents += 1;

                // initialize all variables to -1000. If these stay at -1000, the variable will not be plotted.
                for (const std::string& output:ALL_OUTPUTS){
                    variablesByName[output] = -1000;
                }
 
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

                variablesByName["tau neutral pion pt"] = tau_neut_pion_p4.Pt();
                variablesByName["antitau neutral pion pt"] = antitau_neut_pion_p4.Pt();

                variablesByName["tau charged pion pt"] = (*BUFFER_BY_INPUT["tau_charged_pion_pt"])[0];
                variablesByName["antitau charged pion pt"] = (*BUFFER_BY_INPUT["antitau_charged_pion_pt"])[0];

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

                variablesByName["psi truth true boost"] = TruthPsiHadHadTrueBoost(
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
                                                antitau_neut_pion_p4.E(),

                                                (*BUFFER_BY_INPUT["tau_taunu_pt"])[0],
                                                (*BUFFER_BY_INPUT["tau_taunu_eta"])[0],
                                                (*BUFFER_BY_INPUT["tau_taunu_phi"])[0],
                                                (*BUFFER_BY_INPUT["tau_taunu_E"])[0],

                                                (*BUFFER_BY_INPUT["antitau_tauantinu_pt"])[0],
                                                (*BUFFER_BY_INPUT["antitau_tauantinu_eta"])[0],
                                                (*BUFFER_BY_INPUT["antitau_tauantinu_phi"])[0],
                                                (*BUFFER_BY_INPUT["antitau_tauantinu_E"])[0],

                                                (*BUFFER_BY_INPUT["boson_pt"])[0],
                                                (*BUFFER_BY_INPUT["boson_eta"])[0],
                                                (*BUFFER_BY_INPUT["boson_phi"])[0],
                                                (*BUFFER_BY_INPUT["boson_E"])[0],

                                                (*BUFFER_BY_INPUT["tau_born_pt"])[0],
                                                (*BUFFER_BY_INPUT["tau_born_eta"])[0],
                                                (*BUFFER_BY_INPUT["tau_born_phi"])[0],
                                                (*BUFFER_BY_INPUT["tau_born_E"])[0],

                                                (*BUFFER_BY_INPUT["antitau_born_pt"])[0],
                                                (*BUFFER_BY_INPUT["antitau_born_eta"])[0],
                                                (*BUFFER_BY_INPUT["antitau_born_phi"])[0],
                                                (*BUFFER_BY_INPUT["antitau_born_E"])[0]
                                                );

                variablesByName["psi truth true boost rho plane"] = TruthPsiHadHadTrueBoostRhoPlane(
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
                                                antitau_neut_pion_p4.E(),

                                                (*BUFFER_BY_INPUT["tau_taunu_pt"])[0],
                                                (*BUFFER_BY_INPUT["tau_taunu_eta"])[0],
                                                (*BUFFER_BY_INPUT["tau_taunu_phi"])[0],
                                                (*BUFFER_BY_INPUT["tau_taunu_E"])[0],

                                                (*BUFFER_BY_INPUT["antitau_tauantinu_pt"])[0],
                                                (*BUFFER_BY_INPUT["antitau_tauantinu_eta"])[0],
                                                (*BUFFER_BY_INPUT["antitau_tauantinu_phi"])[0],
                                                (*BUFFER_BY_INPUT["antitau_tauantinu_E"])[0],

                                                (*BUFFER_BY_INPUT["boson_pt"])[0],
                                                (*BUFFER_BY_INPUT["boson_eta"])[0],
                                                (*BUFFER_BY_INPUT["boson_phi"])[0],
                                                (*BUFFER_BY_INPUT["boson_E"])[0],

                                                (*BUFFER_BY_INPUT["tau_born_pt"])[0],
                                                (*BUFFER_BY_INPUT["tau_born_eta"])[0],
                                                (*BUFFER_BY_INPUT["tau_born_phi"])[0],
                                                (*BUFFER_BY_INPUT["tau_born_E"])[0],

                                                (*BUFFER_BY_INPUT["antitau_born_pt"])[0],
                                                (*BUFFER_BY_INPUT["antitau_born_eta"])[0],
                                                (*BUFFER_BY_INPUT["antitau_born_phi"])[0],
                                                (*BUFFER_BY_INPUT["antitau_born_E"])[0]
                                                );

                variablesByName["upsilon minus"] = Upsilon(
                    (*BUFFER_BY_INPUT["tau_charged_pion_pt"])[0],
                    (*BUFFER_BY_INPUT["tau_charged_pion_eta"])[0],
                    (*BUFFER_BY_INPUT["tau_charged_pion_phi"])[0],
                    (*BUFFER_BY_INPUT["tau_charged_pion_E"])[0],

                    tau_neut_pion_p4.Pt(),
                    tau_neut_pion_p4.Eta(),
                    tau_neut_pion_p4.Phi(),
                    tau_neut_pion_p4.E()
                );

                 variablesByName["upsilon plus"] = Upsilon(
                    (*BUFFER_BY_INPUT["antitau_charged_pion_pt"])[0],
                    (*BUFFER_BY_INPUT["antitau_charged_pion_eta"])[0],
                    (*BUFFER_BY_INPUT["antitau_charged_pion_phi"])[0],
                    (*BUFFER_BY_INPUT["antitau_charged_pion_E"])[0],

                    antitau_neut_pion_p4.Pt(),
                    antitau_neut_pion_p4.Eta(),
                    antitau_neut_pion_p4.Phi(),
                    antitau_neut_pion_p4.E()
                );

                variablesByName["upsilon minus higgs"] = UpsilonHiggs(
                    (*BUFFER_BY_INPUT["tau_charged_pion_pt"])[0],
                    (*BUFFER_BY_INPUT["tau_charged_pion_eta"])[0],
                    (*BUFFER_BY_INPUT["tau_charged_pion_phi"])[0],
                    (*BUFFER_BY_INPUT["tau_charged_pion_E"])[0],

                    tau_neut_pion_p4.Pt(),
                    tau_neut_pion_p4.Eta(),
                    tau_neut_pion_p4.Phi(),
                    tau_neut_pion_p4.E()
                );

                 variablesByName["upsilon plus higgs"] = UpsilonHiggs(
                    (*BUFFER_BY_INPUT["antitau_charged_pion_pt"])[0],
                    (*BUFFER_BY_INPUT["antitau_charged_pion_eta"])[0],
                    (*BUFFER_BY_INPUT["antitau_charged_pion_phi"])[0],
                    (*BUFFER_BY_INPUT["antitau_charged_pion_E"])[0],

                    antitau_neut_pion_p4.Pt(),
                    antitau_neut_pion_p4.Eta(),
                    antitau_neut_pion_p4.Phi(),
                    antitau_neut_pion_p4.E()
                );

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

                // Psi for various Upsilon
                if ((variablesByName["upsilon plus"] < 0.5) && (variablesByName["upsilon minus"] < 0.5)){
                    variablesByName["psi YP low YM low"] = variablesByName["psi truth"];
                }
                else if ((variablesByName["upsilon plus"] < 0.5) && (variablesByName["upsilon minus"] > 0.5)){
                    variablesByName["psi YP low YM high"] = variablesByName["psi truth"];
                }
                else if ((variablesByName["upsilon plus"] > 0.5) && (variablesByName["upsilon minus"] < 0.5)){
                    variablesByName["psi YP high YM low"] = variablesByName["psi truth"];
                }
                else if ((variablesByName["upsilon plus"] > 0.5) && (variablesByName["upsilon minus"] > 0.5)){
                    variablesByName["psi YP high YM high"] = variablesByName["psi truth"];
                }

                // Psi for various Zed pT
                if ((*BUFFER_BY_INPUT["boson_pt"])[0] < 20){
                    variablesByName["psi low Z pT"] = variablesByName["psi truth"];
                    variablesByName["psi true boost low Z pT"] = variablesByName["psi truth true boost"];
                    low_pt_count += 1;
                }
                else if (((*BUFFER_BY_INPUT["boson_pt"])[0] >= 20) && ((*BUFFER_BY_INPUT["boson_pt"])[0] < 40)){
                    variablesByName["psi med Z pT"] = variablesByName["psi truth"];
                    variablesByName["psi true boost med Z pT"] = variablesByName["psi truth true boost"];
                    med_pt_count += 1;
                }
                else{
                    variablesByName["psi high Z pT"] = variablesByName["psi truth"];
                    variablesByName["psi true boost high Z pT"] = variablesByName["psi truth true boost"];
                    high_pt_count += 1;
                }

                variablesByName["Z pT vis"] = z_vis_p4.Pt();
                variablesByName["Z eta vis"] = z_vis_p4.Eta();
                variablesByName["Z phi vis"] = z_vis_p4.Phi();
                variablesByName["Z E vis"] = z_vis_p4.E();
                variablesByName["Z px vis"] = z_vis_p4.Px();
                variablesByName["Z py vis"] = z_vis_p4.Py();
                variablesByName["Z pz vis"] = z_vis_p4.Pz();

                variablesByName["Z pT real"] = (*BUFFER_BY_INPUT["boson_pt"])[0];
                variablesByName["Z eta real"] = (*BUFFER_BY_INPUT["boson_eta"])[0];
                variablesByName["Z phi real"] = (*BUFFER_BY_INPUT["boson_phi"])[0];
                variablesByName["Z E real"] = (*BUFFER_BY_INPUT["boson_E"])[0];

                // Fill hists for each variable for 1p1n events only
                for (const std::string& output:ALL_OUTPUTS){
                    if (variablesByName[output] == -1000){
                        continue;
                    }
                    else{
                        // std::cout << output << ": " << variablesByName[output] << std::endl;
                        histsByName[output] -> Fill(variablesByName[output]);
                    }
                }
            }

        }
        else{
            //print number of taus, bosons, etc:
            // std::cout << std::setw(25) << "Multiplicity"  << std::setw(15) << "Number\n"  << std::endl;
            // for (const std::string& input:ALL_INPUTS_INT){
            //     if ((BUFFER_BY_INPUT_INT[input]) > 0){
            //         std::cout << std::setw(25) << input  << std::setw(15) << (BUFFER_BY_INPUT_INT[input]) <<  std::endl;
            //     }
            // }
            // std::cout << "\n" << std::endl;
            nOtherEvents += 1;
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
    std::cout << "\n" << nOtherEvents << " events out of " << nEntries << " are not 1p1n-1p1n events." << std::endl; 

    const auto finish{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds{finish - start};
    // std::cout << elapsed_seconds << '\n' << std::endl;
    std::cout << "Run time: " << elapsed_seconds.count() << "s\n";

    return 0;
}