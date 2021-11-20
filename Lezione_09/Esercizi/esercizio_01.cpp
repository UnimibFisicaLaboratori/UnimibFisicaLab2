/*
c++ -o esercizio_01 casual.cc esercizio_01.cpp
*/

#include <iostream>
#include <vector>

#include "casual.h"

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

  cout << "generati: " << campione.size () << " numeri pseudo-casuali\n" ;
  return 0 ;
}
