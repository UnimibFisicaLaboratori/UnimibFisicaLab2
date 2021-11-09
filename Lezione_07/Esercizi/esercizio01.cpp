/*
c++ -o esercizio01 `root-config --glibs --cflags` esercizio01.cpp casual.cc
*/

#include "casual.h"
#include "TH1F.h"
#include "TCanvas.h"

int main (int argc, char ** argv)
{
  double t_zero = 5. ;
  TH1F h_expo ("h_expo", "h_expo", 100, 0., 30. * t_zero) ;
  for (int i = 0 ; i < 1000000 ; ++i)
    {
      h_expo.Fill (rand_exp (t_zero)) ;
    }

  TCanvas c1 ;
  h_expo.SetFillColor (kOrange) ;
  h_expo.Fit ("expo") ;
  h_expo.Draw ("hist") ;
  c1.Print ("esercizio01.gif", "gif") ;

  return 0 ;
}