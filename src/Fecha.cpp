#include "Fecha.h"

Fecha::Fecha(const int &dia, const int &m, const int &anio){
    this->setFecha(dia, m, anio);
}


void Fecha::setFecha(const int &dia, const int &mes, const int &a) {
    int dmax, diaMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        this->anio=a; //VIP debo asignar año para que al llamar a bisiesto() tenga el año bien
    if (this->bisiesto())
        diaMes[2]=29;

    if (mes<1)  //si el mes es incorrecto
      this->mes=1;
    else if (mes>12) //si el mes es incorrecto
      this->mes=12;
    else
      this->mes=mes;
    dmax=diaMes[this->mes]; //una vez fijado el mes veo cuantos dias tiene ese mes como maximo

    if (dia>dmax) //si dia es superior al numero de dias de dicho mes
      this->dia=dmax;
    else if (dia<1) //si dia es inferior a 1
      this->dia=1;
    else
      this->dia=dia;

}

bool Fecha::bisiesto() const {
    return (this->anio%4==0 && this->anio %100!=0 || this->anio%400==0);
}

void Fecha::ver() const {
    if (this->dia < 10)
        cout << "0";
    cout << this->dia << "/";
    if (this->mes < 10)
        cout << "0";
    cout << this->mes << "/" << this->anio;
}

Fecha Fecha::operator++() {   //++f
    int dmax, diaMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (this->bisiesto()) //si el año es bisiesto febrero tiene 29 dias
      diaMes[2]=29;
    dmax=diaMes[this->mes];
    this->dia++;
    if (this->dia>dmax) { //si al incrementar dia superamos el numero de dias de dicho mes
        this->dia=1;      //pasamos a 1
        this->mes++;      //del mes siguiente
        if (this->mes>12) { //si al incrementar mes pasamos de 12 meses
            this->mes=1;    //pasamos al mes 1
            this->anio++;   //del año siguiente
        }
    }
    return *this; //devolvemos el objeto fecha ya incrementado
}

Fecha Fecha::operator++(int i) {
    Fecha faux(*this);
    ++(*this);
    return faux;
}


Fecha Fecha::operator+(const int &i) const {
    Fecha faux(*this);
    for (int j = 0; j < i; j++) {
        ++faux;
    }
    return faux;
}

Fecha operator+(const int &n, const Fecha &f) {
    return f + n;
}

ostream& operator<<(ostream &s, const Fecha &f) {
  const char *meses[] = {"", "ene", "feb", "mar", "abr", "may", "jun", "jul", "ago", "sep", "oct", "nov", "dic"};
  if (f.dia < 10)
    s << "0";
  s << f.dia << " " << meses[f.mes] << " " << f.anio;
  return s;
}
