/*
 * Ext_config.h
 *
 *  Created on: ???/???/????
 *      Author: Ismailia Laptop
 */
#include "Ext_private.h"
#ifndef EXT_CONFIG_H_
#define EXT_CONFIG_H_

/*Comment!: when does interrupt happen ?*/
#define EOINT_INT0_u8SENSE_CONTROL				EOINT_FALLING_EDGE
#define EOINT_INT1_u8SENSE_CONTROL				EOINT_FALLING_EDGE
#define EOINT_INT2_u8SENSE_CONTROL				EOINT_FALLING_EDGE

/*Comment!: who cause the interrupt?*/
#define EOINT_INT0_ONOROFF						EOINT_ENABLE
#define EOINT_INT1_ONOROFF						EOINT_DISABLE
#define EOINT_INT2_ONOROFF						EOINT_DISABLE

#define INT0   1

#endif /* EXT_CONFIG_H_ */
