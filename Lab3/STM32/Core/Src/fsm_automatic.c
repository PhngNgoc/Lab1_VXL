/*
 * fsm_automatic.c
 *
 *  Created on: Oct 28, 2024
 *      Author: tranm
 */

#include "fsm_automatic.h"

int count1;
int count2;

void fsm_automatic(){
	switch (status1) {
			case INIT:
				HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
				status1 = AUTO_GREEN;
				setTimer1(time_green*100);
				count1 = time_green;
				break;
			case AUTO_RED:
				HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
				HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
				if (timer1_flag == 1 ){
					status1 = AUTO_GREEN;
					setTimer1(time_green*100);
					count1 = time_green;
				}
				break;
			case AUTO_GREEN:
				HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
				HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
				if (timer1_flag == 1){
					status1 = AUTO_YELLOW;
					setTimer1(time_yellow*100);
					count1 = time_yellow;
				}
				break;
			case AUTO_YELLOW:
				HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
				if (timer1_flag == 1){
					status1 = AUTO_RED;
					setTimer1(time_red*100);
					count1 = time_red;
				}
				break;
			default:
				break;
		}
	switch (status2) {
			case INIT:
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
				status2 = AUTO_RED;
				count2 = time_red;
				setTimer2(time_red*100);
				break;
			case AUTO_RED:
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
				if (timer2_flag == 1){
					status2 = AUTO_GREEN;
					setTimer2(time_green*100);
					count2 = time_green;
				}
				break;
			case AUTO_GREEN:
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);
				HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
				if (timer2_flag == 1){
					status2 = AUTO_YELLOW;
					setTimer2(time_yellow*100);
					count2 = time_yellow;
				}
				break;
			case AUTO_YELLOW:
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET);
				if (timer2_flag == 1){
					status2 = AUTO_RED;
					setTimer2(time_red*100);
					count2 = time_red;
				}
				break;
			default:
				break;
		}
	    if (count1 == 0 ) return;
	    if (count2 == 0 ) return;

	    if ( timer3_flag == 1) {
			setTimer3(100);
			if( count1 < 10 ) displayled_3and4(0, count1);
			if( count1 >= 10 ) displayled_3and4(count1/10, count1%10);
			count1--;
		}
		if ( timer4_flag == 1) {
			setTimer4(100);
			if( count1 < 10 ){
				display7SEG2(count2);
				display7SEG1(0);
			}
			if ( count1 >= 10 ){
				display7SEG2(count2 % 10);
				display7SEG1(count2 / 10);
			}
			count2--;
		}

}
