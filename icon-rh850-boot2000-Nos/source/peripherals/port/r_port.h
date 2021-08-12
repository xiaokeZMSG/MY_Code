/*===========================================================================*/
/* Project:  F1x StarterKit V3 Sample Software                               */
/* Module :  r_port.h                                                        */
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
#ifndef R_PORT_H
#define R_PORT_H

/*===========================================================================*/
/* Defines */
/*===========================================================================*/
/* Defines for filter settings */
#define R_FCLA_LEVEL_DETECTION  0x00
#define R_FCLA_LOW_LEVEL        0x00
#define R_FCLA_HIGH_LEVEL       0x01
#define R_FCLA_EDGE_DETECTION   0x04
#define R_FCLA_FALLING_EDGE     0x02
#define R_FCLA_RISING_EDGE      0x01

/* Enumeration for alternative functions of port pins */
enum alt_t
{
    Alt1,
    Alt2,
    Alt3,
    Alt4,
    Alt5,
    Alt6,
    Alt7
};

enum io_t
{
    Input,
    Output
};

enum level_t
{
    Low = 0,
    High = 1
};

/* Enumeration for analog filter signals */
enum fcla_signal_t
{
    R_FCLA_INTP0 = 0,
    R_FCLA_INTP1,
    R_FCLA_INTP2,
    R_FCLA_INTP3,
    R_FCLA_INTP4,
    R_FCLA_INTP5,
    R_FCLA_INTP6,
    R_FCLA_INTP7,
    R_FCLA_INTP8,
    R_FCLA_INTP9,
    R_FCLA_INTP10,
    R_FCLA_INTP11,
    R_FCLA_INTP12,
    R_FCLA_INTP13,
    R_FCLA_INTP14,
    R_FCLA_INTP15,
    R_FCLA_NMI = 0x10
};

/* Structure of registers for each port */
struct pregs_t
{
    volatile uint16_t * P_Reg;
    volatile uint16_t * PNOT_Reg;
    volatile uint16_t * PM_Reg;
    volatile uint16_t * PMC_Reg;
    volatile uint16_t * PFC_Reg;
    volatile uint16_t * PFCE_Reg;
    volatile uint16_t * PFCAE_Reg;
    volatile uint16_t * PIPC_Reg;
    volatile uint16_t * PIBC_Reg;
    volatile const uint16_t * PPR_Reg;
    volatile uint16_t * PD_Reg;
    volatile uint16_t * PU_Reg;
    volatile uint32_t * PODC_Reg;
    volatile uint16_t * PBDC_Reg;
};

/* Enumeration for ports corresponding to the PortList */
enum port_t
{
    Port0 = 0,
    Port1,
    Port2,
    Port8,
    Port9,
    Port10,
    Port11,
    Port12,
    Port18,
    Port20,
    APort0,
    APort1
};

