#include "ContratoMovil.h"

ContratoMovil::ContratoMovil(const char dni[], Fecha f, float p, int m, const char *nac): Contrato(dni, f) {
    this->precioMinuto=p;
    this->minutosHablados=m;
    this->nacionalidad=new char [strlen(nac)+1];
    strcpy(this->nacionalidad, nac);
}

ContratoMovil::ContratoMovil(const ContratoMovil &c): Contrato(c.getDniContrato(), c.getFechaContrato()) {
    this->precioMinuto = c.precioMinuto;
    this->minutosHablados = c.minutosHablados;
    this->nacionalidad = new char[strlen(c.nacionalidad) + 1];
    strcpy(this->nacionalidad, c.nacionalidad);
}

ContratoMovil::~ContratoMovil(){
    delete [] this->nacionalidad;
}


void ContratoMovil::setNacionalidad(const char* nac){
    char *nueva = new char[strlen(nac)+1];
    strcpy(nueva,nac);
    delete [] this->nacionalidad;
    this->nacionalidad = nueva;
}

void ContratoMovil::ver() const {
    Contrato::ver();
    cout << " " << this->minutosHablados << "m, " << this->nacionalidad<< " " << this->precioMinuto;
}

ostream& operator<<(ostream &s, const ContratoMovil &c) {
    s << (const Contrato &)c;
    s << " " << c.getMinutosHablados() << "m, " << c.getNacionalidad() << " " << c.getPrecioMinuto() << " - " << c.factura() << "€";
    return s;
}
