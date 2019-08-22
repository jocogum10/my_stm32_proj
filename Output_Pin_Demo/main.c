#include <stm32f30x.h>
#include <stm32f30x_rcc.h>
#include <stm32f30x_gpio.h>

int main(void)
{
	volatile unsigned int i=0;

	//enable clock for port E
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);

	//configure port e pin
	GPIO_InitTypeDef GPIO_InitStruct;
	//port e settings
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_Level_3;
	//initialize port e
	GPIO_Init(GPIOE, &GPIO_InitStruct);

    while(1)
    {
    	for (i = 0; i < 1000000; i++);
    	GPIO_SetBits(GPIOE, GPIO_Pin_All);
    	for (i = 0; i < 1000000; i++);
		GPIO_ResetBits(GPIOE, GPIO_Pin_All);
    }
}
