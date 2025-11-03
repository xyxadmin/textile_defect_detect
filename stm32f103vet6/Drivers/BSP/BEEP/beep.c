#include "beep.h"


void beep_init(void){
    GPIO_InitTypeDef gpio_init_struct;
    BEEP_GPIO_CLK_ENABLE();                                                            

    gpio_init_struct.Pin = BEEP_PIN;                   
    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;            
    gpio_init_struct.Pull = GPIO_PULLUP;                    
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;          
    HAL_GPIO_Init(BEEP_PORT, &gpio_init_struct);       
}

void beep_start(void){
    for(int i = 0; i < 8; i++){
        BEEP(0);
        delay_us(200);
        BEEP(1);
        delay_us(500);
    }
}
