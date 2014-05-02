Double_t fitf(Double_t *x, Double_t *par)
{
  Double_t fitval;

  fitval=par[0]/x[0]**(par[1])+par[2]/x[0]**(par[3]);
  //fitval=par[0]/x[0]**(par[1]);
  //fitval=exp(par[0]+par[1]*x[0]);
  return fitval;

}
void fitxs(){
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

  TH1F *copy_h = (TH1F*)h->Clone(); copy_h->SetName("hnew");
  h->Draw();

  Double_t xminf= 30.,xmaxf=290.;

  // 2par fit between 40-290 set par(0)=2e16,par(1)=6.
  //TF1 *fitter = new TF1("fitf",fitf,xminf,xmaxf,2);
  //fitter->SetParameters(4e16,6.);


  TF1 *fitter = new TF1("fitf",fitf,xminf,xmaxf,4);
  fitter->SetParameters(2e16,6.,-6e8,4.);
  copy_h->Fit(fitter,"RQ");

  cout << "par(0) " << fitter->GetParameter(0) << endl;
  cout << "par(1) " << fitter->GetParameter(1) << endl;
  cout << "par(2) " << fitter->GetParameter(2) << endl;
  cout << "par(3) " << fitter->GetParameter(3) << endl;

}
