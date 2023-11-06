/*
    Driver for 7-segment display
    Capabilities:
    TBF
*/
#include "stm32f411xe.h"

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

void reset_display(void);

void print_number(uint32_t num);
