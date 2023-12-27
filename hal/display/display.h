/*
    Driver for 7-segment display.
    Prerequisites:
        Pinout defined inside gpio_definition.h
        All pins connected to one pin group
    Capabilities:
        - Reset whole display by using reset_display function
        - Print any number between 0 and 9999 using print_number func. Any number above it will be treated with mod 9999.
*/
#include "gpio_definition.h"
#include "gpio_control.h"
#include "clock_control.h"

void init_display(void);

void reset_display(void);

void print_number(uint32_t num);
