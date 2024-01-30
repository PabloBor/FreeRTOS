#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define COLS 4
#define ROWS 4

#define COL_PIN_1 GPIO_PIN_5
#define COL_PIN_2 GPIO_PIN_6
#define COL_PIN_3 GPIO_PIN_8
#define COL_PIN_4 GPIO_PIN_9

#define ROW_PIN_1 GPIO_PIN_2
#define ROW_PIN_2 GPIO_PIN_12
#define ROW_PIN_3 GPIO_PIN_11
#define ROW_PIN_4 GPIO_PIN_12

void Read_Keypad(void *parameters);
void InitMatrixKeypad();
char GetKey(int Row);
