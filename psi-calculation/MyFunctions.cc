// standard libraries
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

#include "MyFunctions.h"

float TruthPsiHadHad(
                float tau_ch_pt,  // tau charged pion
                float tau_ch_eta,
                float tau_ch_phi,
                float tau_ch_E,

                float antitau_ch_pt,  // anti-tau charged pion
                float antitau_ch_eta,
                float antitau_ch_phi,
                float antitau_ch_E,

                float tau_n_pt,  // tau neutral pion
                float tau_n_eta,
                float tau_n_phi,
                float tau_n_E,

                float antitau_n_pt,  // anti-tau neutral pion
                float antitau_n_eta,
                float antitau_n_phi,
                float antitau_n_E
                ){

    TLorentzVector tau_char_pion;
    TLorentzVector antitau_char_pion;
    TLorentzVector tau_neut_pion;
    TLorentzVector antitau_neut_pion;

    tau_char_pion.SetPtEtaPhiE(tau_ch_pt, tau_ch_eta, tau_ch_phi, tau_ch_E);
    antitau_char_pion.SetPtEtaPhiE(antitau_ch_pt, antitau_ch_eta, antitau_ch_phi, antitau_ch_E);
    tau_neut_pion.SetPtEtaPhiE(tau_n_pt, tau_n_eta, tau_n_phi, tau_n_E);
    antitau_neut_pion.SetPtEtaPhiE(antitau_n_pt, antitau_n_eta, antitau_n_phi, antitau_n_E);

    const TLorentzVector COM = tau_char_pion + antitau_char_pion + tau_neut_pion + antitau_neut_pion;

    const double upsilon0 = tau_char_pion.E()/(tau_char_pion+tau_neut_pion).E();
    const double upsilon1 = antitau_char_pion.E()/(antitau_char_pion+antitau_neut_pion).E();

    // compute_psi_hh_basic

    TLorentzVector beam;
    beam.SetPxPyPzE(0., 0., 6.5e6, 6.5e6);
    
    const TVector3 boostVector = COM.BoostVector();

    tau_char_pion.Boost((-1.)*boostVector);
    antitau_char_pion.Boost((-1.)*boostVector);
    beam.Boost((-1.)*boostVector); 

    // rotate system and obtain psi
    
    double phi_tau_char_pion = tau_char_pion.Phi();
    double theta_tau_char_pion = tau_char_pion.Theta();

    tau_char_pion.RotateZ((-1.0) * phi_tau_char_pion);
    tau_char_pion.RotateY((-1.0) * theta_tau_char_pion);

    antitau_char_pion.RotateZ((-1.0) * phi_tau_char_pion);
    antitau_char_pion.RotateY((-1.0) * theta_tau_char_pion);

    beam.RotateZ((-1.0) * phi_tau_char_pion);
    beam.RotateY((-1.0) * theta_tau_char_pion);
    beam.RotateZ((-1.0) * antitau_char_pion.Phi());

    tau_char_pion.RotateZ((-1.0) * antitau_char_pion.Phi());
    antitau_char_pion.RotateZ((-1.0) * antitau_char_pion.Phi());

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

const TLorentzVector ZedVis(
                float tau_ch_pt,  // tau charged pion
                float tau_ch_eta,
                float tau_ch_phi,
                float tau_ch_E,

                float antitau_ch_pt,  // anti-tau charged pion
                float antitau_ch_eta,
                float antitau_ch_phi,
                float antitau_ch_E,

                float tau_n_pt,  // tau neutral pion
                float tau_n_eta,
                float tau_n_phi,
                float tau_n_E,

                float antitau_n_pt,  // anti-tau neutral pion
                float antitau_n_eta,
                float antitau_n_phi,
                float antitau_n_E
                ){

    TLorentzVector tau_char_pion;
    TLorentzVector antitau_char_pion;
    TLorentzVector tau_neut_pion;
    TLorentzVector antitau_neut_pion;

    tau_char_pion.SetPtEtaPhiE(tau_ch_pt, tau_ch_eta, tau_ch_phi, tau_ch_E);
    antitau_char_pion.SetPtEtaPhiE(antitau_ch_pt, antitau_ch_eta, antitau_ch_phi, antitau_ch_E);
    tau_neut_pion.SetPtEtaPhiE(tau_n_pt, tau_n_eta, tau_n_phi, tau_n_E);
    antitau_neut_pion.SetPtEtaPhiE(antitau_n_pt, antitau_n_eta, antitau_n_phi, antitau_n_E);

    const TLorentzVector z_vis = tau_char_pion + antitau_char_pion + tau_neut_pion + antitau_neut_pion;

    return z_vis;

}

const TLorentzVector ZedReal(
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

    const TLorentzVector z_real = tau_p4 + antitau_p4;

    return z_real;

}