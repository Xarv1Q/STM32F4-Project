#include "stm32f411xe.h"
#include "clock_config.h"

void init_clock(void);

void systick_handler();

void delay_ms(uint32_t milliseconds);
