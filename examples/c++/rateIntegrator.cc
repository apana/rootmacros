void rateIntegrator(){
  MyStyle->SetOptTitle(0);
  MyStyle->SetOptStat(0);
  MyStyle->SetTitleOffset(1.1,"y");
  MyStyle->SetOptLogy(1);

  gROOT->ForceStyle();

  TString rootname = "./jetspect.root";
  // TString rootname = "./hlt1jet60_unweighted.root";
  TFile *rootfile=OpenRootFile(rootname); if (!rootfile) return;
  rootfile->GetListOfKeys()->Print();

  TString hname="gen_JetPt";
  TH1F *h=GetHist(rootfile,hname); if (!h) return;

  TH1F *copy_h1 = (TH1F*)h->Clone(); copy_h1->SetName("h1");
  TH1F *copy_h2 = (TH1F*)h->Clone(); copy_h2->SetName("h2");
  copy_h1->Reset();
  copy_h2->Reset();

  Int_t nbins=copy_h1->GetNbinsX();
  cout << "Number of bins: " << nbins << endl;

  copy_h1->SetLineColor(kRed);
  copy_h2->SetLineColor(kBlue);

  copy_h2->GetYaxis()->SetTitle("Rate (HZ)");

  Float_t dy=1.;  // take out average over rapidity

  for (Int_t ibin=0; ibin<nbins; ++ibin){
    Float_t cont=h->GetBinContent(ibin+1);
    Float_t err =h->GetBinError(ibin+1);
    Float_t bw  =h->GetBinWidth(ibin+1);
    bw=1.;

    Float_t fact=bw*dy;

    //cout << ibin << " " << cont << " +- " << err << " -- BinWidth: " << bw << endl;
    cont=cont*fact;
    err = err*fact;
    
    copy_h1->SetBinContent(ibin+1,cont);
    copy_h1->SetBinError(ibin+1,err);
  }

  // now the integrated rate
  // error on rate is calculated assuming error on integral is dominated by current bin error
  for (Int_t ibin=0; ibin<nbins; ++ibin){
    Int_t ibin1=ibin+1;
    Int_t ibin2=nbins;

    Float_t cont =copy_h1->GetBinContent(ibin+1);
    Float_t err  =copy_h1->GetBinError(ibin+1);

    Float_t ferr=err/cont;

    Float_t fint=copy_h1->Integral(ibin1,ibin2,"width");

    //cout << ibin << "  -- Integral: " << fint << endl;
    cont=fint;
    err = ferr*fint;
    
    copy_h2->SetBinContent(ibin+1,cont);
    copy_h2->SetBinError(ibin+1,err);
  }
  //cout << "  -- Integral: " << copy_h1->Integral() << endl;

  // now multiply by luminosity to get total rate;
  //float Lumo=2.e33;
  float conv=1e-36; // conversion from pb to cm^2
  float Lumo=1.e32;
  
  Float_t fact=Lumo*conv;

  cout << fact << endl;
  copy_h2->Scale(fact);

  copy_h2->Draw("");
  //copy_h1->Draw("same");

  //h->Draw("same");

  //copy_h1->Draw("");
  
}
