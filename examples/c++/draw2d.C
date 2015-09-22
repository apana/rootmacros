{

  gROOT->Reset();
  gStyle->SetPalette(1);

  //TFile *_file0 = new TFile("analyzeL1_239895Splashes_beam1.root");
  //TFile *_file0 = new TFile("analyzeL1_239895All_beam2.root");
  // TFile *_file0 = new TFile("analyzeL1_247644_ExpressDS_HLT_ZeroBias_v1.root");
  // TFile *_file0 = new TFile("analyzeL1_247644_ExpressDS_HLT_Physics_v1.root");
  _file0->ls();

  string hname="hTrigVsBx";
  TH2F *h = (TH2F*)_file0->Get(hname.c_str());

  // h->GetXaxis()->SetRangeUser(0,400);
  h->GetXaxis()->SetRangeUser(0,2200);
  h->GetYaxis()->SetRangeUser(0,7);
  h->SetMinimum(0.01);
  h->SetMarkerSize(1.3);
  h->Draw("colz,text45");

}
