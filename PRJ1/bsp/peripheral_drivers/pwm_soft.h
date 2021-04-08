/**
 * @file pwm_soft.h
 * @author your name (you@domain.com)
 * @brief software pwm generator
 * @version 0.0.1
 * @date 2021-03-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __PWM_SOFT_H_
#define __PWM_SOFT_H_

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

#include <stdint.h>

#define RESOLUTION_BIT_PWM 255  	/*0-255 Output Pwm*/
#define PORCETAGE_MAX	   100      /*0- 100% Output Pwm*/

typedef void (*PwmOutput_FCN)(void *, uint16_t, int);   /* Pointer to function for the HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)*/

/**
 * Struct containing all data pwm
 * */
typedef struct {
	volatile uint8_t Counter;		/* Counter For the timer ( Ramp)*/
	volatile uint8_t DutyCycle;		/* Duty Cycle 0-255 */
	void * GPIO_Port ;
	uint16_t GPIO_Pin;
	int PinState;
	PwmOutput_FCN PwmOutput_Function;
}PwmData_t;


/*=====================================================================================
 * 								PWM Generator
 * ====================================================================================
 * */
/**
 *  @brief Function init parameters for the pwm .
 *  @param obj Structure containing all data from the pwm.
 *  @param pointer to function for wrappers output Pwm
 *  @return void
 * */
void Pwm_Init(PwmData_t * Obj, PwmOutput_FCN PwmOutput_FCN,void* GPIO_Port , uint16_t GPIO_CH_Pin);
/**
 *  @brief Function Update timer( ramp) for the pwm .
 *  @param obj Structure containing all data from the pwm.
 *  @return void
 * */
void Pwm_Update(PwmData_t * Obj);

/**
 *  @brief Function change pwm duty cycle.
 *  @param obj Structure containing all data from the pwm.
 *  @param Set Duty cicle
 *  @param Flag_Porcentage, if 1  DutyC is 0- 100% , if DutyC is 0 DutyC is 0-255
 *  @return void
 * */
void Pwm_DutyCycle(PwmData_t * Obj,uint8_t DutyC, uint8_t Flag_Porcentage);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif