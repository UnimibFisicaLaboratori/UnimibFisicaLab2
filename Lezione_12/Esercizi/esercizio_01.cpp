/*
c++ -o esercizio_01 esercizio_01.cpp funzioni.cc `root-config --glibs --cflags`
*/

#include <iostream>
#include <vector>
#include <cmath>

#include "TF1.h"
#include "TGraph.h"
#include "TCanvas.h"

#include "funzioni.h"


using namespace std ;

int main (int argc, char ** argv)
{

  int nPoints = 5 ;
  double min = 0.5 ;
  double max = 10.5 ;
  double epsilon = 0.15 ;

  TF1 f_true ("f_true", retta, 0., 2. * nPoints, 2) ;
  f_true.SetParameter (0, 0.4) ;
  f_true.SetParameter (1, 1.5) ;

  double x = 0. ;
  for (int i = 0 ; i < nPoints ; ++i)
    {
      x+= rand_range (0., 1.) ;
      double y = f_true.Eval (x) + rand_TCL (0, epsilon) ;
    }
  
  return 0 ;
}