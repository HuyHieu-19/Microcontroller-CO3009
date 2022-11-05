/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Huy Hieu
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isNormalResetPressed();
int isNormalIncPressed();
int isNormalDecPressed();
int isLongResetPressed();
int isLongIncPressed();
int isLongDecPressed();

void getKeyInput();

#endif /* INC_BUTTON_H_ */
