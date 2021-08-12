/*===========================================================================*/
/* Project:  F1x StarterKit Sample Software                                  */
/* Module :  ostm0.c                                                         */
/* Version:  V1.00                                                           */
/*===========================================================================*/
/*                                  COPYRIGHT                                */
/*===========================================================================*/
/* Copyright (c) 2015 by Renesas Electronics Europe GmbH,                    */
/*               a company of the Renesas Electronics Corporation            */
/*===========================================================================*/
/* In case of any question please do not hesitate to contact:                */
/*                                                                           */
/*        ABG Software Tool Support                                          */
/*                                                                           */
/*        Renesas Electronics Europe GmbH                                    */
/*        Arcadiastrasse 10                                                  */
/*        D-40472 Duesseldorf, Germany                                       */
/*                                                                           */
/*        e-mail: software_support-eu@lm.renesas.com                         */
/*        FAX:   +49 - (0)211 / 65 03 - 11 31                                */
/*                                                                           */
/*===========================================================================*/
/* Warranty Disclaimer                                                       */
/*                                                                           */
/* Because the Product(s) is licensed free of charge, there is no warranty   */
/* of any kind whatsoever and expressly disclaimed and excluded by Renesas,  */
/* either expressed or implied, including but not limited to those for       */
/* non-infringement of intellectual property, merchantability and/or         */
/* fitness for the particular purpose.                                       */
/* Renesas shall not have any obligation to maintain, service or provide bug */
/* fixes for the supplied Product(s) and/or the Application.                 */
/*                                                                           */
/* Each User is solely responsible for determining the appropriateness of    */
/* using the Product(s) and assumes all risks associated with its exercise   */
/* of rights under this Agreement, including, but not limited to the risks   */
/* and costs of program errors, compliance with applicable laws, damage to   */
/* or loss of data, programs or equipment, and unavailability or             */
/* interruption of operations.                                               */
/*                                                                           */
/* Limitation of Liability                                                   */
/*                                                                           */
/* In no event shall Renesas be liable to the User for any incidental,       */
/* consequential, indirect, or punitive damage (including but not limited    */
/* to lost profits) regardless of whether such liability is based on breach  */
/* of contract, tort, strict liability, breach of warranties, failure of     */
/* essential purpose or otherwise and even if advised of the possibility of  */
/* such damages. Renesas shall not be liable for any services or products    */
/* provided by third party vendors, developers or consultants identified or  */
/* referred to the User by Renesas in connection with the Product(s) and/or  */
/* the Application.                                                          */
/*                                                                           */
/*===========================================================================*/
/* History:                                                                  */
/*              V1.00: Initial version                                       */
/*                                                                           */
/*===========================================================================*/
/*                                                                           */
/* Source code for the OperatingSystemTimer0 Functions                        */
/* The OSTM0 counts with CPU Clock / 2                                       */
/*                                                                           */
/*===========================================================================*/

/*===========================================================================*/
/* Includes */
/*===========================================================================*/
#include <freertos.h>
#include <semphr.h>
#include "r_device.h"
#include "r_port.h"
#include "r_riic.h"
#include "r_intc.h"

#define SINGLEADDR             (0)
#define MULTIADDR              (1)

#define MUTEX_t                SemaphoreHandle_t
#define I2C_MUTEX_TAKE(dev)    xSemaphoreTakeRecursive(*dev->master->mutex, 500)
#define I2C_MUTEX_REALSE(dev)  xSemaphoreGiveRecursive(*dev->master->mutex)

#define IDLE_STATE             (0x00u)
#define ADDR_W_STATE           (0x10u)
#define ADDR_R_STATE           (0x11u)

#define DATA_SEND_STATE        (0x20u)
#define DATA_SEND_END_STATE    (0x22u)

#define DATA_RECV_STATE        (0x30u)
#define DATA_RECV_STATE_2      (0x31u)
#define DATA_RECV_STATE_3      (0x32u)
#define DATA_RECV_STATE_4      (0x33u)

#define DATA_RECV_END_STATE    (0x40u)
#define DATA_RECV_END_STATE_2  (0x41u)

#define IIC_DIR_W              (0x00u)
#define IIC_DIR_R              (0x01u)

typedef struct _iic_param{
	uint32_t iic_state;
	
	uint32_t tx_count;
	uint32_t tx_len;
	uint8_t  *tx_data_p;
	
	uint32_t rx_count;
	uint32_t rx_len;
	uint8_t  *rx_data_p;
	uint8_t  slave_addr;
}IIC_PARAM;

static IIC_PARAM iic_prm;
static MUTEX_t iic_mutex[1];

struct iic_master
{
	IIC_PARAM  *iic_param;
	volatile __type624 *R_IIC;
	MUTEX_t *mutex;
};
struct iic_cli_dev
{
	struct iic_master *master;
	uint8_t iic_addr;
	uint8_t multiADDR;
};

static struct iic_master iic_master_dev[]={
	{
	   &iic_prm,
	   (volatile __type624*)&RIIC0,
	   &iic_mutex[0]
	},
};

#define  IIC_WR  0
#define  IIC_RD  1
static const struct iic_cli_dev iic_cli_dev[]=
{
	{//RTC_RA8900  0
	 &iic_master_dev[0],
	 0x64,//0x64
	 SINGLEADDR,
	},
};
		

/*===========================================================================*/
/* Functions */
/*===========================================================================*/

