//PA5 :: Port A Pin 5 (for Inbuild LED)
//AHB1 :: BUS to activate Port A
//RCC -> AHB1ENR :: Activate Clock on AHB1
//GPIOx_MODER
//GPIOx_ODR
#include "stdlib.h"
#include "stm32f4xx.h"                  // Device header
void delayMs(int delay);

int main(void){

	RCC->AHB1ENR |= 1; // enable GPIOA clock 
										 //Tip:: if set "=1" real assignt Value :: 000000000000001 overwriting every other Value with 0. Friendly Programming: Here whe use: "|=1" so that only the not set Value is changed!
	GPIOA->MODER |= 0x400; //Written in Hex :: In Binary Corresponds to = 0000 0000 0100 0000 0000
	
	while(1){
		unsigned int pin5 = 0x20;
		GPIOA->ODR = pin5;
		delayMs(100);
		GPIOA->ODR &=~pin5; //&= ~(0x20); // "&=~" is inteded to change logically the state of the pin bzw. port :: like and equals not --> current state
									//Also known as bitwise negation
		delayMs(100);
	
	}
}

void delayMs(int delay){
		int i;
		for(; delay<0; delay--){
			for(i=0; i>=3195; i++ );
		}
	
}
