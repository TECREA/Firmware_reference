/**
 * @file low_level.h
 * @author My Self
 * @date 31 Mar 2021
 * @brief File containing example of low level device driver
 *
 *
 * @see http://www.tecrea.com.co
 */
#ifndef __LOW_LEVEL_H   /*entra cuando no esta definida*/
#define __LOW_LEVEL_H

/** doxygen
 * @brief setea un pin
 * @param latch puerto a setear
 * @param pin  pin a usar
*/
void LL_set_gpio(volatile unsigned int *latch , int pin);

/** doxygen
 * @brief clear un pin
 * @param latch puerto a clear
 * @param pin  pin a usar
*/
void LL_clear_gpio(volatile unsigned int *Latch , int pin);

/** 
 * @brief read un pin
 * @param latch puerto a leer
 * @param pin  pin del puerto a leer
*/
unsigned int LL_read_gpio_bit(volatile unsigned int *latch , int pin);
#endif

