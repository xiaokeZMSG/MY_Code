#include "Nm.h"
Nm_ChannelType Nm_Channel = {
	NM_BUSNM_CANNM,
	0,//BusNmNetworkHandle;
	0,//ComMNetworkHandle;
} ;

Nm_ConfigType Nm_Config = {
    &Nm_Channel,
};

