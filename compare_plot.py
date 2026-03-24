"""
This script uses pyroot functionality to create a png plot of multiple .root files overlaid
Call in terminal as "python compare_plot.py"
"""

# reformat into loop over a list of filenames

import ROOT
import sys
from ROOT import gROOT

ROOT.gStyle.SetOptStat(0)

# Build array of filestems

filestems = []
for i in range(1,len(sys.argv)):
        filestems.append(sys.argv[i])
print(filestems)

# Create canvas
c = ROOT.TCanvas("c", "c", 1200, 800)
c.SetLeftMargin(0.2)
c.SetBottomMargin(0.15)
c.SetRightMargin(0.2)
c.SetTopMargin(0.05)

# Create THStack
s = ROOT.THStack("s", "s")

hists = []

for i in range(0, len(filestems)):
        print(i)
        print("Creating histogram for", filestems[i])
        hist_file = ROOT.TFile(filestems[i]+".root")
        hist_name = hist_file.GetListOfKeys()[0] # Gets name and title and assigns to variable
        hist = hist_file.Get(hist_name.GetName()) # Pulls name only to create hist and assign to variable
        hist_nEntries = hist.GetEntries()

        hist.SetMarkerColor(i+2)
        hist.SetMarkerStyle(20)
        hist.SetLineColor(i+2)
        hist.SetLineStyle(i+1)
        hist.SetLineWidth(5)

        gROOT.cd()
        hnew=hist.Clone()
        s.Add(hnew)
        hists.append(hnew)

c.cd()

# DO LEGEND HERE? loop through hists
# legend settings
# legend = ROOT.TLegend(.5, 0.90, 0.8, 0.80) # (x1, y1, x2, y2)
# legend.AddEntry(hist1, filestems[0], "l")
# legend.SetTextSize(0.04)
# legend.SetBorderSize(0)
# legend.Draw("L")

s.Draw("nostack")
s.SetTitle("")
s.GetXaxis().SetTitle("Z pT")
s.GetYaxis().SetTitle("Events")
s.GetXaxis().SetTitleSize(0.06)
s.GetYaxis().SetTitleSize(0.06)
s.GetXaxis().SetLabelSize(0.05)
s.GetYaxis().SetLabelSize(0.05)
s.GetXaxis().SetTitleOffset(1.1)
s.GetYaxis().SetTitleOffset(1.6)
s.GetXaxis().SetMaxDigits(2)

c.SaveAs(f"plots/z_pt.png")

# only plotting first and third. Need to try instead adding the histograms to a stack, then plotting the stack at once)
# Then, create canvas and plot on canvas