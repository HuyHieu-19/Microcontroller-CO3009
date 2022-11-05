/*
 * software_timer.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Huy Hieu
 */

#include "software_timer.h"

int timer_flag = 0;
int timer_counter = 0;
int led_flag = 0;
int timer_counter_led = 0;
int INC_flag = 0;
int DEC_flag = 0;
int timer_counter_INC = 0;
int timer_counter_DEC = 0;
int	silent_flag = 0;
int timer_counter_silent = 0;
int count_down_flag = 0;
int timer_count_down = 0;

void setTimerCountDown(int duration)
{
	count_down_flag = 0;
	timer_count_down = duration;
}
void setTimerSilent(int duration)
{
	silent_flag = 0;
	timer_counter_silent = duration;
}

void setTimerLed(int duration)
{
	led_flag = 0;
	timer_counter_led = duration;
}
void setTimer(int duration)
{
	timer_flag = 0;
	timer_counter = duration;
}

void setTimerINC(int duration)
{
	INC_flag = 0;
	timer_counter_INC = duration;
}
void setTimerDEC(int duration)
{
	DEC_flag = 0;
	timer_counter_DEC = duration;
}
void timerRun()
{
	if(timer_counter > 0)
	{
		timer_counter--;
		if(timer_counter == 0)
		{
			timer_flag = 1;
		}
	}
	if(timer_counter_led > 0)
	{
		timer_counter_led--;
		if(timer_counter_led == 0)
		{
			led_flag = 1;
		}
	}
	if(timer_counter_INC > 0)
	{
		timer_counter_INC--;
		if(timer_counter_INC == 0)
		{
			INC_flag = 1;
		}
	}
	if(timer_counter_DEC > 0)
	{
		timer_counter_DEC--;
		if(timer_counter_DEC == 0)
		{
			DEC_flag = 1;
		}
	}
	if(timer_counter_silent > 0)
	{
		timer_counter_silent--;
		if(timer_counter_silent == 0)
		{
			silent_flag = 1;
		}
	}
	if(timer_count_down > 0)
	{
		timer_count_down--;
		if(timer_count_down == 0)
		{
			count_down_flag = 1;
		}
	}
}
