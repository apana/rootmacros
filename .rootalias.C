//______________________________________________________________________________
void dir(char *path=0)
{
  //char s[256] = (!strcmp(gSystem->GetName(), "WinNT")) ? "dir " : "ls -l ";
  char s[256];
  strcpy(s,(!strcmp(gSystem->GetName(), "WinNT")) ? "dir " : "ls -l ");
  if (path) strcat(s,path);
  gSystem->Exec(s);
}

//______________________________________________________________________________
void lc(char *path=0)
{
  //char s[256] = (!strcmp(gSystem->GetName(), "WinNT")) ? "lc " : "ls -xstF ";
  // if (path) strcat(s,path);
  // gSystem->Exec(s);

   char s[256];
   strcpy(s, (!strcmp(gSystem->GetName(), "WinNT")) ? "lc " : "ls -xstF");
   if (path) strcat(s,path);
   gSystem->Exec(s);
}

void tb()
{
  new TBrowser();
  //gSystem->Exec("new TBrowser()");
}

//______________________________________________________________________________
void loadMyRootFuncs()
{
   gROOT->ProcessLine(".L ~/rootmacros/rootfuncs.h");
}

void cmsload()
{

  bool foundIt=true;
  TString FWLiteLib = "libFWCoreFWLite.so";

  // see if CMSSW has been setup
  const char *cmsbase=gSystem->Getenv("CMSSW_BASE");
  if (cmsbase==NULL) {
    cout << " \nCMSSW environment has not been setup -- "
	 << " FWLite libraries will not be loaded\n" << endl;
    foundIt=false;
  } else {
    cout << " \nCMSSW environment has been setup:  loading FWLITE libraries \n" << endl;

    const char *search=gSystem->Getenv("LD_LIBRARY_PATH");
    string cms_path = search;
     
    //const char* foundlib =gSystem->Which(search, FWLiteLib, 0);
    const char* foundlib =gSystem->Which(search, FWLiteLib, kFileExists);
    if (! foundlib) {
      FWLiteLib = "libPhysicsToolsFWLite.so";
      //foundlib =gSystem->Which(search, FWLiteLib, 0);
      foundlib =gSystem->Which(search, FWLiteLib, kFileExists);
      if (! foundlib) {
	cout << "Could not find any FWLite libraries to load " << endl;       
	foundIt=false;
      }
    }
  }

  //   foundIt=false;
   
  if (foundIt){
    //cout << " Loading: " << FWLiteLib << endl;
    //gSystem->Load("libCintex");
    //Cintex::Enable();
    gSystem->Load(FWLiteLib);
    //gSystem->Load("libFWCoreFWLite.so");
    AutoLibraryLoader::enable();
    gSystem->Load("libDataFormatsFWLite.so");
    gSystem->Load("libDataFormatsPatCandidates.so");
  }
   
}

