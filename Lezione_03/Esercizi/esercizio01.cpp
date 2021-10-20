/*
c++ -o esercizio01 `root-config --glibs --cflags` esercizio01.cpp
*/

#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"

int main (int argc, char ** argv)
{
  

  TH1F histo ("histo", "prova", 10, 0., 10.) ;
  histo.Fill (9.4) ;
  histo.Fill (2.1) ;
  histo.Fill (123.3) ;
  histo.Fill (0.0004) ;
  histo.Fill (2.9) ;

  TApplication theApp ("theApp", &argc, argv) ;
  TCanvas c1 ;
  histo.Draw () ;
  c1.Print ("histo.png", "png") ;
  theApp.Run () ;

  return 0 ;
}