#include "GPIO.h"
#include "Rcc.h"
#include "Std_Types.h"

#define EXTI_FALLING_EDGE 0
#define EXTI_RISING_EDGE 1
#define EXTI_ON_CHANGE 2

// NVIC registers
#define NVIC ((NvicType *)0xE000E100)
typedef struct {
	uint32 ISER[8];
} NvicType;

// EXTI registers
#define EXTI ((ExtiType *)0x40013C00)
typedef struct {
	uint32 IMR;
	uint32 EMR;
	uint32 RTSR;
	uint32 FTSR;
	uint32 SWIER;
	uint32 PR;
} ExtiType;

// SYSCFG registers
#define SYSCFG ((SyscfgType *)0x40013800)
typedef struct {
	uint32 MEMRMP;
	uint32 PMC;
	uint32 EXTICR[4];
	uint32 CMPCR;
} SyscfgType;


void EXTI_Init(uint8 EXTI_Line, uint8 EXTI_Mode, uint8 Port);
void EXTI_Enable(uint8 EXTI_Line);
void EXTI_Disable(uint8 EXTI_Line);
