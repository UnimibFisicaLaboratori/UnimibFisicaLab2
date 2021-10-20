/*
c++ -o esercizio03 esercizio03.cpp
*/

#include <iostream>
#include <fstream>

#include "dynarray.h"

using namespace std ;

int main (int argc, char ** argv)
{

  if (argc < 2)
    {
      cerr << "manca il nome del file da leggere" << endl ;
      exit (1) ;
    }
  ifstream input_file (argv[1]) ;
  dynarray elementi ;
  double input_val = 0. ;
  while (true)
    {
      input_file >> input_val ;
      if (input_file.eof () == true) break ;
      elementi.aggiungi (input_val) ;
    }
  input_file.close () ;

  cout << "letti " << elementi.dim () << " numeri\n" ;

  for (int i = 0 ; i < 10 ; ++i)
    {
      cout << "elemento " << i
           << " : " << elementi.leggi (i) 
           << "\n" ;
    }

  for (int i = 0 ; i < 20 ; i+=2)
    {
      cout << "elemento " << i
           << " : " << elementi.leggi (i) 
           << "\n" ;
    }

  double elem_max = elementi.leggi (0) ;
  double elem_min = elementi.leggi (0) ;

  for (int i = 0 ; i < elementi.dim () ; ++i)
    {
      if (elementi.leggi (i) < elem_min) elem_min = elementi.leggi (i) ;
      if (elementi.leggi (i) > elem_min) elem_max = elementi.leggi (i) ;
    }

  cout << "minimo:  " << elem_min << "\n" ;
  cout << "massimo: " << elem_max << "\n" ;

  return 0 ;
}