/*****************************************************************************
** Function:    R_RIIC_Init
** Description: Initializes the RIIC
** Parameter:   None
** Return:      None
******************************************************************************/
void R_RIIC_Init(int32_t fd)
{
  struct iic_cli_dev *dev =(struct iic_cli_dev*)&iic_cli_dev[fd];
  volatile __type624  *R_IIC =dev->master->R_IIC;
  /*Disable I2C Bus Interface
  RIICnCR1                 - I2C Bus Control Register 1
  b31:b 8                  - Reserved set to 0
  b 7          ICE         - I2C Bus Interface Enable         - Disable(the RIICnSCL and RIICnSDA pins are not driven). set to 0
  b 6          IICRST      - I2C Bus Interface Internal Reset - not change.
  b 5          CLO         - Extra SCL Clock Cycle Output     - not change.
  b 4          SOWP        - SCLO/SDAO Write Protect          - not change.
  b 3          SCLO        - SCL Output Control/Monitor       - not change. 
  b 2          SDAO        - SDA Output Control/Monitor       - not change. 
  b 1          SCLI        - SCL LINE Control/Monitor         - not change. 
  b 0          SDAI        - SDA LINE Control/Monitor         - not change.  */ 
  //RIIC0.CR1.UINT32    &= 0xFFFFFF7FUL;
  R_IIC->CR1.UINT32    &= 0xFFFFFF7FUL;
  
  /*I2C Bus Interface Internal Reset
  RIICnCR1                 - I2C Bus Control Register 1
  b31:b 8                  - Reserved set to 0
  b 7          ICE         - I2C Bus Interface Enable         - not change.
  b 6          IICRST      - I2C Bus Interface Internal Reset - Initiates the RIIC reset or internal reset. set to 1
  b 5          CLO         - Extra SCL Clock Cycle Output     - not change.
  b 4          SOWP        - SCLO/SDAO Write Protect          - not change.
  b 3          SCLO        - SCL Output Control/Monitor       - not change. 
  b 2          SDAO        - SDA Output Control/Monitor       - not change. 
  b 1          SCLI        - SCL LINE Control/Monitor         - not change. 
  b 0          SDAI        - SDA LINE Control/Monitor         - not change.   */
  //RIIC0.CR1.UINT32    |= 0x00000040UL;
  R_IIC->CR1.UINT32    |= 0x00000040UL;
  
  /*Enable I2C Bus Interface
  RIICnCR1                 - I2C Bus Control Register 1
  b31:b 8                  - Reserved set to 0
  b 7          ICE         - I2C Bus Interface Enable         - Enable(the RIICnSCL and RIICnSDA pins are not driven). set to 1
  b 6          IICRST      - I2C Bus Interface Internal Reset - not change.
  b 5          CLO         - Extra SCL Clock Cycle Output     - not change.
  b 4          SOWP        - SCLO/SDAO Write Protect          - not change.
  b 3          SCLO        - SCL Output Control/Monitor       - not change. 
  b 2          SDAO        - SDA Output Control/Monitor       - not change. 
  b 1          SCLI        - SCL LINE Control/Monitor         - not change. 
  b 0          SDAI        - SDA LINE Control/Monitor         - not change.  */ 
  //RIIC0.CR1.UINT32    |= 0x00000080UL;
  R_IIC->CR1.UINT32    |= 0x00000080UL;
  
  /*Slave address in RIICnSAR0 is enable.
  RIICnSER                 - I2C Bus state enable Register
  b31:b 6                  - Reserved set to 0 
  b 5          DIDE        - Extra SCL Clock Cycle Output     - Device-ID address detection is disable.set to 0.
  b 4                      - Reserved set to 0 
  b 3          GCE         - SCL Output Control/Monitor       - General call address detection is disable.set to 0.
  b 2          SAR2        - SDA Output Control/Monitor       - Slave address in RIICnSAR2 is disable. set to 0 
  b 1          SAR1        - SCL LINE Control/Monitor         - Slave address in RIICnSAR1 is disable. set to 0 
  b 0          SAR0        - SDA LINE Control/Monitor         - Slave address in RIICnSAR0 is enable. set to 1   */ 
  //RIIC0.SER.UINT32    |= 0x00000001UL;
  R_IIC->SER.UINT32    |= 0x00000001UL;
  
  /*Internal Reference Clock Selection.
  RIICnMR1                 - I2C Bus Mode Register
  b31:b 8                  - Reserved set to 0 
  b 7          MTWP        - MST/TRS write Protect            - not change.
  b 6:b 4      CKS         - Internal Reference Clock Selection. - PCLK/16 clock.set to 100'b   
  b 3          BCWP        - BC write Protect                 - not change.
  b 2:b 0      BC          - Bit Counter                      - not change.  */
  //RIIC0.MR1.UINT32    |= 0x00000040UL;//0x00000020UL
  //RIIC0.BRH.UINT32    |= 30;
  //RIIC0.BRL.UINT32    |= 20;
  R_IIC->MR1.UINT32    |= 0x00000040UL;//0x00000020UL
  R_IIC->BRH.UINT32     = 30;
  R_IIC->BRH.UINT32     = 20;
  
  /*set the I2C BUS Mode.
  RIICnMR2                 - I2C Bus Mode Register 2
  b31:b 8                  - Reserved set to 0 
  b 7          DLCS        - SDA Output Delay clock Source Select   - not change.
  b 6:b 4      SDDL        - SDA Output Delay Counter         - not change.      
  b 3          BCWP        - Reserved set to 0 
  b 2          TMOH        - Timeout H Count Control          - not change. 
  b 1          TMOL        - Timeout L Count Control          - not change. 
  b 0          TMOS        - Timeout Detection Time Selection - not change. */
  //RIIC0.MR2.UINT32    |= 0x00000006UL;
  R_IIC->MR2.UINT32    |= 0x00000006UL;
  
  /*set the I2C BUS Mode.
  RIICnMR3                 - I2C Bus Mode Register 3
  b31:b 7                  - Reserved set to 0 
  b 6          WAIT        - WAIT                             - not WAIT. set to 0.
  b 5          RDRFS       - RDRF Flag Set Timing Selection   - The RDRF flag is set at the rising edge of the
                                                                ninth scl clock cycle.set to 0  
  b 4          ACKWP       - ACKBT Write Protect              - Modification of the ACKBT bit is enabled.set to 1 
  b 3          ACKBT       - Transmit Acknowledge             - A is 0 sent as the acknowledge bit.set to 0. 
  b 2          ACKBR       - Receive Acknowledge              - A is 0 received as the acknowledge bit.set to 0.  
  b 1:b 0      NF          - Digital noise Filter Stage Selection   - Noise of up to one IIC cycle is filtered out .set to 00'b */
  
  //RIIC0.MR3.UINT32    |= 0x00000010UL;
  R_IIC->MR3.UINT32    |= 0x00000010UL;
  
  /*set the I2C BUS function.
  RIICnFER                 - I2C Bus Function Enable Register
  b31:b 7                  - Reserved set to 0 
  b 6          SCLE        - SCL synchronous circuit Enable       - An SCL synchronous circuit is unused. set to 0.
  b 5          NFE         - Digital noise Filter circuit Enable  - A digital noise Filter circuit is unused. set to 0.
  b 4          NACKE       - NACKE Reception Transfer Suspension Enable  - Transfer operation is suspended during NACK reception.set to 1 
  b 3          SALE        - Slave Arbitration-Lost Detection Enable     - Slave arbitration-lost detection is disable.set to 0. 
  b 2          NALE        - NACK Transmission Arbitration-Lost 
                             Detection Enable                            - NACK Transmission Arbitration-Lost is detection disable .set to 0.  
  b 1          MALE        - Master Arbitration-Lost Detection Enable    - Master Arbitration-Lost Detection is disable .set to 0.  
  b 0          TMOE        - Timeout function enable                     - Timeout function  is disable .set to 0*/
  
  //RIIC0.FER.UINT32    |= 0x00000010UL;
  R_IIC->FER.UINT32    |= 0x00000010UL;
  
    /*set the I2C Interrupt.
  RIICnIER                 - I2C Bus Interrupt Enable Register
  b31:b 8                  - Reserved set to 0 
  b 7          TIE         - Transmit Data Empty Interrupt Enable           - Transmit Data Empty interrupt request(INTIICnTI) is enabed. set to 1.
  b 6          TEIE        - Transmit End Interrupt Enable                  -  Transmit End Interrupt request(INTIICnTEI) is enabed. set to 1.
  b 5          RIE         - Receive Complete Interrupt Enable              - Receive Complete Interrupt  request(INTIICnRI) is enabed.set to 1 
  b 4          NAKIE       - NACK Reception Interrupt Enable                - NACK Reception Interrupt  request(NAKI) is disable.set to 0. 
  b 3          SPIE        - Stop Condition Detection Interrupt Enable      - Stop Condition Detection Interrupt request(SPI) is enabled.set to 1.  
  b 2          STIE        - Start Condition Detection Interrupt Enable     - Start Condition Detection Interrupt request(STI) is disable.set to 0.
  b 1          ALIE        - Arbitration-Lost  Interrupt Enable             - Arbitration-Lost  Interrupt request(ALI) is disable.set to 0.    
  b 0          TMOIE       - Timeout Interrupt enable                       - Timeout Interrupt Interrupt request(TMOI) is disable .set to 0*/
  
  //RIIC0.IER.UINT32    |= 0x000000E8UL;
  R_IIC->IER.UINT32    |= 0x000000E8UL;
  
    /*I2C Bus Interface Internal Reset
  RIICnCR1                 - I2C Bus Control Register 1
  b31:b 8                  - Reserved set to 0
  b 7          ICE         - I2C Bus Interface Enable         - not change.
  b 6          IICRST      - I2C Bus Interface Internal Reset - Clears the RIIC reset or internal reset. set to 0
  b 5          CLO         - Extra SCL Clock Cycle Output     - not change.
  b 4          SOWP        - SCLO/SDAO Write Protect          - not change.
  b 3          SCLO        - SCL Output Control/Monitor       - not change. 
  b 2          SDAO        - SDA Output Control/Monitor       - not change. 
  b 1          SCLI        - SCL LINE Control/Monitor         - not change. 
  b 0          SDAI        - SDA LINE Control/Monitor         - not change.   */
  //RIIC0.CR1.UINT32    &= 0xFFFFFFBFUL;
  R_IIC->CR1.UINT32    |= 0xFFFFFFBFUL;
  
    /* interrupt mask release */
  //  MKRIIC0TI           = 0U;
  //  MKRIIC0TEI          = 0U;
  //  MKRIIC0RI           = 0U;
  //  MKRIIC0EE           = 0U;
  R_INTC_SetTableBit((uint16_t*)R_ICRIIC0TI);
  R_INTC_UnmaskInterrupt((uint16_t*)R_ICRIIC0TI);
  
  R_INTC_SetTableBit((uint16_t*)R_ICRIIC0TEI);
  R_INTC_UnmaskInterrupt((uint16_t*)R_ICRIIC0TEI);
  
  R_INTC_SetTableBit((uint16_t*)R_ICRIIC0RI);
  R_INTC_UnmaskInterrupt((uint16_t*)R_ICRIIC0RI);
  
  R_INTC_SetTableBit((uint16_t*)R_ICRIIC0EE);
  R_INTC_UnmaskInterrupt((uint16_t*)R_ICRIIC0EE);
  //PORT.PU0 |= 0x1800;
}