/* Array with available registers for the available ports. Registers that are not available */
/* for a port are 0.                                                                        */
static const struct pregs_t PortList[]=
{
  {(volatile uint16_t *)&PORTP0,(volatile uint16_t *) &PORTPNOT0,(volatile uint16_t *) &PORTPM0,(volatile uint16_t *) &PORTPMC0, (volatile uint16_t *)&PORTPFC0, (volatile uint16_t *)&PORTPFCE0, (volatile uint16_t *)&PORTPFCAE0, (volatile uint16_t *)&PORTPIPC0, (volatile uint16_t *)&PORTPIBC0,(volatile uint16_t *) &PORTPPR0, (volatile uint16_t *)&PORTPD0, (volatile uint16_t *)&PORTPU0,(volatile uint32_t *)&PORTPODC0},
  {(volatile uint16_t *)&PORTP1,(volatile uint16_t *) &PORTPNOT1, (volatile uint16_t *)&PORTPM1, (volatile uint16_t *)&PORTPMC1, (volatile uint16_t *)&PORTPFC1, (volatile uint16_t *)&PORTPFCE1, (volatile uint16_t *)&PORTPFCAE1, 0, (volatile uint16_t *)&PORTPIBC1, (volatile uint16_t *)&PORTPPR1, (volatile uint16_t *)&PORTPD1, (volatile uint16_t *)&PORTPU1, (volatile uint32_t *)&PORTPODC1},
  {(volatile uint16_t *)&PORTP2, (volatile uint16_t *)&PORTPNOT2, (volatile uint16_t *)&PORTPM2, (volatile uint16_t *)&PORTPMC2, (volatile uint16_t *)&PORTPFC2, (volatile uint16_t *)&PORTPFCE2, (volatile uint16_t *)&PORTPFCAE2, 0, (volatile uint16_t *)&PORTPIBC2, (volatile uint16_t *)&PORTPPR2, (volatile uint16_t *)&PORTPD2, (volatile uint16_t *)&PORTPU2, (volatile uint32_t *)&PORTPODC2},
  {(volatile uint16_t *)&PORTP8, (volatile uint16_t *)&PORTPNOT8, (volatile uint16_t *)&PORTPM8, (volatile uint16_t *)&PORTPMC8, (volatile uint16_t *)&PORTPFC8, (volatile uint16_t *)&PORTPFCE8, 0, 0, (volatile uint16_t *)&PORTPIBC8, (volatile uint16_t *)&PORTPPR8, (volatile uint16_t *)&PORTPD8, (volatile uint16_t *)&PORTPU8, (volatile uint32_t *)&PORTPODC8},
  {(volatile uint16_t *)&PORTP9, (volatile uint16_t *)&PORTPNOT9, (volatile uint16_t *)&PORTPM9, (volatile uint16_t *)&PORTPMC9, (volatile uint16_t *)&PORTPFC9, (volatile uint16_t *)&PORTPFCE9, 0, 0, (volatile uint16_t *)&PORTPIBC9, (volatile uint16_t *)&PORTPPR9, (volatile uint16_t *)&PORTPD9, (volatile uint16_t *)&PORTPU9, (volatile uint32_t *)&PORTPODC9},
  {(volatile uint16_t *)&PORTP10, (volatile uint16_t *)&PORTPNOT10, (volatile uint16_t *)&PORTPM10, (volatile uint16_t *)&PORTPMC10, (volatile uint16_t *)&PORTPFC10, (volatile uint16_t *)&PORTPFCE10, (volatile uint16_t *)&PORTPFCAE10, (volatile uint16_t *)&PORTPIPC10, (volatile uint16_t *)&PORTPIBC10, (volatile uint16_t *)&PORTPPR10, (volatile uint16_t *)&PORTPD10, (volatile uint16_t *)&PORTPU10, (volatile uint32_t *)&PORTPODC10},
  {(volatile uint16_t *)&PORTP11, (volatile uint16_t *)&PORTPNOT11, (volatile uint16_t *)&PORTPM11, (volatile uint16_t *)&PORTPMC11, (volatile uint16_t *)&PORTPFC11, (volatile uint16_t *)&PORTPFCE11, (volatile uint16_t *)&PORTPFCAE11, (volatile uint16_t *)&PORTPIPC11, (volatile uint16_t *)&PORTPIBC11, (volatile uint16_t *)&PORTPPR11, (volatile uint16_t *)&PORTPD11, (volatile uint16_t *)&PORTPU11, (volatile uint32_t *)&PORTPODC11},
  {(volatile uint16_t *)&PORTP12, (volatile uint16_t *)&PORTPNOT12, (volatile uint16_t *)&PORTPM12, (volatile uint16_t *)&PORTPMC12, (volatile uint16_t *)&PORTPFC12, (volatile uint16_t *)&PORTPFCE12, (volatile uint16_t *)&PORTPFCAE12, 0, (volatile uint16_t *)&PORTPIBC12, (volatile uint16_t *)&PORTPPR12, (volatile uint16_t *)&PORTPD12, (volatile uint16_t *)&PORTPU12, (volatile uint32_t *)&PORTPODC12},
  {(volatile uint16_t *)&PORTP18, (volatile uint16_t *)&PORTPNOT18, (volatile uint16_t *)&PORTPM18, (volatile uint16_t *)&PORTPMC18, (volatile uint16_t *)&PORTPFC18, 0, 0, 0, (volatile uint16_t *)&PORTPIBC18, (volatile uint16_t *)&PORTPPR18, (volatile uint16_t *)&PORTPD18, (volatile uint16_t *)&PORTPU18, (volatile uint32_t *)&PORTPODC18},
  {(volatile uint16_t *)&PORTP20, (volatile uint16_t *)&PORTPNOT20, (volatile uint16_t *)&PORTPM20, (volatile uint16_t *)&PORTPMC20, (volatile uint16_t *)&PORTPFC20, (volatile uint16_t *)&PORTPFCE20, (volatile uint16_t *)&PORTPFCAE20, 0, (volatile uint16_t *)&PORTPIBC20, (volatile uint16_t *)&PORTPPR20, (volatile uint16_t *)&PORTPD20, (volatile uint16_t *)&PORTPU20, (volatile uint32_t *)&PORTPODC20},
  {(volatile uint16_t *)&PORTAP0, (volatile uint16_t *)&PORTAPNOT0, (volatile uint16_t *)&PORTAPM0, 0, 0, 0, 0, 0, (volatile uint16_t *)&PORTAPIBC0, (volatile uint16_t *)&PORTAPPR0, 0, 0, 0},
  {(volatile uint16_t *)&PORTAP1, (volatile uint16_t *)&PORTAPNOT1, (volatile uint16_t *)&PORTAPM1, 0, 0, 0, 0, 0, (volatile uint16_t *)&PORTAPIBC1, (volatile uint16_t *)&PORTAPPR1, 0, 0, 0}
};

/*===========================================================================*/
/* Function defines */
/*===========================================================================*/
void R_PORT_SetGpioOutput(enum port_t Port, uint32_t Pin, enum level_t Level);
void R_PORT_ToggleGpioOutput(enum port_t Port, uint32_t Pin);
void R_PORT_SetGpioInput(enum port_t Port, uint32_t Pin);
void R_PORT_SetGpioHighZ(enum port_t Port, uint32_t Pin);
void R_PORT_SetAltFunc(enum port_t Port, uint32_t Pin, enum alt_t Alt, enum io_t IO);
uint32_t R_PORT_GetLevel(enum port_t Port, uint32_t Pin);
void R_PORT_SetOpenDrain(enum port_t Port, uint32_t Pin);
void R_PORT_SetPushPull(enum port_t Port, uint32_t Pin);
void R_PORT_SetAnalogFilter(enum fcla_signal_t InputSignal, uint8_t FilterSetting);

#endif /* R_PORT_H */
