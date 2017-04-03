/*
 * Ext_interface.h
 *
 *  Created on: ???/???/????
 *      Author: Ismailia Laptop
 */

#ifndef EXT_INTERFACE_H_
#define EXT_INTERFACE_H_

/*Comment:! Functions*/
#define void_SET_I_FLAG()				SETBIT(u8SREG,u8SREG_I_Flag)
#define void_CLEAR_I_FLAG()				CLEARBIT(u8SREG,u8SREG_I_Flag)


extern void Set_ExtInterrupt (u8 Interrupt_Pin ,u8 Interrupt_Control); //Interrupt_Pin (INT0,INT1 or INT2)
extern void EOINT_u8EnableInt(void);
#endif /* EXT_INTERFACE_H_ */
