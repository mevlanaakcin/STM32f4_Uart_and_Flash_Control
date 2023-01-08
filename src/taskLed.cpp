/*
 * taskLed.cpp
 *
 *  Created on: 8 Oca 2023
 *      Author: Mevlana
 */
#include <taskLed.h>
#include "string.h"
#include "stdio.h"

#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal.h"



/////////////////////////////////////////////////////////
///// Write Flash
void led::Flash_Write(uint32_t Flash_Data1, uint32_t Flash_Data2) {
	HAL_FLASH_Unlock();
	FLASH_Erase_Sector(FLASH_SECTOR_7, VOLTAGE_RANGE_3);
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, MEMADDR1, Flash_Data1);
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, MEMADDR2, Flash_Data2);
	HAL_FLASH_Lock();
}
///// Write Flash
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
///// Read Flash
uint32_t led::Flash_Read(uint32_t Flash_Address) {
	uint32_t Flash_Data;
	Flash_Data = *(uint32_t*) Flash_Address;

	return Flash_Data;
}
///// Read Flash
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
///// Set Time is led
void led::setTime(){

	if (Flash_Read(MEMANYONE) == Flash_Read(MEMADDR1)) {

		ledTime[0]=500;
		ledTime[1]=500;

	}
	else{

		ledTime[0]=Flash_Read(MEMADDR1);
		ledTime[1]=Flash_Read(MEMADDR2);

	}
}

///////////////////////////////////////////////////////////
///// task1 Led Control

void led::task1() {

	if (getState == GPIO_PIN_SET) {
		if ((HAL_GetTick() - lastTime) >= ledTime[0]) {
			getState = GPIO_PIN_RESET;
			lastTime = HAL_GetTick();
		}
	} else {
		if ((HAL_GetTick() - lastTime) >= ledTime[1]) {
			getState = GPIO_PIN_SET;
			lastTime = HAL_GetTick();
		}
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, getState);
	}
}

///// task1
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
///// task2 Uart Receive Data Process

void led::task2(UART_HandleTypeDef *huart, uint8_t *msg, uint8_t SIZE) {

	sscanf((char*) msg, "ledon=%d", (int*) &ledTime[0]);

	sscanf((char*) msg, "ledoff=%d", (int*) &ledTime[1]);

	if (!strncmp((char*) msg, "ledon", 5)
			|| !strncmp((char*) msg, "ledoff", 6)) {

		Flash_Write(ledTime[0], ledTime[1]); // Memory address is constant so function is just variables input.

	}

	if (!strncmp((char*) msg, "stop", 4)) {

		uart = false;
		ledTime[0] = 1000;
		ledTime[1] = 1000;

	}

	if (!strncmp((char*) msg, "start", 5)) {

		uart = true;
		setTime();

	}

	if (uart) {

		HAL_UART_Transmit_IT(huart, msg, SIZE);

	}
}

///// task2
///////////////////////////////////////////////////////////

