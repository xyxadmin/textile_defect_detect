#ifndef _ESP8266_H_
#define _ESP8266_H_

#include "./SYSTEM/sys/sys.h"



#define ESP8266_RX_BUF_SIZE         128
#define ESP8266_TX_BUF_SIZE         64

#define ESP8266_EOK                 0
#define ESP8266_ERROR               1
#define ESP8266_ETIMEOUT            2
#define ESP8266_EINVAL              3

#define ESP8266_STA_MODE            1
#define ESP8266_AP_MODE             2
#define ESP8266_STA_AP_MODE         3

#define ESP8266_SINGLE_CONNECTION   0
#define ESP8266_MULTI_CONNECTION    1

#define WIFI_SSID                   "alientek_softap"
#define WIFI_PWD                    "12345678"

#define TCP_SERVER_IP               "192.168.4.1"
#define TCP_SERVER_PORT             "8080"

void esp8266_init(uint32_t baudrate);
uint16_t esp8266_receive_data(char* rece_data);
void esp8266_send_data(char *fmt, ...);
void esp8266_test(void);

#endif

