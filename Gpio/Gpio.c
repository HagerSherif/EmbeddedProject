
#include "Gpio.h"

#include "Gpio_Private.h"

uint32 GPIO_Addresses[4] = { GPIOA_BASE_ADDR, GPIOB_BASE_ADDR,GPIOC_BASE_ADDR,GPIOD_BASE_ADDR };

void GPIO_Init(void){
	uint32 i = 0;
	for (i = 5; i <= 15; i+=5) {

	 GpioType * gpioReg = GPIOD_BASE_ADDR;
	 gpioReg->GPIO_MODER &= ~(0x3 << (2 * i));
	 gpioReg->GPIO_MODER |= (GPIO_OUTPUT << (2 * i));

	 gpioReg->GPIO_OTYPER  &= ~(0x01 << i);
	 gpioReg->GPIO_OTYPER |= (GPIO_PUSH_PULL << i);
	  }

	for (i = 0; i <2; i++) {

	 GpioType * gpioReg = GPIOA_BASE_ADDR;
	 gpioReg->GPIO_MODER &= ~(0x3 << (2 * i));
	 gpioReg->GPIO_MODER |= (GPIO_INPUT << (2 * i));

     gpioReg->GPIO_PUPDR &= ~(0x3 << (2 * i));
	 gpioReg->GPIO_PUPDR |= (Pull_up << (2*i));
   }

}


void GPIO_WritePinValue(unsigned char PinId, unsigned char PinData){
	GpioType * gpioReg =  GPIOD_BASE_ADDR;
	gpioReg->GPIO_ODR &= ~(0x01 << PinId);
	gpioReg->GPIO_ODR |= (PinData << PinId);
}


uint8 Gpio_ReadPin( uint8 PinNum) {
	uint8 data = 0;
	GpioType * gpioReg = GPIOA_BASE_ADDR;
	data = (gpioReg->GPIO_IDR & (1 << PinNum)) >> PinNum;
	return data;
}










