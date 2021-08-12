/*===========================================================================*/
/* Project:  F1x StarterKit V3 Sample Software                               */
/* Module :  r_rlin.c                                                        */
/* Version:  V1.00                                                           */
/*===========================================================================*/
/*                                  COPYRIGHT                                */
/*===========================================================================*/
/* Copyright (c) 2016 by Renesas Electronics Europe GmbH,                    */
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
/* Source code for the RLIN2 and RLIN3 functions. RLIN24 is used as LIN      */
/* interface, RLIN30 is used as UART interface.                              */
/*                                                                           */
/*===========================================================================*/

/*===========================================================================*/
/* Includes */
/*===========================================================================*/
#include "r_device.h"
#include "r_rlin.h"
#include <string.h>
/*===========================================================================*/
/* Variables */
/*===========================================================================*/
char_t *g_pNextData;	/* Pointer to next data to be transmitted */

/*===========================================================================*/
/* Interrupts */
/*===========================================================================*/
/*****************************************************************************
** Function:    INTRLIN30UR0
** Description: RLIN30 UART Tx Completion interrupt.
** Parameter:   None
** Return:      None
******************************************************************************/
#ifdef __IAR__
    #pragma vector = NUMINTRLIN30UR0
    __interrupt void INTRLIN30UR0(void)
#endif
#ifdef __GHS__
    #pragma ghs interrupt
    void INTRLIN30UR0(void)
#endif
#ifdef __CSP__
  #pragma interrupt INTRLIN30UR0(enable=manual)
  void INTRLIN30UR0(void)
#endif /* __CSP__*/
{
	g_pNextData++;
    if(*g_pNextData != '\0')
        {
            RLN30LUTDR = *g_pNextData;
        }
}

/*===========================================================================*/
/* Functions */
/*===========================================================================*/
/*****************************************************************************
** Function:    R_RLIN24_BaudrateInit
** Description: Configures the RLIN24 Baudrate.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_RLIN24_BaudrateInit(void)
{
  /* LIN Wake-up Baud Rate Selector register  */
  RLN240GLWBR = 0X01u;
  
  /* LIN Baud Rate Prescaler1 */
  RLN240GLBRP1 = 0x02;     /* Baudrate = PCLK / (((BRP value) + 1)*(number of samples per bit)) */
  RLN240GLBRP0 = 0x81;     /* 40MHZ/((129+1)*16)=19200 */
}

/*****************************************************************************
** Function:    R_RLIN24_Channel1Init
** Description: Initialize Channel1 of RLIN24.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_RLIN24_Channel1Init(void)
{
  do{
      RLN2401L1CUC = 0x00u;
  }while(RLN2401L1MST !=0u );
  
    /* LIN Mode Register */
  RLN2401L1MD = 0x00u;      /* LIN System Clock: fa */
  
  /* LIN Break Field Configuration Register */
  RLN2401L1BFC = 0x15u;     /* b3-b0=0101: break width 18Tbits; b5b4=01: break delimiter 2Tbit */
  

  
  RLN2401L1SC = 0x17u;     /* Inter-byte(header/response) 7Tbits and interbyte 1Tbit */

  RLN2401L1WUP=0x30u;      /* b7-b4=0100: Wake-up Transmission low width 4 bits */

  RLN2401L1IE = 0x03u;       /* Tx/Rx interrupt enabled */
  

  
  /* LIN Error Detection Enable Register */
  RLN2401L1EDE = 0x0fu;      /* Enable error detection */
  
  RLN2401L1DFC = 0x28u;     /* Enhanced checksum, response field length 8byte + checksum */
  
  /* Reset is cancelled / operating mode is caused */ 
  do
  {
    RLN2401L1CUC = 0x03u;
  }while(RLN2401L1MST != 0x03u);
}

