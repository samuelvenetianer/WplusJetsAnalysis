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

    TLorentzVector rhoPlus_tlv = antitau_char_pion + antitau_neut_pion;
    TLorentzVector rhoMinus_tlv = tau_char_pion + tau_neut_pion;

    const TLorentzVector frame_tlv = rhoPlus_tlv + rhoMinus_tlv;

    const double upsilon_minus = tau_char_pion.E()/(tau_char_pion.E()+tau_neut_pion.E());
    const double upsilon_plus = antitau_char_pion.E()/(antitau_char_pion.E()+antitau_neut_pion.E());

    // compute_psi_hh_basic

    TLorentzVector beam;
    beam.SetPxPyPzE(0., 0., 6.5e6, 6.5e6);
    
    const TVector3 boostVector = frame_tlv.BoostVector();
        
    TVector3 my_boost;
    my_boost.SetXYZ(-1.0*frame_tlv.Beta()*frame_tlv.Px()/frame_tlv.P(),
                    -1.0*frame_tlv.Beta()*frame_tlv.Py()/frame_tlv.P(),
                    -1.0*frame_tlv.Beta()*frame_tlv.Pz()/frame_tlv.P());

    // std::cout << "boostVector (X,Y,Z): " <<  boostVector.X() << ", " << boostVector.Y() << ", " << boostVector.Z() << std::endl;
    // std::cout << "my_boost (X,Y,Z): " <<  my_boost.X() << ", " << my_boost.Y() << ", " << my_boost.Z() << std::endl;
    
    // Boost piPlus and piMinus
    antitau_char_pion.Boost(my_boost);
    tau_char_pion.Boost(my_boost);

    // Rotate beam and piPlus with angles of piMinus
    beam.RotateZ((-1.0)*tau_char_pion.Phi());
    beam.RotateY((-1.0)*tau_char_pion.Theta());
    antitau_char_pion.RotateZ((-1.0)*tau_char_pion.Phi());
    antitau_char_pion.RotateY((-1.0)*tau_char_pion.Theta());

    // Rotate beam with angle of piPlus
    beam.RotateZ((-1.0)*antitau_char_pion.Phi());

    // Calculate psi
    float psi = beam.Phi();

    // std::cout << "Psi before phase shift: " << psi << "\n" << std::endl;

    // perform phase shift if necessary
    if ((upsilon_plus-0.5)*(upsilon_minus-0.5)<0){
        psi += M_PI/2;
    }
    if (psi > M_PI){
        psi = psi-2.0*M_PI;
    }

    return psi;

}

