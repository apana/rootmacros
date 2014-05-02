//
//  generate nice picture of 300GeV pion energy deposition into single HCAL Cell
//
{
  gROOT->Reset();                // Reseting ROOT
  gSystem->Load("libPhysics.so"); // Loading Physics library (TVector3)
  gROOT->SetStyle("Plain");

  //  gStyle->SetOptDate();
  gStyle->SetOptStat(111);

  gStyle->SetStatFont(132);
  gStyle->SetStatFontSize(0.02);

  gStyle->SetStatY(.95);
  gStyle->SetFuncWidth(2);                          

  gStyle->SetTitleYOffset(1.05);
  gStyle->SetFuncColor(6);
  //gStyle->SetHistTopMargin(0.05);

  Int_t ndivx = 510;
  Int_t ips = 1;
  Int_t type = 113;

  TGaxis::SetMaxDigits(3);
  Float_t ytit=1.25;
  //if (ilogy == 1) ytit=1.25;

  // Create the canvas
  Int_t ix1=900, iy1=20, ixl=650, iyl=650;
  TCanvas *c1 = new TCanvas("c1","Root Canvas",ix1,iy1,ixl,iyl);

  c1->GetFrame()->SetFillColor(21);
  c1->cd(1);

  string rootfile = 
    "/home/apana/cms/cosmics/CMSSW_0_3_0/src/Tutorial/Analysis1/test/testbeam_bigb.root";


  cout << "Rootfile:" << rootfile << endl;
  TFile *f0 = TFile::Open(rootfile.c_str());

  // cout << "-- Printing List of Keys " << endl;
  // f1->GetListOfKeys()->Print();


  string hname1="Energy (HB 7,3,1)";
  TKey *key = f0->FindKey(hname1.c_str()); 

  //cout << "-- Key: " << key << endl;
  if (key ==0){
    cout << "!!Histogram does not exist!!" << endl;
    throw 1;
  }
  TH1F *h1 = (TH1F*)f0->Get(hname1.c_str());  
                                    // c_str() returns a const pointer to string hname1

  h1->GetXaxis()->SetTitle("Energy (GeV)");
  h1->GetYaxis()->SetTitle("Entries");
  h1->GetXaxis()->SetNdivisions(ndivx);

  TH1F *copy_h1 = (TH1F*)h1->Clone();

  if (ips == 1)
    TPostScript ps("pion_cell_energy_col.eps",type);

  gPad->SetFillColor(10);
  h1->SetFillColor(5);
  h1->GetYaxis()->SetTitleOffset(ytit);
  h1.Draw();

  c1.Update();
  if (ips == 1){
    ps.Close();
  }
}
