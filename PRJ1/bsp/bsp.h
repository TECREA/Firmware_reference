/**
 * @file bsp.h
 * @author My Self
 * @date 31 Mar 2021
 * @brief File containing example of bsp ( board support package) as MACROS
 *
 *
 * @see http://www.tecrea.com.co
 */

extern unsigned int PORTA,PORTB;  /*prueba*/

#ifndef __BSP_H_
#define __BSP_H_

#define PORT_LED        &PORTA
#define PORT_GPS        &PORTB


#define PIN_LED        1
#define PIN_GPS        2

/* Set or clear teh pin generally*/
#define BSP_SET_GPIO_PIN(port , pin)    LL_set_gpio(port, pin)
#define BSP_CLEAR_GPIO_PIN(port , pin)  LL_clear_gpio(port, pin)
#define BSP_READ_GPIO_PIN(port , pin)   LL_read_gpio_bit(port, pin)

/**/
#define BSP_TURN_ON_LED()               BSP_SET_GPIO_PIN(PORT_LED , PIN_LED)    /*!< turn on led */
#define BSP_TURN_OFF_LED()              BSP_CLEAR_GPIO_PIN(PORT_LED , PIN_LED)  /*!< turn off led red*/

#define BSP_TURN_ON_GPS()               BSP_SET_GPIO_PIN(PORT_GPS,PIN_GPS)
#define BSP_TURN_OFF_GPS()              BSP_CLEAR_GPIO_PIN(PORT_GPS,PIN_GPS)

#endif