import os, sys
import ROOT

# To run, do an "execfile( '<path-to>/demo.py' )" or "python <path-to>/demo.py"

# enable running from another directory than the one where demo.py resides
workdir = os.path.dirname( sys.argv[0] )
if workdir:
   os.chdir( workdir )
   
os.environ["FROMGUI"] = "1"

ROOT.gROOT.Reset()
ROOT.gStyle.SetScreenFactor(1)   # if you have a large screen, select 1.2 or 1.4

bar = ROOT.TControlBar( 'vertical', 'RootGui', 10, 10 )

# The callbacks to python work by having CINT call the python interpreter through
# the "TPython" class. Note the use of "raw strings."
# bar.AddButton( 'Help on Demos', r'TPython::Exec( "execfile( \'demoshelp.py\' )" );', 'Click Here For Help on Running the Demos' )
bar.AddButton( 'Quit', r'TPython::Exec( "sys.exit()" );', 'Quit Button' )
bar.AddButton( '     browser     ', r'TPython::Exec( "b = ROOT.TBrowser()" );','Start the ROOT browser' )
bar.AddButton( 'compHists',    r'TPython::Exec( "execfile( \'compHists.py\' )" );',   'xxxx' )

bar.Show()

ROOT.gROOT.SaveContext()


## wait for input to keep the GUI (which lives on a ROOT event dispatcher) alive
if __name__ == '__main__':
   rep = ''
   while not rep in [ 'q', 'Q' ]:
      rep = raw_input( 'enter "q" to quit: ' )
      if 1 < len(rep):
         rep = rep[0]
