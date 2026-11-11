#ifndef CONTRATO_H
#define CONTRATO_H
#include <iostream>
#include <cstring>
#include "Fecha.h"


class Contrato{

    private:
        const int idContrato;
        char dniContrato[10];
        Fecha fechaContrato;
        static int contador;

    public:
        Contrato(const char dni[], Fecha f);
        Contrato(const Contrato &c);
        virtual ~Contrato();
        //Getter
        int getIdContrato() const {return this->idContrato;}
        Fecha getFechaContrato() const { return this->fechaContrato;}
        const char* getDniContrato() const {return this->dniContrato;};

        //setter
        void setFechaContrato(Fecha f){this->fechaContrato = f;};
        void setDniContrato(const char dni[]){strcpy(this->dniContrato,dni);};

        virtual void ver() const;

        //Crear metodo virtual puro
        virtual float factura() const = 0;
};

    ostream& operator<<(ostream &s, const Contrato &c);

#endif // CONTRATO_H
