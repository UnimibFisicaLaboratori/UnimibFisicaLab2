# Lezione 6: zeri ed estremanti di funzioni

## Indice

  * [6.1 alla ricerca degli zeri di una funzione](#alla-ricerca-degli-zeri-di-una-funzione)
    * [6.1.1 il metodo della bisezione](#il-metodo-della-bisezione)
    * [6.1.2 una implementazione dell'algoritmo di bisezione](#una-implementazione-dell-algoritmo-di-bisezione)
    * [6.1.3 una implementazione dell'algoritmo di bisezione in modo ricorsivo](#una-implementazione-dell-algoritmo-di-bisezione-in-modo-ricorsivo)
  * [6.2 la ricerca di estremanti: il metodo della sezione aurea](#la-ricerca-di-estremanti-il-metodo-della-sezione-aurea)
    * [6.2.1 il criterio di restringimento](#il-criterio-di-restringimento)
    * [6.2.2 l'ottimizzazione della scelta dei punti](#l-ottimizzazione-della-scelta-dei-punti)
  * [6.3 mettere tutto insieme](#mettere-tutto-insieme)
  * [6.4 il disegno di funzioni e punti in ```ROOT```](#il-disegno-di-funzioni-e-punti-in-root)
  * [6.5 ESEMPI](#esempi)
  * [6.6 ESERCIZI](#esercizi)

![linea](../immagini/linea.png)

## 6.1 alla ricerca degli zeri di una funzione

  * Esistono tecniche numeriche per **trovare gli zeri** di una funzione
  ```{admonition} Ipotesi semplici
  :class: important
  * Funzione *g(x)* **continua definita su un intervallo compatto e connesso** *[x<sub>0</sub>, x<sub>1</sub>]*
  * Agli estremi dell'intervallo, i valori della funzione **hanno segno opposto**
  * La funzione ha **un solo zero** nell'intervallo
  ```
  <!--
  * Ipotesi sempici:
    * Funzione *g(x)* **continua definita su un intervallo compatto e connesso** *[x<sub>0</sub>, x<sub>1</sub>]*
    * Agli estremi dell'intervallo, i valori della funzione **hanno segno opposto**
    * La funzione ha **un solo zero** nell'intervallo -->

  ![funzione_con_zero](immagini/funzione_con_zero.png)

![linea](../immagini/linea.png)

### 6.1.1 il metodo della bisezione

  * Il programma non vede la funzione nella sua interezza,
    quindi l'unico modo che ha per determinare dove sia lo zero
    è **stimare la funzione in singoli punti**
  * Date le ipotesi iniziali,
    lo zero della funzione si trova sicuramente fra due punti tali per cui
    la funzione **assume valore con segno opposto** fra questi due punti  
  * La tecnica della bisezione **restringe iterativamente questo intervallo**  
    fino a che non diventa più piccolo di una risoluzione fissata
    ![bisezione](immagini/bisezione.png)

![linea](../immagini/linea.png)

### 6.1.2 una implementazione dell'algoritmo di bisezione

  * Ad ogni iterazione,
    si calcola il **punto medio dell'intervallo** che contiene lo zero
    e si decide se lo zero stia alla sua destra o alla sua sinistra
    ```cpp
    double bisezione (
      double g (double),
      double xMin,
      double xMax,
      double precision = 0.0001
    )
    {
      double xAve = xMin ;
      while ((xMax - xMin) > precision)
        {
          xAve = 0.5 * (xMax + xMin) ;
          if (g (xAve) * g (xMin) > 0.) xMin = xAve ;
          else                          xMax = xAve ;
        }
      return xAve ;
    }  
    ```


    <div style="text-align: right"> (esempio <a href="ESEMPI.html#esempio-di-ricerca-di-zeri">6.0</a>) </div>

![linea](../immagini/linea.png)

### 6.1.3 una implementazione dell'algoritmo di bisezione in modo ricorsivo

  * L'algoritmo di bisezione effettua ripetutamente la **stessa operazione**
    in maniera ricorsiva
  * Questo comportamento si può anche implementare in ```C++```,
    scrivendo una **funzione ricorsiva**,
    cioè che invoca se stessa:  
    ```cpp
    double bisezione_ricorsiva (
      double g (double),
      double xMin,
      double xMax,
      double precision = 0.0001
    )
    {
      double xAve = 0.5 * (xMax + xMin) ;
      if ((xMax - xMin) < precision) return xAve ;
      if (g (xAve) * g (xMin) > 0.) return bisezione_ricorsiva (g, xAve, xMax, precision) ;
      else                          return bisezione_ricorsiva (g, xMin, xAve, precision) ;
    }  
    ```

  <!-- | attenzione |
  | -------- | -->
  ```{admonition} Attenzione
  :class: warning
  In ogni funzione ricorsiva, devono essere presenti **due elementi**:
  * L'**invocazione della funzione** stessa
  * La **condizione di uscita** dalla sequenza di auto-invocazioni
  ```

<div style="text-align: right"> (esempio <a href="ESEMPI.html#esempio-di-bisezione-ricorsiva">6.1</a>) </div>

![linea](../immagini/linea.png)

### 6.2 la ricerca di estremanti: il metodo della sezione aurea

  ```{admonition} Ipotesi semplici
  :class: important
  * Funzione *g(x)* **continua definita su un intervallo compatto e connesso** *[x<sub>0</sub>, x<sub>1</sub>]*
  * la funzione ha **un solo estremante** nell'intervallo
  ```
  <!-- * Ipotesi sempici:
    * funzione *g(x)* **continua definita su un intervallo compatto e connesso** *[x<sub>0</sub>, x<sub>1</sub>]*
    * la funzione ha **un solo estremante** nell'intervallo -->

  ![funzione_con_minimo](immagini/funzione_con_minimo.png)

  * Anche in questo caso si procede per passi,
    **restringendo ad ogni iterazione l'intervallo** che contiene l'estremante
    fino a che diventa più piccolo di una precisione prefissata

![linea](../immagini/linea.png)

### 6.2.1 il criterio di restringimento

  * Per trovare il minimo di una funzione servono abbastanza punti da **capirne la pendenza**
    in diverse regioni dell'intervallo,
    quindi se ne cercano quattro, che determinano tre intervalli
  * L'intervallo si stringe **eliminando il tratto dove il minimo di sicuro non c'è**.
    ![sezione_aurea_pendenza](immagini/sezione_aurea_pendenza.png)
  * L'iterazione successiva si restringe a $[x_3,x_1]$ se $g(x_3) > g(x_2)$,
    altrimenti si restringe a $[x_0, x_2]$

![linea](../immagini/linea.png)

### 6.2.2 l'ottimizzazione della scelta dei punti

  * Per ottimizzare il calcolo,
    i punti $x_2, x_3$ vengono scelti in modo che uno dei due possa essere
    **utilizzato anche nell'iterazione seguente**, garantendo la stessa proporzione
    di suddivisione dell'intervallo
    ![sezione_aurea_r](immagini/sezione_aurea_r.png)
  * Perché questo sia possibile deve valere:
    ![sezione_aurea_r](immagini/sezione_aurea_formula.png)
  * Dunque **il processo iterativo si restringe** intorno all'estremante della funzione:  
    ![sezione_aurea_r](immagini/sezione_aurea.png)

![linea](../immagini/linea.png)

## 6.3 mettere tutto insieme

  * Esistono **molte tecniche** di ricerca di zeri ed estremanti di funzioni,
    che sono spesso il nocciolo duro di software di analisi dati  
  * Una collezione di algoritmi si trova nel volume **[numerical recipes](http://numerical.recipes/)**
  * Oltre al problema locale di compiere operazioni in condizioni di buona regolarità,
    algoritmi generici devono anche trovare il modo di
    **ricondurre un problema generale a casi semplici**
    * Ad esempio, nel caso della ricerca di minimi
      bisogna evitare che gli algoritmi trovino minimi locali
      e non identifichino il **minimo globale** di una funzione
  * La funzionalità di un algoritmo dipende criticamente dalla **dimensione
    dello spazio di definizione** delle funzioni   

![linea](../immagini/linea.png)

## 6.4 il disegno di funzioni e punti in ```ROOT```

  * una **funzione matematica in ROOT** si implementa con la classe ```TF1```
    ```
    TF1 fa1 ("fa1", "sin(x)/x", 0, 10) ;
    TCanvas c1 ;
    fa1.Draw () ;
    ```
    * esistono **molti modi di definire un oggetto di tipo ```TF1```**, 
      sia a partire dalla forma analitica delle funzioni
      che da una funzione scritta in ```C++```,
      descritti nelle [pagine di documentazione](https://root.cern.ch/root/html600/TF1.html) di ```ROOT```
  * un **punto** si disegna con la classe ```TMarker```:
    ```
    TMarker punto (5., 0.5, 20) ;
    ```  

<div style="text-align: right"> (esempio <a href="ESEMPI.html#esempio-di-disegno-di-un-punto-ed-una-funzione">6.2</a>) </div>

![linea](../immagini/linea.png)

## 6.5 ESEMPI

  * Gli esempi relativi alla lezione si trovano [qui](ESEMPI.rst)

![linea](../immagini/linea.png)

## 6.6 ESERCIZI

  * Gli esercizi relativi alla lezione si trovano [qui](ESERCIZI.md)
