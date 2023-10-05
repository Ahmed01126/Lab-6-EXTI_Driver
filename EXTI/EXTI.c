#include "EXTI.h"
#include "Bit_Operations.h"

void EXTI_Init(uint8 EXTI_Line, uint8 EXTI_Mode, uint8 Port) {
  // falling edge detection
  if (EXTI_Mode == EXTI_FALLING_EDGE){
    SET_BIT(EXTI->FTSR, EXTI_Line);
  }
  else if (EXTI_Mode == EXTI_RISING_EDGE){
    SET_BIT(EXTI->RTSR, EXTI_Line);
  }
  else if (EXTI_Mode == EXTI_ON_CHANGE){
    SET_BIT(EXTI->FTSR, EXTI_Line);
    SET_BIT(EXTI->RTSR, EXTI_Line);
  }
  
  if(EXTI_Line < 4){
    SYSCFG->EXTICR[0] &= ~(0xF << (EXTI_Line * 4));
    SYSCFG->EXTICR[0] |= (Port << (EXTI_Line * 4));
  }
  else if(EXTI_Line < 8){
    SYSCFG->EXTICR[1] &= ~(0xF << ((EXTI_Line - 4) * 4));
    SYSCFG->EXTICR[1] |= (Port << ((EXTI_Line - 4) * 4));
  }
  else if(EXTI_Line < 12){
    SYSCFG->EXTICR[2] &= ~(0xF << ((EXTI_Line - 8) * 4));
    SYSCFG->EXTICR[2] |= (Port << ((EXTI_Line - 8) * 4));
  }
  else if(EXTI_Line < 16){
    SYSCFG->EXTICR[3] &= ~(0xF << ((EXTI_Line - 12) * 4));
    SYSCFG->EXTICR[3] |= (Port << ((EXTI_Line - 12) * 4));
  }
}

void EXTI_Enable(uint8 EXTI_Line){
  SET_BIT(EXTI->IMR, EXTI_Line);
  SET_BIT(NVIC->ISER[0], EXTI_Line + 6);
}

void EXTI_Disable(uint8 EXTI_Line){
  CLEAR_BIT(EXTI->IMR, EXTI_Line);
}

