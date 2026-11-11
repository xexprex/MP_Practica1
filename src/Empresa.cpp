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
    if(this->ncli<nmaxcli){
        this->clientes[this->ncli] = c;
        int pos=this->ncli;
        this->ncli++;
        return pos;
    }else{
        cout << "Lo siento, el cupo de clientes esta lleno" << endl;
        return -1;
    }
}

int Empresa::buscarCliente(const char* dni) const {
    for (int i = 0; i < this->ncli; i++) {
        if (strcmp(this->clientes[i]->getDni(), dni) == 0) {
            return i; // Devuelve la posición si existe
        }
    }
    return -1; // Devuelve -1 si NO existe
}

void Empresa::crearContrato() {
    char dni[10];
    cout << "Introduce DNI: ";
    cin >> dni;

    int pos=this->buscarCliente(dni);
    if (pos==-1) {
        int dia, mes, anio;
        char nombre[30];
        string apellidos;
        cin.ignore(1000, '\n');
        cout << "Introduce Nombre: "; cin.getline(nombre, 30);
        cout << "Introduce Apellido: "; getline(cin, apellidos);
        cout << "dia: "; cin >> dia; cout << "mes: "; cin >> mes; cout << "anio: "; cin >> anio;
        Cliente *c = new Cliente(dni, nombre, apellidos, Fecha(dia, mes, anio));
        pos=this->altaCliente(c);
        if (pos == -1) delete c; //Por sii no cabe para no dejarlo perdido.
    }
    if (pos != -1) {                          // 2ª MITAD: el cliente existe
        int tipo, d, m, a, minutos;
        cout << "Tipo de Contrato a abrir (1-Tarifa Plana, 2-Movil): ";
        cin >> tipo;
        cout << "Fecha del contrato\n";
        cout << "dia: "; cin >> d; cout << "mes: "; cin >> m; cout << "anio: "; cin >> a;
        cout << "minutos hablados: "; cin >> minutos;
        if (tipo == 1){
            this->anadirContrato(new ContratoTP(dni, Fecha(d, m, a), minutos));
        }else {
            float precio; char nac[20];
            cout << "Precio minuto: "; cin >> precio;
            cout << "Nacionalidad: "; cin >> nac;
            this->anadirContrato(new ContratoMovil(dni, Fecha(d, m, a), precio, minutos, nac));
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
            delete this->contratos[i];
            for(int j=i+1;j<ncon;j++){
                contratos[j-1]=contratos[j];
                }
            ncon--;
            encontrado = true;
        }else{
            i++;
        }
    }

    if(encontrado==true){
        return true;
    }else{
        return false;
    }
}

void Empresa::ver() const {

    cout << "La Empresa tiene " << this->ncli << " clientes y " << this->ncon << " contratos\n";
    cout << "Clientes:\n";
    for (int i = 0; i < this->ncli; i++)
        cout << *this->clientes[i] << "\n";

    cout << "Contratos:" << endl;
    for (int i = 0; i < this->ncon; i++) {
        this->contratos[i]->ver();
        cout << endl;
    }
}

int Empresa::nContratosTP() const {
    int contador = 0;
    for (int i = 0; i < this->ncon; i++) {
        if (typeid(*(this->contratos[i])) == typeid(ContratoTP)) {
            contador++;
        }
    }
    return contador;
}

bool Empresa::bajaCliente(const char* dni){
    int pos = this->buscarCliente(dni);
    if(pos == -1){
        return false;
    }

    //Tapamos el hueco
    delete this->clientes[pos];
    for(int j = pos+1;j< this->ncli;j++){
        this->clientes[j-1] = this->clientes[j];
    }
    this->ncli--;

    //Eliminamos sus contraros
    for(int i=this->ncon-1;i>=0;i--){
        if(strcmp(this->contratos[i]->getDniContrato(),dni)==0){
            delete this->contratos[i];
            for(int j = i+1;j<this->ncon;j++){
                this->contratos[j-1] = this->contratos[j];
            }
            this->ncon--;
        }
    }
    return true;
}


int Empresa::descuento (float porcentaje) const{
    int modificados=0;
    for(int i=0;i<this->ncon;i++){
        ContratoMovil* cm = dynamic_cast<ContratoMovil*>(this->contratos[i]);
        if(cm !=nullptr){
            float precioActual = cm->getPrecioMinuto();
            cm->setPrecioMinuto(precioActual * (1 - porcentaje / 100));
            modificados++;
        }
    }
    return modificados;
}
void Empresa::anadirContrato(Contrato *c) {
    if (this->ncon == this->nmaxcon) {                  // ¿está lleno?
        Contrato **aux = this->contratos;                  // 1. no perder el viejo
        this->nmaxcon = this->nmaxcon * 2;                 //    10 -> 20 -> 40...
        this->contratos = new Contrato *[this->nmaxcon];   // 2. uno nuevo del doble
        for (int i = 0; i < this->ncon; i++)
            this->contratos[i] = aux[i];                     // 3. copiar las direcciones
        delete [] aux;                                     // 4. liberar solo el array viejo
    }
    this->contratos[this->ncon] = c;                     // poner el nuevo al final
    this->ncon++;
}