/*=========================================================================*/
/* Interrupts                                                              */
/*=========================================================================*/
static void INTRIICTI(int32_t fd)
{
	struct iic_cli_dev *dev = (struct iic_cli_dev *)&iic_cli_dev[fd];
	IIC_PARAM *iic_prm = dev->master->iic_param; 
	volatile __type624 *RIIC = dev->master->R_IIC;
	if ( iic_prm->iic_state == ADDR_W_STATE )
	{
		RIIC->DRT.UINT32    = (uint32_t)iic_prm->slave_addr + IIC_DIR_W;      // Write address
		iic_prm->iic_state   = DATA_SEND_STATE;
	}
	else if ( iic_prm->iic_state == ADDR_R_STATE )
	{
		RIIC->DRT.UINT32    = (uint32_t)iic_prm->slave_addr + IIC_DIR_R;      // Write address
		iic_prm->iic_state   = DATA_RECV_STATE;
	}
}

static void INTRIICTEI(int32_t fd)
{
	volatile uint32_t dummy_read;
	struct iic_cli_dev *dev = (struct iic_cli_dev *)&iic_cli_dev[fd];
	IIC_PARAM *iic_prm = dev->master->iic_param;
	volatile __type624 *RIIC = dev->master->R_IIC;
	if ( iic_prm->iic_state == DATA_SEND_STATE )
	{
		 if ( (RIIC->SR2.UINT32 & 0x00000010UL) || ( iic_prm->tx_count == iic_prm->tx_len ) )      // NACK ? or Transmission end ?
                {
                    /* Clear Transmit End Flag.
                    RIICnSR2            - I2C Bus Status Register 2
                    b31:b 8             - Reserved set to 0
                    b 7      RIICnTDRE  - Transmit Data Empty Flag                    - not change.
                    b 6      RIICnTEND  - Transmit End Flag                           - Data is being transmitted. set to 0
                    b 5      RIICnRDRF  - Receive Complete Flag                       - not change.
                    b 4      RIICnNACKF - NACK Detection Flag                         - not change.
                    b 3      RIICnSTOP  - Stop Condition Detection Flag               - not change.
                    b 2      RIICnSTART - Start Condition Detection Flag              - not change.
                    b 1      RIICnAL    - Arbitration-Lost Flag                       - not change.
                    b 0      RIICnTMOF  - Timeout Detection Flag */
                    RIIC->SR2.UINT32    &= 0xFFFFFFBFUL;


                    /* Clear Stop Condition Detection Flag.
                    RIICnSR2            - I2C Bus Status Register 2
                    b31:b 8             - Reserved set to 0
                    b 7      RIICnTDRE  - Transmit Data Empty Flag                    - not change.
                    b 6      RIICnTEND  - Transmit End Flag                           - not change.
                    b 5      RIICnRDRF  - Receive Complete Flag                       - not change.
                    b 4      RIICnNACKF - NACK Detection Flag                         - not change.
                    b 3      RIICnSTOP  - Stop Condition Detection Flag               - Stop condition is not detected. set to 0
                                                                                      - (When 0 is written to the STOP bit after reading STOP = 1)
                    b 2      RIICnSTART - Start Condition Detection Flag              - not change.
                    b 1      RIICnAL    - Arbitration-Lost Flag                       - not change.
                    b 0      RIICnTMOF  - Timeout Detection Flag */
                    RIIC->SR2.UINT32    &= 0xFFFFFFF7UL;


                    /* Requests to issue a stop condition.
                    RIICnCR2            - I2C Bus Control Register 2
                    b31:b 8             - Reserved set to 0
                    b 7          BBSY   - Bus Busy Detection Flag                     - not change.
                    b 6          MST    - Master/Slave Mode                           - not change.
                    b 5          TRS    - Transmit/Receive Mode                       - not change.
                    b 4                 - Reserved set to 0
                    b 3          SP     - Stop Condition Issuance Request             - Requests to issue a stop condition. set to 1
                    b 2          RS     - Restart Condition Issuance Request          - not change.
                    b 1          ST     - Start Condition Issuance Request            - not change.
                    b 0                 - Reserved set to 0 */
                    RIIC->CR2.UINT32    |= 0x00000008UL;
                    dummy_read = RIIC->CR2.UINT32;
		    __SYNCP();
                    iic_prm->iic_state   = DATA_SEND_END_STATE;
                }
                else
                {
                    RIIC->DRT.UINT32    = *iic_prm->tx_data_p++;                       // Write data
		    dummy_read = RIIC->DRR.UINT32;//RIIC->CR2.UINT32;
		    __SYNCP();
                    iic_prm->tx_count++;
                }
	}
	
}

