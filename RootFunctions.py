############################################################
##
##  Macros for making and manipulating histograms go here
##
############################################################
import sys
import ROOT

def my_range(start, end, step):
    #
    # for looping over discreet steps of arbitrary size
    #  usage:
    #        for xx in my_range(1, 1.3, 0.01):
    #
    #  will set xx to 1,1.01,1.02 ... 1.29 in loop
    
    while start <= end:
        yield start
        start += step

def RateIntegrator(h):

    print h.GetName()
    hout= h.Clone()
    hout.SetName(h.GetName()+ "_clone")
    
    nbins=h.GetNbinsX()
    for ibin in range(1,nbins+1):
        ibin1=ibin+1
        ibin2=nbins

        cont =h.GetBinContent(ibin+1)
        err  =h.GetBinError(ibin+1)

        ferr=0.
        if (cont>0.): ferr=err/cont

        # fint=h.Integral(ibin1,ibin2,"width");
        # fint=h.Integral(ibin1,ibin2,"");
        errorVal = ROOT.Double(0)
        fint=h.IntegralAndError(ibin1,ibin2,errorVal);
        ferr=errorVal
        # print ibin,"  -- Integral: ",fint
        cont=fint
        # err = ferr*fint
        err = ferr

        hout.SetBinContent(ibin+1,cont);
        hout.SetBinError(ibin+1,err);        

    return hout

def RebinHist(h,theBins,divideByBinWidth=True):
##
## Rebin histogram with variable width bins 
## pass histogram and python list containing bin lower edges and upper edge of last bin
##
##
    from array import array

    newbins=array("d",theBins)

    n=len(newbins)
    hname=h.GetName()
    hname=hname + " -- Rebinned"
    hnew=h.Rebin(n-1,hname,newbins)

    if divideByBinWidth:
        ## divide by the bin width
        for i in range(hnew.GetNbinsX()):
            bw=hnew.GetXaxis().GetBinWidth(i+1)
            # print bw
            cont=hnew.GetBinContent(i+1)
            err=hnew.GetBinError(i+1)

            cont=cont/bw
            err=err/bw
            hnew.SetBinContent(i+1,cont)
            hnew.SetBinError(i+1,err)

    print hnew
    return hnew


def DivideByBinWidth(h):

    hnew=h.Clone()
    ## divide by the bin width
    for i in range(hnew.GetNbinsX()):
        bw=hnew.GetXaxis().GetBinWidth(i+1)
        # print bw
        cont=hnew.GetBinContent(i+1)
        err=hnew.GetBinError(i+1)

        cont=cont/bw
        err=err/bw
        hnew.SetBinContent(i+1,cont)
        hnew.SetBinError(i+1,err)

    return hnew


def GetHist(fileName,histName,whichDir=""):

    import os
    from copy import copy

    Debug=False
    # Debug=True

    #if not os.path.exists(fileName):
    #    print "Histogram: ",fileName," does not exist"
    #    sys.exit(1)

    f = ROOT.TFile.Open(fileName)
    f.cd()
    if Debug:
        print "Input file: ",fileName
        print "Histogram: ",histName
        # f.ls()
    if whichDir != "":
        f.cd(whichDir)

    if Debug: 
        print "XXX"
        f.ls()

    h=ROOT.gDirectory.Get(histName)
    if h==None:
        print "Could not find histo with name: ",histName, "in file ",fileName
        sys.exit()

    hnew=h.Clone()
    # print hnew
    ROOT.TH3F.AddDirectory( False )
    ROOT.TH2F.AddDirectory( False )
    ROOT.TH1F.AddDirectory( False )
    hnew.SetDirectory(0)  # retain histogram after closing file
    f.Close()

    return copy(hnew)


def hExist(rootfile,hname):

    retval=True
    key = rootfile.FindKey(hname);
    if (key ==0):
        print "!!Histogram ",hname, " does not exist!!"
        retval=False

    return retval

