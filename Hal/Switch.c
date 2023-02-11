#include "Switch.h"

uint8_t Switch_Check(GPIO_PortType port,GPIO_PinType pin){
	GPIO_Type* PORT = GPIO_GetPort(port);
	return GET_BIT(PORT->GPIODATA[255],pin);
}
