#ifndef CONTRATOTP_H
#define CONTRATOTP_H
#include "Contrato.h"

class ContratoTP : public Contrato{
    private:
        int minutosHablados;
        static const float precioExcesoMinutos;
        static int minutosTP;
        static float precioTP;

    public:
        ContratoTP(const char dni[],Fecha f, int m);
        virtual ~ContratoTP();

        //getter
        static int getLimiteMinutos(){return ContratoTP::minutosTP;}
        static float getPrecio(){return ContratoTP::precioTP;}
        int getMinutosHablados() const {return this->minutosHablados;}
        //setter
        void setMinutosHablados(int m) {this->minutosHablados=m;}
        static void setTarifaPlana(int m,float p);

        float factura() const;
        virtual void ver() const;
};

ostream& operator<<(ostream &s, const ContratoTP &c);
#endif // CONTRATOTP_H
