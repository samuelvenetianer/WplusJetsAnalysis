"""
This script uses pyroot functionality to create a png plot of multiple .root files overlaid
Call in terminal as "python compare_plot.py"
"""

# reformat into loop over a list of filenames

import ROOT

ROOT.gStyle.SetOptStat(0)

filename1 = "z_pt_20GeV"
filename2 = "z_pt_50GeV"
filename3 = "z_pt_80GeV"

hist_file1 = ROOT.TFile(filename1+".root")
hist_file2 = ROOT.TFile(filename2+".root")
hist_file3 = ROOT.TFile(filename3+".root")

for hist_name in hist_file1.GetListOfKeys():
   
        hist1 = hist_file1.Get(hist_name.GetName())
        hist1_nEntries = hist1.GetEntries()
        # print(hist1_nEntries)
        
        # Create canvas and plot histogram with fit
        c = ROOT.TCanvas("psi", hist_name.GetName(), 1200, 800)
        c.SetLeftMargin(0.2)
        c.SetBottomMargin(0.15)
        c.SetRightMargin(0.2)
        c.SetTopMargin(0.05)

        hist1.SetTitle("")
        hist1.SetLineColor(3)
        hist1.SetLineWidth(2)
        hist1.GetXaxis().SetTitle("Z pT")
        hist1.GetYaxis().SetTitle("Events")
        hist1.GetXaxis().SetTitleSize(0.06)
        hist1.GetYaxis().SetTitleSize(0.06)
        hist1.GetXaxis().SetLabelSize(0.05)
        hist1.GetYaxis().SetLabelSize(0.05)
        hist1.GetXaxis().SetTitleOffset(1.1)
        hist1.GetYaxis().SetTitleOffset(1.6)
        hist1.GetXaxis().SetMaxDigits(2)
        hist1.Draw()

        legend = ROOT.TLegend(.5, 0.90, 0.8, 0.80) # (x1, y1, x2, y2)
        legend.AddEntry(hist1, filename1, "l")
        legend.SetTextSize(0.04)
        legend.SetBorderSize(0)
        legend.Draw("L")


        # Scale histogram to make room for text box at top
        hist1_max=hist1.GetMaximum()

        # Create text box with fit parameters at the top
        # text_box.SetFillColor(10)
        # text_box.SetBorderSize(0)
        # text_box.SetTextSize(0.04)

        # text_box.AddText("psi")

        # text_box.Draw()
        c.Update()

for hist_name in hist_file2.GetListOfKeys():
   
        hist2 = hist_file2.Get(hist_name.GetName())
        hist2_nEntries = hist2.GetEntries()
        # print(hist2_nEntries)

        hist2.SetMarkerColor(2)
        hist2.SetMarkerStyle(20)
        hist2.SetLineColor(2)
        hist2.SetLineStyle(1)
        hist2.SetLineWidth(2)

        hist2_max=hist2.GetMaximum()
        global_max = max(hist1_max,hist2_max)
        hist2.SetMaximum(global_max * 1.3)

        legend.AddEntry(hist2, filename2, "l")

        hist2.Draw("SAME")
        c.Update()

for hist_name in hist_file3.GetListOfKeys():
   
        hist3 = hist_file3.Get(hist_name.GetName())
        hist3_nEntries = hist3.GetEntries()
        # print(hist3_nEntries)

        hist3.SetMarkerColor(2)
        hist3.SetMarkerStyle(20)
        hist3.SetLineColor(4)
        hist3.SetLineStyle(1)
        hist3.SetLineWidth(2)

        hist3_max=hist3.GetMaximum()
        global_max = max(hist1_max, hist2_max, hist3_max)
        hist3.SetMaximum(global_max * 1.3)

        legend.AddEntry(hist3, filename3, "l")

        hist3.Draw("SAME")
        c.Update()

c.SaveAs(f"plots/z_pt.png")