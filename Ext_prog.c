/*
 * Ext_prog.c
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

#include "delay_config.h"
#include "delay_interface.h"
#include "delay_private.h"

#include "Ext_config.h"
#include "Ext_interface.h"
#include "Ext_private.h"

void Set_ExtInterrupt (u8 Interrupt_Pin ,u8 Interrupt_Control) //Interrupt_Pin (INT0,INT1 or INT2)
																		                                    //Interrupt_Control choose the mode of interrupt
																		                                   //(Level Triggered or Edge Triggered)
{
	switch (Interrupt_Pin)
	{
		case INT0:
			{
				GICR|=0x40; //GICR|=(1<<INT0);  PIE
				MCUCR|=Interrupt_Control;
				GIFR=0x40; //gobal interrupt
			}break;
		/*case INT1:
			{
				GICR|=0x80; //GICR|=(1<<INT1);
				MCUCR|=Interrupt_Control;
			}break;
		case INT2:
			{
				GICR|=0x20; //GICR|=(1<<INT2);
				MCUCSR=Interrupt_Control;
			}break;*/
	}

}

////////////////////////
extern void EOINT_u8EnableInt()
{

	#if EOINT_INT0_ONOROFF==EOINT_ENABLE
	AssignReg(GICR,INT0_Enable);
		#if  EOINT_INT0_u8SENSE_CONTROL== EOINT_LOW_LEVEL
	AssignReg(MCUCR,INT0_LOW_LEVEL);
		#elif  EOINT_INT0_u8SENSE_CONTROL== EOINT_LOGICAL_CHANGE
	AssignReg(MCUCR,INT0_LOGICAL_CHANGE);
		#elif EOINT_INT0_u8SENSE_CONTROL== EOINT_FALLING_EDGE
	AssignReg(MCUCR,INT0_FALLING_EDGE);
		#elif EOINT_INT0_u8SENSE_CONTROL== EOINT_RISING_EDGE
	AssignReg(MCUCR,INT0_RISING_EDGE);
		#else
		#endif
	#elif EOINT_INT1_ONOROFF==EOINT_ENABLE
	AssignReg(GICR,INT1_Enable);
		#if  EOINT_INT1_u8SENSE_CONTROL== EOINT_LOW_LEVEL
	AssignReg(MCUCR,INT1_LOW_LEVEL);
		#elif  EOINT_INT1_u8SENSE_CONTROL== INT0_LOGICAL_CHANGE
	AssignReg(MCUCR,INT1_LOGICAL_CHANGE);
		#elif EOINT_INT1_u8SENSE_CONTROL== EOINT_FALLING_EDGE
	AssignReg(MCUCR,INT1_FALLING_EDGE);
		#elif EOINT_INT1_u8SENSE_CONTROL== EOINT_RISING_EDGE
	AssignReg(MCUCR,INT1_RISING_EDGE);
		#else
		#endif
	#elif EOINT_INT2_ONOROFF==EOINT_ENABLE
	AssignReg(GICR,INT2_Enable);
		#if EOINT_INT2_u8SENSE_CONTROL== EOINT_FALLING_EDGE
	AssignReg(MCUCSR,INT2_FALLING_EDGE);
		#elif EOINT_INT2_u8SENSE_CONTROL== EOINT_RISING_EDGE
	AssignReg(MCUCSR,INT2_RISING_EDGE);
		#else
		#endif
	#else
	#endif


}

