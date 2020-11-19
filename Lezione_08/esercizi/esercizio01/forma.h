#ifndef forma_h
#define forma_h

#include <string>

class forma {
    public:
        // Costruttore di default
        forma();
        // Costruttore con parametro
        forma(double area = -1);
        // Distruttore
        ~forma();

        // Restituisce l'area
        double GetArea();

        // Restituisce il nome
        std::string GetNome();

        // Imposta il nome
        void SetNome( std::string nome );

    protected:
        /*
         *  I membri protected sono direttamente accessibili alle classi
         *  che ereditano da questa classe
         */

        double m_area;

    private:
        /*
         *  I membri private sono accessibili solo ad oggetti di tipo forma,
         *  non alle classi che ereditano da forma
         */
        std::string m_nome;
};

#endif
