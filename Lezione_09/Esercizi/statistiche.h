#ifndef statistiche_h
#define statistiche_h

#include <cmath>
#include <vector>

template <class T>
double media (std::vector<T> const & inputV)
  {
    double sum = 0. ;
    for (int i = 0 ; i < inputV.size () ; ++i) sum += inputV.at (i) ;
    return sum / inputV.size () ;
  }

template <class T>
double varianza (std::vector<T> const & inputV)
  {
    double sum = 0. ;
    double sumSq = 0. ;
    for (int i = 0 ; i < inputV.size () ; ++i) 
      {
        sum += inputV.at (i) ;
        sumSq += inputV.at (i) * inputV.at (i) ;
      }
    return sumSq / inputV.size () - (sum * sum) / (inputV.size () * inputV.size ()) ;
  }

template <class T>
double sigma (std::vector<T> const & inputV)
  {
    return sqrt (varianza (inputV)) ;
  }

template <class T>
double asimmetria (std::vector<T> const & inputV)
  {
    double mediaV = media (inputV) ;
    double asimmV = 0. ;
    for (int i = 0 ; i < inputV.size () ; ++i) 
      {
        asimmV += pow ((inputV.at (i) - mediaV), 3.) ;
      }
    return asimmV / (inputV.size () * pow (sigma (inputV),3.)) ;
  }

template <class T>
double curtosi (std::vector<T> const & inputV) 
  {
    double mediaV = media (inputV) ;
    double curtosiV = 0. ;
    for (int i = 0 ; i < inputV.size () ; ++i) 
      {
        curtosiV += pow ((inputV.at (i) - mediaV), 4.) ;
      }
    return curtosiV / (inputV.size () * varianza (inputV) * varianza (inputV)) - 3. ;
  }

#endif