/*****************************************************************************
** Function:    R_RLIN24_Channel1TxFrame
** Description: Transmits Data on Channel 1 of RLIN24.
** Parameter:   TxFrame - Frame to be transmitted
**                  ID - Frame ID
**                  DB - Data Buffer
** Return:      LIN_OK - No error occurred
**              LIN_ERROR - Error occurred
******************************************************************************/
uint8_t R_RLIN24_Channel1TxFrame(uint8_t ID, uint8_t TxDB[])
{
  uint8_t PB = 0;
  
  /* Only 6 Bits are valid for ID */
  ID &= 0x3Fu;
  
  /* Parity Bit Calculation */
  if(ID&&0x17u)
    {
        PB |= 0x40;
    }
  if(!(ID&&0x3Au))
    {
        PB |= 0x80;
    }
  ID |= PB;
  
  while(RLN2401L1TRC&&0x03); /* Wait until an ongoing transmission is stopped */
  
  /* Set ID and Parity */
  RLN2401L1IDB = ID;

  /* Fill LIN data buffer registers */
  RLN2401L1DBR1 = TxDB[0];    
  RLN2401L1DBR2 = TxDB[1];    
  RLN2401L1DBR3 = TxDB[2];
  RLN2401L1DBR4 = TxDB[3];
  RLN2401L1DBR5 = TxDB[4];
  RLN2401L1DBR6 = TxDB[5];
  RLN2401L1DBR7 = TxDB[6];
  RLN2401L1DBR8 = TxDB[7];  
  
  RLN2401L1DFC |= 1u<<4;    /* Set mode to transmission */
  RLN2401L1TRC |= 0x01u;    /* Set start bit */
  
  while(RLN2401L1ST!=0x81u)  /* Wait while frame transmission not completed */
  {    
    if((RLN2401L1ST&8)==8u)     /* If error occurred */
    {        
      return RLIN_ERROR;   /* Return error */
    }    
  }
  return RLIN_OK;
}

/*****************************************************************************
** Function:    R_RLIN24_Channel1RxFrame
** Description: Stores Data received on Channel 1 of RLIN24.
** Parameter:   RxDB - Receive Data Buffer
** Return:      LIN_OK - No error occurred
**              LIN_ERROR - Error occurred
**              LIN_NO_MSG - No message received
******************************************************************************/
uint8_t R_RLIN24_Channel1RxFrame(uint8_t RxDB[])
{
   
    while(RLN2401L1TRC&&0x03u); /* Wait until an ongoing transmission is stopped */
    
    if(RLN2401L1ST==0x02u) /* Successful Frame Reception */
        { 
            RxDB[0] = RLN2401L1DBR1;
            RxDB[1] = RLN2401L1DBR2;
            RxDB[2] = RLN2401L1DBR3;
            RxDB[3] = RLN2401L1DBR4;
            RxDB[4] = RLN2401L1DBR5;
            RxDB[5] = RLN2401L1DBR6;
            RxDB[6] = RLN2401L1DBR7;
            RxDB[7] = RLN2401L1DBR8;
            
            return RLIN_OK;
        }
    else
        {
            if(RLN2401L1ST==0x08u) /* An error occured */
                {
                    return RLIN_ERROR;
                }
            else
                {
                    return RLIN_NO_MSG;
                }
        }
}

/*****************************************************************************
** Function:    R_RLIN30_UartInit
** Description: Initialize the RLIN30 for UART usage.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_RLIN30_UartInit(void)
{
  /* RLIN30 is configured in UART mode with 9600 baud */
  /* Disable RLIN */ 
  RLN30LUOER=0x00u;
  RLN30LCUC=0x00u;

  /* LIN Mode Register/UART Mode Register (LMD) */
  RLN30LMD=0x01u;      /* UART mode, noise filter enabled */
                                
                
  /* LIN Break Field Configuration Register/UART Configuration Register1 */
  RLN30LBFC=0x00u;     /* UART 8-bit communication */
                       /* LSB first */
                       /* Stop Bit 1 bit */
                       /* Parity Disabled */
                       /* Without RX inversion */
                       /* Without TX inversion */
  
  /* LIN / UART Error Detection Enable Register */
  RLN30LEDE=0x00u;     /* No error detection */

  /* LIN Wake-up Baud Rate Selector register  */
  RLN30LWBR=0x50u;     /* 6 samples per bit */
                  
  
  /* LIN Baud Rate Prescaler1/UART Baud Rate Prescaler */
  RLN30LBRP01=0x02b5;     /* Baudrate = PCLK / (((BRP value) + 1)*(number of samples per bit)) */
                                /* 40MHZ/((0x2b5+1)*6)= 9600 baud */


  /* LIN / UART Control Register */
  RLN30LCUC=0x01u;     /* LIN reset mode is cancelled */


  /* UART Operation Enable Register */ 
  RLN30LUOER=0x03u;    /* UART Transmission Operation Enable Bit */
                       /* UART Reception Operation Enable Bit */
}



