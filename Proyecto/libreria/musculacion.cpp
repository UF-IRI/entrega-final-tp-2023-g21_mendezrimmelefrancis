#include "musculacion.h"


void ImpPositivosMusculacion(clientes* ltclientes, int tam){
    clientes* clientespos=new clientes[tam];//maximo
    int newtam=0;
    int pos=0;
    for(int i=0;i<tam;i++ ){
        pos=stoi(ltclientes[i].estado);
        if(pos>=0){
            clientespos[newtam]=ltclientes[i];
            newtam++;
        }
    }
    ImpClientes(clientespos,newtam);
    delete[] clientespos;
}

void ImpNegativosMusculacion(clientes* ltclientes, int tam){
    clientes* clientesneg=new clientes[tam];//maximo
    int newtam=0;
    int pos=0;
    for(int i=0;i<tam;i++ ){
        pos=stoi(ltclientes[i].estado);
        if(pos<0){
            clientesneg[newtam]=ltclientes[i];
            newtam++;
        }
    }
    ImpClientes(clientesneg,newtam);
    delete[] clientesneg;
}
