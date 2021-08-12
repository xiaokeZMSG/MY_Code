#ifndef __OSAL_NV_H__
#define __OSAL_NV_H__ 

#include "r_typedefs.h"
#include "osal.h"
#include "Dem_Cfg.h"
#include "eel_descriptor.h"

#if 0
//#include "Apc_diag.h"
#define ECU_FUNC_CONFIG			0x00000F90//R/W F1FB  2BYTE
#define ECU_SYS_CONFIG			0x00000F94//R/W F1FB  6BYTE
#endif

#define ECU_SERIAL_NUMBER  		0x00000FA0//R/W

typedef enum {
    ECU_TRANSPORT_MODE = 0, 
    ECU_NOMAL_MODE ,
	
}ECUFuncModeType;

typedef struct {
    uint8_t partnum[12];
}EcuOEMPartNumberType;

typedef union {
	unsigned char data[6];
	struct
	{
	    unsigned char reserved0:2;
	    unsigned char vehicle_type:1;
	    unsigned char reserved1:5;

	    unsigned char reserved2:8;
	}b;
}ECUFunctionConfigType;
typedef struct {
    uint8_t Program_Date[2];
}ECUFunctionConfig_ECU_Type;
typedef struct {
    uint8_t Version[4];
}EcuVersionsType;

typedef struct {
    uint8_t sysname[3];
}EcuOEMSysNameType;

typedef struct {
    uint8_t         config[8];
}ECUNetworkConfigType;

typedef struct {
    uint8_t         config[8];
}ECUSoftIdType;

typedef struct {
    uint8_t config[8];
}ECUHardIdType;
typedef struct {
    uint8_t config[7];
}ECULicationDataType;
typedef struct {
    uint8_t Vendor[8];
}EcuVendorIDType;
typedef struct {
    uint8_t         Program_Date[4];
}ECUManufacturingDateType;
typedef struct {
	uint8_t hw_ver[3];
}EcuHardwareVersionType;
typedef struct {
	uint8_t sw_ver[3];
}EcuSoftVersionType;
#if 1 //Modify to avoid compile error, 2017-9-21 15:54:23
typedef struct {
    uint8_t         identity[8];
}ECUNetworkConfigDIDType;
#else
typedef union {
	unsigned char data[8];
	struct
	{
	    uint8         EPS:1;/*byte 0*/
	    uint8         PEPS:1;
	    uint8         ABS_ESP:1;
	    uint8         ACU:1;
	    uint8         TCU:1;
	    uint8         BCM:1;
	    uint8         ICU:1;	
	    uint8         EMS:1;
		
	    uint8         ESCL:1;/*byte 1*/
	    uint8         T_BOX:1;
	    uint8         TPMS:1;
	    uint8         PAS:1;
	    uint8         MMI:1;
	    uint8         AC:1;
	    uint8         FRS:1;
	    uint8         SAS:1;

	    uint8         WD4:1;//4WD/*byte 2*/
	    uint8         IMMO:1;
	    uint8         SDC:1;
	    uint8         AFS:1;
	    uint8         SCU:1;
	    uint8         PTG:1;
	    uint8         FCS:1;
	    uint8         EPB:1;
		
	    uint8         reserved_0:6;/*byte 3*/
	    uint8         RCM:1;
	    uint8         reserved_1:1;
		
	    uint8         reserved_2:8;/*byte 4*/
		uint8		  reserved_3:8;/*byte 5*/
		uint8         reserved_4:8;/*byte 6*/
		uint8         reserved_5:8;/*byte 7*/
	}b;
}ECUNetworkConfigDIDType;

#endif


typedef struct {
    uint8_t         name[8];
}ECUVecleNameType;

typedef struct {
    uint8_t Date[4];
}ECUMadeDateType;

typedef struct {
    uint8_t vin[17];
}ECUVinType;


typedef struct {
    uint8_t Date[4];
}ECUInstallDateType;


typedef struct {
    uint8_t Type[2];
}ECUVehType;


typedef struct {
    uint8_t         Serial_Num[28];
}ECUSerialNumType;

typedef struct {
    uint8_t         PDSN_Num[16];
}ECUPdsnType;

typedef struct {
	ECUNetworkConfigDIDType ECUNetworkConfigDID;
	ECUVecleNameType 		ECUVecleName;
	ECUMadeDateType 		ECUMadeDate;
	ECUVinType 				ECUVin;
	ECUInstallDateType		ECUInstallDate;
	ECUFunctionConfigType   ECUFunctionConfig;
	ECUPdsnType				Mb_PDSN;
}SysNvItemInitType;

//extern SysNvItemInitType SysNvItemInit;


uint8_t initSecurityNV( void );
uint8_t initSecurityNV_back( void );

//ID for DTC
void 	  osal_nv_init( void *p );
uint8_t   osal_nv_read( uint16_t id,  uint16_t len, void *buf );
uint8_t   osal_nv_write( uint16_t id,  uint16_t len, void *buf );
uint16_t  osal_nv_item_len( uint16_t id );
bool 	  osal_nv_item_init( uint32_t id, uint16_t len, void *buf );
void osal_nv_clear_all_flash(void);
void osal_nv_clear_flash_page(unsigned char pag_no);

#endif/*__OSAL_NV_H__*/
