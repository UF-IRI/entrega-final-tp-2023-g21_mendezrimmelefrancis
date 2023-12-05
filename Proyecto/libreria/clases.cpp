#include "clases.h"


void ltClases_agregar(clases*& ltclases, clases nuevo, int* tamactual) {
    *tamactual = *tamactual + 1;
    int i = 0;
    clases* aux = new clases[*tamactual];
    while (i < *tamactual - 1 && *tamactual - 1 != 0) {
        aux[i] = ltclases[i];
        i++;
    }
    aux[i] = nuevo;

    delete[] ltclases;
    ltclases = aux;

    return;
}
clases* ArchClases_leer() {
    clases* ltclases = new clases[0];
    clases aux;
    string parche;
    char coma = ',';

    int tamact = 0;

    fstream arch;
    arch.open(fileClases, ios::in);


    if (!(arch.is_open()))
        return nullptr;

    string basura;
    getline(arch,basura);
    while (getline(arch,basura)) {
        string auxestado;
        stringstream stream(basura);
        getline(stream,aux.idClase,coma);
        getline(stream,aux.clase,coma);
        getline(stream,aux.horario,coma);
        ltClases_agregar(ltclases, aux, &tamact);
    }

    arch.close();


    return ltclases;
}
void ArchClases_agregar(clases nuevo) {
    string coma = ",";
    string barra = "/";
    fstream arch;


    string auxestado;



    arch.open(fileClases, ios::in);
    if (!(arch.is_open())) {

        bool ok = ArchClases_crear();
        if (ok == false) {
            arch.close();
            return;
        }
    }
    arch.close();
    arch.open(fileClases,  ios::app);
    if (arch.is_open()) {
        arch <<endl<< nuevo.idClase << coma << nuevo.clase << coma << nuevo.horario ;
    }
    arch.close();



    return;
}
bool ArchClases_crear() {

    fstream arch;
    arch.open(fileClases, ios::out);

    if (arch.is_open()) {
        arch << "idClase,clase,horario" << endl;
        return true;
    }
    else { return false; }
}
int TamanioArchClases() {


    fstream arch;
    arch.open(fileClases, ios::in);

    if (!(arch.is_open()))
        return 0;

    string basura,aux;
    getline(arch,basura);
    int i = 0;
    while (getline(arch,basura)) {
        stringstream stream(basura);
        getline(stream,aux);
        i++;
    }

    arch.close();
    return i;
}
void ImpClases() {
    //imprimo clases
    string coma = " , ";
    clases* p = ArchClases_leer();
    int tam = TamanioArchClases();
    int i = 0;
    cout << "idClase,clase,horario" << endl;
    while (i < tam) {
        cout << p[i].idClase << coma << p[i].clase << coma << p[i].horario << endl;
        i++;
    }
    delete[]p;
    system("pause");
    system("cls");
}

void Minuscula(string &palabra){
    for(int i=0;i<(int)palabra.length();i++){
        palabra[i]=towlower(palabra[i]);
    }
}
