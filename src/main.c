/*=====[Nombre del programa]===================================================
 * Copyright YYYY Nombre completo del autor <author@mail.com>
 * All rights reserved.
 * Licencia: Texto de la licencia o al menos el nombre y un link
         (ejemplo: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.0.0
 * Fecha de creacion: YYYY/MM/DD
 */

/*Objetivo

 */


/*=====[Inclusiones de dependencias de funciones]============================*/

#include "steppermotor_l297.h"
#include "sapi.h"

/*=====[Macros de definición de constantes privadas]=========================*/


/*=====[Definiciones de variables globales externas]=========================*/


/*=====[Definiciones de variables globales publicas]=========================*/
uint32_t cantidadPasos=960;

/*=====[Definiciones de variables globales privadas]=========================*/



/*=====[Funcion principal, punto de entrada al programa luego de encender]===*/
int main( void )
{

   // ----- Setup -----------------------------------
   boardInit();


   // ----- Repeat for ever -------------------------
   while( true ) {


	   delay(250);
	   gpioToggle(LED1);

   }



   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the
   // case of a PC program.
   return 0;
}























