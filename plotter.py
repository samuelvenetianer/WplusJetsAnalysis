"""
This script uses pyroot functionality to create a png plot from a .root file
Call in terminal as "python plotter.py <input filestem> <xaxis name>"
        where filestem does not include ".root" or ".png"
"""

import ROOT
import sys

ROOT.gStyle.SetOptStat(0) # 0 to suppress statistics box, 1 to display

filestem = sys.argv[1] # "i.e. z_pt_80GeV"
hist_file = ROOT.TFile(filestem+".root")

# Creates histogram object from root file for psi_truth
hist_name = hist_file.GetListOfKeys()[0] # Gets name and title and assigns to variable
hist = hist_file.Get(hist_name.GetName()) # Pulls name only to create hist and assign to variable
hist_nEntries = hist.GetEntries()
        
# Create canvas
c = ROOT.TCanvas("c", hist_name.GetName(), 1200, 800) # name, title, width, height
c.SetLeftMargin(0.2)
c.SetBottomMargin(0.15)
c.SetRightMargin(0.2)
c.SetTopMargin(0.05)

# Histogram settings
hist.SetTitle("")
hist.GetXaxis().SetTitle(sys.argv[2])
hist.GetYaxis().SetTitle("Events")
hist.GetXaxis().SetTitleSize(0.06)
hist.GetYaxis().SetTitleSize(0.06)
hist.GetXaxis().SetLabelSize(0.05)
hist.GetYaxis().SetLabelSize(0.05)
hist.GetXaxis().SetTitleOffset(1.1)
hist.GetYaxis().SetTitleOffset(1.6)
hist.GetXaxis().SetMaxDigits(2) # Force scientific notation
hist.SetLineWidth(5)

hist.Draw()

# Create legend
legend = ROOT.TLegend(.5, 0.90, 0.8, 0.80) # position: x1, y1, x2, y2
legend.AddEntry(hist, "Entries =  " + str(int(hist_nEntries)), "l") # "l" sets legend icon as a line, "p" sets as polymarker
legend.SetTextSize(0.04)
legend.SetBorderSize(1)

legend.Draw("L")

# Set max y value to allow room for a legend at top of plot
hist.SetMaximum(hist.GetMaximum() * 1.1)

# Ensure all settings are current
c.Update()

c.SaveAs(f"plots/{sys.argv[2]}.png")