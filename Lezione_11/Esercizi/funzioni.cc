#include "funzioni.h"
#include <cmath>


double retta (double * x, double * par)
  {
    return par[0] + par[1] * x[0] ;
  }


double rand_range (double min, double max)
  {
    return min + (max - min) * rand () / static_cast<double> (RAND_MAX) ;
  } 


float rand_TCL (double mean, double sigma, int N)
  {
    double y = 0. ; 
    double xMin = mean - sqrt (3 * N) * sigma ;
    double xMax = mean + sqrt (3 * N) * sigma ;
    for (int i = 0 ; i < N ; ++i)
      y += rand_range (xMin, xMax) ;
    y /= N ;
    return y ;
  }
