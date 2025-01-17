/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
uint32_t *AHBIENR= (uint32_t*)0x40023830;
uint32_t *DMA2_S0CR=(uint32_t*)0x40026410;
uint32_t *DMA2_S0NDTR=(uint32_t*)0x40026418;
uint32_t *DMA2_S0PAR=(uint32_t)0x40026436;
uint32_t *DMA2_S0M0AR=(uint32_t*)0x4002641C;

void DMA2_init();
void DMA2_Start();
char source[8]="HELOYES";
char dest[8];
char dest1[4];
void DMA2_init(){
   *AHBIENR|=(1<<22);
   *DMA2_S0CR |=(2<<6);
   *DMA2_S0CR &= ~(1<<25);
   *DMA2_S0CR |= (0<<16);
   *DMA2_S0CR |= (1<<10);
   *DMA2_S0CR &= ~(1<<13);
   *DMA2_S0CR |= (1<<9);
   *DMA2_S0CR &= ~(1<<11);
//   *DMA2_S1CR |=(2<<6);
//      *DMA2_S1CR &= ~(2<<25);
//      *DMA2_S1CR |= (0<<16);
//      *DMA2_S1CR |= (1<<10);
//      *DMA2_S1CR &= ~(1<<13);
//      *DMA2_S1CR |= (1<<9);
//      *DMA2_S1CR &= ~(1<<11);

//}
void DMA2_Start(){
	*DMA2_S0NDTR= 0;
	*DMA2_S0M0AR=(uint32_t)&dest;
	*DMA2_S0PAR=(uint32_t)&source;
	*DMA2_S0CR |=(1<<0);


}
//void reverse(char *source){
//	   int len = 0;
//	    while (source[len] != '\0') {
//	        len++;
//	    }
//	    for (int i = 0; i < len / 2; i++) {
//	        char temp = source[i];
//	        source[i] = source[len - 1 - i];
//	        source[len - 1 - i] = temp;
//	    }
//}

int main(void)
{
	DMA2_init();
	DMA2_Start();
//	reverse(dest);

    /* Loop forever */

	while(1){

	}
}
