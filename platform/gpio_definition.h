#include "stm32f411xe.h"

//7-segment 4 digit display config
#define DISP_PIN_A 6
#define DISP_PIN_B 4
#define DISP_PIN_C 3
#define DISP_PIN_D 1
#define DISP_PIN_E 2
#define DISP_PIN_F 5
#define DISP_PIN_G 0
#define DISP_PIN_DP 7

#define DISP_PIN_COM1 11
#define DISP_PIN_COM2 10
#define DISP_PIN_COM3 9
#define DISP_PIN_COM4 8
#define DISP_PINGROUP GPIOC

//lis35de accelerometer config
#define PLATFORM_LIS35DE_SCK_PINGROUP GPIOB
#define PLATFORM_LIS35DE_SCK_PIN  3 //PB3

#define PLATFORM_LIS35DE_MISO_PINGROUP GPIOA
#define PLATFORM_LIS35DE_MISO_PIN 6 //PA6

#define PLATFORM_LIS35DE_MOSI_PINGROUP GPIOA
#define PLATFORM_LIS35DE_MOSI_PIN 7 //PA7

#define PLATFORM_LIS35DE_CS_PINGROUP GPIOA
#define PLATFORM_LIS35DE_CS_PIN 4 //PA4