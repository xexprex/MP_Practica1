#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Fecha.h"
#include "Cliente.h"
#include "Contrato.h"
#include "ContratoTP.h"
#include "ContratoMovil.h"
#include "Empresa.h"

using namespace std;

int main(int argc, char *argv[]){
    bool ok;
    Empresa Yoigo;

    cout << setprecision(2) << fixed; //a partir de aqui float se muestra con 2 decimales
    cout << endl << "APLICACION DE GESTION TELEFONICA\n" << endl;
    Yoigo.cargarDatos(); //crea 3 clientes y 7 contratos. metodo creado para no
    Yoigo.ver(); //tener que meter datos cada vez que pruebo el programa
    cout <<"Yoigo tiene " << Yoigo.nContratosTP() << " Contratos de Tarifa Plana\n\n";

    Yoigo.crearContrato(); //ContratoMovil a 37000017X el 01/01/2017 con 100m a 0.25
    Yoigo.crearContrato(); //ContratoTP a 22330014T (pepe Luis Gomez Pio) el 2/2/2017 con 305m

    ok=Yoigo.cancelarContrato(28); //este Contrato no existe v
    if (ok)
        cout << "Contrato 28 cancelado\n"; else cout << "El Contrato 28 no existe\n";

    ok=Yoigo.cancelarContrato(4); //este Contrato si existe
    if (ok)
        cout << "El Contrato 4 ha sido cancelado\n";
    else
        cout << "El Contrato 4 no existe\n";

    ok=Yoigo.bajaCliente("75547001M"); //debe eliminar el cliente y sus 3 Contratos

    if (ok)
        cout << "El cliente 75547001M y sus Contratos han sido cancelados\n";
    else
        cout << "El cliente 75547001M no existe\n";

    Yoigo.ver();

    Yoigo.descuento(20);
    cout << "\nTras rebajar un 20% la tarifa de los ContratosMovil..." <<endl;
    Yoigo.ver();
    cout <<"Yoigo tiene " << Yoigo. nContratosTP () << " Contratos de Tarifa Plana\n";

    system("PAUSE");
    return 0;
}
