/*=====[Nombre del modulo]=====================================================
 * Copyright Sebastian Herrrera  <sebaherrera152@gmail.com>
 * All rights reserved.
 * Licencia: Texto de la licencia o al menos el nombre y un link
         (ejemplo: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 1.0.0
 * Fecha de creacion: 2021/01/02
 */
/* Motor utilizado es el PM5555L-048, de cuya hojas de datos se saca que:
 * Numeros de pasos por rotacion es: 48 (7,5°/por paso), esto significa que da una vuelta completa
 * 360° en 48 pasos.
 * ver hoja de datos en carpeta
*/

/*====[Inclusion de su propia cabecera]=====================================*/

#include "steppermotor_l297.h"

/*=====[Inclusiones de dependencias de funciones privadas]===================*/

#include "sapi.h"
//#include <dependencia.h>

/*=====[Macros de definicion de constantes privadas]=========================*/

#define QMC5883L_REG_Y_LSB       0x02
#define MAX_AMOUNT_OF_RGB_LEDS   9

/*=====[Macros estilo funcion privadas]======================================*/

#define rtcConfig rtcInit

/*=====[Definiciones de tipos de datos privados]=============================*/

// Tipo de datos que renombra un tipo basico
typedef uint32_t gpioRegister_t;

// Tipo de datos de puntero a funcion
typedef void (*FuncPtrPrivado_t)(void *);

// Tipo de datos enumerado


// Tipo de datos estructua, union o campo de bits


/*=====[Definiciones de Variables globales publicas externas]================*/

extern int32_t varGlobalExterna;

/*=====[Definiciones de Variables globales publicas]=========================*/

int32_t varGlobalPublica = 0;

/*=====[Definiciones de Variables globales privadas]=========================*/

static int32_t varGlobalPrivada = 0;

/*=====[Prototipos de funciones privadas]====================================*/

static void funPrivada(void);

/*=====[Implementaciones de funciones publicas]==============================*/

void stepperMotorL297Init(steppermotor_l297_t *steppermotor,
		                  uint32_t numerodepasosxvuelta){

	if (numerodepasosxvuelta!=0){
		steppermotor->Numeros_pasosxvuelta=numerodepasosxvuelta;
	    steppermotor->angulo_resolucion=360/(steppermotor->Numeros_pasosxvuelta); //Esto me da la resolucion que en este caso es 360/48=7,5°
	    }
	else {
		printf("El numero de pasos por vuelta no puede ser cero");
		}

//Aqui tambien tendria que ir la funcion del sensor de poscion en cero, o se cuando arranque
//que verfique que el motor se encuentra en cero
}

void stepperMotorL297SetVelocidad(steppermotor_l297_t *steppermotor,steppermotor_l297_velocidad velocidad){
	steppermotor->velocidad=velocidad;

//Aqui iria el cambio del valor en set math para variar la velocidad del clock
	//Este seteo d elas velocidades ira acopañado de cuando se colocque el motor y ver
	//los resultados de los ensayos

	switch (steppermotor->velocidad){
	case velocidad_baja:
		//Chip_TIMER_Reset( SIGNAL_TIMER );
		Chip_TIMER_SetMatch( SIGNAL_TIMER,SIGNAL_MATCH_NUMBER,BAJA);
		break;

	case velocidad_media:
		//Chip_TIMER_Reset( SIGNAL_TIMER );
		Chip_TIMER_SetMatch( SIGNAL_TIMER,SIGNAL_MATCH_NUMBER,MEDIA);
		break;

	case velocidad_alta:
		//Chip_TIMER_Reset( SIGNAL_TIMER );
		Chip_TIMER_SetMatch( SIGNAL_TIMER,SIGNAL_MATCH_NUMBER,ALTA);
		break;

	default:
		Chip_TIMER_SetMatch( SIGNAL_TIMER,SIGNAL_MATCH_NUMBER,BAJA);
		break;
	}
}

/*=====[Implementaciones de funciones de interrupcion publicas]==============*/

void UART0_IRQHandler(void)
{
   // ...
}

/*=====[Implementaciones de funciones privadas]==============================*/

static void funPrivada(void)
{
   // ...
}

