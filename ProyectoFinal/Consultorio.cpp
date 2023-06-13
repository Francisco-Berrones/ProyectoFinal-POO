//Programa Principal CPP

#include "iostream"
#include "fstream"
#include "string"
#include "chrono"
#include "conio.h"
#include "ctime"
using namespace std;

#include "Consultorio.h"

int main(){
    int n = 0, r=0, ren = 0, ren2 = 0, ren3 = 0; //contadores

    Paciente *pacientes[10]; Doctora *doctora;
    int numPaciente; string nombre, edad, sexo, calle, colonia, municipio, status; //numero de pacientes que se pueden registrar y datos de los pacientes
    fstream LeerPacientes; string valorNuevo; 
    fstream Acceso; string usuarios[11][11], usuario, contrasena;//datos de usuario y contraseña de bloc de notas
    int cveModificar, numDato;
    
    string username, password; //verifica contrasena dentro del programa
///////////////////////////////////////////////////////////////////////////////////////////

        //Inicializa el programa y pregunta el tipo de usuario
    int opcion;
    cout<<"Bienvenid@ al Consultorio de la Dra. Juguetes!\n";
    cout<<"Desea ingresar como la Doctora o como Paciente?: (1 = Doctora | 2 = Paciente) \n";
    cin>> opcion;

    while(opcion != 1 and opcion != 2){
         cout<<"Porfavor ingrese un numero entre el 1 y el 2 :\n"; cin>>opcion;
    }
    //While que opera mientras el usuario ingresa su usuario y/o contraseña

        if (opcion == 1)    
        {
            ifstream LeerAcceso;
            LeerAcceso.open("ControlDeAcceso.txt"); //read
            while(LeerAcceso >> usuario >> contrasena){        
                usuarios[ren][0] = usuario;
                usuarios[ren][1] = contrasena;
                cout<<"usuario "<< ren << " copiado \n";
                ren++;
            }   LeerAcceso.close();

            cout<<"Favor de ingresar la contrasenia: \n";
            cin>> password;

            if (password == usuarios[0][1])   //SI LA CONTRASENIA DE LA DOCTORA SON CORRECTOS
            {
            doctora = new Doctora();
            cout << "\x1B[2J\x1B[H";    //limpia pantalla
            cout<<" --- Consultorio Dra. Juguetes(Usuario: Doctora Juguetes) ---\n";
            cout<<"1) Registrar un Paciente \n2) Modificar datos del Paciente \n3) Agendar una cita\n";
            cout<<"4) Mostrar la cita \n5) Modificar una cita \n6)Ver Pacientes \n7) Ver el calendario semanal \n8) Salir \n";
            cout<<"";
            cout<<"Eliga una opcion:" ;

        //SWITCH DE LA DOCTORA -- USUARIO DE DOCTORA -- A LO QUE LA DOCTORA TIENE ACCESO
        int opcion2;
        cin>>opcion2;
        while(opcion2 < 1 or opcion2 > 8 ){
            cout<<"Por favor escoja una opcion entre el 1 y el 8: ";
            cin>>opcion2;
        }
         
        switch (opcion2){
        case 1: //NUEVO USUARIO / REGISTRARSE
        doctora->registrarPaciente();
        
            break;

        case 2: //MODIFICAR DATOS DEL USARIO
        LeerPacientes.open("DatosDePacientes.txt");


        cout << "Deme la clave del paciente del que desee modificar algun dato: (1-10): "<<endl;
        cin >> cveModificar;

        while(cveModificar < 0 or cveModificar > 10){
            cout << "Deme la clave del paciente del que desee modificar algun dato (1-10): "<<endl;
            cin >> cveModificar;
        }

        cout<<"1) Nombre\n2) Edad\n3) Sexo\n4) Calle\n5) Colonia\n6) Municipio \n7) Status \n Escriba el numero del dato que desee modificar: "<<endl; //Pido Nueva Cantidad para el almacen
        cin>>numDato;
        while(numDato <0 or numDato >8){
        cout<<"Por favor escoja un  numero del 1 al 8"<<endl; //Pido Nueva Cantidad para el almacen
        cin>>numDato;
        }

        cout<<"Escriba el nuevo dato: "<<endl;
        cin >> valorNuevo;

        for (ren2=0;ren2<ren3;ren2++){   
            if (cveModificar == numeroPaciente[ren2][0]){   //Buscar la clave que pidio modificar
                listaPacientes[ren2][numDato]=valorNuevo;   //Modificar el producto
                cout<<"Se encontro la clave del paciente\n";
            }
        } // cierro for para buscar la clave que pido modificar

            //Cambiamos los datos dentro del archivo txt
            CambiarPacientes.open("DatosDePacientes.txt"); //write
            //for (r=0;r<sizeof(listaPacientes);r++){ //for para cambiar datos del archivo de texto
            for (r=0;r<ren3;r++){
                CambiarPacientes<< numeroPaciente[r][0] <<" "<<listaPacientes[r][1]<<" "<<listaPacientes[r][2]<<" "<<listaPacientes[r][3]<<" "<<listaPacientes[r][4]<<" "<<listaPacientes[r][5]<<" "<<listaPacientes[r][6]<<" "<<listaPacientes[r][7]<<endl;
                cout<<"linea " << r << " escrita correctamente" << endl;
            }
            //}// fin del for de archivo
            CambiarPacientes.close();

            break;

        case 3: //AGENDAR UNA CITA
            
            
            break;

        case 4: //MOSTRAR LA CITA

            break;

        case 5: //MODIFICAR LA CITA

            break;

        case 6:
            exit(0);
        //default:
        //cout<<"Opcion invalida, porfavor oprima cualquier ";
                        }//CIERRA SWITCH
        }//CIERRA SESION DE LA DOCTORA
            
        } else if (opcion == 2){
            int opcion3;
            cout<<"Desea crear un nuevo usuario?: (1 = Si | 2 = Ya tengo un usuario registrado)\n";
            cin>>opcion3;
            if(opcion3 == 1){   //SE CREA NUEVO USUARIO
                cout << "Favor de ingresar el nombre de su usuario: \n";
                cin >> 
                cout << "Favor de ingresar la contrasenia para su usuario: \n";
                cin >> 
            } else if(opcion3 == 2){    //PIDE USUARIO Y CONTRASENIA DEL USUARIO EXISTENTE
            cout<<"Favor de ingresar el nombre de usuario: \n";
            cin>> 

            for (int i = 0; i < ren; i++)
            {
               if(username == usuarios[ren][0]){}
            }
            
            while(username != usuarios[ren][0]){
                cout<<"Nombre de usuario inexistente. Porfavor vuelva a escribir el nombre de usuario \n";
                cin>> usuarios[ren][1]
                ren++;
            }
            
            cout<<"Favor de ingresar la contrasenia: \n";
            cin>> password;

            for (int i = 0; i < ren; i++)
            {
               if(password == password[ren][0]){}
            }
            
            while(password != password[ren][0]){
                cout<<"Contrasenia de usuario inexistente. Porfavor vuelva a escribir la contrasenia \n";
                cin>>password[ren][1];
                ren++;
            }

            if (username == usuarios[ren][0] && password == usuarios[ren][1])   //SI LA CONTRASENIA DE LA DOCTORA SON CORRECTOS
            {
            }
        } 
            

    return 0;
}