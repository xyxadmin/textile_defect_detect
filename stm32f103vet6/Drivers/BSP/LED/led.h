#ifndef __LED_H
#define __LED_H

#include "./SYSTEM/sys/sys.h"

#define LED0_PORT GPIOC
#define LED0_PIN  GPIO_PIN_6
#define LED0_ENABLE() do{__HAL_RCC_GPIOC_CLK_ENABLE();}while(0)

#define LED1_PORT GPIOC 
#define LED1_PIN  GPIO_PIN_7
#define LED1_ENABLE() do{__HAL_RCC_GPIOC_CLK_ENABLE();}while(0)


#define LED2_PORT GPIOB 
#define LED2_PIN  GPIO_PIN_5
#define LED2_ENABLE() do{__HAL_RCC_GPIOB_CLK_ENABLE();}while(0)

#define LED0(x) do{x?\
    HAL_GPIO_WritePin(LED0_PORT,LED0_PIN,GPIO_PIN_SET):\
    HAL_GPIO_WritePin(LED0_PORT,LED0_PIN,GPIO_PIN_RESET);}while(0)

#define LED1(x) do{x?\
    HAL_GPIO_WritePin(LED1_PORT,LED1_PIN,GPIO_PIN_SET):\
    HAL_GPIO_WritePin(LED1_PORT,LED1_PIN,GPIO_PIN_RESET);}while(0) 


#define LED2(x) do{x?\
    HAL_GPIO_WritePin(LED2_PORT,LED2_PIN,GPIO_PIN_SET):\
    HAL_GPIO_WritePin(LED2_PORT,LED2_PIN,GPIO_PIN_RESET);}while(0)    

#define LED0_toggle()  do{HAL_GPIO_TogglePin(LED0_PORT,LED0_PIN);}while(0)
#define LED1_toggle()  do{HAL_GPIO_TogglePin(LED1_PORT,LED1_PIN);}while(0)
#define LED2_toggle()  do{HAL_GPIO_TogglePin(LED2_PORT,LED2_PIN);}while(0)



void led_init(void);

#endif
