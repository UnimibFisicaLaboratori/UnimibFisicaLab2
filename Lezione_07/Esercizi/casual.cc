#include "casual.h"
#include <cstdlib>
#include <cmath>

double rand_range (double min, double max)
{
  return min + (max - min) * rand () / static_cast<double> (RAND_MAX);
}

float rand_exp (double t_zero)
{
  return -1. * log (1 - rand_range (0., 1.)) * t_zero ;
}

float rand_pois (double media) 
{
  double t_tot = rand_exp (1.) ;
  int N_evt = 0 ;
  while (t_tot < media)
    {
      ++N_evt ;
      t_tot += rand_exp (1.) ;
    }
  return N_evt ;
}
