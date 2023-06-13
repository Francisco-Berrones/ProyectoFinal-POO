//Programa Psicologo.h

/*Se pide que se manejen ciclos para la validación de 
los datos que se capturan, control de acceso al programa 
a través de usuario y password. Se debe de utilizar, herencia simple, 
múltiple, constructores, destructores, setters, getters, 
cualificadores private, protected y public, polimorfismo, 
inicialización, arreglos, vectores, strings, menú de selecciones 
y manejo de memoria dinámica (optimización de memoria)
*/

#include "iostream"
#include "fstream"
#include "string"
#include "chrono"
#include "conio"
#include "ctime"
using namespace std;

    class Consultorio{
        private:
            string usuario, Admin;
            char *contraseniaUsuario, *contraseniaAdmin;
            

        public:
            Consultorio();
            void login();
            void leerArchivos();
            void verCalendario();
            ~Consultorio();
            
        protected:
            int ren = 0, ren3 = 0, ren4 = 0;
            int dia, hora, minuto, telefono, n; string nombreDia;
            string calendario[6][5], Lunes, Martes, Miercoles, Jueves, Viernes;
            int numPaciente; string nombre, edad, sexo, calle, colonia, municipio, status; //numero de pacientes que se pueden registrar y datos de los pacientes

            Paciente *pacientes[10]; //numero de pacientes que se pueden registrar
            string fecha;
            ifstream ArchivoCalendario;    // declaro mi variable archivoEnt para llenar productos
            fstream CambiarPacientes; string listaPacientes[10][7]; int numeroPaciente[10][10];
            fstream Acceso; fstream LeerPacientes; fstream LeerCitas;
    };

    Consultorio::Consultorio(){}

    Consultorio::~Consultorio(){}
            
    //Login - Control de acceso para usuario
    void Consultorio::login(){}

    void Consultorio::leerArchivos(){
        ArchivoCalendario.open("Calendario.txt");

    //leer tabla de datos y guardarla en mis tablas
    while(ArchivoCalendario>>Lunes>>Martes>>Miercoles>>Jueves>>Viernes) // leo archivo de tabladeprecios.txt y lo vacio a la tabla
    {
        calendario[ren4][1]=Lunes;
        calendario[ren4][2]=Martes;
        calendario[ren4][3]=Miercoles;
        calendario[ren4][4]=Jueves;
        calendario[ren4][5]=Viernes;
        ren4++;
    }  // termina el while

            Acceso.open("ControlDeAcceso.txt");
            if(Acceso.fail()){ cerr<<'Error:No se encontro el archivo "ControlDeAcceso.txt"' << endl; exit(1); }
            Acceso.close();
            
            LeerPacientes.open("DatosDePacientes.txt");
            while(LeerPacientes>>numPaciente>>nombre>>edad>>sexo>>calle>>colonia>>municipio>>status) // leo archivo de tabladeprecios.txt y lo vacio a la tabla
            {   
                cout<<"Lista "<<ren3 <<" copiada \n";
                numeroPaciente[ren3][0]= ren3+1;;
                listaPacientes[ren3][1]= nombre;
                listaPacientes[ren3][2]= edad;
                listaPacientes[ren3][3]= sexo;
                listaPacientes[ren3][4]= calle;
                listaPacientes[ren3][5]= colonia;
                listaPacientes[ren3][6]= municipio;
                listaPacientes[ren3][7]= status;
                pacientes[ren3] = new Paciente(nombre, edad, sexo, calle, colonia, municipio);
                ren3++;
            }  LeerPacientes.close();// termina el while
    }

    //Ver el calendario de la doctora en general
    void verCalendario(){}

    /////////////////////////////////////////////////////////////////
    //CLASE PACIENTE
    ////////////////////////////////////////////////////////////////

    class Paciente : public Consultorio{

        public:
            Paciente();
            Paciente(string _nombre, string _edad, string _sexo, string _calle, string _colonia, string _municipio);
            string nombreDelPaciente();
            void verMenu();
            void agendarCita();                 //Agendar Citas
            virtual void mostrarCita();         //Ver Citas
            void modificarCita();               //Modificar Citas
            ~Paciente();
    };

    Paciente::Paciente(){}

    Paciente::Paciente(string _nombre, string _edad, string _sexo, string _calle, string _colonia, string _municipio){
        this-> nombre = _nombre;
        this->edad = _edad;
        this->sexo = _sexo;
        this->colonia = _colonia;
        this->municipio = _municipio;
    }

    void Paciente::verMenu(){
        cout << "\x1B[2J\x1B[H";    //limpia pantalla
        cout<<" --- Consultorio Dra. Juguetes (Usuario: ";   /*pacientes[n] -> nombreDelPaciente();*/     cout<<") ---\n";
        cout<<"1) Registrar un Paciente \n2)Modificar datos del Paciente \n3)Agendar una cita\n";
        cout<<"4)Mostrar la cita \n5)Modificar una cita \n6)Ver Pacientes \n7)Ver el calendario semanal \n8)Salir";

    }

    //Agendar Citas -- Paciente
    void Paciente::agendarCita(){
    pacientes[ren3]->leerArchivos();
    LeerCitas.open("Calendario.txt");

    cout << "\x1B[2J\x1B[H";    //limpia pantalla
    cout<<"1) Lunes \n2) Martes \n3) Miercoles \n4) Jueves \n5) Viernes\n";
    cout<<"Que dia desea hacer la cita?: (Escriba el numero del 1 al 5) \n";
    cin >> dia;
        while (dia < 1 or dia > 5){
            cout << "\x1B[2J\x1B[H";    //limpia pantalla
            cout<<"1) Lunes \n2) Martes \n3) Miercoles \n4) Jueves \n5) Viernes\n";
            cout<<"Porfavor, escriba un numero del 1 al 5: \n";
            cin >> dia;
        }
            if(dia == 1){nombreDia == "Lunes";}
            if(dia == 2){nombreDia == "Martes";}
            if(dia == 3){nombreDia == "Miercoles";}
            if(dia == 4){nombreDia == "Jueves";}
            if(dia == 5){nombreDia == "Viernes";}
            cout<<"Horarios disponibles para el dia " << nombreDia << " : \n";
            cout<<"|   Calendario   |   Lunes   |   Martes   |   Miercoles   |   Jueves   |   Viernes   | \n";
            for(int i=0;i<ren4;i++){
                
            }
            cout<<"A que hora desea hacer la cita?: (Escriba el numero del 1 al 8) \n";
            cin >> hora;
 /*           
        cout << "Bienvenido al sistema de Agenda de citas ";
        cout << "En que horario quisiera la cita? (Introduzca un hora entre 0 y 23): ";
        cin >> hora;
        r.setHora(hora);
        cout << "En qué minuto de esa hora quisiera la cita? (Solo introducir minutos entre 0 y 59): ";
        cin >> minuto;
        r.setMin(minuto);
        
        for(int j = 0; j < cantCitas; j++){
            Tiempo rComp = citas[j].getHoraIni();
            if(rComp.getHora() == r.getHora() and rComp.getMinu() == r.getMinu()){
                cout << "La cita se empalma con otra cita en este horario: ";
                rComp.mostrar();
                cout << "\nIntroduzca una hora diferente para la cita (Solo introducir hora entre 0 y 23): ";
                cin >> hora;
                r.setHora(hora);
                cout << "Introduzca un minuto diferente para la cita (Solo introducir minutos entre 0 y 59): ";
                cin >> minuto;
                r.setMin(minuto);
                break;
            }
        }*/
    }

    //Ver Citas -- Paciente
    void Paciente::mostrarCita(){

    }

    //Modificar Citas   -- Paciente
    void Paciente::modificarCita(){

    }

    //Obtener el nombre del Paciente -- DOCTORA
    string Paciente::nombreDelPaciente(){}

    Paciente::~Paciente(){}
    
    /////////////////////////////////////////////////////////////////
    //CLASE DOCTORA
    /////////////////////////////////////////////////////////////////

    class Doctora : public Consultorio{
        private:
            int r, ren2;
            int cveModificar, numDato;
            fstream LeerPacientes; string valorNuevo;
            Doctora *doctora;
            
        public:
            Doctora();
            void mostrarCitasAgendadas();       //Muestra las citas de la semana
            void registrarPaciente();            //Registrar un paciente
            void modificarDatosPaciente();      //Modificar Paciente - Modificar la informacion del paciente
            void verListaDePacientes();
            void modificarStatusPaciente();
            void verStatusPaciente();
            ~Doctora();
    };


    Doctora::Doctora(){}

    //Ver Citas -- DOCTORA -- //Muestra las citas de la semana
    void Doctora::mostrarCitasAgendadas(){}

    //Registrar un paciente  -- DOCTORA
    void Doctora::registrarPaciente(){
        doctora->leerArchivos();
        cin.ignore();
        cout<<"Bienvenido al registro de pacientes!\n Le pedimos que por favor ingrese los siguientes datos: ";
        cout<<"\nNombre: "; getline(cin, nombre);
        cout<<"\nEdad: "; getline(cin, edad);
        cout<<"\nSexo: "; getline(cin, sexo);

        cout<<"\n --- Datos de domicilio --- ";
        cout<<"\nCalle: "; getline(cin, calle);
        cout<<"\nColonia: "; getline(cin, colonia);
        cout<<"\nMunicipio: "; getline(cin, municipio);

        pacientes[ren3] = new Paciente(nombre, edad, sexo, calle, colonia, municipio);

                numeroPaciente[ren3][0]= ren3+1;
                listaPacientes[ren3][1]= nombre;
                listaPacientes[ren3][2]= edad;
                listaPacientes[ren3][3]= sexo;
                listaPacientes[ren3][4]= calle;
                listaPacientes[ren3][5]= colonia;
                listaPacientes[ren3][6]= municipio;
                listaPacientes[ren3][7]= status;
                ren3++;

        CambiarPacientes.open("DatosDePacientes.txt"); //write
        //for para cambiar datos del archivo de texto
        for (r=0;r<ren3;r++){
            CambiarPacientes<< numeroPaciente[r][0] <<" "<<listaPacientes[r][1]<<" "<<listaPacientes[r][2]<<" "<<listaPacientes[r][3]<<" "<<listaPacientes[r][4]<<" "<<listaPacientes[r][5]<<" "<<listaPacientes[r][6]<<" "<<listaPacientes[r][7]<<endl;
        } // fin del for de archivo
        cout<<"El usuario se ha registrado correctamente!" << endl;
        pacientes[ren3-1]->verMenu();
            
        CambiarPacientes.close();
    }            
    
     //Modificar Paciente - Modificar la informacion del paciente  -- DOCTORA
    void Doctora::modificarDatosPaciente(){
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
    }     

    //Ver pacienteS - ver la informacion de los pacientes  -- DOCTORA
    void Doctora::verListaDePacientes(){
        doctora->leerArchivos();

        for (int i = 0; i < ren3 ; i++)
        {
            cout<<"|  Clave del paciente  |  Nombre  |  Edad  |   Sexo   |      Direccion      |        Status del paciente        |" 
        }

        LeerPacientes.open("DatosDePacientes.txt");
            while(LeerPacientes>>numPaciente>>nombre>>edad>>sexo>>calle>>colonia>>municipio>>status) // leo archivo de tabladeprecios.txt y lo vacio a la tabla
            {   
                cout<<"Lista "<<ren3 <<" copiada \n";
                numeroPaciente[ren3][0]= ren3+1;;
                listaPacientes[ren3][1]= nombre;
                listaPacientes[ren3][2]= edad;
                listaPacientes[ren3][3]= sexo;
                listaPacientes[ren3][4]= calle;
                listaPacientes[ren3][5]= colonia;
                listaPacientes[ren3][6]= municipio;
                listaPacientes[ren3][7]= status;
                pacientes[ren3] = new Paciente(nombre, edad, sexo, calle, colonia, municipio);
                ren3++;
            }  LeerPacientes.close();// termina el while
        
    }

    //Estatus del Paciente - Actualizar informacion del estatus del paciente  -- DOCTORA
    void Doctora::modificarStatusPaciente(){}

    void Doctora::verStatusPaciente(){}

    Doctora::~Doctora(){}
