/* 
display en paralelo 8 bits

los pines del diplay son

DigitalOut displayD0( D0 );
DigitalOut displayD1( D1 );
DigitalOut displayD2( D2 );
DigitalOut displayD3( D3 );
DigitalOut displayD4( D4 );
DigitalOut displayD5( D5 );
DigitalOut displayD6( D6 );
DigitalOut displayD7( D7 );
DigitalOut displayRs( D8 );
DigitalOut displayEn( D9 );


el tipo de dato display_t tiene el tipo de conexion displayConnection_t
en este caso DISPLAY_CONNECTION_GPIO_8BITS,


void displayInit( displayConnection_t connection );
es llamada por void userInterfaceInit(), llamada por smartHomeSystemInit();

void displayCharPositionWrite( uint8_t charPositionX, uint8_t charPositionY );
es llamada por  void userInterfaceDisplayInit() antes de usar displayStringWrite()

void displayStringWrite( const char * str );
es llamada por void userInterfaceDisplayInit para escribir la temperatura
                                                 y las palabras a mostrar

privadas 
static void displayPinWrite( uint8_t pinName, int value );
es llamada por void displayCodeWrite()
               void displayDataBusWrite( 

static void displayDataBusWrite( uint8_t dataByte );


static void displayCodeWrite( bool type, uint8_t dataBus );
es llamada por void displayInit() para configurar
               void displayCharPositionWrite para poder escribir parametrizando la coordenada
               void displayStringWrite(const char * str) para escirbir instrucciones y caracteres




por otro lado en user_interfaz
static void userInterfaceDisplayUpdate()
llama a displayCharPositionWrite() y a displayStringWrite( );
para actualizar los valores cuando cambian


para esta conexion no se necesita usar lock()

importante
modificamos la funcion displaystringwrite (display.cpp) para que mande por consola lo mismo que en display
para eso ademas hicimos #include "pc_serial_com.h"

*/

//=====[Libraries]=============================================================

#include "smart_home_system.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    smartHomeSystemInit();
    while (true) {
        smartHomeSystemUpdate();
    }
}