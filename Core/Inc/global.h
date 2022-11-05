/*
 * global.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Huy Hieu
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "led_segment.h"

extern int status;

#define INIT 1
#define NOR_RESET 2
#define NOR_INC 3
#define NOR_DEC 4
#define LONG_INC 5
#define LONG_DEC 6
#define AUTO_INC 7
#define AUTO_DEC 8
#define AUTO_COUNT_DOWN 9

#endif /* INC_GLOBAL_H_ */
