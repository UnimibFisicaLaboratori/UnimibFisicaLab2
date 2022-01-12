# Approfondimento A1: algoritmi predefiniti nelle *Standard Template Library*

## Indice

  * [A1.1 Introduzione](#introduzione)
    * [A1.2 ```std::find```](#stdfind)
    * [A1.2.1 il risultato di ```std::find```](#il-risultato-di-stdfind)
    * [A1.3 ```std::sort```](#stdsort)
    * [A1.3.1 risultato di ```std::sort```](#risultato-di-stdsort)
    * [A1.3.2 la relazione di ordine nell'ordinamento](#la-relazione-di-ordine-nellordinamento)
    * [A1.4 un esempio di utilizzo](#un-esempio-di-utilizzo)
  * [A1.5 ESERCIZI](#esercizi)

![linea](../immagini/linea.png)

## A1.1 Introduzione

  * insieme a strumenti per contenere informazioni, 
    le STL offrono **algoritmi per maneggiarle**
  * due operazoni importanti per maneggiare contenitori
    sono la **ricerca di un elemento al suo interno** e
    l'**ordinamento del suo contenuto**
  * gli algoritmi diventano disponibili
    ** includendo l'*header file* ```algorithm```**  

![linea](../immagini/linea.png)

### A1.2 ```std::find```

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

### A1.2.1 il risultato di ```std::find```

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

### A1.3 ```std::sort```

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

### A1.3.1 risultato di ```std::sort```

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

### A1.3.2 la relazione di ordine nell'ordinamento

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

### A1.4 un esempio di utilizzo

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

## A1.5 ESERCIZI

  * Gli esercizi relativi alla lezione si trovano [qui](ESERCIZI.md)


