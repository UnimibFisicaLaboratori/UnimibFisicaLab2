# Esercizi per la lezione 8

## Esercizio 8.1

Si scriva un programma che, fissato un numero *NMAX*,
generi *NToys* toy experiment,
ciascuno contenente un campione di *NMAX* eventi che seguano una distribuzione a scelta
e ne calcoli la media.

![linea](../immagini/linea.png)

## Esercizio 8.2

Si aggiunga al programma precedente un oggetto di tipo ```TH1F```
che visualizzi la distribuzione delle medie al variare dei toy experiment.

![linea](../immagini/linea.png)

## Esercizio 8.3

Si utilizzi la classe ```statistiche``` sviluppata durante la Lezione 4
per confrontare la deviazione standard della media calcolata per ogni singolo toy
con la deviazione standard del campione delle medie.

![linea](../immagini/linea.png)

## Esercizio 8.4

Si utilizzino due ```TGraph``` per confrontare l'evoluzione
della deviazione standard della media calcolata per ogni singolo toy
con la deviazione standard del campione delle medie
al variare del numero di eventi generati in un singolo toy experiment.

![linea](../immagini/linea.png)

## Esercizio 8.5

Si implementi il metodo di integrazione hit-or-miss
con la funzione di esempio *f(x) = sin (x)*.
  * Si scriva l'algoritmo che calcola l'integrale come una funzione esterna al programma ```main```,
    facendo in modo che prenda come parametri di ingresso,
    oltre agli estremi lungo l'asse *x* e l'asse *y*,
    anche il numero di punti pseudo-casuali da generare.
  * Si faccia in modo che l'algoritmo ritorni un contenitore contenente due elementi:
    il primo elemento sia il valore dell'integrale,
    il secondo sia la sua incertezza.

![linea](../immagini/linea.png)

## Esercizio 8.6

Si inserisca il calcolo dell'integrale dell'esercizio precedente in un ciclo che,
al variare del numero *N* di punti generati, mostri il valore dell'integrale
e della sua incertezza.
  * Si utilizzi un ```TGraph``` per disegnare gli andamenti del valore dell'integrale
    e della sua incertezza, al variare di *N* con ragione logaritmica.

![linea](../immagini/linea.png)

## Esercizio 8.7

Si implementi il metodo di integrazione crude-MC
con la funzione di esempio *f(x) = sin (x)*.
  * Si scriva l'algoritmo che calcola l'integrale come una funzione esterna al programma ```main```,
    facendo in modo che prenda come parametri di ingresso,
    oltre agli estremi lungo l'asse *x*,
    anche il numero di punti pseudo-casuali da generare.
  * Si faccia in modo che l'algoritmo ritorni un contenitore contenente due elementi:
    il primo elemento sia il valore dell'integrale,
    il secondo sia la sua incertezza.

![linea](../immagini/linea.png)

## Esercizio 8.8

Si inserisca il calcolo dell'integrale dell'esercizio precedente in un ciclo che,
al variare del numero *N* di punti generati, mostri il valore dell'integrale
e della sua incertezza.
  * Si utilizzi un ```TGraph``` per disegnare gli andamenti del valore dell'integrale
    e della sua incertezza, al variare di *N* con ragione logaritmica.
  * Si sovrapponga questo ```TGraph``` a quello ottenuto dallo svolgimento dell'Esercizio 8.6.

![linea](../immagini/linea.png)

## Esercizio 8.9

Si disegnino in due ```TGraph``` gli andamenti della precisione del calcolo dell'integrale,
per i due algoritmi di hit-or-miss e crude-MC, in funzione del tempo di calcolo
corrispondente alle varie scelte del numero totale *N* di eventi pseudo-casuali generati.

![linea](../immagini/linea.png)

## Esercizio 8.10

Si utilizzi il metodo hit-or-miss per stimare l’integrale sotteso
ad una disrtibuzione di probabilita' Gaussiana con *&mu;=0* e *&sigma;=1
in un generico intervallo *[a,b]*.
  * Si calcoli l'integrale contenuto entro gli intervalli *[-k&sigma;,k&sigma;]*
    al variare di k da *1* a *5*.
