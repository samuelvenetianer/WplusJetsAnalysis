#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

struct Binning{
    int nBins;
    double low;
    double high;
    const char *title;
    const char *xaxis;
};

const std::map<std::string,Binning> binningByVariable = {
    {"psi truth", {40, -3.14, 3.14, "hists/psi_truth.root", "#psi"}},
    {"psi truth bump", {40, -3.14, 3.14, "hists/psi_truth_bump.root", "#psi"}},
    {"psi diff", {40, -10, 10, "hists/psi_diff.root", "#psi diff"}},
    {"psi truth true boost", {40, -3.14, 3.14, "hists/psi_truth_true_boost.root", "#psi"}},
    {"psi truth true boost rho plane", {40, -3.14, 3.14, "hists/psi_truth_true_boost_rho_plane.root", "#psi"}},

    {"psi YP low YM low", {40, -3.14, 3.14, "hists/psi_truth_yp_low_ym_low.root", "#psi"}},
    {"psi YP low YM high", {40, -3.14, 3.14, "hists/psi_truth_yp_low_ym_high.root", "#psi"}},
    {"psi YP high YM low", {40, -3.14, 3.14, "hists/psi_truth_yp_high_ym_low.root", "#psi"}},
    {"psi YP high YM high", {40, -3.14, 3.14, "hists/psi_truth_yp_high_ym_high.root", "#psi"}},
   
    {"psi low Z pT", {40, -3.14, 3.14, "hists/psi_low_z_pt.root", "#psi"}},
    {"psi med Z pT", {40, -3.14, 3.14, "hists/psi_med_z_pt.root", "#psi"}},
    {"psi high Z pT", {40, -3.14, 3.14, "hists/psi_high_z_pt.root", "#psi"}},

    {"psi bump low Z pT", {40, -3.14, 3.14, "hists/psi_bump_low_z_pt.root", "#psi"}},
    {"psi bump med Z pT", {40, -3.14, 3.14, "hists/psi_bump_med_z_pt.root", "#psi"}},
    {"psi bump high Z pT", {40, -3.14, 3.14, "hists/psi_bump_high_z_pt.root", "#psi"}},

    {"psi true boost low Z pT", {40, -3.14, 3.14, "hists/psi_trueboost_low_z_pt.root", "#psi"}},
    {"psi true boost med Z pT", {40, -3.14, 3.14, "hists/psi_trueboost_med_z_pt.root", "#psi"}},
    {"psi true boost high Z pT", {40, -3.14, 3.14, "hists/psi_trueboost_high_z_pt.root", "#psi"}},

    {"Z pT vis", {40, 0, 50, "hists/Z_pt_vis.root", "Z pT vis"}},
    {"Z eta vis", {40, -4, 4, "hists/Z_eta_vis.root", "Z #eta vis"}},
    {"Z phi vis", {40, -3.14, 3.14, "hists/Z_phi_vis.root", "Z #phi vis"}},
    {"Z E vis", {40, 0, 1500, "hists/Z_E_vis.root", "Z E vis"}},
    
    {"Z pT real", {40, 0, 50, "hists/Z_pt_real.root", "Z pT real"}},
    {"Z eta real", {40, -4, 4, "hists/Z_eta_real.root", "Z #eta real"}},
    {"Z phi real", {40, -3.14, 3.14, "hists/Z_phi_real.root", "Z #phi real"}},
    {"Z E real", {40, 0, 1500, "hists/Z_E_real.root", "Z E real"}},

    {"truth tau pt", {40, 0, 200, "hists/tau_pt.root", "Tau pT"}},
    {"truth tau eta", {40, -4, 4, "hists/tau_eta.root", "Tau eta"}},
    {"truth tau phi", {40, -3.14, 3.14, "hists/tau_phi.root", "Tau phi"}},
    {"truth tau E", {40, 0, 1500, "hists/tau_E.root", "Tau E"}},

    {"truth antitau pt", {40, 0, 200, "hists/antitau_pt.root", "Antitau pT"}},
    {"truth antitau eta", {40, -4, 4, "hists/antitau_eta.root", "Antitau eta"}},
    {"truth antitau phi", {40, -3.14, 3.14, "hists/antitau_phi.root", "Antitau phi"}},
    {"truth antitau E", {40, 0, 1500, "hists/antitau_E.root", "Antitau E"}},

    {"tau charged pion pt", {40, 0, 50, "hists/tau_ch_pion_pt.root", "Tau charged pion pT"}},
    {"tau charged pion eta", {40, -4, 4, "hists/tau_ch_pion_eta.root", "Tau charged pion eta"}},
    {"tau charged pion phi", {40, -3.14, 3.14, "hists/tau_ch_pion_phi.root", "Tau charged pion phi"}},
    {"tau charged pion E", {40, 0, 1500, "hists/tau_ch_pion_E.root", "Tau charged pion E"}},

    {"antitau charged pion pt", {40, 0, 50, "hists/antitau_ch_pion_pt.root", "Antitau charged pion pT"}},
    {"antitau charged pion eta", {40, -4, 4, "hists/antitau_ch_pion_eta.root", "Antitau charged pion eta"}},
    {"antitau charged pion phi", {40, -3.14, 3.14, "hists/antitau_ch_pion_phi.root", "Antitau charged pion phi"}},
    {"antitau charged pion E", {40, 0, 1500, "hists/antitau_ch_pion_E.root", "Antitau charged pion E"}},

    {"tau neutral pion pt", {40, 0, 50, "hists/tau_neut_pion_pt.root", "Tau neutral pion pT"}},
    {"tau neutral pion eta", {40, -4, 4, "hists/tau_ch_pion_eta.root", "Tau neutral pion eta"}},
    {"tau neutral pion phi", {40, -3.14, 3.14, "hists/tau_ch_pion_phi.root", "Tau neutral pion phi"}},
    {"tau neutral pion E", {40, 0, 1500, "hists/tau_ch_pion_E.root", "Tau neutral pion E"}},

    {"antitau neutral pion pt", {40, 0, 50, "hists/antitau_neut_pion_pt.root", "Antitau neutral pion pT"}},
    {"antitau neutral pion eta", {40, -4, 4, "hists/antitau_ch_pion_eta.root", "Antitau neutral pion eta"}},
    {"antitau neutral pion phi", {40, -3.14, 3.14, "hists/antitau_ch_pion_phi.root", "Antitau neutral pion phi"}},
    {"antitau neutral pion E", {40, 0, 1500, "hists/antitau_ch_pion_E.root", "Antitau neutral pion E"}},

    {"upsilon minus", {40, 0, 1, "hists/upsilon_minus.root", "Upsilon Minus"}},
    {"upsilon plus", {40, 0, 1, "hists/upsilon_plus.root", "Upsilon Plus"}},

    {"upsilon minus higgs", {40, -1, 1, "hists/upsilon_minus_higgs.root", "Upsilon Minus"}},
    {"upsilon plus higgs", {40, -1, 1, "hists/upsilon_plus_higgs.root", "Upsilon Plus"}},

};

