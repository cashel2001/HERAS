/**
  @file Display.h
  @brief Defincion de pines de entrada / salidas.
  @author Cashel2001
  @date 21/03/2021

*/

#ifndef InputOutput
#define InputOutput   

#include "Arduino.h"

#define PINPULSADOR1    2  // Pulsador planta 1(INPUT)
#define PINPULSADOR2    3   // Pulsador planta 2 (INPUT)
#define PINPULSADOR3    4   // Pulsador planta 3 (INPUT)
#define PINPARO1        12  // Sensor paro en planta 1(INPUT)
#define PINPARO2        11  // Sensor paro en planta 2 (INPUT)
#define PINPARO3        10  // Sensor paro en planta 3 (INPUT)
#define PINSEGURIDADES  9   // Señal correspondientes a todas las seguridades cerradas(INPUT)
#define PINUP           16  // Pulsador UP (INPUT)
#define PINDOWN         15  // Pulsador DOWN (INPUT)
#define PINENTER        14  // Pulsador ENTER (INPUT) 
#define PINATRAS        17  // Pulsador ATRAS (INPUT)

#define PINRELESUBIR    8   // Rele de mando subir (OUTPUT)
#define PINRELEBAJAR    7   // Rele de mando bajar (OUTPUT)
#define PINCERRADURA1   6   // Señal de cerradura1 (OUTPUT)
#define PINCERRADURA2   5   // Señal de cerradura2 (OUTPUT)
#define PINCERRADURA3   13  // Señal de cerradura3 (OUTPUT)

enum ESTADOS_PLATAFORMA{ //enumeramos todos los estados posibles de la plataforma
  estadoIndeterminado,
  nivelPlanta1, 
  destinoSubiendoP2,
  nivelPlanta2,
  destinoBajandoP1,
  destinoSubiendoP3,
  nivelPlanta3,
  destinoBajandoP2,
  averia,
  };

  enum CONTADORES_SENALES_ENTRADA{ //enumeramos todas las señales de entradas posibles
  senalLlamada1,
  senalLlamada2, 
  senalLlamada3,
  senalParo1,
  senalParo2,
  senalParo3,
  senalSeguridades,
  senalBotonUp,
  senalBotonDown,
  senalBotonEnter,
  senalBotonAtras
  };

boolean estadosInputs[12] = {false, false, false, false, false, false, false, false, false,false,false,false}; //array que me guarda los estados de las diferentes entradas
byte contadores[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0}; //array de contadores para evitar rebotes en los pulsadores; pulsador1,pulsador2,pulsador3,paro1,paro2,paro2

const unsigned long parametroTiempoReenvio = 3000;
const unsigned long parametroTiempoLLamadaNoPermitida = 5000; // tiempo para dejar salir a la persona del ascensor


/** \fn void controles();
 * \brief Definimos las entradas y salidas del arduino
 */
void controles(); 

/** \fn void lectura();
 * \brief Lectura de las señales de entrada de la placa, lee las entradas y si el contador es superior a "x" --> true
 * @param pulsador indica el pin de entrada de señal
 * @param posicion indica la posicion donde se guarda el estado de la señal dentro del array de "contadores"
 */
void lectura( int pulsador, int posicion );


/** \fn void ComprobacionSeguridades();
 * \brief Comprobacion de la linea de seguridades activa
 */
void comprobacionSeguridades();

/** \fn void lecturaPulsadoresLlamada();
 * \brief Funcion que lee si los pulsadores de llamada de la plataforma estan activos o no. 
 */
void lecturaPulsadoresLlamada();



#endif 


