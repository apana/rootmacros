//
//  generate nice picture of 300GeV pion into HCAL
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

  gStyle->SetFuncColor(6);
  //gStyle->SetHistTopMargin(0.05);

  Int_t ndivx = 510;
  Int_t ips = 1;
  Int_t type = 113;

  // Create the canvas
  Int_t ix1=900, iy1=20, ixl=650, iyl=650;
  TCanvas *c1 = new TCanvas("c1","Root Canvas",ix1,iy1,ixl,iyl);

  c1->GetFrame()->SetFillColor(21);
  c1->Divide(1,2);

  string rootfile1 = 
    "/home/apana/cms/cosmics/CMSSW_0_3_0/src/Tutorial/Analysis1/test/testbeam_bigb.root";
  //string rootfile2 = 
  //  "/home/apana/cms/cosmics/CMSSW_0_3_0/src/Tutorial/Analysis1/test/tower_jet_pool.root";
  //string rootfile2 = 
  //  "/uscms_data/d1/apana/noise/CMSSW_0_3_0/src/Tutorial/Analysis1/test/tower_jet_pool_howt_1.4.root";
  string rootfile2 = 
    "/uscms_data/d1/apana/noise/CMSSW_0_3_0/src/Tutorial/Analysis1/test/tower_jet_pool.root";


  cout << "Rootfile:" << rootfile1 << endl;
  cout << "Rootfile:" << rootfile2 << endl;
  TFile *f0 = TFile::Open(rootfile1.c_str());

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

  if (ips == 1){
    TPostScript ps("pion_energy_col.eps",type);
    //    ps.Range(10,10);
  }
  c1->cd(1);
  gPad->SetFillColor(10);
  h1->SetFillColor(5);

  h1.Draw();

  //Now reconstructed jet energy

  TFile *f1 = TFile::Open(rootfile2.c_str());
  TH1F *h2 = new TH1F("h2","CaloJet Energy",200,0.,600.);

  TF1 *gfit = new TF1("gfit","gaus",260.,400.);

  h2->GetXaxis()->SetTitle("Energy (GeV)");
  h2->GetYaxis()->SetTitle("Entries");
  h2->GetXaxis()->SetNdivisions(ndivx);

  TTree *t0 = (TTree*)f1->Get("Events");
  t0->Project("h2","CaloJet_mcone5.obj.data.e");

  h2->SetFillColor(5);
  TH1F *copy_h2 = (TH1F*)h2->Clone();

  c1->cd(2);

  gPad->SetFillColor(10);

  gStyle->SetOptFit(01110);
  gStyle->SetStatFontSize(0.025);

  copy_h2->Fit("gfit","R");

  Double_t chi2=gfit->GetChisquare();
  cout << "Chisquare: " << chi2 << endl;

  c1.Update();
  if (ips == 1)
    ps.Close();
}
