#include "stm32f411xe.h"

#define RCC_AHB1ENR_OFFSET (0x30U)
#define RCC_AHB1ENR ((volatile uint32_t*) (RCC_BASE + RCC_AHB1ENR_OFFSET)) 
#define LED_PIN 6
#define GPIO_ODR_OFFSET (0x14U)
#define GPIOB_ODR ((volatile uint32_t*) (GPIOB_BASE + GPIO_ODR_OFFSET))
#define GPIO_MODER_OFFSET (0x00U)
#define GPIOB_MODER ((volatile uint32_t*) (GPIOB_BASE + GPIO_MODER_OFFSET))

int main(){
    //Enable IO Port B clock
    *RCC_AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

    // do two dummy reads after enabling the peripheral clock, as per the errata
    volatile uint32_t dummy;
    dummy = *(RCC_AHB1ENR);
    dummy = *(RCC_AHB1ENR);
    
    //Set pin 6 & 9 as output
    *GPIOB_MODER |= GPIO_MODER_MODE6_0;
    *GPIOB_MODER |= GPIO_MODER_MODE9_0; 

    *GPIOB_ODR = (1 << 9);
    while(1){
        for (uint32_t i = 0; i < 1000000; i++);
        *GPIOB_ODR ^= (1 << LED_PIN);
    }
    
}