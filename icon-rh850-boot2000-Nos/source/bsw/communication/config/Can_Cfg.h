#ifndef __CAN_CFG_H
#define __CAN_CFG_H
#include "r_typedefs.h"
#include "Can.h"

typedef struct {
  uint32_t lword[4];
}can_cre_type;

#define USE_CAN_CTRL_B
#define FILTER_EXT_LEN 25//21
#define CAN_HW_TRANSMIT_CANCELLATION  STD_OFF
//#define FILTER_MASK_NUM 20
#define FILTER_MASK_NUM 16 //How many RXIMR on this devices ?

extern uint32_t CanDrv_ID_Filter[FILTER_EXT_LEN];
extern const uint32_t can_hw_filter_mask[FILTER_MASK_NUM];
extern const Can_ConfigType Can_Config;
extern const can_cre_type CAN_RX_RULE_TABLE[];
#define CAN_RX_RULE_TABLE_NUM  (8)
#endif
