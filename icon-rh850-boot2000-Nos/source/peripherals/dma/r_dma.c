/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
* (c) 2014 Renesas Electronics Corporation All rights reserved.
*******************************************************************************/


/******************************************************************************
* File Name     : r_dma.c
* Version       : 1.0
* Device(s)     : R7F701035xAFP RH850/F1L
* Tool-Chain    : CubeSuite+(V2.01.00)
* Description   : This file is a sample of the DMA.
* Operation     : -
*******************************************************************************
*******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 20.03.2014 1.00    First Release
******************************************************************************/

/******************************************************************************
Includes <System Includes> , ÅgProject IncludesÅh
******************************************************************************/
#include "dr7f701587.dvf.h"
//#include "iodefine.h"
#include "r_device.h"

//#include "r_dma.h"
#include "intc/r_intc.h"

/******************************************************************************
Imported global variables and functions (from other files)
******************************************************************************/


/******************************************************************************
Macro definitions
******************************************************************************/


/******************************************************************************
Exported global variables and functions (to be accessed by other files)
******************************************************************************/
void R_DMA_Init( void );
void R_DMA_clear_tc( uint8_t chan );


/******************************************************************************
Private global variables and functions
******************************************************************************/
extern uint8_t uart_dma_tx_isr(uint8_t chan);
struct uart_dma_tag{
	volatile uint32_t *dsa;
	volatile uint32_t *dda;
	volatile uint16_t *dtc;
	volatile uint16_t *dtct;
	volatile uint8_t  *dts;
	volatile uint16_t *dtfr;
	volatile __type631 *Rlin;
	volatile uint16_t *R_ICDMA;
	uint8_t trigger_factor;
	uint8_t dma_channel;
	volatile uint32_t *DRQCLR;
};
const struct uart_dma_tag g_uart_dma_st[]=
{
    {(volatile uint32_t *)&DMAC.DSA0, (volatile uint32_t *)&DMAC.DDA0, (volatile uint16_t *)&DMAC.DTC0,(volatile uint16_t *)&DMACDTCT0, (volatile uint8_t *)&DMAC.DCEN0, (volatile uint16_t *)&DMAC.DTFR0, (volatile __type631*)0xFFCE2080/*0xFFCF0080*/, R_ICDMA0, 44, 0, (volatile uint32_t *)&DMAC.DTFRRQC0},
    {(volatile uint32_t *)&DMAC.DSA8, (volatile uint32_t *)&DMAC.DDA8, (volatile uint16_t *)&DMAC.DTC8,(volatile uint16_t *)&DMACDTCT8, (volatile uint8_t *)&DMAC.DCEN8, (volatile uint16_t *)&DMAC.DTFR8, (volatile __type631*)0xFFCE2140/*0xFFCF0140*/, R_ICDMA8, 49, 8, (volatile uint32_t *)&DMAC.DTFRRQC8},
};
#define DMA_NUM   (sizeof(g_uart_dma_st)/sizeof(struct uart_dma_tag))
/******************************************************************************
* Function Name : void R_DMA_Init( void )
* Description   : This function initialize DMA0.
* Argument      : none
* Return Value  : none
******************************************************************************/
void R_DMA_Init( void )
{
    /* Set interrupt flags */
    INTC2MKDMA0               = 1U;
    INTC2RFDMA0               = 0U;
    INTC2TBDMA0               = 0U;

    //DMCM0                = 0x0000U;                                      /* Supervisor mode is assigned as the master */
    DMACDM00CM             = 0x0000U;  
    
   // DTS0DTE              = 0U;                                           /* Disables DMA transfer */
     DMACDCEN0             = 0U;                                           /* Disables DMA transfer */
     
   // DSA0                 = (uint32_t)&ADCA0.DIR00.UINT32;                /* Set the DMA source address (ADCA0.DIR00)  */
  //  DDA0                 = (uint32_t)&dma_destination_buff[0];           /* Set the DMA destination address (RAM)     */
    DMACDTCT0              = 0x0008U;                                      /* Transfer executed 8                       */


    /* Set the transfer data size , address count direction and loop enable.
    DTCTm   - DMA Transfer Control Register
    b15                  - Reserved set to 0
    b14:b13   DTCTmDSn   - DMA transfer data size                         - 32 bits data. Set to 10'b.
    b12       DTCTmLE    - Loop enable                                    - Disable. Set to 0'b.
    b11:b 8              - Reserved set to 0
    b 7       DTCTmSACM1 - DMA transfer source address counting direction - Increment. Set to 0'b.
    b 6                  - Reserved set to 0
    b 5       DTCTmDACM1 - DMA transfer destination address counting
                           direction                                      - Increment. Set to 0'b.
    b 4:b 0              - Reserved set to 0 */
    DMACDTCT0            = 0x4000U;


    //DRQCLR               = 0x0001U;                                      /* DMA0 Request Clear       */
    DMACDTFRRQC0          = 0x0001U;                                      /* DMA0 Request Clear       */

   // DTFR0                = 0x8000U + 0x04U;                              /* Enables the generation of the DMA trigger factor. */
                                                                         /* DMA Trigger Interrupt = INTADCA0I0                */
     DMACDTFR0            == 0x0001U + (0x04U<<1);  

   //DTS0DTE              = 1U;                                           /* Enables DMA transfer     */
    DMACDCEN0            = 1U;
    
    INTC2MKDMA0               = 0U;                                           /* Enable INTDMA0 interrupt */
}


