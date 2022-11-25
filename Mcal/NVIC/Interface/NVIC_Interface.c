#include "NVIC_Interface.h"

void NVIC_EnableINT(INT_type INT){
	SET_BIT(NVIC.EN[INT/32],INT%32);
}

void NVIC_DisableINT(INT_type INT){
	SET_BIT(NVIC.DIS[INT/32],INT%32);
}