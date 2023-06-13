#include <iostream>

#include <conio.h>

#include <fstream> 



using namespace std;



string nombre; 

string contra; 

string linea; 

string arreglo[2]; 

size_t pos = 0; 

int contador=0; 

string dato; 

int fin = 0; 



int main()

{



cout << "Ingrese su usuario" << endl;

cin >> nombre;

cout << "Ingrese su contraseña" << endl;

cin >> contra;



ifstream archivo("datos.txt"); 



while(getline(archivo,linea)&&fin==0){ 

while ((pos = linea.find(",")) != std::string::npos){ 

    dato = linea.substr(0, pos); 

    arreglo[contador]=dato; 

    linea.erase(0, pos + 1); 

    contador++; 

}

        if (arreglo[0].find(nombre, 0) != string::npos){

            fin=1;

        }

contador=0;

}



/* Revisamos a continuacion si el nombre de usuario y la contraseña son iguales a los ingresados por el usuario de ser asi le dejamos pasar,

le damos un mensaje de bienvenida y realizamos cualquier otra accion que necesitemos*/



if (nombre==arreglo[0]&&contra==arreglo[1]){

    cout << "Bienvenido a Codigazo" << endl;

}

else{

    cout << "Los datos ingresados son incorrectos" << endl;

}



_getch();

}