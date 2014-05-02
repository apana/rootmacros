{
  //#include <sstream>
  //#include <stdexcept>


  gROOT->Reset();           // Resetting ROOT (Not to be use in named macros)
  gSystem->Load("libPhysics.so"); // Loading Physics library (TVector3)

  gStyle->SetPadLeftMargin(0.12);

  string rootfile="cosmics_proc.root";
  TFile *f0 = TFile::Open(rootfile.c_str());
  f0->GetListOfKeys()->Print();

  string hname1="Energy (HB 1,56,1)";
  string hname2="Energy (HB 4,56,1)";
  string hname3="Energy (HB 12,56,1)";
  string hname4="Energy (HB 16,56,1)";

  TH1F *h1 = (TH1F*)f0->Get(hname1.c_str());  
  TH1F *h2 = (TH1F*)f0->Get(hname2.c_str());  
  TH1F *h3 = (TH1F*)f0->Get(hname3.c_str());  
  TH1F *h4 = (TH1F*)f0->Get(hname4.c_str());  

  Int_t ix1=750, iy1=20, ixl=650, iyl=650;
  TCanvas *c1 = new TCanvas("c1","Root Canvas",ix1,iy1,ixl,iyl);

  Float_t lpad=gStyle->GetPadLeftMargin();
  cout<< "Left Pad Margin:" << lpad <<endl;

  Float_t ytit=1.65;
  h1->GetYaxis()->SetTitleOffset(ytit);
  h1.Draw();

}
