#include "./BSP/LED/led.h"

void led_init(void){

    GPIO_InitTypeDef gpio_struct;
    LED0_ENABLE();
    gpio_struct.Pin = LED0_PIN | LED1_PIN | LED2_PIN;
    gpio_struct.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_struct.Pull = GPIO_NOPULL;
    gpio_struct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED0_PORT,&gpio_struct);
    
    HAL_GPIO_Init(LED2_PORT,&gpio_struct);
    
    
    LED0(1);
    LED1(1);
    LED2(1);
}