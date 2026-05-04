// standard libraries
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

#include "MyFunctions.h"

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