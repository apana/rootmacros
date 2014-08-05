#include "rootfuncs.h"

class SetupHistos
{
public:
  //constructor
  SetupHistos(TString Distribution )
  {
    std::cout << "Setting up comparisions for " << Distribution << std::endl;
    cutString_="";
    rebin_=1; xmin_=0.; xmax_=1000.; ymin_=0.1; ymax_=-1; 
    if (Distribution == "RelaxedTau" || Distribution == "IsolatedTau"){
      nbins_=64;
      xmax_=64;
    } else if (Distribution == "RelaxedEG" || Distribution == "IsolatedEG"){
      nbins_=64;
      xmax_=64;
      rebin_=4;
    } else if ( Distribution == "MET" || Distribution == "MHT"){ 
      xmax_=460;
      nbins_=100;
      rebin_=5;
    } else if ( Distribution == "SET" || Distribution == "SHT"){ 
      xmax_=1200;
      nbins_=100;
      rebin_=5;
    } else if ( Distribution == "CorrJet"){ 
      xmax_=900;
      nbins_=100;
      rebin_=5;
    }

    varString_= "UCTCandidates_UCT2015Producer_"+Distribution+"Unpacked_ReRunningL1.obj.pt()";
    hname1_= Distribution + "_UCT1", hname2_=Distribution +"_UCT2";
    h1_ = new TH1F(hname1_,hname1_,nbins_,xmin_,xmax_);
    h2_ = new TH1F(hname2_,hname2_,nbins_,xmin_,xmax_);
    h1_->Sumw2();  h2_->Sumw2();
 
    h1_->SetLineColor(kRed);
    h2_->SetLineColor(kBlue);

  }
  ~SetupHistos(){}

  int getNbins() const {return nbins_; }
  int getRebin() const {return rebin_; }
  float getYmax() const {return ymax_;}
  float getYmin() const {return ymin_;}
  TString getVarString() const {return varString_; }
  TString getCutString() const {return cutString_; }
  TH1F *getHist1() {return h1_;}
  TH1F *getHist2() {return h2_;}
private:

  int nbins_, rebin_;
  float xmin_, xmax_;
  float ymin_, ymax_;

  TString hname1_, hname2_, varString_, cutString_;
  TH1F *h1_,*h2_;

};

void compUCTVers(){

  gROOT->Reset();
  gStyle->SetOptTitle(1);
  gStyle->SetOptStat(1);
  //gStyle->SetTitleOffset(0.8,"y");
  gStyle->SetOptLogy(1);
  gStyle->SetOptTitle(0);
  gROOT->ForceStyle();

 
  TString rootnameUCT1 = "test/out_uct2015corebranch.root";  TString label1 = "core";
  TString rootnameUCT2 = "test/out_v47branch.root";  TString label2 = "v47";
  TString treename  = "Events";
  
  TString Var;

  // Var        = "IsolatedTau";
  // Var        = "RelaxedTau";
  // Var        = "RelaxedEG";
  // Var        = "IsolatedEG";
  // Var        = "CorrJet";
  // Var        = "MET";
  Var        = "MHT";
  //Var        = "SET";
  //Var        = "SHT";

 
  TFile *rootUCT1=OpenRootFile(rootnameUCT1); if (!rootUCT1) return;
  TFile *rootUCT2=OpenRootFile(rootnameUCT2); if (!rootUCT2) return;
  //rootUCT->GetListOfKeys()->Print();

  SetupHistos myHists(Var);
  int nbins=myHists.getNbins();
  int rebin=myHists.getRebin();

  TH1F* hUCT1=myHists.getHist1();
  TH1F* hUCT2=myHists.getHist2();
  TString hname1=hUCT1->GetName();
  TString hname2=hUCT2->GetName();
  TString varString=myHists.getVarString();
  TString cutString=myHists.getCutString();

  // TTree *_treeUCT1 = dynamic_cast<TTree*>(rootUCT1->Get(treename));
  TTree* _treeUCT1 = (TTree*)rootUCT1->Get(treename);
  if (! _treeUCT1) {
    cout << " Treename " << treename << " not found" << endl;
    return;
  }

  // TTree *_treeUCT2 = dynamic_cast<TTree*>(rootUCT2->Get(treename));
  TTree* _treeUCT2 = (TTree*)rootUCT2->Get(treename);
  if (!_treeUCT2) {
    cout << " Treename " << treename << " not found" << endl;
    return;
  }

  _treeUCT1->Project(hname1,varString,cutString);
  _treeUCT2->Project(hname2,varString,cutString);

  TCanvas *c1= new TCanvas("c1","Root Canvas 1");

  if (myHists.getYmax() > 0.){
    hUCT1->GetYaxis()->SetRangeUser(myHists.getYmin(),myHists.getYmax());
    hUCT2->GetYaxis()->SetRangeUser(myHists.getYmin(),myHists.getYmax());
  }
  hUCT1->Rebin(rebin);
  hUCT2->Rebin(rebin);
  hUCT1->Draw();
  hUCT2->Draw("sames");
  // hL1T->Draw();
 
  Double_t xl1=.16, yl1=0.16, xl2=xl1+.3, yl2=yl1+.125;
  TLegend *leg = new TLegend(xl1,yl1,xl2,yl2);

  leg->SetTextSize(.03);
  leg->AddEntry(hUCT1,"UCT2015 -- " +label1,"pl");   // h1 and h2 are histogram pointers
  leg->AddEntry(hUCT2,"UCT2015 -- " +label2,"pl");
  leg->Draw();

  TLatex *t = new TLatex();
  Int_t txtalign=13;
  Float_t xtxt=.605, ytxt=.8;
  t->SetNDC();
  t->SetTextAlign(txtalign);
  //t->SetTextFont(txtfnt);
  //t->SetTextSizePixels(txtsize);
  t->DrawLatex(xtxt,ytxt,Var);

  if( !c1->IsZombie() ) {
    gPad->Update();
    TPaveStats *tt1 = (TPaveStats*)hUCT1->GetFunction("stats");
    tt1->SetTextColor(hUCT1->GetLineColor());
    TPaveStats *tt2 = (TPaveStats*)hUCT2->GetFunction("stats");
    tt2->SetTextColor(hUCT2->GetLineColor());
    double x1 = tt1->GetX1NDC();    double y1 = tt1->GetY1NDC();
    double x2 = tt1->GetX2NDC();    double y2 = tt1->GetY2NDC();
    //double dx = x2-x1;              double dy = y2-y1;
    double dy = 0.15;
    double dx = 0.20;
 
    // //set stat boxes one on top of the other
    // tt1->SetY2NDC(y2);        tt1->SetX2NDC(x2);
    // tt1->SetY1NDC(y2-dy);     tt1->SetX1NDC(x2-dx);
    // tt2->SetY2NDC(y2-dy);     tt2->SetX2NDC(x2);
    // tt2->SetY1NDC(y2-2*dy);   tt2->SetX1NDC(x2-dx);
 
    // cout << " x1: " << x1 << " x2:" << x2 << endl;
    // cout << " y1: " << y1 << " y2:" << y2 << endl;
 
    tt1->SetY2NDC(y2);        tt1->SetX2NDC(x2);
    tt1->SetY1NDC(y2-dy);     tt1->SetX1NDC(x2-dx);
 
    tt2->SetY2NDC(y2);      tt2->SetX2NDC(x2-dx);
    tt2->SetY1NDC(y2-dy);   tt2->SetX1NDC(x2-2*dx);
    gPad->Modified();   
  }// modify statboxes 
 
 
 //gROOT->Reset();

}
