/*
 * software_timer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Huy Hieu
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag;
extern int led_flag;
extern int INC_flag;
extern int DEC_flag;
extern int silent_flag;
extern int count_down_flag;

void setTimer(int duration);
void setTimerLed(int duration);
void setTimerINC(int duration);
void setTimerDEC(int duration);
void setTimerSilent(int ten_seconds);
void setTimerCountDown(int duration);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