/*****************************************************************************
** Function:    R_RLIN30_UartSendString
** Description: Sends out a string via UART.
** Parameter:   string to be send
** Return:      None
******************************************************************************/
void R_RLIN30_UartSendString(char_t send_string[])
{
  while((RLN30LST&16u)==16u)
  {
    /* Wait until RLIN transmission is finished */
  }
  
  g_pNextData = send_string;

  RLN30LUTDR = *g_pNextData;
}

/*****************************************************************************
** Function:    R_RLIN30_GetStatus
** Description: Returns if RLIN30 is busy or ready.
** Parameter:   None
** Return:      RLIN30_busy
**              RLIN30_ready
******************************************************************************/
uint8_t R_RLIN30_GetStatus(void)
{
  if((RLN30LST&16u)==16u)
  {
    return RLIN_BUSY;
  }
  else                             /* If transmission bit is 0 (transmission ready) */
  {
    return RLIN_READY;
  }
}


void R_RLIN35_UartInit(void)
{
  /* RLIN30 is configured in UART mode with 9600 baud */
  /* Disable RLIN */ 
  RLN35LUOER=0x00u; /* bit7 to bit2 reserved                                       */
                    /* bit1 UROE 0: Disables reception,    1: Enables reception    */
		    /* bit0 UTOE 0: Disables transmission, 1: Enables transmission */
                 
  RLN35LCUC=0x00u;  /*bit7 to bit1 reserved                                     */
                    /*bit0 OM0 0: LIN reset mode; 1: LIN reset mode is canceled */

  /* LIN Mode Register/UART Mode Register (LMD) */
  RLN35LMD=0x01u;   /* UART mode, noise filter enabled */
                    /*bit7,bit6,bit4 to bit2:Reserved */
		    /*bit5: LRDNFS 0: The noise filter is enabled */
		    /*             1:1: The noise filter is disabled */
		    /*bit1,bit0��LMD[1:0]�� 01 UART mode */
                                
                
  /* LIN Break Field Configuration Register/UART Configuration Register1 */
  RLN35LBFC=0x00u;     /* bit0��UART 8-bit communication */
                       /* bit1��LSB first */
                       /* bit2:Stop Bit 1 bit */
                       /* bit4,3:Parity Disabled */
                       /* bit5:Without RX inversion */
                       /* bit6:Without TX inversion */
  
  /* LIN / UART Error Detection Enable Register */
  RLN35LEDE=0x00u;     /* No error detection */
                       /*bit0 BERE  0: Disables bit error detection*/
		       /*           1: Enables bit error detection*/
		       /*bit2 OERE  0: Disables overrun error detection*/
		       /*           1: Enables overrun error detection*/
		       /*bit3 FERE  0: Disables framing error detection */
		       /*           1: Enables framing error detection */

  /* LIN Wake-up Baud Rate Selector register  */
  RLN35LWBR=0x50u;     /* 6 samples per bit */
                  
  
  /* LIN Baud Rate Prescaler1/UART Baud Rate Prescaler */
  /*RLN35LBRP01=0x02b5;*/   /* Baudrate = PCLK / (((BRP value) + 1)*(number of samples per bit)) */
                        /* 40MHZ/((0x2b5+1)*6)= 9600 baud */

  RLN35LBRP01=0x001c;   /* Baudrate = PCLK / (((BRP value) + 1)*(number of samples per bit)) */
                        /* 40MHZ/((0x1c+1)*6)= 230400 baud */

  /* LIN / UART Control Register */
  RLN35LCUC=0x01u;     /* LIN reset mode is cancelled */


  /* UART Operation Enable Register */ 
  RLN35LUOER=0x03u;    /* UART Transmission Operation Enable Bit */
                       /* UART Reception Operation Enable Bit */
}
#if 0
/*****************************************************************************
** Function:    R_RLIN30_UartSendString
** Description: Sends out a string via UART.
** Parameter:   string to be send
** Return:      None
******************************************************************************/
void R_RLIN35_UartSendString(char_t send_string[])
{
  while((RLN35LST&16u)==16u)
  {
    /* Wait until RLIN transmission is finished */
  }
  
  g_pNextData = send_string;

  RLN35LUTDR = *g_pNextData;
}

