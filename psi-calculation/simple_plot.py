"""
This script uses pyroot functionality to create a png plot of multiple .root files overlaid
Call in terminal as "python compare_plot.py <output name> <filestem1> <filestem2> etc..."
        Up to 9 input files allowed (constrained by line style, which can be changed)
"""

# reformat into loop over a list of filenames

import ROOT
import sys
from ROOT import gROOT

ROOT.gStyle.SetOptStat(0)

# Create canvas
c = ROOT.TCanvas("c", "c", 1200, 800)
c.SetLeftMargin(0.2)
c.SetBottomMargin(0.15)
c.SetRightMargin(0.2)
c.SetTopMargin(0.05)

# Create THStack
s = ROOT.THStack("s", "s")

# print("Creating histogram for...")

hist_file = ROOT.TFile(sys.argv[1])
hist_name = hist_file.GetListOfKeys()[0] # Gets name and title and assigns to variable
hist = hist_file.Get(hist_name.GetName()) # Pulls name only to create hist and assign to variable
xaxis_label=hist_name.GetName()

entries=hist.Integral()

# if hist.Integral() > 0:
#         hist.Scale(1.0 / hist.Integral())

hist.SetMarkerColor(1)
hist.SetMarkerStyle(20)
hist.SetLineColor(1)
hist.SetLineStyle(1)
hist.SetLineWidth(5)

gROOT.cd()
hnew=hist.Clone()
s.Add(hnew)

c.cd()

s.Draw("nostack") # "P nostack" plots as markers
s.SetTitle("")
# s.GetXaxis().SetTitle("Z p_{T}_{vis}/Z p_{T}_{real}")
s.GetXaxis().SetTitle(xaxis_label)
s.GetYaxis().SetTitle("Events")
s.GetXaxis().SetTitleSize(0.06)
s.GetYaxis().SetTitleSize(0.06)
s.GetXaxis().SetLabelSize(0.05)
s.GetYaxis().SetLabelSize(0.05)
s.GetXaxis().SetTitleOffset(1.1)
s.GetYaxis().SetTitleOffset(1.6)
# s.GetXaxis().SetMaxDigits(1)
# Allow room for space at top and bottom of plot
s.SetMaximum(hist.GetMaximum()*1.5)
s.SetMinimum(hist.GetMinimum()*0.9)

# legend settings
legend = ROOT.TLegend(.3, 0.90, 0.6, 0.75) # (x1, y1, x2, y2)
legend.AddEntry(hist, "Entries:" + str(entries), "l")
legend.SetTextSize(0.04)
legend.SetBorderSize(0)
# legend.SetFillColor(0)
# legend.SetFillStyle(1001)
legend.Draw("L")

c.SaveAs(f"/cluster/tufts/beaucheminlab/svenet01/WplusJetsAnalysis/psi-calculation/plots/{xaxis_label}.png")