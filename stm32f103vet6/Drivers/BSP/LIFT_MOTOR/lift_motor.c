#include "lift_motor.h"


TIM_HandleTypeDef htim5;
int8_t lift_direction = 0; // 1:正转，-1:反转

// 步进序列（全步模式）
static const uint8_t lift_step_sequence[4][4] = {
    {1, 0, 1, 0}, // Step 1: IN1=1, IN2=0, IN3=1, IN4=0
    {0, 1, 1, 0}, // Step 2: IN1=0, IN2=1, IN3=1, IN4=0
    {0, 1, 0, 1}, // Step 3: IN1=0, IN2=1, IN3=0, IN4=1
    {1, 0, 0, 1}  // Step 4: IN1=1, IN2=0, IN3=0, IN4=1
};
uint8_t lift_motor_current_step = 0;


void lift_motor_init(void){
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // 使能GPIO和定时器时钟
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_TIM5_CLK_ENABLE();

    // 配置GPIO为输出模式
    GPIO_InitStruct.Pin = LIFT_MOTOR_IN1_PIN | LIFT_MOTOR_IN2_PIN | LIFT_MOTOR_IN3_PIN | LIFT_MOTOR_IN4_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    // 初始化定时器2配置
    htim5.Instance = TIM5;
    htim5.Init.Prescaler = 71;          // 72MHz / (71+1) = 1MHz
    htim5.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim5.Init.Period = 999;            // 初始频率1kHz
    htim5.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim5.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_TIM_Base_Init(&htim5);

    // 使能定时器更新中断
    __HAL_TIM_ENABLE_IT(&htim5, TIM_IT_UPDATE);

    // 配置NVIC
    HAL_NVIC_SetPriority(TIM5_IRQn, 2, 2);
    HAL_NVIC_EnableIRQ(TIM5_IRQn);
    
    //HAL_TIM_Base_Start_IT(&htim5); // 启动定时器中断
}

void lift_motor_start(void){
    HAL_TIM_Base_Start_IT(&htim5); // 启动定时器中断
}

void lift_motor_setDirection(int8_t dir){
    __disable_irq();
    if (dir > 0) lift_direction = 1;
    else if (dir < 0) lift_direction = -1;
    __enable_irq();
}

void lift_motor_stop(void){
    HAL_TIM_Base_Stop_IT(&htim5);  // 停止定时器
    // 关闭所有电机引脚
    HAL_GPIO_WritePin(LIFT_MOTOR_IN1_PORT, LIFT_MOTOR_IN1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LIFT_MOTOR_IN2_PORT, LIFT_MOTOR_IN2_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LIFT_MOTOR_IN3_PORT, LIFT_MOTOR_IN3_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LIFT_MOTOR_IN4_PORT, LIFT_MOTOR_IN4_PIN, GPIO_PIN_RESET);
}

void lift_motor_setSpeed(uint16_t speed){
     __HAL_TIM_SET_AUTORELOAD(&htim5, speed); // 设置新的周期值调整速度
}

// 定时器中断处理函数
void TIM5_IRQHandler(void) {
    HAL_TIM_IRQHandler(&htim5);
}

void update(void){
    __disable_irq();
    // 更新步进电机引脚状态
        HAL_GPIO_WritePin(LIFT_MOTOR_IN1_PORT, LIFT_MOTOR_IN1_PIN, lift_step_sequence[lift_motor_current_step][0] ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(LIFT_MOTOR_IN2_PORT, LIFT_MOTOR_IN2_PIN, lift_step_sequence[lift_motor_current_step][1] ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(LIFT_MOTOR_IN3_PORT, LIFT_MOTOR_IN3_PIN, lift_step_sequence[lift_motor_current_step][2] ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(LIFT_MOTOR_IN4_PORT, LIFT_MOTOR_IN4_PIN, lift_step_sequence[lift_motor_current_step][3] ? GPIO_PIN_SET : GPIO_PIN_RESET);
      
        // 更新步数
        lift_motor_current_step = (lift_motor_current_step + lift_direction + 4) % 4; // +4避免负数
        __enable_irq();
}



