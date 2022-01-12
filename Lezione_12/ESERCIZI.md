# Esercizi per la lezione 12

## Esercizio 12.1

Si scriva un programma che effettui il fit degli eventi salvati nel file [```dati.txt```](https://raw.githubusercontent.com/UnimibFisicaLaboratori/UnimibFisicaLab2/master/Lezione_12/programmi/dati.txt),
utilizzando gli algoritmi di ```ROOT``` ed il modello descritto nella Lezione.
  * Si abbia cura di determinare l'intervallo di definizione ed il binning dell'istogramma utilizzato per il fit
    a partire dagli eventi medesimi,
    scrivendo algoritmi appropriati che determinino il minimo ed il massimo fra i dati
    ed una stima ragionevole del numero di bin da utilizzare.
  * Si determinino i valori iniziali dei parametri del fit
    con le tecniche descritte a lezione.
  * Si stampi a schermo il risultato del fit,
    includendo un test di bontà del fit.
  * Si disegni l'istogramma con il modello fittato sovrapposto.  

![linea](../immagini/linea.png)

## Esercizio 12.2

Utilizzando il programma [```main_03.cpp```](https://raw.githubusercontent.com/UnimibFisicaLaboratori/UnimibFisicaLab2/master/Lezione_12/programmi/main_03.cpp),
si generi un file ```dati_2.txt``` contenente 10,000 eventi
distribuiti secondo una distribuzione di probabilità Gaussiana.

![linea](../immagini/linea.png)

## Esercizio 12.3

Si scriva un programma che effettui il fit degli eventi salvati nel file ```dati_2.txt```
con il metodo della massima verosimiglianza e con il metodo dei minimi quadrati
e si confronti il risultato delle due tecniche,
comparando i valori studiati nell'esercizio 12.1 per i parametri e per la bontà del fit.

![linea](../immagini/linea.png)

## Esercizio 12.4

Si inserisca il codice sorgente dell'esercizio precedente in un ciclo
che effettui il confronto al variare del numero di eventi considerato per il fit,
da ```20``` a ```10000```, con andamento regolare in scala logaritmica.
  * Si utilizzino diversi ```TGraphErrors```
    per disegnare l'andamento dei parametri e delle loro incertezze
    al variare del numero di eventi, per i due tipi di stimatore.
  * Quale stimatore risulta meno distorto, a bassa statistica?  
