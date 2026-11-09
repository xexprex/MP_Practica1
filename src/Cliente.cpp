#include <cstdlib>
#include <cstring> //strlen, strcpy
#include <iomanip> //std::setprecision
#include <sstream> //stringstream
#include "Cliente.h"

Cliente::Cliente(char d[], char *nom, string ape, Fecha f):fechaAlta(f){ //Invocamos a constructor de copia
  strcpy(this->dni, d);
  this->nombre=new char[strlen(nom)+1];
  strcpy(this->nombre, nom);
  apellidos=ape;
}

Cliente::~Cliente() {
  delete [] this->nombre; //si en el constructor uso new [] en el destructor uso delete []
}

void Cliente::setNombre(char* nom){
    delete[] this->nombre;
    this->nombre=new char[strlen(nom)+1];
    strcpy(this->nombre,nom);
}

Cliente& Cliente::operator=(const Cliente& c) {
  if (this != &c) { //si el cliente no es el mismo
        strcpy(this->dni,c.dni);
        delete [] this->nombre;
        this->nombre=new char[strlen(c.nombre)+1];
        strcpy(this->nombre, c.nombre);
        apellidos=c.apellidos;
        this->fechaAlta=c.fechaAlta;
  }
  return *this;
}

bool Cliente::operator==(Cliente c) const {
    if (strcmp(this->dni,c.dni)!=0) return false;
    if (strcmp(this->nombre, c.nombre)!=0) return false;
    if (this->apellidos!=c.apellidos) return false;
    if (this->fechaAlta.getDia()!=c.fechaAlta.getDia() ||
        this->fechaAlta.getMes()!=c.fechaAlta.getMes() ||
        this->fechaAlta.getAnio()!=c.fechaAlta.getAnio()) return false;
  return true;
}

ostream& operator<<(ostream &s, const Cliente &c) {
    s << c.getDni() << " - "
      << c.getApellidos() << ", " << c.getNombre()
      << " (Fecha de alta: " << c.getFecha() << ")";

    return s;
}
