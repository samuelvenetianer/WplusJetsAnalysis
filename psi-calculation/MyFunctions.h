#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

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
                );

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
                );

float TruthPsiHadHadTrueBoostRhoPlane(
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
                );

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
                );

float Upsilon(
                float tau_ch_pt,  // tau charged pion
                float tau_ch_eta,
                float tau_ch_phi,
                float tau_ch_E,

                float tau_n_pt,  // tau neutral pion
                float tau_n_eta,
                float tau_n_phi,
                float tau_n_E
                );

float UpsilonHiggs(
                float tau_ch_pt,  // tau charged pion
                float tau_ch_eta,
                float tau_ch_phi,
                float tau_ch_E,

                float tau_n_pt,  // tau neutral pion
                float tau_n_eta,
                float tau_n_phi,
                float tau_n_E
                );

#endif
