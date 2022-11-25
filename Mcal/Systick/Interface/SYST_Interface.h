#ifndef _SYST_INTERFACE_H_
#define _SYST_INTERFACE_H_
#include "Utilities.h"
#include "SYST_Private.h"

#define F_CPU 12000000

typedef enum{DISABLE,ENABLE} SYST_EnableInterruptType;
typedef enum{PIOSC,SYSTEM_CLOCK} SYST_ClockSourceType;
typedef uint32_t SYST_ReloadValueType;

typedef struct{
	SYST_EnableInterruptType interrupten;
	SYST_ClockSourceType clocksource;
	SYST_ReloadValueType reloadvalue;
}SYST_ConfigType;

typedef struct{
    uint32_t STCTRL;
    uint32_t STRELOAD;
    uint32_t STCURRENT;
}SYST_Type;

void SYST_Init (const SYST_ConfigType* config);

/*
void SYST_Disable(void);
void SYST_InterruptEnable (void);
void SYST_InterruptDisable(void);
void SYST_SetReloadVal(uint32_t reloadVal);
uint32_t SYST_GetCountVal(void);
uint8_t SYST_IsDone(void);
*/


#endif