def Get1DHist(rootfile,hname,Debug=False):
    ROOT.TH1F.AddDirectory( False )

    f = ROOT.TFile.Open(rootfile)
    if f==None:
        print "TFile.Open returned empty pointer \n\t", rootfile," probably doesn\'t exist"
        print "Exiting macro\n"
        sys.exit(1)
        
    f.cd()

    if Debug:
        f.ls()

    h=ROOT.TH1F()
    if hExist(f,hname):
        h=f.Get(hname)

    #  h.SetDirectory(0)  # retain histogram after closing file
    # print h
    if h==None:
        print "Looks like a histogram with name: ",hname," does not exist on input file ",rootfile
        if not Debug:
            print "Add option debug to Get1DHist to see list of histograms"
        
    f.Close()
    return h

def Get2DHist(rootfile,hname,Debug=False):
    ROOT.TH2F.AddDirectory( False )

    
    # Debug=True
    print "Input file: ",rootfile
    print "Histogram: ",hname
    
    f = ROOT.TFile.Open(rootfile)
    if f==None:
        print "TFile.Open returned empty pointer \n\t", rootfile," probably doesn\'t exist"
        print "Exiting macro\n"
        sys.exit(1)
        
    f.cd()

    if Debug:
        f.ls()

    # f.ls()
    h=ROOT.TH2F()
    if hExist(f,hname):
        h=f.Get(hname)


    # h.SetDirectory(0)  # retain histogram after closing file
    # print h
    f.Close()
    return h

def Get3DHist(rootfile,hname):
    ROOT.TH3F.AddDirectory( False )

    f = ROOT.TFile.Open(rootfile)
    if f==None:
        print "TFile.Open returned empty pointer \n\t", rootfile," probably doesn\'t exist"
        print "Exiting macro\n"
        sys.exit(1)
        
    f.cd()

    h=ROOT.TH3F()
    if hExist(f,hname):
        h=f.Get(hname)

    # h.SetDirectory(0)  # retain histogram after closing file
    # print h
    f.Close()
    return h


def Book1D(cname,ctitle,nbins,xmin,xmax,doSumw2=True):
    h=ROOT.TH1F(cname,ctitle,nbins,xmin,xmax)
    if doSumw2: h.Sumw2()
    return h


def DivideHistograms(hNum,hDen,c1=1.,c2=1.,WhichErrors="",newName=""):

    hRat= hNum.Clone()

    if len(newName) == 0:
        hRat.SetName("Ratio")
    else:
        hRat.SetName(newName)

    hRat.Divide(hNum,hDen,c1,c2,WhichErrors);

    return hRat


def Proj2D_Y(h,xmin,xmax,hname="XXX",Debug=False):

    # project 2D histogram into 1D along Y

    imin=h.GetXaxis().FindBin(xmin+0.01)
    imax=h.GetXaxis().FindBin(xmax-0.01)

    if Debug: 
        nx= h.GetXaxis().GetNbins()
        ny= h.GetYaxis().GetNbins()
        print "Number of x bins: ",nx,"  Number of y bins: ",ny
        print "Proj2D_Y: X-axis,low edge,upper edge:",\
            h.GetXaxis().GetBinLowEdge(1),h.GetXaxis().GetBinUpEdge(nx)
        print "Proj2D_Y: Y-axis,low edge,upper edge:",\
            h.GetYaxis().GetBinLowEdge(1),h.GetYaxis().GetBinUpEdge(ny)

        for i in range(1,nx):
            print i,h.GetXaxis().GetBinLowEdge(i),h.GetXaxis().GetBinUpEdge(i)


        print imin,xmin
        print imax,xmax

    if hname == "XXX":
        orgname=h.GetName()        
        hname=orgname +"__projY_" + str(xmin) + "-" + str(xmax)
    
    ## hname="projY_" + str(xmin) + "-" + str(xmax)
    proj_y=h.ProjectionY(hname, imin, imax)
    ROOT.SetOwnership(proj_y,True)

    if Debug:
        n= proj_y.GetXaxis().GetNbins()
        print hname
        print "Proj_y low edge,upper edge:",\
            proj_y.GetXaxis().GetBinLowEdge(1),proj_y.GetXaxis().GetBinUpEdge(n)
        print proj_y.GetEntries()

    return proj_y


