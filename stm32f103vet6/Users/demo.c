/**
 ****************************************************************************************************
 * @file        demo.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2022-06-21
 * @brief       ATK-MS53L0模块单次测量测试实验
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

#include "demo.h"
#include "./BSP/ATK_MS53L0/atk_ms53l0.h"
#include "./BSP/LED/led.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"

#define DEMO_DEV_IIC_ADDDR  (ATK_MS53L0_IIC_ADDR + 1)           /* IIC通讯地址 */
#define DEMO_DEVICE_MODE    VL53L0X_DEVICEMODE_SINGLE_RANGING   /* 单次测量模式 */
#define DEMO_BUDGET_TIME    (20*1000)                           /* 测量时间 */

/* VL53L0X设备结构体 */
static VL53L0X_Dev_t demo_dev = {
    .I2cDevAddr = ATK_MS53L0_IIC_ADDR,                          /* 上电默认IIC通讯地址 */
};

/**
 * @brief       检测设备
 * @param       dev     : 设备
 *              iic_addr: 设备IIC通讯地址
 * @retval      0: 设备无误
 *              1: 设备有误
 */
static void demo_detect_device(VL53L0X_DEV dev, uint8_t iic_addr)
{
    uint16_t module_id = 0;
    
    /* 获取设备模块ID */
    VL53L0X_RdWord(dev, VL53L0X_REG_IDENTIFICATION_MODEL_ID, &module_id);
    if (module_id != ATK_MS53L0_MODULE_ID)
    {
        printf("ATK-MS53L0 Detect Failed!\r\n");
        while (1)
        {
            LED0_TOGGLE();
            delay_ms(200);
        }
    }
    
    /* 设置设备IIC通讯地址 */
    if (iic_addr != dev->I2cDevAddr)
    {
        VL53L0X_SetDeviceAddress(dev, iic_addr << 1);
        dev->I2cDevAddr = iic_addr;
    }
    
    /* 设备一次性初始化 */
    VL53L0X_DataInit(dev);
}

/**
 * @brief       配置设备
 * @param       dev: 设备
 * @retval      0: 配置成功
 *              1: 配置失败
 */
static void demo_config_device(VL53L0X_DEV dev)
{
    uint8_t vhvsettings;
    uint8_t phasecal;
    uint32_t refspadcount;
    uint8_t isaperturespads;
    
    /* 设备基础初始化 */
    VL53L0X_StaticInit(dev);
    
    /* 参考校准 */
    VL53L0X_PerformRefCalibration(dev, &vhvsettings, &phasecal);
    
    /* 参考Spad管理 */
    VL53L0X_PerformRefSpadManagement(dev, &refspadcount, &isaperturespads);
    
    /* 设置设备模式 */
    VL53L0X_SetDeviceMode(dev, DEMO_DEVICE_MODE);
    
    /* 设置测量时间 */
    VL53L0X_SetMeasurementTimingBudgetMicroSeconds(dev, DEMO_BUDGET_TIME);
}

/**
 * @brief       例程演示入口函数
 * @param       无
 * @retval      无
 */
void demo_run(void)
{
    uint8_t ret;
    VL53L0X_RangingMeasurementData_t data;
    
    atk_ms53l0_hw_init();                               /* 硬件相关初始化 */
    VL53L0X_comms_initialise(NULL, NULL);               /* 通讯接口初始化 */
    demo_detect_device(&demo_dev, DEMO_DEV_IIC_ADDDR);  /* 检测设备 */
    demo_config_device(&demo_dev);                      /* 配置设备 */
    
    printf("ATK-MS53L0 Config Succedded!\r\n");
    
    while (1)
    {
        /* 启动设备测量 */
        VL53L0X_StartMeasurement(&demo_dev);
        
        /* 等待设备测量完毕 */
        do {
            VL53L0X_GetMeasurementDataReady(&demo_dev, &ret);
        } while (ret != 1);
        
        /* 清除中断标志 */
        VL53L0X_ClearInterruptMask(&demo_dev, 0);
        
        /* 获取测量值 */
        VL53L0X_GetRangingMeasurementData(&demo_dev, &data);
        
        printf("Distance: %dmm\r\n", data.RangeMilliMeter);
    }
}