/******************************************************************************
* Function Name : void R_DMA_Init( void )
* Description   : This function initialize DMA0.
* Argument      : none
* Return Value  : none
******************************************************************************/
#define TDATASIZE8        00 
#define SADDRFIX          01
#define DADDRFIX          01  
void R_DMA_uart_init( uint8_t dma_chan )
{
	struct uart_dma_tag *uart_dma;
	if(DMA_NUM <= dma_chan)
	{
		return ;
	}
	uart_dma=(struct uart_dma_tag *)&g_uart_dma_st[dma_chan];
    /* Set interrupt flags */
   // MKDMA8               = 1U;
   // RFDMA8               = 0U;
    //TBDMA8               = 0U;

    //DMCM0                = 0x0000U;                                      /* Supervisor mode is assigned as the master */
    DMACDM00CM            = 0x0000U; 
#if 0
    DTS8DTE              = 0U;                                           /* Disables DMA transfer                     */
    DSA8                 =(uint32_t)&ADCA0.DIR00; /* Set the DMA source address (ADCA0.DIR00)  */
    DDA8                 = (uint32_t)&RLN35.LUTDR.UINT16;//RLN35LUTDR;/*(uint32_t)&dma_destination_buff[0];  */         /* Set the DMA destination address (RAM)     */
    DTC8                 = 0;                                      /* Transfer executed 8                       */


    /* Set the transfer data size , address count direction and loop enable.
    DTCTm   - DMA Transfer Control Register
    b15                  - Reserved set to 0
    b14:b13   DTCTmDSn   - DMA transfer data size                         - 32 bits data. Set to 10'b.
    b12       DTCTmLE    - Loop enable                                    - Disable. Set to 0'b.
    b11:b 8              - Reserved set to 0
    b 7       DTCTmSACM1 - DMA transfer source address counting direction - Increment. Set to 0'b.
    b 6                  - Reserved set to 0
    b 5       DTCTmDACM1 - DMA transfer destination address counting
                           direction                                      - Increment. Set to 0'b.
    b 4:b 0              - Reserved set to 0 */
    DTCT8                = (TDATASIZE8<<13)|(DADDRFIX<<5);


    DRQCLR               = 1<<8;                                      /* DMA0 Request Clear       */

    DTFR8                = 0;                                         /* Enables the generation of the DMA trigger factor. */
                                                                      /* DMA Trigger Interrupt = INTADCA0I0                */

    DTS8DTE              = 0U;                                        /* Enables DMA transfer     */

   // MKDMA8               = 0U;                                      /* Enable INTDMA8 interrupt */
    
    R_INTC_SetTableBit((uint16_t*)R_ICDMA8);
    R_INTC_UnmaskInterrupt((uint16_t*)R_ICDMA8);
#else
    *uart_dma->dts  = *uart_dma->dts & 0xfe;
	*uart_dma->dda  = (uint32_t)&uart_dma->Rlin->LUTDR.UINT16;
	*uart_dma->dtct = (TDATASIZE8<<13)|(DADDRFIX<<5);
	//*uart_dma->dtfr = 0x8000U|uart_dma->trigger_factor;
	*uart_dma->dtfr = 0x00001|(uart_dma->trigger_factor<<1);
	//DRQCLR          = 1 << uart_dma->dma_channel;
	*uart_dma->DRQCLR=  1 ;
	R_INTC_SetTableBit((uint16_t*)uart_dma->R_ICDMA);
	R_INTC_UnmaskInterrupt((uint16_t*)uart_dma->R_ICDMA);
	*uart_dma->dts &= 0x7f;
#endif
}

