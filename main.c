#include "GPIO.h"
#include "Rcc.h"
#include "Std_Types.h"
#include "EXTI.h"
#include "SevenSegments.h"
#include "Bit_Operations.h"

uint8 counter = 0;
int main() {
	Rcc_Init();
	Rcc_Enable(RCC_GPIOA);
	Rcc_Enable(RCC_GPIOB);
	Rcc_Enable(RCC_GPIOC);
	Rcc_Enable(RCC_SYSCFG);

	GPIO_ConfigPin(GPIOA, 0, GPIO_INPUT, GPIO_PUSH_PULL, GPIO_PULL_UP);
	GPIO_ConfigPin(GPIOB, 1, GPIO_INPUT, GPIO_PUSH_PULL, GPIO_PULL_UP);

	EXTI_Init(0, EXTI_FALLING_EDGE, GPIOA);
	EXTI_Enable(0);
	EXTI_Init(1, EXTI_FALLING_EDGE, GPIOB);
	EXTI_Enable(1);

	
	SevenSegments_Init();
	SevenSegments_Display(0);
	// for(uint8 i = 0; i < 10; i++){
	// 	SevenSegments_Display(i);
	// 	for(uint32 j = 0; j < 1000000; j++){}
	// }
	while (1){}
	

	
	return 0;
}

void EXTI0_IRQHandler(void) {
	counter++;
	counter %= 10;
	SevenSegments_Display(counter);
	SET_BIT(EXTI->PR, 0);
}

void EXTI1_IRQHandler(void) {
	if(counter !=0){
		counter--;
		SevenSegments_Display(counter);
		SET_BIT(EXTI->PR, 1);
	}
}
