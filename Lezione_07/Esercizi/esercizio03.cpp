/*
c++ -o esercizio03 `root-config --glibs --cflags` esercizio03.cpp casual.cc
*/

#include "casual.h"
#include "TH1F.h"
#include "TCanvas.h"
#include <iostream>

using namespace std ;

int main (int argc, char ** argv)
{

  if (argc < 2)
    {
      cerr << "uso del programma: " 
           << argv[0]
           << " media_attesa\n" ;  
      return 1 ;
    }

  double media = atoi (argv[1]) ; // media della distribuzione di Poisson

  int N = 3 * media ;
  TH1F h_pois ("h_pois", "h_pois", N, 0, N) ;

  // ciclo su tanti pseudo-esperimenti
  for (int i = 0 ; i < 1000000 ; ++i)
    {
      h_pois.Fill (rand_pois (media)) ;
    } // ciclo su tanti pseudo-esperimenti

  TCanvas c1 ;
  h_pois.SetFillColor (kAzure + 4) ;
  h_pois.Draw ("hist") ;
  c1.Print ("esercizio03.gif", "gif") ;

  h_pois.DrawNormalized ("hist") ;
  c1.Print ("esercizio03_pdf.gif", "gif") ;

  return 0 ;
}