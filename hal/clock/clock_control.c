#include "clock_control.h"

void init_clock(void){
    volatile uint32_t dummy;

    //Configure HSE
    RCC->CR |= RCC_CR_HSEBYP_Msk | RCC_CR_HSEON_Msk;
    while (!(RCC->CR & RCC_CR_HSERDY_Msk));
    
    //Enable power controller
    RCC->APB1ENR |= RCC_APB1ENR_PWREN_Msk;
    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN_Msk;
    dummy = RCC->APB1ENR;
    dummy = RCC->APB1ENR;
    dummy = RCC->APB2ENR;
    dummy = RCC->APB2ENR;
    //Enable IO Port C clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    PWR->CR |= PWR_CR_VOS_Msk;
    
    // Configure flash controller
    FLASH->ACR |= FLASH_ACR_LATENCY_3WS;

    // Clear PLLM, PLLN and PLLP bits
    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM_Msk |
                    RCC_PLLCFGR_PLLN_Msk |
                    RCC_PLLCFGR_PLLP_Msk);
    
    // Set PLLM, PLLN and PLLP, and select HSE as PLL source
    RCC->PLLCFGR |= ((4 << RCC_PLLCFGR_PLLM_Pos) | 
                    (160 << RCC_PLLCFGR_PLLN_Pos) |
                    (1 << RCC_PLLCFGR_PLLP_Pos) |
                    (1 << RCC_PLLCFGR_PLLSRC_Pos));

    // Enable PLL and wait for ready
    RCC->CR |= RCC_CR_PLLON_Msk;
    while (! (RCC->CR & RCC_CR_PLLRDY_Msk));

    // Select PLL output as system clock
    RCC->CFGR |= (RCC_CFGR_SW_PLL << RCC_CFGR_SW_Pos);
    while (! (RCC->CFGR & RCC_CFGR_SWS_PLL));

    SysTick_Config(TICKS_PER_INTERRUPT);
}

uint32_t ticks;

void systick_handler()
{
  ticks++;
}

void delay_ms(uint32_t milliseconds)
{
  uint32_t start = ticks;
  uint32_t end = start + milliseconds;

  if (end < start) // handle overflow
  {
    while (ticks > start); // wait for ticks to wrap around to zero
  }

  while (ticks < end);
}