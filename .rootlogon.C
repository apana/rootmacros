// This is the file rootlogon.C
{
   printf("\n Beginning new ROOT session\n");

   gROOT->ProcessLine(".x ~/rootmacros/myStyle.cc");
   gROOT->ProcessLine(".x ~/rootmacros/setTDRStyle.C");
   gROOT->SetStyle("MyStyle");


   Int_t ivers=gROOT->GetVersionInt();
   cout << " Version: " << ivers << "\n\n";

   
   Int_t kDarkGreen=kGreen+3;
   if (ivers < 51800) {
     Int_t kDarkGreen=111;
     TColor *mycolor=(TColor*)gROOT->GetListOfColors()->At(kDarkGreen);
     mycolor->SetRGB(0,0.5,0); // dark green
   }


   char *myhome=gSystem->Getenv("HOME");
   TString HomeDir = myhome;
   TString MyIncludePath = HomeDir + "/rootmacros";
   // cout << HomeDir << endl;
   gROOT->ProcessLine(".include " + MyIncludePath);

   // may cause compilation problems
   cmsload();
}
