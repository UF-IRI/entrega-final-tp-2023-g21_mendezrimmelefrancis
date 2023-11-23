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

asistencias NuevaMusculacionRandom(){

    asistencias random;

    time_t hoy=time(0);

    /*int idcliente = (rand() % tamclientes)+1;
    int idclase = (rand() % tamclases)+1;

    random={idcliente,1,{{idclase,hoy}}};

    return random;*/

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> randcliente(1, TamanioArchClientes());
    uniform_int_distribution<int> randclase(34, TamanioArchClases());//todos los ids de las clases que no sean musculacion

    int idcliente = randcliente(gen);
    int idclase = randclase(gen);

    random={idcliente,1,{{idclase,hoy}}};

    return random;
}
