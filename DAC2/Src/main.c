#include <stdint.h>

#include "stm32f446xx.h"



//#if !defined(_SOFT_FP) && defined(_ARM_FP)

//  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."

//#endif



int main(void)

{

//	float val = 0.0;

	uint32_t dac_value[] = {0,620,1240,1861,2481,3102,3722};

	int32_t i = 0;

	// enable GPIOA clock, bit 0 on AMBIENR

	RCC->AHB1ENR |=  (1 << 0);

	GPIOA->MODER &= ~(3<<8);// Reset bits 8-9 to clear old values

	GPIOA->MODER |= (3<<8); // Set pin 4 to analog mode (@bil)

	// enable DAC clock, bit 29 on APBIENK

	RCC->APB1ENR |= (1 <<29);

	DAC->CR |= (1 << 0); // enable DAC channel 1

	DAC->CR &= ~(1 << 1) ;// anable DAC chi output buffer

	DAC->CR |= (1 << 2); // enable trigger

	DAC->CR |= (7 << 3);// choose se trigger as source (0b111)


	// set output to Vref (dac value/0xFFF)
	DAC->DHR12R1 = dac_value[0];

	DAC->SWTRIGR |= (1 << 0) ;// trigger chl

		while (1)

		{
//			dac_value = (val*4095)/3.3;
			for(int a=0;a<6;a++)
			{
					DAC->DHR12R1 = dac_value[a];
					DAC->SWTRIGR |= (1 << 0) ;
					for(i=0;i<1000000;i++);
			}
			for(int b=6;b>0;b--)
			{
			DAC->DHR12R1 = dac_value[a];
			DAC->SWTRIGR |= (1 << 0) ;
		    for(i=0;i<1000000;i++);
			}
			// trigger chl
//			val += 0.5;
//			for (i = 0; 1<10000 ;i++);
//			if (val>3) val = 0.2;
//			return 0;

		}
		return 0;
}
