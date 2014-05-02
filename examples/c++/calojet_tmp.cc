//
// draw a nice picture of the CaloJetEnergy
//
{
  gROOT->Reset();                // Reseting ROOT


  TString dirname = "/home/apana/rootfiles";
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

  //TBranch        *b_CaloJet_mcone5_obj_data_e;   //!
  //const Int_t kMaxCaloJet_mcone5 = 1;
  //const Int_t kMaxCaloJet_mcone5_obj = 2;
  //Double_t        CaloJet_mcone5_obj_data_e[kMaxCaloJet_mcone5_obj];   //[CaloJet_mcone5.obj_]
  //Double_t        CaloJet_mcone7_obj_data_e;
  //Double_t        e[kMaxCaloJet_mcone5];
  //Double_t        e;

  //b_CaloJet_mcone5_obj_data_e = srcevts->GetBranch("CaloJet_mcone5.obj.data.e");
  //b_CaloJet_mcone5_obj_data_e->SetAddress(&CaloJet_mcone5_obj_data_e);
  //srcevts->SetBranchAddress("CaloJet_mcone5.obj.data.e",CaloJet_mcone5_obj_data_e);
  //srcevts->SetMakeClass(1);

  //srcevts->Print();

  // get number of events
  //Int_t nsrcevts = srcevts->GetEntries();
  //cout << "Number of Events: " << nsrcevts << endl;

  TH1F *h0 = new TH1F("h0","CaloJet Energy",200,0.,600.);
  TH1F *h1 = new TH1F("h1","CaloJet Energy",200,0.,600.);
  srcevts->Project("h0","CaloJet_mcone5.obj.data.e");    

  return;

  // get branch from tree
  //TBranch *srcbrnch = srcevts->GetBranch(brnchname);
  //assert(srcbrnch != 0);

  //  new TBrowser();
  //srcevts->StartViewer();
  //return;

  // set variables
  //Float_t e;

  //for (Int_t i=0; i<nsrcevts; i++){
  for (Int_t i=0; i<1000; i++){
    //srcbrnch->GetEntry(i);
    //b_CaloJet_mcone5_obj_data_e->GetEntry(i);
    //h1->Fill(CaloJet_mcone5_obj_data_e[0],1.);
    //if (i<10) cout<<  CaloJet_mcone5_obj_data_e[0] << endl;
    //if (i<10) cout<< CaloJet_mcone5_obj_data_e->size() << endl;
  }
  h0->Draw();
  //h1->Draw("SAME");
}
