{
  gROOT->Reset();                // Reseting ROOT
  //gROOT->SetStyle("Plain");
  gROOT->SetStyle("Default");

  //gStyle->SetCanvasBorderMode(0);     // turn off canvas borders
  //gStyle->SetPadBorderMode(0);

  Float_t val=0.1;

  gStyle->SetPadTopMargin(0.025);
  gStyle->SetPadRightMargin(0.025);
  gStyle->SetPadBottomMargin(val);
  gStyle->SetPadLeftMargin(val);

  gStyle->SetLabelOffset(0.005,"y");
  gStyle->SetTitleOffset(1.1,"y");


  gStyle->SetOptStat(111);
  gStyle->SetOptTitle(0);
  Int_t ips = 0;
  Int_t itype=100114; // 113 for eps

  TString dirname = ".";
  TString srcname = "hlt1jet_mc_120.root";

  srcname = dirname + "/" + srcname;
  // clear memory of file name
  delete gROOT->GetListOfFiles()->FindObject(srcname);

  // open source file
  cout << "Rootfile:" << srcname << endl;
  if( gSystem->AccessPathName(srcname) ) {
    cout << endl << "File: " << srcname << " not there!!!" << endl << endl;
    return;
  }
  TFile *srcfile = new TFile(srcname);

  srcfile->GetListOfKeys()->Print();

  // Create the canvas
  Int_t ix1=900, iy1=20, ixl=650, iyl=650;
  TCanvas *c1 = new TCanvas("c1","Root Canvas",ix1,iy1,ixl,iyl);
  c1->SetFillColor(17);

  TString psfile="/dev/null";
  if (ips==1){
    psfile="plot_2x2";
    if (itype==113)
      psfile = psfile + ".eps";
    else
      psfile = psfile + ".ps";
  }
  TPostScript ps(psfile,itype);// if no itype given, format is determined by extension

  //                                       xl  yl  xu  yu   
  //pad1 = new TPad("pad1","This is pad1",0.01,0.51,0.49,0.99);
  //pad2 = new TPad("pad2","This is pad1",0.51,0.51,0.99,0.99);
  //pad3 = new TPad("pad3","This is pad3",0.01,0.01,0.49,0.49);
  //pad4 = new TPad("pad4","This is pad4",0.51,0.01,0.99,0.49);

  pad1 = new TPad("pad1","This is pad1",0.0,0.5,0.5,1.0);
  pad2 = new TPad("pad2","This is pad1",0.5,0.5,1.0,1.0);
  pad3 = new TPad("pad3","This is pad3",0.0,0.0,0.5,0.5);
  pad4 = new TPad("pad4","This is pad4",0.5,0.0,1.0,0.5);

  //pad1->SetTopMargin(0.05);
  //pad2->SetTopMargin(0.05);
  pad1->Draw();
  pad2->Draw();
  pad3->Draw();
  pad4->Draw();

  string hname1="GenZMass";
  string hname2="GenZMass";
  string hname3="GenJets";
  string hname4="TriggerJets";

  TH1F *h1 = (TH1F*)srcfile->Get(hname1.c_str());
  TH1F *h2 = (TH1F*)srcfile->Get(hname2.c_str());
  TH1F *h3 = (TH1F*)srcfile->Get(hname3.c_str());
  TH1F *h4 = (TH1F*)srcfile->Get(hname4.c_str());

  h1->UseCurrentStyle();
  h2->UseCurrentStyle();
  h3->UseCurrentStyle();
  h4->UseCurrentStyle();

  h1->GetXaxis()->SetTitle("Mass (GeV/c^{2})");
  h1->GetYaxis()->SetTitle("Entries");

  h2->GetXaxis()->SetTitle("Mass (GeV/c^{2})");
  h2->GetYaxis()->SetTitle("Entries");

  h3->GetXaxis()->SetTitle("Gen pT (GeV/c)");
  h3->GetYaxis()->SetTitle("Entries");

  
  h4->GetXaxis()->SetTitle("Rec pT (GeV/c)");
  h4->GetYaxis()->SetTitle("Entries");
  h4->GetYaxis()->SetLabelOffset(0.0005);

  h3->GetXaxis()->SetRangeUser(0.,750.);
  h4->GetXaxis()->SetRangeUser(0.,750.);


  Int_t txtsize=17;
  Int_t txtfnt=63;
  Int_t txtalign=13;
  Float_t xtxt=.15, ytxt=.85;

  pad1->cd();
  h1->Draw();
  TLatex *t = new TLatex();
  t->SetNDC();
  t->SetTextAlign(txtalign);
  t->SetTextFont(txtfnt);
  t->SetTextSizePixels(txtsize);
  t->DrawLatex(xtxt,ytxt,"From Generated 4-vector");


  pad2->cd();
  h2->Draw();
  TLatex *t = new TLatex();
  t->SetNDC();
  t->SetTextAlign(txtalign);
  t->SetTextFont(txtfnt);
  t->SetTextSizePixels(txtsize);
  t->DrawLatex(xtxt,ytxt,"From Daughters 4-vectors");

  pad3->cd();
  h3->Draw();
  TLatex *t = new TLatex();
  t->SetNDC();
  t->SetTextAlign(txtalign);
  t->SetTextFont(txtfnt);
  t->SetTextSizePixels(txtsize);
  t->DrawLatex(xtxt,ytxt,"Gen pT (Two Daughters)");

  pad4->cd();
  h4->Draw();
  gPad->SetLogy(1);
  TLatex *t = new TLatex();
  t->SetNDC();
  t->SetTextAlign(txtalign);
  t->SetTextFont(txtfnt);
  t->SetTextSizePixels(txtsize);
  //t->DrawLatex(xtxt,ytxt,"Rec pT -- CaloJets");
  gPad->Modified();
  gPad->Update();

  //c1->Update();
  cout << "Postscript: " << psfile << endl;
  ps.Close();

}
