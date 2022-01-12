# Approfondimento A3: approfondimenti su ```STL```

## Indice

  * [A3.1 algoritmi nelle STL](#algoritmi-nelle-stl)
    * [A3.1.1 ```std::find```](#stdfind)
    * [A3.1.2 il risultato di ```std::find```](#il-risultato-di-stdfind)
    * [A3.1.3 ```std::sort```](#stdsort)
    * [A3.1.4 risultato di ```std::sort```](#risultato-di-stdsort)
    * [A3.1.5 la relazione di ordine nell'ordinamento](#la-relazione-di-ordine-nellordinamento)
    * [A3.1.6 un esempio di utilizzo](#un-esempio-di-utilizzo)
  * [A3.2 Ereditarietà e ```template```](#ereditarietà-e-template)
  * [A3.3 Un utile strumento: la lettura e la scrittura di un *file* di testo](#un-utile-strumento-la-lettura-e-la-scrittura-di-un-file-di-testo)
    * [A3.3.1 L'implementazione della lettura](#limplementazione-della-lettura)
    * [A3.3.2 L'implementazione della scrittura](#limplementazione-della-scrittura)
    * [A3.3.3 Il controllo dell'apertura di un file](#il-controllo-dellapertura-di-un-file)
  * [A3.4 ESERCIZI](#esercizi)

![linea](../immagini/linea.png)


## A3.1 algoritmi nelle STL

  * insieme a strumenti per contenere informazioni,
    le STL offrono **algoritmi per maneggiarle**
  * due operazoni importanti per maneggiare contenitori
    sono la **ricerca di un elemento al suo interno** e
    l'**ordinamento del suo contenuto**
  * gli algoritmi diventano disponibili
    ** includendo l'*header file* ```algorithm```**  

![linea](../immagini/linea.png)

### A3.1.1 ```std::find```

  * il prototipo di questo algoritmo è il seguente:
    ```cpp
    template <class InputIterator, class T>
    InputIterator find (InputIterator first, InputIterator last, const T& val);
    ```
  * trova il **primo elemento** all'interno di un contenitore uguale a ```val```,
    nell'intervallo delimitato da due iteratori ```[first, last)```
    * per cercare su **tutto un contenitore** si passano come argomenti i suoi ```begin ()``` ed ```end ()```
  * utilizza l'**```operator==``` definito per il tipo ```T```** per la ricerca
    * deve essere definito!

![linea](../immagini/linea.png)

### A3.1.2 il risultato di ```std::find```

  * restituisce l'**iteratore** al primo elemento trovato uguale a ```val```
    * se **non trova nulla**, restituisce l'iteratore alla fine del contenitore
  ```cpp
  vector<float> v ;
  for (int i = 0 ; i < 10 ; ++i) v.push_back (0.5 * i) ;

  vector<float>::iterator risultato =
    find (v.begin (), v.end (), 3.5) ;

  if (risultato != v.end ()) cout << "trovato " << *risultato << endl ;
  ```

![linea](../immagini/linea.png)

### A3.1.3 ```std::sort```

  * esistono **due prototipi** per l'algoritmo di ordinamento
  * quello comunemente utilizzato funziona similmente a ```find```,
    perché agisce su un contenitore **tramite i suoi iteratori**:
    ```cpp
    template <class RandomAccessIterator>
    void sort (RandomAccessIterator first, RandomAccessIterator last);
    ```
  * utilizza l'**```operator<``` definito per il tipo ```T```**
    per ordinare in modo crescente il contenitore
    * deve essere definito!
  * per ordinare **tutto un contenitore** si passano
    come argomenti i suoi ```begin ()``` ed ```end ()```

![linea](../immagini/linea.png)

### A3.1.4 risultato di ```std::sort```

  * a partire da un ```vector``` riempito in questo modo:
    ```
    3, 2, 10, -1
    ```
  * la chiamata dell'algoritmo ```sort```:
    ```cpp
    sort (v.begin (), v.end ()) ;
    ```
    produce il seguente effetto sul contenuto del ```vector```:
    ```
    -1, 2, 3, 10
    ```

![linea](../immagini/linea.png)

### A3.1.5 la relazione di ordine nell'ordinamento

  * esiste un secondo prototipo di ```sort```,
    che permette di **indicare la funzione da usare
    per ordinare** il contenitore
    ```cpp
    template <class RandomAccessIterator, class Compare>
    void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp) ;
    ```
  * ```comp``` può essere una funzione o una classe
    * nel caso sia una **funzione**,
      deve prendere in **input** (per copia o referenza) due argomenti del tipo
      contenuto nel contenitore e restituire in **output** un tipo compatibile con un ```bool```.
    * nel caso sia una **classe**,
      deve contenere un ```operator()``` che prenda in **input** (per copia o referenza)
      due argomenti del tipo contenuto nel contenitore
      e restituisca in **output** un tipo compatibile con un ```bool```.

![linea](../immagini/linea.png)

### A3.1.6 un esempio di utilizzo

  * supponiamo di voler ordinare il vettore visto in precedenza
    **anteponendo i numeri pari a quelli dispari**.
    La funzione che deve sostituire la relazione di ```<``` è:
    ```cpp
    bool confronto (int i, int j)
      {
        if (i % 2 == 0)
          {
            if (j % 2 != 0) return true ;
            else return (i < j) ;
          }
        else
          {
            if (j % 2 == 0) return false ;
            else return (i < j) ;
          }
      }
    ```
  * In questo modo, la seguente chiamata:
    ```cpp
    sort (v.begin (), v.end (), confronto) ;
    ```
    restituisce:
    ```
    2, 10, -1, 3
    ```

![linea](../immagini/linea.png)

## A3.2 Ereditarietà e ```template```

  * L'ereditarietà e la programmazione ```template``` sono due tecniche
    che permettono di implementare il polimorfismo nel ```C++```
  * Entrambe le tecniche permettono infatti di **generalizzare il medesimo comportamento
    per diversi tipi**, senza necessariamente dover scrivere più volte lo stesso codice sorgente  
  * oltre al vantaggio pratico legato al tempo di scrittura dei programmi,
    questo comporta che le funzionalità vengono implementate meno volte,
    **rendendo più difficile commettere errori**
    e produrre programmi inconsistenti
  * le due tecniche sono complementari:
    mentre l'ereditarietà comporta polimorfismo **durante l'esecuzione del programma**,
    la programmazione template lo implementa **durante la compilazione**

![linea](../immagini/linea.png)

## A3.3 Un utile strumento: la lettura e la scrittura di un *file* di testo

  * Può essere comodo **salvare informazioni semplici** su file di testo,
    per poterle rileggere dai programmi di analisi dati
  * La gestione dell'accesso a file di testo in ```C++``` è **analoga
    alla scrittura a schermo e lettura da tastiera**:
    si utilizzano gli operatori di redirezione ```operator>>``` (per leggere)
    ed ```operator<<``` (per scrivere) fra un oggetto che rappresenta il file
    e le variabili

![linea](../immagini/linea.png)

### A3.3.1 L'implementazione della lettura

  * L'oggetto che rappresenta un file è di tipo ```fstream```:
    ```ifstream``` per lettura (**input file stream**) ed
    ```ofstream``` per scrittura (**output file stream**):
    ```cpp
    #include <fstream>
    // ...
    ifstream input_file ;
    input_file.open ("file.txt", ios::in) ;
    // ...
    vector<double> data ;
    double input_val ;
    while (true)
      {
        input_file >> input_val ;
        if (input_file.eof () == true) break ;
        data.push_back (input_val) ;
      }
    input_file.close () ;
    ```
    * In questo modo, una sequenza di numeri scritti nel file ```file.txt```
      vengono letti uno ad uno, **trasferendone il valore nella variabile ```input_val```**
    * Il valore della variabile, ad ogni lettura, viene aggiunto al ```vector``` chiamato ```data```
    * All'interno del file di testo,
      i valori sono seperati da spazi, tab o accapo.  
    * Al termine della lettura, il *file* viene chiuso.
    * la condizione ```input_file.eof () == true``` **non può essere controllata direttamente
      dall'istruzione ```while```**,
      perché l'ultima operazione di lettura riconosce la fine del file,
      senza leggere contenuto utile.

![linea](../immagini/linea.png)

### A3.3.2 L'implementazione della scrittura

  * In questo caso,
    si utilizza la classe ```ofstream``` per produrre un file che contiene numeri:
    ```cpp
    #include <fstream>
    // ...
    ofstream output_file ;
    output_file.open ("example.txt", ios::out) ;

    for (int i = 0 ; i < 10 ; ++i)
      {
        output_file << i << "\n" ;
      }  

    output_file.close () ;
    ```
    * l'**operatore di redirezione** ```<<``` funziona come nel caso di ```std::cout```,
      con il file come destilazione della redirezione,
      invece dello schermo
      * tutto ciò che si può scrivere a schermo può essere scritto in un file
    * **l'opzione ```ios::out```** passata al metodo ```ofstream::open```
      indica che il file con nome ```"example.txt"``` viene aperto per scrittura
      * se il file non esiste, viene creato
      * se il file esiste, viene sovrascritto, perdendo il contenuto del file precendente
    * aprendo il file con opzione ```ios::app```, invece,
      il file viene aperto e predisposto perché la scrittura avvenga
      **in coda al contenuto già presente nel file**

![linea](../immagini/linea.png)

### A3.3.3 Il controllo dell'apertura di un file

  * Per controllare se un file sia effettivamente stato aperto,
    si può utilizzare il metodo ```is_open```:
    ```cpp
    if (myfile.is_open ())
      {
        /* istruzioni da eseguire */
      }
    ```

![linea](../immagini/linea.png)

## A3.4 ESERCIZI

  * Gli esercizi relativi alla lezione si trovano [qui](ESERCIZI.md)
