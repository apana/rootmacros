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

    RootDir="."
    WhichCorr="L1L2L3"
    WhichJets="ak5PFJets"
    # WhichJets="ak5CaloJets"

    RootFile1="Corr_L1L2L3_data_"+WhichJets+"r180250.root"
    RootFile2="Corr_L2L3_data_"+WhichJets+"r180250.root"


    HistFile1=os.path.join(RootDir,RootFile1)
    HistFile2=os.path.join(RootDir,RootFile2)


    Name="Ratio"

    f1 = TFile(HistFile1)
    f1.ls()
    
    hNum = gDirectory.Get(Name)
    f2 = TFile(HistFile2)
    hDen = gDirectory.Get(Name)

    hRat= hNum.Clone()
    hRat.SetName("Ratio")
    hRat.Divide(hNum,hDen,1.,1.,"");
    Hlist=TObjArray()
    Hlist.Add(hRat);

    cname="pT"
    c1 = prepPlot("c1",cname,700,20,500,500)
    c1.SetLogy(0);    

    # i1=90; i2=110
    i1=0; i2=500
    hNum.GetXaxis().SetRange(i1,i2)
    hDen.SetLineColor(ROOT.kRed)
    hNum.Draw()
    hDen.Draw("same")

    cname="Ratio"
    c2 = prepPlot("c2",cname,150,120,500,500)
    c2.SetLogy(0);    

    min=0.; max=1.24
    if WhichJets=="ak5CaloJets":
        min=0.
    hRat.SetMaximum(1.5)
    hRat.SetMinimum(0.65)
    hRat.Draw()


