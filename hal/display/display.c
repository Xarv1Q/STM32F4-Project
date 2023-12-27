#include "display.h"

void init_display(void){
  //TODO: Remove hardcode
  DISP_PINGROUP->MODER |= GPIO_MODER_MODE0_0 | GPIO_MODER_MODE1_0 | GPIO_MODER_MODE2_0 | GPIO_MODER_MODE3_0 | GPIO_MODER_MODE4_0 \
                    | GPIO_MODER_MODE5_0 | GPIO_MODER_MODE6_0 | GPIO_MODER_MODE7_0 | GPIO_MODER_MODE8_0 | GPIO_MODER_MODE9_0 \
                    | GPIO_MODER_MODE10_0 | GPIO_MODER_MODE11_0;
}

void reset_display(void){
  reset_pin(DISP_PINGROUP, DISP_PIN_COM1);
  reset_pin(DISP_PINGROUP, DISP_PIN_COM2);
  reset_pin(DISP_PINGROUP, DISP_PIN_COM3);
  reset_pin(DISP_PINGROUP, DISP_PIN_COM4);

  reset_pin(DISP_PINGROUP, DISP_PIN_A);
  reset_pin(DISP_PINGROUP, DISP_PIN_B);
  reset_pin(DISP_PINGROUP, DISP_PIN_C);
  reset_pin(DISP_PINGROUP, DISP_PIN_D);
  reset_pin(DISP_PINGROUP, DISP_PIN_E);
  reset_pin(DISP_PINGROUP, DISP_PIN_F);
  reset_pin(DISP_PINGROUP, DISP_PIN_G);
  reset_pin(DISP_PINGROUP, DISP_PIN_DP);
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
      DISP_PINGROUP->ODR ^= (!(shift == DISP_PIN_COM1) << DISP_PIN_COM1);
      DISP_PINGROUP->ODR ^= (!(shift == DISP_PIN_COM2) << DISP_PIN_COM2);
      DISP_PINGROUP->ODR ^= (!(shift == DISP_PIN_COM3) << DISP_PIN_COM3);
      DISP_PINGROUP->ODR ^= (!(shift == DISP_PIN_COM4) << DISP_PIN_COM4);

      //Print desired number
      switch(mod_num){
        case 1:
          toggle_pin(DISP_PINGROUP, DISP_PIN_B);
          toggle_pin(DISP_PINGROUP, DISP_PIN_C);
          break;
        case 2:
          toggle_pin(DISP_PINGROUP, DISP_PIN_A);
          toggle_pin(DISP_PINGROUP, DISP_PIN_B);
          toggle_pin(DISP_PINGROUP, DISP_PIN_G);
          toggle_pin(DISP_PINGROUP, DISP_PIN_E);
          toggle_pin(DISP_PINGROUP, DISP_PIN_D);
          break;
        case 3:
          toggle_pin(DISP_PINGROUP, DISP_PIN_A);
          toggle_pin(DISP_PINGROUP, DISP_PIN_B);
          toggle_pin(DISP_PINGROUP, DISP_PIN_G);
          toggle_pin(DISP_PINGROUP, DISP_PIN_C);
          toggle_pin(DISP_PINGROUP, DISP_PIN_D);
          break;
        case 4:
          toggle_pin(DISP_PINGROUP, DISP_PIN_F);
          toggle_pin(DISP_PINGROUP, DISP_PIN_G);
          toggle_pin(DISP_PINGROUP, DISP_PIN_B);
          toggle_pin(DISP_PINGROUP, DISP_PIN_C);
          break;
        case 5:
          toggle_pin(DISP_PINGROUP, DISP_PIN_A);
          toggle_pin(DISP_PINGROUP, DISP_PIN_F);
          toggle_pin(DISP_PINGROUP, DISP_PIN_G);
          toggle_pin(DISP_PINGROUP, DISP_PIN_C);
          toggle_pin(DISP_PINGROUP, DISP_PIN_D);
          break;
        case 6:
          toggle_pin(DISP_PINGROUP, DISP_PIN_A);
          toggle_pin(DISP_PINGROUP, DISP_PIN_F);
          toggle_pin(DISP_PINGROUP, DISP_PIN_G);
          toggle_pin(DISP_PINGROUP, DISP_PIN_E);
          toggle_pin(DISP_PINGROUP, DISP_PIN_D);
          toggle_pin(DISP_PINGROUP, DISP_PIN_C);
          break;
        case 7:
          toggle_pin(DISP_PINGROUP, DISP_PIN_A);
          toggle_pin(DISP_PINGROUP, DISP_PIN_B);
          toggle_pin(DISP_PINGROUP, DISP_PIN_C);
          break;
        case 8:
          toggle_pin(DISP_PINGROUP, DISP_PIN_A);
          toggle_pin(DISP_PINGROUP, DISP_PIN_B);
          toggle_pin(DISP_PINGROUP, DISP_PIN_C);
          toggle_pin(DISP_PINGROUP, DISP_PIN_D);
          toggle_pin(DISP_PINGROUP, DISP_PIN_E);
          toggle_pin(DISP_PINGROUP, DISP_PIN_F);
          toggle_pin(DISP_PINGROUP, DISP_PIN_G);
          break;
        case 9:
          toggle_pin(DISP_PINGROUP, DISP_PIN_A);
          toggle_pin(DISP_PINGROUP, DISP_PIN_B);
          toggle_pin(DISP_PINGROUP, DISP_PIN_C);
          toggle_pin(DISP_PINGROUP, DISP_PIN_F);
          toggle_pin(DISP_PINGROUP, DISP_PIN_G);
          break;
        case 0:
          toggle_pin(DISP_PINGROUP, DISP_PIN_A);
          toggle_pin(DISP_PINGROUP, DISP_PIN_B);
          toggle_pin(DISP_PINGROUP, DISP_PIN_C);
          toggle_pin(DISP_PINGROUP, DISP_PIN_D);
          toggle_pin(DISP_PINGROUP, DISP_PIN_E);
          toggle_pin(DISP_PINGROUP, DISP_PIN_F);
          break;
      }
        
      num = (num - mod_num) / 10;
      shift = shift + 1;
      delay_ms(1);
    }  
}
