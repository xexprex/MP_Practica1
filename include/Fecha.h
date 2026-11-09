#ifndef FECHA_H
#define FECHA_H
#include <iostream>

using namespace std;

class Fecha{

    private:
        int dia;
        int mes;
        int anio;

    public:
        Fecha(const int &d,const int &m,const int &a) ;

        int getDia()const {return dia;};
        int getMes()const {return mes;};
        int getAnio()const {return anio;};

        void setFecha(const int &d,const int &m,const int &a);
        void ver() const;
        bool bisiesto() const;

        //Sobrecarga de operadores
        Fecha operator++();      //++f
        Fecha operator++(int i); //f++
        Fecha operator+(const int &i) const;  //f+5

        friend Fecha operator+(const int &n,const Fecha &f); //const por seguridad y & por velocidad
        friend ostream& operator<<(ostream &s, const Fecha &f);
};

#endif // FECHA_H
