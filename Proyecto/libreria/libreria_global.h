#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <ctime>
#include <random>
#include <libreria.h>

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
    string dia;
    string mes;
    string anio;

};typedef struct Fecha fecha;

struct Clientes{
    string idCliente;
    string nombre,apellido,email;
    string telefono;
    fecha fechaNac;
    string estado;
};typedef struct Clientes clientes;

struct Clases{
    string idClase;
    string clase;
    string horario;
};typedef struct Clases clases;

struct Inscripcion{
    int idclase;
    time_t fechainscripcion;
};typedef struct Inscripcion inscripcion;

struct Asistencias{
    int idcliente;
    int cantinscriptos;
    inscripcion inscripcion[11];//maaximo de 11 clases diarias por horarios de apertura
};typedef struct Asistencias asistencias;



