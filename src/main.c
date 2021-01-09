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
uint32_t cantidadPasos;

/*=====[Definiciones de variables globales privadas]=========================*/



/*=====[Funcion principal, punto de entrada al programa luego de encender]===*/
int main( void )
{
   steppermotor_l297_half_full  volatile var=0;         //Hay que colocar volatile sino el compilador la optimiza

   // ----- Setup -----------------------------------
   boardInit();
   stepperMotorL297Init(&steppermotor,48,GPIO0,GPIO1,GPIO2,GPIO4);
   stepperMotorL297SetVelocidad(&steppermotor,velocidad_media);

   //Pruebas de sentido de giro
   stepperMotorL297SetDireccionGiro(&steppermotor,sentido_cw); //Pruebo las salidas ,Pone a 3,3 vel Gpio
   stepperMotorL297SetDireccionGiro(&steppermotor,sentido_ccw);//Pone a 0 Volts

   stepperMotorL297SetEnable(&steppermotor,motor_enable);    //Pruebo habilitacion o deshabilitacion Pone 3,3 Volts
   stepperMotorL297SetEnable(&steppermotor,motor_disable );  //Pone 0 v

   stepperMotorL297SetReset(&steppermotor,l297_set);       //Pruebo set o REset, Pone 3,3 Volts
   stepperMotorL297SetReset(&steppermotor,l297_reset);     //Pone a 0 v

   stepperMotorL297SetFullHalf(&steppermotor,l297_half);
   stepperMotorL297SetFullHalf(&steppermotor,l297_full);

   var=stepperMotorL297GetHalfFull(&steppermotor);

   delay(1);

   // ----- Repeat for ever -------------------------
   while( true ) {

	if (!gpioRead(TEC1)){
		stepperMotorL297MoveXNanometers(&steppermotor,400);

	}
	   delay(250);
	   gpioToggle(LED1);

   }



   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the
   // case of a PC program.
   return 0;
}























