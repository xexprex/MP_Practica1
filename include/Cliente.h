#ifndef CLIENTE_H
#define CLIENTE_H
#include <Fecha.h>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Cliente{

private:
    char dni[10];
    char *nombre;       //Cadena dinamica
    string apellidos;
    Fecha fechaAlta;

public:
    Cliente(char dni[], char *nom,string ape, Fecha f);
    virtual ~Cliente();
    Cliente& operator=(const Cliente& c);   //Constructor de copia

    const char* getDni() const { return this->dni;}
    const char* getNombre() const { return nombre;}
    string getApellidos() const {return apellidos;}
    Fecha getFecha() const { return fechaAlta;}

    //void setNombre(char *nom){strcpy(this->nombre,nom);}
    void setNombre(char *nom);    //Solucion problema
    void setApellidos(string ape) { this->apellidos=ape;}
    void setFecha(Fecha f){this->fechaAlta=f;};

    bool operator==(Cliente c) const;

};

ostream& operator<<(ostream &s, const Cliente &c); //funcion no amiga de la clase

#endif // CLIENTE_H
