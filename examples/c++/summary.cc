//
//  Summary of HO Weighting factors
//
{
  
  gROOT->Reset();           // Resetting ROOT (Not to be use in named macros)
  gSystem->Load("libPhysics.so"); // Loading Physics library (TVector3)
  gSystem->Load("myFuncs_cc.so"); // Loading Physics library (TVector3)

  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  gStyle->SetTitleOffset(1.2,"y");
  Int_t ips=1;
  
  const int nBins = 12;
  Double_t xx[nBins] =    {0.0, 1.0,  1.4,  1.6,  1.8,  2.0,  2.2,  2.4,  2.6, 2.8, 3.0, 4.0};
  Double_t mean[nBins] = {287.5, 293.4, 296.9,298.4,300.0,301.0,303.1,304.5,305.9,307.3,308.7,316.1};
  Double_t rms[nBins] =   {52.93,45.76, 43.42,42.80,42.33,42.03,42.03,42.08,42.12,42.44,42.86,45.96};

  Double_t emean[nBins] =  {.250,.216,.205,.202,.200,.198,.198,.199,.199,.201,.262,.217};
  Double_t erms[nBins] =   {.177,.153,.145,.142,.141,.140,.140,.141,.140,.142,.185,.154};


  TH1F *h1 = new TH1F("histo","HO Weighting",105,-0.5,5.);
  h1->SetMarkerStyle(21);
  Int_t ibin;
  Double_t ratio,erat;

  for(int i=0; i < nBins;  i++){
    ibin=h1->GetXaxis()->FindBin(xx[i]);
    cout << " i = " << i << " " << xx[i] << endl;

    ratio=rms[i]/mean[i];
    erat=ratio*sqrt((emean[i]/mean[i])**2+(erms[i]/rms[i])**2);

    cout << " ratio = " << ratio << " +- " << erat<< endl;
    
    h1->SetBinContent(ibin,ratio);
    h1->SetBinError(ibin,erat);
  }


  // Create the canvas
  Int_t ix1=750, iy1=20, ixl=600, iyl=440;
  TCanvas *c1 = new TCanvas("c1","Root Canvas",ix1,iy1,ixl,iyl);

  if (ips == 1){
    cout << "PS file: " << "ho_summary.eps" << endl;
    TPostScript ps("ho_summary.eps",113);
  }

  h1->SetMaximum(0.19);
  h1->SetMinimum(0.11);
  h1->GetXaxis()->SetRangeUser(0.25,5.);
  h1->GetXaxis()->SetTitle("Weighting Constant (k)");
  h1->GetYaxis()->SetTitle("RMS/Mean");
  h1->GetYaxis()->SetNdivisions(606);
  h1->Draw();

  c1.Update();
  if (ips == 1)
    ps.Close();

}
