#include "ComM.h"

#define COMM_NETWORK_HANDLE 0
#define NM_NETWORK_HANDLE 0
#define COMM_MAIN_PERIOD 10
ComM_ChannelType  ComM_Channel = {
	COMM_BUS_TYPE_CAN,
	COMM_NETWORK_HANDLE,
	NM_NETWORK_HANDLE,
	COMM_NM_VARIANT_FULL,
	COMM_MAIN_PERIOD,
	100,
	0,//Channel number
} ;
ComM_ChannelType  *ComM_Channel_inter = &ComM_Channel;

ComM_UserType const ComM_User = {
	&ComM_Channel_inter,
	1
} ;

ComM_ConfigType  const ComM_Config = {
	&ComM_Channel,
	&ComM_User,
} ;

