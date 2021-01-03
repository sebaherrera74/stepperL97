/*=====[Nombre del modulo]=====================================================
 * Sebastian Herrrera <sebaherrera@gmail.com>
 * All rights reserved.
 * Licencia: Texto de la licencia o al menos el nombre y un link
         (ejemplo: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.0.0
 * Fecha de creacion: 2021/01/02
 */

/*=====[Evitar inclusion multiple comienzo]==================================*/

#ifndef _STEPPERMOTOR_L297_H_
#define _STEPPERMOTOR_L297_H_

/*=====[Inclusiones de dependencias de funciones publicas]===================*/

#include "sapi.h"


/*=====[C++ comienzo]========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Macros de definicion de constantes publicas]=========================*/

#define PI 3.14
#define BAJA    204000000
#define MEDIA   1000000
#define ALTA    300000

/*=====[Macros estilo funcion publicas]======================================*/

#define printInt(printer,number) printIntFormat((printer),(number),(DEC_FORMAT))

#define printlnString(printer,string);   {printString((printer),(string));\
                                          printEnter((printer));}

/*=====[Definiciones de tipos de datos publicos]=============================*/

// Tipo de datos que renombra un tipo basico
typedef uint8_t bool_t;

// Tipo de datos de puntero a funcion
typedef void (*callBackFuncPtr_t)(void *);

// Tipo de datos enumerado
typedef enum {
   velocidad_baja,
   velocidad_media,
   velocidad_alta
} steppermotor_l297_velocidad;


// Tipo de datos estructurados, union o campo de bits
typedef struct {

	uint32_t cantidad_pasos;
	uint32_t contador_pasos;
	uint8_t  Numeros_pasosxvuelta;
	float   angulo_resolucion;
	gpioMap_t half_full_step;
	gpioMap_t reset;
	gpioMap_t direccion;           //sentido agujas del reloj Horario (CW) o antihorario (CCW)
	gpioMap_t enable;
	gpioMap_t control;
	steppermotor_l297_velocidad velocidad;
} steppermotor_l297_t;

steppermotor_l297_t  steppermotor;


/*=====[Prototipos de funciones publicas]====================================*/

//Funcion de inicializacion del motor paso a paso a utilizar, se pasa una structura , los numeros de pasos
//por vuelta y el angulo de resolucion
//Tambien esta funcion inicializa el Timer() para generar el clock
//seguir agregando lo que hace el timer

void stepperMotorL297Init(steppermotor_l297_t *steppermotor,uint32_t numerodepasosxvuelta);



/*=====[Prototipos de funciones publicas de interrupcion]====================*/

void UART0_IRQHandler(void);

/*=====[C++ fin]=============================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Evitar inclusion multiple fin]=======================================*/

#endif /* _MODULE_NAME_H_ */
