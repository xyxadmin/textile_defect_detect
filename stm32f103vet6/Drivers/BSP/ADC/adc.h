#ifndef __ADC_H_
#define __ADC_H_

#include "./SYSTEM/sys/sys.h"

void adc_init(void);
uint32_t adc_get_result(uint32_t ch);


#endif
