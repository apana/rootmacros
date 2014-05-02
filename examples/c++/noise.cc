//
//  HCAL test beam analysis
//
{
  //#include <sstream>
  //#include <stdexcept>

  
  //gROOT->Reset();           // Resetting ROOT (Not to be use in named macros)
  gSystem->Load("libPhysics.so"); // Loading Physics library (TVector3)
  gSystem->Load("myFuncs_cc.so"); // Loading Physics library (TVector3)

  gROOT->SetStyle("Plain");

  Int_t ips=1;
  Int_t isamp=1; //  isamp =0 Cosmic triggers, =1 Beam Triggers

  Int_t i_wait,do_wait=0;
  Int_t type = 113;
  Int_t iped = 1; // look at pedestal triggers
  int idet = 0 ; // 0 -- HB, 1 -- HO, 2 == HF

  Double_t topMargin;

  gStyle->SetOptTitle(1);
  
  // Create the canvas
  Int_t ix1=900, iy1=20, ixl=650, iyl=650;
  TCanvas *c1 = new TCanvas("c1","Root Canvas",ix1,iy1,ixl,iyl);

  topMargin=c1->GetTopMargin();
  cout << "topMargin: " << topMargin << endl;
  //printf("TopMargin is %d units",topMargin," \n");

  // c1->SetTopMargin(.05);
  topMargin=c1->GetTopMargin();
  cout << "topMargin: " << topMargin << endl;

  string wait_string;
  string rootfile;
  string rootdir= "~/analysis/cosmics/CMSSW_0_3_0/src/Tutorial/Analysis1/test/";
  if (isamp == 0){
    rootfile = "cosmics.root";
    // allowed phi channels: 19-22, 55-58 (possibly others)
    const size_t phi_vals[] = {19,20,21,22,55,56,57,58};
  }
  else{
    rootdir = "/uscms_data/d1/apana/rootfiles/";
    rootfile="tutorial_11609_noise";

    switch (idet){
    case 0: 
      const size_t phi_vals[] = {1,2,3,4};
      break;
    case 1:
      const size_t phi_vals[] = {3,4,5,6};
      break;
    default:
      cout << "Illegal value for idet1, idet= " << idet << endl;      
      return 1;      
    }
  }
  if (idet < 2){
    if (iped == 1) 
      rootfile=rootfile + "_peds";
    else
      rootfile=rootfile + "_beam";
  }
  rootfile = rootdir + rootfile;
  rootfile=rootfile + ".root";
  cout << "Rootfile:" << rootfile << endl;
  if( gSystem->AccessPathName(rootfile.c_str()) ) {
    cout << endl << "File: " << rootfile << " not there!!!" << endl<< endl;
    return;
  }


  //const size_t phi_vals[] = {19,20};

  // i_wait=wait_fcn(1);  
  Int_t itmp;
  itmp=writeIt(ips);

  TFile *f0 = TFile::Open(rootfile.c_str());

  //cout << "-- Printing List of Keys " << endl;
  //  f0->GetListOfKeys()->Print();

  const size_t nphi=sizeof(phi_vals)/sizeof(*phi_vals); // sizeof return bytes
  cout << "Number of phi elements: " << nphi << endl;

  Int_t iphi;
  Int_t indx=-1;

  vector<Double_t> xval,  exval;
  vector<Double_t> yvalm, eyvalm;
  vector<Double_t> yvals, eyvals;

  //std::map<Int_t, TH1*> m_peds_phi;  // map phi channels to hist ids

  Int_t n_eta;  // 16 eta channels
  
  Float_t minf=-1.5,maxf=1.5;

  // loop over phi, then eta
  for (size_t i=0; i<nphi; ++i){

    iphi=phi_vals[i];

    ostringstream ch_phi("");
    ostringstream ch_eta;

    ch_phi << iphi;
    cout << "-- PHI: " << ch_phi.str() << endl;
    string hname1;
    string hbeg ="Energy ";
    switch (idet){
    case 0: 
      hbeg= hbeg + "(HB ";
      n_eta=16;  // 16 eta channels
      break;
    case 1:
      minf=-1.5;
      maxf=3.;
      hbeg= hbeg + "(HO ";
      n_eta=10;  // 10 eta channels
      break;
    default:
      cout << "Illegal value for idet2, idet= " << idet << endl;      
      return 1;      
    }

    if (idet == 0)
      string hend ="," + ch_phi.str() + ",1)";
    else
      string hend ="," + ch_phi.str() + ")";
    string answer;

    const int cLen = 40;
    //  string cpause;
    char cpause[cLen];

    for (Int_t ieta = 0 ; ieta <n_eta ; ++ieta){
      indx++;
      ch_eta.str("");

      if (idet==0)
	ch_eta << ieta+1;
      else
	ch_eta << ieta+1+5;

      // cout << "-- ETA: " << ch_eta.str() << endl;
      hname1=hbeg + ch_eta.str() + hend;
      cout << "Histogram: " << hname1 << endl;
      cout << "INDX: " << indx << endl;

      //string hname1="Energy (HB 1,56,1)";

      TKey *key = f0->FindKey(hname1.c_str()); 

      //cout << "-- Key: " << key << endl;
      if (key ==0){
	cout << "!!Histogram " << hname1 << " does not exist!!" << endl;
	//throw std::domain_error("xxx");
	throw 1;
      }
      TH1F *h1 = (TH1F*)f0->Get(hname1.c_str());  
                          // c_str() returns a const pointer to string hname1

      h1->GetXaxis()->SetTitle("Energy (GeV)");
      h1->GetYaxis()->SetTitle("Entries");
      h1->GetXaxis()->SetNdivisions(512);

      TH1F *copy_h1 = (TH1F*)h1->Clone();


      //simple gaussian fit
      TF1 *gfit = new TF1("gfit","gaus",minf,maxf);
      copy_h1->Fit("gfit","RQ");

      Double_t chisq,chisqdf;
      Int_t ndf;

      chisq=gfit->GetChisquare();
      ndf=gfit->GetNDF();

      chisqdf=chisq/ndf;

      cout << "Chisquare: " << chisq << "/" << ndf << " : " << chisqdf << endl;

      Double_t mean = gfit->GetParameter(1); //value of 1st parameter
      Double_t emean = gfit->GetParError(1); //error on first parameter 
      cout << "Mean " << mean << " +- " << emean << endl;  
      
      Double_t sig = gfit->GetParameter(2); //value of 1st parameter
      Double_t esig = gfit->GetParError(2); //error on first parameter 
      cout << "Sigma " << sig << " +- " << esig << endl;  

      if (iped == 1){
	if (iphi ==4 ){
	  emean=0.0;
	  esig=0.0;
	}
      }
      xval.push_back(indx*1.0001);
      exval.push_back(0.);
      
      yvalm.push_back(mean);
      eyvalm.push_back(emean);
      
      yvals.push_back(sig);
      eyvals.push_back(esig);
      
      copy_h1->GetXaxis()->SetRangeUser(-2.,1.5);  // set the x-axis limits
      copy_h1->Draw();
      c1->Update();

      // if (sig <0.15)   i_wait=wait_fcn(1);
      i_wait=wait_fcn(do_wait);
      cout << "i_wait " << i_wait << endl;        
      if (i_wait == 1) return 0;
      if (i_wait == 2) break;

    } // end of loop over eta values
  } // end of loop over phi values

  Int_t npts=indx;

  if (npts == 0){
    cout << "No Points to Graph" << endl;  
    return 0;
  }

  // load arrays for graph
  const Int_t nmax=npts;
  Double_t chan[nmax], echan[nmax];
  Double_t means[nmax], emeans[nmax];
  Double_t sigmas[nmax], esigmas[nmax];
  
  cout << " Number of Channels: " << nmax << endl;
  for (Int_t ii = 0 ; ii !=nmax ; ++ii){
    //cout << " ii = " << ii << endl;
    chan[ii]=xval[ii]+1.;;
    echan[ii]=exval[ii];;
    means[ii]=yvalm[ii];;
    emeans[ii]=eyvalm[ii];;
    sigmas[ii]=yvals[ii];;
    esigmas[ii]=eyvals[ii];;

    //cout << " chan = " << chan[ii] << endl;
  }

  TGraph *gr1 = new TGraphErrors(npts,chan,means,echan,emeans);

  gStyle->SetTitleSize(.06,"xy");
  gStyle->SetTitleOffset(0.75,"y");
  gStyle->SetTitleOffset(0.75,"x");

  ix1=200;
  TCanvas *c2 = new TCanvas("c2","Graph Canvas",ix1,iy1,ixl,iyl);


  if (ips == 1){
    string psfile="noise_means-sigmas";
    if (isamp == 0)
      psfile=psfile + "_cosmics";
    else
      psfile=psfile + "_tbeam";

    switch (idet){
    case 0: 
      psfile= "hb_" + psfile;
      break;
    case 1:
      psfile= "ho_" + psfile;
      break;
    case 2:
      psfile= "hf_" + psfile;
      break;
    default:
      cout << "Illegal value for idet1, idet= " << idet << endl;      
      return 1;
    }

    if (iped == 1) psfile=psfile + "_peds";
    psfile=psfile + ".eps";
    cout << "PostScript file: " << psfile << endl;
    TPostScript ps(psfile.c_str(),type);
  }

  //c2->Divide(1,2,0.05,0.15);
  c2->Divide(1,2,0.01,0.01);
  //gPad->SetBottomMargin(0.005);

  c2->cd(1);
  gPad->SetTicks(1,1);
  gStyle->SetOptTitle(0);

  gr1->SetMinimum(-1.45);
  gr1->SetMaximum(1.45);
  gr1->GetYaxis()->SetTitle("Mean (GeV)");  
  gr1->GetXaxis()->SetTitle("Channel");
  //
  gr1->SetMarkerStyle(20);
  gr1->SetMarkerColor(6);
  gr1->Draw("AP");

  printf("Okay so far1\n"); 
  TGraph *gr2 = new TGraphErrors(npts,chan,sigmas,echan,esigmas);
  //TCanvas *c3 = new TCanvas("c3","Graph Canvas",ix1,iy1,ixl,iyl);

  //gr2->SetMinimum(-1.95);
  //gr2->SetMaximum(1.95);
  //


  //TF1 *p0fit = new TF1("p0fit","pol0",chan[0],chan[60]);
  //gr2->Fit("p0fit","RQ");
  //p0fit->Draw("same");
  //Double_t p0 = p0fit->GetParameter(0); //value of 1st parameter
  //Double_t ep0 = p0fit->GetParError(0); //error on first parameter 
  //cout << "Mean " << p0 << " +- " << ep0 << endl;  

  TLatex l1;
  l1.SetTextSize(0.07);
  //l1.DrawLatex(12.,1.,"Means");

  c2->cd(2);
  gPad->SetTicks(1,1);
  gr2->GetYaxis()->SetNdivisions(505);
  gr2->SetMarkerStyle(20);
  gr2->SetMarkerColor(6);

  gr2->GetYaxis()->SetTitle("Sigma (GeV)");  
  gr2->GetXaxis()->SetTitle("Channel");

  gr2->SetMinimum(0.);
  gr2->SetMaximum(.5);

  gr2->Draw("AP");

  TLatex l2;
  l2.SetTextSize(0.07);
  //l2.DrawLatex(12.,.4,"Sigmas");

  c2->Update();

  if (ips == 1)
    ps.Close();

  // end of analysis
  return 0;
}