static void INTRIICEE(int32_t fd)
{
	volatile uint32_t dummy_read;
	struct iic_cli_dev *dev = (struct iic_cli_dev *)&iic_cli_dev[fd];
	IIC_PARAM *iic_prm = dev->master->iic_param;
	volatile __type624 *RIIC = dev->master->R_IIC;
	if ( (iic_prm->iic_state == DATA_SEND_END_STATE) || (iic_prm->iic_state == DATA_RECV_END_STATE) || ( iic_prm->iic_state == DATA_RECV_END_STATE_2 ) )
	{
		if ( RIIC->SR2.UINT32 & 0x00000008UL )                                // STOP = 1 ?
		{
			if ( iic_prm->iic_state == DATA_RECV_END_STATE_2 )
			{
				/* ACK write enable
				RIICnMR3            - I2C Bus Mode Register 3
				b31:b 7             - Reserved set to 0
				b 6          WAIT   - WAIT                                        - not change.
				b 5          RDRFS  - RDRF Flag Set Timing Selection              - not change.
				b 4          ACKWP  - ACKBT Write Protect                         - Modification of the ACKBT bit is enabled. set to 1
				b 3          ACKBT  - Transmit Acknowledge                        - not change.
				b 2          ACKBR  - Receive Acknowledge                         - not change.
				b 1:b 0      NF     - Digital noise Filter Stage Selection        - not change. */
				RIIC->MR3.UINT32    |= 0x00000010UL;

				/* set I2C Bus Mode
				RIICnMR3            - I2C Bus Mode Register 3
				b31:b 7             - Reserved set to 0
				b 6          WAIT   - WAIT                                        - not change.
				b 5          RDRFS  - RDRF Flag Set Timing Selection              - The RDRF flag is set at the rising edge of the ninth SCL clock cycle. set to 0
				b 4          ACKWP  - ACKBT Write Protect                         - not change.
				b 3          ACKBT  - Transmit Acknowledge                        - A 0 is sent as the acknowledge bit (ACK transmission). set to 0
				b 2          ACKBR  - Receive Acknowledge                         - not change.
				b 1:b 0      NF     - Digital noise Filter Stage Selection        - not change. */
				RIIC->MR3.UINT32    &= 0xFFFFFFD7UL;
			}
			/* Clear NACK Detection Flag
			RIICnSR2            - I2C Bus Status Register 2
			b31:b 8             - Reserved set to 0
			b 7      RIICnTDRE  - Transmit Data Empty Flag                    - not change.
			b 6      RIICnTEND  - Transmit End Flag                           - not change.
			b 5      RIICnRDRF  - Receive Complete Flag                       - not change.
			b 4      RIICnNACKF - NACK Detection Flag                         - NACK is not detected. set to 0
																			  - When 0 is written to the NACKF bit after reading NACKF = 1
			b 3      RIICnSTOP  - Stop Condition Detection Flag               - not change.
			b 2      RIICnSTART - Start Condition Detection Flag              - not change.
			b 1      RIICnAL    - Arbitration-Lost Flag                       - not change.
			b 0      RIICnTMOF  - Timeout Detection Flag */
			RIIC->SR2.UINT32    &= 0xFFFFFFEFUL;


			/* Clear Stop Condition Detection Flag.
			RIICnSR2            - I2C Bus Status Register 2
			b31:b 8             - Reserved set to 0
			b 7      RIICnTDRE  - Transmit Data Empty Flag                    - not change.
			b 6      RIICnTEND  - Transmit End Flag                           - not change.
			b 5      RIICnRDRF  - Receive Complete Flag                       - not change.
			b 4      RIICnNACKF - NACK Detection Flag                         - not change.
			b 3      RIICnSTOP  - Stop Condition Detection Flag               - Stop condition is not detected. set to 0
																			  - (When 0 is written to the STOP bit after reading STOP = 1)
			b 2      RIICnSTART - Start Condition Detection Flag              - not change.
			b 1      RIICnAL    - Arbitration-Lost Flag                       - not change.
			b 0      RIICnTMOF  - Timeout Detection Flag */
			RIIC->SR2.UINT32    &= 0xFFFFFFF7UL;

			iic_prm->iic_state   = IDLE_STATE;
		}
	}
}

