//
//  HCAL test beam analysis
//
{
  //#include <sstream>

  gROOT->Reset();                // Reseting ROOT
  gSystem->Load("libPhysics.so"); // Loading Physics library (TVector3)

  gStyle->SetOptStat(111111);
	
  // Create the canvas
  Int_t ix1=900, iy1=20, ixl=650, iyl=650;
  TCanvas *c1 = new TCanvas("c1","Root Canvas",ix1,iy1,ixl,iyl);
  c1->Divide(1,2);

  string rootfile = 
    "/uscms_data/d1/apana/CMSSW_0_3_0/src/Tutorial/Analysis1/test/tutorial_5000_new.root";

  ostringstream rfile = 
    "/uscms_data/d1/apana/CMSSW_0_3_0/src/Tutorial/Analysis1/test/tutorial_5000_new.root";

  cout << "Rootfile:" << rootfile << endl;
  cout << "Rootfile:" << rfile.str() << endl;

  //  TFile *f0 = TFile::Open(rfile.str().c_str());
  TFile *f0 = TFile::Open(rootfile.c_str());

  //cout << "-- Printing List of Keys " << endl;
  //  f0->GetListOfKeys()->Print();


  // string hname1="Energy (HB 7,3,1)";
  // string hname2="HBHE Time (HB 7,3,1)";
  string hname1="Energy (HB 1,3,1)";
  string hname2="HBHE Time (HB 1,3,1)";
  string hname3="TriggerBunch";

  TH1F *h1 = (TH1F*)f0->Get(hname1.c_str());  
                                    // c_str() returns a const pointer to string hname1
  TH1F *h2 = (TH1F*)f0->Get(hname2.c_str());
  TH1F *h3 = (TH1F*)f0->Get(hname3.c_str());

  h2->GetXaxis()->SetRangeUser(0.,400.);  // set the x-axis limits
  c1->cd(1);
  h1->Draw();

  std::string answer ;
  cout << "Press carriage return to continue ";
  std::getline(cin,answer);

  c1->cd(2);
  h2->Draw();

  // end of analysis
}
