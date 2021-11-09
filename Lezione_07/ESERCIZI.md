# Esercizi per la lezione 7

## Esercizio 7.1

Si generi un campione di numeri pseudo-casuali 
distribuiti secondo una distribuzione di densità esponenziale
con tempo caratteristico t<sub>0</sub> di 5 secondi
e si visualizzi la distribuzione del campione ottenuto
in un ```TH1F``` utilizzando il metodo della funzione inversa.
Si scrivano tutte le funzioni deputate alla generazione di numeri casuali
in una libreria, implementata in file separati rispetto al programma principale.

![linea](../immagini/linea.png)

## Esercizio 7.2

Si utilizzi il risultato del primo esercizio per simulare uno pseudo-esperimento di conteggio
con caratteristiche di Poisson:
  * si scelga un tempo caratteristico t<sub>0</sub> di un processo di decadimento radioattivo;
  * si scelta un tempo di misura t<sub>M</sub> entro cui fare conteggi;
  * in un ciclo, si simulino N pseudo-esperimenti di conteggio, in cui,
    per ciascuno di essi, si simuli una sequenza di eventi casuali
    con intertempo caratteristico dei fenomeni di Poisson, 
    fino a che il tempo totale trascorso non sia maggiore del tempo di misura,
    contando il numero di eventi generati che cascano nell'intervallo;
  * si riempia un istogramma ```TH1F``` con i conteggi simulati per ogni esperimento  

![linea](../immagini/linea.png)

## Esercizio 7.3

Si utilizzi il codice sorgente scritto nell'esercizio precedente 
per aggiungere alla libreria sviluppata per l'esercizio 1
una funzione che generi numeri casuali
secondo la distribuzione di Poisson,
avendo la media di eventi attesi come parametro in ingresso.
Si riscriva l'esercizio precedente facendo uso di questa funzione, 
disegnando anche l'istogramma della densità di probabilità.

![linea](../immagini/linea.png)

## Esercizio 7.4

A partire dall'esercizio precedente,
  * si scriva un nuovo programma che riempia un ```vector``` con il campione generato;
  * si scriva una libreria che calcola le statistiche del campione 
    (media, varianza, asimmetria, curtosi)
    a partire dal ```vector``` come input;
  * si utilizzi il campione generato per fare il test di funzionamento della libreria.  

![linea](../immagini/linea.png)

## Esercizio 7.5

  * Si utilizzi il risultato dell'esercizio precedente
    per calcolare le statistiche di una distribuzione di Poisson 
    al variare della media, fra 1 e 20.
  * Si disegni l'andamento ottenuto di ciascuna statistica in funzione della media
    con quattro ```TGraph``` di ```ROOT```;
  * si disegnino in quattro ```TGraph``` in quattro ```TCanvas``` e si crei per ciascuno
    un'immagine salvata su disco.  




