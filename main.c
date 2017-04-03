/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: Ismailia Laptop
 */
#include "Conc.h"
#include "util.h"
#include "Types.h"

#include "DIO_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"

//#include "delay_config.h"
//#include "delay_interface.h"
//#include "delay_private.h"
#include "TACTILE_config.h"
#include "TACTILE_interface.h"

#include "Ext_config.h"
#include "Ext_interface.h"
#include "Ext_private.h"
#include "util/delay.h"

#define ISR(vector)            \
    void vector (void) __attribute__ ((signal,used,externally_visible)) ; \
    void vector (void)


u8 volatile count=0;

u8 volatile x=0;

ISR(__vector_1 )
{

	count++;
	DIO_u8WritePortVal(2,count);

	if(count>10)
		{

		x=!x;

		DIO_u8WritePinVal( DIO_u8PIN1,x);
count=0;
		}

}

int main(void)
{
	u8 Local_u8SwState=0;
	   DIO_voidInit();

	  //EOINT_u8EnableInt();
	  __asm__("SEI");

	  Set_ExtInterrupt(INT0,EOINT_INT0_u8SENSE_CONTROL);
	while(1)
	{
		DIO_u8WritePinVal( DIO_u8PIN2,0);
		_delay_ms(250);
		DIO_u8WritePinVal( DIO_u8PIN2,1);
		_delay_ms(250);


		//TACTILE_u8GetState(TACTILE_u8Switch27,&Local_u8SwState);
		//Set_ExtInterrupt(INT0,RISING_EDGE_0);


	}
return 0;
}
