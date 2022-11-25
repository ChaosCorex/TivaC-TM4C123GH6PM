#include "SYST_Interface.h"

void SYST_Init (const SYST_ConfigType* config){
	
	CLR_BIT(SYST.STCTRL,0);
	
	if(config->interrupten){
		SET_BIT(SYST.STCTRL,1);
	}
	
	if(config->clocksource==SYSTEM_CLOCK){
    SET_BIT(SYST.STCTRL,2);
	}else{
		CLR_BIT(SYST.STCTRL,2);
	}
	
	SYST.STRELOAD = config->reloadvalue;
	SET_BIT(SYST.STCTRL,0);
}

