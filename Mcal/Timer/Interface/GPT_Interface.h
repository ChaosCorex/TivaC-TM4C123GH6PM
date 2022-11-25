#ifndef _GPT_INTERFACE_H_
#define _GPT_INTERFACE_H_
#include "Utilities.h"
#include "GPT_Private.h"

typedef enum{TIMER0=0, TIMER1, TIMER2, TIMER3, TIMER4, TIMER5}GPT_TimerType;
typedef enum{TIMERA=0, TIMERB=8}GPT_ChannelType;
typedef uint32_t GPT_ValueType;
typedef enum{Oneshot=1, Periodic=2}GPT_ModeType;
typedef uint32_t GPT_PrescalerType;
typedef enum{DOWN,UP} GPT_CountDirection;
typedef enum {TIMERA_TIME_OUT=0, TIMERA_CAPTURE, TIMERA_CAPTURE_EVENT, RTC, TIMERA_MATCH,TIMERB_TIME_OUT=8, TIMERB_CAPTURE, TIMERB_CAPTURE_EVENT ,TIMERB_MATCH}GPT_InterruptType;
/*typedef enum{GPT_PREDEF_TIMER_1US_16BIT=0, GPT_PREDEF_TIMER_1US_24BIT=1, GPT_PREDEF_TIMER_1US_32BIT=2, GPT_PREDEF_TIMER_100US_32BIT=3}GPT_PredefTimerType;*/

typedef struct{
	GPT_TimerType timer;
	GPT_ChannelType channel;
	GPT_ModeType mode;
	GPT_CountDirection direction;
	GPT_ValueType value;
	GPT_PrescalerType prescaler;
}GPT_ConfigType;
	
typedef struct {
    uint32_t GPTMCFG;
    uint32_t GPTMTAMR;
    uint32_t GPTMTBMR;
    uint32_t GPTMCTL;
    uint32_t GPTMSYNC;
    uint32_t RESERVED;
    uint32_t GPTMIMR;
    uint32_t GPTMRIS;
    uint32_t GPTMMIS;
    uint32_t GPTMICR;
    uint32_t GPTMTAILR;
    uint32_t GPTMTBILR;
    uint32_t GPTMTAMATCHR;
    uint32_t GPTMTBMATCHR;
    uint32_t GPTMTAPR;
    uint32_t GPTMTBPR;
    uint32_t GPTMTAPMR;
    uint32_t GPTMTBPMR;
    uint32_t GPTMTAR;
    uint32_t GPTMTBR;
    uint32_t GPTMTAV;
    uint32_t GPTMTBV;
    uint32_t GPTMRTCPD;
    uint32_t GPTMTAPS;
    uint32_t GPTMTBPS;
    uint32_t GPTMTAPV;
    uint32_t GPTMTBPV;
}GPTM_Type;

void GPT_Init(const GPT_ConfigType* config);

GPTM_Type* GPT_GetTimer(GPT_TimerType timer);

void GPT_StartTimer(GPT_TimerType timer, GPT_ChannelType channel, GPT_ValueType value);

void GPT_StopTimer(GPT_TimerType timer, GPT_ChannelType channel);

void GPT_EnableInt (GPT_TimerType timer, GPT_InterruptType interrupt);

void GPT_DisableInt (GPT_TimerType timer, GPT_InterruptType interrupt);

void GPT_ClearInt (GPT_TimerType timer, GPT_InterruptType interrupt);

void GPT_Notification(void(*op)(void));

/*GPT_ValueType GPT_GetTimeElapsed(GPT_TimerType timer, GPT_ChannelType channel);

void GPT_DisableNotification(GPT_TimerType timer, GPT_ChannelType channel);

void GPT_EnableNotification(GPT_TimerType timer, GPT_ChannelType channel);

GPT_ValueType GPT_GetTimeRemaining(GPT_TimerType timer, GPT_ChannelType channel);

uint32_t GPT_GetPredefTimerValue(GPT_PredefTimerType predef, uint32_t* timevalue);*/
#endif
