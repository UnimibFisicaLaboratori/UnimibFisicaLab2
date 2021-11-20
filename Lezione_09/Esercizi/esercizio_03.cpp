/*
c++ -o esercizio_03 `root-config --glibs --cflags` funzioni.cc esercizio_03.cpp
*/

#include <iostream>
#include <vector>

#include "TCanvas.h"
#include "TF1.h"

#include "funzioni.h"

using namespace std ;

int main (int argc, char ** argv)
{
  if (argc < 2)
    {
      cerr << "uso: " << argv[0] << " tau" << endl ;
      exit (1) ;
    }

  double t_zero = atof (argv[1]) ;

  TF1 f_exp ("f_exp", exp_R, 0, 5 * t_zero, 1) ;
  f_exp.SetParameter (0, t_zero) ;
  f_exp.SetParName (0, "t_0") ;
  f_exp.SetLineColor (kBlue) ;
  f_exp.SetLineWidth (2) ;

  TCanvas c1 ;
  f_exp.Draw () ;
  c1.Print ("esercizio_03.png", "png") ;

  return 0 ;
}
