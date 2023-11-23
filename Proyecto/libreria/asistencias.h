#include "clientes.h"

void ltAsistencias_agregar(asistencias*& ltasistencias, asistencias nuevo, int* tamactual);
asistencias* ArchAsistencias_leer(int tam);
void ArchAsistencias_agregar(asistencias* ltasistencias,asistencias nuevo,int tam);
bool ArchAsistencias_crear();
int TamanioArchAsistencias();
void Impasistencias(int tam);
void cupoAsistencias(eClase eclase,clientes* ltclientes,int tamclientes);
void ImpSemana();
int cantInscripciones(int idclase,int idcliente);
bool ExisteInscripcionCliente(asistencias nuevo, int tam);
bool Inscripciones(asistencias nuevo,int tamltasistencias);
asistencias NuevaInscripcionRandom();
