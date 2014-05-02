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
    WhichCorr="L2L3"
    WhichJets="ak5PFJets"
    # WhichJets="ak5CaloJets"
    if WhichJets=="ak5PFJets":
      # RootFile="jetCorrectionsOnTheFlyExample_L2L3.root"
      RootFile="jetCorrectionsOnTheFlyExample_"+WhichCorr+"_data_r180250.root"
    else:
      RootFile="jetCorrectionsOnTheFlyExample_"+WhichCorr+"_data_"+WhichJets+"r180250.root"

    OutFile="Corr_"+WhichCorr+"_data_"+WhichJets+"r180250.root"
    HistFile=os.path.join(RootDir,RootFile)


    Num="uncorrPt"
    Den="uncorrPt_wt"

    Num="Eta"
    Den="Eta_wt"

    f1 = TFile(HistFile)
    # f1.ls()
    f1.cd("pf")
    hNum = gDirectory.Get(Num)
    hDen = gDirectory.Get(Den)

    hRat= hNum.Clone()
    hRat.SetName("Ratio")
    hRat.Divide(hNum,hDen,1.,1.,"");
    Hlist=TObjArray()
    Hlist.Add(hRat);

    cname="pT"
    c1 = prepPlot("c1",cname,700,20,500,500)
    c1.SetLogy(1);    

    # i1=90; i2=110
    i1=0; i2=500
    hNum.GetXaxis().SetRange(i1,i2)
    hDen.SetLineColor(ROOT.kRed)
    hNum.Draw()
    hDen.Draw("same")

    cname="Ratio"
    c2 = prepPlot("c2",cname,750,120,500,500)
    c2.SetLogy(0);    

    min=0.; max=1.24
    if WhichJets=="ak5CaloJets":
        min=0.
    hRat.SetMaximum(1.24)
    hRat.SetMinimum(0.0)
    hRat.Draw()


    f2=TFile(OutFile,"RECREATE")
    f2.cd()
    hRat.Write()
    f2.Close()


