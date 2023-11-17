#include "clientes.h"

void ltReservas_agregar(reservas*& ltreservas, reservas nuevo, int* tamactual);
reservas* ArchReservas_leer();
void ArchReservas_agregar(reservas nuevo);
bool ArchReservas_crear();
int TamanioArchReservas();
void ImpReservas();
void cupoReservas(eClase eclase,clientes* ltclientes,int tamclientes);
void ImpSemana();
