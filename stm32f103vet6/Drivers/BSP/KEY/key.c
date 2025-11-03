#include "key.h"
#include "delay.h"

void key_init(void){
    GPIO_InitTypeDef gpio_struct = {0};
    KEY_ENABLE();
    gpio_struct.Pin = KEY1_PIN | KEY2_PIN;
    gpio_struct.Mode = GPIO_MODE_INPUT;
    gpio_struct.Pull = GPIO_PULLUP;
    gpio_struct.Speed = GPIO_SPEED_FREQ_HIGH;

    HAL_GPIO_Init(KEY_PORT,&gpio_struct);
}

uint8_t key_scanf(void){
    if(KEY1 == 0 || KEY2 == 0){
        delay_ms(20);
        if(KEY1 == 0){
            while(KEY1 == 0);
            return 1;
        }else if(KEY2 == 0){
            while(KEY2 == 0);
            return 2;
        }
    }
    return 0;

}

