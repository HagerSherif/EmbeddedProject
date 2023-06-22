#include "Gpio.h"
#include "Gpio_Private.h"
#include "Rcc.h"
#include "Bit_Operations.h"
#include "Std_Types.h"



#ifndef GPT_H
#define GPT_H

#define TIM2_BASE_ADD 0x40000000

typedef struct {
   uint32 CR1;
   uint32 CR2;
   uint32 SMCR;
   uint32 DIER;
   uint32 SR;
   uint32 EGR;
   uint32 CCMR1;
   uint32 CCMR2;
   uint32 CCER;
   uint32 CNT;
   uint32 PSC;         /*!< TIM prescaler register,                       Address offset: 0x28 */
   uint32 ARR;         /*!< TIM auto-reload register,                      Address offset: 0x2C */
   uint32 RCR;         /*!< TIM repetition counter register,              Address offset: 0x30 */
   uint32 CCR1;        /*!< TIM capture/compare register 1,                Address offset: 0x34 */
   uint32 CCR2;        /*!< TIM capture/compare register 2,                Address offset: 0x38 */
   uint32 CCR3;        /*!< TIM capture/compare register 3,                Address offset: 0x3C */
   uint32 CCR4;        /*!< TIM capture/compare register 4,                Address offset: 0x40 */
   uint32 BDTR;        /*!< TIM break and dead-time register,              Address offset: 0x44 */
   uint32 DCR;         /*!< TIM DMA control register,                      Address offset: 0x48 */
   uint32 DMAR;        /*!< TIM DMA address for full transfer register,    Address offset: 0x4C */
   uint32 OR;          /*!< TIM option register,                            Address offset: 0x50 */
} TIM_TypeDef;

void GPT_Init(void);
void GPT_StartTimer(unsigned long int OverFlowTicks);
unsigned char GPT_CheckTimeIsElapsed(void);
unsigned long int GPT_GetElapsedTime(void);
unsigned long int GPT_GetRemainingTime(void);

#endif
