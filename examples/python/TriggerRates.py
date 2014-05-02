from ROOT import gROOT, gStyle, gSystem, TCanvas, TF1, TFile, TH1F
from ROOT import TColor, TLine, TLegend, TLatex
from ROOT import SetOwnership

from ROOT import gDirectory, gPad

import sys,string,math,os

# import myPyRootSettings
sys.path.append(os.path.join(os.environ.get("HOME"),'rootmacros'))
from myPyRootSettings import prepPlot

def printTriggerRates(h,minRate=0.0):

    nbins=h.GetNbinsX()

    for ibin in range(1,nbins+1):

        cont=h.GetBinContent(ibin);
        err =h.GetBinError(ibin);
        if cont>minRate:
            print ibin, h.GetXaxis().GetBinLabel(ibin), cont, " +- ", err


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

    RootDir="hists"
    RootFile="analyzeTriggerResults_HLT.root"
    HistFile=os.path.join(RootDir,RootFile)


    HistName="hltrates"

    f1 = TFile(HistFile)
    # f1.ls()
    f1.cd("triggerRates")
    hHlt = gDirectory.Get(HistName)


    cname="HLT Rates"
    c1 = prepPlot("c1",cname,250,20,1000,500)
    c1.SetLeftMargin(.2);
    c1.SetRightMargin(.01)
    c1.SetBottomMargin(.5);   
    c1.SetLogy(1);    

    # i1=90; i2=110
    i1=96; i2=110
    hHlt.GetXaxis().SetRange(i1,i2)
    hHlt.GetXaxis().LabelsOption("u")  # "u" or "d"
    hHlt.Draw()


    printRates=True
    if (printRates): printTriggerRates(hHlt,4.9)
        
