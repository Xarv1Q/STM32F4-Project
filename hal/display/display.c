#include "display.h"

void reset_display(void){
  reset_pin(GPIOC, DISP_PIN_COM1);
  reset_pin(GPIOC, DISP_PIN_COM2);
  reset_pin(GPIOC, DISP_PIN_COM3);
  reset_pin(GPIOC, DISP_PIN_COM4);

  reset_pin(GPIOC, DISP_PIN_A);
  reset_pin(GPIOC, DISP_PIN_B);
  reset_pin(GPIOC, DISP_PIN_C);
  reset_pin(GPIOC, DISP_PIN_D);
  reset_pin(GPIOC, DISP_PIN_E);
  reset_pin(GPIOC, DISP_PIN_F);
  reset_pin(GPIOC, DISP_PIN_G);
  reset_pin(GPIOC, DISP_PIN_DP);
}

void print_number(uint32_t num){
    uint8_t mod_num = 0 , shift = 8;
    if (num > 9999){
      num = num % 9999;
    }

    while (num > 0){
  
      mod_num = num % 10;
      
      // Zero display
      reset_display();

      // Enable only one desired channel
      GPIOC->ODR ^= (!(shift == DISP_PIN_COM1) << DISP_PIN_COM1);
      GPIOC->ODR ^= (!(shift == DISP_PIN_COM2) << DISP_PIN_COM2);
      GPIOC->ODR ^= (!(shift == DISP_PIN_COM3) << DISP_PIN_COM3);
      GPIOC->ODR ^= (!(shift == DISP_PIN_COM4) << DISP_PIN_COM4);

      //Print desired number
      switch(mod_num){
        case 1:
          toggle_pin(GPIOC, DISP_PIN_B);
          toggle_pin(GPIOC, DISP_PIN_C);
          break;
        case 2:
          toggle_pin(GPIOC, DISP_PIN_A);
          toggle_pin(GPIOC, DISP_PIN_B);
          toggle_pin(GPIOC, DISP_PIN_G);
          toggle_pin(GPIOC, DISP_PIN_E);
          toggle_pin(GPIOC, DISP_PIN_D);
          break;
        case 3:
          toggle_pin(GPIOC, DISP_PIN_A);
          toggle_pin(GPIOC, DISP_PIN_B);
          toggle_pin(GPIOC, DISP_PIN_G);
          toggle_pin(GPIOC, DISP_PIN_C);
          toggle_pin(GPIOC, DISP_PIN_D);
          break;
        case 4:
          toggle_pin(GPIOC, DISP_PIN_F);
          toggle_pin(GPIOC, DISP_PIN_G);
          toggle_pin(GPIOC, DISP_PIN_B);
          toggle_pin(GPIOC, DISP_PIN_C);
          break;
        case 5:
          toggle_pin(GPIOC, DISP_PIN_A);
          toggle_pin(GPIOC, DISP_PIN_F);
          toggle_pin(GPIOC, DISP_PIN_G);
          toggle_pin(GPIOC, DISP_PIN_C);
          toggle_pin(GPIOC, DISP_PIN_D);
          break;
        case 6:
          toggle_pin(GPIOC, DISP_PIN_A);
          toggle_pin(GPIOC, DISP_PIN_F);
          toggle_pin(GPIOC, DISP_PIN_G);
          toggle_pin(GPIOC, DISP_PIN_E);
          toggle_pin(GPIOC, DISP_PIN_D);
          toggle_pin(GPIOC, DISP_PIN_C);
          break;
        case 7:
          toggle_pin(GPIOC, DISP_PIN_A);
          toggle_pin(GPIOC, DISP_PIN_B);
          toggle_pin(GPIOC, DISP_PIN_C);
          break;
        case 8:
          toggle_pin(GPIOC, DISP_PIN_A);
          toggle_pin(GPIOC, DISP_PIN_B);
          toggle_pin(GPIOC, DISP_PIN_C);
          toggle_pin(GPIOC, DISP_PIN_D);
          toggle_pin(GPIOC, DISP_PIN_E);
          toggle_pin(GPIOC, DISP_PIN_F);
          toggle_pin(GPIOC, DISP_PIN_G);
          break;
        case 9:
          toggle_pin(GPIOC, DISP_PIN_A);
          toggle_pin(GPIOC, DISP_PIN_B);
          toggle_pin(GPIOC, DISP_PIN_C);
          toggle_pin(GPIOC, DISP_PIN_F);
          toggle_pin(GPIOC, DISP_PIN_G);
          break;
        case 0:
          toggle_pin(GPIOC, DISP_PIN_A);
          toggle_pin(GPIOC, DISP_PIN_B);
          toggle_pin(GPIOC, DISP_PIN_C);
          toggle_pin(GPIOC, DISP_PIN_D);
          toggle_pin(GPIOC, DISP_PIN_E);
          toggle_pin(GPIOC, DISP_PIN_F);
          break;
      }
        
      num = (num - mod_num) / 10;
      shift = shift + 1;
      delay_ms(1);
    }  
}
