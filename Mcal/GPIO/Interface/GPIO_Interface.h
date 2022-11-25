#ifndef _GPIO_INTERFACE_H_
#define _GPIO_INTERFACE_H_
#include "Utilities.h"
#include "GPIO_Private.h"

typedef enum{PIN0=0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7} GPIO_PinType;
typedef enum{PORTA=0, PORTB, PORTC, PORTD, PORTE, PORTF} GPIO_PortType;
typedef enum{INPUT,OUTPUT} GPIO_PinDirectionType;
typedef enum{GPIO,PERIPHERAL} GPIO_PinModeType;
typedef enum{PULLUP,PULLDOWN,OPENDRAIN} GPIO_PinInternalAttachType;
typedef enum{DRIVE_2mA=1, DRIVE_4mA=2,DRIVE_8mA=3} GPIO_PinOutputCurrentType;
typedef enum{ANALOG, DIGITAL} GPIO_PinDigitalEnableType;
typedef enum{LOW=0,HIGH=1} GPIO_LevelType;
typedef uint8_t GPIO_PortLevelType;

typedef struct{
	GPIO_PinType pin;
	GPIO_PortType port;
	GPIO_PinDirectionType pindirection;
	GPIO_PinModeType pinmode;
	GPIO_PinInternalAttachType pinres;
	GPIO_PinOutputCurrentType pincurrent;
	GPIO_PinDigitalEnableType digitalen;
} GPIO_ConfigType;

typedef struct{
  uint32_t GPIODATA[256];
	uint32_t GPIODIR;
  uint32_t GPIOIS;
  uint32_t GPIOIBE;
  uint32_t GPIOIEV;
  uint32_t GPIOIM;
  uint32_t GPIORIS;
  uint32_t GPIOMIS;
  uint32_t GPIOICR;
  uint32_t GPIOAFSEL;
  uint32_t RESERVED[55];
  uint32_t GPIODR2R;
  uint32_t GPIODR4R;
  uint32_t GPIODR8R;
  uint32_t GPIOODR;
  uint32_t GPIOPUR;
  uint32_t GPIOPDR;
  uint32_t GPIOSLR;
  uint32_t GPIODEN;
  uint32_t GPIOLOCK;
  uint32_t GPIOCR;
  uint32_t GPIOAMSEL;
  uint32_t GPIOPCTL;
  uint32_t GPIOADCCTL;
  uint32_t GPIODMACTL;
}GPIO_Type;

void GPIO_Init(const GPIO_ConfigType* config);

GPIO_Type* GPIO_GetPort(GPIO_PortType port);

void GPIO_DigitalEnable(GPIO_PinType pin,GPIO_PortType port,GPIO_PinDigitalEnableType digitalen);

GPIO_LevelType GPIO_ReadPin(GPIO_PinType pin, GPIO_PortType port);

void GPIO_WritePin(GPIO_PinType pin,GPIO_PortType port, GPIO_LevelType level);

GPIO_PortLevelType GPIO_ReadPort(GPIO_PortType port);

void GPIO_WritePort(GPIO_PortType port, GPIO_PortLevelType level);

GPIO_LevelType GPIO_TogglePin(GPIO_PinType pin,GPIO_PortType port);



#endif