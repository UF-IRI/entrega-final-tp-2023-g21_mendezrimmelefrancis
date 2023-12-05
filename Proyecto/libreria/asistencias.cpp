#include "asistencias.h"

void ltAsistencias_agregar(asistencias*& ltasistencias, asistencias nuevo, int* tamactual) {
    *tamactual = *tamactual + 1;
    int i = 0;
    asistencias* aux = new asistencias[*tamactual];
    while (i < *tamactual - 1 && *tamactual - 1 != 0) {
        aux[i] = ltasistencias[i];
        i++;
    }
    aux[i] = nuevo;

    delete[] ltasistencias;
    ltasistencias = aux;

    return;
}
asistencias* ArchAsistencias_leer(int tam) {
        asistencias* ltasistencias = new asistencias[0];
        int tamact=0;
        int maxclientes = TamanioArchClientes();
        asistencias aux;
        ifstream archivoBinario(fileAsistencias, ios::binary);

        if (archivoBinario.is_open()) {

        for(int k =0;k<tam;k++) {

                archivoBinario.read((char*)&aux.idcliente, sizeof(int));
            if(aux.idcliente>0 && maxclientes>aux.idcliente){//compruebo que sea un cliente y no basura, no me esta saliendo borrar un solo elemento
                    archivoBinario.read((char*)&aux.cantinscriptos, sizeof(int));

                    int i=0;
                    while(i<aux.cantinscriptos && aux.cantinscriptos!=0){

                        archivoBinario.read((char*)&aux.inscripcion[i].idclase, sizeof(int));

                        archivoBinario.read((char*)&aux.inscripcion[i].fechainscripcion, sizeof(time_t));

                        i++;
                    }
                    if(aux.idcliente!=0 && aux.cantinscriptos!=0){
                        ltAsistencias_agregar(ltasistencias, aux, &tamact);
                    }
            }
        }
            archivoBinario.close();
    }

        return ltasistencias;
}
void ArchAsistencias_agregar(asistencias* ltasistencias, asistencias nuevo,int tam) {

        int tamclientes=TamanioArchClientes();
        int parche=0;
        time_t parchet;
        bool existe=ExisteInscripcionCliente(nuevo,tam);

        ofstream archivoBinario(fileAsistencias, ios::binary);

        if (archivoBinario.is_open()) {
            for(int k=0;k<tam;k++){
            if(ltasistencias[k].idcliente>0 && ltasistencias[k].idcliente<(tamclientes+1)){
                    if(ltasistencias[k].idcliente==nuevo.idcliente){
                        ltasistencias[k]=nuevo;
                    }
                    parche=ltasistencias[k].idcliente;
                    archivoBinario.write((char*)&parche, sizeof(int));
                    parche=ltasistencias[k].cantinscriptos;
                    archivoBinario.write((char*)&parche, sizeof(int));

                    int i=0;
                    while(i<ltasistencias[k].cantinscriptos && ltasistencias[k].cantinscriptos!=0){
                        parche=ltasistencias[k].inscripcion[i].idclase;
                        archivoBinario.write((char*)&parche, sizeof(int));
                        parchet=ltasistencias[k].inscripcion[i].fechainscripcion;
                        archivoBinario.write((char*)&parchet, sizeof(time_t));
                        i++;
                    }
                }

            }
            if(existe == false){//lo agrego como nuevo
                archivoBinario.write((char*)&nuevo.idcliente, sizeof(int));
                archivoBinario.write((char*)&nuevo.cantinscriptos, sizeof(int));

                int i=0;
                while(i<nuevo.cantinscriptos && nuevo.cantinscriptos!=0){
                    archivoBinario.write((char*)&nuevo.inscripcion[i].idclase, sizeof(int));
                    archivoBinario.write((char*)&nuevo.inscripcion[i].fechainscripcion, sizeof(time_t));
                    i++;
                }
            }
            archivoBinario.close();
        }

}
bool ArchAsistencias_crear() {

    fstream arch;
    arch.open(fileAsistencias, ios::out);

    if (arch.is_open()) {
        arch << "idCliente,cantInscriptos,{Inscripcion(idCurso, fechaInscripcion)}" ;
        return true;
    }
    else { return false; }
}
int TamanioArchAsistencias() {
    int tamanio=0;
    asistencias aux;
    int exit=0;

    ifstream archivoBinario(fileAsistencias, ios::binary);


    if (archivoBinario.is_open()) {
        while (!archivoBinario.eof()) {

                archivoBinario.read((char*)&aux.idcliente, sizeof(int));
                if(exit==aux.idcliente){
                    break;
                }exit=aux.idcliente;
                archivoBinario.read((char*)&aux.cantinscriptos, sizeof(int));
                int i=0;
                while(i<aux.cantinscriptos && aux.cantinscriptos!=0){
                    archivoBinario.read((char*)&aux.inscripcion[i].idclase, sizeof(int));
                    archivoBinario.read((char*)&aux.inscripcion[i].fechainscripcion, sizeof(time_t));
                    i++;
                    }

                tamanio++;
        }

    }
    archivoBinario.close();
    return tamanio;
}
void Impasistencias(int tam) {

    char coma = ',';
    asistencias* p = ArchAsistencias_leer(tam);

    int i = 0;
    cout << "idCliente,cantInscriptos,{Inscripcion(idCurso, fechaInscripcion)}" << endl;
    while (i < tam) {
        cout << p[i].idcliente << coma << p[i].cantinscriptos << coma <<'{';
        int cant=p[i].cantinscriptos;
        for(int k=0;k<cant;k++){

                    cout<<'(';cout<<p[i].inscripcion[k].idclase<<coma<<p[i].inscripcion[k].fechainscripcion;cout<<')'<<coma;

        }
        cout<<'}'<<endl;
        i++;
    }
    delete[]p;
    system("pause");
    system("cls");
}
bool Inscripciones(asistencias nuevo,int tamltasistencias){
asistencias* ltasistencias=ArchAsistencias_leer(tamltasistencias);
clases* ltclases=ArchClases_leer();
clientes* ltclientes=ArchClientes_leer();
int tamltclases=TamanioArchClases();
int tamclientes=TamanioArchClientes();
string clase;
int sala=0,contar=0,estado=0;

//ESTO SI DEBERIA IR PARA QUE LOS QUE DEBEN NO PUEDAN INSCRIBIRSE, NO ME ANDA STOI Y NO PUEDO COMPARAR ENTEROS
for(int i=0;i<tamclientes;i++){
        if(to_string(nuevo.idcliente)==ltclientes[i].idCliente){
            estado=stoi(ltclientes[i].estado);
            if(estado<0){
                    cout<<"No puede reservar por estado en negativo."<<endl;
                    delete[] ltclientes;
                    delete[] ltclases;
                    delete[] ltasistencias;
                    system("pause");
                    return false;
            }
        }
}

for(int i=0;i<tamltclases;i++){ //recorro ltclases y busco id para saber cual el el cupo max de la sala de la calse que quiere asistir
      if(ltclases[i].idClase==to_string(nuevo.inscripcion[0].idclase)){//solo se puede agregar de a una clase
            clase=ltclases[i].clase;
            if(clase=="Spinning"){
                    sala=bicis;
                    break;
            }else if(clase=="Yoga"){
                    sala=siri;
                    break;
            }else if(clase=="Pilates"){
                    sala=camillas;
                    break;
            }else if(clase=="Stretching"){
                    sala=gim1;
                    break;
            }else if(clase=="Zumba"){
                    sala=gim2;
                    break;
            }else if(clase=="Boxeo"){
                    sala=box;
                    break;
            }else if(clase=="Musculacion"){
                    sala=30;//supongo que hay cupo de 30
                    break;
            }else{
                    cout<<"no encuentra la clase"<<endl;
                    delete[] ltclientes;
                    delete[] ltclases;
                    delete[] ltasistencias;
                    return false;
      }
    }
}
for(int i=0;i<tamltasistencias;i++){
    for(int k=0;k<ltasistencias[i].cantinscriptos;k++){
      if(ltasistencias[i].inscripcion[k].idclase==nuevo.inscripcion[0].idclase){
                    contar++;//cuento la cantidad de inscriptos en esa clase
      }
    }
}
//cout<<sala<<"-->"<<contar<<endl; //imprime la cantidad de lugares maximos y la  cantidad de ocupados que hay en la clase, lo uso para comprobar que funcione bien que no quede cupo
if((sala-contar)<=0){//si no queda cupo
    cout<<"no queda cupo"<<endl;
    system("pause");
    delete[] ltclientes;
    delete[] ltclases;
    delete[] ltasistencias;
    return false;
}
int posicion;
bool esnuevo=true;

for(int i=0;i<tamltasistencias;i++){
    posicion=ltasistencias[i].cantinscriptos;
      if(ltasistencias[i].idcliente==nuevo.idcliente ){//si ya existe en la lista
      for(int k =0;k<ltasistencias[i].cantinscriptos;k++){
                    if(ltasistencias[i].inscripcion[k].idclase!=nuevo.inscripcion[0].idclase){//si no esta inscripto ya en esta clase

                            ltasistencias[i].inscripcion[posicion].idclase=nuevo.inscripcion[0].idclase;
                            ltasistencias[i].inscripcion[posicion].fechainscripcion=nuevo.inscripcion[0].fechainscripcion;
                            ltasistencias[i].cantinscriptos++;
                            posicion=i;
                            esnuevo=false;
                            break;

                    }else{
                        cout<<"Ya esta inscripto en esta clase."<<endl;
                            system("pause");
                            delete[] ltclientes;
                            delete[] ltclases;
                            delete[] ltasistencias;
                        return false;
                    }
      }

      }
}
if(esnuevo == true){
      tamltasistencias++;
      ArchAsistencias_agregar(ltasistencias, nuevo,tamltasistencias);
      cout<<"Se guardo correctamente"<<endl;
      delete[] ltclientes;
      delete[] ltclases;
      delete[] ltasistencias;
      return true;
}
ArchAsistencias_agregar(ltasistencias, ltasistencias[posicion],tamltasistencias);
cout<<"Se guardo correctamente"<<endl;
delete[] ltclientes;
delete[] ltclases;
delete[] ltasistencias;
return true;
}
bool ExisteInscripcionCliente(asistencias nuevo, int tam){
asistencias* ltasistencias=ArchAsistencias_leer(tam);
for(int i=0;i<tam;i++){
      if(ltasistencias[i].idcliente==nuevo.idcliente){
      delete[] ltasistencias;
      return true;
      }
}
delete[] ltasistencias;
return false;
}

asistencias NuevaInscripcionRandom(){

    asistencias random;

    time_t hoy=time(0);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> randcliente(1, TamanioArchClientes());
    uniform_int_distribution<int> randclase(1, 33);//todos los ids de las clases que no sean musculacion

    int idcliente = randcliente(gen);
    int idclase = randclase(gen);

    random={idcliente,1,{{idclase,hoy}}};

    return random;
}
