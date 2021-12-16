/*
c++ -o esercizio_03 esercizio_03.cpp funzioni.cc `root-config --glibs --cflags`
*/

#include <iostream>
#include <vector>
#include <cmath>

#include "TF1.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TFitResult.h"

#include "funzioni.h"


using namespace std ;

int main (int argc, char ** argv)
{

  int nPoints = 10 ;
  double min = 0.5 ;
  double max = 10.5 ;
  double epsilon = 0.15 ;

  TF1 f_true ("f_true", retta, 0., 2. * nPoints, 2) ;
  f_true.SetParameter (0, 0.4) ;
  f_true.SetParameter (1, 1.5) ;

  vector<double> v_x ;
  vector<double> v_y ;

  double x = 0. ;
  for (int i = 0 ; i < nPoints ; ++i)
    {
      x+= rand_range (0., 1.) ;
      v_x.push_back (x) ;
      double y = f_true.Eval (x) + rand_TCL (0, epsilon) ;
      v_y.push_back (y) ;
    }
  
  // errore sulle coordinate x dei punti
  vector<double> v_ex (v_x.size (), 0.) ;
  // errore sulle coordinate y dei punti
  vector<double> v_ey (v_y.size (), epsilon);

  TGraphErrors g_retta (v_x.size (), &v_x[0], &v_y[0], &v_ex[0], &v_ey[0]) ;
  g_retta.SetMarkerStyle (4) ;
  g_retta.SetMarkerColor (kRed) ;

  TF1 f_fit ("f_fit", retta, 0., 2. * nPoints, 2) ;
  TFitResultPtr fit_result = g_retta.Fit (&f_fit, "S") ;

  cout << endl ;
  cout.precision (3) ;
  cout << "risultato del fit: " << fit_result->IsValid () << endl ;
  cout << "termine noto : " << f_fit.GetParameter (0) << "\t+- " << f_fit.GetParError (0) << endl ;
  cout << "pendenza     : " << f_fit.GetParameter (1) << "\t+- " << f_fit.GetParError (1) << endl ;

  TCanvas c1 ;
  g_retta.Draw ("AP") ;
  c1.Print ("retta.png", "png") ; 

  return 0 ;
}