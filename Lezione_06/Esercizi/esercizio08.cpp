/*
Esercizio 08:Si inserisca il calcolo dell'integrale dell'esercizio precedente in un ciclo che, al variare del numero N di punti generati, mostri il valore dell'integrale e della sua incertezza.
Si utilizzi un TGraph per disegnare gli andamenti del valore dell'integrale e della sua incertezza, al variare di N con ragione logaritmica.
Si sovrapponga questo TGraph a quello ottenuto dallo svolgimento dell'Esercizio 6.6.

c++ -o esercizio08 esercizio08.cpp `root-config --glibs --cflags`
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "TH1F.h"
#include "TCanvas.h"
#include "TGraph.h"


float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


double fsin (double x) 
  {
    return sin (x) ; 
  }
  
 
void CrudeMC (int Nrand, double g(double), double xMin, double xMax, double* risultato_MC )
   {
     double lunghezza  = (xMax - xMin);
     double somma = 0;
     double sommaQ = 0;
     double media = 0;
     double varianza = 0;
     
     for (int i = 0; i<Nrand; i++)
     {
        double x = rand_range(xMin, xMax);
        somma += g(x);
        sommaQ += g(x)*g(x);     
     }
      
     media = somma/static_cast<double>(Nrand);
     varianza = sommaQ/static_cast<double>(Nrand) - media*media ;
                                   
     risultato_MC[0] = media*lunghezza ;
     risultato_MC[1] = sqrt (varianza/static_cast<double>(Nrand)) * lunghezza;
     
    return;       
   }  
   
void HitOrMiss (int Nrand, double g(double), double xMin, double xMax,
              double yMin, double yMax, double* risultato_HoM )
   {
     int nHit = 0;
     double area  = (xMax - xMin) * (yMax - yMin) ;
     
     for (int i = 0 ; i < Nrand ; ++i) 
      {
        double x = rand_range (xMin, xMax) ;
        double y = rand_range (yMin, yMax) ; 
        if (y < g (x)) ++nHit ; 
      }   
      
     double p = nHit / static_cast<double> (Nrand) ;
     double varianza = area * area / static_cast<double> (Nrand) * p * (1. - p) ;
           
     risultato_HoM[0] = nHit * area / static_cast<double> (Nrand) ;
     risultato_HoM[1] = sqrt (varianza) ;
      
    return;       
   }           
            
//----------------- MAIN -----------------
int main (int argc, char ** argv)
{ 
  srand (time (NULL)) ;
  int N = 50000 ;
  double x_min = 0. ;
  double x_max = M_PI ; 
  double y_min = 0. ; 
  double y_max = 1. ;
  double* risultato_MC = new double[2];
  double* risultato_HoM = new double[2];

  TGraph g_integrale_MC ;
  TGraph g_incertezza_MC;
  TGraph g_integrale_HoM ;
  TGraph g_incertezza_HoM;
  
 for (int iN = 10; iN < N; iN = iN*2)
  {  
    CrudeMC(iN,fsin,x_min,x_max,risultato_MC); 
    HitOrMiss(iN,fsin,x_min,x_max,y_min,y_max,risultato_HoM); 

    g_integrale_MC.SetPoint (g_integrale_MC.GetN(), iN, risultato_MC[0]) ;  
    g_incertezza_MC.SetPoint (g_incertezza_MC.GetN(), iN, risultato_MC[1]) ; 
    
    g_integrale_HoM.SetPoint (g_integrale_HoM.GetN(), iN, risultato_HoM[0]) ;  
    g_incertezza_HoM.SetPoint (g_incertezza_HoM.GetN(), iN, risultato_HoM[1]) ;                             
  }
  
  TCanvas c1 ("c1", "c1", 100, 100, 1000, 1000) ;
   c1.SetLogx () ; 

   g_integrale_HoM.SetMarkerStyle (21) ;
   g_integrale_HoM.SetMarkerColor (kBlue + 1) ;
   g_integrale_HoM.SetLineColor (kBlue - 9) ;
   g_integrale_HoM.SetMarkerSize (2) ;
   g_integrale_HoM.GetHistogram ()->GetXaxis ()->SetTitle ("numero di eventi generati") ;
   g_integrale_HoM.GetHistogram ()->GetYaxis ()->SetTitle ("integrale") ;
   g_integrale_HoM.GetHistogram ()->GetYaxis ()->SetRangeUser (1.1, 2.6) ; //definisco il range dell'asse y
   g_integrale_HoM.Draw ("ALP") ;

   g_integrale_MC.SetMarkerStyle (20) ;
   g_integrale_MC.SetMarkerColor (kRed + 1) ;
   g_integrale_MC.SetLineColor (kRed - 9) ;
   g_integrale_MC.SetMarkerSize (2) ;
   g_integrale_MC.Draw ("LPSAME") ;
   
   c1.Print ("esercizio8_integrale.png", "png") ; 
   
   TCanvas c2 ("c2", "c2", 100, 100, 1000, 1000) ;
   c2.SetLogx () ; 

   g_incertezza_HoM.SetMarkerStyle (21) ;
   g_incertezza_HoM.SetMarkerColor (kBlue + 1) ;
   g_incertezza_HoM.SetLineColor (kBlue - 9) ;
   g_incertezza_HoM.SetMarkerSize (2) ;
   g_incertezza_HoM.GetHistogram ()->GetXaxis ()->SetTitle ("numero di eventi generati") ;
   g_incertezza_HoM.GetHistogram ()->GetYaxis ()->SetTitle ("integrale") ;
   g_incertezza_HoM.Draw ("ALP") ;

   g_incertezza_MC.SetMarkerStyle (20) ;
   g_incertezza_MC.SetMarkerColor (kRed + 1) ;
   g_incertezza_MC.SetLineColor (kRed - 9) ;
   g_incertezza_MC.SetMarkerSize (2) ;
   g_incertezza_MC.Draw ("LPSAME") ;
   
   c2.Print ("esercizio8_incertezza.png", "png") ;    
                   
  delete[] risultato_MC;   
  delete[] risultato_HoM;       
            
  return 0 ;
}




