#include "Gpt.h"

TIM_TypeDef* TIM2 = (TIM_TypeDef*)TIM2_BASE_ADD;
void GPT_Init(void){

	Rcc_Enable(RCC_TIM2);
	TIM2->PSC=2999;
	SET_BIT(TIM2->EGR, 0);
//	SET_BIT(TIM2->DIER, 0);
}
void GPT_StartTimer(unsigned long int OverFlowTicks){

	TIM2->CNT=0; //restart counter
	TIM2->ARR = OverFlowTicks;  //OverFlowTicks=10000 for 10 seconds
	SET_BIT(TIM2->CR1, 0);  //enable counter
}

unsigned char GPT_CheckTimeIsElapsed(void) {

        if ((TIM2->CNT== TIM2->ARR-1) &&((TIM2->CR1)&1))
	    {
        	char read_flag=(TIM2->SR &1);
	        return 1;
	    }
	    return 0;
}

unsigned long int GPT_GetElapsedTime(void){
	if (GPT_CheckTimeIsElapsed()) {
	        return  0xfffffff;
	    }
	else if (((TIM2->CR1)&1)==0){
	    return 0;
	}
    return (TIM2->CNT);
}

unsigned long int GPT_GetRemainingTime(void){

	if (GPT_CheckTimeIsElapsed()) {
		        return 0;
    }
	else if(((TIM2->CR1)&1)==0){
	    return 0xfffffff;
	}
	return ((TIM2->ARR)-(TIM2->CNT));

}
