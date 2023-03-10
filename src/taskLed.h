/*
 * taskLed.hpp
 *
 *  Created on: 8 Oca 2023
 *      Author: Mevlana
 */

#ifndef INC_TASKLED_H_
#define INC_TASKLED_H_

#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal.h"

#define MEMADDR1  0x08060000 //ledTime[0] is memory address definition
#define MEMADDR2  0x08060010 //ledTime[1] is memory address definition
#define MEMANYONE 0x08060030 //Anyone memory address is definition

class led {

private:

	void Flash_Write(uint32_t Flash_Data1,uint32_t Flash_Data2);

	uint32_t Flash_Read(uint32_t Flash_Address);

public:

	uint32_t ledTime[2];

	bool uart = true;

	GPIO_PinState getState = GPIO_PIN_SET;

	uint32_t lastTime = 0;


	void setTime();

	void task1();

	void task2(UART_HandleTypeDef *huart, uint8_t *msg, uint8_t SIZE);
};

#endif /* INC_TASKLED_H_ */
