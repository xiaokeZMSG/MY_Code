/*
 * file: iic_drv_soft.h
 * Description:  i2c software driver
 * Change Logs:
 * Date           Author          VER  Notes
 * 2018-07-02    mgd              0.1  First edition
 */
#ifndef __IIC_DRV_SOFT_H__
#define __IIC_DRV_SOFT_H__ 

#include "r_device.h"



#define  RTC_FD             (0u)
#define  TPA6404_FD         (1u)
#define  TPS43331_FD        (2u)
#define  DSLR_FD            TPS43331_FD
#define  E52400B62C_FD      (3u)
#define  TCA6408A_FD        (4u)
#define  USB_ELMOS1_FD      (5u)
#define  USB_ELMOS2_FD      (6u)
#define  QBA_FD             (7u)
//#define DEV_ADDR  RTC_ADDRESS /* device address */
typedef uint8_t Std_ReturnType;
#define E_OK                     (Std_ReturnType)0
#define E_NOT_OK                 (Std_ReturnType)1

#define E_NO_DTC_AVAILABLE       (Std_ReturnType)2
#define E_SESSION_NOT_ALLOWED    (Std_ReturnType)4
#define E_PROTOCOL_NOT_ALLOWED   (Std_ReturnType)5
#define E_REQUEST_NOT_ACCEPTED   (Std_ReturnType)8
#define E_REQUEST_ENV_NOK        (Std_ReturnType)9
#define E_PENDING                (Std_ReturnType)10
#define E_COMPARE_KEY_FAILED     (Std_ReturnType)11
#define E_RFORCE_RCRRP           (Std_ReturnType)12

#define E_REQUEST_NOT_FUCADDR    (Std_ReturnType)13
#define E_IIC_NOT_ACK            (Std_ReturnType)14
#define E_OS_MUTEX_ERROR         (Std_ReturnType)15

#define E_POINT_NULL_ERROR       (Std_ReturnType)16
extern void iic_soft_init(int32_t fd);
//extern uint8_t IIC_ReadBytes(uint16_t usAddress, uint16_t usSize,uint8_t *pReadBuf);
extern uint8_t iic_read_bytes (int32_t fd, uint16_t usRegister, uint16_t usSize, uint8_t *pReadBuf);
extern uint8_t iic_write_bytes(int32_t fd, uint16_t usRegister, uint16_t usSize, uint8_t *pBuf);

#endif /*__IIC_DRV_SOFT_H__*/

