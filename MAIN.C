/* USER CODE BEGIN Includes */
#include<string.h>
/* USER CODE END Includes */

/* USER CODE BEGIN PV */

extern char letter[5];
extern  char buffer[200];
uint8_t intr;//=0;

/* USER CODE END PV */

/* USER CODE BEGIN 2 */

HAL_UART_Receive_IT(&huart1, letter, 1);



/* USER CODE END 2 */
 /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while(1){
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	HAL_Delay(100);
 	HAL_UART_Transmit(&huart1, buffer, strlen(buffer), HAL_MAX_DELAY);
	memset(buffer, NULL , sizeof(buffer));
	intr=0;
/* USER CODE END WHILE */

}


/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	HAL_UART_Receive_IT(&huart1, letter, 1);


		buffer[intr++]=letter[0];

		 if (intr >= sizeof(buffer) - 1) // Check if buffer is full
		 {
		                buffer[sizeof(buffer) - 1] = '\0'; // Ensure null-termination
		                intr = 0; // Reset index for the next line
		 }

}
/* USER CODE END 4 */
