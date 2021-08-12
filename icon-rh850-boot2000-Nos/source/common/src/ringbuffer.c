/*
 * Copyright (c) 20109-2020, SAIC  Team
 * file: sip-ring.c
 *  Description:  This file contains ring
 *
 * Change Logs:
 * Date           Author         VER      Notes        
 * 2020-02-11    maguangdong     0.1    First edition  
 * 2020-03-09    maguangdong     0.2    add"pop_multidata_from_ring" 
 */

#include "ringbuffer.h"
int32_t init_ring(struct ring *ring, uint8_t *data, uint8_t size)
{
    ring->count = 0;
    ring->front = 0;
    ring->rear  = 0;
    ring->size  = size;
    ring->data  = data;
    return 0;
}
int32_t push_data_to_ring(struct ring *ring, uint8_t data)
{
  int32_t ret = -1;

  if(ring->count < ring->size)
  {
     ring->data[ring->front] = data;
     ring->count++;
     ring->front++;
     if(ring->front >= ring->size)
        ring->front = 0;
     ret = 0;
  }  
  
  return ret;
}
int32_t pop_data_from_ring(struct ring *ring, uint8_t *data)
{
  int32_t ret = -1;

  if(ring->count )
  {
     *data = ring->data[ring->rear];
     ring->count--;
     ring->rear++;
     if(ring->rear >= ring->size)
        ring->rear = 0;
     ret = 0;
  }

  return ret;
}
/*
 *function: pop_multidata_from_ring
 *          读取缓冲区中的数据,应用在在发送给外设发送缓冲区，如dma buffer等
 *param:
 *     actlen: 实际接受到的数据长度
 *     data  : 接收数据缓冲区
 *     len   : 接收数据缓冲区长度
 *     ring  : 环形数据缓冲区指针
 *return: 0  : OK； 
 *       -1  : 错误，缓冲区无数据;
 *       -2  : data 或ring 空指针 
 */
int32_t pop_multidata_from_ring(struct ring *ring, uint8_t *data, uint8_t len, int32_t *actlen)
{
  int32_t ret = -1;
  uint32_t length;
  if((NULL==ring)||(NULL==data)||(NULL==actlen))
  {
      ret = -2;
  }
  else
  {

    if(ring->count )
    {
      if(len > ring->count)
         length = (int32_t)ring->count;
      else
         length = len;
      *actlen = (int32_t)length;
      while(length > 0)
      {
         *data = ring->data[ring->rear];
         ring->count--;
         ring->rear++;
         if(ring->rear >= ring->size)
            ring->rear = 0;
         length--;
         data++;
      }
      
    }
    else
    {
       *actlen = 0;
    }
    ret=0;

  }
  return ret;
}
uint8_t get_count_from_ring(struct ring *ring)
{
   return ring->count;
}
