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

    RootDir="/Users/apana/cms/LPCTRIG/Higgs/testedm10/src/VHbbAnalysis/VHbbDataFormats/bin/"
    RootFile="analyzeHiggs_NoTrig.root"

    HistFile=os.path.join(RootDir,RootFile)

    Deno="genZpt"
    Numer1="genZpt_sj100"
    Numer2="genZpt_dj30"
    Numer3="genZpt_dj50"

    # Numer="genZpt_dj30"
    Numer="genZpt_sj100"

    f1 = TFile(HistFile)
    f1.cd("Higgs")
    f1.ls()

    hDen = gDirectory.Get(Deno)    
    hNum = gDirectory.Get(Numer)

    i1=0; i2=800
    hNum.GetXaxis().SetRangeUser(i1,i2)
    hDen.GetXaxis().SetRangeUser(i1,i2)
    hDen.SetLineColor(ROOT.kRed)

    hRat= hNum.Clone()
    hRat.SetName("Ratio")
    hRat.Divide(hNum,hDen,1.,1.,"B");
    Hlist=TObjArray()
    Hlist.Add(hRat);

    cname="pT"
    c1 = prepPlot("c1",cname,700,20,500,500)
    c1.SetLogy(1);    

    hDen.Draw()
    hNum.Draw("same")

    cname="Ratio"
    c2 = prepPlot("c2",cname,150,120,500,500)
    c2.SetLogy(0);    

    min=0.65; max=1.04

    hRat.SetMaximum(max)
    hRat.SetMinimum(min)
    hRat.Draw()


