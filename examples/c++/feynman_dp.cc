void compton1(Double_t wvlen=0.03, Color_t qcol=kRed, Color_t gcol=kBlue, Color_t pcol=kGreen)
{
  std::cout << compton1 << std::endl;

   TLatex t;
   t.SetTextAlign(22);
   t.SetTextSize(0.1);
   TLine * l;
   // quark line

   Double_t x1,x2,y1,y2;

   x1=10.;y1=55.;x2=30.;y2=30.;
   l = new TArrow(x1,y1,x2,y2, 0.02, "->-" ); 
   l->SetLineColor(qcol);
   l->Draw();
   t.SetTextColor(qcol);
   t.DrawLatex(7,56,"q");

   x1=10.;y1=5.;x2=30.;y2=30.;
   TCurlyLine *gluon = new TCurlyLine(x1, y1, x2, y2,wvlen);
   gluon->SetLineColor(gcol);
   gluon->Draw();
   t.SetTextColor(gcol);
   t.DrawLatex(7,4,"g");

   //vertex line
   x1=30.;y1=30.;x2=50.;y2=30.;
   l = new TArrow(x1,y1,x2,y2, 0.02, "->-" ); l->SetLineColor(qcol); l->Draw();

   // outgoing lines
   x1=50.;y1=30.;x2=70.;y2=5.;
   l = new TArrow(x1,y1,x2,y2, 0.02, "->-" ); l->SetLineColor(qcol); l->Draw();
   t.SetTextColor(qcol);
   t.DrawLatex(72,4,"q");

   x1=50.;y1=30.;x2=70.;y2=55.;
   TCurlyLine *gamma = new TCurlyLine(x1, y1, x2, y2,wvlen);
   gamma->SetWavy();
   gamma->SetLineColor(pcol);
   gamma->Draw();
   t.SetTextColor(pcol);
   t.DrawLatex(72,56,"#gamma");

}

void compton2(Double_t wvlen=0.03, Color_t qcol=kRed, Color_t gcol=kBlue, Color_t pcol=kGreen)
{
  std::cout << compton2 << std::endl;

   TLatex t;
   t.SetTextAlign(22);
   t.SetTextSize(0.1);
   TLine * l;
   // quark line

   Double_t x1,x2,y1,y2;

   // incoming lines
   x1=10.;y1=55.;x2=40.;y2=40.;
   l = new TArrow(x1,y1,x2,y2, 0.02, "->-" ); l->SetLineColor(qcol); l->Draw();
   t.SetTextColor(qcol);
   t.DrawLatex(7,56,"q");

   x1=10.;y1=5.;x2=40.;y2=20.;
   TCurlyLine *gluon = new TCurlyLine(x1, y1, x2, y2,wvlen);
   gluon->SetLineColor(gcol);
   gluon->Draw();
   t.SetTextColor(gcol);
   t.DrawLatex(7,4,"g");

   //vertex line
   x1=40.;y1=40.;x2=40.;y2=20.;
   l = new TArrow(x1,y1,x2,y2, 0.02, "->-" ); l->SetLineColor(qcol); l->Draw();

   // outgoing lines
   x1=40.;y1=20.;x2=70.;y2=5.;
   l = new TArrow(x1,y1,x2,y2, 0.02, "->-" ); l->SetLineColor(qcol); l->Draw();
   t.SetTextColor(qcol);
   t.DrawLatex(72,4,"q");

   x1=40.;y1=40.;x2=70.;y2=55.;
   TCurlyLine *gamma = new TCurlyLine(x1, y1, x2, y2,wvlen);
   gamma->SetLineColor(pcol);
   gamma->SetWavy();
   gamma->Draw();
   t.SetTextColor(pcol);
   t.DrawLatex(72,56,"#gamma");

}

void annih1(Double_t wvlen=0.03, Color_t qcol=kRed, Color_t gcol=kBlue, Color_t pcol=kGreen)
{
  std::cout << annih1 << std::endl;

   TLatex t;
   t.SetTextAlign(22);
   t.SetTextSize(0.1);
   TLine * l;
   // quark line

   Double_t x1,x2,y1,y2;

   x1=10.;y1=55.;x2=40.;y2=40.;
   l = new TArrow(x1,y1,x2,y2, 0.02, "->-" ); l->SetLineColor(qcol); l->Draw();
   t.SetTextColor(qcol);
   t.DrawLatex(7,56,"q");

   x1=10.;y1=5.;x2=40.;y2=20.;
   l = new TArrow(x1,y1,x2,y2, 0.02, "-<-" ); l->SetLineColor(qcol); l->Draw();
   t.SetTextColor(qcol);
   t.DrawLatex(7,4,"#bar{q}");

   //vertex line
   x1=40.;y1=40.;x2=40.;y2=20.;
   l = new TArrow(x1,y1,x2,y2, 0.02, "->-" ); l->SetLineColor(qcol); l->Draw();

   // outgoing lines
   x1=40.;y1=20.;x2=70.;y2=5.;
   TCurlyLine *gamma = new TCurlyLine(x1, y1, x2, y2,wvlen);
   gamma->SetWavy();
   gamma->SetLineColor(pcol);
   gamma->Draw();
   t.SetTextColor(pcol);
   t.DrawLatex(72,4,"#gamma");

   x1=40.;y1=40.;x2=70.;y2=55.;
   TCurlyLine *gluon = new TCurlyLine(x1, y1, x2, y2,wvlen);
   gluon->SetLineColor(gcol);
   gluon->Draw();
   t.SetTextColor(gcol);
   t.DrawLatex(72,56,"g");

}

