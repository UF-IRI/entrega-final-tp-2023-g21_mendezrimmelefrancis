#include "clases.h"

void ltClientes_agregar(clientes*& ltclientes, clientes nuevo, int* tamactual);
clientes* ArchClientes_leer();
void ArchClientes_agregar(clientes nuevo, int tam);
bool ArchClientes_crear();
int TamanioArchClientes();
void ImpClientes(clientes* ltclientes,int tamclientes);
string buscarIdCliente(clientes* ltclientes,int tamclientes);
void ImpPositivos(clientes* ltclientes, int tam);
void ImpNegativos(clientes* ltclientes, int tam);
bool ExisteCliente(clientes nuevo, int tam);
