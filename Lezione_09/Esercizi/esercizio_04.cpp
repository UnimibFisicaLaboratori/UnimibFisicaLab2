/*
c++ -o esercizio_04 `root-config --glibs --cflags` casual.cc funzioni.cc esercizio_04.cpp
*/

#include <iostream>
#include <vector>

#include "TF1.h"
#include "TH1F.h"
#include "TCanvas.h"

#include "casual.h"
#include "funzioni.h"
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

  double m = media (campione) ;
  double s = sigma (campione) ;

  vector<double> dati_forTF1 ;
  dati_forTF1.push_back (campione.size ()) ;
  dati_forTF1.insert (dati_forTF1.end (), campione.begin (), campione.end ()) ;

  TF1 f_ll ("f_ll", loglikelihood, max (0.1 * m, m - 3 * s), m + 3 * s, dati_forTF1.size ()) ;
  f_ll.SetParameters (&dati_forTF1[0]) ;
  f_ll.SetLineColor (kRed) ;
  f_ll.SetLineWidth (2) ;

  TCanvas c1 ;
  f_ll.Draw () ;
  c1.Print ("esercizio_04.png", "png") ;

  return 0 ;
}
