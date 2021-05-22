#include "stm32f4xx.h"                  // Device header

int main(void){
	RCC->AHB1ENR |=1;
	RCC->AHB1ENR |=4; //Enable port C
	GPIOA->MODER |=0x400;
	
	
	while(1){
		
		if(GPIOC->IDR & 0x2000) //Check if data input register is true and bit 13 also true. (PC13 high)
		{
			GPIOA->BSRR = 0x002; //Turn off LED
		}
		
		else{
			GPIOA->BSRR = 0x20; //Turn on LED
		}
		
	
	}

}
