#include "convey_motor.h"


TIM_HandleTypeDef htim3;

void convey_motor_init(void){
GPIO_InitTypeDef GPIO_InitStruct = {0};
    TIM_OC_InitTypeDef sConfigOC = {0};

    // 使能时钟
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_TIM3_CLK_ENABLE();

    // 配置方向控制引脚
    GPIO_InitStruct.Pin = CONVEY_MOTOR_IN1_PIN | CONVEY_MOTOR_IN2_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    // 配置PWM引脚
    GPIO_InitStruct.Pin = CONVEY_MOTOR_PWM_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(CONVEY_MOTOR_PWM_PORT, &GPIO_InitStruct);

    // 配置TIM3
    htim3.Instance = TIM3;
    htim3.Init.Prescaler = 71;         // 72MHz / (71+1) = 1MHz
    htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim3.Init.Period = 1000-1;           // PWM频率 = 1MHz / 1000 = 1kHz
    htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    HAL_TIM_PWM_Init(&htim3);

    // 配置PWM通道
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 0;               // 初始占空比0%
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1);

    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}

/* 中断服务函数 */
void TIM3_IRQHandler(void) {
    HAL_TIM_IRQHandler(&htim3);
}


void convey_motor_start(void){
     HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}

void convey_motor_stop(void){
     HAL_GPIO_WritePin(CONVEY_MOTOR_IN1_PORT, CONVEY_MOTOR_IN1_PIN, GPIO_PIN_RESET);
     HAL_GPIO_WritePin(CONVEY_MOTOR_IN2_PORT, CONVEY_MOTOR_IN2_PIN, GPIO_PIN_RESET);
     __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
}

void convey_motor_setSpeed(uint16_t speed){
     __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, speed);
}

void convey_motor_setDirection(uint8_t dir){
     if(dir == 0) {  // 正转
        HAL_GPIO_WritePin(CONVEY_MOTOR_IN1_PORT, CONVEY_MOTOR_IN1_PIN, GPIO_PIN_SET);
        HAL_GPIO_WritePin(CONVEY_MOTOR_IN2_PORT, CONVEY_MOTOR_IN2_PIN, GPIO_PIN_RESET);
    } else {        // 反转
        HAL_GPIO_WritePin(CONVEY_MOTOR_IN1_PORT, CONVEY_MOTOR_IN1_PIN, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(CONVEY_MOTOR_IN2_PORT, CONVEY_MOTOR_IN2_PIN, GPIO_PIN_SET);
    }
}

