/*
 * Copyright (c) 20109-2020, SAIC  Team
 * file: sip-ring.h
 *  Description:  This file contains ring
 *
 * Change Logs:
 * Date           Author         VER      Notes        
 * 2020-02-11    maguangdong     0.1    First edition  
 * 2020-03-09    maguangdong     0.2    add"pop_multidata_from_ring" 
 *
 */
#ifndef __SIP_RING_H__
#define __SIP_RING_H__

#include "r_device.h"
#include <string.h>
//#include "osal.h"

struct ring{ 
  uint8_t *data;
  uint8_t front;
  uint8_t rear;
  uint8_t count;
  uint8_t size;
};

int32_t init_ring(struct ring *ring, uint8_t *data, uint8_t size);
int32_t push_data_to_ring(struct ring *ring, uint8_t data);
int32_t pop_data_from_ring(struct ring *ring, uint8_t *data);
uint8_t get_count_from_ring(struct ring *ring);
/*
 *function: pop_multidata_from_ring
 *          读取缓冲区中的数据,应用再发送给外设发送缓冲区，如dma buffer等
 *param:
 *     actlen: 实际接受到的数据长度
 *     data  : 接收数据缓冲区
 *     len   : 接收数据缓冲区长度
 *     ring  : 环形数据缓冲区指针
 *return: 0  : OK； 
 *       -1  : 错误，缓冲区无数据;
 *       -2  : data 或ring 空指针 
 */
int32_t pop_multidata_from_ring(struct ring *ring, uint8_t *data, uint8_t len, int32_t *actlen);
#endif
