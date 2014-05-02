{

  gROOT->Reset();                // Reseting ROOT


  TString dirname = "../rootfiles";
  TString srcname = "tower_jet_pool_howt_3.0.root";

  srcname = dirname + "/" + srcname;
  // clear memory of file name
  delete gROOT->GetListOfFiles()->FindObject(srcname);

  // open source file
  cout << "Rootfile:" << srcname << endl;
  if( gSystem->AccessPathName(srcname) ) {
    cout << endl << "File: " << srcname << " not there!!!" << endl << endl;
    return;
  }
  TFile *srcfile = new TFile(srcname);

  TString treename = "Events";
  TString brnchname = "CaloJet_mcone5.obj";


  // get tree from file
  TTree *srcevts = dynamic_cast<TTree*>(srcfile->Get(treename));
  assert(srcevts != 0);

  srcevts->Process("NewSelector.C");
  //srcevts->MakeSelector("NewSelector");
  //h1->Draw();

}
