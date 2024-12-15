/*
 * sofware_timer.h
 *
 *  Created on: Oct 28, 2024
 *      Author: tranm
 */

#ifndef INC_SOFWARE_TIMER_H_
#define INC_SOFWARE_TIMER_H_

#include "display7seg.h"

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
extern int timer4_flag;
extern int timer5_flag;


void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
void setTimer5(int duration);
void timerRun();


#endif /* INC_SOFWARE_TIMER_H_ */
