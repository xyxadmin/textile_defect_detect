#ifndef __CONVEY_MOTOR_H
#define __CONVEY_MOTOR_H


#include "./SYSTEM/sys/sys.h"

// GPIO定义
#define CONVEY_MOTOR_IN1_PIN     GPIO_PIN_6
#define CONVEY_MOTOR_IN1_PORT    GPIOD
#define CONVEY_MOTOR_IN2_PIN     GPIO_PIN_7
#define CONVEY_MOTOR_IN2_PORT    GPIOD
#define CONVEY_MOTOR_PWM_PIN     GPIO_PIN_6    //
#define CONVEY_MOTOR_PWM_PORT    GPIOA

extern volatile uint16_t target_pulse;
extern TIM_HandleTypeDef htim3;

// 函数声明
void convey_motor_init(void);
void convey_motor_start(void);
void convey_motor_stop(void);
void convey_motor_setSpeed(uint16_t speed);
void convey_motor_setDirection(uint8_t dir);


#endif 
