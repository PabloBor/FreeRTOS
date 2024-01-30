#include "keypad.h"

const char characters[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

void InitMatrixKeypad() {
  
  TaskHandle_t Read_Keypad_handle;
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  BaseType_t status;

  status = xTaskCreate(Read_Keypad, "Read_Keypad", 300, NULL, 1, &Read_Keypad_handle);

  printf("Error code %ld/r/n", status);

  // Configure GPIOC 5, 6, 8 and 9 as input
  GPIO_InitStruct.Pin = COL_PIN_1 | COL_PIN_2 | COL_PIN_3 | COL_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  // Configure GPIOB 2, 12 and GPIOA 11, 12 as output
  GPIO_InitStruct.Pin =  ROW_PIN_1 | ROW_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  GPIO_InitStruct.Pin =  ROW_PIN_3 | ROW_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  

}

char GetKey(int Row) {
  int Col;
  if (HAL_GPIO_ReadPin(GPIOC, COL_PIN_1) == GPIO_PIN_SET) {
    Col = 1;
    vTaskDelay(pdMS_TO_TICKS(10));
    if (HAL_GPIO_ReadPin(GPIOC, COL_PIN_1) == GPIO_PIN_SET) {
      while (HAL_GPIO_ReadPin(GPIOC, COL_PIN_1) == GPIO_PIN_SET);
    } else {
      return ' ';
    }
  } 
  else if (HAL_GPIO_ReadPin(GPIOC, COL_PIN_2) == GPIO_PIN_SET) {
    Col = 2;
    vTaskDelay(pdMS_TO_TICKS(10));
    if (HAL_GPIO_ReadPin(GPIOC, COL_PIN_2) == GPIO_PIN_SET) {
      while (HAL_GPIO_ReadPin(GPIOC, COL_PIN_2) == GPIO_PIN_SET);
    } else {
      return ' ';
    }
  }
  else if (HAL_GPIO_ReadPin(GPIOC, COL_PIN_3) == GPIO_PIN_SET) {
    Col = 3;
    vTaskDelay(pdMS_TO_TICKS(10));
    if (HAL_GPIO_ReadPin(GPIOC, COL_PIN_3) == GPIO_PIN_SET) {
      while (HAL_GPIO_ReadPin(GPIOC, COL_PIN_3) == GPIO_PIN_SET);
    } else {
      return ' ';
    }
  }
  else if (HAL_GPIO_ReadPin(GPIOC, COL_PIN_4) == GPIO_PIN_SET) {
    Col = 4;
    vTaskDelay(pdMS_TO_TICKS(10));
    if (HAL_GPIO_ReadPin(GPIOC, COL_PIN_4) == GPIO_PIN_SET) {
      while (HAL_GPIO_ReadPin(GPIOC, COL_PIN_4) == GPIO_PIN_SET);
    } else {
      return ' ';
    }
  }
  else {
    return ' ';
  }
  return characters[Row-1][Col-1];
}


void Read_Keypad(void *parameters) {
    HAL_GPIO_WritePin(GPIOB, ROW_PIN_1, GPIO_PIN_SET);
    char KeyPress = ' ';
    printf("Read_Keypad executed\r\n");

  while (1) {
    if (KeyPress != ' '){
      printf("%c\r\n",KeyPress);
    }
    KeyPress = ' ';

    KeyPress = GetKey(1);
    if (KeyPress != ' '){continue;}
    HAL_GPIO_WritePin(GPIOB, ROW_PIN_1, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, ROW_PIN_2, GPIO_PIN_SET);

    KeyPress = GetKey(2);
    if (KeyPress != ' '){continue;}
    HAL_GPIO_WritePin(GPIOB, ROW_PIN_2, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, ROW_PIN_3, GPIO_PIN_SET);

    KeyPress = GetKey(3);
    if (KeyPress != ' '){continue;}
    HAL_GPIO_WritePin(GPIOA, ROW_PIN_3, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, ROW_PIN_4, GPIO_PIN_SET);

    KeyPress = GetKey(4);
    if (KeyPress != ' '){continue;}
    HAL_GPIO_WritePin(GPIOA, ROW_PIN_4, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, ROW_PIN_1, GPIO_PIN_SET);

  }
}