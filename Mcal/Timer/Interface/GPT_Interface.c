#include "GPT_Interface.h"


GPTM_Type* GPT_GetTimer(GPT_TimerType timer){
switch(timer){
		case TIMER0:
				return (GPTM_Type*)&GPTM0;
		case TIMER1:
				return (GPTM_Type*)&GPTM1;
		case TIMER2:
				return (GPTM_Type*)&GPTM2;
		case TIMER3:
				return (GPTM_Type*)&GPTM3;
		case TIMER4:
				return (GPTM_Type*)&GPTM4;
		case TIMER5:
				return (GPTM_Type*)&GPTM5;
	}
}
void GPT_Init(const GPT_ConfigType* config){
	
	GPTM_Type* TIMER = GPT_GetTimer(config->timer);
	
	SET_BIT(RCGCTIMER,config->timer);
	CLR_BIT(TIMER->GPTMCTL,config->channel);
	TIMER->GPTMCFG=0x0;
	TIMER->GPTMCFG=0x4;
	
	if (config->channel==TIMERA){
		TIMER->GPTMTAMR=config->mode;
		TIMER->GPTMTAILR=config->value;
		TIMER->GPTMTAPR=config->prescaler;
	}
	else{
		TIMER->GPTMTBMR=config->mode;
		TIMER->GPTMTBILR=config->value;
		TIMER->GPTMTBPR=config->prescaler;
	}
	SET_BIT(TIMER->GPTMCTL,config->channel);
}

void GPT_StartTimer(GPT_TimerType timer, GPT_ChannelType channel, GPT_ValueType value){
	GPTM_Type* TIMER = GPT_GetTimer(timer);
	if (channel==TIMERA){
				TIMER->GPTMTAILR=value;
				SET_BIT(TIMER->GPTMCTL,channel);
			}
			else{
				TIMER->GPTMTBILR=value;
				SET_BIT(TIMER->GPTMCTL,channel);
			}
	
}

void GPT_StopTimer(GPT_TimerType timer, GPT_ChannelType channel){
	GPTM_Type* TIMER = GPT_GetTimer(timer);
			CLR_BIT(TIMER->GPTMCTL,channel);
}

void GPT_EnableInt (GPT_TimerType timer, GPT_InterruptType interrupt){
	GPTM_Type* TIMER = GPT_GetTimer(timer);
			SET_BIT(TIMER->GPTMIMR,interrupt);
}

void GPT_DisableInt (GPT_TimerType timer, GPT_InterruptType interrupt){
	GPTM_Type* TIMER = GPT_GetTimer(timer);
			CLR_BIT(TIMER->GPTMIMR,interrupt);
}

void GPT_ClearInt (GPT_TimerType timer, GPT_InterruptType interrupt){
	GPTM_Type* TIMER = GPT_GetTimer(timer);
			SET_BIT(TIMER->GPTMICR,interrupt);
}

void GPT_Notification(void(*op)(void)){
	static volatile int counter;
	op();
	counter++;
}
