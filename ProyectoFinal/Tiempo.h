#include "iostream"
using namespace std;
class Tiempo{
    public:
        Tiempo();
        Tiempo(int c_hora, int c_min);
        void setHora(int _hora);
        void setMin(int _min);
        int getHora();
        int getMinu();
        void mostrar();
    private:
        int hora, min;
};

Tiempo :: Tiempo(){  //Se crea el constructor
    hora = 0;
    min = 0;
}

Tiempo :: Reloj(int c_hora, int c_min){
    hora = c_hora;
    min = c_min;
    while(hora > 23 or hora < 0){
        cout << "Inserte una hora entre las 0 y 23 horas, por favor: ";
        cin >> hora;
    }
    while(min > 59 or min < 0){
        cout << "Inserte un minuto entre 0 y 59, por favor: ";
        cin >> min;
    }
}

void Tiempo :: setHora(int _hora){ //Se crea el  setter
    hora = _hora;
    while(hora > 23 or hora < 0){
        cout << "Inserte una hora entre las 0 y 23 horas, por favor: ";
        cin >> hora;
    }
}

void Tiempo::setMin(int _min){
    min= _min;
    while(min > 59 or min < 0){
        cout << "Inserte un minuto entre 0 y 59, por favor: ";
        cin >> min;
    }
}

int Tiempo :: getHora(){
    return hora;
}

int Tiempo :: getMinu(){ 
    return min;
}

void Tiempo :: mostrar(){
    if(hora < 10){
        cout << "0";
    }
    cout << hora << ":";

    if(min < 10){
        cout << "0";
    }
    cout << min << endl;
}