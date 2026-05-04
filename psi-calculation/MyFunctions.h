#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

float hadhadTruthPsi(
                TLorentzVector tau0_ch,  
                TLorentzVector tau1_ch,  
                TLorentzVector tau0_neut,   
                TLorentzVector tau1_neut);

const TLorentzVector COM_vis(
                TLorentzVector tau0_ch,  
                TLorentzVector tau1_ch,  
                TLorentzVector tau0_neut,   
                TLorentzVector tau1_neut);

const TLorentzVector COM_real(
                float tau_pt, 
                float tau_eta,
                float tau_phi,
                float tau_E,
                float antitau_pt,
                float antitau_eta,
                float antitau_phi,
                float antitau_E);

#endif
