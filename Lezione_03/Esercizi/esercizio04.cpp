/*
c++ -o esercizio04 `root-config --glibs --cflags` esercizio04.cpp statistiche.cc
*/

#include <iostream>
#include <fstream>

#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"

#include "statistiche.h"

using namespace std ;

int main (int argc, char ** argv)
{

  if (argc < 2)
    {
      cerr << "manca il numero di eventi da leggere" << endl ;
      exit (1) ;
    }
  ifstream input_file ("../programmi/eventi_gauss.txt") ;
  statistiche campione ;
  double input_val = 0. ;
  int max_N = atoi (argv[1]) ;

  while (true)
    {
      input_file >> input_val ;
      if (input_file.eof () == true) break ;
      campione.aggiungiNumero (input_val) ;
    }
  input_file.close () ;

  cout << "letti " << campione.N () << " numeri\n" ;

  if (max_N > campione.N ()) max_N = campione.N () ;

  double media = campione.media () ;
  double sigma = campione.dev_standard (true) ;

  TH1F histo ("histo", "istogramma", 
              max_N / 10,  // numero di bin
              media - 4 * sigma,   // limite inferiore
              media + 4 * sigma) ; // limite superiore

  for (int i = 0 ; i < max_N ; ++i)
    {
      histo.Fill (campione.elem (i)) ; 
    }

  TApplication theApp ("theApp", &argc, argv) ;
  TCanvas c1 ;
  histo.Draw () ;
  c1.Print ("histo.png", "png") ;
  theApp.Run () ;

  return 0 ;
}