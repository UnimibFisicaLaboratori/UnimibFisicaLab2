/*
c++ -o esercizio05 `root-config --glibs --cflags` esercizio05.cpp statistiche.cc
*/

#include <iostream>
#include <fstream>

#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"

#include "statistiche.h"

using namespace std ;


int leggi_campione (const char * nome_file, statistiche & campione)
  {
    ifstream input_file (nome_file) ;
    double input_val = 0. ;

    while (true)
      {
        input_file >> input_val ;
        if (input_file.eof () == true) break ;
        campione.aggiungiNumero (input_val) ;
      }
    input_file.close () ;
  
    return campione.N () ;
  }


void riempi_histo (TH1F & histo, statistiche & campione, int max_N)
  {
    for (int i = 0 ; i < max_N ; ++i)
      {
        histo.Fill (campione.elem (i)) ; 
      }
    return ; 
  }


int main (int argc, char ** argv)
{

  if (argc < 2)
    {
      cerr << "manca il numero di eventi da leggere" << endl ;
      exit (1) ;
    }
  int max_N = atoi (argv[1]) ;

  statistiche campione_gauss ;
  int N_gauss = leggi_campione ("../programmi/eventi_gauss.txt", campione_gauss) ;
  if (N_gauss < max_N) max_N = N_gauss ;

  statistiche campione_unif ;
  int N_unif = leggi_campione ("../programmi/eventi_unif.txt", campione_unif) ;
  if (N_unif < max_N) max_N = N_unif ;

  double media = campione_gauss.media () ;
  double sigma = campione_gauss.dev_standard (true) ;

  TH1F histo_gauss ("histo_gauss", "istogramma", 
                    max_N / 10,  // numero di bin
                    media - 4 * sigma,   // limite inferiore
                    media + 4 * sigma) ; // limite superiore
  riempi_histo (histo_gauss, campione_gauss, max_N) ;

  TH1F histo_unif ("histo_unif", "istogramma", 
                    max_N / 10,  // numero di bin
                    media - 4 * sigma,   // limite inferiore
                    media + 4 * sigma) ; // limite superiore
  riempi_histo (histo_unif, campione_unif, max_N) ;

  TApplication theApp ("theApp", &argc, argv) ;
  TCanvas c1 ; 
  histo_gauss.Draw () ;
  histo_unif.SetLineColor (kRed) ;
  histo_unif.Draw ("same") ;
  c1.Print ("histos.png") ;
  theApp.Run () ;

  return 0 ;
}