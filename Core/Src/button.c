/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Huy Hieu
 */

#include "button.h"

int	ButtonState[12] ={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE
,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int NormalButtonFlag[3] = {0,0,0};
int LongButtonFlag[3] ={0,0,0};
int TimeOutForKeyPress = 300;


int isNormalResetPressed()
{
	if(NormalButtonFlag[0] == 1)
	{
		NormalButtonFlag[0] = 0;
		return 1;
	}
	return 0;
}
int isNormalIncPressed()
{
	if(NormalButtonFlag[1] == 1)
	{
		NormalButtonFlag[1] = 0;
		return 1;
	}
	return 0;
}
int isNormalDecPressed()
{
	if(NormalButtonFlag[2] == 1)
	{
		NormalButtonFlag[2] = 0;
		return 1;
	}
	return 0;
}
int isLongResetPressed()
{
	if(LongButtonFlag[0] == 1)
	{
		LongButtonFlag[0] = 0;
		return 1;
	}
	return 0;
}
int isLongIncPressed()
{
	if(LongButtonFlag[1] == 1)
	{
		LongButtonFlag[1] = 0;
		return 1;
	}
	return 0;
}
int isLongDecPressed()
{
	if(LongButtonFlag[2] == 1)
	{
		LongButtonFlag[2] = 0;
		return 1;
	}
	return 0;
}

void getKeyInput()
{
	for(int i=0;i<12;i += 4)
	{
 		ButtonState[i] = ButtonState[i+1];
		ButtonState[i+1] = ButtonState[i+2];
		ButtonState[i+2] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0 << (12+(i/4)));

		if ((ButtonState[i] == ButtonState[i+1]) && (ButtonState[i+1] == ButtonState[i+2])) //trang thai phim nhan on dinh (cung` set hoac cung` reset)
		{
			if(ButtonState[i+3] != ButtonState[i+2]) //truong hop nhan tha (dang ko nhan nhan xuong or dang nhan roi tha ra)
			{
				ButtonState[i+3] = ButtonState[i+2];
				if(ButtonState[i+2] == PRESSED_STATE) //=> toggle
				{
					NormalButtonFlag[i/4] = 1;
					TimeOutForKeyPress = 300;
				}
				//else dang Pressed ma tha ra thi se   ko co hien tuong gi xay ra nhu cach the hien tren proteus
			}
			else //roi vao truong hop nhan de
			{
			   TimeOutForKeyPress--;
			   if (TimeOutForKeyPress == 0) //het thoi gian nhan de` va bat dau xu ly
			   {
				   if(ButtonState[i+2] == PRESSED_STATE) LongButtonFlag[i/4] = 1;
				   TimeOutForKeyPress = 300;
				   ButtonState[i+3] = NORMAL_STATE;
			   }
			}
		}
	}
  //else : phim' bi rung
}

