//
//  2x2 plot showing noise dists in some random HB/HO/HF channels
//
{
  gROOT->Reset();                // Reseting ROOT
  gSystem->Load("libPhysics.so"); // Loading Physics library (TVector3)
  gROOT->SetStyle("Plain");


  gStyle->SetOptStat(1110);
  gStyle->SetOptFit(111);

  gStyle->SetFuncWidth(2);                          
  gStyle->SetFuncColor(6);

  // gStyle->SetTitleOffset(1.75,"y");
  gStyle->SetLabelSize(0.03,"xyz");

  //gStyle->SetStatFont(62);
  //gStyle->SetStatFontSize(.04);

  gStyle->SetStatFontSize(.04);

  gStyle->SetStatX(0.95); 
  gStyle->SetStatY(0.995); 
  gStyle->SetStatW(0.25);
  gStyle->SetStatH(.5);

  //gStyle->SetStatFont(62);

  Int_t isamp = 1; // 0 -- cosmics 1 -- tbeam

  Int_t ips = 1;
  Int_t type = 113;
  Int_t ilogy = 0;
  Int_t ipeds = 1;
  int idet = 2 ; // 0 -- HB, 1 -- HO, 2 == HF

  if (isamp == 0){
    if (ipeds == 1){
      cout << "Peds not available for cosmic data" << endl;
      ipeds=0;
      return 0;
    }
  }

  // TGaxis::SetMaxDigits(4);
  Float_t ytit=1.65;
  if (ilogy == 1) ytit=1.25;

  // Create the canvas
  Int_t ix1=900, iy1=20, ixl=650, iyl=650;
  TCanvas *c1 = new TCanvas("c1","Root Canvas",ix1,iy1,ixl,iyl);

  c1->UseCurrentStyle();

  if (ips == 1){
    if (isamp == 0)
      string psfile="noise_fits_cosmics";
    else
      string psfile="noise_fits_tbeam";

    switch (idet){
    case 0: 
      psfile= "hb_" + psfile;
      break;
    case 1:
      psfile= "ho_" + psfile;
      break;
    case 2:
      psfile= "hf_short_" + psfile;
      break;
    default:
      cout << "Illegal value for idet1, idet= " << idet << endl;      
      return 1;
    }

    if (ipeds == 1) psfile=psfile + "_peds";
    if (ilogy == 1) psfile=psfile + "_logy";
    psfile=psfile + ".eps";
    cout << "Postscript: " << psfile << endl;
    TPostScript ps(psfile.c_str(),type);
  }

  c1->Divide(2,2,.005,.005);

  if (isamp == 0){  
    string rootfile = 
      "/home/apana/analysis/cosmics/CMSSW_0_3_0/src/Tutorial/Analysis1/test/cosmics";
    string hname1="Energy (HB 2,19,1)";
    string hname2="Energy (HB 3,21,1)";
    string hname3="Energy (HB 10,55,1)";
    string hname4="Energy (HB 15,57,1)";
  }
  else {    
    //string rootfile = "/home/apana/cms/cosmics/CMSSW_0_3_0/src/Tutorial/Analysis1/test/testbeam";
    string rootdir = "/uscms_data/d1/apana/rootfiles";
    switch (idet){
    case 0: 
      string hname1="Energy (HB 1,3,1)";
      string hname2="Energy (HB 2,1,1)";
      string hname3="Energy (HB 13,3,1)";
      string hname4="Energy (HB 3,3,1)";
      break;
    case 1: 
      string hname1="Energy (HO 6,6)";
      string hname2="Energy (HO 8,2)";
      string hname3="Energy (HO 13,4)";
      string hname4="Energy (HO 15,5)";
      break;
    case 2:
      rootdir = "/uscms/home/apana/work/hf/CMSSW_0_3_0/src/Tutorial/Analysis1/test";
      string hname1="Energy SB (HF 31,3,2)";
      string hname2="Energy SB (HF 33,5,2)";
      string hname3="Energy SB (HF 37,3,2)";
      string hname4="Energy SB (HF 41,5,2)";
      break;
    default:
      cout << "Illegal value for idet2, idet= " << idet << endl;      
      return 1;
    }
  }
  string rootfile="tutorial_11609_noise";
  if (idet == 2){
    //rootfile="hf_019016_2ts";
    rootfile="hf_020200_2ts_peds_reco_fs4_newg";
  }
  rootfile = rootdir + "/" + rootfile;

  if (idet < 2){
    if (ipeds == 1) 
      rootfile=rootfile + "_peds";
    else
      rootfile=rootfile + "_beam";
  }
  rootfile=rootfile + ".root";

  cout << "Rootfile:" << rootfile << endl;
  if( gSystem->AccessPathName(rootfile.c_str()) ) {
    cout << endl << "File: " << rootfile << " not there!!!" << endl<< endl;
    return;
  }

  TFile *f0 = TFile::Open(rootfile.c_str());

  //cout << "-- Printing List of Keys " << endl;
  //f0->GetListOfKeys()->Print();


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

  Double_t xmin = -1.1,xmax = 2.;
  Double_t xminf= -1.1,xmaxf=1.;

  if (idet == 2) {
    xmax=4.5; xmaxf=3.5;
  }

  h1->UseCurrentStyle();
  h2->UseCurrentStyle();
  h3->UseCurrentStyle();
  h4->UseCurrentStyle();

  h1->GetXaxis()->SetRangeUser(xmin,xmax);
  h2->GetXaxis()->SetRangeUser(xmin,xmax);
  h3->GetXaxis()->SetRangeUser(xmin,xmax);
  h4->GetXaxis()->SetRangeUser(xmin,xmax);

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

  TF1 *gfit = new TF1("gfit","gaus",xminf,xmaxf);
    

  Float_t leftm1=0.15, leftm2=0.15;

  c1->cd(1);
  gPad->SetLogy(ilogy); gPad->SetLeftMargin(leftm1); gPad->SetTicks(1,1);
  copy_h1->Fit("gfit","RQ");

  c1->cd(2);
  gPad->SetLogy(ilogy); gPad->SetLeftMargin(leftm2); gPad->SetTicks(1,1);
  copy_h2->Fit("gfit","RQ");

  c1->cd(3);
  gPad->SetLogy(ilogy); gPad->SetLeftMargin(leftm1); gPad->SetTicks(1,1);
  copy_h3->Fit("gfit","RQ");

  c1->cd(4);
  gPad->SetLogy(ilogy); gPad->SetLeftMargin(leftm2); gPad->SetTicks(1,1);
  copy_h4->Fit("gfit","RQ");
  c1.Update();  

  if (ips == 1)
    ps.Close();
}
