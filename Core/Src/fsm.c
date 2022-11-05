/*
 * fsm.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Huy Hieu
 */
#include "fsm.h"

int duration = 100;
int num = 0;
int countForPress = 100;

void fsm_implement()
{
	if(led_flag == 1)
	{
		HAL_GPIO_TogglePin(GPIOA, RED_LED_Pin);
		setTimerLed(duration);
	}


	switch(status)
	{
		case INIT:
			if(isNormalResetPressed() == 1 || isLongResetPressed() == 1)
			{
				status = NOR_RESET;
				setTimerSilent(1000);
			}
			else if(isNormalIncPressed() == 1)
			{
				status = NOR_INC;
				setTimerSilent(1000);
			}
			else if(isNormalDecPressed() == 1)
			{
				status = NOR_DEC;
				setTimerSilent(1000);
			}
			else if(isLongIncPressed() == 1)
			{
				status = LONG_INC;
				setTimerSilent(1000);
			}
			else if(isLongDecPressed() == 1)
			{
				status = LONG_DEC;
				setTimerSilent(1000);
			}

			if(silent_flag == 1)
			{
				status = AUTO_COUNT_DOWN;
				setTimerCountDown(duration);
			}
			break;

		case NOR_RESET:
			num = 0;
			display7SEG(num);

			status = INIT;

			break;
		case NOR_INC:
			num++;
			if(num > 9) num = 0;
			display7SEG(num);

			status = INIT;

			break;
		case NOR_DEC:
			num--;
			if(num < 0) num = 9;
			display7SEG(num);
			status = INIT;

			break;
		case LONG_INC:
			num++;
			if(num > 9) num = 0;
			display7SEG(num);
			status = AUTO_INC;
			setTimerINC(duration);
			break;
		case LONG_DEC:
			num--;
			if(num < 0) num = 9;
			display7SEG(num);
			status = AUTO_DEC;
			setTimerDEC(duration);
			break;
		case AUTO_INC:
			if(INC_flag == 1)
			{
				num++;
				if(num > 9) num = 0;
				display7SEG(num);
				setTimerINC(duration);
				setTimerSilent(1000);
			}
			if(isNormalIncPressed() == 1) status = INIT;
			break;
		case AUTO_DEC:
			if(DEC_flag == 1)
			{
				num--;
				if(num < 0) num = 9;
				display7SEG(num);
				setTimerDEC(duration);
				setTimerSilent(1000);
			}
			if(isNormalDecPressed() == 1) status = INIT;
			break;
		case AUTO_COUNT_DOWN:
			if(count_down_flag == 1)
			{
				num--;
				if(num < 0) num = 0;
				display7SEG(num);
				setTimerCountDown(duration);
			}
			if(isNormalDecPressed() == 1 || isNormalIncPressed() == 1|| isNormalResetPressed() == 1)
			{
				status = INIT;
				setTimerSilent(1000);
			}
			break;
		default:
			break;
	}
}
