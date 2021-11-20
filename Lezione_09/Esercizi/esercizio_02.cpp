/*
c++ -o esercizio_02 `root-config --glibs --cflags` utils.cc casual.cc esercizio_02.cpp
*/

#include <iostream>
#include <vector>

#include "TH1F.h"
#include "TCanvas.h"

#include "utils.h"
#include "casual.h"
#include "statistiche.h"

using namespace std ;


int main (int argc, char ** argv)
{

  if (argc < 3)
    {
      cerr << "uso: " << argv[0] << " tau nnumero_di_eventi" << endl ;
      exit (1) ;
    }

  double t_zero = atof (argv[1]) ;
  vector<double> campione ;
  for (int i = 0 ; i < atoi (argv[2]) ; ++i)
    {
      campione.push_back (rand_exp (t_zero)) ;
    }

  TH1F * histo = crea_histo ("h_exp", campione) ;

  TCanvas c1 ;
  histo->SetFillColor (kBlue) ;
  histo->Draw () ;
  c1.Print ("esercizio_02.png", "png") ;

  delete histo ;
  return 0 ;
}
