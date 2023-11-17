#include "reservas.h"

void ltReservas_agregar(reservas*& ltreservas, reservas nuevo, int* tamactual) {
    *tamactual = *tamactual + 1;
    int i = 0;
    reservas* aux = new reservas[*tamactual];
    while (i < *tamactual - 1 && *tamactual - 1 != 0) {
        aux[i] = ltreservas[i];
        i++;
    }
    aux[i] = nuevo;

    delete[] ltreservas;
    ltreservas = aux;

    return;
}
reservas* ArchReservas_leer() {
    reservas* ltreservas = new reservas[0];
    reservas aux;
    string parche;
    char coma = ',';

    int tamact = 0;

    fstream arch;
    arch.open(fileReservas, ios::in);


    if (!(arch.is_open()))
        return nullptr;

    string basura;
    //arch >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura;
    getline(arch,basura);
    while (getline(arch,basura)) {
        //arch >> aux.dni >> coma >> aux.clase >> coma >> aux.apellido >> coma >> aux.sexo >> coma >> aux.natalicio.dia >> coma >> aux.natalicio.mes >> coma >> aux.natalicio.anio >> coma >> auxestado >> coma >> aux.id_os.obra_social;
        stringstream stream(basura);
        getline(stream,aux.cliente.idCliente,coma);
        //aux.idCliente=stoi(parche); // ->no se porque pero el programa se traba y me tira error cuando uso datos numerico
        getline(stream,aux.clase.idClase,coma);
        getline(stream,aux.f_reserva.dia,'-');
        getline(stream,aux.f_reserva.mes,'-');
        getline(stream,aux.f_reserva.anio,coma);
        ltReservas_agregar(ltreservas, aux, &tamact);
    }

    arch.close();


    return ltreservas;
}
void ArchReservas_agregar(reservas nuevo) {
    string coma = ",";
    string barra = "/";
    fstream arch;

    string auxestado;

    arch.open(fileReservas, ios::in);
    if (!(arch.is_open())) {

        bool ok = ArchReservas_crear();
        if (ok == false) {
            arch.close();
            return;
        }
    }
    arch.close();
    arch.open(fileReservas,  ios::app);
    if (arch.is_open()) {
        arch <<endl<< nuevo.cliente.idCliente << coma << nuevo.clase.idClase<<coma<<nuevo.f_reserva.dia<<'-'<<nuevo.f_reserva.mes<<'-'<<nuevo.f_reserva.anio;
    }
    arch.close();



    return;
}
bool ArchReservas_crear() {

    fstream arch;
    arch.open(fileReservas, ios::out);

    if (arch.is_open()) {
        arch << "idCliente, idClase, Fecha" ;
        return true;
    }
    else { return false; }
}
int TamanioArchReservas() {


    fstream arch;
    arch.open(fileReservas, ios::in);

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
void ImpReservas() {
    //imprimo clases
    string coma = " , ";
    reservas* p = ArchReservas_leer();
    int tam = TamanioArchReservas();
    int i = 0;
    cout << "idCliente,idClase,Fecha" << endl;
    while (i < tam) {
        cout << p[i].cliente.idCliente << coma << p[i].clase.idClase << coma<< p[i].f_reserva.dia << '-'<<p[i].f_reserva.mes<<'-'<<p[i].f_reserva.anio << endl;
        i++;
    }
    delete[]p;
    system("pause");
    system("cls");
}
/*void cupoReservas(eClase eclase,clientes* ltclientes,int tamclientes){



    string clase;
    int sala;
    switch(eclase){
    case Spinning:

        cout << "---Spinning---" << endl <<"Seleccione horario disponible:" << endl;
        clase="Spinning";
        sala=bicis;
        break;
    case Yoga:

        cout << "---Yoga---" << endl <<"Seleccione horario disponible:" << endl;
        clase="Yoga";
        sala=siri;
        break;
    case Pilates:

        cout << "---Pilates---" << endl <<"Seleccione horario disponible:" << endl;
        clase="Pilates";
        sala=camillas;
        break;
    case Stretching:

        cout << "---Stretching---" << endl <<"Seleccione horario disponible:" << endl;
        clase="Stretching";
        sala=gim1;
        break;
    case Zumba:

        cout << "---Zumba---" << endl <<"Seleccione horario disponible:" << endl;
        clase="Zumba";
        sala=gim2;
        break;
    case Boxeo:

        cout << "---Boxeo---" << endl <<"Seleccione horario disponible:" << endl;
        clase="Boxeo";
        sala=box;
        break;
    }

    // Obtener la fecha actual
    time_t hoy = time(0);

    // Avanzar al día de mañana
    tm* mañana = localtime(&hoy);
    mañana->tm_mday++; // Incrementar al día siguiente
    mañana->tm_wday++;

    // Imprimir los días de la semana siguiente, excluyendo el domingo
    for (int i = 0; i < 6; ++i) {
    // Ajustar el mes si el día es mayor que los días del mes actual
        if (mañana->tm_mday > 31) { // Suponiendo un máximo de 31 días por mes
            mañana->tm_mday -= 31; // Volver al principio del mes
            mañana->tm_mon++; // Cambiar al próximo mes
        }



        // Imprimir la fecha (formato: día de la semana - día del mes)
        switch (mañana->tm_wday) {
            case 1: cout << "Lunes - "; break;
            case 2: cout << "Martes - "; break;
            case 3: cout << "Miercoles - "; break;
            case 4: cout << "Jueves - "; break;
            case 5: cout << "Viernes - "; break;
            case 6: cout << "Sabado - "; break;
        }
        mañana->tm_wday++;

        cout << mañana->tm_mday << "   |   ";
        if(mañana->tm_wday>6){
            mañana->tm_wday=1;
            mañana->tm_mday++;
        }
        mañana->tm_mday ++;
    }
    cout<<endl;
    string ids[108]; // un maximo de 18 clases al dia x 6 dias, ya que el horario es desde 8 a 19 hs, con la posibilidad de que areguen mas clases
    string hora[108];


    clases* ltclases=ArchClases_leer();
    int tamclases=TamanioArchClases();
    int k=0;
    for(int i =0;i<tamclases;i++){
        if(ltclases[i].clase==clase){
            ids[k]=ltclases[i].idClase;
            hora[k]=ltclases[i].horario;
            k++;
        }
    }


    int contar[k];
    int contador;
    reservas* ltreservas=ArchReservas_leer();
    int tamreservas=TamanioArchReservas();

    for(int j=0;j<k;j++){ //cuenta el total de reservas que hay por codigo de clase
        contador=0;
        for(int i=0;i<tamreservas;i++){
            if(ids[j]==ltreservas[i].clase.idClase){
                contador++;
            }
        }
        contar[j]=contador;
    }

    string guardadoID[108];
    reservas nueva_reserva;

    int j=0;
    for(int i=0;i<k;i++){
        if((sala-contar[i])>0){ //significa que si hay lugar en la sala i
            cout<<j+1<<")"<<hora[i]<<endl;
            guardadoID[j]=ids[i];
            j++;
        }
    }
    cout<<"9)Salir."<<endl;
    int opcion;
    if(j!=0){
        cout<<"Eleccion:";cin>>opcion;
        do{
            if((opcion<1 || opcion>j) && opcion!=9){
                system("cls");
                j=0;
                cout<<"Intente nuevamente"<<endl;
                for(int i=0;i<k;i++){
                    if((sala-contar[i])>0){ //significa que si hay lugar en la sala i
                        cout<<j+1<<")"<<hora[i]<<endl;
                        j++;
                    }
                }
                cout<<"9)Salir."<<endl;
                cout<<"Eleccion:";cin>>opcion;
            }
        }while((opcion<1 || opcion>j) && opcion!=9);
        if(opcion!=9){
            //cout<<"prueba:"<<guardadoID[opcion]<<endl;
            opcion--;
            nueva_reserva.clase.idClase=guardadoID[opcion];
            system("cls");



            string idcliente= buscarIdCliente(ltclientes,tamclientes);
            if(idcliente == " "){
                return;
            }
            nueva_reserva.cliente.idCliente=idcliente;
            ArchReservas_agregar(nueva_reserva);
            cout<<"Se guardo con exito."<<endl;
            system("pause");
            system("cls");
        }
    }else{//si no encuntra ninguna clase con por lo menos 1 lugar
        system("cls");
        cout<<"No hay horarios disponibles."<<endl;
        system("pause");
        system("cls");
    }
    system("cls");
}
*/
void cupoReservas(eClase eclase,clientes* ltclientes,int tamclientes){



    string clase;
    int sala;
    switch(eclase){
    case Spinning:

        cout << "---Spinning---" << endl <<"Seleccione horario disponible:" << endl;
        clase="Spinning";
        sala=bicis;
        break;
    case Yoga:

        cout << "---Yoga---" << endl <<"Seleccione horario disponible:" << endl;
        clase="Yoga";
        sala=siri;
        break;
    case Pilates:

        cout << "---Pilates---" << endl <<"Seleccione horario disponible:" << endl;
        clase="Pilates";
        sala=camillas;
        break;
    case Stretching:

        cout << "---Stretching---" << endl <<"Seleccione horario disponible:" << endl;
        clase="Stretching";
        sala=gim1;
        break;
    case Zumba:

        cout << "---Zumba---" << endl <<"Seleccione horario disponible:" << endl;
        clase="Zumba";
        sala=gim2;
        break;
    case Boxeo:

        cout << "---Boxeo---" << endl <<"Seleccione horario disponible:" << endl;
        clase="Boxeo";
        sala=box;
        break;
    }

    ImpSemana();

    time_t hoy = time(0);

    // Avanzar al día de mañana
    tm* mañana = localtime(&hoy);

string ids[18]; // un maximo de 18 clases al dia x 6 dias, ya que el horario es desde 8 a 19 hs, con la posibilidad de que areguen mas clases
string hora[18];
fecha dia[6];

clases* ltclases=ArchClases_leer();
int tamclases=TamanioArchClases();
int k=0;


for(int i =0;i<tamclases;i++){
        if(ltclases[i].clase==clase){
            ids[k]=ltclases[i].idClase;
            hora[k]=ltclases[i].horario;
            k++;
        }
}
mañana = localtime(&hoy);
         mañana->tm_mon++;
         if(mañana->tm_mon>12){
         mañana->tm_mon=1;
      mañana->tm_year++;
}
mañana->tm_mday++;
if(mañana->tm_mday>31){
mañana->tm_mday=1;
mañana->tm_mon++;
             if(mañana->tm_mon>12){
             mañana->tm_mon=1;
mañana->tm_year++;
}
}



int contar[6][k];
int contador;
reservas* ltreservas=ArchReservas_leer();
int tamreservas=TamanioArchReservas();


for(int d=0;d<6;d++){
    for(int j=0;j<k;j++){ //cuenta el total de reservas que hay por codigo de clase en ese mismo dia
        contador=0;
        for(int i=0;i<tamreservas;i++){
            int anio=mañana->tm_year+1900;
            if(ids[j]==ltreservas[i].clase.idClase && to_string(mañana->tm_mday)==ltreservas[i].f_reserva.dia && to_string(mañana->tm_mon)==ltreservas[i].f_reserva.mes && to_string(anio)==ltreservas[i].f_reserva.anio){
                contador++;
            }
        }
        contar[d][j]=contador;
    }
    mañana->tm_mday++;
        mañana->tm_wday++;
        if(mañana->tm_wday>6){
        mañana->tm_wday=1;
        mañana->tm_mday++;
}
        if(mañana->tm_mday>31){
        mañana->tm_mday=1;
          mañana->tm_mon++;
          if(mañana->tm_mon>12){
          mañana->tm_mon=1;
          mañana->tm_year++;
}
}
}


string guardadoID[108];//18 clases max x diax6
string guardadoDia[108];
fecha guardadoFecha[108];
reservas nueva_reserva;

mañana = localtime(&hoy);
         mañana->tm_mon++;
         mañana->tm_mday++;
         if(mañana->tm_mday>31){
         mañana->tm_mday=1;
      mañana->tm_mon++;
      if(mañana->tm_mon>12){
      mañana->tm_mon=1;
      mañana->tm_year++;
}
}
         if(mañana->tm_mon>12){
mañana->tm_mon=1;
                 mañana->tm_year++;
}
        // mañana->tm_mday++;
        mañana->tm_wday++;
int j=1;
for(int i=0;i<k;i++){

    for(int d=0;d<6;d++){
        if((sala-contar[d][i])>0){ //significa que si hay lugar en la sala i dia d
            cout<<j<<")"<<hora[i]<<"hs.";
            if(j==1 || clase=="Pilates"){
                cout<<"   ";
            }cout<<" \t|";

            guardadoFecha[j].mes=to_string(mañana->tm_mon);
            guardadoFecha[j].anio=to_string(mañana->tm_year+1900);
            guardadoID[j]=ids[i];
            guardadoDia[j]=to_string(d);
            guardadoFecha[j].dia=to_string(mañana->tm_mday);
            mañana->tm_wday++;
            mañana->tm_mday++;
                if(mañana->tm_wday>=6){
                mañana->tm_wday=1;
                mañana->tm_mday++;
                }
            if(mañana->tm_mday>31){
                mañana->tm_mday=1;
                mañana->tm_mon++;
                if(mañana->tm_mon>12){
                    mañana->tm_mon=1;
                    mañana->tm_year++;
                }
            }

            j++;
            if(d==5){
                cout<<endl;
            }
        }else{
            if(d==5){
                cout<<endl;
            }else{cout<<"\t\t|";}
        }
    }
    mañana = localtime(&hoy);
             mañana->tm_mon++;
    mañana->tm_mday++;
    if(mañana->tm_mday>31){
        mañana->tm_mday=1;
        mañana->tm_mon++;
        if(mañana->tm_mon>12){
            mañana->tm_mon=1;
            mañana->tm_year++;
        }
    }
    if(mañana->tm_mon>12){
        mañana->tm_mon=1;
                         mañana->tm_year++;
}
}

cout<<"99)Salir."<<endl;
int opcion;
if(j!=0){
    cout<<"Eleccion:";cin>>opcion;
    do{
        if((opcion<1 || opcion>j) && opcion!=99){
            system("cls");

            cout<<"Intente nuevamente"<<endl;
            ImpSemana();
            j=1;
            for(int i=0;i<k;i++){

                for(int d=0;d<6;d++){
                    if((sala-contar[d][i])>0){ //significa que si hay lugar en la sala i dia d
                        cout<<j<<")"<<hora[i]<<"hs.";
                        if(j==1){
                            cout<<"   ";
                        }cout<<" \t|";

                        guardadoFecha[j].mes=to_string(mañana->tm_mon);
                        guardadoFecha[j].anio=to_string(mañana->tm_year+1900);
                        guardadoID[j]=ids[i];
                        guardadoDia[j]=to_string(d);
                        guardadoFecha[j].dia=to_string(mañana->tm_mday);
                                               mañana->tm_wday++;
                                               mañana->tm_mday++;
                                               if(mañana->tm_wday>=6){//salteo el domingo
                                               mañana->tm_wday=1;
                              mañana->tm_mday++;
                    }
                    if(mañana->tm_mday>31){
                        mañana->tm_mday=1;
                                          mañana->tm_mon++;
                                          if(mañana->tm_mon>12){
                                          mañana->tm_mon=1;
                              mañana->tm_year++;
                }
            }

            j++;
            if(d==5){
                cout<<endl;
            }
        }else{
            if(d==5){
                cout<<endl;
            }else{cout<<"\t\t|";}
        }
    }
    mañana = localtime(&hoy);
             mañana->tm_mon++;
             mañana->tm_mday++;
             if(mañana->tm_mday>31){
             mañana->tm_mday=1;
          mañana->tm_mon++;
          if(mañana->tm_mon>12){
          mañana->tm_mon=1;
          mañana->tm_year++;
}
}
if(mañana->tm_mon>12){
mañana->tm_mon=1;
                 mañana->tm_year++;
}
}
            cout<<"99)Salir."<<endl;
            cout<<"Eleccion:";cin>>opcion;
        }
    }while((opcion<1 || opcion>j) && opcion!=99);
    if(opcion!=99){

        //opcion--;
        nueva_reserva.clase.idClase=guardadoID[opcion];
        nueva_reserva.f_reserva.dia=guardadoFecha[opcion].dia;
        nueva_reserva.f_reserva.mes=guardadoFecha[opcion].mes;
        nueva_reserva.f_reserva.anio=guardadoFecha[opcion].anio;
        system("cls");
        string idcliente= buscarIdCliente(ltclientes,tamclientes);
        if(idcliente == " "){
            return;
        }
        nueva_reserva.cliente.idCliente=idcliente;
        ArchReservas_agregar(nueva_reserva);
        cout<<"Se guardo con exito."<<endl;
        system("pause");
        system("cls");
    }
}else{//si no encuntra ninguna clase con por lo menos 1 lugar
    system("cls");
    cout<<"No hay horarios disponibles."<<endl;
    system("pause");
    system("cls");
}
system("cls");
}

void ImpSemana(){
// Obtener la fecha actual
time_t hoy = time(0);

// Avanzar al día de mañana
tm* mañana = localtime(&hoy);
             mañana->tm_mday++; // Incrementar al día siguiente
mañana->tm_wday++;

    // Imprimir los días de la semana siguiente, excluyendo el domingo
    for (int i = 0; i < 6; ++i) {
    // Ajustar el mes si el día es mayor que los días del mes actual
    if (mañana->tm_mday > 31) { // Suponiendo un máximo de 31 días por mes
        mañana->tm_mday -= 31; // Volver al principio del mes
        mañana->tm_mon++; // Cambiar al próximo mes
    }



    // Imprimir la fecha (formato: día de la semana - día del mes)
    switch (mañana->tm_wday) {
    case 1: cout << "Lunes - "; break;
case 2: cout << "Martes - "; break;
case 3: cout << "Miercoles - "; break;
case 4: cout << "Jueves - "; break;
case 5: cout << "Viernes - "; break;
case 6: cout << "Sabado - "; break;
}
mañana->tm_wday++;

    cout << mañana->tm_mday << "  |  ";
                          if(mañana->tm_wday>6){
                          mañana->tm_wday=1;
      mañana->tm_mday++;
}
mañana->tm_mday ++;
}
cout<<endl;

}
