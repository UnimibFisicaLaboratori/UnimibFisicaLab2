# Esercizi per la lezione 3

## Esercizio 3.1

  * Si crei un istogramma monodimensionale di tipo ```TH1F``` e lo si riempia con 5 valori
    compresi nel suo intervallo di definizione.
  * Si salvi l'immagine dell'istogramma in un file di tipo ```png```
    utilizzando un oggetto di tipo ```TCanvas``` ed il suo metodo ```TCanvas::Print```
  * Si visualizzi l'istogramma intereattivamente utilizzando
    un oggetto di tipo ```TApplication```

![linea](../immagini/linea.png)

## Esercizio 3.2

  Si svolga l'esercizio precedente utlizzando l'allocazione dinamica della memoria
  per creare l'oggetto di tipo ```TH1F```, senza dimenticare di pulire la memoria
  con l'istruzione ```delete``` prima del termine del programma.

![linea](../immagini/linea.png)

## Esercizio 3.3

Si legga il file di testo [```eventi_unif.txt```](https://raw.githubusercontent.com/UnimibFisicaLaboratori/UnimibFisicaLab2/master/Lezione_03/programmi/eventi_unif.txt):

  * si scrivano a schermo i suoi primi 10 elementi positivi;
  * si conti il numero di eventi contenuti nel file;
  * si trascriva il contenuto del file in un array opportunamente dimensionato
    e se ne scrivano a schermo i primi 10 elementi;
  * si determinino il minimo ed il massimo valore fra i numeri salvati nel file.

```{admonition} Istruzioni per scaricare il file
:class: tip
  Si possono utilizzare due metodi:
  1. aprire il link e fare `Salva come` (o `Save as`) dal browser
  2. utilizzare il comando `wget <link>` nella directory dove si desidera salvarlo (e.g.: `$ wget https://raw.githubusercontent.com/UnimibFisicaLaboratori/UnimibFisicaLab2/master/Lezione_03/programmi/eventi_unif.txt`)
```

![linea](../immagini/linea.png)

## Esercizio 3.4

Si legga il file di testo [```eventi_gauss.txt```](https://raw.githubusercontent.com/UnimibFisicaLaboratori/UnimibFisicaLab2/master/Lezione_03/programmi/eventi_gauss.txt):
  * si riempia un istogramma di tipo ```TH1F``` con i primi N numeri contenuti nel file,
    dove N è un parametro passato a linea di comando in fase di esecuzione del programma;
  * si scelga l'intervallo di definizione dell'istogramma ed il suo numero di bin
    in funzione dei numeri da rappresentare.  

![linea](../immagini/linea.png)

## Esercizio 3.5

Si legga il file di testo [```eventi_unif.txt```](https://raw.githubusercontent.com/UnimibFisicaLaboratori/UnimibFisicaLab2/master/Lezione_03/programmi/eventi_unif.txt):
  * si riempia un istogramma di tipo ```TH1F``` con i primi N numeri contenuti nel file,
    dove N è un parametro passato a linea di comando in fase di esecuzione del programma;
  * si scelga l'intervallo di definizione dell'istogramma ed il suo numero di bin
    in funzione dei numeri da rappresentare;
  * Si visualizzino, sovrapposte, le distribuzioni degli eventi contenuti nei due file,
    trovado il modo di ottenere la migliore visualizzazione per poter effettuare
    un confronto visivo fra i due istogrammi.

![linea](../immagini/linea.png)

## Esercizio 3.6

Si legga il file di testo [```eventi_unif.txt```](https://raw.githubusercontent.com/UnimibFisicaLaboratori/UnimibFisicaLab2/master/Lezione_03/programmi/eventi_unif.txt):
  * si calcoli la media dei numeri contenuti nel file di testo;
  * si calcoli la varianza dei numeri contenuti nel file di testo;
  * si calcoli la deviazione standard dei numeri contenuti nel file di testo;
  * si calcoli la deviazione standard dalla media dei numeri contenuti nel file di testo;

![linea](../immagini/linea.png)

## Esercizio 3.7

Si scriva una nuova classe, sotto forma di libreria,
che dato in input il nome di un file di testo contenente un campione di eventi,
sia in grado di salvare al proprio interno il campione,
calcolarne media, varianza, deviazione standard, deviazione standard dalla media,
visualizzare il campione in un istogramma
con intervallo di definizione e numero di bin scelto appropriatamente.
Si scriva un programma di test della classe creata.
