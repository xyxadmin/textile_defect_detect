#ifndef __LIFT_MOTOR_H
#define __LIFT_MOTOR_H

#include "./SYSTEM/sys/sys.h"


// GPIO定义
#define LIFT_MOTOR_IN1_PIN     GPIO_PIN_2
#define LIFT_MOTOR_IN1_PORT    GPIOE
#define LIFT_MOTOR_IN2_PIN     GPIO_PIN_3
#define LIFT_MOTOR_IN2_PORT    GPIOE
#define LIFT_MOTOR_IN3_PIN     GPIO_PIN_4
#define LIFT_MOTOR_IN3_PORT    GPIOE
#define LIFT_MOTOR_IN4_PIN     GPIO_PIN_5
#define LIFT_MOTOR_IN4_PORT    GPIOE

// 函数声明
void lift_motor_init(void);
void lift_motor_start(void);
void lift_motor_setDirection(int8_t dir);
void lift_motor_stop(void);
void lift_motor_setSpeed(uint16_t speed);

void update(void);

extern int8_t lift_direction;


#endif
