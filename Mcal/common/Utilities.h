#ifndef _UTILITIES_H__
#define _UTILITIES_H__

typedef unsigned int uint32_t; 
typedef unsigned char uint8_t;

#define SET_BIT(REG,BIT) (REG|=(1<<BIT))
#define CLR_BIT(REG,BIT) (REG&=~(1<<BIT))
#define TOG_BIT(REG,BIT) (REG^=(1<<BIT))
#define GET_BIT(REG,BIT) ((REG>>BIT)&1)

#endif