def Proj2D_X(h,ymin,ymax,hname="XXX",Debug=False):

    # project 2D histogram into 1D along Y

    imin=h.GetYaxis().FindBin(ymin+0.01)
    imax=h.GetYaxis().FindBin(ymax-0.01)

    if Debug: 
        nx= h.GetXaxis().GetNbins()
        ny= h.GetYaxis().GetNbins()
        print "X-axis,low edge,upper edge:",\
            h.GetXaxis().GetBinLowEdge(1),h.GetXaxis().GetBinUpEdge(nx)
        print "Y-axis,low edge,upper edge:",\
            h.GetYaxis().GetBinLowEdge(1),h.GetYaxis().GetBinUpEdge(ny)

        print imin,ymin
        print imax,ymax

    if hname == "XXX":
        orgname=h.GetName()        
        hname=orgname +"__projX_" + str(ymin) + "-" + str(ymax)

    proj_x=h.ProjectionX(hname, imin, imax)
    ROOT.SetOwnership(proj_x,True)

    if Debug:
        n= proj_x.GetXaxis().GetNbins()
        print hname
        print "Proj_y low edge,upper edge:",\
            proj_x.GetXaxis().GetBinLowEdge(1),proj_x.GetXaxis().GetBinUpEdge(n)
        print proj_x.GetEntries()

    return proj_x

def Proj3D_Z(h,xmin,xmax,ymin,ymax,Debug=False):

    # project 3D histogram into 1D along Z (x and y into Z)

    imin=h.GetXaxis().FindBin(xmin+0.01)
    imax=h.GetXaxis().FindBin(xmax-0.01)

    jmin=h.GetYaxis().FindBin(ymin+0.01)
    jmax=h.GetYaxis().FindBin(ymax-0.01)

    if Debug: 
        n= h.GetXaxis().GetNbins()
        print "X-axis,low edge,upper edge:",\
            h.GetXaxis().GetBinLowEdge(1),h.GetXaxis().GetBinUpEdge(n)
        print "Y-axis,low edge,upper edge:",\
            h.GetYaxis().GetBinLowEdge(1),h.GetYaxis().GetBinUpEdge(n)

        print imin,xmin
        print imax,xmax

        print jmin,ymin
        print jmax,ymax


    hname="projZ_" + str(xmin) + "-" + str(xmax) +"__"+ str(ymin) + "_" + str(ymax)
    proj_z=h.ProjectionZ(hname, imin, imax, jmin, jmax)
    ROOT.SetOwnership(proj_z,True)

    if Debug:
        n= proj_z.GetXaxis().GetNbins()
        print hname
        print "Proj_z low edge,upper edge:",\
            proj_z.GetXaxis().GetBinLowEdge(1),proj_z.GetXaxis().GetBinUpEdge(n)
        print proj_z.GetEntries()

    return proj_z

def ZeroErrorBars(histo):

    nbins=histo.GetNbinsX()
    for ibin in range(1,nbins+1):
        histo.SetBinError(ibin,0.0)

    return

class XSFIT:
   def __call__( self, x, par ):
       value = par[0]/x[0]**(par[1])+par[2]/x[0]**(par[3]);
       return value

class EFFFIT:
   def __call__( self, x, par ):
       value=par[0]/2.+par[0]/2.*ROOT.TMath.Erf((x[0]-par[1])/par[2]);
       return value
   
class GFIT:
   def __call__( self, x, par ):
      # value1 = par[0]*math.exp(-0.5 * (x[0] - par[1])**2 / par[2]**2 );
      # value2 = par[3]*math.exp(-0.5 * (x[0] - par[4])**2 / par[5]**2 );

      value1 = par[0]*math.exp(-0.5 * ((x[0] - par[1])/par[2])**2 );
      value2 = par[3]*math.exp(-0.5 * ((x[0] - par[4])/par[5])**2 );

      return par[6]-(value1+value2)
