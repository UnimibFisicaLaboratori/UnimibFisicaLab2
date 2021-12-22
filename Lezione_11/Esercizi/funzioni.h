#ifndef funzioni_h
#define funzioni_h

// retta secondo il prototipo utilizzato da root
double retta (double * x, double * par) ;

// generazione di numeri casuali su un intervallo 
// con distribuzione uniforme
double rand_range (double min, double max) ;

// generazione di numeri casuali
// distribuiti secondo una Gaussiana
// con il metodo del teorema centrale del limite
float rand_TCL (double mean, double sigma, int N = 10) ;


#endif