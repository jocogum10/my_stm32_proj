#include <stm32f30x.h>
#include <stm32f30x_rcc.h>
#include <stm32f30x_gpio.h>

int main(void)
{
	volatile unsigned int input_pb;
	//enable the RCC clock for AHB bus
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE | RCC_AHBPeriph_GPIOA, ENABLE);

	//initialize type definition
	GPIO_InitTypeDef GPIO_InitStruct;

	//configure port e
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_Level_2;
	GPIO_Init(GPIOE, &GPIO_InitStruct);

	//configure port a
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStruct);

    while(1)
    {
    	input_pb = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0);
    	if (input_pb == 1){
    		GPIO_SetBits(GPIOE, GPIO_Pin_All);
    	}
    	else{
    		GPIO_ResetBits(GPIOE, GPIO_Pin_All);
    	}
    }
}
