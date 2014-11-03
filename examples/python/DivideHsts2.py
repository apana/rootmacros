from ROOT import *

import sys,string,math,os

# import myPyRootSettings
sys.path.append(os.path.join(os.environ.get("HOME"),'rootmacros'))
from myPyRootMacros import SetStyle, prepPlot, DrawText, PrepLegend

if __name__ == '__main__':

    SetStyle("MyStyle")

    RootDir="."

    RootFile1="results/results_13TeV_40PU_25ns_62X_ReEmul2015_L1Emu_12x12_RATE.root"
    RootFile2="results/results_13TeV_40PU_25ns_62X_ReEmul2015_L1Emu_RATE.root"

    HistFile1=os.path.join(RootDir,RootFile1)
    HistFile2=os.path.join(RootDir,RootFile2)


    ## Name="nIsoEGVsPt" ; cName="SingleIsoEG"
    Name="nTauVsPt" ; cName="Tau"

    f1 = TFile(HistFile1)
    f1.ls()
    
    hNum = gDirectory.Get(Name)
    f2 = TFile(HistFile2)
    hDen = gDirectory.Get(Name)

    rebin=1
    if Name == "nTauVsPt":
        rebin=4

    hNum.Rebin(rebin); hNum.Scale(1./float(rebin))
    hDen.Rebin(rebin); hDen.Scale(1./float(rebin))

    hRat= hNum.Clone()
    hRat.SetName("Ratio")
    hRat.Divide(hNum,hDen,1.,1.,"");
    Hlist=TObjArray()
    Hlist.Add(hRat);

    cname="pT"
    c1 = prepPlot("c1",cname,700,20,500,500)
    c1.SetLogy(1);    

    xmin=5; xmax=100
    hNum.GetXaxis().SetRangeUser(xmin,xmax)
    hDen.SetLineColor(ROOT.kRed)
    hNum.Draw()
    hDen.Draw("same")

    xl1=0.5; yl1=.7;
    DrawText(xl1,yl1,cName + " Rate")

    x1=0.5; x2=x1+0.25
    y1=.5; y2=y1+0.15
    leg=PrepLegend(x1,y1,x2,y2,0.038,ROOT.kWhite)
    leg.AddEntry(hNum,"Iso using 12x12s")
    leg.AddEntry(hDen,"Iso using Jets")
    leg.Draw()

    c1.Print(cName + "_rate.gif")

    cname="Ratio"
    c2 = prepPlot("c2",cname,150,120,500,500)
    c2.SetLogy(0);    

    ymin=0.65; ymax=1.1

    hRat.SetMaximum(ymax)
    hRat.SetMinimum(ymin)
    hRat.GetXaxis().SetRangeUser(xmin,xmax)
    hRat.GetYaxis().SetTitle(cname)
    hRat.GetYaxis().SetTitleOffset(1.25);
    hRat.Draw()

    xl1=0.6; yl1=.3;
    DrawText(xl1,yl1,cName + " Rate")
    yl1=yl1-0.05
    DrawText(xl1,yl1,"12x12 / Jet Iso")
    c2.Print(cName + "_ratio.gif")

    raw_input('\npress return to end the program...')
