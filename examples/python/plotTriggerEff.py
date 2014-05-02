from ROOT import gROOT, gStyle, gSystem, TCanvas, TF1, TFile, TH1F
from ROOT import TColor, TLine, TLegend, TLatex, TObjArray
from ROOT import SetOwnership

from ROOT import gDirectory, gPad

import sys,string,math,os

# import myPyRootSettings
sys.path.append(os.path.join(os.environ.get("HOME"),'rootmacros'))
from myPyRootSettings import prepPlot

if __name__ == '__main__':

    gROOT.Reset()
    gROOT.SetStyle("MyStyle");    
    # gStyle.SetOptLogy(0);
    gStyle.SetPalette(1);
    gStyle.SetOptTitle(0);
    gStyle.SetOptStat(0);
    gStyle.SetPadTopMargin(0.02);
    gStyle.SetPadTickX(1);

    gStyle.SetLabelSize(0.045, "XYZ");
    gStyle.SetLabelSize(0.04, "Y");
    gStyle.SetTitleSize(0.05, "XYZ");

    # TriggerName="HLT_PFJet80"
    TriggerName="HLT_PFL1FastL2L3CorJet80"

    HistFile="jetTriggerEff_"+TriggerName+"_v1_JEC_v4.root"
    f = TFile(HistFile)

    Dir="JetEff"
    hnumer="leadingJetPtTrig"
    hdenom="leadingJetPt"

    hNum=f.Get(Dir + "/" + hnumer)
    hDen=f.Get(Dir + "/" + hdenom)

    # f1.ls()
    # f.cd(Dir)
    # hNum = gDirectory.Get(Num)
    # hDen = gDirectory.Get(Den)

    cname="Triggers"
    c1 = prepPlot("c1",cname,700,20,500,500)
    c1.SetLogy(1);    

    # i1=90; i2=110
    xmin=40.; xmax=200.
    hNum.GetXaxis().SetRangeUser(xmin,xmax)
    hDen.GetXaxis().SetRangeUser(xmin,xmax)
    hDen.SetLineColor(ROOT.kRed)
    hDen.Draw()
    hNum.Draw("same")

    cname="Trigger Efficiency"
    c2 = prepPlot("c2",cname,150,120,500,500)
    c2.SetLogy(0);    

    min=0.; max=1.24


    hRat= hNum.Clone()
    hRat.SetName("Ratio")

    tr = ROOT.TGraphAsymmErrors()
    tr.Divide(hNum,hDen,"cl=0.683 b(1,1) mode");

    tr.SetMaximum(max)
    tr.SetMinimum(min)
    tr.GetXaxis().SetRangeUser(xmin,xmax)
    tr.GetXaxis().SetTitle("RECO jet p_{T}"); tr.GetXaxis().SetTitleOffset(1.1);
    tr.GetYaxis().SetTitle("Efficiency"); tr.GetYaxis().SetTitleOffset(1.1);

    tr.SetMarkerStyle(20);
    tr.SetMarkerSize(.75);
    tr.SetMarkerColor(ROOT.kBlue);
    tr.SetLineColor(ROOT.kBlue);
    tr.SetMaximum(max)
    tr.SetMinimum(min)
    tr.Draw("APZ")

    
    t1 = TLatex();
    t1.SetNDC();

    txtsize=0.05;  t1.SetTextSize(txtsize);
    leglabel=TriggerName

    xtxt=.15; ytxt=.85;
    t1.DrawLatex(xtxt,ytxt,leglabel);

