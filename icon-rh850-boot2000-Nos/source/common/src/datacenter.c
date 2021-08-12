/*
 * Copyright (c) 20109-2020, SAIC  Team
 * file: datacenter.c
 *  Description:  This file contains sip channel be setting
 *
 * Change Logs:
 * Date           Author         VER   Notes
 * 2020-03-11    maguangdong     0.1   First edition
 */

#include "datacenter.h"

//Can_Param_Set g_db_Can_Param_Set;
//Data_Message_T key_msg;
veh_data_T veh_data;
/********************CAN ÐéÄâ¼ü ****************************/




int32_t db_init_data(void)
{
    memset((char*)&veh_data,0,sizeof(veh_data_T));
    return 0;
}

/********************CAN ÐéÄâ¼ü END*************************/