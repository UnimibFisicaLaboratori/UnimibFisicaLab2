# Esercizi per la lezione 9

## Esercizio 9.1

Si scriva un programma che generi numeri pseudo-casuali 
distribuiti secondo una funzione esponenziale
e li scriva in un ```vector<double>```.
  * Si faccia in modo che il tempo caratteristico dell'esponenziale
    ed numero di eventi da generare sia passato a linea di comando
    come parametro del programma eseguibile.

![linea](../immagini/linea.png)

## Esercizio 9.2

Si aggiunga al programma precedente il codice sorgente che riempia un istogramma 
con i numeri presenti nel ```vector``` dove sono stati trasferiti
e che visualizzi l'istogramma a schermo.

![linea](../immagini/linea.png)

## Esercizio 9.3

Si scriva un programma 
che disegni in un ```TCanvas``` di ROOT la distribuzione di probabilità esponenziale
avendo fissato il parametro *t<sub>0</sub>* ad un numero passato da linea di comando
come parametro del programma eseguibile.

![linea](../immagini/linea.png)

## Esercizio 9.4

Si scriva una funzione ```loglikelihood``` che calcoli il logaritmo della verosimiglianza
al variare del parametro *t<sub>0</sub>*,
per un campione di eventi pseudo-casuali generati secondo le istruzioni dell'Esercizio 1.
Si scriva la funzione in modo che possa essere utilizzata per costruire una ```TF1```
di ```ROOT``` che ne disegni l'andamento in funzione di *t<sub>0</sub>*.
Si utilizzi il seguente prototipo:
```cpp
Double_t loglikelihood (Double_t * x, Double_t * par)
{
  // implementazione della funzione
}
```
dove:
   * ```Double_t * x``` è la variabile libera nel disegno, dunque *t<sub>0</sub>*
   * ```Double_t * par``` sono le informazioni aggiuntive dal punto di vista
     del disegno da effettuare, dunque il campione.
Si trovi il modo di passare alla funzione il campione di eventi e la sua lunghezza
tramite l'argomento ```par```.
Si ricordi che il logaritmo della verosimiglianza è definito
solamente per il caso in cui la *likelihood* sia strettamente positiva.

![linea](../immagini/linea.png)

## Esercizio 9.5

Si studi l'andamento della forma della log-likelihood in funzione del numero di eventi
che compongono il campione generato.

