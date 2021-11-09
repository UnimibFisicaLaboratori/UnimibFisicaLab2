/*
c++ -o esercizio04 esercizio04.cpp casual.cc
*/

#include "casual.h"
#include "statistiche.h"
#include <iostream>
#include <vector>

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

  double mediaP = atoi (argv[1]) ; // media della distribuzione di Poisson

  vector<int> campione ;

  // ciclo su tanti pseudo-esperimenti
  for (int i = 0 ; i < 1000000 ; ++i)
    {
      campione.push_back (rand_pois (mediaP)) ;

    } // ciclo su tanti pseudo-esperimenti
    
  cout << "media del campione:      " << media (campione) << "\n" ;  
  cout << "varianza del campione:   " << varianza (campione) << "\n" ;  
  cout << "sigma del campione:      " << sigma (campione) << "\n" ;  
  cout << "asimmetria del campione: " << asimmetria (campione) << "\n" ;  
  cout << "curtosi del campione:     " << curtosi (campione) << "\n" ;  
  return 0 ;
}