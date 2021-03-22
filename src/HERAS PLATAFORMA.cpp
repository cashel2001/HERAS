/**
  @file HERAS PLATAFIRMA.cpp
  @brief Desarrollo de placa electronica para gobierno de plataforma elevadora de tres paradas.
  @author Cashel2001
  @date 21/03/2021

*/

#include <Arduino.h>
#include "InputOutput.h"
#include "Display.h"


void setup()
{

Serial.begin( 9600 );
Serial.print( "PROBANDO SERIAL" );
iniciodisplay();
controles();


}

void loop()
{

lecturaPulsadoresLlamada();
comprobacionSeguridades();

}
