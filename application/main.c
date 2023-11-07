#include "clock_control.h"
#include "display.h"
#include "gpio_control.h"

extern uint32_t ticks;

int main(){
    init_clock();
    
    SysTick_Config(100000);
    __enable_irq();

    //TODO: Make function in gpio_control
    GPIOC->MODER |= GPIO_MODER_MODE0_0 | GPIO_MODER_MODE1_0 | GPIO_MODER_MODE2_0 | GPIO_MODER_MODE3_0 | GPIO_MODER_MODE4_0 \
                    | GPIO_MODER_MODE5_0 | GPIO_MODER_MODE6_0 | GPIO_MODER_MODE7_0 | GPIO_MODER_MODE8_0 | GPIO_MODER_MODE9_0 \
                    | GPIO_MODER_MODE10_0 | GPIO_MODER_MODE11_0;
    
    while(1){
      print_number(ticks);
    }
    
}