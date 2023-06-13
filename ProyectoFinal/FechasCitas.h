#ifndef _Fecha_H_
#define _Fecha_H_
#include <iostream>
using namespace std;
class FechasCitas{
     public:
        Fecha();
        Fecha(string);
        Fecha(int d, int m, int a);
        void setDia(int d);
        void setMes(int m);
        void setAno(int a);
        int getDia();
        int getMes();
        int getAno();
        void muestra();
        void setFechaL(string);
        string getFechaL();
    private:
        int  dia, mes, anio;
        string fecha;
};

Fecha :: Fecha(){
    dia = 0;
    mes = 0;
    anio = 0;
}

Fecha :: Fecha(string fec){
    dia = 0;
    mes = 0;
    anio = 0;
    fecha = fec;
}

Fecha :: Fecha(int m, int d, int a){
    mes = m;
    dia = d;
    anio = a;

}

void Fecha :: setMes(int m){
    mes = m;
    while(mes < 0 or mes > 12){
        cout << "Mes invalido, por favor ingrese uno entre 0 y 12:";
        cin >> mes;
    }
}

void Fecha :: setDia(int d){
    dia = d;
    while(dia < 0 or dia > 31){
        cout << "Dia invalido, por favor ingrese uno entre 1 y 31: ";
        cin >> dia;
    }
}


void Fecha::setAno(int a){
    ano = a;
    while(ano > 2024 or ano < 2020){
        cout << "Año invalido, ingrese el año actual: ";
        cin >> ano;
    }
}


int Fecha :: getMes(){
    return mes;
}

int Fecha :: getDia(){
    return dia;
}

int Fecha :: getAno(){
    return ano;
}

void Fecha :: muestra(){
    if(dia == 0 and mes == 0 and ano == 0){
        cout << fecha << endl;
        return;
    }

    cout << ano;

    if (mes > 0 and mes < 10){
        cout << "0" << mes;
    }
    else{
        cout << mes;
    }

    if (dia > 0 and dia < 10){
        cout << "0" << dia << endl;
    }
    else{
        cout << dia << endl;

    }    
}

void Fecha :: setFechaL(string fec){
    fecha = fec;
    dia = mes = ano = 0;
}

string Fecha :: getFechaL(){
    return fecha;
}

#endif