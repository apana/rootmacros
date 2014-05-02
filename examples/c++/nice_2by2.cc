void prepCanvas(){

  TCanvas *c1 = new TCanvas("c1","Root Canvas",900,20,840,675); // My Default Canvas
  Int_t wtopx,wtopy; UInt_t ww, wh;
  c1->GetCanvasPar(wtopx,wtopy,ww,wh); // Gets Canvas Parameters 
  //cout << wtopx << " " << wtopy << " " << ww << " " << wh << endl;
  //TCanvas *c2 = new TCanvas("c2","Root Canvas 2");
  //TCanvas *c3 = new TCanvas("c3","Root Canvas 3",2);

  pad1 = new TPad("pad1","This is pad1",0.0,0.5,0.5,1.00);
  pad2 = new TPad("pad2","This is pad1",0.5,0.5,1.00,1.00);
  pad3 = new TPad("pad3","This is pad3",0.0,0.0,0.5,0.5);
  pad4 = new TPad("pad4","This is pad4",0.5,0.0,1.00,0.5);

  pad1->UseCurrentStyle();
  pad2->UseCurrentStyle();
  pad3->UseCurrentStyle();
  pad4->UseCurrentStyle();


  // Set the right and left margins for all pads
  Double_t p1_lm=0.100, p3_lm=p1_lm;   // pad1 and 3 left margins
  Double_t p1_rm=0.005, p3_rm=p1_rm;   // pad1 and 3 right margins

  Double_t p2_lm=p1_rm, p4_lm=p1_rm;   
  Double_t p2_rm=p1_lm, p4_rm=p1_lm;  

  pad1->SetLeftMargin(p1_lm); pad1->SetRightMargin(p1_rm);
  pad2->SetLeftMargin(p2_lm); pad2->SetRightMargin(p2_rm);
  pad3->SetLeftMargin(p3_lm); pad3->SetRightMargin(p3_rm);
  pad4->SetLeftMargin(p4_lm); pad4->SetRightMargin(p4_rm);

  // Set the top and bottom margins for all pads
  Double_t p1_tm=0.125, p2_tm=p1_tm;   // pad1 and 2 top margins
  Double_t p1_bm=0.007, p2_bm=p1_bm;   // pad1 and 2 bottom margins

  Double_t p3_tm=p1_bm, p4_tm=p2_bm;   
  Double_t p3_bm=p1_tm, p4_bm=p2_tm;  

  pad1->SetTopMargin(p1_tm); pad1->SetBottomMargin(p1_bm);
  pad2->SetTopMargin(p2_tm); pad2->SetBottomMargin(p2_bm);
  pad3->SetTopMargin(p3_tm); pad3->SetBottomMargin(p3_bm);
  pad4->SetTopMargin(p4_tm); pad4->SetBottomMargin(p4_bm);

  pad1->Draw();
  pad2->Draw();
  pad3->Draw();
  pad4->Draw();

}

void setHistColorandMarker(TH1F* h, Int_t col, Int_t mk){

  h->SetLineColor(col); 
  h->SetMarkerColor(col); 
  h->SetMarkerStyle(mk); 

  Float_t title_s=0.05;
  h->SetTitleSize(title_s,"x"); // axis title size
  h->SetTitleSize(title_s,"y");

  Float_t label_s=0.04;
  h->SetLabelSize(label_s,"x"); // axis label size
  h->SetLabelSize(label_s,"y");
}

