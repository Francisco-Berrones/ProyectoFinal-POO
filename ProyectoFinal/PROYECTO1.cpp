#include <iostream> 
#include <stdlib.h>
#include <cstdlib>
#include <fstream>


using namespace std;

//Este es un programa enfocado en un consultorio de pediatria que consta de dos procesos 
//El primero se enfoca a registrar pacientes
//El segundo permite consultar expedientes medicos guardados en el dispositivo de la doctora
//y tambien tendrá la opción de modificarlos

//Declaración de procesos en funciones
void Registrar_Paciente();
void array_Pacientes();
void Ver_Registros();
void Buscar_Registro();
void Modificar_Registro();
 
int main()
{

    //Declaramos las variables del menú

    int opcion, salida;
    ifstream Leer;

    //Declaramos las letras que llevan acento para que se puedan visualizar bien
    char letra_e = 130;
    char letra_u = 163;
    char letra_o = 162;
    char letra_i = 161;
    char signo_interrogacion = 168;

    //Declaramos los arreglos a utilizar
        string nombre[500];
        int peso[500], existencia_pesos[500], contador=0, total_peso=0;


    do{
        
        system("cls");
        //A continuación se muestra el menú de opciones
        cout << "\n\n\t\t\t Consultorio MedicaPrime" <<endl;
        cout << "\t\t\t-------------------------" <<endl;
        cout << "\n\t1. Registrar un nuevo paciente" <<endl;
        cout << "\t2. Consultar los expedientes m" <<letra_e <<"dicos" <<endl;
        cout << "\t3. Buscar Registro m"<<letra_e <<"dico" <<endl;
        cout << "\t4. Modificar Registro m"<<letra_e <<"dico" <<endl;
        cout << "\t5. Consultar promedio de pesos de los pacientes" <<endl;
        cout << "\t0. Salir del Men" <<letra_u <<endl;
    
        cout << "\n\tIngresa la opci" <<letra_o <<"n que desees realizar:  ";
        cin >> opcion;

        //Creamos una validación para el menú para que de esta manera, si se llega a ingresar
        //un numero diferente al del menú, el sistema pida un numero correcto
        if(opcion > 3 && opcion < 0)
        {
            cout<<"\n\t\t\tOpcion invalida, a ingresado un numero incorrecto" <<endl;
            cout<<"\n\t\t\tIngrese una Opcion Correcta: ";
            cin>>opcion;
        }

        switch (opcion) 
        {
            case 1:
            {
            //Aqui se realizará el registro de pacientes creando un nuevo documento y se podrá visualizar posteriormente lo que se agregó
            cout << "\n\tBienvenido al registro de pacientes" <<endl;
            cout << "\tIngresa los siguientes datos\n";
            Registrar_Paciente();
            cout << "El paciente ha sido registrado\n\n";

                cout<< "\n\t" << signo_interrogacion <<"Deseas realizar otro registro?\n";
                cout <<"\n\t1. S" <<letra_i <<"\n";
                cout << "\t2. No\n\t";
                cin >> salida;

                    
                if (salida == 1)
                { //do while
                    do
                    {
                    cout << "\n\tBienvenido al registro de pacientes" <<endl;
                    cout << "\tIngresa los siguientes datos\n";
                    Registrar_Paciente();
                    cout << "El paciente ha sido registrado\n\n";
                        cout<< "\n\t" << signo_interrogacion <<"Deseas realizar otro registro?\n";
                        cout <<"\n\t1. S" <<letra_i <<"\n";
                        cout << "\t2. No\n\t";
                        cin >> salida;
                    }while (salida == 1); 
                }else
                {
                    system("cls");
                        //A continuación se muestra el menú de opciones
                        cout << "\n\n\t\t\t Consultorio MedicaPrime" <<endl;
                        cout << "\t\t\t-------------------------" <<endl;
                        cout << "\n\t1. Registrar un nuevo paciente" <<endl;
                        cout << "\t2. Consultar los expedientes m" <<letra_e <<"dicos" <<endl;
                        cout << "\t3. Buscar Registro m"<<letra_e <<"dico" <<endl;
                        cout << "\t4. Modificar Registro m"<<letra_e <<"dico" <<endl;
                        cout << "\t5. Consultar promedio de pesos de los pacientes" <<endl;
                        cout << "\t0. Salir del Men" <<letra_u <<endl;
                    
                        cout << "\n\tIngresa la opci" <<letra_o <<"n que desees realizar:  ";
                        cin >> opcion;

                }
            }
            break;

            case 2:
            {
            //Consulta y/o modificación de un expediente médico
            //Lectura de expedientes y registro de pacientes
            cout << "Aquí se van a poder visualizar los registros";
            Ver_Registros(); 
            }

            break;
            case 3:
            {
                Buscar_Registro();
            }
            break;
            case 4:
            { 
        
               Modificar_Registro();
            }
            break;
            case 5:
            {
            string nombres[50];
            int pesos[50];
            int numPacientes = 0;
            string linea;
            

            ifstream pacientes; 
            pacientes.open("PacNuev.txt");

            string line;
            int cont = 0;

            while(getline(pacientes, linea)){

                if(cont == 0){
                    nombres[numPacientes] = linea;
                }
                if(cont == 9){
                    pesos[numPacientes] = stoi(linea);
                }
                cont++;

                if(cont == 12){
                    cont = 0;
                    numPacientes ++;
                }
            }
            break;
            }
            
            case 0:
            //Salida
                cout<< "\n\t" << signo_interrogacion <<"Segur@ que quieres salir?\n";
                cout <<"\n\t1. S" <<letra_i <<"\n";
                cout << "\t2. No\n\t";
                cin >> salida;

                if (salida == 2){
                    opcion = 4;
                    //return 0;//no se puede
                } 
                //else{
                  
                //return main();
                
                break;
                


        }

     
    } while (opcion != 0);
        system ("pause");
    
}

