#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 

#define RBUFFER_LEN  			128  	//定义最大接收字节数 200
#define EN_USART1_RX 			1		//使能（1）/禁止（0）串口1接收
#define BUFFER_FULL_FLAG        0x02
#define BUFFER_EMPTY_FLAG       0x01


typedef struct RingQueue
{
    u8 UsartBuffer[RBUFFER_LEN];
    u16 BufferWptr;			//串口环形缓冲区写指针
    u16 BufferRptr;		//串口环形缓冲区读指针
    u8 BufferFull;				//缓冲区满标志位   bit7~bit2:  接收到的行数 
                                                //bit0:       1：缓冲区空
                                                //bit1：      1：缓冲区满  
}RingBuffer;

//如果想串口中断接收，请不要注释以下宏定义
void RBUFF_INIT(RingBuffer* rqptr);
void RBUFF_WRITE(RingBuffer* rqptr,u8 RBData);
u8 RBUFF_READ(RingBuffer* rqptr);

void uart_init(u32 bound);

#endif


