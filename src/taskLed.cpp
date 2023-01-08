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