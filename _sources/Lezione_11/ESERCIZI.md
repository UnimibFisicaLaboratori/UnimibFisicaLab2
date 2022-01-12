# Esercizi per la lezione 11

## Esercizio 11.1

  * Dopo aver definito, in un'apposita libreria,
    una funzione $\phi(x, \theta)$ lineare in due parametri $\theta$,
  * Si scriva un programma che generi un insieme di *10* coppie $(x_i,y_i)$
    tali per cui i punti $x_i$ siano disposti casualmente sull'asse orizzontale
    fra 0 e 10 ed i punti $y_i$ siano costruiti a partire dalla formula $y_i = \phi(x_i,\theta) + \epsilon_i$.

![linea](../immagini/linea.png)

## Esercizio 11.2

  * Si aggiunga al programma precedente la trasposizione dei punti generati in un ```TGraphErrors``` di ```ROOT```.

![linea](../immagini/linea.png)

## Esercizio 11.3

  * Si aggiunga al programma precendente la costruzione di una ```TF1``` di ```ROOT```
    che contenga il medesimo modello $\phi(x, \theta)$ utilizzato per la generazione pseudo-casuale
    delle coppie di punti
    e si utilizzi questa ```TF1``` per fare un fit del ```TGraphErrors```.
  * Si controlli che il fit abbia avuto successo e
  * si stampi a schermo il valore dei parametri determinati e la loro sigma.  

![linea](../immagini/linea.png)

## Esercizio 11.4

  * Si calcoli il valore di $Q^2$ a partire dai punti e dalla funzione di fit
    ottenuta nell'esercizio precedente.
    (si ricordi che si può calcolare $\phi(x, \theta)$ utilizzando il metodo ```TF1::Eval (Double_t)```)
  * Si confronti il numero così ottenuto con quello calcolato da ```ROOT```,
    che si può ottenere dal risultato del fit utilizzando il metodo ```FitResult::Chi2 ()```.
  * Si stampi a schermo il valore del numero di gradi di libertà del fit,
    utilizzando il metodo ```FitResult::Ndf ()```.

![linea](../immagini/linea.png)

## Esercizio 11.5

  * Utilizzando la tecnica dei toy experiment,
    si generino 10,000 esperimenti di fit con il modello studiato negli esercizi precedenti
    e si riempia un istogramma dei valori di $Q^2$ ottenuti.

![linea](../immagini/linea.png)

## Esercizio 11.6

  * Si modifichi il programma precedente alterando volutamente l'incertezza sperimentale
    associata ai punti $y_i$ nei ```TGraphErrors```
    e si verifichi che si possa risalire alla incertezza utilizzata nella generazione dei punti
    tramite il valore di aspettazione della variabile $Q^2$.

![linea](../immagini/linea.png)

## Esercizio 11.7

  * Si aggiunga all'esercizio 11.3 la scrittura a schermo dell'intera matrice di covarianza
    dei parametri del fit.
