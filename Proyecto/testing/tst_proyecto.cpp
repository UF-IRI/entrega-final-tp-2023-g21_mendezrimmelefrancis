#include <catch2/catch.hpp>
#include <musculacion.h>

TEST_CASE("Test Inscripcion correcto")
{
    time_t hoy=time(0);
    asistencias inscripcion={25,1,{{12,hoy}}}; //parametros de reserva correctos

    int tamanio=0;

    bool inscripto=Inscripciones(inscripcion,tamanio);

    REQUIRE(inscripto == true); //debe inscribir con normalidad
}

TEST_CASE("Test Inscripcion incorrecto")
{

    time_t hoy=time(0);
    asistencias inscripcion={-45,1,{{12,hoy}}}; //parametro idcliente incorrecto

    int tamanio=0;

    bool inscripto=Inscripciones(inscripcion,tamanio);

    REQUIRE(inscripto == false); // no debe inscribir
}

TEST_CASE("Test ExisteInscripcionCliente true")
{

    time_t hoy=time(0);
    asistencias inscripcion={1,1,{{1,hoy}}};
    int tamanio=0;
    bool inscripto=Inscripciones(inscripcion,tamanio);//false->no se pudo

    tamanio=TamanioArchAsistencias();

    bool existe=false;
    if(inscripto==true){
     existe=ExisteInscripcionCliente(inscripcion,tamanio);
    }

    REQUIRE(existe == true);//ya existe
}

TEST_CASE("Test ExisteInscripcionCliente false")
{

    time_t hoy=time(0);
    asistencias inscripcion={1,1,{{1,hoy}}};
    asistencias nuevo={1,1,{{2,hoy}}};
    int tamanio=0;
    bool inscripto=Inscripciones(inscripcion,tamanio);//false->no se pudo

    tamanio=TamanioArchAsistencias();

    bool existe=false;
    if(inscripto==true){
     existe=ExisteInscripcionCliente(nuevo,tamanio);
    }

    REQUIRE(existe == false);//no existe o no se pudo
}
