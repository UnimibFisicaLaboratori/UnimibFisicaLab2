# Aopprofondimento 5: il salvataggio su file di classi di ROOT

## Indice

  * [A5.5 Una funzionalità utile: il salvataggio degli oggetti di ```ROOT```](#A5-una-funzionalita-utile-il-salvataggio-degli-oggetti-di-root)
    * [A5.5.1 La scrittura di un oggetto su un file](#A51-la-scrittura-di-un-oggetto-su-un-file)
    * [A5.5.2 Come aprire un terminale di ```ROOT```](#A52-come-aprire-un-terminale-di-root)
    * [A5.5.3 Come guardare dentro ad un file](#A53-come-guardare-dentro-ad-un-file)


![linea](../immagini/linea.png)

## A5.5 Una funzionalità utile: il salvataggio degli oggetti di ```ROOT```

  * Un oggetto utilizzato per fare analisi dati in ```ROOT```
    tipicamente può essere **salvato in un file binario** di tipo ```.root```
  * Analogamente al salvataggio su file di testo, 
    si utilizza una **classe dedicata alla gestione del file**:
    in questo caso, ```TFile```:
    ```cpp
    #include "TFile.h"
    //...
    TFile f_out ("salvataggio.root", "recreate") ;
    ```
    * il **primo argomento** è il nome del file da salvare su disco
    * il **secondo argomento** è la modalità di apertura del file:
      ```recreate``` apre il file in scrittura e ne cancella il contenuto,
      se il file è già esistente

![linea](../immagini/linea.png)

### A5.5.1 La scrittura di un oggetto su un file

  * Dopo aver creto un oggetto di tipo ```TFile```, 
    si possono **scrivere al suo interno** altri oggetti,
    utilizzando il metodo ```Write``` degli oggetti stessi:
    ```cpp
    #include "TFile.h"
    //...
    TH1F h_test ("h_test", "istogramma di test", 10, 0., 10) ;
    h_test.Fill (5.3) ;

    TFile f_out ("salvataggio.root", "recreate") ;
    h_test.Write () ;
    f_out.Close () ;
    ```
  * Al termine della scrittura, il file va **chiuso**

![linea](../immagini/linea.png)

### A5.5.2 Come aprire un terminale di ```ROOT```

  * Un file di tipo ```.root``` può essere **letto dalla linea di comando di ```ROOT```**
  * Per aprire la linea di comando,
    si esegue da ```SHELL``` il comando **```root```**:
    ```
    > root
     ------------------------------------------------------------------
    | Welcome to ROOT 6.20/04                        https://root.cern |
    | (c) 1995-2020, The ROOT Team; conception: R. Brun, F. Rademakers |
    | Built for macosx64 on Apr 01 2020, 08:28:48                      |
    | From tags/v6-20-04@v6-20-04                                      |
    | Try '.help', '.demò, '.licensè, '.credits', '.quit'/'.q'       |
     ------------------------------------------------------------------
 
    root [0] 
    ```
  * In questa linea di comando,
    ```ROOT``` fornisce un **interprete di istruzioni ```C++```** 
    che possono essere inserite a mano
    * Essendo interpretate, sono tipicamente molto **più lente** di un programma compilato

![linea](../immagini/linea.png)

### A5.5.3 Come guardare dentro ad un file

  * Se il comando ```root``` viene **seguito dal nome del file da aprire**,
    ```ROOT``` crea automaticamente il puntatore ad un oggetto ti dipo ```TFile``` con nome ```_file0```
    che punta al ```TFile``` stesso:
    ```
    root [0] 
    Attaching file main_03.root as _file0...
    (TFile *) 0x7ffb3f44eb80
    root [1] 
    ```
  * A questo punto, 
    è possibile **operare sugli oggetti** contenuti nel ```TFile```, 
    come se fossero puntatori:
    ```
    root [1] _file0->ls ()
    TFile**   main_03.root  
    TFile*   main_03.root  
    KEY: TH1F h_test;1  istogramma di test
    root [2] h_test->Draw ()
    Info in <TCanvas::MakeDefCanvas>:  created default TCanvas with name c1
    ```

![linea](../immagini/linea.png)
