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

# Build array of filestems

filestems = []
for i in range(2,len(sys.argv)):
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
maxes = []
mins = []
entries = []
xaxis_label = []

for i in range(0, len(filestems)):
        print("Creating histogram for", filestems[i])

        hist_file = ROOT.TFile("/cluster/tufts/beaucheminlab/svenet01/WplusJetsAnalysis/psi-calculation/hists_compare/"+filestems[i]+".root")
        hist_name = hist_file.GetListOfKeys()[0] # Gets name and title and assigns to variable
        hist = hist_file.Get(hist_name.GetName()) # Pulls name only to create hist and assign to variable
        xaxis_label.append(hist_name.GetName())

        entries.append(hist.Integral())

        # if hist.Integral() > 0:
        #         hist.Scale(1.0 / hist.Integral())

        hist.SetMarkerColor(i+1)
        hist.SetMarkerStyle(20)
        hist.SetLineColor(i+1)
        # hist.SetLineStyle(i+2)
        hist.SetLineWidth(2)
        maxes.append(hist.GetMaximum()*1.05)
        mins.append(hist.GetMinimum()*.95)
        
        gROOT.cd()
        hnew=hist.Clone()
        s.Add(hnew)
        hists.append(hnew)

c.cd()

s.Draw("nostack, hist") # "P nostack" plots as markers
s.SetTitle("")
# s.GetXaxis().SetTitle("Z p_{T}_{vis}/Z p_{T}_{real}")
s.GetXaxis().SetTitle(xaxis_label[0])
s.GetYaxis().SetTitle("Events")
s.GetXaxis().SetTitleSize(0.06)
s.GetYaxis().SetTitleSize(0.06)
s.GetXaxis().SetLabelSize(0.05)
s.GetYaxis().SetLabelSize(0.05)
s.GetXaxis().SetTitleOffset(1.1)
s.GetYaxis().SetTitleOffset(1.6)
# s.GetXaxis().SetMaxDigits(1)
# Allow room for space at top and bottom of plot
s.SetMaximum(max(maxes))
s.SetMinimum(min(mins))

# legend settings
legend = ROOT.TLegend(.3, 0.95, 0.6, 0.80) # (x1, y1, x2, y2)
for i in range(0,len(filestems)):
        legend.AddEntry(hists[i], filestems[i] + ", Entries:" + str(entries[i]), "l")
        legend.SetTextSize(0.04)
        legend.SetBorderSize(0)
        # legend.SetFillColor(0)
        # legend.SetFillStyle(1001)
        legend.Draw("L")

c.SaveAs(f"/cluster/tufts/beaucheminlab/svenet01/WplusJetsAnalysis/psi-calculation/hists_compare/{sys.argv[1]}.png")