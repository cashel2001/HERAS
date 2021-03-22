
#include "InputOutput.h"
#include "Arduino.h"

void controles()
{
  pinMode( PINPULSADOR1, INPUT );
  pinMode( PINPULSADOR2, INPUT );
  pinMode( PINPULSADOR3, INPUT );
  pinMode( PINPARO1, INPUT );
  pinMode( PINPARO2, INPUT );
  pinMode( PINPARO3, INPUT );
  pinMode( PINSEGURIDADES, INPUT );
  pinMode( PINRELESUBIR, OUTPUT );
  pinMode( PINRELEBAJAR, OUTPUT );
  pinMode( PINCERRADURA1, OUTPUT );
  pinMode( PINCERRADURA2, OUTPUT );
  pinMode( PINCERRADURA3, OUTPUT );
  pinMode( PINUP, INPUT );
  pinMode( PINDOWN, INPUT );
  pinMode( PINENTER, INPUT );
  pinMode( PINATRAS, INPUT );
}



void lectura( int pulsador, int posicion )
{
  if ( digitalRead( pulsador ) == true )
  {
    contadores[posicion] = contadores[posicion] + 1;
    if ( contadores[posicion] > 8 ) // con el valor regulamos el rebote del pulsador
    { 
      estadosInputs[posicion] = true;
      contadores[posicion] = 0;
    }
  }

  else
  {
    contadores[posicion] = 0;
    estadosInputs[posicion] = false;
  }
}

void lecturaPulsadoresLLamada()
{
lectura ( PINPULSADOR1, senalLlamada1 );
lectura ( PINPULSADOR2, senalLlamada2 );
lectura ( PINPULSADOR3, senalLlamada3 );
}

void comprobacionSeguridades()
{
  boolean flagSeguridadesOK = false;
  lectura( PINSEGURIDADES , senalSeguridades );
    if ( senalSeguridades == true )
    {
      flagSeguridadesOK = true;
    }
}
