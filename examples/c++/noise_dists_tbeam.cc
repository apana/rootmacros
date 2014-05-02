//
//  generate nice picture of 300GeV pion into HCAL
//
{
  gROOT->Reset();                // Reseting ROOT
  gSystem->Load("libPhysics.so"); // Loading Physics library (TVector3)
  gROOT->SetStyle("Plain");

  //gStyle->SetStatFont(130);
  gStyle->SetStatFontSize(.06);
  gStyle->SetPaperSize(20,20);

  Float_t dum = gStyle->GetTitleOffset("Y");
  cout << "Dum:" << dum << endl;

  //  gStyle->SetStatY(.95);

  Int_t ips = 1;
  Int_t type = 113;
  Int_t ilogy = 1;
  Int_t ipeds = 0;

  // Create the canvas
  Int_t ix1=900, iy1=20, ixl=650, iyl=650;
  TCanvas *c1 = new TCanvas("c1","Root Canvas",ix1,iy1,ixl,iyl);

  gPad->SetLeftMargin(0.015);
  //  c1->SetRightMargin(0.005);
  if (ips == 1){
    string psfile="noise_dists_tbeam";
    if (ipeds == 1) psfile=psfile + "_peds";
    if (ilogy == 1) psfile=psfile + "_logy";
    psfile=psfile + ".eps";
    cout << "Postscript: " << psfile << endl;
    TPostScript ps(psfile.c_str(),type);
  }
  c1->Divide(2,2);

  string rootfile = 
    "/home/apana/cms/cosmics/CMSSW_0_3_0/src/Tutorial/Analysis1/test/testbeam";
  if (ipeds == 1) rootfile=rootfile + "_peds";
  rootfile=rootfile + ".root";

  cout << "Rootfile:" << rootfile << endl;

  TFile *f0 = TFile::Open(rootfile.c_str());


  string hname1="Energy (HB 1,3,1)";
  string hname2="Energy (HB 2,1,1)";
  string hname3="Energy (HB 13,4,1)";
  string hname4="Energy (HB 3,3,1)";

  TKey *key1 = f0->FindKey(hname1.c_str()); 
  TKey *key2 = f0->FindKey(hname2.c_str()); 
  TKey *key3 = f0->FindKey(hname3.c_str()); 
  TKey *key4 = f0->FindKey(hname4.c_str()); 

  //cout << "-- Key: " << key << endl;
  if (key1 ==0){
    cout << "!!Histogram does not exist!!" << endl;
    throw 1;
  }
  if (key2 ==0){
    cout << "!!Histogram does not exist!!" << endl;
    throw 1;
  }
  if (key3 ==0){
    cout << "!!Histogram does not exist!!" << endl;
    throw 1;
  }
  if (key4 ==0){
    cout << "!!Histogram does not exist!!" << endl;
    throw 1;
  }

  TH1F *h1 = (TH1F*)f0->Get(hname1.c_str());  
                                    // c_str() returns a const pointer to string hname1

  TH1F *h2 = (TH1F*)f0->Get(hname2.c_str());  
                                    // c_str() returns a const pointer to string hname1
  TH1F *h3 = (TH1F*)f0->Get(hname3.c_str());  
                                    // c_str() returns a const pointer to string hname1
  TH1F *h4 = (TH1F*)f0->Get(hname4.c_str());  
                                    // c_str() returns a const pointer to string hname1


  h1->GetXaxis()->SetRangeUser(-2.,5.);
  h2->GetXaxis()->SetRangeUser(-2.,5.);
  h3->GetXaxis()->SetRangeUser(-2.,5.);
  h4->GetXaxis()->SetRangeUser(-2.,5.);

  TGaxis::SetMaxDigits(4);
  Float_t ytit=1.45;
  if (ilogy == 1) ytit=1.25;

  h1->GetYaxis()->SetTitleOffset(ytit);
  h2->GetYaxis()->SetTitleOffset(ytit);
  h3->GetYaxis()->SetTitleOffset(ytit);
  h4->GetYaxis()->SetTitleOffset(ytit);

  Int_t ndiv =512;

  h1->GetXaxis()->SetTitle("Energy (GeV)");
  h1->GetYaxis()->SetTitle("Entries");
  h1->GetXaxis()->SetNdivisions(ndiv);

  h2->GetXaxis()->SetTitle("Energy (GeV)");
  h2->GetYaxis()->SetTitle("Entries");
  h2->GetXaxis()->SetNdivisions(ndiv);

  h3->GetXaxis()->SetTitle("Energy (GeV)");
  h3->GetYaxis()->SetTitle("Entries");
  h3->GetXaxis()->SetNdivisions(ndiv);

  h4->GetXaxis()->SetTitle("Energy (GeV)");
  h4->GetYaxis()->SetTitle("Entries");
  h4->GetXaxis()->SetNdivisions(ndiv);


  TH1F *copy_h1 = (TH1F*)h1->Clone();
  TH1F *copy_h2 = (TH1F*)h2->Clone();
  TH1F *copy_h3 = (TH1F*)h3->Clone();
  TH1F *copy_h4 = (TH1F*)h4->Clone();

  c1->cd(1);
  gPad->SetLogy(ilogy);
  Float_t dum = gStyle->GetTitleOffset("Y");
  cout << "Dum:" << dum << endl;

  h1.Draw();

  c1->cd(2);
  gPad->SetLogy(ilogy);
  h2.Draw();

  c1->cd(3);
  gPad->SetLogy(ilogy);
  h3.Draw();

  c1->cd(4);
  gPad->SetLogy(ilogy);
  h4.Draw();

  c1.Update();  
  if (ips == 1)
    ps.Close();
}
