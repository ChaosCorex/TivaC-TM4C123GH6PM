#include "GPIO_Interface.h"

GPIO_Type* GPIO_GetPort(GPIO_PortType port){
	switch(port){
		case PORTA:
				return (GPIO_Type*)&GPIOA;
			case PORTB:
				return (GPIO_Type*)&GPIOB;
			case PORTC:
				return (GPIO_Type*)&GPIOC;
			case PORTD:
				return (GPIO_Type*)&GPIOD;
			case PORTE:
				return (GPIO_Type*)&GPIOE;
			case PORTF:
				return (GPIO_Type*)&GPIOF;
	}
}

void GPIO_Init(const GPIO_ConfigType* config){
	
	GPIO_Type* PORT = GPIO_GetPort(config->port);
	
	SET_BIT(RCGCGPIO,config->port);
	
	if (config->pindirection == OUTPUT){
				SET_BIT(PORT->GPIODIR,config->pin);
	}
	else if (config->pindirection == INPUT){
		CLR_BIT(PORT->GPIODIR,config->pin);
	}
	
	PORT->GPIOLOCK=0x4C4F434B;
	SET_BIT(PORT->GPIOCR,config->pin);
	
	if(config->digitalen){
		SET_BIT(PORT->GPIODEN, config->pin);
	}
	else{
		CLR_BIT(PORT->GPIODEN, config->pin);
	}
	
	if(config->pinmode==GPIO){
		CLR_BIT(PORT->GPIOAFSEL,config->pin);	
	}
	
	switch(config->pinres){
		case PULLUP:
				SET_BIT(PORT->GPIOPUR,config->pin);	
				break;
			case PULLDOWN:
				SET_BIT(PORT->GPIOPDR,config->pin);	
				break;
			case OPENDRAIN:
				SET_BIT(PORT->GPIOODR,config->pin);
	}
	switch(config->pincurrent){
		case DRIVE_2mA:
				SET_BIT(PORT->GPIODR2R,config->pin);	
				break;
			case DRIVE_4mA:
				SET_BIT(PORT->GPIODR4R,config->pin);	
				break;
			case DRIVE_8mA:
				SET_BIT(PORT->GPIODR8R,config->pin);
	}
	
	CLR_BIT(PORT->GPIOCR,config->pin);
	PORT->GPIOLOCK=0;
}

void GPIO_DigitalEnable(GPIO_PinType pin,GPIO_PortType port,GPIO_PinDigitalEnableType digitalen){
	GPIO_Type* PORT = GPIO_GetPort(port);
	PORT->GPIOLOCK=0x4C4F434B;
	SET_BIT(PORT->GPIOCR,pin);
	if(digitalen){
		SET_BIT(PORT->GPIODEN, pin);
	}
	else{
		CLR_BIT(PORT->GPIODEN, pin);
	}
	CLR_BIT(PORT->GPIOCR,pin);
	PORT->GPIOLOCK=0;
}

GPIO_LevelType GPIO_ReadPin(GPIO_PinType pin, GPIO_PortType port){
	GPIO_Type* PORT = GPIO_GetPort(port);
	if(GET_BIT(PORT->GPIODIR,pin)==0){
		return GET_BIT(PORT->GPIODATA[255],pin);
	}
	return 0;
}

void GPIO_WritePin(GPIO_PinType pin,GPIO_PortType port, GPIO_LevelType level){
	GPIO_Type* PORT = GPIO_GetPort(port);
	if(GET_BIT(PORT->GPIODIR,pin)==1){
		if (level == HIGH){
		SET_BIT(PORT->GPIODATA[255],pin);
		}
		else{
		CLR_BIT(PORT->GPIODATA[255],pin);
		}
	}
}
GPIO_PortLevelType GPIO_ReadPort(GPIO_PortType port){
	GPIO_Type* PORT = GPIO_GetPort(port);
				return PORT->GPIODATA[255]&0x000F;
			
}

void GPIO_WritePort(GPIO_PortType port, GPIO_PortLevelType level){
	GPIO_Type* PORT = GPIO_GetPort(port);
			PORT->GPIODATA[255]=level;
			
}
GPIO_LevelType GPIO_TogglePin(GPIO_PinType pin,GPIO_PortType port){
	GPIO_Type* PORT = GPIO_GetPort(port);
	TOG_BIT(PORT->GPIODATA[255],pin);
	return GET_BIT(PORT->GPIODATA[255],pin);
}
