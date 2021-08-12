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
 *          ��ȡ�������е�����,Ӧ���ٷ��͸����跢�ͻ���������dma buffer��
 *param:
 *     actlen: ʵ�ʽ��ܵ������ݳ���
 *     data  : �������ݻ�����
 *     len   : �������ݻ���������
 *     ring  : �������ݻ�����ָ��
 *return: 0  : OK�� 
 *       -1  : ���󣬻�����������;
 *       -2  : data ��ring ��ָ�� 
 */
int32_t pop_multidata_from_ring(struct ring *ring, uint8_t *data, uint8_t len, int32_t *actlen);
#endif
