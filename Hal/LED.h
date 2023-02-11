#ifndef _LED_H_
#define _LED_H_

#include "Utilities.h"
#include "GPIO_Interface.h"
typedef enum{OFF=0,ON=1}LED_LevelType;
void LED_Toggle(GPIO_PortType port,GPIO_PinType pin, LED_LevelType level);

uint8_t LED_Check(GPIO_PortType port,GPIO_PinType pin);
	
#endif