void Registrar_Paciente()
    {
        //system("cls");
        string nombre;
        int edad;
        string sexo;
        string lugar_nacimiento;
        string nombre_padre;
        int edad_padre;
        string nombre_madre;
        int edad_madre;
        int telefono;
        float peso;
        float estatura;
        string alergias;
        fstream Registro;

        Registro.open("PacNuev.txt", ios::out | ios::app);
            cout << "Nombre Completo: ";
            cin >> nombre;
            cout << "Edad: ";
            cin >> edad;
            cout << "Sexo: ";
            cin >> sexo;
            cout << "Lugar de nacimiento: ";
            cin >> lugar_nacimiento;
            cout << "Nombre completo del padre: ";
            cin >> nombre_padre;
            cout << "Edad del padre: ";
            cin >> edad_padre;
            cout << "Nombre de la madre: ";
            cin >> nombre_madre;
            cout << "Edad de la madre: ";
            cin >> edad_madre;
            cout << "Telefono: ";
            cin >> telefono;
            cout << "Peso: ";
            cin >> peso;
            cout << "Estatura: ";
            cin >> estatura;
            cout << "Alergias: ";
            cin >> alergias;
            Registro << nombre; 
            Registro <<"\n" << edad; 
            Registro <<"\n" << sexo; 
            Registro <<"\n" << lugar_nacimiento; 
            Registro <<"\n" << nombre_padre ;
            Registro <<"\n" << edad_padre ;
            Registro <<"\n" << nombre_madre ;
            Registro <<"\n" << edad_madre ;
            Registro <<"\n" << telefono ;
            Registro <<"\n" << peso ;
            Registro <<"\n" << estatura ;
            Registro <<"\n" << alergias << "\n";
            Registro.flush(); //para forzar
            Registro.close();
            //cout << "El paciente ha sido registrado";
    }        

