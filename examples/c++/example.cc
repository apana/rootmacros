void example(){

  MyStyle->SetOptTitle(1);
  MyStyle->SetOptStat(0);
  MyStyle->SetTitleOffset(1.1,"y");

  //gPad->SetLogy(1);
  gROOT->ForceStyle();

  TString rootname = "./xxx.root";
  TFile *rootfile=OpenRootFile(rootname); if (!rootfile) return;
  //rootfile->GetListOfKeys()->Print();


  TString hname="EBDigis";

  TH1F *h=GetHist(rootfile,hname); if (!h) return;

  h->SetLineColor(kRed);
  h->GetXaxis()->SetRangeUser(180.,250.);

  h->Draw();

}
