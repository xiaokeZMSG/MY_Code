#include "Com.h"
#include "CanAppComRxCallback.h"
#include "Com_Internal.h"
//#include "apc_can.h"
#include "dem.h"
#include "Dcm_Cbk.h"
#include "OSAL_Nv.h"


//int64_t canmsg_rcv_passed_mask;
uint8_t canmsg_rcv_passed_mask[SGWM_RX_FACTORY_0x77A];
extern ECUFunctionConfigType ECUFunctionConfig;

uint32_t canmsg_rcv_passed_mask31_0;
uint32_t canmsg_rcv_passed_mask63_32;
uint32_t canmsg_rcv_passed_mask95_64;



void Set_CamMsg_Rcv_Passed_Mask(uint8_t ComRxId)
{
	if((0<=ComRxId)&&(ComRxId<=31))
	{
		canmsg_rcv_passed_mask31_0 |= (1<<ComRxId);
	}
	else if((32<=ComRxId)&&(ComRxId<=63))
	{
		canmsg_rcv_passed_mask63_32 |= (1<<(ComRxId-32));
	}
	else if((64<=ComRxId)&&(ComRxId<=95))
	{
		canmsg_rcv_passed_mask95_64 |= (1<<(ComRxId-64));
	}
}

void Clr_CamMsg_Rcv_Passed_Mask(uint8_t ComRxId)
{
	if((0<=ComRxId)&&(ComRxId<=31))
	{
		canmsg_rcv_passed_mask31_0 &= (~(1<<ComRxId));
	}
	else if((32<=ComRxId)&&(ComRxId<=63))
	{
		canmsg_rcv_passed_mask63_32 &= (~(1<<(ComRxId-32)));
	}
	else if((64<=ComRxId)&&(ComRxId<=95))
	{
		canmsg_rcv_passed_mask95_64 &= (~(1<<(ComRxId-64)));
	}
}


uint8_t Get_CamMsg_Rcv_Passed_Mask(uint8_t ComRxId)
{
	uint32_t value=0;
	uint8_t re =0;
	if((0<=ComRxId)&&(ComRxId<=31))
	{
		value =  (canmsg_rcv_passed_mask31_0 & (1<<ComRxId));
	}
	else if((32<=ComRxId)&&(ComRxId<=63))
	{
		value = (canmsg_rcv_passed_mask63_32 & (1<<(ComRxId-32)));
	}
	else if((64<=ComRxId)&&(ComRxId<=95))
	{
		value = (canmsg_rcv_passed_mask95_64 & (1<<(ComRxId-64)));
	}

	re = (value?1:0);
	return re;
}





/***********************Message timeout****************************/
void RX_MMI_0x2A2_TimeoutCallout (uint16_t signal_id)
{

}
void RX_GW_0x287_TimeoutCallout (uint16_t signal_id)
{
	

}

/***********************Message rcv callout****************************/
