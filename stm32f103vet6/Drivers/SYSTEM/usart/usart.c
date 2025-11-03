
#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "string.h"
#include "stdarg.h"
#include "./BSP/LED/led.h"


/* 如果使用os,则包括下面的头文件即可. */
#if SYS_SUPPORT_OS
#include "os.h" /* os 使用 */
#endif

/******************************************************************************************/
/* 加入以下代码, 支持printf函数, 而不需要选择use MicroLIB */

#if 1

#if (__ARMCC_VERSION >= 6010050)            /* 使用AC6编译器时 */
__asm(".global __use_no_semihosting\n\t");  /* 声明不使用半主机模式 */
__asm(".global __ARM_use_no_argv \n\t");    /* AC6下需要声明main函数为无参数格式，否则部分例程可能出现半主机模式 */

#else
/* 使用AC5编译器时, 要在这里定义__FILE 和 不使用半主机模式 */
#pragma import(__use_no_semihosting)

struct __FILE
{
    int handle;
    /* Whatever you require here. If the only file you are using is */
    /* standard output using printf() for debugging, no file handling */
    /* is required. */
};

#endif

/* 不使用半主机模式，至少需要重定义_ttywrch\_sys_exit\_sys_command_string函数,以同时兼容AC6和AC5模式 */
int _ttywrch(int ch)
{
    ch = ch;
    return ch;
}

/* 定义_sys_exit()以避免使用半主机模式 */
void _sys_exit(int x)
{
    x = x;
}

char *_sys_command_string(char *cmd, int len)
{
    return NULL;
}


/* FILE 在 stdio.h里面定义. */
FILE __stdout;

/* MDK下需要重定义fputc函数, printf函数最终会通过调用fputc输出字符串到串口 */
int fputc(int ch, FILE *f)
{
    while ((USART_UX->SR & 0X40) == 0);     /* 等待上一个字符发送完成 */

    USART_UX->DR = (uint8_t)ch;             /* 将要发送的字符 ch 写入到DR寄存器 */
    return ch;
}
#endif
/******************************************************************************************/




uint8_t usart1_rx_buf[USART1_RX_BUF_SIZE];
uint16_t usart1_rx_len = 0;

uint8_t usart1_temp[10];
uint8_t usart1_tx_buf[USART1_TX_BUF_SIZE];
int rx_flag = 0;

UART_HandleTypeDef g_uart1_handle;  /* UART句柄 */


void usart1_init(uint32_t baudrate)
{
    /*UART 初始化设置*/
    g_uart1_handle.Instance = USART_UX;                                       /* USART_UX */
    g_uart1_handle.Init.BaudRate = baudrate;                                  /* 波特率 */
    g_uart1_handle.Init.WordLength = UART_WORDLENGTH_8B;                      /* 字长为8位数据格式 */
    g_uart1_handle.Init.StopBits = UART_STOPBITS_1;                           /* 一个停止位 */
    g_uart1_handle.Init.Parity = UART_PARITY_NONE;                            /* 无奇偶校验位 */
    g_uart1_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;                      /* 无硬件流控 */
    g_uart1_handle.Init.Mode = UART_MODE_TX_RX;                               /* 收发模式 */
    HAL_UART_Init(&g_uart1_handle);                                           /* HAL_UART_Init()会使能UART1 */
}


