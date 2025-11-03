#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "key.h"
#include "oled.h"
#include "bmp.h"
#include "beep.h"
#include "convey_motor.h"
#include "forward_motor.h"
#include "lift_motor.h"
#include "esp8266.h"
#include "math.h"

#include <stdlib.h>
#include <string.h>

float forward_current_pos = 0.0;
float lift_current_pos = 0.0;
int8_t lift_dir = 0;
int8_t forward_dir = 0;
uint8_t key_cnt = 0;


uint8_t key = 0;
float motor_data[3] = {0.0,0.0,0.0};

void lift_forward_motor_init(void);
void lift_forward_motor_detect(void);
float calculate_motor_pos(float current_pos,float target_pos,int8_t *dir);
void key_reset(void);
void handle_receive(char* receive_data);
void lift_setPos(float motor_pos);
void forward_setPos(float motor_pos);
void test(void);
void case_example(void);


int main(void)
{
    HAL_Init(); /* ��ʼ�� HAL �� */
    sys_stm32_clock_init(RCC_PLL_MUL9); /* ����ʱ��, 72Mhz */
    usart1_init(115200);
    delay_init(72); /* ��ʱ��ʼ�� */
    led_init(); /* LED ��ʼ�� */
    key_init();
    //esp8266_init(115200);
    convey_motor_init();
    lift_motor_init();
    forward_motor_init();//4000
    convey_motor_start();
//    lift_motor_start();
//    lift_motor_setDirection(1);
//    lift_motor_setSpeed(2000);
//    forward_motor_start();
//    forward_motor_setDirection(1);
//    forward_motor_setSpeed(2000);
    convey_motor_setDirection(0);
    convey_motor_setSpeed(999);
    lift_motor_start();
lift_motor_setDirection(1); // 测试dir=1时的转向
lift_motor_setSpeed(2000);
delay_ms(1000); // 运行1秒
lift_motor_stop();
printf("lift_dir=1时，观察实际转向是否使位置增加\n");
delay_ms(2000);
lift_motor_start();
lift_motor_setDirection(-1); // 测试dir=-1时的转向
lift_motor_setSpeed(2000);
delay_ms(1000);
lift_motor_stop();
printf("lift_dir=-1时，观察实际转向是否使位置减少\n");
    while(1)
    {
        key_reset();
        delay_ms(100);
     }
}


void lift_forward_motor_init(void){
    float forward_target = 0.0;
    float lift_target = 0.0;
    
    forward_motor_start();
    float forward_time = calculate_motor_pos(forward_current_pos,forward_target,&forward_dir);
    forward_motor_setDirection(forward_dir);
    forward_motor_setSpeed(2000);
    delay_ms((uint16_t)(forward_time * 1000));
    forward_motor_stop();
    forward_current_pos = forward_target;
    lift_motor_start();
    float lift_time = calculate_motor_pos(lift_current_pos,lift_target,&lift_dir);
    lift_motor_setDirection(lift_dir);
    lift_motor_setSpeed(2000);
    delay_ms((uint16_t)(lift_time * 1000));
    lift_motor_stop();
    lift_current_pos = lift_target;
    
    printf("init: forward : dir = %d, pos = %f, lift : dir = %d, pos = %f\r\n",forward_dir, forward_current_pos,
    lift_dir, lift_current_pos);
    
//    lift_motor_start();
//    lift_motor_setDirection(1);
//    lift_motor_setSpeed(2000);
//    delay_ms(1500);
//    lift_motor_stop();
}
    
    
void lift_forward_motor_detect(void){
    float forward_target = 4.0;
    float lift_target = 1.1;
    
    forward_motor_start();
    float forward_time = calculate_motor_pos(forward_current_pos,forward_target,&forward_dir);
    forward_motor_setDirection(forward_dir);
    forward_motor_setSpeed(2000);
    delay_ms((uint16_t)(forward_time * 1000));
    forward_motor_stop();
    forward_current_pos = forward_target;
    lift_motor_start();
    float lift_time = calculate_motor_pos(lift_current_pos,lift_target,&lift_dir);
    lift_motor_setDirection(lift_dir);
    lift_motor_setSpeed(2000);
    delay_ms((uint16_t)(lift_time * 1000));
    //printf("forward_time = %d\r\n",(uint16_t)(forward_time * 1000));
    lift_motor_stop();
    lift_current_pos = lift_target;
    printf("detect: forward : dir = %d, pos = %f, lift : dir = %d, pos = %f\r\n",forward_dir, forward_current_pos,
    lift_dir, lift_current_pos);
}

float calculate_motor_pos(float current_pos,float target_pos,int8_t *dir){
    if(target_pos > 4.0 || target_pos < 0.0){
        return 0.0;
    }
    float pos_diff = fabs(current_pos - target_pos);
    *dir = (target_pos > current_pos) ? -1 : 1;
    //printf("cal_dir = %d\r\n",*dir);
    return pos_diff;
}

void test(void){
    float pos[10] = {4.0,2.0,3.0,2.0,1.2,0.5,0.1,2.5,3.5,0.0};
    uint8_t i = 0;
    forward_motor_start();
    for(i = 0; i < 10; i++){
        float forward_time = calculate_motor_pos(forward_current_pos,pos[i],&forward_dir);
        forward_motor_setDirection(forward_dir);
        forward_motor_setSpeed(2000);
        delay_ms((uint16_t)(forward_time * 1000));
        forward_current_pos = pos[i];
        //printf("time = %d , dir = %d\r\n",(uint16_t)(forward_time * 1000),forward_dir);
    }
    
    forward_motor_stop();

}

void key_reset(void){
    key = key_scanf();
    if(key == 1){
        lift_forward_motor_detect();
    }else if(key == 2){
        lift_forward_motor_init();
    }
}


void lift_setPos(float motor_pos){
    lift_motor_start();
    float lift_time = calculate_motor_pos(lift_current_pos,motor_pos,&lift_dir);
    lift_motor_setDirection(lift_dir);
    lift_motor_setSpeed(2000);
    delay_ms((uint16_t)(lift_time * 1000));
    lift_motor_stop();
    lift_current_pos = motor_pos;
}

void forward_setPos(float motor_pos){
    forward_motor_start();
    float forward_time = calculate_motor_pos(forward_current_pos,motor_pos,&forward_dir);
    forward_motor_setDirection(forward_dir);
    forward_motor_setSpeed(2000);
    delay_ms((uint16_t)(forward_time * 1000));
    forward_motor_stop();
    forward_current_pos = motor_pos;
}

void case_example(void){
    float forward_target = 2.0;
    float lift_target = 0.0;
    
    forward_motor_start();
    float forward_time = calculate_motor_pos(forward_current_pos,forward_target,&forward_dir);
    forward_motor_setDirection(forward_dir);
    forward_motor_setSpeed(2000);
    delay_ms((uint16_t)(forward_time * 1000));
    forward_motor_stop();
    forward_current_pos = forward_target;
    lift_motor_start();
    float lift_time = calculate_motor_pos(lift_current_pos,lift_target,&lift_dir);
    lift_motor_setDirection(lift_dir);
    lift_motor_setSpeed(2000);
    delay_ms((uint16_t)(lift_time * 1000));
    //printf("forward_time = %d\r\n",(uint16_t)(forward_time * 1000));
    lift_motor_stop();
    lift_current_pos = lift_target;
}


