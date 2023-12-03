#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <ctime>
#include <random>

#define fileClases "C:\\Users\\Facu\\OneDrive\\Documentos\\UF\\IRI\\2023 2do cuatri\\QT\\entrega-final-tp-2023-g21_mendezrimmelefrancis\\Proyecto\\iriClasesGYM.csv"
#define fileClientes "C:\\Users\\Facu\\OneDrive\\Documentos\\UF\\IRI\\2023 2do cuatri\\QT\\entrega-final-tp-2023-g21_mendezrimmelefrancis\\Proyecto\\iriClientesGYM.csv"
#define fileAsistencias "C:\\Users\\Facu\\OneDrive\\Documentos\\UF\\IRI\\2023 2do cuatri\\QT\\entrega-final-tp-2023-g21_mendezrimmelefrancis\\Proyecto\\asistencias_1697673600000.dat"
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

struct Inscripcion{
    int idclase;
    //string idclase;
    time_t fechainscripcion;
    //string fechainscripcion;
};typedef struct Inscripcion inscripcion;

struct Asistencias{
    int idcliente;
    //string idcliente;
    int cantinscriptos;
    //string cantinscriptos;
    inscripcion inscripcion[11];//maaximo de 11 clases diarias por horarios de apertura
};typedef struct Asistencias asistencias;



