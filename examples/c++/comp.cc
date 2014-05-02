//
//  generate plot to compare noise dist with ORCA
//
{
  gROOT->Reset();                // Reseting ROOT
  gSystem->Load("libPhysics.so"); // Loading Physics library (TVector3)
  gROOT->SetStyle("Plain");

  Int_t ips = 1;

  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  //  string rootfile = 
  //  "/home/apana/analysis/cosmics/CMSSW_0_3_0/src/Tutorial/Analysis1/test/cosmics.root";
  string rootfile = 
    "/home/apana/analysis/cosmics/CMSSW_0_3_0/src/Tutorial/Analysis1/test/testbeam.root";
  cout << "Rootfile:" << rootfile << endl;
  TFile *f0 = TFile::Open(rootfile.c_str());

  //  string hname1="Energy (HB 2,20,1)"; // allowed phi channels: 19-22, 55-5
  string hname1="Energy (HB 2,1,1)"; // allowed phi channels: 19-22, 55-5
  TKey *key = f0->FindKey(hname1.c_str()); 

  //cout << "-- Key: " << key << endl;
  if (key ==0){
    cout << "!!Histogram does not exist!!" << endl;
    throw 1;
  }
  TH1F *h1 = (TH1F*)f0->Get(hname1.c_str());  
                                    // c_str() returns a const pointer to string hname1

  // Create the canvas
  Int_t ix1=900, iy1=20, ixl=400, iyl=260;
  //TCanvas *c1 = new TCanvas("c1","Root Canvas",ix1,iy1,ixl,iyl);
  TCanvas *c1 = new TCanvas("c1","Root Canvas",600,425);


  string psfile="/dev/null";
  if (ips == 1) psfile="tbeam_cell_2_1_1.eps";
  cout << "PostScript file: " << psfile << endl;
  TPostScript *myps = new TPostScript(psfile.c_str(),113);

  myps.Range(14,14);

  Int_t ilogy = 1;
  gPad->SetLogy(ilogy);
  h1->GetXaxis()->SetRangeUser(0.,5.);
  h1->GetXaxis()->SetNdivisions(512);
  h1->GetXaxis()->SetTitle("HB Cell Energy (GeV)");
  h1->GetYaxis()->SetTitle("Number of towers");


  h1->Draw();

  TText *t1 = new TText(0.6,0.75,"HB Cell 2,1,1");
  t1->SetNDC(kTRUE); // <- use NDC coordinate
  t1->SetTextSize(0.07);
  t1->Draw(); 

  //c1->Print("zzz.eps") ; 
  myps->Close();
}
