/*
  c++ -o main_02 `root-config --glibs --cflags` main_02.cpp

*/

#include "TF1.h"
#include "TMarker.h"
#include "TCanvas.h"


int main (int argc, char ** argv)
{
  // https://root.cern.ch/root/html600/TF1.html
  TF1 fa1 ("fa1", "sin(x)/x", 0, 10) ;
  TCanvas c1 ;
  fa1.Draw () ;

  // https://root.cern.ch/root/html528/TMarker.html
  TMarker punto (5., 0.5, 20) ;
  punto.Draw () ;

  c1.Print ("main_02.png", "png") ;
}
