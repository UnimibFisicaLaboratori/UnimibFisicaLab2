#include "funzioni.h"


double esponenziale (double x, double tau)
{
   if (tau == 0.) return 1. ;
   return exp (-1. * x / tau) / tau ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


Double_t exp_R (Double_t * x, Double_t * par)
{
  if (par[0] == 0.) return 1. ;
  return esponenziale (x[0], par[0]) ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


Double_t loglikelihood (Double_t * x, Double_t * par)
{
  double result = 0. ; 
  for (int i = 0 ; i < par[0] ; ++i) 
    {      
      result += log (esponenziale (par[i+1], x[0])) ;
    }  
  return result ;
}
