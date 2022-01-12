# Approfondimento 4: i minimi quadrati ed il caso lineare: soluzione algebrica

## Indice

  * [A4.1 Introduzione](#introduzione)
    * [A4.1.1 Un esempio immediato](#un-esempio-immediato)
    * [A4.1.2 Il caso *y=g(x)*](#il-caso-ygx)
    * [A4.1.3 La determinazione dei parametri &theta;](#la-determinazione-dei-parametri-theta)
    * [A4.1.4 Le proprietà del metodo](#le-proprietà-del-metodo)
  * [A4.2 Il caso lineare](#il-caso-lineare)
    * [A4.2.1 La formulazione matriciale](#la-formulazione-matriciale)
    * [A4.2.2 Le espressioni dei singoli elementi](#le-espressioni-dei-singoli-elementi)
    * [A4.2.3 Il valore dei parametri e della loro incertezza](#il-valore-dei-parametri-e-della-loro-incertezza)
  * [A4.3 Un esempio: il fit di una retta](#un-esempio-il-fit-di-una-retta)
    * [A4.3.1 L'algebra delle matrici](#lalgebra-delle-matrici)
    * [A4.3.2 Gli strumenti a disposizione](#gli-strumenti-a-disposizione)
    * [A4.3.3 La generazione dei punti da interpolare](#la-generazione-dei-punti-da-interpolare)
    * [A4.3.4 La preparazione di matrici e vettori](#la-preparazione-di-matrici-e-vettori)
    * [A4.3.5 La stima dei parametri &theta;](#la-stima-dei-parametri-theta)
    * [A4.3.6 La stampa del risultato](#la-stampa-del-risultato)
  * [A4.4 Le proprietà statistiche degli stimatori](#le-proprietà-statistiche-degli-stimatori)
    * [A4.4.1 Gli elementi del ciclo](#gli-elementi-del-ciclo)
    * [A4.4.2 La distribuzione delle stime](#la-distribuzione-delle-stime)
    * [A4.4.3 Il risultato ottenuto](#il-risultato-ottenuto)
    * [A4.4.4 La copertura dell'intervallo di confidenza](#la-copertura-dellintervallo-di-confidenza)
    * [A4.4.5 Il risultato del test](#il-risultato-del-test)
    * [A4.4.6 La correlazione fra i parametri](#la-correlazione-fra-i-parametri)
    * [A4.4.7 La visualizzazione della correlazione](#la-visualizzazione-della-correlazione)
    * [A4.4.8 Il riempimento dell'istogramma](#il-riempimento-dellistogramma)
  * [A4.5 La stima di una incertezza ignota](#la-stima-di-una-incertezza-ignota)
    * [A4.5.1 La distribuzione attesa di *Q<sup>2</sup><sub>min</sub>*](#la-distribuzione-attesa-di-qsup2supsubminsub)
    * [A4.5.2 Il calcolo della varianza di *y<sub>i</sub>*](#il-calcolo-della-varianza-di-ysubisub)
  * [A4.6 ESERCIZI](#107-esercizi)

![linea](../immagini/linea.png)

## A4.1 Introduzione

  * Il metodo dei **minimi quadrati** si basa su un principio indipendente
    rispetto a quello della massima verosimiglianza
  * Si scelgono i parametri &theta; che rendono **minima la distanza** 
    fra il modello ed i dati, 
    secondo una metrica definita dagli scarti quadratici medi

![linea](../immagini/linea.png)

### A4.1.1 Un esempio immediato

  * Per determinare la media &mu; di un insieme di misure *x<sub>i</sub>*
    si può minimizzare la funzione:
![Q_media](immagini/Q_media_2.png)

![linea](../immagini/linea.png)

### A4.1.2 Il caso *y=g(x)*

  * La stessa metrica viene spesso utilizzata
    per fare **regressioni sui dati**, chiamata anche *fit*
  * Siano date *N* coppie di misure indipendenti del tipo *(x<sub>i</sub>, y<sub>i</sub> )*,
    per le quali:
    * l'incertezza sul valore *x<sub>i</sub>* sia **nulla o trascuarbile**
    * **l'incertezza sul valore *y<sub>i</sub>*** sia &sigma;<sub>i</sub>
  * Sia data l'ipotesi che le due variabili *x<sub>i</sub>* e *y<sub>i</sub>*
    siano in **relazione fra loro secondo una funzione *g*** tale per cui *y=g(x,&theta;)*
  * Si definisce la **funzione *Q<sup>2</sup>(&theta;)*** come:
![Q_funzione_2](immagini/Q_funzione_2.png)

![linea](../immagini/linea.png)

### A4.1.3 La determinazione dei parametri &theta;

  * In questo caso, i parametri &theta; (&theta; può essere un vettore)
    si determinano **trovando il minimo della funzione *Q(&theta;)***:
![Q_funzione](immagini/Q_derivata.png)
  * esistono diverse tecniche numeriche per trovare il minimo della funzione

![linea](../immagini/linea.png)

### A4.1.4 Le proprietà del metodo

  * Se gli scarti *&epsilon;<sub>i</sub>* di *y<sub>i</sub>* rispetto a *g(x<sub>i</sub>,&theta;)*
    hanno **valore di aspettazione nullo e varianza finita e fissa**,
    cioè non dipendente da *y*, allora 
    * il metodo dei minimi quadrati è uno **stimatore non distorto** dei parametri &theta;
    * ed ha la **varianza minima** fra tutti gli stimatori non distorti lineari (in *y*), 
      indipendentemente dalla distribuzione di probabilità degli scarti
  * Se gli scarti *&epsilon;<sub>i</sub>* sono distribuiti secondo una distribuzione di probabilità Gaussiana,
    il minimo della funzione *Q<sup>2</sup>(&theta;)*
    è distribuito secondo una **distribuzione di probabilià &Chi;<sup>2</sup>**
    con *N-k* gradi di libertà,
    * dove *N* è il **numero di coppie** *(x<sub>i</sub>, y<sub>i</sub> )*
      e *k* il **numero di parametri stimati** con i minimi quadrati

![linea](../immagini/linea.png)

## A4.2 Il caso lineare

  * Nel caso in cui la funzione *g(x)* sia **lineare nei parametri &theta;**,
    le equazioni di minimizzazione possono essere risolte analiticamente
![g_lineare](immagini/g_lineare.png)
  * Un esempio di funzione lineare è **la retta 
    *g(x,&theta;) = &theta;<sub>1</sub> + &theta;<sub>2</sub> x***:
    * *h<sub>1</sub>(x) = 1*
    * *h<sub>2</sub>(x) = x*
  * Un altro esempio di funzione lineare è **una parabola 
    *g(x,&theta;) = &theta;<sub>1</sub> + &theta;<sub>2</sub> x + &theta;<sub>3</sub> x<sup>2</sup>***:
    * *h<sub>1</sub>(x) = 1*
    * *h<sub>2</sub>(x) = x*
    * *h<sub>3</sub>(x) = x<sup>2</sup>*

![linea](../immagini/linea.png)

### A4.2.1 La formulazione matriciale

  * Nel caso generale, 
    le *N* coppie di misure *(x<sub>i</sub>, y<sub>i</sub> )* 
    e *k* parametri *&theta;<sub>j</sub>*
    si possono **rappresentare in forma vettoriale**
  * Per comodità di scrittura,
    la determinazione del minimo della funzione *Q<sup>2</sup>(&theta;)*
    viene **svolta in forma matriciale**

![linea](../immagini/linea.png)

### A4.2.2 Le espressioni dei singoli elementi

  * Gli **ingredienti necessari**
    per la deteminazione dei parametri *&theta;<sub>j</sub>* 
    sono i seguenti:
![espressioni_mtr](immagini/espressioni_mtr.png)
  * Dove *V* è la matrice di covarianza delle misure *y<sub>i</sub>*,
    che è diagonale perché le misure sono indipendenti fra loro

![linea](../immagini/linea.png)

### A4.2.3 Il valore dei parametri e della loro incertezza

  * Il risultato delle operazioni di minimizzazione è il seguente:
![modello_lineare](immagini/modello_lineare_2.png)
  * *V<sup>-1</sup>* indica l'**inversa** della matrice di covarianza delle misure *y<sub>i</sub>*
  * *<sup>t</sup>H* indica la **trasposta** della matrice *H*
  * La notazione che indica il risultato dell'algoritmo dei minimi quadrati
    con un accento circonflesso sulla lettera &theta;
    sottolinea il fatto che si tratta del **risultato di una stima**

![linea](../immagini/linea.png)

## A4.3 Un esempio: il fit di una retta

  * L'implementazione di una regressione di un modello *g(x,&theta;) = &theta;<sub>1</sub> + &theta;<sub>2</sub> x*
    in ```C++``` è un utile esercizio di **programmazione e comprensione della statistica**
  * ... ricordando che esistono **librerie per l'analisi dati** (come ```ROOT```) con già implementati questi algoritmi
    * strumenti **più generici**: 
      implementano il metodo dei minimi quadrati sia per un modello lineare generico
      che per modelli non lineari
    * strumenti **più efficaci**:
      implementano algoritmi di minimizzazione tipicamente più potenti di quelli 
      che possiamo scrivere in una lezione  

![linea](../immagini/linea.png)

### A4.3.1 L'algebra delle matrici

  * Assumiamo di avere a disposizione una semplice libreria per lo **svolgimento di calcoli fra matrici**,
    che potete trovare qui: [algebra_2.h](programmi/algebra_2.h) e [algebra_2.cc](programmi/algebra_2.cc)
    (per scaricare o copiare il file sorgente conviene visualizzarlo in versione ```Raw```)
    * Rispetto a quella scritta per esercizio nella Lezione 7, 
      in questo caso non si utilizzano ```template```
      perché risuta più comodo **decidere a *runtime*** la dimensione delle matrici

![linea](../immagini/linea.png)

### A4.3.2 Gli strumenti a disposizione

  * Una classe **```vettore```**:
    ```cpp
    class vettore 
    {
      public:
        vettore (int N) ;
        vettore (const std::vector<double> & v) ;
        vettore (const vettore & orig) ;
        vettore & operator = (const vettore & orig) ;
        ~vettore () ;
    
        void    setCoord (int i, double val) ;
        double  norm () const ;
        int     N () const ;
        double  at (int i) const ;
        void    stampa () const ;
        double  operator[] (int i) const ;
        vettore operator+ (const vettore & v) const ;
        vettore operator- (const vettore & v) const ;
        vettore operator* (double val) const ;
        double  dot (const vettore & v) const ;
    
      private:
        double * m_elementi ;
        int m_N ;
    } ;
    ```      
  * Una classe **```matrice```**:
    ```cpp
    class matrice
    {
      public:
        matrice (int R) ;
        matrice (int R, int C) ;
        matrice (const matrice & orig) ;
        matrice & operator= (const matrice & orig) ;
        ~matrice () ;
    
        void    setCoord (int i, int j, double val) ;
        double  at (int i, int j) const ;
        void    stampa () const ;
        bool    quadrata () const ;
        int     rango () const ;
        int     N_righe () const ;
        int     N_colonne () const ;
        bool    simmetrica () const ;
        void    dimensioni () const ;
        matrice minore (int r, int c) const ; // complemento algebrico
        matrice inversa () const ;
        matrice trasposta () const ;
        double  determinante () const ;
        void    operator*= (double val) ;
    
      private:
        int index (int i, int j) const ;
        int m_R ;
        int m_C ;
        double * m_elementi ;
    } ;
    ```
  * **operazioni** fra i due tipi:
    ```cpp
    vettore operator* (const matrice & M, const vettore & v) ;
    matrice operator* (const matrice & M1, const matrice & M2) ;
    ```

![linea](../immagini/linea.png)

### A4.3.3 La generazione dei punti da interpolare

  * Per svolgere l'esercizio,
    bisogna innanzitutto avere a disposizione una **collezione di dati**
  * Con un generatore di numeri pseudo-casuali,
    si possono **generare valori degli scarti *&epsilon;<sub>i</sub>***
    per ogni punto *x<sub>i</sub>*,
    tali per cui:
    *y<sub>i</sub> = g(x<sub>i</sub> , &theta;) + &epsilon;<sub>i</sub>*
  * Assumendo una **distribuzione Gaussiana** per *&epsilon;<sub>i</sub>*,
    centrata in ```0``` e con &sigma; scelta a piacere:
    ```cpp
    double g (double x)
      {
         return 3.14 + 2 * x ;
      }
    // ....
    vector<double> asse_x ;
    vector<double> asse_y ;
    for (int i_point = 0 ; i_point < N_points ; ++i_point)
      {
        double epsilon = rand_TAC_gaus (sigma) ; 
        asse_x.push_back (i_point) ;
        asse_y.push_back (g (i_point) + epsilon) ;
      }
    ```
    * In questo caso, la funzione ```rand_TAC``` è stata modificata,
      con una implementazione **dedicata al problema**

![linea](../immagini/linea.png)

### A4.3.4 La preparazione di matrici e vettori

  * a partire dalle coppie di punti, si costruiscono:
  * la **matrice H** dei valori delle funzioni *h<sub>j</sub> (x)*
    per tutti i punti:
    ```cpp
    matrice H (Npoints, 2) ;
    for (int i_point = 0 ; i_point < N_points ; ++i_point)
      {
        H.setCoord (i_point, 0, 1) ;
        H.setCoord (i_point, 1, asse_x.at (i_point)) ;
      }
    ```
  * il **vettore y** (con un costruttore apposito che riceve in input uno ```std::vector```:
    ```cpp
    vettore y (asse_y) ;
    ```
  * la **matrice V** di covarianza delle misure *y<sub>i</sub>* :
    ```cpp
    matrice V (Npoints) ;
    for (int i_point = 0 ; i_point < N_points ; ++i_point) 
      V.setCoord (i_point, i_point, sigma * sigma) ;
    ```
    * assumendo **nota ```sigma```**

![linea](../immagini/linea.png)

### A4.3.5 La stima dei parametri &theta;

  * I calcoli per la determinazione del vettore &theta;
    e della sua varianza
    sono svolte in sequenza,
    **minimizzando il numero di singole operazioni**:
    ```cpp
    matrice V_inv = V.inversa () ;
    matrice theta_v = (H.trasposta () * V_inv * H).inversa () ;
    vettore theta = (theta_v * (H.trasposta () * V_inv)) * y ;
    ```
    * L'**inversione della matrice *V*** è fatta una sola volta
    * La **matrice di covarianza** di &theta;,
      che entra anche nel calcolo del suo valore centrale,
      viene calcolata una sola volta

![linea](../immagini/linea.png)

### A4.3.6 La stampa del risultato

  * Sapendo che i **termini diagonali della matrice di covarianza**
    corrispondono alle varianze dei vari &theta;<sub>i</sub> ,
    il risultato del fit è:
    ```cpp
    cout << "termine noto: " << theta.at (0) << " +- " << sqrt (theta_v.at (0, 0)) << endl ;
    cout << "pendenza:     " << theta.at (1) << " +- " << sqrt (theta_v.at (1, 1)) << endl ;
    ```

![linea](../immagini/linea.png)

## A4.4 Le proprietà statistiche degli stimatori

  * Per studiare le **proprietà statistiche delle stime** 
    ottenute con lo stimatore dei minimi quadrati,
    si utilizza la tecnica dei *toy montecarlo*
  * **Riprodurre molte volte** (```N_toys```) lo stesso fit 
    fatto su un determinato numero di punti (```N_point```), 
    ciascuno generato in modo pseudo-casuale
  * La procedura di fit viene quindi inserita in un ciclo aggiuntivo:
    ```cpp
    //loop over toys
    for (int i_toy = 0 ; i_toy < N_toys ; ++i_toy)
      {
        // generare il sample
        // trovare i parametri
        // riempire istogrammi e contatori
      } //loop over toys
    ```

![linea](../immagini/linea.png)

### A4.4.1 Gli elementi del ciclo

  * Il ciclo è composto di tre fasi:
    * La **generazione degli eventi**, come è stato fatto in precedenza
    * Il **calcolo del valore dei parametri**, con lo stesso programma utilizzato in precedenza
    * Il **riempimento di istogrammi e contatori**
      per la determinazione delle proprietà delle stime ottenute

![linea](../immagini/linea.png)

### A4.4.2 La distribuzione delle stime

  * Le proprietà dello stimatore dei minimi quadrati 
    si verificano osservando la **distribuzione di probabilità delle stime** ottenute
  * Queste distribuzioni si determinano attraverso **istogrammi**,
    che vanno creati prima del ciclo sui *toy experiment*:
    ```cpp
    // istogrammi per il disegno dei risultati del fit
    TH1F h_a ("h_a", "termine noto", 
              100, 3.14 * (1. - 1. * sigma), 3.14 * (1. + 1. * sigma) ) ;
    TH1F h_b ("h_b", "coefficiente angolare", 
              100, 2. * (1. - 1. * sigma), 2. * (1. + 1. * sigma) ) ;
    ```  
  * Gli istogrammi vanno poi **riempiti** nel ciclo:
    ```cpp
    //loop over toys
    for (int i_toy = 0 ; i_toy < N_toys ; ++i_toy)
      {
        // ...
        h_a.Fill (theta.at (0)) ;
        h_b.Fill (theta.at (1)) ;
      } //loop over toys
    ```

![linea](../immagini/linea.png)

### A4.4.3 Il risultato ottenuto

  * Infine, gli istogrammi vanno **visualizzati** dopo il termine del ciclo:
    ```cpp
    TCanvas c1 ("c1", "", 800, 800) ;
    c1.SetRightMargin (0.15) ;
    h_a.SetFillColor (kOrange + 1) ;
    h_a.SetLineColor (kGray + 1) ;
    h_a.Draw ("hist") ;
    c1.Print ("parametro_a.png", "png") ;
 
    h_b.Draw ("hist") ;
    h_b.SetFillColor (kOrange + 1) ;
    h_b.SetLineColor (kGray + 1) ;
    c1.Print ("parametro_b.png", "png") ;
    ```
  * Ottenendo le seguenti distribuzioni:
![distrib_parametri](immagini/distrib_parametri.png)

![linea](../immagini/linea.png)

### A4.4.4 La copertura dell'intervallo di confidenza

  * Oltre al valore centrale, 
    per ogni parametro lo stimatore dei minimi quadrati
    produce anche una **stima della sua varianza**
  * Per verificare che l'intervallo &theta;<sub>j</sub> &plusmn; &sigma;<sub>j</sub>
    abbia la **copertura attesa del 68%**,
    si contano i *toy experiment* per cui il valore vero è contenuto nell'intervallo:
    ```cpp
    int cont_a  = 0 ;
    int cont_b  = 0 ;

    //loop over toys
    for (int i_toy = 0 ; i_toy < N_toys ; ++i_toy)
      {
        //...
        if (fabs (theta.at (0) - 3.14) < sqrt (theta_v.at (0,0))) ++cont_a ;
        if (fabs (theta.at (1) - 2.  ) < sqrt (theta_v.at (1,1))) ++cont_b ;
      } //loop over toys
    ```

![linea](../immagini/linea.png)

### A4.4.5 Il risultato del test

  * Dividendo il numero di volte in cui il valore vero è contenuto nell'intervallo
    per il numero totale di *toy experiment*:
    ```cpp
    cout << "copertura parametro a: " << static_cast<double> (cont_a) / N_toys << endl ;
    cout << "copertura parametro b: " << static_cast<double> (cont_b) / N_toys << endl ;
    ```
  * Si ottiene il valore ricercato:
    ```
    copertura parametro a: 0.6829
    copertura parametro b: 0.68
    ```  

![linea](../immagini/linea.png)

### A4.4.6 La correlazione fra i parametri

  * Il metodo dei minimi quadrati produce la **matrice di covarianza**
    dei parametri stimati, che non è necessariamente diagonale
  * Questo significa che i **parametri stimati possono essere correlati fra loro**:
    se &theta;<sub>j</sub> è maggiore del suo valore vero, 
    può succedere che in media anche &theta;<sub>k</sub> sia maggiore del proprio valore vero,
    o viceversa
  * I **termini fuori diagonale** della matrice di covarianza dei parametri 
    indicano la correlazione fra i parametri

![linea](../immagini/linea.png)

### A4.4.7 La visualizzazione della correlazione

  * Anche in questo caso, 
    si sfruttano i *toy experiment* per visualizzare la correlazione,
    utilizzando un istogramma bi-dimensionale, 
    che mostri cioè il numero di *toy experiment* **in funzione di due variabili**
  * La classe di ```ROOT``` che si utilizza si chiama ```TH2F```:
    ```cpp
    TH2F h_ab ("h_ab", "parametri", 
              50, 3.14 * (1. - 1. * sigma), 3.14 * (1. + 1. * sigma),
              50, 2. * (1. - 1. * sigma), 2. * (1. + 1. * sigma) ) ;
    h_ab.GetXaxis ()->SetTitle ("termine noto") ;
    h_ab.GetYaxis ()->SetTitle ("coefficiente angolare") ;
    h_ab.SetStats (0) ;
    ```  
    * come nel caso di un ```TH1F```, 
      il costruttore prende in ingresso un **nome ed un titolo**
    * essendoci due variabili fisiche,
      il **numero di bin, minimo e massimo** vanno indicati per ciascuna variabile  

![linea](../immagini/linea.png)

### A4.4.8 Il riempimento dell'istogramma

  * All'interno del ciclo sui *toy experiment*,
    l'istogramma bi-dimensionale va **riempito con le due variabili**:
    ```cpp
    //loop over toys
    for (int i_toy = 0 ; i_toy < N_toys ; ++i_toy)
      {
        //...
        h_ab.Fill (theta.at (0), theta.at (1)) ;
      } //loop over toys
    ```
  * Quindi, al termine del ciclo,
    **disegnato** su un oggetto di tipo ```TCanvas```    
    ```cpp
    TCanvas c1 ("c1", "", 800, 800) ;
    c1.SetRightMargin (0.15) ;
    h_ab.Draw ("colz") ;
    c1.Print ("parametri_2D.png", "png") ;
    ```
    * Diverse **opzioni grafiche** producono varie visualizzazioni,
      come descritto nella [documentazione](https://root.cern/root/htmldoc/guides/users-guide/ROOTUsersGuide.html#drawing-histograms)
      di ```ROOT```
![correlaz_parametri](immagini/correlaz_parametri.png)

![linea](../immagini/linea.png)

## A4.5 La stima di una incertezza ignota

  * Se gli scarti *&epsilon;<sub>i</sub>* sono distribuiti secondo una distribuzione di probabilità Gaussiana,
    il minimo della funzione *Q<sup>2</sup>(&theta;)* al variare di &theta;, *Q<sup>2</sup><sub>min</sub>*,
    è distribuito secondo una **distribuzione di probabilià &Chi;<sup>2</sup>**
    con *N-k* gradi di libertà,
    * dove *N* è il **numero di coppie** *(x<sub>i</sub>, y<sub>i</sub> )*
      e *k* il **numero di parametri stimati** con i minimi quadrati
  * Il **valore di *Q<sup>2</sup>(&theta;)<sub>min</sub>*** è dato dal prodotto:
![qsq_formula](immagini/qsq_formula.png)
  * Che nel programma scritto finora **si calcola** a partire dalla informazioni già esistenti:
    ```cpp
    double Q2min = (y - H * theta).dot (V_inv * (y - H * theta)) ;
    ```

![linea](../immagini/linea.png)

### A4.5.1 La distribuzione attesa di *Q<sup>2</sup><sub>min</sub>*

  * Se la varianza dei singoli punti *y<sub>i</sub>* è nota,
    allora si può riempire un istogramma contenente i valori di *Q<sup>2</sup><sub>min</sub>*
    per i *toy experiment* generati
    e confrontarla con la distribuzione di probabilià &Chi;<sup>2</sup>
    dopo il termine del ciclo: 
![qsq_chisq](immagini/qsq_chisq.png)

![linea](../immagini/linea.png)

### A4.5.2 Il calcolo della varianza di *y<sub>i</sub>*

  * Se la varianza delle misure *y<sub>i</sub>* è ignota, invece,
    si può portare a termine la stima di &theta; e della sua matrice di covarianza
    assumendo che **la matrice di covarianza delle misure sia una identità**
  * Ricordando che la media di una distribuzione di &Chi;<sup>2</sup>
    è uguale al numero di gradi di libertà,
    se nel calcolo di *Q<sup>2</sup><sub>min</sub>*
    manca **il valore di &sigma;<sup>2</sup> 
    si può ricavare con la formula**:
![varianza_formula](immagini/varianza_formula.png)
  * Che, dati ```N_toys``` *toy experiment*,
    si traduce in:
    ```cpp
    TH1F h_scarti ("h_scarti", "scarti", 200, 0., 5 * N_points) ;

    //loop over toys
    for (int i_toy = 0 ; i_toy < N_toys ; ++i_toy)
      {
        // ...
        h_scarti.Fill (Q2min) ;
      } //loop over toys
    cout << "sigma = "
         << sqrt (h_scarti.GetMean () / (N_points - 2))
         << endl ;         
    ```
    * Questo calcolo della varianza vale anche **per ogni singolo *toy experiment***

![linea](../immagini/linea.png)

## A4.6 ESERCIZI

  * Gli esercizi relativi alla lezione si trovano [qui](ESERCIZI.md)
