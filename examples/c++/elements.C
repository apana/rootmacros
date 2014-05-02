//
//  get listing of Rootfiles
//
{
  //#include <sstream>

  gROOT->Reset();                // Reseting ROOT
  gSystem->Load("libPhysics.so"); // Loading Physics library (TVector3)

  string rootfile = 
    //  "/uscms_data/d1/jmmans/tutorial_data/HTBqc_001042.root";
  "/uscms_data/d1/jmmans/tutorial_data/HTB_011609.root";


  cout << "Rootfile:" << rootfile << endl;
  TFile *f0 = TFile::Open(rootfile.c_str());

  //cout << "-- Printing List of Keys " << endl;
  f0->GetListOfKeys()->Print();
  // end of analysis
}