static void INTRIICRI(int32_t fd)
{
	volatile uint32_t dummy_read;
	struct iic_cli_dev *dev = (struct iic_cli_dev *)&iic_cli_dev[fd];
	IIC_PARAM *iic_prm = dev->master->iic_param;
	volatile __type624 *RIIC = dev->master->R_IIC;
	if ( iic_prm->iic_state == DATA_RECV_STATE )
	{
		if ( RIIC->SR2.UINT32 & 0x00000010UL )                                // NACK ?
		{
			/* Clear Stop Condition Detection Flag.
			RIICnSR2            - I2C Bus Status Register 2
			b31:b 8             - Reserved set to 0
			b 7      RIICnTDRE  - Transmit Data Empty Flag                    - not change.
			b 6      RIICnTEND  - Transmit End Flag                           - not change.
			b 5      RIICnRDRF  - Receive Complete Flag                       - not change.
			b 4      RIICnNACKF - NACK Detection Flag                         - not change.
			b 3      RIICnSTOP  - Stop Condition Detection Flag               - Stop condition is not detected. set to 0
																			  - (When 0 is written to the STOP bit after reading STOP = 1)
			b 2      RIICnSTART - Start Condition Detection Flag              - not change.
			b 1      RIICnAL    - Arbitration-Lost Flag                       - not change.
			b 0      RIICnTMOF  - Timeout Detection Flag */
			RIIC->SR2.UINT32    &= 0xFFFFFFF7UL;


			/* Requests to issue a stop condition.
			RIICnCR2            - I2C Bus Control Register 2
			b31:b 8             - Reserved set to 0
			b 7          BBSY   - Bus Busy Detection Flag                     - not change.
			b 6          MST    - Master/Slave Mode                           - not change.
			b 5          TRS    - Transmit/Receive Mode                       - not change.
			b 4                 - Reserved set to 0
			b 3          SP     - Stop Condition Issuance Request             - Requests to issue a stop condition. set to 1
			b 2          RS     - Restart Condition Issuance Request          - not change.
			b 1          ST     - Start Condition Issuance Request            - not change.
			b 0                 - Reserved set to 0 */
			RIIC->CR2.UINT32    |= 0x00000008UL;


			dummy_read          = RIIC->DRR.UINT32;                           // Dummy read

			if ( iic_prm->rx_len <= 2UL )
			{
				iic_prm->iic_state   = DATA_RECV_END_STATE_2;
			}
			else
			{
				iic_prm->iic_state   = DATA_RECV_END_STATE;
			}
		}
		else
		{
			if ( iic_prm->rx_len <= 2UL )
			{
				/* WAIT
				RIICnMR3            - I2C Bus Mode Register 3
				b31:b 7             - Reserved set to 0
				b 6          WAIT   - WAIT                                        - WAIT. set to 1
				b 5          RDRFS  - RDRF Flag Set Timing Selection              - not change.
				b 4          ACKWP  - ACKBT Write Protect                         - not change.
				b 3          ACKBT  - Transmit Acknowledge                        - not change.
				b 2          ACKBR  - Receive Acknowledge                         - not change.
				b 1:b 0      NF     - Digital noise Filter Stage Selection        - not change. */
				RIIC->MR3.UINT32    |= 0x00000040UL;

				if ( iic_prm->rx_len == 2U )
				{
					dummy_read           = RIIC->DRR.UINT32;                       // Dummy read
					iic_prm->iic_state   = DATA_RECV_STATE_2;
				}
				else
				{
					/* NACK write enable
					RIICnMR3            - I2C Bus Mode Register 3
					b31:b 7             - Reserved set to 0
					b 6          WAIT   - WAIT                                        - not change.
					b 5          RDRFS  - RDRF Flag Set Timing Selection              - not change.
					b 4          ACKWP  - ACKBT Write Protect                         - Modification of the ACKBT bit is enabled. set to 1
					b 3          ACKBT  - Transmit Acknowledge                        - not change.
					b 2          ACKBR  - Receive Acknowledge                         - not change.
					b 1:b 0      NF     - Digital noise Filter Stage Selection        - not change. */
					RIIC->MR3.UINT32    |= 0x00000010UL;


					/* NACK
					RIICnMR3            - I2C Bus Mode Register 3
					b31:b 7             - Reserved set to 0
					b 6          WAIT   - WAIT                                        - not change.
					b 5          RDRFS  - RDRF Flag Set Timing Selection              - The RDRF flag is set at the rising edge of the eighth SCL clock cycle. set to 1
					b 4          ACKWP  - ACKBT Write Protect                         - not change.
					b 3          ACKBT  - Transmit Acknowledge                        - A 1 is sent as the acknowledge bit (NACK transmission). set to 1
					b 2          ACKBR  - Receive Acknowledge                         - not change.
					b 1:b 0      NF     - Digital noise Filter Stage Selection        - not change. */
					RIIC->MR3.UINT32    |= 0x00000028UL;

					dummy_read          = RIIC->DRR.UINT32;                           // Dummy read
					iic_prm->iic_state  = DATA_RECV_STATE_3;
				}
			}
			else
			{
				dummy_read              = RIIC->DRR.UINT32;                           // Dummy read
				iic_prm->iic_state      = DATA_RECV_STATE_4;
			}
		}
	}
	else if ( iic_prm->iic_state == DATA_RECV_STATE_2 )
	{
		/* NACK write enable
		RIICnMR3            - I2C Bus Mode Register 3
		b31:b 7             - Reserved set to 0
		b 6          WAIT   - WAIT                                        - not change.
		b 5          RDRFS  - RDRF Flag Set Timing Selection              - not change.
		b 4          ACKWP  - ACKBT Write Protect                         - Modification of the ACKBT bit is enabled. set to 1
		b 3          ACKBT  - Transmit Acknowledge                        - not change.
		b 2          ACKBR  - Receive Acknowledge                         - not change.
		b 1:b 0      NF     - Digital noise Filter Stage Selection        - not change. */
		RIIC->MR3.UINT32    |= 0x00000010UL;


		/* NACK
		RIICnMR3            - I2C Bus Mode Register 3
		b31:b 7             - Reserved set to 0
		b 6          WAIT   - WAIT                                        - not change.
		b 5          RDRFS  - RDRF Flag Set Timing Selection              - The RDRF flag is set at the rising edge of the eighth SCL clock cycle. set to 1
		b 4          ACKWP  - ACKBT Write Protect                         - A 1 is sent as the acknowledge bit (NACK transmission). set to 1
		b 3          ACKBT  - Transmit Acknowledge                        - not change.
		b 2          ACKBR  - Receive Acknowledge                         - not change.
		b 1:b 0      NF     - Digital noise Filter Stage Selection        - not change. */
		RIIC->MR3.UINT32    |= 0x00000028UL;


		*iic_prm->rx_data_p++ = RIIC->DRR.UINT32;                          // Read data
		iic_prm->rx_count++;
		iic_prm->iic_state    = DATA_RECV_STATE_3;
	}
	else if ( iic_prm->iic_state == DATA_RECV_STATE_3 )
	{
		/* Clear Stop Condition Detection Flag.
		RIICnSR2            - I2C Bus Status Register 2
		b31:b 8             - Reserved set to 0
		b 7      RIICnTDRE  - Transmit Data Empty Flag                    - not change.
		b 6      RIICnTEND  - Transmit End Flag                           - not change.
		b 5      RIICnRDRF  - Receive Complete Flag                       - not change.
		b 4      RIICnNACKF - NACK Detection Flag                         - not change.
		b 3      RIICnSTOP  - Stop Condition Detection Flag               - Stop condition is not detected. set to 0
																		  - (When 0 is written to the STOP bit after reading STOP = 1)
		b 2      RIICnSTART - Start Condition Detection Flag              - not change.
		b 1      RIICnAL    - Arbitration-Lost Flag                       - not change.
		b 0      RIICnTMOF  - Timeout Detection Flag */
		RIIC->SR2.UINT32    &= 0xFFFFFFF7UL;


		/* Requests to issue a stop condition.
		RIICnCR2            - I2C Bus Control Register 2
		b31:b 8             - Reserved set to 0
		b 7          BBSY   - Bus Busy Detection Flag                     - not change.
		b 6          MST    - Master/Slave Mode                           - not change.
		b 5          TRS    - Transmit/Receive Mode                       - not change.
		b 4                 - Reserved set to 0
		b 3          SP     - Stop Condition Issuance Request             - Requests to issue a stop condition. set to 1
		b 2          RS     - Restart Condition Issuance Request          - not change.
		b 1          ST     - Start Condition Issuance Request            - not change.
		b 0                 - Reserved set to 0 */
		RIIC->CR2.UINT32    |= 0x00000008UL;


		*iic_prm->rx_data_p++ = RIIC->DRR.UINT32;                          // Read data
		iic_prm->rx_count++;


		/* NACK write enable
		RIICnMR3            - I2C Bus Mode Register 3
		b31:b 7             - Reserved set to 0
		b 6          WAIT   - WAIT                                        - not change.
		b 5          RDRFS  - RDRF Flag Set Timing Selection              - not change.
		b 4          ACKWP  - ACKBT Write Protect                         - Modification of the ACKBT bit is enabled. set to 1
		b 3          ACKBT  - Transmit Acknowledge                        - not change.
		b 2          ACKBR  - Receive Acknowledge                         - not change.
		b 1:b 0      NF     - Digital noise Filter Stage Selection        - not change. */
		RIIC->MR3.UINT32    |= 0x00000010UL;                              // NACK write enable


		/* NACK
		RIICnMR3            - I2C Bus Mode Register 3
		b31:b 7             - Reserved set to 0
		b 6          WAIT   - WAIT                                        - not change.
		b 5          RDRFS  - RDRF Flag Set Timing Selection              - not change.
		b 4          ACKWP  - ACKBT Write Protect                         - A 1 is sent as the acknowledge bit (NACK transmission). set to 1
		b 3          ACKBT  - Transmit Acknowledge                        - not change.
		b 2          ACKBR  - Receive Acknowledge                         - not change.
		b 1:b 0      NF     - Digital noise Filter Stage Selection        - not change. */
		RIIC->MR3.UINT32    |= 0x00000008UL;


		/* WAIT relese
		RIICnMR3            - I2C Bus Mode Register 3
		b31:b 7             - Reserved set to 0
		b 6          WAIT   - WAIT                                        - no WAIT. set to 0
		b 5          RDRFS  - RDRF Flag Set Timing Selection              - not change.
		b 4          ACKWP  - ACKBT Write Protect                         - not change.
		b 3          ACKBT  - Transmit Acknowledge                        - not change.
		b 2          ACKBR  - Receive Acknowledge                         - not change.
		b 1:b 0      NF     - Digital noise Filter Stage Selection        - not change. */
		RIIC->MR3.UINT32    &= 0xFFFFFFBFUL;

		iic_prm->iic_state   = DATA_RECV_END_STATE_2;
	}
	else if ( iic_prm->iic_state == DATA_RECV_STATE_4 )
	{
		if ( iic_prm->rx_len == (iic_prm->rx_count + 1UL) )
		{
			/* Clear Stop Condition Detection Flag.
			RIICnSR2            - I2C Bus Status Register 2
			b31:b 8             - Reserved set to 0
			b 7      RIICnTDRE  - Transmit Data Empty Flag                    - not change.
			b 6      RIICnTEND  - Transmit End Flag                           - not change.
			b 5      RIICnRDRF  - Receive Complete Flag                       - not change.
			b 4      RIICnNACKF - NACK Detection Flag                         - not change.
			b 3      RIICnSTOP  - Stop Condition Detection Flag               - Stop condition is not detected. set to 0
																			  - (When 0 is written to the STOP bit after reading STOP = 1)
			b 2      RIICnSTART - Start Condition Detection Flag              - not change.
			b 1      RIICnAL    - Arbitration-Lost Flag                       - not change.
			b 0      RIICnTMOF  - Timeout Detection Flag */
			RIIC->SR2.UINT32    &= 0xFFFFFFF7UL;


			/* Requests to issue a stop condition.
			RIICnCR2            - I2C Bus Control Register 2
			b31:b 8             - Reserved set to 0
			b 7          BBSY   - Bus Busy Detection Flag                     - not change.
			b 6          MST    - Master/Slave Mode                           - not change.
			b 5          TRS    - Transmit/Receive Mode                       - not change.
			b 4                 - Reserved set to 0
			b 3          SP     - Stop Condition Issuance Request             - Requests to issue a stop condition. set to 1
			b 2          RS     - Restart Condition Issuance Request          - not change.
			b 1          ST     - Start Condition Issuance Request            - not change.
			b 0                 - Reserved set to 0 */
			RIIC->CR2.UINT32    |= 0x00000008UL;

			*iic_prm->rx_data_p++ = RIIC->DRR.UINT32;                          // Read data
			iic_prm->rx_count++;

			/* WAIT relese
			RIICnMR3            - I2C Bus Mode Register 3
			b31:b 7             - Reserved set to 0
			b 6          WAIT   - WAIT                                        - no WAIT. set to 0
			b 5          RDRFS  - RDRF Flag Set Timing Selection              - not change.
			b 4          ACKWP  - ACKBT Write Protect                         - not change.
			b 3          ACKBT  - Transmit Acknowledge                        - not change.
			b 2          ACKBR  - Receive Acknowledge                         - not change.
			b 1:b 0      NF     - Digital noise Filter Stage Selection        - not change. */
			RIIC->MR3.UINT32    &= 0xFFFFFFBFUL;

			iic_prm->iic_state   = DATA_RECV_END_STATE;
		}
		else if ( iic_prm->rx_len == (iic_prm->rx_count + 2UL) )
		{
			/* NACK write enable
			RIICnMR3            - I2C Bus Mode Register 3
			b31:b 7             - Reserved set to 0
			b 6          WAIT   - WAIT                                        - not change.
			b 5          RDRFS  - RDRF Flag Set Timing Selection              - not change.
			b 4          ACKWP  - ACKBT Write Protect                         - Modification of the ACKBT bit is enabled. set to 1
			b 3          ACKBT  - Transmit Acknowledge                        - not change.
			b 2          ACKBR  - Receive Acknowledge                         - not change.
			b 1:b 0      NF     - Digital noise Filter Stage Selection        - not change. */
			RIIC->MR3.UINT32    |= 0x00000010UL;


			/* NACK
			RIICnMR3            - I2C Bus Mode Register 3
			b31:b 7             - Reserved set to 0
			b 6          WAIT   - WAIT                                        - not change.
			b 5          RDRFS  - RDRF Flag Set Timing Selection              - not change.
			b 4          ACKWP  - ACKBT Write Protect                         - A 1 is sent as the acknowledge bit (NACK transmission). set to 1
			b 3          ACKBT  - Transmit Acknowledge                        - not change.
			b 2          ACKBR  - Receive Acknowledge                         - not change.
			b 1:b 0      NF     - Digital noise Filter Stage Selection        - not change. */
			RIIC->MR3.UINT32    |= 0x00000008UL;

			*iic_prm->rx_data_p++ = RIIC->DRR.UINT32;                          // Read data
			iic_prm->rx_count++;
		}
		else if ( iic_prm->rx_len == (iic_prm->rx_count + 3UL) )
		{
			/* WAIT
			RIICnMR3            - I2C Bus Mode Register 3
			b31:b 7             - Reserved set to 0
			b 6          WAIT   - WAIT                                        - WAIT. set to 1
			b 5          RDRFS  - RDRF Flag Set Timing Selection              - not change.
			b 4          ACKWP  - ACKBT Write Protect                         - not change.
			b 3          ACKBT  - Transmit Acknowledge                        - not change.
			b 2          ACKBR  - Receive Acknowledge                         - not change.
			b 1:b 0      NF     - Digital noise Filter Stage Selection        - not change. */
			RIIC->MR3.UINT32    |= 0x00000040UL;

			*iic_prm->rx_data_p++ = RIIC->DRR.UINT32;                          // Read data
			iic_prm->rx_count++;

		} else {
			*iic_prm->rx_data_p++ = RIIC->DRR.UINT32;                          // Read data
			iic_prm->rx_count++;
		}
	}
}