void Ver_Registros()
{
    system("cls");
    string nombre;
    int edad;
    string sexo;
    string lugar_nacimiento;
    string nombre_padre;
    int edad_padre;
    string nombre_madre;
    int edad_madre;
    int telefono;
    float peso;
    float estatura;
    string alergias;
    fstream Lec;

    Lec.open("PacNuev.txt", ios::in);
    cout<<"----------Registro Pacientes----------"<<endl<<endl;
    Lec >> nombre;
    while(!Lec.eof()){  
    Lec >> edad;
    Lec >> sexo;
    Lec >> lugar_nacimiento;
    Lec >> nombre_padre;
    Lec >> edad_padre;
    Lec >> nombre_madre;
    Lec >> edad_madre;
    Lec >> telefono;
    Lec >> peso;
    Lec >> estatura;
    Lec >> alergias;
    cout<<"Nombre------: " <<nombre<<endl;
    cout<<"Edad------: " <<edad<<endl;
    cout<<"Sexo------: " <<sexo<<endl;
    cout<<"Lugar------: " <<lugar_nacimiento<<endl;
    cout<<"NombrePadre------: " <<nombre_padre<<endl;
    cout<<"EdadPadre------: " <<edad_padre<<endl;
    cout<<"NombreMadre------: " <<nombre_madre<<endl;
    cout<<"EdadMadre------: " <<edad_madre<<endl;
    cout<<"Telefono------: " <<telefono<<endl;
    cout<<"Peso------: " <<peso<<endl;
    cout<<"Estatura------: " <<estatura<<endl;
    cout<<"Alergias------: " <<alergias<<endl;
    cout << "--------------------------------"<<endl;
    Lec >> nombre;

    }  
    Lec.close();
    system ("pause");
} 


void Buscar_Registro()
    {
        system("cls");
        string nombre;
        string nombre_paciente;
        int edad;
        bool encontrado = false;
        string sexo;
        string lugar_nacimiento;
        string nombre_padre;
        int edad_padre;
        string nombre_madre;
        int edad_madre;
        int telefono;
        float peso;
        float estatura;
        string alergias;
        fstream Lec;

        Lec.open("PacNuev.txt", ios::in);
        cout<<"Digite el nombre: ";
        cin >>nombre_paciente;
        Lec>>nombre;
        while(!Lec.eof() && !encontrado)
        {
            Lec >> edad;
            Lec >> sexo;
            Lec >> lugar_nacimiento;
            Lec >> nombre_padre;
            Lec >> edad_padre;
            Lec >> nombre_madre;
            Lec >> edad_madre;
            Lec >> telefono;
            Lec >> peso;
            Lec >> estatura;
            Lec >> alergias;
   
            if (nombre_paciente == nombre)
            {
                    cout<<"Nombre------: " <<nombre<<endl;
                    cout<<"Sexo------: " <<sexo<<endl;
                    cout<<"Lugar------: " <<lugar_nacimiento<<endl;
                    cout<<"NombrePadre------: " <<nombre_padre<<endl;
                    cout<<"EdadPadre------: " <<edad_padre<<endl;
                    cout<<"NombreMadre------: " <<nombre_madre<<endl;
                    cout<<"EdadMadre------: " <<edad_madre<<endl;
                    cout<<"Telefono------: " <<telefono<<endl;
                    cout<<"Peso------: " <<peso<<endl;
                    cout<<"Estatura------: " <<estatura<<endl;
                    cout<<"Alergias------: " <<alergias<<endl;
                    cout << "--------------------------------"<<endl;
                    encontrado = true;
        
            }
            Lec >> nombre;
        }
        Lec.close();

        if(!encontrado)
            cout<<"Dato no encontrado"<<endl;
        system("pause");

    }
void Modificar_Registro()
    {
        system("cls");
        string nombre;
        string sexo;
        string lugar_nacimiento;
        string nombre_padre;
        int edad_padre;
        string nombre_madre;
        int edad_madre;
        int telefono;
        float peso;
        float estatura;
        string alergias;
        string nomaux;
        string alergiasaux;
        fstream Lec; 

        Lec.open("PacNuev.txt", ios::in);
        ofstream aux("Auxiliar.txt", ios::out);
        if(Lec.is_open()){
            cout<<"Nombre a modificar";
            cin>>nomaux;
            cout<<"Alergias a modificar";
            cin>>alergiasaux;
            Lec>>nombre;
            while(!Lec.eof()){
                Lec>>alergiasaux;
                Lec>>alergias;
                if(alergias ==alergiasaux){
                    cout<<"Escribe tu modificacion";
                    cin>>nomaux;
                    aux<<nomaux<<" "<<nombre<<" "<<alergias<<"\n";
                }else{
                    aux<<nombre<<" "<<nombre<<" "<<alergias<<"\n";
                }
                Lec>>nombre;

            }
            Lec.close();
            aux.close();
        }else{
            cout<<"Error"<<endl;
        remove("PacNuev.txt");
        rename("Auxiliar.txt", "PacNuev.txt");
        }


    }

    