/*
 * led_segment.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Huy Hieu
 */

#include "led_segment.h"

void display7SEG(int num)
{
	char segmentNumber[10] = {0xC0,0xF9,0xA4, 0xB0, 0x99 , 0x92 , 0x82 ,0xF8, 0x80 , 0x90};
	for(int i=0;i<7;i++)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 << i, (segmentNumber[num] >> i) & 1);
	}
}
