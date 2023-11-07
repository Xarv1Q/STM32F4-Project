#include "gpio_control.h"

void toggle_pin(GPIO_TypeDef *gpiox, int pin){
    gpiox->ODR ^= (GPIO_PIN_SET_STATE << pin);
}

void set_pin(GPIO_TypeDef *gpiox, int pin){
    gpiox->ODR = (GPIO_PIN_SET_STATE << pin);
}

void reset_pin(GPIO_TypeDef *gpiox, int pin){
    gpiox->ODR = (GPIO_PIN_RESET_STATE << pin);
}
