
/**
 * @file main.c
 * @author My Self
 * @date 31 Mar 2021
 * @brief File containing example of bsp,low-level and peripheral drivers
 *
 *
 * @see http://www.tecrea.com.co
 */
#include <stdio.h>
#include "bsp/low_level/low_level.h"
#include "bsp/bsp.h"

#define APP_MAX_VALUE   4095

int main(){
    uint16_t adc_value;
    /*↓↓ Bien usada bsp ↓↓*/
    /*Encapsulado para usar en la aplicación sin depender de que pin , puerto o micro se usa*/
    BSP_TURN_ON_LED();
    BSP_TURN_ON_GPS();

    /* ↓↓ Mal usada la bsp, dehacerlo sí mejor uso LL_clear_gpio(port,pin) ↓↓*/
    BSP_CLEAR_GPIO_PIN(&PORTA,1);   /*Aplicación dependiente del MCU*/

    if(   (adc_value = APP_MAX_VALUE ) != 0 ){ // Rule 13.1 misra c 2004
        adc_value = 3;
    }else{ 
        //Rule 14.9
        //Rule 14.10
        /* no change in value of adc_value */
    }

    return 0;
}

//http://caxapa.ru/thumbs/468328/misra-c-2004.pdf
//http://my.ldrasoftware.co.uk/repository//miscellaneous/Misra-c_2012_compliance.pdf