void R_DMA_uart_send( uint8_t dma_chan, char *uartbuf, unsigned short len  )
{
#if 0
    /* Set interrupt flags */
    //MKDMA8               = 1U;
  //  RFDMA8               = 0U;
  //  TBDMA8               = 0U;

    DMCM0                = 0x0000U;                                      /* Supervisor mode is assigned as the master */

    DTS8DTE              = 0U;                                           /* Disables DMA transfer                     */
    DSA8                 = (uint32_t)&uartbuf[1];/*(uint32_t)&ADCA0.DIR00.UINT32; */ /* Set the DMA source address (ADCA0.DIR00)  */
    DDA8                 = (uint32_t)&RLN35LUTDR;/*(uint32_t)&dma_destination_buff[0];  */         /* Set the DMA destination address (RAM)     */
    DTC8                 = len-1;                                      /* Transfer executed 8                       */


    /* Set the transfer data size , address count direction and loop enable.
    DTCTm   - DMA Transfer Control Register
    b15                  - Reserved set to 0
    b14:b13   DTCTmDSn   - DMA transfer data size                         - 32 bits data. Set to 10'b.
    b12       DTCTmLE    - Loop enable                                    - Disable. Set to 0'b.
    b11:b 8              - Reserved set to 0
    b 7       DTCTmSACM1 - DMA transfer source address counting direction - Increment. Set to 0'b.
    b 6                  - Reserved set to 0
    b 5       DTCTmDACM1 - DMA transfer destination address counting
                           direction                                      - Increment. Set to 0'b.
    b 4:b 0              - Reserved set to 0 */
    DTCT8                = (TDATASIZE8<<13)|(DADDRFIX<<5);//|(1<<12);
   

    DRQCLR               = 1<<8;                                      /* DMA0 Request Clear       */

    DTFR8                = 0x8000U+49;                              /* Enables the generation of the DMA trigger factor. */
                                                                         /* DMA Trigger Interrupt = INTADCA0I0                */

 

    DTS8DTE              = 1U;                                           /* Enables DMA transfer     */

    //MKDMA8               = 0U;                                         /* Enable INTDMA8 interrupt */
  while((RLN35LTRC&0x02)==0x02)
  {
    /* Wait until RLIN transmission is finished */
  }
  RLN35LUTDR = uartbuf[0];
  // DTS8SR               = 1U;                                           /*Software DMA transfer request*/
#else
    struct uart_dma_tag *uart_dma;
	if(DMA_NUM <=dma_chan)
	{
		return ;
	}
	uart_dma=(struct uart_dma_tag *)&g_uart_dma_st[dma_chan];
	*uart_dma->dts  = *uart_dma->dts & 0xfe;
	*uart_dma->dsa  = (uint32_t)&uartbuf;
	*uart_dma->dtc = len;
	//*uart_dma->dtfr = 0x8000U|uart_dma->trigger_factor;	
	*uart_dma->dts |= 0x01;
#endif
}

void R_DMA_uart_start(uint8_t dma_chan, const uint8_t ch)
{
	struct uart_dma_tag *uart_dma;
	if(DMA_NUM <= dma_chan)
	{
		return ;
	}
	uart_dma=(struct uart_dma_tag *)&g_uart_dma_st[dma_chan];
	uart_dma->Rlin->LUTDR.UINT16 = ch;
}
/******************************************************************************
* Function Name : void R_DMA_clear_tc( void )
* Description   : TC bit clear
* Argument      : none
* Return Value  : none
******************************************************************************/
void R_DMA_clear_tc( uint8_t chan )
{
	struct uart_dma_tag *uart_dma;
	if(DMA_NUM <= chan)
	{
		return ;
	}
	uart_dma=(struct uart_dma_tag *)&g_uart_dma_st[chan];
       while ( (*uart_dma->dts & 0x80) != 0x80U ) {
        //__nop();
    }
   // DTS8DTE              = 0U;  
    //DTS8TC               = 0U; 	
	*uart_dma->dts &= 0x7f;/* clear DMA transfer end status             */
}
#if 0
/******************************************************************************
* Function Name : void priority7_interrupt( uint32_t regEIIC_value )
* Description   : This function is priority(7) interrupt processing. (direct vector)
* Argument      : regEIIC_value     : Interrupt factor
* Return Value  : none
******************************************************************************/
#pragma interrupt priority7_interrupt( enable=false , priority=EIINT_PRIORITY7 , callt=false , fpu=false )
void priority7_interrupt( uint32_t regEIIC_value )
{
    switch ( regEIIC_value )
    {
        case 0x00001034UL: /* INTDMA0 */
            R_DMA_clear_tc();                                   /* DMA0 transfer end status clear   */
        break;

        default:
        break;
    }
}
#endif
#ifdef __IAR__
  #pragma vector = NUMINTDMA8 // NUMINTRLIN35UR1
  __interrupt void Rlin35DMA8(void)
#endif
#ifdef __GHS__
  #pragma ghs interrupt
  void Rlin35DMA8(void)
#endif
#ifdef __CSP__
  #pragma interrupt Rlin35DMA8(enable=manual)
  void Rlin35DMA8(void)
#endif /* __CSP__*/
{
    R_DMA_clear_tc(1); 
    uart_dma_tx_isr(1);
}

#ifdef __IAR__
  #pragma vector = NUMINTDMA0 // NUMINTRLIN35UR1
  __interrupt void Rlin32DMA0(void)
#endif
#ifdef __GHS__
  #pragma ghs interrupt
  void Rlin32DMA0(void)
#endif
#ifdef __CSP__
  #pragma interrupt Rlin32DMA0(enable=manual)
  void Rlin32DMA0(void)
#endif /* __CSP__*/
{
    R_DMA_clear_tc(0); 
    uart_dma_tx_isr(0);
}