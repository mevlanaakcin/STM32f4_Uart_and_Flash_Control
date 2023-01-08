#include <taskLed.h>
#include "main.h"
#include "string.h"

uint8_t tempBuff[1];
uint8_t text[32];
uint16_t size = 0;
bool uartStatus = false;


led Led;
UART_HandleTypeDef huart2;


/////////////////////////////////////////////////////////
///// Read Data Complate Interrupt
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {

	if (huart == &huart2) {

		text[size] = tempBuff[0];
		if (text[size] != '\n') {
			size++;
		} else {
			size = 0;
			uartStatus = true;
		}
		HAL_UART_Receive_IT(&huart2, tempBuff, 1);
	}
}
///// Read Data Complate Interrupt
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
///// Send Data Complate Interrupt
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart == &huart2) {

		memset(text, 0, 32);

	}

}
///// Send Data Complate Interrupt
/////////////////////////////////////////////////////////

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);


int main(void) {

	HAL_Init();
	SystemClock_Config();

	MX_GPIO_Init();
	MX_USART2_UART_Init();

	HAL_UART_Receive_IT(&huart2, tempBuff, 1);

	while (1) {




	}

}