void annih2(Double_t wvlen=0.03, Color_t qcol=kRed, Color_t gcol=kBlue, Color_t pcol=kGreen)
{
  std::cout << annih2 << std::endl;

   TLatex t;
   t.SetTextAlign(22);
   t.SetTextSize(0.1);
   TLine * l;
   // quark line

   Double_t x1,x2,y1,y2;

   x1=10.;y1=55.;x2=40.;y2=40.;
   l = new TArrow(x1,y1,x2,y2, 0.02, "->-" ); l->SetLineColor(qcol); l->Draw();
   t.SetTextColor(qcol);
   t.DrawLatex(7,56,"q");

   x1=10.;y1=5.;x2=40.;y2=20.;
   l = new TArrow(x1,y1,x2,y2, 0.02, "-<-" ); l->SetLineColor(qcol); l->Draw();
   t.SetTextColor(qcol);
   t.DrawLatex(7,4,"#bar{q}");

   //vertex line
   x1=40.;y1=40.;x2=40.;y2=20.;
   l = new TArrow(x1,y1,x2,y2, 0.02, "->-" ); l->SetLineColor(qcol); l->Draw();

   // outgoing lines
   x1=40.;y1=20.;x2=70.;y2=5.;
   TCurlyLine *gluon = new TCurlyLine(x1, y1, x2, y2,wvlen);
   gluon->SetLineColor(gcol);
   gluon->Draw();
   t.SetTextColor(gcol);
   t.DrawLatex(72,4,"g");

   x1=40.;y1=40.;x2=70.;y2=55.;
   TCurlyLine *gamma = new TCurlyLine(x1, y1, x2, y2,wvlen);
   gamma->SetWavy();
   gamma->SetLineColor(pcol);
   gamma->Draw();
   t.SetTextColor(pcol);
   t.DrawLatex(72,56,"#gamma");

}

void feynman_dp()
{
   //
   // To see the output of this macro, click  here. 
   //
   //TCanvas *c1 = new TCanvas("c1", "Diagrams", 10,10, 600, 300);
  TCanvas *c1 = new TCanvas("c1", "Diagrams", 10,20, 450, 235);
   //c1->Range(5, 0, 75, 60);

   Color_t padcol=MyStyle->GetPadColor();
   cout << "color= " << padcol << endl;

   MyStyle->SetPadColor(kBlack);
   MyStyle->SetCanvasBorderMode(0);
   MyStyle->SetCanvasBorderSize(0.1);
   MyStyle->SetCanvasColor(kBlue);
   MyStyle->SetPadBorderMode(0);  // turn off to eliminate pad outline
   MyStyle->SetTextColor(kWhite);

   pad1 = new TPad("pad1","This is pad1",0.0,0.5,0.5,1.0);
   pad2 = new TPad("pad2","This is pad1",0.5,0.5,1.0,1.0);
   pad3 = new TPad("pad3","This is pad3",0.0,0.0,0.5,0.5);
   pad4 = new TPad("pad4","This is pad4",0.5,0.0,1.0,0.5);

   pad1->Range(0, -5, 75, 70);
   pad2->Range(0, -5, 75, 70);
   pad3->Range(0, -12, 75, 65);
   pad4->Range(0, -12, 75, 65);

   pad1->Draw();
   pad2->Draw();
   pad3->Draw();
   pad4->Draw();

   Int_t linsav = MyStyle->GetLineWidth();
   MyStyle->SetLineWidth(1);


   Double_t wvlen=0.03;
   Color_t quarkcol=kRed;
   Color_t glcol=kBlue;
   Color_t photcol=kGreen;

   pad1->cd();
   compton1(wvlen,quarkcol,glcol,photcol);

   pad2->cd();
   compton2(wvlen,quarkcol,glcol,photcol);

   pad3->cd();
   annih1(wvlen,quarkcol,glcol,photcol);

   pad4->cd();
   annih2(wvlen,quarkcol,glcol,photcol);

   c1->cd();

   TPad *newpad = new TPad("newpad","Transparent Pad",0.,0.,1.,1.);
   newpad->SetFillStyle(4000);
   newpad->Draw();
   newpad->cd();


   TLatex *tt = new TLatex();
   //tt->SetNDC();
   tt->SetTextAlign(23);
   tt->SetTextFont(63);
   tt->SetTextSizePixels(12);
   tt->DrawLatex(0.5,0.525,"Compton Diagrams");
   tt->DrawLatex(0.5,0.065,"Annihilation Diagrams");

   gPad->Modified();
   gPad->Update();


   c1->Update();
   //gVirtualX->WritePixmap(c1->GetPixmapID(),580,240,"pad.jpg");
   //c1->SaveAs("feynman_dp.jpg");
   c1->Print("feynman_dp_small.gif");

   MyStyle->SetLineWidth(linsav);
   MyStyle->SetPadColor(padcol);
}
