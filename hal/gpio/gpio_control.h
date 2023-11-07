#include "stm32f411xe.h"
#include "gpio_definition.h"

#define GPIO_PIN_RESET_STATE 0
#define GPIO_PIN_SET_STATE 1

void toggle_pin(GPIO_TypeDef *gpiox, int pin);

void set_pin(GPIO_TypeDef *gpiox, int pin);

void reset_pin(GPIO_TypeDef *gpiox, int pin);