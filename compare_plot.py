"""
This script uses pyroot functionality to create a png plot of multiple hists from same root file overlaid
Call in terminal as "python compare_plot.py <filestem>"
"""

# reformat into loop over a list of filenames

import ROOT
import sys
from ROOT import gROOT
from ROOT import gDirectory
from ROOT import TH1D

ROOT.gStyle.SetOptStat(0)

var1 = "muon_born_pt"
var2 = "tau_born_pt"
nbins = 50
binlow = 0
binhigh = 100 
title = "pt_tautau"

# Create canvas
c = ROOT.TCanvas("c", "c", 1200, 800)
c.SetLeftMargin(0.2)
c.SetBottomMargin(0.15)
c.SetRightMargin(0.2)
c.SetTopMargin(0.05)

# Create THStack
s = ROOT.THStack("s", "s")

hists = []

print("Creating histogram for", sys.argv[1])
hist_file = ROOT.TFile.Open("/cluster/tufts/beaucheminlab/svenet01/WplusJetsAnalysis/pythia-outputs/2025/"+sys.argv[1]+".root", "READ")
tree = hist_file.Get("ParticleTree")
print(tree)
mu = ROOT.TH1D("data", "mu", nbins, binlow, binhigh)
tau = ROOT.TH1D("data", "tau", nbins, binlow, binhigh)
for entryNum in range(0,tree.GetEntries()):
        tree.GetEntry(entryNum)
        var1_store = getattr(tree, var1)
        var2_store = getattr(tree, var2)
        # print("Size of var1, var2: ", "(", len(var1), ",", len(var2),")")
        mu.Fill(var1_store[0])
        mu.Fill(var1_store[1])
        tau.Fill(var2_store[0])
        tau.Fill(var2_store[1])
mu.SetMarkerColor(2)
mu.SetMarkerStyle(20)
mu.SetLineColor(2)
mu.SetLineStyle(1)
mu.SetLineWidth(5)

tau.SetMarkerColor(3)
tau.SetMarkerStyle(20)
tau.SetLineColor(3)
tau.SetLineStyle(2)
tau.SetLineWidth(5)

gROOT.cd()
muon_stack=mu.Clone()
tau_stack=tau.Clone()
s.Add(muon_stack)
s.Add(tau_stack)
hists.append(muon_stack)
hists.append(tau_stack)

c.cd()

s.Draw("nostack")
s.SetTitle("")
s.GetXaxis().SetTitle(title)
s.GetYaxis().SetTitle("Events")
s.GetXaxis().SetTitleSize(0.06)
s.GetYaxis().SetTitleSize(0.06)
s.GetXaxis().SetLabelSize(0.05)
s.GetYaxis().SetLabelSize(0.05)
s.GetXaxis().SetTitleOffset(1.1)
s.GetYaxis().SetTitleOffset(1.6)
s.GetXaxis().SetMaxDigits(2)

# legend settings
legend = ROOT.TLegend(.5, 0.90, 0.8, 0.75) # (x1, y1, x2, y2)
legend.AddEntry(hists[0], var1, "l")
legend.AddEntry(hists[1], var2, "l")
legend.SetTextSize(0.04)
legend.SetBorderSize(0)
legend.Draw("L")

c.SaveAs(f"plots/tautau_mumu/{title}.png")