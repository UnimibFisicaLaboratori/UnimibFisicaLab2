/*
c++ -o esercizio02 `root-config --glibs --cflags` esercizio02.cpp casual.cc
*/

#include "casual.h"
#include "TH1F.h"
#include "TCanvas.h"
#include <iostream>

using namespace std ;

int main (int argc, char ** argv)
{

  if (argc < 3)
    {
      cerr << "uso del programma: " 
           << argv[0]
           << " t_zero tempo_di_misura\n" ;  
      return 1 ;
    }

  double t_zero = atoi (argv[1]) ;           // tempo caratteristico dell'esponenziale
  double tempo_di_misura = atoi (argv[2]) ;  // tempo di misura

  int N = 3 * tempo_di_misura / t_zero ;
  TH1F h_pois ("h_pois", "h_pois", N, 0, N) ;

  // ciclo su tanti pseudo-esperimenti
  for (int i = 0 ; i < 1000000 ; ++i)
    {
      double t_tot = rand_exp (t_zero) ;
      int N_evt = 0 ;
      while (t_tot < tempo_di_misura)
        {
          ++N_evt ;
          t_tot += rand_exp (t_zero) ;
        }
      h_pois.Fill (N_evt) ;
    } // ciclo su tanti pseudo-esperimenti

  TCanvas c1 ;
  h_pois.SetFillColor (kAzure + 2) ;
  h_pois.Draw ("hist") ;
  c1.Print ("esercizio02.gif", "gif") ;

  return 0 ;
}