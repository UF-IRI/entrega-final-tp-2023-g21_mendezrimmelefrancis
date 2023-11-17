#include "reservas.h"

int main(){
    int opcion;
    int subopcionclases;
    int subopcionmusculacion;
    int subopcionclientes;
    int subopcioncupo;

    int tamltclases = TamanioArchClases();
    int tamltclientes = TamanioArchClientes();

    string idnuevocliente = to_string(tamltclientes+1);
    //clases* ltclases = new clases[tamltclases];
    clientes* ltclientes=ArchClientes_leer();
    clientes nuevo_cliente ={idnuevocliente,"facundo","rimmele","facurimmele@gmail.com","2995808204","6","9","2000","0"};

    do{
        opcion = 0;
        subopcionclases = 0;
        subopcionmusculacion = 0;



        while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 9){
            cout << "------Gimnacio Musculito------" << endl;
            //cout << "1)Musculacion." << endl;
            cout << "1)Clases." << endl;
            cout << "2)Clientes." << endl;
            cout << "9)Cerrar" << endl;
            cout << "Eleccion:";
            cin >> opcion;
            system("cls");
            if(opcion != 1 && opcion != 2 /*&& opcion != 3*/ && opcion != 9){
                cout<<"-> Intente nuevamente"<<endl;
            }
        }


        switch (opcion){
        /*case Musculacion:
            do{
                //opcion = 0;
                while(subopcionmusculacion != 1 && subopcionmusculacion != 2 && subopcionmusculacion != 9){
                    cout << "------Musculacion------" << endl;
                    cout << "1)Validar existecia de plan." << endl;
                    cout << "2)Agregar nuevo plan." << endl;
                    cout << "9)Salir de musculacion." << endl;
                    cin >> subopcionmusculacion;
                    system("cls");
                    if(subopcionmusculacion != 1 && subopcionmusculacion != 2 && subopcionmusculacion != 9){
                        cout<<"-> Intente nuevamente"<<endl;
                    }
                }

                switch(subopcionmusculacion){
                case Validar:
                    subopcionmusculacion=0;
                    cout << "------Validacion------" << endl;

                    break;
                case Agregar:
                    subopcionmusculacion=0;

                    system("cls");
                    break;
                default:
                    break;
                }
            }while(subopcionmusculacion != 9);

            break;*/
        //case Clases:
        case 1:
            //obtenerFechaActual(fechactual);
            do{
                subopcionclases=0;
                while ((subopcionclases < 1 || subopcionclases > 2) && subopcionclases != 9){
                    cout << "--------Clases--------" << endl;
                    cout << "1)Cupos disponibles." << endl;
                    cout << "2)Agregar nueva clase." << endl;
                    cout << "9)Salir de clases." << endl;
                    cout << "Eleccion: ";
                    cin >> subopcionclases;
                    system("cls");
                    if((subopcionclases<1 || subopcionclases>2) && subopcionclases!=9){
                        cout<<"-> Intente nuevamente"<<endl;
                    }
                }



                switch(subopcionclases){
                case 1://leer lt
                    do{
                        subopcioncupo=0;
                        while ((subopcioncupo < 1 || subopcioncupo > 6) && subopcioncupo != 9){
                            cout << "--------Clases--------" << endl;
                            cout << "1)Spinning." << endl;
                            cout << "2)Yoga." << endl;
                            cout << "3)Pilates." << endl;
                            cout << "4)Stretching." << endl;
                            cout << "5)Zumba." << endl;
                            cout << "6)Boxeo." << endl;
                            cout << "9)Salir de clases." << endl;
                            cout << "Eleccion: ";
                            cin >> subopcioncupo;
                            system("cls");
                            if((subopcioncupo<1 || subopcioncupo>6) && subopcioncupo!=9){
                                cout<<"-> Intente nuevamente"<<endl;
                            }
                        }



                        switch(subopcioncupo){
                        case Spinning://leer lt
                            cupoReservas(Spinning,ltclientes,tamltclientes); //imprime los cupos de la clase y guarda la reserva o en caso contrario "no hay cupo"
                            break;
                        case Yoga:
                            cupoReservas(Yoga,ltclientes,tamltclientes); //imprime los cupos de la clase y guarda la reserva o en caso contrario "no hay cupo"
                            break;
                        case Pilates:
                            cupoReservas(Pilates,ltclientes,tamltclientes); //imprime los cupos de la clase y guarda la reserva o en caso contrario "no hay cupo"
                            break;
                        case Stretching:
                            cupoReservas(Stretching,ltclientes,tamltclientes); //imprime los cupos de la clase y guarda la reserva o en caso contrario "no hay cupo"
                            break;
                        case Zumba:
                            cupoReservas(Zumba,ltclientes,tamltclientes); //imprime los cupos de la clase y guarda la reserva o en caso contrario "no hay cupo"
                            break;
                        case Boxeo:
                            cupoReservas(Boxeo,ltclientes,tamltclientes); //imprime los cupos de la clase y guarda la reserva o en caso contrario "no hay cupo"
                            break;
                        default:
                            break;
                        }
                    }while(subopcioncupo != 9);

                    break;

                case 2:
                    clases nueva_clase{"100","Crossfit","22.22"};

                    ArchClases_agregar(nueva_clase);
                    cout<<"Guardado correctamente";
                    system("pause");
                    break;   
                }
            }while(subopcionclases != 9);

            break;
        //case Clientes:
        case 2:
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
                    ImpClientes();
                    break;
                case 2:
                    tamltclientes = TamanioArchClientes();
                    idnuevocliente = to_string(tamltclientes+1);
                    nuevo_cliente={idnuevocliente,"facundo","apellido","facurimmele@gmail.com","2995808204","6","9","2000","0"};
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
