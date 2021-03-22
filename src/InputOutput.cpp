
#include "InputOutput.h"
#include "Arduino.h"

void controles()
{
  pinMode( pulsador1, INPUT );
  pinMode( pulsador2, INPUT );
  pinMode( pulsador3, INPUT );
  pinMode( paro1, INPUT );
  pinMode( paro2, INPUT );
  pinMode( paro3, INPUT );
  pinMode( seguridades, INPUT );
  pinMode( releSubir, OUTPUT );
  pinMode( releBajar, OUTPUT );
  pinMode( cerradura1, OUTPUT );
  pinMode( cerradura2, OUTPUT );
  pinMode( cerradura3, OUTPUT );
  pinMode( up, INPUT );
  pinMode( down, INPUT );
  pinMode( enter, INPUT );
  pinMode( atras, INPUT );
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
lectura ( pulsador1, senalLlamada1 );
lectura ( pulsador2, senalLlamada2 );
lectura ( pulsador3, senalLlamada3 );
}

void comprobacionSeguridades()
{
  boolean flagSeguridadesOK = false;
  lectura( seguridades , senalSeguridades );
    if ( senalSeguridades == true )
    {
      flagSeguridadesOK = true;
    }
}
