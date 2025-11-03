#ifndef _KEY_H_
#define _KEY_H_

#include "sys.h"

#define KEY_PORT GPIOE
#define KEY1_PIN GPIO_PIN_13
#define KEY2_PIN GPIO_PIN_14

#define KEY_ENABLE() do{__HAL_RCC_GPIOE_CLK_ENABLE();}while(0)

#define KEY1 HAL_GPIO_ReadPin(KEY_PORT,KEY1_PIN)
#define KEY2 HAL_GPIO_ReadPin(KEY_PORT,KEY2_PIN)

void key_init(void);
uint8_t key_scanf(void);


#endif
