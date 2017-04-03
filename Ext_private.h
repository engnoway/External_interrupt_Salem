/*
 * Ext_private.h
 *
 *  Created on: ???/???/????
 *      Author: Ismailia Laptop
 */

#ifndef EXT_PRIVATE_H_
#define EXT_PRIVATE_H_
/////registers
#define GICR 								 *((volatile u8*)(0x5B))
#define MCUCR 								 *((volatile u8*)(0x55))
#define MCUCSR 								 *((volatile u8*)(0x54))
#define GIFR   								 *((volatile u8*)(0x5A))
//status register
#define u8SREG								*( (volatile u8*)(0x5F) ))
/*Comment!: ISR address*/
#define EOINT_ISR_u16INT0					(**( (volatile u16*)(0x0002) ))
#define EOINT_ISR_u16INT1					(**( (volatile u16*)(0x0004) ))
#define EOINT_ISR_u16INT2					(**( (volatile u16*)(0x0006) ))
/*Comment!: I-flag in SREG Register num 7 */
#define u8SREG_I_Flag						7

/*Comment!: MCUCR Reg bins*/
#define EOINT_MCUCR_ISC00					0
#define EOINT_MCUCR_ISC01					1
#define EOINT_MCUCR_ISC10					2
#define EOINT_MCUCR_ISC11					3

/*Comment!: MCUCSR Reg bins*/
#define EOINT_MCUCSR_ISC2					6

/*Comment!: GICR Reg bins*/
#define EOINT_GICR_INT2						5
#define EOINT_GICR_INT0						6
#define EOINT_GICR_INT1						7

/*Comment!: GIFR Reg bins*/
#define EOINT_GICR_INTF2					5
#define EOINT_GICR_INTF0					6
#define EOINT_GICR_INTF1					7

/************************************************************************************/
/*Comment!: ISC00,01 states*/
#define INT0_LOW_LEVEL						0x00
#define INT0_LOGICAL_CHANGE					0x01
#define INT0_FALLING_EDGE					0x02
#define INT0_RISING_EDGE					0x03

/*Comment!: ISC10,11 states*/
#define INT1_LOW_LEVEL						0x00
#define INT1_LOGICAL_CHANGE					0x04
#define INT1_FALLING_EDGE					0x08
#define INT1_RISING_EDGE					0x0C

/*Comment!: ISC2 states*/
#define INT2_FALLING_EDGE					0x00
#define INT2_RISING_EDGE					0x40

/*Comment!: Enable Interrupt*/
#define INT0_Enable							0x40
#define INT1_Enable							0x80
#define INT2_Enable							0x20


/*Comment!: ISC00,01 states*/
#define EOINT_LOW_LEVEL						0
#define EOINT_LOGICAL_CHANGE			    1
#define EOINT_FALLING_EDGE					2
#define EOINT_RISING_EDGE					3
/*Comment!:General Definition*/
#define EOINT_ENABLE						1
#define EOINT_DISABLE						0
#endif /* EXT_PRIVATE_H_ */
