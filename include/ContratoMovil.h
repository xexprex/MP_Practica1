#ifndef CONTRATOMOVIL_H
#define CONTRATOMOVIL_H
#include "Contrato.h"


class ContratoMovil : public Contrato{
    private:
        float precioMinuto;
        int minutosHablados;
        char *nacionalidad;
    public:
        ContratoMovil(const char dni[],Fecha f,float p,int m,const char *nac);
        ContratoMovil(const ContratoMovil &c);
        virtual ~ContratoMovil();

        //getter
        float getPrecioMinuto() const {return this->precioMinuto;}
        int getMinutosHablados() const {return this->minutosHablados;}
        const char* getNacionalidad() const { return this->nacionalidad;}
        //setter
        void setNacionalidad(const char* nac);
        void setPrecioMinuto(float p){this->precioMinuto=p;};
        void setMinutosHablados(int m){this->minutosHablados=m;};

        float factura() const { return this->precioMinuto * this->minutosHablados;};
        virtual void ver() const;

        virtual void nada() const { ; } //No hace nada

};

ostream& operator<<(ostream &s, const ContratoMovil &c);

#endif // CONTRATOMOVIL_H
