#include "stm32f4xx.h"                  // Device header


void delayMs(volatile int delay);

int main(void){
	RCC -> AHB1ENR |=1;
	GPIOA ->MODER |=0x400;
	
	while(1)
	{	
		
		GPIOA -> BSRR = 0x20; //Set PA5 high
		
		GPIOA -> BSRR = 0x00200000; //0b 0000 0000 0010 0000 0000 0000 0000 0000
		
	}
}

void delayMs(volatile int delay){
	volatile int i;
	for(; delay>0; delay--){
		for(i=0; i<3195; i++);
	}

}
