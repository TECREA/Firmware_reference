#include "low_level.h"


void LL_set_gpio(volatile unsigned int *latch , int pin){
    /*add anything*/
   *latch |= (1 << pin);  // *latch = *latch | (1 << pin)
}

void LL_clear_gpio(volatile unsigned int *latch , int pin){
    /*add anything*/
    *latch &= ~(1 << pin);
}
unsigned int LL_read_gpio_bit(volatile unsigned int *latch , int pin){
    /*add anything*/
    // 1000 0100  & (1 << 3)   1000 1100 & 0000 1000 = 0000 1000
    return (*latch & (1 << pin)) == pin;
}