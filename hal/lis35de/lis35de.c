#include "lis35de.h"

void lis35de_init(void){
    //Configure all pins
    SPI1->CR1 |= (0b1 << 0x0); //Set CPHA: Second clock transition is data read: rising edge this case
    SPI1->CR1 |= (0b1 << 0x1); //Set CPOL: IDLE High
    SPI1->CR1 |= (0b1 << 0x2); //Set master
    SPI1->CR1 |= (0b101 << 0x3); //Set clk divider to 8 (Related to 80MHz output clk)
    SPI1->CR1 |= (0b0 << 0x7); //Set MSB first transmission type
    SPI1->CR1 |= (0b1 << 0x8); //0x8 is software assigned SS
    SPI1->CR1 |= (0b1 << 0x9); //Internal SS = 1
    SPI1->CR1 |= (0b0 << 0xa); //Full duplex mode
    SPI1->CR1 |= (0b0 << 0xb); //Set DFF to 8-bit
    //0x12 is way of sending crc, for now unused
    SPI1->CR1 |= (0b0 << 0xd); //Disable CRC FOR NOW
    //0x14 is bidirectional output enable, we're using unidirectional
    SPI1->CR1 |= (0b0 << 0xf); //2-line unidirectional data mode
    SPI1->CR2 = 0;
    SPI1->CR1 |= (0b1 << 0x6); //Enable SPI
    
    //TODO: if pin is higher than 7, AFR[1] needs to be used
    LIS35DE_CS_PINGROUP->MODER |= (0b01 << LIS35DE_CS*2); // Set pin in GPO mode
    LIS35DE_CS_PINGROUP->PUPDR |= (0b01 << LIS35DE_CS*2); // Pull-up
    LIS35DE_CS_PINGROUP->AFR[0] |= (0b0101 << LIS35DE_CS*4); //set alternate function as SPI1 CS

    LIS35DE_MISO_PINGROUP->MODER |= (0b10 << LIS35DE_MISO*2); // set pin as alternate function
    LIS35DE_MISO_PINGROUP->PUPDR |= (0b01 << LIS35DE_MISO*2); // Pull-up
    LIS35DE_MISO_PINGROUP->OSPEEDR |= (0b11 << LIS35DE_MISO*2); //Set pin as high speed
    LIS35DE_MISO_PINGROUP->AFR[0] |= (0b0101 << LIS35DE_MISO*4); //set alternate function as SPI1 MISO

    LIS35DE_MOSI_PINGROUP->MODER |= (0b10 << LIS35DE_MOSI*2); // set pin as alternate function
    LIS35DE_MOSI_PINGROUP->OSPEEDR |= (0b11 << LIS35DE_MOSI*2); //Set pin as high speed
    LIS35DE_MOSI_PINGROUP->AFR[0] |= (0b0101 << LIS35DE_MOSI*4); //set alternate function as SPI1 MOSI

    LIS35DE_SCK_PINGROUP->MODER |= (0b10 << LIS35DE_SCK*2); // set pin as alternate function
    LIS35DE_SCK_PINGROUP->OSPEEDR |= (0b11 << LIS35DE_SCK*2); //Set pin as high speed
    LIS35DE_SCK_PINGROUP->AFR[0] |= (0b0101 << LIS35DE_SCK*4); //set alternate function as SPI1 SCK 

}

void lis35de_send(uint8_t *data, int size){
    SPI_Transmit(data, size);
}

void lis35de_receive (uint8_t *data, int size){
    SPI_Receive(data, size);
}

void CS_Enable (void)
{
    LIS35DE_CS_PINGROUP->BSRR |= (1 << LIS35DE_CS) << 16;
}

void CS_Disable (void)
{
    LIS35DE_CS_PINGROUP->BSRR |= (1 << LIS35DE_CS);

}
