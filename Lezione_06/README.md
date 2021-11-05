# Lezione 6: zeri ed estremanti di funzioni

## Indice

  * [6.1 alla ricerca degli zeri di una funzione](#61-aree-positive-o-negative-alla-ricerca-degli-zeri-di-una-funzione)
    * [6.1.1 il metodo della bisezione](#611-il-metodo-della-bisezione)
    * [6.1.2 una implementazione dell'algoritmo di bisezione](#612-una-implementazione-dellalgoritmo-di-bisezione)
    * [6.1.3 una implementazione dell'algoritmo di bisezione in modo ricorsivo](#613-una-implementazione-dellalgoritmo-di-bisezione-in-modo-ricorsivo)
  * [6.2 la ricerca di estremanti: il metodo della sezione aurea](#62-la-ricerca-di-estremanti-il-metodo-della-sezione-aurea)
    * [6.2.1 il criterio di restringimento](#622-il-criterio-di-restringimento)
    * [6.2.2 l'ottimizzazione della scelta dei punti](#623-lottimizzazione-della-scelta-dei-punti)
  * [6.3 mettere tutto insieme](#63-mettere-tutto-insieme)
  * [6.4 ESERCIZI](#65-esercizi)

![linea](../immagini/linea.png)

## 6.1 alla ricerca degli zeri di una funzione

  * Esistono tecniche numeriche per **trovare gli zeri** di una funzione  
  * Ipotesi sempici:
    * Funzione *g(x)* **continua definita su un intervallo compatto e connesso** *[x<sub>0</sub>, x<sub>1</sub>]*
    * La funzione ha **un solo zero** nell'intervallo
    * Agli estremi dell'intervallo, i valori della funzione **hanno segno opposto**
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

  | attenzione |
  | -------- |

  * In ogni funzione ricorsiva, devono essere presenti **due elementi**:
    * L'**invocazione della funzione** stessa
    * La **condizione di uscita** dalla sequenza di auto-invocazioni

![linea](../immagini/linea.png)

### 6.2 la ricerca di estremanti: il metodo della sezione aurea
  
  * Ipotesi sempici:
    * funzione *g(x)* **continua definita su un intervallo compatto e connesso** *[x<sub>0</sub>, x<sub>1</sub>]*
    * la funzione ha **un solo estremante** nell'intervallo
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
  * L'iterazione successiva si restringe a
    *[x<sub>3</sub>, x<sub>1</sub>]* se *g(x<sub>3</sub>) > g(x<sub>2</sub>)*,
    altrimenti si restringe a *[x<sub>o</sub>, x<sub>2</sub>]*

![linea](../immagini/linea.png)

### 6.2.2 l'ottimizzazione della scelta dei punti
  
  * Per ottimizzare il calcolo,
    i punti *x<sub>2</sub>, x<sub>3</sub>* vengono scelti in modo
    che uno dei due possa essere **utilizzato anche nell'iterazione seguente**,
    garantendo la stessa proporzione di suddivisione dell'intervallo
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

## 6.4 ESERCIZI

  * Gli esercizi relativi alla lezione si trovano [qui](ESERCIZI.md)


