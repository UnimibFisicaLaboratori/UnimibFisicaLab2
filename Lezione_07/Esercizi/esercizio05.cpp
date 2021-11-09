/*
c++ -o esercizio05 `root-config --glibs --cflags` esercizio05.cpp casual.cc
*/

#include "casual.h"
#include "statistiche.h"
#include "TH1F.h"
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
  for (int mediaP = 1 ; mediaP < 101 ; mediaP+=5)
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

  TCanvas c1 ("c1", "c1", 100, 100, 1000, 1000) ;

  g_media.SetMarkerStyle (20) ;
  g_media.SetMarkerColor (kAzure - 1) ;
  g_media.SetLineColor (kGray + 1) ;
  g_media.SetMarkerSize (2) ;
  g_media.GetHistogram ()->GetXaxis ()->SetTitle ("media della distribuzione") ;
  g_media.GetHistogram ()->GetYaxis ()->SetTitle ("media del campione") ;
  g_media.Draw ("ALP") ;
  c1.Print ("es5_media.gif", "gif") ;

  g_sigma.SetMarkerStyle (20) ;
  g_sigma.SetMarkerColor (kAzure - 1) ;
  g_sigma.SetLineColor (kGray + 1) ;
  g_sigma.SetMarkerSize (2) ;
  g_sigma.GetHistogram ()->GetXaxis ()->SetTitle ("media della distribuzione") ;
  g_sigma.GetHistogram ()->GetYaxis ()->SetTitle ("deviazione standard del campione") ;
  g_sigma.Draw ("ALP") ;
  c1.Print ("es5_sigma.gif", "gif") ;

  g_asimmetria.SetMarkerStyle (20) ;
  g_asimmetria.SetMarkerColor (kAzure - 1) ;
  g_asimmetria.SetLineColor (kGray + 1) ;
  g_asimmetria.SetMarkerSize (2) ;
  g_asimmetria.GetHistogram ()->GetXaxis ()->SetTitle ("media della distribuzione") ;
  g_asimmetria.GetHistogram ()->GetYaxis ()->SetTitle ("asimmetria del campione") ;
  g_asimmetria.Draw ("ALP") ;
  c1.Print ("es5_asimmetria.gif", "gif") ;

  g_curtosi.SetMarkerStyle (20) ;
  g_curtosi.SetMarkerColor (kAzure - 1) ;
  g_curtosi.SetLineColor (kGray + 1) ;
  g_curtosi.SetMarkerSize (2) ;
  g_curtosi.GetHistogram ()->GetXaxis ()->SetTitle ("media della distribuzione") ;
  g_curtosi.GetHistogram ()->GetYaxis ()->SetTitle ("curtosi del campione") ;
  g_curtosi.Draw ("ALP") ;
  c1.Print ("es5_curtosi.gif", "gif") ;

  return 0 ;
}