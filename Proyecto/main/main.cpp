#include "musculacion.h"

int main(){
    int opcion;
    int subopcionclases;
    int subopcionmusculacion;
    int subopcionclientes;

    int tamltclientes;
    int tamltasistencias = TamanioArchAsistencias();

    bool inscripto;

    string idnuevocliente = to_string(TamanioArchClientes()+1);
    clientes* ltclientes;

    //declaro las variables a agrega nuevas
    clientes nuevo_cliente ={idnuevocliente,"facundo","rimmele","frimmele@gmail.com","2995808204","6","9","2000","0"};


    do{
        opcion = 0;
        subopcionclases = 0;
        subopcionmusculacion = 0;



        while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 9){
            cout << "------Gimnasio Musculito------" << endl;
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
                while(subopcionmusculacion != 1 && subopcionmusculacion != 9){
                    cout << "------Musculacion------" << endl;
                    cout << "1)Inscrivirse a musculacion (es random)." << endl;
                    cout << "9)Salir de musculacion." << endl;
                    cin >> subopcionmusculacion;
                    system("cls");
                    if(subopcionmusculacion != 1 && subopcionmusculacion != 9){
                        cout<<"-> Intente nuevamente"<<endl;
                    }
                }

                switch(subopcionmusculacion){
                case 1:
                    subopcionmusculacion=0;
                    inscripto=Inscripciones(NuevaMusculacionRandom(),tamltasistencias);
                    tamltasistencias=TamanioArchAsistencias();
                    break;
                default:
                    break;
                }
            }while(subopcionmusculacion != 9);

            break;
        //case Clases:
        case 2:

            do{
                subopcionclases=0;
                while ((subopcionclases < 1 || subopcionclases > 2) && subopcionclases != 9){
                    cout << "--------Clases--------" << endl;
                    cout << "1)Leer todas las inscripciones." << endl;
                    cout << "2)Inscrivirse a una clase (es random)."<<endl;
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
                while ((subopcionclientes < 1 || subopcionclientes > 4) && subopcionclientes != 9){
                    cout << "--------Clientes--------" << endl;
                    cout << "1)Agregar nuevo cliente." << endl;
                    cout << "-->Leer:" << endl;
                    cout <<"\t2)Todos los clientes."<<endl;
                    cout <<"\t3)Clientes positivos."<<endl;
                    cout <<"\t4)Clientes negativos."<<endl;
                    cout << "9)Salir de clientes." << endl;
                    cout << "Eleccion: ";
                    cin >> subopcionclientes;
                    system("cls");
                    if((subopcionclientes<1 || subopcionclientes>4) && subopcionclientes!=9){
                        cout<<"-> Intente nuevamente"<<endl;
                    }
                }



                switch(subopcionclientes){
                case 1:
                    subopcionclientes=0;
                    tamltclientes = TamanioArchClientes();
                    idnuevocliente = to_string(tamltclientes+1);
                    nuevo_cliente.idCliente=idnuevocliente;
                    ltclientes=ArchClientes_leer();
                    ArchClientes_agregar(nuevo_cliente,tamltclientes);
                    system("pause");

                    break;
                case 2:
                    subopcionclientes=0;
                    ltclientes=ArchClientes_leer();
                    tamltclientes = TamanioArchClientes();
                    ImpClientes(ltclientes,tamltclientes);
                    break;
                case 3:
                    subopcionclientes=0;
                    cout << "------Saldo Positivo------" << endl;
                    ltclientes=ArchClientes_leer();
                    tamltclientes = TamanioArchClientes();
                    ImpPositivos(ltclientes,tamltclientes);
                    break;
                case 4:
                    subopcionclientes=0;
                    cout << "------Saldo Negativo------" << endl;
                    ltclientes=ArchClientes_leer();
                    tamltclientes = TamanioArchClientes();
                    ImpNegativos(ltclientes,tamltclientes);

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
