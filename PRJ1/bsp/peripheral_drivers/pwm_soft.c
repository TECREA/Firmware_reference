/*
 * Pwm_Generator.c
 *
 *  Created on: Jun 11, 2019
 *      Author: ingeniero04
 */


#include "pwm_soft.h"

/*Note : all pwm are the fixed frecuency */

/**
 *  @brief Function init parameters for the pwm .
 *  @param obj Structure containing all data from the pwm.
 *  @param pointer to function for wrappers output Pwm
 *  @param pointer GPIO port output pwm
 *  @param GPIO pin output pwm
 *  @return void
 * */
void Pwm_Init(PwmData_t * Obj, PwmOutput_FCN PwmOutput_FCN,void* GPIO_Port , uint16_t GPIO_Pin){
	Obj->Counter = 0;
	Obj->DutyCycle = 0;
	Obj->GPIO_Port = GPIO_Port;
	Obj->GPIO_Pin = GPIO_Pin;
	Obj->PinState = 0;
	Obj->PwmOutput_Function = PwmOutput_FCN;   /*Init pwm output*/
}


/**
 *  @brief Function Update timer( ramp) for the pwm .
 *  @param obj Structure containing all data from the pwm.
 *  @return void
 * */
void Pwm_Update(PwmData_t * Obj){
	Obj->Counter++;   /*Overflow automatically 0-255*/

	/*Puntero a wrapper de función que maneja los pines de salidas*/
	Obj->PwmOutput_Function(Obj->GPIO_Port,Obj->GPIO_Pin ,Obj->Counter < Obj->DutyCycle);
}

/**
 *  @brief Function change pwm duty cycle.
 *  @param obj Structure containing all data from the pwm.
 *  @param Set Duty cicle
 *  @param Flag_Porcentage, if 1  DutyC is 0- 100% , if DutyC is 0 DutyC is 0-255
 *  @return void
 * */
void Pwm_DutyCycle(PwmData_t * Obj,uint8_t DutyC, uint8_t Flag_Porcentage){
	/* 0-100 % O  0 - 255*/

	if(Flag_Porcentage){
		DutyC =	DutyC > PORCETAGE_MAX ? PORCETAGE_MAX : DutyC;
		Obj->DutyCycle = (uint8_t)( DutyC*RESOLUTION_BIT_PWM / PORCETAGE_MAX ); /*0-100%*/
	}
	else Obj->DutyCycle = DutyC  ; /*0-255*/
}

/*
systick(){ // 1ms

Pwm_Update()

}

timer0(){ 0.255ms
    Pwm_Update()

}*/