/*****************************************************************************
** Function:    R_RLIN30_UartSendString
** Description: Sends out a string via UART.
** Parameter:   string to be send
** Return:      None
******************************************************************************/
void R_RLIN35_UartSendStringByBuffer(char_t send_string[])
{
  int len;
 // while((RLN35LST&16u)==16u)
  while((RLN35LTRC&0x02)==0x02)
  {
    /* Wait until RLIN transmission is finished */
  }
  len=strlen(send_string);
  if(len>9)
    len= 9;
  RLN35LDFC = len;
  if(len==9)
  {
    RLN35LUDB0=send_string[0];
    RLN35LDBR1=send_string[1];
    RLN35LDBR2=send_string[2];
    RLN35LDBR3=send_string[3];
    RLN35LDBR4=send_string[4];
    RLN35LDBR5=send_string[5];
    RLN35LDBR6=send_string[6];
    RLN35LDBR7=send_string[7];
    RLN35LDBR8=send_string[8];
  }
  else
  {
     RLN35LDBR1=send_string[0];
     RLN35LDBR2=send_string[1];
     RLN35LDBR3=send_string[2];
     RLN35LDBR4=send_string[3];
     RLN35LDBR5=send_string[4];
     RLN35LDBR6=send_string[5];
     RLN35LDBR7=send_string[6];
     RLN35LDBR8=send_string[7];
  }
  RLN35LTRC |=0x02;
 // RLN35LUTDR = *g_pNextData;
}
#endif
/*****************************************************************************
** Function:    R_RLIN30_GetStatus
** Description: Returns if RLIN30 is busy or ready.
** Parameter:   None
** Return:      RLIN30_busy
**              RLIN30_ready
******************************************************************************/
uint8_t R_RLIN35_GetStatus(void)
{
  if((RLN35LST&16u)==16u)
  {
    return RLIN_BUSY;
  }
  else                             /* If transmission bit is 0 (transmission ready) */
  {
    return RLIN_READY;
  }
}


#ifdef __IAR__
    #pragma vector = NUMINTRLIN35UR0
    __interrupt void INTRLIN35UR0(void)
#endif
#ifdef __GHS__
    #pragma ghs interrupt
    void INTRLIN35UR0(void)
#endif
#ifdef __CSP__
  #pragma interrupt INTRLIN35UR0( enable=false , channel=0xe5 , callt=false , fpu=false )//(enable=manual)
  void INTRLIN35UR0(void)
#endif /* __CSP__*/
{

}

#ifdef __IAR__
    #pragma vector = NUMINTRLIN35UR1
    __interrupt void INTRLIN35UR1(void)
#endif
#ifdef __GHS__
    #pragma ghs interrupt
    void INTRLIN35UR1(void)
#endif
#ifdef __CSP__
  #pragma interrupt INTRLIN35UR1(enable=manual)
  void INTRLIN35UR1(void)
#endif /* __CSP__*/
{
  //RLN35LUTDR =  RLN35LURDR&0xff;
  void uart_dma_rx_isr(uint8_t chan, uint8_t data);
  uart_dma_rx_isr(1, RLN35LURDR&0xff);
}

/*****************************************************************************
** Function:    R_RLIN32_UartInit
** Description: Initialize the RLIN30 for UART usage.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_RLIN32_UartInit(void)
{
  /* RLIN30 is configured in UART mode with 9600 baud */
  /* Disable RLIN */ 
  RLN32LUOER=0x00u;
  RLN30LCUC=0x00u;

  /* LIN Mode Register/UART Mode Register (LMD) */
  RLN32LMD=0x01u;      /* UART mode, noise filter enabled */
                                
                
  /* LIN Break Field Configuration Register/UART Configuration Register1 */
  RLN32LBFC=0x00u;     /* UART 8-bit communication */
                       /* LSB first */
                       /* Stop Bit 1 bit */
                       /* Parity Disabled */
                       /* Without RX inversion */
                       /* Without TX inversion */
  
  /* LIN / UART Error Detection Enable Register */
  RLN32LEDE=0x00u;     /* No error detection */

  /* LIN Wake-up Baud Rate Selector register  */
  RLN32LWBR=0x50u;     /* 6 samples per bit */
                  
  
  /* LIN Baud Rate Prescaler1/UART Baud Rate Prescaler */
  RLN32LBRP01=0x001c;     /* Baudrate = PCLK / (((BRP value) + 1)*(number of samples per bit)) */
                                /* 40MHZ/((0x01c+1)*6)= 230400 baud */


  /* LIN / UART Control Register */
  RLN30LCUC=0x01u;     /* LIN reset mode is cancelled */


  /* UART Operation Enable Register */ 
  RLN30LUOER=0x01u;    /* UART Transmission Operation Enable Bit */
                       /* UART Reception Operation Diable Bit */
}

