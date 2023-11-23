#include "musculacion.h"

int main(){
    int opcion;
    int subopcionclases;
    int subopcionmusculacion;
    int subopcionclientes;
    int subopcioncupo;

    int tamltclases = TamanioArchClases();
    int tamltclientes = TamanioArchClientes();
    int tamltasistencias = TamanioArchAsistencias();

    bool inscripto;

    string idnuevocliente = to_string(tamltclientes+1);
    //clases* ltclases = new clases[tamltclases];
    clientes* ltclientes=ArchClientes_leer();

    //declaro las variables a agrega nuevas
    clientes nuevo_cliente ={idnuevocliente,"facundo","rimmele","facurimmele@gmail.com","2995808204","6","9","2000","0"};


    do{
        opcion = 0;
        subopcionclases = 0;
        subopcionmusculacion = 0;



        while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 9){
            cout << "------Gimnacio Musculito------" << endl;
            cout << "1)Musculacion." << endl;
            cout << "2)Clases." << endl;
            cout << "3)Clientes." << endl;
            cout << "9)Cerrar" << endl;
            cout << "Eleccion:";
            cin >> opcion;
            system("cls");
            if(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 9){
                cout<<"-> Intente nuevamente"<<endl;
            }
        }


        switch (opcion){
        case Musculacion:
            do{
                //opcion = 0;
                while(subopcionmusculacion != 1 && subopcionmusculacion != 2 && subopcionmusculacion != 9){
                    cout << "------Musculacion------" << endl;
                    cout << "1)Clientes saldo positivo." << endl;
                    cout << "2)Clientes saldo negativo." << endl;
                    cout << "9)Salir de musculacion." << endl;
                    cin >> subopcionmusculacion;
                    system("cls");
                    if(subopcionmusculacion != 1 && subopcionmusculacion != 2 && subopcionmusculacion != 9){
                        cout<<"-> Intente nuevamente"<<endl;
                    }
                }

                switch(subopcionmusculacion){
                case 1:
                    subopcionmusculacion=0;
                    cout << "------Saldo Positivo------" << endl;
                    ImpPositivosMusculacion(ltclientes,tamltclientes);
                    break;
                case 2:
                    subopcionmusculacion=0;
                    cout << "------Saldo Negativo------" << endl;
                    ImpNegativosMusculacion(ltclientes,tamltclientes);
                    system("cls");
                    break;
                default:
                    break;
                }
            }while(subopcionmusculacion != 9);

            break;
        //case Clases:
        case 2:
            //obtenerFechaActual(fechactual);
            do{
                subopcionclases=0;
                while ((subopcionclases < 1 || subopcionclases > 2) && subopcionclases != 9){
                    cout << "--------Clases--------" << endl;
                    cout << "1)Leer inscripciones." << endl;
                    cout << "2)Inscrivirse (es random)."<<endl;
                    cout << "9)Salir de clases." << endl;
                    cout << "Eleccion: ";
                    cin >> subopcionclases;
                    system("cls");
                    if((subopcionclases<1 || subopcionclases>2) && subopcionclases!=9){
                        cout<<"-> Intente nuevamente"<<endl;
                    }
                }

                switch(subopcionclases){

                case 1:
                    Impasistencias(tamltasistencias);
                    break;
                case 2:
                    //nueva_inscripcion=NuevaInscripcionRandom();
                    inscripto=Inscripciones(NuevaInscripcionRandom(),tamltasistencias);
                    tamltasistencias=TamanioArchAsistencias();

                    system("pause");
                    break;
                }


            }while(subopcionclases != 9);

            break;
        //case Clientes:
        case 3:
            do{
                subopcionclientes=0;
                while ((subopcionclientes < 1 || subopcionclientes > 2) && subopcionclientes != 9){
                    cout << "--------Clientes--------" << endl;
                    cout << "1)Leer lista." << endl;
                    cout << "2)Agregar nuevo cliente." << endl;
                    cout << "9)Salir de clientes." << endl;
                    cout << "Eleccion: ";
                    cin >> subopcionclientes;
                    system("cls");
                    if((subopcionclientes<1 || subopcionclientes>2) && subopcionclientes!=9){
                        cout<<"-> Intente nuevamente"<<endl;
                    }
                }



                switch(subopcionclientes){
                case 1://leer lt
                    ImpClientes(ltclientes,tamltclientes);
                    break;
                case 2:
                    tamltclientes = TamanioArchClientes();
                    idnuevocliente = to_string(tamltclientes+1);
                    nuevo_cliente.idCliente=idnuevocliente;
                    ArchClientes_agregar(nuevo_cliente);
                    cout<<"Guardado correctamente";               
                    system("pause");
                    break;
                }
            }while(subopcionclientes != 9);

            break;


        default:
            break;
        }
        if(opcion == 9)
            break;
    }while((opcion != 1 && opcion != 2 && opcion != 3) || subopcionclases == 9 || subopcionmusculacion == 9 || subopcionclientes == 9);

    delete[] ltclientes;
    //delete[] ltclases;
}
