/*
c++ -o esercizio05 `root-config --glibs --cflags` esercizio05.cpp casual.cc
*/

#include "casual.h"
#include "statistiche.h"
#include "TGraph.h"
#include "TCanvas.h"
#include <iostream>

using namespace std ;

int main (int argc, char ** argv)
{

  TGraph g_media ;
  TGraph g_sigma ;
  TGraph g_asimmetria ;
  TGraph g_curtosi ;

  // ciclo sulla media della distribuzione di Poisson
  for (int mediaP = 1 ; mediaP < 1001 ; mediaP+=10)
    {
      cout << "generazioni con media " << mediaP << endl ;
      vector<int> campione ;
    
      // ciclo su tanti pseudo-esperimenti
      for (int i = 0 ; i < 1000000 ; ++i)
        {
          campione.push_back (rand_pois (mediaP)) ;    
        } // ciclo su tanti pseudo-esperimenti
        
      g_media.SetPoint (g_media.GetN (), mediaP, media (campione)) ;
      g_sigma.SetPoint (g_sigma.GetN (), mediaP, sigma (campione)) ;
      g_asimmetria.SetPoint (g_asimmetria.GetN (), mediaP, asimmetria (campione)) ;
      g_curtosi.SetPoint (g_curtosi.GetN (), mediaP, curtosi (campione)) ;

    } // ciclo sulla media della distribuzione di Poisson

  TCanvas c1 ;
  g_media.SetMarkerStyle (4) ;
  g_media.SetMarkerColor (kBlue) ;
  g_media.Draw ("ALP") ;
  c1.Print ("es5_media.gif", "gif") ;

  g_sigma.SetMarkerStyle (4) ;
  g_sigma.SetMarkerColor (kBlue) ;
  g_sigma.Draw ("ALP") ;
  c1.Print ("es5_sigma.gif", "gif") ;

  g_asimmetria.SetMarkerStyle (4) ;
  g_asimmetria.SetMarkerColor (kBlue) ;
  g_asimmetria.Draw ("ALP") ;
  c1.Print ("es5_asimmetria.gif", "gif") ;

  g_curtosi.SetMarkerStyle (4) ;
  g_curtosi.SetMarkerColor (kBlue) ;
  g_curtosi.Draw ("ALP") ;
  c1.Print ("es5_curtosi.gif", "gif") ;

  return 0 ;
}