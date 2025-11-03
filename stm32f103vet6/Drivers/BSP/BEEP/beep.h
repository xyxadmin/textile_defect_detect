#ifndef _BEEP_H
#define _BEEP_H

#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/delay/delay.h"

#define BEEP_PORT GPIOB
#define BEEP_PIN GPIO_PIN_4
#define BEEP_GPIO_CLK_ENABLE() do{ __HAL_RCC_GPIOD_CLK_ENABLE(); }while(0) 
#define BEEP(x)   do{ x ? \
                      HAL_GPIO_WritePin(BEEP_PORT, BEEP_PIN, GPIO_PIN_SET) : \
                      HAL_GPIO_WritePin(BEEP_PORT, BEEP_PIN, GPIO_PIN_RESET); \
                  }while(0) 

void beep_init(void);
void beep_start(void);

                  
#endif   
