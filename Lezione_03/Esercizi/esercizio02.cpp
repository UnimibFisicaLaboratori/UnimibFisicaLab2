/*
c++ -o esercizio02 `root-config --glibs --cflags` esercizio02.cpp
*/

#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"

int main (int argc, char ** argv)
{
  

  TH1F * histo = new TH1F ("histo", "prova", 10, 0., 10.) ;
  histo->Fill (9.4) ;
  histo->Fill (2.1) ;
  histo->Fill (123.3) ;
  histo->Fill (0.0004) ;
  histo->Fill (2.9) ;

  TApplication * theApp = new TApplication ("theApp", &argc, argv) ;
  TCanvas * c1 = new TCanvas () ;
  histo->Draw () ;
  c1->Print ("histo.png", "png") ;
  theApp->Run () ;

  delete histo ;
  delete theApp ;
  delete c1 ;
  return 0 ;
}