float TruthPsiHadHadTrueBoost(
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
                float antitau_n_E,

                float tau_nu_pt,    // neutrino coming from tau
                float tau_nu_eta,
                float tau_nu_phi,
                float tau_nu_E,

                float antitau_nu_pt,    // neutrino coming from antitau
                float antitau_nu_eta,
                float antitau_nu_phi,
                float antitau_nu_E,

                float boson_pt,
                float boson_eta,
                float boson_phi,
                float boson_E,

                float tau_pt,
                float tau_eta,
                float tau_phi,
                float tau_E,

                float antitau_pt,
                float antitau_eta,
                float antitau_phi,
                float antitau_E
                ){

    TLorentzVector tau_char_pion;
    TLorentzVector antitau_char_pion;
    TLorentzVector tau_neut_pion;
    TLorentzVector antitau_neut_pion;
    TLorentzVector tau_neutrino;
    TLorentzVector antitau_neutrino;

    TLorentzVector boson_p4;
    TLorentzVector tau_p4;
    TLorentzVector antitau_p4;

    tau_char_pion.SetPtEtaPhiE(tau_ch_pt, tau_ch_eta, tau_ch_phi, tau_ch_E);
    antitau_char_pion.SetPtEtaPhiE(antitau_ch_pt, antitau_ch_eta, antitau_ch_phi, antitau_ch_E);
    tau_neut_pion.SetPtEtaPhiE(tau_n_pt, tau_n_eta, tau_n_phi, tau_n_E);
    antitau_neut_pion.SetPtEtaPhiE(antitau_n_pt, antitau_n_eta, antitau_n_phi, antitau_n_E);

    tau_neutrino.SetPtEtaPhiE(tau_nu_pt, tau_nu_eta, tau_nu_phi, tau_nu_E);
    antitau_neutrino.SetPtEtaPhiE(antitau_nu_pt, antitau_nu_eta, antitau_nu_phi, antitau_nu_E);

    boson_p4.SetPtEtaPhiE(boson_pt, boson_eta, boson_phi, boson_E);
    tau_p4.SetPtEtaPhiE(tau_pt, tau_eta, tau_phi, tau_E);
    antitau_p4.SetPtEtaPhiE(antitau_pt, antitau_eta, antitau_phi, antitau_E);

    TLorentzVector rhoPlus_tlv = antitau_char_pion + antitau_neut_pion;
    TLorentzVector rhoMinus_tlv = tau_char_pion + tau_neut_pion;

    // Frame for psi calc
    const TLorentzVector frame_tlv = tau_p4 + antitau_p4;
    
    // create tau rest frame boostvector
    TVector3 my_tau_boost;
    my_tau_boost.SetXYZ(-1.0*tau_p4.Beta()*tau_p4.Px()/tau_p4.P(),
                    -1.0*tau_p4.Beta()*tau_p4.Py()/tau_p4.P(),
                    -1.0*tau_p4.Beta()*tau_p4.Pz()/tau_p4.P());

    // create antitau rest frame boostvector
    TVector3 my_antitau_boost;
    my_antitau_boost.SetXYZ(-1.0*antitau_p4.Beta()*antitau_p4.Px()/antitau_p4.P(),
                    -1.0*antitau_p4.Beta()*antitau_p4.Py()/antitau_p4.P(),
                    -1.0*antitau_p4.Beta()*antitau_p4.Pz()/antitau_p4.P());

    // boost pions into respective tau restframes for upsilon calc
    TLorentzVector boosted_t_neutpion = tau_neut_pion;
    TLorentzVector boosted_at_neutpion = antitau_neut_pion;
    TLorentzVector boosted_t_charpion = tau_char_pion;
    TLorentzVector boosted_at_charpion = antitau_char_pion;
    
    boosted_t_neutpion.Boost(my_tau_boost);
    boosted_at_neutpion.Boost(my_antitau_boost);
    boosted_t_charpion.Boost(my_tau_boost);
    boosted_at_charpion.Boost(my_antitau_boost);

    // Calc upsilon after boosting into tautau frame
    const double upsilon_minus = boosted_t_charpion.E()/(boosted_t_charpion.E()+boosted_t_neutpion.E());
    const double upsilon_plus = boosted_at_charpion.E()/(boosted_at_charpion.E()+boosted_at_neutpion.E());
    
    // Calc upsilon using definition from higgs powerpoint
    // const double upsilon_minus = (boosted_t_charpion.E()-boosted_t_neutpion.E())/(boosted_t_charpion.E()+boosted_t_neutpion.E());
    // const double upsilon_plus = (boosted_at_charpion.E()-boosted_at_neutpion.E())/(boosted_at_charpion.E()+boosted_at_neutpion.E());

    // compute_psi_hh_basic

    TLorentzVector beam;
    beam.SetPxPyPzE(0., 0., 6.5e6, 6.5e6);
    
    // const TVector3 boostVector = frame_tlv.BoostVector();
        
    TVector3 my_boost;
    my_boost.SetXYZ(-1.0*frame_tlv.Beta()*frame_tlv.Px()/frame_tlv.P(),
                    -1.0*frame_tlv.Beta()*frame_tlv.Py()/frame_tlv.P(),
                    -1.0*frame_tlv.Beta()*frame_tlv.Pz()/frame_tlv.P());

    // std::cout << "boostVector (X,Y,Z): " <<  boostVector.X() << ", " << boostVector.Y() << ", " << boostVector.Z() << std::endl;
    // std::cout << "my_boost (X,Y,Z): " <<  my_boost.X() << ", " << my_boost.Y() << ", " << my_boost.Z() << std::endl;
    
    // Boost piPlus and piMinus
    antitau_char_pion.Boost(my_boost);
    tau_char_pion.Boost(my_boost);

    // Rotate beam and piPlus with angles of piMinus
    beam.RotateZ((-1.0)*tau_char_pion.Phi());
    beam.RotateY((-1.0)*tau_char_pion.Theta());
    antitau_char_pion.RotateZ((-1.0)*tau_char_pion.Phi());
    antitau_char_pion.RotateY((-1.0)*tau_char_pion.Theta());

    // Rotate beam with angle of piPlus
    beam.RotateZ((-1.0)*antitau_char_pion.Phi());

    // Calculate psi
    float psi = beam.Phi();

    // std::cout << "Psi before phase shift: " << psi << "\n" << std::endl;

    // perform phase shift if necessary
    if ((upsilon_plus-0.5)*(upsilon_minus-0.5)<0){
        psi += M_PI/2;
    }
    if (psi > M_PI){
        psi = psi-2.0*M_PI;
    }

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