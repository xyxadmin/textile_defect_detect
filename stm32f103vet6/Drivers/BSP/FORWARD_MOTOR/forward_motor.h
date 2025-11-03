#ifndef __FORWARD_MOTOR_H
#define __FORWARD_MOTOR_H


#include "./SYSTEM/sys/sys.h"
#include "lift_motor.h"

// GPIO定义
#define MOTOR_IN1_PIN     GPIO_PIN_2
#define MOTOR_IN1_PORT    GPIOD
#define MOTOR_IN2_PIN     GPIO_PIN_3
#define MOTOR_IN2_PORT    GPIOD
#define MOTOR_IN3_PIN     GPIO_PIN_4
#define MOTOR_IN3_PORT    GPIOD
#define MOTOR_IN4_PIN     GPIO_PIN_5
#define MOTOR_IN4_PORT    GPIOD

// 函数声明
void forward_motor_init(void);
void forward_motor_start(void);
void forward_motor_setDirection(int8_t dir);
void forward_motor_stop(void);
void forward_motor_setSpeed(uint16_t speed);

#endif 
