{

  string rootdir= "/afs/fnal/files/data/e706/cms";
  string rootfile="tutorial_11609_noise_beam.root";

  rootfile = rootdir + rootfile;
  cout << "Rootfile:" << rootfile << endl;
  TFile *f0 = TFile::Open(rootfile.c_str());


  cout << "-- Printing List of Keys " << endl;
  f0->GetListOfKeys()->Print();
}
