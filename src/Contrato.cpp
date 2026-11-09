#include "Contrato.h"

int Contrato::contador=1;


Contrato::Contrato(const char dni[], Fecha f): idContrato(contador), fechaContrato(f) {
  Contrato::contador++;
  strcpy(this->dniContrato,dni);
}

Contrato::Contrato(const Contrato &c): idContrato(contador),fechaContrato(c.fechaContrato){
    Contrato::contador++;
    strcpy(this->dniContrato,c.dniContrato);
}

Contrato::~Contrato(){
    //dtor
}

void Contrato::ver() const {
  cout << this->dniContrato << " (" << this->idContrato << " - ";
  this->fechaContrato.ver();
  cout << ")";
}

ostream& operator<<(ostream &s, const Contrato &c) {
  s << c.getDniContrato() << " (" << c.getIdContrato() << " - " << c.getFechaContrato() << " )";
  return s;
}
