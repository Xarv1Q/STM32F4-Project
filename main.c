#include "stm32f411xe.h"

#define LED_PIN 6

int main(){
    //Enable IO Port B clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

    // do two dummy reads after enabling the peripheral clock, as per the errata
    volatile uint32_t dummy;
    dummy = RCC->AHB1ENR;
    dummy = RCC->AHB1ENR;
    
    //Set pin 6 & 9 as output
    GPIOB->MODER |= GPIO_MODER_MODE6_0;
    GPIOB->MODER |= GPIO_MODER_MODE9_0; 

    GPIOB->ODR = (1 << 9);
    while(1){
        for (uint32_t i = 0; i < 1000000; i++);
        GPIOB->ODR ^= (1 << LED_PIN);
    }
    
}