const std::vector<std::string> ALL_OUTPUTS = {
    "psi truth",
    "psi truth bump",
    "psi diff",
    "psi truth true boost", 
    "psi truth true boost rho plane",
    
    "psi YP low YM low",
    "psi YP low YM high",
    "psi YP high YM low",
    "psi YP high YM high",

    "Z pT vis", 
    "Z eta vis", 
    "Z phi vis", 

    "Z pT real",
    "Z eta real",
    "Z phi real",
    "Z E real",

    "psi low Z pT",
    "psi med Z pT",
    "psi high Z pT",

    "psi bump low Z pT",
    "psi bump med Z pT",
    "psi bump high Z pT",

    "psi true boost low Z pT",
    "psi true boost med Z pT",
    "psi true boost high Z pT",

    "truth tau pt",
    "truth antitau pt",

    "tau charged pion pt",
    "tau charged pion eta",
    "tau charged pion phi",
    "tau charged pion E",

    "antitau charged pion pt",
    "antitau charged pion eta",
    "antitau charged pion phi",
    "antitau charged pion E",

    "tau neutral pion pt",
    "tau neutral pion eta",
    "tau neutral pion phi",
    "tau neutral pion E",

    "antitau neutral pion pt",
    "antitau neutral pion eta",
    "antitau neutral pion phi",
    "antitau neutral pion E",

    "upsilon minus",
    "upsilon plus",

    "upsilon minus higgs",
    "upsilon plus higgs",
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

    "plus_bump_px",
    "plus_bump_py",
    "plus_bump_pz",

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

const std::vector<std::string> ALL_INPUTS_VEC_INT = {
    
    // Variables formatted as vectors of integers

    "boson_ID",
};

