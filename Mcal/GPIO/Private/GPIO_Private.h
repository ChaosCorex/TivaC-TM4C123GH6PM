#ifndef _GPIO_PRIVATE_H_
#define _GPIO_PRIVATE_H_

#define RCGCGPIO (*((volatile uint32_t*) 0x400FE608))
	
#define GPIOA (*((volatile GPIO_Type*) 0x40004000))
#define GPIOB (*((volatile GPIO_Type*) 0x40005000))
#define GPIOC (*((volatile GPIO_Type*) 0x40006000))
#define GPIOD (*((volatile GPIO_Type*) 0x40007000))
#define GPIOE (*((volatile GPIO_Type*) 0x40024000))
#define GPIOF (*((volatile GPIO_Type*) 0x40025000))

#define HPORTA (*((volatile GPIO_Type*) 0x40058000))
#define HPORTB (*((volatile GPIO_Type*) 0x40059000))
#define HPORTC (*((volatile GPIO_Type*) 0x4005A000))
#define HPORTD (*((volatile GPIO_Type*) 0x4005B000))
#define HPORTE (*((volatile GPIO_Type*) 0x4005C000))
#define HPORTF (*((volatile GPIO_Type*) 0x4005D000))
	
#endif