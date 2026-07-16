"""
This script uses pyroot functionality to create a png plot from a .root file
Call in terminal as "python psi_plotter.py <input filestem> <output filestem>"
        where filestem does not include ".root" or ".png"
"""

import ROOT
import sys

ROOT.gStyle.SetOptStat(0)

filestem = sys.argv[1] # i.e. "truth_psi"
hist_file = ROOT.TFile("/cluster/tufts/beaucheminlab/svenet01/WplusJetsAnalysis/psi-calculation/hists/"+filestem+".root")

# Creates histogram object from root file for psi_truth
hist_name = hist_file.GetListOfKeys()[0] # Gets name and title and assigns to variable
hist = hist_file.Get(hist_name.GetName()) # Pulls name only to create hist and assign to variable
hist_nEntries = hist.Integral()
xaxis_label=hist_name.GetName()

# if hist.Integral() > 0:
#         hist.Scale(1.0 / hist.Integral())

# Create canvas
c = ROOT.TCanvas("psi", hist_name.GetName(), 1200, 800)
c.SetLeftMargin(0.2)
c.SetBottomMargin(0.15)
c.SetRightMargin(0.2)
c.SetTopMargin(0.1)

# Histogram settings
hist.SetTitle(xaxis_label)
hist.GetXaxis().SetTitle("#psi")
hist.GetYaxis().SetTitle("Events")
hist.GetXaxis().SetTitleSize(0.06)
hist.GetYaxis().SetTitleSize(0.06)
hist.GetXaxis().SetLabelSize(0.05)
hist.GetYaxis().SetLabelSize(0.05)
hist.GetXaxis().SetTitleOffset(1.1)
hist.GetYaxis().SetTitleOffset(1.6)
hist.GetXaxis().SetMaxDigits(2)
hist.SetMarkerColor(1)
hist.SetMarkerStyle(20)
hist.SetLineWidth(2)

hist.Draw() # "P" flag draws hist with markers instead of lines

# Create legend
legend = ROOT.TLegend(.5, 0.90, 0.8, 0.80) # (x1, y1, x2, y2)
legend.AddEntry(0, "Entries =  " + str((hist_nEntries)), "") 
"""
        0 indicates no association with specific data
        "" indicates no marker
"""
legend.SetTextSize(0.04)
legend.SetBorderSize(1)

legend.Draw("L")

# Allow room for space at top and bottom of plot
hist.SetMaximum(hist.GetMaximum() * 1.1)
hist.SetMinimum(hist.GetMinimum() * 0.9)

c.Update()

c.SaveAs(f"plots/{sys.argv[2]}.png") 