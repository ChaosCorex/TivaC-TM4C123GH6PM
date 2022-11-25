#include "..\Mcal\GPIO\Interface\GPIO_Interface.h"
#include "..\Mcal\NVIC\Interface\NVIC_Interface.h"
#include "..\Mcal\Timer\Interface\GPT_Interface.h"
#include "..\Mcal\Systick\Interface\SYST_Interface.h"
#include "..\Hal\LED.h"
#include "..\Hal\Switch.h"

/*Interrupt Handlers Prototypes*/
void SysTick_Handler(void);

/*Global Variables*/
static volatile uint32_t on_time;
static volatile uint32_t off_time;

/*Main*/
int main(void){
	
	on_time=2500;
	off_time=2500;
	
	GPIO_ConfigType* GPIO_config;
	GPIO_config->pin=PIN1;
	GPIO_config->pincurrent=DRIVE_2mA;
	GPIO_config->pindirection=OUTPUT;
	GPIO_config->pinmode=GPIO;
	GPIO_config->pinres=PULLDOWN;
	GPIO_config->port=PORTF;
	GPIO_config->digitalen=DIGITAL;
  GPIO_Init(GPIO_config);
	
	SYST_ConfigType* SYST_config;
	SYST_config->interrupten=ENABLE;
	SYST_config->clocksource=SYSTEM_CLOCK;
	SYST_config->reloadvalue=F_CPU/1000; // = 1 msec delay
	SYST_Init(SYST_config);

  while(1){
		if (Switch_Check(PORTF,4)==0){
			on_time+=500;
			off_time-=500;
		}
		if (Switch_Check(PORTF,0)==0){
			off_time+=500;
			on_time-=500;
		}	
	} //super loop
}

void SysTick_Handler(void){
  static uint32_t counter=0;
  counter++;
  if(LED_Check(PORTF,1)==1 && counter >= on_time){
      LED_Toggle(PORTF, PIN1, OFF);
      counter=0;
  }else if(LED_Check(PORTF,1)==0 && counter >= off_time){
    LED_Toggle(PORTF, PIN1, ON);
    counter=0;
  }
}
