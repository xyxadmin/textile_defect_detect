#include "adc.h"

ADC_HandleTypeDef adc_handle = {0};

void adc_init(void){
    adc_handle.Instance = ADC3;
    adc_handle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
    adc_handle.Init.ScanConvMode = ADC_SCAN_DISABLE;
    adc_handle.Init.ContinuousConvMode = DISABLE;
    adc_handle.Init.NbrOfConversion = 1;
    adc_handle.Init.DiscontinuousConvMode = DISABLE;
    adc_handle.Init.NbrOfDiscConversion = 0;
    adc_handle.Init.ExternalTrigConv = ADC_SOFTWARE_START;
    HAL_ADC_Init(&adc_handle);
    HAL_ADCEx_Calibration_Start(&adc_handle);
}

void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc){
    if(hadc->Instance == ADC3){
        RCC_PeriphCLKInitTypeDef  adc_clk_init = {0};
        __HAL_RCC_ADC3_CLK_ENABLE();
        __HAL_RCC_GPIOC_CLK_ENABLE();
        GPIO_InitTypeDef gpio_struct;
        gpio_struct.Pin = GPIO_PIN_0;
        gpio_struct.Mode = GPIO_MODE_ANALOG;
        gpio_struct.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(GPIOC,&gpio_struct);
        adc_clk_init.PeriphClockSelection = RCC_PERIPHCLK_ADC;
        adc_clk_init.AdcClockSelection = RCC_ADCPCLK2_DIV6;
        HAL_RCCEx_PeriphCLKConfig(&adc_clk_init);
    }
}

void adc_channel_config(ADC_HandleTypeDef* hadc,uint32_t ch,uint32_t rank,uint32_t stime){
    ADC_ChannelConfTypeDef adc_ch_config = {0};
    adc_ch_config.Channel = ch;
    adc_ch_config.Rank = rank;
    adc_ch_config.SamplingTime = stime;
    HAL_ADC_ConfigChannel(&adc_handle,&adc_ch_config);
}

uint32_t adc_get_result(uint32_t ch){
    adc_channel_config(&adc_handle,ch,ADC_REGULAR_RANK_1,ADC_SAMPLETIME_239CYCLES_5);
    HAL_ADC_Start(&adc_handle);
    HAL_ADC_PollForConversion(&adc_handle,10);
    
    return (uint16_t)HAL_ADC_GetValue(&adc_handle);
}

