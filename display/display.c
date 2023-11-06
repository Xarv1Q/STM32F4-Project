#include "display.h"


void reset_display(void){
  GPIOC->ODR = (0 << DISP_PIN_COM1);
  GPIOC->ODR = (0 << DISP_PIN_COM2);
  GPIOC->ODR = (0 << DISP_PIN_COM3);
  GPIOC->ODR = (0 << DISP_PIN_COM4);

  GPIOC->ODR = (0 << DISP_PIN_A);
  GPIOC->ODR = (0 << DISP_PIN_B);
  GPIOC->ODR = (0 << DISP_PIN_C);
  GPIOC->ODR = (0 << DISP_PIN_D);
  GPIOC->ODR = (0 << DISP_PIN_E);
  GPIOC->ODR = (0 << DISP_PIN_F);
  GPIOC->ODR = (0 << DISP_PIN_G);
  GPIOC->ODR = (0 << DISP_PIN_DP);
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
          GPIOC->ODR ^= (1 << DISP_PIN_B);
          GPIOC->ODR ^= (1 << DISP_PIN_C);
          break;
        case 2:
          GPIOC->ODR ^= (1 << DISP_PIN_A);
          GPIOC->ODR ^= (1 << DISP_PIN_B);
          GPIOC->ODR ^= (1 << DISP_PIN_G);
          GPIOC->ODR ^= (1 << DISP_PIN_E);
          GPIOC->ODR ^= (1 << DISP_PIN_D);
          break;
        case 3:
          GPIOC->ODR ^= (1 << DISP_PIN_A);
          GPIOC->ODR ^= (1 << DISP_PIN_B);
          GPIOC->ODR ^= (1 << DISP_PIN_G);
          GPIOC->ODR ^= (1 << DISP_PIN_C);
          GPIOC->ODR ^= (1 << DISP_PIN_D);
          break;
        case 4:
          GPIOC->ODR ^= (1 << DISP_PIN_F);
          GPIOC->ODR ^= (1 << DISP_PIN_G);
          GPIOC->ODR ^= (1 << DISP_PIN_B);
          GPIOC->ODR ^= (1 << DISP_PIN_C);
          break;
        case 5:
          GPIOC->ODR ^= (1 << DISP_PIN_A);
          GPIOC->ODR ^= (1 << DISP_PIN_F);
          GPIOC->ODR ^= (1 << DISP_PIN_G);
          GPIOC->ODR ^= (1 << DISP_PIN_C);
          GPIOC->ODR ^= (1 << DISP_PIN_D);
          break;
        case 6:
          GPIOC->ODR ^= (1 << DISP_PIN_A);
          GPIOC->ODR ^= (1 << DISP_PIN_F);
          GPIOC->ODR ^= (1 << DISP_PIN_G);
          GPIOC->ODR ^= (1 << DISP_PIN_E);
          GPIOC->ODR ^= (1 << DISP_PIN_D);
          GPIOC->ODR ^= (1 << DISP_PIN_C);
          break;
        case 7:
          GPIOC->ODR ^= (1 << DISP_PIN_A);
          GPIOC->ODR ^= (1 << DISP_PIN_B);
          GPIOC->ODR ^= (1 << DISP_PIN_C);
          break;
        case 8:
          GPIOC->ODR ^= (1 << DISP_PIN_A);
          GPIOC->ODR ^= (1 << DISP_PIN_B);
          GPIOC->ODR ^= (1 << DISP_PIN_C);
          GPIOC->ODR ^= (1 << DISP_PIN_D);
          GPIOC->ODR ^= (1 << DISP_PIN_E);
          GPIOC->ODR ^= (1 << DISP_PIN_F);
          GPIOC->ODR ^= (1 << DISP_PIN_G);
          break;
        case 9:
          GPIOC->ODR ^= (1 << DISP_PIN_A);
          GPIOC->ODR ^= (1 << DISP_PIN_B);
          GPIOC->ODR ^= (1 << DISP_PIN_C);
          GPIOC->ODR ^= (1 << DISP_PIN_F);
          GPIOC->ODR ^= (1 << DISP_PIN_G);
          break;
        case 0:
          GPIOC->ODR ^= (1 << DISP_PIN_A);
          GPIOC->ODR ^= (1 << DISP_PIN_B);
          GPIOC->ODR ^= (1 << DISP_PIN_C);
          GPIOC->ODR ^= (1 << DISP_PIN_D);
          GPIOC->ODR ^= (1 << DISP_PIN_E);
          GPIOC->ODR ^= (1 << DISP_PIN_F);
          break;
      }
        
      num = (num - mod_num) / 10;
      shift = shift + 1;
      delay_ms(1);
    }  
}
