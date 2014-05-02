//
// draw a nice picture of the CaloJetEnergy
//
{
  gROOT->Reset();                // Reseting ROOT
  gROOT->SetStyle("Plain");
  // gStyle->SetOptFit(01110);
  gStyle->SetFuncColor(6);
  gStyle->SetFuncWidth(2);
  //gStyle->SetLabelFont(64,"xyz");
  //gStyle->SetLabelSize(0.04,"xyz");
  gStyle->SetTitleOffset(1.4,"y");
  gStyle->SetStatBorderSize(2);

  gStyle->SetLabelFont(63,"x"); //font in pixels
  gStyle->SetLabelSize(11,"x"); //font size in pixels
  gStyle->SetLabelFont(63,"y");
  gStyle->SetLabelSize(11,"y");
  gStyle->SetStatFont(63);
  gStyle->SetStatFontSize(11); 

  //gStyle->SetStatX(); 
  gStyle->SetStatY(.95); 
  gStyle->SetStatW(.35); 
  gStyle->SetStatH(.15); 

  gStyle->SetOptTitle(0); 

  Float_t ylab=gStyle->GetLabelOffset("X");
  //cout << "Ytitle offset: " << ylab << endl;

  gStyle->SetLabelOffset(1.,"X");

  gStyle->SetStatTextColor(6);
  //gStyle->SetStatFont(42);
  //gStyle->SetStatFontSize(0.04);

  gStyle->SetOptStat(1110) ; 
  gSystem->Load("myFuncs_cc.so");

  Int_t ips = 1;
  Int_t pstype = 113;
  Bool_t ho_wt = 1;

  Int_t nplots = 6;
  const string ch_wt[] = {"1.2","1.6","2.0","2.4","2.8","4.0"}
  TH1F* hist_ptrs[6];

  Int_t ix1=500, iy1=20, ixl=950, iyl=650;
  TCanvas *c1 = new TCanvas("c1","Root Canvas",ix1,iy1,ixl,iyl);
  c1->Divide(3,2,0.0,0.0);

  
  for (Int_t ii = 0 ; ii !=nplots ; ++ii){

    string rootdir="/uscms_data/d1/asmoron/" ;
    if ( ii < 3 ){
      rootdir="/home/asmoron/" ;
    }
    string rootfile="tower_jet_pool";
    rootfile= rootfile + ch_wt[ii].c_str() + ".root";
    rootfile=rootdir + rootfile;


    //    if (ii == 5){
    //rootdir="./" ;
    //rootfile="tower_jet_pool_howt_";
    //rootfile= rootfile + ch_wt[ii].c_str() + ".root";
    //rootfile=rootdir + rootfile;
    //}
    cout << "Rootfile:" << rootfile << endl;
    if( gSystem->AccessPathName(rootfile.c_str()) ) {
      cout << endl << "File: " << rootfile << " not there!!!" << endl << endl;
      return;
    }
    TFile *f0 = TFile::Open(rootfile.c_str());    
    TH1F *h0 = new TH1F("h0","CaloJet Energy",200,0.,600.);

    TTree *t0 = (TTree*)f0->Get("Events");

    TF1 *gfit = new TF1("gfit","gaus",260.,400.);

    t0->Project("h0","CaloJet_mcone5.obj.data.e");    

    c1->cd(ii+1);
    gPad->SetRightMargin(0.02); 
    gPad->SetTopMargin(0.02); 
    if (ii < 3) gPad->SetBottomMargin(0.02); 
    gPad->SetTicks(1,1);

    h0->GetXaxis()->SetRangeUser(0.,590.);

    h0->Draw();

    Int_t ndivx = 510;
    h0->GetXaxis()->SetTitle("Energy (GeV)");
    h0->GetYaxis()->SetTitle("Entries");
    h0->GetXaxis()->SetNdivisions(ndivx);
    if (ii > 2) h0->SetLabelOffset(0.005,"X");


    h0->SetFillColor(5);

    if (ii == 0){
      TPaveText *pt = new TPaveText(0.15,0.78,0.45,0.85,"brNDC");
      pt->SetTextFont(22);
      pt->SetTextSize(.04);
      pt->SetFillColor(18);
      pt->SetBorderSize(2);
      //pt->AddText(htext.c_str());
      pt->AddText("300 GeV #font[112]{#pi^{-}} Beam");
      // pt->Draw();
      //return;
    }
    c1->Update();

    string htext="k = " ;
    htext=htext +  ch_wt[ii].c_str(); 

    TLatex *t = new TLatex();
    Float_t xtxt=.725, ytxt=.65;
    t->SetNDC();
    t->SetTextAlign(23);
    t->SetTextFont(63);  
    t->SetTextSizePixels(17);  
    t->DrawLatex(xtxt,ytxt,htext.c_str());

    //TPaveStats *st = (TPaveStats*)h0->GetListOfFunctions()->FindObject("stats") ;
    //st->SetOption("brNDC");
    //st->SetX1NDC(0.70);
    //st->SetX2NDC(0.98);
    //st->SetY1NDC(0.82) ; 
    //st->SetY2NDC(0.95) ; 
    //st->SetFillColor(18);

    //delete f0;

  } // end for loop

  string psfile="/dev/null";  
  if (ips == 1) {
    psfile="calojetenergy_comp.eps";      
    c1->Print(psfile.c_str());
  }
}