void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    GPIO_InitTypeDef gpio_init_struct;

    if (huart->Instance == USART_UX)                            /* 如果是串口1，进行串口1 MSP初始化 */
    {
        USART_TX_GPIO_CLK_ENABLE();                             /* 使能串口TX脚时钟 */
        USART_RX_GPIO_CLK_ENABLE();                             /* 使能串口RX脚时钟 */
        USART_UX_CLK_ENABLE();                                  /* 使能串口时钟 */

        gpio_init_struct.Pin = USART_TX_GPIO_PIN;               /* 串口发送引脚号 */
        gpio_init_struct.Mode = GPIO_MODE_AF_PP;                /* 复用推挽输出 */
        gpio_init_struct.Pull = GPIO_PULLUP;                    /* 上拉 */
        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;          /* IO速度设置为高速 */
        HAL_GPIO_Init(USART_TX_GPIO_PORT, &gpio_init_struct);
                
        gpio_init_struct.Pin = USART_RX_GPIO_PIN;               /* 串口RX脚 模式设置 */
        gpio_init_struct.Mode = GPIO_MODE_AF_INPUT;    
        HAL_GPIO_Init(USART_RX_GPIO_PORT, &gpio_init_struct);   /* 串口RX脚 必须设置成输入模式 */
        

        HAL_NVIC_EnableIRQ(USART_UX_IRQn);                      /* 使能USART1中断通道 */
        HAL_NVIC_SetPriority(USART_UX_IRQn, 3, 3);              /* 组2，最低优先级:抢占优先级3，子优先级3 */
        
        __HAL_UART_ENABLE_IT(huart,UART_IT_RXNE);
        __HAL_UART_ENABLE_IT(huart,UART_IT_IDLE);
    }else if(huart->Instance == USART2){
        __HAL_RCC_GPIOA_CLK_ENABLE();
        __HAL_RCC_USART2_CLK_ENABLE();
        
         gpio_init_struct.Pin = GPIO_PIN_2;               /* 串口发送引脚号 */
        gpio_init_struct.Mode = GPIO_MODE_AF_PP;                /* 复用推挽输出 */
        gpio_init_struct.Pull = GPIO_PULLUP;                    /* 上拉 */
        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;          /* IO速度设置为高速 */
        HAL_GPIO_Init(GPIOA, &gpio_init_struct);
                
        gpio_init_struct.Pin = GPIO_PIN_3;               /* 串口RX脚 模式设置 */
        gpio_init_struct.Mode = GPIO_MODE_AF_INPUT;    
        HAL_GPIO_Init(GPIOA, &gpio_init_struct);   /* 串口RX脚 必须设置成输入模式 */
        

        HAL_NVIC_EnableIRQ(USART2_IRQn);                      /* 使能USART1中断通道 */
        HAL_NVIC_SetPriority(USART2_IRQn, 1, 3);              /* 组2，最低优先级:抢占优先级3，子优先级3 */
        
        __HAL_UART_ENABLE_IT(huart,UART_IT_RXNE);
        //__HAL_UART_ENABLE_IT(huart,UART_IT_IDLE);
    }else if(huart->Instance == USART3){
        __HAL_RCC_GPIOB_CLK_ENABLE();
        __HAL_RCC_USART3_CLK_ENABLE();
        
         gpio_init_struct.Pin = GPIO_PIN_10;               /* 串口发送引脚号 */
        gpio_init_struct.Mode = GPIO_MODE_AF_PP;                /* 复用推挽输出 */
        gpio_init_struct.Pull = GPIO_PULLUP;                    /* 上拉 */
        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;          /* IO速度设置为高速 */
        HAL_GPIO_Init(GPIOB, &gpio_init_struct);
                
        gpio_init_struct.Pin = GPIO_PIN_11;               /* 串口RX脚 模式设置 */
        gpio_init_struct.Mode = GPIO_MODE_AF_INPUT;    
        HAL_GPIO_Init(GPIOB, &gpio_init_struct);   /* 串口RX脚 必须设置成输入模式 */
        

        HAL_NVIC_EnableIRQ(USART3_IRQn);                      /* 使能USART1中断通道 */
        HAL_NVIC_SetPriority(USART3_IRQn, 2, 3);              /* 组2，最低优先级:抢占优先级3，子优先级3 */
        
        __HAL_UART_ENABLE_IT(huart,UART_IT_RXNE);
        __HAL_UART_ENABLE_IT(huart,UART_IT_IDLE);
    }
}

void usart1_rx_clear(void){
    memset(usart1_rx_buf,0,sizeof(usart1_rx_buf));
    usart1_rx_len = 0;
}

void USART_UX_IRQHandler(void)
{
    uint8_t receive_data = 0;
    if(__HAL_UART_GET_FLAG(&g_uart1_handle,UART_FLAG_RXNE) != RESET){
        if(usart1_rx_len >= sizeof(usart1_rx_buf)){
            usart1_rx_len = 0;
        }
        HAL_UART_Receive(&g_uart1_handle,&receive_data,1,1000);
        usart1_rx_buf[usart1_rx_len++] = receive_data;
        //HAL_UART_Transmit(&g_uart1_handle,&receive_data,1,1000); 
    }
    if(__HAL_UART_GET_FLAG(&g_uart1_handle,UART_FLAG_IDLE) != RESET){
        //printf("usart1== %s\r\n",usart1_rx_buf);
        //memcpy(usart1_temp,usart1_rx_buf,strlen((const char*)usart1_rx_buf));
        //usart1_rx_clear();
        rx_flag = 1;
        __HAL_UART_CLEAR_IDLEFLAG(&g_uart1_handle);
    }
}

void usart1_send_data(char *fmt, ...)
{
    va_list ap;
    uint16_t len;
    
    va_start(ap, fmt);
    vsprintf((char *)usart1_tx_buf, fmt, ap);
    va_end(ap);
    
    len = strlen((const char *)usart1_tx_buf);
    HAL_UART_Transmit(&g_uart1_handle, usart1_tx_buf, len, 100);
}
uint16_t usart1_receive_data(char* rece_data)
{
    if(rx_flag == 1)
    {
        //printf("esp8266 recv: %s\r\n", esp8266_rx_buf);
        memcpy(rece_data,usart1_rx_buf,strlen((const char*)usart1_rx_buf));
        usart1_rx_clear();
        rx_flag = 0;
        return strlen((const char*)rece_data);
    }
    return 0;
}



