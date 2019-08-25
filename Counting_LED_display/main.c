#include <stm32f30x.h>
#include <stm32f30x_rcc.h>
#include <stm32f30x_gpio.h>

GPIO_InitTypeDef GPIO_InitStruct;
int main(void)
{
	unsigned int i = 0;
	unsigned int count = 0;
	unsigned int display_count = 0;

	//enable clock
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);

	//configure clock for leds
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 |
				GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 |
				GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_Level_2;
	GPIO_Init(GPIOE, &GPIO_InitStruct);

	GPIO_Write(GPIOE, 0x00);

    while(1)
    {
    	for (i = 0; i < 500000; i++);
    	count = count + 1;
    	display_count = count << 7;
    	GPIO_Write(GPIOE, display_count);
    }
}
