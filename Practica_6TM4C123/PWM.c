#include "lib/include.h"

extern void Configura_Reg_PWM1(uint16_t freq)
{
   SYSCTL->RCGCPWM |= (1<<0);    
    SYSCTL->RCGCGPIO |= (1<<1); 
    SYSCTL->RCC |=(1<<20);   
    SYSCTL->RCC &= 0xFFF0FFFF; 
    GPIOB->AFSEL |= (1<<4); 
    GPIOB->PCTL |= 0x00040000; 
    GPIOB->DEN |= (1<<4);
    PWM1->_1_CTL &= ~(1<<0);
    PWM1->_1_GENA = 0x008C; 
    PWM1->_1_LOAD = 2500;
    PWM1->_1_CMPB = 2000;
    PWM1->_1_CMPA = 2000; 
    PWM1->_1_CTL |= (1<<0);
    PWM1->ENABLE = (1<<2);
 
}

