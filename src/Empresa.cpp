#include "Empresa.h"

Empresa::Empresa():nmaxcli(100){
    this->ncli=0;
    this->ncon=0;
    this->contratos=new Contrato *[10];
    this->nmaxcon=10;
}

Empresa::~Empresa(){
    for(int i=0; i<this->ncon;i++){
        delete this->contratos[i];
    }
    delete [] this->contratos;

    for(int i=0; i<this->ncli; i++) {
        delete this->clientes[i];
    }
}

int Empresa::altaCliente(Cliente *c){
    int pos=-1;
    if(this->ncli<nmaxcli){
        this->clientes[this->ncli] = c;
        pos=this->ncli;
        this->ncli++;
    }else{
        cout << "El cupo de cliente esta lleno";
        pos=-1;
    }
    return pos;
}

int Empresa::buscarCliente(const char dni[]) const{
    int i=0;
    while(i<ncli && strcmp(this->clientes[i]->getDni(),dni)!=0){
        i++;
    }
    if(i==100){
        return -1;
    }
    return i;
}

void Empresa::crearContrato() {
    char dni[10];
    int pos;
    cout << "Introduce DNI: ";
    cin >> dni;

    pos=this->buscarCliente(dni);
    if (pos==-1) {
        int dia, mes, anio;
        char nombre[30]; string apellidos;
        Cliente *c; //NO CREO NINGUN CLIENTE SINO SOLO UN PUNTERO A CLIENTE
        cout << "Introduce Nombre: "; gets(nombre);
        cout << "Introduce Apellido: "; getline(cin, apellidos);
        cout << "Introduce Fecha (dd mm aaaa): ";
        cin >> dia >> mes >> anio;
        c=new Cliente(dni, nombre, apellidos, Fecha(dia, mes, anio));
        pos=this->altaCliente(c);
    }
    if (pos!=-1){
        cout << "Tipo de Contrato a abrir (1-Tarifa Plana, 2-Movil):";
        int n;
        cin >> n;
        if(n==1){
            int dia, mes, anio, minutos;
            float preciom;
            char dniContrato[10], nacionalidad[50];

            cout << "Introduce Fecha (dd mm aaaa): ";
            cin >> dia >> mes >> anio;

            cout << "Introduce precio por minuto: ";
            cin >> preciom;

            cout << "Introduce los minutos hablados: ";
            cin >> minutos;

            cout << "Introduce la nacionalidad: ";
            cin >> nacionalidad;

            this->contratos[this->ncon] = new ContratoMovil(dni, Fecha(dia, mes, anio), preciom, minutos, nacionalidad);
            this->ncon++;
        }else if(n==2){
            int dia, mes, anio, minutos;
            char dniContrato[10];

            cout << "Introduce DNI: ";
            cin >> dniContrato;
            cout << "Introduce Fecha (dd mm aaaa): ";
            cin >> dia >> mes >> anio;
            cout << "Introduce los minutos hablados: ";
            cin >> minutos;

            this->contratos[this->ncon] = new ContratoTP(dniContrato, Fecha(dia, mes, anio), minutos);
            this->ncon++;
        }else{
            cout << "Tipo de contrato no valido." << endl;
        }
    }
}

void Empresa::cargarDatos() {
    Fecha f1(29,2,2001), f2(31,1,2002), f3(1,2,2002);
    this->clientes[0] = new Cliente("75547001M", "Peter Lee", "Bo Pio", f1);
    this->clientes[1] = new Cliente("45999000J", "Juan", "Perez", Fecha(29,2,2000));
    this->clientes[2] = new Cliente("37000017X", "Luis", "Bono Feria", f2);
    this->ncli=3;
    this->contratos[0] = new ContratoMovil("75547001M", f1, 0.12, 110, "DANES"); //habla 110m a 0.12€/m
    this->contratos[1] = new ContratoMovil("75547001M", f2, 0.09, 170, "DANES"); //habla 170m a 0.09€/m
    this->contratos[2] = new ContratoTP("37000017X", f3, 250); //habla 250m (300m a 10€, exceso 0.15€/m)
    this->contratos[3] = new ContratoTP("75547001M", f1, 312); //habla 312m (300m a 10€, exceso 0.15€/m)
    this->contratos[4] = new ContratoMovil("45999000J", f2, 0.10, 202, "ESPAÑOL"); //habla 202m a 0.10€/m
    this->contratos[5] = new ContratoMovil("75547001M", f2, 0.15, 80, "DANES"); //habla 80m a 0.15€/m
    this->contratos[6] = new ContratoTP("45999000J", f3, 400); //habla 400m (300m a 10€, exceso 0.15€/m)
    this->ncon=7;
}


bool Empresa::cancelarContrato(int idContrato){
    bool encontrado = false;
    int i=0;
    while(i<ncon && encontrado == false){
        if(idContrato==this->contratos[i]->getIdContrato()){
            for(int j=i+1;j<ncon;j++){
                contratos[j-1]=contratos[j];
                }
            ncon--;
            encontrado == true;
        }else{
            i++;
        }
    }

    if(encontrado==true){
        return true;
    }else{
        cout << "El contrato no se ha encontrado.";
        return false;
    }
}

void Empresa::ver() const {
    for(int i=0;i<this->ncon;i++){
        this->contratos[i]->ver();
        cout << endl;
    }
}

int Empresa::nContratosTP() const{
    int contador =0;

    for(int i=0;i<this->ncon;i++){
        ContratoTP *ctp = dynamic_cast<ContratoTP*>(this->contratos[i]);
        if(ctp !=nullptr){
            contador++;
        }
    }
    return contador;
}

bool Empresa::bajaCliente(long int dni){


}