/******************************************************************************
* Function Name : INTRIIC0EE
* Description   : RIIC communication error / event generation interrupt
* Argument      : None
* Return Value  : none
******************************************************************************/
#ifdef __IAR__
  #pragma vector = NUMINTRIIC0EE // NUMINTRLIN35UR1
  __interrupt void INTRIIC0EE(void)
#endif
#ifdef __GHS__
  #pragma ghs interrupt
  void INTRIIC0EE(void)
#endif
#ifdef __CSP__
  #pragma interrupt INTRIIC0EE(enable=manual)
void INTRIIC0EE(void)
#endif /* __CSP__*/
{
    INTRIICEE(0); 
}

/******************************************************************************
* Function Name : INTRIIC0RI
* Description   : RIIC communication error / event generation interrupt
* Argument      : None
* Return Value  : none
******************************************************************************/
#ifdef __IAR__
  #pragma vector = NUMINTRIIC0RI // NUMINTRLIN35UR1
  __interrupt void INTRIIC0RI(void)
#endif
#ifdef __GHS__
  #pragma ghs interrupt
  void INTRIIC0RI(void)
#endif
#ifdef __CSP__
  #pragma interrupt INTRIIC0RI(enable=manual)
void INTRIIC0RI(void)
#endif /* __CSP__*/
{
    INTRIICRI(0); 
}

