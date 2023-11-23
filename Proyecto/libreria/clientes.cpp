#include "clientes.h"


void ltClientes_agregar(clientes*& ltclientes, clientes nuevo, int* tamactual) {
    *tamactual = *tamactual + 1;
    int i = 0;
    clientes* aux = new clientes[*tamactual];
    while (i < *tamactual - 1 && *tamactual - 1 != 0) {
        aux[i] = ltclientes[i];
        i++;
    }
    if(nuevo.idCliente!=""){
        aux[i] = nuevo;
    }

    delete[] ltclientes;
    ltclientes = aux;

    return;
}
clientes* ArchClientes_leer() {
    clientes* ltclientes = new clientes[0];
    clientes aux;
    string parche;
    char coma = ',';

    int tamact = 0;

    fstream arch;
    arch.open(fileClientes, ios::in);


    if (!(arch.is_open()))
        return nullptr;

    string basura;
    //arch >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura;
    getline(arch,basura);
    while (getline(arch,basura)) {
        //arch >> aux.dni >> coma >> aux.clase >> coma >> aux.apellido >> coma >> aux.sexo >> coma >> aux.natalicio.dia >> coma >> aux.natalicio.mes >> coma >> aux.natalicio.anio >> coma >> auxestado >> coma >> aux.id_os.obra_social;
        stringstream stream(basura);
        getline(stream,parche,coma);
        aux.idCliente=parche;
        //aux.idCliente=stoi(parche); // ->no se porque pero el programa se traba y me tira error cuando uso datos numerico
        getline(stream,aux.nombre,coma);
        getline(stream,aux.apellido,coma);
        getline(stream,aux.email,coma);
        getline(stream,aux.telefono,coma);
        //aux.telefono=stoi(parche);
        getline(stream,aux.fechaNac.dia,'-');
        //aux.fechaNac.dia=stoi(parche);
        getline(stream,aux.fechaNac.mes,'-');
        //aux.fechaNac.mes=stoi(parche);
        getline(stream,aux.fechaNac.anio,coma);
        //aux.fechaNac.anio=stoi(parche);
        getline(stream,aux.estado,coma);
        //aux.estado=stoi(parche);
        ltClientes_agregar(ltclientes, aux, &tamact);

    }

    arch.close();


    return ltclientes;
}
void ArchClientes_agregar(clientes nuevo) {
    string coma = ",";
    string barra = "/";
    fstream arch;


    string auxestado;



    arch.open(fileClientes, ios::in);
    if (!(arch.is_open())) {

        bool ok = ArchClientes_crear();
        if (ok == false) {
            arch.close();
            return;
        }
    }
    arch.close();
    arch.open(fileClientes,  ios::app);
    if (arch.is_open()) {
        arch <<endl<< nuevo.idCliente << coma << nuevo.nombre << coma << nuevo.apellido << coma << nuevo.email << coma << nuevo.telefono << coma << nuevo.fechaNac.dia + '-' + nuevo.fechaNac.mes + '-' + nuevo.fechaNac.anio << coma << nuevo.estado;
    }
    arch.close();



    return;
}
bool ArchClientes_crear() {

    fstream arch;
    arch.open(fileClientes, ios::out);

    if (arch.is_open()) {
        arch << "idCliente,nombre,apellido,email,telefono,fechaNac,estado" << endl;
        return true;
    }
    else { return false; }
}
int TamanioArchClientes() {


    fstream arch;
    arch.open(fileClientes, ios::in);

    if (!(arch.is_open()))
        return 0;

    string basura,aux;
    //arch >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura;
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
void ImpClientes(clientes* p,int tam) {
    //imprimo clases
    string coma = " , ";

    int i = 0;
    cout << "idCliente,nombre,apellido,email,telefono,fechaNac,estado" << endl;
    while (i < tam) {
        if(p[i].idCliente!=""){
            cout << p[i].idCliente << coma << p[i].nombre << coma << p[i].apellido << coma << p[i].email << coma << p[i].telefono << coma << p[i].fechaNac.dia + '-' + p[i].fechaNac.mes + '-' + p[i].fechaNac.anio << coma << p[i].estado << endl;
        }
       i++;
    }
    delete[]p;
    system("pause");
    system("cls");
}
string buscarIdCliente(clientes* ltclientes,int tamclientes){
    string apellido;
    int largo=0;
    cout<<"Ingrese apellido:";cin>>apellido;
    Minuscula(apellido);
    string ap;
    for(int i=0;i<tamclientes;i++){
        ap=ltclientes[i].apellido;
        Minuscula(ap);
        if(apellido==ap){
            largo++;
        }
    }
    system("cls");

    string apellidos[largo];
    string ids[largo];
    //asistencias nueva_asistencia;
    cout<<"Elija el cliente:"<<endl;
    int j=0;

    for(int i=0;i<tamclientes;i++){
        ap=ltclientes[i].apellido;
        Minuscula(ap);
        if(apellido==ap){ //significa que si hay lugar en la sala i
            cout<<j+1<<")"<<ltclientes[i].apellido<<", "<<ltclientes[i].nombre<<endl;
            apellidos[j]=ltclientes[i].apellido;
            ids[j]=ltclientes[i].idCliente;
            j++;
        }
    }
    int opcion;
    if(j!=0){
        cout<<"Eleccion:";cin>>opcion;
        do{
            if(opcion<1 || opcion>j){
                system("cls");
                j=0;
                cout<<"Intente nuevamente"<<endl;
                for(int i=0;i<tamclientes;i++){
                    ap=ltclientes[i].apellido;
                    Minuscula(ap);
                    if(apellido==ap){ //significa que si hay lugar en la sala i
                        cout<<j+1<<")"<<ltclientes[i].apellido<<", "<<ltclientes[i].nombre<<endl;
                        j++;
                    }
                }
                cout<<"Eleccion:";cin>>opcion;
            }
        }while(opcion<1 || opcion>j);
        //cout<<"prueba:"<<guardadoID[opcion]<<endl;
        opcion--;
        return ids[opcion];
    }else{//si no encuntra ninguna clase con por lo menos 1 lugar
        system("cls");
        cout<<"No existe el cliente o intente nuevamente."<<endl;
        system("pause");
        system("cls");
        return " ";
    }
    system("cls");
}
