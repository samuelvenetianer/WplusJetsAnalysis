// binning for output variables

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<bits/stdc++.h>


// link root header files
// #include "TROOT.h"
// #include "TTree.h"
// #include "TFile.h"
// #include "TRandom3.h"
// #include "TLorentzVector.h"
// #include "TVector3.h"
// #include "TH1D.h"

struct Binning{
    int nBins;
    double low;
    double high;
    const char *title;
    const char *xaxis;
};

const std::map<std::string,Binning> binningByVariable = {
    {"psi truth", {40, -3.14, 3.14, "hists/psi_canvas_test.root", "#psi"}},

    {"Z pT vis", {40, 0, 50, "hists/Z_pt_vis.root", "Z pT vis"}},
    {"Z eta vis", {40, -4, 4, "hists/Z_eta_vis.root", "Z #eta vis"}},
    {"Z phi vis", {40, -3.14, 3.14, "hists/Z_phi_vis.root", "Z #phi vis"}},
    {"Z E vis", {40, 0, 1500, "hists/Z_E_vis.root", "Z E vis"}},

    {"Z px vis", {40, -50, 50, "hists/Z_px_vis.root", "Z px vis"}},
    {"Z py vis", {40, -50, 50, "hists/Z_py_vis.root", "Z py vis"}},
    {"Z pz vis", {40, -50, 50, "hists/Z_pz_vis.root", "Z pz vis"}},
    
    {"Z pT real", {40, 0, 50, "hists/Z_pt_real.root", "Z pT real"}},
    {"Z eta real", {40, -4, 4, "hists/Z_eta_real.root", "Z #eta real"}},
    {"Z phi real", {40, -3.14, 3.14, "hists/Z_phi_real.root", "Z #phi real"}},
    {"Z E real", {40, 0, 1500, "hists/Z_E_real.root", "Z E real"}},

    {"Z px real", {40, -50, 50, "hists/Z_px_real.root", "Z px real"}},
    {"Z py real", {40, -50, 50, "hists/Z_py_real.root", "Z py real"}},
    {"Z pz real", {40, -50, 50, "hists/Z_pz_real.root", "Z pz real"}},

    // UPDATE BINNING

    {"Delta vis real Z px", {40, -3.14, 3.14, "hists/d_vis_real_Zpx.root", "Delta vis real Z px"}},
    {"Delta vis real Z py", {40, -3.14, 3.14, "hists/d_vis_real_Zpy.root", "Delta vis real Z py"}},
    {"Delta vis real Z pz", {40, -3.14, 3.14, "hists/d_vis_real_Zpz.root", "Delta vis real Z pz"}},

    // Ratio troubleshooting

    {"Ratio Z pT visible to real", {40, 0, 1, "hists/ratio_zpt_vis_real.root", "Ratio Z pT visible to real"}},
    {"Ratio Sum pT visible to real", {40, 0, 1, "hists/sum_pt_ratio.root", "Ratio Sum pT visible to real"}},
    
    {"Ratio for low pT real", {40, 0, 1, "hists/ratio_low.root", "Ratio pT visible products to pT all products for low real pT"}},
    {"Ratio for med pT real", {40, 0, 1, "hists/ratio_med.root", "Ratio pT visible products to pT all products for med real pT"}},
    {"Ratio for high pT real", {40, 0, 1, "hists/ratio_high.root", "Ratio pT visible products to pT all products for high real pT"}},

    {"Sum pT real", {40, 0, 100, "hists/sum_pt_real.root", "Sum pT real"}},
    {"Sum pT vis", {40, 0, 100, "hists/sum_pt_vis.root", "Sum pT vis"}},
};

const std::vector<std::string> ALL_OUTPUTS = {
    "psi truth", 
    "Z pT vis", 
    "Z eta vis", 
    "Z phi vis", 
    "Z px vis",
    "Z py vis",
    "Z pz vis",
    "Z pT real",
    "Z eta real",
    "Z phi real",
    "Z E real",
    "Z px real",
    "Z py real",
    "Z pz real",
    "Delta vis real Z px",
    "Delta vis real Z py",
    "Delta vis real Z pz",
    "Ratio Z pT visible to real",
    "Ratio Sum pT visible to real",
    "Ratio for low pT real",
    "Ratio for med pT real",
    "Ratio for high pT real",
    "Sum pT real",
    "Sum pT vis",
};

const std::vector<std::string> ALL_INPUTS = {
    "boson_pt",
    "boson_eta",
    "boson_phi",
    "boson_E",
    
    "tau_charged_pion_pt",
    "tau_charged_pion_eta",
    "tau_charged_pion_phi",
    "tau_charged_pion_E",

    "antitau_charged_pion_pt",
    "antitau_charged_pion_eta",
    "antitau_charged_pion_phi",
    "antitau_charged_pion_E",

    "tau_photon_pt",
    "tau_photon_eta",
    "tau_photon_phi",
    "tau_photon_E",

    "antitau_photon_pt",
    "antitau_photon_eta",
    "antitau_photon_phi",
    "antitau_photon_E",

    "tau_born_pt",
    "tau_born_eta",
    "tau_born_phi",
    "tau_born_E",

    "antitau_born_pt",
    "antitau_born_eta",
    "antitau_born_phi",
    "antitau_born_E",

    "tau_taunu_pt",
    "tau_taunu_eta",
    "tau_taunu_phi",
    "tau_taunu_E",

    "antitau_tauantinu_pt",
    "antitau_tauantinu_eta",
    "antitau_tauantinu_phi",
    "antitau_tauantinu_E",

};

const std::vector<std::string> ALL_INPUTS_INT = {
    
    // Multiplicity variables for 1p1n-1p1n
    
    "nBoson",

    "nTauBorn",
    "nAntiTauBorn",

    "nTauChargedPion",
    "nTauNeutralPion",
    "nTauPhoton",
    "nTauTauNu",

    "nAntiTauChargedPion",
    "nAntiTauNeutralPion",
    "nAntiTauPhoton",
    "nAntiTauTauAntiNu",

    // Other multiplicity variables
    "nTauMuon",
    "nTauMuonAntiNu",
    "nTauMuonNu",
    "nTauElectron",
    "nTauElectronAntiNu",
    "nTauElectronNu",
    "nTauTauAntiNu",
    "nTauKaonL",
    "nTauKaonS",
    "nTauKaon",
    "nAntiTauMuon",
    "nAntiTauMuonAntiNu",
    "nAntiTauMuonNu",
    "nAntiTauElectron",
    "nAntiTauElectronAntiNu",
    "nAntiTauElectronNu",
    "nAntiTauTauNu",
    "nAntiTauKaonL",
    "nAntiTauKaonS",
    "nAntiTauKaon",
};