/******************************************************************************
* Function Name : INTRIIC0TI
* Description   : RIIC communication error / event generation interrupt
* Argument      : None
* Return Value  : none
******************************************************************************/
#ifdef __IAR__
  #pragma vector = NUMINTRIIC0TI // NUMINTRLIN35UR1
  __interrupt void INTRIIC0TI(void)
#endif
#ifdef __GHS__
  #pragma ghs interrupt
  void INTRIIC0TI(void)
#endif
#ifdef __CSP__
  #pragma interrupt INTRIIC0TI(enable=manual)
void INTRIIC0TI(void)
#endif /* __CSP__*/
{
    INTRIICTI(0); 
}

/******************************************************************************
* Function Name : INTRIIC0EE
* Description   : RIIC communication error / event generation interrupt
* Argument      : None
* Return Value  : none
******************************************************************************/
#ifdef __IAR__
  #pragma vector = NUMINTRIIC0TEI // NUMINTRLIN35UR1
  __interrupt void INTRIIC0TEI(void)
#endif
#ifdef __GHS__
  #pragma ghs interrupt
  void INTRIIC0TEI(void)
#endif
#ifdef __CSP__
  #pragma interrupt INTRIIC0TEI(enable=manual)
void INTRIIC0TEI(void)
#endif /* __CSP__*/
{
    INTRIICTEI(0); 
}

