#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <ctime>

#define fileClases "C:\\Users\\Facu\\OneDrive\\Documentos\\UF\\IRI\\2023 2do cuatri\\QT\\TP\\G21-MendezRimmele\\Proyecto\\iriClasesGYM.csv"
#define fileClientes "C:\\Users\\Facu\\OneDrive\\Documentos\\UF\\IRI\\2023 2do cuatri\\QT\\TP\\G21-MendezRimmele\\Proyecto\\iriClientesGYM.csv"
#define fileReservas "C:\\Users\\Facu\\OneDrive\\Documentos\\UF\\IRI\\2023 2do cuatri\\QT\\TP\\G21-MendezRimmele\\Proyecto\\iriReservasGYM.csv"

using namespace std;

enum eActividad { Musculacion = 1, Clases, Clientes };
enum eClase { Spinning = 1, Yoga, Pilates, Stretching, Zumba, Boxeo };
enum ePlan {Dia = 1, Semana, Mes, Anio};
enum eMusc { Validar = 1, Agregar};
enum eSalas {bicis=45,siri=25,camillas=15,gim1=40,gim2=50,box=30};

struct Fecha{
    //int dia;
    //int mes;
    //int anio;
    string dia;
    string mes;
    string anio;

};typedef struct Fecha fecha;

struct Clientes{
    //unsigned int idCliente;
    string idCliente;
    string nombre,apellido,email;
    //unsigned int telefono;
    string telefono;
    fecha fechaNac;
    //int estado;
    string estado;
};typedef struct Clientes clientes;

struct Clases{
    //int idClase;
    string idClase;
    string clase;
    //float horario;
    string horario;
};typedef struct Clases clases;

struct Reservas{
    clientes cliente;
    clases clase;
    fecha f_reserva;
};typedef struct Reservas reservas;


