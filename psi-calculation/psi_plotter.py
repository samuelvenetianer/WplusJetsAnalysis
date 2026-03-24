"""
This script uses pyroot functionality to create a png plot from a .root file
Call in terminal as "python psi_plotter.py <filestem>" where filestem does not include ".root"
"""

import ROOT
import sys

ROOT.gStyle.SetOptStat(0)

filestem = sys.argv[1] # i.e. "truth_psi"
hist_file = ROOT.TFile(filestem+".root")

# Creates histogram object from root file for psi_truth
hist_name = hist_file.GetListOfKeys()[0] # Gets name and title and assigns to variable
hist = hist_file.Get(hist_name.GetName()) # Pulls name only to create hist and assign to variable
hist_nEntries = hist.GetEntries()

# Create canvas
c = ROOT.TCanvas("psi", hist_name.GetName(), 1200, 800)
c.SetLeftMargin(0.2)
c.SetBottomMargin(0.15)
c.SetRightMargin(0.2)
c.SetTopMargin(0.1)

# Histogram settings
hist.SetTitle("Truth #psi 1p1n-1p1n")
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

hist.Draw("P") # "P" flag draws hist with markers instead of lines

# Create legend
legend = ROOT.TLegend(.5, 0.90, 0.8, 0.80) # (x1, y1, x2, y2)
legend.AddEntry(0, "Entries =  " + str(int(hist_nEntries)), "") 
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