/*****************************************************************************
** Function:    R_RIIC_GetState()
** Description: return driver state
** Parameter:   None
** Return:      driver state
******************************************************************************/
static uint8_t R_IIC_GetState(int32_t fd)
{
	struct iic_cli_dev *dev = (struct iic_cli_dev *)&iic_cli_dev[fd];
	return dev->master->iic_param->iic_state;
	//return iic_prm.iic_state;
}

/******************************************************************************
* Function Name : void R_IIC_Master_Transmit( uint32_t len , uint8_t *transmission_data )
* Description   : This function transmits the master mode.
* Argument      : none
* Return Value  : none
******************************************************************************/
static void R_IIC_Master_Transmit( int32_t fd, uint8_t slave_addr, uint32_t len , uint8_t *transmission_data )
{
	struct iic_cli_dev *dev = (struct iic_cli_dev *)&iic_cli_dev[fd];
	IIC_PARAM *iic_prm = dev->master->iic_param;
    while( dev->master->R_IIC->CR2.UINT32 & 0x00000080UL );                         // Wait to a bus-free state

    iic_prm->iic_state   = ADDR_W_STATE;
    iic_prm->tx_data_p   = transmission_data;
    iic_prm->tx_len      = len;
    iic_prm->tx_count    = 0UL;
	iic_prm->slave_addr  = dev->iic_addr;//slave_addr;

    /* Requests to issue a start condition.
    RIICnCR2            - I2C Bus Control Register 2
    b31:b 8             - Reserved set to 0
    b 7          BBSY   - Bus Busy Detection Flag                     - not change.
    b 6          MST    - Master/Slave Mode                           - not change.
    b 5          TRS    - Transmit/Receive Mode                       - not change.
    b 4                 - Reserved set to 0
    b 3          SP     - Stop Condition Issuance Request             - not change.
    b 2          RS     - Restart Condition Issuance Request          - not change.
    b 1          ST     - Start Condition Issuance Request            - Requests to issue a start condition. set to 1
    b 0                 - Reserved set to 0 */
    dev->master->R_IIC->CR2.UINT32    |= 0x00000002UL;

}


/******************************************************************************
* Function Name : void R_IIC_Master_Reception( uint32_t len , uint8_t *reception_data )
* Description   : This function reception the master mode.
* Argument      : none
* Return Value  : none
******************************************************************************/
static void R_IIC_Master_Reception( int32_t fd, uint8_t slave_addr, uint32_t len , uint8_t *reception_data )
{
	struct iic_cli_dev *dev = (struct iic_cli_dev *)&iic_cli_dev[fd];
	IIC_PARAM *iic_prm = dev->master->iic_param;
    while( dev->master->R_IIC->CR2.UINT32 & 0x00000080UL );                         // Wait to a bus-free state

    iic_prm->iic_state   = ADDR_R_STATE;
    iic_prm->rx_data_p   = reception_data;
    iic_prm->rx_len      = len;
    iic_prm->rx_count    = 0UL;
	iic_prm->slave_addr  = dev->iic_addr;//slave_addr;

    /* Requests to issue a start condition.
    RIICnCR2            - I2C Bus Control Register 2
    b31:b 8             - Reserved set to 0
    b 7          BBSY   - Bus Busy Detection Flag                     - not change.
    b 6          MST    - Master/Slave Mode                           - not change.
    b 5          TRS    - Transmit/Receive Mode                       - not change.
    b 4                 - Reserved set to 0
    b 3          SP     - Stop Condition Issuance Request             - not change.
    b 2          RS     - Restart Condition Issuance Request          - not change.
    b 1          ST     - Start Condition Issuance Request            - Requests to issue a start condition. set to 1
    b 0                 - Reserved set to 0 */
    dev->master->R_IIC->CR2.UINT32    |= 0x00000002UL;
}

int32_t iic_read_bytes(int fd, uint16_t usRegister, uint16_t usSize, uint8_t *pBuf)
{
    //while(R_IIC_GetState(fd) != IDLE_STATE);
	R_IIC_Master_Transmit(fd, 0x64, 1, (uint8_t*)&usRegister);
    while(R_IIC_GetState(fd) != IDLE_STATE);
    R_IIC_Master_Reception(fd, 0x64, usSize, pBuf);
    while(R_IIC_GetState(fd) != IDLE_STATE);
    return 0; 
}
int32_t iic_write_bytes(int fd, uint16_t usRegister, uint16_t usSize, uint8_t *pBuf)
{
    uint8_t iic_sendbuf[32];
	iic_sendbuf[0]=(uint8_t)usRegister;
	memcpy(&iic_sendbuf[1], pBuf, usSize);
	R_IIC_Master_Transmit(fd, 0x64, usSize+1, iic_sendbuf);
	while(R_IIC_GetState(fd) != IDLE_STATE);
    return 0;      
}

