#include "clock_control.h"
#include "display.h"
#include "gpio_control.h"
#include "lis35de.h"

extern uint32_t ticks;

int main(){
    __enable_irq();

    init_clock();
  
    init_display();
    
    lis35de_init();
    
    uint8_t rxdata[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    uint8_t txdata[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    txdata[0] = 0x20;
    txdata[1] = 0b01000111; // Enable output reading
    CS_Enable();
    lis35de_send(&txdata,2);
    CS_Disable();


    while(1){

      CS_Enable();
      txdata[0] = 0x2d | 0x80;
      lis35de_send(&txdata,1);
      lis35de_receive(&rxdata, 1);

      CS_Disable();
      print_number(rxdata[0]);
      delay_ms(10);
    }
    
}