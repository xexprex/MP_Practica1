#include "ContratoTP.h"

int ContratoTP::minutosTP=300;
float ContratoTP::precioTP=10;
const float ContratoTP::precioExcesoMinutos=0.15;

ContratoTP::ContratoTP(const char dni[],Fecha f, int m): Contrato(dni,f){
    this->minutosHablados = m;
}

void ContratoTP::setTarifaPlana(int m, float p) {
  ContratoTP::minutosTP=m;
  ContratoTP::precioTP=p;
}

ContratoTP::~ContratoTP(){
    //dtor
}

float ContratoTP::factura() const {
    float total = ContratoTP::precioTP;
    if(this->minutosHablados > ContratoTP::minutosTP){
        total +=(this->minutosHablados - ContratoTP::minutosTP) * ContratoTP::precioExcesoMinutos;
    }
    return total;
}

void ContratoTP::ver() const{
    Contrato::ver();
    cout << " " << this->minutosHablados << "m " << ContratoTP::minutosTP << "(" << ContratoTP::precioTP << ") - " << factura() << " EUR";
}

ostream& operator<<(ostream &s, const ContratoTP &c) {
    s << (const Contrato &)c;
    s << " " << c.getMinutosHablados() << "m, " << ContratoTP::getLimiteMinutos() << "(" << ContratoTP::getPrecio() << ") - " << c.factura() << " EUR";
    return s;
}