void nice_2by2(){

  gROOT->ForceStyle();
  gStyle->SetOptLogy(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);

  prepCanvas();

  //gStyle->SetPadColor(kRed);
  //gStyle->SetCanvasColor(kBlue);


  TFile *_file0 = TFile::Open("mcanalysis_mcone5_eta5.2_noPU.root");
  TFile *_file1 = TFile::Open("mcanalysis_mcone5_eta5.2_PU.root");

  //_file1->ls();

  bool plotRec=true, plotRat=true; 

  TString hbase="Calopt"; // Genpt or Calopt
  TString xaxis="CaloJet p_{T} (GeV/c)";
  TString yaxis="Entries";
  if ( ! plotRec){
    hbase="Genpt";
    xaxis="GenJet p_{T} (GeV/c)";
  }
  if (plotRat) {
    yaxis="Ratio";
    gStyle->SetOptLogy(0);
  }

  TString hname0=hbase + "_Barrel";
  TString hname1=hbase + "_1.4eta2.4";
  TString hname2=hbase + "_2.4eta3.0";
  TString hname3=hbase + "_3.0eta5.2";

  TString hlabel1=" | y | < 1.4" ;
  TString hlabel2=" 1.4 < | y | < 2.4" ;
  TString hlabel3=" 2.4 < | y | < 3.0" ;
  TString hlabel4=" 3.0 < | y | < 5.2" ;

  TH1F *h0_no=GetHist(_file0,hname0); if (!h0_no) return;
  TH1F *h0_pu=GetHist(_file1,hname0); if (!h0_pu) return;

  TH1F *h1_no=GetHist(_file0,hname1); if (!h1_no) return;
  TH1F *h1_pu=GetHist(_file1,hname1); if (!h1_pu) return;

  TH1F *h2_no=GetHist(_file0,hname2); if (!h2_no) return;
  TH1F *h2_pu=GetHist(_file1,hname2); if (!h2_pu) return;

  TH1F *h3_no=GetHist(_file0,hname3); if (!h3_no) return;
  TH1F *h3_pu=GetHist(_file1,hname3); if (!h3_pu) return;

  Double_t rebin=4.;
  h0_no->Rebin(rebin);   h0_pu->Rebin(rebin);
  h1_no->Rebin(rebin);   h1_pu->Rebin(rebin);
  h2_no->Rebin(rebin);   h2_pu->Rebin(rebin);
  h3_no->Rebin(rebin);   h3_pu->Rebin(rebin);


  h0_no->Sumw2(); h0_pu->Sumw2(); 
  h1_no->Sumw2(); h1_pu->Sumw2(); 
  h2_no->Sumw2(); h2_pu->Sumw2(); 
  h3_no->Sumw2(); h3_pu->Sumw2(); 
 

  TH1F* h_rat0 = (TH1F*)h0_no->Clone(); h_rat0->SetName("Ratio0"); h_rat0->SetTitle("RATIO_0");
  TH1F* h_rat1 = (TH1F*)h1_no->Clone(); h_rat1->SetName("Ratio1"); h_rat1->SetTitle("RATIO_1");
  TH1F* h_rat2 = (TH1F*)h2_no->Clone(); h_rat2->SetName("Ratio2"); h_rat2->SetTitle("RATIO_2");
  TH1F* h_rat3 = (TH1F*)h3_no->Clone(); h_rat3->SetName("Ratio3"); h_rat3->SetTitle("RATIO_3");

  TH1F *h0=h0_pu, *h1=h1_pu, *h2=h2_pu, *h3=h3_pu;
  if (plotRat){
    h0=h_rat0; h1=h_rat1; h2=h_rat2; h3=h_rat3;
  }

  h_rat0->Divide(h0_pu,h0_no,1.,1.," ");
  h_rat1->Divide(h1_pu,h1_no,1.,1.," ");
  h_rat2->Divide(h2_pu,h2_no,1.,1.," ");
  h_rat3->Divide(h3_pu,h3_no,1.,1.," ");

  Double_t xmin=0.0, xmax=179.99;
  //Double_t ymin=1.e-1, ymax=1.e3;
  h0->GetXaxis()->SetRangeUser(xmin,xmax); // Set the range
  h1->GetXaxis()->SetRangeUser(xmin+0.01,xmax); // Set the range
  h2->GetXaxis()->SetRangeUser(xmin,xmax); // Set the range
  h3->GetXaxis()->SetRangeUser(xmin+0.01,xmax); // Set the range

  if (plotRat) {
    Double_t ymin=0., ymax=2.99;
    h0->GetYaxis()->SetRangeUser(ymin+0.01,ymax); // Set the range
    h1->GetYaxis()->SetRangeUser(ymin+0.01,ymax); // Set the range
    h2->GetYaxis()->SetRangeUser(ymin,ymax); // Set the range
    h3->GetYaxis()->SetRangeUser(ymin,ymax); // Set the range
  }

  Int_t colNo=kMagenta, colPU=kBlue, colRat=kBlack;
  Int_t mkSty=20;

  setHistColorandMarker(h0_no, colNo, mkSty);
  setHistColorandMarker(h1_no, colNo, mkSty);
  setHistColorandMarker(h2_no, colNo, mkSty);
  setHistColorandMarker(h3_no, colNo, mkSty);

  setHistColorandMarker(h0_pu, colPU, mkSty);
  setHistColorandMarker(h1_pu, colPU, mkSty);
  setHistColorandMarker(h2_pu, colPU, mkSty);
  setHistColorandMarker(h3_pu, colPU, mkSty);

  setHistColorandMarker(h_rat0, colRat, mkSty);
  setHistColorandMarker(h_rat1, colRat, mkSty);
  setHistColorandMarker(h_rat2, colRat, mkSty);
  setHistColorandMarker(h_rat3, colRat, mkSty);

  Float_t offpage = 2.05, yoffset=0.005; 
  h0->GetXaxis()->SetLabelOffset(offpage);
  h1->GetXaxis()->SetLabelOffset(offpage); // do not show the x-axis labels on top plots

  h1->GetYaxis()->SetLabelOffset(offpage);
  h3->GetYaxis()->SetLabelOffset(offpage);

  h0->GetYaxis()->SetLabelOffset(yoffset);
  h2->GetYaxis()->SetLabelOffset(yoffset);

  Float_t xoffset = 0.01;
  h2->GetXaxis()->SetLabelOffset(xoffset);
  h3->GetXaxis()->SetLabelOffset(xoffset);


  Float_t xtit=1.1;
  h2->GetXaxis()->SetTitleOffset(xtit);
  h3->GetXaxis()->SetTitleOffset(xtit);

  Float_t ytit=0.85;
  h0->GetYaxis()->SetTitleOffset(ytit);
  h2->GetYaxis()->SetTitleOffset(ytit);


  h0->GetYaxis()->SetTitle(yaxis);
  h2->GetYaxis()->SetTitle(yaxis);

  h2->GetXaxis()->SetTitle(xaxis);
  h3->GetXaxis()->SetTitle(xaxis);


  if (plotRat){
    double minf=0.0, maxf=180.;
    if (plotRec) minf=60.;

    TF1 *myfit = new TF1("P0","pol0",minf,maxf); // Create the fit function
    myfit->SetLineWidth(2);
    myfit->SetLineStyle(2);
    myfit->SetLineColor(kRed);

    pad1->cd();  h_rat0->Draw(); h_rat0->Fit(myfit,"R");
    pad2->cd();  h_rat1->Draw(); h_rat1->Fit(myfit,"R");
    pad3->cd();  h_rat2->Draw(); h_rat2->Fit(myfit,"R");
    pad4->cd();  h_rat3->Draw(); h_rat3->Fit(myfit,"R");
  }else{
    pad1->cd();  h0_pu->Draw(); h0_no->Draw("same");
    pad2->cd();  h1_pu->Draw(); h1_no->Draw("same");
    pad3->cd();  h2_pu->Draw(); h2_no->Draw("same");
    pad4->cd();  h3_pu->Draw(); h3_no->Draw("same");
  }
  //c2.cd();
  
  pad1->cd();
  if ( ! plotRat) {
    Double_t xl1=.55, yl1=0.65, xl2=xl1+.4, yl2=yl1+.15;
    TLegend *leg = new TLegend(xl1,yl1,xl2,yl2);
    leg->AddEntry(h0_no,"No Pile-Up","pl");   // h1 and h2 are histogram pointers
    leg->AddEntry(h0_pu,"Pile-Up included","pl");
    leg->Draw();
  }else {

    Double_t xl1=.55, yl1=0.05, xl2=xl1+.4, yl2=yl1+.1;
    TLegend *leg = new TLegend(xl1,yl1,xl2,yl2);
    leg->AddEntry(myfit,"Constant Fit","l");   // h1 and h2 are histogram pointers
    leg->Draw();

    Int_t txtsize=18;
    Int_t txtfnt=63;
    Int_t txtalign=23;

    TLatex *myTxt = new TLatex();
    myTxt->SetNDC();
    myTxt->SetTextAlign(txtalign);
    myTxt->SetTextFont(txtfnt);
    myTxt->SetTextSizePixels(txtsize);
    Float_t xtxt=.55, ytxt=.7;
    TString txtlabel="#frac{CaloJet p_{T} Spectrum with Pile-Up}{CaloJet p_{T} Spectrum without Pile-Up}";
    if (! plotRec)
      txtlabel="#frac{GenJet p_{T} Spectrum with Pile-Up}{GenJet p_{T} Spectrum without Pile-Up}";
    myTxt->DrawLatex(xtxt,ytxt,txtlabel);
  }

  Int_t txtsize=20;
  Int_t txtfnt=63;
  Int_t txtalign=33;
  Float_t xtxt=.95, ytxt=.925,topoff=-0.1,rightoff=-0.1;

  TLatex *t = new TLatex();
  t->SetNDC();
  t->SetTextAlign(txtalign);
  t->SetTextFont(txtfnt);
  t->SetTextSizePixels(txtsize);


              t->DrawLatex(xtxt,ytxt+topoff,hlabel1);
  pad2->cd(); t->DrawLatex(xtxt+rightoff,ytxt+topoff,hlabel2);
  pad3->cd(); t->DrawLatex(xtxt,ytxt,hlabel3);
  pad4->cd(); t->DrawLatex(xtxt+rightoff,ytxt,hlabel4);

}
