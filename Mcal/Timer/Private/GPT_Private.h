#ifndef _GPIO_PRIVATE_H_
#define _GPIO_PRIVATE_H_

#define RCGCTIMER (*((volatile uint32_t*)0x400FE604))
#define RCGCWTIMER (*((volatile uint32_t*)0x400FE65C))

#define GPTM0   (*((volatile GPTM_Type *)0x40030000))
#define GPTM1   (*((volatile GPTM_Type *)0x40031000))
#define GPTM2   (*((volatile GPTM_Type *)0x40032000))
#define GPTM3   (*((volatile GPTM_Type *)0x40033000))
#define GPTM4   (*((volatile GPTM_Type *)0x40034000))
#define GPTM5   (*((volatile GPTM_Type *)0x40035000))
	
#endif