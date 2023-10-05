#include "SevenSegments.h"
void SevenSegments_Init(void){
	uint8 i;
	  for (i = SevenSegments_FIRST_PIN; i < (SevenSegments_FIRST_PIN + 7); i++) {
	    GPIO_ConfigPin(SevenSegments_PORT, i, GPIO_OUTPUT, GPIO_PUSH_PULL,GPIO_PULL_DOWN);
	  }
}

void SevenSegments_Display(uint8 value){
	switch (value)
			{
			case 0:
			default:
				GPIO_WritePin(SevenSegments_PORT, 0, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 1, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 2, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 3, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 4, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 5, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 6, LOW);
				break;

			case 1:
				GPIO_WritePin(SevenSegments_PORT, 0, LOW);
				GPIO_WritePin(SevenSegments_PORT, 1, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 2, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 3, LOW);
				GPIO_WritePin(SevenSegments_PORT, 4, LOW);
				GPIO_WritePin(SevenSegments_PORT, 5, LOW);
				GPIO_WritePin(SevenSegments_PORT, 6, LOW);
			break;

			case 2:
				GPIO_WritePin(SevenSegments_PORT, 0, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 1, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 2, LOW);
				GPIO_WritePin(SevenSegments_PORT, 3, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 4, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 5, LOW);
				GPIO_WritePin(SevenSegments_PORT, 6, HIGH);
			break;

			case 3:
				GPIO_WritePin(SevenSegments_PORT, 0, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 1, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 2, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 3, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 4, LOW);
				GPIO_WritePin(SevenSegments_PORT, 5, LOW);
				GPIO_WritePin(SevenSegments_PORT, 6, HIGH);
			break;

			case 4:
				GPIO_WritePin(SevenSegments_PORT, 0, LOW);
				GPIO_WritePin(SevenSegments_PORT, 1, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 2, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 3, LOW);
				GPIO_WritePin(SevenSegments_PORT, 4, LOW);
				GPIO_WritePin(SevenSegments_PORT, 5, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 6, HIGH);
			break;

			case 5:
				GPIO_WritePin(SevenSegments_PORT, 0, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 1, LOW);
				GPIO_WritePin(SevenSegments_PORT, 2, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 3, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 4, LOW);
				GPIO_WritePin(SevenSegments_PORT, 5, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 6, HIGH);
			break;

			case 6:
				GPIO_WritePin(SevenSegments_PORT, 0, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 1, LOW);
				GPIO_WritePin(SevenSegments_PORT, 2, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 3, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 4, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 5, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 6, HIGH);
			break;

			case 7:
				GPIO_WritePin(SevenSegments_PORT, 0, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 1, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 2, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 3, LOW);
				GPIO_WritePin(SevenSegments_PORT, 4, LOW);
				GPIO_WritePin(SevenSegments_PORT, 5, LOW);
				GPIO_WritePin(SevenSegments_PORT, 6, LOW);
			break;

			case 8:
				GPIO_WritePin(SevenSegments_PORT, 0, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 1, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 2, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 3, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 4, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 5, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 6, HIGH);
			break;

			case 9:
				GPIO_WritePin(SevenSegments_PORT, 0, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 1, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 2, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 3, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 4, LOW);
				GPIO_WritePin(SevenSegments_PORT, 5, HIGH);
				GPIO_WritePin(SevenSegments_PORT, 6, HIGH);
			break;
			}
}

