/**
 ****************************************************************************************************
 * @file        atk_ms53l0.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2022-06-21
 * @brief       ATK-MS53L0模块驱动代码
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 STM32F103开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 ****************************************************************************************************
 */

#include "./BSP/ATK_MS53L0/atk_ms53l0.h"
#include "./SYSTEM/delay/delay.h"

/**
 * @brief       ATK-MS53L0模块硬件复位
 * @param       无
 * @retval      无
 */
static void atk_ms53l0_hw_reset(void)
{
    ATK_MS53L0_XSH(0);
    delay_ms(30);
    ATK_MS53L0_XSH(1);
    delay_ms(30);
}

/**
 * @brief       ATK-MS53L0模块硬件初始化
 * @param       无
 * @retval      无
 */
void atk_ms53l0_hw_init(void)
{
    GPIO_InitTypeDef gpio_init_struct = {0};
    
    ATK_MS53L0_XSH_GPIO_CLK_ENABLE();
    
    gpio_init_struct.Pin    = ATK_MS53L0_XSH_GPIO_PIN;
    gpio_init_struct.Mode   = GPIO_MODE_OUTPUT_PP;
    gpio_init_struct.Pull   = GPIO_PULLUP;
    gpio_init_struct.Speed  = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(ATK_MS53L0_XSH_GPIO_PORT, &gpio_init_struct);
    
    atk_ms53l0_hw_reset();
}
