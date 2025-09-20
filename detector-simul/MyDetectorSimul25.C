
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>
#include "TH1F.h"
#include "TDirectory.h"
#include "TTree.h"
#include "TString.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "TTreeReaderArray.h"
#include <vector>
#include <vector>
#include <math.h>
#include <dirent.h>

// Controls input directory:
string inpath = "../pythia-outputs/2025/";

int DetectorEffects(string sample)
{

    // Load and read the output files from Pythia
    //===========================================

    // Path to input and output root files
    string fileIn = inpath + sample;
    string fileOut = "$PWD/reconstructed/" + sample;

    // print output file name & path
    std::cout << "Output file name: " << fileOut << std::endl;

    // first load all the variables we will use from the original pythia output file
    TString treeName = "ParticleTree";
    TChain *cc_tree = new TChain(treeName);
    cc_tree->Add(fileIn.c_str());
    TTreeReader treeReader(cc_tree);

    // init number of entries and percentage processed
    Int_t nentries = Int_t(cc_tree->GetEntries());
    int ientry = 0;
    double percent = 0;

    // Load truth variables
        std::string branch_name;
        if (treeReader.GetTree()->GetBranch("event_weights")) 
        {
            branch_name = "event_weights";
        }    
        
        // Use the detected branch name
        TTreeReaderArray<double> event_weights_1(treeReader, branch_name.c_str());
        
        TTreeReaderValue<int> nNeutrino_1(treeReader, "nNeutrino");
        TTreeReaderValue<int> nElectronBare_1(treeReader, "nElectronBare");
        TTreeReaderValue<int> nMuonBare_1(treeReader, "nMuonBare");
        TTreeReaderValue<int> nLightjetBare_1(treeReader, "nLightjetBare");
        TTreeReaderValue<int> nBoson_1(treeReader, "nBoson");
        TTreeReaderValue<double> Met_1(treeReader, "Met");
        TTreeReaderValue<double> Met_phi_1(treeReader, "Met_phi");

        TTreeReaderArray<int> boson_ID_1(treeReader, "boson_ID");
        TTreeReaderArray<int> neutrino_PdgId_1(treeReader, "neutrino_PdgId");
        TTreeReaderArray<int> lightjet_bare_nPart_1(treeReader, "lightjet_bare_nPart");

        TTreeReaderArray<float> neutrino_pt_1(treeReader, "neutrino_pt");
        TTreeReaderArray<float> neutrino_eta_1(treeReader, "neutrino_eta");
        TTreeReaderArray<float> neutrino_phi_1(treeReader, "neutrino_phi");
        TTreeReaderArray<float> neutrino_E_1(treeReader, "neutrino_E");
        TTreeReaderArray<float> electron_bare_pt_1(treeReader, "electron_bare_pt");
        TTreeReaderArray<float> electron_bare_eta_1(treeReader, "electron_bare_eta");
        TTreeReaderArray<float> electron_bare_phi_1(treeReader, "electron_bare_phi");
        TTreeReaderArray<float> electron_bare_E_1(treeReader, "electron_bare_E");
        TTreeReaderArray<float> electron_bare_charge_1(treeReader, "electron_bare_charge");
        TTreeReaderArray<float> muon_bare_pt_1(treeReader, "muon_bare_pt");
        TTreeReaderArray<float> muon_bare_eta_1(treeReader, "muon_bare_eta");
        TTreeReaderArray<float> muon_bare_phi_1(treeReader, "muon_bare_phi");
        TTreeReaderArray<float> muon_bare_E_1(treeReader, "muon_bare_E");
        TTreeReaderArray<float> muon_bare_charge_1(treeReader, "muon_bare_charge");
        TTreeReaderArray<float> lightjet_bare_pt_1(treeReader, "lightjet_bare_pt");
        TTreeReaderArray<float> lightjet_bare_eta_1(treeReader, "lightjet_bare_eta");
        TTreeReaderArray<float> lightjet_bare_phi_1(treeReader, "lightjet_bare_phi");
        TTreeReaderArray<float> lightjet_bare_E_1(treeReader, "lightjet_bare_E");
        TTreeReaderArray<float> boson_pt_1(treeReader, "boson_pt");
        TTreeReaderArray<float> boson_eta_1(treeReader, "boson_eta");
        TTreeReaderArray<float> boson_phi_1(treeReader, "boson_phi");
        TTreeReaderArray<float> boson_E_1(treeReader, "boson_E");

    // End truth variables

    // Now build the new ntuple

    // Create new file for new ntuple with detector effects
    TFile *output = TFile::Open(fileOut.c_str(), "recreate");
    // Define tree
    TTree *tree = new TTree("ParticleTree", "ParticleTree");

    // initiate variables to copy truth values
    std::vector<double> event_weights;
    int nNeutrino, nElectronBare, nMuonBare, nLightjetBare, nBoson;
    double Met, Met_phi;
    std::vector<float> neutrino_pt, neutrino_eta, neutrino_phi, neutrino_E;
    std::vector<float> electron_bare_pt, electron_bare_eta, electron_bare_phi, electron_bare_E, electron_bare_charge;
    std::vector<float> muon_bare_pt, muon_bare_eta, muon_bare_phi, muon_bare_E, muon_bare_charge;
    std::vector<float> lightjet_bare_pt, lightjet_bare_eta, lightjet_bare_phi, lightjet_bare_E;
    std::vector<int> boson_ID, neutrino_PdgId, lightjet_bare_nPart;
    std::vector<float> boson_pt, boson_eta, boson_phi, boson_E;

    // truth branches
    tree->Branch("event_weights",&event_weights);

    tree->Branch("nNeutrino",&nNeutrino);
    tree->Branch("nElectronBare",&nElectronBare);
    tree->Branch("nMuonBare",&nMuonBare);
    tree->Branch("nLightjetBare",&nLightjetBare);
    tree->Branch("nBoson",&nBoson);
    tree->Branch("Met",&Met);
    tree->Branch("Met_phi",&Met_phi);

    tree->Branch("neutrino_pt",&neutrino_pt);
    tree->Branch("neutrino_eta",&neutrino_eta);
    tree->Branch("neutrino_phi",&neutrino_phi);
    tree->Branch("neutrino_E",&neutrino_E);
    tree->Branch("neutrino_PdgId",&neutrino_PdgId);

    tree->Branch("electron_bare_pt",&electron_bare_pt);
    tree->Branch("electron_bare_eta",&electron_bare_eta);
    tree->Branch("electron_bare_phi",&electron_bare_phi);
    tree->Branch("electron_bare_E",&electron_bare_E);
    tree->Branch("electron_bare_charge",&electron_bare_charge);

    // BSJ
    tree->Branch("muon_bare_pt",&muon_bare_pt);
    tree->Branch("muon_bare_eta",&muon_bare_eta);
    tree->Branch("muon_bare_phi",&muon_bare_phi);
    tree->Branch("muon_bare_E",&muon_bare_E);
    tree->Branch("muon_bare_charge",&muon_bare_charge);

    tree->Branch("lightjet_bare_pt",&lightjet_bare_pt);
    tree->Branch("lightjet_bare_eta",&lightjet_bare_eta);
    tree->Branch("lightjet_bare_phi",&lightjet_bare_phi);
    tree->Branch("lightjet_bare_E",&lightjet_bare_E);
    tree->Branch("lightjet_bare_nPart",&lightjet_bare_nPart);

    tree->Branch("boson_ID",&boson_ID);
    tree->Branch("boson_pt",&boson_pt);
    tree->Branch("boson_eta",&boson_eta);
    tree->Branch("boson_phi",&boson_phi);
    tree->Branch("boson_E",&boson_E);

    // initiate variables for the new detector effects
    double RecoMet, RecoMet_phi;
    int nMuonReco, nElectronReco, nJetReco;
    std::vector<float> electron_reco_pt, electron_reco_eta, electron_reco_phi, electron_reco_E, electron_reco_charge;
    std::vector<float> muon_reco_pt, muon_reco_eta, muon_reco_phi, muon_reco_E, muon_reco_charge;
    std::vector<float> jet_reco_pt, jet_reco_eta, jet_reco_phi, jet_reco_E;
    std::vector<float> jet_reco_pt_map, jet_reco_eta_map, jet_reco_phi_map, jet_reco_E_map;

    // reco branches
    tree->Branch("electron_reco_pt",&electron_reco_pt);
    tree->Branch("electron_reco_eta",&electron_reco_eta);
    tree->Branch("electron_reco_phi",&electron_reco_phi);
    tree->Branch("electron_reco_E",&electron_reco_E);
    tree->Branch("electron_reco_charge",&electron_reco_charge);

    // BSJ
    tree->Branch("muon_reco_pt",&muon_reco_pt);
    tree->Branch("muon_reco_eta",&muon_reco_eta);
    tree->Branch("muon_reco_phi",&muon_reco_phi);
    tree->Branch("muon_reco_E",&muon_reco_E);
    tree->Branch("muon_reco_charge",&muon_reco_charge);

    tree->Branch("jet_reco_pt",&jet_reco_pt);
    tree->Branch("jet_reco_eta",&jet_reco_eta);
    tree->Branch("jet_reco_phi",&jet_reco_phi);
    tree->Branch("jet_reco_E",&jet_reco_E);

    tree->Branch("nMuonReco",&nMuonReco);
    tree->Branch("nElectronReco",&nElectronReco);
    tree->Branch("nJetReco",&nJetReco);
    tree->Branch("RecoMet",&RecoMet);
    tree->Branch("RecoMet_phi",&RecoMet_phi);

    tree->Branch("jet_reco_pt_map",&jet_reco_pt_map);
    tree->Branch("jet_reco_eta_map",&jet_reco_eta_map);
    tree->Branch("jet_reco_phi_map",&jet_reco_phi_map);
    tree->Branch("jet_reco_E_map",&jet_reco_E_map);

    


    // Control parameter
    bool dosystematics = false;
    int systnum = 0;
    bool electronChannel = true;
    bool muonChannel =  false;


    // Loop over the events to run analysis on the ntuple
    // ==================================================

    while(treeReader.Next())
    {

        // print percentage processed
        ientry++;
        if ((20 * ientry) / nentries >= percent)
        {
            cout << "Processed: " << percent * 5 << "%" << endl;
            percent = (20 * ientry) / nentries + 1;
        }
        

        // Reweight the event if needed
        double wgt = 1.0;
        if (dosystematics) wgt = event_weights_1[systnum];


        // Copy truth values
        nNeutrino = *nNeutrino_1;
        nElectronBare = *nElectronBare_1;
        nMuonBare = *nMuonBare_1;
        nLightjetBare = *nLightjetBare_1;
        nBoson = *nBoson_1;
        Met = *Met_1;
        Met_phi = *Met_phi_1;

        // Copy truth vectors
        for (int i = 0; i < event_weights_1.GetSize(); i++)
        {
            event_weights.push_back(event_weights_1[i]);
        }

        for (int i = 0; i < boson_ID_1.GetSize(); i++)
        {
            boson_ID.push_back(boson_ID_1[i]);
            boson_pt.push_back(boson_pt_1[i]);
            boson_eta.push_back(boson_eta_1[i]);
            boson_phi.push_back(boson_phi_1[i]);
            boson_E.push_back(boson_E_1[i]);
        }
        for (int i = 0; i < neutrino_pt_1.GetSize(); i++)
        {
            neutrino_pt.push_back(neutrino_pt_1[i]);
            neutrino_eta.push_back(neutrino_eta_1[i]);
            neutrino_phi.push_back(neutrino_phi_1[i]);
            neutrino_E.push_back(neutrino_E_1[i]);
            neutrino_PdgId.push_back(neutrino_PdgId_1[i]);
        }
        for (int i = 0; i < electron_bare_pt_1.GetSize(); i++)
        {
            electron_bare_pt.push_back(electron_bare_pt_1[i]);
            electron_bare_eta.push_back(electron_bare_eta_1[i]);
            electron_bare_phi.push_back(electron_bare_phi_1[i]);
            electron_bare_E.push_back(electron_bare_E_1[i]);
            electron_bare_charge.push_back(electron_bare_charge_1[i]);
        }
        //BSJ
        for (int i = 0; i < muon_bare_pt_1.GetSize(); i++)
        {
            muon_bare_pt.push_back(muon_bare_pt_1[i]);
            muon_bare_eta.push_back(muon_bare_eta_1[i]);
            muon_bare_phi.push_back(muon_bare_phi_1[i]);
            muon_bare_E.push_back(muon_bare_E_1[i]);
            muon_bare_charge.push_back(muon_bare_charge_1[i]);
        }
        for (int i = 0; i < lightjet_bare_pt_1.GetSize(); i++)
        {
            lightjet_bare_pt.push_back(lightjet_bare_pt_1[i]);
            lightjet_bare_eta.push_back(lightjet_bare_eta_1[i]);
            lightjet_bare_phi.push_back(lightjet_bare_phi_1[i]);
            lightjet_bare_E.push_back(lightjet_bare_E_1[i]);
            lightjet_bare_nPart.push_back(lightjet_bare_nPart_1[i]);
        }

        

        // Define variables for reco MET calculation
        float RecoSqSum;
        float RecoSum_x=0;
        float RecoSum_y=0;
        for (int i = 0; i < neutrino_pt.size(); i++)
        {
            // Fetch truth information
            double NeutrinoTrueE = neutrino_E[i];
            double NeutrinoTrueEta = neutrino_eta[i];
            double NeutrinoTruePhi = neutrino_phi[i];
            double NeutrinoTruePt = neutrino_pt[i];

            TLorentzVector trueNeu;
            trueNeu.SetPtEtaPhiE(NeutrinoTruePt,NeutrinoTrueEta,NeutrinoTruePhi,NeutrinoTrueE);
            RecoSum_x += trueNeu.Px();
            RecoSum_y += trueNeu.Py();
        }



        // Reco jets
        // .........

            // Note 1: The momentum of each jet is shifted and smeared following 
            //         ATLAS calibration and resolution functions. Angles are smeared too 
            //         but the effect is small because the angular resolution effects are
            //         proportional to the detector fined granularity (multiple scattering
            //         have little effects on jets). We assume that there is no angular shifts
            //         (neglect inter-calorimeter effects) i.e. that we smear eta and phi with 
            //         a Gaussian each centered on 0. In principle a calorimeter cell  
            //         measurement is an energy measurement, so we should be smearing the 
            //         energy and the pseudo-rapidity and then calculate the transverse 
            //         momentum from this smeared energy with pT = E/cosh(eta). However, 
            //         experiments precisely and carefully measure the jet transverse 
            //         momentum resolution expressed as: sigma/pt = N/pt circ+ S/sqrt(pt) circ+ C
            //         where N is the noise term, S the stochastic term, C the constant term
            //         including non-scaling effects like material in front of the calorimeter,
            //         and "circ+" means that the quadratic sum is used. We therefore use this 
            //         smearing using however only the resolution measurement results obtained
            //         for central R=0.4 EM+JES jets (0<|eta|<0.8) for simplicity.  

            // Note 2: Smearing resolution factors are obtained from the ATLAS 8 TeV Jet 
            //         performance paper: https://arxiv.org/pdf/1910.04482.pdf:
            //
            //           eta, phi: approximate quadratic fit to fig 2. a (eta), and b (phi)
            //           pt: N=3.33 GeV, S=0.71 GeV^0.5 and C=0.03

            // Note 3: No efficiency factor is considered because we'll deal only with jets Pt?30 GeV
            //         which are almost fully efficient. 

            // Note 4: For the Reco Met, we start by adding the true jet Px and Py. That will balance
            //         out part of the neutrino, but after calculating all the reco quantities, we 
            //         subtract from the sum, the reco Px and Py. That will restore the Met. If there
            //         no resolution effect on the jet, the Met will be the same as the true, plus the
            //         particles that are not detected (efficiency, acceptance). For example, if a jet
            //         is lost, the truee jet would have been added to the Reco Met, but the reco jet 
            //         would not be subtracted, so that jet would contribute to Reco Met. Note that only
            //         the fiducial part of the acceptance is not removed from Reco Met, which means that
            //         if a jet is not reconstructed because it is too low in Pt, it neverthess leaves
            //         measurable energy in the detector, which is therefore not Met. Resolution is 
            //         properly accounted for this way. 

            // Note 5: Reco jets, because of migration, are not anymore sorted from the highest pt to the
            //         lowest. To this end, reco jets are temporarily stored in a vector TLorentzVector, 
            //         which are then sorted in decreasing pt order, before each quantities get pushed
            //         in their respective vectors. At the end, vectors of reco energy, pt, eta, and phi
            //         will have matching indices sorted in decending pt.       
        
        float jetcut = 30.; // jet pT cut

        vector<TLorentzVector> tempJetRecoContainer;

        nJetReco  = 0;
        for (int i_tjet = 0; i_tjet < lightjet_bare_E.size(); i_tjet++)
        {

            // Fetch truth information
            double JetTrueE = lightjet_bare_E[i_tjet];
            double JetTrueEta = lightjet_bare_eta[i_tjet];
            double JetTruePhi = lightjet_bare_phi[i_tjet];
            double JetTruePt = lightjet_bare_pt[i_tjet];

            TLorentzVector trueJet;
            trueJet.SetPtEtaPhiE(JetTruePt,JetTrueEta,JetTruePhi,JetTrueE);
            double truePx = trueJet.Px();
            double truePy = trueJet.Py();

            // Add truth particle to the Reco Met (reco will be remove later)
            RecoSum_y += truePy;
            RecoSum_x += truePx;

            // Calculate pt-dependent resolution and calibration parameters
            double eta_resol = 0.000000056*JetTruePt*JetTruePt - 0.000112*JetTruePt + 0.06;
            double phi_resol = 0.000000084*JetTruePt*JetTruePt - 0.000168*JetTruePt + 0.09;
            double pt_resol = JetTruePt*sqrt(11.09/(JetTruePt*JetTruePt)+0.504/JetTruePt+0.0009);
            
            // set a calibration offset?
            double pt_calib = JetTruePt;
            // double pt_calib = JetTruePt*(0.00639*sqrt(JetTruePt - 20.) + 0.6);


            // Calculate detector distorted quantities
            double recoEta = gRandom->Gaus(JetTrueEta,eta_resol);
            double recoPhi = gRandom->Gaus(JetTruePhi,phi_resol);
            if (recoPhi < 0.) recoPhi += 6.283185307;
            else if (recoPhi > 6.283185307) recoPhi = recoPhi - 6.283185307;
            double recoPt  = gRandom->Gaus(pt_calib,pt_resol);
            double recoE = recoPt*cosh(recoEta);

            // For mapping of truth -> reco jets
            // -------------------------------------
            // Store -999 values for bad jets, don't want to get rid of them yet
            // because we need to keep them matched between truth and reco

            // Remove non-fiducial jets
            if (fabs(recoEta) > 4.5) recoEta = -999;
            
            // Don't store too low Pt jets
            if (recoPt<5.) recoPt = -999;

            // Remove NaN's and infinities
            if (recoPt != recoPt) recoPt = -999;
            if (recoE != recoE) recoE = -999;
            if (recoEta != recoEta) recoEta = -999;
            if (recoPhi != recoPhi) recoPhi = -999;

            // Store values including -999's into branch
            jet_reco_pt_map.push_back(recoPt);
            jet_reco_E_map.push_back(recoE);
            jet_reco_eta_map.push_back(recoEta);
            jet_reco_phi_map.push_back(recoPhi);

            // For usable dist of reco jets
            // ----------------------------

            // skip bad jets before constructing jet and adding to regular container
            if (fabs(recoEta) > 4.5 || recoPt<5. || recoE==-999 || recoPhi==-999) continue;

            TLorentzVector recoJet;
            recoJet.SetPtEtaPhiE(recoPt,recoEta,recoPhi,recoE);
            double recoPx = recoJet.Px();
            double recoPy = recoJet.Py();

            // Calculate reco impact on Met
            RecoSum_y += (-1)*recoPy;
            RecoSum_x += (-1)*recoPx;

            // Fill tempJetRecoContainer (to sort by pT later)
            tempJetRecoContainer.push_back(recoJet);
            if (recoPt>jetcut) nJetReco++;

        }
        

        // Sort reco jets in descending pt
        std::sort(tempJetRecoContainer.begin(), tempJetRecoContainer.end(), 
            [](TLorentzVector x, TLorentzVector y) { return x.Pt() > y.Pt(); });


        // Fill reco jet quantities

        for (int i_j = 0; i_j < tempJetRecoContainer.size(); i_j++)
        {
            jet_reco_E.push_back( (tempJetRecoContainer[i_j]).E() );
            jet_reco_pt.push_back( (tempJetRecoContainer[i_j]).Pt() );
            jet_reco_eta.push_back( (tempJetRecoContainer[i_j]).Eta() );
            jet_reco_phi.push_back( (tempJetRecoContainer[i_j]).Phi() );      
        }

        tempJetRecoContainer.clear();




        // Reco electrons and muons
        // ........................

            // Note 1: No resolution smearing is applied to the angle eta and phi because
            //         these parameters are sufficiently precisely measured from fit at
            //         primary vertex. For the electrons, the resolution is applied to the 
            //         total energy, but varies as a function of the pT of the electron. This
            //         pT dependence is obtained from an exponential fit to the resolution
            //         measurement results published by ATLAS with 13 TeV 2015 data. For the 
            //         muons, it is the resolution of the total momentum that is measured (in 
            //         fact it is the resolution of the invariant mass of the dimuon system,
            //         which equal the total momentum resolution up to a factor of srqt(2)). 
            //         It depends on the transverse momentum of the muon. This pT dependence 
            //         is modeled from a linear fit to the ATLAS muon resolution measurement
            //         performed on 13 TeV data. A different fit is obtained for central 
            //         (barrel) and forward (end-cap) muons. 

            // Note 2: Both electrons and muons are assumed to be well calibrated.

            // Note 3: A probability of bremsstrahlung emission is measured for electrons with
            //         ATLAS data. This measurement results has been modeled by a special 
            //         corrected error function as a function of the fraction of energy 
            //         radiated the fraction of initial energy radiated is obtained from a  
            //         random number between 0 and 1, and the the probability for that raditation
            //         to happen is obtained from the model function. Another randome number is 
            //         used to decide if this radiation happens or not. If it does, 1-fBrem is
            //         applied to the reco electron energy to model this lost. 

            // Note 4: The efficiency for tight electrons and medium muons are modeled from 
            //         the measurement results respecively obtained from ATLAS data for these
            //         two particles. Muons are assumed to be constant in pT and depend only
            //         on eta (constant functions in different eta ranges). Electrons reco+id
            //         efficiency is depends on pT. This dependence is modeled from a Cauchy 
            //         cumulative function approximatively fitted to the ATLAS measurement
            //         results also used for the resolution and Bremsstrahlung models. Once the
            //         efficiency for a given leptons is known, a random number is selected and
            //         compared to this efficiency to decide if the lepton is kept or not. If it
            //         passes the test, it is pushed back in the reco vector, otherwise it is lost.

            // Note 5: Reco Met is calculated in the same way as it is for jets. One small exception, 
            //         and electron is not fiducial to the tracker, but still within the boundaries
            //         of the calo, this electron will be visible and will not be considered as Met.

            // Note 6: As for jets, electrons and muons might not be sorted in decreasing pt order
            //         after modeling detector effects. Even if the "disordering" is much smaller
            //         then for jets because resolution effects are much smaller, it is important
            //         to sort leptons properly. We cannot use the exact same method as for jets 
            //         however, because of the charge of the leptons that need to be stored as well
            //         and which is not part of a TLorentzVector. So all reco-level electrons (muons)
            //         are stored in a vector of pair consisting in a TLorentzVector as the first
            //         component, and a float, to hold the charge, as the second component of each
            //         pairs. The vector of pairs is then sorted based on the pt of the first
            //         component of the pair, before the assignment to the vectors of electrons
            //         (muons) quantities (E, pt, eta, phi, and charge) get properly assigned.

        vector< pair<TLorentzVector,float> > tempEleRecoContainer;
        vector< pair<TLorentzVector,float> > tempMuoRecoContainer;

        nElectronReco = 0;
        for (int i_tele = 0; i_tele < electron_bare_E.size(); i_tele++)
        {

            // Fetch truth information
            double EleTrueE = electron_bare_E[i_tele];
            double EleTrueEta = electron_bare_eta[i_tele];
            double EleTruePhi = electron_bare_phi[i_tele];
            double EleTruePt = electron_bare_pt[i_tele];
            float EleTrueChg = electron_bare_charge[i_tele];

            TLorentzVector trueEle;
            trueEle.SetPtEtaPhiE(EleTruePt,EleTrueEta,EleTruePhi,EleTrueE);
            double truePx = trueEle.Px();
            double truePy = trueEle.Py();

            // Add truth particle to the Reco Met (reco will be remove later)
            RecoSum_y += truePy;
            RecoSum_x += truePx;

            // Calculate pt-dependent resolution
            double E_resol = EleTrueE*0.4*exp((-0.75)*log(EleTruePt));

            // Calculate detector distortion
            double recoE = gRandom->Gaus(EleTrueE,E_resol);

            // Calculate Bremsstrahlung fraction
            double fBrem = gRandom->Rndm();
            double probBrem = 0.05*TMath::Gaus(fBrem,0.1,0.05) + 0.01;
            bool doBrem = false;
            double testBrem = gRandom->Rndm();
            
            if (testBrem < probBrem) doBrem = true;
            if (doBrem) recoE *= fBrem;


            // Calculate reco quantities
            double recoEta = EleTrueEta;
            double recoPhi = EleTruePhi;
            double recoPt = recoE/cosh(recoEta);
            
            TLorentzVector recoEle;
            recoEle.SetPtEtaPhiE(recoPt,recoEta,recoPhi,recoE);
            double recoPx = recoEle.Px();
            double recoPy = recoEle.Py();

            // Calculate efficiency and apply
            double EleEff = (1./TMath::Pi())*TMath::ATan( (recoPt+15.)/30. ) + 0.5;
            bool looseEle = false;
            
            double testEle = gRandom->Rndm();
            if (testEle > EleEff) looseEle = true;

            if (looseEle) continue;

            // Remove non-fiducial electrons
            if (fabs(recoEta) > 5.) continue;
            
            // Calculate reco impact on Met
            RecoSum_y += (-1)*recoPy;
            RecoSum_x += (-1)*recoPx;

            // Don't store too low Pt jets
            if (recoPt<5. || fabs(recoEta)>2.5) continue;

            // Charge mis-Id
            bool chargeFlip = false;
            float testFlip = gRandom->Rndm();
            float recoChg = EleTrueChg;
            if (testFlip > 0.98) chargeFlip = true;
            if (chargeFlip) recoChg = (-1.)*EleTrueChg;


            // Fill tempEleRecoContainer
            pair<TLorentzVector,float> elerecpair;
            elerecpair.first = recoEle;
            elerecpair.second = recoChg;
            tempEleRecoContainer.push_back(elerecpair);

            nElectronReco++;
        }

        // Sort reco electrons in descending pt
        std::sort(tempEleRecoContainer.begin(), tempEleRecoContainer.end(), 
            [](pair<TLorentzVector,float> x, pair<TLorentzVector,float> y) { return (x.first).Pt() > (y.first).Pt(); });


        // Fill reco electron quantities
        for (int i_e = 0; i_e < tempEleRecoContainer.size(); i_e++)
        {
            electron_reco_E.push_back( ( (tempEleRecoContainer[i_e]).first).E() );
            electron_reco_pt.push_back( ( (tempEleRecoContainer[i_e]).first).Pt() );
            electron_reco_eta.push_back( ( (tempEleRecoContainer[i_e]).first).Eta() );
            electron_reco_phi.push_back( ( (tempEleRecoContainer[i_e]).first).Phi() );
            electron_reco_charge.push_back( (tempEleRecoContainer[i_e]).second);
        }


        // BSJ (muoons ;)

        nMuonReco = 0;
        for (int i_tmuo = 0; i_tmuo < muon_bare_E.size(); i_tmuo++)
        {
    
            // Fetch truth information
            double MuoTrueE = muon_bare_E[i_tmuo];
            double MuoTrueEta = muon_bare_eta[i_tmuo];
            double MuoTruePhi = muon_bare_phi[i_tmuo];
            double MuoTruePt = muon_bare_pt[i_tmuo];
            double MuoTrueChg = muon_bare_charge[i_tmuo];

            TLorentzVector trueMuo;
            trueMuo.SetPtEtaPhiE(MuoTruePt,MuoTrueEta,MuoTruePhi,MuoTrueE);
            double truePx = trueMuo.Px();
            double truePy = trueMuo.Py();

            // Add truth particle to the Reco Met (reco will be remove later)
            RecoSum_y += truePy;
            RecoSum_x += truePx;

            // Calculate pt-dependent resolution
            double E_resol = 0;
            if (fabs(MuoTrueEta)<1.) E_resol = MuoTrueE*sqrt(2)*(0.00008*MuoTruePt+0.012);
            else if (fabs(MuoTrueEta)>1.) E_resol = MuoTrueE*sqrt(2)*(0.0001*MuoTruePt+0.02);

            // Calculate detector distortion
            double recoE = gRandom->Gaus(MuoTrueE,E_resol);

            // Calculate reco quantities
            double recoEta = MuoTrueEta;
            double recoPhi = MuoTruePhi;
            double recoPt = recoE/cosh(recoEta);
    
            TLorentzVector recoMuo;
            recoMuo.SetPtEtaPhiE(recoPt,recoEta,recoPhi,recoE);
            double recoPx = recoMuo.Px();
            double recoPy = recoMuo.Py();

            // Calculate efficiency and apply
            double MuoEff = 0.98;
            if (fabs(recoEta)<0.1) MuoEff = 0.6;

            bool looseMuo = false;
    
            double testMuo = gRandom->Rndm();
            if (testMuo > MuoEff) looseMuo = true;
            if (looseMuo) continue;

            // Remove non-fiducial muons
            if ( fabs(recoEta) > 2.5) continue;

            // Calculate reco impact on Met
            RecoSum_y += (-1)*recoPy;
            RecoSum_x += (-1)*recoPx;

            // Don't store too low Pt jets
            if (recoPt < 5.) continue;

            // Charge mis-Id
            bool chargeFlip = false;
            float testFlip = gRandom->Rndm();
            float recoChg = MuoTrueChg; 
            if (testFlip > 0.98) chargeFlip = true;
            if (chargeFlip) recoChg = (-1.)*MuoTrueChg;


            // Fill tempMuoRecoContainer
            pair<TLorentzVector,float> muorecpair;
            muorecpair.first = recoMuo;
            muorecpair.second = recoChg;
            tempMuoRecoContainer.push_back(muorecpair);

            nMuonReco++;

        }


        // Sort reco muoons in descending pt
        std::sort(tempMuoRecoContainer.begin(), tempMuoRecoContainer.end(), 
            [](pair<TLorentzVector,float> x, pair<TLorentzVector,float> y) { return (x.first).Pt() > (y.first).Pt(); });


        // Fill reco muon quantities
        for (int i_m = 0; i_m < tempMuoRecoContainer.size(); i_m++)
        {
            muon_reco_E.push_back( ( (tempMuoRecoContainer[i_m]).first).E() );
            muon_reco_pt.push_back( ( (tempMuoRecoContainer[i_m]).first).Pt() );
            muon_reco_eta.push_back( ( (tempMuoRecoContainer[i_m]).first).Eta() );
            muon_reco_phi.push_back( ( (tempMuoRecoContainer[i_m]).first).Phi() );
            muon_reco_charge.push_back( (tempMuoRecoContainer[i_m]).second);
        }

        
        // Reco Met
        // ........

        RecoSqSum = pow(RecoSum_x, 2.0) + pow(RecoSum_y, 2.0);
        RecoMet = sqrt(RecoSqSum);
        RecoMet_phi = atan2(RecoSum_y,RecoSum_x);
        if (RecoMet_phi < 0.) RecoMet_phi = RecoMet_phi + 6.283185307;


        // Fill the analysis tree
        tree->Fill();

        // Clear reco vectors

        electron_reco_pt.clear();
        electron_reco_eta.clear();
        electron_reco_phi.clear();
        electron_reco_E.clear();
        electron_reco_charge.clear();

        muon_reco_pt.clear();
        muon_reco_eta.clear();
        muon_reco_phi.clear();
        muon_reco_E.clear();
        muon_reco_charge.clear();

        jet_reco_pt.clear();
        jet_reco_eta.clear();
        jet_reco_phi.clear();
        jet_reco_E.clear();

        jet_reco_pt_map.clear();
        jet_reco_eta_map.clear();
        jet_reco_phi_map.clear();
        jet_reco_E_map.clear();

        // Clear truth vectors
        event_weights.clear();

        neutrino_pt.clear();
        neutrino_eta.clear();
        neutrino_phi.clear();
        neutrino_E.clear();
        neutrino_PdgId.clear();

        electron_bare_pt.clear();
        electron_bare_eta.clear();
        electron_bare_phi.clear();
        electron_bare_E.clear();
        electron_bare_charge.clear();

        muon_bare_pt.clear();
        muon_bare_eta.clear();
        muon_bare_phi.clear();
        muon_bare_E.clear();
        muon_bare_charge.clear();

        lightjet_bare_pt.clear();
        lightjet_bare_eta.clear();
        lightjet_bare_phi.clear();
        lightjet_bare_E.clear();
        lightjet_bare_nPart.clear();

        boson_ID.clear();
        boson_pt.clear();
        boson_eta.clear();
        boson_phi.clear();
        boson_E.clear();

    } // End loop on events


    // Write tree
    tree->Write();

    // Close output file
    output->Close();


    return 0;
}






//================================================================================//
//=============================== Main Function ==================================//
//================================================================================//

int MyDetectorSimul25()
{

    // two options:
    // -----------

    // give a list of files (within pythia-outputs)
    std::vector<string> samples = {"Wpythia21_test.root"}; 

    // or run over all files in pythia-output/ directory
    // std::vector<string> samples;
    // DIR *dir_ptr;
    // struct dirent *diread;
    // if ((dir_ptr = opendir(inpath.c_str())) != nullptr) {
    //     while ((diread = readdir(dir_ptr)) != nullptr) {
    //         string sample = diread->d_name;
    //         if (sample.find(".root") != string::npos){
    //             samples.push_back(sample);
    //         }
            
    //     }
    //     closedir(dir_ptr);
    // }

    // loop over list of files and fill histograms with RunAnalysis
    for (int i = 0; i <samples.size(); i++) 
    {
        cout << "Analysing " << samples[i] << " ..." << endl;
        DetectorEffects(samples[i]);
    }

    return 0;

}

