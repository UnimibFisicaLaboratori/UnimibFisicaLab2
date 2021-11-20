#include "utils.h"
#include "statistiche.h"

using namespace std ;

TH1F * crea_histo (const string & histo_name, const vector<double> & campione)
{
  double m = media (campione) ;
  double s = sigma (campione) ;
  double N = campione.size () ;
  double minimo_campione = *min_element (campione.begin (), campione.end ()) ;
  double massimo_campione = *max_element (campione.begin (), campione.end ()) ;
  double minimo_histo = max (minimo_campione, m - 5 * s) ;
  double massimo_histo = min (massimo_campione, m + 5 * s) ;
  int Nbin = 10 * log (N/10) ;

  TH1F * histo = new TH1F (
      histo_name.c_str (), histo_name.c_str (),
      Nbin, 
      minimo_histo, 
      massimo_histo
    ) ;

  for (int i = 0 ; i < campione.size () ; ++i)
    {
      histo->Fill (campione.at (i)) ;
    }
  return histo ;
}
