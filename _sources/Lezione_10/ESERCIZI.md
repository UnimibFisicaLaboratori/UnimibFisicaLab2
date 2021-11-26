# Esercizi per la lezione 10


## Esercizio 10.1

Si scriva una libreria di funzioni per determinare il parametro &tau; della distribuzione esponenziale
a partire da un ```vector``` di numeri riempito con numeri pseudo-casuali 
distribuiti secondo una distribuzione di densità di probabilità esponenziale.
  * Si implementino i prototipi delle funzioni presentate a lezione.
  * Si confronti il risultato ottenuto con la media dei numeri salvati nel ```vector```.
  * Come dipende il risultato dall'intervallo inziale passato alla funzione ```sezione_aurea_max```?

![linea](../immagini/linea.png)

## Esercizio 10.2

Si modifichi la funzione ```sezione_aurea_max```,
aggiungendo la stampa a schermo dei valori degli estremi dell'intevallo considerato ad ogni iterazione,
per osservarne il restringimento durante l'esecuzione del programma.

![linea](../immagini/linea.png)

## Esercizio 10.3

Si modifichi la funzione ```loglikelihood``` in modo che calcoli il logaritmo del prodotto
dei valori della funzione di densità di probabilità, piuttosto che la somma dei singoli logaritmi.
Come cambia il comportamento dell'algoritmo?

![linea](../immagini/linea.png)

## Esercizio 10.4

Si utilizzi il metodo della bisezione per trovare i due punti 
*&tau; - &sigma;<sub>&tau;</sub>* e *&tau; + &sigma;<sub>&tau;</sub>* 
nel caso dell'esercizio precedente.
  * Si confronti il valore di *&sigma;<sub>&tau;</sub>* ottenuto in questo modo
    con quello calcolato a partire dalla media aritmetica
    dei numeri salvati nel ```vector```.

![linea](../immagini/linea.png)

## Esercizio 10.5

Utilizzando il generatore di numeri pseudo-casuali secondo una pdf esponenziale
sviluppato nelle lezioni passate, si disegni la distribuzione di probabilita' dello stimatore di &tau;
in funzione del numero di eventi a disposizione per la stima.

![linea](../immagini/linea.png)

## Esercizio 10.6

In regime asintotico,
la distribuzione degli scarti *(&tau; - &tau;<sub>vero</sub>) / &sigma;<sub>&tau;</sub>* 
ha forma Normale.
  * Si utilizzi il metodo dei *toy experiment* per riempire l'istogramma degli scarti, 
    dato un numero di eventi per *toy experiment*.
  * Si calcoli la media e la sigma della distribuzione degli scarti
    e se ne disegni il valore al variare del numero di eventi a disposizione per la stima,
    riempiendo un ```TGraph``` con il numero di eventi a disposizione sull'asse orizziontale
    ed il valore del parametro sull'asse verticale.




