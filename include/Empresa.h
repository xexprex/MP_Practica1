#ifndef EMPRESA_H
#define EMPRESA_H
#include "Fecha.h"
#include "Cliente.h"
#include "Contrato.h"
#include "ContratoTP.h"
#include "ContratoMovil.h"

using namespace std;

class Empresa{
    private:
        Cliente *clientes[100];
        int ncli;
        const int nmaxcli;
        Contrato **contratos;
        int ncon;
        int nmaxcon;

    protected:
    int buscarCliente(const char* dni) const;
    int altaCliente(Cliente *c);
    void anadirContrato(Contrato *c);

    public:
        Empresa();
        virtual ~Empresa();
        void crearContrato();
        void cargarDatos();

        bool cancelarContrato(int idContrato);
        bool bajaCliente(const char* dni);
        int descuento (float porcentaje) const;
        int nContratosTP() const;
        void ver() const;
};

#endif // EMPRESA_H
