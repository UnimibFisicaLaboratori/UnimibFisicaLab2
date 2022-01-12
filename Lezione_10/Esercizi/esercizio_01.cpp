/*
c++ -o esercizio_01 funzioni.cc casual.cc esercizio_01.cpp

Testo:
  Si scriva una libreria di funzioni per determinare il parametro τ della distribuzione 
  esponenziale utilizzata per generare gli eventi presenti nel file dati_esponenziali.txt, 
  a partire dal vector di numeri creato negli esercizi precedenti.

  Si implementino i prototipi delle funzioni presentate a lezione.
  Si confronti il risultato ottenuto con la media dei numeri salvati nel vector.
  Come dipende il risultato dall'intervallo inziale passato alla funzione sezione_aurea_max?
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "statistiche_vector.h"
#include "funzioni.h"
#include "casual.h"

using namespace std ;

int main (int argc, char ** argv)
  {

    if (argc < 2)
      {
        cerr << "uso: " << argv[0] << " numero_di_eventi [t_zero]" << endl ;
        exit (1) ;
      }

    double t_zero = 5. ;
    if (argc == 3) 
      {
        t_zero = atof (argv[2]) ;
      }

    vector<double> data ;
    for (int i = 0 ; i < atoi (argv[1]) ; ++i)
      {
        data.push_back (rand_exp (t_zero)) ;
      }

    cout << "generati " << data.size () << " eventi" << endl ;

    double media_v = media (data) ;
    cout << "media = " << media_v << endl ; 

    double massimo = sezione_aurea_max (loglikelihood, 0.5 * media_v, 1.5 * media_v, data) ;

    cout << "massimo della likelihood = " << massimo << endl ; 

    return 0 ;
}
