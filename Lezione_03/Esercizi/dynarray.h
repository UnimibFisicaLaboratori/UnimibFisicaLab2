#ifndef dynarray_h
#define dynarray_h

class dynarray
{
  public :
    dynarray (int N = 100) : // valore di default 100, nel caso nessun valore venga passato
      m_size (N),
      m_dim (0)
      {
        m_ptr = new double [m_size] ;
      }

    ~dynarray ()
      {
        delete [] m_ptr ;
      }

    int aggiungi (double valore)
      {
        m_ptr[m_dim] = valore ;
        ++m_dim ;
        if (m_dim > m_size)
          {
            double * tempo = m_ptr ;
            m_ptr = new double [m_size * 2] ;
            for (int i = 0 ; i < m_size ; ++i) m_ptr[i] = tempo[i] ;
            m_size *= 2 ;
            delete [] tempo ;
          }
        return m_dim ;
      }
     
    int dim () const 
      { 
        return m_dim ; 
      }

    double leggi (int indice) const
      {
        if (indice >=0 and indice < m_dim) return m_ptr[indice] ;
        return 0. ;
      }

  private :
    double * m_ptr ; // puntatore al primo elemento dell'array
    int m_size ;     // dimensione dello spazion disponibile nell'array
    int m_dim ;      // numero di elementi effettivamente salvati nell'array  

} ;


#endif