/**
 ****************************************************************************************************
 * @file        atk_ms53l0.h
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

#ifndef __ATK_MS53L0_H
#define __ATK_MS53L0_H

#include "./SYSTEM/sys/sys.h"
#include "vl53l0x_api.h"

/* 引脚定义 */
#define ATK_MS53L0_XSH_GPIO_PORT            GPIOA
#define ATK_MS53L0_XSH_GPIO_PIN             GPIO_PIN_15
#define ATK_MS53L0_XSH_GPIO_CLK_ENABLE()    do{ __HAL_RCC_GPIOA_CLK_ENABLE();   \
                                                __HAL_RCC_AFIO_CLK_ENABLE();    \
                                                __HAL_AFIO_REMAP_SWJ_NOJTAG();  \
                                            }while(0)

/* IO操作 */
#define ATK_MS53L0_XSH(x)                   do{ x ?                                                                                     \
                                                HAL_GPIO_WritePin(ATK_MS53L0_XSH_GPIO_PORT, ATK_MS53L0_XSH_GPIO_PIN, GPIO_PIN_SET) :    \
                                                HAL_GPIO_WritePin(ATK_MS53L0_XSH_GPIO_PORT, ATK_MS53L0_XSH_GPIO_PIN, GPIO_PIN_RESET);   \
                                            }while(0)

/* ATK-MS53L0模块上电默认IIC通讯地址 */
#define ATK_MS53L0_IIC_ADDR                 0x29

/* ATK-MS53L0模块ID */
#define ATK_MS53L0_MODULE_ID                0xEEAA

/* 操作函数 */
void atk_ms53l0_hw_init(void);  /* ATK-MS53L0模块硬件初始化 */

#endif
