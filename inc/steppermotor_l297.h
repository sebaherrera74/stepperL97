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
   GPIO_INPUT, 
   GPIO_OUTPUT
} gpioMode_t;

typedef enum {

} hmc5883lRegisters_t;

// Tipo de datos estructurados, union o campo de bits
typedef struct {

	gpioMap_t half_full_step;
	gpioMap_t reset;
	gpioMap_t direccion;
	gpioMap_t enable;
	gpioMap_t control;

} steppermotor_l297_t;


/*=====[Prototipos de funciones publicas]====================================*/

bool_t rtcInit( rtc_t* rtc );

/*=====[Prototipos de funciones publicas de interrupcion]====================*/

void UART0_IRQHandler(void);

/*=====[C++ fin]=============================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Evitar inclusion multiple fin]=======================================*/

#endif /* _MODULE_NAME_H_ */
