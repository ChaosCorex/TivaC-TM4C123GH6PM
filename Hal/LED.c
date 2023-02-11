#include "LED.h"

void LED_Toggle(GPIO_PortType port, GPIO_PinType pin, LED_LevelType level){
		GPIO_WritePin(pin, port, (GPIO_LevelType)level);
}

uint8_t LED_Check(GPIO_PortType port,GPIO_PinType pin){
	GPIO_Type* PORT = GPIO_GetPort(port);
	return GET_BIT(PORT->GPIODATA[255],pin);
}