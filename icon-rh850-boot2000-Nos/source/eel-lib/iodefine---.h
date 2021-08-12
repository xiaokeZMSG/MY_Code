/********************************************************************************/
/*                                                                              */
/* Device     : RH/RH850G3K/R7F701018xAFP                                       */
/* File Name  : iodefine.h                                                      */
/* Abstract   : Definition of I/O Register                                      */
/* History    : V1.00a [Device File version]                                    */
/* This is a typical example.                                                   */
/*                                                                              */
/* Copyright(c) 2013-2016 Renesas Electronics Corp. All rights reserved.        */
/*                                                                              */
/********************************************************************************/
#ifndef __R7F701018xAFPIODEFINE_HEADER__
#define __R7F701018xAFPIODEFINE_HEADER__

typedef struct
{
    unsigned char bit00:1;
    unsigned char bit01:1;
    unsigned char bit02:1;
    unsigned char bit03:1;
    unsigned char bit04:1;
    unsigned char bit05:1;
    unsigned char bit06:1;
    unsigned char bit07:1;
} bitf_T;

#define  L 0
#define  H 1
#define LL 0
#define LH 1
#define HL 2
#define HH 3

struct st_riic0
{                                                          /* RIIC0            */
    union                                                  /*                  */
    {                                                      /* CR1              */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CR1;                                                 /*                  */
    
    union                                                  /*                  */
    {                                                      /* CR2              */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CR2;                                                 /*                  */
    
    union                                                  /*                  */
    {                                                      /* MR1              */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } MR1;                                                 /*                  */
    
    union                                                  /*                  */
    {                                                      /* MR2              */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } MR2;                                                 /*                  */
    
    union                                                  /*                  */
    {                                                      /* MR3              */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } MR3;                                                 /*                  */
    
    union                                                  /*                  */
    {                                                      /* FER              */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } FER;                                                 /*                  */
    
    union                                                  /*                  */
    {                                                      /* SER              */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SER;                                                 /*                  */
    
    union                                                  /*                  */
    {                                                      /* IER              */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } IER;                                                 /*                  */
    
    union                                                  /*                  */
    {                                                      /* SR1              */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
        struct                                             /*                  */
        {                                                  /*  Bit Access      */
            unsigned char  AAS0:1;                         /*   AAS0           */
            unsigned char  AAS1:1;                         /*   AAS1           */
            unsigned char  AAS2:1;                         /*   AAS2           */
            unsigned char  GCA:1;                          /*   GCA            */
            unsigned char  :1;                             /*   Reserved Bits  */
            unsigned char  DID:1;                          /*   DID            */
            unsigned char  :1;                             /*   Reserved Bits  */
            unsigned char  HOA:1;                          /*   HOA            */
            unsigned char  :8;                             /*   Reserved Bits  */
            unsigned char  :8;                             /*   Reserved Bits  */
            unsigned char  :8;                             /*   Reserved Bits  */
        } BIT;                                             /*                  */
    } SR1;                                                 /*                  */
    
    union                                                  /*                  */
    {                                                      /* SR2              */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
        struct                                             /*                  */
        {                                                  /*  Bit Access      */
            unsigned char  TMOF:1;                         /*   TMOF           */
            unsigned char  AL:1;                           /*   AL             */
            unsigned char  START:1;                        /*   START          */
            unsigned char  STOP:1;                         /*   STOP           */
            unsigned char  NACKF:1;                        /*   NACKF          */
            unsigned char  RDRF:1;                         /*   RDRF           */
            unsigned char  TEND:1;                         /*   TEND           */
            unsigned char  TDRE:1;                         /*   TDRE           */
            unsigned char  :8;                             /*   Reserved Bits  */
            unsigned char  :8;                             /*   Reserved Bits  */
            unsigned char  :8;                             /*   Reserved Bits  */
        } BIT;                                             /*                  */
    } SR2;                                                 /*                  */
    
    union                                                  /*                  */
    {                                                      /* SAR0             */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SAR0;                                                /*                  */
    
    union                                                  /*                  */
    {                                                      /* SAR1             */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SAR1;                                                /*                  */
    
    union                                                  /*                  */
    {                                                      /* SAR2             */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SAR2;                                                /*                  */
    
    union                                                  /*                  */
    {                                                      /* BRL              */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } BRL;                                                 /*                  */
    
    union                                                  /*                  */
    {                                                      /* BRH              */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } BRH;                                                 /*                  */
    
    union                                                  /*                  */
    {                                                      /* DRT              */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } DRT;                                                 /*                  */
    
    union                                                  /*                  */
    {                                                      /* DRR              */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } DRR;                                                 /*                  */
    
};
struct st_rln240
{                                                          /* RLN240           */
    unsigned char  dummy0[1];                              /*                  */
    unsigned char  GLWBR;                                  /*  GLWBR           */
    unsigned char  GLBRP0;                                 /*  GLBRP0          */
    unsigned char  GLBRP1;                                 /*  GLBRP1          */
    unsigned char  GLSTC;                                  /*  GLSTC           */
};
struct st_rln2400
{                                                          /* RLN2400          */
    unsigned char  L0MD;                                   /*  L0MD            */
    unsigned char  L0BFC;                                  /*  L0BFC           */
    unsigned char  L0SC;                                   /*  L0SC            */
    unsigned char  L0WUP;                                  /*  L0WUP           */
    unsigned char  L0IE;                                   /*  L0IE            */
    unsigned char  L0EDE;                                  /*  L0EDE           */
    unsigned char  L0CUC;                                  /*  L0CUC           */
    unsigned char  dummy1[1];                              /*                  */
    unsigned char  L0TRC;                                  /*  L0TRC           */
    unsigned char  L0MST;                                  /*  L0MST           */
    unsigned char  L0ST;                                   /*  L0ST            */
    unsigned char  L0EST;                                  /*  L0EST           */
    unsigned char  L0DFC;                                  /*  L0DFC           */
    unsigned char  L0IDB;                                  /*  L0IDB           */
    unsigned char  L0CBR;                                  /*  L0CBR           */
    unsigned char  dummy2[1];                              /*                  */
    unsigned char  L0DBR1;                                 /*  L0DBR1          */
    unsigned char  L0DBR2;                                 /*  L0DBR2          */
    unsigned char  L0DBR3;                                 /*  L0DBR3          */
    unsigned char  L0DBR4;                                 /*  L0DBR4          */
    unsigned char  L0DBR5;                                 /*  L0DBR5          */
    unsigned char  L0DBR6;                                 /*  L0DBR6          */
    unsigned char  L0DBR7;                                 /*  L0DBR7          */
    unsigned char  L0DBR8;                                 /*  L0DBR8          */
};
struct st_rln2401
{                                                          /* RLN2401          */
    unsigned char  L1MD;                                   /*  L1MD            */
    unsigned char  L1BFC;                                  /*  L1BFC           */
    unsigned char  L1SC;                                   /*  L1SC            */
    unsigned char  L1WUP;                                  /*  L1WUP           */
    unsigned char  L1IE;                                   /*  L1IE            */
    unsigned char  L1EDE;                                  /*  L1EDE           */
    unsigned char  L1CUC;                                  /*  L1CUC           */
    unsigned char  dummy3[1];                              /*                  */
    unsigned char  L1TRC;                                  /*  L1TRC           */
    unsigned char  L1MST;                                  /*  L1MST           */
    unsigned char  L1ST;                                   /*  L1ST            */
    unsigned char  L1EST;                                  /*  L1EST           */
    unsigned char  L1DFC;                                  /*  L1DFC           */
    unsigned char  L1IDB;                                  /*  L1IDB           */
    unsigned char  L1CBR;                                  /*  L1CBR           */
    unsigned char  dummy4[1];                              /*                  */
    unsigned char  L1DBR1;                                 /*  L1DBR1          */
    unsigned char  L1DBR2;                                 /*  L1DBR2          */
    unsigned char  L1DBR3;                                 /*  L1DBR3          */
    unsigned char  L1DBR4;                                 /*  L1DBR4          */
    unsigned char  L1DBR5;                                 /*  L1DBR5          */
    unsigned char  L1DBR6;                                 /*  L1DBR6          */
    unsigned char  L1DBR7;                                 /*  L1DBR7          */
    unsigned char  L1DBR8;                                 /*  L1DBR8          */
};
struct st_rln30
{                                                          /* RLN30            */
    unsigned char  dummy5[1];                              /*                  */
    unsigned char  LWBR;                                   /*  LWBR            */
    
    union                                                  /*                  */
    {                                                      /* LBRP01           */
        unsigned short UINT16;                             /*  16-bit Access   */
        unsigned char  UINT8[2];                           /*  8-bit Access    */
        struct                                             /*                  */
        {                                                  /*                  */
            union                                          /*                  */
            {                                              /*   LBRP0          */
                unsigned char  UINT8;                      /*   8-bit Access   */
            } LBRP0;                                       /*                  */
            union                                          /*                  */
            {                                              /*   LBRP1          */
                unsigned char  UINT8;                      /*   8-bit Access   */
            } LBRP1;                                       /*                  */
        } REGS8;                                           /*                  */
    } LBRP01;                                              /*                  */
    
    unsigned char  LSTC;                                   /*  LSTC            */
    unsigned char  dummy6[3];                              /*                  */
    unsigned char  LMD;                                    /*  LMD             */
    unsigned char  LBFC;                                   /*  LBFC            */
    unsigned char  LSC;                                    /*  LSC             */
    unsigned char  LWUP;                                   /*  LWUP            */
    unsigned char  LIE;                                    /*  LIE             */
    unsigned char  LEDE;                                   /*  LEDE            */
    unsigned char  LCUC;                                   /*  LCUC            */
    unsigned char  dummy7[1];                              /*                  */
    unsigned char  LTRC;                                   /*  LTRC            */
    unsigned char  LMST;                                   /*  LMST            */
    unsigned char  LST;                                    /*  LST             */
    unsigned char  LEST;                                   /*  LEST            */
    unsigned char  LDFC;                                   /*  LDFC            */
    unsigned char  LIDB;                                   /*  LIDB            */
    unsigned char  LCBR;                                   /*  LCBR            */
    unsigned char  LUDB0;                                  /*  LUDB0           */
    unsigned char  LDBR1;                                  /*  LDBR1           */
    unsigned char  LDBR2;                                  /*  LDBR2           */
    unsigned char  LDBR3;                                  /*  LDBR3           */
    unsigned char  LDBR4;                                  /*  LDBR4           */
    unsigned char  LDBR5;                                  /*  LDBR5           */
    unsigned char  LDBR6;                                  /*  LDBR6           */
    unsigned char  LDBR7;                                  /*  LDBR7           */
    unsigned char  LDBR8;                                  /*  LDBR8           */
    unsigned char  LUOER;                                  /*  LUOER           */
    unsigned char  LUOR1;                                  /*  LUOR1           */
    unsigned char  dummy8[2];                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* LUTDR            */
        unsigned short UINT16;                             /*  16-bit Access   */
        unsigned char  UINT8[2];                           /*  8-bit Access    */
    } LUTDR;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* LURDR            */
        unsigned short UINT16;                             /*  16-bit Access   */
        unsigned char  UINT8[2];                           /*  8-bit Access    */
    } LURDR;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* LUWTDR           */
        unsigned short UINT16;                             /*  16-bit Access   */
        unsigned char  UINT8[2];                           /*  8-bit Access    */
    } LUWTDR;                                              /*                  */
    
};
struct st_rln31
{                                                          /* RLN31            */
    unsigned char  dummy9[1];                              /*                  */
    unsigned char  LWBR;                                   /*  LWBR            */
    
    union                                                  /*                  */
    {                                                      /* LBRP01           */
        unsigned short UINT16;                             /*  16-bit Access   */
        unsigned char  UINT8[2];                           /*  8-bit Access    */
        struct                                             /*                  */
        {                                                  /*                  */
            union                                          /*                  */
            {                                              /*   LBRP0          */
                unsigned char  UINT8;                      /*   8-bit Access   */
            } LBRP0;                                       /*                  */
            union                                          /*                  */
            {                                              /*   LBRP1          */
                unsigned char  UINT8;                      /*   8-bit Access   */
            } LBRP1;                                       /*                  */
        } REGS8;                                           /*                  */
    } LBRP01;                                              /*                  */
    
    unsigned char  LSTC;                                   /*  LSTC            */
    unsigned char  dummy10[3];                             /*                  */
    unsigned char  LMD;                                    /*  LMD             */
    unsigned char  LBFC;                                   /*  LBFC            */
    unsigned char  LSC;                                    /*  LSC             */
    unsigned char  LWUP;                                   /*  LWUP            */
    unsigned char  LIE;                                    /*  LIE             */
    unsigned char  LEDE;                                   /*  LEDE            */
    unsigned char  LCUC;                                   /*  LCUC            */
    unsigned char  dummy11[1];                             /*                  */
    unsigned char  LTRC;                                   /*  LTRC            */
    unsigned char  LMST;                                   /*  LMST            */
    unsigned char  LST;                                    /*  LST             */
    unsigned char  LEST;                                   /*  LEST            */
    unsigned char  LDFC;                                   /*  LDFC            */
    unsigned char  LIDB;                                   /*  LIDB            */
    unsigned char  LCBR;                                   /*  LCBR            */
    unsigned char  LUDB0;                                  /*  LUDB0           */
    unsigned char  LDBR1;                                  /*  LDBR1           */
    unsigned char  LDBR2;                                  /*  LDBR2           */
    unsigned char  LDBR3;                                  /*  LDBR3           */
    unsigned char  LDBR4;                                  /*  LDBR4           */
    unsigned char  LDBR5;                                  /*  LDBR5           */
    unsigned char  LDBR6;                                  /*  LDBR6           */
    unsigned char  LDBR7;                                  /*  LDBR7           */
    unsigned char  LDBR8;                                  /*  LDBR8           */
    unsigned char  LUOER;                                  /*  LUOER           */
    unsigned char  LUOR1;                                  /*  LUOR1           */
    unsigned char  dummy12[2];                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* LUTDR            */
        unsigned short UINT16;                             /*  16-bit Access   */
        unsigned char  UINT8[2];                           /*  8-bit Access    */
    } LUTDR;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* LURDR            */
        unsigned short UINT16;                             /*  16-bit Access   */
        unsigned char  UINT8[2];                           /*  8-bit Access    */
    } LURDR;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* LUWTDR           */
        unsigned short UINT16;                             /*  16-bit Access   */
        unsigned char  UINT8[2];                           /*  8-bit Access    */
    } LUWTDR;                                              /*                  */
    
};
struct st_rln32
{                                                          /* RLN32            */
    unsigned char  dummy13[1];                             /*                  */
    unsigned char  LWBR;                                   /*  LWBR            */
    
    union                                                  /*                  */
    {                                                      /* LBRP01           */
        unsigned short UINT16;                             /*  16-bit Access   */
        unsigned char  UINT8[2];                           /*  8-bit Access    */
        struct                                             /*                  */
        {                                                  /*                  */
            union                                          /*                  */
            {                                              /*   LBRP0          */
                unsigned char  UINT8;                      /*   8-bit Access   */
            } LBRP0;                                       /*                  */
            union                                          /*                  */
            {                                              /*   LBRP1          */
                unsigned char  UINT8;                      /*   8-bit Access   */
            } LBRP1;                                       /*                  */
        } REGS8;                                           /*                  */
    } LBRP01;                                              /*                  */
    
    unsigned char  LSTC;                                   /*  LSTC            */
    unsigned char  dummy14[3];                             /*                  */
    unsigned char  LMD;                                    /*  LMD             */
    unsigned char  LBFC;                                   /*  LBFC            */
    unsigned char  LSC;                                    /*  LSC             */
    unsigned char  LWUP;                                   /*  LWUP            */
    unsigned char  LIE;                                    /*  LIE             */
    unsigned char  LEDE;                                   /*  LEDE            */
    unsigned char  LCUC;                                   /*  LCUC            */
    unsigned char  dummy15[1];                             /*                  */
    unsigned char  LTRC;                                   /*  LTRC            */
    unsigned char  LMST;                                   /*  LMST            */
    unsigned char  LST;                                    /*  LST             */
    unsigned char  LEST;                                   /*  LEST            */
    unsigned char  LDFC;                                   /*  LDFC            */
    unsigned char  LIDB;                                   /*  LIDB            */
    unsigned char  LCBR;                                   /*  LCBR            */
    unsigned char  LUDB0;                                  /*  LUDB0           */
    unsigned char  LDBR1;                                  /*  LDBR1           */
    unsigned char  LDBR2;                                  /*  LDBR2           */
    unsigned char  LDBR3;                                  /*  LDBR3           */
    unsigned char  LDBR4;                                  /*  LDBR4           */
    unsigned char  LDBR5;                                  /*  LDBR5           */
    unsigned char  LDBR6;                                  /*  LDBR6           */
    unsigned char  LDBR7;                                  /*  LDBR7           */
    unsigned char  LDBR8;                                  /*  LDBR8           */
    unsigned char  LUOER;                                  /*  LUOER           */
    unsigned char  LUOR1;                                  /*  LUOR1           */
    unsigned char  dummy16[2];                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* LUTDR            */
        unsigned short UINT16;                             /*  16-bit Access   */
        unsigned char  UINT8[2];                           /*  8-bit Access    */
    } LUTDR;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* LURDR            */
        unsigned short UINT16;                             /*  16-bit Access   */
        unsigned char  UINT8[2];                           /*  8-bit Access    */
    } LURDR;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* LUWTDR           */
        unsigned short UINT16;                             /*  16-bit Access   */
        unsigned char  UINT8[2];                           /*  8-bit Access    */
    } LUWTDR;                                              /*                  */
    
};
struct st_rscan0
{                                                          /* RSCAN0           */
    union                                                  /*                  */
    {                                                      /* C0CFG            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } C0CFG;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* C0CTR            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } C0CTR;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* C0STS            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } C0STS;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* C0ERFL           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } C0ERFL;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* C1CFG            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } C1CFG;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* C1CTR            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } C1CTR;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* C1STS            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } C1STS;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* C1ERFL           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } C1ERFL;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* C2CFG            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } C2CFG;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* C2CTR            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } C2CTR;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* C2STS            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } C2STS;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* C2ERFL           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } C2ERFL;                                              /*                  */
    
    unsigned char  dummy17[84];                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GCFG             */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GCFG;                                                /*                  */
    
    union                                                  /*                  */
    {                                                      /* GCTR             */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GCTR;                                                /*                  */
    
    union                                                  /*                  */
    {                                                      /* GSTS             */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GSTS;                                                /*                  */
    
    union                                                  /*                  */
    {                                                      /* GERFL            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GERFL;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* GTSC             */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GTSC;                                                /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLECTR         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLECTR;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLCFG0         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLCFG0;                                            /*                  */
    
    unsigned char  dummy18[4];                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMNB             */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMNB;                                                /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMND0            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMND0;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMND1            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMND1;                                               /*                  */
    
    unsigned char  dummy19[8];                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFCC0            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFCC0;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFCC1            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFCC1;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFCC2            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFCC2;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFCC3            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFCC3;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFCC4            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFCC4;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFCC5            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFCC5;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFCC6            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFCC6;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFCC7            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFCC7;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFSTS0           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFSTS0;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFSTS1           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFSTS1;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFSTS2           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFSTS2;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFSTS3           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFSTS3;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFSTS4           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFSTS4;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFSTS5           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFSTS5;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFSTS6           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFSTS6;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFSTS7           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFSTS7;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFPCTR0          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFPCTR0;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFPCTR1          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFPCTR1;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFPCTR2          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFPCTR2;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFPCTR3          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFPCTR3;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFPCTR4          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFPCTR4;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFPCTR5          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFPCTR5;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFPCTR6          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFPCTR6;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFPCTR7          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFPCTR7;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFCC0            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFCC0;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFCC1            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFCC1;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFCC2            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFCC2;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFCC3            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFCC3;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFCC4            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFCC4;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFCC5            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFCC5;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFCC6            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFCC6;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFCC7            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFCC7;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFCC8            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFCC8;                                               /*                  */
    
    unsigned char  dummy20[60];                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFSTS0           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFSTS0;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFSTS1           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFSTS1;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFSTS2           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFSTS2;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFSTS3           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFSTS3;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFSTS4           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFSTS4;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFSTS5           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFSTS5;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFSTS6           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFSTS6;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFSTS7           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFSTS7;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFSTS8           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFSTS8;                                              /*                  */
    
    unsigned char  dummy21[60];                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFPCTR0          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFPCTR0;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFPCTR1          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFPCTR1;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFPCTR2          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFPCTR2;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFPCTR3          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFPCTR3;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFPCTR4          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFPCTR4;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFPCTR5          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFPCTR5;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFPCTR6          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFPCTR6;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFPCTR7          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFPCTR7;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFPCTR8          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFPCTR8;                                             /*                  */
    
    unsigned char  dummy22[60];                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* FESTS            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } FESTS;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* FFSTS            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } FFSTS;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* FMSTS            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } FMSTS;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFISTS           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFISTS;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFRISTS          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFRISTS;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFTISTS          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFTISTS;                                             /*                  */
    
    unsigned char  TMC0;                                   /*  TMC0            */
    unsigned char  TMC1;                                   /*  TMC1            */
    unsigned char  TMC2;                                   /*  TMC2            */
    unsigned char  TMC3;                                   /*  TMC3            */
    unsigned char  TMC4;                                   /*  TMC4            */
    unsigned char  TMC5;                                   /*  TMC5            */
    unsigned char  TMC6;                                   /*  TMC6            */
    unsigned char  TMC7;                                   /*  TMC7            */
    unsigned char  TMC8;                                   /*  TMC8            */
    unsigned char  TMC9;                                   /*  TMC9            */
    unsigned char  TMC10;                                  /*  TMC10           */
    unsigned char  TMC11;                                  /*  TMC11           */
    unsigned char  TMC12;                                  /*  TMC12           */
    unsigned char  TMC13;                                  /*  TMC13           */
    unsigned char  TMC14;                                  /*  TMC14           */
    unsigned char  TMC15;                                  /*  TMC15           */
    unsigned char  TMC16;                                  /*  TMC16           */
    unsigned char  TMC17;                                  /*  TMC17           */
    unsigned char  TMC18;                                  /*  TMC18           */
    unsigned char  TMC19;                                  /*  TMC19           */
    unsigned char  TMC20;                                  /*  TMC20           */
    unsigned char  TMC21;                                  /*  TMC21           */
    unsigned char  TMC22;                                  /*  TMC22           */
    unsigned char  TMC23;                                  /*  TMC23           */
    unsigned char  TMC24;                                  /*  TMC24           */
    unsigned char  TMC25;                                  /*  TMC25           */
    unsigned char  TMC26;                                  /*  TMC26           */
    unsigned char  TMC27;                                  /*  TMC27           */
    unsigned char  TMC28;                                  /*  TMC28           */
    unsigned char  TMC29;                                  /*  TMC29           */
    unsigned char  TMC30;                                  /*  TMC30           */
    unsigned char  TMC31;                                  /*  TMC31           */
    unsigned char  TMC32;                                  /*  TMC32           */
    unsigned char  TMC33;                                  /*  TMC33           */
    unsigned char  TMC34;                                  /*  TMC34           */
    unsigned char  TMC35;                                  /*  TMC35           */
    unsigned char  TMC36;                                  /*  TMC36           */
    unsigned char  TMC37;                                  /*  TMC37           */
    unsigned char  TMC38;                                  /*  TMC38           */
    unsigned char  TMC39;                                  /*  TMC39           */
    unsigned char  TMC40;                                  /*  TMC40           */
    unsigned char  TMC41;                                  /*  TMC41           */
    unsigned char  TMC42;                                  /*  TMC42           */
    unsigned char  TMC43;                                  /*  TMC43           */
    unsigned char  TMC44;                                  /*  TMC44           */
    unsigned char  TMC45;                                  /*  TMC45           */
    unsigned char  TMC46;                                  /*  TMC46           */
    unsigned char  TMC47;                                  /*  TMC47           */
    unsigned char  dummy23[80];                            /*                  */
    unsigned char  TMSTS0;                                 /*  TMSTS0          */
    unsigned char  TMSTS1;                                 /*  TMSTS1          */
    unsigned char  TMSTS2;                                 /*  TMSTS2          */
    unsigned char  TMSTS3;                                 /*  TMSTS3          */
    unsigned char  TMSTS4;                                 /*  TMSTS4          */
    unsigned char  TMSTS5;                                 /*  TMSTS5          */
    unsigned char  TMSTS6;                                 /*  TMSTS6          */
    unsigned char  TMSTS7;                                 /*  TMSTS7          */
    unsigned char  TMSTS8;                                 /*  TMSTS8          */
    unsigned char  TMSTS9;                                 /*  TMSTS9          */
    unsigned char  TMSTS10;                                /*  TMSTS10         */
    unsigned char  TMSTS11;                                /*  TMSTS11         */
    unsigned char  TMSTS12;                                /*  TMSTS12         */
    unsigned char  TMSTS13;                                /*  TMSTS13         */
    unsigned char  TMSTS14;                                /*  TMSTS14         */
    unsigned char  TMSTS15;                                /*  TMSTS15         */
    unsigned char  TMSTS16;                                /*  TMSTS16         */
    unsigned char  TMSTS17;                                /*  TMSTS17         */
    unsigned char  TMSTS18;                                /*  TMSTS18         */
    unsigned char  TMSTS19;                                /*  TMSTS19         */
    unsigned char  TMSTS20;                                /*  TMSTS20         */
    unsigned char  TMSTS21;                                /*  TMSTS21         */
    unsigned char  TMSTS22;                                /*  TMSTS22         */
    unsigned char  TMSTS23;                                /*  TMSTS23         */
    unsigned char  TMSTS24;                                /*  TMSTS24         */
    unsigned char  TMSTS25;                                /*  TMSTS25         */
    unsigned char  TMSTS26;                                /*  TMSTS26         */
    unsigned char  TMSTS27;                                /*  TMSTS27         */
    unsigned char  TMSTS28;                                /*  TMSTS28         */
    unsigned char  TMSTS29;                                /*  TMSTS29         */
    unsigned char  TMSTS30;                                /*  TMSTS30         */
    unsigned char  TMSTS31;                                /*  TMSTS31         */
    unsigned char  TMSTS32;                                /*  TMSTS32         */
    unsigned char  TMSTS33;                                /*  TMSTS33         */
    unsigned char  TMSTS34;                                /*  TMSTS34         */
    unsigned char  TMSTS35;                                /*  TMSTS35         */
    unsigned char  TMSTS36;                                /*  TMSTS36         */
    unsigned char  TMSTS37;                                /*  TMSTS37         */
    unsigned char  TMSTS38;                                /*  TMSTS38         */
    unsigned char  TMSTS39;                                /*  TMSTS39         */
    unsigned char  TMSTS40;                                /*  TMSTS40         */
    unsigned char  TMSTS41;                                /*  TMSTS41         */
    unsigned char  TMSTS42;                                /*  TMSTS42         */
    unsigned char  TMSTS43;                                /*  TMSTS43         */
    unsigned char  TMSTS44;                                /*  TMSTS44         */
    unsigned char  TMSTS45;                                /*  TMSTS45         */
    unsigned char  TMSTS46;                                /*  TMSTS46         */
    unsigned char  TMSTS47;                                /*  TMSTS47         */
    unsigned char  dummy24[80];                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMTRSTS0         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMTRSTS0;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMTRSTS1         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMTRSTS1;                                            /*                  */
    
    unsigned char  dummy25[8];                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMTARSTS0        */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMTARSTS0;                                           /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMTARSTS1        */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMTARSTS1;                                           /*                  */
    
    unsigned char  dummy26[8];                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMTCSTS0         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMTCSTS0;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMTCSTS1         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMTCSTS1;                                            /*                  */
    
    unsigned char  dummy27[8];                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMTASTS0         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMTASTS0;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMTASTS1         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMTASTS1;                                            /*                  */
    
    unsigned char  dummy28[8];                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMIEC0           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMIEC0;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMIEC1           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMIEC1;                                              /*                  */
    
    unsigned char  dummy29[8];                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TXQCC0           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TXQCC0;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TXQCC1           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TXQCC1;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TXQCC2           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TXQCC2;                                              /*                  */
    
    unsigned char  dummy30[20];                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* TXQSTS0          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TXQSTS0;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TXQSTS1          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TXQSTS1;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TXQSTS2          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TXQSTS2;                                             /*                  */
    
    unsigned char  dummy31[20];                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* TXQPCTR0         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TXQPCTR0;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* TXQPCTR1         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TXQPCTR1;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* TXQPCTR2         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TXQPCTR2;                                            /*                  */
    
    unsigned char  dummy32[20];                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* THLCC0           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THLCC0;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* THLCC1           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THLCC1;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* THLCC2           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THLCC2;                                              /*                  */
    
    unsigned char  dummy33[20];                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* THLSTS0          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THLSTS0;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* THLSTS1          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THLSTS1;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* THLSTS2          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THLSTS2;                                             /*                  */
    
    unsigned char  dummy34[20];                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* THLPCTR0         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THLPCTR0;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* THLPCTR1         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THLPCTR1;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* THLPCTR2         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THLPCTR2;                                            /*                  */
    
    unsigned char  dummy35[20];                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GTINTSTS0        */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GTINTSTS0;                                           /*                  */
    
    unsigned char  dummy36[4];                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GTSTCFG          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GTSTCFG;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GTSTCTR          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GTSTCTR;                                             /*                  */
    
    unsigned char  dummy37[12];                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GLOCKK           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } GLOCKK;                                              /*                  */
    
    unsigned char  dummy38[128];                           /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLID0          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLID0;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLM0           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLM0;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP00          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP00;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP10          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP10;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLID1          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLID1;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLM1           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLM1;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP01          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP01;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP11          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP11;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLID2          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLID2;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLM2           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLM2;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP02          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP02;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP12          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP12;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLID3          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLID3;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLM3           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLM3;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP03          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP03;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP13          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP13;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLID4          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLID4;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLM4           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLM4;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP04          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP04;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP14          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP14;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLID5          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLID5;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLM5           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLM5;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP05          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP05;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP15          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP15;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLID6          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLID6;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLM6           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLM6;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP06          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP06;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP16          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP16;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLID7          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLID7;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLM7           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLM7;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP07          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP07;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP17          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP17;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLID8          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLID8;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLM8           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLM8;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP08          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP08;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP18          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP18;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLID9          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLID9;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLM9           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLM9;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP09          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP09;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP19          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP19;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLID10         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLID10;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLM10          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLM10;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP010         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP010;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP110         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP110;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLID11         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLID11;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLM11          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLM11;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP011         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP011;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP111         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP111;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLID12         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLID12;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLM12          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLM12;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP012         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP012;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP112         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP112;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLID13         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLID13;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLM13          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLM13;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP013         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP013;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP113         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP113;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLID14         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLID14;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLM14          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLM14;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP014         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP014;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP114         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP114;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLID15         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLID15;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLM15          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLM15;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP015         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP015;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* GAFLP115         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } GAFLP115;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID0            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID0;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR0           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR0;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF00           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF00;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF10           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF10;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID1            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID1;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR1           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR1;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF01           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF01;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF11           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF11;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID2            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID2;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR2           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR2;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF02           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF02;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF12           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF12;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID3            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID3;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR3           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR3;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF03           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF03;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF13           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF13;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID4            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID4;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR4           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR4;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF04           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF04;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF14           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF14;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID5            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID5;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR5           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR5;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF05           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF05;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF15           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF15;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID6            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID6;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR6           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR6;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF06           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF06;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF16           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF16;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID7            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID7;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR7           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR7;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF07           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF07;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF17           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF17;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID8            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID8;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR8           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR8;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF08           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF08;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF18           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF18;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID9            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID9;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR9           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR9;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF09           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF09;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF19           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF19;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID10           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID10;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR10          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR10;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF010          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF010;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF110          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF110;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID11           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID11;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR11          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR11;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF011          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF011;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF111          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF111;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID12           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID12;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR12          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR12;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF012          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF012;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF112          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF112;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID13           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID13;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR13          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR13;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF013          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF013;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF113          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF113;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID14           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID14;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR14          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR14;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF014          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF014;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF114          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF114;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID15           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID15;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR15          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR15;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF015          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF015;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF115          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF115;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID16           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID16;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR16          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR16;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF016          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF016;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF116          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF116;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID17           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID17;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR17          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR17;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF017          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF017;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF117          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF117;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID18           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID18;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR18          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR18;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF018          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF018;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF118          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF118;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID19           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID19;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR19          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR19;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF019          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF019;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF119          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF119;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID20           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID20;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR20          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR20;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF020          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF020;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF120          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF120;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID21           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID21;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR21          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR21;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF021          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF021;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF121          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF121;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID22           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID22;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR22          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR22;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF022          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF022;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF122          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF122;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID23           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID23;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR23          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR23;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF023          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF023;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF123          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF123;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID24           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID24;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR24          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR24;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF024          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF024;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF124          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF124;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID25           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID25;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR25          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR25;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF025          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF025;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF125          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF125;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID26           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID26;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR26          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR26;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF026          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF026;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF126          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF126;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID27           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID27;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR27          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR27;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF027          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF027;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF127          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF127;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID28           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID28;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR28          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR28;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF028          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF028;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF128          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF128;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID29           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID29;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR29          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR29;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF029          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF029;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF129          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF129;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID30           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID30;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR30          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR30;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF030          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF030;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF130          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF130;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID31           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID31;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR31          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR31;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF031          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF031;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF131          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF131;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID32           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID32;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR32          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR32;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF032          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF032;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF132          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF132;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID33           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID33;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR33          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR33;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF033          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF033;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF133          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF133;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID34           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID34;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR34          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR34;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF034          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF034;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF134          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF134;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID35           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID35;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR35          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR35;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF035          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF035;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF135          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF135;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID36           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID36;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR36          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR36;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF036          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF036;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF136          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF136;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID37           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID37;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR37          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR37;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF037          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF037;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF137          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF137;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID38           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID38;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR38          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR38;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF038          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF038;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF138          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF138;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID39           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID39;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR39          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR39;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF039          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF039;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF139          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF139;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID40           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID40;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR40          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR40;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF040          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF040;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF140          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF140;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID41           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID41;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR41          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR41;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF041          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF041;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF141          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF141;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID42           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID42;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR42          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR42;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF042          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF042;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF142          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF142;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID43           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID43;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR43          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR43;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF043          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF043;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF143          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF143;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID44           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID44;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR44          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR44;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF044          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF044;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF144          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF144;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID45           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID45;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR45          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR45;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF045          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF045;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF145          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF145;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID46           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID46;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR46          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR46;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF046          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF046;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF146          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF146;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMID47           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMID47;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMPTR47          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMPTR47;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF047          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF047;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RMDF147          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RMDF147;                                             /*                  */
    
    unsigned char  dummy39[1280];                          /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFID0            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFID0;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFPTR0           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFPTR0;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFDF00           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFDF00;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFDF10           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFDF10;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFID1            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFID1;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFPTR1           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFPTR1;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFDF01           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFDF01;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFDF11           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFDF11;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFID2            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFID2;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFPTR2           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFPTR2;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFDF02           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFDF02;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFDF12           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFDF12;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFID3            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFID3;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFPTR3           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFPTR3;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFDF03           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFDF03;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFDF13           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFDF13;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFID4            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFID4;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFPTR4           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFPTR4;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFDF04           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFDF04;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFDF14           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFDF14;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFID5            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFID5;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFPTR5           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFPTR5;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFDF05           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFDF05;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFDF15           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFDF15;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFID6            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFID6;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFPTR6           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFPTR6;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFDF06           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFDF06;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFDF16           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFDF16;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFID7            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFID7;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFPTR7           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFPTR7;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFDF07           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFDF07;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* RFDF17           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RFDF17;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFID0            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFID0;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFPTR0           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFPTR0;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFDF00           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFDF00;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFDF10           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFDF10;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFID1            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFID1;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFPTR1           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFPTR1;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFDF01           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFDF01;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFDF11           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFDF11;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFID2            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFID2;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFPTR2           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFPTR2;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFDF02           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFDF02;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFDF12           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFDF12;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFID3            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFID3;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFPTR3           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFPTR3;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFDF03           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFDF03;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFDF13           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFDF13;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFID4            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFID4;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFPTR4           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFPTR4;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFDF04           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFDF04;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFDF14           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFDF14;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFID5            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFID5;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFPTR5           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFPTR5;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFDF05           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFDF05;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFDF15           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFDF15;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFID6            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFID6;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFPTR6           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFPTR6;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFDF06           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFDF06;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFDF16           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFDF16;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFID7            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFID7;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFPTR7           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFPTR7;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFDF07           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFDF07;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFDF17           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFDF17;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFID8            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFID8;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFPTR8           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFPTR8;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFDF08           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFDF08;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* CFDF18           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } CFDF18;                                              /*                  */
    
    unsigned char  dummy40[240];                           /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID0            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID0;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR0           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR0;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF00           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF00;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF10           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF10;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID1            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID1;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR1           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR1;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF01           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF01;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF11           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF11;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID2            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID2;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR2           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR2;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF02           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF02;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF12           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF12;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID3            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID3;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR3           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR3;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF03           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF03;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF13           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF13;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID4            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID4;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR4           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR4;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF04           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF04;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF14           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF14;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID5            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID5;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR5           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR5;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF05           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF05;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF15           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF15;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID6            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID6;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR6           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR6;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF06           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF06;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF16           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF16;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID7            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID7;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR7           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR7;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF07           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF07;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF17           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF17;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID8            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID8;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR8           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR8;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF08           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF08;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF18           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF18;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID9            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID9;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR9           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR9;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF09           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF09;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF19           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF19;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID10           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID10;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR10          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR10;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF010          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF010;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF110          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF110;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID11           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID11;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR11          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR11;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF011          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF011;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF111          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF111;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID12           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID12;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR12          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR12;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF012          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF012;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF112          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF112;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID13           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID13;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR13          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR13;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF013          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF013;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF113          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF113;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID14           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID14;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR14          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR14;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF014          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF014;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF114          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF114;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID15           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID15;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR15          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR15;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF015          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF015;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF115          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF115;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID16           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID16;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR16          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR16;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF016          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF016;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF116          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF116;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID17           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID17;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR17          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR17;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF017          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF017;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF117          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF117;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID18           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID18;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR18          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR18;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF018          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF018;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF118          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF118;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID19           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID19;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR19          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR19;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF019          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF019;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF119          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF119;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID20           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID20;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR20          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR20;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF020          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF020;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF120          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF120;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID21           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID21;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR21          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR21;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF021          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF021;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF121          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF121;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID22           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID22;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR22          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR22;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF022          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF022;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF122          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF122;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID23           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID23;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR23          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR23;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF023          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF023;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF123          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF123;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID24           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID24;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR24          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR24;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF024          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF024;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF124          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF124;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID25           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID25;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR25          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR25;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF025          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF025;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF125          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF125;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID26           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID26;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR26          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR26;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF026          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF026;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF126          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF126;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID27           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID27;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR27          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR27;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF027          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF027;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF127          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF127;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID28           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID28;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR28          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR28;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF028          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF028;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF128          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF128;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID29           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID29;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR29          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR29;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF029          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF029;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF129          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF129;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID30           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID30;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR30          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR30;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF030          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF030;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF130          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF130;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID31           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID31;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR31          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR31;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF031          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF031;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF131          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF131;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID32           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID32;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR32          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR32;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF032          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF032;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF132          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF132;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID33           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID33;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR33          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR33;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF033          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF033;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF133          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF133;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID34           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID34;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR34          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR34;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF034          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF034;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF134          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF134;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID35           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID35;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR35          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR35;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF035          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF035;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF135          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF135;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID36           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID36;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR36          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR36;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF036          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF036;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF136          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF136;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID37           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID37;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR37          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR37;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF037          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF037;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF137          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF137;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID38           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID38;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR38          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR38;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF038          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF038;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF138          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF138;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID39           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID39;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR39          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR39;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF039          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF039;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF139          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF139;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID40           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID40;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR40          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR40;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF040          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF040;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF140          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF140;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID41           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID41;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR41          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR41;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF041          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF041;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF141          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF141;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID42           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID42;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR42          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR42;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF042          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF042;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF142          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF142;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID43           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID43;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR43          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR43;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF043          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF043;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF143          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF143;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID44           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID44;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR44          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR44;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF044          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF044;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF144          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF144;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID45           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID45;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR45          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR45;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF045          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF045;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF145          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF145;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID46           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID46;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR46          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR46;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF046          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF046;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF146          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF146;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMID47           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMID47;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMPTR47          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMPTR47;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF047          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF047;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* TMDF147          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } TMDF147;                                             /*                  */
    
    unsigned char  dummy41[1280];                          /*                  */
    
    union                                                  /*                  */
    {                                                      /* THLACC0          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THLACC0;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* THLACC1          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THLACC1;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* THLACC2          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THLACC2;                                             /*                  */
    
    unsigned char  dummy42[244];                           /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC0          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC0;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC1          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC1;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC2          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC2;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC3          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC3;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC4          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC4;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC5          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC5;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC6          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC6;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC7          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC7;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC8          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC8;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC9          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC9;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC10         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC10;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC11         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC11;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC12         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC12;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC13         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC13;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC14         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC14;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC15         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC15;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC16         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC16;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC17         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC17;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC18         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC18;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC19         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC19;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC20         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC20;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC21         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC21;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC22         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC22;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC23         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC23;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC24         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC24;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC25         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC25;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC26         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC26;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC27         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC27;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC28         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC28;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC29         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC29;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC30         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC30;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC31         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC31;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC32         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC32;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC33         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC33;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC34         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC34;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC35         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC35;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC36         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC36;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC37         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC37;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC38         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC38;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC39         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC39;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC40         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC40;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC41         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC41;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC42         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC42;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC43         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC43;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC44         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC44;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC45         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC45;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC46         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC46;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC47         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC47;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC48         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC48;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC49         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC49;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC50         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC50;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC51         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC51;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC52         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC52;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC53         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC53;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC54         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC54;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC55         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC55;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC56         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC56;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC57         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC57;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC58         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC58;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC59         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC59;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC60         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC60;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC61         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC61;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC62         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC62;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* RPGACC63         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } RPGACC63;                                            /*                  */
    
};
struct st_csih0
{                                                          /* CSIH0            */
    union                                                  /*                  */
    {                                                      /* CTL0             */
        unsigned char  UINT8;                              /*  8-bit Access    */
        struct                                             /*                  */
        {                                                  /*  Bit Access      */
            unsigned char  MBS:1;                          /*   MBS            */
            unsigned char  JOBE:1;                         /*   JOBE           */
            unsigned char  :3;                             /*   Reserved Bits  */
            unsigned char  RXE:1;                          /*   RXE            */
            unsigned char  TXE:1;                          /*   TXE            */
            unsigned char  PWR:1;                          /*   PWR            */
        } BIT;                                             /*                  */
    } CTL0;                                                /*                  */
    
    unsigned char  dummy43[3];                             /*                  */
    unsigned long  STR0;                                   /*  STR0            */
    unsigned short STCR0;                                  /*  STCR0           */
    unsigned char  dummy44[6];                             /*                  */
    unsigned long  CTL1;                                   /*  CTL1            */
    unsigned short CTL2;                                   /*  CTL2            */
    unsigned char  dummy45[2];                             /*                  */
    unsigned char  EMU;                                    /*  EMU             */
    unsigned char  dummy46[4071];                          /*                  */
    unsigned long  MCTL1;                                  /*  MCTL1           */
    unsigned long  MCTL2;                                  /*  MCTL2           */
    unsigned long  TX0W;                                   /*  TX0W            */
    unsigned short TX0H;                                   /*  TX0H            */
    unsigned char  dummy47[2];                             /*                  */
    unsigned long  RX0W;                                   /*  RX0W            */
    unsigned short RX0H;                                   /*  RX0H            */
    unsigned char  dummy48[2];                             /*                  */
    unsigned long  MRWP0;                                  /*  MRWP0           */
    unsigned char  dummy49[36];                            /*                  */
    unsigned short MCTL0;                                  /*  MCTL0           */
    unsigned char  dummy50[2];                             /*                  */
    unsigned long  CFG0;                                   /*  CFG0            */
    unsigned long  CFG1;                                   /*  CFG1            */
    unsigned long  CFG2;                                   /*  CFG2            */
    unsigned long  CFG3;                                   /*  CFG3            */
    unsigned long  CFG4;                                   /*  CFG4            */
    unsigned long  CFG5;                                   /*  CFG5            */
    unsigned long  CFG6;                                   /*  CFG6            */
    unsigned long  CFG7;                                   /*  CFG7            */
    unsigned char  dummy51[4];                             /*                  */
    unsigned short BRS0;                                   /*  BRS0            */
    unsigned char  dummy52[2];                             /*                  */
    unsigned short BRS1;                                   /*  BRS1            */
    unsigned char  dummy53[2];                             /*                  */
    unsigned short BRS2;                                   /*  BRS2            */
    unsigned char  dummy54[2];                             /*                  */
    unsigned short BRS3;                                   /*  BRS3            */
};
struct st_csih1
{                                                          /* CSIH1            */
    union                                                  /*                  */
    {                                                      /* CTL0             */
        unsigned char  UINT8;                              /*  8-bit Access    */
        struct                                             /*                  */
        {                                                  /*  Bit Access      */
            unsigned char  MBS:1;                          /*   MBS            */
            unsigned char  JOBE:1;                         /*   JOBE           */
            unsigned char  :3;                             /*   Reserved Bits  */
            unsigned char  RXE:1;                          /*   RXE            */
            unsigned char  TXE:1;                          /*   TXE            */
            unsigned char  PWR:1;                          /*   PWR            */
        } BIT;                                             /*                  */
    } CTL0;                                                /*                  */
    
    unsigned char  dummy55[3];                             /*                  */
    unsigned long  STR0;                                   /*  STR0            */
    unsigned short STCR0;                                  /*  STCR0           */
    unsigned char  dummy56[6];                             /*                  */
    unsigned long  CTL1;                                   /*  CTL1            */
    unsigned short CTL2;                                   /*  CTL2            */
    unsigned char  dummy57[2];                             /*                  */
    unsigned char  EMU;                                    /*  EMU             */
    unsigned char  dummy58[4071];                          /*                  */
    unsigned long  MCTL1;                                  /*  MCTL1           */
    unsigned long  MCTL2;                                  /*  MCTL2           */
    unsigned long  TX0W;                                   /*  TX0W            */
    unsigned short TX0H;                                   /*  TX0H            */
    unsigned char  dummy59[2];                             /*                  */
    unsigned long  RX0W;                                   /*  RX0W            */
    unsigned short RX0H;                                   /*  RX0H            */
    unsigned char  dummy60[2];                             /*                  */
    unsigned long  MRWP0;                                  /*  MRWP0           */
    unsigned char  dummy61[36];                            /*                  */
    unsigned short MCTL0;                                  /*  MCTL0           */
    unsigned char  dummy62[2];                             /*                  */
    unsigned long  CFG0;                                   /*  CFG0            */
    unsigned long  CFG1;                                   /*  CFG1            */
    unsigned long  CFG2;                                   /*  CFG2            */
    unsigned long  CFG3;                                   /*  CFG3            */
    unsigned char  dummy63[20];                            /*                  */
    unsigned short BRS0;                                   /*  BRS0            */
    unsigned char  dummy64[2];                             /*                  */
    unsigned short BRS1;                                   /*  BRS1            */
    unsigned char  dummy65[2];                             /*                  */
    unsigned short BRS2;                                   /*  BRS2            */
    unsigned char  dummy66[2];                             /*                  */
    unsigned short BRS3;                                   /*  BRS3            */
};
struct st_csih2
{                                                          /* CSIH2            */
    union                                                  /*                  */
    {                                                      /* CTL0             */
        unsigned char  UINT8;                              /*  8-bit Access    */
        struct                                             /*                  */
        {                                                  /*  Bit Access      */
            unsigned char  MBS:1;                          /*   MBS            */
            unsigned char  JOBE:1;                         /*   JOBE           */
            unsigned char  :3;                             /*   Reserved Bits  */
            unsigned char  RXE:1;                          /*   RXE            */
            unsigned char  TXE:1;                          /*   TXE            */
            unsigned char  PWR:1;                          /*   PWR            */
        } BIT;                                             /*                  */
    } CTL0;                                                /*                  */
    
    unsigned char  dummy67[3];                             /*                  */
    unsigned long  STR0;                                   /*  STR0            */
    unsigned short STCR0;                                  /*  STCR0           */
    unsigned char  dummy68[6];                             /*                  */
    unsigned long  CTL1;                                   /*  CTL1            */
    unsigned short CTL2;                                   /*  CTL2            */
    unsigned char  dummy69[2];                             /*                  */
    unsigned char  EMU;                                    /*  EMU             */
    unsigned char  dummy70[4071];                          /*                  */
    unsigned long  MCTL1;                                  /*  MCTL1           */
    unsigned long  MCTL2;                                  /*  MCTL2           */
    unsigned long  TX0W;                                   /*  TX0W            */
    unsigned short TX0H;                                   /*  TX0H            */
    unsigned char  dummy71[2];                             /*                  */
    unsigned long  RX0W;                                   /*  RX0W            */
    unsigned short RX0H;                                   /*  RX0H            */
    unsigned char  dummy72[2];                             /*                  */
    unsigned long  MRWP0;                                  /*  MRWP0           */
    unsigned char  dummy73[36];                            /*                  */
    unsigned short MCTL0;                                  /*  MCTL0           */
    unsigned char  dummy74[2];                             /*                  */
    unsigned long  CFG0;                                   /*  CFG0            */
    unsigned long  CFG1;                                   /*  CFG1            */
    unsigned long  CFG2;                                   /*  CFG2            */
    unsigned long  CFG3;                                   /*  CFG3            */
    unsigned char  dummy75[20];                            /*                  */
    unsigned short BRS0;                                   /*  BRS0            */
    unsigned char  dummy76[2];                             /*                  */
    unsigned short BRS1;                                   /*  BRS1            */
    unsigned char  dummy77[2];                             /*                  */
    unsigned short BRS2;                                   /*  BRS2            */
    unsigned char  dummy78[2];                             /*                  */
    unsigned short BRS3;                                   /*  BRS3            */
};
struct st_csig0
{                                                          /* CSIG0            */
    union                                                  /*                  */
    {                                                      /* CTL0             */
        unsigned char  UINT8;                              /*  8-bit Access    */
        struct                                             /*                  */
        {                                                  /*  Bit Access      */
            unsigned char  :5;                             /*   Reserved Bits  */
            unsigned char  RXE:1;                          /*   RXE            */
            unsigned char  TXE:1;                          /*   TXE            */
            unsigned char  PWR:1;                          /*   PWR            */
        } BIT;                                             /*                  */
    } CTL0;                                                /*                  */
    
    unsigned char  dummy79[3];                             /*                  */
    unsigned long  STR0;                                   /*  STR0            */
    unsigned short STCR0;                                  /*  STCR0           */
    unsigned char  dummy80[6];                             /*                  */
    unsigned long  CTL1;                                   /*  CTL1            */
    unsigned short CTL2;                                   /*  CTL2            */
    unsigned char  dummy81[2];                             /*                  */
    unsigned char  EMU;                                    /*  EMU             */
    unsigned char  dummy82[4071];                          /*                  */
    
    union                                                  /*                  */
    {                                                      /* BCTL0            */
        unsigned char  UINT8;                              /*  8-bit Access    */
        struct                                             /*                  */
        {                                                  /*  Bit Access      */
            unsigned char  SCE:1;                          /*   SCE            */
            unsigned char  :7;                             /*   Reserved Bits  */
        } BIT;                                             /*                  */
    } BCTL0;                                               /*                  */
    
    unsigned char  dummy83[3];                             /*                  */
    unsigned long  TX0W;                                   /*  TX0W            */
    unsigned short TX0H;                                   /*  TX0H            */
    unsigned char  dummy84[2];                             /*                  */
    unsigned short RX0;                                    /*  RX0             */
    unsigned char  dummy85[2];                             /*                  */
    unsigned long  CFG0;                                   /*  CFG0            */
};
struct st_pic0
{                                                          /* PIC0             */
    unsigned char  SST;                                    /*  SST             */
    unsigned char  dummy86[11];                            /*                  */
    unsigned short SSER0;                                  /*  SSER0           */
    unsigned char  dummy87[6];                             /*                  */
    unsigned short SSER2;                                  /*  SSER2           */
    unsigned char  dummy88[102];                           /*                  */
    unsigned char  HIZCEN0;                                /*  HIZCEN0         */
    unsigned char  dummy89[15];                            /*                  */
    unsigned short ADTEN400;                               /*  ADTEN400        */
    unsigned char  dummy90[2];                             /*                  */
    unsigned short ADTEN401;                               /*  ADTEN401        */
    unsigned char  dummy91[2];                             /*                  */
    unsigned short ADTEN402;                               /*  ADTEN402        */
    unsigned char  dummy92[38];                            /*                  */
    unsigned long  REG200;                                 /*  REG200          */
    unsigned long  REG201;                                 /*  REG201          */
    unsigned long  REG202;                                 /*  REG202          */
    unsigned long  REG203;                                 /*  REG203          */
    unsigned char  dummy93[24];                            /*                  */
    unsigned long  REG30;                                  /*  REG30           */
    unsigned long  REG31;                                  /*  REG31           */
};
struct st_taud0
{                                                          /* TAUD0            */
    unsigned short CDR0;                                   /*  CDR0            */
    unsigned char  dummy94[2];                             /*                  */
    unsigned short CDR1;                                   /*  CDR1            */
    unsigned char  dummy95[2];                             /*                  */
    unsigned short CDR2;                                   /*  CDR2            */
    unsigned char  dummy96[2];                             /*                  */
    unsigned short CDR3;                                   /*  CDR3            */
    unsigned char  dummy97[2];                             /*                  */
    unsigned short CDR4;                                   /*  CDR4            */
    unsigned char  dummy98[2];                             /*                  */
    unsigned short CDR5;                                   /*  CDR5            */
    unsigned char  dummy99[2];                             /*                  */
    unsigned short CDR6;                                   /*  CDR6            */
    unsigned char  dummy100[2];                            /*                  */
    unsigned short CDR7;                                   /*  CDR7            */
    unsigned char  dummy101[2];                            /*                  */
    unsigned short CDR8;                                   /*  CDR8            */
    unsigned char  dummy102[2];                            /*                  */
    unsigned short CDR9;                                   /*  CDR9            */
    unsigned char  dummy103[2];                            /*                  */
    unsigned short CDR10;                                  /*  CDR10           */
    unsigned char  dummy104[2];                            /*                  */
    unsigned short CDR11;                                  /*  CDR11           */
    unsigned char  dummy105[2];                            /*                  */
    unsigned short CDR12;                                  /*  CDR12           */
    unsigned char  dummy106[2];                            /*                  */
    unsigned short CDR13;                                  /*  CDR13           */
    unsigned char  dummy107[2];                            /*                  */
    unsigned short CDR14;                                  /*  CDR14           */
    unsigned char  dummy108[2];                            /*                  */
    unsigned short CDR15;                                  /*  CDR15           */
    unsigned char  dummy109[2];                            /*                  */
    unsigned short TOL;                                    /*  TOL             */
    unsigned char  dummy110[2];                            /*                  */
    unsigned short RDT;                                    /*  RDT             */
    unsigned char  dummy111[2];                            /*                  */
    unsigned short RSF;                                    /*  RSF             */
    unsigned char  dummy112[2];                            /*                  */
    unsigned short TRO;                                    /*  TRO             */
    unsigned char  dummy113[2];                            /*                  */
    unsigned short TME;                                    /*  TME             */
    unsigned char  dummy114[2];                            /*                  */
    unsigned short TDL;                                    /*  TDL             */
    unsigned char  dummy115[2];                            /*                  */
    unsigned short TO;                                     /*  TO              */
    unsigned char  dummy116[2];                            /*                  */
    unsigned short TOE;                                    /*  TOE             */
    unsigned char  dummy117[34];                           /*                  */
    unsigned short CNT0;                                   /*  CNT0            */
    unsigned char  dummy118[2];                            /*                  */
    unsigned short CNT1;                                   /*  CNT1            */
    unsigned char  dummy119[2];                            /*                  */
    unsigned short CNT2;                                   /*  CNT2            */
    unsigned char  dummy120[2];                            /*                  */
    unsigned short CNT3;                                   /*  CNT3            */
    unsigned char  dummy121[2];                            /*                  */
    unsigned short CNT4;                                   /*  CNT4            */
    unsigned char  dummy122[2];                            /*                  */
    unsigned short CNT5;                                   /*  CNT5            */
    unsigned char  dummy123[2];                            /*                  */
    unsigned short CNT6;                                   /*  CNT6            */
    unsigned char  dummy124[2];                            /*                  */
    unsigned short CNT7;                                   /*  CNT7            */
    unsigned char  dummy125[2];                            /*                  */
    unsigned short CNT8;                                   /*  CNT8            */
    unsigned char  dummy126[2];                            /*                  */
    unsigned short CNT9;                                   /*  CNT9            */
    unsigned char  dummy127[2];                            /*                  */
    unsigned short CNT10;                                  /*  CNT10           */
    unsigned char  dummy128[2];                            /*                  */
    unsigned short CNT11;                                  /*  CNT11           */
    unsigned char  dummy129[2];                            /*                  */
    unsigned short CNT12;                                  /*  CNT12           */
    unsigned char  dummy130[2];                            /*                  */
    unsigned short CNT13;                                  /*  CNT13           */
    unsigned char  dummy131[2];                            /*                  */
    unsigned short CNT14;                                  /*  CNT14           */
    unsigned char  dummy132[2];                            /*                  */
    unsigned short CNT15;                                  /*  CNT15           */
    unsigned char  dummy133[2];                            /*                  */
    unsigned char  CMUR0;                                  /*  CMUR0           */
    unsigned char  dummy134[3];                            /*                  */
    unsigned char  CMUR1;                                  /*  CMUR1           */
    unsigned char  dummy135[3];                            /*                  */
    unsigned char  CMUR2;                                  /*  CMUR2           */
    unsigned char  dummy136[3];                            /*                  */
    unsigned char  CMUR3;                                  /*  CMUR3           */
    unsigned char  dummy137[3];                            /*                  */
    unsigned char  CMUR4;                                  /*  CMUR4           */
    unsigned char  dummy138[3];                            /*                  */
    unsigned char  CMUR5;                                  /*  CMUR5           */
    unsigned char  dummy139[3];                            /*                  */
    unsigned char  CMUR6;                                  /*  CMUR6           */
    unsigned char  dummy140[3];                            /*                  */
    unsigned char  CMUR7;                                  /*  CMUR7           */
    unsigned char  dummy141[3];                            /*                  */
    unsigned char  CMUR8;                                  /*  CMUR8           */
    unsigned char  dummy142[3];                            /*                  */
    unsigned char  CMUR9;                                  /*  CMUR9           */
    unsigned char  dummy143[3];                            /*                  */
    unsigned char  CMUR10;                                 /*  CMUR10          */
    unsigned char  dummy144[3];                            /*                  */
    unsigned char  CMUR11;                                 /*  CMUR11          */
    unsigned char  dummy145[3];                            /*                  */
    unsigned char  CMUR12;                                 /*  CMUR12          */
    unsigned char  dummy146[3];                            /*                  */
    unsigned char  CMUR13;                                 /*  CMUR13          */
    unsigned char  dummy147[3];                            /*                  */
    unsigned char  CMUR14;                                 /*  CMUR14          */
    unsigned char  dummy148[3];                            /*                  */
    unsigned char  CMUR15;                                 /*  CMUR15          */
    unsigned char  dummy149[67];                           /*                  */
    unsigned char  CSR0;                                   /*  CSR0            */
    unsigned char  dummy150[3];                            /*                  */
    unsigned char  CSR1;                                   /*  CSR1            */
    unsigned char  dummy151[3];                            /*                  */
    unsigned char  CSR2;                                   /*  CSR2            */
    unsigned char  dummy152[3];                            /*                  */
    unsigned char  CSR3;                                   /*  CSR3            */
    unsigned char  dummy153[3];                            /*                  */
    unsigned char  CSR4;                                   /*  CSR4            */
    unsigned char  dummy154[3];                            /*                  */
    unsigned char  CSR5;                                   /*  CSR5            */
    unsigned char  dummy155[3];                            /*                  */
    unsigned char  CSR6;                                   /*  CSR6            */
    unsigned char  dummy156[3];                            /*                  */
    unsigned char  CSR7;                                   /*  CSR7            */
    unsigned char  dummy157[3];                            /*                  */
    unsigned char  CSR8;                                   /*  CSR8            */
    unsigned char  dummy158[3];                            /*                  */
    unsigned char  CSR9;                                   /*  CSR9            */
    unsigned char  dummy159[3];                            /*                  */
    unsigned char  CSR10;                                  /*  CSR10           */
    unsigned char  dummy160[3];                            /*                  */
    unsigned char  CSR11;                                  /*  CSR11           */
    unsigned char  dummy161[3];                            /*                  */
    unsigned char  CSR12;                                  /*  CSR12           */
    unsigned char  dummy162[3];                            /*                  */
    unsigned char  CSR13;                                  /*  CSR13           */
    unsigned char  dummy163[3];                            /*                  */
    unsigned char  CSR14;                                  /*  CSR14           */
    unsigned char  dummy164[3];                            /*                  */
    unsigned char  CSR15;                                  /*  CSR15           */
    unsigned char  dummy165[3];                            /*                  */
    unsigned char  CSC0;                                   /*  CSC0            */
    unsigned char  dummy166[3];                            /*                  */
    unsigned char  CSC1;                                   /*  CSC1            */
    unsigned char  dummy167[3];                            /*                  */
    unsigned char  CSC2;                                   /*  CSC2            */
    unsigned char  dummy168[3];                            /*                  */
    unsigned char  CSC3;                                   /*  CSC3            */
    unsigned char  dummy169[3];                            /*                  */
    unsigned char  CSC4;                                   /*  CSC4            */
    unsigned char  dummy170[3];                            /*                  */
    unsigned char  CSC5;                                   /*  CSC5            */
    unsigned char  dummy171[3];                            /*                  */
    unsigned char  CSC6;                                   /*  CSC6            */
    unsigned char  dummy172[3];                            /*                  */
    unsigned char  CSC7;                                   /*  CSC7            */
    unsigned char  dummy173[3];                            /*                  */
    unsigned char  CSC8;                                   /*  CSC8            */
    unsigned char  dummy174[3];                            /*                  */
    unsigned char  CSC9;                                   /*  CSC9            */
    unsigned char  dummy175[3];                            /*                  */
    unsigned char  CSC10;                                  /*  CSC10           */
    unsigned char  dummy176[3];                            /*                  */
    unsigned char  CSC11;                                  /*  CSC11           */
    unsigned char  dummy177[3];                            /*                  */
    unsigned char  CSC12;                                  /*  CSC12           */
    unsigned char  dummy178[3];                            /*                  */
    unsigned char  CSC13;                                  /*  CSC13           */
    unsigned char  dummy179[3];                            /*                  */
    unsigned char  CSC14;                                  /*  CSC14           */
    unsigned char  dummy180[3];                            /*                  */
    unsigned char  CSC15;                                  /*  CSC15           */
    unsigned char  dummy181[3];                            /*                  */
    unsigned short TE;                                     /*  TE              */
    unsigned char  dummy182[2];                            /*                  */
    unsigned short TS;                                     /*  TS              */
    unsigned char  dummy183[2];                            /*                  */
    unsigned short TT;                                     /*  TT              */
    unsigned char  dummy184[54];                           /*                  */
    unsigned short CMOR0;                                  /*  CMOR0           */
    unsigned char  dummy185[2];                            /*                  */
    unsigned short CMOR1;                                  /*  CMOR1           */
    unsigned char  dummy186[2];                            /*                  */
    unsigned short CMOR2;                                  /*  CMOR2           */
    unsigned char  dummy187[2];                            /*                  */
    unsigned short CMOR3;                                  /*  CMOR3           */
    unsigned char  dummy188[2];                            /*                  */
    unsigned short CMOR4;                                  /*  CMOR4           */
    unsigned char  dummy189[2];                            /*                  */
    unsigned short CMOR5;                                  /*  CMOR5           */
    unsigned char  dummy190[2];                            /*                  */
    unsigned short CMOR6;                                  /*  CMOR6           */
    unsigned char  dummy191[2];                            /*                  */
    unsigned short CMOR7;                                  /*  CMOR7           */
    unsigned char  dummy192[2];                            /*                  */
    unsigned short CMOR8;                                  /*  CMOR8           */
    unsigned char  dummy193[2];                            /*                  */
    unsigned short CMOR9;                                  /*  CMOR9           */
    unsigned char  dummy194[2];                            /*                  */
    unsigned short CMOR10;                                 /*  CMOR10          */
    unsigned char  dummy195[2];                            /*                  */
    unsigned short CMOR11;                                 /*  CMOR11          */
    unsigned char  dummy196[2];                            /*                  */
    unsigned short CMOR12;                                 /*  CMOR12          */
    unsigned char  dummy197[2];                            /*                  */
    unsigned short CMOR13;                                 /*  CMOR13          */
    unsigned char  dummy198[2];                            /*                  */
    unsigned short CMOR14;                                 /*  CMOR14          */
    unsigned char  dummy199[2];                            /*                  */
    unsigned short CMOR15;                                 /*  CMOR15          */
    unsigned char  dummy200[2];                            /*                  */
    unsigned short TPS;                                    /*  TPS             */
    unsigned char  dummy201[2];                            /*                  */
    unsigned char  BRS;                                    /*  BRS             */
    unsigned char  dummy202[3];                            /*                  */
    unsigned short TOM;                                    /*  TOM             */
    unsigned char  dummy203[2];                            /*                  */
    unsigned short TOC;                                    /*  TOC             */
    unsigned char  dummy204[2];                            /*                  */
    unsigned short TDE;                                    /*  TDE             */
    unsigned char  dummy205[2];                            /*                  */
    unsigned short TDM;                                    /*  TDM             */
    unsigned char  dummy206[2];                            /*                  */
    unsigned short TRE;                                    /*  TRE             */
    unsigned char  dummy207[2];                            /*                  */
    unsigned short TRC;                                    /*  TRC             */
    unsigned char  dummy208[2];                            /*                  */
    unsigned short RDE;                                    /*  RDE             */
    unsigned char  dummy209[2];                            /*                  */
    unsigned short RDM;                                    /*  RDM             */
    unsigned char  dummy210[2];                            /*                  */
    unsigned short RDS;                                    /*  RDS             */
    unsigned char  dummy211[2];                            /*                  */
    unsigned short RDC;                                    /*  RDC             */
    unsigned char  dummy212[34];                           /*                  */
    unsigned char  EMU;                                    /*  EMU             */
};
struct st_tauj0
{                                                          /* TAUJ0            */
    unsigned long  CDR0;                                   /*  CDR0            */
    unsigned long  CDR1;                                   /*  CDR1            */
    unsigned long  CDR2;                                   /*  CDR2            */
    unsigned long  CDR3;                                   /*  CDR3            */
    unsigned long  CNT0;                                   /*  CNT0            */
    unsigned long  CNT1;                                   /*  CNT1            */
    unsigned long  CNT2;                                   /*  CNT2            */
    unsigned long  CNT3;                                   /*  CNT3            */
    unsigned char  CMUR0;                                  /*  CMUR0           */
    unsigned char  dummy213[3];                            /*                  */
    unsigned char  CMUR1;                                  /*  CMUR1           */
    unsigned char  dummy214[3];                            /*                  */
    unsigned char  CMUR2;                                  /*  CMUR2           */
    unsigned char  dummy215[3];                            /*                  */
    unsigned char  CMUR3;                                  /*  CMUR3           */
    unsigned char  dummy216[3];                            /*                  */
    unsigned char  CSR0;                                   /*  CSR0            */
    unsigned char  dummy217[3];                            /*                  */
    unsigned char  CSR1;                                   /*  CSR1            */
    unsigned char  dummy218[3];                            /*                  */
    unsigned char  CSR2;                                   /*  CSR2            */
    unsigned char  dummy219[3];                            /*                  */
    unsigned char  CSR3;                                   /*  CSR3            */
    unsigned char  dummy220[3];                            /*                  */
    unsigned char  CSC0;                                   /*  CSC0            */
    unsigned char  dummy221[3];                            /*                  */
    unsigned char  CSC1;                                   /*  CSC1            */
    unsigned char  dummy222[3];                            /*                  */
    unsigned char  CSC2;                                   /*  CSC2            */
    unsigned char  dummy223[3];                            /*                  */
    unsigned char  CSC3;                                   /*  CSC3            */
    unsigned char  dummy224[3];                            /*                  */
    unsigned char  TE;                                     /*  TE              */
    unsigned char  dummy225[3];                            /*                  */
    unsigned char  TS;                                     /*  TS              */
    unsigned char  dummy226[3];                            /*                  */
    unsigned char  TT;                                     /*  TT              */
    unsigned char  dummy227[3];                            /*                  */
    unsigned char  TO;                                     /*  TO              */
    unsigned char  dummy228[3];                            /*                  */
    unsigned char  TOE;                                    /*  TOE             */
    unsigned char  dummy229[3];                            /*                  */
    unsigned char  TOL;                                    /*  TOL             */
    unsigned char  dummy230[3];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy231[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy232[19];                           /*                  */
    unsigned short CMOR0;                                  /*  CMOR0           */
    unsigned char  dummy233[2];                            /*                  */
    unsigned short CMOR1;                                  /*  CMOR1           */
    unsigned char  dummy234[2];                            /*                  */
    unsigned short CMOR2;                                  /*  CMOR2           */
    unsigned char  dummy235[2];                            /*                  */
    unsigned short CMOR3;                                  /*  CMOR3           */
    unsigned char  dummy236[2];                            /*                  */
    unsigned short TPS;                                    /*  TPS             */
    unsigned char  dummy237[2];                            /*                  */
    unsigned char  BRS;                                    /*  BRS             */
    unsigned char  dummy238[3];                            /*                  */
    unsigned char  TOM;                                    /*  TOM             */
    unsigned char  dummy239[3];                            /*                  */
    unsigned char  TOC;                                    /*  TOC             */
    unsigned char  dummy240[3];                            /*                  */
    unsigned char  RDE;                                    /*  RDE             */
    unsigned char  dummy241[3];                            /*                  */
    unsigned char  RDM;                                    /*  RDM             */
    unsigned char  dummy242[3];                            /*                  */
    unsigned char  EMU;                                    /*  EMU             */
};
struct st_pwsa0
{                                                          /* PWSA0            */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy243[3];                            /*                  */
    unsigned char  STR;                                    /*  STR             */
    unsigned char  dummy244[3];                            /*                  */
    unsigned char  STC;                                    /*  STC             */
    unsigned char  dummy245[3];                            /*                  */
    unsigned char  EMU;                                    /*  EMU             */
    unsigned char  dummy246[19];                           /*                  */
    unsigned char  QUE0;                                   /*  QUE0            */
    unsigned char  dummy247[3];                            /*                  */
    unsigned char  QUE1;                                   /*  QUE1            */
    unsigned char  dummy248[3];                            /*                  */
    unsigned char  QUE2;                                   /*  QUE2            */
    unsigned char  dummy249[3];                            /*                  */
    unsigned char  QUE3;                                   /*  QUE3            */
    unsigned char  dummy250[3];                            /*                  */
    unsigned char  QUE4;                                   /*  QUE4            */
    unsigned char  dummy251[3];                            /*                  */
    unsigned char  QUE5;                                   /*  QUE5            */
    unsigned char  dummy252[3];                            /*                  */
    unsigned char  QUE6;                                   /*  QUE6            */
    unsigned char  dummy253[3];                            /*                  */
    unsigned char  QUE7;                                   /*  QUE7            */
    unsigned char  dummy254[3];                            /*                  */
    unsigned long  PVCR00_01;                              /*  PVCR00_01       */
    unsigned long  PVCR02_03;                              /*  PVCR02_03       */
    unsigned long  PVCR04_05;                              /*  PVCR04_05       */
    unsigned long  PVCR06_07;                              /*  PVCR06_07       */
    unsigned long  PVCR08_09;                              /*  PVCR08_09       */
    unsigned long  PVCR10_11;                              /*  PVCR10_11       */
    unsigned long  PVCR12_13;                              /*  PVCR12_13       */
    unsigned long  PVCR14_15;                              /*  PVCR14_15       */
    unsigned long  PVCR16_17;                              /*  PVCR16_17       */
    unsigned long  PVCR18_19;                              /*  PVCR18_19       */
    unsigned long  PVCR20_21;                              /*  PVCR20_21       */
    unsigned long  PVCR22_23;                              /*  PVCR22_23       */
};
struct st_pwga0
{                                                          /* PWGA0            */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy255[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy256[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy257[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy258[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy259[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy260[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy261[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy262[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy263[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga1
{                                                          /* PWGA1            */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy264[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy265[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy266[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy267[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy268[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy269[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy270[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy271[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy272[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga2
{                                                          /* PWGA2            */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy273[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy274[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy275[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy276[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy277[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy278[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy279[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy280[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy281[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga3
{                                                          /* PWGA3            */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy282[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy283[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy284[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy285[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy286[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy287[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy288[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy289[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy290[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga4
{                                                          /* PWGA4            */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy291[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy292[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy293[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy294[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy295[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy296[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy297[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy298[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy299[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga5
{                                                          /* PWGA5            */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy300[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy301[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy302[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy303[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy304[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy305[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy306[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy307[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy308[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga6
{                                                          /* PWGA6            */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy309[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy310[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy311[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy312[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy313[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy314[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy315[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy316[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy317[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga7
{                                                          /* PWGA7            */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy318[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy319[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy320[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy321[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy322[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy323[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy324[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy325[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy326[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga8
{                                                          /* PWGA8            */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy327[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy328[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy329[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy330[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy331[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy332[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy333[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy334[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy335[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga9
{                                                          /* PWGA9            */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy336[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy337[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy338[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy339[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy340[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy341[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy342[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy343[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy344[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga10
{                                                          /* PWGA10           */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy345[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy346[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy347[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy348[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy349[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy350[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy351[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy352[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy353[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga11
{                                                          /* PWGA11           */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy354[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy355[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy356[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy357[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy358[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy359[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy360[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy361[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy362[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga12
{                                                          /* PWGA12           */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy363[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy364[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy365[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy366[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy367[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy368[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy369[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy370[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy371[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga13
{                                                          /* PWGA13           */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy372[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy373[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy374[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy375[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy376[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy377[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy378[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy379[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy380[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga14
{                                                          /* PWGA14           */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy381[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy382[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy383[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy384[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy385[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy386[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy387[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy388[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy389[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga15
{                                                          /* PWGA15           */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy390[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy391[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy392[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy393[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy394[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy395[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy396[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy397[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy398[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga16
{                                                          /* PWGA16           */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy399[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy400[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy401[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy402[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy403[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy404[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy405[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy406[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy407[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga17
{                                                          /* PWGA17           */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy408[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy409[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy410[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy411[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy412[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy413[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy414[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy415[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy416[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga18
{                                                          /* PWGA18           */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy417[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy418[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy419[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy420[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy421[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy422[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy423[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy424[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy425[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga19
{                                                          /* PWGA19           */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy426[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy427[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy428[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy429[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy430[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy431[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy432[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy433[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy434[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga20
{                                                          /* PWGA20           */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy435[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy436[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy437[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy438[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy439[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy440[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy441[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy442[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy443[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga21
{                                                          /* PWGA21           */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy444[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy445[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy446[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy447[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy448[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy449[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy450[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy451[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy452[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga22
{                                                          /* PWGA22           */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy453[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy454[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy455[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy456[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy457[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy458[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy459[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy460[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy461[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwga23
{                                                          /* PWGA23           */
    unsigned short CSDR;                                   /*  CSDR            */
    unsigned char  dummy462[2];                            /*                  */
    unsigned short CRDR;                                   /*  CRDR            */
    unsigned char  dummy463[2];                            /*                  */
    unsigned short CTDR;                                   /*  CTDR            */
    unsigned char  dummy464[2];                            /*                  */
    unsigned char  RDT;                                    /*  RDT             */
    unsigned char  dummy465[3];                            /*                  */
    unsigned char  RSF;                                    /*  RSF             */
    unsigned char  dummy466[3];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy467[10];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy468[3];                            /*                  */
    unsigned short CSBR;                                   /*  CSBR            */
    unsigned char  dummy469[2];                            /*                  */
    unsigned short CRBR;                                   /*  CRBR            */
    unsigned char  dummy470[2];                            /*                  */
    unsigned short CTBR;                                   /*  CTBR            */
};
struct st_pwba0
{                                                          /* PWBA0            */
    unsigned short BRS0;                                   /*  BRS0            */
    unsigned char  dummy471[2];                            /*                  */
    unsigned short BRS1;                                   /*  BRS1            */
    unsigned char  dummy472[2];                            /*                  */
    unsigned short BRS2;                                   /*  BRS2            */
    unsigned char  dummy473[2];                            /*                  */
    unsigned short BRS3;                                   /*  BRS3            */
    unsigned char  dummy474[2];                            /*                  */
    unsigned char  TE;                                     /*  TE              */
    unsigned char  dummy475[3];                            /*                  */
    unsigned char  TS;                                     /*  TS              */
    unsigned char  dummy476[3];                            /*                  */
    unsigned char  TT;                                     /*  TT              */
    unsigned char  dummy477[3];                            /*                  */
    unsigned char  EMU;                                    /*  EMU             */
};
struct st_enca0
{                                                          /* ENCA0            */
    unsigned short CCR0;                                   /*  CCR0            */
    unsigned char  dummy478[2];                            /*                  */
    unsigned short CCR1;                                   /*  CCR1            */
    unsigned char  dummy479[2];                            /*                  */
    unsigned short CNT;                                    /*  CNT             */
    unsigned char  dummy480[2];                            /*                  */
    unsigned char  FLG;                                    /*  FLG             */
    unsigned char  dummy481[3];                            /*                  */
    unsigned char  FGC;                                    /*  FGC             */
    unsigned char  dummy482[3];                            /*                  */
    unsigned char  TE;                                     /*  TE              */
    unsigned char  dummy483[3];                            /*                  */
    unsigned char  TS;                                     /*  TS              */
    unsigned char  dummy484[3];                            /*                  */
    unsigned char  TT;                                     /*  TT              */
    unsigned char  dummy485[3];                            /*                  */
    unsigned char  IOC0;                                   /*  IOC0            */
    unsigned char  dummy486[31];                           /*                  */
    unsigned short CTL;                                    /*  CTL             */
    unsigned char  dummy487[2];                            /*                  */
    unsigned char  IOC1;                                   /*  IOC1            */
    unsigned char  dummy488[3];                            /*                  */
    unsigned char  EMU;                                    /*  EMU             */
};
struct st_tapa0
{                                                          /* TAPA0            */
    unsigned short FLG;                                    /*  FLG             */
    unsigned char  dummy489[2];                            /*                  */
    unsigned char  ACWE;                                   /*  ACWE            */
    unsigned char  dummy490[3];                            /*                  */
    unsigned char  ACTS;                                   /*  ACTS            */
    unsigned char  dummy491[3];                            /*                  */
    unsigned char  ACTT;                                   /*  ACTT            */
    unsigned char  dummy492[7];                            /*                  */
    unsigned char  OPHS;                                   /*  OPHS            */
    unsigned char  dummy493[3];                            /*                  */
    unsigned char  OPHT;                                   /*  OPHT            */
    unsigned char  dummy494[7];                            /*                  */
    unsigned short CTL0;                                   /*  CTL0            */
    unsigned char  dummy495[2];                            /*                  */
    unsigned char  CTL1;                                   /*  CTL1            */
    unsigned char  dummy496[3];                            /*                  */
    unsigned char  EMU;                                    /*  EMU             */
};
struct st_ostm0
{                                                          /* OSTM0            */
    unsigned long  CMP;                                    /*  CMP             */
    unsigned long  CNT;                                    /*  CNT             */
    unsigned char  dummy497[8];                            /*                  */
    unsigned char  TE;                                     /*  TE              */
    unsigned char  dummy498[3];                            /*                  */
    unsigned char  TS;                                     /*  TS              */
    unsigned char  dummy499[3];                            /*                  */
    unsigned char  TT;                                     /*  TT              */
    unsigned char  dummy500[7];                            /*                  */
    unsigned char  CTL;                                    /*  CTL             */
    unsigned char  dummy501[3];                            /*                  */
    unsigned char  EMU;                                    /*  EMU             */
};
struct st_wdta0
{                                                          /* WDTA0            */
    unsigned char  WDTE;                                   /*  WDTE            */
    unsigned char  dummy502[3];                            /*                  */
    unsigned char  EVAC;                                   /*  EVAC            */
    unsigned char  dummy503[3];                            /*                  */
    unsigned char  REF;                                    /*  REF             */
    unsigned char  dummy504[3];                            /*                  */
    unsigned char  MD;                                     /*  MD              */
};
struct st_wdta1
{                                                          /* WDTA1            */
    unsigned char  WDTE;                                   /*  WDTE            */
    unsigned char  dummy505[3];                            /*                  */
    unsigned char  EVAC;                                   /*  EVAC            */
    unsigned char  dummy506[3];                            /*                  */
    unsigned char  REF;                                    /*  REF             */
    unsigned char  dummy507[3];                            /*                  */
    unsigned char  MD;                                     /*  MD              */
};
struct st_adca0
{                                                          /* ADCA0            */
    union                                                  /*                  */
    {                                                      /* VCR00            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR00;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR01            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR01;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR02            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR02;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR03            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR03;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR04            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR04;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR05            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR05;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR06            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR06;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR07            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR07;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR08            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR08;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR09            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR09;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR10            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR10;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR11            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR11;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR12            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR12;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR13            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR13;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR14            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR14;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR15            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR15;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR16            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR16;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR17            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR17;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR18            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR18;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR19            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR19;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR20            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR20;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR21            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR21;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR22            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR22;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR23            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR23;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR24            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR24;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR25            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR25;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR26            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR26;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR27            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR27;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR28            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR28;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR29            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR29;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR30            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR30;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR31            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR31;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR32            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR32;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR33            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR33;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR34            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR34;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR35            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR35;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* VCR36            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } VCR36;                                               /*                  */
    
    unsigned char  dummy508[96];                           /*                  */
    
    union                                                  /*                  */
    {                                                      /* PWDVCR           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } PWDVCR;                                              /*                  */
    
    unsigned char  dummy509[8];                            /*                  */
    unsigned long  DR00;                                   /*  DR00            */
    unsigned long  DR02;                                   /*  DR02            */
    unsigned long  DR04;                                   /*  DR04            */
    unsigned long  DR06;                                   /*  DR06            */
    unsigned long  DR08;                                   /*  DR08            */
    unsigned long  DR10;                                   /*  DR10            */
    unsigned long  DR12;                                   /*  DR12            */
    unsigned long  DR14;                                   /*  DR14            */
    unsigned long  DR16;                                   /*  DR16            */
    unsigned long  DR18;                                   /*  DR18            */
    unsigned long  DR20;                                   /*  DR20            */
    unsigned long  DR22;                                   /*  DR22            */
    unsigned long  DR24;                                   /*  DR24            */
    unsigned long  DR26;                                   /*  DR26            */
    unsigned long  DR28;                                   /*  DR28            */
    unsigned long  DR30;                                   /*  DR30            */
    unsigned long  DR32;                                   /*  DR32            */
    unsigned long  DR34;                                   /*  DR34            */
    unsigned long  DR36;                                   /*  DR36            */
    unsigned char  dummy510[44];                           /*                  */
    unsigned long  PWDTSNDR;                               /*  PWDTSNDR        */
    unsigned char  dummy511[132];                          /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR00            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR00;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR01            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR01;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR02            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR02;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR03            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR03;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR04            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR04;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR05            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR05;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR06            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR06;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR07            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR07;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR08            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR08;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR09            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR09;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR10            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR10;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR11            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR11;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR12            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR12;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR13            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR13;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR14            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR14;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR15            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR15;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR16            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR16;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR17            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR17;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR18            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR18;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR19            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR19;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR20            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR20;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR21            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR21;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR22            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR22;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR23            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR23;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR24            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR24;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR25            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR25;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR26            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR26;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR27            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR27;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR28            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR28;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR29            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR29;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR30            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR30;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR31            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR31;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR32            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR32;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR33            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR33;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR34            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR34;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR35            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR35;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* DIR36            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DIR36;                                               /*                  */
    
    unsigned char  dummy512[96];                           /*                  */
    
    union                                                  /*                  */
    {                                                      /* PWDDIR           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } PWDDIR;                                              /*                  */
    
    unsigned char  dummy513[8];                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* ADHALTR          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } ADHALTR;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* ADCR             */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } ADCR;                                                /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGSTR            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } SGSTR;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* MPXCURR          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } MPXCURR;                                             /*                  */
    
    unsigned char  dummy514[4];                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* THSMPSTCR        */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THSMPSTCR;                                           /*                  */
    
    union                                                  /*                  */
    {                                                      /* THCR             */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THCR;                                                /*                  */
    
    union                                                  /*                  */
    {                                                      /* THAHLDSTCR       */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THAHLDSTCR;                                          /*                  */
    
    union                                                  /*                  */
    {                                                      /* THBHLDSTCR       */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THBHLDSTCR;                                          /*                  */
    
    union                                                  /*                  */
    {                                                      /* THACR            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THACR;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* THBCR            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THBCR;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* THER             */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THER;                                                /*                  */
    
    union                                                  /*                  */
    {                                                      /* THGSR            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } THGSR;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* SFTCR            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SFTCR;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* ULLMTBR0         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } ULLMTBR0;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* ULLMTBR1         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } ULLMTBR1;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* ULLMTBR2         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } ULLMTBR2;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* ECR              */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } ECR;                                                 /*                  */
    
    union                                                  /*                  */
    {                                                      /* ULER             */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } ULER;                                                /*                  */
    
    union                                                  /*                  */
    {                                                      /* OWER             */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } OWER;                                                /*                  */
    
    union                                                  /*                  */
    {                                                      /* DGCTL0           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } DGCTL0;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* DGCTL1           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } DGCTL1;                                              /*                  */
    
    union                                                  /*                  */
    {                                                      /* PDCTL1           */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } PDCTL1;                                              /*                  */
    
    unsigned long  PDCTL2;                                 /*  PDCTL2          */
    unsigned char  dummy515[32];                           /*                  */
    
    union                                                  /*                  */
    {                                                      /* SMPCR            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SMPCR;                                               /*                  */
    
    unsigned char  dummy516[4];                            /*                  */
    unsigned long  EMU;                                    /*  EMU             */
    unsigned char  dummy517[180];                          /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGSTCR1          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SGSTCR1;                                             /*                  */
    
    unsigned char  dummy518[4];                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGCR1            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SGCR1;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGVCSP1          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SGVCSP1;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGVCEP1          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SGVCEP1;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGMCYCR1         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SGMCYCR1;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGSEFCR1         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SGSEFCR1;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGTSEL1          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } SGTSEL1;                                             /*                  */
    
    unsigned char  dummy519[32];                           /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGSTCR2          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SGSTCR2;                                             /*                  */
    
    unsigned char  dummy520[4];                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGCR2            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SGCR2;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGVCSP2          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SGVCSP2;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGVCEP2          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SGVCEP2;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGMCYCR2         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SGMCYCR2;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGSEFCR2         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SGSEFCR2;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGTSEL2          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } SGTSEL2;                                             /*                  */
    
    unsigned char  dummy521[32];                           /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGSTCR3          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SGSTCR3;                                             /*                  */
    
    unsigned char  dummy522[4];                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGCR3            */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SGCR3;                                               /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGVCSP3          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SGVCSP3;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGVCEP3          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SGVCEP3;                                             /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGMCYCR3         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SGMCYCR3;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGSEFCR3         */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } SGSEFCR3;                                            /*                  */
    
    union                                                  /*                  */
    {                                                      /* SGTSEL3          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
    } SGTSEL3;                                             /*                  */
    
    unsigned char  dummy523[40];                           /*                  */
    
    union                                                  /*                  */
    {                                                      /* PWDSGCR          */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } PWDSGCR;                                             /*                  */
    
    unsigned char  dummy524[12];                           /*                  */
    
    union                                                  /*                  */
    {                                                      /* PWDSGSEFCR       */
        unsigned long  UINT32;                             /*  32-bit Access   */
        unsigned short UINT16[2];                          /*  16-bit Access   */
        unsigned char  UINT8[4];                           /*  8-bit Access    */
    } PWDSGSEFCR;                                          /*                  */
    
};
struct st_dcra0
{                                                          /* DCRA0            */
    unsigned long  CIN;                                    /*  CIN             */
    unsigned long  COUT;                                   /*  COUT            */
    unsigned char  dummy525[24];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
};
struct st_dcra1
{                                                          /* DCRA1            */
    unsigned long  CIN;                                    /*  CIN             */
    unsigned long  COUT;                                   /*  COUT            */
    unsigned char  dummy526[24];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
};
struct st_dcra2
{                                                          /* DCRA2            */
    unsigned long  CIN;                                    /*  CIN             */
    unsigned long  COUT;                                   /*  COUT            */
    unsigned char  dummy527[24];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
};
struct st_dcra3
{                                                          /* DCRA3            */
    unsigned long  CIN;                                    /*  CIN             */
    unsigned long  COUT;                                   /*  COUT            */
    unsigned char  dummy528[24];                           /*                  */
    unsigned char  CTL;                                    /*  CTL             */
};
struct st_kr0
{                                                          /* KR0              */
    union                                                  /*                  */
    {                                                      /* KRM              */
        unsigned char  UINT8;                              /*  8-bit Access    */
        struct                                             /*                  */
        {                                                  /*  Bit Access      */
            unsigned char  KRM0:1;                         /*   KRM0           */
            unsigned char  KRM1:1;                         /*   KRM1           */
            unsigned char  KRM2:1;                         /*   KRM2           */
            unsigned char  KRM3:1;                         /*   KRM3           */
            unsigned char  KRM4:1;                         /*   KRM4           */
            unsigned char  KRM5:1;                         /*   KRM5           */
            unsigned char  KRM6:1;                         /*   KRM6           */
            unsigned char  KRM7:1;                         /*   KRM7           */
        } BIT;                                             /*                  */
    } KRM;                                                 /*                  */
    
};
struct st_clma0
{                                                          /* CLMA0            */
    unsigned char  CTL0;                                   /*  CTL0            */
    unsigned char  dummy529[7];                            /*                  */
    unsigned short CMPL;                                   /*  CMPL            */
    unsigned char  dummy530[2];                            /*                  */
    unsigned short CMPH;                                   /*  CMPH            */
    unsigned char  dummy531[2];                            /*                  */
    unsigned char  PCMD;                                   /*  PCMD            */
    unsigned char  dummy532[3];                            /*                  */
    unsigned char  PS;                                     /*  PS              */
    unsigned char  dummy533[3];                            /*                  */
    unsigned char  EMU0;                                   /*  EMU0            */
};
struct st_clma
{                                                          /* CLMA             */
    unsigned long  TEST;                                   /*  TEST            */
    unsigned long  TESTS;                                  /*  TESTS           */
};
struct st_clma1
{                                                          /* CLMA1            */
    unsigned char  CTL0;                                   /*  CTL0            */
    unsigned char  dummy534[7];                            /*                  */
    unsigned short CMPL;                                   /*  CMPL            */
    unsigned char  dummy535[2];                            /*                  */
    unsigned short CMPH;                                   /*  CMPH            */
    unsigned char  dummy536[2];                            /*                  */
    unsigned char  PCMD;                                   /*  PCMD            */
    unsigned char  dummy537[3];                            /*                  */
    unsigned char  PS;                                     /*  PS              */
    unsigned char  dummy538[3];                            /*                  */
    unsigned char  EMU0;                                   /*  EMU0            */
};
struct st_clma2
{                                                          /* CLMA2            */
    unsigned char  CTL0;                                   /*  CTL0            */
    unsigned char  dummy539[7];                            /*                  */
    unsigned short CMPL;                                   /*  CMPL            */
    unsigned char  dummy540[2];                            /*                  */
    unsigned short CMPH;                                   /*  CMPH            */
    unsigned char  dummy541[2];                            /*                  */
    unsigned char  PCMD;                                   /*  PCMD            */
    unsigned char  dummy542[3];                            /*                  */
    unsigned char  PS;                                     /*  PS              */
    unsigned char  dummy543[3];                            /*                  */
    unsigned char  EMU0;                                   /*  EMU0            */
};


#define FLMDCNT            (*(volatile unsigned long  *)0xFFA00000)
#define FLMDPCMD           (*(volatile unsigned long  *)0xFFA00004)
#define FLMDPS             (*(volatile unsigned long  *)0xFFA00008)
#define SELB_TAUD0I        (*(volatile unsigned short *)0xFFBC0200)
#define SELB_INTC1         (*(volatile unsigned short *)0xFFBC0300)
#define SELB_INTC2         (*(volatile unsigned short *)0xFFBC0304)
#define SELB_READTEST      (*(volatile unsigned char  *)0xFFBC0600)
#define SLPWGA0            (*(volatile unsigned long  *)0xFFBC1000)
#define SCTLR              (*(volatile unsigned long  *)0xFFBC2000)
#define EVFR               (*(volatile unsigned long  *)0xFFBC2004)
#define DPSELR0            (*(volatile unsigned long  *)0xFFBC2008)
#define DPSELRM            (*(volatile unsigned long  *)0xFFBC200C)
#define DPSELRML           (*(volatile unsigned short *)0xFFBC200C)
#define DPSELR1            (*(volatile unsigned char  *)0xFFBC200C)
#define DPSELR2            (*(volatile unsigned char  *)0xFFBC200D)
#define DPSELRMH           (*(volatile unsigned short *)0xFFBC200E)
#define DPSELR3            (*(volatile unsigned char  *)0xFFBC200E)
#define DPSELR4            (*(volatile unsigned char  *)0xFFBC200F)
#define DPSELRH            (*(volatile unsigned long  *)0xFFBC2010)
#define DPSELRHL           (*(volatile unsigned short *)0xFFBC2010)
#define DPSELR5            (*(volatile unsigned char  *)0xFFBC2010)
#define DPSELR6            (*(volatile unsigned char  *)0xFFBC2011)
#define DPSELRHH           (*(volatile unsigned short *)0xFFBC2012)
#define DPSELR7            (*(volatile unsigned char  *)0xFFBC2012)
#define DPDSR0             (*(volatile unsigned long  *)0xFFBC2014)
#define DPDSRM             (*(volatile unsigned long  *)0xFFBC2018)
#define DPDSRML            (*(volatile unsigned short *)0xFFBC2018)
#define DPDSR1             (*(volatile unsigned char  *)0xFFBC2018)
#define DPDSR2             (*(volatile unsigned char  *)0xFFBC2019)
#define DPDSRMH            (*(volatile unsigned short *)0xFFBC201A)
#define DPDSR3             (*(volatile unsigned char  *)0xFFBC201A)
#define DPDSR4             (*(volatile unsigned char  *)0xFFBC201B)
#define DPDSRH             (*(volatile unsigned long  *)0xFFBC201C)
#define DPDSRHL            (*(volatile unsigned short *)0xFFBC201C)
#define DPDSR5             (*(volatile unsigned char  *)0xFFBC201C)
#define DPDSR6             (*(volatile unsigned char  *)0xFFBC201D)
#define DPDSRHH            (*(volatile unsigned short *)0xFFBC201E)
#define DPDSR7             (*(volatile unsigned char  *)0xFFBC201E)
#define DPDIMR0            (*(volatile unsigned long  *)0xFFBC2020)
#define DPDIMR1            (*(volatile unsigned char  *)0xFFBC2024)
#define DPDIMR2            (*(volatile unsigned char  *)0xFFBC2028)
#define DPDIMR3            (*(volatile unsigned char  *)0xFFBC202C)
#define DPDIMR4            (*(volatile unsigned char  *)0xFFBC2030)
#define DPDIMR5            (*(volatile unsigned char  *)0xFFBC2034)
#define DPDIMR6            (*(volatile unsigned char  *)0xFFBC2038)
#define DPDIMR7            (*(volatile unsigned char  *)0xFFBC203C)
#define CNTVAL             (*(volatile unsigned short *)0xFFBC2040)
#define SOSTR              (*(volatile unsigned char  *)0xFFBC2044)
#define P0                 (*(volatile unsigned short *)0xFFC10000)
#define P8                 (*(volatile unsigned short *)0xFFC10020)
#define P9                 (*(volatile unsigned short *)0xFFC10024)
#define P10                (*(volatile unsigned short *)0xFFC10028)
#define P11                (*(volatile unsigned short *)0xFFC1002C)
#define AP0                (*(volatile unsigned short *)0xFFC100C8)
#define PSR0               (*(volatile unsigned long  *)0xFFC10100)
#define PSR8               (*(volatile unsigned long  *)0xFFC10120)
#define PSR9               (*(volatile unsigned long  *)0xFFC10124)
#define PSR10              (*(volatile unsigned long  *)0xFFC10128)
#define PSR11              (*(volatile unsigned long  *)0xFFC1012C)
#define APSR0              (*(volatile unsigned long  *)0xFFC101C8)
#define PPR0               (*(volatile unsigned short *)0xFFC10200)
#define PPR8               (*(volatile unsigned short *)0xFFC10220)
#define PPR9               (*(volatile unsigned short *)0xFFC10224)
#define PPR10              (*(volatile unsigned short *)0xFFC10228)
#define PPR11              (*(volatile unsigned short *)0xFFC1022C)
#define APPR0              (*(volatile unsigned short *)0xFFC102C8)
#define PM0                (*(volatile unsigned short *)0xFFC10300)
#define PM8                (*(volatile unsigned short *)0xFFC10320)
#define PM9                (*(volatile unsigned short *)0xFFC10324)
#define PM10               (*(volatile unsigned short *)0xFFC10328)
#define PM11               (*(volatile unsigned short *)0xFFC1032C)
#define APM0               (*(volatile unsigned short *)0xFFC103C8)
#define PMC0               (*(volatile unsigned short *)0xFFC10400)
#define PMC8               (*(volatile unsigned short *)0xFFC10420)
#define PMC9               (*(volatile unsigned short *)0xFFC10424)
#define PMC10              (*(volatile unsigned short *)0xFFC10428)
#define PMC11              (*(volatile unsigned short *)0xFFC1042C)
#define PFC0               (*(volatile unsigned short *)0xFFC10500)
#define PFC8               (*(volatile unsigned short *)0xFFC10520)
#define PFC9               (*(volatile unsigned short *)0xFFC10524)
#define PFC10              (*(volatile unsigned short *)0xFFC10528)
#define PFC11              (*(volatile unsigned short *)0xFFC1052C)
#define PFCE0              (*(volatile unsigned short *)0xFFC10600)
#define PFCE8              (*(volatile unsigned short *)0xFFC10620)
#define PFCE9              (*(volatile unsigned short *)0xFFC10624)
#define PFCE10             (*(volatile unsigned short *)0xFFC10628)
#define PNOT0              (*(volatile unsigned short *)0xFFC10700)
#define PNOT8              (*(volatile unsigned short *)0xFFC10720)
#define PNOT9              (*(volatile unsigned short *)0xFFC10724)
#define PNOT10             (*(volatile unsigned short *)0xFFC10728)
#define PNOT11             (*(volatile unsigned short *)0xFFC1072C)
#define APNOT0             (*(volatile unsigned short *)0xFFC107C8)
#define PMSR0              (*(volatile unsigned long  *)0xFFC10800)
#define PMSR8              (*(volatile unsigned long  *)0xFFC10820)
#define PMSR9              (*(volatile unsigned long  *)0xFFC10824)
#define PMSR10             (*(volatile unsigned long  *)0xFFC10828)
#define PMSR11             (*(volatile unsigned long  *)0xFFC1082C)
#define APMSR0             (*(volatile unsigned long  *)0xFFC108C8)
#define PMCSR0             (*(volatile unsigned long  *)0xFFC10900)
#define PMCSR8             (*(volatile unsigned long  *)0xFFC10920)
#define PMCSR9             (*(volatile unsigned long  *)0xFFC10924)
#define PMCSR10            (*(volatile unsigned long  *)0xFFC10928)
#define PMCSR11            (*(volatile unsigned long  *)0xFFC1092C)
#define PFCAE0             (*(volatile unsigned short *)0xFFC10A00)
#define PFCAE10            (*(volatile unsigned short *)0xFFC10A28)
#define PIBC0              (*(volatile unsigned short *)0xFFC14000)
#define PIBC8              (*(volatile unsigned short *)0xFFC14020)
#define PIBC9              (*(volatile unsigned short *)0xFFC14024)
#define PIBC10             (*(volatile unsigned short *)0xFFC14028)
#define PIBC11             (*(volatile unsigned short *)0xFFC1402C)
#define APIBC0             (*(volatile unsigned short *)0xFFC140C8)
#define PBDC0              (*(volatile unsigned short *)0xFFC14100)
#define PBDC8              (*(volatile unsigned short *)0xFFC14120)
#define PBDC9              (*(volatile unsigned short *)0xFFC14124)
#define PBDC10             (*(volatile unsigned short *)0xFFC14128)
#define PBDC11             (*(volatile unsigned short *)0xFFC1412C)
#define APBDC0             (*(volatile unsigned short *)0xFFC141C8)
#define PIPC0              (*(volatile unsigned short *)0xFFC14200)
#define PIPC10             (*(volatile unsigned short *)0xFFC14228)
#define PIPC11             (*(volatile unsigned short *)0xFFC1422C)
#define PU0                (*(volatile unsigned short *)0xFFC14300)
#define PU8                (*(volatile unsigned short *)0xFFC14320)
#define PU9                (*(volatile unsigned short *)0xFFC14324)
#define PU10               (*(volatile unsigned short *)0xFFC14328)
#define PU11               (*(volatile unsigned short *)0xFFC1432C)
#define PD0                (*(volatile unsigned short *)0xFFC14400)
#define PD8                (*(volatile unsigned short *)0xFFC14420)
#define PD9                (*(volatile unsigned short *)0xFFC14424)
#define PD10               (*(volatile unsigned short *)0xFFC14428)
#define PD11               (*(volatile unsigned short *)0xFFC1442C)
#define PODC0              (*(volatile unsigned long  *)0xFFC14500)
#define PODC8              (*(volatile unsigned long  *)0xFFC14520)
#define PODC9              (*(volatile unsigned long  *)0xFFC14524)
#define PODC10             (*(volatile unsigned long  *)0xFFC14528)
#define PODC11             (*(volatile unsigned long  *)0xFFC1452C)
#define PDSC0              (*(volatile unsigned long  *)0xFFC14600)
#define PDSC10             (*(volatile unsigned long  *)0xFFC14628)
#define PDSC11             (*(volatile unsigned long  *)0xFFC1462C)
#define PIS0               (*(volatile unsigned short *)0xFFC14700)
#define PIS10              (*(volatile unsigned short *)0xFFC14728)
#define PIS11              (*(volatile unsigned short *)0xFFC1472C)
#define PPROTS0            (*(volatile unsigned long  *)0xFFC14B00)
#define PPROTS8            (*(volatile unsigned long  *)0xFFC14B20)
#define PPROTS9            (*(volatile unsigned long  *)0xFFC14B24)
#define PPROTS10           (*(volatile unsigned long  *)0xFFC14B28)
#define PPROTS11           (*(volatile unsigned long  *)0xFFC14B2C)
#define PPCMD0             (*(volatile unsigned long  *)0xFFC14C00)
#define PPCMD8             (*(volatile unsigned long  *)0xFFC14C20)
#define PPCMD9             (*(volatile unsigned long  *)0xFFC14C24)
#define PPCMD10            (*(volatile unsigned long  *)0xFFC14C28)
#define PPCMD11            (*(volatile unsigned long  *)0xFFC14C2C)
#define JP0                (*(volatile unsigned char  *)0xFFC20000)
#define JPSR0              (*(volatile unsigned long  *)0xFFC20010)
#define JPPR0              (*(volatile unsigned char  *)0xFFC20020)
#define JPM0               (*(volatile unsigned char  *)0xFFC20030)
#define JPMC0              (*(volatile unsigned char  *)0xFFC20040)
#define JPFC0              (*(volatile unsigned char  *)0xFFC20050)
#define JPNOT0             (*(volatile unsigned char  *)0xFFC20070)
#define JPMSR0             (*(volatile unsigned long  *)0xFFC20080)
#define JPMCSR0            (*(volatile unsigned long  *)0xFFC20090)
#define JPIBC0             (*(volatile unsigned char  *)0xFFC20400)
#define JPBDC0             (*(volatile unsigned char  *)0xFFC20410)
#define JPU0               (*(volatile unsigned char  *)0xFFC20430)
#define JPD0               (*(volatile unsigned char  *)0xFFC20440)
#define JPODC0             (*(volatile unsigned long  *)0xFFC20450)
#define JPPROTS0           (*(volatile unsigned long  *)0xFFC204B0)
#define JPPCMD0            (*(volatile unsigned long  *)0xFFC204C0)
#define DNFATAUD0ICTL      (*(volatile unsigned char  *)0xFFC30000)
#define DNFATAUD0IEN       (*(volatile unsigned short *)0xFFC30004)
#define DNFATAUD0IENH      (*(volatile unsigned char  *)0xFFC30008)
#define DNFATAUD0IENH0     (((volatile bitf_T *)0xFFC30008)->bit00)
#define DNFATAUD0IENH1     (((volatile bitf_T *)0xFFC30008)->bit01)
#define DNFATAUD0IENH2     (((volatile bitf_T *)0xFFC30008)->bit02)
#define DNFATAUD0IENH3     (((volatile bitf_T *)0xFFC30008)->bit03)
#define DNFATAUD0IENH4     (((volatile bitf_T *)0xFFC30008)->bit04)
#define DNFATAUD0IENH5     (((volatile bitf_T *)0xFFC30008)->bit05)
#define DNFATAUD0IENH6     (((volatile bitf_T *)0xFFC30008)->bit06)
#define DNFATAUD0IENH7     (((volatile bitf_T *)0xFFC30008)->bit07)
#define DNFATAUD0IENL      (*(volatile unsigned char  *)0xFFC3000C)
#define DNFATAUD0IENL0     (((volatile bitf_T *)0xFFC3000C)->bit00)
#define DNFATAUD0IENL1     (((volatile bitf_T *)0xFFC3000C)->bit01)
#define DNFATAUD0IENL2     (((volatile bitf_T *)0xFFC3000C)->bit02)
#define DNFATAUD0IENL3     (((volatile bitf_T *)0xFFC3000C)->bit03)
#define DNFATAUD0IENL4     (((volatile bitf_T *)0xFFC3000C)->bit04)
#define DNFATAUD0IENL5     (((volatile bitf_T *)0xFFC3000C)->bit05)
#define DNFATAUD0IENL6     (((volatile bitf_T *)0xFFC3000C)->bit06)
#define DNFATAUD0IENL7     (((volatile bitf_T *)0xFFC3000C)->bit07)
#define DNFAENCA0ICTL      (*(volatile unsigned char  *)0xFFC30060)
#define DNFAENCA0IEN       (*(volatile unsigned short *)0xFFC30064)
#define DNFAENCA0IENL      (*(volatile unsigned char  *)0xFFC3006C)
#define DNFAENCA0IENL0     (((volatile bitf_T *)0xFFC3006C)->bit00)
#define DNFAENCA0IENL1     (((volatile bitf_T *)0xFFC3006C)->bit01)
#define DNFAENCA0IENL2     (((volatile bitf_T *)0xFFC3006C)->bit02)
#define DNFAENCA0IENL3     (((volatile bitf_T *)0xFFC3006C)->bit03)
#define DNFAENCA0IENL4     (((volatile bitf_T *)0xFFC3006C)->bit04)
#define DNFAADCTL0CTL      (*(volatile unsigned char  *)0xFFC300A0)
#define DNFAADCTL0EN       (*(volatile unsigned short *)0xFFC300A4)
#define DNFAADCTL0ENL      (*(volatile unsigned char  *)0xFFC300AC)
#define DNFAADCTL0ENL0     (((volatile bitf_T *)0xFFC300AC)->bit00)
#define DNFAADCTL0ENL1     (((volatile bitf_T *)0xFFC300AC)->bit01)
#define DNFAADCTL0ENL2     (((volatile bitf_T *)0xFFC300AC)->bit02)
#define FCLA0CTL0_NMI      (*(volatile unsigned char  *)0xFFC34000)
#define FCLA0CTL0_INTPL    (*(volatile unsigned char  *)0xFFC34020)
#define FCLA0CTL1_INTPL    (*(volatile unsigned char  *)0xFFC34024)
#define FCLA0CTL2_INTPL    (*(volatile unsigned char  *)0xFFC34028)
#define FCLA0CTL3_INTPL    (*(volatile unsigned char  *)0xFFC3402C)
#define FCLA0CTL4_INTPL    (*(volatile unsigned char  *)0xFFC34030)
#define FCLA0CTL5_INTPL    (*(volatile unsigned char  *)0xFFC34034)
#define FCLA0CTL6_INTPL    (*(volatile unsigned char  *)0xFFC34038)
#define FCLA0CTL7_INTPL    (*(volatile unsigned char  *)0xFFC3403C)
#define FCLA0CTL0_INTPH    (*(volatile unsigned char  *)0xFFC34040)
#define FCLA0CTL2_INTPH    (*(volatile unsigned char  *)0xFFC34048)
#define FCLA0CTL3_INTPH    (*(volatile unsigned char  *)0xFFC3404C)
#define FCLA0CTL4_INTPH    (*(volatile unsigned char  *)0xFFC34050)
#define FCLA0CTL0_ADC0     (*(volatile unsigned char  *)0xFFC34060)
#define FCLA0CTL1_ADC0     (*(volatile unsigned char  *)0xFFC34064)
#define FCLA0CTL2_ADC0     (*(volatile unsigned char  *)0xFFC34068)
#define EEPRDCYCL          (*(volatile unsigned char  *)0xFFC5A010)
#define CFECCCTL           (*(volatile unsigned short *)0xFFC62000)
#define CFFSTERSTR         (*(volatile unsigned long  *)0xFFC62004)
#define CFFSTSTC           (*(volatile unsigned char  *)0xFFC62024)
#define CFOVFSTR           (*(volatile unsigned char  *)0xFFC62028)
#define CFOVFSTC           (*(volatile unsigned char  *)0xFFC6202C)
#define CFERRINT           (*(volatile unsigned char  *)0xFFC62030)
#define CFFSTEADR          (*(volatile unsigned long  *)0xFFC62034)
#define CFTSTCTL           (*(volatile unsigned short *)0xFFC62054)
#define LRECCCTL           (*(volatile unsigned short *)0xFFC63000)
#define LRFSTERSTR         (*(volatile unsigned long  *)0xFFC63004)
#define LRSTCLR            (*(volatile unsigned char  *)0xFFC63024)
#define LROVFSTR           (*(volatile unsigned char  *)0xFFC63028)
#define LROVFSTC           (*(volatile unsigned char  *)0xFFC6302C)
#define LRFSTEADR0         (*(volatile unsigned long  *)0xFFC63030)
#define LRERRINT           (*(volatile unsigned char  *)0xFFC630B0)
#define LRTSTCTL           (*(volatile unsigned short *)0xFFC630B4)
#define LRTDATBF0          (*(volatile unsigned long  *)0xFFC630B8)
#define DFECCCTL           (*(volatile unsigned short *)0xFFC66000)
#define DFERSTR            (*(volatile unsigned long  *)0xFFC66004)
#define DFERSTC            (*(volatile unsigned char  *)0xFFC66008)
#define DFERRINT           (*(volatile unsigned char  *)0xFFC66014)
#define DFTSTCTL           (*(volatile unsigned short *)0xFFC6601C)
#define ECCCSIH0CTL        (*(volatile unsigned short *)0xFFC70000)
#define ECCCSIH0TMC        (*(volatile unsigned short *)0xFFC70004)
#define ECCCSIH0TRC        (*(volatile unsigned long  *)0xFFC70008)
#define ECCCSIH0ERDB       (*(volatile unsigned char  *)0xFFC70008)
#define ECCCSIH0ECRD       (*(volatile unsigned char  *)0xFFC70009)
#define ECCCSIH0HORD       (*(volatile unsigned char  *)0xFFC7000A)
#define ECCCSIH0SYND       (*(volatile unsigned char  *)0xFFC7000B)
#define ECCCSIH0TED        (*(volatile unsigned long  *)0xFFC7000C)
#define ECCCSIH1CTL        (*(volatile unsigned short *)0xFFC70010)
#define ECCCSIH1TMC        (*(volatile unsigned short *)0xFFC70014)
#define ECCCSIH1TRC        (*(volatile unsigned long  *)0xFFC70018)
#define ECCCSIH1ERDB       (*(volatile unsigned char  *)0xFFC70018)
#define ECCCSIH1ECRD       (*(volatile unsigned char  *)0xFFC70019)
#define ECCCSIH1HORD       (*(volatile unsigned char  *)0xFFC7001A)
#define ECCCSIH1SYND       (*(volatile unsigned char  *)0xFFC7001B)
#define ECCCSIH1TED        (*(volatile unsigned long  *)0xFFC7001C)
#define ECCCSIH2CTL        (*(volatile unsigned short *)0xFFC70020)
#define ECCCSIH2TMC        (*(volatile unsigned short *)0xFFC70024)
#define ECCCSIH2TRC        (*(volatile unsigned long  *)0xFFC70028)
#define ECCCSIH2ERDB       (*(volatile unsigned char  *)0xFFC70028)
#define ECCCSIH2ECRD       (*(volatile unsigned char  *)0xFFC70029)
#define ECCCSIH2HORD       (*(volatile unsigned char  *)0xFFC7002A)
#define ECCCSIH2SYND       (*(volatile unsigned char  *)0xFFC7002B)
#define ECCCSIH2TED        (*(volatile unsigned long  *)0xFFC7002C)
#define ECCRCAN0CTL        (*(volatile unsigned short *)0xFFC71000)
#define ECCRCAN0TMC        (*(volatile unsigned short *)0xFFC71004)
#define ECCRCAN0TRC        (*(volatile unsigned long  *)0xFFC71008)
#define ECCRCAN0ERDB       (*(volatile unsigned char  *)0xFFC71008)
#define ECCRCAN0ECRD       (*(volatile unsigned char  *)0xFFC71009)
#define ECCRCAN0HORD       (*(volatile unsigned char  *)0xFFC7100A)
#define ECCRCAN0SYND       (*(volatile unsigned char  *)0xFFC7100B)
#define ECCRCAN0TED        (*(volatile unsigned long  *)0xFFC7100C)
#define CVMF               (*(volatile unsigned long  *)0xFFF50000)
#define CVMDE              (*(volatile unsigned long  *)0xFFF50004)
#define CVMDIAG            (*(volatile unsigned long  *)0xFFF50014)
#define PROTCMDCVM         (*(volatile unsigned long  *)0xFFF50100)
#define PROTSCVM           (*(volatile unsigned long  *)0xFFF50104)
#define PROTCMD0           (*(volatile unsigned long  *)0xFFF80000)
#define PROTS0             (*(volatile unsigned long  *)0xFFF80004)
#define STBC0PSC           (*(volatile unsigned long  *)0xFFF80100)
#define STBC0STPT          (*(volatile unsigned long  *)0xFFF80110)
#define WDTNMIF            (*(volatile unsigned long  *)0xFFF80200)
#define WDTNMIFC           (*(volatile unsigned long  *)0xFFF80208)
#define FEINTF             (*(volatile unsigned long  *)0xFFF80300)
#define FEINTFMSK          (*(volatile unsigned long  *)0xFFF80304)
#define FEINTFC            (*(volatile unsigned long  *)0xFFF80308)
#define WUF0               (*(volatile unsigned long  *)0xFFF80400)
#define WUFMSK0            (*(volatile unsigned long  *)0xFFF80404)
#define WUFC0              (*(volatile unsigned long  *)0xFFF80408)
#define WUF20              (*(volatile unsigned long  *)0xFFF80520)
#define WUFMSK20           (*(volatile unsigned long  *)0xFFF80524)
#define WUFC20             (*(volatile unsigned long  *)0xFFF80528)
#define RESF               (*(volatile unsigned long  *)0xFFF80760)
#define RESFC              (*(volatile unsigned long  *)0xFFF80768)
#define RESFR              (*(volatile unsigned long  *)0xFFF80860)
#define RESFCR             (*(volatile unsigned long  *)0xFFF80868)
#define VLVF               (*(volatile unsigned long  *)0xFFF80980)
#define VLVFC              (*(volatile unsigned long  *)0xFFF80988)
#define LVICNT             (*(volatile unsigned long  *)0xFFF80A00)
#define SWRESA             (*(volatile unsigned long  *)0xFFF80A04)
#define IOHOLD             (*(volatile unsigned long  *)0xFFF80B00)
#define ROSCE              (*(volatile unsigned long  *)0xFFF81000)
#define ROSCS              (*(volatile unsigned long  *)0xFFF81004)
#define ROSCST             (*(volatile unsigned long  *)0xFFF8100C)
#define ROSCSTPM           (*(volatile unsigned long  *)0xFFF81018)
#define MOSCE              (*(volatile unsigned long  *)0xFFF81100)
#define MOSCS              (*(volatile unsigned long  *)0xFFF81104)
#define MOSCC              (*(volatile unsigned long  *)0xFFF81108)
#define MOSCST             (*(volatile unsigned long  *)0xFFF8110C)
#define MOSCSTPM           (*(volatile unsigned long  *)0xFFF81118)
#define CKSC_AWDTAD_CTL    (*(volatile unsigned long  *)0xFFF82000)
#define CKSC_AWDTAD_ACT    (*(volatile unsigned long  *)0xFFF82008)
#define CKSC_AWDTAD_STPM   (*(volatile unsigned long  *)0xFFF82018)
#define CKSC_ATAUJS_CTL    (*(volatile unsigned long  *)0xFFF82100)
#define CKSC_ATAUJS_ACT    (*(volatile unsigned long  *)0xFFF82108)
#define CKSC_ATAUJD_CTL    (*(volatile unsigned long  *)0xFFF82200)
#define CKSC_ATAUJD_ACT    (*(volatile unsigned long  *)0xFFF82208)
#define CKSC_ATAUJD_STPM   (*(volatile unsigned long  *)0xFFF82218)
#define CKSC_AADCAS_CTL    (*(volatile unsigned long  *)0xFFF82500)
#define CKSC_AADCAS_ACT    (*(volatile unsigned long  *)0xFFF82508)
#define CKSC_AADCAD_CTL    (*(volatile unsigned long  *)0xFFF82600)
#define CKSC_AADCAD_ACT    (*(volatile unsigned long  *)0xFFF82608)
#define CKSC_AADCAD_STPM   (*(volatile unsigned long  *)0xFFF82618)
#define CKSC_AFOUTS_CTL    (*(volatile unsigned long  *)0xFFF82700)
#define CKSC_AFOUTS_ACT    (*(volatile unsigned long  *)0xFFF82708)
#define CKSC_AFOUTS_STPM   (*(volatile unsigned long  *)0xFFF82718)
#define FOUTDIV            (*(volatile unsigned long  *)0xFFF82800)
#define FOUTSTAT           (*(volatile unsigned long  *)0xFFF82804)
#define PROTCMD1           (*(volatile unsigned long  *)0xFFF88000)
#define PROTS1             (*(volatile unsigned long  *)0xFFF88004)
#define WUF_ISO0           (*(volatile unsigned long  *)0xFFF88110)
#define WUFMSK_ISO0        (*(volatile unsigned long  *)0xFFF88114)
#define WUFC_ISO0          (*(volatile unsigned long  *)0xFFF88118)
#define PLLE               (*(volatile unsigned long  *)0xFFF89000)
#define PLLS               (*(volatile unsigned long  *)0xFFF89004)
#define PLLC               (*(volatile unsigned long  *)0xFFF89008)
#define CKSC_CPUCLKS_CTL   (*(volatile unsigned long  *)0xFFF8A000)
#define CKSC_CPUCLKS_ACT   (*(volatile unsigned long  *)0xFFF8A008)
#define CKSC_CPUCLKD_CTL   (*(volatile unsigned long  *)0xFFF8A100)
#define CKSC_CPUCLKD_ACT   (*(volatile unsigned long  *)0xFFF8A108)
#define CKSC_IPERI1S_CTL   (*(volatile unsigned long  *)0xFFF8A200)
#define CKSC_IPERI1S_ACT   (*(volatile unsigned long  *)0xFFF8A208)
#define CKSC_IPERI2S_CTL   (*(volatile unsigned long  *)0xFFF8A300)
#define CKSC_IPERI2S_ACT   (*(volatile unsigned long  *)0xFFF8A308)
#define CKSC_ILINS_CTL     (*(volatile unsigned long  *)0xFFF8A400)
#define CKSC_ILINS_ACT     (*(volatile unsigned long  *)0xFFF8A408)
#define CKSC_ILIND_CTL     (*(volatile unsigned long  *)0xFFF8A800)
#define CKSC_ILIND_ACT     (*(volatile unsigned long  *)0xFFF8A808)
#define CKSC_ILIND_STPM    (*(volatile unsigned long  *)0xFFF8A818)
#define CKSC_ICANS_CTL     (*(volatile unsigned long  *)0xFFF8A900)
#define CKSC_ICANS_ACT     (*(volatile unsigned long  *)0xFFF8A908)
#define CKSC_ICANS_STPM    (*(volatile unsigned long  *)0xFFF8A918)
#define CKSC_ICANOSCD_CTL  (*(volatile unsigned long  *)0xFFF8AA00)
#define CKSC_ICANOSCD_ACT  (*(volatile unsigned long  *)0xFFF8AA08)
#define CKSC_ICANOSCD_STPM (*(volatile unsigned long  *)0xFFF8AA18)
#define CKSC_ICSIS_CTL     (*(volatile unsigned long  *)0xFFF8AB00)
#define CKSC_ICSIS_ACT     (*(volatile unsigned long  *)0xFFF8AB08)
#define PROTCMDCLMA        (*(volatile unsigned long  *)0xFFF8C200)
#define PROTSCLMA          (*(volatile unsigned long  *)0xFFF8C204)
#define DTRC0              (*(volatile unsigned char  *)0xFFFF8300)
#define DTRC0ADS           (((volatile bitf_T *)0xFFFF8300)->bit00)
#define DTRC0ERR           (((volatile bitf_T *)0xFFFF8300)->bit07)
#define DMCM0              (*(volatile unsigned short *)0xFFFF8304)
#define DSA0               (*(volatile unsigned long  *)0xFFFF8314)
#define DSA0L              (*(volatile unsigned short *)0xFFFF8314)
#define DSA0H              (*(volatile unsigned short *)0xFFFF8316)
#define DDA0               (*(volatile unsigned long  *)0xFFFF8324)
#define DDA0L              (*(volatile unsigned short *)0xFFFF8324)
#define DDA0H              (*(volatile unsigned short *)0xFFFF8326)
#define DTC0               (*(volatile unsigned short *)0xFFFF8332)
#define DTCT0              (*(volatile unsigned short *)0xFFFF8338)
#define DTS0               (*(volatile unsigned char  *)0xFFFF833A)
#define DTS0DTE            (((volatile bitf_T *)0xFFFF833A)->bit00)
#define DTS0SR             (((volatile bitf_T *)0xFFFF833A)->bit01)
#define DTS0DR             (((volatile bitf_T *)0xFFFF833A)->bit02)
#define DTS0ER             (((volatile bitf_T *)0xFFFF833A)->bit03)
#define DTS0DT             (((volatile bitf_T *)0xFFFF833A)->bit06)
#define DTS0TC             (((volatile bitf_T *)0xFFFF833A)->bit07)
#define DSA1               (*(volatile unsigned long  *)0xFFFF8344)
#define DSA1L              (*(volatile unsigned short *)0xFFFF8344)
#define DSA1H              (*(volatile unsigned short *)0xFFFF8346)
#define DDA1               (*(volatile unsigned long  *)0xFFFF8354)
#define DDA1L              (*(volatile unsigned short *)0xFFFF8354)
#define DDA1H              (*(volatile unsigned short *)0xFFFF8356)
#define DTC1               (*(volatile unsigned short *)0xFFFF8362)
#define DTCT1              (*(volatile unsigned short *)0xFFFF8368)
#define DTS1               (*(volatile unsigned char  *)0xFFFF836A)
#define DTS1DTE            (((volatile bitf_T *)0xFFFF836A)->bit00)
#define DTS1SR             (((volatile bitf_T *)0xFFFF836A)->bit01)
#define DTS1DR             (((volatile bitf_T *)0xFFFF836A)->bit02)
#define DTS1ER             (((volatile bitf_T *)0xFFFF836A)->bit03)
#define DTS1DT             (((volatile bitf_T *)0xFFFF836A)->bit06)
#define DTS1TC             (((volatile bitf_T *)0xFFFF836A)->bit07)
#define DSA2               (*(volatile unsigned long  *)0xFFFF8374)
#define DSA2L              (*(volatile unsigned short *)0xFFFF8374)
#define DSA2H              (*(volatile unsigned short *)0xFFFF8376)
#define DDA2               (*(volatile unsigned long  *)0xFFFF8384)
#define DDA2L              (*(volatile unsigned short *)0xFFFF8384)
#define DDA2H              (*(volatile unsigned short *)0xFFFF8386)
#define DTC2               (*(volatile unsigned short *)0xFFFF8392)
#define DTCT2              (*(volatile unsigned short *)0xFFFF8398)
#define DTS2               (*(volatile unsigned char  *)0xFFFF839A)
#define DTS2DTE            (((volatile bitf_T *)0xFFFF839A)->bit00)
#define DTS2SR             (((volatile bitf_T *)0xFFFF839A)->bit01)
#define DTS2DR             (((volatile bitf_T *)0xFFFF839A)->bit02)
#define DTS2ER             (((volatile bitf_T *)0xFFFF839A)->bit03)
#define DTS2DT             (((volatile bitf_T *)0xFFFF839A)->bit06)
#define DTS2TC             (((volatile bitf_T *)0xFFFF839A)->bit07)
#define DSA3               (*(volatile unsigned long  *)0xFFFF83A4)
#define DSA3L              (*(volatile unsigned short *)0xFFFF83A4)
#define DSA3H              (*(volatile unsigned short *)0xFFFF83A6)
#define DDA3               (*(volatile unsigned long  *)0xFFFF83B4)
#define DDA3L              (*(volatile unsigned short *)0xFFFF83B4)
#define DDA3H              (*(volatile unsigned short *)0xFFFF83B6)
#define DTC3               (*(volatile unsigned short *)0xFFFF83C2)
#define DTCT3              (*(volatile unsigned short *)0xFFFF83C8)
#define DTS3               (*(volatile unsigned char  *)0xFFFF83CA)
#define DTS3DTE            (((volatile bitf_T *)0xFFFF83CA)->bit00)
#define DTS3SR             (((volatile bitf_T *)0xFFFF83CA)->bit01)
#define DTS3DR             (((volatile bitf_T *)0xFFFF83CA)->bit02)
#define DTS3ER             (((volatile bitf_T *)0xFFFF83CA)->bit03)
#define DTS3DT             (((volatile bitf_T *)0xFFFF83CA)->bit06)
#define DTS3TC             (((volatile bitf_T *)0xFFFF83CA)->bit07)
#define DSA4               (*(volatile unsigned long  *)0xFFFF83D4)
#define DSA4L              (*(volatile unsigned short *)0xFFFF83D4)
#define DSA4H              (*(volatile unsigned short *)0xFFFF83D6)
#define DDA4               (*(volatile unsigned long  *)0xFFFF83E4)
#define DDA4L              (*(volatile unsigned short *)0xFFFF83E4)
#define DDA4H              (*(volatile unsigned short *)0xFFFF83E6)
#define DTC4               (*(volatile unsigned short *)0xFFFF83F2)
#define DTCT4              (*(volatile unsigned short *)0xFFFF83F8)
#define DTS4               (*(volatile unsigned char  *)0xFFFF83FA)
#define DTS4DTE            (((volatile bitf_T *)0xFFFF83FA)->bit00)
#define DTS4SR             (((volatile bitf_T *)0xFFFF83FA)->bit01)
#define DTS4DR             (((volatile bitf_T *)0xFFFF83FA)->bit02)
#define DTS4ER             (((volatile bitf_T *)0xFFFF83FA)->bit03)
#define DTS4DT             (((volatile bitf_T *)0xFFFF83FA)->bit06)
#define DTS4TC             (((volatile bitf_T *)0xFFFF83FA)->bit07)
#define DSA5               (*(volatile unsigned long  *)0xFFFF8404)
#define DSA5L              (*(volatile unsigned short *)0xFFFF8404)
#define DSA5H              (*(volatile unsigned short *)0xFFFF8406)
#define DDA5               (*(volatile unsigned long  *)0xFFFF8414)
#define DDA5L              (*(volatile unsigned short *)0xFFFF8414)
#define DDA5H              (*(volatile unsigned short *)0xFFFF8416)
#define DTC5               (*(volatile unsigned short *)0xFFFF8422)
#define DTCT5              (*(volatile unsigned short *)0xFFFF8428)
#define DTS5               (*(volatile unsigned char  *)0xFFFF842A)
#define DTS5DTE            (((volatile bitf_T *)0xFFFF842A)->bit00)
#define DTS5SR             (((volatile bitf_T *)0xFFFF842A)->bit01)
#define DTS5DR             (((volatile bitf_T *)0xFFFF842A)->bit02)
#define DTS5ER             (((volatile bitf_T *)0xFFFF842A)->bit03)
#define DTS5DT             (((volatile bitf_T *)0xFFFF842A)->bit06)
#define DTS5TC             (((volatile bitf_T *)0xFFFF842A)->bit07)
#define DSA6               (*(volatile unsigned long  *)0xFFFF8434)
#define DSA6L              (*(volatile unsigned short *)0xFFFF8434)
#define DSA6H              (*(volatile unsigned short *)0xFFFF8436)
#define DDA6               (*(volatile unsigned long  *)0xFFFF8444)
#define DDA6L              (*(volatile unsigned short *)0xFFFF8444)
#define DDA6H              (*(volatile unsigned short *)0xFFFF8446)
#define DTC6               (*(volatile unsigned short *)0xFFFF8452)
#define DTCT6              (*(volatile unsigned short *)0xFFFF8458)
#define DTS6               (*(volatile unsigned char  *)0xFFFF845A)
#define DTS6DTE            (((volatile bitf_T *)0xFFFF845A)->bit00)
#define DTS6SR             (((volatile bitf_T *)0xFFFF845A)->bit01)
#define DTS6DR             (((volatile bitf_T *)0xFFFF845A)->bit02)
#define DTS6ER             (((volatile bitf_T *)0xFFFF845A)->bit03)
#define DTS6DT             (((volatile bitf_T *)0xFFFF845A)->bit06)
#define DTS6TC             (((volatile bitf_T *)0xFFFF845A)->bit07)
#define DSA7               (*(volatile unsigned long  *)0xFFFF8464)
#define DSA7L              (*(volatile unsigned short *)0xFFFF8464)
#define DSA7H              (*(volatile unsigned short *)0xFFFF8466)
#define DDA7               (*(volatile unsigned long  *)0xFFFF8474)
#define DDA7L              (*(volatile unsigned short *)0xFFFF8474)
#define DDA7H              (*(volatile unsigned short *)0xFFFF8476)
#define DTC7               (*(volatile unsigned short *)0xFFFF8482)
#define DTCT7              (*(volatile unsigned short *)0xFFFF8488)
#define DTS7               (*(volatile unsigned char  *)0xFFFF848A)
#define DTS7DTE            (((volatile bitf_T *)0xFFFF848A)->bit00)
#define DTS7SR             (((volatile bitf_T *)0xFFFF848A)->bit01)
#define DTS7DR             (((volatile bitf_T *)0xFFFF848A)->bit02)
#define DTS7ER             (((volatile bitf_T *)0xFFFF848A)->bit03)
#define DTS7DT             (((volatile bitf_T *)0xFFFF848A)->bit06)
#define DTS7TC             (((volatile bitf_T *)0xFFFF848A)->bit07)
#define DSA8               (*(volatile unsigned long  *)0xFFFF8514)
#define DSA8L              (*(volatile unsigned short *)0xFFFF8514)
#define DSA8H              (*(volatile unsigned short *)0xFFFF8516)
#define DDA8               (*(volatile unsigned long  *)0xFFFF8524)
#define DDA8L              (*(volatile unsigned short *)0xFFFF8524)
#define DDA8H              (*(volatile unsigned short *)0xFFFF8526)
#define DTC8               (*(volatile unsigned short *)0xFFFF8532)
#define DTCT8              (*(volatile unsigned short *)0xFFFF8538)
#define DTS8               (*(volatile unsigned char  *)0xFFFF853A)
#define DTS8DTE            (((volatile bitf_T *)0xFFFF853A)->bit00)
#define DTS8SR             (((volatile bitf_T *)0xFFFF853A)->bit01)
#define DTS8DR             (((volatile bitf_T *)0xFFFF853A)->bit02)
#define DTS8ER             (((volatile bitf_T *)0xFFFF853A)->bit03)
#define DTS8DT             (((volatile bitf_T *)0xFFFF853A)->bit06)
#define DTS8TC             (((volatile bitf_T *)0xFFFF853A)->bit07)
#define DSA9               (*(volatile unsigned long  *)0xFFFF8544)
#define DSA9L              (*(volatile unsigned short *)0xFFFF8544)
#define DSA9H              (*(volatile unsigned short *)0xFFFF8546)
#define DDA9               (*(volatile unsigned long  *)0xFFFF8554)
#define DDA9L              (*(volatile unsigned short *)0xFFFF8554)
#define DDA9H              (*(volatile unsigned short *)0xFFFF8556)
#define DTC9               (*(volatile unsigned short *)0xFFFF8562)
#define DTCT9              (*(volatile unsigned short *)0xFFFF8568)
#define DTS9               (*(volatile unsigned char  *)0xFFFF856A)
#define DTS9DTE            (((volatile bitf_T *)0xFFFF856A)->bit00)
#define DTS9SR             (((volatile bitf_T *)0xFFFF856A)->bit01)
#define DTS9DR             (((volatile bitf_T *)0xFFFF856A)->bit02)
#define DTS9ER             (((volatile bitf_T *)0xFFFF856A)->bit03)
#define DTS9DT             (((volatile bitf_T *)0xFFFF856A)->bit06)
#define DTS9TC             (((volatile bitf_T *)0xFFFF856A)->bit07)
#define DSA10              (*(volatile unsigned long  *)0xFFFF8574)
#define DSA10L             (*(volatile unsigned short *)0xFFFF8574)
#define DSA10H             (*(volatile unsigned short *)0xFFFF8576)
#define DDA10              (*(volatile unsigned long  *)0xFFFF8584)
#define DDA10L             (*(volatile unsigned short *)0xFFFF8584)
#define DDA10H             (*(volatile unsigned short *)0xFFFF8586)
#define DTC10              (*(volatile unsigned short *)0xFFFF8592)
#define DTCT10             (*(volatile unsigned short *)0xFFFF8598)
#define DTS10              (*(volatile unsigned char  *)0xFFFF859A)
#define DTS10DTE           (((volatile bitf_T *)0xFFFF859A)->bit00)
#define DTS10SR            (((volatile bitf_T *)0xFFFF859A)->bit01)
#define DTS10DR            (((volatile bitf_T *)0xFFFF859A)->bit02)
#define DTS10ER            (((volatile bitf_T *)0xFFFF859A)->bit03)
#define DTS10DT            (((volatile bitf_T *)0xFFFF859A)->bit06)
#define DTS10TC            (((volatile bitf_T *)0xFFFF859A)->bit07)
#define DSA11              (*(volatile unsigned long  *)0xFFFF85A4)
#define DSA11L             (*(volatile unsigned short *)0xFFFF85A4)
#define DSA11H             (*(volatile unsigned short *)0xFFFF85A6)
#define DDA11              (*(volatile unsigned long  *)0xFFFF85B4)
#define DDA11L             (*(volatile unsigned short *)0xFFFF85B4)
#define DDA11H             (*(volatile unsigned short *)0xFFFF85B6)
#define DTC11              (*(volatile unsigned short *)0xFFFF85C2)
#define DTCT11             (*(volatile unsigned short *)0xFFFF85C8)
#define DTS11              (*(volatile unsigned char  *)0xFFFF85CA)
#define DTS11DTE           (((volatile bitf_T *)0xFFFF85CA)->bit00)
#define DTS11SR            (((volatile bitf_T *)0xFFFF85CA)->bit01)
#define DTS11DR            (((volatile bitf_T *)0xFFFF85CA)->bit02)
#define DTS11ER            (((volatile bitf_T *)0xFFFF85CA)->bit03)
#define DTS11DT            (((volatile bitf_T *)0xFFFF85CA)->bit06)
#define DTS11TC            (((volatile bitf_T *)0xFFFF85CA)->bit07)
#define DSA12              (*(volatile unsigned long  *)0xFFFF85D4)
#define DSA12L             (*(volatile unsigned short *)0xFFFF85D4)
#define DSA12H             (*(volatile unsigned short *)0xFFFF85D6)
#define DDA12              (*(volatile unsigned long  *)0xFFFF85E4)
#define DDA12L             (*(volatile unsigned short *)0xFFFF85E4)
#define DDA12H             (*(volatile unsigned short *)0xFFFF85E6)
#define DTC12              (*(volatile unsigned short *)0xFFFF85F2)
#define DTCT12             (*(volatile unsigned short *)0xFFFF85F8)
#define DTS12              (*(volatile unsigned char  *)0xFFFF85FA)
#define DTS12DTE           (((volatile bitf_T *)0xFFFF85FA)->bit00)
#define DTS12SR            (((volatile bitf_T *)0xFFFF85FA)->bit01)
#define DTS12DR            (((volatile bitf_T *)0xFFFF85FA)->bit02)
#define DTS12ER            (((volatile bitf_T *)0xFFFF85FA)->bit03)
#define DTS12DT            (((volatile bitf_T *)0xFFFF85FA)->bit06)
#define DTS12TC            (((volatile bitf_T *)0xFFFF85FA)->bit07)
#define DSA13              (*(volatile unsigned long  *)0xFFFF8604)
#define DSA13L             (*(volatile unsigned short *)0xFFFF8604)
#define DSA13H             (*(volatile unsigned short *)0xFFFF8606)
#define DDA13              (*(volatile unsigned long  *)0xFFFF8614)
#define DDA13L             (*(volatile unsigned short *)0xFFFF8614)
#define DDA13H             (*(volatile unsigned short *)0xFFFF8616)
#define DTC13              (*(volatile unsigned short *)0xFFFF8622)
#define DTCT13             (*(volatile unsigned short *)0xFFFF8628)
#define DTS13              (*(volatile unsigned char  *)0xFFFF862A)
#define DTS13DTE           (((volatile bitf_T *)0xFFFF862A)->bit00)
#define DTS13SR            (((volatile bitf_T *)0xFFFF862A)->bit01)
#define DTS13DR            (((volatile bitf_T *)0xFFFF862A)->bit02)
#define DTS13ER            (((volatile bitf_T *)0xFFFF862A)->bit03)
#define DTS13DT            (((volatile bitf_T *)0xFFFF862A)->bit06)
#define DTS13TC            (((volatile bitf_T *)0xFFFF862A)->bit07)
#define DSA14              (*(volatile unsigned long  *)0xFFFF8634)
#define DSA14L             (*(volatile unsigned short *)0xFFFF8634)
#define DSA14H             (*(volatile unsigned short *)0xFFFF8636)
#define DDA14              (*(volatile unsigned long  *)0xFFFF8644)
#define DDA14L             (*(volatile unsigned short *)0xFFFF8644)
#define DDA14H             (*(volatile unsigned short *)0xFFFF8646)
#define DTC14              (*(volatile unsigned short *)0xFFFF8652)
#define DTCT14             (*(volatile unsigned short *)0xFFFF8658)
#define DTS14              (*(volatile unsigned char  *)0xFFFF865A)
#define DTS14DTE           (((volatile bitf_T *)0xFFFF865A)->bit00)
#define DTS14SR            (((volatile bitf_T *)0xFFFF865A)->bit01)
#define DTS14DR            (((volatile bitf_T *)0xFFFF865A)->bit02)
#define DTS14ER            (((volatile bitf_T *)0xFFFF865A)->bit03)
#define DTS14DT            (((volatile bitf_T *)0xFFFF865A)->bit06)
#define DTS14TC            (((volatile bitf_T *)0xFFFF865A)->bit07)
#define DSA15              (*(volatile unsigned long  *)0xFFFF8664)
#define DSA15L             (*(volatile unsigned short *)0xFFFF8664)
#define DSA15H             (*(volatile unsigned short *)0xFFFF8666)
#define DDA15              (*(volatile unsigned long  *)0xFFFF8674)
#define DDA15L             (*(volatile unsigned short *)0xFFFF8674)
#define DDA15H             (*(volatile unsigned short *)0xFFFF8676)
#define DTC15              (*(volatile unsigned short *)0xFFFF8682)
#define DTCT15             (*(volatile unsigned short *)0xFFFF8688)
#define DTS15              (*(volatile unsigned char  *)0xFFFF868A)
#define DTS15DTE           (((volatile bitf_T *)0xFFFF868A)->bit00)
#define DTS15SR            (((volatile bitf_T *)0xFFFF868A)->bit01)
#define DTS15DR            (((volatile bitf_T *)0xFFFF868A)->bit02)
#define DTS15ER            (((volatile bitf_T *)0xFFFF868A)->bit03)
#define DTS15DT            (((volatile bitf_T *)0xFFFF868A)->bit06)
#define DTS15TC            (((volatile bitf_T *)0xFFFF868A)->bit07)
#define DTFR0              (*(volatile unsigned short *)0xFFFF8B00)
#define DTFR1              (*(volatile unsigned short *)0xFFFF8B02)
#define DTFR2              (*(volatile unsigned short *)0xFFFF8B04)
#define DTFR3              (*(volatile unsigned short *)0xFFFF8B06)
#define DTFR4              (*(volatile unsigned short *)0xFFFF8B08)
#define DTFR5              (*(volatile unsigned short *)0xFFFF8B0A)
#define DTFR6              (*(volatile unsigned short *)0xFFFF8B0C)
#define DTFR7              (*(volatile unsigned short *)0xFFFF8B0E)
#define DTFR8              (*(volatile unsigned short *)0xFFFF8B10)
#define DTFR9              (*(volatile unsigned short *)0xFFFF8B12)
#define DTFR10             (*(volatile unsigned short *)0xFFFF8B14)
#define DTFR11             (*(volatile unsigned short *)0xFFFF8B16)
#define DTFR12             (*(volatile unsigned short *)0xFFFF8B18)
#define DTFR13             (*(volatile unsigned short *)0xFFFF8B1A)
#define DTFR14             (*(volatile unsigned short *)0xFFFF8B1C)
#define DTFR15             (*(volatile unsigned short *)0xFFFF8B1E)
#define DRQCLR             (*(volatile unsigned short *)0xFFFF8B40)
#define DRQSTR             (*(volatile unsigned short *)0xFFFF8B44)
#define SEG_CONT           (*(volatile unsigned short *)0xFFFF8C00)
#define SEG_CONTL          (*(volatile unsigned char  *)0xFFFF8C00)
#define SEG_CONTROME       (((volatile bitf_T *)0xFFFF8C00)->bit01)
#define SEG_CONTRAME       (((volatile bitf_T *)0xFFFF8C00)->bit04)
#define SEG_CONTRMWE       (((volatile bitf_T *)0xFFFF8C00)->bit06)
#define SEG_CONTDMAE       (((volatile bitf_T *)0xFFFF8C00)->bit07)
#define SEG_FLAG           (*(volatile unsigned short *)0xFFFF8C02)
#define SEG_FLAGL          (*(volatile unsigned char  *)0xFFFF8C02)
#define SEG_FLAGROMF       (((volatile bitf_T *)0xFFFF8C02)->bit01)
#define SEG_FLAGRAMF       (((volatile bitf_T *)0xFFFF8C02)->bit04)
#define SEG_FLAGRMWF       (((volatile bitf_T *)0xFFFF8C02)->bit06)
#define SEG_FLAGDMAF       (((volatile bitf_T *)0xFFFF8C02)->bit07)
#define ICCSIH2IC_1        (*(volatile unsigned short *)0xFFFF9000)
#define ICTAUD0I0          (*(volatile unsigned short *)0xFFFF9000)
#define ICCSIH2ICL_1       (*(volatile unsigned char  *)0xFFFF9000)
#define ICTAUD0I0L         (*(volatile unsigned char  *)0xFFFF9000)
#define ICCSIH2ICH_1       (*(volatile unsigned char  *)0xFFFF9001)
#define ICTAUD0I0H         (*(volatile unsigned char  *)0xFFFF9001)
#define P0CSIH2IC_1        (((volatile bitf_T *)0xFFFF9000)->bit00)
#define P0TAUD0I0          (((volatile bitf_T *)0xFFFF9000)->bit00)
#define P1CSIH2IC_1        (((volatile bitf_T *)0xFFFF9000)->bit01)
#define P1TAUD0I0          (((volatile bitf_T *)0xFFFF9000)->bit01)
#define P2CSIH2IC_1        (((volatile bitf_T *)0xFFFF9000)->bit02)
#define P2TAUD0I0          (((volatile bitf_T *)0xFFFF9000)->bit02)
#define TBCSIH2IC_1        (((volatile bitf_T *)0xFFFF9000)->bit06)
#define TBTAUD0I0          (((volatile bitf_T *)0xFFFF9000)->bit06)
#define MKCSIH2IC_1        (((volatile bitf_T *)0xFFFF9000)->bit07)
#define MKTAUD0I0          (((volatile bitf_T *)0xFFFF9000)->bit07)
#define RFCSIH2IC_1        (((volatile bitf_T *)0xFFFF9001)->bit04)
#define RFTAUD0I0          (((volatile bitf_T *)0xFFFF9001)->bit04)
#define CTCSIH2IC_1        (((volatile bitf_T *)0xFFFF9001)->bit07)
#define CTTAUD0I0          (((volatile bitf_T *)0xFFFF9001)->bit07)
#define ICTAUD0I2          (*(volatile unsigned short *)0xFFFF9002)
#define ICTAUD0I2L         (*(volatile unsigned char  *)0xFFFF9002)
#define ICTAUD0I2H         (*(volatile unsigned char  *)0xFFFF9003)
#define P0TAUD0I2          (((volatile bitf_T *)0xFFFF9002)->bit00)
#define P1TAUD0I2          (((volatile bitf_T *)0xFFFF9002)->bit01)
#define P2TAUD0I2          (((volatile bitf_T *)0xFFFF9002)->bit02)
#define TBTAUD0I2          (((volatile bitf_T *)0xFFFF9002)->bit06)
#define MKTAUD0I2          (((volatile bitf_T *)0xFFFF9002)->bit07)
#define RFTAUD0I2          (((volatile bitf_T *)0xFFFF9003)->bit04)
#define CTTAUD0I2          (((volatile bitf_T *)0xFFFF9003)->bit07)
#define ICTAUD0I4          (*(volatile unsigned short *)0xFFFF9004)
#define ICTAUD0I4L         (*(volatile unsigned char  *)0xFFFF9004)
#define ICTAUD0I4H         (*(volatile unsigned char  *)0xFFFF9005)
#define P0TAUD0I4          (((volatile bitf_T *)0xFFFF9004)->bit00)
#define P1TAUD0I4          (((volatile bitf_T *)0xFFFF9004)->bit01)
#define P2TAUD0I4          (((volatile bitf_T *)0xFFFF9004)->bit02)
#define TBTAUD0I4          (((volatile bitf_T *)0xFFFF9004)->bit06)
#define MKTAUD0I4          (((volatile bitf_T *)0xFFFF9004)->bit07)
#define RFTAUD0I4          (((volatile bitf_T *)0xFFFF9005)->bit04)
#define CTTAUD0I4          (((volatile bitf_T *)0xFFFF9005)->bit07)
#define ICTAUD0I6          (*(volatile unsigned short *)0xFFFF9006)
#define ICTAUD0I6L         (*(volatile unsigned char  *)0xFFFF9006)
#define ICTAUD0I6H         (*(volatile unsigned char  *)0xFFFF9007)
#define P0TAUD0I6          (((volatile bitf_T *)0xFFFF9006)->bit00)
#define P1TAUD0I6          (((volatile bitf_T *)0xFFFF9006)->bit01)
#define P2TAUD0I6          (((volatile bitf_T *)0xFFFF9006)->bit02)
#define TBTAUD0I6          (((volatile bitf_T *)0xFFFF9006)->bit06)
#define MKTAUD0I6          (((volatile bitf_T *)0xFFFF9006)->bit07)
#define RFTAUD0I6          (((volatile bitf_T *)0xFFFF9007)->bit04)
#define CTTAUD0I6          (((volatile bitf_T *)0xFFFF9007)->bit07)
#define ICTAUD0I8          (*(volatile unsigned short *)0xFFFF9008)
#define ICTAUD0I8L         (*(volatile unsigned char  *)0xFFFF9008)
#define ICTAUD0I8H         (*(volatile unsigned char  *)0xFFFF9009)
#define P0TAUD0I8          (((volatile bitf_T *)0xFFFF9008)->bit00)
#define P1TAUD0I8          (((volatile bitf_T *)0xFFFF9008)->bit01)
#define P2TAUD0I8          (((volatile bitf_T *)0xFFFF9008)->bit02)
#define TBTAUD0I8          (((volatile bitf_T *)0xFFFF9008)->bit06)
#define MKTAUD0I8          (((volatile bitf_T *)0xFFFF9008)->bit07)
#define RFTAUD0I8          (((volatile bitf_T *)0xFFFF9009)->bit04)
#define CTTAUD0I8          (((volatile bitf_T *)0xFFFF9009)->bit07)
#define ICTAUD0I10         (*(volatile unsigned short *)0xFFFF900A)
#define ICTAUD0I10L        (*(volatile unsigned char  *)0xFFFF900A)
#define ICTAUD0I10H        (*(volatile unsigned char  *)0xFFFF900B)
#define P0TAUD0I10         (((volatile bitf_T *)0xFFFF900A)->bit00)
#define P1TAUD0I10         (((volatile bitf_T *)0xFFFF900A)->bit01)
#define P2TAUD0I10         (((volatile bitf_T *)0xFFFF900A)->bit02)
#define TBTAUD0I10         (((volatile bitf_T *)0xFFFF900A)->bit06)
#define MKTAUD0I10         (((volatile bitf_T *)0xFFFF900A)->bit07)
#define RFTAUD0I10         (((volatile bitf_T *)0xFFFF900B)->bit04)
#define CTTAUD0I10         (((volatile bitf_T *)0xFFFF900B)->bit07)
#define ICTAUD0I12         (*(volatile unsigned short *)0xFFFF900C)
#define ICTAUD0I12L        (*(volatile unsigned char  *)0xFFFF900C)
#define ICTAUD0I12H        (*(volatile unsigned char  *)0xFFFF900D)
#define P0TAUD0I12         (((volatile bitf_T *)0xFFFF900C)->bit00)
#define P1TAUD0I12         (((volatile bitf_T *)0xFFFF900C)->bit01)
#define P2TAUD0I12         (((volatile bitf_T *)0xFFFF900C)->bit02)
#define TBTAUD0I12         (((volatile bitf_T *)0xFFFF900C)->bit06)
#define MKTAUD0I12         (((volatile bitf_T *)0xFFFF900C)->bit07)
#define RFTAUD0I12         (((volatile bitf_T *)0xFFFF900D)->bit04)
#define CTTAUD0I12         (((volatile bitf_T *)0xFFFF900D)->bit07)
#define ICTAUD0I14         (*(volatile unsigned short *)0xFFFF900E)
#define ICTAUD0I14L        (*(volatile unsigned char  *)0xFFFF900E)
#define ICTAUD0I14H        (*(volatile unsigned char  *)0xFFFF900F)
#define P0TAUD0I14         (((volatile bitf_T *)0xFFFF900E)->bit00)
#define P1TAUD0I14         (((volatile bitf_T *)0xFFFF900E)->bit01)
#define P2TAUD0I14         (((volatile bitf_T *)0xFFFF900E)->bit02)
#define TBTAUD0I14         (((volatile bitf_T *)0xFFFF900E)->bit06)
#define MKTAUD0I14         (((volatile bitf_T *)0xFFFF900E)->bit07)
#define RFTAUD0I14         (((volatile bitf_T *)0xFFFF900F)->bit04)
#define CTTAUD0I14         (((volatile bitf_T *)0xFFFF900F)->bit07)
#define ICCSIH1IC_1        (*(volatile unsigned short *)0xFFFF9010)
#define ICTAPA0IPEK0       (*(volatile unsigned short *)0xFFFF9010)
#define ICCSIH1ICL_1       (*(volatile unsigned char  *)0xFFFF9010)
#define ICTAPA0IPEK0L      (*(volatile unsigned char  *)0xFFFF9010)
#define ICCSIH1ICH_1       (*(volatile unsigned char  *)0xFFFF9011)
#define ICTAPA0IPEK0H      (*(volatile unsigned char  *)0xFFFF9011)
#define P0CSIH1IC_1        (((volatile bitf_T *)0xFFFF9010)->bit00)
#define P0TAPA0IPEK0       (((volatile bitf_T *)0xFFFF9010)->bit00)
#define P1CSIH1IC_1        (((volatile bitf_T *)0xFFFF9010)->bit01)
#define P1TAPA0IPEK0       (((volatile bitf_T *)0xFFFF9010)->bit01)
#define P2CSIH1IC_1        (((volatile bitf_T *)0xFFFF9010)->bit02)
#define P2TAPA0IPEK0       (((volatile bitf_T *)0xFFFF9010)->bit02)
#define TBCSIH1IC_1        (((volatile bitf_T *)0xFFFF9010)->bit06)
#define TBTAPA0IPEK0       (((volatile bitf_T *)0xFFFF9010)->bit06)
#define MKCSIH1IC_1        (((volatile bitf_T *)0xFFFF9010)->bit07)
#define MKTAPA0IPEK0       (((volatile bitf_T *)0xFFFF9010)->bit07)
#define RFCSIH1IC_1        (((volatile bitf_T *)0xFFFF9011)->bit04)
#define RFTAPA0IPEK0       (((volatile bitf_T *)0xFFFF9011)->bit04)
#define CTCSIH1IC_1        (((volatile bitf_T *)0xFFFF9011)->bit07)
#define CTTAPA0IPEK0       (((volatile bitf_T *)0xFFFF9011)->bit07)
#define ICCSIH1IR_1        (*(volatile unsigned short *)0xFFFF9012)
#define ICTAPA0IVLY0       (*(volatile unsigned short *)0xFFFF9012)
#define ICCSIH1IRL_1       (*(volatile unsigned char  *)0xFFFF9012)
#define ICTAPA0IVLY0L      (*(volatile unsigned char  *)0xFFFF9012)
#define ICCSIH1IRH_1       (*(volatile unsigned char  *)0xFFFF9013)
#define ICTAPA0IVLY0H      (*(volatile unsigned char  *)0xFFFF9013)
#define P0CSIH1IR_1        (((volatile bitf_T *)0xFFFF9012)->bit00)
#define P0TAPA0IVLY0       (((volatile bitf_T *)0xFFFF9012)->bit00)
#define P1CSIH1IR_1        (((volatile bitf_T *)0xFFFF9012)->bit01)
#define P1TAPA0IVLY0       (((volatile bitf_T *)0xFFFF9012)->bit01)
#define P2CSIH1IR_1        (((volatile bitf_T *)0xFFFF9012)->bit02)
#define P2TAPA0IVLY0       (((volatile bitf_T *)0xFFFF9012)->bit02)
#define TBCSIH1IR_1        (((volatile bitf_T *)0xFFFF9012)->bit06)
#define TBTAPA0IVLY0       (((volatile bitf_T *)0xFFFF9012)->bit06)
#define MKCSIH1IR_1        (((volatile bitf_T *)0xFFFF9012)->bit07)
#define MKTAPA0IVLY0       (((volatile bitf_T *)0xFFFF9012)->bit07)
#define RFCSIH1IR_1        (((volatile bitf_T *)0xFFFF9013)->bit04)
#define RFTAPA0IVLY0       (((volatile bitf_T *)0xFFFF9013)->bit04)
#define CTCSIH1IR_1        (((volatile bitf_T *)0xFFFF9013)->bit07)
#define CTTAPA0IVLY0       (((volatile bitf_T *)0xFFFF9013)->bit07)
#define ICADCA0I0          (*(volatile unsigned short *)0xFFFF9014)
#define ICADCA0I0L         (*(volatile unsigned char  *)0xFFFF9014)
#define ICADCA0I0H         (*(volatile unsigned char  *)0xFFFF9015)
#define P0ADCA0I0          (((volatile bitf_T *)0xFFFF9014)->bit00)
#define P1ADCA0I0          (((volatile bitf_T *)0xFFFF9014)->bit01)
#define P2ADCA0I0          (((volatile bitf_T *)0xFFFF9014)->bit02)
#define TBADCA0I0          (((volatile bitf_T *)0xFFFF9014)->bit06)
#define MKADCA0I0          (((volatile bitf_T *)0xFFFF9014)->bit07)
#define RFADCA0I0          (((volatile bitf_T *)0xFFFF9015)->bit04)
#define CTADCA0I0          (((volatile bitf_T *)0xFFFF9015)->bit07)
#define ICADCA0I1          (*(volatile unsigned short *)0xFFFF9016)
#define ICADCA0I1L         (*(volatile unsigned char  *)0xFFFF9016)
#define ICADCA0I1H         (*(volatile unsigned char  *)0xFFFF9017)
#define P0ADCA0I1          (((volatile bitf_T *)0xFFFF9016)->bit00)
#define P1ADCA0I1          (((volatile bitf_T *)0xFFFF9016)->bit01)
#define P2ADCA0I1          (((volatile bitf_T *)0xFFFF9016)->bit02)
#define TBADCA0I1          (((volatile bitf_T *)0xFFFF9016)->bit06)
#define MKADCA0I1          (((volatile bitf_T *)0xFFFF9016)->bit07)
#define RFADCA0I1          (((volatile bitf_T *)0xFFFF9017)->bit04)
#define CTADCA0I1          (((volatile bitf_T *)0xFFFF9017)->bit07)
#define ICADCA0I2          (*(volatile unsigned short *)0xFFFF9018)
#define ICADCA0I2L         (*(volatile unsigned char  *)0xFFFF9018)
#define ICADCA0I2H         (*(volatile unsigned char  *)0xFFFF9019)
#define P0ADCA0I2          (((volatile bitf_T *)0xFFFF9018)->bit00)
#define P1ADCA0I2          (((volatile bitf_T *)0xFFFF9018)->bit01)
#define P2ADCA0I2          (((volatile bitf_T *)0xFFFF9018)->bit02)
#define TBADCA0I2          (((volatile bitf_T *)0xFFFF9018)->bit06)
#define MKADCA0I2          (((volatile bitf_T *)0xFFFF9018)->bit07)
#define RFADCA0I2          (((volatile bitf_T *)0xFFFF9019)->bit04)
#define CTADCA0I2          (((volatile bitf_T *)0xFFFF9019)->bit07)
#define ICDCUTDI           (*(volatile unsigned short *)0xFFFF901A)
#define ICDCUTDIL          (*(volatile unsigned char  *)0xFFFF901A)
#define ICDCUTDIH          (*(volatile unsigned char  *)0xFFFF901B)
#define P0DCUTDI           (((volatile bitf_T *)0xFFFF901A)->bit00)
#define P1DCUTDI           (((volatile bitf_T *)0xFFFF901A)->bit01)
#define P2DCUTDI           (((volatile bitf_T *)0xFFFF901A)->bit02)
#define TBDCUTDI           (((volatile bitf_T *)0xFFFF901A)->bit06)
#define MKDCUTDI           (((volatile bitf_T *)0xFFFF901A)->bit07)
#define RFDCUTDI           (((volatile bitf_T *)0xFFFF901B)->bit04)
#define CTDCUTDI           (((volatile bitf_T *)0xFFFF901B)->bit07)
#define ICRCANGERR         (*(volatile unsigned short *)0xFFFF901C)
#define ICRCANGERRL        (*(volatile unsigned char  *)0xFFFF901C)
#define ICRCANGERRH        (*(volatile unsigned char  *)0xFFFF901D)
#define P0RCANGERR         (((volatile bitf_T *)0xFFFF901C)->bit00)
#define P1RCANGERR         (((volatile bitf_T *)0xFFFF901C)->bit01)
#define P2RCANGERR         (((volatile bitf_T *)0xFFFF901C)->bit02)
#define TBRCANGERR         (((volatile bitf_T *)0xFFFF901C)->bit06)
#define MKRCANGERR         (((volatile bitf_T *)0xFFFF901C)->bit07)
#define RFRCANGERR         (((volatile bitf_T *)0xFFFF901D)->bit04)
#define CTRCANGERR         (((volatile bitf_T *)0xFFFF901D)->bit07)
#define ICRCANGRECC        (*(volatile unsigned short *)0xFFFF901E)
#define ICRCANGRECCL       (*(volatile unsigned char  *)0xFFFF901E)
#define ICRCANGRECCH       (*(volatile unsigned char  *)0xFFFF901F)
#define P0RCANGRECC        (((volatile bitf_T *)0xFFFF901E)->bit00)
#define P1RCANGRECC        (((volatile bitf_T *)0xFFFF901E)->bit01)
#define P2RCANGRECC        (((volatile bitf_T *)0xFFFF901E)->bit02)
#define TBRCANGRECC        (((volatile bitf_T *)0xFFFF901E)->bit06)
#define MKRCANGRECC        (((volatile bitf_T *)0xFFFF901E)->bit07)
#define RFRCANGRECC        (((volatile bitf_T *)0xFFFF901F)->bit04)
#define CTRCANGRECC        (((volatile bitf_T *)0xFFFF901F)->bit07)
#define ICRCAN0ERR         (*(volatile unsigned short *)0xFFFF9020)
#define ICRCAN0ERRL        (*(volatile unsigned char  *)0xFFFF9020)
#define ICRCAN0ERRH        (*(volatile unsigned char  *)0xFFFF9021)
#define P0RCAN0ERR         (((volatile bitf_T *)0xFFFF9020)->bit00)
#define P1RCAN0ERR         (((volatile bitf_T *)0xFFFF9020)->bit01)
#define P2RCAN0ERR         (((volatile bitf_T *)0xFFFF9020)->bit02)
#define TBRCAN0ERR         (((volatile bitf_T *)0xFFFF9020)->bit06)
#define MKRCAN0ERR         (((volatile bitf_T *)0xFFFF9020)->bit07)
#define RFRCAN0ERR         (((volatile bitf_T *)0xFFFF9021)->bit04)
#define CTRCAN0ERR         (((volatile bitf_T *)0xFFFF9021)->bit07)
#define ICRCAN0REC         (*(volatile unsigned short *)0xFFFF9022)
#define ICRCAN0RECL        (*(volatile unsigned char  *)0xFFFF9022)
#define ICRCAN0RECH        (*(volatile unsigned char  *)0xFFFF9023)
#define P0RCAN0REC         (((volatile bitf_T *)0xFFFF9022)->bit00)
#define P1RCAN0REC         (((volatile bitf_T *)0xFFFF9022)->bit01)
#define P2RCAN0REC         (((volatile bitf_T *)0xFFFF9022)->bit02)
#define TBRCAN0REC         (((volatile bitf_T *)0xFFFF9022)->bit06)
#define MKRCAN0REC         (((volatile bitf_T *)0xFFFF9022)->bit07)
#define RFRCAN0REC         (((volatile bitf_T *)0xFFFF9023)->bit04)
#define CTRCAN0REC         (((volatile bitf_T *)0xFFFF9023)->bit07)
#define ICRCAN0TRX         (*(volatile unsigned short *)0xFFFF9024)
#define ICRCAN0TRXL        (*(volatile unsigned char  *)0xFFFF9024)
#define ICRCAN0TRXH        (*(volatile unsigned char  *)0xFFFF9025)
#define P0RCAN0TRX         (((volatile bitf_T *)0xFFFF9024)->bit00)
#define P1RCAN0TRX         (((volatile bitf_T *)0xFFFF9024)->bit01)
#define P2RCAN0TRX         (((volatile bitf_T *)0xFFFF9024)->bit02)
#define TBRCAN0TRX         (((volatile bitf_T *)0xFFFF9024)->bit06)
#define MKRCAN0TRX         (((volatile bitf_T *)0xFFFF9024)->bit07)
#define RFRCAN0TRX         (((volatile bitf_T *)0xFFFF9025)->bit04)
#define CTRCAN0TRX         (((volatile bitf_T *)0xFFFF9025)->bit07)
#define ICCSIG0IC          (*(volatile unsigned short *)0xFFFF9026)
#define ICCSIH1IRE_1       (*(volatile unsigned short *)0xFFFF9026)
#define ICCSIG0ICL         (*(volatile unsigned char  *)0xFFFF9026)
#define ICCSIH1IREL_1      (*(volatile unsigned char  *)0xFFFF9026)
#define ICCSIG0ICH         (*(volatile unsigned char  *)0xFFFF9027)
#define ICCSIH1IREH_1      (*(volatile unsigned char  *)0xFFFF9027)
#define P0CSIG0IC          (((volatile bitf_T *)0xFFFF9026)->bit00)
#define P0CSIH1IRE_1       (((volatile bitf_T *)0xFFFF9026)->bit00)
#define P1CSIG0IC          (((volatile bitf_T *)0xFFFF9026)->bit01)
#define P1CSIH1IRE_1       (((volatile bitf_T *)0xFFFF9026)->bit01)
#define P2CSIG0IC          (((volatile bitf_T *)0xFFFF9026)->bit02)
#define P2CSIH1IRE_1       (((volatile bitf_T *)0xFFFF9026)->bit02)
#define TBCSIG0IC          (((volatile bitf_T *)0xFFFF9026)->bit06)
#define TBCSIH1IRE_1       (((volatile bitf_T *)0xFFFF9026)->bit06)
#define MKCSIG0IC          (((volatile bitf_T *)0xFFFF9026)->bit07)
#define MKCSIH1IRE_1       (((volatile bitf_T *)0xFFFF9026)->bit07)
#define RFCSIG0IC          (((volatile bitf_T *)0xFFFF9027)->bit04)
#define RFCSIH1IRE_1       (((volatile bitf_T *)0xFFFF9027)->bit04)
#define CTCSIG0IC          (((volatile bitf_T *)0xFFFF9027)->bit07)
#define CTCSIH1IRE_1       (((volatile bitf_T *)0xFFFF9027)->bit07)
#define ICCSIG0IR          (*(volatile unsigned short *)0xFFFF9028)
#define ICCSIH1IJC_1       (*(volatile unsigned short *)0xFFFF9028)
#define ICCSIG0IRL         (*(volatile unsigned char  *)0xFFFF9028)
#define ICCSIH1IJCL_1      (*(volatile unsigned char  *)0xFFFF9028)
#define ICCSIG0IRH         (*(volatile unsigned char  *)0xFFFF9029)
#define ICCSIH1IJCH_1      (*(volatile unsigned char  *)0xFFFF9029)
#define P0CSIG0IR          (((volatile bitf_T *)0xFFFF9028)->bit00)
#define P0CSIH1IJC_1       (((volatile bitf_T *)0xFFFF9028)->bit00)
#define P1CSIG0IR          (((volatile bitf_T *)0xFFFF9028)->bit01)
#define P1CSIH1IJC_1       (((volatile bitf_T *)0xFFFF9028)->bit01)
#define P2CSIG0IR          (((volatile bitf_T *)0xFFFF9028)->bit02)
#define P2CSIH1IJC_1       (((volatile bitf_T *)0xFFFF9028)->bit02)
#define TBCSIG0IR          (((volatile bitf_T *)0xFFFF9028)->bit06)
#define TBCSIH1IJC_1       (((volatile bitf_T *)0xFFFF9028)->bit06)
#define MKCSIG0IR          (((volatile bitf_T *)0xFFFF9028)->bit07)
#define MKCSIH1IJC_1       (((volatile bitf_T *)0xFFFF9028)->bit07)
#define RFCSIG0IR          (((volatile bitf_T *)0xFFFF9029)->bit04)
#define RFCSIH1IJC_1       (((volatile bitf_T *)0xFFFF9029)->bit04)
#define CTCSIG0IR          (((volatile bitf_T *)0xFFFF9029)->bit07)
#define CTCSIH1IJC_1       (((volatile bitf_T *)0xFFFF9029)->bit07)
#define ICCSIH0IC          (*(volatile unsigned short *)0xFFFF902A)
#define ICCSIH0ICL         (*(volatile unsigned char  *)0xFFFF902A)
#define ICCSIH0ICH         (*(volatile unsigned char  *)0xFFFF902B)
#define P0CSIH0IC          (((volatile bitf_T *)0xFFFF902A)->bit00)
#define P1CSIH0IC          (((volatile bitf_T *)0xFFFF902A)->bit01)
#define P2CSIH0IC          (((volatile bitf_T *)0xFFFF902A)->bit02)
#define TBCSIH0IC          (((volatile bitf_T *)0xFFFF902A)->bit06)
#define MKCSIH0IC          (((volatile bitf_T *)0xFFFF902A)->bit07)
#define RFCSIH0IC          (((volatile bitf_T *)0xFFFF902B)->bit04)
#define CTCSIH0IC          (((volatile bitf_T *)0xFFFF902B)->bit07)
#define ICCSIH0IR          (*(volatile unsigned short *)0xFFFF902C)
#define ICCSIH0IRL         (*(volatile unsigned char  *)0xFFFF902C)
#define ICCSIH0IRH         (*(volatile unsigned char  *)0xFFFF902D)
#define P0CSIH0IR          (((volatile bitf_T *)0xFFFF902C)->bit00)
#define P1CSIH0IR          (((volatile bitf_T *)0xFFFF902C)->bit01)
#define P2CSIH0IR          (((volatile bitf_T *)0xFFFF902C)->bit02)
#define TBCSIH0IR          (((volatile bitf_T *)0xFFFF902C)->bit06)
#define MKCSIH0IR          (((volatile bitf_T *)0xFFFF902C)->bit07)
#define RFCSIH0IR          (((volatile bitf_T *)0xFFFF902D)->bit04)
#define CTCSIH0IR          (((volatile bitf_T *)0xFFFF902D)->bit07)
#define ICCSIH0IRE         (*(volatile unsigned short *)0xFFFF902E)
#define ICCSIH0IREL        (*(volatile unsigned char  *)0xFFFF902E)
#define ICCSIH0IREH        (*(volatile unsigned char  *)0xFFFF902F)
#define P0CSIH0IRE         (((volatile bitf_T *)0xFFFF902E)->bit00)
#define P1CSIH0IRE         (((volatile bitf_T *)0xFFFF902E)->bit01)
#define P2CSIH0IRE         (((volatile bitf_T *)0xFFFF902E)->bit02)
#define TBCSIH0IRE         (((volatile bitf_T *)0xFFFF902E)->bit06)
#define MKCSIH0IRE         (((volatile bitf_T *)0xFFFF902E)->bit07)
#define RFCSIH0IRE         (((volatile bitf_T *)0xFFFF902F)->bit04)
#define CTCSIH0IRE         (((volatile bitf_T *)0xFFFF902F)->bit07)
#define ICCSIH0IJC         (*(volatile unsigned short *)0xFFFF9030)
#define ICCSIH0IJCL        (*(volatile unsigned char  *)0xFFFF9030)
#define ICCSIH0IJCH        (*(volatile unsigned char  *)0xFFFF9031)
#define P0CSIH0IJC         (((volatile bitf_T *)0xFFFF9030)->bit00)
#define P1CSIH0IJC         (((volatile bitf_T *)0xFFFF9030)->bit01)
#define P2CSIH0IJC         (((volatile bitf_T *)0xFFFF9030)->bit02)
#define TBCSIH0IJC         (((volatile bitf_T *)0xFFFF9030)->bit06)
#define MKCSIH0IJC         (((volatile bitf_T *)0xFFFF9030)->bit07)
#define RFCSIH0IJC         (((volatile bitf_T *)0xFFFF9031)->bit04)
#define CTCSIH0IJC         (((volatile bitf_T *)0xFFFF9031)->bit07)
#define ICRLIN30           (*(volatile unsigned short *)0xFFFF9032)
#define ICRLIN30L          (*(volatile unsigned char  *)0xFFFF9032)
#define ICRLIN30H          (*(volatile unsigned char  *)0xFFFF9033)
#define P0RLIN30           (((volatile bitf_T *)0xFFFF9032)->bit00)
#define P1RLIN30           (((volatile bitf_T *)0xFFFF9032)->bit01)
#define P2RLIN30           (((volatile bitf_T *)0xFFFF9032)->bit02)
#define TBRLIN30           (((volatile bitf_T *)0xFFFF9032)->bit06)
#define MKRLIN30           (((volatile bitf_T *)0xFFFF9032)->bit07)
#define RFRLIN30           (((volatile bitf_T *)0xFFFF9033)->bit04)
#define CTRLIN30           (((volatile bitf_T *)0xFFFF9033)->bit07)
#define ICRLIN30UR0        (*(volatile unsigned short *)0xFFFF9034)
#define ICRLIN30UR0L       (*(volatile unsigned char  *)0xFFFF9034)
#define ICRLIN30UR0H       (*(volatile unsigned char  *)0xFFFF9035)
#define P0RLIN30UR0        (((volatile bitf_T *)0xFFFF9034)->bit00)
#define P1RLIN30UR0        (((volatile bitf_T *)0xFFFF9034)->bit01)
#define P2RLIN30UR0        (((volatile bitf_T *)0xFFFF9034)->bit02)
#define TBRLIN30UR0        (((volatile bitf_T *)0xFFFF9034)->bit06)
#define MKRLIN30UR0        (((volatile bitf_T *)0xFFFF9034)->bit07)
#define RFRLIN30UR0        (((volatile bitf_T *)0xFFFF9035)->bit04)
#define CTRLIN30UR0        (((volatile bitf_T *)0xFFFF9035)->bit07)
#define ICRLIN30UR1        (*(volatile unsigned short *)0xFFFF9036)
#define ICRLIN30UR1L       (*(volatile unsigned char  *)0xFFFF9036)
#define ICRLIN30UR1H       (*(volatile unsigned char  *)0xFFFF9037)
#define P0RLIN30UR1        (((volatile bitf_T *)0xFFFF9036)->bit00)
#define P1RLIN30UR1        (((volatile bitf_T *)0xFFFF9036)->bit01)
#define P2RLIN30UR1        (((volatile bitf_T *)0xFFFF9036)->bit02)
#define TBRLIN30UR1        (((volatile bitf_T *)0xFFFF9036)->bit06)
#define MKRLIN30UR1        (((volatile bitf_T *)0xFFFF9036)->bit07)
#define RFRLIN30UR1        (((volatile bitf_T *)0xFFFF9037)->bit04)
#define CTRLIN30UR1        (((volatile bitf_T *)0xFFFF9037)->bit07)
#define ICRLIN30UR2        (*(volatile unsigned short *)0xFFFF9038)
#define ICRLIN30UR2L       (*(volatile unsigned char  *)0xFFFF9038)
#define ICRLIN30UR2H       (*(volatile unsigned char  *)0xFFFF9039)
#define P0RLIN30UR2        (((volatile bitf_T *)0xFFFF9038)->bit00)
#define P1RLIN30UR2        (((volatile bitf_T *)0xFFFF9038)->bit01)
#define P2RLIN30UR2        (((volatile bitf_T *)0xFFFF9038)->bit02)
#define TBRLIN30UR2        (((volatile bitf_T *)0xFFFF9038)->bit06)
#define MKRLIN30UR2        (((volatile bitf_T *)0xFFFF9038)->bit07)
#define RFRLIN30UR2        (((volatile bitf_T *)0xFFFF9039)->bit04)
#define CTRLIN30UR2        (((volatile bitf_T *)0xFFFF9039)->bit07)
#define ICCSIH2IR_1        (*(volatile unsigned short *)0xFFFF903A)
#define ICP0               (*(volatile unsigned short *)0xFFFF903A)
#define ICCSIH2IRL_1       (*(volatile unsigned char  *)0xFFFF903A)
#define ICP0L              (*(volatile unsigned char  *)0xFFFF903A)
#define ICCSIH2IRH_1       (*(volatile unsigned char  *)0xFFFF903B)
#define ICP0H              (*(volatile unsigned char  *)0xFFFF903B)
#define P0CSIH2IR_1        (((volatile bitf_T *)0xFFFF903A)->bit00)
#define P0P0               (((volatile bitf_T *)0xFFFF903A)->bit00)
#define P1CSIH2IR_1        (((volatile bitf_T *)0xFFFF903A)->bit01)
#define P1P0               (((volatile bitf_T *)0xFFFF903A)->bit01)
#define P2CSIH2IR_1        (((volatile bitf_T *)0xFFFF903A)->bit02)
#define P2P0               (((volatile bitf_T *)0xFFFF903A)->bit02)
#define TBCSIH2IR_1        (((volatile bitf_T *)0xFFFF903A)->bit06)
#define TBP0               (((volatile bitf_T *)0xFFFF903A)->bit06)
#define MKCSIH2IR_1        (((volatile bitf_T *)0xFFFF903A)->bit07)
#define MKP0               (((volatile bitf_T *)0xFFFF903A)->bit07)
#define RFCSIH2IR_1        (((volatile bitf_T *)0xFFFF903B)->bit04)
#define RFP0               (((volatile bitf_T *)0xFFFF903B)->bit04)
#define CTCSIH2IR_1        (((volatile bitf_T *)0xFFFF903B)->bit07)
#define CTP0               (((volatile bitf_T *)0xFFFF903B)->bit07)
#define ICCSIH2IRE_1       (*(volatile unsigned short *)0xFFFF903C)
#define ICP1               (*(volatile unsigned short *)0xFFFF903C)
#define ICCSIH2IREL_1      (*(volatile unsigned char  *)0xFFFF903C)
#define ICP1L              (*(volatile unsigned char  *)0xFFFF903C)
#define ICCSIH2IREH_1      (*(volatile unsigned char  *)0xFFFF903D)
#define ICP1H              (*(volatile unsigned char  *)0xFFFF903D)
#define P0CSIH2IRE_1       (((volatile bitf_T *)0xFFFF903C)->bit00)
#define P0P1               (((volatile bitf_T *)0xFFFF903C)->bit00)
#define P1CSIH2IRE_1       (((volatile bitf_T *)0xFFFF903C)->bit01)
#define P1P1               (((volatile bitf_T *)0xFFFF903C)->bit01)
#define P2CSIH2IRE_1       (((volatile bitf_T *)0xFFFF903C)->bit02)
#define P2P1               (((volatile bitf_T *)0xFFFF903C)->bit02)
#define TBCSIH2IRE_1       (((volatile bitf_T *)0xFFFF903C)->bit06)
#define TBP1               (((volatile bitf_T *)0xFFFF903C)->bit06)
#define MKCSIH2IRE_1       (((volatile bitf_T *)0xFFFF903C)->bit07)
#define MKP1               (((volatile bitf_T *)0xFFFF903C)->bit07)
#define RFCSIH2IRE_1       (((volatile bitf_T *)0xFFFF903D)->bit04)
#define RFP1               (((volatile bitf_T *)0xFFFF903D)->bit04)
#define CTCSIH2IRE_1       (((volatile bitf_T *)0xFFFF903D)->bit07)
#define CTP1               (((volatile bitf_T *)0xFFFF903D)->bit07)
#define ICCSIH2IJC_1       (*(volatile unsigned short *)0xFFFF903E)
#define ICP2               (*(volatile unsigned short *)0xFFFF903E)
#define ICCSIH2IJCL_1      (*(volatile unsigned char  *)0xFFFF903E)
#define ICP2L              (*(volatile unsigned char  *)0xFFFF903E)
#define ICCSIH2IJCH_1      (*(volatile unsigned char  *)0xFFFF903F)
#define ICP2H              (*(volatile unsigned char  *)0xFFFF903F)
#define P0CSIH2IJC_1       (((volatile bitf_T *)0xFFFF903E)->bit00)
#define P0P2               (((volatile bitf_T *)0xFFFF903E)->bit00)
#define P1CSIH2IJC_1       (((volatile bitf_T *)0xFFFF903E)->bit01)
#define P1P2               (((volatile bitf_T *)0xFFFF903E)->bit01)
#define P2CSIH2IJC_1       (((volatile bitf_T *)0xFFFF903E)->bit02)
#define P2P2               (((volatile bitf_T *)0xFFFF903E)->bit02)
#define TBCSIH2IJC_1       (((volatile bitf_T *)0xFFFF903E)->bit06)
#define TBP2               (((volatile bitf_T *)0xFFFF903E)->bit06)
#define MKCSIH2IJC_1       (((volatile bitf_T *)0xFFFF903E)->bit07)
#define MKP2               (((volatile bitf_T *)0xFFFF903E)->bit07)
#define RFCSIH2IJC_1       (((volatile bitf_T *)0xFFFF903F)->bit04)
#define RFP2               (((volatile bitf_T *)0xFFFF903F)->bit04)
#define CTCSIH2IJC_1       (((volatile bitf_T *)0xFFFF903F)->bit07)
#define CTP2               (((volatile bitf_T *)0xFFFF903F)->bit07)
#define FNC                (*(volatile unsigned short *)0xFFFF9078)
#define FNCH               (*(volatile unsigned char  *)0xFFFF9079)
#define FNRF               (((volatile bitf_T *)0xFFFF9079)->bit04)
#define FIC                (*(volatile unsigned short *)0xFFFF907A)
#define FICH               (*(volatile unsigned char  *)0xFFFF907B)
#define FIRF               (((volatile bitf_T *)0xFFFF907B)->bit04)
#define IMR0               (*(volatile unsigned long  *)0xFFFF90F0)
#define IMR0L              (*(volatile unsigned short *)0xFFFF90F0)
#define IMR0LL             (*(volatile unsigned char  *)0xFFFF90F0)
#define IMR0LH             (*(volatile unsigned char  *)0xFFFF90F1)
#define IMR0H              (*(volatile unsigned short *)0xFFFF90F2)
#define IMR0HL             (*(volatile unsigned char  *)0xFFFF90F2)
#define IMR0HH             (*(volatile unsigned char  *)0xFFFF90F3)
#define IMR0EIMK0          (((volatile bitf_T *)0xFFFF90F0)->bit00)
#define IMR0EIMK1          (((volatile bitf_T *)0xFFFF90F0)->bit01)
#define IMR0EIMK2          (((volatile bitf_T *)0xFFFF90F0)->bit02)
#define IMR0EIMK3          (((volatile bitf_T *)0xFFFF90F0)->bit03)
#define IMR0EIMK4          (((volatile bitf_T *)0xFFFF90F0)->bit04)
#define IMR0EIMK5          (((volatile bitf_T *)0xFFFF90F0)->bit05)
#define IMR0EIMK6          (((volatile bitf_T *)0xFFFF90F0)->bit06)
#define IMR0EIMK7          (((volatile bitf_T *)0xFFFF90F0)->bit07)
#define IMR0EIMK8          (((volatile bitf_T *)0xFFFF90F1)->bit00)
#define IMR0EIMK9          (((volatile bitf_T *)0xFFFF90F1)->bit01)
#define IMR0EIMK10         (((volatile bitf_T *)0xFFFF90F1)->bit02)
#define IMR0EIMK11         (((volatile bitf_T *)0xFFFF90F1)->bit03)
#define IMR0EIMK12         (((volatile bitf_T *)0xFFFF90F1)->bit04)
#define IMR0EIMK14         (((volatile bitf_T *)0xFFFF90F1)->bit06)
#define IMR0EIMK15         (((volatile bitf_T *)0xFFFF90F1)->bit07)
#define IMR0EIMK16         (((volatile bitf_T *)0xFFFF90F2)->bit00)
#define IMR0EIMK17         (((volatile bitf_T *)0xFFFF90F2)->bit01)
#define IMR0EIMK18         (((volatile bitf_T *)0xFFFF90F2)->bit02)
#define IMR0EIMK19         (((volatile bitf_T *)0xFFFF90F2)->bit03)
#define IMR0EIMK20         (((volatile bitf_T *)0xFFFF90F2)->bit04)
#define IMR0EIMK21         (((volatile bitf_T *)0xFFFF90F2)->bit05)
#define IMR0EIMK22         (((volatile bitf_T *)0xFFFF90F2)->bit06)
#define IMR0EIMK23         (((volatile bitf_T *)0xFFFF90F2)->bit07)
#define IMR0EIMK24         (((volatile bitf_T *)0xFFFF90F3)->bit00)
#define IMR0EIMK25         (((volatile bitf_T *)0xFFFF90F3)->bit01)
#define IMR0EIMK26         (((volatile bitf_T *)0xFFFF90F3)->bit02)
#define IMR0EIMK27         (((volatile bitf_T *)0xFFFF90F3)->bit03)
#define IMR0EIMK28         (((volatile bitf_T *)0xFFFF90F3)->bit04)
#define IMR0EIMK29         (((volatile bitf_T *)0xFFFF90F3)->bit05)
#define IMR0EIMK30         (((volatile bitf_T *)0xFFFF90F3)->bit06)
#define IMR0EIMK31         (((volatile bitf_T *)0xFFFF90F3)->bit07)
#define ICWDTA0            (*(volatile unsigned short *)0xFFFFA040)
#define ICWDTA0L           (*(volatile unsigned char  *)0xFFFFA040)
#define ICWDTA0H           (*(volatile unsigned char  *)0xFFFFA041)
#define P0WDTA0            (((volatile bitf_T *)0xFFFFA040)->bit00)
#define P1WDTA0            (((volatile bitf_T *)0xFFFFA040)->bit01)
#define P2WDTA0            (((volatile bitf_T *)0xFFFFA040)->bit02)
#define TBWDTA0            (((volatile bitf_T *)0xFFFFA040)->bit06)
#define MKWDTA0            (((volatile bitf_T *)0xFFFFA040)->bit07)
#define RFWDTA0            (((volatile bitf_T *)0xFFFFA041)->bit04)
#define CTWDTA0            (((volatile bitf_T *)0xFFFFA041)->bit07)
#define ICWDTA1            (*(volatile unsigned short *)0xFFFFA042)
#define ICWDTA1L           (*(volatile unsigned char  *)0xFFFFA042)
#define ICWDTA1H           (*(volatile unsigned char  *)0xFFFFA043)
#define P0WDTA1            (((volatile bitf_T *)0xFFFFA042)->bit00)
#define P1WDTA1            (((volatile bitf_T *)0xFFFFA042)->bit01)
#define P2WDTA1            (((volatile bitf_T *)0xFFFFA042)->bit02)
#define TBWDTA1            (((volatile bitf_T *)0xFFFFA042)->bit06)
#define MKWDTA1            (((volatile bitf_T *)0xFFFFA042)->bit07)
#define RFWDTA1            (((volatile bitf_T *)0xFFFFA043)->bit04)
#define CTWDTA1            (((volatile bitf_T *)0xFFFFA043)->bit07)
#define ICP3               (*(volatile unsigned short *)0xFFFFA044)
#define ICP3L              (*(volatile unsigned char  *)0xFFFFA044)
#define ICP3H              (*(volatile unsigned char  *)0xFFFFA045)
#define P0P3               (((volatile bitf_T *)0xFFFFA044)->bit00)
#define P1P3               (((volatile bitf_T *)0xFFFFA044)->bit01)
#define P2P3               (((volatile bitf_T *)0xFFFFA044)->bit02)
#define TBP3               (((volatile bitf_T *)0xFFFFA044)->bit06)
#define MKP3               (((volatile bitf_T *)0xFFFFA044)->bit07)
#define RFP3               (((volatile bitf_T *)0xFFFFA045)->bit04)
#define CTP3               (((volatile bitf_T *)0xFFFFA045)->bit07)
#define ICP4               (*(volatile unsigned short *)0xFFFFA046)
#define ICP4L              (*(volatile unsigned char  *)0xFFFFA046)
#define ICP4H              (*(volatile unsigned char  *)0xFFFFA047)
#define P0P4               (((volatile bitf_T *)0xFFFFA046)->bit00)
#define P1P4               (((volatile bitf_T *)0xFFFFA046)->bit01)
#define P2P4               (((volatile bitf_T *)0xFFFFA046)->bit02)
#define TBP4               (((volatile bitf_T *)0xFFFFA046)->bit06)
#define MKP4               (((volatile bitf_T *)0xFFFFA046)->bit07)
#define RFP4               (((volatile bitf_T *)0xFFFFA047)->bit04)
#define CTP4               (((volatile bitf_T *)0xFFFFA047)->bit07)
#define ICP5               (*(volatile unsigned short *)0xFFFFA048)
#define ICP5L              (*(volatile unsigned char  *)0xFFFFA048)
#define ICP5H              (*(volatile unsigned char  *)0xFFFFA049)
#define P0P5               (((volatile bitf_T *)0xFFFFA048)->bit00)
#define P1P5               (((volatile bitf_T *)0xFFFFA048)->bit01)
#define P2P5               (((volatile bitf_T *)0xFFFFA048)->bit02)
#define TBP5               (((volatile bitf_T *)0xFFFFA048)->bit06)
#define MKP5               (((volatile bitf_T *)0xFFFFA048)->bit07)
#define RFP5               (((volatile bitf_T *)0xFFFFA049)->bit04)
#define CTP5               (((volatile bitf_T *)0xFFFFA049)->bit07)
#define ICP10              (*(volatile unsigned short *)0xFFFFA04A)
#define ICP10L             (*(volatile unsigned char  *)0xFFFFA04A)
#define ICP10H             (*(volatile unsigned char  *)0xFFFFA04B)
#define P0P10              (((volatile bitf_T *)0xFFFFA04A)->bit00)
#define P1P10              (((volatile bitf_T *)0xFFFFA04A)->bit01)
#define P2P10              (((volatile bitf_T *)0xFFFFA04A)->bit02)
#define TBP10              (((volatile bitf_T *)0xFFFFA04A)->bit06)
#define MKP10              (((volatile bitf_T *)0xFFFFA04A)->bit07)
#define RFP10              (((volatile bitf_T *)0xFFFFA04B)->bit04)
#define CTP10              (((volatile bitf_T *)0xFFFFA04B)->bit07)
#define ICP11              (*(volatile unsigned short *)0xFFFFA04C)
#define ICP11L             (*(volatile unsigned char  *)0xFFFFA04C)
#define ICP11H             (*(volatile unsigned char  *)0xFFFFA04D)
#define P0P11              (((volatile bitf_T *)0xFFFFA04C)->bit00)
#define P1P11              (((volatile bitf_T *)0xFFFFA04C)->bit01)
#define P2P11              (((volatile bitf_T *)0xFFFFA04C)->bit02)
#define TBP11              (((volatile bitf_T *)0xFFFFA04C)->bit06)
#define MKP11              (((volatile bitf_T *)0xFFFFA04C)->bit07)
#define RFP11              (((volatile bitf_T *)0xFFFFA04D)->bit04)
#define CTP11              (((volatile bitf_T *)0xFFFFA04D)->bit07)
#define ICTAUD0I1          (*(volatile unsigned short *)0xFFFFA04E)
#define ICTAUD0I1L         (*(volatile unsigned char  *)0xFFFFA04E)
#define ICTAUD0I1H         (*(volatile unsigned char  *)0xFFFFA04F)
#define P0TAUD0I1          (((volatile bitf_T *)0xFFFFA04E)->bit00)
#define P1TAUD0I1          (((volatile bitf_T *)0xFFFFA04E)->bit01)
#define P2TAUD0I1          (((volatile bitf_T *)0xFFFFA04E)->bit02)
#define TBTAUD0I1          (((volatile bitf_T *)0xFFFFA04E)->bit06)
#define MKTAUD0I1          (((volatile bitf_T *)0xFFFFA04E)->bit07)
#define RFTAUD0I1          (((volatile bitf_T *)0xFFFFA04F)->bit04)
#define CTTAUD0I1          (((volatile bitf_T *)0xFFFFA04F)->bit07)
#define ICTAUD0I3          (*(volatile unsigned short *)0xFFFFA050)
#define ICTAUD0I3L         (*(volatile unsigned char  *)0xFFFFA050)
#define ICTAUD0I3H         (*(volatile unsigned char  *)0xFFFFA051)
#define P0TAUD0I3          (((volatile bitf_T *)0xFFFFA050)->bit00)
#define P1TAUD0I3          (((volatile bitf_T *)0xFFFFA050)->bit01)
#define P2TAUD0I3          (((volatile bitf_T *)0xFFFFA050)->bit02)
#define TBTAUD0I3          (((volatile bitf_T *)0xFFFFA050)->bit06)
#define MKTAUD0I3          (((volatile bitf_T *)0xFFFFA050)->bit07)
#define RFTAUD0I3          (((volatile bitf_T *)0xFFFFA051)->bit04)
#define CTTAUD0I3          (((volatile bitf_T *)0xFFFFA051)->bit07)
#define ICTAUD0I5          (*(volatile unsigned short *)0xFFFFA052)
#define ICTAUD0I5L         (*(volatile unsigned char  *)0xFFFFA052)
#define ICTAUD0I5H         (*(volatile unsigned char  *)0xFFFFA053)
#define P0TAUD0I5          (((volatile bitf_T *)0xFFFFA052)->bit00)
#define P1TAUD0I5          (((volatile bitf_T *)0xFFFFA052)->bit01)
#define P2TAUD0I5          (((volatile bitf_T *)0xFFFFA052)->bit02)
#define TBTAUD0I5          (((volatile bitf_T *)0xFFFFA052)->bit06)
#define MKTAUD0I5          (((volatile bitf_T *)0xFFFFA052)->bit07)
#define RFTAUD0I5          (((volatile bitf_T *)0xFFFFA053)->bit04)
#define CTTAUD0I5          (((volatile bitf_T *)0xFFFFA053)->bit07)
#define ICTAUD0I7          (*(volatile unsigned short *)0xFFFFA054)
#define ICTAUD0I7L         (*(volatile unsigned char  *)0xFFFFA054)
#define ICTAUD0I7H         (*(volatile unsigned char  *)0xFFFFA055)
#define P0TAUD0I7          (((volatile bitf_T *)0xFFFFA054)->bit00)
#define P1TAUD0I7          (((volatile bitf_T *)0xFFFFA054)->bit01)
#define P2TAUD0I7          (((volatile bitf_T *)0xFFFFA054)->bit02)
#define TBTAUD0I7          (((volatile bitf_T *)0xFFFFA054)->bit06)
#define MKTAUD0I7          (((volatile bitf_T *)0xFFFFA054)->bit07)
#define RFTAUD0I7          (((volatile bitf_T *)0xFFFFA055)->bit04)
#define CTTAUD0I7          (((volatile bitf_T *)0xFFFFA055)->bit07)
#define ICTAUD0I9          (*(volatile unsigned short *)0xFFFFA056)
#define ICTAUD0I9L         (*(volatile unsigned char  *)0xFFFFA056)
#define ICTAUD0I9H         (*(volatile unsigned char  *)0xFFFFA057)
#define P0TAUD0I9          (((volatile bitf_T *)0xFFFFA056)->bit00)
#define P1TAUD0I9          (((volatile bitf_T *)0xFFFFA056)->bit01)
#define P2TAUD0I9          (((volatile bitf_T *)0xFFFFA056)->bit02)
#define TBTAUD0I9          (((volatile bitf_T *)0xFFFFA056)->bit06)
#define MKTAUD0I9          (((volatile bitf_T *)0xFFFFA056)->bit07)
#define RFTAUD0I9          (((volatile bitf_T *)0xFFFFA057)->bit04)
#define CTTAUD0I9          (((volatile bitf_T *)0xFFFFA057)->bit07)
#define ICTAUD0I11         (*(volatile unsigned short *)0xFFFFA058)
#define ICTAUD0I11L        (*(volatile unsigned char  *)0xFFFFA058)
#define ICTAUD0I11H        (*(volatile unsigned char  *)0xFFFFA059)
#define P0TAUD0I11         (((volatile bitf_T *)0xFFFFA058)->bit00)
#define P1TAUD0I11         (((volatile bitf_T *)0xFFFFA058)->bit01)
#define P2TAUD0I11         (((volatile bitf_T *)0xFFFFA058)->bit02)
#define TBTAUD0I11         (((volatile bitf_T *)0xFFFFA058)->bit06)
#define MKTAUD0I11         (((volatile bitf_T *)0xFFFFA058)->bit07)
#define RFTAUD0I11         (((volatile bitf_T *)0xFFFFA059)->bit04)
#define CTTAUD0I11         (((volatile bitf_T *)0xFFFFA059)->bit07)
#define ICTAUD0I13         (*(volatile unsigned short *)0xFFFFA05A)
#define ICTAUD0I13L        (*(volatile unsigned char  *)0xFFFFA05A)
#define ICTAUD0I13H        (*(volatile unsigned char  *)0xFFFFA05B)
#define P0TAUD0I13         (((volatile bitf_T *)0xFFFFA05A)->bit00)
#define P1TAUD0I13         (((volatile bitf_T *)0xFFFFA05A)->bit01)
#define P2TAUD0I13         (((volatile bitf_T *)0xFFFFA05A)->bit02)
#define TBTAUD0I13         (((volatile bitf_T *)0xFFFFA05A)->bit06)
#define MKTAUD0I13         (((volatile bitf_T *)0xFFFFA05A)->bit07)
#define RFTAUD0I13         (((volatile bitf_T *)0xFFFFA05B)->bit04)
#define CTTAUD0I13         (((volatile bitf_T *)0xFFFFA05B)->bit07)
#define ICTAUD0I15         (*(volatile unsigned short *)0xFFFFA05C)
#define ICTAUD0I15L        (*(volatile unsigned char  *)0xFFFFA05C)
#define ICTAUD0I15H        (*(volatile unsigned char  *)0xFFFFA05D)
#define P0TAUD0I15         (((volatile bitf_T *)0xFFFFA05C)->bit00)
#define P1TAUD0I15         (((volatile bitf_T *)0xFFFFA05C)->bit01)
#define P2TAUD0I15         (((volatile bitf_T *)0xFFFFA05C)->bit02)
#define TBTAUD0I15         (((volatile bitf_T *)0xFFFFA05C)->bit06)
#define MKTAUD0I15         (((volatile bitf_T *)0xFFFFA05C)->bit07)
#define RFTAUD0I15         (((volatile bitf_T *)0xFFFFA05D)->bit04)
#define CTTAUD0I15         (((volatile bitf_T *)0xFFFFA05D)->bit07)
#define ICADCA0ERR         (*(volatile unsigned short *)0xFFFFA05E)
#define ICADCA0ERRL        (*(volatile unsigned char  *)0xFFFFA05E)
#define ICADCA0ERRH        (*(volatile unsigned char  *)0xFFFFA05F)
#define P0ADCA0ERR         (((volatile bitf_T *)0xFFFFA05E)->bit00)
#define P1ADCA0ERR         (((volatile bitf_T *)0xFFFFA05E)->bit01)
#define P2ADCA0ERR         (((volatile bitf_T *)0xFFFFA05E)->bit02)
#define TBADCA0ERR         (((volatile bitf_T *)0xFFFFA05E)->bit06)
#define MKADCA0ERR         (((volatile bitf_T *)0xFFFFA05E)->bit07)
#define RFADCA0ERR         (((volatile bitf_T *)0xFFFFA05F)->bit04)
#define CTADCA0ERR         (((volatile bitf_T *)0xFFFFA05F)->bit07)
#define ICCSIG0IRE         (*(volatile unsigned short *)0xFFFFA062)
#define ICCSIG0IREL        (*(volatile unsigned char  *)0xFFFFA062)
#define ICCSIG0IREH        (*(volatile unsigned char  *)0xFFFFA063)
#define P0CSIG0IRE         (((volatile bitf_T *)0xFFFFA062)->bit00)
#define P1CSIG0IRE         (((volatile bitf_T *)0xFFFFA062)->bit01)
#define P2CSIG0IRE         (((volatile bitf_T *)0xFFFFA062)->bit02)
#define TBCSIG0IRE         (((volatile bitf_T *)0xFFFFA062)->bit06)
#define MKCSIG0IRE         (((volatile bitf_T *)0xFFFFA062)->bit07)
#define RFCSIG0IRE         (((volatile bitf_T *)0xFFFFA063)->bit04)
#define CTCSIG0IRE         (((volatile bitf_T *)0xFFFFA063)->bit07)
#define ICRLIN20           (*(volatile unsigned short *)0xFFFFA064)
#define ICRLIN20L          (*(volatile unsigned char  *)0xFFFFA064)
#define ICRLIN20H          (*(volatile unsigned char  *)0xFFFFA065)
#define P0RLIN20           (((volatile bitf_T *)0xFFFFA064)->bit00)
#define P1RLIN20           (((volatile bitf_T *)0xFFFFA064)->bit01)
#define P2RLIN20           (((volatile bitf_T *)0xFFFFA064)->bit02)
#define TBRLIN20           (((volatile bitf_T *)0xFFFFA064)->bit06)
#define MKRLIN20           (((volatile bitf_T *)0xFFFFA064)->bit07)
#define RFRLIN20           (((volatile bitf_T *)0xFFFFA065)->bit04)
#define CTRLIN20           (((volatile bitf_T *)0xFFFFA065)->bit07)
#define ICRLIN21           (*(volatile unsigned short *)0xFFFFA066)
#define ICRLIN21L          (*(volatile unsigned char  *)0xFFFFA066)
#define ICRLIN21H          (*(volatile unsigned char  *)0xFFFFA067)
#define P0RLIN21           (((volatile bitf_T *)0xFFFFA066)->bit00)
#define P1RLIN21           (((volatile bitf_T *)0xFFFFA066)->bit01)
#define P2RLIN21           (((volatile bitf_T *)0xFFFFA066)->bit02)
#define TBRLIN21           (((volatile bitf_T *)0xFFFFA066)->bit06)
#define MKRLIN21           (((volatile bitf_T *)0xFFFFA066)->bit07)
#define RFRLIN21           (((volatile bitf_T *)0xFFFFA067)->bit04)
#define CTRLIN21           (((volatile bitf_T *)0xFFFFA067)->bit07)
#define ICDMA0             (*(volatile unsigned short *)0xFFFFA068)
#define ICDMA0L            (*(volatile unsigned char  *)0xFFFFA068)
#define ICDMA0H            (*(volatile unsigned char  *)0xFFFFA069)
#define P0DMA0             (((volatile bitf_T *)0xFFFFA068)->bit00)
#define P1DMA0             (((volatile bitf_T *)0xFFFFA068)->bit01)
#define P2DMA0             (((volatile bitf_T *)0xFFFFA068)->bit02)
#define TBDMA0             (((volatile bitf_T *)0xFFFFA068)->bit06)
#define MKDMA0             (((volatile bitf_T *)0xFFFFA068)->bit07)
#define RFDMA0             (((volatile bitf_T *)0xFFFFA069)->bit04)
#define CTDMA0             (((volatile bitf_T *)0xFFFFA069)->bit07)
#define ICDMA1             (*(volatile unsigned short *)0xFFFFA06A)
#define ICDMA1L            (*(volatile unsigned char  *)0xFFFFA06A)
#define ICDMA1H            (*(volatile unsigned char  *)0xFFFFA06B)
#define P0DMA1             (((volatile bitf_T *)0xFFFFA06A)->bit00)
#define P1DMA1             (((volatile bitf_T *)0xFFFFA06A)->bit01)
#define P2DMA1             (((volatile bitf_T *)0xFFFFA06A)->bit02)
#define TBDMA1             (((volatile bitf_T *)0xFFFFA06A)->bit06)
#define MKDMA1             (((volatile bitf_T *)0xFFFFA06A)->bit07)
#define RFDMA1             (((volatile bitf_T *)0xFFFFA06B)->bit04)
#define CTDMA1             (((volatile bitf_T *)0xFFFFA06B)->bit07)
#define ICDMA2             (*(volatile unsigned short *)0xFFFFA06C)
#define ICDMA2L            (*(volatile unsigned char  *)0xFFFFA06C)
#define ICDMA2H            (*(volatile unsigned char  *)0xFFFFA06D)
#define P0DMA2             (((volatile bitf_T *)0xFFFFA06C)->bit00)
#define P1DMA2             (((volatile bitf_T *)0xFFFFA06C)->bit01)
#define P2DMA2             (((volatile bitf_T *)0xFFFFA06C)->bit02)
#define TBDMA2             (((volatile bitf_T *)0xFFFFA06C)->bit06)
#define MKDMA2             (((volatile bitf_T *)0xFFFFA06C)->bit07)
#define RFDMA2             (((volatile bitf_T *)0xFFFFA06D)->bit04)
#define CTDMA2             (((volatile bitf_T *)0xFFFFA06D)->bit07)
#define ICDMA3             (*(volatile unsigned short *)0xFFFFA06E)
#define ICDMA3L            (*(volatile unsigned char  *)0xFFFFA06E)
#define ICDMA3H            (*(volatile unsigned char  *)0xFFFFA06F)
#define P0DMA3             (((volatile bitf_T *)0xFFFFA06E)->bit00)
#define P1DMA3             (((volatile bitf_T *)0xFFFFA06E)->bit01)
#define P2DMA3             (((volatile bitf_T *)0xFFFFA06E)->bit02)
#define TBDMA3             (((volatile bitf_T *)0xFFFFA06E)->bit06)
#define MKDMA3             (((volatile bitf_T *)0xFFFFA06E)->bit07)
#define RFDMA3             (((volatile bitf_T *)0xFFFFA06F)->bit04)
#define CTDMA3             (((volatile bitf_T *)0xFFFFA06F)->bit07)
#define ICDMA4             (*(volatile unsigned short *)0xFFFFA070)
#define ICDMA4L            (*(volatile unsigned char  *)0xFFFFA070)
#define ICDMA4H            (*(volatile unsigned char  *)0xFFFFA071)
#define P0DMA4             (((volatile bitf_T *)0xFFFFA070)->bit00)
#define P1DMA4             (((volatile bitf_T *)0xFFFFA070)->bit01)
#define P2DMA4             (((volatile bitf_T *)0xFFFFA070)->bit02)
#define TBDMA4             (((volatile bitf_T *)0xFFFFA070)->bit06)
#define MKDMA4             (((volatile bitf_T *)0xFFFFA070)->bit07)
#define RFDMA4             (((volatile bitf_T *)0xFFFFA071)->bit04)
#define CTDMA4             (((volatile bitf_T *)0xFFFFA071)->bit07)
#define ICDMA5             (*(volatile unsigned short *)0xFFFFA072)
#define ICDMA5L            (*(volatile unsigned char  *)0xFFFFA072)
#define ICDMA5H            (*(volatile unsigned char  *)0xFFFFA073)
#define P0DMA5             (((volatile bitf_T *)0xFFFFA072)->bit00)
#define P1DMA5             (((volatile bitf_T *)0xFFFFA072)->bit01)
#define P2DMA5             (((volatile bitf_T *)0xFFFFA072)->bit02)
#define TBDMA5             (((volatile bitf_T *)0xFFFFA072)->bit06)
#define MKDMA5             (((volatile bitf_T *)0xFFFFA072)->bit07)
#define RFDMA5             (((volatile bitf_T *)0xFFFFA073)->bit04)
#define CTDMA5             (((volatile bitf_T *)0xFFFFA073)->bit07)
#define ICDMA6             (*(volatile unsigned short *)0xFFFFA074)
#define ICDMA6L            (*(volatile unsigned char  *)0xFFFFA074)
#define ICDMA6H            (*(volatile unsigned char  *)0xFFFFA075)
#define P0DMA6             (((volatile bitf_T *)0xFFFFA074)->bit00)
#define P1DMA6             (((volatile bitf_T *)0xFFFFA074)->bit01)
#define P2DMA6             (((volatile bitf_T *)0xFFFFA074)->bit02)
#define TBDMA6             (((volatile bitf_T *)0xFFFFA074)->bit06)
#define MKDMA6             (((volatile bitf_T *)0xFFFFA074)->bit07)
#define RFDMA6             (((volatile bitf_T *)0xFFFFA075)->bit04)
#define CTDMA6             (((volatile bitf_T *)0xFFFFA075)->bit07)
#define ICDMA7             (*(volatile unsigned short *)0xFFFFA076)
#define ICDMA7L            (*(volatile unsigned char  *)0xFFFFA076)
#define ICDMA7H            (*(volatile unsigned char  *)0xFFFFA077)
#define P0DMA7             (((volatile bitf_T *)0xFFFFA076)->bit00)
#define P1DMA7             (((volatile bitf_T *)0xFFFFA076)->bit01)
#define P2DMA7             (((volatile bitf_T *)0xFFFFA076)->bit02)
#define TBDMA7             (((volatile bitf_T *)0xFFFFA076)->bit06)
#define MKDMA7             (((volatile bitf_T *)0xFFFFA076)->bit07)
#define RFDMA7             (((volatile bitf_T *)0xFFFFA077)->bit04)
#define CTDMA7             (((volatile bitf_T *)0xFFFFA077)->bit07)
#define ICDMA8             (*(volatile unsigned short *)0xFFFFA078)
#define ICDMA8L            (*(volatile unsigned char  *)0xFFFFA078)
#define ICDMA8H            (*(volatile unsigned char  *)0xFFFFA079)
#define P0DMA8             (((volatile bitf_T *)0xFFFFA078)->bit00)
#define P1DMA8             (((volatile bitf_T *)0xFFFFA078)->bit01)
#define P2DMA8             (((volatile bitf_T *)0xFFFFA078)->bit02)
#define TBDMA8             (((volatile bitf_T *)0xFFFFA078)->bit06)
#define MKDMA8             (((volatile bitf_T *)0xFFFFA078)->bit07)
#define RFDMA8             (((volatile bitf_T *)0xFFFFA079)->bit04)
#define CTDMA8             (((volatile bitf_T *)0xFFFFA079)->bit07)
#define ICDMA9             (*(volatile unsigned short *)0xFFFFA07A)
#define ICDMA9L            (*(volatile unsigned char  *)0xFFFFA07A)
#define ICDMA9H            (*(volatile unsigned char  *)0xFFFFA07B)
#define P0DMA9             (((volatile bitf_T *)0xFFFFA07A)->bit00)
#define P1DMA9             (((volatile bitf_T *)0xFFFFA07A)->bit01)
#define P2DMA9             (((volatile bitf_T *)0xFFFFA07A)->bit02)
#define TBDMA9             (((volatile bitf_T *)0xFFFFA07A)->bit06)
#define MKDMA9             (((volatile bitf_T *)0xFFFFA07A)->bit07)
#define RFDMA9             (((volatile bitf_T *)0xFFFFA07B)->bit04)
#define CTDMA9             (((volatile bitf_T *)0xFFFFA07B)->bit07)
#define ICDMA10            (*(volatile unsigned short *)0xFFFFA07C)
#define ICDMA10L           (*(volatile unsigned char  *)0xFFFFA07C)
#define ICDMA10H           (*(volatile unsigned char  *)0xFFFFA07D)
#define P0DMA10            (((volatile bitf_T *)0xFFFFA07C)->bit00)
#define P1DMA10            (((volatile bitf_T *)0xFFFFA07C)->bit01)
#define P2DMA10            (((volatile bitf_T *)0xFFFFA07C)->bit02)
#define TBDMA10            (((volatile bitf_T *)0xFFFFA07C)->bit06)
#define MKDMA10            (((volatile bitf_T *)0xFFFFA07C)->bit07)
#define RFDMA10            (((volatile bitf_T *)0xFFFFA07D)->bit04)
#define CTDMA10            (((volatile bitf_T *)0xFFFFA07D)->bit07)
#define ICDMA11            (*(volatile unsigned short *)0xFFFFA07E)
#define ICDMA11L           (*(volatile unsigned char  *)0xFFFFA07E)
#define ICDMA11H           (*(volatile unsigned char  *)0xFFFFA07F)
#define P0DMA11            (((volatile bitf_T *)0xFFFFA07E)->bit00)
#define P1DMA11            (((volatile bitf_T *)0xFFFFA07E)->bit01)
#define P2DMA11            (((volatile bitf_T *)0xFFFFA07E)->bit02)
#define TBDMA11            (((volatile bitf_T *)0xFFFFA07E)->bit06)
#define MKDMA11            (((volatile bitf_T *)0xFFFFA07E)->bit07)
#define RFDMA11            (((volatile bitf_T *)0xFFFFA07F)->bit04)
#define CTDMA11            (((volatile bitf_T *)0xFFFFA07F)->bit07)
#define ICDMA12            (*(volatile unsigned short *)0xFFFFA080)
#define ICDMA12L           (*(volatile unsigned char  *)0xFFFFA080)
#define ICDMA12H           (*(volatile unsigned char  *)0xFFFFA081)
#define P0DMA12            (((volatile bitf_T *)0xFFFFA080)->bit00)
#define P1DMA12            (((volatile bitf_T *)0xFFFFA080)->bit01)
#define P2DMA12            (((volatile bitf_T *)0xFFFFA080)->bit02)
#define TBDMA12            (((volatile bitf_T *)0xFFFFA080)->bit06)
#define MKDMA12            (((volatile bitf_T *)0xFFFFA080)->bit07)
#define RFDMA12            (((volatile bitf_T *)0xFFFFA081)->bit04)
#define CTDMA12            (((volatile bitf_T *)0xFFFFA081)->bit07)
#define ICDMA13            (*(volatile unsigned short *)0xFFFFA082)
#define ICDMA13L           (*(volatile unsigned char  *)0xFFFFA082)
#define ICDMA13H           (*(volatile unsigned char  *)0xFFFFA083)
#define P0DMA13            (((volatile bitf_T *)0xFFFFA082)->bit00)
#define P1DMA13            (((volatile bitf_T *)0xFFFFA082)->bit01)
#define P2DMA13            (((volatile bitf_T *)0xFFFFA082)->bit02)
#define TBDMA13            (((volatile bitf_T *)0xFFFFA082)->bit06)
#define MKDMA13            (((volatile bitf_T *)0xFFFFA082)->bit07)
#define RFDMA13            (((volatile bitf_T *)0xFFFFA083)->bit04)
#define CTDMA13            (((volatile bitf_T *)0xFFFFA083)->bit07)
#define ICDMA14            (*(volatile unsigned short *)0xFFFFA084)
#define ICDMA14L           (*(volatile unsigned char  *)0xFFFFA084)
#define ICDMA14H           (*(volatile unsigned char  *)0xFFFFA085)
#define P0DMA14            (((volatile bitf_T *)0xFFFFA084)->bit00)
#define P1DMA14            (((volatile bitf_T *)0xFFFFA084)->bit01)
#define P2DMA14            (((volatile bitf_T *)0xFFFFA084)->bit02)
#define TBDMA14            (((volatile bitf_T *)0xFFFFA084)->bit06)
#define MKDMA14            (((volatile bitf_T *)0xFFFFA084)->bit07)
#define RFDMA14            (((volatile bitf_T *)0xFFFFA085)->bit04)
#define CTDMA14            (((volatile bitf_T *)0xFFFFA085)->bit07)
#define ICDMA15            (*(volatile unsigned short *)0xFFFFA086)
#define ICDMA15L           (*(volatile unsigned char  *)0xFFFFA086)
#define ICDMA15H           (*(volatile unsigned char  *)0xFFFFA087)
#define P0DMA15            (((volatile bitf_T *)0xFFFFA086)->bit00)
#define P1DMA15            (((volatile bitf_T *)0xFFFFA086)->bit01)
#define P2DMA15            (((volatile bitf_T *)0xFFFFA086)->bit02)
#define TBDMA15            (((volatile bitf_T *)0xFFFFA086)->bit06)
#define MKDMA15            (((volatile bitf_T *)0xFFFFA086)->bit07)
#define RFDMA15            (((volatile bitf_T *)0xFFFFA087)->bit04)
#define CTDMA15            (((volatile bitf_T *)0xFFFFA087)->bit07)
#define ICRIIC0TI          (*(volatile unsigned short *)0xFFFFA088)
#define ICRIIC0TIL         (*(volatile unsigned char  *)0xFFFFA088)
#define ICRIIC0TIH         (*(volatile unsigned char  *)0xFFFFA089)
#define P0RIIC0TI          (((volatile bitf_T *)0xFFFFA088)->bit00)
#define P1RIIC0TI          (((volatile bitf_T *)0xFFFFA088)->bit01)
#define P2RIIC0TI          (((volatile bitf_T *)0xFFFFA088)->bit02)
#define TBRIIC0TI          (((volatile bitf_T *)0xFFFFA088)->bit06)
#define MKRIIC0TI          (((volatile bitf_T *)0xFFFFA088)->bit07)
#define RFRIIC0TI          (((volatile bitf_T *)0xFFFFA089)->bit04)
#define CTRIIC0TI          (((volatile bitf_T *)0xFFFFA089)->bit07)
#define ICRIIC0TEI         (*(volatile unsigned short *)0xFFFFA08A)
#define ICRIIC0TEIL        (*(volatile unsigned char  *)0xFFFFA08A)
#define ICRIIC0TEIH        (*(volatile unsigned char  *)0xFFFFA08B)
#define P0RIIC0TEI         (((volatile bitf_T *)0xFFFFA08A)->bit00)
#define P1RIIC0TEI         (((volatile bitf_T *)0xFFFFA08A)->bit01)
#define P2RIIC0TEI         (((volatile bitf_T *)0xFFFFA08A)->bit02)
#define TBRIIC0TEI         (((volatile bitf_T *)0xFFFFA08A)->bit06)
#define MKRIIC0TEI         (((volatile bitf_T *)0xFFFFA08A)->bit07)
#define RFRIIC0TEI         (((volatile bitf_T *)0xFFFFA08B)->bit04)
#define CTRIIC0TEI         (((volatile bitf_T *)0xFFFFA08B)->bit07)
#define ICRIIC0RI          (*(volatile unsigned short *)0xFFFFA08C)
#define ICRIIC0RIL         (*(volatile unsigned char  *)0xFFFFA08C)
#define ICRIIC0RIH         (*(volatile unsigned char  *)0xFFFFA08D)
#define P0RIIC0RI          (((volatile bitf_T *)0xFFFFA08C)->bit00)
#define P1RIIC0RI          (((volatile bitf_T *)0xFFFFA08C)->bit01)
#define P2RIIC0RI          (((volatile bitf_T *)0xFFFFA08C)->bit02)
#define TBRIIC0RI          (((volatile bitf_T *)0xFFFFA08C)->bit06)
#define MKRIIC0RI          (((volatile bitf_T *)0xFFFFA08C)->bit07)
#define RFRIIC0RI          (((volatile bitf_T *)0xFFFFA08D)->bit04)
#define CTRIIC0RI          (((volatile bitf_T *)0xFFFFA08D)->bit07)
#define ICRIIC0EE          (*(volatile unsigned short *)0xFFFFA08E)
#define ICRIIC0EEL         (*(volatile unsigned char  *)0xFFFFA08E)
#define ICRIIC0EEH         (*(volatile unsigned char  *)0xFFFFA08F)
#define P0RIIC0EE          (((volatile bitf_T *)0xFFFFA08E)->bit00)
#define P1RIIC0EE          (((volatile bitf_T *)0xFFFFA08E)->bit01)
#define P2RIIC0EE          (((volatile bitf_T *)0xFFFFA08E)->bit02)
#define TBRIIC0EE          (((volatile bitf_T *)0xFFFFA08E)->bit06)
#define MKRIIC0EE          (((volatile bitf_T *)0xFFFFA08E)->bit07)
#define RFRIIC0EE          (((volatile bitf_T *)0xFFFFA08F)->bit04)
#define CTRIIC0EE          (((volatile bitf_T *)0xFFFFA08F)->bit07)
#define ICTAUJ0I0          (*(volatile unsigned short *)0xFFFFA090)
#define ICTAUJ0I0L         (*(volatile unsigned char  *)0xFFFFA090)
#define ICTAUJ0I0H         (*(volatile unsigned char  *)0xFFFFA091)
#define P0TAUJ0I0          (((volatile bitf_T *)0xFFFFA090)->bit00)
#define P1TAUJ0I0          (((volatile bitf_T *)0xFFFFA090)->bit01)
#define P2TAUJ0I0          (((volatile bitf_T *)0xFFFFA090)->bit02)
#define TBTAUJ0I0          (((volatile bitf_T *)0xFFFFA090)->bit06)
#define MKTAUJ0I0          (((volatile bitf_T *)0xFFFFA090)->bit07)
#define RFTAUJ0I0          (((volatile bitf_T *)0xFFFFA091)->bit04)
#define CTTAUJ0I0          (((volatile bitf_T *)0xFFFFA091)->bit07)
#define ICTAUJ0I1          (*(volatile unsigned short *)0xFFFFA092)
#define ICTAUJ0I1L         (*(volatile unsigned char  *)0xFFFFA092)
#define ICTAUJ0I1H         (*(volatile unsigned char  *)0xFFFFA093)
#define P0TAUJ0I1          (((volatile bitf_T *)0xFFFFA092)->bit00)
#define P1TAUJ0I1          (((volatile bitf_T *)0xFFFFA092)->bit01)
#define P2TAUJ0I1          (((volatile bitf_T *)0xFFFFA092)->bit02)
#define TBTAUJ0I1          (((volatile bitf_T *)0xFFFFA092)->bit06)
#define MKTAUJ0I1          (((volatile bitf_T *)0xFFFFA092)->bit07)
#define RFTAUJ0I1          (((volatile bitf_T *)0xFFFFA093)->bit04)
#define CTTAUJ0I1          (((volatile bitf_T *)0xFFFFA093)->bit07)
#define ICTAUJ0I2          (*(volatile unsigned short *)0xFFFFA094)
#define ICTAUJ0I2L         (*(volatile unsigned char  *)0xFFFFA094)
#define ICTAUJ0I2H         (*(volatile unsigned char  *)0xFFFFA095)
#define P0TAUJ0I2          (((volatile bitf_T *)0xFFFFA094)->bit00)
#define P1TAUJ0I2          (((volatile bitf_T *)0xFFFFA094)->bit01)
#define P2TAUJ0I2          (((volatile bitf_T *)0xFFFFA094)->bit02)
#define TBTAUJ0I2          (((volatile bitf_T *)0xFFFFA094)->bit06)
#define MKTAUJ0I2          (((volatile bitf_T *)0xFFFFA094)->bit07)
#define RFTAUJ0I2          (((volatile bitf_T *)0xFFFFA095)->bit04)
#define CTTAUJ0I2          (((volatile bitf_T *)0xFFFFA095)->bit07)
#define ICTAUJ0I3          (*(volatile unsigned short *)0xFFFFA096)
#define ICTAUJ0I3L         (*(volatile unsigned char  *)0xFFFFA096)
#define ICTAUJ0I3H         (*(volatile unsigned char  *)0xFFFFA097)
#define P0TAUJ0I3          (((volatile bitf_T *)0xFFFFA096)->bit00)
#define P1TAUJ0I3          (((volatile bitf_T *)0xFFFFA096)->bit01)
#define P2TAUJ0I3          (((volatile bitf_T *)0xFFFFA096)->bit02)
#define TBTAUJ0I3          (((volatile bitf_T *)0xFFFFA096)->bit06)
#define MKTAUJ0I3          (((volatile bitf_T *)0xFFFFA096)->bit07)
#define RFTAUJ0I3          (((volatile bitf_T *)0xFFFFA097)->bit04)
#define CTTAUJ0I3          (((volatile bitf_T *)0xFFFFA097)->bit07)
#define ICOSTM0            (*(volatile unsigned short *)0xFFFFA098)
#define ICOSTM0L           (*(volatile unsigned char  *)0xFFFFA098)
#define ICOSTM0H           (*(volatile unsigned char  *)0xFFFFA099)
#define P0OSTM0            (((volatile bitf_T *)0xFFFFA098)->bit00)
#define P1OSTM0            (((volatile bitf_T *)0xFFFFA098)->bit01)
#define P2OSTM0            (((volatile bitf_T *)0xFFFFA098)->bit02)
#define TBOSTM0            (((volatile bitf_T *)0xFFFFA098)->bit06)
#define MKOSTM0            (((volatile bitf_T *)0xFFFFA098)->bit07)
#define RFOSTM0            (((volatile bitf_T *)0xFFFFA099)->bit04)
#define CTOSTM0            (((volatile bitf_T *)0xFFFFA099)->bit07)
#define ICENCA0IOV         (*(volatile unsigned short *)0xFFFFA09A)
#define ICPWGA4            (*(volatile unsigned short *)0xFFFFA09A)
#define ICENCA0IOVL        (*(volatile unsigned char  *)0xFFFFA09A)
#define ICPWGA4L           (*(volatile unsigned char  *)0xFFFFA09A)
#define ICENCA0IOVH        (*(volatile unsigned char  *)0xFFFFA09B)
#define ICPWGA4H           (*(volatile unsigned char  *)0xFFFFA09B)
#define P0ENCA0IOV         (((volatile bitf_T *)0xFFFFA09A)->bit00)
#define P0PWGA4            (((volatile bitf_T *)0xFFFFA09A)->bit00)
#define P1ENCA0IOV         (((volatile bitf_T *)0xFFFFA09A)->bit01)
#define P1PWGA4            (((volatile bitf_T *)0xFFFFA09A)->bit01)
#define P2ENCA0IOV         (((volatile bitf_T *)0xFFFFA09A)->bit02)
#define P2PWGA4            (((volatile bitf_T *)0xFFFFA09A)->bit02)
#define TBENCA0IOV         (((volatile bitf_T *)0xFFFFA09A)->bit06)
#define TBPWGA4            (((volatile bitf_T *)0xFFFFA09A)->bit06)
#define MKENCA0IOV         (((volatile bitf_T *)0xFFFFA09A)->bit07)
#define MKPWGA4            (((volatile bitf_T *)0xFFFFA09A)->bit07)
#define RFENCA0IOV         (((volatile bitf_T *)0xFFFFA09B)->bit04)
#define RFPWGA4            (((volatile bitf_T *)0xFFFFA09B)->bit04)
#define CTENCA0IOV         (((volatile bitf_T *)0xFFFFA09B)->bit07)
#define CTPWGA4            (((volatile bitf_T *)0xFFFFA09B)->bit07)
#define ICENCA0IUD         (*(volatile unsigned short *)0xFFFFA09C)
#define ICPWGA5            (*(volatile unsigned short *)0xFFFFA09C)
#define ICENCA0IUDL        (*(volatile unsigned char  *)0xFFFFA09C)
#define ICPWGA5L           (*(volatile unsigned char  *)0xFFFFA09C)
#define ICENCA0IUDH        (*(volatile unsigned char  *)0xFFFFA09D)
#define ICPWGA5H           (*(volatile unsigned char  *)0xFFFFA09D)
#define P0ENCA0IUD         (((volatile bitf_T *)0xFFFFA09C)->bit00)
#define P0PWGA5            (((volatile bitf_T *)0xFFFFA09C)->bit00)
#define P1ENCA0IUD         (((volatile bitf_T *)0xFFFFA09C)->bit01)
#define P1PWGA5            (((volatile bitf_T *)0xFFFFA09C)->bit01)
#define P2ENCA0IUD         (((volatile bitf_T *)0xFFFFA09C)->bit02)
#define P2PWGA5            (((volatile bitf_T *)0xFFFFA09C)->bit02)
#define TBENCA0IUD         (((volatile bitf_T *)0xFFFFA09C)->bit06)
#define TBPWGA5            (((volatile bitf_T *)0xFFFFA09C)->bit06)
#define MKENCA0IUD         (((volatile bitf_T *)0xFFFFA09C)->bit07)
#define MKPWGA5            (((volatile bitf_T *)0xFFFFA09C)->bit07)
#define RFENCA0IUD         (((volatile bitf_T *)0xFFFFA09D)->bit04)
#define RFPWGA5            (((volatile bitf_T *)0xFFFFA09D)->bit04)
#define CTENCA0IUD         (((volatile bitf_T *)0xFFFFA09D)->bit07)
#define CTPWGA5            (((volatile bitf_T *)0xFFFFA09D)->bit07)
#define ICENCA0I0          (*(volatile unsigned short *)0xFFFFA09E)
#define ICPWGA6            (*(volatile unsigned short *)0xFFFFA09E)
#define ICENCA0I0L         (*(volatile unsigned char  *)0xFFFFA09E)
#define ICPWGA6L           (*(volatile unsigned char  *)0xFFFFA09E)
#define ICENCA0I0H         (*(volatile unsigned char  *)0xFFFFA09F)
#define ICPWGA6H           (*(volatile unsigned char  *)0xFFFFA09F)
#define P0ENCA0I0          (((volatile bitf_T *)0xFFFFA09E)->bit00)
#define P0PWGA6            (((volatile bitf_T *)0xFFFFA09E)->bit00)
#define P1ENCA0I0          (((volatile bitf_T *)0xFFFFA09E)->bit01)
#define P1PWGA6            (((volatile bitf_T *)0xFFFFA09E)->bit01)
#define P2ENCA0I0          (((volatile bitf_T *)0xFFFFA09E)->bit02)
#define P2PWGA6            (((volatile bitf_T *)0xFFFFA09E)->bit02)
#define TBENCA0I0          (((volatile bitf_T *)0xFFFFA09E)->bit06)
#define TBPWGA6            (((volatile bitf_T *)0xFFFFA09E)->bit06)
#define MKENCA0I0          (((volatile bitf_T *)0xFFFFA09E)->bit07)
#define MKPWGA6            (((volatile bitf_T *)0xFFFFA09E)->bit07)
#define RFENCA0I0          (((volatile bitf_T *)0xFFFFA09F)->bit04)
#define RFPWGA6            (((volatile bitf_T *)0xFFFFA09F)->bit04)
#define CTENCA0I0          (((volatile bitf_T *)0xFFFFA09F)->bit07)
#define CTPWGA6            (((volatile bitf_T *)0xFFFFA09F)->bit07)
#define ICENCA0I1          (*(volatile unsigned short *)0xFFFFA0A0)
#define ICPWGA7            (*(volatile unsigned short *)0xFFFFA0A0)
#define ICENCA0I1L         (*(volatile unsigned char  *)0xFFFFA0A0)
#define ICPWGA7L           (*(volatile unsigned char  *)0xFFFFA0A0)
#define ICENCA0I1H         (*(volatile unsigned char  *)0xFFFFA0A1)
#define ICPWGA7H           (*(volatile unsigned char  *)0xFFFFA0A1)
#define P0ENCA0I1          (((volatile bitf_T *)0xFFFFA0A0)->bit00)
#define P0PWGA7            (((volatile bitf_T *)0xFFFFA0A0)->bit00)
#define P1ENCA0I1          (((volatile bitf_T *)0xFFFFA0A0)->bit01)
#define P1PWGA7            (((volatile bitf_T *)0xFFFFA0A0)->bit01)
#define P2ENCA0I1          (((volatile bitf_T *)0xFFFFA0A0)->bit02)
#define P2PWGA7            (((volatile bitf_T *)0xFFFFA0A0)->bit02)
#define TBENCA0I1          (((volatile bitf_T *)0xFFFFA0A0)->bit06)
#define TBPWGA7            (((volatile bitf_T *)0xFFFFA0A0)->bit06)
#define MKENCA0I1          (((volatile bitf_T *)0xFFFFA0A0)->bit07)
#define MKPWGA7            (((volatile bitf_T *)0xFFFFA0A0)->bit07)
#define RFENCA0I1          (((volatile bitf_T *)0xFFFFA0A1)->bit04)
#define RFPWGA7            (((volatile bitf_T *)0xFFFFA0A1)->bit04)
#define CTENCA0I1          (((volatile bitf_T *)0xFFFFA0A1)->bit07)
#define CTPWGA7            (((volatile bitf_T *)0xFFFFA0A1)->bit07)
#define ICENCA0IEC         (*(volatile unsigned short *)0xFFFFA0A2)
#define ICENCA0IECL        (*(volatile unsigned char  *)0xFFFFA0A2)
#define ICENCA0IECH        (*(volatile unsigned char  *)0xFFFFA0A3)
#define P0ENCA0IEC         (((volatile bitf_T *)0xFFFFA0A2)->bit00)
#define P1ENCA0IEC         (((volatile bitf_T *)0xFFFFA0A2)->bit01)
#define P2ENCA0IEC         (((volatile bitf_T *)0xFFFFA0A2)->bit02)
#define TBENCA0IEC         (((volatile bitf_T *)0xFFFFA0A2)->bit06)
#define MKENCA0IEC         (((volatile bitf_T *)0xFFFFA0A2)->bit07)
#define RFENCA0IEC         (((volatile bitf_T *)0xFFFFA0A3)->bit04)
#define CTENCA0IEC         (((volatile bitf_T *)0xFFFFA0A3)->bit07)
#define ICKR0              (*(volatile unsigned short *)0xFFFFA0A4)
#define ICKR0L             (*(volatile unsigned char  *)0xFFFFA0A4)
#define ICKR0H             (*(volatile unsigned char  *)0xFFFFA0A5)
#define P0KR0              (((volatile bitf_T *)0xFFFFA0A4)->bit00)
#define P1KR0              (((volatile bitf_T *)0xFFFFA0A4)->bit01)
#define P2KR0              (((volatile bitf_T *)0xFFFFA0A4)->bit02)
#define TBKR0              (((volatile bitf_T *)0xFFFFA0A4)->bit06)
#define MKKR0              (((volatile bitf_T *)0xFFFFA0A4)->bit07)
#define RFKR0              (((volatile bitf_T *)0xFFFFA0A5)->bit04)
#define CTKR0              (((volatile bitf_T *)0xFFFFA0A5)->bit07)
#define ICQFULL            (*(volatile unsigned short *)0xFFFFA0A6)
#define ICQFULLL           (*(volatile unsigned char  *)0xFFFFA0A6)
#define ICQFULLH           (*(volatile unsigned char  *)0xFFFFA0A7)
#define P0QFULL            (((volatile bitf_T *)0xFFFFA0A6)->bit00)
#define P1QFULL            (((volatile bitf_T *)0xFFFFA0A6)->bit01)
#define P2QFULL            (((volatile bitf_T *)0xFFFFA0A6)->bit02)
#define TBQFULL            (((volatile bitf_T *)0xFFFFA0A6)->bit06)
#define MKQFULL            (((volatile bitf_T *)0xFFFFA0A6)->bit07)
#define RFQFULL            (((volatile bitf_T *)0xFFFFA0A7)->bit04)
#define CTQFULL            (((volatile bitf_T *)0xFFFFA0A7)->bit07)
#define ICPWGA0            (*(volatile unsigned short *)0xFFFFA0A8)
#define ICPWGA0L           (*(volatile unsigned char  *)0xFFFFA0A8)
#define ICPWGA0H           (*(volatile unsigned char  *)0xFFFFA0A9)
#define P0PWGA0            (((volatile bitf_T *)0xFFFFA0A8)->bit00)
#define P1PWGA0            (((volatile bitf_T *)0xFFFFA0A8)->bit01)
#define P2PWGA0            (((volatile bitf_T *)0xFFFFA0A8)->bit02)
#define TBPWGA0            (((volatile bitf_T *)0xFFFFA0A8)->bit06)
#define MKPWGA0            (((volatile bitf_T *)0xFFFFA0A8)->bit07)
#define RFPWGA0            (((volatile bitf_T *)0xFFFFA0A9)->bit04)
#define CTPWGA0            (((volatile bitf_T *)0xFFFFA0A9)->bit07)
#define ICPWGA1            (*(volatile unsigned short *)0xFFFFA0AA)
#define ICPWGA1L           (*(volatile unsigned char  *)0xFFFFA0AA)
#define ICPWGA1H           (*(volatile unsigned char  *)0xFFFFA0AB)
#define P0PWGA1            (((volatile bitf_T *)0xFFFFA0AA)->bit00)
#define P1PWGA1            (((volatile bitf_T *)0xFFFFA0AA)->bit01)
#define P2PWGA1            (((volatile bitf_T *)0xFFFFA0AA)->bit02)
#define TBPWGA1            (((volatile bitf_T *)0xFFFFA0AA)->bit06)
#define MKPWGA1            (((volatile bitf_T *)0xFFFFA0AA)->bit07)
#define RFPWGA1            (((volatile bitf_T *)0xFFFFA0AB)->bit04)
#define CTPWGA1            (((volatile bitf_T *)0xFFFFA0AB)->bit07)
#define ICPWGA2            (*(volatile unsigned short *)0xFFFFA0AC)
#define ICPWGA2L           (*(volatile unsigned char  *)0xFFFFA0AC)
#define ICPWGA2H           (*(volatile unsigned char  *)0xFFFFA0AD)
#define P0PWGA2            (((volatile bitf_T *)0xFFFFA0AC)->bit00)
#define P1PWGA2            (((volatile bitf_T *)0xFFFFA0AC)->bit01)
#define P2PWGA2            (((volatile bitf_T *)0xFFFFA0AC)->bit02)
#define TBPWGA2            (((volatile bitf_T *)0xFFFFA0AC)->bit06)
#define MKPWGA2            (((volatile bitf_T *)0xFFFFA0AC)->bit07)
#define RFPWGA2            (((volatile bitf_T *)0xFFFFA0AD)->bit04)
#define CTPWGA2            (((volatile bitf_T *)0xFFFFA0AD)->bit07)
#define ICPWGA3            (*(volatile unsigned short *)0xFFFFA0AE)
#define ICPWGA3L           (*(volatile unsigned char  *)0xFFFFA0AE)
#define ICPWGA3H           (*(volatile unsigned char  *)0xFFFFA0AF)
#define P0PWGA3            (((volatile bitf_T *)0xFFFFA0AE)->bit00)
#define P1PWGA3            (((volatile bitf_T *)0xFFFFA0AE)->bit01)
#define P2PWGA3            (((volatile bitf_T *)0xFFFFA0AE)->bit02)
#define TBPWGA3            (((volatile bitf_T *)0xFFFFA0AE)->bit06)
#define MKPWGA3            (((volatile bitf_T *)0xFFFFA0AE)->bit07)
#define RFPWGA3            (((volatile bitf_T *)0xFFFFA0AF)->bit04)
#define CTPWGA3            (((volatile bitf_T *)0xFFFFA0AF)->bit07)
#define ICPWGA8            (*(volatile unsigned short *)0xFFFFA0B0)
#define ICPWGA8L           (*(volatile unsigned char  *)0xFFFFA0B0)
#define ICPWGA8H           (*(volatile unsigned char  *)0xFFFFA0B1)
#define P0PWGA8            (((volatile bitf_T *)0xFFFFA0B0)->bit00)
#define P1PWGA8            (((volatile bitf_T *)0xFFFFA0B0)->bit01)
#define P2PWGA8            (((volatile bitf_T *)0xFFFFA0B0)->bit02)
#define TBPWGA8            (((volatile bitf_T *)0xFFFFA0B0)->bit06)
#define MKPWGA8            (((volatile bitf_T *)0xFFFFA0B0)->bit07)
#define RFPWGA8            (((volatile bitf_T *)0xFFFFA0B1)->bit04)
#define CTPWGA8            (((volatile bitf_T *)0xFFFFA0B1)->bit07)
#define ICPWGA9            (*(volatile unsigned short *)0xFFFFA0B2)
#define ICPWGA9L           (*(volatile unsigned char  *)0xFFFFA0B2)
#define ICPWGA9H           (*(volatile unsigned char  *)0xFFFFA0B3)
#define P0PWGA9            (((volatile bitf_T *)0xFFFFA0B2)->bit00)
#define P1PWGA9            (((volatile bitf_T *)0xFFFFA0B2)->bit01)
#define P2PWGA9            (((volatile bitf_T *)0xFFFFA0B2)->bit02)
#define TBPWGA9            (((volatile bitf_T *)0xFFFFA0B2)->bit06)
#define MKPWGA9            (((volatile bitf_T *)0xFFFFA0B2)->bit07)
#define RFPWGA9            (((volatile bitf_T *)0xFFFFA0B3)->bit04)
#define CTPWGA9            (((volatile bitf_T *)0xFFFFA0B3)->bit07)
#define ICPWGA10           (*(volatile unsigned short *)0xFFFFA0B4)
#define ICPWGA10L          (*(volatile unsigned char  *)0xFFFFA0B4)
#define ICPWGA10H          (*(volatile unsigned char  *)0xFFFFA0B5)
#define P0PWGA10           (((volatile bitf_T *)0xFFFFA0B4)->bit00)
#define P1PWGA10           (((volatile bitf_T *)0xFFFFA0B4)->bit01)
#define P2PWGA10           (((volatile bitf_T *)0xFFFFA0B4)->bit02)
#define TBPWGA10           (((volatile bitf_T *)0xFFFFA0B4)->bit06)
#define MKPWGA10           (((volatile bitf_T *)0xFFFFA0B4)->bit07)
#define RFPWGA10           (((volatile bitf_T *)0xFFFFA0B5)->bit04)
#define CTPWGA10           (((volatile bitf_T *)0xFFFFA0B5)->bit07)
#define ICPWGA11           (*(volatile unsigned short *)0xFFFFA0B6)
#define ICPWGA11L          (*(volatile unsigned char  *)0xFFFFA0B6)
#define ICPWGA11H          (*(volatile unsigned char  *)0xFFFFA0B7)
#define P0PWGA11           (((volatile bitf_T *)0xFFFFA0B6)->bit00)
#define P1PWGA11           (((volatile bitf_T *)0xFFFFA0B6)->bit01)
#define P2PWGA11           (((volatile bitf_T *)0xFFFFA0B6)->bit02)
#define TBPWGA11           (((volatile bitf_T *)0xFFFFA0B6)->bit06)
#define MKPWGA11           (((volatile bitf_T *)0xFFFFA0B6)->bit07)
#define RFPWGA11           (((volatile bitf_T *)0xFFFFA0B7)->bit04)
#define CTPWGA11           (((volatile bitf_T *)0xFFFFA0B7)->bit07)
#define ICPWGA12           (*(volatile unsigned short *)0xFFFFA0B8)
#define ICPWGA12L          (*(volatile unsigned char  *)0xFFFFA0B8)
#define ICPWGA12H          (*(volatile unsigned char  *)0xFFFFA0B9)
#define P0PWGA12           (((volatile bitf_T *)0xFFFFA0B8)->bit00)
#define P1PWGA12           (((volatile bitf_T *)0xFFFFA0B8)->bit01)
#define P2PWGA12           (((volatile bitf_T *)0xFFFFA0B8)->bit02)
#define TBPWGA12           (((volatile bitf_T *)0xFFFFA0B8)->bit06)
#define MKPWGA12           (((volatile bitf_T *)0xFFFFA0B8)->bit07)
#define RFPWGA12           (((volatile bitf_T *)0xFFFFA0B9)->bit04)
#define CTPWGA12           (((volatile bitf_T *)0xFFFFA0B9)->bit07)
#define ICPWGA13           (*(volatile unsigned short *)0xFFFFA0BA)
#define ICPWGA13L          (*(volatile unsigned char  *)0xFFFFA0BA)
#define ICPWGA13H          (*(volatile unsigned char  *)0xFFFFA0BB)
#define P0PWGA13           (((volatile bitf_T *)0xFFFFA0BA)->bit00)
#define P1PWGA13           (((volatile bitf_T *)0xFFFFA0BA)->bit01)
#define P2PWGA13           (((volatile bitf_T *)0xFFFFA0BA)->bit02)
#define TBPWGA13           (((volatile bitf_T *)0xFFFFA0BA)->bit06)
#define MKPWGA13           (((volatile bitf_T *)0xFFFFA0BA)->bit07)
#define RFPWGA13           (((volatile bitf_T *)0xFFFFA0BB)->bit04)
#define CTPWGA13           (((volatile bitf_T *)0xFFFFA0BB)->bit07)
#define ICPWGA14           (*(volatile unsigned short *)0xFFFFA0BC)
#define ICPWGA14L          (*(volatile unsigned char  *)0xFFFFA0BC)
#define ICPWGA14H          (*(volatile unsigned char  *)0xFFFFA0BD)
#define P0PWGA14           (((volatile bitf_T *)0xFFFFA0BC)->bit00)
#define P1PWGA14           (((volatile bitf_T *)0xFFFFA0BC)->bit01)
#define P2PWGA14           (((volatile bitf_T *)0xFFFFA0BC)->bit02)
#define TBPWGA14           (((volatile bitf_T *)0xFFFFA0BC)->bit06)
#define MKPWGA14           (((volatile bitf_T *)0xFFFFA0BC)->bit07)
#define RFPWGA14           (((volatile bitf_T *)0xFFFFA0BD)->bit04)
#define CTPWGA14           (((volatile bitf_T *)0xFFFFA0BD)->bit07)
#define ICPWGA15           (*(volatile unsigned short *)0xFFFFA0BE)
#define ICPWGA15L          (*(volatile unsigned char  *)0xFFFFA0BE)
#define ICPWGA15H          (*(volatile unsigned char  *)0xFFFFA0BF)
#define P0PWGA15           (((volatile bitf_T *)0xFFFFA0BE)->bit00)
#define P1PWGA15           (((volatile bitf_T *)0xFFFFA0BE)->bit01)
#define P2PWGA15           (((volatile bitf_T *)0xFFFFA0BE)->bit02)
#define TBPWGA15           (((volatile bitf_T *)0xFFFFA0BE)->bit06)
#define MKPWGA15           (((volatile bitf_T *)0xFFFFA0BE)->bit07)
#define RFPWGA15           (((volatile bitf_T *)0xFFFFA0BF)->bit04)
#define CTPWGA15           (((volatile bitf_T *)0xFFFFA0BF)->bit07)
#define ICFLERR            (*(volatile unsigned short *)0xFFFFA0CC)
#define ICFLERRL           (*(volatile unsigned char  *)0xFFFFA0CC)
#define ICFLERRH           (*(volatile unsigned char  *)0xFFFFA0CD)
#define P0FLERR            (((volatile bitf_T *)0xFFFFA0CC)->bit00)
#define P1FLERR            (((volatile bitf_T *)0xFFFFA0CC)->bit01)
#define P2FLERR            (((volatile bitf_T *)0xFFFFA0CC)->bit02)
#define TBFLERR            (((volatile bitf_T *)0xFFFFA0CC)->bit06)
#define MKFLERR            (((volatile bitf_T *)0xFFFFA0CC)->bit07)
#define RFFLERR            (((volatile bitf_T *)0xFFFFA0CD)->bit04)
#define CTFLERR            (((volatile bitf_T *)0xFFFFA0CD)->bit07)
#define ICFLENDNM          (*(volatile unsigned short *)0xFFFFA0CE)
#define ICFLENDNML         (*(volatile unsigned char  *)0xFFFFA0CE)
#define ICFLENDNMH         (*(volatile unsigned char  *)0xFFFFA0CF)
#define P0FLENDNM          (((volatile bitf_T *)0xFFFFA0CE)->bit00)
#define P1FLENDNM          (((volatile bitf_T *)0xFFFFA0CE)->bit01)
#define P2FLENDNM          (((volatile bitf_T *)0xFFFFA0CE)->bit02)
#define TBFLENDNM          (((volatile bitf_T *)0xFFFFA0CE)->bit06)
#define MKFLENDNM          (((volatile bitf_T *)0xFFFFA0CE)->bit07)
#define RFFLENDNM          (((volatile bitf_T *)0xFFFFA0CF)->bit04)
#define CTFLENDNM          (((volatile bitf_T *)0xFFFFA0CF)->bit07)
#define ICCWEND            (*(volatile unsigned short *)0xFFFFA0D0)
#define ICCWENDL           (*(volatile unsigned char  *)0xFFFFA0D0)
#define ICCWENDH           (*(volatile unsigned char  *)0xFFFFA0D1)
#define P0CWEND            (((volatile bitf_T *)0xFFFFA0D0)->bit00)
#define P1CWEND            (((volatile bitf_T *)0xFFFFA0D0)->bit01)
#define P2CWEND            (((volatile bitf_T *)0xFFFFA0D0)->bit02)
#define TBCWEND            (((volatile bitf_T *)0xFFFFA0D0)->bit06)
#define MKCWEND            (((volatile bitf_T *)0xFFFFA0D0)->bit07)
#define RFCWEND            (((volatile bitf_T *)0xFFFFA0D1)->bit04)
#define CTCWEND            (((volatile bitf_T *)0xFFFFA0D1)->bit07)
#define ICRCAN1ERR         (*(volatile unsigned short *)0xFFFFA0D2)
#define ICRCAN1ERRL        (*(volatile unsigned char  *)0xFFFFA0D2)
#define ICRCAN1ERRH        (*(volatile unsigned char  *)0xFFFFA0D3)
#define P0RCAN1ERR         (((volatile bitf_T *)0xFFFFA0D2)->bit00)
#define P1RCAN1ERR         (((volatile bitf_T *)0xFFFFA0D2)->bit01)
#define P2RCAN1ERR         (((volatile bitf_T *)0xFFFFA0D2)->bit02)
#define TBRCAN1ERR         (((volatile bitf_T *)0xFFFFA0D2)->bit06)
#define MKRCAN1ERR         (((volatile bitf_T *)0xFFFFA0D2)->bit07)
#define RFRCAN1ERR         (((volatile bitf_T *)0xFFFFA0D3)->bit04)
#define CTRCAN1ERR         (((volatile bitf_T *)0xFFFFA0D3)->bit07)
#define ICRCAN1REC         (*(volatile unsigned short *)0xFFFFA0D4)
#define ICRCAN1RECL        (*(volatile unsigned char  *)0xFFFFA0D4)
#define ICRCAN1RECH        (*(volatile unsigned char  *)0xFFFFA0D5)
#define P0RCAN1REC         (((volatile bitf_T *)0xFFFFA0D4)->bit00)
#define P1RCAN1REC         (((volatile bitf_T *)0xFFFFA0D4)->bit01)
#define P2RCAN1REC         (((volatile bitf_T *)0xFFFFA0D4)->bit02)
#define TBRCAN1REC         (((volatile bitf_T *)0xFFFFA0D4)->bit06)
#define MKRCAN1REC         (((volatile bitf_T *)0xFFFFA0D4)->bit07)
#define RFRCAN1REC         (((volatile bitf_T *)0xFFFFA0D5)->bit04)
#define CTRCAN1REC         (((volatile bitf_T *)0xFFFFA0D5)->bit07)
#define ICRCAN1TRX         (*(volatile unsigned short *)0xFFFFA0D6)
#define ICRCAN1TRXL        (*(volatile unsigned char  *)0xFFFFA0D6)
#define ICRCAN1TRXH        (*(volatile unsigned char  *)0xFFFFA0D7)
#define P0RCAN1TRX         (((volatile bitf_T *)0xFFFFA0D6)->bit00)
#define P1RCAN1TRX         (((volatile bitf_T *)0xFFFFA0D6)->bit01)
#define P2RCAN1TRX         (((volatile bitf_T *)0xFFFFA0D6)->bit02)
#define TBRCAN1TRX         (((volatile bitf_T *)0xFFFFA0D6)->bit06)
#define MKRCAN1TRX         (((volatile bitf_T *)0xFFFFA0D6)->bit07)
#define RFRCAN1TRX         (((volatile bitf_T *)0xFFFFA0D7)->bit04)
#define CTRCAN1TRX         (((volatile bitf_T *)0xFFFFA0D7)->bit07)
#define ICCSIH1IC          (*(volatile unsigned short *)0xFFFFA0D8)
#define ICTAPA0IPEK0_2     (*(volatile unsigned short *)0xFFFFA0D8)
#define ICCSIH1ICL         (*(volatile unsigned char  *)0xFFFFA0D8)
#define ICTAPA0IPEK0L_2    (*(volatile unsigned char  *)0xFFFFA0D8)
#define ICCSIH1ICH         (*(volatile unsigned char  *)0xFFFFA0D9)
#define ICTAPA0IPEK0H_2    (*(volatile unsigned char  *)0xFFFFA0D9)
#define P0CSIH1IC          (((volatile bitf_T *)0xFFFFA0D8)->bit00)
#define P0TAPA0IPEK0_2     (((volatile bitf_T *)0xFFFFA0D8)->bit00)
#define P1CSIH1IC          (((volatile bitf_T *)0xFFFFA0D8)->bit01)
#define P1TAPA0IPEK0_2     (((volatile bitf_T *)0xFFFFA0D8)->bit01)
#define P2CSIH1IC          (((volatile bitf_T *)0xFFFFA0D8)->bit02)
#define P2TAPA0IPEK0_2     (((volatile bitf_T *)0xFFFFA0D8)->bit02)
#define TBCSIH1IC          (((volatile bitf_T *)0xFFFFA0D8)->bit06)
#define TBTAPA0IPEK0_2     (((volatile bitf_T *)0xFFFFA0D8)->bit06)
#define MKCSIH1IC          (((volatile bitf_T *)0xFFFFA0D8)->bit07)
#define MKTAPA0IPEK0_2     (((volatile bitf_T *)0xFFFFA0D8)->bit07)
#define RFCSIH1IC          (((volatile bitf_T *)0xFFFFA0D9)->bit04)
#define RFTAPA0IPEK0_2     (((volatile bitf_T *)0xFFFFA0D9)->bit04)
#define CTCSIH1IC          (((volatile bitf_T *)0xFFFFA0D9)->bit07)
#define CTTAPA0IPEK0_2     (((volatile bitf_T *)0xFFFFA0D9)->bit07)
#define ICCSIH1IR          (*(volatile unsigned short *)0xFFFFA0DA)
#define ICTAPA0IVLY0_2     (*(volatile unsigned short *)0xFFFFA0DA)
#define ICCSIH1IRL         (*(volatile unsigned char  *)0xFFFFA0DA)
#define ICTAPA0IVLY0L_2    (*(volatile unsigned char  *)0xFFFFA0DA)
#define ICCSIH1IRH         (*(volatile unsigned char  *)0xFFFFA0DB)
#define ICTAPA0IVLY0H_2    (*(volatile unsigned char  *)0xFFFFA0DB)
#define P0CSIH1IR          (((volatile bitf_T *)0xFFFFA0DA)->bit00)
#define P0TAPA0IVLY0_2     (((volatile bitf_T *)0xFFFFA0DA)->bit00)
#define P1CSIH1IR          (((volatile bitf_T *)0xFFFFA0DA)->bit01)
#define P1TAPA0IVLY0_2     (((volatile bitf_T *)0xFFFFA0DA)->bit01)
#define P2CSIH1IR          (((volatile bitf_T *)0xFFFFA0DA)->bit02)
#define P2TAPA0IVLY0_2     (((volatile bitf_T *)0xFFFFA0DA)->bit02)
#define TBCSIH1IR          (((volatile bitf_T *)0xFFFFA0DA)->bit06)
#define TBTAPA0IVLY0_2     (((volatile bitf_T *)0xFFFFA0DA)->bit06)
#define MKCSIH1IR          (((volatile bitf_T *)0xFFFFA0DA)->bit07)
#define MKTAPA0IVLY0_2     (((volatile bitf_T *)0xFFFFA0DA)->bit07)
#define RFCSIH1IR          (((volatile bitf_T *)0xFFFFA0DB)->bit04)
#define RFTAPA0IVLY0_2     (((volatile bitf_T *)0xFFFFA0DB)->bit04)
#define CTCSIH1IR          (((volatile bitf_T *)0xFFFFA0DB)->bit07)
#define CTTAPA0IVLY0_2     (((volatile bitf_T *)0xFFFFA0DB)->bit07)
#define ICCSIG0IC_2        (*(volatile unsigned short *)0xFFFFA0DC)
#define ICCSIH1IRE         (*(volatile unsigned short *)0xFFFFA0DC)
#define ICCSIG0ICL_2       (*(volatile unsigned char  *)0xFFFFA0DC)
#define ICCSIH1IREL        (*(volatile unsigned char  *)0xFFFFA0DC)
#define ICCSIG0ICH_2       (*(volatile unsigned char  *)0xFFFFA0DD)
#define ICCSIH1IREH        (*(volatile unsigned char  *)0xFFFFA0DD)
#define P0CSIG0IC_2        (((volatile bitf_T *)0xFFFFA0DC)->bit00)
#define P0CSIH1IRE         (((volatile bitf_T *)0xFFFFA0DC)->bit00)
#define P1CSIG0IC_2        (((volatile bitf_T *)0xFFFFA0DC)->bit01)
#define P1CSIH1IRE         (((volatile bitf_T *)0xFFFFA0DC)->bit01)
#define P2CSIG0IC_2        (((volatile bitf_T *)0xFFFFA0DC)->bit02)
#define P2CSIH1IRE         (((volatile bitf_T *)0xFFFFA0DC)->bit02)
#define TBCSIG0IC_2        (((volatile bitf_T *)0xFFFFA0DC)->bit06)
#define TBCSIH1IRE         (((volatile bitf_T *)0xFFFFA0DC)->bit06)
#define MKCSIG0IC_2        (((volatile bitf_T *)0xFFFFA0DC)->bit07)
#define MKCSIH1IRE         (((volatile bitf_T *)0xFFFFA0DC)->bit07)
#define RFCSIG0IC_2        (((volatile bitf_T *)0xFFFFA0DD)->bit04)
#define RFCSIH1IRE         (((volatile bitf_T *)0xFFFFA0DD)->bit04)
#define CTCSIG0IC_2        (((volatile bitf_T *)0xFFFFA0DD)->bit07)
#define CTCSIH1IRE         (((volatile bitf_T *)0xFFFFA0DD)->bit07)
#define ICCSIG0IR_2        (*(volatile unsigned short *)0xFFFFA0DE)
#define ICCSIH1IJC         (*(volatile unsigned short *)0xFFFFA0DE)
#define ICCSIG0IRL_2       (*(volatile unsigned char  *)0xFFFFA0DE)
#define ICCSIH1IJCL        (*(volatile unsigned char  *)0xFFFFA0DE)
#define ICCSIG0IRH_2       (*(volatile unsigned char  *)0xFFFFA0DF)
#define ICCSIH1IJCH        (*(volatile unsigned char  *)0xFFFFA0DF)
#define P0CSIG0IR_2        (((volatile bitf_T *)0xFFFFA0DE)->bit00)
#define P0CSIH1IJC         (((volatile bitf_T *)0xFFFFA0DE)->bit00)
#define P1CSIG0IR_2        (((volatile bitf_T *)0xFFFFA0DE)->bit01)
#define P1CSIH1IJC         (((volatile bitf_T *)0xFFFFA0DE)->bit01)
#define P2CSIG0IR_2        (((volatile bitf_T *)0xFFFFA0DE)->bit02)
#define P2CSIH1IJC         (((volatile bitf_T *)0xFFFFA0DE)->bit02)
#define TBCSIG0IR_2        (((volatile bitf_T *)0xFFFFA0DE)->bit06)
#define TBCSIH1IJC         (((volatile bitf_T *)0xFFFFA0DE)->bit06)
#define MKCSIG0IR_2        (((volatile bitf_T *)0xFFFFA0DE)->bit07)
#define MKCSIH1IJC         (((volatile bitf_T *)0xFFFFA0DE)->bit07)
#define RFCSIG0IR_2        (((volatile bitf_T *)0xFFFFA0DF)->bit04)
#define RFCSIH1IJC         (((volatile bitf_T *)0xFFFFA0DF)->bit04)
#define CTCSIG0IR_2        (((volatile bitf_T *)0xFFFFA0DF)->bit07)
#define CTCSIH1IJC         (((volatile bitf_T *)0xFFFFA0DF)->bit07)
#define ICRLIN31           (*(volatile unsigned short *)0xFFFFA0E0)
#define ICRLIN31L          (*(volatile unsigned char  *)0xFFFFA0E0)
#define ICRLIN31H          (*(volatile unsigned char  *)0xFFFFA0E1)
#define P0RLIN31           (((volatile bitf_T *)0xFFFFA0E0)->bit00)
#define P1RLIN31           (((volatile bitf_T *)0xFFFFA0E0)->bit01)
#define P2RLIN31           (((volatile bitf_T *)0xFFFFA0E0)->bit02)
#define TBRLIN31           (((volatile bitf_T *)0xFFFFA0E0)->bit06)
#define MKRLIN31           (((volatile bitf_T *)0xFFFFA0E0)->bit07)
#define RFRLIN31           (((volatile bitf_T *)0xFFFFA0E1)->bit04)
#define CTRLIN31           (((volatile bitf_T *)0xFFFFA0E1)->bit07)
#define ICRLIN31UR0        (*(volatile unsigned short *)0xFFFFA0E2)
#define ICRLIN31UR0L       (*(volatile unsigned char  *)0xFFFFA0E2)
#define ICRLIN31UR0H       (*(volatile unsigned char  *)0xFFFFA0E3)
#define P0RLIN31UR0        (((volatile bitf_T *)0xFFFFA0E2)->bit00)
#define P1RLIN31UR0        (((volatile bitf_T *)0xFFFFA0E2)->bit01)
#define P2RLIN31UR0        (((volatile bitf_T *)0xFFFFA0E2)->bit02)
#define TBRLIN31UR0        (((volatile bitf_T *)0xFFFFA0E2)->bit06)
#define MKRLIN31UR0        (((volatile bitf_T *)0xFFFFA0E2)->bit07)
#define RFRLIN31UR0        (((volatile bitf_T *)0xFFFFA0E3)->bit04)
#define CTRLIN31UR0        (((volatile bitf_T *)0xFFFFA0E3)->bit07)
#define ICRLIN31UR1        (*(volatile unsigned short *)0xFFFFA0E4)
#define ICRLIN31UR1L       (*(volatile unsigned char  *)0xFFFFA0E4)
#define ICRLIN31UR1H       (*(volatile unsigned char  *)0xFFFFA0E5)
#define P0RLIN31UR1        (((volatile bitf_T *)0xFFFFA0E4)->bit00)
#define P1RLIN31UR1        (((volatile bitf_T *)0xFFFFA0E4)->bit01)
#define P2RLIN31UR1        (((volatile bitf_T *)0xFFFFA0E4)->bit02)
#define TBRLIN31UR1        (((volatile bitf_T *)0xFFFFA0E4)->bit06)
#define MKRLIN31UR1        (((volatile bitf_T *)0xFFFFA0E4)->bit07)
#define RFRLIN31UR1        (((volatile bitf_T *)0xFFFFA0E5)->bit04)
#define CTRLIN31UR1        (((volatile bitf_T *)0xFFFFA0E5)->bit07)
#define ICRLIN31UR2        (*(volatile unsigned short *)0xFFFFA0E6)
#define ICRLIN31UR2L       (*(volatile unsigned char  *)0xFFFFA0E6)
#define ICRLIN31UR2H       (*(volatile unsigned char  *)0xFFFFA0E7)
#define P0RLIN31UR2        (((volatile bitf_T *)0xFFFFA0E6)->bit00)
#define P1RLIN31UR2        (((volatile bitf_T *)0xFFFFA0E6)->bit01)
#define P2RLIN31UR2        (((volatile bitf_T *)0xFFFFA0E6)->bit02)
#define TBRLIN31UR2        (((volatile bitf_T *)0xFFFFA0E6)->bit06)
#define MKRLIN31UR2        (((volatile bitf_T *)0xFFFFA0E6)->bit07)
#define RFRLIN31UR2        (((volatile bitf_T *)0xFFFFA0E7)->bit04)
#define CTRLIN31UR2        (((volatile bitf_T *)0xFFFFA0E7)->bit07)
#define ICPWGA20           (*(volatile unsigned short *)0xFFFFA0E8)
#define ICPWGA20L          (*(volatile unsigned char  *)0xFFFFA0E8)
#define ICPWGA20H          (*(volatile unsigned char  *)0xFFFFA0E9)
#define P0PWGA20           (((volatile bitf_T *)0xFFFFA0E8)->bit00)
#define P1PWGA20           (((volatile bitf_T *)0xFFFFA0E8)->bit01)
#define P2PWGA20           (((volatile bitf_T *)0xFFFFA0E8)->bit02)
#define TBPWGA20           (((volatile bitf_T *)0xFFFFA0E8)->bit06)
#define MKPWGA20           (((volatile bitf_T *)0xFFFFA0E8)->bit07)
#define RFPWGA20           (((volatile bitf_T *)0xFFFFA0E9)->bit04)
#define CTPWGA20           (((volatile bitf_T *)0xFFFFA0E9)->bit07)
#define ICPWGA21           (*(volatile unsigned short *)0xFFFFA0EA)
#define ICPWGA21L          (*(volatile unsigned char  *)0xFFFFA0EA)
#define ICPWGA21H          (*(volatile unsigned char  *)0xFFFFA0EB)
#define P0PWGA21           (((volatile bitf_T *)0xFFFFA0EA)->bit00)
#define P1PWGA21           (((volatile bitf_T *)0xFFFFA0EA)->bit01)
#define P2PWGA21           (((volatile bitf_T *)0xFFFFA0EA)->bit02)
#define TBPWGA21           (((volatile bitf_T *)0xFFFFA0EA)->bit06)
#define MKPWGA21           (((volatile bitf_T *)0xFFFFA0EA)->bit07)
#define RFPWGA21           (((volatile bitf_T *)0xFFFFA0EB)->bit04)
#define CTPWGA21           (((volatile bitf_T *)0xFFFFA0EB)->bit07)
#define ICPWGA22           (*(volatile unsigned short *)0xFFFFA0EC)
#define ICPWGA22L          (*(volatile unsigned char  *)0xFFFFA0EC)
#define ICPWGA22H          (*(volatile unsigned char  *)0xFFFFA0ED)
#define P0PWGA22           (((volatile bitf_T *)0xFFFFA0EC)->bit00)
#define P1PWGA22           (((volatile bitf_T *)0xFFFFA0EC)->bit01)
#define P2PWGA22           (((volatile bitf_T *)0xFFFFA0EC)->bit02)
#define TBPWGA22           (((volatile bitf_T *)0xFFFFA0EC)->bit06)
#define MKPWGA22           (((volatile bitf_T *)0xFFFFA0EC)->bit07)
#define RFPWGA22           (((volatile bitf_T *)0xFFFFA0ED)->bit04)
#define CTPWGA22           (((volatile bitf_T *)0xFFFFA0ED)->bit07)
#define ICPWGA23           (*(volatile unsigned short *)0xFFFFA0EE)
#define ICPWGA23L          (*(volatile unsigned char  *)0xFFFFA0EE)
#define ICPWGA23H          (*(volatile unsigned char  *)0xFFFFA0EF)
#define P0PWGA23           (((volatile bitf_T *)0xFFFFA0EE)->bit00)
#define P1PWGA23           (((volatile bitf_T *)0xFFFFA0EE)->bit01)
#define P2PWGA23           (((volatile bitf_T *)0xFFFFA0EE)->bit02)
#define TBPWGA23           (((volatile bitf_T *)0xFFFFA0EE)->bit06)
#define MKPWGA23           (((volatile bitf_T *)0xFFFFA0EE)->bit07)
#define RFPWGA23           (((volatile bitf_T *)0xFFFFA0EF)->bit04)
#define CTPWGA23           (((volatile bitf_T *)0xFFFFA0EF)->bit07)
#define ICP6               (*(volatile unsigned short *)0xFFFFA0F0)
#define ICP6L              (*(volatile unsigned char  *)0xFFFFA0F0)
#define ICP6H              (*(volatile unsigned char  *)0xFFFFA0F1)
#define P0P6               (((volatile bitf_T *)0xFFFFA0F0)->bit00)
#define P1P6               (((volatile bitf_T *)0xFFFFA0F0)->bit01)
#define P2P6               (((volatile bitf_T *)0xFFFFA0F0)->bit02)
#define TBP6               (((volatile bitf_T *)0xFFFFA0F0)->bit06)
#define MKP6               (((volatile bitf_T *)0xFFFFA0F0)->bit07)
#define RFP6               (((volatile bitf_T *)0xFFFFA0F1)->bit04)
#define CTP6               (((volatile bitf_T *)0xFFFFA0F1)->bit07)
#define ICP7               (*(volatile unsigned short *)0xFFFFA0F2)
#define ICP7L              (*(volatile unsigned char  *)0xFFFFA0F2)
#define ICP7H              (*(volatile unsigned char  *)0xFFFFA0F3)
#define P0P7               (((volatile bitf_T *)0xFFFFA0F2)->bit00)
#define P1P7               (((volatile bitf_T *)0xFFFFA0F2)->bit01)
#define P2P7               (((volatile bitf_T *)0xFFFFA0F2)->bit02)
#define TBP7               (((volatile bitf_T *)0xFFFFA0F2)->bit06)
#define MKP7               (((volatile bitf_T *)0xFFFFA0F2)->bit07)
#define RFP7               (((volatile bitf_T *)0xFFFFA0F3)->bit04)
#define CTP7               (((volatile bitf_T *)0xFFFFA0F3)->bit07)
#define ICP8               (*(volatile unsigned short *)0xFFFFA0F4)
#define ICP8L              (*(volatile unsigned char  *)0xFFFFA0F4)
#define ICP8H              (*(volatile unsigned char  *)0xFFFFA0F5)
#define P0P8               (((volatile bitf_T *)0xFFFFA0F4)->bit00)
#define P1P8               (((volatile bitf_T *)0xFFFFA0F4)->bit01)
#define P2P8               (((volatile bitf_T *)0xFFFFA0F4)->bit02)
#define TBP8               (((volatile bitf_T *)0xFFFFA0F4)->bit06)
#define MKP8               (((volatile bitf_T *)0xFFFFA0F4)->bit07)
#define RFP8               (((volatile bitf_T *)0xFFFFA0F5)->bit04)
#define CTP8               (((volatile bitf_T *)0xFFFFA0F5)->bit07)
#define ICP12              (*(volatile unsigned short *)0xFFFFA0F6)
#define ICP12L             (*(volatile unsigned char  *)0xFFFFA0F6)
#define ICP12H             (*(volatile unsigned char  *)0xFFFFA0F7)
#define P0P12              (((volatile bitf_T *)0xFFFFA0F6)->bit00)
#define P1P12              (((volatile bitf_T *)0xFFFFA0F6)->bit01)
#define P2P12              (((volatile bitf_T *)0xFFFFA0F6)->bit02)
#define TBP12              (((volatile bitf_T *)0xFFFFA0F6)->bit06)
#define MKP12              (((volatile bitf_T *)0xFFFFA0F6)->bit07)
#define RFP12              (((volatile bitf_T *)0xFFFFA0F7)->bit04)
#define CTP12              (((volatile bitf_T *)0xFFFFA0F7)->bit07)
#define ICCSIH2IC          (*(volatile unsigned short *)0xFFFFA0F8)
#define ICTAUD0I0_2        (*(volatile unsigned short *)0xFFFFA0F8)
#define ICCSIH2ICL         (*(volatile unsigned char  *)0xFFFFA0F8)
#define ICTAUD0I0L_2       (*(volatile unsigned char  *)0xFFFFA0F8)
#define ICCSIH2ICH         (*(volatile unsigned char  *)0xFFFFA0F9)
#define ICTAUD0I0H_2       (*(volatile unsigned char  *)0xFFFFA0F9)
#define P0CSIH2IC          (((volatile bitf_T *)0xFFFFA0F8)->bit00)
#define P0TAUD0I0_2        (((volatile bitf_T *)0xFFFFA0F8)->bit00)
#define P1CSIH2IC          (((volatile bitf_T *)0xFFFFA0F8)->bit01)
#define P1TAUD0I0_2        (((volatile bitf_T *)0xFFFFA0F8)->bit01)
#define P2CSIH2IC          (((volatile bitf_T *)0xFFFFA0F8)->bit02)
#define P2TAUD0I0_2        (((volatile bitf_T *)0xFFFFA0F8)->bit02)
#define TBCSIH2IC          (((volatile bitf_T *)0xFFFFA0F8)->bit06)
#define TBTAUD0I0_2        (((volatile bitf_T *)0xFFFFA0F8)->bit06)
#define MKCSIH2IC          (((volatile bitf_T *)0xFFFFA0F8)->bit07)
#define MKTAUD0I0_2        (((volatile bitf_T *)0xFFFFA0F8)->bit07)
#define RFCSIH2IC          (((volatile bitf_T *)0xFFFFA0F9)->bit04)
#define RFTAUD0I0_2        (((volatile bitf_T *)0xFFFFA0F9)->bit04)
#define CTCSIH2IC          (((volatile bitf_T *)0xFFFFA0F9)->bit07)
#define CTTAUD0I0_2        (((volatile bitf_T *)0xFFFFA0F9)->bit07)
#define ICCSIH2IR          (*(volatile unsigned short *)0xFFFFA0FA)
#define ICP0_2             (*(volatile unsigned short *)0xFFFFA0FA)
#define ICCSIH2IRL         (*(volatile unsigned char  *)0xFFFFA0FA)
#define ICP0L_2            (*(volatile unsigned char  *)0xFFFFA0FA)
#define ICCSIH2IRH         (*(volatile unsigned char  *)0xFFFFA0FB)
#define ICP0H_2            (*(volatile unsigned char  *)0xFFFFA0FB)
#define P0CSIH2IR          (((volatile bitf_T *)0xFFFFA0FA)->bit00)
#define P0P0_2             (((volatile bitf_T *)0xFFFFA0FA)->bit00)
#define P1CSIH2IR          (((volatile bitf_T *)0xFFFFA0FA)->bit01)
#define P1P0_2             (((volatile bitf_T *)0xFFFFA0FA)->bit01)
#define P2CSIH2IR          (((volatile bitf_T *)0xFFFFA0FA)->bit02)
#define P2P0_2             (((volatile bitf_T *)0xFFFFA0FA)->bit02)
#define TBCSIH2IR          (((volatile bitf_T *)0xFFFFA0FA)->bit06)
#define TBP0_2             (((volatile bitf_T *)0xFFFFA0FA)->bit06)
#define MKCSIH2IR          (((volatile bitf_T *)0xFFFFA0FA)->bit07)
#define MKP0_2             (((volatile bitf_T *)0xFFFFA0FA)->bit07)
#define RFCSIH2IR          (((volatile bitf_T *)0xFFFFA0FB)->bit04)
#define RFP0_2             (((volatile bitf_T *)0xFFFFA0FB)->bit04)
#define CTCSIH2IR          (((volatile bitf_T *)0xFFFFA0FB)->bit07)
#define CTP0_2             (((volatile bitf_T *)0xFFFFA0FB)->bit07)
#define ICCSIH2IRE         (*(volatile unsigned short *)0xFFFFA0FC)
#define ICP1_2             (*(volatile unsigned short *)0xFFFFA0FC)
#define ICCSIH2IREL        (*(volatile unsigned char  *)0xFFFFA0FC)
#define ICP1L_2            (*(volatile unsigned char  *)0xFFFFA0FC)
#define ICCSIH2IREH        (*(volatile unsigned char  *)0xFFFFA0FD)
#define ICP1H_2            (*(volatile unsigned char  *)0xFFFFA0FD)
#define P0CSIH2IRE         (((volatile bitf_T *)0xFFFFA0FC)->bit00)
#define P0P1_2             (((volatile bitf_T *)0xFFFFA0FC)->bit00)
#define P1CSIH2IRE         (((volatile bitf_T *)0xFFFFA0FC)->bit01)
#define P1P1_2             (((volatile bitf_T *)0xFFFFA0FC)->bit01)
#define P2CSIH2IRE         (((volatile bitf_T *)0xFFFFA0FC)->bit02)
#define P2P1_2             (((volatile bitf_T *)0xFFFFA0FC)->bit02)
#define TBCSIH2IRE         (((volatile bitf_T *)0xFFFFA0FC)->bit06)
#define TBP1_2             (((volatile bitf_T *)0xFFFFA0FC)->bit06)
#define MKCSIH2IRE         (((volatile bitf_T *)0xFFFFA0FC)->bit07)
#define MKP1_2             (((volatile bitf_T *)0xFFFFA0FC)->bit07)
#define RFCSIH2IRE         (((volatile bitf_T *)0xFFFFA0FD)->bit04)
#define RFP1_2             (((volatile bitf_T *)0xFFFFA0FD)->bit04)
#define CTCSIH2IRE         (((volatile bitf_T *)0xFFFFA0FD)->bit07)
#define CTP1_2             (((volatile bitf_T *)0xFFFFA0FD)->bit07)
#define ICCSIH2IJC         (*(volatile unsigned short *)0xFFFFA0FE)
#define ICP2_2             (*(volatile unsigned short *)0xFFFFA0FE)
#define ICCSIH2IJCL        (*(volatile unsigned char  *)0xFFFFA0FE)
#define ICP2L_2            (*(volatile unsigned char  *)0xFFFFA0FE)
#define ICCSIH2IJCH        (*(volatile unsigned char  *)0xFFFFA0FF)
#define ICP2H_2            (*(volatile unsigned char  *)0xFFFFA0FF)
#define P0CSIH2IJC         (((volatile bitf_T *)0xFFFFA0FE)->bit00)
#define P0P2_2             (((volatile bitf_T *)0xFFFFA0FE)->bit00)
#define P1CSIH2IJC         (((volatile bitf_T *)0xFFFFA0FE)->bit01)
#define P1P2_2             (((volatile bitf_T *)0xFFFFA0FE)->bit01)
#define P2CSIH2IJC         (((volatile bitf_T *)0xFFFFA0FE)->bit02)
#define P2P2_2             (((volatile bitf_T *)0xFFFFA0FE)->bit02)
#define TBCSIH2IJC         (((volatile bitf_T *)0xFFFFA0FE)->bit06)
#define TBP2_2             (((volatile bitf_T *)0xFFFFA0FE)->bit06)
#define MKCSIH2IJC         (((volatile bitf_T *)0xFFFFA0FE)->bit07)
#define MKP2_2             (((volatile bitf_T *)0xFFFFA0FE)->bit07)
#define RFCSIH2IJC         (((volatile bitf_T *)0xFFFFA0FF)->bit04)
#define RFP2_2             (((volatile bitf_T *)0xFFFFA0FF)->bit04)
#define CTCSIH2IJC         (((volatile bitf_T *)0xFFFFA0FF)->bit07)
#define CTP2_2             (((volatile bitf_T *)0xFFFFA0FF)->bit07)
#define ICPWGA16           (*(volatile unsigned short *)0xFFFFA112)
#define ICPWGA16L          (*(volatile unsigned char  *)0xFFFFA112)
#define ICPWGA16H          (*(volatile unsigned char  *)0xFFFFA113)
#define P0PWGA16           (((volatile bitf_T *)0xFFFFA112)->bit00)
#define P1PWGA16           (((volatile bitf_T *)0xFFFFA112)->bit01)
#define P2PWGA16           (((volatile bitf_T *)0xFFFFA112)->bit02)
#define TBPWGA16           (((volatile bitf_T *)0xFFFFA112)->bit06)
#define MKPWGA16           (((volatile bitf_T *)0xFFFFA112)->bit07)
#define RFPWGA16           (((volatile bitf_T *)0xFFFFA113)->bit04)
#define CTPWGA16           (((volatile bitf_T *)0xFFFFA113)->bit07)
#define ICPWGA17           (*(volatile unsigned short *)0xFFFFA116)
#define ICPWGA17L          (*(volatile unsigned char  *)0xFFFFA116)
#define ICPWGA17H          (*(volatile unsigned char  *)0xFFFFA117)
#define P0PWGA17           (((volatile bitf_T *)0xFFFFA116)->bit00)
#define P1PWGA17           (((volatile bitf_T *)0xFFFFA116)->bit01)
#define P2PWGA17           (((volatile bitf_T *)0xFFFFA116)->bit02)
#define TBPWGA17           (((volatile bitf_T *)0xFFFFA116)->bit06)
#define MKPWGA17           (((volatile bitf_T *)0xFFFFA116)->bit07)
#define RFPWGA17           (((volatile bitf_T *)0xFFFFA117)->bit04)
#define CTPWGA17           (((volatile bitf_T *)0xFFFFA117)->bit07)
#define ICPWGA18           (*(volatile unsigned short *)0xFFFFA11A)
#define ICPWGA18L          (*(volatile unsigned char  *)0xFFFFA11A)
#define ICPWGA18H          (*(volatile unsigned char  *)0xFFFFA11B)
#define P0PWGA18           (((volatile bitf_T *)0xFFFFA11A)->bit00)
#define P1PWGA18           (((volatile bitf_T *)0xFFFFA11A)->bit01)
#define P2PWGA18           (((volatile bitf_T *)0xFFFFA11A)->bit02)
#define TBPWGA18           (((volatile bitf_T *)0xFFFFA11A)->bit06)
#define MKPWGA18           (((volatile bitf_T *)0xFFFFA11A)->bit07)
#define RFPWGA18           (((volatile bitf_T *)0xFFFFA11B)->bit04)
#define CTPWGA18           (((volatile bitf_T *)0xFFFFA11B)->bit07)
#define ICPWGA19           (*(volatile unsigned short *)0xFFFFA11E)
#define ICPWGA19L          (*(volatile unsigned char  *)0xFFFFA11E)
#define ICPWGA19H          (*(volatile unsigned char  *)0xFFFFA11F)
#define P0PWGA19           (((volatile bitf_T *)0xFFFFA11E)->bit00)
#define P1PWGA19           (((volatile bitf_T *)0xFFFFA11E)->bit01)
#define P2PWGA19           (((volatile bitf_T *)0xFFFFA11E)->bit02)
#define TBPWGA19           (((volatile bitf_T *)0xFFFFA11E)->bit06)
#define MKPWGA19           (((volatile bitf_T *)0xFFFFA11E)->bit07)
#define RFPWGA19           (((volatile bitf_T *)0xFFFFA11F)->bit04)
#define CTPWGA19           (((volatile bitf_T *)0xFFFFA11F)->bit07)
#define ICRLIN32           (*(volatile unsigned short *)0xFFFFA138)
#define ICRLIN32L          (*(volatile unsigned char  *)0xFFFFA138)
#define ICRLIN32H          (*(volatile unsigned char  *)0xFFFFA139)
#define P0RLIN32           (((volatile bitf_T *)0xFFFFA138)->bit00)
#define P1RLIN32           (((volatile bitf_T *)0xFFFFA138)->bit01)
#define P2RLIN32           (((volatile bitf_T *)0xFFFFA138)->bit02)
#define TBRLIN32           (((volatile bitf_T *)0xFFFFA138)->bit06)
#define MKRLIN32           (((volatile bitf_T *)0xFFFFA138)->bit07)
#define RFRLIN32           (((volatile bitf_T *)0xFFFFA139)->bit04)
#define CTRLIN32           (((volatile bitf_T *)0xFFFFA139)->bit07)
#define ICRLIN32UR0        (*(volatile unsigned short *)0xFFFFA13A)
#define ICRLIN32UR0L       (*(volatile unsigned char  *)0xFFFFA13A)
#define ICRLIN32UR0H       (*(volatile unsigned char  *)0xFFFFA13B)
#define P0RLIN32UR0        (((volatile bitf_T *)0xFFFFA13A)->bit00)
#define P1RLIN32UR0        (((volatile bitf_T *)0xFFFFA13A)->bit01)
#define P2RLIN32UR0        (((volatile bitf_T *)0xFFFFA13A)->bit02)
#define TBRLIN32UR0        (((volatile bitf_T *)0xFFFFA13A)->bit06)
#define MKRLIN32UR0        (((volatile bitf_T *)0xFFFFA13A)->bit07)
#define RFRLIN32UR0        (((volatile bitf_T *)0xFFFFA13B)->bit04)
#define CTRLIN32UR0        (((volatile bitf_T *)0xFFFFA13B)->bit07)
#define ICRLIN32UR1        (*(volatile unsigned short *)0xFFFFA13C)
#define ICRLIN32UR1L       (*(volatile unsigned char  *)0xFFFFA13C)
#define ICRLIN32UR1H       (*(volatile unsigned char  *)0xFFFFA13D)
#define P0RLIN32UR1        (((volatile bitf_T *)0xFFFFA13C)->bit00)
#define P1RLIN32UR1        (((volatile bitf_T *)0xFFFFA13C)->bit01)
#define P2RLIN32UR1        (((volatile bitf_T *)0xFFFFA13C)->bit02)
#define TBRLIN32UR1        (((volatile bitf_T *)0xFFFFA13C)->bit06)
#define MKRLIN32UR1        (((volatile bitf_T *)0xFFFFA13C)->bit07)
#define RFRLIN32UR1        (((volatile bitf_T *)0xFFFFA13D)->bit04)
#define CTRLIN32UR1        (((volatile bitf_T *)0xFFFFA13D)->bit07)
#define ICRLIN32UR2        (*(volatile unsigned short *)0xFFFFA13E)
#define ICRLIN32UR2L       (*(volatile unsigned char  *)0xFFFFA13E)
#define ICRLIN32UR2H       (*(volatile unsigned char  *)0xFFFFA13F)
#define P0RLIN32UR2        (((volatile bitf_T *)0xFFFFA13E)->bit00)
#define P1RLIN32UR2        (((volatile bitf_T *)0xFFFFA13E)->bit01)
#define P2RLIN32UR2        (((volatile bitf_T *)0xFFFFA13E)->bit02)
#define TBRLIN32UR2        (((volatile bitf_T *)0xFFFFA13E)->bit06)
#define MKRLIN32UR2        (((volatile bitf_T *)0xFFFFA13E)->bit07)
#define RFRLIN32UR2        (((volatile bitf_T *)0xFFFFA13F)->bit04)
#define CTRLIN32UR2        (((volatile bitf_T *)0xFFFFA13F)->bit07)
#define ICRCAN2ERR         (*(volatile unsigned short *)0xFFFFA1A2)
#define ICRCAN2ERRL        (*(volatile unsigned char  *)0xFFFFA1A2)
#define ICRCAN2ERRH        (*(volatile unsigned char  *)0xFFFFA1A3)
#define P0RCAN2ERR         (((volatile bitf_T *)0xFFFFA1A2)->bit00)
#define P1RCAN2ERR         (((volatile bitf_T *)0xFFFFA1A2)->bit01)
#define P2RCAN2ERR         (((volatile bitf_T *)0xFFFFA1A2)->bit02)
#define TBRCAN2ERR         (((volatile bitf_T *)0xFFFFA1A2)->bit06)
#define MKRCAN2ERR         (((volatile bitf_T *)0xFFFFA1A2)->bit07)
#define RFRCAN2ERR         (((volatile bitf_T *)0xFFFFA1A3)->bit04)
#define CTRCAN2ERR         (((volatile bitf_T *)0xFFFFA1A3)->bit07)
#define ICRCAN2REC         (*(volatile unsigned short *)0xFFFFA1A4)
#define ICRCAN2RECL        (*(volatile unsigned char  *)0xFFFFA1A4)
#define ICRCAN2RECH        (*(volatile unsigned char  *)0xFFFFA1A5)
#define P0RCAN2REC         (((volatile bitf_T *)0xFFFFA1A4)->bit00)
#define P1RCAN2REC         (((volatile bitf_T *)0xFFFFA1A4)->bit01)
#define P2RCAN2REC         (((volatile bitf_T *)0xFFFFA1A4)->bit02)
#define TBRCAN2REC         (((volatile bitf_T *)0xFFFFA1A4)->bit06)
#define MKRCAN2REC         (((volatile bitf_T *)0xFFFFA1A4)->bit07)
#define RFRCAN2REC         (((volatile bitf_T *)0xFFFFA1A5)->bit04)
#define CTRCAN2REC         (((volatile bitf_T *)0xFFFFA1A5)->bit07)
#define ICRCAN2TRX         (*(volatile unsigned short *)0xFFFFA1A6)
#define ICRCAN2TRXL        (*(volatile unsigned char  *)0xFFFFA1A6)
#define ICRCAN2TRXH        (*(volatile unsigned char  *)0xFFFFA1A7)
#define P0RCAN2TRX         (((volatile bitf_T *)0xFFFFA1A6)->bit00)
#define P1RCAN2TRX         (((volatile bitf_T *)0xFFFFA1A6)->bit01)
#define P2RCAN2TRX         (((volatile bitf_T *)0xFFFFA1A6)->bit02)
#define TBRCAN2TRX         (((volatile bitf_T *)0xFFFFA1A6)->bit06)
#define MKRCAN2TRX         (((volatile bitf_T *)0xFFFFA1A6)->bit07)
#define RFRCAN2TRX         (((volatile bitf_T *)0xFFFFA1A7)->bit04)
#define CTRCAN2TRX         (((volatile bitf_T *)0xFFFFA1A7)->bit07)
#define IMR1               (*(volatile unsigned long  *)0xFFFFA404)
#define IMR1L              (*(volatile unsigned short *)0xFFFFA404)
#define IMR1LL             (*(volatile unsigned char  *)0xFFFFA404)
#define IMR1LH             (*(volatile unsigned char  *)0xFFFFA405)
#define IMR1H              (*(volatile unsigned short *)0xFFFFA406)
#define IMR1HL             (*(volatile unsigned char  *)0xFFFFA406)
#define IMR1HH             (*(volatile unsigned char  *)0xFFFFA407)
#define IMR1EIMK32         (((volatile bitf_T *)0xFFFFA404)->bit00)
#define IMR1EIMK33         (((volatile bitf_T *)0xFFFFA404)->bit01)
#define IMR1EIMK34         (((volatile bitf_T *)0xFFFFA404)->bit02)
#define IMR1EIMK35         (((volatile bitf_T *)0xFFFFA404)->bit03)
#define IMR1EIMK36         (((volatile bitf_T *)0xFFFFA404)->bit04)
#define IMR1EIMK37         (((volatile bitf_T *)0xFFFFA404)->bit05)
#define IMR1EIMK38         (((volatile bitf_T *)0xFFFFA404)->bit06)
#define IMR1EIMK39         (((volatile bitf_T *)0xFFFFA404)->bit07)
#define IMR1EIMK40         (((volatile bitf_T *)0xFFFFA405)->bit00)
#define IMR1EIMK41         (((volatile bitf_T *)0xFFFFA405)->bit01)
#define IMR1EIMK42         (((volatile bitf_T *)0xFFFFA405)->bit02)
#define IMR1EIMK43         (((volatile bitf_T *)0xFFFFA405)->bit03)
#define IMR1EIMK44         (((volatile bitf_T *)0xFFFFA405)->bit04)
#define IMR1EIMK45         (((volatile bitf_T *)0xFFFFA405)->bit05)
#define IMR1EIMK46         (((volatile bitf_T *)0xFFFFA405)->bit06)
#define IMR1EIMK47         (((volatile bitf_T *)0xFFFFA405)->bit07)
#define IMR1EIMK49         (((volatile bitf_T *)0xFFFFA406)->bit01)
#define IMR1EIMK50         (((volatile bitf_T *)0xFFFFA406)->bit02)
#define IMR1EIMK51         (((volatile bitf_T *)0xFFFFA406)->bit03)
#define IMR1EIMK52         (((volatile bitf_T *)0xFFFFA406)->bit04)
#define IMR1EIMK53         (((volatile bitf_T *)0xFFFFA406)->bit05)
#define IMR1EIMK54         (((volatile bitf_T *)0xFFFFA406)->bit06)
#define IMR1EIMK55         (((volatile bitf_T *)0xFFFFA406)->bit07)
#define IMR1EIMK56         (((volatile bitf_T *)0xFFFFA407)->bit00)
#define IMR1EIMK57         (((volatile bitf_T *)0xFFFFA407)->bit01)
#define IMR1EIMK58         (((volatile bitf_T *)0xFFFFA407)->bit02)
#define IMR1EIMK59         (((volatile bitf_T *)0xFFFFA407)->bit03)
#define IMR1EIMK60         (((volatile bitf_T *)0xFFFFA407)->bit04)
#define IMR1EIMK61         (((volatile bitf_T *)0xFFFFA407)->bit05)
#define IMR1EIMK62         (((volatile bitf_T *)0xFFFFA407)->bit06)
#define IMR1EIMK63         (((volatile bitf_T *)0xFFFFA407)->bit07)
#define IMR2               (*(volatile unsigned long  *)0xFFFFA408)
#define IMR2L              (*(volatile unsigned short *)0xFFFFA408)
#define IMR2LL             (*(volatile unsigned char  *)0xFFFFA408)
#define IMR2LH             (*(volatile unsigned char  *)0xFFFFA409)
#define IMR2H              (*(volatile unsigned short *)0xFFFFA40A)
#define IMR2HL             (*(volatile unsigned char  *)0xFFFFA40A)
#define IMR2HH             (*(volatile unsigned char  *)0xFFFFA40B)
#define IMR2EIMK64         (((volatile bitf_T *)0xFFFFA408)->bit00)
#define IMR2EIMK65         (((volatile bitf_T *)0xFFFFA408)->bit01)
#define IMR2EIMK66         (((volatile bitf_T *)0xFFFFA408)->bit02)
#define IMR2EIMK67         (((volatile bitf_T *)0xFFFFA408)->bit03)
#define IMR2EIMK68         (((volatile bitf_T *)0xFFFFA408)->bit04)
#define IMR2EIMK69         (((volatile bitf_T *)0xFFFFA408)->bit05)
#define IMR2EIMK70         (((volatile bitf_T *)0xFFFFA408)->bit06)
#define IMR2EIMK71         (((volatile bitf_T *)0xFFFFA408)->bit07)
#define IMR2EIMK72         (((volatile bitf_T *)0xFFFFA409)->bit00)
#define IMR2EIMK73         (((volatile bitf_T *)0xFFFFA409)->bit01)
#define IMR2EIMK74         (((volatile bitf_T *)0xFFFFA409)->bit02)
#define IMR2EIMK75         (((volatile bitf_T *)0xFFFFA409)->bit03)
#define IMR2EIMK76         (((volatile bitf_T *)0xFFFFA409)->bit04)
#define IMR2EIMK77         (((volatile bitf_T *)0xFFFFA409)->bit05)
#define IMR2EIMK78         (((volatile bitf_T *)0xFFFFA409)->bit06)
#define IMR2EIMK79         (((volatile bitf_T *)0xFFFFA409)->bit07)
#define IMR2EIMK80         (((volatile bitf_T *)0xFFFFA40A)->bit00)
#define IMR2EIMK81         (((volatile bitf_T *)0xFFFFA40A)->bit01)
#define IMR2EIMK82         (((volatile bitf_T *)0xFFFFA40A)->bit02)
#define IMR2EIMK83         (((volatile bitf_T *)0xFFFFA40A)->bit03)
#define IMR2EIMK84         (((volatile bitf_T *)0xFFFFA40A)->bit04)
#define IMR2EIMK85         (((volatile bitf_T *)0xFFFFA40A)->bit05)
#define IMR2EIMK86         (((volatile bitf_T *)0xFFFFA40A)->bit06)
#define IMR2EIMK87         (((volatile bitf_T *)0xFFFFA40A)->bit07)
#define IMR2EIMK88         (((volatile bitf_T *)0xFFFFA40B)->bit00)
#define IMR2EIMK89         (((volatile bitf_T *)0xFFFFA40B)->bit01)
#define IMR2EIMK90         (((volatile bitf_T *)0xFFFFA40B)->bit02)
#define IMR2EIMK91         (((volatile bitf_T *)0xFFFFA40B)->bit03)
#define IMR2EIMK92         (((volatile bitf_T *)0xFFFFA40B)->bit04)
#define IMR2EIMK93         (((volatile bitf_T *)0xFFFFA40B)->bit05)
#define IMR2EIMK94         (((volatile bitf_T *)0xFFFFA40B)->bit06)
#define IMR2EIMK95         (((volatile bitf_T *)0xFFFFA40B)->bit07)
#define IMR3               (*(volatile unsigned long  *)0xFFFFA40C)
#define IMR3L              (*(volatile unsigned short *)0xFFFFA40C)
#define IMR3LL             (*(volatile unsigned char  *)0xFFFFA40C)
#define IMR3LH             (*(volatile unsigned char  *)0xFFFFA40D)
#define IMR3H              (*(volatile unsigned short *)0xFFFFA40E)
#define IMR3HL             (*(volatile unsigned char  *)0xFFFFA40E)
#define IMR3HH             (*(volatile unsigned char  *)0xFFFFA40F)
#define IMR3EIMK102        (((volatile bitf_T *)0xFFFFA40C)->bit06)
#define IMR3EIMK103        (((volatile bitf_T *)0xFFFFA40C)->bit07)
#define IMR3EIMK104        (((volatile bitf_T *)0xFFFFA40D)->bit00)
#define IMR3EIMK105        (((volatile bitf_T *)0xFFFFA40D)->bit01)
#define IMR3EIMK106        (((volatile bitf_T *)0xFFFFA40D)->bit02)
#define IMR3EIMK107        (((volatile bitf_T *)0xFFFFA40D)->bit03)
#define IMR3EIMK108        (((volatile bitf_T *)0xFFFFA40D)->bit04)
#define IMR3EIMK109        (((volatile bitf_T *)0xFFFFA40D)->bit05)
#define IMR3EIMK110        (((volatile bitf_T *)0xFFFFA40D)->bit06)
#define IMR3EIMK111        (((volatile bitf_T *)0xFFFFA40D)->bit07)
#define IMR3EIMK112        (((volatile bitf_T *)0xFFFFA40E)->bit00)
#define IMR3EIMK113        (((volatile bitf_T *)0xFFFFA40E)->bit01)
#define IMR3EIMK114        (((volatile bitf_T *)0xFFFFA40E)->bit02)
#define IMR3EIMK115        (((volatile bitf_T *)0xFFFFA40E)->bit03)
#define IMR3EIMK116        (((volatile bitf_T *)0xFFFFA40E)->bit04)
#define IMR3EIMK117        (((volatile bitf_T *)0xFFFFA40E)->bit05)
#define IMR3EIMK118        (((volatile bitf_T *)0xFFFFA40E)->bit06)
#define IMR3EIMK119        (((volatile bitf_T *)0xFFFFA40E)->bit07)
#define IMR3EIMK120        (((volatile bitf_T *)0xFFFFA40F)->bit00)
#define IMR3EIMK121        (((volatile bitf_T *)0xFFFFA40F)->bit01)
#define IMR3EIMK122        (((volatile bitf_T *)0xFFFFA40F)->bit02)
#define IMR3EIMK123        (((volatile bitf_T *)0xFFFFA40F)->bit03)
#define IMR3EIMK124        (((volatile bitf_T *)0xFFFFA40F)->bit04)
#define IMR3EIMK125        (((volatile bitf_T *)0xFFFFA40F)->bit05)
#define IMR3EIMK126        (((volatile bitf_T *)0xFFFFA40F)->bit06)
#define IMR3EIMK127        (((volatile bitf_T *)0xFFFFA40F)->bit07)
#define IMR4               (*(volatile unsigned long  *)0xFFFFA410)
#define IMR4L              (*(volatile unsigned short *)0xFFFFA410)
#define IMR4LH             (*(volatile unsigned char  *)0xFFFFA411)
#define IMR4H              (*(volatile unsigned short *)0xFFFFA412)
#define IMR4HH             (*(volatile unsigned char  *)0xFFFFA413)
#define IMR4EIMK137        (((volatile bitf_T *)0xFFFFA411)->bit01)
#define IMR4EIMK139        (((volatile bitf_T *)0xFFFFA411)->bit03)
#define IMR4EIMK141        (((volatile bitf_T *)0xFFFFA411)->bit05)
#define IMR4EIMK143        (((volatile bitf_T *)0xFFFFA411)->bit07)
#define IMR4EIMK156        (((volatile bitf_T *)0xFFFFA413)->bit04)
#define IMR4EIMK157        (((volatile bitf_T *)0xFFFFA413)->bit05)
#define IMR4EIMK158        (((volatile bitf_T *)0xFFFFA413)->bit06)
#define IMR4EIMK159        (((volatile bitf_T *)0xFFFFA413)->bit07)
#define IMR6               (*(volatile unsigned long  *)0xFFFFA418)
#define IMR6H              (*(volatile unsigned short *)0xFFFFA41A)
#define IMR6HL             (*(volatile unsigned char  *)0xFFFFA41A)
#define IMR6EIMK209        (((volatile bitf_T *)0xFFFFA41A)->bit01)
#define IMR6EIMK210        (((volatile bitf_T *)0xFFFFA41A)->bit02)
#define IMR6EIMK211        (((volatile bitf_T *)0xFFFFA41A)->bit03)

#define RIIC0   (*(volatile struct st_riic0   *)0xFFCA0000) /* RIIC0 */
#define RLN240  (*(volatile struct st_rln240  *)0xFFCE0000) /* RLN240 */
#define RLN2400 (*(volatile struct st_rln2400 *)0xFFCE0008) /* RLN2400 */
#define RLN2401 (*(volatile struct st_rln2401 *)0xFFCE0028) /* RLN2401 */
#define RLN30   (*(volatile struct st_rln30   *)0xFFCF0000) /* RLN30 */
#define RLN31   (*(volatile struct st_rln31   *)0xFFCF0040) /* RLN31 */
#define RLN32   (*(volatile struct st_rln32   *)0xFFCF0080) /* RLN32 */
#define RSCAN0  (*(volatile struct st_rscan0  *)0xFFD00000) /* RSCAN0 */
#define CSIH0   (*(volatile struct st_csih0   *)0xFFD80000) /* CSIH0 */
#define CSIH1   (*(volatile struct st_csih1   *)0xFFD82000) /* CSIH1 */
#define CSIH2   (*(volatile struct st_csih2   *)0xFFD84000) /* CSIH2 */
#define CSIG0   (*(volatile struct st_csig0   *)0xFFDB0000) /* CSIG0 */
#define PIC0    (*(volatile struct st_pic0    *)0xFFDD0004) /* PIC0 */
#define TAUD0   (*(volatile struct st_taud0   *)0xFFE20000) /* TAUD0 */
#define TAUJ0   (*(volatile struct st_tauj0   *)0xFFE50000) /* TAUJ0 */
#define PWSA0   (*(volatile struct st_pwsa0   *)0xFFE70000) /* PWSA0 */
#define PWGA0   (*(volatile struct st_pwga0   *)0xFFE71000) /* PWGA0 */
#define PWGA1   (*(volatile struct st_pwga1   *)0xFFE71040) /* PWGA1 */
#define PWGA2   (*(volatile struct st_pwga2   *)0xFFE71080) /* PWGA2 */
#define PWGA3   (*(volatile struct st_pwga3   *)0xFFE710C0) /* PWGA3 */
#define PWGA4   (*(volatile struct st_pwga4   *)0xFFE71100) /* PWGA4 */
#define PWGA5   (*(volatile struct st_pwga5   *)0xFFE71140) /* PWGA5 */
#define PWGA6   (*(volatile struct st_pwga6   *)0xFFE71180) /* PWGA6 */
#define PWGA7   (*(volatile struct st_pwga7   *)0xFFE711C0) /* PWGA7 */
#define PWGA8   (*(volatile struct st_pwga8   *)0xFFE71200) /* PWGA8 */
#define PWGA9   (*(volatile struct st_pwga9   *)0xFFE71240) /* PWGA9 */
#define PWGA10  (*(volatile struct st_pwga10  *)0xFFE71280) /* PWGA10 */
#define PWGA11  (*(volatile struct st_pwga11  *)0xFFE712C0) /* PWGA11 */
#define PWGA12  (*(volatile struct st_pwga12  *)0xFFE71300) /* PWGA12 */
#define PWGA13  (*(volatile struct st_pwga13  *)0xFFE71340) /* PWGA13 */
#define PWGA14  (*(volatile struct st_pwga14  *)0xFFE71380) /* PWGA14 */
#define PWGA15  (*(volatile struct st_pwga15  *)0xFFE713C0) /* PWGA15 */
#define PWGA16  (*(volatile struct st_pwga16  *)0xFFE71400) /* PWGA16 */
#define PWGA17  (*(volatile struct st_pwga17  *)0xFFE71440) /* PWGA17 */
#define PWGA18  (*(volatile struct st_pwga18  *)0xFFE71480) /* PWGA18 */
#define PWGA19  (*(volatile struct st_pwga19  *)0xFFE714C0) /* PWGA19 */
#define PWGA20  (*(volatile struct st_pwga20  *)0xFFE71500) /* PWGA20 */
#define PWGA21  (*(volatile struct st_pwga21  *)0xFFE71540) /* PWGA21 */
#define PWGA22  (*(volatile struct st_pwga22  *)0xFFE71580) /* PWGA22 */
#define PWGA23  (*(volatile struct st_pwga23  *)0xFFE715C0) /* PWGA23 */
#define PWBA0   (*(volatile struct st_pwba0   *)0xFFE72800) /* PWBA0 */
#define ENCA0   (*(volatile struct st_enca0   *)0xFFE80000) /* ENCA0 */
#define TAPA0   (*(volatile struct st_tapa0   *)0xFFE90000) /* TAPA0 */
#define OSTM0   (*(volatile struct st_ostm0   *)0xFFEC0000) /* OSTM0 */
#define WDTA0   (*(volatile struct st_wdta0   *)0xFFED0000) /* WDTA0 */
#define WDTA1   (*(volatile struct st_wdta1   *)0xFFED1000) /* WDTA1 */
#define ADCA0   (*(volatile struct st_adca0   *)0xFFF20000) /* ADCA0 */
#define DCRA0   (*(volatile struct st_dcra0   *)0xFFF70000) /* DCRA0 */
#define DCRA1   (*(volatile struct st_dcra1   *)0xFFF71000) /* DCRA1 */
#define DCRA2   (*(volatile struct st_dcra2   *)0xFFF72000) /* DCRA2 */
#define DCRA3   (*(volatile struct st_dcra3   *)0xFFF73000) /* DCRA3 */
#define KR0     (*(volatile struct st_kr0     *)0xFFF78000) /* KR0 */
#define CLMA0   (*(volatile struct st_clma0   *)0xFFF8C000) /* CLMA0 */
#define CLMA    (*(volatile struct st_clma    *)0xFFF8C100) /* CLMA */
#define CLMA1   (*(volatile struct st_clma1   *)0xFFF8D000) /* CLMA1 */
#define CLMA2   (*(volatile struct st_clma2   *)0xFFF8E000) /* CLMA2 */

#define RIIC0CR1 RIIC0.CR1.UINT32
#define RIIC0CR1L RIIC0.CR1.UINT16[L]
#define RIIC0CR1LL RIIC0.CR1.UINT8[LL]
#define RIIC0CR1LH RIIC0.CR1.UINT8[LH]
#define RIIC0CR1H RIIC0.CR1.UINT16[H]
#define RIIC0CR1HL RIIC0.CR1.UINT8[HL]
#define RIIC0CR1HH RIIC0.CR1.UINT8[HH]
#define RIIC0CR2 RIIC0.CR2.UINT32
#define RIIC0CR2L RIIC0.CR2.UINT16[L]
#define RIIC0CR2LL RIIC0.CR2.UINT8[LL]
#define RIIC0CR2LH RIIC0.CR2.UINT8[LH]
#define RIIC0CR2H RIIC0.CR2.UINT16[H]
#define RIIC0CR2HL RIIC0.CR2.UINT8[HL]
#define RIIC0CR2HH RIIC0.CR2.UINT8[HH]
#define RIIC0MR1 RIIC0.MR1.UINT32
#define RIIC0MR1L RIIC0.MR1.UINT16[L]
#define RIIC0MR1LL RIIC0.MR1.UINT8[LL]
#define RIIC0MR1LH RIIC0.MR1.UINT8[LH]
#define RIIC0MR1H RIIC0.MR1.UINT16[H]
#define RIIC0MR1HL RIIC0.MR1.UINT8[HL]
#define RIIC0MR1HH RIIC0.MR1.UINT8[HH]
#define RIIC0MR2 RIIC0.MR2.UINT32
#define RIIC0MR2L RIIC0.MR2.UINT16[L]
#define RIIC0MR2LL RIIC0.MR2.UINT8[LL]
#define RIIC0MR2LH RIIC0.MR2.UINT8[LH]
#define RIIC0MR2H RIIC0.MR2.UINT16[H]
#define RIIC0MR2HL RIIC0.MR2.UINT8[HL]
#define RIIC0MR2HH RIIC0.MR2.UINT8[HH]
#define RIIC0MR3 RIIC0.MR3.UINT32
#define RIIC0MR3L RIIC0.MR3.UINT16[L]
#define RIIC0MR3LL RIIC0.MR3.UINT8[LL]
#define RIIC0MR3LH RIIC0.MR3.UINT8[LH]
#define RIIC0MR3H RIIC0.MR3.UINT16[H]
#define RIIC0MR3HL RIIC0.MR3.UINT8[HL]
#define RIIC0MR3HH RIIC0.MR3.UINT8[HH]
#define RIIC0FER RIIC0.FER.UINT32
#define RIIC0FERL RIIC0.FER.UINT16[L]
#define RIIC0FERLL RIIC0.FER.UINT8[LL]
#define RIIC0FERLH RIIC0.FER.UINT8[LH]
#define RIIC0FERH RIIC0.FER.UINT16[H]
#define RIIC0FERHL RIIC0.FER.UINT8[HL]
#define RIIC0FERHH RIIC0.FER.UINT8[HH]
#define RIIC0SER RIIC0.SER.UINT32
#define RIIC0SERL RIIC0.SER.UINT16[L]
#define RIIC0SERLL RIIC0.SER.UINT8[LL]
#define RIIC0SERLH RIIC0.SER.UINT8[LH]
#define RIIC0SERH RIIC0.SER.UINT16[H]
#define RIIC0SERHL RIIC0.SER.UINT8[HL]
#define RIIC0SERHH RIIC0.SER.UINT8[HH]
#define RIIC0IER RIIC0.IER.UINT32
#define RIIC0IERL RIIC0.IER.UINT16[L]
#define RIIC0IERLL RIIC0.IER.UINT8[LL]
#define RIIC0IERLH RIIC0.IER.UINT8[LH]
#define RIIC0IERH RIIC0.IER.UINT16[H]
#define RIIC0IERHL RIIC0.IER.UINT8[HL]
#define RIIC0IERHH RIIC0.IER.UINT8[HH]
#define RIIC0SR1 RIIC0.SR1.UINT32
#define RIIC0SR1L RIIC0.SR1.UINT16[L]
#define RIIC0SR1LL RIIC0.SR1.UINT8[LL]
#define RIIC0SR1LH RIIC0.SR1.UINT8[LH]
#define RIIC0SR1H RIIC0.SR1.UINT16[H]
#define RIIC0SR1HL RIIC0.SR1.UINT8[HL]
#define RIIC0SR1HH RIIC0.SR1.UINT8[HH]
#define RIIC0AAS0 RIIC0.SR1.BIT.AAS0
#define RIIC0AAS1 RIIC0.SR1.BIT.AAS1
#define RIIC0AAS2 RIIC0.SR1.BIT.AAS2
#define RIIC0GCA RIIC0.SR1.BIT.GCA
#define RIIC0DID RIIC0.SR1.BIT.DID
#define RIIC0HOA RIIC0.SR1.BIT.HOA
#define RIIC0SR2 RIIC0.SR2.UINT32
#define RIIC0SR2L RIIC0.SR2.UINT16[L]
#define RIIC0SR2LL RIIC0.SR2.UINT8[LL]
#define RIIC0SR2LH RIIC0.SR2.UINT8[LH]
#define RIIC0SR2H RIIC0.SR2.UINT16[H]
#define RIIC0SR2HL RIIC0.SR2.UINT8[HL]
#define RIIC0SR2HH RIIC0.SR2.UINT8[HH]
#define RIIC0TMOF RIIC0.SR2.BIT.TMOF
#define RIIC0AL RIIC0.SR2.BIT.AL
#define RIIC0START RIIC0.SR2.BIT.START
#define RIIC0STOP RIIC0.SR2.BIT.STOP
#define RIIC0NACKF RIIC0.SR2.BIT.NACKF
#define RIIC0RDRF RIIC0.SR2.BIT.RDRF
#define RIIC0TEND RIIC0.SR2.BIT.TEND
#define RIIC0TDRE RIIC0.SR2.BIT.TDRE
#define RIIC0SAR0 RIIC0.SAR0.UINT32
#define RIIC0SAR0L RIIC0.SAR0.UINT16[L]
#define RIIC0SAR0LL RIIC0.SAR0.UINT8[LL]
#define RIIC0SAR0LH RIIC0.SAR0.UINT8[LH]
#define RIIC0SAR0H RIIC0.SAR0.UINT16[H]
#define RIIC0SAR0HL RIIC0.SAR0.UINT8[HL]
#define RIIC0SAR0HH RIIC0.SAR0.UINT8[HH]
#define RIIC0SAR1 RIIC0.SAR1.UINT32
#define RIIC0SAR1L RIIC0.SAR1.UINT16[L]
#define RIIC0SAR1LL RIIC0.SAR1.UINT8[LL]
#define RIIC0SAR1LH RIIC0.SAR1.UINT8[LH]
#define RIIC0SAR1H RIIC0.SAR1.UINT16[H]
#define RIIC0SAR1HL RIIC0.SAR1.UINT8[HL]
#define RIIC0SAR1HH RIIC0.SAR1.UINT8[HH]
#define RIIC0SAR2 RIIC0.SAR2.UINT32
#define RIIC0SAR2L RIIC0.SAR2.UINT16[L]
#define RIIC0SAR2LL RIIC0.SAR2.UINT8[LL]
#define RIIC0SAR2LH RIIC0.SAR2.UINT8[LH]
#define RIIC0SAR2H RIIC0.SAR2.UINT16[H]
#define RIIC0SAR2HL RIIC0.SAR2.UINT8[HL]
#define RIIC0SAR2HH RIIC0.SAR2.UINT8[HH]
#define RIIC0BRL RIIC0.BRL.UINT32
#define RIIC0BRLL RIIC0.BRL.UINT16[L]
#define RIIC0BRLLL RIIC0.BRL.UINT8[LL]
#define RIIC0BRLLH RIIC0.BRL.UINT8[LH]
#define RIIC0BRLH RIIC0.BRL.UINT16[H]
#define RIIC0BRLHL RIIC0.BRL.UINT8[HL]
#define RIIC0BRLHH RIIC0.BRL.UINT8[HH]
#define RIIC0BRH RIIC0.BRH.UINT32
#define RIIC0BRHL RIIC0.BRH.UINT16[L]
#define RIIC0BRHLL RIIC0.BRH.UINT8[LL]
#define RIIC0BRHLH RIIC0.BRH.UINT8[LH]
#define RIIC0BRHH RIIC0.BRH.UINT16[H]
#define RIIC0BRHHL RIIC0.BRH.UINT8[HL]
#define RIIC0BRHHH RIIC0.BRH.UINT8[HH]
#define RIIC0DRT RIIC0.DRT.UINT32
#define RIIC0DRTL RIIC0.DRT.UINT16[L]
#define RIIC0DRTLL RIIC0.DRT.UINT8[LL]
#define RIIC0DRTLH RIIC0.DRT.UINT8[LH]
#define RIIC0DRTH RIIC0.DRT.UINT16[H]
#define RIIC0DRTHL RIIC0.DRT.UINT8[HL]
#define RIIC0DRTHH RIIC0.DRT.UINT8[HH]
#define RIIC0DRR RIIC0.DRR.UINT32
#define RIIC0DRRL RIIC0.DRR.UINT16[L]
#define RIIC0DRRLL RIIC0.DRR.UINT8[LL]
#define RIIC0DRRLH RIIC0.DRR.UINT8[LH]
#define RIIC0DRRH RIIC0.DRR.UINT16[H]
#define RIIC0DRRHL RIIC0.DRR.UINT8[HL]
#define RIIC0DRRHH RIIC0.DRR.UINT8[HH]
#define RLN240GLWBR RLN240.GLWBR
#define RLN240GLBRP0 RLN240.GLBRP0
#define RLN240GLBRP1 RLN240.GLBRP1
#define RLN240GLSTC RLN240.GLSTC
#define RLN2400L0MD RLN2400.L0MD
#define RLN2400L0BFC RLN2400.L0BFC
#define RLN2400L0SC RLN2400.L0SC
#define RLN2400L0WUP RLN2400.L0WUP
#define RLN2400L0IE RLN2400.L0IE
#define RLN2400L0EDE RLN2400.L0EDE
#define RLN2400L0CUC RLN2400.L0CUC
#define RLN2400L0TRC RLN2400.L0TRC
#define RLN2400L0MST RLN2400.L0MST
#define RLN2400L0ST RLN2400.L0ST
#define RLN2400L0EST RLN2400.L0EST
#define RLN2400L0DFC RLN2400.L0DFC
#define RLN2400L0IDB RLN2400.L0IDB
#define RLN2400L0CBR RLN2400.L0CBR
#define RLN2400L0DBR1 RLN2400.L0DBR1
#define RLN2400L0DBR2 RLN2400.L0DBR2
#define RLN2400L0DBR3 RLN2400.L0DBR3
#define RLN2400L0DBR4 RLN2400.L0DBR4
#define RLN2400L0DBR5 RLN2400.L0DBR5
#define RLN2400L0DBR6 RLN2400.L0DBR6
#define RLN2400L0DBR7 RLN2400.L0DBR7
#define RLN2400L0DBR8 RLN2400.L0DBR8
#define RLN2401L1MD RLN2401.L1MD
#define RLN2401L1BFC RLN2401.L1BFC
#define RLN2401L1SC RLN2401.L1SC
#define RLN2401L1WUP RLN2401.L1WUP
#define RLN2401L1IE RLN2401.L1IE
#define RLN2401L1EDE RLN2401.L1EDE
#define RLN2401L1CUC RLN2401.L1CUC
#define RLN2401L1TRC RLN2401.L1TRC
#define RLN2401L1MST RLN2401.L1MST
#define RLN2401L1ST RLN2401.L1ST
#define RLN2401L1EST RLN2401.L1EST
#define RLN2401L1DFC RLN2401.L1DFC
#define RLN2401L1IDB RLN2401.L1IDB
#define RLN2401L1CBR RLN2401.L1CBR
#define RLN2401L1DBR1 RLN2401.L1DBR1
#define RLN2401L1DBR2 RLN2401.L1DBR2
#define RLN2401L1DBR3 RLN2401.L1DBR3
#define RLN2401L1DBR4 RLN2401.L1DBR4
#define RLN2401L1DBR5 RLN2401.L1DBR5
#define RLN2401L1DBR6 RLN2401.L1DBR6
#define RLN2401L1DBR7 RLN2401.L1DBR7
#define RLN2401L1DBR8 RLN2401.L1DBR8
#define RLN30LWBR RLN30.LWBR
#define RLN30LBRP01 RLN30.LBRP01.UINT16
#define RLN30LBRP0 RLN30.LBRP01.UINT8[L]
#define RLN30LBRP1 RLN30.LBRP01.UINT8[H]
#define RLN30LSTC RLN30.LSTC
#define RLN30LMD RLN30.LMD
#define RLN30LBFC RLN30.LBFC
#define RLN30LSC RLN30.LSC
#define RLN30LWUP RLN30.LWUP
#define RLN30LIE RLN30.LIE
#define RLN30LEDE RLN30.LEDE
#define RLN30LCUC RLN30.LCUC
#define RLN30LTRC RLN30.LTRC
#define RLN30LMST RLN30.LMST
#define RLN30LST RLN30.LST
#define RLN30LEST RLN30.LEST
#define RLN30LDFC RLN30.LDFC
#define RLN30LIDB RLN30.LIDB
#define RLN30LCBR RLN30.LCBR
#define RLN30LUDB0 RLN30.LUDB0
#define RLN30LDBR1 RLN30.LDBR1
#define RLN30LDBR2 RLN30.LDBR2
#define RLN30LDBR3 RLN30.LDBR3
#define RLN30LDBR4 RLN30.LDBR4
#define RLN30LDBR5 RLN30.LDBR5
#define RLN30LDBR6 RLN30.LDBR6
#define RLN30LDBR7 RLN30.LDBR7
#define RLN30LDBR8 RLN30.LDBR8
#define RLN30LUOER RLN30.LUOER
#define RLN30LUOR1 RLN30.LUOR1
#define RLN30LUTDR RLN30.LUTDR.UINT16
#define RLN30LUTDRL RLN30.LUTDR.UINT8[L]
#define RLN30LUTDRH RLN30.LUTDR.UINT8[H]
#define RLN30LURDR RLN30.LURDR.UINT16
#define RLN30LURDRL RLN30.LURDR.UINT8[L]
#define RLN30LURDRH RLN30.LURDR.UINT8[H]
#define RLN30LUWTDR RLN30.LUWTDR.UINT16
#define RLN30LUWTDRL RLN30.LUWTDR.UINT8[L]
#define RLN30LUWTDRH RLN30.LUWTDR.UINT8[H]
#define RLN31LWBR RLN31.LWBR
#define RLN31LBRP01 RLN31.LBRP01.UINT16
#define RLN31LBRP0 RLN31.LBRP01.UINT8[L]
#define RLN31LBRP1 RLN31.LBRP01.UINT8[H]
#define RLN31LSTC RLN31.LSTC
#define RLN31LMD RLN31.LMD
#define RLN31LBFC RLN31.LBFC
#define RLN31LSC RLN31.LSC
#define RLN31LWUP RLN31.LWUP
#define RLN31LIE RLN31.LIE
#define RLN31LEDE RLN31.LEDE
#define RLN31LCUC RLN31.LCUC
#define RLN31LTRC RLN31.LTRC
#define RLN31LMST RLN31.LMST
#define RLN31LST RLN31.LST
#define RLN31LEST RLN31.LEST
#define RLN31LDFC RLN31.LDFC
#define RLN31LIDB RLN31.LIDB
#define RLN31LCBR RLN31.LCBR
#define RLN31LUDB0 RLN31.LUDB0
#define RLN31LDBR1 RLN31.LDBR1
#define RLN31LDBR2 RLN31.LDBR2
#define RLN31LDBR3 RLN31.LDBR3
#define RLN31LDBR4 RLN31.LDBR4
#define RLN31LDBR5 RLN31.LDBR5
#define RLN31LDBR6 RLN31.LDBR6
#define RLN31LDBR7 RLN31.LDBR7
#define RLN31LDBR8 RLN31.LDBR8
#define RLN31LUOER RLN31.LUOER
#define RLN31LUOR1 RLN31.LUOR1
#define RLN31LUTDR RLN31.LUTDR.UINT16
#define RLN31LUTDRL RLN31.LUTDR.UINT8[L]
#define RLN31LUTDRH RLN31.LUTDR.UINT8[H]
#define RLN31LURDR RLN31.LURDR.UINT16
#define RLN31LURDRL RLN31.LURDR.UINT8[L]
#define RLN31LURDRH RLN31.LURDR.UINT8[H]
#define RLN31LUWTDR RLN31.LUWTDR.UINT16
#define RLN31LUWTDRL RLN31.LUWTDR.UINT8[L]
#define RLN31LUWTDRH RLN31.LUWTDR.UINT8[H]
#define RLN32LWBR RLN32.LWBR
#define RLN32LBRP01 RLN32.LBRP01.UINT16
#define RLN32LBRP0 RLN32.LBRP01.UINT8[L]
#define RLN32LBRP1 RLN32.LBRP01.UINT8[H]
#define RLN32LSTC RLN32.LSTC
#define RLN32LMD RLN32.LMD
#define RLN32LBFC RLN32.LBFC
#define RLN32LSC RLN32.LSC
#define RLN32LWUP RLN32.LWUP
#define RLN32LIE RLN32.LIE
#define RLN32LEDE RLN32.LEDE
#define RLN32LCUC RLN32.LCUC
#define RLN32LTRC RLN32.LTRC
#define RLN32LMST RLN32.LMST
#define RLN32LST RLN32.LST
#define RLN32LEST RLN32.LEST
#define RLN32LDFC RLN32.LDFC
#define RLN32LIDB RLN32.LIDB
#define RLN32LCBR RLN32.LCBR
#define RLN32LUDB0 RLN32.LUDB0
#define RLN32LDBR1 RLN32.LDBR1
#define RLN32LDBR2 RLN32.LDBR2
#define RLN32LDBR3 RLN32.LDBR3
#define RLN32LDBR4 RLN32.LDBR4
#define RLN32LDBR5 RLN32.LDBR5
#define RLN32LDBR6 RLN32.LDBR6
#define RLN32LDBR7 RLN32.LDBR7
#define RLN32LDBR8 RLN32.LDBR8
#define RLN32LUOER RLN32.LUOER
#define RLN32LUOR1 RLN32.LUOR1
#define RLN32LUTDR RLN32.LUTDR.UINT16
#define RLN32LUTDRL RLN32.LUTDR.UINT8[L]
#define RLN32LUTDRH RLN32.LUTDR.UINT8[H]
#define RLN32LURDR RLN32.LURDR.UINT16
#define RLN32LURDRL RLN32.LURDR.UINT8[L]
#define RLN32LURDRH RLN32.LURDR.UINT8[H]
#define RLN32LUWTDR RLN32.LUWTDR.UINT16
#define RLN32LUWTDRL RLN32.LUWTDR.UINT8[L]
#define RLN32LUWTDRH RLN32.LUWTDR.UINT8[H]
#define RSCAN0C0CFG RSCAN0.C0CFG.UINT32
#define RSCAN0C0CFGL RSCAN0.C0CFG.UINT16[L]
#define RSCAN0C0CFGLL RSCAN0.C0CFG.UINT8[LL]
#define RSCAN0C0CFGLH RSCAN0.C0CFG.UINT8[LH]
#define RSCAN0C0CFGH RSCAN0.C0CFG.UINT16[H]
#define RSCAN0C0CFGHL RSCAN0.C0CFG.UINT8[HL]
#define RSCAN0C0CFGHH RSCAN0.C0CFG.UINT8[HH]
#define RSCAN0C0CTR RSCAN0.C0CTR.UINT32
#define RSCAN0C0CTRL RSCAN0.C0CTR.UINT16[L]
#define RSCAN0C0CTRLL RSCAN0.C0CTR.UINT8[LL]
#define RSCAN0C0CTRLH RSCAN0.C0CTR.UINT8[LH]
#define RSCAN0C0CTRH RSCAN0.C0CTR.UINT16[H]
#define RSCAN0C0CTRHL RSCAN0.C0CTR.UINT8[HL]
#define RSCAN0C0CTRHH RSCAN0.C0CTR.UINT8[HH]
#define RSCAN0C0STS RSCAN0.C0STS.UINT32
#define RSCAN0C0STSL RSCAN0.C0STS.UINT16[L]
#define RSCAN0C0STSLL RSCAN0.C0STS.UINT8[LL]
#define RSCAN0C0STSLH RSCAN0.C0STS.UINT8[LH]
#define RSCAN0C0STSH RSCAN0.C0STS.UINT16[H]
#define RSCAN0C0STSHL RSCAN0.C0STS.UINT8[HL]
#define RSCAN0C0STSHH RSCAN0.C0STS.UINT8[HH]
#define RSCAN0C0ERFL RSCAN0.C0ERFL.UINT32
#define RSCAN0C0ERFLL RSCAN0.C0ERFL.UINT16[L]
#define RSCAN0C0ERFLLL RSCAN0.C0ERFL.UINT8[LL]
#define RSCAN0C0ERFLLH RSCAN0.C0ERFL.UINT8[LH]
#define RSCAN0C0ERFLH RSCAN0.C0ERFL.UINT16[H]
#define RSCAN0C0ERFLHL RSCAN0.C0ERFL.UINT8[HL]
#define RSCAN0C0ERFLHH RSCAN0.C0ERFL.UINT8[HH]
#define RSCAN0C1CFG RSCAN0.C1CFG.UINT32
#define RSCAN0C1CFGL RSCAN0.C1CFG.UINT16[L]
#define RSCAN0C1CFGLL RSCAN0.C1CFG.UINT8[LL]
#define RSCAN0C1CFGLH RSCAN0.C1CFG.UINT8[LH]
#define RSCAN0C1CFGH RSCAN0.C1CFG.UINT16[H]
#define RSCAN0C1CFGHL RSCAN0.C1CFG.UINT8[HL]
#define RSCAN0C1CFGHH RSCAN0.C1CFG.UINT8[HH]
#define RSCAN0C1CTR RSCAN0.C1CTR.UINT32
#define RSCAN0C1CTRL RSCAN0.C1CTR.UINT16[L]
#define RSCAN0C1CTRLL RSCAN0.C1CTR.UINT8[LL]
#define RSCAN0C1CTRLH RSCAN0.C1CTR.UINT8[LH]
#define RSCAN0C1CTRH RSCAN0.C1CTR.UINT16[H]
#define RSCAN0C1CTRHL RSCAN0.C1CTR.UINT8[HL]
#define RSCAN0C1CTRHH RSCAN0.C1CTR.UINT8[HH]
#define RSCAN0C1STS RSCAN0.C1STS.UINT32
#define RSCAN0C1STSL RSCAN0.C1STS.UINT16[L]
#define RSCAN0C1STSLL RSCAN0.C1STS.UINT8[LL]
#define RSCAN0C1STSLH RSCAN0.C1STS.UINT8[LH]
#define RSCAN0C1STSH RSCAN0.C1STS.UINT16[H]
#define RSCAN0C1STSHL RSCAN0.C1STS.UINT8[HL]
#define RSCAN0C1STSHH RSCAN0.C1STS.UINT8[HH]
#define RSCAN0C1ERFL RSCAN0.C1ERFL.UINT32
#define RSCAN0C1ERFLL RSCAN0.C1ERFL.UINT16[L]
#define RSCAN0C1ERFLLL RSCAN0.C1ERFL.UINT8[LL]
#define RSCAN0C1ERFLLH RSCAN0.C1ERFL.UINT8[LH]
#define RSCAN0C1ERFLH RSCAN0.C1ERFL.UINT16[H]
#define RSCAN0C1ERFLHL RSCAN0.C1ERFL.UINT8[HL]
#define RSCAN0C1ERFLHH RSCAN0.C1ERFL.UINT8[HH]
#define RSCAN0C2CFG RSCAN0.C2CFG.UINT32
#define RSCAN0C2CFGL RSCAN0.C2CFG.UINT16[L]
#define RSCAN0C2CFGLL RSCAN0.C2CFG.UINT8[LL]
#define RSCAN0C2CFGLH RSCAN0.C2CFG.UINT8[LH]
#define RSCAN0C2CFGH RSCAN0.C2CFG.UINT16[H]
#define RSCAN0C2CFGHL RSCAN0.C2CFG.UINT8[HL]
#define RSCAN0C2CFGHH RSCAN0.C2CFG.UINT8[HH]
#define RSCAN0C2CTR RSCAN0.C2CTR.UINT32
#define RSCAN0C2CTRL RSCAN0.C2CTR.UINT16[L]
#define RSCAN0C2CTRLL RSCAN0.C2CTR.UINT8[LL]
#define RSCAN0C2CTRLH RSCAN0.C2CTR.UINT8[LH]
#define RSCAN0C2CTRH RSCAN0.C2CTR.UINT16[H]
#define RSCAN0C2CTRHL RSCAN0.C2CTR.UINT8[HL]
#define RSCAN0C2CTRHH RSCAN0.C2CTR.UINT8[HH]
#define RSCAN0C2STS RSCAN0.C2STS.UINT32
#define RSCAN0C2STSL RSCAN0.C2STS.UINT16[L]
#define RSCAN0C2STSLL RSCAN0.C2STS.UINT8[LL]
#define RSCAN0C2STSLH RSCAN0.C2STS.UINT8[LH]
#define RSCAN0C2STSH RSCAN0.C2STS.UINT16[H]
#define RSCAN0C2STSHL RSCAN0.C2STS.UINT8[HL]
#define RSCAN0C2STSHH RSCAN0.C2STS.UINT8[HH]
#define RSCAN0C2ERFL RSCAN0.C2ERFL.UINT32
#define RSCAN0C2ERFLL RSCAN0.C2ERFL.UINT16[L]
#define RSCAN0C2ERFLLL RSCAN0.C2ERFL.UINT8[LL]
#define RSCAN0C2ERFLLH RSCAN0.C2ERFL.UINT8[LH]
#define RSCAN0C2ERFLH RSCAN0.C2ERFL.UINT16[H]
#define RSCAN0C2ERFLHL RSCAN0.C2ERFL.UINT8[HL]
#define RSCAN0C2ERFLHH RSCAN0.C2ERFL.UINT8[HH]
#define RSCAN0GCFG RSCAN0.GCFG.UINT32
#define RSCAN0GCFGL RSCAN0.GCFG.UINT16[L]
#define RSCAN0GCFGLL RSCAN0.GCFG.UINT8[LL]
#define RSCAN0GCFGLH RSCAN0.GCFG.UINT8[LH]
#define RSCAN0GCFGH RSCAN0.GCFG.UINT16[H]
#define RSCAN0GCFGHL RSCAN0.GCFG.UINT8[HL]
#define RSCAN0GCFGHH RSCAN0.GCFG.UINT8[HH]
#define RSCAN0GCTR RSCAN0.GCTR.UINT32
#define RSCAN0GCTRL RSCAN0.GCTR.UINT16[L]
#define RSCAN0GCTRLL RSCAN0.GCTR.UINT8[LL]
#define RSCAN0GCTRLH RSCAN0.GCTR.UINT8[LH]
#define RSCAN0GCTRH RSCAN0.GCTR.UINT16[H]
#define RSCAN0GCTRHL RSCAN0.GCTR.UINT8[HL]
#define RSCAN0GCTRHH RSCAN0.GCTR.UINT8[HH]
#define RSCAN0GSTS RSCAN0.GSTS.UINT32
#define RSCAN0GSTSL RSCAN0.GSTS.UINT16[L]
#define RSCAN0GSTSLL RSCAN0.GSTS.UINT8[LL]
#define RSCAN0GSTSLH RSCAN0.GSTS.UINT8[LH]
#define RSCAN0GSTSH RSCAN0.GSTS.UINT16[H]
#define RSCAN0GSTSHL RSCAN0.GSTS.UINT8[HL]
#define RSCAN0GSTSHH RSCAN0.GSTS.UINT8[HH]
#define RSCAN0GERFL RSCAN0.GERFL.UINT32
#define RSCAN0GERFLL RSCAN0.GERFL.UINT16[L]
#define RSCAN0GERFLLL RSCAN0.GERFL.UINT8[LL]
#define RSCAN0GERFLLH RSCAN0.GERFL.UINT8[LH]
#define RSCAN0GERFLH RSCAN0.GERFL.UINT16[H]
#define RSCAN0GERFLHL RSCAN0.GERFL.UINT8[HL]
#define RSCAN0GERFLHH RSCAN0.GERFL.UINT8[HH]
#define RSCAN0GTSC RSCAN0.GTSC.UINT32
#define RSCAN0GTSCL RSCAN0.GTSC.UINT16[L]
#define RSCAN0GTSCLL RSCAN0.GTSC.UINT8[LL]
#define RSCAN0GTSCLH RSCAN0.GTSC.UINT8[LH]
#define RSCAN0GTSCH RSCAN0.GTSC.UINT16[H]
#define RSCAN0GTSCHL RSCAN0.GTSC.UINT8[HL]
#define RSCAN0GTSCHH RSCAN0.GTSC.UINT8[HH]
#define RSCAN0GAFLECTR RSCAN0.GAFLECTR.UINT32
#define RSCAN0GAFLECTRL RSCAN0.GAFLECTR.UINT16[L]
#define RSCAN0GAFLECTRLL RSCAN0.GAFLECTR.UINT8[LL]
#define RSCAN0GAFLECTRLH RSCAN0.GAFLECTR.UINT8[LH]
#define RSCAN0GAFLECTRH RSCAN0.GAFLECTR.UINT16[H]
#define RSCAN0GAFLECTRHL RSCAN0.GAFLECTR.UINT8[HL]
#define RSCAN0GAFLECTRHH RSCAN0.GAFLECTR.UINT8[HH]
#define RSCAN0GAFLCFG0 RSCAN0.GAFLCFG0.UINT32
#define RSCAN0GAFLCFG0L RSCAN0.GAFLCFG0.UINT16[L]
#define RSCAN0GAFLCFG0LL RSCAN0.GAFLCFG0.UINT8[LL]
#define RSCAN0GAFLCFG0LH RSCAN0.GAFLCFG0.UINT8[LH]
#define RSCAN0GAFLCFG0H RSCAN0.GAFLCFG0.UINT16[H]
#define RSCAN0GAFLCFG0HL RSCAN0.GAFLCFG0.UINT8[HL]
#define RSCAN0GAFLCFG0HH RSCAN0.GAFLCFG0.UINT8[HH]
#define RSCAN0RMNB RSCAN0.RMNB.UINT32
#define RSCAN0RMNBL RSCAN0.RMNB.UINT16[L]
#define RSCAN0RMNBLL RSCAN0.RMNB.UINT8[LL]
#define RSCAN0RMNBLH RSCAN0.RMNB.UINT8[LH]
#define RSCAN0RMNBH RSCAN0.RMNB.UINT16[H]
#define RSCAN0RMNBHL RSCAN0.RMNB.UINT8[HL]
#define RSCAN0RMNBHH RSCAN0.RMNB.UINT8[HH]
#define RSCAN0RMND0 RSCAN0.RMND0.UINT32
#define RSCAN0RMND0L RSCAN0.RMND0.UINT16[L]
#define RSCAN0RMND0LL RSCAN0.RMND0.UINT8[LL]
#define RSCAN0RMND0LH RSCAN0.RMND0.UINT8[LH]
#define RSCAN0RMND0H RSCAN0.RMND0.UINT16[H]
#define RSCAN0RMND0HL RSCAN0.RMND0.UINT8[HL]
#define RSCAN0RMND0HH RSCAN0.RMND0.UINT8[HH]
#define RSCAN0RMND1 RSCAN0.RMND1.UINT32
#define RSCAN0RMND1L RSCAN0.RMND1.UINT16[L]
#define RSCAN0RMND1LL RSCAN0.RMND1.UINT8[LL]
#define RSCAN0RMND1LH RSCAN0.RMND1.UINT8[LH]
#define RSCAN0RMND1H RSCAN0.RMND1.UINT16[H]
#define RSCAN0RMND1HL RSCAN0.RMND1.UINT8[HL]
#define RSCAN0RMND1HH RSCAN0.RMND1.UINT8[HH]
#define RSCAN0RFCC0 RSCAN0.RFCC0.UINT32
#define RSCAN0RFCC0L RSCAN0.RFCC0.UINT16[L]
#define RSCAN0RFCC0LL RSCAN0.RFCC0.UINT8[LL]
#define RSCAN0RFCC0LH RSCAN0.RFCC0.UINT8[LH]
#define RSCAN0RFCC0H RSCAN0.RFCC0.UINT16[H]
#define RSCAN0RFCC0HL RSCAN0.RFCC0.UINT8[HL]
#define RSCAN0RFCC0HH RSCAN0.RFCC0.UINT8[HH]
#define RSCAN0RFCC1 RSCAN0.RFCC1.UINT32
#define RSCAN0RFCC1L RSCAN0.RFCC1.UINT16[L]
#define RSCAN0RFCC1LL RSCAN0.RFCC1.UINT8[LL]
#define RSCAN0RFCC1LH RSCAN0.RFCC1.UINT8[LH]
#define RSCAN0RFCC1H RSCAN0.RFCC1.UINT16[H]
#define RSCAN0RFCC1HL RSCAN0.RFCC1.UINT8[HL]
#define RSCAN0RFCC1HH RSCAN0.RFCC1.UINT8[HH]
#define RSCAN0RFCC2 RSCAN0.RFCC2.UINT32
#define RSCAN0RFCC2L RSCAN0.RFCC2.UINT16[L]
#define RSCAN0RFCC2LL RSCAN0.RFCC2.UINT8[LL]
#define RSCAN0RFCC2LH RSCAN0.RFCC2.UINT8[LH]
#define RSCAN0RFCC2H RSCAN0.RFCC2.UINT16[H]
#define RSCAN0RFCC2HL RSCAN0.RFCC2.UINT8[HL]
#define RSCAN0RFCC2HH RSCAN0.RFCC2.UINT8[HH]
#define RSCAN0RFCC3 RSCAN0.RFCC3.UINT32
#define RSCAN0RFCC3L RSCAN0.RFCC3.UINT16[L]
#define RSCAN0RFCC3LL RSCAN0.RFCC3.UINT8[LL]
#define RSCAN0RFCC3LH RSCAN0.RFCC3.UINT8[LH]
#define RSCAN0RFCC3H RSCAN0.RFCC3.UINT16[H]
#define RSCAN0RFCC3HL RSCAN0.RFCC3.UINT8[HL]
#define RSCAN0RFCC3HH RSCAN0.RFCC3.UINT8[HH]
#define RSCAN0RFCC4 RSCAN0.RFCC4.UINT32
#define RSCAN0RFCC4L RSCAN0.RFCC4.UINT16[L]
#define RSCAN0RFCC4LL RSCAN0.RFCC4.UINT8[LL]
#define RSCAN0RFCC4LH RSCAN0.RFCC4.UINT8[LH]
#define RSCAN0RFCC4H RSCAN0.RFCC4.UINT16[H]
#define RSCAN0RFCC4HL RSCAN0.RFCC4.UINT8[HL]
#define RSCAN0RFCC4HH RSCAN0.RFCC4.UINT8[HH]
#define RSCAN0RFCC5 RSCAN0.RFCC5.UINT32
#define RSCAN0RFCC5L RSCAN0.RFCC5.UINT16[L]
#define RSCAN0RFCC5LL RSCAN0.RFCC5.UINT8[LL]
#define RSCAN0RFCC5LH RSCAN0.RFCC5.UINT8[LH]
#define RSCAN0RFCC5H RSCAN0.RFCC5.UINT16[H]
#define RSCAN0RFCC5HL RSCAN0.RFCC5.UINT8[HL]
#define RSCAN0RFCC5HH RSCAN0.RFCC5.UINT8[HH]
#define RSCAN0RFCC6 RSCAN0.RFCC6.UINT32
#define RSCAN0RFCC6L RSCAN0.RFCC6.UINT16[L]
#define RSCAN0RFCC6LL RSCAN0.RFCC6.UINT8[LL]
#define RSCAN0RFCC6LH RSCAN0.RFCC6.UINT8[LH]
#define RSCAN0RFCC6H RSCAN0.RFCC6.UINT16[H]
#define RSCAN0RFCC6HL RSCAN0.RFCC6.UINT8[HL]
#define RSCAN0RFCC6HH RSCAN0.RFCC6.UINT8[HH]
#define RSCAN0RFCC7 RSCAN0.RFCC7.UINT32
#define RSCAN0RFCC7L RSCAN0.RFCC7.UINT16[L]
#define RSCAN0RFCC7LL RSCAN0.RFCC7.UINT8[LL]
#define RSCAN0RFCC7LH RSCAN0.RFCC7.UINT8[LH]
#define RSCAN0RFCC7H RSCAN0.RFCC7.UINT16[H]
#define RSCAN0RFCC7HL RSCAN0.RFCC7.UINT8[HL]
#define RSCAN0RFCC7HH RSCAN0.RFCC7.UINT8[HH]
#define RSCAN0RFSTS0 RSCAN0.RFSTS0.UINT32
#define RSCAN0RFSTS0L RSCAN0.RFSTS0.UINT16[L]
#define RSCAN0RFSTS0LL RSCAN0.RFSTS0.UINT8[LL]
#define RSCAN0RFSTS0LH RSCAN0.RFSTS0.UINT8[LH]
#define RSCAN0RFSTS0H RSCAN0.RFSTS0.UINT16[H]
#define RSCAN0RFSTS0HL RSCAN0.RFSTS0.UINT8[HL]
#define RSCAN0RFSTS0HH RSCAN0.RFSTS0.UINT8[HH]
#define RSCAN0RFSTS1 RSCAN0.RFSTS1.UINT32
#define RSCAN0RFSTS1L RSCAN0.RFSTS1.UINT16[L]
#define RSCAN0RFSTS1LL RSCAN0.RFSTS1.UINT8[LL]
#define RSCAN0RFSTS1LH RSCAN0.RFSTS1.UINT8[LH]
#define RSCAN0RFSTS1H RSCAN0.RFSTS1.UINT16[H]
#define RSCAN0RFSTS1HL RSCAN0.RFSTS1.UINT8[HL]
#define RSCAN0RFSTS1HH RSCAN0.RFSTS1.UINT8[HH]
#define RSCAN0RFSTS2 RSCAN0.RFSTS2.UINT32
#define RSCAN0RFSTS2L RSCAN0.RFSTS2.UINT16[L]
#define RSCAN0RFSTS2LL RSCAN0.RFSTS2.UINT8[LL]
#define RSCAN0RFSTS2LH RSCAN0.RFSTS2.UINT8[LH]
#define RSCAN0RFSTS2H RSCAN0.RFSTS2.UINT16[H]
#define RSCAN0RFSTS2HL RSCAN0.RFSTS2.UINT8[HL]
#define RSCAN0RFSTS2HH RSCAN0.RFSTS2.UINT8[HH]
#define RSCAN0RFSTS3 RSCAN0.RFSTS3.UINT32
#define RSCAN0RFSTS3L RSCAN0.RFSTS3.UINT16[L]
#define RSCAN0RFSTS3LL RSCAN0.RFSTS3.UINT8[LL]
#define RSCAN0RFSTS3LH RSCAN0.RFSTS3.UINT8[LH]
#define RSCAN0RFSTS3H RSCAN0.RFSTS3.UINT16[H]
#define RSCAN0RFSTS3HL RSCAN0.RFSTS3.UINT8[HL]
#define RSCAN0RFSTS3HH RSCAN0.RFSTS3.UINT8[HH]
#define RSCAN0RFSTS4 RSCAN0.RFSTS4.UINT32
#define RSCAN0RFSTS4L RSCAN0.RFSTS4.UINT16[L]
#define RSCAN0RFSTS4LL RSCAN0.RFSTS4.UINT8[LL]
#define RSCAN0RFSTS4LH RSCAN0.RFSTS4.UINT8[LH]
#define RSCAN0RFSTS4H RSCAN0.RFSTS4.UINT16[H]
#define RSCAN0RFSTS4HL RSCAN0.RFSTS4.UINT8[HL]
#define RSCAN0RFSTS4HH RSCAN0.RFSTS4.UINT8[HH]
#define RSCAN0RFSTS5 RSCAN0.RFSTS5.UINT32
#define RSCAN0RFSTS5L RSCAN0.RFSTS5.UINT16[L]
#define RSCAN0RFSTS5LL RSCAN0.RFSTS5.UINT8[LL]
#define RSCAN0RFSTS5LH RSCAN0.RFSTS5.UINT8[LH]
#define RSCAN0RFSTS5H RSCAN0.RFSTS5.UINT16[H]
#define RSCAN0RFSTS5HL RSCAN0.RFSTS5.UINT8[HL]
#define RSCAN0RFSTS5HH RSCAN0.RFSTS5.UINT8[HH]
#define RSCAN0RFSTS6 RSCAN0.RFSTS6.UINT32
#define RSCAN0RFSTS6L RSCAN0.RFSTS6.UINT16[L]
#define RSCAN0RFSTS6LL RSCAN0.RFSTS6.UINT8[LL]
#define RSCAN0RFSTS6LH RSCAN0.RFSTS6.UINT8[LH]
#define RSCAN0RFSTS6H RSCAN0.RFSTS6.UINT16[H]
#define RSCAN0RFSTS6HL RSCAN0.RFSTS6.UINT8[HL]
#define RSCAN0RFSTS6HH RSCAN0.RFSTS6.UINT8[HH]
#define RSCAN0RFSTS7 RSCAN0.RFSTS7.UINT32
#define RSCAN0RFSTS7L RSCAN0.RFSTS7.UINT16[L]
#define RSCAN0RFSTS7LL RSCAN0.RFSTS7.UINT8[LL]
#define RSCAN0RFSTS7LH RSCAN0.RFSTS7.UINT8[LH]
#define RSCAN0RFSTS7H RSCAN0.RFSTS7.UINT16[H]
#define RSCAN0RFSTS7HL RSCAN0.RFSTS7.UINT8[HL]
#define RSCAN0RFSTS7HH RSCAN0.RFSTS7.UINT8[HH]
#define RSCAN0RFPCTR0 RSCAN0.RFPCTR0.UINT32
#define RSCAN0RFPCTR0L RSCAN0.RFPCTR0.UINT16[L]
#define RSCAN0RFPCTR0LL RSCAN0.RFPCTR0.UINT8[LL]
#define RSCAN0RFPCTR0LH RSCAN0.RFPCTR0.UINT8[LH]
#define RSCAN0RFPCTR0H RSCAN0.RFPCTR0.UINT16[H]
#define RSCAN0RFPCTR0HL RSCAN0.RFPCTR0.UINT8[HL]
#define RSCAN0RFPCTR0HH RSCAN0.RFPCTR0.UINT8[HH]
#define RSCAN0RFPCTR1 RSCAN0.RFPCTR1.UINT32
#define RSCAN0RFPCTR1L RSCAN0.RFPCTR1.UINT16[L]
#define RSCAN0RFPCTR1LL RSCAN0.RFPCTR1.UINT8[LL]
#define RSCAN0RFPCTR1LH RSCAN0.RFPCTR1.UINT8[LH]
#define RSCAN0RFPCTR1H RSCAN0.RFPCTR1.UINT16[H]
#define RSCAN0RFPCTR1HL RSCAN0.RFPCTR1.UINT8[HL]
#define RSCAN0RFPCTR1HH RSCAN0.RFPCTR1.UINT8[HH]
#define RSCAN0RFPCTR2 RSCAN0.RFPCTR2.UINT32
#define RSCAN0RFPCTR2L RSCAN0.RFPCTR2.UINT16[L]
#define RSCAN0RFPCTR2LL RSCAN0.RFPCTR2.UINT8[LL]
#define RSCAN0RFPCTR2LH RSCAN0.RFPCTR2.UINT8[LH]
#define RSCAN0RFPCTR2H RSCAN0.RFPCTR2.UINT16[H]
#define RSCAN0RFPCTR2HL RSCAN0.RFPCTR2.UINT8[HL]
#define RSCAN0RFPCTR2HH RSCAN0.RFPCTR2.UINT8[HH]
#define RSCAN0RFPCTR3 RSCAN0.RFPCTR3.UINT32
#define RSCAN0RFPCTR3L RSCAN0.RFPCTR3.UINT16[L]
#define RSCAN0RFPCTR3LL RSCAN0.RFPCTR3.UINT8[LL]
#define RSCAN0RFPCTR3LH RSCAN0.RFPCTR3.UINT8[LH]
#define RSCAN0RFPCTR3H RSCAN0.RFPCTR3.UINT16[H]
#define RSCAN0RFPCTR3HL RSCAN0.RFPCTR3.UINT8[HL]
#define RSCAN0RFPCTR3HH RSCAN0.RFPCTR3.UINT8[HH]
#define RSCAN0RFPCTR4 RSCAN0.RFPCTR4.UINT32
#define RSCAN0RFPCTR4L RSCAN0.RFPCTR4.UINT16[L]
#define RSCAN0RFPCTR4LL RSCAN0.RFPCTR4.UINT8[LL]
#define RSCAN0RFPCTR4LH RSCAN0.RFPCTR4.UINT8[LH]
#define RSCAN0RFPCTR4H RSCAN0.RFPCTR4.UINT16[H]
#define RSCAN0RFPCTR4HL RSCAN0.RFPCTR4.UINT8[HL]
#define RSCAN0RFPCTR4HH RSCAN0.RFPCTR4.UINT8[HH]
#define RSCAN0RFPCTR5 RSCAN0.RFPCTR5.UINT32
#define RSCAN0RFPCTR5L RSCAN0.RFPCTR5.UINT16[L]
#define RSCAN0RFPCTR5LL RSCAN0.RFPCTR5.UINT8[LL]
#define RSCAN0RFPCTR5LH RSCAN0.RFPCTR5.UINT8[LH]
#define RSCAN0RFPCTR5H RSCAN0.RFPCTR5.UINT16[H]
#define RSCAN0RFPCTR5HL RSCAN0.RFPCTR5.UINT8[HL]
#define RSCAN0RFPCTR5HH RSCAN0.RFPCTR5.UINT8[HH]
#define RSCAN0RFPCTR6 RSCAN0.RFPCTR6.UINT32
#define RSCAN0RFPCTR6L RSCAN0.RFPCTR6.UINT16[L]
#define RSCAN0RFPCTR6LL RSCAN0.RFPCTR6.UINT8[LL]
#define RSCAN0RFPCTR6LH RSCAN0.RFPCTR6.UINT8[LH]
#define RSCAN0RFPCTR6H RSCAN0.RFPCTR6.UINT16[H]
#define RSCAN0RFPCTR6HL RSCAN0.RFPCTR6.UINT8[HL]
#define RSCAN0RFPCTR6HH RSCAN0.RFPCTR6.UINT8[HH]
#define RSCAN0RFPCTR7 RSCAN0.RFPCTR7.UINT32
#define RSCAN0RFPCTR7L RSCAN0.RFPCTR7.UINT16[L]
#define RSCAN0RFPCTR7LL RSCAN0.RFPCTR7.UINT8[LL]
#define RSCAN0RFPCTR7LH RSCAN0.RFPCTR7.UINT8[LH]
#define RSCAN0RFPCTR7H RSCAN0.RFPCTR7.UINT16[H]
#define RSCAN0RFPCTR7HL RSCAN0.RFPCTR7.UINT8[HL]
#define RSCAN0RFPCTR7HH RSCAN0.RFPCTR7.UINT8[HH]
#define RSCAN0CFCC0 RSCAN0.CFCC0.UINT32
#define RSCAN0CFCC0L RSCAN0.CFCC0.UINT16[L]
#define RSCAN0CFCC0LL RSCAN0.CFCC0.UINT8[LL]
#define RSCAN0CFCC0LH RSCAN0.CFCC0.UINT8[LH]
#define RSCAN0CFCC0H RSCAN0.CFCC0.UINT16[H]
#define RSCAN0CFCC0HL RSCAN0.CFCC0.UINT8[HL]
#define RSCAN0CFCC0HH RSCAN0.CFCC0.UINT8[HH]
#define RSCAN0CFCC1 RSCAN0.CFCC1.UINT32
#define RSCAN0CFCC1L RSCAN0.CFCC1.UINT16[L]
#define RSCAN0CFCC1LL RSCAN0.CFCC1.UINT8[LL]
#define RSCAN0CFCC1LH RSCAN0.CFCC1.UINT8[LH]
#define RSCAN0CFCC1H RSCAN0.CFCC1.UINT16[H]
#define RSCAN0CFCC1HL RSCAN0.CFCC1.UINT8[HL]
#define RSCAN0CFCC1HH RSCAN0.CFCC1.UINT8[HH]
#define RSCAN0CFCC2 RSCAN0.CFCC2.UINT32
#define RSCAN0CFCC2L RSCAN0.CFCC2.UINT16[L]
#define RSCAN0CFCC2LL RSCAN0.CFCC2.UINT8[LL]
#define RSCAN0CFCC2LH RSCAN0.CFCC2.UINT8[LH]
#define RSCAN0CFCC2H RSCAN0.CFCC2.UINT16[H]
#define RSCAN0CFCC2HL RSCAN0.CFCC2.UINT8[HL]
#define RSCAN0CFCC2HH RSCAN0.CFCC2.UINT8[HH]
#define RSCAN0CFCC3 RSCAN0.CFCC3.UINT32
#define RSCAN0CFCC3L RSCAN0.CFCC3.UINT16[L]
#define RSCAN0CFCC3LL RSCAN0.CFCC3.UINT8[LL]
#define RSCAN0CFCC3LH RSCAN0.CFCC3.UINT8[LH]
#define RSCAN0CFCC3H RSCAN0.CFCC3.UINT16[H]
#define RSCAN0CFCC3HL RSCAN0.CFCC3.UINT8[HL]
#define RSCAN0CFCC3HH RSCAN0.CFCC3.UINT8[HH]
#define RSCAN0CFCC4 RSCAN0.CFCC4.UINT32
#define RSCAN0CFCC4L RSCAN0.CFCC4.UINT16[L]
#define RSCAN0CFCC4LL RSCAN0.CFCC4.UINT8[LL]
#define RSCAN0CFCC4LH RSCAN0.CFCC4.UINT8[LH]
#define RSCAN0CFCC4H RSCAN0.CFCC4.UINT16[H]
#define RSCAN0CFCC4HL RSCAN0.CFCC4.UINT8[HL]
#define RSCAN0CFCC4HH RSCAN0.CFCC4.UINT8[HH]
#define RSCAN0CFCC5 RSCAN0.CFCC5.UINT32
#define RSCAN0CFCC5L RSCAN0.CFCC5.UINT16[L]
#define RSCAN0CFCC5LL RSCAN0.CFCC5.UINT8[LL]
#define RSCAN0CFCC5LH RSCAN0.CFCC5.UINT8[LH]
#define RSCAN0CFCC5H RSCAN0.CFCC5.UINT16[H]
#define RSCAN0CFCC5HL RSCAN0.CFCC5.UINT8[HL]
#define RSCAN0CFCC5HH RSCAN0.CFCC5.UINT8[HH]
#define RSCAN0CFCC6 RSCAN0.CFCC6.UINT32
#define RSCAN0CFCC6L RSCAN0.CFCC6.UINT16[L]
#define RSCAN0CFCC6LL RSCAN0.CFCC6.UINT8[LL]
#define RSCAN0CFCC6LH RSCAN0.CFCC6.UINT8[LH]
#define RSCAN0CFCC6H RSCAN0.CFCC6.UINT16[H]
#define RSCAN0CFCC6HL RSCAN0.CFCC6.UINT8[HL]
#define RSCAN0CFCC6HH RSCAN0.CFCC6.UINT8[HH]
#define RSCAN0CFCC7 RSCAN0.CFCC7.UINT32
#define RSCAN0CFCC7L RSCAN0.CFCC7.UINT16[L]
#define RSCAN0CFCC7LL RSCAN0.CFCC7.UINT8[LL]
#define RSCAN0CFCC7LH RSCAN0.CFCC7.UINT8[LH]
#define RSCAN0CFCC7H RSCAN0.CFCC7.UINT16[H]
#define RSCAN0CFCC7HL RSCAN0.CFCC7.UINT8[HL]
#define RSCAN0CFCC7HH RSCAN0.CFCC7.UINT8[HH]
#define RSCAN0CFCC8 RSCAN0.CFCC8.UINT32
#define RSCAN0CFCC8L RSCAN0.CFCC8.UINT16[L]
#define RSCAN0CFCC8LL RSCAN0.CFCC8.UINT8[LL]
#define RSCAN0CFCC8LH RSCAN0.CFCC8.UINT8[LH]
#define RSCAN0CFCC8H RSCAN0.CFCC8.UINT16[H]
#define RSCAN0CFCC8HL RSCAN0.CFCC8.UINT8[HL]
#define RSCAN0CFCC8HH RSCAN0.CFCC8.UINT8[HH]
#define RSCAN0CFSTS0 RSCAN0.CFSTS0.UINT32
#define RSCAN0CFSTS0L RSCAN0.CFSTS0.UINT16[L]
#define RSCAN0CFSTS0LL RSCAN0.CFSTS0.UINT8[LL]
#define RSCAN0CFSTS0LH RSCAN0.CFSTS0.UINT8[LH]
#define RSCAN0CFSTS0H RSCAN0.CFSTS0.UINT16[H]
#define RSCAN0CFSTS0HL RSCAN0.CFSTS0.UINT8[HL]
#define RSCAN0CFSTS0HH RSCAN0.CFSTS0.UINT8[HH]
#define RSCAN0CFSTS1 RSCAN0.CFSTS1.UINT32
#define RSCAN0CFSTS1L RSCAN0.CFSTS1.UINT16[L]
#define RSCAN0CFSTS1LL RSCAN0.CFSTS1.UINT8[LL]
#define RSCAN0CFSTS1LH RSCAN0.CFSTS1.UINT8[LH]
#define RSCAN0CFSTS1H RSCAN0.CFSTS1.UINT16[H]
#define RSCAN0CFSTS1HL RSCAN0.CFSTS1.UINT8[HL]
#define RSCAN0CFSTS1HH RSCAN0.CFSTS1.UINT8[HH]
#define RSCAN0CFSTS2 RSCAN0.CFSTS2.UINT32
#define RSCAN0CFSTS2L RSCAN0.CFSTS2.UINT16[L]
#define RSCAN0CFSTS2LL RSCAN0.CFSTS2.UINT8[LL]
#define RSCAN0CFSTS2LH RSCAN0.CFSTS2.UINT8[LH]
#define RSCAN0CFSTS2H RSCAN0.CFSTS2.UINT16[H]
#define RSCAN0CFSTS2HL RSCAN0.CFSTS2.UINT8[HL]
#define RSCAN0CFSTS2HH RSCAN0.CFSTS2.UINT8[HH]
#define RSCAN0CFSTS3 RSCAN0.CFSTS3.UINT32
#define RSCAN0CFSTS3L RSCAN0.CFSTS3.UINT16[L]
#define RSCAN0CFSTS3LL RSCAN0.CFSTS3.UINT8[LL]
#define RSCAN0CFSTS3LH RSCAN0.CFSTS3.UINT8[LH]
#define RSCAN0CFSTS3H RSCAN0.CFSTS3.UINT16[H]
#define RSCAN0CFSTS3HL RSCAN0.CFSTS3.UINT8[HL]
#define RSCAN0CFSTS3HH RSCAN0.CFSTS3.UINT8[HH]
#define RSCAN0CFSTS4 RSCAN0.CFSTS4.UINT32
#define RSCAN0CFSTS4L RSCAN0.CFSTS4.UINT16[L]
#define RSCAN0CFSTS4LL RSCAN0.CFSTS4.UINT8[LL]
#define RSCAN0CFSTS4LH RSCAN0.CFSTS4.UINT8[LH]
#define RSCAN0CFSTS4H RSCAN0.CFSTS4.UINT16[H]
#define RSCAN0CFSTS4HL RSCAN0.CFSTS4.UINT8[HL]
#define RSCAN0CFSTS4HH RSCAN0.CFSTS4.UINT8[HH]
#define RSCAN0CFSTS5 RSCAN0.CFSTS5.UINT32
#define RSCAN0CFSTS5L RSCAN0.CFSTS5.UINT16[L]
#define RSCAN0CFSTS5LL RSCAN0.CFSTS5.UINT8[LL]
#define RSCAN0CFSTS5LH RSCAN0.CFSTS5.UINT8[LH]
#define RSCAN0CFSTS5H RSCAN0.CFSTS5.UINT16[H]
#define RSCAN0CFSTS5HL RSCAN0.CFSTS5.UINT8[HL]
#define RSCAN0CFSTS5HH RSCAN0.CFSTS5.UINT8[HH]
#define RSCAN0CFSTS6 RSCAN0.CFSTS6.UINT32
#define RSCAN0CFSTS6L RSCAN0.CFSTS6.UINT16[L]
#define RSCAN0CFSTS6LL RSCAN0.CFSTS6.UINT8[LL]
#define RSCAN0CFSTS6LH RSCAN0.CFSTS6.UINT8[LH]
#define RSCAN0CFSTS6H RSCAN0.CFSTS6.UINT16[H]
#define RSCAN0CFSTS6HL RSCAN0.CFSTS6.UINT8[HL]
#define RSCAN0CFSTS6HH RSCAN0.CFSTS6.UINT8[HH]
#define RSCAN0CFSTS7 RSCAN0.CFSTS7.UINT32
#define RSCAN0CFSTS7L RSCAN0.CFSTS7.UINT16[L]
#define RSCAN0CFSTS7LL RSCAN0.CFSTS7.UINT8[LL]
#define RSCAN0CFSTS7LH RSCAN0.CFSTS7.UINT8[LH]
#define RSCAN0CFSTS7H RSCAN0.CFSTS7.UINT16[H]
#define RSCAN0CFSTS7HL RSCAN0.CFSTS7.UINT8[HL]
#define RSCAN0CFSTS7HH RSCAN0.CFSTS7.UINT8[HH]
#define RSCAN0CFSTS8 RSCAN0.CFSTS8.UINT32
#define RSCAN0CFSTS8L RSCAN0.CFSTS8.UINT16[L]
#define RSCAN0CFSTS8LL RSCAN0.CFSTS8.UINT8[LL]
#define RSCAN0CFSTS8LH RSCAN0.CFSTS8.UINT8[LH]
#define RSCAN0CFSTS8H RSCAN0.CFSTS8.UINT16[H]
#define RSCAN0CFSTS8HL RSCAN0.CFSTS8.UINT8[HL]
#define RSCAN0CFSTS8HH RSCAN0.CFSTS8.UINT8[HH]
#define RSCAN0CFPCTR0 RSCAN0.CFPCTR0.UINT32
#define RSCAN0CFPCTR0L RSCAN0.CFPCTR0.UINT16[L]
#define RSCAN0CFPCTR0LL RSCAN0.CFPCTR0.UINT8[LL]
#define RSCAN0CFPCTR0LH RSCAN0.CFPCTR0.UINT8[LH]
#define RSCAN0CFPCTR0H RSCAN0.CFPCTR0.UINT16[H]
#define RSCAN0CFPCTR0HL RSCAN0.CFPCTR0.UINT8[HL]
#define RSCAN0CFPCTR0HH RSCAN0.CFPCTR0.UINT8[HH]
#define RSCAN0CFPCTR1 RSCAN0.CFPCTR1.UINT32
#define RSCAN0CFPCTR1L RSCAN0.CFPCTR1.UINT16[L]
#define RSCAN0CFPCTR1LL RSCAN0.CFPCTR1.UINT8[LL]
#define RSCAN0CFPCTR1LH RSCAN0.CFPCTR1.UINT8[LH]
#define RSCAN0CFPCTR1H RSCAN0.CFPCTR1.UINT16[H]
#define RSCAN0CFPCTR1HL RSCAN0.CFPCTR1.UINT8[HL]
#define RSCAN0CFPCTR1HH RSCAN0.CFPCTR1.UINT8[HH]
#define RSCAN0CFPCTR2 RSCAN0.CFPCTR2.UINT32
#define RSCAN0CFPCTR2L RSCAN0.CFPCTR2.UINT16[L]
#define RSCAN0CFPCTR2LL RSCAN0.CFPCTR2.UINT8[LL]
#define RSCAN0CFPCTR2LH RSCAN0.CFPCTR2.UINT8[LH]
#define RSCAN0CFPCTR2H RSCAN0.CFPCTR2.UINT16[H]
#define RSCAN0CFPCTR2HL RSCAN0.CFPCTR2.UINT8[HL]
#define RSCAN0CFPCTR2HH RSCAN0.CFPCTR2.UINT8[HH]
#define RSCAN0CFPCTR3 RSCAN0.CFPCTR3.UINT32
#define RSCAN0CFPCTR3L RSCAN0.CFPCTR3.UINT16[L]
#define RSCAN0CFPCTR3LL RSCAN0.CFPCTR3.UINT8[LL]
#define RSCAN0CFPCTR3LH RSCAN0.CFPCTR3.UINT8[LH]
#define RSCAN0CFPCTR3H RSCAN0.CFPCTR3.UINT16[H]
#define RSCAN0CFPCTR3HL RSCAN0.CFPCTR3.UINT8[HL]
#define RSCAN0CFPCTR3HH RSCAN0.CFPCTR3.UINT8[HH]
#define RSCAN0CFPCTR4 RSCAN0.CFPCTR4.UINT32
#define RSCAN0CFPCTR4L RSCAN0.CFPCTR4.UINT16[L]
#define RSCAN0CFPCTR4LL RSCAN0.CFPCTR4.UINT8[LL]
#define RSCAN0CFPCTR4LH RSCAN0.CFPCTR4.UINT8[LH]
#define RSCAN0CFPCTR4H RSCAN0.CFPCTR4.UINT16[H]
#define RSCAN0CFPCTR4HL RSCAN0.CFPCTR4.UINT8[HL]
#define RSCAN0CFPCTR4HH RSCAN0.CFPCTR4.UINT8[HH]
#define RSCAN0CFPCTR5 RSCAN0.CFPCTR5.UINT32
#define RSCAN0CFPCTR5L RSCAN0.CFPCTR5.UINT16[L]
#define RSCAN0CFPCTR5LL RSCAN0.CFPCTR5.UINT8[LL]
#define RSCAN0CFPCTR5LH RSCAN0.CFPCTR5.UINT8[LH]
#define RSCAN0CFPCTR5H RSCAN0.CFPCTR5.UINT16[H]
#define RSCAN0CFPCTR5HL RSCAN0.CFPCTR5.UINT8[HL]
#define RSCAN0CFPCTR5HH RSCAN0.CFPCTR5.UINT8[HH]
#define RSCAN0CFPCTR6 RSCAN0.CFPCTR6.UINT32
#define RSCAN0CFPCTR6L RSCAN0.CFPCTR6.UINT16[L]
#define RSCAN0CFPCTR6LL RSCAN0.CFPCTR6.UINT8[LL]
#define RSCAN0CFPCTR6LH RSCAN0.CFPCTR6.UINT8[LH]
#define RSCAN0CFPCTR6H RSCAN0.CFPCTR6.UINT16[H]
#define RSCAN0CFPCTR6HL RSCAN0.CFPCTR6.UINT8[HL]
#define RSCAN0CFPCTR6HH RSCAN0.CFPCTR6.UINT8[HH]
#define RSCAN0CFPCTR7 RSCAN0.CFPCTR7.UINT32
#define RSCAN0CFPCTR7L RSCAN0.CFPCTR7.UINT16[L]
#define RSCAN0CFPCTR7LL RSCAN0.CFPCTR7.UINT8[LL]
#define RSCAN0CFPCTR7LH RSCAN0.CFPCTR7.UINT8[LH]
#define RSCAN0CFPCTR7H RSCAN0.CFPCTR7.UINT16[H]
#define RSCAN0CFPCTR7HL RSCAN0.CFPCTR7.UINT8[HL]
#define RSCAN0CFPCTR7HH RSCAN0.CFPCTR7.UINT8[HH]
#define RSCAN0CFPCTR8 RSCAN0.CFPCTR8.UINT32
#define RSCAN0CFPCTR8L RSCAN0.CFPCTR8.UINT16[L]
#define RSCAN0CFPCTR8LL RSCAN0.CFPCTR8.UINT8[LL]
#define RSCAN0CFPCTR8LH RSCAN0.CFPCTR8.UINT8[LH]
#define RSCAN0CFPCTR8H RSCAN0.CFPCTR8.UINT16[H]
#define RSCAN0CFPCTR8HL RSCAN0.CFPCTR8.UINT8[HL]
#define RSCAN0CFPCTR8HH RSCAN0.CFPCTR8.UINT8[HH]
#define RSCAN0FESTS RSCAN0.FESTS.UINT32
#define RSCAN0FESTSL RSCAN0.FESTS.UINT16[L]
#define RSCAN0FESTSLL RSCAN0.FESTS.UINT8[LL]
#define RSCAN0FESTSLH RSCAN0.FESTS.UINT8[LH]
#define RSCAN0FESTSH RSCAN0.FESTS.UINT16[H]
#define RSCAN0FESTSHL RSCAN0.FESTS.UINT8[HL]
#define RSCAN0FESTSHH RSCAN0.FESTS.UINT8[HH]
#define RSCAN0FFSTS RSCAN0.FFSTS.UINT32
#define RSCAN0FFSTSL RSCAN0.FFSTS.UINT16[L]
#define RSCAN0FFSTSLL RSCAN0.FFSTS.UINT8[LL]
#define RSCAN0FFSTSLH RSCAN0.FFSTS.UINT8[LH]
#define RSCAN0FFSTSH RSCAN0.FFSTS.UINT16[H]
#define RSCAN0FFSTSHL RSCAN0.FFSTS.UINT8[HL]
#define RSCAN0FFSTSHH RSCAN0.FFSTS.UINT8[HH]
#define RSCAN0FMSTS RSCAN0.FMSTS.UINT32
#define RSCAN0FMSTSL RSCAN0.FMSTS.UINT16[L]
#define RSCAN0FMSTSLL RSCAN0.FMSTS.UINT8[LL]
#define RSCAN0FMSTSLH RSCAN0.FMSTS.UINT8[LH]
#define RSCAN0FMSTSH RSCAN0.FMSTS.UINT16[H]
#define RSCAN0FMSTSHL RSCAN0.FMSTS.UINT8[HL]
#define RSCAN0FMSTSHH RSCAN0.FMSTS.UINT8[HH]
#define RSCAN0RFISTS RSCAN0.RFISTS.UINT32
#define RSCAN0RFISTSL RSCAN0.RFISTS.UINT16[L]
#define RSCAN0RFISTSLL RSCAN0.RFISTS.UINT8[LL]
#define RSCAN0RFISTSLH RSCAN0.RFISTS.UINT8[LH]
#define RSCAN0RFISTSH RSCAN0.RFISTS.UINT16[H]
#define RSCAN0RFISTSHL RSCAN0.RFISTS.UINT8[HL]
#define RSCAN0RFISTSHH RSCAN0.RFISTS.UINT8[HH]
#define RSCAN0CFRISTS RSCAN0.CFRISTS.UINT32
#define RSCAN0CFRISTSL RSCAN0.CFRISTS.UINT16[L]
#define RSCAN0CFRISTSLL RSCAN0.CFRISTS.UINT8[LL]
#define RSCAN0CFRISTSLH RSCAN0.CFRISTS.UINT8[LH]
#define RSCAN0CFRISTSH RSCAN0.CFRISTS.UINT16[H]
#define RSCAN0CFRISTSHL RSCAN0.CFRISTS.UINT8[HL]
#define RSCAN0CFRISTSHH RSCAN0.CFRISTS.UINT8[HH]
#define RSCAN0CFTISTS RSCAN0.CFTISTS.UINT32
#define RSCAN0CFTISTSL RSCAN0.CFTISTS.UINT16[L]
#define RSCAN0CFTISTSLL RSCAN0.CFTISTS.UINT8[LL]
#define RSCAN0CFTISTSLH RSCAN0.CFTISTS.UINT8[LH]
#define RSCAN0CFTISTSH RSCAN0.CFTISTS.UINT16[H]
#define RSCAN0CFTISTSHL RSCAN0.CFTISTS.UINT8[HL]
#define RSCAN0CFTISTSHH RSCAN0.CFTISTS.UINT8[HH]
#define RSCAN0TMC0 RSCAN0.TMC0
#define RSCAN0TMC1 RSCAN0.TMC1
#define RSCAN0TMC2 RSCAN0.TMC2
#define RSCAN0TMC3 RSCAN0.TMC3
#define RSCAN0TMC4 RSCAN0.TMC4
#define RSCAN0TMC5 RSCAN0.TMC5
#define RSCAN0TMC6 RSCAN0.TMC6
#define RSCAN0TMC7 RSCAN0.TMC7
#define RSCAN0TMC8 RSCAN0.TMC8
#define RSCAN0TMC9 RSCAN0.TMC9
#define RSCAN0TMC10 RSCAN0.TMC10
#define RSCAN0TMC11 RSCAN0.TMC11
#define RSCAN0TMC12 RSCAN0.TMC12
#define RSCAN0TMC13 RSCAN0.TMC13
#define RSCAN0TMC14 RSCAN0.TMC14
#define RSCAN0TMC15 RSCAN0.TMC15
#define RSCAN0TMC16 RSCAN0.TMC16
#define RSCAN0TMC17 RSCAN0.TMC17
#define RSCAN0TMC18 RSCAN0.TMC18
#define RSCAN0TMC19 RSCAN0.TMC19
#define RSCAN0TMC20 RSCAN0.TMC20
#define RSCAN0TMC21 RSCAN0.TMC21
#define RSCAN0TMC22 RSCAN0.TMC22
#define RSCAN0TMC23 RSCAN0.TMC23
#define RSCAN0TMC24 RSCAN0.TMC24
#define RSCAN0TMC25 RSCAN0.TMC25
#define RSCAN0TMC26 RSCAN0.TMC26
#define RSCAN0TMC27 RSCAN0.TMC27
#define RSCAN0TMC28 RSCAN0.TMC28
#define RSCAN0TMC29 RSCAN0.TMC29
#define RSCAN0TMC30 RSCAN0.TMC30
#define RSCAN0TMC31 RSCAN0.TMC31
#define RSCAN0TMC32 RSCAN0.TMC32
#define RSCAN0TMC33 RSCAN0.TMC33
#define RSCAN0TMC34 RSCAN0.TMC34
#define RSCAN0TMC35 RSCAN0.TMC35
#define RSCAN0TMC36 RSCAN0.TMC36
#define RSCAN0TMC37 RSCAN0.TMC37
#define RSCAN0TMC38 RSCAN0.TMC38
#define RSCAN0TMC39 RSCAN0.TMC39
#define RSCAN0TMC40 RSCAN0.TMC40
#define RSCAN0TMC41 RSCAN0.TMC41
#define RSCAN0TMC42 RSCAN0.TMC42
#define RSCAN0TMC43 RSCAN0.TMC43
#define RSCAN0TMC44 RSCAN0.TMC44
#define RSCAN0TMC45 RSCAN0.TMC45
#define RSCAN0TMC46 RSCAN0.TMC46
#define RSCAN0TMC47 RSCAN0.TMC47
#define RSCAN0TMSTS0 RSCAN0.TMSTS0
#define RSCAN0TMSTS1 RSCAN0.TMSTS1
#define RSCAN0TMSTS2 RSCAN0.TMSTS2
#define RSCAN0TMSTS3 RSCAN0.TMSTS3
#define RSCAN0TMSTS4 RSCAN0.TMSTS4
#define RSCAN0TMSTS5 RSCAN0.TMSTS5
#define RSCAN0TMSTS6 RSCAN0.TMSTS6
#define RSCAN0TMSTS7 RSCAN0.TMSTS7
#define RSCAN0TMSTS8 RSCAN0.TMSTS8
#define RSCAN0TMSTS9 RSCAN0.TMSTS9
#define RSCAN0TMSTS10 RSCAN0.TMSTS10
#define RSCAN0TMSTS11 RSCAN0.TMSTS11
#define RSCAN0TMSTS12 RSCAN0.TMSTS12
#define RSCAN0TMSTS13 RSCAN0.TMSTS13
#define RSCAN0TMSTS14 RSCAN0.TMSTS14
#define RSCAN0TMSTS15 RSCAN0.TMSTS15
#define RSCAN0TMSTS16 RSCAN0.TMSTS16
#define RSCAN0TMSTS17 RSCAN0.TMSTS17
#define RSCAN0TMSTS18 RSCAN0.TMSTS18
#define RSCAN0TMSTS19 RSCAN0.TMSTS19
#define RSCAN0TMSTS20 RSCAN0.TMSTS20
#define RSCAN0TMSTS21 RSCAN0.TMSTS21
#define RSCAN0TMSTS22 RSCAN0.TMSTS22
#define RSCAN0TMSTS23 RSCAN0.TMSTS23
#define RSCAN0TMSTS24 RSCAN0.TMSTS24
#define RSCAN0TMSTS25 RSCAN0.TMSTS25
#define RSCAN0TMSTS26 RSCAN0.TMSTS26
#define RSCAN0TMSTS27 RSCAN0.TMSTS27
#define RSCAN0TMSTS28 RSCAN0.TMSTS28
#define RSCAN0TMSTS29 RSCAN0.TMSTS29
#define RSCAN0TMSTS30 RSCAN0.TMSTS30
#define RSCAN0TMSTS31 RSCAN0.TMSTS31
#define RSCAN0TMSTS32 RSCAN0.TMSTS32
#define RSCAN0TMSTS33 RSCAN0.TMSTS33
#define RSCAN0TMSTS34 RSCAN0.TMSTS34
#define RSCAN0TMSTS35 RSCAN0.TMSTS35
#define RSCAN0TMSTS36 RSCAN0.TMSTS36
#define RSCAN0TMSTS37 RSCAN0.TMSTS37
#define RSCAN0TMSTS38 RSCAN0.TMSTS38
#define RSCAN0TMSTS39 RSCAN0.TMSTS39
#define RSCAN0TMSTS40 RSCAN0.TMSTS40
#define RSCAN0TMSTS41 RSCAN0.TMSTS41
#define RSCAN0TMSTS42 RSCAN0.TMSTS42
#define RSCAN0TMSTS43 RSCAN0.TMSTS43
#define RSCAN0TMSTS44 RSCAN0.TMSTS44
#define RSCAN0TMSTS45 RSCAN0.TMSTS45
#define RSCAN0TMSTS46 RSCAN0.TMSTS46
#define RSCAN0TMSTS47 RSCAN0.TMSTS47
#define RSCAN0TMTRSTS0 RSCAN0.TMTRSTS0.UINT32
#define RSCAN0TMTRSTS0L RSCAN0.TMTRSTS0.UINT16[L]
#define RSCAN0TMTRSTS0LL RSCAN0.TMTRSTS0.UINT8[LL]
#define RSCAN0TMTRSTS0LH RSCAN0.TMTRSTS0.UINT8[LH]
#define RSCAN0TMTRSTS0H RSCAN0.TMTRSTS0.UINT16[H]
#define RSCAN0TMTRSTS0HL RSCAN0.TMTRSTS0.UINT8[HL]
#define RSCAN0TMTRSTS0HH RSCAN0.TMTRSTS0.UINT8[HH]
#define RSCAN0TMTRSTS1 RSCAN0.TMTRSTS1.UINT32
#define RSCAN0TMTRSTS1L RSCAN0.TMTRSTS1.UINT16[L]
#define RSCAN0TMTRSTS1LL RSCAN0.TMTRSTS1.UINT8[LL]
#define RSCAN0TMTRSTS1LH RSCAN0.TMTRSTS1.UINT8[LH]
#define RSCAN0TMTRSTS1H RSCAN0.TMTRSTS1.UINT16[H]
#define RSCAN0TMTRSTS1HL RSCAN0.TMTRSTS1.UINT8[HL]
#define RSCAN0TMTRSTS1HH RSCAN0.TMTRSTS1.UINT8[HH]
#define RSCAN0TMTARSTS0 RSCAN0.TMTARSTS0.UINT32
#define RSCAN0TMTARSTS0L RSCAN0.TMTARSTS0.UINT16[L]
#define RSCAN0TMTARSTS0LL RSCAN0.TMTARSTS0.UINT8[LL]
#define RSCAN0TMTARSTS0LH RSCAN0.TMTARSTS0.UINT8[LH]
#define RSCAN0TMTARSTS0H RSCAN0.TMTARSTS0.UINT16[H]
#define RSCAN0TMTARSTS0HL RSCAN0.TMTARSTS0.UINT8[HL]
#define RSCAN0TMTARSTS0HH RSCAN0.TMTARSTS0.UINT8[HH]
#define RSCAN0TMTARSTS1 RSCAN0.TMTARSTS1.UINT32
#define RSCAN0TMTARSTS1L RSCAN0.TMTARSTS1.UINT16[L]
#define RSCAN0TMTARSTS1LL RSCAN0.TMTARSTS1.UINT8[LL]
#define RSCAN0TMTARSTS1LH RSCAN0.TMTARSTS1.UINT8[LH]
#define RSCAN0TMTARSTS1H RSCAN0.TMTARSTS1.UINT16[H]
#define RSCAN0TMTARSTS1HL RSCAN0.TMTARSTS1.UINT8[HL]
#define RSCAN0TMTARSTS1HH RSCAN0.TMTARSTS1.UINT8[HH]
#define RSCAN0TMTCSTS0 RSCAN0.TMTCSTS0.UINT32
#define RSCAN0TMTCSTS0L RSCAN0.TMTCSTS0.UINT16[L]
#define RSCAN0TMTCSTS0LL RSCAN0.TMTCSTS0.UINT8[LL]
#define RSCAN0TMTCSTS0LH RSCAN0.TMTCSTS0.UINT8[LH]
#define RSCAN0TMTCSTS0H RSCAN0.TMTCSTS0.UINT16[H]
#define RSCAN0TMTCSTS0HL RSCAN0.TMTCSTS0.UINT8[HL]
#define RSCAN0TMTCSTS0HH RSCAN0.TMTCSTS0.UINT8[HH]
#define RSCAN0TMTCSTS1 RSCAN0.TMTCSTS1.UINT32
#define RSCAN0TMTCSTS1L RSCAN0.TMTCSTS1.UINT16[L]
#define RSCAN0TMTCSTS1LL RSCAN0.TMTCSTS1.UINT8[LL]
#define RSCAN0TMTCSTS1LH RSCAN0.TMTCSTS1.UINT8[LH]
#define RSCAN0TMTCSTS1H RSCAN0.TMTCSTS1.UINT16[H]
#define RSCAN0TMTCSTS1HL RSCAN0.TMTCSTS1.UINT8[HL]
#define RSCAN0TMTCSTS1HH RSCAN0.TMTCSTS1.UINT8[HH]
#define RSCAN0TMTASTS0 RSCAN0.TMTASTS0.UINT32
#define RSCAN0TMTASTS0L RSCAN0.TMTASTS0.UINT16[L]
#define RSCAN0TMTASTS0LL RSCAN0.TMTASTS0.UINT8[LL]
#define RSCAN0TMTASTS0LH RSCAN0.TMTASTS0.UINT8[LH]
#define RSCAN0TMTASTS0H RSCAN0.TMTASTS0.UINT16[H]
#define RSCAN0TMTASTS0HL RSCAN0.TMTASTS0.UINT8[HL]
#define RSCAN0TMTASTS0HH RSCAN0.TMTASTS0.UINT8[HH]
#define RSCAN0TMTASTS1 RSCAN0.TMTASTS1.UINT32
#define RSCAN0TMTASTS1L RSCAN0.TMTASTS1.UINT16[L]
#define RSCAN0TMTASTS1LL RSCAN0.TMTASTS1.UINT8[LL]
#define RSCAN0TMTASTS1LH RSCAN0.TMTASTS1.UINT8[LH]
#define RSCAN0TMTASTS1H RSCAN0.TMTASTS1.UINT16[H]
#define RSCAN0TMTASTS1HL RSCAN0.TMTASTS1.UINT8[HL]
#define RSCAN0TMTASTS1HH RSCAN0.TMTASTS1.UINT8[HH]
#define RSCAN0TMIEC0 RSCAN0.TMIEC0.UINT32
#define RSCAN0TMIEC0L RSCAN0.TMIEC0.UINT16[L]
#define RSCAN0TMIEC0LL RSCAN0.TMIEC0.UINT8[LL]
#define RSCAN0TMIEC0LH RSCAN0.TMIEC0.UINT8[LH]
#define RSCAN0TMIEC0H RSCAN0.TMIEC0.UINT16[H]
#define RSCAN0TMIEC0HL RSCAN0.TMIEC0.UINT8[HL]
#define RSCAN0TMIEC0HH RSCAN0.TMIEC0.UINT8[HH]
#define RSCAN0TMIEC1 RSCAN0.TMIEC1.UINT32
#define RSCAN0TMIEC1L RSCAN0.TMIEC1.UINT16[L]
#define RSCAN0TMIEC1LL RSCAN0.TMIEC1.UINT8[LL]
#define RSCAN0TMIEC1LH RSCAN0.TMIEC1.UINT8[LH]
#define RSCAN0TMIEC1H RSCAN0.TMIEC1.UINT16[H]
#define RSCAN0TMIEC1HL RSCAN0.TMIEC1.UINT8[HL]
#define RSCAN0TMIEC1HH RSCAN0.TMIEC1.UINT8[HH]
#define RSCAN0TXQCC0 RSCAN0.TXQCC0.UINT32
#define RSCAN0TXQCC0L RSCAN0.TXQCC0.UINT16[L]
#define RSCAN0TXQCC0LL RSCAN0.TXQCC0.UINT8[LL]
#define RSCAN0TXQCC0LH RSCAN0.TXQCC0.UINT8[LH]
#define RSCAN0TXQCC0H RSCAN0.TXQCC0.UINT16[H]
#define RSCAN0TXQCC0HL RSCAN0.TXQCC0.UINT8[HL]
#define RSCAN0TXQCC0HH RSCAN0.TXQCC0.UINT8[HH]
#define RSCAN0TXQCC1 RSCAN0.TXQCC1.UINT32
#define RSCAN0TXQCC1L RSCAN0.TXQCC1.UINT16[L]
#define RSCAN0TXQCC1LL RSCAN0.TXQCC1.UINT8[LL]
#define RSCAN0TXQCC1LH RSCAN0.TXQCC1.UINT8[LH]
#define RSCAN0TXQCC1H RSCAN0.TXQCC1.UINT16[H]
#define RSCAN0TXQCC1HL RSCAN0.TXQCC1.UINT8[HL]
#define RSCAN0TXQCC1HH RSCAN0.TXQCC1.UINT8[HH]
#define RSCAN0TXQCC2 RSCAN0.TXQCC2.UINT32
#define RSCAN0TXQCC2L RSCAN0.TXQCC2.UINT16[L]
#define RSCAN0TXQCC2LL RSCAN0.TXQCC2.UINT8[LL]
#define RSCAN0TXQCC2LH RSCAN0.TXQCC2.UINT8[LH]
#define RSCAN0TXQCC2H RSCAN0.TXQCC2.UINT16[H]
#define RSCAN0TXQCC2HL RSCAN0.TXQCC2.UINT8[HL]
#define RSCAN0TXQCC2HH RSCAN0.TXQCC2.UINT8[HH]
#define RSCAN0TXQSTS0 RSCAN0.TXQSTS0.UINT32
#define RSCAN0TXQSTS0L RSCAN0.TXQSTS0.UINT16[L]
#define RSCAN0TXQSTS0LL RSCAN0.TXQSTS0.UINT8[LL]
#define RSCAN0TXQSTS0LH RSCAN0.TXQSTS0.UINT8[LH]
#define RSCAN0TXQSTS0H RSCAN0.TXQSTS0.UINT16[H]
#define RSCAN0TXQSTS0HL RSCAN0.TXQSTS0.UINT8[HL]
#define RSCAN0TXQSTS0HH RSCAN0.TXQSTS0.UINT8[HH]
#define RSCAN0TXQSTS1 RSCAN0.TXQSTS1.UINT32
#define RSCAN0TXQSTS1L RSCAN0.TXQSTS1.UINT16[L]
#define RSCAN0TXQSTS1LL RSCAN0.TXQSTS1.UINT8[LL]
#define RSCAN0TXQSTS1LH RSCAN0.TXQSTS1.UINT8[LH]
#define RSCAN0TXQSTS1H RSCAN0.TXQSTS1.UINT16[H]
#define RSCAN0TXQSTS1HL RSCAN0.TXQSTS1.UINT8[HL]
#define RSCAN0TXQSTS1HH RSCAN0.TXQSTS1.UINT8[HH]
#define RSCAN0TXQSTS2 RSCAN0.TXQSTS2.UINT32
#define RSCAN0TXQSTS2L RSCAN0.TXQSTS2.UINT16[L]
#define RSCAN0TXQSTS2LL RSCAN0.TXQSTS2.UINT8[LL]
#define RSCAN0TXQSTS2LH RSCAN0.TXQSTS2.UINT8[LH]
#define RSCAN0TXQSTS2H RSCAN0.TXQSTS2.UINT16[H]
#define RSCAN0TXQSTS2HL RSCAN0.TXQSTS2.UINT8[HL]
#define RSCAN0TXQSTS2HH RSCAN0.TXQSTS2.UINT8[HH]
#define RSCAN0TXQPCTR0 RSCAN0.TXQPCTR0.UINT32
#define RSCAN0TXQPCTR0L RSCAN0.TXQPCTR0.UINT16[L]
#define RSCAN0TXQPCTR0LL RSCAN0.TXQPCTR0.UINT8[LL]
#define RSCAN0TXQPCTR0LH RSCAN0.TXQPCTR0.UINT8[LH]
#define RSCAN0TXQPCTR0H RSCAN0.TXQPCTR0.UINT16[H]
#define RSCAN0TXQPCTR0HL RSCAN0.TXQPCTR0.UINT8[HL]
#define RSCAN0TXQPCTR0HH RSCAN0.TXQPCTR0.UINT8[HH]
#define RSCAN0TXQPCTR1 RSCAN0.TXQPCTR1.UINT32
#define RSCAN0TXQPCTR1L RSCAN0.TXQPCTR1.UINT16[L]
#define RSCAN0TXQPCTR1LL RSCAN0.TXQPCTR1.UINT8[LL]
#define RSCAN0TXQPCTR1LH RSCAN0.TXQPCTR1.UINT8[LH]
#define RSCAN0TXQPCTR1H RSCAN0.TXQPCTR1.UINT16[H]
#define RSCAN0TXQPCTR1HL RSCAN0.TXQPCTR1.UINT8[HL]
#define RSCAN0TXQPCTR1HH RSCAN0.TXQPCTR1.UINT8[HH]
#define RSCAN0TXQPCTR2 RSCAN0.TXQPCTR2.UINT32
#define RSCAN0TXQPCTR2L RSCAN0.TXQPCTR2.UINT16[L]
#define RSCAN0TXQPCTR2LL RSCAN0.TXQPCTR2.UINT8[LL]
#define RSCAN0TXQPCTR2LH RSCAN0.TXQPCTR2.UINT8[LH]
#define RSCAN0TXQPCTR2H RSCAN0.TXQPCTR2.UINT16[H]
#define RSCAN0TXQPCTR2HL RSCAN0.TXQPCTR2.UINT8[HL]
#define RSCAN0TXQPCTR2HH RSCAN0.TXQPCTR2.UINT8[HH]
#define RSCAN0THLCC0 RSCAN0.THLCC0.UINT32
#define RSCAN0THLCC0L RSCAN0.THLCC0.UINT16[L]
#define RSCAN0THLCC0LL RSCAN0.THLCC0.UINT8[LL]
#define RSCAN0THLCC0LH RSCAN0.THLCC0.UINT8[LH]
#define RSCAN0THLCC0H RSCAN0.THLCC0.UINT16[H]
#define RSCAN0THLCC0HL RSCAN0.THLCC0.UINT8[HL]
#define RSCAN0THLCC0HH RSCAN0.THLCC0.UINT8[HH]
#define RSCAN0THLCC1 RSCAN0.THLCC1.UINT32
#define RSCAN0THLCC1L RSCAN0.THLCC1.UINT16[L]
#define RSCAN0THLCC1LL RSCAN0.THLCC1.UINT8[LL]
#define RSCAN0THLCC1LH RSCAN0.THLCC1.UINT8[LH]
#define RSCAN0THLCC1H RSCAN0.THLCC1.UINT16[H]
#define RSCAN0THLCC1HL RSCAN0.THLCC1.UINT8[HL]
#define RSCAN0THLCC1HH RSCAN0.THLCC1.UINT8[HH]
#define RSCAN0THLCC2 RSCAN0.THLCC2.UINT32
#define RSCAN0THLCC2L RSCAN0.THLCC2.UINT16[L]
#define RSCAN0THLCC2LL RSCAN0.THLCC2.UINT8[LL]
#define RSCAN0THLCC2LH RSCAN0.THLCC2.UINT8[LH]
#define RSCAN0THLCC2H RSCAN0.THLCC2.UINT16[H]
#define RSCAN0THLCC2HL RSCAN0.THLCC2.UINT8[HL]
#define RSCAN0THLCC2HH RSCAN0.THLCC2.UINT8[HH]
#define RSCAN0THLSTS0 RSCAN0.THLSTS0.UINT32
#define RSCAN0THLSTS0L RSCAN0.THLSTS0.UINT16[L]
#define RSCAN0THLSTS0LL RSCAN0.THLSTS0.UINT8[LL]
#define RSCAN0THLSTS0LH RSCAN0.THLSTS0.UINT8[LH]
#define RSCAN0THLSTS0H RSCAN0.THLSTS0.UINT16[H]
#define RSCAN0THLSTS0HL RSCAN0.THLSTS0.UINT8[HL]
#define RSCAN0THLSTS0HH RSCAN0.THLSTS0.UINT8[HH]
#define RSCAN0THLSTS1 RSCAN0.THLSTS1.UINT32
#define RSCAN0THLSTS1L RSCAN0.THLSTS1.UINT16[L]
#define RSCAN0THLSTS1LL RSCAN0.THLSTS1.UINT8[LL]
#define RSCAN0THLSTS1LH RSCAN0.THLSTS1.UINT8[LH]
#define RSCAN0THLSTS1H RSCAN0.THLSTS1.UINT16[H]
#define RSCAN0THLSTS1HL RSCAN0.THLSTS1.UINT8[HL]
#define RSCAN0THLSTS1HH RSCAN0.THLSTS1.UINT8[HH]
#define RSCAN0THLSTS2 RSCAN0.THLSTS2.UINT32
#define RSCAN0THLSTS2L RSCAN0.THLSTS2.UINT16[L]
#define RSCAN0THLSTS2LL RSCAN0.THLSTS2.UINT8[LL]
#define RSCAN0THLSTS2LH RSCAN0.THLSTS2.UINT8[LH]
#define RSCAN0THLSTS2H RSCAN0.THLSTS2.UINT16[H]
#define RSCAN0THLSTS2HL RSCAN0.THLSTS2.UINT8[HL]
#define RSCAN0THLSTS2HH RSCAN0.THLSTS2.UINT8[HH]
#define RSCAN0THLPCTR0 RSCAN0.THLPCTR0.UINT32
#define RSCAN0THLPCTR0L RSCAN0.THLPCTR0.UINT16[L]
#define RSCAN0THLPCTR0LL RSCAN0.THLPCTR0.UINT8[LL]
#define RSCAN0THLPCTR0LH RSCAN0.THLPCTR0.UINT8[LH]
#define RSCAN0THLPCTR0H RSCAN0.THLPCTR0.UINT16[H]
#define RSCAN0THLPCTR0HL RSCAN0.THLPCTR0.UINT8[HL]
#define RSCAN0THLPCTR0HH RSCAN0.THLPCTR0.UINT8[HH]
#define RSCAN0THLPCTR1 RSCAN0.THLPCTR1.UINT32
#define RSCAN0THLPCTR1L RSCAN0.THLPCTR1.UINT16[L]
#define RSCAN0THLPCTR1LL RSCAN0.THLPCTR1.UINT8[LL]
#define RSCAN0THLPCTR1LH RSCAN0.THLPCTR1.UINT8[LH]
#define RSCAN0THLPCTR1H RSCAN0.THLPCTR1.UINT16[H]
#define RSCAN0THLPCTR1HL RSCAN0.THLPCTR1.UINT8[HL]
#define RSCAN0THLPCTR1HH RSCAN0.THLPCTR1.UINT8[HH]
#define RSCAN0THLPCTR2 RSCAN0.THLPCTR2.UINT32
#define RSCAN0THLPCTR2L RSCAN0.THLPCTR2.UINT16[L]
#define RSCAN0THLPCTR2LL RSCAN0.THLPCTR2.UINT8[LL]
#define RSCAN0THLPCTR2LH RSCAN0.THLPCTR2.UINT8[LH]
#define RSCAN0THLPCTR2H RSCAN0.THLPCTR2.UINT16[H]
#define RSCAN0THLPCTR2HL RSCAN0.THLPCTR2.UINT8[HL]
#define RSCAN0THLPCTR2HH RSCAN0.THLPCTR2.UINT8[HH]
#define RSCAN0GTINTSTS0 RSCAN0.GTINTSTS0.UINT32
#define RSCAN0GTINTSTS0L RSCAN0.GTINTSTS0.UINT16[L]
#define RSCAN0GTINTSTS0LL RSCAN0.GTINTSTS0.UINT8[LL]
#define RSCAN0GTINTSTS0LH RSCAN0.GTINTSTS0.UINT8[LH]
#define RSCAN0GTINTSTS0H RSCAN0.GTINTSTS0.UINT16[H]
#define RSCAN0GTINTSTS0HL RSCAN0.GTINTSTS0.UINT8[HL]
#define RSCAN0GTINTSTS0HH RSCAN0.GTINTSTS0.UINT8[HH]
#define RSCAN0GTSTCFG RSCAN0.GTSTCFG.UINT32
#define RSCAN0GTSTCFGL RSCAN0.GTSTCFG.UINT16[L]
#define RSCAN0GTSTCFGLL RSCAN0.GTSTCFG.UINT8[LL]
#define RSCAN0GTSTCFGLH RSCAN0.GTSTCFG.UINT8[LH]
#define RSCAN0GTSTCFGH RSCAN0.GTSTCFG.UINT16[H]
#define RSCAN0GTSTCFGHL RSCAN0.GTSTCFG.UINT8[HL]
#define RSCAN0GTSTCFGHH RSCAN0.GTSTCFG.UINT8[HH]
#define RSCAN0GTSTCTR RSCAN0.GTSTCTR.UINT32
#define RSCAN0GTSTCTRL RSCAN0.GTSTCTR.UINT16[L]
#define RSCAN0GTSTCTRLL RSCAN0.GTSTCTR.UINT8[LL]
#define RSCAN0GTSTCTRLH RSCAN0.GTSTCTR.UINT8[LH]
#define RSCAN0GTSTCTRH RSCAN0.GTSTCTR.UINT16[H]
#define RSCAN0GTSTCTRHL RSCAN0.GTSTCTR.UINT8[HL]
#define RSCAN0GTSTCTRHH RSCAN0.GTSTCTR.UINT8[HH]
#define RSCAN0GLOCKK RSCAN0.GLOCKK.UINT32
#define RSCAN0GLOCKKL RSCAN0.GLOCKK.UINT16[L]
#define RSCAN0GLOCKKH RSCAN0.GLOCKK.UINT16[H]
#define RSCAN0GAFLID0 RSCAN0.GAFLID0.UINT32
#define RSCAN0GAFLID0L RSCAN0.GAFLID0.UINT16[L]
#define RSCAN0GAFLID0LL RSCAN0.GAFLID0.UINT8[LL]
#define RSCAN0GAFLID0LH RSCAN0.GAFLID0.UINT8[LH]
#define RSCAN0GAFLID0H RSCAN0.GAFLID0.UINT16[H]
#define RSCAN0GAFLID0HL RSCAN0.GAFLID0.UINT8[HL]
#define RSCAN0GAFLID0HH RSCAN0.GAFLID0.UINT8[HH]
#define RSCAN0GAFLM0 RSCAN0.GAFLM0.UINT32
#define RSCAN0GAFLM0L RSCAN0.GAFLM0.UINT16[L]
#define RSCAN0GAFLM0LL RSCAN0.GAFLM0.UINT8[LL]
#define RSCAN0GAFLM0LH RSCAN0.GAFLM0.UINT8[LH]
#define RSCAN0GAFLM0H RSCAN0.GAFLM0.UINT16[H]
#define RSCAN0GAFLM0HL RSCAN0.GAFLM0.UINT8[HL]
#define RSCAN0GAFLM0HH RSCAN0.GAFLM0.UINT8[HH]
#define RSCAN0GAFLP00 RSCAN0.GAFLP00.UINT32
#define RSCAN0GAFLP00L RSCAN0.GAFLP00.UINT16[L]
#define RSCAN0GAFLP00LL RSCAN0.GAFLP00.UINT8[LL]
#define RSCAN0GAFLP00LH RSCAN0.GAFLP00.UINT8[LH]
#define RSCAN0GAFLP00H RSCAN0.GAFLP00.UINT16[H]
#define RSCAN0GAFLP00HL RSCAN0.GAFLP00.UINT8[HL]
#define RSCAN0GAFLP00HH RSCAN0.GAFLP00.UINT8[HH]
#define RSCAN0GAFLP10 RSCAN0.GAFLP10.UINT32
#define RSCAN0GAFLP10L RSCAN0.GAFLP10.UINT16[L]
#define RSCAN0GAFLP10LL RSCAN0.GAFLP10.UINT8[LL]
#define RSCAN0GAFLP10LH RSCAN0.GAFLP10.UINT8[LH]
#define RSCAN0GAFLP10H RSCAN0.GAFLP10.UINT16[H]
#define RSCAN0GAFLP10HL RSCAN0.GAFLP10.UINT8[HL]
#define RSCAN0GAFLP10HH RSCAN0.GAFLP10.UINT8[HH]
#define RSCAN0GAFLID1 RSCAN0.GAFLID1.UINT32
#define RSCAN0GAFLID1L RSCAN0.GAFLID1.UINT16[L]
#define RSCAN0GAFLID1LL RSCAN0.GAFLID1.UINT8[LL]
#define RSCAN0GAFLID1LH RSCAN0.GAFLID1.UINT8[LH]
#define RSCAN0GAFLID1H RSCAN0.GAFLID1.UINT16[H]
#define RSCAN0GAFLID1HL RSCAN0.GAFLID1.UINT8[HL]
#define RSCAN0GAFLID1HH RSCAN0.GAFLID1.UINT8[HH]
#define RSCAN0GAFLM1 RSCAN0.GAFLM1.UINT32
#define RSCAN0GAFLM1L RSCAN0.GAFLM1.UINT16[L]
#define RSCAN0GAFLM1LL RSCAN0.GAFLM1.UINT8[LL]
#define RSCAN0GAFLM1LH RSCAN0.GAFLM1.UINT8[LH]
#define RSCAN0GAFLM1H RSCAN0.GAFLM1.UINT16[H]
#define RSCAN0GAFLM1HL RSCAN0.GAFLM1.UINT8[HL]
#define RSCAN0GAFLM1HH RSCAN0.GAFLM1.UINT8[HH]
#define RSCAN0GAFLP01 RSCAN0.GAFLP01.UINT32
#define RSCAN0GAFLP01L RSCAN0.GAFLP01.UINT16[L]
#define RSCAN0GAFLP01LL RSCAN0.GAFLP01.UINT8[LL]
#define RSCAN0GAFLP01LH RSCAN0.GAFLP01.UINT8[LH]
#define RSCAN0GAFLP01H RSCAN0.GAFLP01.UINT16[H]
#define RSCAN0GAFLP01HL RSCAN0.GAFLP01.UINT8[HL]
#define RSCAN0GAFLP01HH RSCAN0.GAFLP01.UINT8[HH]
#define RSCAN0GAFLP11 RSCAN0.GAFLP11.UINT32
#define RSCAN0GAFLP11L RSCAN0.GAFLP11.UINT16[L]
#define RSCAN0GAFLP11LL RSCAN0.GAFLP11.UINT8[LL]
#define RSCAN0GAFLP11LH RSCAN0.GAFLP11.UINT8[LH]
#define RSCAN0GAFLP11H RSCAN0.GAFLP11.UINT16[H]
#define RSCAN0GAFLP11HL RSCAN0.GAFLP11.UINT8[HL]
#define RSCAN0GAFLP11HH RSCAN0.GAFLP11.UINT8[HH]
#define RSCAN0GAFLID2 RSCAN0.GAFLID2.UINT32
#define RSCAN0GAFLID2L RSCAN0.GAFLID2.UINT16[L]
#define RSCAN0GAFLID2LL RSCAN0.GAFLID2.UINT8[LL]
#define RSCAN0GAFLID2LH RSCAN0.GAFLID2.UINT8[LH]
#define RSCAN0GAFLID2H RSCAN0.GAFLID2.UINT16[H]
#define RSCAN0GAFLID2HL RSCAN0.GAFLID2.UINT8[HL]
#define RSCAN0GAFLID2HH RSCAN0.GAFLID2.UINT8[HH]
#define RSCAN0GAFLM2 RSCAN0.GAFLM2.UINT32
#define RSCAN0GAFLM2L RSCAN0.GAFLM2.UINT16[L]
#define RSCAN0GAFLM2LL RSCAN0.GAFLM2.UINT8[LL]
#define RSCAN0GAFLM2LH RSCAN0.GAFLM2.UINT8[LH]
#define RSCAN0GAFLM2H RSCAN0.GAFLM2.UINT16[H]
#define RSCAN0GAFLM2HL RSCAN0.GAFLM2.UINT8[HL]
#define RSCAN0GAFLM2HH RSCAN0.GAFLM2.UINT8[HH]
#define RSCAN0GAFLP02 RSCAN0.GAFLP02.UINT32
#define RSCAN0GAFLP02L RSCAN0.GAFLP02.UINT16[L]
#define RSCAN0GAFLP02LL RSCAN0.GAFLP02.UINT8[LL]
#define RSCAN0GAFLP02LH RSCAN0.GAFLP02.UINT8[LH]
#define RSCAN0GAFLP02H RSCAN0.GAFLP02.UINT16[H]
#define RSCAN0GAFLP02HL RSCAN0.GAFLP02.UINT8[HL]
#define RSCAN0GAFLP02HH RSCAN0.GAFLP02.UINT8[HH]
#define RSCAN0GAFLP12 RSCAN0.GAFLP12.UINT32
#define RSCAN0GAFLP12L RSCAN0.GAFLP12.UINT16[L]
#define RSCAN0GAFLP12LL RSCAN0.GAFLP12.UINT8[LL]
#define RSCAN0GAFLP12LH RSCAN0.GAFLP12.UINT8[LH]
#define RSCAN0GAFLP12H RSCAN0.GAFLP12.UINT16[H]
#define RSCAN0GAFLP12HL RSCAN0.GAFLP12.UINT8[HL]
#define RSCAN0GAFLP12HH RSCAN0.GAFLP12.UINT8[HH]
#define RSCAN0GAFLID3 RSCAN0.GAFLID3.UINT32
#define RSCAN0GAFLID3L RSCAN0.GAFLID3.UINT16[L]
#define RSCAN0GAFLID3LL RSCAN0.GAFLID3.UINT8[LL]
#define RSCAN0GAFLID3LH RSCAN0.GAFLID3.UINT8[LH]
#define RSCAN0GAFLID3H RSCAN0.GAFLID3.UINT16[H]
#define RSCAN0GAFLID3HL RSCAN0.GAFLID3.UINT8[HL]
#define RSCAN0GAFLID3HH RSCAN0.GAFLID3.UINT8[HH]
#define RSCAN0GAFLM3 RSCAN0.GAFLM3.UINT32
#define RSCAN0GAFLM3L RSCAN0.GAFLM3.UINT16[L]
#define RSCAN0GAFLM3LL RSCAN0.GAFLM3.UINT8[LL]
#define RSCAN0GAFLM3LH RSCAN0.GAFLM3.UINT8[LH]
#define RSCAN0GAFLM3H RSCAN0.GAFLM3.UINT16[H]
#define RSCAN0GAFLM3HL RSCAN0.GAFLM3.UINT8[HL]
#define RSCAN0GAFLM3HH RSCAN0.GAFLM3.UINT8[HH]
#define RSCAN0GAFLP03 RSCAN0.GAFLP03.UINT32
#define RSCAN0GAFLP03L RSCAN0.GAFLP03.UINT16[L]
#define RSCAN0GAFLP03LL RSCAN0.GAFLP03.UINT8[LL]
#define RSCAN0GAFLP03LH RSCAN0.GAFLP03.UINT8[LH]
#define RSCAN0GAFLP03H RSCAN0.GAFLP03.UINT16[H]
#define RSCAN0GAFLP03HL RSCAN0.GAFLP03.UINT8[HL]
#define RSCAN0GAFLP03HH RSCAN0.GAFLP03.UINT8[HH]
#define RSCAN0GAFLP13 RSCAN0.GAFLP13.UINT32
#define RSCAN0GAFLP13L RSCAN0.GAFLP13.UINT16[L]
#define RSCAN0GAFLP13LL RSCAN0.GAFLP13.UINT8[LL]
#define RSCAN0GAFLP13LH RSCAN0.GAFLP13.UINT8[LH]
#define RSCAN0GAFLP13H RSCAN0.GAFLP13.UINT16[H]
#define RSCAN0GAFLP13HL RSCAN0.GAFLP13.UINT8[HL]
#define RSCAN0GAFLP13HH RSCAN0.GAFLP13.UINT8[HH]
#define RSCAN0GAFLID4 RSCAN0.GAFLID4.UINT32
#define RSCAN0GAFLID4L RSCAN0.GAFLID4.UINT16[L]
#define RSCAN0GAFLID4LL RSCAN0.GAFLID4.UINT8[LL]
#define RSCAN0GAFLID4LH RSCAN0.GAFLID4.UINT8[LH]
#define RSCAN0GAFLID4H RSCAN0.GAFLID4.UINT16[H]
#define RSCAN0GAFLID4HL RSCAN0.GAFLID4.UINT8[HL]
#define RSCAN0GAFLID4HH RSCAN0.GAFLID4.UINT8[HH]
#define RSCAN0GAFLM4 RSCAN0.GAFLM4.UINT32
#define RSCAN0GAFLM4L RSCAN0.GAFLM4.UINT16[L]
#define RSCAN0GAFLM4LL RSCAN0.GAFLM4.UINT8[LL]
#define RSCAN0GAFLM4LH RSCAN0.GAFLM4.UINT8[LH]
#define RSCAN0GAFLM4H RSCAN0.GAFLM4.UINT16[H]
#define RSCAN0GAFLM4HL RSCAN0.GAFLM4.UINT8[HL]
#define RSCAN0GAFLM4HH RSCAN0.GAFLM4.UINT8[HH]
#define RSCAN0GAFLP04 RSCAN0.GAFLP04.UINT32
#define RSCAN0GAFLP04L RSCAN0.GAFLP04.UINT16[L]
#define RSCAN0GAFLP04LL RSCAN0.GAFLP04.UINT8[LL]
#define RSCAN0GAFLP04LH RSCAN0.GAFLP04.UINT8[LH]
#define RSCAN0GAFLP04H RSCAN0.GAFLP04.UINT16[H]
#define RSCAN0GAFLP04HL RSCAN0.GAFLP04.UINT8[HL]
#define RSCAN0GAFLP04HH RSCAN0.GAFLP04.UINT8[HH]
#define RSCAN0GAFLP14 RSCAN0.GAFLP14.UINT32
#define RSCAN0GAFLP14L RSCAN0.GAFLP14.UINT16[L]
#define RSCAN0GAFLP14LL RSCAN0.GAFLP14.UINT8[LL]
#define RSCAN0GAFLP14LH RSCAN0.GAFLP14.UINT8[LH]
#define RSCAN0GAFLP14H RSCAN0.GAFLP14.UINT16[H]
#define RSCAN0GAFLP14HL RSCAN0.GAFLP14.UINT8[HL]
#define RSCAN0GAFLP14HH RSCAN0.GAFLP14.UINT8[HH]
#define RSCAN0GAFLID5 RSCAN0.GAFLID5.UINT32
#define RSCAN0GAFLID5L RSCAN0.GAFLID5.UINT16[L]
#define RSCAN0GAFLID5LL RSCAN0.GAFLID5.UINT8[LL]
#define RSCAN0GAFLID5LH RSCAN0.GAFLID5.UINT8[LH]
#define RSCAN0GAFLID5H RSCAN0.GAFLID5.UINT16[H]
#define RSCAN0GAFLID5HL RSCAN0.GAFLID5.UINT8[HL]
#define RSCAN0GAFLID5HH RSCAN0.GAFLID5.UINT8[HH]
#define RSCAN0GAFLM5 RSCAN0.GAFLM5.UINT32
#define RSCAN0GAFLM5L RSCAN0.GAFLM5.UINT16[L]
#define RSCAN0GAFLM5LL RSCAN0.GAFLM5.UINT8[LL]
#define RSCAN0GAFLM5LH RSCAN0.GAFLM5.UINT8[LH]
#define RSCAN0GAFLM5H RSCAN0.GAFLM5.UINT16[H]
#define RSCAN0GAFLM5HL RSCAN0.GAFLM5.UINT8[HL]
#define RSCAN0GAFLM5HH RSCAN0.GAFLM5.UINT8[HH]
#define RSCAN0GAFLP05 RSCAN0.GAFLP05.UINT32
#define RSCAN0GAFLP05L RSCAN0.GAFLP05.UINT16[L]
#define RSCAN0GAFLP05LL RSCAN0.GAFLP05.UINT8[LL]
#define RSCAN0GAFLP05LH RSCAN0.GAFLP05.UINT8[LH]
#define RSCAN0GAFLP05H RSCAN0.GAFLP05.UINT16[H]
#define RSCAN0GAFLP05HL RSCAN0.GAFLP05.UINT8[HL]
#define RSCAN0GAFLP05HH RSCAN0.GAFLP05.UINT8[HH]
#define RSCAN0GAFLP15 RSCAN0.GAFLP15.UINT32
#define RSCAN0GAFLP15L RSCAN0.GAFLP15.UINT16[L]
#define RSCAN0GAFLP15LL RSCAN0.GAFLP15.UINT8[LL]
#define RSCAN0GAFLP15LH RSCAN0.GAFLP15.UINT8[LH]
#define RSCAN0GAFLP15H RSCAN0.GAFLP15.UINT16[H]
#define RSCAN0GAFLP15HL RSCAN0.GAFLP15.UINT8[HL]
#define RSCAN0GAFLP15HH RSCAN0.GAFLP15.UINT8[HH]
#define RSCAN0GAFLID6 RSCAN0.GAFLID6.UINT32
#define RSCAN0GAFLID6L RSCAN0.GAFLID6.UINT16[L]
#define RSCAN0GAFLID6LL RSCAN0.GAFLID6.UINT8[LL]
#define RSCAN0GAFLID6LH RSCAN0.GAFLID6.UINT8[LH]
#define RSCAN0GAFLID6H RSCAN0.GAFLID6.UINT16[H]
#define RSCAN0GAFLID6HL RSCAN0.GAFLID6.UINT8[HL]
#define RSCAN0GAFLID6HH RSCAN0.GAFLID6.UINT8[HH]
#define RSCAN0GAFLM6 RSCAN0.GAFLM6.UINT32
#define RSCAN0GAFLM6L RSCAN0.GAFLM6.UINT16[L]
#define RSCAN0GAFLM6LL RSCAN0.GAFLM6.UINT8[LL]
#define RSCAN0GAFLM6LH RSCAN0.GAFLM6.UINT8[LH]
#define RSCAN0GAFLM6H RSCAN0.GAFLM6.UINT16[H]
#define RSCAN0GAFLM6HL RSCAN0.GAFLM6.UINT8[HL]
#define RSCAN0GAFLM6HH RSCAN0.GAFLM6.UINT8[HH]
#define RSCAN0GAFLP06 RSCAN0.GAFLP06.UINT32
#define RSCAN0GAFLP06L RSCAN0.GAFLP06.UINT16[L]
#define RSCAN0GAFLP06LL RSCAN0.GAFLP06.UINT8[LL]
#define RSCAN0GAFLP06LH RSCAN0.GAFLP06.UINT8[LH]
#define RSCAN0GAFLP06H RSCAN0.GAFLP06.UINT16[H]
#define RSCAN0GAFLP06HL RSCAN0.GAFLP06.UINT8[HL]
#define RSCAN0GAFLP06HH RSCAN0.GAFLP06.UINT8[HH]
#define RSCAN0GAFLP16 RSCAN0.GAFLP16.UINT32
#define RSCAN0GAFLP16L RSCAN0.GAFLP16.UINT16[L]
#define RSCAN0GAFLP16LL RSCAN0.GAFLP16.UINT8[LL]
#define RSCAN0GAFLP16LH RSCAN0.GAFLP16.UINT8[LH]
#define RSCAN0GAFLP16H RSCAN0.GAFLP16.UINT16[H]
#define RSCAN0GAFLP16HL RSCAN0.GAFLP16.UINT8[HL]
#define RSCAN0GAFLP16HH RSCAN0.GAFLP16.UINT8[HH]
#define RSCAN0GAFLID7 RSCAN0.GAFLID7.UINT32
#define RSCAN0GAFLID7L RSCAN0.GAFLID7.UINT16[L]
#define RSCAN0GAFLID7LL RSCAN0.GAFLID7.UINT8[LL]
#define RSCAN0GAFLID7LH RSCAN0.GAFLID7.UINT8[LH]
#define RSCAN0GAFLID7H RSCAN0.GAFLID7.UINT16[H]
#define RSCAN0GAFLID7HL RSCAN0.GAFLID7.UINT8[HL]
#define RSCAN0GAFLID7HH RSCAN0.GAFLID7.UINT8[HH]
#define RSCAN0GAFLM7 RSCAN0.GAFLM7.UINT32
#define RSCAN0GAFLM7L RSCAN0.GAFLM7.UINT16[L]
#define RSCAN0GAFLM7LL RSCAN0.GAFLM7.UINT8[LL]
#define RSCAN0GAFLM7LH RSCAN0.GAFLM7.UINT8[LH]
#define RSCAN0GAFLM7H RSCAN0.GAFLM7.UINT16[H]
#define RSCAN0GAFLM7HL RSCAN0.GAFLM7.UINT8[HL]
#define RSCAN0GAFLM7HH RSCAN0.GAFLM7.UINT8[HH]
#define RSCAN0GAFLP07 RSCAN0.GAFLP07.UINT32
#define RSCAN0GAFLP07L RSCAN0.GAFLP07.UINT16[L]
#define RSCAN0GAFLP07LL RSCAN0.GAFLP07.UINT8[LL]
#define RSCAN0GAFLP07LH RSCAN0.GAFLP07.UINT8[LH]
#define RSCAN0GAFLP07H RSCAN0.GAFLP07.UINT16[H]
#define RSCAN0GAFLP07HL RSCAN0.GAFLP07.UINT8[HL]
#define RSCAN0GAFLP07HH RSCAN0.GAFLP07.UINT8[HH]
#define RSCAN0GAFLP17 RSCAN0.GAFLP17.UINT32
#define RSCAN0GAFLP17L RSCAN0.GAFLP17.UINT16[L]
#define RSCAN0GAFLP17LL RSCAN0.GAFLP17.UINT8[LL]
#define RSCAN0GAFLP17LH RSCAN0.GAFLP17.UINT8[LH]
#define RSCAN0GAFLP17H RSCAN0.GAFLP17.UINT16[H]
#define RSCAN0GAFLP17HL RSCAN0.GAFLP17.UINT8[HL]
#define RSCAN0GAFLP17HH RSCAN0.GAFLP17.UINT8[HH]
#define RSCAN0GAFLID8 RSCAN0.GAFLID8.UINT32
#define RSCAN0GAFLID8L RSCAN0.GAFLID8.UINT16[L]
#define RSCAN0GAFLID8LL RSCAN0.GAFLID8.UINT8[LL]
#define RSCAN0GAFLID8LH RSCAN0.GAFLID8.UINT8[LH]
#define RSCAN0GAFLID8H RSCAN0.GAFLID8.UINT16[H]
#define RSCAN0GAFLID8HL RSCAN0.GAFLID8.UINT8[HL]
#define RSCAN0GAFLID8HH RSCAN0.GAFLID8.UINT8[HH]
#define RSCAN0GAFLM8 RSCAN0.GAFLM8.UINT32
#define RSCAN0GAFLM8L RSCAN0.GAFLM8.UINT16[L]
#define RSCAN0GAFLM8LL RSCAN0.GAFLM8.UINT8[LL]
#define RSCAN0GAFLM8LH RSCAN0.GAFLM8.UINT8[LH]
#define RSCAN0GAFLM8H RSCAN0.GAFLM8.UINT16[H]
#define RSCAN0GAFLM8HL RSCAN0.GAFLM8.UINT8[HL]
#define RSCAN0GAFLM8HH RSCAN0.GAFLM8.UINT8[HH]
#define RSCAN0GAFLP08 RSCAN0.GAFLP08.UINT32
#define RSCAN0GAFLP08L RSCAN0.GAFLP08.UINT16[L]
#define RSCAN0GAFLP08LL RSCAN0.GAFLP08.UINT8[LL]
#define RSCAN0GAFLP08LH RSCAN0.GAFLP08.UINT8[LH]
#define RSCAN0GAFLP08H RSCAN0.GAFLP08.UINT16[H]
#define RSCAN0GAFLP08HL RSCAN0.GAFLP08.UINT8[HL]
#define RSCAN0GAFLP08HH RSCAN0.GAFLP08.UINT8[HH]
#define RSCAN0GAFLP18 RSCAN0.GAFLP18.UINT32
#define RSCAN0GAFLP18L RSCAN0.GAFLP18.UINT16[L]
#define RSCAN0GAFLP18LL RSCAN0.GAFLP18.UINT8[LL]
#define RSCAN0GAFLP18LH RSCAN0.GAFLP18.UINT8[LH]
#define RSCAN0GAFLP18H RSCAN0.GAFLP18.UINT16[H]
#define RSCAN0GAFLP18HL RSCAN0.GAFLP18.UINT8[HL]
#define RSCAN0GAFLP18HH RSCAN0.GAFLP18.UINT8[HH]
#define RSCAN0GAFLID9 RSCAN0.GAFLID9.UINT32
#define RSCAN0GAFLID9L RSCAN0.GAFLID9.UINT16[L]
#define RSCAN0GAFLID9LL RSCAN0.GAFLID9.UINT8[LL]
#define RSCAN0GAFLID9LH RSCAN0.GAFLID9.UINT8[LH]
#define RSCAN0GAFLID9H RSCAN0.GAFLID9.UINT16[H]
#define RSCAN0GAFLID9HL RSCAN0.GAFLID9.UINT8[HL]
#define RSCAN0GAFLID9HH RSCAN0.GAFLID9.UINT8[HH]
#define RSCAN0GAFLM9 RSCAN0.GAFLM9.UINT32
#define RSCAN0GAFLM9L RSCAN0.GAFLM9.UINT16[L]
#define RSCAN0GAFLM9LL RSCAN0.GAFLM9.UINT8[LL]
#define RSCAN0GAFLM9LH RSCAN0.GAFLM9.UINT8[LH]
#define RSCAN0GAFLM9H RSCAN0.GAFLM9.UINT16[H]
#define RSCAN0GAFLM9HL RSCAN0.GAFLM9.UINT8[HL]
#define RSCAN0GAFLM9HH RSCAN0.GAFLM9.UINT8[HH]
#define RSCAN0GAFLP09 RSCAN0.GAFLP09.UINT32
#define RSCAN0GAFLP09L RSCAN0.GAFLP09.UINT16[L]
#define RSCAN0GAFLP09LL RSCAN0.GAFLP09.UINT8[LL]
#define RSCAN0GAFLP09LH RSCAN0.GAFLP09.UINT8[LH]
#define RSCAN0GAFLP09H RSCAN0.GAFLP09.UINT16[H]
#define RSCAN0GAFLP09HL RSCAN0.GAFLP09.UINT8[HL]
#define RSCAN0GAFLP09HH RSCAN0.GAFLP09.UINT8[HH]
#define RSCAN0GAFLP19 RSCAN0.GAFLP19.UINT32
#define RSCAN0GAFLP19L RSCAN0.GAFLP19.UINT16[L]
#define RSCAN0GAFLP19LL RSCAN0.GAFLP19.UINT8[LL]
#define RSCAN0GAFLP19LH RSCAN0.GAFLP19.UINT8[LH]
#define RSCAN0GAFLP19H RSCAN0.GAFLP19.UINT16[H]
#define RSCAN0GAFLP19HL RSCAN0.GAFLP19.UINT8[HL]
#define RSCAN0GAFLP19HH RSCAN0.GAFLP19.UINT8[HH]
#define RSCAN0GAFLID10 RSCAN0.GAFLID10.UINT32
#define RSCAN0GAFLID10L RSCAN0.GAFLID10.UINT16[L]
#define RSCAN0GAFLID10LL RSCAN0.GAFLID10.UINT8[LL]
#define RSCAN0GAFLID10LH RSCAN0.GAFLID10.UINT8[LH]
#define RSCAN0GAFLID10H RSCAN0.GAFLID10.UINT16[H]
#define RSCAN0GAFLID10HL RSCAN0.GAFLID10.UINT8[HL]
#define RSCAN0GAFLID10HH RSCAN0.GAFLID10.UINT8[HH]
#define RSCAN0GAFLM10 RSCAN0.GAFLM10.UINT32
#define RSCAN0GAFLM10L RSCAN0.GAFLM10.UINT16[L]
#define RSCAN0GAFLM10LL RSCAN0.GAFLM10.UINT8[LL]
#define RSCAN0GAFLM10LH RSCAN0.GAFLM10.UINT8[LH]
#define RSCAN0GAFLM10H RSCAN0.GAFLM10.UINT16[H]
#define RSCAN0GAFLM10HL RSCAN0.GAFLM10.UINT8[HL]
#define RSCAN0GAFLM10HH RSCAN0.GAFLM10.UINT8[HH]
#define RSCAN0GAFLP010 RSCAN0.GAFLP010.UINT32
#define RSCAN0GAFLP010L RSCAN0.GAFLP010.UINT16[L]
#define RSCAN0GAFLP010LL RSCAN0.GAFLP010.UINT8[LL]
#define RSCAN0GAFLP010LH RSCAN0.GAFLP010.UINT8[LH]
#define RSCAN0GAFLP010H RSCAN0.GAFLP010.UINT16[H]
#define RSCAN0GAFLP010HL RSCAN0.GAFLP010.UINT8[HL]
#define RSCAN0GAFLP010HH RSCAN0.GAFLP010.UINT8[HH]
#define RSCAN0GAFLP110 RSCAN0.GAFLP110.UINT32
#define RSCAN0GAFLP110L RSCAN0.GAFLP110.UINT16[L]
#define RSCAN0GAFLP110LL RSCAN0.GAFLP110.UINT8[LL]
#define RSCAN0GAFLP110LH RSCAN0.GAFLP110.UINT8[LH]
#define RSCAN0GAFLP110H RSCAN0.GAFLP110.UINT16[H]
#define RSCAN0GAFLP110HL RSCAN0.GAFLP110.UINT8[HL]
#define RSCAN0GAFLP110HH RSCAN0.GAFLP110.UINT8[HH]
#define RSCAN0GAFLID11 RSCAN0.GAFLID11.UINT32
#define RSCAN0GAFLID11L RSCAN0.GAFLID11.UINT16[L]
#define RSCAN0GAFLID11LL RSCAN0.GAFLID11.UINT8[LL]
#define RSCAN0GAFLID11LH RSCAN0.GAFLID11.UINT8[LH]
#define RSCAN0GAFLID11H RSCAN0.GAFLID11.UINT16[H]
#define RSCAN0GAFLID11HL RSCAN0.GAFLID11.UINT8[HL]
#define RSCAN0GAFLID11HH RSCAN0.GAFLID11.UINT8[HH]
#define RSCAN0GAFLM11 RSCAN0.GAFLM11.UINT32
#define RSCAN0GAFLM11L RSCAN0.GAFLM11.UINT16[L]
#define RSCAN0GAFLM11LL RSCAN0.GAFLM11.UINT8[LL]
#define RSCAN0GAFLM11LH RSCAN0.GAFLM11.UINT8[LH]
#define RSCAN0GAFLM11H RSCAN0.GAFLM11.UINT16[H]
#define RSCAN0GAFLM11HL RSCAN0.GAFLM11.UINT8[HL]
#define RSCAN0GAFLM11HH RSCAN0.GAFLM11.UINT8[HH]
#define RSCAN0GAFLP011 RSCAN0.GAFLP011.UINT32
#define RSCAN0GAFLP011L RSCAN0.GAFLP011.UINT16[L]
#define RSCAN0GAFLP011LL RSCAN0.GAFLP011.UINT8[LL]
#define RSCAN0GAFLP011LH RSCAN0.GAFLP011.UINT8[LH]
#define RSCAN0GAFLP011H RSCAN0.GAFLP011.UINT16[H]
#define RSCAN0GAFLP011HL RSCAN0.GAFLP011.UINT8[HL]
#define RSCAN0GAFLP011HH RSCAN0.GAFLP011.UINT8[HH]
#define RSCAN0GAFLP111 RSCAN0.GAFLP111.UINT32
#define RSCAN0GAFLP111L RSCAN0.GAFLP111.UINT16[L]
#define RSCAN0GAFLP111LL RSCAN0.GAFLP111.UINT8[LL]
#define RSCAN0GAFLP111LH RSCAN0.GAFLP111.UINT8[LH]
#define RSCAN0GAFLP111H RSCAN0.GAFLP111.UINT16[H]
#define RSCAN0GAFLP111HL RSCAN0.GAFLP111.UINT8[HL]
#define RSCAN0GAFLP111HH RSCAN0.GAFLP111.UINT8[HH]
#define RSCAN0GAFLID12 RSCAN0.GAFLID12.UINT32
#define RSCAN0GAFLID12L RSCAN0.GAFLID12.UINT16[L]
#define RSCAN0GAFLID12LL RSCAN0.GAFLID12.UINT8[LL]
#define RSCAN0GAFLID12LH RSCAN0.GAFLID12.UINT8[LH]
#define RSCAN0GAFLID12H RSCAN0.GAFLID12.UINT16[H]
#define RSCAN0GAFLID12HL RSCAN0.GAFLID12.UINT8[HL]
#define RSCAN0GAFLID12HH RSCAN0.GAFLID12.UINT8[HH]
#define RSCAN0GAFLM12 RSCAN0.GAFLM12.UINT32
#define RSCAN0GAFLM12L RSCAN0.GAFLM12.UINT16[L]
#define RSCAN0GAFLM12LL RSCAN0.GAFLM12.UINT8[LL]
#define RSCAN0GAFLM12LH RSCAN0.GAFLM12.UINT8[LH]
#define RSCAN0GAFLM12H RSCAN0.GAFLM12.UINT16[H]
#define RSCAN0GAFLM12HL RSCAN0.GAFLM12.UINT8[HL]
#define RSCAN0GAFLM12HH RSCAN0.GAFLM12.UINT8[HH]
#define RSCAN0GAFLP012 RSCAN0.GAFLP012.UINT32
#define RSCAN0GAFLP012L RSCAN0.GAFLP012.UINT16[L]
#define RSCAN0GAFLP012LL RSCAN0.GAFLP012.UINT8[LL]
#define RSCAN0GAFLP012LH RSCAN0.GAFLP012.UINT8[LH]
#define RSCAN0GAFLP012H RSCAN0.GAFLP012.UINT16[H]
#define RSCAN0GAFLP012HL RSCAN0.GAFLP012.UINT8[HL]
#define RSCAN0GAFLP012HH RSCAN0.GAFLP012.UINT8[HH]
#define RSCAN0GAFLP112 RSCAN0.GAFLP112.UINT32
#define RSCAN0GAFLP112L RSCAN0.GAFLP112.UINT16[L]
#define RSCAN0GAFLP112LL RSCAN0.GAFLP112.UINT8[LL]
#define RSCAN0GAFLP112LH RSCAN0.GAFLP112.UINT8[LH]
#define RSCAN0GAFLP112H RSCAN0.GAFLP112.UINT16[H]
#define RSCAN0GAFLP112HL RSCAN0.GAFLP112.UINT8[HL]
#define RSCAN0GAFLP112HH RSCAN0.GAFLP112.UINT8[HH]
#define RSCAN0GAFLID13 RSCAN0.GAFLID13.UINT32
#define RSCAN0GAFLID13L RSCAN0.GAFLID13.UINT16[L]
#define RSCAN0GAFLID13LL RSCAN0.GAFLID13.UINT8[LL]
#define RSCAN0GAFLID13LH RSCAN0.GAFLID13.UINT8[LH]
#define RSCAN0GAFLID13H RSCAN0.GAFLID13.UINT16[H]
#define RSCAN0GAFLID13HL RSCAN0.GAFLID13.UINT8[HL]
#define RSCAN0GAFLID13HH RSCAN0.GAFLID13.UINT8[HH]
#define RSCAN0GAFLM13 RSCAN0.GAFLM13.UINT32
#define RSCAN0GAFLM13L RSCAN0.GAFLM13.UINT16[L]
#define RSCAN0GAFLM13LL RSCAN0.GAFLM13.UINT8[LL]
#define RSCAN0GAFLM13LH RSCAN0.GAFLM13.UINT8[LH]
#define RSCAN0GAFLM13H RSCAN0.GAFLM13.UINT16[H]
#define RSCAN0GAFLM13HL RSCAN0.GAFLM13.UINT8[HL]
#define RSCAN0GAFLM13HH RSCAN0.GAFLM13.UINT8[HH]
#define RSCAN0GAFLP013 RSCAN0.GAFLP013.UINT32
#define RSCAN0GAFLP013L RSCAN0.GAFLP013.UINT16[L]
#define RSCAN0GAFLP013LL RSCAN0.GAFLP013.UINT8[LL]
#define RSCAN0GAFLP013LH RSCAN0.GAFLP013.UINT8[LH]
#define RSCAN0GAFLP013H RSCAN0.GAFLP013.UINT16[H]
#define RSCAN0GAFLP013HL RSCAN0.GAFLP013.UINT8[HL]
#define RSCAN0GAFLP013HH RSCAN0.GAFLP013.UINT8[HH]
#define RSCAN0GAFLP113 RSCAN0.GAFLP113.UINT32
#define RSCAN0GAFLP113L RSCAN0.GAFLP113.UINT16[L]
#define RSCAN0GAFLP113LL RSCAN0.GAFLP113.UINT8[LL]
#define RSCAN0GAFLP113LH RSCAN0.GAFLP113.UINT8[LH]
#define RSCAN0GAFLP113H RSCAN0.GAFLP113.UINT16[H]
#define RSCAN0GAFLP113HL RSCAN0.GAFLP113.UINT8[HL]
#define RSCAN0GAFLP113HH RSCAN0.GAFLP113.UINT8[HH]
#define RSCAN0GAFLID14 RSCAN0.GAFLID14.UINT32
#define RSCAN0GAFLID14L RSCAN0.GAFLID14.UINT16[L]
#define RSCAN0GAFLID14LL RSCAN0.GAFLID14.UINT8[LL]
#define RSCAN0GAFLID14LH RSCAN0.GAFLID14.UINT8[LH]
#define RSCAN0GAFLID14H RSCAN0.GAFLID14.UINT16[H]
#define RSCAN0GAFLID14HL RSCAN0.GAFLID14.UINT8[HL]
#define RSCAN0GAFLID14HH RSCAN0.GAFLID14.UINT8[HH]
#define RSCAN0GAFLM14 RSCAN0.GAFLM14.UINT32
#define RSCAN0GAFLM14L RSCAN0.GAFLM14.UINT16[L]
#define RSCAN0GAFLM14LL RSCAN0.GAFLM14.UINT8[LL]
#define RSCAN0GAFLM14LH RSCAN0.GAFLM14.UINT8[LH]
#define RSCAN0GAFLM14H RSCAN0.GAFLM14.UINT16[H]
#define RSCAN0GAFLM14HL RSCAN0.GAFLM14.UINT8[HL]
#define RSCAN0GAFLM14HH RSCAN0.GAFLM14.UINT8[HH]
#define RSCAN0GAFLP014 RSCAN0.GAFLP014.UINT32
#define RSCAN0GAFLP014L RSCAN0.GAFLP014.UINT16[L]
#define RSCAN0GAFLP014LL RSCAN0.GAFLP014.UINT8[LL]
#define RSCAN0GAFLP014LH RSCAN0.GAFLP014.UINT8[LH]
#define RSCAN0GAFLP014H RSCAN0.GAFLP014.UINT16[H]
#define RSCAN0GAFLP014HL RSCAN0.GAFLP014.UINT8[HL]
#define RSCAN0GAFLP014HH RSCAN0.GAFLP014.UINT8[HH]
#define RSCAN0GAFLP114 RSCAN0.GAFLP114.UINT32
#define RSCAN0GAFLP114L RSCAN0.GAFLP114.UINT16[L]
#define RSCAN0GAFLP114LL RSCAN0.GAFLP114.UINT8[LL]
#define RSCAN0GAFLP114LH RSCAN0.GAFLP114.UINT8[LH]
#define RSCAN0GAFLP114H RSCAN0.GAFLP114.UINT16[H]
#define RSCAN0GAFLP114HL RSCAN0.GAFLP114.UINT8[HL]
#define RSCAN0GAFLP114HH RSCAN0.GAFLP114.UINT8[HH]
#define RSCAN0GAFLID15 RSCAN0.GAFLID15.UINT32
#define RSCAN0GAFLID15L RSCAN0.GAFLID15.UINT16[L]
#define RSCAN0GAFLID15LL RSCAN0.GAFLID15.UINT8[LL]
#define RSCAN0GAFLID15LH RSCAN0.GAFLID15.UINT8[LH]
#define RSCAN0GAFLID15H RSCAN0.GAFLID15.UINT16[H]
#define RSCAN0GAFLID15HL RSCAN0.GAFLID15.UINT8[HL]
#define RSCAN0GAFLID15HH RSCAN0.GAFLID15.UINT8[HH]
#define RSCAN0GAFLM15 RSCAN0.GAFLM15.UINT32
#define RSCAN0GAFLM15L RSCAN0.GAFLM15.UINT16[L]
#define RSCAN0GAFLM15LL RSCAN0.GAFLM15.UINT8[LL]
#define RSCAN0GAFLM15LH RSCAN0.GAFLM15.UINT8[LH]
#define RSCAN0GAFLM15H RSCAN0.GAFLM15.UINT16[H]
#define RSCAN0GAFLM15HL RSCAN0.GAFLM15.UINT8[HL]
#define RSCAN0GAFLM15HH RSCAN0.GAFLM15.UINT8[HH]
#define RSCAN0GAFLP015 RSCAN0.GAFLP015.UINT32
#define RSCAN0GAFLP015L RSCAN0.GAFLP015.UINT16[L]
#define RSCAN0GAFLP015LL RSCAN0.GAFLP015.UINT8[LL]
#define RSCAN0GAFLP015LH RSCAN0.GAFLP015.UINT8[LH]
#define RSCAN0GAFLP015H RSCAN0.GAFLP015.UINT16[H]
#define RSCAN0GAFLP015HL RSCAN0.GAFLP015.UINT8[HL]
#define RSCAN0GAFLP015HH RSCAN0.GAFLP015.UINT8[HH]
#define RSCAN0GAFLP115 RSCAN0.GAFLP115.UINT32
#define RSCAN0GAFLP115L RSCAN0.GAFLP115.UINT16[L]
#define RSCAN0GAFLP115LL RSCAN0.GAFLP115.UINT8[LL]
#define RSCAN0GAFLP115LH RSCAN0.GAFLP115.UINT8[LH]
#define RSCAN0GAFLP115H RSCAN0.GAFLP115.UINT16[H]
#define RSCAN0GAFLP115HL RSCAN0.GAFLP115.UINT8[HL]
#define RSCAN0GAFLP115HH RSCAN0.GAFLP115.UINT8[HH]
#define RSCAN0RMID0 RSCAN0.RMID0.UINT32
#define RSCAN0RMID0L RSCAN0.RMID0.UINT16[L]
#define RSCAN0RMID0LL RSCAN0.RMID0.UINT8[LL]
#define RSCAN0RMID0LH RSCAN0.RMID0.UINT8[LH]
#define RSCAN0RMID0H RSCAN0.RMID0.UINT16[H]
#define RSCAN0RMID0HL RSCAN0.RMID0.UINT8[HL]
#define RSCAN0RMID0HH RSCAN0.RMID0.UINT8[HH]
#define RSCAN0RMPTR0 RSCAN0.RMPTR0.UINT32
#define RSCAN0RMPTR0L RSCAN0.RMPTR0.UINT16[L]
#define RSCAN0RMPTR0LL RSCAN0.RMPTR0.UINT8[LL]
#define RSCAN0RMPTR0LH RSCAN0.RMPTR0.UINT8[LH]
#define RSCAN0RMPTR0H RSCAN0.RMPTR0.UINT16[H]
#define RSCAN0RMPTR0HL RSCAN0.RMPTR0.UINT8[HL]
#define RSCAN0RMPTR0HH RSCAN0.RMPTR0.UINT8[HH]
#define RSCAN0RMDF00 RSCAN0.RMDF00.UINT32
#define RSCAN0RMDF00L RSCAN0.RMDF00.UINT16[L]
#define RSCAN0RMDF00LL RSCAN0.RMDF00.UINT8[LL]
#define RSCAN0RMDF00LH RSCAN0.RMDF00.UINT8[LH]
#define RSCAN0RMDF00H RSCAN0.RMDF00.UINT16[H]
#define RSCAN0RMDF00HL RSCAN0.RMDF00.UINT8[HL]
#define RSCAN0RMDF00HH RSCAN0.RMDF00.UINT8[HH]
#define RSCAN0RMDF10 RSCAN0.RMDF10.UINT32
#define RSCAN0RMDF10L RSCAN0.RMDF10.UINT16[L]
#define RSCAN0RMDF10LL RSCAN0.RMDF10.UINT8[LL]
#define RSCAN0RMDF10LH RSCAN0.RMDF10.UINT8[LH]
#define RSCAN0RMDF10H RSCAN0.RMDF10.UINT16[H]
#define RSCAN0RMDF10HL RSCAN0.RMDF10.UINT8[HL]
#define RSCAN0RMDF10HH RSCAN0.RMDF10.UINT8[HH]
#define RSCAN0RMID1 RSCAN0.RMID1.UINT32
#define RSCAN0RMID1L RSCAN0.RMID1.UINT16[L]
#define RSCAN0RMID1LL RSCAN0.RMID1.UINT8[LL]
#define RSCAN0RMID1LH RSCAN0.RMID1.UINT8[LH]
#define RSCAN0RMID1H RSCAN0.RMID1.UINT16[H]
#define RSCAN0RMID1HL RSCAN0.RMID1.UINT8[HL]
#define RSCAN0RMID1HH RSCAN0.RMID1.UINT8[HH]
#define RSCAN0RMPTR1 RSCAN0.RMPTR1.UINT32
#define RSCAN0RMPTR1L RSCAN0.RMPTR1.UINT16[L]
#define RSCAN0RMPTR1LL RSCAN0.RMPTR1.UINT8[LL]
#define RSCAN0RMPTR1LH RSCAN0.RMPTR1.UINT8[LH]
#define RSCAN0RMPTR1H RSCAN0.RMPTR1.UINT16[H]
#define RSCAN0RMPTR1HL RSCAN0.RMPTR1.UINT8[HL]
#define RSCAN0RMPTR1HH RSCAN0.RMPTR1.UINT8[HH]
#define RSCAN0RMDF01 RSCAN0.RMDF01.UINT32
#define RSCAN0RMDF01L RSCAN0.RMDF01.UINT16[L]
#define RSCAN0RMDF01LL RSCAN0.RMDF01.UINT8[LL]
#define RSCAN0RMDF01LH RSCAN0.RMDF01.UINT8[LH]
#define RSCAN0RMDF01H RSCAN0.RMDF01.UINT16[H]
#define RSCAN0RMDF01HL RSCAN0.RMDF01.UINT8[HL]
#define RSCAN0RMDF01HH RSCAN0.RMDF01.UINT8[HH]
#define RSCAN0RMDF11 RSCAN0.RMDF11.UINT32
#define RSCAN0RMDF11L RSCAN0.RMDF11.UINT16[L]
#define RSCAN0RMDF11LL RSCAN0.RMDF11.UINT8[LL]
#define RSCAN0RMDF11LH RSCAN0.RMDF11.UINT8[LH]
#define RSCAN0RMDF11H RSCAN0.RMDF11.UINT16[H]
#define RSCAN0RMDF11HL RSCAN0.RMDF11.UINT8[HL]
#define RSCAN0RMDF11HH RSCAN0.RMDF11.UINT8[HH]
#define RSCAN0RMID2 RSCAN0.RMID2.UINT32
#define RSCAN0RMID2L RSCAN0.RMID2.UINT16[L]
#define RSCAN0RMID2LL RSCAN0.RMID2.UINT8[LL]
#define RSCAN0RMID2LH RSCAN0.RMID2.UINT8[LH]
#define RSCAN0RMID2H RSCAN0.RMID2.UINT16[H]
#define RSCAN0RMID2HL RSCAN0.RMID2.UINT8[HL]
#define RSCAN0RMID2HH RSCAN0.RMID2.UINT8[HH]
#define RSCAN0RMPTR2 RSCAN0.RMPTR2.UINT32
#define RSCAN0RMPTR2L RSCAN0.RMPTR2.UINT16[L]
#define RSCAN0RMPTR2LL RSCAN0.RMPTR2.UINT8[LL]
#define RSCAN0RMPTR2LH RSCAN0.RMPTR2.UINT8[LH]
#define RSCAN0RMPTR2H RSCAN0.RMPTR2.UINT16[H]
#define RSCAN0RMPTR2HL RSCAN0.RMPTR2.UINT8[HL]
#define RSCAN0RMPTR2HH RSCAN0.RMPTR2.UINT8[HH]
#define RSCAN0RMDF02 RSCAN0.RMDF02.UINT32
#define RSCAN0RMDF02L RSCAN0.RMDF02.UINT16[L]
#define RSCAN0RMDF02LL RSCAN0.RMDF02.UINT8[LL]
#define RSCAN0RMDF02LH RSCAN0.RMDF02.UINT8[LH]
#define RSCAN0RMDF02H RSCAN0.RMDF02.UINT16[H]
#define RSCAN0RMDF02HL RSCAN0.RMDF02.UINT8[HL]
#define RSCAN0RMDF02HH RSCAN0.RMDF02.UINT8[HH]
#define RSCAN0RMDF12 RSCAN0.RMDF12.UINT32
#define RSCAN0RMDF12L RSCAN0.RMDF12.UINT16[L]
#define RSCAN0RMDF12LL RSCAN0.RMDF12.UINT8[LL]
#define RSCAN0RMDF12LH RSCAN0.RMDF12.UINT8[LH]
#define RSCAN0RMDF12H RSCAN0.RMDF12.UINT16[H]
#define RSCAN0RMDF12HL RSCAN0.RMDF12.UINT8[HL]
#define RSCAN0RMDF12HH RSCAN0.RMDF12.UINT8[HH]
#define RSCAN0RMID3 RSCAN0.RMID3.UINT32
#define RSCAN0RMID3L RSCAN0.RMID3.UINT16[L]
#define RSCAN0RMID3LL RSCAN0.RMID3.UINT8[LL]
#define RSCAN0RMID3LH RSCAN0.RMID3.UINT8[LH]
#define RSCAN0RMID3H RSCAN0.RMID3.UINT16[H]
#define RSCAN0RMID3HL RSCAN0.RMID3.UINT8[HL]
#define RSCAN0RMID3HH RSCAN0.RMID3.UINT8[HH]
#define RSCAN0RMPTR3 RSCAN0.RMPTR3.UINT32
#define RSCAN0RMPTR3L RSCAN0.RMPTR3.UINT16[L]
#define RSCAN0RMPTR3LL RSCAN0.RMPTR3.UINT8[LL]
#define RSCAN0RMPTR3LH RSCAN0.RMPTR3.UINT8[LH]
#define RSCAN0RMPTR3H RSCAN0.RMPTR3.UINT16[H]
#define RSCAN0RMPTR3HL RSCAN0.RMPTR3.UINT8[HL]
#define RSCAN0RMPTR3HH RSCAN0.RMPTR3.UINT8[HH]
#define RSCAN0RMDF03 RSCAN0.RMDF03.UINT32
#define RSCAN0RMDF03L RSCAN0.RMDF03.UINT16[L]
#define RSCAN0RMDF03LL RSCAN0.RMDF03.UINT8[LL]
#define RSCAN0RMDF03LH RSCAN0.RMDF03.UINT8[LH]
#define RSCAN0RMDF03H RSCAN0.RMDF03.UINT16[H]
#define RSCAN0RMDF03HL RSCAN0.RMDF03.UINT8[HL]
#define RSCAN0RMDF03HH RSCAN0.RMDF03.UINT8[HH]
#define RSCAN0RMDF13 RSCAN0.RMDF13.UINT32
#define RSCAN0RMDF13L RSCAN0.RMDF13.UINT16[L]
#define RSCAN0RMDF13LL RSCAN0.RMDF13.UINT8[LL]
#define RSCAN0RMDF13LH RSCAN0.RMDF13.UINT8[LH]
#define RSCAN0RMDF13H RSCAN0.RMDF13.UINT16[H]
#define RSCAN0RMDF13HL RSCAN0.RMDF13.UINT8[HL]
#define RSCAN0RMDF13HH RSCAN0.RMDF13.UINT8[HH]
#define RSCAN0RMID4 RSCAN0.RMID4.UINT32
#define RSCAN0RMID4L RSCAN0.RMID4.UINT16[L]
#define RSCAN0RMID4LL RSCAN0.RMID4.UINT8[LL]
#define RSCAN0RMID4LH RSCAN0.RMID4.UINT8[LH]
#define RSCAN0RMID4H RSCAN0.RMID4.UINT16[H]
#define RSCAN0RMID4HL RSCAN0.RMID4.UINT8[HL]
#define RSCAN0RMID4HH RSCAN0.RMID4.UINT8[HH]
#define RSCAN0RMPTR4 RSCAN0.RMPTR4.UINT32
#define RSCAN0RMPTR4L RSCAN0.RMPTR4.UINT16[L]
#define RSCAN0RMPTR4LL RSCAN0.RMPTR4.UINT8[LL]
#define RSCAN0RMPTR4LH RSCAN0.RMPTR4.UINT8[LH]
#define RSCAN0RMPTR4H RSCAN0.RMPTR4.UINT16[H]
#define RSCAN0RMPTR4HL RSCAN0.RMPTR4.UINT8[HL]
#define RSCAN0RMPTR4HH RSCAN0.RMPTR4.UINT8[HH]
#define RSCAN0RMDF04 RSCAN0.RMDF04.UINT32
#define RSCAN0RMDF04L RSCAN0.RMDF04.UINT16[L]
#define RSCAN0RMDF04LL RSCAN0.RMDF04.UINT8[LL]
#define RSCAN0RMDF04LH RSCAN0.RMDF04.UINT8[LH]
#define RSCAN0RMDF04H RSCAN0.RMDF04.UINT16[H]
#define RSCAN0RMDF04HL RSCAN0.RMDF04.UINT8[HL]
#define RSCAN0RMDF04HH RSCAN0.RMDF04.UINT8[HH]
#define RSCAN0RMDF14 RSCAN0.RMDF14.UINT32
#define RSCAN0RMDF14L RSCAN0.RMDF14.UINT16[L]
#define RSCAN0RMDF14LL RSCAN0.RMDF14.UINT8[LL]
#define RSCAN0RMDF14LH RSCAN0.RMDF14.UINT8[LH]
#define RSCAN0RMDF14H RSCAN0.RMDF14.UINT16[H]
#define RSCAN0RMDF14HL RSCAN0.RMDF14.UINT8[HL]
#define RSCAN0RMDF14HH RSCAN0.RMDF14.UINT8[HH]
#define RSCAN0RMID5 RSCAN0.RMID5.UINT32
#define RSCAN0RMID5L RSCAN0.RMID5.UINT16[L]
#define RSCAN0RMID5LL RSCAN0.RMID5.UINT8[LL]
#define RSCAN0RMID5LH RSCAN0.RMID5.UINT8[LH]
#define RSCAN0RMID5H RSCAN0.RMID5.UINT16[H]
#define RSCAN0RMID5HL RSCAN0.RMID5.UINT8[HL]
#define RSCAN0RMID5HH RSCAN0.RMID5.UINT8[HH]
#define RSCAN0RMPTR5 RSCAN0.RMPTR5.UINT32
#define RSCAN0RMPTR5L RSCAN0.RMPTR5.UINT16[L]
#define RSCAN0RMPTR5LL RSCAN0.RMPTR5.UINT8[LL]
#define RSCAN0RMPTR5LH RSCAN0.RMPTR5.UINT8[LH]
#define RSCAN0RMPTR5H RSCAN0.RMPTR5.UINT16[H]
#define RSCAN0RMPTR5HL RSCAN0.RMPTR5.UINT8[HL]
#define RSCAN0RMPTR5HH RSCAN0.RMPTR5.UINT8[HH]
#define RSCAN0RMDF05 RSCAN0.RMDF05.UINT32
#define RSCAN0RMDF05L RSCAN0.RMDF05.UINT16[L]
#define RSCAN0RMDF05LL RSCAN0.RMDF05.UINT8[LL]
#define RSCAN0RMDF05LH RSCAN0.RMDF05.UINT8[LH]
#define RSCAN0RMDF05H RSCAN0.RMDF05.UINT16[H]
#define RSCAN0RMDF05HL RSCAN0.RMDF05.UINT8[HL]
#define RSCAN0RMDF05HH RSCAN0.RMDF05.UINT8[HH]
#define RSCAN0RMDF15 RSCAN0.RMDF15.UINT32
#define RSCAN0RMDF15L RSCAN0.RMDF15.UINT16[L]
#define RSCAN0RMDF15LL RSCAN0.RMDF15.UINT8[LL]
#define RSCAN0RMDF15LH RSCAN0.RMDF15.UINT8[LH]
#define RSCAN0RMDF15H RSCAN0.RMDF15.UINT16[H]
#define RSCAN0RMDF15HL RSCAN0.RMDF15.UINT8[HL]
#define RSCAN0RMDF15HH RSCAN0.RMDF15.UINT8[HH]
#define RSCAN0RMID6 RSCAN0.RMID6.UINT32
#define RSCAN0RMID6L RSCAN0.RMID6.UINT16[L]
#define RSCAN0RMID6LL RSCAN0.RMID6.UINT8[LL]
#define RSCAN0RMID6LH RSCAN0.RMID6.UINT8[LH]
#define RSCAN0RMID6H RSCAN0.RMID6.UINT16[H]
#define RSCAN0RMID6HL RSCAN0.RMID6.UINT8[HL]
#define RSCAN0RMID6HH RSCAN0.RMID6.UINT8[HH]
#define RSCAN0RMPTR6 RSCAN0.RMPTR6.UINT32
#define RSCAN0RMPTR6L RSCAN0.RMPTR6.UINT16[L]
#define RSCAN0RMPTR6LL RSCAN0.RMPTR6.UINT8[LL]
#define RSCAN0RMPTR6LH RSCAN0.RMPTR6.UINT8[LH]
#define RSCAN0RMPTR6H RSCAN0.RMPTR6.UINT16[H]
#define RSCAN0RMPTR6HL RSCAN0.RMPTR6.UINT8[HL]
#define RSCAN0RMPTR6HH RSCAN0.RMPTR6.UINT8[HH]
#define RSCAN0RMDF06 RSCAN0.RMDF06.UINT32
#define RSCAN0RMDF06L RSCAN0.RMDF06.UINT16[L]
#define RSCAN0RMDF06LL RSCAN0.RMDF06.UINT8[LL]
#define RSCAN0RMDF06LH RSCAN0.RMDF06.UINT8[LH]
#define RSCAN0RMDF06H RSCAN0.RMDF06.UINT16[H]
#define RSCAN0RMDF06HL RSCAN0.RMDF06.UINT8[HL]
#define RSCAN0RMDF06HH RSCAN0.RMDF06.UINT8[HH]
#define RSCAN0RMDF16 RSCAN0.RMDF16.UINT32
#define RSCAN0RMDF16L RSCAN0.RMDF16.UINT16[L]
#define RSCAN0RMDF16LL RSCAN0.RMDF16.UINT8[LL]
#define RSCAN0RMDF16LH RSCAN0.RMDF16.UINT8[LH]
#define RSCAN0RMDF16H RSCAN0.RMDF16.UINT16[H]
#define RSCAN0RMDF16HL RSCAN0.RMDF16.UINT8[HL]
#define RSCAN0RMDF16HH RSCAN0.RMDF16.UINT8[HH]
#define RSCAN0RMID7 RSCAN0.RMID7.UINT32
#define RSCAN0RMID7L RSCAN0.RMID7.UINT16[L]
#define RSCAN0RMID7LL RSCAN0.RMID7.UINT8[LL]
#define RSCAN0RMID7LH RSCAN0.RMID7.UINT8[LH]
#define RSCAN0RMID7H RSCAN0.RMID7.UINT16[H]
#define RSCAN0RMID7HL RSCAN0.RMID7.UINT8[HL]
#define RSCAN0RMID7HH RSCAN0.RMID7.UINT8[HH]
#define RSCAN0RMPTR7 RSCAN0.RMPTR7.UINT32
#define RSCAN0RMPTR7L RSCAN0.RMPTR7.UINT16[L]
#define RSCAN0RMPTR7LL RSCAN0.RMPTR7.UINT8[LL]
#define RSCAN0RMPTR7LH RSCAN0.RMPTR7.UINT8[LH]
#define RSCAN0RMPTR7H RSCAN0.RMPTR7.UINT16[H]
#define RSCAN0RMPTR7HL RSCAN0.RMPTR7.UINT8[HL]
#define RSCAN0RMPTR7HH RSCAN0.RMPTR7.UINT8[HH]
#define RSCAN0RMDF07 RSCAN0.RMDF07.UINT32
#define RSCAN0RMDF07L RSCAN0.RMDF07.UINT16[L]
#define RSCAN0RMDF07LL RSCAN0.RMDF07.UINT8[LL]
#define RSCAN0RMDF07LH RSCAN0.RMDF07.UINT8[LH]
#define RSCAN0RMDF07H RSCAN0.RMDF07.UINT16[H]
#define RSCAN0RMDF07HL RSCAN0.RMDF07.UINT8[HL]
#define RSCAN0RMDF07HH RSCAN0.RMDF07.UINT8[HH]
#define RSCAN0RMDF17 RSCAN0.RMDF17.UINT32
#define RSCAN0RMDF17L RSCAN0.RMDF17.UINT16[L]
#define RSCAN0RMDF17LL RSCAN0.RMDF17.UINT8[LL]
#define RSCAN0RMDF17LH RSCAN0.RMDF17.UINT8[LH]
#define RSCAN0RMDF17H RSCAN0.RMDF17.UINT16[H]
#define RSCAN0RMDF17HL RSCAN0.RMDF17.UINT8[HL]
#define RSCAN0RMDF17HH RSCAN0.RMDF17.UINT8[HH]
#define RSCAN0RMID8 RSCAN0.RMID8.UINT32
#define RSCAN0RMID8L RSCAN0.RMID8.UINT16[L]
#define RSCAN0RMID8LL RSCAN0.RMID8.UINT8[LL]
#define RSCAN0RMID8LH RSCAN0.RMID8.UINT8[LH]
#define RSCAN0RMID8H RSCAN0.RMID8.UINT16[H]
#define RSCAN0RMID8HL RSCAN0.RMID8.UINT8[HL]
#define RSCAN0RMID8HH RSCAN0.RMID8.UINT8[HH]
#define RSCAN0RMPTR8 RSCAN0.RMPTR8.UINT32
#define RSCAN0RMPTR8L RSCAN0.RMPTR8.UINT16[L]
#define RSCAN0RMPTR8LL RSCAN0.RMPTR8.UINT8[LL]
#define RSCAN0RMPTR8LH RSCAN0.RMPTR8.UINT8[LH]
#define RSCAN0RMPTR8H RSCAN0.RMPTR8.UINT16[H]
#define RSCAN0RMPTR8HL RSCAN0.RMPTR8.UINT8[HL]
#define RSCAN0RMPTR8HH RSCAN0.RMPTR8.UINT8[HH]
#define RSCAN0RMDF08 RSCAN0.RMDF08.UINT32
#define RSCAN0RMDF08L RSCAN0.RMDF08.UINT16[L]
#define RSCAN0RMDF08LL RSCAN0.RMDF08.UINT8[LL]
#define RSCAN0RMDF08LH RSCAN0.RMDF08.UINT8[LH]
#define RSCAN0RMDF08H RSCAN0.RMDF08.UINT16[H]
#define RSCAN0RMDF08HL RSCAN0.RMDF08.UINT8[HL]
#define RSCAN0RMDF08HH RSCAN0.RMDF08.UINT8[HH]
#define RSCAN0RMDF18 RSCAN0.RMDF18.UINT32
#define RSCAN0RMDF18L RSCAN0.RMDF18.UINT16[L]
#define RSCAN0RMDF18LL RSCAN0.RMDF18.UINT8[LL]
#define RSCAN0RMDF18LH RSCAN0.RMDF18.UINT8[LH]
#define RSCAN0RMDF18H RSCAN0.RMDF18.UINT16[H]
#define RSCAN0RMDF18HL RSCAN0.RMDF18.UINT8[HL]
#define RSCAN0RMDF18HH RSCAN0.RMDF18.UINT8[HH]
#define RSCAN0RMID9 RSCAN0.RMID9.UINT32
#define RSCAN0RMID9L RSCAN0.RMID9.UINT16[L]
#define RSCAN0RMID9LL RSCAN0.RMID9.UINT8[LL]
#define RSCAN0RMID9LH RSCAN0.RMID9.UINT8[LH]
#define RSCAN0RMID9H RSCAN0.RMID9.UINT16[H]
#define RSCAN0RMID9HL RSCAN0.RMID9.UINT8[HL]
#define RSCAN0RMID9HH RSCAN0.RMID9.UINT8[HH]
#define RSCAN0RMPTR9 RSCAN0.RMPTR9.UINT32
#define RSCAN0RMPTR9L RSCAN0.RMPTR9.UINT16[L]
#define RSCAN0RMPTR9LL RSCAN0.RMPTR9.UINT8[LL]
#define RSCAN0RMPTR9LH RSCAN0.RMPTR9.UINT8[LH]
#define RSCAN0RMPTR9H RSCAN0.RMPTR9.UINT16[H]
#define RSCAN0RMPTR9HL RSCAN0.RMPTR9.UINT8[HL]
#define RSCAN0RMPTR9HH RSCAN0.RMPTR9.UINT8[HH]
#define RSCAN0RMDF09 RSCAN0.RMDF09.UINT32
#define RSCAN0RMDF09L RSCAN0.RMDF09.UINT16[L]
#define RSCAN0RMDF09LL RSCAN0.RMDF09.UINT8[LL]
#define RSCAN0RMDF09LH RSCAN0.RMDF09.UINT8[LH]
#define RSCAN0RMDF09H RSCAN0.RMDF09.UINT16[H]
#define RSCAN0RMDF09HL RSCAN0.RMDF09.UINT8[HL]
#define RSCAN0RMDF09HH RSCAN0.RMDF09.UINT8[HH]
#define RSCAN0RMDF19 RSCAN0.RMDF19.UINT32
#define RSCAN0RMDF19L RSCAN0.RMDF19.UINT16[L]
#define RSCAN0RMDF19LL RSCAN0.RMDF19.UINT8[LL]
#define RSCAN0RMDF19LH RSCAN0.RMDF19.UINT8[LH]
#define RSCAN0RMDF19H RSCAN0.RMDF19.UINT16[H]
#define RSCAN0RMDF19HL RSCAN0.RMDF19.UINT8[HL]
#define RSCAN0RMDF19HH RSCAN0.RMDF19.UINT8[HH]
#define RSCAN0RMID10 RSCAN0.RMID10.UINT32
#define RSCAN0RMID10L RSCAN0.RMID10.UINT16[L]
#define RSCAN0RMID10LL RSCAN0.RMID10.UINT8[LL]
#define RSCAN0RMID10LH RSCAN0.RMID10.UINT8[LH]
#define RSCAN0RMID10H RSCAN0.RMID10.UINT16[H]
#define RSCAN0RMID10HL RSCAN0.RMID10.UINT8[HL]
#define RSCAN0RMID10HH RSCAN0.RMID10.UINT8[HH]
#define RSCAN0RMPTR10 RSCAN0.RMPTR10.UINT32
#define RSCAN0RMPTR10L RSCAN0.RMPTR10.UINT16[L]
#define RSCAN0RMPTR10LL RSCAN0.RMPTR10.UINT8[LL]
#define RSCAN0RMPTR10LH RSCAN0.RMPTR10.UINT8[LH]
#define RSCAN0RMPTR10H RSCAN0.RMPTR10.UINT16[H]
#define RSCAN0RMPTR10HL RSCAN0.RMPTR10.UINT8[HL]
#define RSCAN0RMPTR10HH RSCAN0.RMPTR10.UINT8[HH]
#define RSCAN0RMDF010 RSCAN0.RMDF010.UINT32
#define RSCAN0RMDF010L RSCAN0.RMDF010.UINT16[L]
#define RSCAN0RMDF010LL RSCAN0.RMDF010.UINT8[LL]
#define RSCAN0RMDF010LH RSCAN0.RMDF010.UINT8[LH]
#define RSCAN0RMDF010H RSCAN0.RMDF010.UINT16[H]
#define RSCAN0RMDF010HL RSCAN0.RMDF010.UINT8[HL]
#define RSCAN0RMDF010HH RSCAN0.RMDF010.UINT8[HH]
#define RSCAN0RMDF110 RSCAN0.RMDF110.UINT32
#define RSCAN0RMDF110L RSCAN0.RMDF110.UINT16[L]
#define RSCAN0RMDF110LL RSCAN0.RMDF110.UINT8[LL]
#define RSCAN0RMDF110LH RSCAN0.RMDF110.UINT8[LH]
#define RSCAN0RMDF110H RSCAN0.RMDF110.UINT16[H]
#define RSCAN0RMDF110HL RSCAN0.RMDF110.UINT8[HL]
#define RSCAN0RMDF110HH RSCAN0.RMDF110.UINT8[HH]
#define RSCAN0RMID11 RSCAN0.RMID11.UINT32
#define RSCAN0RMID11L RSCAN0.RMID11.UINT16[L]
#define RSCAN0RMID11LL RSCAN0.RMID11.UINT8[LL]
#define RSCAN0RMID11LH RSCAN0.RMID11.UINT8[LH]
#define RSCAN0RMID11H RSCAN0.RMID11.UINT16[H]
#define RSCAN0RMID11HL RSCAN0.RMID11.UINT8[HL]
#define RSCAN0RMID11HH RSCAN0.RMID11.UINT8[HH]
#define RSCAN0RMPTR11 RSCAN0.RMPTR11.UINT32
#define RSCAN0RMPTR11L RSCAN0.RMPTR11.UINT16[L]
#define RSCAN0RMPTR11LL RSCAN0.RMPTR11.UINT8[LL]
#define RSCAN0RMPTR11LH RSCAN0.RMPTR11.UINT8[LH]
#define RSCAN0RMPTR11H RSCAN0.RMPTR11.UINT16[H]
#define RSCAN0RMPTR11HL RSCAN0.RMPTR11.UINT8[HL]
#define RSCAN0RMPTR11HH RSCAN0.RMPTR11.UINT8[HH]
#define RSCAN0RMDF011 RSCAN0.RMDF011.UINT32
#define RSCAN0RMDF011L RSCAN0.RMDF011.UINT16[L]
#define RSCAN0RMDF011LL RSCAN0.RMDF011.UINT8[LL]
#define RSCAN0RMDF011LH RSCAN0.RMDF011.UINT8[LH]
#define RSCAN0RMDF011H RSCAN0.RMDF011.UINT16[H]
#define RSCAN0RMDF011HL RSCAN0.RMDF011.UINT8[HL]
#define RSCAN0RMDF011HH RSCAN0.RMDF011.UINT8[HH]
#define RSCAN0RMDF111 RSCAN0.RMDF111.UINT32
#define RSCAN0RMDF111L RSCAN0.RMDF111.UINT16[L]
#define RSCAN0RMDF111LL RSCAN0.RMDF111.UINT8[LL]
#define RSCAN0RMDF111LH RSCAN0.RMDF111.UINT8[LH]
#define RSCAN0RMDF111H RSCAN0.RMDF111.UINT16[H]
#define RSCAN0RMDF111HL RSCAN0.RMDF111.UINT8[HL]
#define RSCAN0RMDF111HH RSCAN0.RMDF111.UINT8[HH]
#define RSCAN0RMID12 RSCAN0.RMID12.UINT32
#define RSCAN0RMID12L RSCAN0.RMID12.UINT16[L]
#define RSCAN0RMID12LL RSCAN0.RMID12.UINT8[LL]
#define RSCAN0RMID12LH RSCAN0.RMID12.UINT8[LH]
#define RSCAN0RMID12H RSCAN0.RMID12.UINT16[H]
#define RSCAN0RMID12HL RSCAN0.RMID12.UINT8[HL]
#define RSCAN0RMID12HH RSCAN0.RMID12.UINT8[HH]
#define RSCAN0RMPTR12 RSCAN0.RMPTR12.UINT32
#define RSCAN0RMPTR12L RSCAN0.RMPTR12.UINT16[L]
#define RSCAN0RMPTR12LL RSCAN0.RMPTR12.UINT8[LL]
#define RSCAN0RMPTR12LH RSCAN0.RMPTR12.UINT8[LH]
#define RSCAN0RMPTR12H RSCAN0.RMPTR12.UINT16[H]
#define RSCAN0RMPTR12HL RSCAN0.RMPTR12.UINT8[HL]
#define RSCAN0RMPTR12HH RSCAN0.RMPTR12.UINT8[HH]
#define RSCAN0RMDF012 RSCAN0.RMDF012.UINT32
#define RSCAN0RMDF012L RSCAN0.RMDF012.UINT16[L]
#define RSCAN0RMDF012LL RSCAN0.RMDF012.UINT8[LL]
#define RSCAN0RMDF012LH RSCAN0.RMDF012.UINT8[LH]
#define RSCAN0RMDF012H RSCAN0.RMDF012.UINT16[H]
#define RSCAN0RMDF012HL RSCAN0.RMDF012.UINT8[HL]
#define RSCAN0RMDF012HH RSCAN0.RMDF012.UINT8[HH]
#define RSCAN0RMDF112 RSCAN0.RMDF112.UINT32
#define RSCAN0RMDF112L RSCAN0.RMDF112.UINT16[L]
#define RSCAN0RMDF112LL RSCAN0.RMDF112.UINT8[LL]
#define RSCAN0RMDF112LH RSCAN0.RMDF112.UINT8[LH]
#define RSCAN0RMDF112H RSCAN0.RMDF112.UINT16[H]
#define RSCAN0RMDF112HL RSCAN0.RMDF112.UINT8[HL]
#define RSCAN0RMDF112HH RSCAN0.RMDF112.UINT8[HH]
#define RSCAN0RMID13 RSCAN0.RMID13.UINT32
#define RSCAN0RMID13L RSCAN0.RMID13.UINT16[L]
#define RSCAN0RMID13LL RSCAN0.RMID13.UINT8[LL]
#define RSCAN0RMID13LH RSCAN0.RMID13.UINT8[LH]
#define RSCAN0RMID13H RSCAN0.RMID13.UINT16[H]
#define RSCAN0RMID13HL RSCAN0.RMID13.UINT8[HL]
#define RSCAN0RMID13HH RSCAN0.RMID13.UINT8[HH]
#define RSCAN0RMPTR13 RSCAN0.RMPTR13.UINT32
#define RSCAN0RMPTR13L RSCAN0.RMPTR13.UINT16[L]
#define RSCAN0RMPTR13LL RSCAN0.RMPTR13.UINT8[LL]
#define RSCAN0RMPTR13LH RSCAN0.RMPTR13.UINT8[LH]
#define RSCAN0RMPTR13H RSCAN0.RMPTR13.UINT16[H]
#define RSCAN0RMPTR13HL RSCAN0.RMPTR13.UINT8[HL]
#define RSCAN0RMPTR13HH RSCAN0.RMPTR13.UINT8[HH]
#define RSCAN0RMDF013 RSCAN0.RMDF013.UINT32
#define RSCAN0RMDF013L RSCAN0.RMDF013.UINT16[L]
#define RSCAN0RMDF013LL RSCAN0.RMDF013.UINT8[LL]
#define RSCAN0RMDF013LH RSCAN0.RMDF013.UINT8[LH]
#define RSCAN0RMDF013H RSCAN0.RMDF013.UINT16[H]
#define RSCAN0RMDF013HL RSCAN0.RMDF013.UINT8[HL]
#define RSCAN0RMDF013HH RSCAN0.RMDF013.UINT8[HH]
#define RSCAN0RMDF113 RSCAN0.RMDF113.UINT32
#define RSCAN0RMDF113L RSCAN0.RMDF113.UINT16[L]
#define RSCAN0RMDF113LL RSCAN0.RMDF113.UINT8[LL]
#define RSCAN0RMDF113LH RSCAN0.RMDF113.UINT8[LH]
#define RSCAN0RMDF113H RSCAN0.RMDF113.UINT16[H]
#define RSCAN0RMDF113HL RSCAN0.RMDF113.UINT8[HL]
#define RSCAN0RMDF113HH RSCAN0.RMDF113.UINT8[HH]
#define RSCAN0RMID14 RSCAN0.RMID14.UINT32
#define RSCAN0RMID14L RSCAN0.RMID14.UINT16[L]
#define RSCAN0RMID14LL RSCAN0.RMID14.UINT8[LL]
#define RSCAN0RMID14LH RSCAN0.RMID14.UINT8[LH]
#define RSCAN0RMID14H RSCAN0.RMID14.UINT16[H]
#define RSCAN0RMID14HL RSCAN0.RMID14.UINT8[HL]
#define RSCAN0RMID14HH RSCAN0.RMID14.UINT8[HH]
#define RSCAN0RMPTR14 RSCAN0.RMPTR14.UINT32
#define RSCAN0RMPTR14L RSCAN0.RMPTR14.UINT16[L]
#define RSCAN0RMPTR14LL RSCAN0.RMPTR14.UINT8[LL]
#define RSCAN0RMPTR14LH RSCAN0.RMPTR14.UINT8[LH]
#define RSCAN0RMPTR14H RSCAN0.RMPTR14.UINT16[H]
#define RSCAN0RMPTR14HL RSCAN0.RMPTR14.UINT8[HL]
#define RSCAN0RMPTR14HH RSCAN0.RMPTR14.UINT8[HH]
#define RSCAN0RMDF014 RSCAN0.RMDF014.UINT32
#define RSCAN0RMDF014L RSCAN0.RMDF014.UINT16[L]
#define RSCAN0RMDF014LL RSCAN0.RMDF014.UINT8[LL]
#define RSCAN0RMDF014LH RSCAN0.RMDF014.UINT8[LH]
#define RSCAN0RMDF014H RSCAN0.RMDF014.UINT16[H]
#define RSCAN0RMDF014HL RSCAN0.RMDF014.UINT8[HL]
#define RSCAN0RMDF014HH RSCAN0.RMDF014.UINT8[HH]
#define RSCAN0RMDF114 RSCAN0.RMDF114.UINT32
#define RSCAN0RMDF114L RSCAN0.RMDF114.UINT16[L]
#define RSCAN0RMDF114LL RSCAN0.RMDF114.UINT8[LL]
#define RSCAN0RMDF114LH RSCAN0.RMDF114.UINT8[LH]
#define RSCAN0RMDF114H RSCAN0.RMDF114.UINT16[H]
#define RSCAN0RMDF114HL RSCAN0.RMDF114.UINT8[HL]
#define RSCAN0RMDF114HH RSCAN0.RMDF114.UINT8[HH]
#define RSCAN0RMID15 RSCAN0.RMID15.UINT32
#define RSCAN0RMID15L RSCAN0.RMID15.UINT16[L]
#define RSCAN0RMID15LL RSCAN0.RMID15.UINT8[LL]
#define RSCAN0RMID15LH RSCAN0.RMID15.UINT8[LH]
#define RSCAN0RMID15H RSCAN0.RMID15.UINT16[H]
#define RSCAN0RMID15HL RSCAN0.RMID15.UINT8[HL]
#define RSCAN0RMID15HH RSCAN0.RMID15.UINT8[HH]
#define RSCAN0RMPTR15 RSCAN0.RMPTR15.UINT32
#define RSCAN0RMPTR15L RSCAN0.RMPTR15.UINT16[L]
#define RSCAN0RMPTR15LL RSCAN0.RMPTR15.UINT8[LL]
#define RSCAN0RMPTR15LH RSCAN0.RMPTR15.UINT8[LH]
#define RSCAN0RMPTR15H RSCAN0.RMPTR15.UINT16[H]
#define RSCAN0RMPTR15HL RSCAN0.RMPTR15.UINT8[HL]
#define RSCAN0RMPTR15HH RSCAN0.RMPTR15.UINT8[HH]
#define RSCAN0RMDF015 RSCAN0.RMDF015.UINT32
#define RSCAN0RMDF015L RSCAN0.RMDF015.UINT16[L]
#define RSCAN0RMDF015LL RSCAN0.RMDF015.UINT8[LL]
#define RSCAN0RMDF015LH RSCAN0.RMDF015.UINT8[LH]
#define RSCAN0RMDF015H RSCAN0.RMDF015.UINT16[H]
#define RSCAN0RMDF015HL RSCAN0.RMDF015.UINT8[HL]
#define RSCAN0RMDF015HH RSCAN0.RMDF015.UINT8[HH]
#define RSCAN0RMDF115 RSCAN0.RMDF115.UINT32
#define RSCAN0RMDF115L RSCAN0.RMDF115.UINT16[L]
#define RSCAN0RMDF115LL RSCAN0.RMDF115.UINT8[LL]
#define RSCAN0RMDF115LH RSCAN0.RMDF115.UINT8[LH]
#define RSCAN0RMDF115H RSCAN0.RMDF115.UINT16[H]
#define RSCAN0RMDF115HL RSCAN0.RMDF115.UINT8[HL]
#define RSCAN0RMDF115HH RSCAN0.RMDF115.UINT8[HH]
#define RSCAN0RMID16 RSCAN0.RMID16.UINT32
#define RSCAN0RMID16L RSCAN0.RMID16.UINT16[L]
#define RSCAN0RMID16LL RSCAN0.RMID16.UINT8[LL]
#define RSCAN0RMID16LH RSCAN0.RMID16.UINT8[LH]
#define RSCAN0RMID16H RSCAN0.RMID16.UINT16[H]
#define RSCAN0RMID16HL RSCAN0.RMID16.UINT8[HL]
#define RSCAN0RMID16HH RSCAN0.RMID16.UINT8[HH]
#define RSCAN0RMPTR16 RSCAN0.RMPTR16.UINT32
#define RSCAN0RMPTR16L RSCAN0.RMPTR16.UINT16[L]
#define RSCAN0RMPTR16LL RSCAN0.RMPTR16.UINT8[LL]
#define RSCAN0RMPTR16LH RSCAN0.RMPTR16.UINT8[LH]
#define RSCAN0RMPTR16H RSCAN0.RMPTR16.UINT16[H]
#define RSCAN0RMPTR16HL RSCAN0.RMPTR16.UINT8[HL]
#define RSCAN0RMPTR16HH RSCAN0.RMPTR16.UINT8[HH]
#define RSCAN0RMDF016 RSCAN0.RMDF016.UINT32
#define RSCAN0RMDF016L RSCAN0.RMDF016.UINT16[L]
#define RSCAN0RMDF016LL RSCAN0.RMDF016.UINT8[LL]
#define RSCAN0RMDF016LH RSCAN0.RMDF016.UINT8[LH]
#define RSCAN0RMDF016H RSCAN0.RMDF016.UINT16[H]
#define RSCAN0RMDF016HL RSCAN0.RMDF016.UINT8[HL]
#define RSCAN0RMDF016HH RSCAN0.RMDF016.UINT8[HH]
#define RSCAN0RMDF116 RSCAN0.RMDF116.UINT32
#define RSCAN0RMDF116L RSCAN0.RMDF116.UINT16[L]
#define RSCAN0RMDF116LL RSCAN0.RMDF116.UINT8[LL]
#define RSCAN0RMDF116LH RSCAN0.RMDF116.UINT8[LH]
#define RSCAN0RMDF116H RSCAN0.RMDF116.UINT16[H]
#define RSCAN0RMDF116HL RSCAN0.RMDF116.UINT8[HL]
#define RSCAN0RMDF116HH RSCAN0.RMDF116.UINT8[HH]
#define RSCAN0RMID17 RSCAN0.RMID17.UINT32
#define RSCAN0RMID17L RSCAN0.RMID17.UINT16[L]
#define RSCAN0RMID17LL RSCAN0.RMID17.UINT8[LL]
#define RSCAN0RMID17LH RSCAN0.RMID17.UINT8[LH]
#define RSCAN0RMID17H RSCAN0.RMID17.UINT16[H]
#define RSCAN0RMID17HL RSCAN0.RMID17.UINT8[HL]
#define RSCAN0RMID17HH RSCAN0.RMID17.UINT8[HH]
#define RSCAN0RMPTR17 RSCAN0.RMPTR17.UINT32
#define RSCAN0RMPTR17L RSCAN0.RMPTR17.UINT16[L]
#define RSCAN0RMPTR17LL RSCAN0.RMPTR17.UINT8[LL]
#define RSCAN0RMPTR17LH RSCAN0.RMPTR17.UINT8[LH]
#define RSCAN0RMPTR17H RSCAN0.RMPTR17.UINT16[H]
#define RSCAN0RMPTR17HL RSCAN0.RMPTR17.UINT8[HL]
#define RSCAN0RMPTR17HH RSCAN0.RMPTR17.UINT8[HH]
#define RSCAN0RMDF017 RSCAN0.RMDF017.UINT32
#define RSCAN0RMDF017L RSCAN0.RMDF017.UINT16[L]
#define RSCAN0RMDF017LL RSCAN0.RMDF017.UINT8[LL]
#define RSCAN0RMDF017LH RSCAN0.RMDF017.UINT8[LH]
#define RSCAN0RMDF017H RSCAN0.RMDF017.UINT16[H]
#define RSCAN0RMDF017HL RSCAN0.RMDF017.UINT8[HL]
#define RSCAN0RMDF017HH RSCAN0.RMDF017.UINT8[HH]
#define RSCAN0RMDF117 RSCAN0.RMDF117.UINT32
#define RSCAN0RMDF117L RSCAN0.RMDF117.UINT16[L]
#define RSCAN0RMDF117LL RSCAN0.RMDF117.UINT8[LL]
#define RSCAN0RMDF117LH RSCAN0.RMDF117.UINT8[LH]
#define RSCAN0RMDF117H RSCAN0.RMDF117.UINT16[H]
#define RSCAN0RMDF117HL RSCAN0.RMDF117.UINT8[HL]
#define RSCAN0RMDF117HH RSCAN0.RMDF117.UINT8[HH]
#define RSCAN0RMID18 RSCAN0.RMID18.UINT32
#define RSCAN0RMID18L RSCAN0.RMID18.UINT16[L]
#define RSCAN0RMID18LL RSCAN0.RMID18.UINT8[LL]
#define RSCAN0RMID18LH RSCAN0.RMID18.UINT8[LH]
#define RSCAN0RMID18H RSCAN0.RMID18.UINT16[H]
#define RSCAN0RMID18HL RSCAN0.RMID18.UINT8[HL]
#define RSCAN0RMID18HH RSCAN0.RMID18.UINT8[HH]
#define RSCAN0RMPTR18 RSCAN0.RMPTR18.UINT32
#define RSCAN0RMPTR18L RSCAN0.RMPTR18.UINT16[L]
#define RSCAN0RMPTR18LL RSCAN0.RMPTR18.UINT8[LL]
#define RSCAN0RMPTR18LH RSCAN0.RMPTR18.UINT8[LH]
#define RSCAN0RMPTR18H RSCAN0.RMPTR18.UINT16[H]
#define RSCAN0RMPTR18HL RSCAN0.RMPTR18.UINT8[HL]
#define RSCAN0RMPTR18HH RSCAN0.RMPTR18.UINT8[HH]
#define RSCAN0RMDF018 RSCAN0.RMDF018.UINT32
#define RSCAN0RMDF018L RSCAN0.RMDF018.UINT16[L]
#define RSCAN0RMDF018LL RSCAN0.RMDF018.UINT8[LL]
#define RSCAN0RMDF018LH RSCAN0.RMDF018.UINT8[LH]
#define RSCAN0RMDF018H RSCAN0.RMDF018.UINT16[H]
#define RSCAN0RMDF018HL RSCAN0.RMDF018.UINT8[HL]
#define RSCAN0RMDF018HH RSCAN0.RMDF018.UINT8[HH]
#define RSCAN0RMDF118 RSCAN0.RMDF118.UINT32
#define RSCAN0RMDF118L RSCAN0.RMDF118.UINT16[L]
#define RSCAN0RMDF118LL RSCAN0.RMDF118.UINT8[LL]
#define RSCAN0RMDF118LH RSCAN0.RMDF118.UINT8[LH]
#define RSCAN0RMDF118H RSCAN0.RMDF118.UINT16[H]
#define RSCAN0RMDF118HL RSCAN0.RMDF118.UINT8[HL]
#define RSCAN0RMDF118HH RSCAN0.RMDF118.UINT8[HH]
#define RSCAN0RMID19 RSCAN0.RMID19.UINT32
#define RSCAN0RMID19L RSCAN0.RMID19.UINT16[L]
#define RSCAN0RMID19LL RSCAN0.RMID19.UINT8[LL]
#define RSCAN0RMID19LH RSCAN0.RMID19.UINT8[LH]
#define RSCAN0RMID19H RSCAN0.RMID19.UINT16[H]
#define RSCAN0RMID19HL RSCAN0.RMID19.UINT8[HL]
#define RSCAN0RMID19HH RSCAN0.RMID19.UINT8[HH]
#define RSCAN0RMPTR19 RSCAN0.RMPTR19.UINT32
#define RSCAN0RMPTR19L RSCAN0.RMPTR19.UINT16[L]
#define RSCAN0RMPTR19LL RSCAN0.RMPTR19.UINT8[LL]
#define RSCAN0RMPTR19LH RSCAN0.RMPTR19.UINT8[LH]
#define RSCAN0RMPTR19H RSCAN0.RMPTR19.UINT16[H]
#define RSCAN0RMPTR19HL RSCAN0.RMPTR19.UINT8[HL]
#define RSCAN0RMPTR19HH RSCAN0.RMPTR19.UINT8[HH]
#define RSCAN0RMDF019 RSCAN0.RMDF019.UINT32
#define RSCAN0RMDF019L RSCAN0.RMDF019.UINT16[L]
#define RSCAN0RMDF019LL RSCAN0.RMDF019.UINT8[LL]
#define RSCAN0RMDF019LH RSCAN0.RMDF019.UINT8[LH]
#define RSCAN0RMDF019H RSCAN0.RMDF019.UINT16[H]
#define RSCAN0RMDF019HL RSCAN0.RMDF019.UINT8[HL]
#define RSCAN0RMDF019HH RSCAN0.RMDF019.UINT8[HH]
#define RSCAN0RMDF119 RSCAN0.RMDF119.UINT32
#define RSCAN0RMDF119L RSCAN0.RMDF119.UINT16[L]
#define RSCAN0RMDF119LL RSCAN0.RMDF119.UINT8[LL]
#define RSCAN0RMDF119LH RSCAN0.RMDF119.UINT8[LH]
#define RSCAN0RMDF119H RSCAN0.RMDF119.UINT16[H]
#define RSCAN0RMDF119HL RSCAN0.RMDF119.UINT8[HL]
#define RSCAN0RMDF119HH RSCAN0.RMDF119.UINT8[HH]
#define RSCAN0RMID20 RSCAN0.RMID20.UINT32
#define RSCAN0RMID20L RSCAN0.RMID20.UINT16[L]
#define RSCAN0RMID20LL RSCAN0.RMID20.UINT8[LL]
#define RSCAN0RMID20LH RSCAN0.RMID20.UINT8[LH]
#define RSCAN0RMID20H RSCAN0.RMID20.UINT16[H]
#define RSCAN0RMID20HL RSCAN0.RMID20.UINT8[HL]
#define RSCAN0RMID20HH RSCAN0.RMID20.UINT8[HH]
#define RSCAN0RMPTR20 RSCAN0.RMPTR20.UINT32
#define RSCAN0RMPTR20L RSCAN0.RMPTR20.UINT16[L]
#define RSCAN0RMPTR20LL RSCAN0.RMPTR20.UINT8[LL]
#define RSCAN0RMPTR20LH RSCAN0.RMPTR20.UINT8[LH]
#define RSCAN0RMPTR20H RSCAN0.RMPTR20.UINT16[H]
#define RSCAN0RMPTR20HL RSCAN0.RMPTR20.UINT8[HL]
#define RSCAN0RMPTR20HH RSCAN0.RMPTR20.UINT8[HH]
#define RSCAN0RMDF020 RSCAN0.RMDF020.UINT32
#define RSCAN0RMDF020L RSCAN0.RMDF020.UINT16[L]
#define RSCAN0RMDF020LL RSCAN0.RMDF020.UINT8[LL]
#define RSCAN0RMDF020LH RSCAN0.RMDF020.UINT8[LH]
#define RSCAN0RMDF020H RSCAN0.RMDF020.UINT16[H]
#define RSCAN0RMDF020HL RSCAN0.RMDF020.UINT8[HL]
#define RSCAN0RMDF020HH RSCAN0.RMDF020.UINT8[HH]
#define RSCAN0RMDF120 RSCAN0.RMDF120.UINT32
#define RSCAN0RMDF120L RSCAN0.RMDF120.UINT16[L]
#define RSCAN0RMDF120LL RSCAN0.RMDF120.UINT8[LL]
#define RSCAN0RMDF120LH RSCAN0.RMDF120.UINT8[LH]
#define RSCAN0RMDF120H RSCAN0.RMDF120.UINT16[H]
#define RSCAN0RMDF120HL RSCAN0.RMDF120.UINT8[HL]
#define RSCAN0RMDF120HH RSCAN0.RMDF120.UINT8[HH]
#define RSCAN0RMID21 RSCAN0.RMID21.UINT32
#define RSCAN0RMID21L RSCAN0.RMID21.UINT16[L]
#define RSCAN0RMID21LL RSCAN0.RMID21.UINT8[LL]
#define RSCAN0RMID21LH RSCAN0.RMID21.UINT8[LH]
#define RSCAN0RMID21H RSCAN0.RMID21.UINT16[H]
#define RSCAN0RMID21HL RSCAN0.RMID21.UINT8[HL]
#define RSCAN0RMID21HH RSCAN0.RMID21.UINT8[HH]
#define RSCAN0RMPTR21 RSCAN0.RMPTR21.UINT32
#define RSCAN0RMPTR21L RSCAN0.RMPTR21.UINT16[L]
#define RSCAN0RMPTR21LL RSCAN0.RMPTR21.UINT8[LL]
#define RSCAN0RMPTR21LH RSCAN0.RMPTR21.UINT8[LH]
#define RSCAN0RMPTR21H RSCAN0.RMPTR21.UINT16[H]
#define RSCAN0RMPTR21HL RSCAN0.RMPTR21.UINT8[HL]
#define RSCAN0RMPTR21HH RSCAN0.RMPTR21.UINT8[HH]
#define RSCAN0RMDF021 RSCAN0.RMDF021.UINT32
#define RSCAN0RMDF021L RSCAN0.RMDF021.UINT16[L]
#define RSCAN0RMDF021LL RSCAN0.RMDF021.UINT8[LL]
#define RSCAN0RMDF021LH RSCAN0.RMDF021.UINT8[LH]
#define RSCAN0RMDF021H RSCAN0.RMDF021.UINT16[H]
#define RSCAN0RMDF021HL RSCAN0.RMDF021.UINT8[HL]
#define RSCAN0RMDF021HH RSCAN0.RMDF021.UINT8[HH]
#define RSCAN0RMDF121 RSCAN0.RMDF121.UINT32
#define RSCAN0RMDF121L RSCAN0.RMDF121.UINT16[L]
#define RSCAN0RMDF121LL RSCAN0.RMDF121.UINT8[LL]
#define RSCAN0RMDF121LH RSCAN0.RMDF121.UINT8[LH]
#define RSCAN0RMDF121H RSCAN0.RMDF121.UINT16[H]
#define RSCAN0RMDF121HL RSCAN0.RMDF121.UINT8[HL]
#define RSCAN0RMDF121HH RSCAN0.RMDF121.UINT8[HH]
#define RSCAN0RMID22 RSCAN0.RMID22.UINT32
#define RSCAN0RMID22L RSCAN0.RMID22.UINT16[L]
#define RSCAN0RMID22LL RSCAN0.RMID22.UINT8[LL]
#define RSCAN0RMID22LH RSCAN0.RMID22.UINT8[LH]
#define RSCAN0RMID22H RSCAN0.RMID22.UINT16[H]
#define RSCAN0RMID22HL RSCAN0.RMID22.UINT8[HL]
#define RSCAN0RMID22HH RSCAN0.RMID22.UINT8[HH]
#define RSCAN0RMPTR22 RSCAN0.RMPTR22.UINT32
#define RSCAN0RMPTR22L RSCAN0.RMPTR22.UINT16[L]
#define RSCAN0RMPTR22LL RSCAN0.RMPTR22.UINT8[LL]
#define RSCAN0RMPTR22LH RSCAN0.RMPTR22.UINT8[LH]
#define RSCAN0RMPTR22H RSCAN0.RMPTR22.UINT16[H]
#define RSCAN0RMPTR22HL RSCAN0.RMPTR22.UINT8[HL]
#define RSCAN0RMPTR22HH RSCAN0.RMPTR22.UINT8[HH]
#define RSCAN0RMDF022 RSCAN0.RMDF022.UINT32
#define RSCAN0RMDF022L RSCAN0.RMDF022.UINT16[L]
#define RSCAN0RMDF022LL RSCAN0.RMDF022.UINT8[LL]
#define RSCAN0RMDF022LH RSCAN0.RMDF022.UINT8[LH]
#define RSCAN0RMDF022H RSCAN0.RMDF022.UINT16[H]
#define RSCAN0RMDF022HL RSCAN0.RMDF022.UINT8[HL]
#define RSCAN0RMDF022HH RSCAN0.RMDF022.UINT8[HH]
#define RSCAN0RMDF122 RSCAN0.RMDF122.UINT32
#define RSCAN0RMDF122L RSCAN0.RMDF122.UINT16[L]
#define RSCAN0RMDF122LL RSCAN0.RMDF122.UINT8[LL]
#define RSCAN0RMDF122LH RSCAN0.RMDF122.UINT8[LH]
#define RSCAN0RMDF122H RSCAN0.RMDF122.UINT16[H]
#define RSCAN0RMDF122HL RSCAN0.RMDF122.UINT8[HL]
#define RSCAN0RMDF122HH RSCAN0.RMDF122.UINT8[HH]
#define RSCAN0RMID23 RSCAN0.RMID23.UINT32
#define RSCAN0RMID23L RSCAN0.RMID23.UINT16[L]
#define RSCAN0RMID23LL RSCAN0.RMID23.UINT8[LL]
#define RSCAN0RMID23LH RSCAN0.RMID23.UINT8[LH]
#define RSCAN0RMID23H RSCAN0.RMID23.UINT16[H]
#define RSCAN0RMID23HL RSCAN0.RMID23.UINT8[HL]
#define RSCAN0RMID23HH RSCAN0.RMID23.UINT8[HH]
#define RSCAN0RMPTR23 RSCAN0.RMPTR23.UINT32
#define RSCAN0RMPTR23L RSCAN0.RMPTR23.UINT16[L]
#define RSCAN0RMPTR23LL RSCAN0.RMPTR23.UINT8[LL]
#define RSCAN0RMPTR23LH RSCAN0.RMPTR23.UINT8[LH]
#define RSCAN0RMPTR23H RSCAN0.RMPTR23.UINT16[H]
#define RSCAN0RMPTR23HL RSCAN0.RMPTR23.UINT8[HL]
#define RSCAN0RMPTR23HH RSCAN0.RMPTR23.UINT8[HH]
#define RSCAN0RMDF023 RSCAN0.RMDF023.UINT32
#define RSCAN0RMDF023L RSCAN0.RMDF023.UINT16[L]
#define RSCAN0RMDF023LL RSCAN0.RMDF023.UINT8[LL]
#define RSCAN0RMDF023LH RSCAN0.RMDF023.UINT8[LH]
#define RSCAN0RMDF023H RSCAN0.RMDF023.UINT16[H]
#define RSCAN0RMDF023HL RSCAN0.RMDF023.UINT8[HL]
#define RSCAN0RMDF023HH RSCAN0.RMDF023.UINT8[HH]
#define RSCAN0RMDF123 RSCAN0.RMDF123.UINT32
#define RSCAN0RMDF123L RSCAN0.RMDF123.UINT16[L]
#define RSCAN0RMDF123LL RSCAN0.RMDF123.UINT8[LL]
#define RSCAN0RMDF123LH RSCAN0.RMDF123.UINT8[LH]
#define RSCAN0RMDF123H RSCAN0.RMDF123.UINT16[H]
#define RSCAN0RMDF123HL RSCAN0.RMDF123.UINT8[HL]
#define RSCAN0RMDF123HH RSCAN0.RMDF123.UINT8[HH]
#define RSCAN0RMID24 RSCAN0.RMID24.UINT32
#define RSCAN0RMID24L RSCAN0.RMID24.UINT16[L]
#define RSCAN0RMID24LL RSCAN0.RMID24.UINT8[LL]
#define RSCAN0RMID24LH RSCAN0.RMID24.UINT8[LH]
#define RSCAN0RMID24H RSCAN0.RMID24.UINT16[H]
#define RSCAN0RMID24HL RSCAN0.RMID24.UINT8[HL]
#define RSCAN0RMID24HH RSCAN0.RMID24.UINT8[HH]
#define RSCAN0RMPTR24 RSCAN0.RMPTR24.UINT32
#define RSCAN0RMPTR24L RSCAN0.RMPTR24.UINT16[L]
#define RSCAN0RMPTR24LL RSCAN0.RMPTR24.UINT8[LL]
#define RSCAN0RMPTR24LH RSCAN0.RMPTR24.UINT8[LH]
#define RSCAN0RMPTR24H RSCAN0.RMPTR24.UINT16[H]
#define RSCAN0RMPTR24HL RSCAN0.RMPTR24.UINT8[HL]
#define RSCAN0RMPTR24HH RSCAN0.RMPTR24.UINT8[HH]
#define RSCAN0RMDF024 RSCAN0.RMDF024.UINT32
#define RSCAN0RMDF024L RSCAN0.RMDF024.UINT16[L]
#define RSCAN0RMDF024LL RSCAN0.RMDF024.UINT8[LL]
#define RSCAN0RMDF024LH RSCAN0.RMDF024.UINT8[LH]
#define RSCAN0RMDF024H RSCAN0.RMDF024.UINT16[H]
#define RSCAN0RMDF024HL RSCAN0.RMDF024.UINT8[HL]
#define RSCAN0RMDF024HH RSCAN0.RMDF024.UINT8[HH]
#define RSCAN0RMDF124 RSCAN0.RMDF124.UINT32
#define RSCAN0RMDF124L RSCAN0.RMDF124.UINT16[L]
#define RSCAN0RMDF124LL RSCAN0.RMDF124.UINT8[LL]
#define RSCAN0RMDF124LH RSCAN0.RMDF124.UINT8[LH]
#define RSCAN0RMDF124H RSCAN0.RMDF124.UINT16[H]
#define RSCAN0RMDF124HL RSCAN0.RMDF124.UINT8[HL]
#define RSCAN0RMDF124HH RSCAN0.RMDF124.UINT8[HH]
#define RSCAN0RMID25 RSCAN0.RMID25.UINT32
#define RSCAN0RMID25L RSCAN0.RMID25.UINT16[L]
#define RSCAN0RMID25LL RSCAN0.RMID25.UINT8[LL]
#define RSCAN0RMID25LH RSCAN0.RMID25.UINT8[LH]
#define RSCAN0RMID25H RSCAN0.RMID25.UINT16[H]
#define RSCAN0RMID25HL RSCAN0.RMID25.UINT8[HL]
#define RSCAN0RMID25HH RSCAN0.RMID25.UINT8[HH]
#define RSCAN0RMPTR25 RSCAN0.RMPTR25.UINT32
#define RSCAN0RMPTR25L RSCAN0.RMPTR25.UINT16[L]
#define RSCAN0RMPTR25LL RSCAN0.RMPTR25.UINT8[LL]
#define RSCAN0RMPTR25LH RSCAN0.RMPTR25.UINT8[LH]
#define RSCAN0RMPTR25H RSCAN0.RMPTR25.UINT16[H]
#define RSCAN0RMPTR25HL RSCAN0.RMPTR25.UINT8[HL]
#define RSCAN0RMPTR25HH RSCAN0.RMPTR25.UINT8[HH]
#define RSCAN0RMDF025 RSCAN0.RMDF025.UINT32
#define RSCAN0RMDF025L RSCAN0.RMDF025.UINT16[L]
#define RSCAN0RMDF025LL RSCAN0.RMDF025.UINT8[LL]
#define RSCAN0RMDF025LH RSCAN0.RMDF025.UINT8[LH]
#define RSCAN0RMDF025H RSCAN0.RMDF025.UINT16[H]
#define RSCAN0RMDF025HL RSCAN0.RMDF025.UINT8[HL]
#define RSCAN0RMDF025HH RSCAN0.RMDF025.UINT8[HH]
#define RSCAN0RMDF125 RSCAN0.RMDF125.UINT32
#define RSCAN0RMDF125L RSCAN0.RMDF125.UINT16[L]
#define RSCAN0RMDF125LL RSCAN0.RMDF125.UINT8[LL]
#define RSCAN0RMDF125LH RSCAN0.RMDF125.UINT8[LH]
#define RSCAN0RMDF125H RSCAN0.RMDF125.UINT16[H]
#define RSCAN0RMDF125HL RSCAN0.RMDF125.UINT8[HL]
#define RSCAN0RMDF125HH RSCAN0.RMDF125.UINT8[HH]
#define RSCAN0RMID26 RSCAN0.RMID26.UINT32
#define RSCAN0RMID26L RSCAN0.RMID26.UINT16[L]
#define RSCAN0RMID26LL RSCAN0.RMID26.UINT8[LL]
#define RSCAN0RMID26LH RSCAN0.RMID26.UINT8[LH]
#define RSCAN0RMID26H RSCAN0.RMID26.UINT16[H]
#define RSCAN0RMID26HL RSCAN0.RMID26.UINT8[HL]
#define RSCAN0RMID26HH RSCAN0.RMID26.UINT8[HH]
#define RSCAN0RMPTR26 RSCAN0.RMPTR26.UINT32
#define RSCAN0RMPTR26L RSCAN0.RMPTR26.UINT16[L]
#define RSCAN0RMPTR26LL RSCAN0.RMPTR26.UINT8[LL]
#define RSCAN0RMPTR26LH RSCAN0.RMPTR26.UINT8[LH]
#define RSCAN0RMPTR26H RSCAN0.RMPTR26.UINT16[H]
#define RSCAN0RMPTR26HL RSCAN0.RMPTR26.UINT8[HL]
#define RSCAN0RMPTR26HH RSCAN0.RMPTR26.UINT8[HH]
#define RSCAN0RMDF026 RSCAN0.RMDF026.UINT32
#define RSCAN0RMDF026L RSCAN0.RMDF026.UINT16[L]
#define RSCAN0RMDF026LL RSCAN0.RMDF026.UINT8[LL]
#define RSCAN0RMDF026LH RSCAN0.RMDF026.UINT8[LH]
#define RSCAN0RMDF026H RSCAN0.RMDF026.UINT16[H]
#define RSCAN0RMDF026HL RSCAN0.RMDF026.UINT8[HL]
#define RSCAN0RMDF026HH RSCAN0.RMDF026.UINT8[HH]
#define RSCAN0RMDF126 RSCAN0.RMDF126.UINT32
#define RSCAN0RMDF126L RSCAN0.RMDF126.UINT16[L]
#define RSCAN0RMDF126LL RSCAN0.RMDF126.UINT8[LL]
#define RSCAN0RMDF126LH RSCAN0.RMDF126.UINT8[LH]
#define RSCAN0RMDF126H RSCAN0.RMDF126.UINT16[H]
#define RSCAN0RMDF126HL RSCAN0.RMDF126.UINT8[HL]
#define RSCAN0RMDF126HH RSCAN0.RMDF126.UINT8[HH]
#define RSCAN0RMID27 RSCAN0.RMID27.UINT32
#define RSCAN0RMID27L RSCAN0.RMID27.UINT16[L]
#define RSCAN0RMID27LL RSCAN0.RMID27.UINT8[LL]
#define RSCAN0RMID27LH RSCAN0.RMID27.UINT8[LH]
#define RSCAN0RMID27H RSCAN0.RMID27.UINT16[H]
#define RSCAN0RMID27HL RSCAN0.RMID27.UINT8[HL]
#define RSCAN0RMID27HH RSCAN0.RMID27.UINT8[HH]
#define RSCAN0RMPTR27 RSCAN0.RMPTR27.UINT32
#define RSCAN0RMPTR27L RSCAN0.RMPTR27.UINT16[L]
#define RSCAN0RMPTR27LL RSCAN0.RMPTR27.UINT8[LL]
#define RSCAN0RMPTR27LH RSCAN0.RMPTR27.UINT8[LH]
#define RSCAN0RMPTR27H RSCAN0.RMPTR27.UINT16[H]
#define RSCAN0RMPTR27HL RSCAN0.RMPTR27.UINT8[HL]
#define RSCAN0RMPTR27HH RSCAN0.RMPTR27.UINT8[HH]
#define RSCAN0RMDF027 RSCAN0.RMDF027.UINT32
#define RSCAN0RMDF027L RSCAN0.RMDF027.UINT16[L]
#define RSCAN0RMDF027LL RSCAN0.RMDF027.UINT8[LL]
#define RSCAN0RMDF027LH RSCAN0.RMDF027.UINT8[LH]
#define RSCAN0RMDF027H RSCAN0.RMDF027.UINT16[H]
#define RSCAN0RMDF027HL RSCAN0.RMDF027.UINT8[HL]
#define RSCAN0RMDF027HH RSCAN0.RMDF027.UINT8[HH]
#define RSCAN0RMDF127 RSCAN0.RMDF127.UINT32
#define RSCAN0RMDF127L RSCAN0.RMDF127.UINT16[L]
#define RSCAN0RMDF127LL RSCAN0.RMDF127.UINT8[LL]
#define RSCAN0RMDF127LH RSCAN0.RMDF127.UINT8[LH]
#define RSCAN0RMDF127H RSCAN0.RMDF127.UINT16[H]
#define RSCAN0RMDF127HL RSCAN0.RMDF127.UINT8[HL]
#define RSCAN0RMDF127HH RSCAN0.RMDF127.UINT8[HH]
#define RSCAN0RMID28 RSCAN0.RMID28.UINT32
#define RSCAN0RMID28L RSCAN0.RMID28.UINT16[L]
#define RSCAN0RMID28LL RSCAN0.RMID28.UINT8[LL]
#define RSCAN0RMID28LH RSCAN0.RMID28.UINT8[LH]
#define RSCAN0RMID28H RSCAN0.RMID28.UINT16[H]
#define RSCAN0RMID28HL RSCAN0.RMID28.UINT8[HL]
#define RSCAN0RMID28HH RSCAN0.RMID28.UINT8[HH]
#define RSCAN0RMPTR28 RSCAN0.RMPTR28.UINT32
#define RSCAN0RMPTR28L RSCAN0.RMPTR28.UINT16[L]
#define RSCAN0RMPTR28LL RSCAN0.RMPTR28.UINT8[LL]
#define RSCAN0RMPTR28LH RSCAN0.RMPTR28.UINT8[LH]
#define RSCAN0RMPTR28H RSCAN0.RMPTR28.UINT16[H]
#define RSCAN0RMPTR28HL RSCAN0.RMPTR28.UINT8[HL]
#define RSCAN0RMPTR28HH RSCAN0.RMPTR28.UINT8[HH]
#define RSCAN0RMDF028 RSCAN0.RMDF028.UINT32
#define RSCAN0RMDF028L RSCAN0.RMDF028.UINT16[L]
#define RSCAN0RMDF028LL RSCAN0.RMDF028.UINT8[LL]
#define RSCAN0RMDF028LH RSCAN0.RMDF028.UINT8[LH]
#define RSCAN0RMDF028H RSCAN0.RMDF028.UINT16[H]
#define RSCAN0RMDF028HL RSCAN0.RMDF028.UINT8[HL]
#define RSCAN0RMDF028HH RSCAN0.RMDF028.UINT8[HH]
#define RSCAN0RMDF128 RSCAN0.RMDF128.UINT32
#define RSCAN0RMDF128L RSCAN0.RMDF128.UINT16[L]
#define RSCAN0RMDF128LL RSCAN0.RMDF128.UINT8[LL]
#define RSCAN0RMDF128LH RSCAN0.RMDF128.UINT8[LH]
#define RSCAN0RMDF128H RSCAN0.RMDF128.UINT16[H]
#define RSCAN0RMDF128HL RSCAN0.RMDF128.UINT8[HL]
#define RSCAN0RMDF128HH RSCAN0.RMDF128.UINT8[HH]
#define RSCAN0RMID29 RSCAN0.RMID29.UINT32
#define RSCAN0RMID29L RSCAN0.RMID29.UINT16[L]
#define RSCAN0RMID29LL RSCAN0.RMID29.UINT8[LL]
#define RSCAN0RMID29LH RSCAN0.RMID29.UINT8[LH]
#define RSCAN0RMID29H RSCAN0.RMID29.UINT16[H]
#define RSCAN0RMID29HL RSCAN0.RMID29.UINT8[HL]
#define RSCAN0RMID29HH RSCAN0.RMID29.UINT8[HH]
#define RSCAN0RMPTR29 RSCAN0.RMPTR29.UINT32
#define RSCAN0RMPTR29L RSCAN0.RMPTR29.UINT16[L]
#define RSCAN0RMPTR29LL RSCAN0.RMPTR29.UINT8[LL]
#define RSCAN0RMPTR29LH RSCAN0.RMPTR29.UINT8[LH]
#define RSCAN0RMPTR29H RSCAN0.RMPTR29.UINT16[H]
#define RSCAN0RMPTR29HL RSCAN0.RMPTR29.UINT8[HL]
#define RSCAN0RMPTR29HH RSCAN0.RMPTR29.UINT8[HH]
#define RSCAN0RMDF029 RSCAN0.RMDF029.UINT32
#define RSCAN0RMDF029L RSCAN0.RMDF029.UINT16[L]
#define RSCAN0RMDF029LL RSCAN0.RMDF029.UINT8[LL]
#define RSCAN0RMDF029LH RSCAN0.RMDF029.UINT8[LH]
#define RSCAN0RMDF029H RSCAN0.RMDF029.UINT16[H]
#define RSCAN0RMDF029HL RSCAN0.RMDF029.UINT8[HL]
#define RSCAN0RMDF029HH RSCAN0.RMDF029.UINT8[HH]
#define RSCAN0RMDF129 RSCAN0.RMDF129.UINT32
#define RSCAN0RMDF129L RSCAN0.RMDF129.UINT16[L]
#define RSCAN0RMDF129LL RSCAN0.RMDF129.UINT8[LL]
#define RSCAN0RMDF129LH RSCAN0.RMDF129.UINT8[LH]
#define RSCAN0RMDF129H RSCAN0.RMDF129.UINT16[H]
#define RSCAN0RMDF129HL RSCAN0.RMDF129.UINT8[HL]
#define RSCAN0RMDF129HH RSCAN0.RMDF129.UINT8[HH]
#define RSCAN0RMID30 RSCAN0.RMID30.UINT32
#define RSCAN0RMID30L RSCAN0.RMID30.UINT16[L]
#define RSCAN0RMID30LL RSCAN0.RMID30.UINT8[LL]
#define RSCAN0RMID30LH RSCAN0.RMID30.UINT8[LH]
#define RSCAN0RMID30H RSCAN0.RMID30.UINT16[H]
#define RSCAN0RMID30HL RSCAN0.RMID30.UINT8[HL]
#define RSCAN0RMID30HH RSCAN0.RMID30.UINT8[HH]
#define RSCAN0RMPTR30 RSCAN0.RMPTR30.UINT32
#define RSCAN0RMPTR30L RSCAN0.RMPTR30.UINT16[L]
#define RSCAN0RMPTR30LL RSCAN0.RMPTR30.UINT8[LL]
#define RSCAN0RMPTR30LH RSCAN0.RMPTR30.UINT8[LH]
#define RSCAN0RMPTR30H RSCAN0.RMPTR30.UINT16[H]
#define RSCAN0RMPTR30HL RSCAN0.RMPTR30.UINT8[HL]
#define RSCAN0RMPTR30HH RSCAN0.RMPTR30.UINT8[HH]
#define RSCAN0RMDF030 RSCAN0.RMDF030.UINT32
#define RSCAN0RMDF030L RSCAN0.RMDF030.UINT16[L]
#define RSCAN0RMDF030LL RSCAN0.RMDF030.UINT8[LL]
#define RSCAN0RMDF030LH RSCAN0.RMDF030.UINT8[LH]
#define RSCAN0RMDF030H RSCAN0.RMDF030.UINT16[H]
#define RSCAN0RMDF030HL RSCAN0.RMDF030.UINT8[HL]
#define RSCAN0RMDF030HH RSCAN0.RMDF030.UINT8[HH]
#define RSCAN0RMDF130 RSCAN0.RMDF130.UINT32
#define RSCAN0RMDF130L RSCAN0.RMDF130.UINT16[L]
#define RSCAN0RMDF130LL RSCAN0.RMDF130.UINT8[LL]
#define RSCAN0RMDF130LH RSCAN0.RMDF130.UINT8[LH]
#define RSCAN0RMDF130H RSCAN0.RMDF130.UINT16[H]
#define RSCAN0RMDF130HL RSCAN0.RMDF130.UINT8[HL]
#define RSCAN0RMDF130HH RSCAN0.RMDF130.UINT8[HH]
#define RSCAN0RMID31 RSCAN0.RMID31.UINT32
#define RSCAN0RMID31L RSCAN0.RMID31.UINT16[L]
#define RSCAN0RMID31LL RSCAN0.RMID31.UINT8[LL]
#define RSCAN0RMID31LH RSCAN0.RMID31.UINT8[LH]
#define RSCAN0RMID31H RSCAN0.RMID31.UINT16[H]
#define RSCAN0RMID31HL RSCAN0.RMID31.UINT8[HL]
#define RSCAN0RMID31HH RSCAN0.RMID31.UINT8[HH]
#define RSCAN0RMPTR31 RSCAN0.RMPTR31.UINT32
#define RSCAN0RMPTR31L RSCAN0.RMPTR31.UINT16[L]
#define RSCAN0RMPTR31LL RSCAN0.RMPTR31.UINT8[LL]
#define RSCAN0RMPTR31LH RSCAN0.RMPTR31.UINT8[LH]
#define RSCAN0RMPTR31H RSCAN0.RMPTR31.UINT16[H]
#define RSCAN0RMPTR31HL RSCAN0.RMPTR31.UINT8[HL]
#define RSCAN0RMPTR31HH RSCAN0.RMPTR31.UINT8[HH]
#define RSCAN0RMDF031 RSCAN0.RMDF031.UINT32
#define RSCAN0RMDF031L RSCAN0.RMDF031.UINT16[L]
#define RSCAN0RMDF031LL RSCAN0.RMDF031.UINT8[LL]
#define RSCAN0RMDF031LH RSCAN0.RMDF031.UINT8[LH]
#define RSCAN0RMDF031H RSCAN0.RMDF031.UINT16[H]
#define RSCAN0RMDF031HL RSCAN0.RMDF031.UINT8[HL]
#define RSCAN0RMDF031HH RSCAN0.RMDF031.UINT8[HH]
#define RSCAN0RMDF131 RSCAN0.RMDF131.UINT32
#define RSCAN0RMDF131L RSCAN0.RMDF131.UINT16[L]
#define RSCAN0RMDF131LL RSCAN0.RMDF131.UINT8[LL]
#define RSCAN0RMDF131LH RSCAN0.RMDF131.UINT8[LH]
#define RSCAN0RMDF131H RSCAN0.RMDF131.UINT16[H]
#define RSCAN0RMDF131HL RSCAN0.RMDF131.UINT8[HL]
#define RSCAN0RMDF131HH RSCAN0.RMDF131.UINT8[HH]
#define RSCAN0RMID32 RSCAN0.RMID32.UINT32
#define RSCAN0RMID32L RSCAN0.RMID32.UINT16[L]
#define RSCAN0RMID32LL RSCAN0.RMID32.UINT8[LL]
#define RSCAN0RMID32LH RSCAN0.RMID32.UINT8[LH]
#define RSCAN0RMID32H RSCAN0.RMID32.UINT16[H]
#define RSCAN0RMID32HL RSCAN0.RMID32.UINT8[HL]
#define RSCAN0RMID32HH RSCAN0.RMID32.UINT8[HH]
#define RSCAN0RMPTR32 RSCAN0.RMPTR32.UINT32
#define RSCAN0RMPTR32L RSCAN0.RMPTR32.UINT16[L]
#define RSCAN0RMPTR32LL RSCAN0.RMPTR32.UINT8[LL]
#define RSCAN0RMPTR32LH RSCAN0.RMPTR32.UINT8[LH]
#define RSCAN0RMPTR32H RSCAN0.RMPTR32.UINT16[H]
#define RSCAN0RMPTR32HL RSCAN0.RMPTR32.UINT8[HL]
#define RSCAN0RMPTR32HH RSCAN0.RMPTR32.UINT8[HH]
#define RSCAN0RMDF032 RSCAN0.RMDF032.UINT32
#define RSCAN0RMDF032L RSCAN0.RMDF032.UINT16[L]
#define RSCAN0RMDF032LL RSCAN0.RMDF032.UINT8[LL]
#define RSCAN0RMDF032LH RSCAN0.RMDF032.UINT8[LH]
#define RSCAN0RMDF032H RSCAN0.RMDF032.UINT16[H]
#define RSCAN0RMDF032HL RSCAN0.RMDF032.UINT8[HL]
#define RSCAN0RMDF032HH RSCAN0.RMDF032.UINT8[HH]
#define RSCAN0RMDF132 RSCAN0.RMDF132.UINT32
#define RSCAN0RMDF132L RSCAN0.RMDF132.UINT16[L]
#define RSCAN0RMDF132LL RSCAN0.RMDF132.UINT8[LL]
#define RSCAN0RMDF132LH RSCAN0.RMDF132.UINT8[LH]
#define RSCAN0RMDF132H RSCAN0.RMDF132.UINT16[H]
#define RSCAN0RMDF132HL RSCAN0.RMDF132.UINT8[HL]
#define RSCAN0RMDF132HH RSCAN0.RMDF132.UINT8[HH]
#define RSCAN0RMID33 RSCAN0.RMID33.UINT32
#define RSCAN0RMID33L RSCAN0.RMID33.UINT16[L]
#define RSCAN0RMID33LL RSCAN0.RMID33.UINT8[LL]
#define RSCAN0RMID33LH RSCAN0.RMID33.UINT8[LH]
#define RSCAN0RMID33H RSCAN0.RMID33.UINT16[H]
#define RSCAN0RMID33HL RSCAN0.RMID33.UINT8[HL]
#define RSCAN0RMID33HH RSCAN0.RMID33.UINT8[HH]
#define RSCAN0RMPTR33 RSCAN0.RMPTR33.UINT32
#define RSCAN0RMPTR33L RSCAN0.RMPTR33.UINT16[L]
#define RSCAN0RMPTR33LL RSCAN0.RMPTR33.UINT8[LL]
#define RSCAN0RMPTR33LH RSCAN0.RMPTR33.UINT8[LH]
#define RSCAN0RMPTR33H RSCAN0.RMPTR33.UINT16[H]
#define RSCAN0RMPTR33HL RSCAN0.RMPTR33.UINT8[HL]
#define RSCAN0RMPTR33HH RSCAN0.RMPTR33.UINT8[HH]
#define RSCAN0RMDF033 RSCAN0.RMDF033.UINT32
#define RSCAN0RMDF033L RSCAN0.RMDF033.UINT16[L]
#define RSCAN0RMDF033LL RSCAN0.RMDF033.UINT8[LL]
#define RSCAN0RMDF033LH RSCAN0.RMDF033.UINT8[LH]
#define RSCAN0RMDF033H RSCAN0.RMDF033.UINT16[H]
#define RSCAN0RMDF033HL RSCAN0.RMDF033.UINT8[HL]
#define RSCAN0RMDF033HH RSCAN0.RMDF033.UINT8[HH]
#define RSCAN0RMDF133 RSCAN0.RMDF133.UINT32
#define RSCAN0RMDF133L RSCAN0.RMDF133.UINT16[L]
#define RSCAN0RMDF133LL RSCAN0.RMDF133.UINT8[LL]
#define RSCAN0RMDF133LH RSCAN0.RMDF133.UINT8[LH]
#define RSCAN0RMDF133H RSCAN0.RMDF133.UINT16[H]
#define RSCAN0RMDF133HL RSCAN0.RMDF133.UINT8[HL]
#define RSCAN0RMDF133HH RSCAN0.RMDF133.UINT8[HH]
#define RSCAN0RMID34 RSCAN0.RMID34.UINT32
#define RSCAN0RMID34L RSCAN0.RMID34.UINT16[L]
#define RSCAN0RMID34LL RSCAN0.RMID34.UINT8[LL]
#define RSCAN0RMID34LH RSCAN0.RMID34.UINT8[LH]
#define RSCAN0RMID34H RSCAN0.RMID34.UINT16[H]
#define RSCAN0RMID34HL RSCAN0.RMID34.UINT8[HL]
#define RSCAN0RMID34HH RSCAN0.RMID34.UINT8[HH]
#define RSCAN0RMPTR34 RSCAN0.RMPTR34.UINT32
#define RSCAN0RMPTR34L RSCAN0.RMPTR34.UINT16[L]
#define RSCAN0RMPTR34LL RSCAN0.RMPTR34.UINT8[LL]
#define RSCAN0RMPTR34LH RSCAN0.RMPTR34.UINT8[LH]
#define RSCAN0RMPTR34H RSCAN0.RMPTR34.UINT16[H]
#define RSCAN0RMPTR34HL RSCAN0.RMPTR34.UINT8[HL]
#define RSCAN0RMPTR34HH RSCAN0.RMPTR34.UINT8[HH]
#define RSCAN0RMDF034 RSCAN0.RMDF034.UINT32
#define RSCAN0RMDF034L RSCAN0.RMDF034.UINT16[L]
#define RSCAN0RMDF034LL RSCAN0.RMDF034.UINT8[LL]
#define RSCAN0RMDF034LH RSCAN0.RMDF034.UINT8[LH]
#define RSCAN0RMDF034H RSCAN0.RMDF034.UINT16[H]
#define RSCAN0RMDF034HL RSCAN0.RMDF034.UINT8[HL]
#define RSCAN0RMDF034HH RSCAN0.RMDF034.UINT8[HH]
#define RSCAN0RMDF134 RSCAN0.RMDF134.UINT32
#define RSCAN0RMDF134L RSCAN0.RMDF134.UINT16[L]
#define RSCAN0RMDF134LL RSCAN0.RMDF134.UINT8[LL]
#define RSCAN0RMDF134LH RSCAN0.RMDF134.UINT8[LH]
#define RSCAN0RMDF134H RSCAN0.RMDF134.UINT16[H]
#define RSCAN0RMDF134HL RSCAN0.RMDF134.UINT8[HL]
#define RSCAN0RMDF134HH RSCAN0.RMDF134.UINT8[HH]
#define RSCAN0RMID35 RSCAN0.RMID35.UINT32
#define RSCAN0RMID35L RSCAN0.RMID35.UINT16[L]
#define RSCAN0RMID35LL RSCAN0.RMID35.UINT8[LL]
#define RSCAN0RMID35LH RSCAN0.RMID35.UINT8[LH]
#define RSCAN0RMID35H RSCAN0.RMID35.UINT16[H]
#define RSCAN0RMID35HL RSCAN0.RMID35.UINT8[HL]
#define RSCAN0RMID35HH RSCAN0.RMID35.UINT8[HH]
#define RSCAN0RMPTR35 RSCAN0.RMPTR35.UINT32
#define RSCAN0RMPTR35L RSCAN0.RMPTR35.UINT16[L]
#define RSCAN0RMPTR35LL RSCAN0.RMPTR35.UINT8[LL]
#define RSCAN0RMPTR35LH RSCAN0.RMPTR35.UINT8[LH]
#define RSCAN0RMPTR35H RSCAN0.RMPTR35.UINT16[H]
#define RSCAN0RMPTR35HL RSCAN0.RMPTR35.UINT8[HL]
#define RSCAN0RMPTR35HH RSCAN0.RMPTR35.UINT8[HH]
#define RSCAN0RMDF035 RSCAN0.RMDF035.UINT32
#define RSCAN0RMDF035L RSCAN0.RMDF035.UINT16[L]
#define RSCAN0RMDF035LL RSCAN0.RMDF035.UINT8[LL]
#define RSCAN0RMDF035LH RSCAN0.RMDF035.UINT8[LH]
#define RSCAN0RMDF035H RSCAN0.RMDF035.UINT16[H]
#define RSCAN0RMDF035HL RSCAN0.RMDF035.UINT8[HL]
#define RSCAN0RMDF035HH RSCAN0.RMDF035.UINT8[HH]
#define RSCAN0RMDF135 RSCAN0.RMDF135.UINT32
#define RSCAN0RMDF135L RSCAN0.RMDF135.UINT16[L]
#define RSCAN0RMDF135LL RSCAN0.RMDF135.UINT8[LL]
#define RSCAN0RMDF135LH RSCAN0.RMDF135.UINT8[LH]
#define RSCAN0RMDF135H RSCAN0.RMDF135.UINT16[H]
#define RSCAN0RMDF135HL RSCAN0.RMDF135.UINT8[HL]
#define RSCAN0RMDF135HH RSCAN0.RMDF135.UINT8[HH]
#define RSCAN0RMID36 RSCAN0.RMID36.UINT32
#define RSCAN0RMID36L RSCAN0.RMID36.UINT16[L]
#define RSCAN0RMID36LL RSCAN0.RMID36.UINT8[LL]
#define RSCAN0RMID36LH RSCAN0.RMID36.UINT8[LH]
#define RSCAN0RMID36H RSCAN0.RMID36.UINT16[H]
#define RSCAN0RMID36HL RSCAN0.RMID36.UINT8[HL]
#define RSCAN0RMID36HH RSCAN0.RMID36.UINT8[HH]
#define RSCAN0RMPTR36 RSCAN0.RMPTR36.UINT32
#define RSCAN0RMPTR36L RSCAN0.RMPTR36.UINT16[L]
#define RSCAN0RMPTR36LL RSCAN0.RMPTR36.UINT8[LL]
#define RSCAN0RMPTR36LH RSCAN0.RMPTR36.UINT8[LH]
#define RSCAN0RMPTR36H RSCAN0.RMPTR36.UINT16[H]
#define RSCAN0RMPTR36HL RSCAN0.RMPTR36.UINT8[HL]
#define RSCAN0RMPTR36HH RSCAN0.RMPTR36.UINT8[HH]
#define RSCAN0RMDF036 RSCAN0.RMDF036.UINT32
#define RSCAN0RMDF036L RSCAN0.RMDF036.UINT16[L]
#define RSCAN0RMDF036LL RSCAN0.RMDF036.UINT8[LL]
#define RSCAN0RMDF036LH RSCAN0.RMDF036.UINT8[LH]
#define RSCAN0RMDF036H RSCAN0.RMDF036.UINT16[H]
#define RSCAN0RMDF036HL RSCAN0.RMDF036.UINT8[HL]
#define RSCAN0RMDF036HH RSCAN0.RMDF036.UINT8[HH]
#define RSCAN0RMDF136 RSCAN0.RMDF136.UINT32
#define RSCAN0RMDF136L RSCAN0.RMDF136.UINT16[L]
#define RSCAN0RMDF136LL RSCAN0.RMDF136.UINT8[LL]
#define RSCAN0RMDF136LH RSCAN0.RMDF136.UINT8[LH]
#define RSCAN0RMDF136H RSCAN0.RMDF136.UINT16[H]
#define RSCAN0RMDF136HL RSCAN0.RMDF136.UINT8[HL]
#define RSCAN0RMDF136HH RSCAN0.RMDF136.UINT8[HH]
#define RSCAN0RMID37 RSCAN0.RMID37.UINT32
#define RSCAN0RMID37L RSCAN0.RMID37.UINT16[L]
#define RSCAN0RMID37LL RSCAN0.RMID37.UINT8[LL]
#define RSCAN0RMID37LH RSCAN0.RMID37.UINT8[LH]
#define RSCAN0RMID37H RSCAN0.RMID37.UINT16[H]
#define RSCAN0RMID37HL RSCAN0.RMID37.UINT8[HL]
#define RSCAN0RMID37HH RSCAN0.RMID37.UINT8[HH]
#define RSCAN0RMPTR37 RSCAN0.RMPTR37.UINT32
#define RSCAN0RMPTR37L RSCAN0.RMPTR37.UINT16[L]
#define RSCAN0RMPTR37LL RSCAN0.RMPTR37.UINT8[LL]
#define RSCAN0RMPTR37LH RSCAN0.RMPTR37.UINT8[LH]
#define RSCAN0RMPTR37H RSCAN0.RMPTR37.UINT16[H]
#define RSCAN0RMPTR37HL RSCAN0.RMPTR37.UINT8[HL]
#define RSCAN0RMPTR37HH RSCAN0.RMPTR37.UINT8[HH]
#define RSCAN0RMDF037 RSCAN0.RMDF037.UINT32
#define RSCAN0RMDF037L RSCAN0.RMDF037.UINT16[L]
#define RSCAN0RMDF037LL RSCAN0.RMDF037.UINT8[LL]
#define RSCAN0RMDF037LH RSCAN0.RMDF037.UINT8[LH]
#define RSCAN0RMDF037H RSCAN0.RMDF037.UINT16[H]
#define RSCAN0RMDF037HL RSCAN0.RMDF037.UINT8[HL]
#define RSCAN0RMDF037HH RSCAN0.RMDF037.UINT8[HH]
#define RSCAN0RMDF137 RSCAN0.RMDF137.UINT32
#define RSCAN0RMDF137L RSCAN0.RMDF137.UINT16[L]
#define RSCAN0RMDF137LL RSCAN0.RMDF137.UINT8[LL]
#define RSCAN0RMDF137LH RSCAN0.RMDF137.UINT8[LH]
#define RSCAN0RMDF137H RSCAN0.RMDF137.UINT16[H]
#define RSCAN0RMDF137HL RSCAN0.RMDF137.UINT8[HL]
#define RSCAN0RMDF137HH RSCAN0.RMDF137.UINT8[HH]
#define RSCAN0RMID38 RSCAN0.RMID38.UINT32
#define RSCAN0RMID38L RSCAN0.RMID38.UINT16[L]
#define RSCAN0RMID38LL RSCAN0.RMID38.UINT8[LL]
#define RSCAN0RMID38LH RSCAN0.RMID38.UINT8[LH]
#define RSCAN0RMID38H RSCAN0.RMID38.UINT16[H]
#define RSCAN0RMID38HL RSCAN0.RMID38.UINT8[HL]
#define RSCAN0RMID38HH RSCAN0.RMID38.UINT8[HH]
#define RSCAN0RMPTR38 RSCAN0.RMPTR38.UINT32
#define RSCAN0RMPTR38L RSCAN0.RMPTR38.UINT16[L]
#define RSCAN0RMPTR38LL RSCAN0.RMPTR38.UINT8[LL]
#define RSCAN0RMPTR38LH RSCAN0.RMPTR38.UINT8[LH]
#define RSCAN0RMPTR38H RSCAN0.RMPTR38.UINT16[H]
#define RSCAN0RMPTR38HL RSCAN0.RMPTR38.UINT8[HL]
#define RSCAN0RMPTR38HH RSCAN0.RMPTR38.UINT8[HH]
#define RSCAN0RMDF038 RSCAN0.RMDF038.UINT32
#define RSCAN0RMDF038L RSCAN0.RMDF038.UINT16[L]
#define RSCAN0RMDF038LL RSCAN0.RMDF038.UINT8[LL]
#define RSCAN0RMDF038LH RSCAN0.RMDF038.UINT8[LH]
#define RSCAN0RMDF038H RSCAN0.RMDF038.UINT16[H]
#define RSCAN0RMDF038HL RSCAN0.RMDF038.UINT8[HL]
#define RSCAN0RMDF038HH RSCAN0.RMDF038.UINT8[HH]
#define RSCAN0RMDF138 RSCAN0.RMDF138.UINT32
#define RSCAN0RMDF138L RSCAN0.RMDF138.UINT16[L]
#define RSCAN0RMDF138LL RSCAN0.RMDF138.UINT8[LL]
#define RSCAN0RMDF138LH RSCAN0.RMDF138.UINT8[LH]
#define RSCAN0RMDF138H RSCAN0.RMDF138.UINT16[H]
#define RSCAN0RMDF138HL RSCAN0.RMDF138.UINT8[HL]
#define RSCAN0RMDF138HH RSCAN0.RMDF138.UINT8[HH]
#define RSCAN0RMID39 RSCAN0.RMID39.UINT32
#define RSCAN0RMID39L RSCAN0.RMID39.UINT16[L]
#define RSCAN0RMID39LL RSCAN0.RMID39.UINT8[LL]
#define RSCAN0RMID39LH RSCAN0.RMID39.UINT8[LH]
#define RSCAN0RMID39H RSCAN0.RMID39.UINT16[H]
#define RSCAN0RMID39HL RSCAN0.RMID39.UINT8[HL]
#define RSCAN0RMID39HH RSCAN0.RMID39.UINT8[HH]
#define RSCAN0RMPTR39 RSCAN0.RMPTR39.UINT32
#define RSCAN0RMPTR39L RSCAN0.RMPTR39.UINT16[L]
#define RSCAN0RMPTR39LL RSCAN0.RMPTR39.UINT8[LL]
#define RSCAN0RMPTR39LH RSCAN0.RMPTR39.UINT8[LH]
#define RSCAN0RMPTR39H RSCAN0.RMPTR39.UINT16[H]
#define RSCAN0RMPTR39HL RSCAN0.RMPTR39.UINT8[HL]
#define RSCAN0RMPTR39HH RSCAN0.RMPTR39.UINT8[HH]
#define RSCAN0RMDF039 RSCAN0.RMDF039.UINT32
#define RSCAN0RMDF039L RSCAN0.RMDF039.UINT16[L]
#define RSCAN0RMDF039LL RSCAN0.RMDF039.UINT8[LL]
#define RSCAN0RMDF039LH RSCAN0.RMDF039.UINT8[LH]
#define RSCAN0RMDF039H RSCAN0.RMDF039.UINT16[H]
#define RSCAN0RMDF039HL RSCAN0.RMDF039.UINT8[HL]
#define RSCAN0RMDF039HH RSCAN0.RMDF039.UINT8[HH]
#define RSCAN0RMDF139 RSCAN0.RMDF139.UINT32
#define RSCAN0RMDF139L RSCAN0.RMDF139.UINT16[L]
#define RSCAN0RMDF139LL RSCAN0.RMDF139.UINT8[LL]
#define RSCAN0RMDF139LH RSCAN0.RMDF139.UINT8[LH]
#define RSCAN0RMDF139H RSCAN0.RMDF139.UINT16[H]
#define RSCAN0RMDF139HL RSCAN0.RMDF139.UINT8[HL]
#define RSCAN0RMDF139HH RSCAN0.RMDF139.UINT8[HH]
#define RSCAN0RMID40 RSCAN0.RMID40.UINT32
#define RSCAN0RMID40L RSCAN0.RMID40.UINT16[L]
#define RSCAN0RMID40LL RSCAN0.RMID40.UINT8[LL]
#define RSCAN0RMID40LH RSCAN0.RMID40.UINT8[LH]
#define RSCAN0RMID40H RSCAN0.RMID40.UINT16[H]
#define RSCAN0RMID40HL RSCAN0.RMID40.UINT8[HL]
#define RSCAN0RMID40HH RSCAN0.RMID40.UINT8[HH]
#define RSCAN0RMPTR40 RSCAN0.RMPTR40.UINT32
#define RSCAN0RMPTR40L RSCAN0.RMPTR40.UINT16[L]
#define RSCAN0RMPTR40LL RSCAN0.RMPTR40.UINT8[LL]
#define RSCAN0RMPTR40LH RSCAN0.RMPTR40.UINT8[LH]
#define RSCAN0RMPTR40H RSCAN0.RMPTR40.UINT16[H]
#define RSCAN0RMPTR40HL RSCAN0.RMPTR40.UINT8[HL]
#define RSCAN0RMPTR40HH RSCAN0.RMPTR40.UINT8[HH]
#define RSCAN0RMDF040 RSCAN0.RMDF040.UINT32
#define RSCAN0RMDF040L RSCAN0.RMDF040.UINT16[L]
#define RSCAN0RMDF040LL RSCAN0.RMDF040.UINT8[LL]
#define RSCAN0RMDF040LH RSCAN0.RMDF040.UINT8[LH]
#define RSCAN0RMDF040H RSCAN0.RMDF040.UINT16[H]
#define RSCAN0RMDF040HL RSCAN0.RMDF040.UINT8[HL]
#define RSCAN0RMDF040HH RSCAN0.RMDF040.UINT8[HH]
#define RSCAN0RMDF140 RSCAN0.RMDF140.UINT32
#define RSCAN0RMDF140L RSCAN0.RMDF140.UINT16[L]
#define RSCAN0RMDF140LL RSCAN0.RMDF140.UINT8[LL]
#define RSCAN0RMDF140LH RSCAN0.RMDF140.UINT8[LH]
#define RSCAN0RMDF140H RSCAN0.RMDF140.UINT16[H]
#define RSCAN0RMDF140HL RSCAN0.RMDF140.UINT8[HL]
#define RSCAN0RMDF140HH RSCAN0.RMDF140.UINT8[HH]
#define RSCAN0RMID41 RSCAN0.RMID41.UINT32
#define RSCAN0RMID41L RSCAN0.RMID41.UINT16[L]
#define RSCAN0RMID41LL RSCAN0.RMID41.UINT8[LL]
#define RSCAN0RMID41LH RSCAN0.RMID41.UINT8[LH]
#define RSCAN0RMID41H RSCAN0.RMID41.UINT16[H]
#define RSCAN0RMID41HL RSCAN0.RMID41.UINT8[HL]
#define RSCAN0RMID41HH RSCAN0.RMID41.UINT8[HH]
#define RSCAN0RMPTR41 RSCAN0.RMPTR41.UINT32
#define RSCAN0RMPTR41L RSCAN0.RMPTR41.UINT16[L]
#define RSCAN0RMPTR41LL RSCAN0.RMPTR41.UINT8[LL]
#define RSCAN0RMPTR41LH RSCAN0.RMPTR41.UINT8[LH]
#define RSCAN0RMPTR41H RSCAN0.RMPTR41.UINT16[H]
#define RSCAN0RMPTR41HL RSCAN0.RMPTR41.UINT8[HL]
#define RSCAN0RMPTR41HH RSCAN0.RMPTR41.UINT8[HH]
#define RSCAN0RMDF041 RSCAN0.RMDF041.UINT32
#define RSCAN0RMDF041L RSCAN0.RMDF041.UINT16[L]
#define RSCAN0RMDF041LL RSCAN0.RMDF041.UINT8[LL]
#define RSCAN0RMDF041LH RSCAN0.RMDF041.UINT8[LH]
#define RSCAN0RMDF041H RSCAN0.RMDF041.UINT16[H]
#define RSCAN0RMDF041HL RSCAN0.RMDF041.UINT8[HL]
#define RSCAN0RMDF041HH RSCAN0.RMDF041.UINT8[HH]
#define RSCAN0RMDF141 RSCAN0.RMDF141.UINT32
#define RSCAN0RMDF141L RSCAN0.RMDF141.UINT16[L]
#define RSCAN0RMDF141LL RSCAN0.RMDF141.UINT8[LL]
#define RSCAN0RMDF141LH RSCAN0.RMDF141.UINT8[LH]
#define RSCAN0RMDF141H RSCAN0.RMDF141.UINT16[H]
#define RSCAN0RMDF141HL RSCAN0.RMDF141.UINT8[HL]
#define RSCAN0RMDF141HH RSCAN0.RMDF141.UINT8[HH]
#define RSCAN0RMID42 RSCAN0.RMID42.UINT32
#define RSCAN0RMID42L RSCAN0.RMID42.UINT16[L]
#define RSCAN0RMID42LL RSCAN0.RMID42.UINT8[LL]
#define RSCAN0RMID42LH RSCAN0.RMID42.UINT8[LH]
#define RSCAN0RMID42H RSCAN0.RMID42.UINT16[H]
#define RSCAN0RMID42HL RSCAN0.RMID42.UINT8[HL]
#define RSCAN0RMID42HH RSCAN0.RMID42.UINT8[HH]
#define RSCAN0RMPTR42 RSCAN0.RMPTR42.UINT32
#define RSCAN0RMPTR42L RSCAN0.RMPTR42.UINT16[L]
#define RSCAN0RMPTR42LL RSCAN0.RMPTR42.UINT8[LL]
#define RSCAN0RMPTR42LH RSCAN0.RMPTR42.UINT8[LH]
#define RSCAN0RMPTR42H RSCAN0.RMPTR42.UINT16[H]
#define RSCAN0RMPTR42HL RSCAN0.RMPTR42.UINT8[HL]
#define RSCAN0RMPTR42HH RSCAN0.RMPTR42.UINT8[HH]
#define RSCAN0RMDF042 RSCAN0.RMDF042.UINT32
#define RSCAN0RMDF042L RSCAN0.RMDF042.UINT16[L]
#define RSCAN0RMDF042LL RSCAN0.RMDF042.UINT8[LL]
#define RSCAN0RMDF042LH RSCAN0.RMDF042.UINT8[LH]
#define RSCAN0RMDF042H RSCAN0.RMDF042.UINT16[H]
#define RSCAN0RMDF042HL RSCAN0.RMDF042.UINT8[HL]
#define RSCAN0RMDF042HH RSCAN0.RMDF042.UINT8[HH]
#define RSCAN0RMDF142 RSCAN0.RMDF142.UINT32
#define RSCAN0RMDF142L RSCAN0.RMDF142.UINT16[L]
#define RSCAN0RMDF142LL RSCAN0.RMDF142.UINT8[LL]
#define RSCAN0RMDF142LH RSCAN0.RMDF142.UINT8[LH]
#define RSCAN0RMDF142H RSCAN0.RMDF142.UINT16[H]
#define RSCAN0RMDF142HL RSCAN0.RMDF142.UINT8[HL]
#define RSCAN0RMDF142HH RSCAN0.RMDF142.UINT8[HH]
#define RSCAN0RMID43 RSCAN0.RMID43.UINT32
#define RSCAN0RMID43L RSCAN0.RMID43.UINT16[L]
#define RSCAN0RMID43LL RSCAN0.RMID43.UINT8[LL]
#define RSCAN0RMID43LH RSCAN0.RMID43.UINT8[LH]
#define RSCAN0RMID43H RSCAN0.RMID43.UINT16[H]
#define RSCAN0RMID43HL RSCAN0.RMID43.UINT8[HL]
#define RSCAN0RMID43HH RSCAN0.RMID43.UINT8[HH]
#define RSCAN0RMPTR43 RSCAN0.RMPTR43.UINT32
#define RSCAN0RMPTR43L RSCAN0.RMPTR43.UINT16[L]
#define RSCAN0RMPTR43LL RSCAN0.RMPTR43.UINT8[LL]
#define RSCAN0RMPTR43LH RSCAN0.RMPTR43.UINT8[LH]
#define RSCAN0RMPTR43H RSCAN0.RMPTR43.UINT16[H]
#define RSCAN0RMPTR43HL RSCAN0.RMPTR43.UINT8[HL]
#define RSCAN0RMPTR43HH RSCAN0.RMPTR43.UINT8[HH]
#define RSCAN0RMDF043 RSCAN0.RMDF043.UINT32
#define RSCAN0RMDF043L RSCAN0.RMDF043.UINT16[L]
#define RSCAN0RMDF043LL RSCAN0.RMDF043.UINT8[LL]
#define RSCAN0RMDF043LH RSCAN0.RMDF043.UINT8[LH]
#define RSCAN0RMDF043H RSCAN0.RMDF043.UINT16[H]
#define RSCAN0RMDF043HL RSCAN0.RMDF043.UINT8[HL]
#define RSCAN0RMDF043HH RSCAN0.RMDF043.UINT8[HH]
#define RSCAN0RMDF143 RSCAN0.RMDF143.UINT32
#define RSCAN0RMDF143L RSCAN0.RMDF143.UINT16[L]
#define RSCAN0RMDF143LL RSCAN0.RMDF143.UINT8[LL]
#define RSCAN0RMDF143LH RSCAN0.RMDF143.UINT8[LH]
#define RSCAN0RMDF143H RSCAN0.RMDF143.UINT16[H]
#define RSCAN0RMDF143HL RSCAN0.RMDF143.UINT8[HL]
#define RSCAN0RMDF143HH RSCAN0.RMDF143.UINT8[HH]
#define RSCAN0RMID44 RSCAN0.RMID44.UINT32
#define RSCAN0RMID44L RSCAN0.RMID44.UINT16[L]
#define RSCAN0RMID44LL RSCAN0.RMID44.UINT8[LL]
#define RSCAN0RMID44LH RSCAN0.RMID44.UINT8[LH]
#define RSCAN0RMID44H RSCAN0.RMID44.UINT16[H]
#define RSCAN0RMID44HL RSCAN0.RMID44.UINT8[HL]
#define RSCAN0RMID44HH RSCAN0.RMID44.UINT8[HH]
#define RSCAN0RMPTR44 RSCAN0.RMPTR44.UINT32
#define RSCAN0RMPTR44L RSCAN0.RMPTR44.UINT16[L]
#define RSCAN0RMPTR44LL RSCAN0.RMPTR44.UINT8[LL]
#define RSCAN0RMPTR44LH RSCAN0.RMPTR44.UINT8[LH]
#define RSCAN0RMPTR44H RSCAN0.RMPTR44.UINT16[H]
#define RSCAN0RMPTR44HL RSCAN0.RMPTR44.UINT8[HL]
#define RSCAN0RMPTR44HH RSCAN0.RMPTR44.UINT8[HH]
#define RSCAN0RMDF044 RSCAN0.RMDF044.UINT32
#define RSCAN0RMDF044L RSCAN0.RMDF044.UINT16[L]
#define RSCAN0RMDF044LL RSCAN0.RMDF044.UINT8[LL]
#define RSCAN0RMDF044LH RSCAN0.RMDF044.UINT8[LH]
#define RSCAN0RMDF044H RSCAN0.RMDF044.UINT16[H]
#define RSCAN0RMDF044HL RSCAN0.RMDF044.UINT8[HL]
#define RSCAN0RMDF044HH RSCAN0.RMDF044.UINT8[HH]
#define RSCAN0RMDF144 RSCAN0.RMDF144.UINT32
#define RSCAN0RMDF144L RSCAN0.RMDF144.UINT16[L]
#define RSCAN0RMDF144LL RSCAN0.RMDF144.UINT8[LL]
#define RSCAN0RMDF144LH RSCAN0.RMDF144.UINT8[LH]
#define RSCAN0RMDF144H RSCAN0.RMDF144.UINT16[H]
#define RSCAN0RMDF144HL RSCAN0.RMDF144.UINT8[HL]
#define RSCAN0RMDF144HH RSCAN0.RMDF144.UINT8[HH]
#define RSCAN0RMID45 RSCAN0.RMID45.UINT32
#define RSCAN0RMID45L RSCAN0.RMID45.UINT16[L]
#define RSCAN0RMID45LL RSCAN0.RMID45.UINT8[LL]
#define RSCAN0RMID45LH RSCAN0.RMID45.UINT8[LH]
#define RSCAN0RMID45H RSCAN0.RMID45.UINT16[H]
#define RSCAN0RMID45HL RSCAN0.RMID45.UINT8[HL]
#define RSCAN0RMID45HH RSCAN0.RMID45.UINT8[HH]
#define RSCAN0RMPTR45 RSCAN0.RMPTR45.UINT32
#define RSCAN0RMPTR45L RSCAN0.RMPTR45.UINT16[L]
#define RSCAN0RMPTR45LL RSCAN0.RMPTR45.UINT8[LL]
#define RSCAN0RMPTR45LH RSCAN0.RMPTR45.UINT8[LH]
#define RSCAN0RMPTR45H RSCAN0.RMPTR45.UINT16[H]
#define RSCAN0RMPTR45HL RSCAN0.RMPTR45.UINT8[HL]
#define RSCAN0RMPTR45HH RSCAN0.RMPTR45.UINT8[HH]
#define RSCAN0RMDF045 RSCAN0.RMDF045.UINT32
#define RSCAN0RMDF045L RSCAN0.RMDF045.UINT16[L]
#define RSCAN0RMDF045LL RSCAN0.RMDF045.UINT8[LL]
#define RSCAN0RMDF045LH RSCAN0.RMDF045.UINT8[LH]
#define RSCAN0RMDF045H RSCAN0.RMDF045.UINT16[H]
#define RSCAN0RMDF045HL RSCAN0.RMDF045.UINT8[HL]
#define RSCAN0RMDF045HH RSCAN0.RMDF045.UINT8[HH]
#define RSCAN0RMDF145 RSCAN0.RMDF145.UINT32
#define RSCAN0RMDF145L RSCAN0.RMDF145.UINT16[L]
#define RSCAN0RMDF145LL RSCAN0.RMDF145.UINT8[LL]
#define RSCAN0RMDF145LH RSCAN0.RMDF145.UINT8[LH]
#define RSCAN0RMDF145H RSCAN0.RMDF145.UINT16[H]
#define RSCAN0RMDF145HL RSCAN0.RMDF145.UINT8[HL]
#define RSCAN0RMDF145HH RSCAN0.RMDF145.UINT8[HH]
#define RSCAN0RMID46 RSCAN0.RMID46.UINT32
#define RSCAN0RMID46L RSCAN0.RMID46.UINT16[L]
#define RSCAN0RMID46LL RSCAN0.RMID46.UINT8[LL]
#define RSCAN0RMID46LH RSCAN0.RMID46.UINT8[LH]
#define RSCAN0RMID46H RSCAN0.RMID46.UINT16[H]
#define RSCAN0RMID46HL RSCAN0.RMID46.UINT8[HL]
#define RSCAN0RMID46HH RSCAN0.RMID46.UINT8[HH]
#define RSCAN0RMPTR46 RSCAN0.RMPTR46.UINT32
#define RSCAN0RMPTR46L RSCAN0.RMPTR46.UINT16[L]
#define RSCAN0RMPTR46LL RSCAN0.RMPTR46.UINT8[LL]
#define RSCAN0RMPTR46LH RSCAN0.RMPTR46.UINT8[LH]
#define RSCAN0RMPTR46H RSCAN0.RMPTR46.UINT16[H]
#define RSCAN0RMPTR46HL RSCAN0.RMPTR46.UINT8[HL]
#define RSCAN0RMPTR46HH RSCAN0.RMPTR46.UINT8[HH]
#define RSCAN0RMDF046 RSCAN0.RMDF046.UINT32
#define RSCAN0RMDF046L RSCAN0.RMDF046.UINT16[L]
#define RSCAN0RMDF046LL RSCAN0.RMDF046.UINT8[LL]
#define RSCAN0RMDF046LH RSCAN0.RMDF046.UINT8[LH]
#define RSCAN0RMDF046H RSCAN0.RMDF046.UINT16[H]
#define RSCAN0RMDF046HL RSCAN0.RMDF046.UINT8[HL]
#define RSCAN0RMDF046HH RSCAN0.RMDF046.UINT8[HH]
#define RSCAN0RMDF146 RSCAN0.RMDF146.UINT32
#define RSCAN0RMDF146L RSCAN0.RMDF146.UINT16[L]
#define RSCAN0RMDF146LL RSCAN0.RMDF146.UINT8[LL]
#define RSCAN0RMDF146LH RSCAN0.RMDF146.UINT8[LH]
#define RSCAN0RMDF146H RSCAN0.RMDF146.UINT16[H]
#define RSCAN0RMDF146HL RSCAN0.RMDF146.UINT8[HL]
#define RSCAN0RMDF146HH RSCAN0.RMDF146.UINT8[HH]
#define RSCAN0RMID47 RSCAN0.RMID47.UINT32
#define RSCAN0RMID47L RSCAN0.RMID47.UINT16[L]
#define RSCAN0RMID47LL RSCAN0.RMID47.UINT8[LL]
#define RSCAN0RMID47LH RSCAN0.RMID47.UINT8[LH]
#define RSCAN0RMID47H RSCAN0.RMID47.UINT16[H]
#define RSCAN0RMID47HL RSCAN0.RMID47.UINT8[HL]
#define RSCAN0RMID47HH RSCAN0.RMID47.UINT8[HH]
#define RSCAN0RMPTR47 RSCAN0.RMPTR47.UINT32
#define RSCAN0RMPTR47L RSCAN0.RMPTR47.UINT16[L]
#define RSCAN0RMPTR47LL RSCAN0.RMPTR47.UINT8[LL]
#define RSCAN0RMPTR47LH RSCAN0.RMPTR47.UINT8[LH]
#define RSCAN0RMPTR47H RSCAN0.RMPTR47.UINT16[H]
#define RSCAN0RMPTR47HL RSCAN0.RMPTR47.UINT8[HL]
#define RSCAN0RMPTR47HH RSCAN0.RMPTR47.UINT8[HH]
#define RSCAN0RMDF047 RSCAN0.RMDF047.UINT32
#define RSCAN0RMDF047L RSCAN0.RMDF047.UINT16[L]
#define RSCAN0RMDF047LL RSCAN0.RMDF047.UINT8[LL]
#define RSCAN0RMDF047LH RSCAN0.RMDF047.UINT8[LH]
#define RSCAN0RMDF047H RSCAN0.RMDF047.UINT16[H]
#define RSCAN0RMDF047HL RSCAN0.RMDF047.UINT8[HL]
#define RSCAN0RMDF047HH RSCAN0.RMDF047.UINT8[HH]
#define RSCAN0RMDF147 RSCAN0.RMDF147.UINT32
#define RSCAN0RMDF147L RSCAN0.RMDF147.UINT16[L]
#define RSCAN0RMDF147LL RSCAN0.RMDF147.UINT8[LL]
#define RSCAN0RMDF147LH RSCAN0.RMDF147.UINT8[LH]
#define RSCAN0RMDF147H RSCAN0.RMDF147.UINT16[H]
#define RSCAN0RMDF147HL RSCAN0.RMDF147.UINT8[HL]
#define RSCAN0RMDF147HH RSCAN0.RMDF147.UINT8[HH]
#define RSCAN0RFID0 RSCAN0.RFID0.UINT32
#define RSCAN0RFID0L RSCAN0.RFID0.UINT16[L]
#define RSCAN0RFID0LL RSCAN0.RFID0.UINT8[LL]
#define RSCAN0RFID0LH RSCAN0.RFID0.UINT8[LH]
#define RSCAN0RFID0H RSCAN0.RFID0.UINT16[H]
#define RSCAN0RFID0HL RSCAN0.RFID0.UINT8[HL]
#define RSCAN0RFID0HH RSCAN0.RFID0.UINT8[HH]
#define RSCAN0RFPTR0 RSCAN0.RFPTR0.UINT32
#define RSCAN0RFPTR0L RSCAN0.RFPTR0.UINT16[L]
#define RSCAN0RFPTR0LL RSCAN0.RFPTR0.UINT8[LL]
#define RSCAN0RFPTR0LH RSCAN0.RFPTR0.UINT8[LH]
#define RSCAN0RFPTR0H RSCAN0.RFPTR0.UINT16[H]
#define RSCAN0RFPTR0HL RSCAN0.RFPTR0.UINT8[HL]
#define RSCAN0RFPTR0HH RSCAN0.RFPTR0.UINT8[HH]
#define RSCAN0RFDF00 RSCAN0.RFDF00.UINT32
#define RSCAN0RFDF00L RSCAN0.RFDF00.UINT16[L]
#define RSCAN0RFDF00LL RSCAN0.RFDF00.UINT8[LL]
#define RSCAN0RFDF00LH RSCAN0.RFDF00.UINT8[LH]
#define RSCAN0RFDF00H RSCAN0.RFDF00.UINT16[H]
#define RSCAN0RFDF00HL RSCAN0.RFDF00.UINT8[HL]
#define RSCAN0RFDF00HH RSCAN0.RFDF00.UINT8[HH]
#define RSCAN0RFDF10 RSCAN0.RFDF10.UINT32
#define RSCAN0RFDF10L RSCAN0.RFDF10.UINT16[L]
#define RSCAN0RFDF10LL RSCAN0.RFDF10.UINT8[LL]
#define RSCAN0RFDF10LH RSCAN0.RFDF10.UINT8[LH]
#define RSCAN0RFDF10H RSCAN0.RFDF10.UINT16[H]
#define RSCAN0RFDF10HL RSCAN0.RFDF10.UINT8[HL]
#define RSCAN0RFDF10HH RSCAN0.RFDF10.UINT8[HH]
#define RSCAN0RFID1 RSCAN0.RFID1.UINT32
#define RSCAN0RFID1L RSCAN0.RFID1.UINT16[L]
#define RSCAN0RFID1LL RSCAN0.RFID1.UINT8[LL]
#define RSCAN0RFID1LH RSCAN0.RFID1.UINT8[LH]
#define RSCAN0RFID1H RSCAN0.RFID1.UINT16[H]
#define RSCAN0RFID1HL RSCAN0.RFID1.UINT8[HL]
#define RSCAN0RFID1HH RSCAN0.RFID1.UINT8[HH]
#define RSCAN0RFPTR1 RSCAN0.RFPTR1.UINT32
#define RSCAN0RFPTR1L RSCAN0.RFPTR1.UINT16[L]
#define RSCAN0RFPTR1LL RSCAN0.RFPTR1.UINT8[LL]
#define RSCAN0RFPTR1LH RSCAN0.RFPTR1.UINT8[LH]
#define RSCAN0RFPTR1H RSCAN0.RFPTR1.UINT16[H]
#define RSCAN0RFPTR1HL RSCAN0.RFPTR1.UINT8[HL]
#define RSCAN0RFPTR1HH RSCAN0.RFPTR1.UINT8[HH]
#define RSCAN0RFDF01 RSCAN0.RFDF01.UINT32
#define RSCAN0RFDF01L RSCAN0.RFDF01.UINT16[L]
#define RSCAN0RFDF01LL RSCAN0.RFDF01.UINT8[LL]
#define RSCAN0RFDF01LH RSCAN0.RFDF01.UINT8[LH]
#define RSCAN0RFDF01H RSCAN0.RFDF01.UINT16[H]
#define RSCAN0RFDF01HL RSCAN0.RFDF01.UINT8[HL]
#define RSCAN0RFDF01HH RSCAN0.RFDF01.UINT8[HH]
#define RSCAN0RFDF11 RSCAN0.RFDF11.UINT32
#define RSCAN0RFDF11L RSCAN0.RFDF11.UINT16[L]
#define RSCAN0RFDF11LL RSCAN0.RFDF11.UINT8[LL]
#define RSCAN0RFDF11LH RSCAN0.RFDF11.UINT8[LH]
#define RSCAN0RFDF11H RSCAN0.RFDF11.UINT16[H]
#define RSCAN0RFDF11HL RSCAN0.RFDF11.UINT8[HL]
#define RSCAN0RFDF11HH RSCAN0.RFDF11.UINT8[HH]
#define RSCAN0RFID2 RSCAN0.RFID2.UINT32
#define RSCAN0RFID2L RSCAN0.RFID2.UINT16[L]
#define RSCAN0RFID2LL RSCAN0.RFID2.UINT8[LL]
#define RSCAN0RFID2LH RSCAN0.RFID2.UINT8[LH]
#define RSCAN0RFID2H RSCAN0.RFID2.UINT16[H]
#define RSCAN0RFID2HL RSCAN0.RFID2.UINT8[HL]
#define RSCAN0RFID2HH RSCAN0.RFID2.UINT8[HH]
#define RSCAN0RFPTR2 RSCAN0.RFPTR2.UINT32
#define RSCAN0RFPTR2L RSCAN0.RFPTR2.UINT16[L]
#define RSCAN0RFPTR2LL RSCAN0.RFPTR2.UINT8[LL]
#define RSCAN0RFPTR2LH RSCAN0.RFPTR2.UINT8[LH]
#define RSCAN0RFPTR2H RSCAN0.RFPTR2.UINT16[H]
#define RSCAN0RFPTR2HL RSCAN0.RFPTR2.UINT8[HL]
#define RSCAN0RFPTR2HH RSCAN0.RFPTR2.UINT8[HH]
#define RSCAN0RFDF02 RSCAN0.RFDF02.UINT32
#define RSCAN0RFDF02L RSCAN0.RFDF02.UINT16[L]
#define RSCAN0RFDF02LL RSCAN0.RFDF02.UINT8[LL]
#define RSCAN0RFDF02LH RSCAN0.RFDF02.UINT8[LH]
#define RSCAN0RFDF02H RSCAN0.RFDF02.UINT16[H]
#define RSCAN0RFDF02HL RSCAN0.RFDF02.UINT8[HL]
#define RSCAN0RFDF02HH RSCAN0.RFDF02.UINT8[HH]
#define RSCAN0RFDF12 RSCAN0.RFDF12.UINT32
#define RSCAN0RFDF12L RSCAN0.RFDF12.UINT16[L]
#define RSCAN0RFDF12LL RSCAN0.RFDF12.UINT8[LL]
#define RSCAN0RFDF12LH RSCAN0.RFDF12.UINT8[LH]
#define RSCAN0RFDF12H RSCAN0.RFDF12.UINT16[H]
#define RSCAN0RFDF12HL RSCAN0.RFDF12.UINT8[HL]
#define RSCAN0RFDF12HH RSCAN0.RFDF12.UINT8[HH]
#define RSCAN0RFID3 RSCAN0.RFID3.UINT32
#define RSCAN0RFID3L RSCAN0.RFID3.UINT16[L]
#define RSCAN0RFID3LL RSCAN0.RFID3.UINT8[LL]
#define RSCAN0RFID3LH RSCAN0.RFID3.UINT8[LH]
#define RSCAN0RFID3H RSCAN0.RFID3.UINT16[H]
#define RSCAN0RFID3HL RSCAN0.RFID3.UINT8[HL]
#define RSCAN0RFID3HH RSCAN0.RFID3.UINT8[HH]
#define RSCAN0RFPTR3 RSCAN0.RFPTR3.UINT32
#define RSCAN0RFPTR3L RSCAN0.RFPTR3.UINT16[L]
#define RSCAN0RFPTR3LL RSCAN0.RFPTR3.UINT8[LL]
#define RSCAN0RFPTR3LH RSCAN0.RFPTR3.UINT8[LH]
#define RSCAN0RFPTR3H RSCAN0.RFPTR3.UINT16[H]
#define RSCAN0RFPTR3HL RSCAN0.RFPTR3.UINT8[HL]
#define RSCAN0RFPTR3HH RSCAN0.RFPTR3.UINT8[HH]
#define RSCAN0RFDF03 RSCAN0.RFDF03.UINT32
#define RSCAN0RFDF03L RSCAN0.RFDF03.UINT16[L]
#define RSCAN0RFDF03LL RSCAN0.RFDF03.UINT8[LL]
#define RSCAN0RFDF03LH RSCAN0.RFDF03.UINT8[LH]
#define RSCAN0RFDF03H RSCAN0.RFDF03.UINT16[H]
#define RSCAN0RFDF03HL RSCAN0.RFDF03.UINT8[HL]
#define RSCAN0RFDF03HH RSCAN0.RFDF03.UINT8[HH]
#define RSCAN0RFDF13 RSCAN0.RFDF13.UINT32
#define RSCAN0RFDF13L RSCAN0.RFDF13.UINT16[L]
#define RSCAN0RFDF13LL RSCAN0.RFDF13.UINT8[LL]
#define RSCAN0RFDF13LH RSCAN0.RFDF13.UINT8[LH]
#define RSCAN0RFDF13H RSCAN0.RFDF13.UINT16[H]
#define RSCAN0RFDF13HL RSCAN0.RFDF13.UINT8[HL]
#define RSCAN0RFDF13HH RSCAN0.RFDF13.UINT8[HH]
#define RSCAN0RFID4 RSCAN0.RFID4.UINT32
#define RSCAN0RFID4L RSCAN0.RFID4.UINT16[L]
#define RSCAN0RFID4LL RSCAN0.RFID4.UINT8[LL]
#define RSCAN0RFID4LH RSCAN0.RFID4.UINT8[LH]
#define RSCAN0RFID4H RSCAN0.RFID4.UINT16[H]
#define RSCAN0RFID4HL RSCAN0.RFID4.UINT8[HL]
#define RSCAN0RFID4HH RSCAN0.RFID4.UINT8[HH]
#define RSCAN0RFPTR4 RSCAN0.RFPTR4.UINT32
#define RSCAN0RFPTR4L RSCAN0.RFPTR4.UINT16[L]
#define RSCAN0RFPTR4LL RSCAN0.RFPTR4.UINT8[LL]
#define RSCAN0RFPTR4LH RSCAN0.RFPTR4.UINT8[LH]
#define RSCAN0RFPTR4H RSCAN0.RFPTR4.UINT16[H]
#define RSCAN0RFPTR4HL RSCAN0.RFPTR4.UINT8[HL]
#define RSCAN0RFPTR4HH RSCAN0.RFPTR4.UINT8[HH]
#define RSCAN0RFDF04 RSCAN0.RFDF04.UINT32
#define RSCAN0RFDF04L RSCAN0.RFDF04.UINT16[L]
#define RSCAN0RFDF04LL RSCAN0.RFDF04.UINT8[LL]
#define RSCAN0RFDF04LH RSCAN0.RFDF04.UINT8[LH]
#define RSCAN0RFDF04H RSCAN0.RFDF04.UINT16[H]
#define RSCAN0RFDF04HL RSCAN0.RFDF04.UINT8[HL]
#define RSCAN0RFDF04HH RSCAN0.RFDF04.UINT8[HH]
#define RSCAN0RFDF14 RSCAN0.RFDF14.UINT32
#define RSCAN0RFDF14L RSCAN0.RFDF14.UINT16[L]
#define RSCAN0RFDF14LL RSCAN0.RFDF14.UINT8[LL]
#define RSCAN0RFDF14LH RSCAN0.RFDF14.UINT8[LH]
#define RSCAN0RFDF14H RSCAN0.RFDF14.UINT16[H]
#define RSCAN0RFDF14HL RSCAN0.RFDF14.UINT8[HL]
#define RSCAN0RFDF14HH RSCAN0.RFDF14.UINT8[HH]
#define RSCAN0RFID5 RSCAN0.RFID5.UINT32
#define RSCAN0RFID5L RSCAN0.RFID5.UINT16[L]
#define RSCAN0RFID5LL RSCAN0.RFID5.UINT8[LL]
#define RSCAN0RFID5LH RSCAN0.RFID5.UINT8[LH]
#define RSCAN0RFID5H RSCAN0.RFID5.UINT16[H]
#define RSCAN0RFID5HL RSCAN0.RFID5.UINT8[HL]
#define RSCAN0RFID5HH RSCAN0.RFID5.UINT8[HH]
#define RSCAN0RFPTR5 RSCAN0.RFPTR5.UINT32
#define RSCAN0RFPTR5L RSCAN0.RFPTR5.UINT16[L]
#define RSCAN0RFPTR5LL RSCAN0.RFPTR5.UINT8[LL]
#define RSCAN0RFPTR5LH RSCAN0.RFPTR5.UINT8[LH]
#define RSCAN0RFPTR5H RSCAN0.RFPTR5.UINT16[H]
#define RSCAN0RFPTR5HL RSCAN0.RFPTR5.UINT8[HL]
#define RSCAN0RFPTR5HH RSCAN0.RFPTR5.UINT8[HH]
#define RSCAN0RFDF05 RSCAN0.RFDF05.UINT32
#define RSCAN0RFDF05L RSCAN0.RFDF05.UINT16[L]
#define RSCAN0RFDF05LL RSCAN0.RFDF05.UINT8[LL]
#define RSCAN0RFDF05LH RSCAN0.RFDF05.UINT8[LH]
#define RSCAN0RFDF05H RSCAN0.RFDF05.UINT16[H]
#define RSCAN0RFDF05HL RSCAN0.RFDF05.UINT8[HL]
#define RSCAN0RFDF05HH RSCAN0.RFDF05.UINT8[HH]
#define RSCAN0RFDF15 RSCAN0.RFDF15.UINT32
#define RSCAN0RFDF15L RSCAN0.RFDF15.UINT16[L]
#define RSCAN0RFDF15LL RSCAN0.RFDF15.UINT8[LL]
#define RSCAN0RFDF15LH RSCAN0.RFDF15.UINT8[LH]
#define RSCAN0RFDF15H RSCAN0.RFDF15.UINT16[H]
#define RSCAN0RFDF15HL RSCAN0.RFDF15.UINT8[HL]
#define RSCAN0RFDF15HH RSCAN0.RFDF15.UINT8[HH]
#define RSCAN0RFID6 RSCAN0.RFID6.UINT32
#define RSCAN0RFID6L RSCAN0.RFID6.UINT16[L]
#define RSCAN0RFID6LL RSCAN0.RFID6.UINT8[LL]
#define RSCAN0RFID6LH RSCAN0.RFID6.UINT8[LH]
#define RSCAN0RFID6H RSCAN0.RFID6.UINT16[H]
#define RSCAN0RFID6HL RSCAN0.RFID6.UINT8[HL]
#define RSCAN0RFID6HH RSCAN0.RFID6.UINT8[HH]
#define RSCAN0RFPTR6 RSCAN0.RFPTR6.UINT32
#define RSCAN0RFPTR6L RSCAN0.RFPTR6.UINT16[L]
#define RSCAN0RFPTR6LL RSCAN0.RFPTR6.UINT8[LL]
#define RSCAN0RFPTR6LH RSCAN0.RFPTR6.UINT8[LH]
#define RSCAN0RFPTR6H RSCAN0.RFPTR6.UINT16[H]
#define RSCAN0RFPTR6HL RSCAN0.RFPTR6.UINT8[HL]
#define RSCAN0RFPTR6HH RSCAN0.RFPTR6.UINT8[HH]
#define RSCAN0RFDF06 RSCAN0.RFDF06.UINT32
#define RSCAN0RFDF06L RSCAN0.RFDF06.UINT16[L]
#define RSCAN0RFDF06LL RSCAN0.RFDF06.UINT8[LL]
#define RSCAN0RFDF06LH RSCAN0.RFDF06.UINT8[LH]
#define RSCAN0RFDF06H RSCAN0.RFDF06.UINT16[H]
#define RSCAN0RFDF06HL RSCAN0.RFDF06.UINT8[HL]
#define RSCAN0RFDF06HH RSCAN0.RFDF06.UINT8[HH]
#define RSCAN0RFDF16 RSCAN0.RFDF16.UINT32
#define RSCAN0RFDF16L RSCAN0.RFDF16.UINT16[L]
#define RSCAN0RFDF16LL RSCAN0.RFDF16.UINT8[LL]
#define RSCAN0RFDF16LH RSCAN0.RFDF16.UINT8[LH]
#define RSCAN0RFDF16H RSCAN0.RFDF16.UINT16[H]
#define RSCAN0RFDF16HL RSCAN0.RFDF16.UINT8[HL]
#define RSCAN0RFDF16HH RSCAN0.RFDF16.UINT8[HH]
#define RSCAN0RFID7 RSCAN0.RFID7.UINT32
#define RSCAN0RFID7L RSCAN0.RFID7.UINT16[L]
#define RSCAN0RFID7LL RSCAN0.RFID7.UINT8[LL]
#define RSCAN0RFID7LH RSCAN0.RFID7.UINT8[LH]
#define RSCAN0RFID7H RSCAN0.RFID7.UINT16[H]
#define RSCAN0RFID7HL RSCAN0.RFID7.UINT8[HL]
#define RSCAN0RFID7HH RSCAN0.RFID7.UINT8[HH]
#define RSCAN0RFPTR7 RSCAN0.RFPTR7.UINT32
#define RSCAN0RFPTR7L RSCAN0.RFPTR7.UINT16[L]
#define RSCAN0RFPTR7LL RSCAN0.RFPTR7.UINT8[LL]
#define RSCAN0RFPTR7LH RSCAN0.RFPTR7.UINT8[LH]
#define RSCAN0RFPTR7H RSCAN0.RFPTR7.UINT16[H]
#define RSCAN0RFPTR7HL RSCAN0.RFPTR7.UINT8[HL]
#define RSCAN0RFPTR7HH RSCAN0.RFPTR7.UINT8[HH]
#define RSCAN0RFDF07 RSCAN0.RFDF07.UINT32
#define RSCAN0RFDF07L RSCAN0.RFDF07.UINT16[L]
#define RSCAN0RFDF07LL RSCAN0.RFDF07.UINT8[LL]
#define RSCAN0RFDF07LH RSCAN0.RFDF07.UINT8[LH]
#define RSCAN0RFDF07H RSCAN0.RFDF07.UINT16[H]
#define RSCAN0RFDF07HL RSCAN0.RFDF07.UINT8[HL]
#define RSCAN0RFDF07HH RSCAN0.RFDF07.UINT8[HH]
#define RSCAN0RFDF17 RSCAN0.RFDF17.UINT32
#define RSCAN0RFDF17L RSCAN0.RFDF17.UINT16[L]
#define RSCAN0RFDF17LL RSCAN0.RFDF17.UINT8[LL]
#define RSCAN0RFDF17LH RSCAN0.RFDF17.UINT8[LH]
#define RSCAN0RFDF17H RSCAN0.RFDF17.UINT16[H]
#define RSCAN0RFDF17HL RSCAN0.RFDF17.UINT8[HL]
#define RSCAN0RFDF17HH RSCAN0.RFDF17.UINT8[HH]
#define RSCAN0CFID0 RSCAN0.CFID0.UINT32
#define RSCAN0CFID0L RSCAN0.CFID0.UINT16[L]
#define RSCAN0CFID0LL RSCAN0.CFID0.UINT8[LL]
#define RSCAN0CFID0LH RSCAN0.CFID0.UINT8[LH]
#define RSCAN0CFID0H RSCAN0.CFID0.UINT16[H]
#define RSCAN0CFID0HL RSCAN0.CFID0.UINT8[HL]
#define RSCAN0CFID0HH RSCAN0.CFID0.UINT8[HH]
#define RSCAN0CFPTR0 RSCAN0.CFPTR0.UINT32
#define RSCAN0CFPTR0L RSCAN0.CFPTR0.UINT16[L]
#define RSCAN0CFPTR0LL RSCAN0.CFPTR0.UINT8[LL]
#define RSCAN0CFPTR0LH RSCAN0.CFPTR0.UINT8[LH]
#define RSCAN0CFPTR0H RSCAN0.CFPTR0.UINT16[H]
#define RSCAN0CFPTR0HL RSCAN0.CFPTR0.UINT8[HL]
#define RSCAN0CFPTR0HH RSCAN0.CFPTR0.UINT8[HH]
#define RSCAN0CFDF00 RSCAN0.CFDF00.UINT32
#define RSCAN0CFDF00L RSCAN0.CFDF00.UINT16[L]
#define RSCAN0CFDF00LL RSCAN0.CFDF00.UINT8[LL]
#define RSCAN0CFDF00LH RSCAN0.CFDF00.UINT8[LH]
#define RSCAN0CFDF00H RSCAN0.CFDF00.UINT16[H]
#define RSCAN0CFDF00HL RSCAN0.CFDF00.UINT8[HL]
#define RSCAN0CFDF00HH RSCAN0.CFDF00.UINT8[HH]
#define RSCAN0CFDF10 RSCAN0.CFDF10.UINT32
#define RSCAN0CFDF10L RSCAN0.CFDF10.UINT16[L]
#define RSCAN0CFDF10LL RSCAN0.CFDF10.UINT8[LL]
#define RSCAN0CFDF10LH RSCAN0.CFDF10.UINT8[LH]
#define RSCAN0CFDF10H RSCAN0.CFDF10.UINT16[H]
#define RSCAN0CFDF10HL RSCAN0.CFDF10.UINT8[HL]
#define RSCAN0CFDF10HH RSCAN0.CFDF10.UINT8[HH]
#define RSCAN0CFID1 RSCAN0.CFID1.UINT32
#define RSCAN0CFID1L RSCAN0.CFID1.UINT16[L]
#define RSCAN0CFID1LL RSCAN0.CFID1.UINT8[LL]
#define RSCAN0CFID1LH RSCAN0.CFID1.UINT8[LH]
#define RSCAN0CFID1H RSCAN0.CFID1.UINT16[H]
#define RSCAN0CFID1HL RSCAN0.CFID1.UINT8[HL]
#define RSCAN0CFID1HH RSCAN0.CFID1.UINT8[HH]
#define RSCAN0CFPTR1 RSCAN0.CFPTR1.UINT32
#define RSCAN0CFPTR1L RSCAN0.CFPTR1.UINT16[L]
#define RSCAN0CFPTR1LL RSCAN0.CFPTR1.UINT8[LL]
#define RSCAN0CFPTR1LH RSCAN0.CFPTR1.UINT8[LH]
#define RSCAN0CFPTR1H RSCAN0.CFPTR1.UINT16[H]
#define RSCAN0CFPTR1HL RSCAN0.CFPTR1.UINT8[HL]
#define RSCAN0CFPTR1HH RSCAN0.CFPTR1.UINT8[HH]
#define RSCAN0CFDF01 RSCAN0.CFDF01.UINT32
#define RSCAN0CFDF01L RSCAN0.CFDF01.UINT16[L]
#define RSCAN0CFDF01LL RSCAN0.CFDF01.UINT8[LL]
#define RSCAN0CFDF01LH RSCAN0.CFDF01.UINT8[LH]
#define RSCAN0CFDF01H RSCAN0.CFDF01.UINT16[H]
#define RSCAN0CFDF01HL RSCAN0.CFDF01.UINT8[HL]
#define RSCAN0CFDF01HH RSCAN0.CFDF01.UINT8[HH]
#define RSCAN0CFDF11 RSCAN0.CFDF11.UINT32
#define RSCAN0CFDF11L RSCAN0.CFDF11.UINT16[L]
#define RSCAN0CFDF11LL RSCAN0.CFDF11.UINT8[LL]
#define RSCAN0CFDF11LH RSCAN0.CFDF11.UINT8[LH]
#define RSCAN0CFDF11H RSCAN0.CFDF11.UINT16[H]
#define RSCAN0CFDF11HL RSCAN0.CFDF11.UINT8[HL]
#define RSCAN0CFDF11HH RSCAN0.CFDF11.UINT8[HH]
#define RSCAN0CFID2 RSCAN0.CFID2.UINT32
#define RSCAN0CFID2L RSCAN0.CFID2.UINT16[L]
#define RSCAN0CFID2LL RSCAN0.CFID2.UINT8[LL]
#define RSCAN0CFID2LH RSCAN0.CFID2.UINT8[LH]
#define RSCAN0CFID2H RSCAN0.CFID2.UINT16[H]
#define RSCAN0CFID2HL RSCAN0.CFID2.UINT8[HL]
#define RSCAN0CFID2HH RSCAN0.CFID2.UINT8[HH]
#define RSCAN0CFPTR2 RSCAN0.CFPTR2.UINT32
#define RSCAN0CFPTR2L RSCAN0.CFPTR2.UINT16[L]
#define RSCAN0CFPTR2LL RSCAN0.CFPTR2.UINT8[LL]
#define RSCAN0CFPTR2LH RSCAN0.CFPTR2.UINT8[LH]
#define RSCAN0CFPTR2H RSCAN0.CFPTR2.UINT16[H]
#define RSCAN0CFPTR2HL RSCAN0.CFPTR2.UINT8[HL]
#define RSCAN0CFPTR2HH RSCAN0.CFPTR2.UINT8[HH]
#define RSCAN0CFDF02 RSCAN0.CFDF02.UINT32
#define RSCAN0CFDF02L RSCAN0.CFDF02.UINT16[L]
#define RSCAN0CFDF02LL RSCAN0.CFDF02.UINT8[LL]
#define RSCAN0CFDF02LH RSCAN0.CFDF02.UINT8[LH]
#define RSCAN0CFDF02H RSCAN0.CFDF02.UINT16[H]
#define RSCAN0CFDF02HL RSCAN0.CFDF02.UINT8[HL]
#define RSCAN0CFDF02HH RSCAN0.CFDF02.UINT8[HH]
#define RSCAN0CFDF12 RSCAN0.CFDF12.UINT32
#define RSCAN0CFDF12L RSCAN0.CFDF12.UINT16[L]
#define RSCAN0CFDF12LL RSCAN0.CFDF12.UINT8[LL]
#define RSCAN0CFDF12LH RSCAN0.CFDF12.UINT8[LH]
#define RSCAN0CFDF12H RSCAN0.CFDF12.UINT16[H]
#define RSCAN0CFDF12HL RSCAN0.CFDF12.UINT8[HL]
#define RSCAN0CFDF12HH RSCAN0.CFDF12.UINT8[HH]
#define RSCAN0CFID3 RSCAN0.CFID3.UINT32
#define RSCAN0CFID3L RSCAN0.CFID3.UINT16[L]
#define RSCAN0CFID3LL RSCAN0.CFID3.UINT8[LL]
#define RSCAN0CFID3LH RSCAN0.CFID3.UINT8[LH]
#define RSCAN0CFID3H RSCAN0.CFID3.UINT16[H]
#define RSCAN0CFID3HL RSCAN0.CFID3.UINT8[HL]
#define RSCAN0CFID3HH RSCAN0.CFID3.UINT8[HH]
#define RSCAN0CFPTR3 RSCAN0.CFPTR3.UINT32
#define RSCAN0CFPTR3L RSCAN0.CFPTR3.UINT16[L]
#define RSCAN0CFPTR3LL RSCAN0.CFPTR3.UINT8[LL]
#define RSCAN0CFPTR3LH RSCAN0.CFPTR3.UINT8[LH]
#define RSCAN0CFPTR3H RSCAN0.CFPTR3.UINT16[H]
#define RSCAN0CFPTR3HL RSCAN0.CFPTR3.UINT8[HL]
#define RSCAN0CFPTR3HH RSCAN0.CFPTR3.UINT8[HH]
#define RSCAN0CFDF03 RSCAN0.CFDF03.UINT32
#define RSCAN0CFDF03L RSCAN0.CFDF03.UINT16[L]
#define RSCAN0CFDF03LL RSCAN0.CFDF03.UINT8[LL]
#define RSCAN0CFDF03LH RSCAN0.CFDF03.UINT8[LH]
#define RSCAN0CFDF03H RSCAN0.CFDF03.UINT16[H]
#define RSCAN0CFDF03HL RSCAN0.CFDF03.UINT8[HL]
#define RSCAN0CFDF03HH RSCAN0.CFDF03.UINT8[HH]
#define RSCAN0CFDF13 RSCAN0.CFDF13.UINT32
#define RSCAN0CFDF13L RSCAN0.CFDF13.UINT16[L]
#define RSCAN0CFDF13LL RSCAN0.CFDF13.UINT8[LL]
#define RSCAN0CFDF13LH RSCAN0.CFDF13.UINT8[LH]
#define RSCAN0CFDF13H RSCAN0.CFDF13.UINT16[H]
#define RSCAN0CFDF13HL RSCAN0.CFDF13.UINT8[HL]
#define RSCAN0CFDF13HH RSCAN0.CFDF13.UINT8[HH]
#define RSCAN0CFID4 RSCAN0.CFID4.UINT32
#define RSCAN0CFID4L RSCAN0.CFID4.UINT16[L]
#define RSCAN0CFID4LL RSCAN0.CFID4.UINT8[LL]
#define RSCAN0CFID4LH RSCAN0.CFID4.UINT8[LH]
#define RSCAN0CFID4H RSCAN0.CFID4.UINT16[H]
#define RSCAN0CFID4HL RSCAN0.CFID4.UINT8[HL]
#define RSCAN0CFID4HH RSCAN0.CFID4.UINT8[HH]
#define RSCAN0CFPTR4 RSCAN0.CFPTR4.UINT32
#define RSCAN0CFPTR4L RSCAN0.CFPTR4.UINT16[L]
#define RSCAN0CFPTR4LL RSCAN0.CFPTR4.UINT8[LL]
#define RSCAN0CFPTR4LH RSCAN0.CFPTR4.UINT8[LH]
#define RSCAN0CFPTR4H RSCAN0.CFPTR4.UINT16[H]
#define RSCAN0CFPTR4HL RSCAN0.CFPTR4.UINT8[HL]
#define RSCAN0CFPTR4HH RSCAN0.CFPTR4.UINT8[HH]
#define RSCAN0CFDF04 RSCAN0.CFDF04.UINT32
#define RSCAN0CFDF04L RSCAN0.CFDF04.UINT16[L]
#define RSCAN0CFDF04LL RSCAN0.CFDF04.UINT8[LL]
#define RSCAN0CFDF04LH RSCAN0.CFDF04.UINT8[LH]
#define RSCAN0CFDF04H RSCAN0.CFDF04.UINT16[H]
#define RSCAN0CFDF04HL RSCAN0.CFDF04.UINT8[HL]
#define RSCAN0CFDF04HH RSCAN0.CFDF04.UINT8[HH]
#define RSCAN0CFDF14 RSCAN0.CFDF14.UINT32
#define RSCAN0CFDF14L RSCAN0.CFDF14.UINT16[L]
#define RSCAN0CFDF14LL RSCAN0.CFDF14.UINT8[LL]
#define RSCAN0CFDF14LH RSCAN0.CFDF14.UINT8[LH]
#define RSCAN0CFDF14H RSCAN0.CFDF14.UINT16[H]
#define RSCAN0CFDF14HL RSCAN0.CFDF14.UINT8[HL]
#define RSCAN0CFDF14HH RSCAN0.CFDF14.UINT8[HH]
#define RSCAN0CFID5 RSCAN0.CFID5.UINT32
#define RSCAN0CFID5L RSCAN0.CFID5.UINT16[L]
#define RSCAN0CFID5LL RSCAN0.CFID5.UINT8[LL]
#define RSCAN0CFID5LH RSCAN0.CFID5.UINT8[LH]
#define RSCAN0CFID5H RSCAN0.CFID5.UINT16[H]
#define RSCAN0CFID5HL RSCAN0.CFID5.UINT8[HL]
#define RSCAN0CFID5HH RSCAN0.CFID5.UINT8[HH]
#define RSCAN0CFPTR5 RSCAN0.CFPTR5.UINT32
#define RSCAN0CFPTR5L RSCAN0.CFPTR5.UINT16[L]
#define RSCAN0CFPTR5LL RSCAN0.CFPTR5.UINT8[LL]
#define RSCAN0CFPTR5LH RSCAN0.CFPTR5.UINT8[LH]
#define RSCAN0CFPTR5H RSCAN0.CFPTR5.UINT16[H]
#define RSCAN0CFPTR5HL RSCAN0.CFPTR5.UINT8[HL]
#define RSCAN0CFPTR5HH RSCAN0.CFPTR5.UINT8[HH]
#define RSCAN0CFDF05 RSCAN0.CFDF05.UINT32
#define RSCAN0CFDF05L RSCAN0.CFDF05.UINT16[L]
#define RSCAN0CFDF05LL RSCAN0.CFDF05.UINT8[LL]
#define RSCAN0CFDF05LH RSCAN0.CFDF05.UINT8[LH]
#define RSCAN0CFDF05H RSCAN0.CFDF05.UINT16[H]
#define RSCAN0CFDF05HL RSCAN0.CFDF05.UINT8[HL]
#define RSCAN0CFDF05HH RSCAN0.CFDF05.UINT8[HH]
#define RSCAN0CFDF15 RSCAN0.CFDF15.UINT32
#define RSCAN0CFDF15L RSCAN0.CFDF15.UINT16[L]
#define RSCAN0CFDF15LL RSCAN0.CFDF15.UINT8[LL]
#define RSCAN0CFDF15LH RSCAN0.CFDF15.UINT8[LH]
#define RSCAN0CFDF15H RSCAN0.CFDF15.UINT16[H]
#define RSCAN0CFDF15HL RSCAN0.CFDF15.UINT8[HL]
#define RSCAN0CFDF15HH RSCAN0.CFDF15.UINT8[HH]
#define RSCAN0CFID6 RSCAN0.CFID6.UINT32
#define RSCAN0CFID6L RSCAN0.CFID6.UINT16[L]
#define RSCAN0CFID6LL RSCAN0.CFID6.UINT8[LL]
#define RSCAN0CFID6LH RSCAN0.CFID6.UINT8[LH]
#define RSCAN0CFID6H RSCAN0.CFID6.UINT16[H]
#define RSCAN0CFID6HL RSCAN0.CFID6.UINT8[HL]
#define RSCAN0CFID6HH RSCAN0.CFID6.UINT8[HH]
#define RSCAN0CFPTR6 RSCAN0.CFPTR6.UINT32
#define RSCAN0CFPTR6L RSCAN0.CFPTR6.UINT16[L]
#define RSCAN0CFPTR6LL RSCAN0.CFPTR6.UINT8[LL]
#define RSCAN0CFPTR6LH RSCAN0.CFPTR6.UINT8[LH]
#define RSCAN0CFPTR6H RSCAN0.CFPTR6.UINT16[H]
#define RSCAN0CFPTR6HL RSCAN0.CFPTR6.UINT8[HL]
#define RSCAN0CFPTR6HH RSCAN0.CFPTR6.UINT8[HH]
#define RSCAN0CFDF06 RSCAN0.CFDF06.UINT32
#define RSCAN0CFDF06L RSCAN0.CFDF06.UINT16[L]
#define RSCAN0CFDF06LL RSCAN0.CFDF06.UINT8[LL]
#define RSCAN0CFDF06LH RSCAN0.CFDF06.UINT8[LH]
#define RSCAN0CFDF06H RSCAN0.CFDF06.UINT16[H]
#define RSCAN0CFDF06HL RSCAN0.CFDF06.UINT8[HL]
#define RSCAN0CFDF06HH RSCAN0.CFDF06.UINT8[HH]
#define RSCAN0CFDF16 RSCAN0.CFDF16.UINT32
#define RSCAN0CFDF16L RSCAN0.CFDF16.UINT16[L]
#define RSCAN0CFDF16LL RSCAN0.CFDF16.UINT8[LL]
#define RSCAN0CFDF16LH RSCAN0.CFDF16.UINT8[LH]
#define RSCAN0CFDF16H RSCAN0.CFDF16.UINT16[H]
#define RSCAN0CFDF16HL RSCAN0.CFDF16.UINT8[HL]
#define RSCAN0CFDF16HH RSCAN0.CFDF16.UINT8[HH]
#define RSCAN0CFID7 RSCAN0.CFID7.UINT32
#define RSCAN0CFID7L RSCAN0.CFID7.UINT16[L]
#define RSCAN0CFID7LL RSCAN0.CFID7.UINT8[LL]
#define RSCAN0CFID7LH RSCAN0.CFID7.UINT8[LH]
#define RSCAN0CFID7H RSCAN0.CFID7.UINT16[H]
#define RSCAN0CFID7HL RSCAN0.CFID7.UINT8[HL]
#define RSCAN0CFID7HH RSCAN0.CFID7.UINT8[HH]
#define RSCAN0CFPTR7 RSCAN0.CFPTR7.UINT32
#define RSCAN0CFPTR7L RSCAN0.CFPTR7.UINT16[L]
#define RSCAN0CFPTR7LL RSCAN0.CFPTR7.UINT8[LL]
#define RSCAN0CFPTR7LH RSCAN0.CFPTR7.UINT8[LH]
#define RSCAN0CFPTR7H RSCAN0.CFPTR7.UINT16[H]
#define RSCAN0CFPTR7HL RSCAN0.CFPTR7.UINT8[HL]
#define RSCAN0CFPTR7HH RSCAN0.CFPTR7.UINT8[HH]
#define RSCAN0CFDF07 RSCAN0.CFDF07.UINT32
#define RSCAN0CFDF07L RSCAN0.CFDF07.UINT16[L]
#define RSCAN0CFDF07LL RSCAN0.CFDF07.UINT8[LL]
#define RSCAN0CFDF07LH RSCAN0.CFDF07.UINT8[LH]
#define RSCAN0CFDF07H RSCAN0.CFDF07.UINT16[H]
#define RSCAN0CFDF07HL RSCAN0.CFDF07.UINT8[HL]
#define RSCAN0CFDF07HH RSCAN0.CFDF07.UINT8[HH]
#define RSCAN0CFDF17 RSCAN0.CFDF17.UINT32
#define RSCAN0CFDF17L RSCAN0.CFDF17.UINT16[L]
#define RSCAN0CFDF17LL RSCAN0.CFDF17.UINT8[LL]
#define RSCAN0CFDF17LH RSCAN0.CFDF17.UINT8[LH]
#define RSCAN0CFDF17H RSCAN0.CFDF17.UINT16[H]
#define RSCAN0CFDF17HL RSCAN0.CFDF17.UINT8[HL]
#define RSCAN0CFDF17HH RSCAN0.CFDF17.UINT8[HH]
#define RSCAN0CFID8 RSCAN0.CFID8.UINT32
#define RSCAN0CFID8L RSCAN0.CFID8.UINT16[L]
#define RSCAN0CFID8LL RSCAN0.CFID8.UINT8[LL]
#define RSCAN0CFID8LH RSCAN0.CFID8.UINT8[LH]
#define RSCAN0CFID8H RSCAN0.CFID8.UINT16[H]
#define RSCAN0CFID8HL RSCAN0.CFID8.UINT8[HL]
#define RSCAN0CFID8HH RSCAN0.CFID8.UINT8[HH]
#define RSCAN0CFPTR8 RSCAN0.CFPTR8.UINT32
#define RSCAN0CFPTR8L RSCAN0.CFPTR8.UINT16[L]
#define RSCAN0CFPTR8LL RSCAN0.CFPTR8.UINT8[LL]
#define RSCAN0CFPTR8LH RSCAN0.CFPTR8.UINT8[LH]
#define RSCAN0CFPTR8H RSCAN0.CFPTR8.UINT16[H]
#define RSCAN0CFPTR8HL RSCAN0.CFPTR8.UINT8[HL]
#define RSCAN0CFPTR8HH RSCAN0.CFPTR8.UINT8[HH]
#define RSCAN0CFDF08 RSCAN0.CFDF08.UINT32
#define RSCAN0CFDF08L RSCAN0.CFDF08.UINT16[L]
#define RSCAN0CFDF08LL RSCAN0.CFDF08.UINT8[LL]
#define RSCAN0CFDF08LH RSCAN0.CFDF08.UINT8[LH]
#define RSCAN0CFDF08H RSCAN0.CFDF08.UINT16[H]
#define RSCAN0CFDF08HL RSCAN0.CFDF08.UINT8[HL]
#define RSCAN0CFDF08HH RSCAN0.CFDF08.UINT8[HH]
#define RSCAN0CFDF18 RSCAN0.CFDF18.UINT32
#define RSCAN0CFDF18L RSCAN0.CFDF18.UINT16[L]
#define RSCAN0CFDF18LL RSCAN0.CFDF18.UINT8[LL]
#define RSCAN0CFDF18LH RSCAN0.CFDF18.UINT8[LH]
#define RSCAN0CFDF18H RSCAN0.CFDF18.UINT16[H]
#define RSCAN0CFDF18HL RSCAN0.CFDF18.UINT8[HL]
#define RSCAN0CFDF18HH RSCAN0.CFDF18.UINT8[HH]
#define RSCAN0TMID0 RSCAN0.TMID0.UINT32
#define RSCAN0TMID0L RSCAN0.TMID0.UINT16[L]
#define RSCAN0TMID0LL RSCAN0.TMID0.UINT8[LL]
#define RSCAN0TMID0LH RSCAN0.TMID0.UINT8[LH]
#define RSCAN0TMID0H RSCAN0.TMID0.UINT16[H]
#define RSCAN0TMID0HL RSCAN0.TMID0.UINT8[HL]
#define RSCAN0TMID0HH RSCAN0.TMID0.UINT8[HH]
#define RSCAN0TMPTR0 RSCAN0.TMPTR0.UINT32
#define RSCAN0TMPTR0L RSCAN0.TMPTR0.UINT16[L]
#define RSCAN0TMPTR0LL RSCAN0.TMPTR0.UINT8[LL]
#define RSCAN0TMPTR0LH RSCAN0.TMPTR0.UINT8[LH]
#define RSCAN0TMPTR0H RSCAN0.TMPTR0.UINT16[H]
#define RSCAN0TMPTR0HL RSCAN0.TMPTR0.UINT8[HL]
#define RSCAN0TMPTR0HH RSCAN0.TMPTR0.UINT8[HH]
#define RSCAN0TMDF00 RSCAN0.TMDF00.UINT32
#define RSCAN0TMDF00L RSCAN0.TMDF00.UINT16[L]
#define RSCAN0TMDF00LL RSCAN0.TMDF00.UINT8[LL]
#define RSCAN0TMDF00LH RSCAN0.TMDF00.UINT8[LH]
#define RSCAN0TMDF00H RSCAN0.TMDF00.UINT16[H]
#define RSCAN0TMDF00HL RSCAN0.TMDF00.UINT8[HL]
#define RSCAN0TMDF00HH RSCAN0.TMDF00.UINT8[HH]
#define RSCAN0TMDF10 RSCAN0.TMDF10.UINT32
#define RSCAN0TMDF10L RSCAN0.TMDF10.UINT16[L]
#define RSCAN0TMDF10LL RSCAN0.TMDF10.UINT8[LL]
#define RSCAN0TMDF10LH RSCAN0.TMDF10.UINT8[LH]
#define RSCAN0TMDF10H RSCAN0.TMDF10.UINT16[H]
#define RSCAN0TMDF10HL RSCAN0.TMDF10.UINT8[HL]
#define RSCAN0TMDF10HH RSCAN0.TMDF10.UINT8[HH]
#define RSCAN0TMID1 RSCAN0.TMID1.UINT32
#define RSCAN0TMID1L RSCAN0.TMID1.UINT16[L]
#define RSCAN0TMID1LL RSCAN0.TMID1.UINT8[LL]
#define RSCAN0TMID1LH RSCAN0.TMID1.UINT8[LH]
#define RSCAN0TMID1H RSCAN0.TMID1.UINT16[H]
#define RSCAN0TMID1HL RSCAN0.TMID1.UINT8[HL]
#define RSCAN0TMID1HH RSCAN0.TMID1.UINT8[HH]
#define RSCAN0TMPTR1 RSCAN0.TMPTR1.UINT32
#define RSCAN0TMPTR1L RSCAN0.TMPTR1.UINT16[L]
#define RSCAN0TMPTR1LL RSCAN0.TMPTR1.UINT8[LL]
#define RSCAN0TMPTR1LH RSCAN0.TMPTR1.UINT8[LH]
#define RSCAN0TMPTR1H RSCAN0.TMPTR1.UINT16[H]
#define RSCAN0TMPTR1HL RSCAN0.TMPTR1.UINT8[HL]
#define RSCAN0TMPTR1HH RSCAN0.TMPTR1.UINT8[HH]
#define RSCAN0TMDF01 RSCAN0.TMDF01.UINT32
#define RSCAN0TMDF01L RSCAN0.TMDF01.UINT16[L]
#define RSCAN0TMDF01LL RSCAN0.TMDF01.UINT8[LL]
#define RSCAN0TMDF01LH RSCAN0.TMDF01.UINT8[LH]
#define RSCAN0TMDF01H RSCAN0.TMDF01.UINT16[H]
#define RSCAN0TMDF01HL RSCAN0.TMDF01.UINT8[HL]
#define RSCAN0TMDF01HH RSCAN0.TMDF01.UINT8[HH]
#define RSCAN0TMDF11 RSCAN0.TMDF11.UINT32
#define RSCAN0TMDF11L RSCAN0.TMDF11.UINT16[L]
#define RSCAN0TMDF11LL RSCAN0.TMDF11.UINT8[LL]
#define RSCAN0TMDF11LH RSCAN0.TMDF11.UINT8[LH]
#define RSCAN0TMDF11H RSCAN0.TMDF11.UINT16[H]
#define RSCAN0TMDF11HL RSCAN0.TMDF11.UINT8[HL]
#define RSCAN0TMDF11HH RSCAN0.TMDF11.UINT8[HH]
#define RSCAN0TMID2 RSCAN0.TMID2.UINT32
#define RSCAN0TMID2L RSCAN0.TMID2.UINT16[L]
#define RSCAN0TMID2LL RSCAN0.TMID2.UINT8[LL]
#define RSCAN0TMID2LH RSCAN0.TMID2.UINT8[LH]
#define RSCAN0TMID2H RSCAN0.TMID2.UINT16[H]
#define RSCAN0TMID2HL RSCAN0.TMID2.UINT8[HL]
#define RSCAN0TMID2HH RSCAN0.TMID2.UINT8[HH]
#define RSCAN0TMPTR2 RSCAN0.TMPTR2.UINT32
#define RSCAN0TMPTR2L RSCAN0.TMPTR2.UINT16[L]
#define RSCAN0TMPTR2LL RSCAN0.TMPTR2.UINT8[LL]
#define RSCAN0TMPTR2LH RSCAN0.TMPTR2.UINT8[LH]
#define RSCAN0TMPTR2H RSCAN0.TMPTR2.UINT16[H]
#define RSCAN0TMPTR2HL RSCAN0.TMPTR2.UINT8[HL]
#define RSCAN0TMPTR2HH RSCAN0.TMPTR2.UINT8[HH]
#define RSCAN0TMDF02 RSCAN0.TMDF02.UINT32
#define RSCAN0TMDF02L RSCAN0.TMDF02.UINT16[L]
#define RSCAN0TMDF02LL RSCAN0.TMDF02.UINT8[LL]
#define RSCAN0TMDF02LH RSCAN0.TMDF02.UINT8[LH]
#define RSCAN0TMDF02H RSCAN0.TMDF02.UINT16[H]
#define RSCAN0TMDF02HL RSCAN0.TMDF02.UINT8[HL]
#define RSCAN0TMDF02HH RSCAN0.TMDF02.UINT8[HH]
#define RSCAN0TMDF12 RSCAN0.TMDF12.UINT32
#define RSCAN0TMDF12L RSCAN0.TMDF12.UINT16[L]
#define RSCAN0TMDF12LL RSCAN0.TMDF12.UINT8[LL]
#define RSCAN0TMDF12LH RSCAN0.TMDF12.UINT8[LH]
#define RSCAN0TMDF12H RSCAN0.TMDF12.UINT16[H]
#define RSCAN0TMDF12HL RSCAN0.TMDF12.UINT8[HL]
#define RSCAN0TMDF12HH RSCAN0.TMDF12.UINT8[HH]
#define RSCAN0TMID3 RSCAN0.TMID3.UINT32
#define RSCAN0TMID3L RSCAN0.TMID3.UINT16[L]
#define RSCAN0TMID3LL RSCAN0.TMID3.UINT8[LL]
#define RSCAN0TMID3LH RSCAN0.TMID3.UINT8[LH]
#define RSCAN0TMID3H RSCAN0.TMID3.UINT16[H]
#define RSCAN0TMID3HL RSCAN0.TMID3.UINT8[HL]
#define RSCAN0TMID3HH RSCAN0.TMID3.UINT8[HH]
#define RSCAN0TMPTR3 RSCAN0.TMPTR3.UINT32
#define RSCAN0TMPTR3L RSCAN0.TMPTR3.UINT16[L]
#define RSCAN0TMPTR3LL RSCAN0.TMPTR3.UINT8[LL]
#define RSCAN0TMPTR3LH RSCAN0.TMPTR3.UINT8[LH]
#define RSCAN0TMPTR3H RSCAN0.TMPTR3.UINT16[H]
#define RSCAN0TMPTR3HL RSCAN0.TMPTR3.UINT8[HL]
#define RSCAN0TMPTR3HH RSCAN0.TMPTR3.UINT8[HH]
#define RSCAN0TMDF03 RSCAN0.TMDF03.UINT32
#define RSCAN0TMDF03L RSCAN0.TMDF03.UINT16[L]
#define RSCAN0TMDF03LL RSCAN0.TMDF03.UINT8[LL]
#define RSCAN0TMDF03LH RSCAN0.TMDF03.UINT8[LH]
#define RSCAN0TMDF03H RSCAN0.TMDF03.UINT16[H]
#define RSCAN0TMDF03HL RSCAN0.TMDF03.UINT8[HL]
#define RSCAN0TMDF03HH RSCAN0.TMDF03.UINT8[HH]
#define RSCAN0TMDF13 RSCAN0.TMDF13.UINT32
#define RSCAN0TMDF13L RSCAN0.TMDF13.UINT16[L]
#define RSCAN0TMDF13LL RSCAN0.TMDF13.UINT8[LL]
#define RSCAN0TMDF13LH RSCAN0.TMDF13.UINT8[LH]
#define RSCAN0TMDF13H RSCAN0.TMDF13.UINT16[H]
#define RSCAN0TMDF13HL RSCAN0.TMDF13.UINT8[HL]
#define RSCAN0TMDF13HH RSCAN0.TMDF13.UINT8[HH]
#define RSCAN0TMID4 RSCAN0.TMID4.UINT32
#define RSCAN0TMID4L RSCAN0.TMID4.UINT16[L]
#define RSCAN0TMID4LL RSCAN0.TMID4.UINT8[LL]
#define RSCAN0TMID4LH RSCAN0.TMID4.UINT8[LH]
#define RSCAN0TMID4H RSCAN0.TMID4.UINT16[H]
#define RSCAN0TMID4HL RSCAN0.TMID4.UINT8[HL]
#define RSCAN0TMID4HH RSCAN0.TMID4.UINT8[HH]
#define RSCAN0TMPTR4 RSCAN0.TMPTR4.UINT32
#define RSCAN0TMPTR4L RSCAN0.TMPTR4.UINT16[L]
#define RSCAN0TMPTR4LL RSCAN0.TMPTR4.UINT8[LL]
#define RSCAN0TMPTR4LH RSCAN0.TMPTR4.UINT8[LH]
#define RSCAN0TMPTR4H RSCAN0.TMPTR4.UINT16[H]
#define RSCAN0TMPTR4HL RSCAN0.TMPTR4.UINT8[HL]
#define RSCAN0TMPTR4HH RSCAN0.TMPTR4.UINT8[HH]
#define RSCAN0TMDF04 RSCAN0.TMDF04.UINT32
#define RSCAN0TMDF04L RSCAN0.TMDF04.UINT16[L]
#define RSCAN0TMDF04LL RSCAN0.TMDF04.UINT8[LL]
#define RSCAN0TMDF04LH RSCAN0.TMDF04.UINT8[LH]
#define RSCAN0TMDF04H RSCAN0.TMDF04.UINT16[H]
#define RSCAN0TMDF04HL RSCAN0.TMDF04.UINT8[HL]
#define RSCAN0TMDF04HH RSCAN0.TMDF04.UINT8[HH]
#define RSCAN0TMDF14 RSCAN0.TMDF14.UINT32
#define RSCAN0TMDF14L RSCAN0.TMDF14.UINT16[L]
#define RSCAN0TMDF14LL RSCAN0.TMDF14.UINT8[LL]
#define RSCAN0TMDF14LH RSCAN0.TMDF14.UINT8[LH]
#define RSCAN0TMDF14H RSCAN0.TMDF14.UINT16[H]
#define RSCAN0TMDF14HL RSCAN0.TMDF14.UINT8[HL]
#define RSCAN0TMDF14HH RSCAN0.TMDF14.UINT8[HH]
#define RSCAN0TMID5 RSCAN0.TMID5.UINT32
#define RSCAN0TMID5L RSCAN0.TMID5.UINT16[L]
#define RSCAN0TMID5LL RSCAN0.TMID5.UINT8[LL]
#define RSCAN0TMID5LH RSCAN0.TMID5.UINT8[LH]
#define RSCAN0TMID5H RSCAN0.TMID5.UINT16[H]
#define RSCAN0TMID5HL RSCAN0.TMID5.UINT8[HL]
#define RSCAN0TMID5HH RSCAN0.TMID5.UINT8[HH]
#define RSCAN0TMPTR5 RSCAN0.TMPTR5.UINT32
#define RSCAN0TMPTR5L RSCAN0.TMPTR5.UINT16[L]
#define RSCAN0TMPTR5LL RSCAN0.TMPTR5.UINT8[LL]
#define RSCAN0TMPTR5LH RSCAN0.TMPTR5.UINT8[LH]
#define RSCAN0TMPTR5H RSCAN0.TMPTR5.UINT16[H]
#define RSCAN0TMPTR5HL RSCAN0.TMPTR5.UINT8[HL]
#define RSCAN0TMPTR5HH RSCAN0.TMPTR5.UINT8[HH]
#define RSCAN0TMDF05 RSCAN0.TMDF05.UINT32
#define RSCAN0TMDF05L RSCAN0.TMDF05.UINT16[L]
#define RSCAN0TMDF05LL RSCAN0.TMDF05.UINT8[LL]
#define RSCAN0TMDF05LH RSCAN0.TMDF05.UINT8[LH]
#define RSCAN0TMDF05H RSCAN0.TMDF05.UINT16[H]
#define RSCAN0TMDF05HL RSCAN0.TMDF05.UINT8[HL]
#define RSCAN0TMDF05HH RSCAN0.TMDF05.UINT8[HH]
#define RSCAN0TMDF15 RSCAN0.TMDF15.UINT32
#define RSCAN0TMDF15L RSCAN0.TMDF15.UINT16[L]
#define RSCAN0TMDF15LL RSCAN0.TMDF15.UINT8[LL]
#define RSCAN0TMDF15LH RSCAN0.TMDF15.UINT8[LH]
#define RSCAN0TMDF15H RSCAN0.TMDF15.UINT16[H]
#define RSCAN0TMDF15HL RSCAN0.TMDF15.UINT8[HL]
#define RSCAN0TMDF15HH RSCAN0.TMDF15.UINT8[HH]
#define RSCAN0TMID6 RSCAN0.TMID6.UINT32
#define RSCAN0TMID6L RSCAN0.TMID6.UINT16[L]
#define RSCAN0TMID6LL RSCAN0.TMID6.UINT8[LL]
#define RSCAN0TMID6LH RSCAN0.TMID6.UINT8[LH]
#define RSCAN0TMID6H RSCAN0.TMID6.UINT16[H]
#define RSCAN0TMID6HL RSCAN0.TMID6.UINT8[HL]
#define RSCAN0TMID6HH RSCAN0.TMID6.UINT8[HH]
#define RSCAN0TMPTR6 RSCAN0.TMPTR6.UINT32
#define RSCAN0TMPTR6L RSCAN0.TMPTR6.UINT16[L]
#define RSCAN0TMPTR6LL RSCAN0.TMPTR6.UINT8[LL]
#define RSCAN0TMPTR6LH RSCAN0.TMPTR6.UINT8[LH]
#define RSCAN0TMPTR6H RSCAN0.TMPTR6.UINT16[H]
#define RSCAN0TMPTR6HL RSCAN0.TMPTR6.UINT8[HL]
#define RSCAN0TMPTR6HH RSCAN0.TMPTR6.UINT8[HH]
#define RSCAN0TMDF06 RSCAN0.TMDF06.UINT32
#define RSCAN0TMDF06L RSCAN0.TMDF06.UINT16[L]
#define RSCAN0TMDF06LL RSCAN0.TMDF06.UINT8[LL]
#define RSCAN0TMDF06LH RSCAN0.TMDF06.UINT8[LH]
#define RSCAN0TMDF06H RSCAN0.TMDF06.UINT16[H]
#define RSCAN0TMDF06HL RSCAN0.TMDF06.UINT8[HL]
#define RSCAN0TMDF06HH RSCAN0.TMDF06.UINT8[HH]
#define RSCAN0TMDF16 RSCAN0.TMDF16.UINT32
#define RSCAN0TMDF16L RSCAN0.TMDF16.UINT16[L]
#define RSCAN0TMDF16LL RSCAN0.TMDF16.UINT8[LL]
#define RSCAN0TMDF16LH RSCAN0.TMDF16.UINT8[LH]
#define RSCAN0TMDF16H RSCAN0.TMDF16.UINT16[H]
#define RSCAN0TMDF16HL RSCAN0.TMDF16.UINT8[HL]
#define RSCAN0TMDF16HH RSCAN0.TMDF16.UINT8[HH]
#define RSCAN0TMID7 RSCAN0.TMID7.UINT32
#define RSCAN0TMID7L RSCAN0.TMID7.UINT16[L]
#define RSCAN0TMID7LL RSCAN0.TMID7.UINT8[LL]
#define RSCAN0TMID7LH RSCAN0.TMID7.UINT8[LH]
#define RSCAN0TMID7H RSCAN0.TMID7.UINT16[H]
#define RSCAN0TMID7HL RSCAN0.TMID7.UINT8[HL]
#define RSCAN0TMID7HH RSCAN0.TMID7.UINT8[HH]
#define RSCAN0TMPTR7 RSCAN0.TMPTR7.UINT32
#define RSCAN0TMPTR7L RSCAN0.TMPTR7.UINT16[L]
#define RSCAN0TMPTR7LL RSCAN0.TMPTR7.UINT8[LL]
#define RSCAN0TMPTR7LH RSCAN0.TMPTR7.UINT8[LH]
#define RSCAN0TMPTR7H RSCAN0.TMPTR7.UINT16[H]
#define RSCAN0TMPTR7HL RSCAN0.TMPTR7.UINT8[HL]
#define RSCAN0TMPTR7HH RSCAN0.TMPTR7.UINT8[HH]
#define RSCAN0TMDF07 RSCAN0.TMDF07.UINT32
#define RSCAN0TMDF07L RSCAN0.TMDF07.UINT16[L]
#define RSCAN0TMDF07LL RSCAN0.TMDF07.UINT8[LL]
#define RSCAN0TMDF07LH RSCAN0.TMDF07.UINT8[LH]
#define RSCAN0TMDF07H RSCAN0.TMDF07.UINT16[H]
#define RSCAN0TMDF07HL RSCAN0.TMDF07.UINT8[HL]
#define RSCAN0TMDF07HH RSCAN0.TMDF07.UINT8[HH]
#define RSCAN0TMDF17 RSCAN0.TMDF17.UINT32
#define RSCAN0TMDF17L RSCAN0.TMDF17.UINT16[L]
#define RSCAN0TMDF17LL RSCAN0.TMDF17.UINT8[LL]
#define RSCAN0TMDF17LH RSCAN0.TMDF17.UINT8[LH]
#define RSCAN0TMDF17H RSCAN0.TMDF17.UINT16[H]
#define RSCAN0TMDF17HL RSCAN0.TMDF17.UINT8[HL]
#define RSCAN0TMDF17HH RSCAN0.TMDF17.UINT8[HH]
#define RSCAN0TMID8 RSCAN0.TMID8.UINT32
#define RSCAN0TMID8L RSCAN0.TMID8.UINT16[L]
#define RSCAN0TMID8LL RSCAN0.TMID8.UINT8[LL]
#define RSCAN0TMID8LH RSCAN0.TMID8.UINT8[LH]
#define RSCAN0TMID8H RSCAN0.TMID8.UINT16[H]
#define RSCAN0TMID8HL RSCAN0.TMID8.UINT8[HL]
#define RSCAN0TMID8HH RSCAN0.TMID8.UINT8[HH]
#define RSCAN0TMPTR8 RSCAN0.TMPTR8.UINT32
#define RSCAN0TMPTR8L RSCAN0.TMPTR8.UINT16[L]
#define RSCAN0TMPTR8LL RSCAN0.TMPTR8.UINT8[LL]
#define RSCAN0TMPTR8LH RSCAN0.TMPTR8.UINT8[LH]
#define RSCAN0TMPTR8H RSCAN0.TMPTR8.UINT16[H]
#define RSCAN0TMPTR8HL RSCAN0.TMPTR8.UINT8[HL]
#define RSCAN0TMPTR8HH RSCAN0.TMPTR8.UINT8[HH]
#define RSCAN0TMDF08 RSCAN0.TMDF08.UINT32
#define RSCAN0TMDF08L RSCAN0.TMDF08.UINT16[L]
#define RSCAN0TMDF08LL RSCAN0.TMDF08.UINT8[LL]
#define RSCAN0TMDF08LH RSCAN0.TMDF08.UINT8[LH]
#define RSCAN0TMDF08H RSCAN0.TMDF08.UINT16[H]
#define RSCAN0TMDF08HL RSCAN0.TMDF08.UINT8[HL]
#define RSCAN0TMDF08HH RSCAN0.TMDF08.UINT8[HH]
#define RSCAN0TMDF18 RSCAN0.TMDF18.UINT32
#define RSCAN0TMDF18L RSCAN0.TMDF18.UINT16[L]
#define RSCAN0TMDF18LL RSCAN0.TMDF18.UINT8[LL]
#define RSCAN0TMDF18LH RSCAN0.TMDF18.UINT8[LH]
#define RSCAN0TMDF18H RSCAN0.TMDF18.UINT16[H]
#define RSCAN0TMDF18HL RSCAN0.TMDF18.UINT8[HL]
#define RSCAN0TMDF18HH RSCAN0.TMDF18.UINT8[HH]
#define RSCAN0TMID9 RSCAN0.TMID9.UINT32
#define RSCAN0TMID9L RSCAN0.TMID9.UINT16[L]
#define RSCAN0TMID9LL RSCAN0.TMID9.UINT8[LL]
#define RSCAN0TMID9LH RSCAN0.TMID9.UINT8[LH]
#define RSCAN0TMID9H RSCAN0.TMID9.UINT16[H]
#define RSCAN0TMID9HL RSCAN0.TMID9.UINT8[HL]
#define RSCAN0TMID9HH RSCAN0.TMID9.UINT8[HH]
#define RSCAN0TMPTR9 RSCAN0.TMPTR9.UINT32
#define RSCAN0TMPTR9L RSCAN0.TMPTR9.UINT16[L]
#define RSCAN0TMPTR9LL RSCAN0.TMPTR9.UINT8[LL]
#define RSCAN0TMPTR9LH RSCAN0.TMPTR9.UINT8[LH]
#define RSCAN0TMPTR9H RSCAN0.TMPTR9.UINT16[H]
#define RSCAN0TMPTR9HL RSCAN0.TMPTR9.UINT8[HL]
#define RSCAN0TMPTR9HH RSCAN0.TMPTR9.UINT8[HH]
#define RSCAN0TMDF09 RSCAN0.TMDF09.UINT32
#define RSCAN0TMDF09L RSCAN0.TMDF09.UINT16[L]
#define RSCAN0TMDF09LL RSCAN0.TMDF09.UINT8[LL]
#define RSCAN0TMDF09LH RSCAN0.TMDF09.UINT8[LH]
#define RSCAN0TMDF09H RSCAN0.TMDF09.UINT16[H]
#define RSCAN0TMDF09HL RSCAN0.TMDF09.UINT8[HL]
#define RSCAN0TMDF09HH RSCAN0.TMDF09.UINT8[HH]
#define RSCAN0TMDF19 RSCAN0.TMDF19.UINT32
#define RSCAN0TMDF19L RSCAN0.TMDF19.UINT16[L]
#define RSCAN0TMDF19LL RSCAN0.TMDF19.UINT8[LL]
#define RSCAN0TMDF19LH RSCAN0.TMDF19.UINT8[LH]
#define RSCAN0TMDF19H RSCAN0.TMDF19.UINT16[H]
#define RSCAN0TMDF19HL RSCAN0.TMDF19.UINT8[HL]
#define RSCAN0TMDF19HH RSCAN0.TMDF19.UINT8[HH]
#define RSCAN0TMID10 RSCAN0.TMID10.UINT32
#define RSCAN0TMID10L RSCAN0.TMID10.UINT16[L]
#define RSCAN0TMID10LL RSCAN0.TMID10.UINT8[LL]
#define RSCAN0TMID10LH RSCAN0.TMID10.UINT8[LH]
#define RSCAN0TMID10H RSCAN0.TMID10.UINT16[H]
#define RSCAN0TMID10HL RSCAN0.TMID10.UINT8[HL]
#define RSCAN0TMID10HH RSCAN0.TMID10.UINT8[HH]
#define RSCAN0TMPTR10 RSCAN0.TMPTR10.UINT32
#define RSCAN0TMPTR10L RSCAN0.TMPTR10.UINT16[L]
#define RSCAN0TMPTR10LL RSCAN0.TMPTR10.UINT8[LL]
#define RSCAN0TMPTR10LH RSCAN0.TMPTR10.UINT8[LH]
#define RSCAN0TMPTR10H RSCAN0.TMPTR10.UINT16[H]
#define RSCAN0TMPTR10HL RSCAN0.TMPTR10.UINT8[HL]
#define RSCAN0TMPTR10HH RSCAN0.TMPTR10.UINT8[HH]
#define RSCAN0TMDF010 RSCAN0.TMDF010.UINT32
#define RSCAN0TMDF010L RSCAN0.TMDF010.UINT16[L]
#define RSCAN0TMDF010LL RSCAN0.TMDF010.UINT8[LL]
#define RSCAN0TMDF010LH RSCAN0.TMDF010.UINT8[LH]
#define RSCAN0TMDF010H RSCAN0.TMDF010.UINT16[H]
#define RSCAN0TMDF010HL RSCAN0.TMDF010.UINT8[HL]
#define RSCAN0TMDF010HH RSCAN0.TMDF010.UINT8[HH]
#define RSCAN0TMDF110 RSCAN0.TMDF110.UINT32
#define RSCAN0TMDF110L RSCAN0.TMDF110.UINT16[L]
#define RSCAN0TMDF110LL RSCAN0.TMDF110.UINT8[LL]
#define RSCAN0TMDF110LH RSCAN0.TMDF110.UINT8[LH]
#define RSCAN0TMDF110H RSCAN0.TMDF110.UINT16[H]
#define RSCAN0TMDF110HL RSCAN0.TMDF110.UINT8[HL]
#define RSCAN0TMDF110HH RSCAN0.TMDF110.UINT8[HH]
#define RSCAN0TMID11 RSCAN0.TMID11.UINT32
#define RSCAN0TMID11L RSCAN0.TMID11.UINT16[L]
#define RSCAN0TMID11LL RSCAN0.TMID11.UINT8[LL]
#define RSCAN0TMID11LH RSCAN0.TMID11.UINT8[LH]
#define RSCAN0TMID11H RSCAN0.TMID11.UINT16[H]
#define RSCAN0TMID11HL RSCAN0.TMID11.UINT8[HL]
#define RSCAN0TMID11HH RSCAN0.TMID11.UINT8[HH]
#define RSCAN0TMPTR11 RSCAN0.TMPTR11.UINT32
#define RSCAN0TMPTR11L RSCAN0.TMPTR11.UINT16[L]
#define RSCAN0TMPTR11LL RSCAN0.TMPTR11.UINT8[LL]
#define RSCAN0TMPTR11LH RSCAN0.TMPTR11.UINT8[LH]
#define RSCAN0TMPTR11H RSCAN0.TMPTR11.UINT16[H]
#define RSCAN0TMPTR11HL RSCAN0.TMPTR11.UINT8[HL]
#define RSCAN0TMPTR11HH RSCAN0.TMPTR11.UINT8[HH]
#define RSCAN0TMDF011 RSCAN0.TMDF011.UINT32
#define RSCAN0TMDF011L RSCAN0.TMDF011.UINT16[L]
#define RSCAN0TMDF011LL RSCAN0.TMDF011.UINT8[LL]
#define RSCAN0TMDF011LH RSCAN0.TMDF011.UINT8[LH]
#define RSCAN0TMDF011H RSCAN0.TMDF011.UINT16[H]
#define RSCAN0TMDF011HL RSCAN0.TMDF011.UINT8[HL]
#define RSCAN0TMDF011HH RSCAN0.TMDF011.UINT8[HH]
#define RSCAN0TMDF111 RSCAN0.TMDF111.UINT32
#define RSCAN0TMDF111L RSCAN0.TMDF111.UINT16[L]
#define RSCAN0TMDF111LL RSCAN0.TMDF111.UINT8[LL]
#define RSCAN0TMDF111LH RSCAN0.TMDF111.UINT8[LH]
#define RSCAN0TMDF111H RSCAN0.TMDF111.UINT16[H]
#define RSCAN0TMDF111HL RSCAN0.TMDF111.UINT8[HL]
#define RSCAN0TMDF111HH RSCAN0.TMDF111.UINT8[HH]
#define RSCAN0TMID12 RSCAN0.TMID12.UINT32
#define RSCAN0TMID12L RSCAN0.TMID12.UINT16[L]
#define RSCAN0TMID12LL RSCAN0.TMID12.UINT8[LL]
#define RSCAN0TMID12LH RSCAN0.TMID12.UINT8[LH]
#define RSCAN0TMID12H RSCAN0.TMID12.UINT16[H]
#define RSCAN0TMID12HL RSCAN0.TMID12.UINT8[HL]
#define RSCAN0TMID12HH RSCAN0.TMID12.UINT8[HH]
#define RSCAN0TMPTR12 RSCAN0.TMPTR12.UINT32
#define RSCAN0TMPTR12L RSCAN0.TMPTR12.UINT16[L]
#define RSCAN0TMPTR12LL RSCAN0.TMPTR12.UINT8[LL]
#define RSCAN0TMPTR12LH RSCAN0.TMPTR12.UINT8[LH]
#define RSCAN0TMPTR12H RSCAN0.TMPTR12.UINT16[H]
#define RSCAN0TMPTR12HL RSCAN0.TMPTR12.UINT8[HL]
#define RSCAN0TMPTR12HH RSCAN0.TMPTR12.UINT8[HH]
#define RSCAN0TMDF012 RSCAN0.TMDF012.UINT32
#define RSCAN0TMDF012L RSCAN0.TMDF012.UINT16[L]
#define RSCAN0TMDF012LL RSCAN0.TMDF012.UINT8[LL]
#define RSCAN0TMDF012LH RSCAN0.TMDF012.UINT8[LH]
#define RSCAN0TMDF012H RSCAN0.TMDF012.UINT16[H]
#define RSCAN0TMDF012HL RSCAN0.TMDF012.UINT8[HL]
#define RSCAN0TMDF012HH RSCAN0.TMDF012.UINT8[HH]
#define RSCAN0TMDF112 RSCAN0.TMDF112.UINT32
#define RSCAN0TMDF112L RSCAN0.TMDF112.UINT16[L]
#define RSCAN0TMDF112LL RSCAN0.TMDF112.UINT8[LL]
#define RSCAN0TMDF112LH RSCAN0.TMDF112.UINT8[LH]
#define RSCAN0TMDF112H RSCAN0.TMDF112.UINT16[H]
#define RSCAN0TMDF112HL RSCAN0.TMDF112.UINT8[HL]
#define RSCAN0TMDF112HH RSCAN0.TMDF112.UINT8[HH]
#define RSCAN0TMID13 RSCAN0.TMID13.UINT32
#define RSCAN0TMID13L RSCAN0.TMID13.UINT16[L]
#define RSCAN0TMID13LL RSCAN0.TMID13.UINT8[LL]
#define RSCAN0TMID13LH RSCAN0.TMID13.UINT8[LH]
#define RSCAN0TMID13H RSCAN0.TMID13.UINT16[H]
#define RSCAN0TMID13HL RSCAN0.TMID13.UINT8[HL]
#define RSCAN0TMID13HH RSCAN0.TMID13.UINT8[HH]
#define RSCAN0TMPTR13 RSCAN0.TMPTR13.UINT32
#define RSCAN0TMPTR13L RSCAN0.TMPTR13.UINT16[L]
#define RSCAN0TMPTR13LL RSCAN0.TMPTR13.UINT8[LL]
#define RSCAN0TMPTR13LH RSCAN0.TMPTR13.UINT8[LH]
#define RSCAN0TMPTR13H RSCAN0.TMPTR13.UINT16[H]
#define RSCAN0TMPTR13HL RSCAN0.TMPTR13.UINT8[HL]
#define RSCAN0TMPTR13HH RSCAN0.TMPTR13.UINT8[HH]
#define RSCAN0TMDF013 RSCAN0.TMDF013.UINT32
#define RSCAN0TMDF013L RSCAN0.TMDF013.UINT16[L]
#define RSCAN0TMDF013LL RSCAN0.TMDF013.UINT8[LL]
#define RSCAN0TMDF013LH RSCAN0.TMDF013.UINT8[LH]
#define RSCAN0TMDF013H RSCAN0.TMDF013.UINT16[H]
#define RSCAN0TMDF013HL RSCAN0.TMDF013.UINT8[HL]
#define RSCAN0TMDF013HH RSCAN0.TMDF013.UINT8[HH]
#define RSCAN0TMDF113 RSCAN0.TMDF113.UINT32
#define RSCAN0TMDF113L RSCAN0.TMDF113.UINT16[L]
#define RSCAN0TMDF113LL RSCAN0.TMDF113.UINT8[LL]
#define RSCAN0TMDF113LH RSCAN0.TMDF113.UINT8[LH]
#define RSCAN0TMDF113H RSCAN0.TMDF113.UINT16[H]
#define RSCAN0TMDF113HL RSCAN0.TMDF113.UINT8[HL]
#define RSCAN0TMDF113HH RSCAN0.TMDF113.UINT8[HH]
#define RSCAN0TMID14 RSCAN0.TMID14.UINT32
#define RSCAN0TMID14L RSCAN0.TMID14.UINT16[L]
#define RSCAN0TMID14LL RSCAN0.TMID14.UINT8[LL]
#define RSCAN0TMID14LH RSCAN0.TMID14.UINT8[LH]
#define RSCAN0TMID14H RSCAN0.TMID14.UINT16[H]
#define RSCAN0TMID14HL RSCAN0.TMID14.UINT8[HL]
#define RSCAN0TMID14HH RSCAN0.TMID14.UINT8[HH]
#define RSCAN0TMPTR14 RSCAN0.TMPTR14.UINT32
#define RSCAN0TMPTR14L RSCAN0.TMPTR14.UINT16[L]
#define RSCAN0TMPTR14LL RSCAN0.TMPTR14.UINT8[LL]
#define RSCAN0TMPTR14LH RSCAN0.TMPTR14.UINT8[LH]
#define RSCAN0TMPTR14H RSCAN0.TMPTR14.UINT16[H]
#define RSCAN0TMPTR14HL RSCAN0.TMPTR14.UINT8[HL]
#define RSCAN0TMPTR14HH RSCAN0.TMPTR14.UINT8[HH]
#define RSCAN0TMDF014 RSCAN0.TMDF014.UINT32
#define RSCAN0TMDF014L RSCAN0.TMDF014.UINT16[L]
#define RSCAN0TMDF014LL RSCAN0.TMDF014.UINT8[LL]
#define RSCAN0TMDF014LH RSCAN0.TMDF014.UINT8[LH]
#define RSCAN0TMDF014H RSCAN0.TMDF014.UINT16[H]
#define RSCAN0TMDF014HL RSCAN0.TMDF014.UINT8[HL]
#define RSCAN0TMDF014HH RSCAN0.TMDF014.UINT8[HH]
#define RSCAN0TMDF114 RSCAN0.TMDF114.UINT32
#define RSCAN0TMDF114L RSCAN0.TMDF114.UINT16[L]
#define RSCAN0TMDF114LL RSCAN0.TMDF114.UINT8[LL]
#define RSCAN0TMDF114LH RSCAN0.TMDF114.UINT8[LH]
#define RSCAN0TMDF114H RSCAN0.TMDF114.UINT16[H]
#define RSCAN0TMDF114HL RSCAN0.TMDF114.UINT8[HL]
#define RSCAN0TMDF114HH RSCAN0.TMDF114.UINT8[HH]
#define RSCAN0TMID15 RSCAN0.TMID15.UINT32
#define RSCAN0TMID15L RSCAN0.TMID15.UINT16[L]
#define RSCAN0TMID15LL RSCAN0.TMID15.UINT8[LL]
#define RSCAN0TMID15LH RSCAN0.TMID15.UINT8[LH]
#define RSCAN0TMID15H RSCAN0.TMID15.UINT16[H]
#define RSCAN0TMID15HL RSCAN0.TMID15.UINT8[HL]
#define RSCAN0TMID15HH RSCAN0.TMID15.UINT8[HH]
#define RSCAN0TMPTR15 RSCAN0.TMPTR15.UINT32
#define RSCAN0TMPTR15L RSCAN0.TMPTR15.UINT16[L]
#define RSCAN0TMPTR15LL RSCAN0.TMPTR15.UINT8[LL]
#define RSCAN0TMPTR15LH RSCAN0.TMPTR15.UINT8[LH]
#define RSCAN0TMPTR15H RSCAN0.TMPTR15.UINT16[H]
#define RSCAN0TMPTR15HL RSCAN0.TMPTR15.UINT8[HL]
#define RSCAN0TMPTR15HH RSCAN0.TMPTR15.UINT8[HH]
#define RSCAN0TMDF015 RSCAN0.TMDF015.UINT32
#define RSCAN0TMDF015L RSCAN0.TMDF015.UINT16[L]
#define RSCAN0TMDF015LL RSCAN0.TMDF015.UINT8[LL]
#define RSCAN0TMDF015LH RSCAN0.TMDF015.UINT8[LH]
#define RSCAN0TMDF015H RSCAN0.TMDF015.UINT16[H]
#define RSCAN0TMDF015HL RSCAN0.TMDF015.UINT8[HL]
#define RSCAN0TMDF015HH RSCAN0.TMDF015.UINT8[HH]
#define RSCAN0TMDF115 RSCAN0.TMDF115.UINT32
#define RSCAN0TMDF115L RSCAN0.TMDF115.UINT16[L]
#define RSCAN0TMDF115LL RSCAN0.TMDF115.UINT8[LL]
#define RSCAN0TMDF115LH RSCAN0.TMDF115.UINT8[LH]
#define RSCAN0TMDF115H RSCAN0.TMDF115.UINT16[H]
#define RSCAN0TMDF115HL RSCAN0.TMDF115.UINT8[HL]
#define RSCAN0TMDF115HH RSCAN0.TMDF115.UINT8[HH]
#define RSCAN0TMID16 RSCAN0.TMID16.UINT32
#define RSCAN0TMID16L RSCAN0.TMID16.UINT16[L]
#define RSCAN0TMID16LL RSCAN0.TMID16.UINT8[LL]
#define RSCAN0TMID16LH RSCAN0.TMID16.UINT8[LH]
#define RSCAN0TMID16H RSCAN0.TMID16.UINT16[H]
#define RSCAN0TMID16HL RSCAN0.TMID16.UINT8[HL]
#define RSCAN0TMID16HH RSCAN0.TMID16.UINT8[HH]
#define RSCAN0TMPTR16 RSCAN0.TMPTR16.UINT32
#define RSCAN0TMPTR16L RSCAN0.TMPTR16.UINT16[L]
#define RSCAN0TMPTR16LL RSCAN0.TMPTR16.UINT8[LL]
#define RSCAN0TMPTR16LH RSCAN0.TMPTR16.UINT8[LH]
#define RSCAN0TMPTR16H RSCAN0.TMPTR16.UINT16[H]
#define RSCAN0TMPTR16HL RSCAN0.TMPTR16.UINT8[HL]
#define RSCAN0TMPTR16HH RSCAN0.TMPTR16.UINT8[HH]
#define RSCAN0TMDF016 RSCAN0.TMDF016.UINT32
#define RSCAN0TMDF016L RSCAN0.TMDF016.UINT16[L]
#define RSCAN0TMDF016LL RSCAN0.TMDF016.UINT8[LL]
#define RSCAN0TMDF016LH RSCAN0.TMDF016.UINT8[LH]
#define RSCAN0TMDF016H RSCAN0.TMDF016.UINT16[H]
#define RSCAN0TMDF016HL RSCAN0.TMDF016.UINT8[HL]
#define RSCAN0TMDF016HH RSCAN0.TMDF016.UINT8[HH]
#define RSCAN0TMDF116 RSCAN0.TMDF116.UINT32
#define RSCAN0TMDF116L RSCAN0.TMDF116.UINT16[L]
#define RSCAN0TMDF116LL RSCAN0.TMDF116.UINT8[LL]
#define RSCAN0TMDF116LH RSCAN0.TMDF116.UINT8[LH]
#define RSCAN0TMDF116H RSCAN0.TMDF116.UINT16[H]
#define RSCAN0TMDF116HL RSCAN0.TMDF116.UINT8[HL]
#define RSCAN0TMDF116HH RSCAN0.TMDF116.UINT8[HH]
#define RSCAN0TMID17 RSCAN0.TMID17.UINT32
#define RSCAN0TMID17L RSCAN0.TMID17.UINT16[L]
#define RSCAN0TMID17LL RSCAN0.TMID17.UINT8[LL]
#define RSCAN0TMID17LH RSCAN0.TMID17.UINT8[LH]
#define RSCAN0TMID17H RSCAN0.TMID17.UINT16[H]
#define RSCAN0TMID17HL RSCAN0.TMID17.UINT8[HL]
#define RSCAN0TMID17HH RSCAN0.TMID17.UINT8[HH]
#define RSCAN0TMPTR17 RSCAN0.TMPTR17.UINT32
#define RSCAN0TMPTR17L RSCAN0.TMPTR17.UINT16[L]
#define RSCAN0TMPTR17LL RSCAN0.TMPTR17.UINT8[LL]
#define RSCAN0TMPTR17LH RSCAN0.TMPTR17.UINT8[LH]
#define RSCAN0TMPTR17H RSCAN0.TMPTR17.UINT16[H]
#define RSCAN0TMPTR17HL RSCAN0.TMPTR17.UINT8[HL]
#define RSCAN0TMPTR17HH RSCAN0.TMPTR17.UINT8[HH]
#define RSCAN0TMDF017 RSCAN0.TMDF017.UINT32
#define RSCAN0TMDF017L RSCAN0.TMDF017.UINT16[L]
#define RSCAN0TMDF017LL RSCAN0.TMDF017.UINT8[LL]
#define RSCAN0TMDF017LH RSCAN0.TMDF017.UINT8[LH]
#define RSCAN0TMDF017H RSCAN0.TMDF017.UINT16[H]
#define RSCAN0TMDF017HL RSCAN0.TMDF017.UINT8[HL]
#define RSCAN0TMDF017HH RSCAN0.TMDF017.UINT8[HH]
#define RSCAN0TMDF117 RSCAN0.TMDF117.UINT32
#define RSCAN0TMDF117L RSCAN0.TMDF117.UINT16[L]
#define RSCAN0TMDF117LL RSCAN0.TMDF117.UINT8[LL]
#define RSCAN0TMDF117LH RSCAN0.TMDF117.UINT8[LH]
#define RSCAN0TMDF117H RSCAN0.TMDF117.UINT16[H]
#define RSCAN0TMDF117HL RSCAN0.TMDF117.UINT8[HL]
#define RSCAN0TMDF117HH RSCAN0.TMDF117.UINT8[HH]
#define RSCAN0TMID18 RSCAN0.TMID18.UINT32
#define RSCAN0TMID18L RSCAN0.TMID18.UINT16[L]
#define RSCAN0TMID18LL RSCAN0.TMID18.UINT8[LL]
#define RSCAN0TMID18LH RSCAN0.TMID18.UINT8[LH]
#define RSCAN0TMID18H RSCAN0.TMID18.UINT16[H]
#define RSCAN0TMID18HL RSCAN0.TMID18.UINT8[HL]
#define RSCAN0TMID18HH RSCAN0.TMID18.UINT8[HH]
#define RSCAN0TMPTR18 RSCAN0.TMPTR18.UINT32
#define RSCAN0TMPTR18L RSCAN0.TMPTR18.UINT16[L]
#define RSCAN0TMPTR18LL RSCAN0.TMPTR18.UINT8[LL]
#define RSCAN0TMPTR18LH RSCAN0.TMPTR18.UINT8[LH]
#define RSCAN0TMPTR18H RSCAN0.TMPTR18.UINT16[H]
#define RSCAN0TMPTR18HL RSCAN0.TMPTR18.UINT8[HL]
#define RSCAN0TMPTR18HH RSCAN0.TMPTR18.UINT8[HH]
#define RSCAN0TMDF018 RSCAN0.TMDF018.UINT32
#define RSCAN0TMDF018L RSCAN0.TMDF018.UINT16[L]
#define RSCAN0TMDF018LL RSCAN0.TMDF018.UINT8[LL]
#define RSCAN0TMDF018LH RSCAN0.TMDF018.UINT8[LH]
#define RSCAN0TMDF018H RSCAN0.TMDF018.UINT16[H]
#define RSCAN0TMDF018HL RSCAN0.TMDF018.UINT8[HL]
#define RSCAN0TMDF018HH RSCAN0.TMDF018.UINT8[HH]
#define RSCAN0TMDF118 RSCAN0.TMDF118.UINT32
#define RSCAN0TMDF118L RSCAN0.TMDF118.UINT16[L]
#define RSCAN0TMDF118LL RSCAN0.TMDF118.UINT8[LL]
#define RSCAN0TMDF118LH RSCAN0.TMDF118.UINT8[LH]
#define RSCAN0TMDF118H RSCAN0.TMDF118.UINT16[H]
#define RSCAN0TMDF118HL RSCAN0.TMDF118.UINT8[HL]
#define RSCAN0TMDF118HH RSCAN0.TMDF118.UINT8[HH]
#define RSCAN0TMID19 RSCAN0.TMID19.UINT32
#define RSCAN0TMID19L RSCAN0.TMID19.UINT16[L]
#define RSCAN0TMID19LL RSCAN0.TMID19.UINT8[LL]
#define RSCAN0TMID19LH RSCAN0.TMID19.UINT8[LH]
#define RSCAN0TMID19H RSCAN0.TMID19.UINT16[H]
#define RSCAN0TMID19HL RSCAN0.TMID19.UINT8[HL]
#define RSCAN0TMID19HH RSCAN0.TMID19.UINT8[HH]
#define RSCAN0TMPTR19 RSCAN0.TMPTR19.UINT32
#define RSCAN0TMPTR19L RSCAN0.TMPTR19.UINT16[L]
#define RSCAN0TMPTR19LL RSCAN0.TMPTR19.UINT8[LL]
#define RSCAN0TMPTR19LH RSCAN0.TMPTR19.UINT8[LH]
#define RSCAN0TMPTR19H RSCAN0.TMPTR19.UINT16[H]
#define RSCAN0TMPTR19HL RSCAN0.TMPTR19.UINT8[HL]
#define RSCAN0TMPTR19HH RSCAN0.TMPTR19.UINT8[HH]
#define RSCAN0TMDF019 RSCAN0.TMDF019.UINT32
#define RSCAN0TMDF019L RSCAN0.TMDF019.UINT16[L]
#define RSCAN0TMDF019LL RSCAN0.TMDF019.UINT8[LL]
#define RSCAN0TMDF019LH RSCAN0.TMDF019.UINT8[LH]
#define RSCAN0TMDF019H RSCAN0.TMDF019.UINT16[H]
#define RSCAN0TMDF019HL RSCAN0.TMDF019.UINT8[HL]
#define RSCAN0TMDF019HH RSCAN0.TMDF019.UINT8[HH]
#define RSCAN0TMDF119 RSCAN0.TMDF119.UINT32
#define RSCAN0TMDF119L RSCAN0.TMDF119.UINT16[L]
#define RSCAN0TMDF119LL RSCAN0.TMDF119.UINT8[LL]
#define RSCAN0TMDF119LH RSCAN0.TMDF119.UINT8[LH]
#define RSCAN0TMDF119H RSCAN0.TMDF119.UINT16[H]
#define RSCAN0TMDF119HL RSCAN0.TMDF119.UINT8[HL]
#define RSCAN0TMDF119HH RSCAN0.TMDF119.UINT8[HH]
#define RSCAN0TMID20 RSCAN0.TMID20.UINT32
#define RSCAN0TMID20L RSCAN0.TMID20.UINT16[L]
#define RSCAN0TMID20LL RSCAN0.TMID20.UINT8[LL]
#define RSCAN0TMID20LH RSCAN0.TMID20.UINT8[LH]
#define RSCAN0TMID20H RSCAN0.TMID20.UINT16[H]
#define RSCAN0TMID20HL RSCAN0.TMID20.UINT8[HL]
#define RSCAN0TMID20HH RSCAN0.TMID20.UINT8[HH]
#define RSCAN0TMPTR20 RSCAN0.TMPTR20.UINT32
#define RSCAN0TMPTR20L RSCAN0.TMPTR20.UINT16[L]
#define RSCAN0TMPTR20LL RSCAN0.TMPTR20.UINT8[LL]
#define RSCAN0TMPTR20LH RSCAN0.TMPTR20.UINT8[LH]
#define RSCAN0TMPTR20H RSCAN0.TMPTR20.UINT16[H]
#define RSCAN0TMPTR20HL RSCAN0.TMPTR20.UINT8[HL]
#define RSCAN0TMPTR20HH RSCAN0.TMPTR20.UINT8[HH]
#define RSCAN0TMDF020 RSCAN0.TMDF020.UINT32
#define RSCAN0TMDF020L RSCAN0.TMDF020.UINT16[L]
#define RSCAN0TMDF020LL RSCAN0.TMDF020.UINT8[LL]
#define RSCAN0TMDF020LH RSCAN0.TMDF020.UINT8[LH]
#define RSCAN0TMDF020H RSCAN0.TMDF020.UINT16[H]
#define RSCAN0TMDF020HL RSCAN0.TMDF020.UINT8[HL]
#define RSCAN0TMDF020HH RSCAN0.TMDF020.UINT8[HH]
#define RSCAN0TMDF120 RSCAN0.TMDF120.UINT32
#define RSCAN0TMDF120L RSCAN0.TMDF120.UINT16[L]
#define RSCAN0TMDF120LL RSCAN0.TMDF120.UINT8[LL]
#define RSCAN0TMDF120LH RSCAN0.TMDF120.UINT8[LH]
#define RSCAN0TMDF120H RSCAN0.TMDF120.UINT16[H]
#define RSCAN0TMDF120HL RSCAN0.TMDF120.UINT8[HL]
#define RSCAN0TMDF120HH RSCAN0.TMDF120.UINT8[HH]
#define RSCAN0TMID21 RSCAN0.TMID21.UINT32
#define RSCAN0TMID21L RSCAN0.TMID21.UINT16[L]
#define RSCAN0TMID21LL RSCAN0.TMID21.UINT8[LL]
#define RSCAN0TMID21LH RSCAN0.TMID21.UINT8[LH]
#define RSCAN0TMID21H RSCAN0.TMID21.UINT16[H]
#define RSCAN0TMID21HL RSCAN0.TMID21.UINT8[HL]
#define RSCAN0TMID21HH RSCAN0.TMID21.UINT8[HH]
#define RSCAN0TMPTR21 RSCAN0.TMPTR21.UINT32
#define RSCAN0TMPTR21L RSCAN0.TMPTR21.UINT16[L]
#define RSCAN0TMPTR21LL RSCAN0.TMPTR21.UINT8[LL]
#define RSCAN0TMPTR21LH RSCAN0.TMPTR21.UINT8[LH]
#define RSCAN0TMPTR21H RSCAN0.TMPTR21.UINT16[H]
#define RSCAN0TMPTR21HL RSCAN0.TMPTR21.UINT8[HL]
#define RSCAN0TMPTR21HH RSCAN0.TMPTR21.UINT8[HH]
#define RSCAN0TMDF021 RSCAN0.TMDF021.UINT32
#define RSCAN0TMDF021L RSCAN0.TMDF021.UINT16[L]
#define RSCAN0TMDF021LL RSCAN0.TMDF021.UINT8[LL]
#define RSCAN0TMDF021LH RSCAN0.TMDF021.UINT8[LH]
#define RSCAN0TMDF021H RSCAN0.TMDF021.UINT16[H]
#define RSCAN0TMDF021HL RSCAN0.TMDF021.UINT8[HL]
#define RSCAN0TMDF021HH RSCAN0.TMDF021.UINT8[HH]
#define RSCAN0TMDF121 RSCAN0.TMDF121.UINT32
#define RSCAN0TMDF121L RSCAN0.TMDF121.UINT16[L]
#define RSCAN0TMDF121LL RSCAN0.TMDF121.UINT8[LL]
#define RSCAN0TMDF121LH RSCAN0.TMDF121.UINT8[LH]
#define RSCAN0TMDF121H RSCAN0.TMDF121.UINT16[H]
#define RSCAN0TMDF121HL RSCAN0.TMDF121.UINT8[HL]
#define RSCAN0TMDF121HH RSCAN0.TMDF121.UINT8[HH]
#define RSCAN0TMID22 RSCAN0.TMID22.UINT32
#define RSCAN0TMID22L RSCAN0.TMID22.UINT16[L]
#define RSCAN0TMID22LL RSCAN0.TMID22.UINT8[LL]
#define RSCAN0TMID22LH RSCAN0.TMID22.UINT8[LH]
#define RSCAN0TMID22H RSCAN0.TMID22.UINT16[H]
#define RSCAN0TMID22HL RSCAN0.TMID22.UINT8[HL]
#define RSCAN0TMID22HH RSCAN0.TMID22.UINT8[HH]
#define RSCAN0TMPTR22 RSCAN0.TMPTR22.UINT32
#define RSCAN0TMPTR22L RSCAN0.TMPTR22.UINT16[L]
#define RSCAN0TMPTR22LL RSCAN0.TMPTR22.UINT8[LL]
#define RSCAN0TMPTR22LH RSCAN0.TMPTR22.UINT8[LH]
#define RSCAN0TMPTR22H RSCAN0.TMPTR22.UINT16[H]
#define RSCAN0TMPTR22HL RSCAN0.TMPTR22.UINT8[HL]
#define RSCAN0TMPTR22HH RSCAN0.TMPTR22.UINT8[HH]
#define RSCAN0TMDF022 RSCAN0.TMDF022.UINT32
#define RSCAN0TMDF022L RSCAN0.TMDF022.UINT16[L]
#define RSCAN0TMDF022LL RSCAN0.TMDF022.UINT8[LL]
#define RSCAN0TMDF022LH RSCAN0.TMDF022.UINT8[LH]
#define RSCAN0TMDF022H RSCAN0.TMDF022.UINT16[H]
#define RSCAN0TMDF022HL RSCAN0.TMDF022.UINT8[HL]
#define RSCAN0TMDF022HH RSCAN0.TMDF022.UINT8[HH]
#define RSCAN0TMDF122 RSCAN0.TMDF122.UINT32
#define RSCAN0TMDF122L RSCAN0.TMDF122.UINT16[L]
#define RSCAN0TMDF122LL RSCAN0.TMDF122.UINT8[LL]
#define RSCAN0TMDF122LH RSCAN0.TMDF122.UINT8[LH]
#define RSCAN0TMDF122H RSCAN0.TMDF122.UINT16[H]
#define RSCAN0TMDF122HL RSCAN0.TMDF122.UINT8[HL]
#define RSCAN0TMDF122HH RSCAN0.TMDF122.UINT8[HH]
#define RSCAN0TMID23 RSCAN0.TMID23.UINT32
#define RSCAN0TMID23L RSCAN0.TMID23.UINT16[L]
#define RSCAN0TMID23LL RSCAN0.TMID23.UINT8[LL]
#define RSCAN0TMID23LH RSCAN0.TMID23.UINT8[LH]
#define RSCAN0TMID23H RSCAN0.TMID23.UINT16[H]
#define RSCAN0TMID23HL RSCAN0.TMID23.UINT8[HL]
#define RSCAN0TMID23HH RSCAN0.TMID23.UINT8[HH]
#define RSCAN0TMPTR23 RSCAN0.TMPTR23.UINT32
#define RSCAN0TMPTR23L RSCAN0.TMPTR23.UINT16[L]
#define RSCAN0TMPTR23LL RSCAN0.TMPTR23.UINT8[LL]
#define RSCAN0TMPTR23LH RSCAN0.TMPTR23.UINT8[LH]
#define RSCAN0TMPTR23H RSCAN0.TMPTR23.UINT16[H]
#define RSCAN0TMPTR23HL RSCAN0.TMPTR23.UINT8[HL]
#define RSCAN0TMPTR23HH RSCAN0.TMPTR23.UINT8[HH]
#define RSCAN0TMDF023 RSCAN0.TMDF023.UINT32
#define RSCAN0TMDF023L RSCAN0.TMDF023.UINT16[L]
#define RSCAN0TMDF023LL RSCAN0.TMDF023.UINT8[LL]
#define RSCAN0TMDF023LH RSCAN0.TMDF023.UINT8[LH]
#define RSCAN0TMDF023H RSCAN0.TMDF023.UINT16[H]
#define RSCAN0TMDF023HL RSCAN0.TMDF023.UINT8[HL]
#define RSCAN0TMDF023HH RSCAN0.TMDF023.UINT8[HH]
#define RSCAN0TMDF123 RSCAN0.TMDF123.UINT32
#define RSCAN0TMDF123L RSCAN0.TMDF123.UINT16[L]
#define RSCAN0TMDF123LL RSCAN0.TMDF123.UINT8[LL]
#define RSCAN0TMDF123LH RSCAN0.TMDF123.UINT8[LH]
#define RSCAN0TMDF123H RSCAN0.TMDF123.UINT16[H]
#define RSCAN0TMDF123HL RSCAN0.TMDF123.UINT8[HL]
#define RSCAN0TMDF123HH RSCAN0.TMDF123.UINT8[HH]
#define RSCAN0TMID24 RSCAN0.TMID24.UINT32
#define RSCAN0TMID24L RSCAN0.TMID24.UINT16[L]
#define RSCAN0TMID24LL RSCAN0.TMID24.UINT8[LL]
#define RSCAN0TMID24LH RSCAN0.TMID24.UINT8[LH]
#define RSCAN0TMID24H RSCAN0.TMID24.UINT16[H]
#define RSCAN0TMID24HL RSCAN0.TMID24.UINT8[HL]
#define RSCAN0TMID24HH RSCAN0.TMID24.UINT8[HH]
#define RSCAN0TMPTR24 RSCAN0.TMPTR24.UINT32
#define RSCAN0TMPTR24L RSCAN0.TMPTR24.UINT16[L]
#define RSCAN0TMPTR24LL RSCAN0.TMPTR24.UINT8[LL]
#define RSCAN0TMPTR24LH RSCAN0.TMPTR24.UINT8[LH]
#define RSCAN0TMPTR24H RSCAN0.TMPTR24.UINT16[H]
#define RSCAN0TMPTR24HL RSCAN0.TMPTR24.UINT8[HL]
#define RSCAN0TMPTR24HH RSCAN0.TMPTR24.UINT8[HH]
#define RSCAN0TMDF024 RSCAN0.TMDF024.UINT32
#define RSCAN0TMDF024L RSCAN0.TMDF024.UINT16[L]
#define RSCAN0TMDF024LL RSCAN0.TMDF024.UINT8[LL]
#define RSCAN0TMDF024LH RSCAN0.TMDF024.UINT8[LH]
#define RSCAN0TMDF024H RSCAN0.TMDF024.UINT16[H]
#define RSCAN0TMDF024HL RSCAN0.TMDF024.UINT8[HL]
#define RSCAN0TMDF024HH RSCAN0.TMDF024.UINT8[HH]
#define RSCAN0TMDF124 RSCAN0.TMDF124.UINT32
#define RSCAN0TMDF124L RSCAN0.TMDF124.UINT16[L]
#define RSCAN0TMDF124LL RSCAN0.TMDF124.UINT8[LL]
#define RSCAN0TMDF124LH RSCAN0.TMDF124.UINT8[LH]
#define RSCAN0TMDF124H RSCAN0.TMDF124.UINT16[H]
#define RSCAN0TMDF124HL RSCAN0.TMDF124.UINT8[HL]
#define RSCAN0TMDF124HH RSCAN0.TMDF124.UINT8[HH]
#define RSCAN0TMID25 RSCAN0.TMID25.UINT32
#define RSCAN0TMID25L RSCAN0.TMID25.UINT16[L]
#define RSCAN0TMID25LL RSCAN0.TMID25.UINT8[LL]
#define RSCAN0TMID25LH RSCAN0.TMID25.UINT8[LH]
#define RSCAN0TMID25H RSCAN0.TMID25.UINT16[H]
#define RSCAN0TMID25HL RSCAN0.TMID25.UINT8[HL]
#define RSCAN0TMID25HH RSCAN0.TMID25.UINT8[HH]
#define RSCAN0TMPTR25 RSCAN0.TMPTR25.UINT32
#define RSCAN0TMPTR25L RSCAN0.TMPTR25.UINT16[L]
#define RSCAN0TMPTR25LL RSCAN0.TMPTR25.UINT8[LL]
#define RSCAN0TMPTR25LH RSCAN0.TMPTR25.UINT8[LH]
#define RSCAN0TMPTR25H RSCAN0.TMPTR25.UINT16[H]
#define RSCAN0TMPTR25HL RSCAN0.TMPTR25.UINT8[HL]
#define RSCAN0TMPTR25HH RSCAN0.TMPTR25.UINT8[HH]
#define RSCAN0TMDF025 RSCAN0.TMDF025.UINT32
#define RSCAN0TMDF025L RSCAN0.TMDF025.UINT16[L]
#define RSCAN0TMDF025LL RSCAN0.TMDF025.UINT8[LL]
#define RSCAN0TMDF025LH RSCAN0.TMDF025.UINT8[LH]
#define RSCAN0TMDF025H RSCAN0.TMDF025.UINT16[H]
#define RSCAN0TMDF025HL RSCAN0.TMDF025.UINT8[HL]
#define RSCAN0TMDF025HH RSCAN0.TMDF025.UINT8[HH]
#define RSCAN0TMDF125 RSCAN0.TMDF125.UINT32
#define RSCAN0TMDF125L RSCAN0.TMDF125.UINT16[L]
#define RSCAN0TMDF125LL RSCAN0.TMDF125.UINT8[LL]
#define RSCAN0TMDF125LH RSCAN0.TMDF125.UINT8[LH]
#define RSCAN0TMDF125H RSCAN0.TMDF125.UINT16[H]
#define RSCAN0TMDF125HL RSCAN0.TMDF125.UINT8[HL]
#define RSCAN0TMDF125HH RSCAN0.TMDF125.UINT8[HH]
#define RSCAN0TMID26 RSCAN0.TMID26.UINT32
#define RSCAN0TMID26L RSCAN0.TMID26.UINT16[L]
#define RSCAN0TMID26LL RSCAN0.TMID26.UINT8[LL]
#define RSCAN0TMID26LH RSCAN0.TMID26.UINT8[LH]
#define RSCAN0TMID26H RSCAN0.TMID26.UINT16[H]
#define RSCAN0TMID26HL RSCAN0.TMID26.UINT8[HL]
#define RSCAN0TMID26HH RSCAN0.TMID26.UINT8[HH]
#define RSCAN0TMPTR26 RSCAN0.TMPTR26.UINT32
#define RSCAN0TMPTR26L RSCAN0.TMPTR26.UINT16[L]
#define RSCAN0TMPTR26LL RSCAN0.TMPTR26.UINT8[LL]
#define RSCAN0TMPTR26LH RSCAN0.TMPTR26.UINT8[LH]
#define RSCAN0TMPTR26H RSCAN0.TMPTR26.UINT16[H]
#define RSCAN0TMPTR26HL RSCAN0.TMPTR26.UINT8[HL]
#define RSCAN0TMPTR26HH RSCAN0.TMPTR26.UINT8[HH]
#define RSCAN0TMDF026 RSCAN0.TMDF026.UINT32
#define RSCAN0TMDF026L RSCAN0.TMDF026.UINT16[L]
#define RSCAN0TMDF026LL RSCAN0.TMDF026.UINT8[LL]
#define RSCAN0TMDF026LH RSCAN0.TMDF026.UINT8[LH]
#define RSCAN0TMDF026H RSCAN0.TMDF026.UINT16[H]
#define RSCAN0TMDF026HL RSCAN0.TMDF026.UINT8[HL]
#define RSCAN0TMDF026HH RSCAN0.TMDF026.UINT8[HH]
#define RSCAN0TMDF126 RSCAN0.TMDF126.UINT32
#define RSCAN0TMDF126L RSCAN0.TMDF126.UINT16[L]
#define RSCAN0TMDF126LL RSCAN0.TMDF126.UINT8[LL]
#define RSCAN0TMDF126LH RSCAN0.TMDF126.UINT8[LH]
#define RSCAN0TMDF126H RSCAN0.TMDF126.UINT16[H]
#define RSCAN0TMDF126HL RSCAN0.TMDF126.UINT8[HL]
#define RSCAN0TMDF126HH RSCAN0.TMDF126.UINT8[HH]
#define RSCAN0TMID27 RSCAN0.TMID27.UINT32
#define RSCAN0TMID27L RSCAN0.TMID27.UINT16[L]
#define RSCAN0TMID27LL RSCAN0.TMID27.UINT8[LL]
#define RSCAN0TMID27LH RSCAN0.TMID27.UINT8[LH]
#define RSCAN0TMID27H RSCAN0.TMID27.UINT16[H]
#define RSCAN0TMID27HL RSCAN0.TMID27.UINT8[HL]
#define RSCAN0TMID27HH RSCAN0.TMID27.UINT8[HH]
#define RSCAN0TMPTR27 RSCAN0.TMPTR27.UINT32
#define RSCAN0TMPTR27L RSCAN0.TMPTR27.UINT16[L]
#define RSCAN0TMPTR27LL RSCAN0.TMPTR27.UINT8[LL]
#define RSCAN0TMPTR27LH RSCAN0.TMPTR27.UINT8[LH]
#define RSCAN0TMPTR27H RSCAN0.TMPTR27.UINT16[H]
#define RSCAN0TMPTR27HL RSCAN0.TMPTR27.UINT8[HL]
#define RSCAN0TMPTR27HH RSCAN0.TMPTR27.UINT8[HH]
#define RSCAN0TMDF027 RSCAN0.TMDF027.UINT32
#define RSCAN0TMDF027L RSCAN0.TMDF027.UINT16[L]
#define RSCAN0TMDF027LL RSCAN0.TMDF027.UINT8[LL]
#define RSCAN0TMDF027LH RSCAN0.TMDF027.UINT8[LH]
#define RSCAN0TMDF027H RSCAN0.TMDF027.UINT16[H]
#define RSCAN0TMDF027HL RSCAN0.TMDF027.UINT8[HL]
#define RSCAN0TMDF027HH RSCAN0.TMDF027.UINT8[HH]
#define RSCAN0TMDF127 RSCAN0.TMDF127.UINT32
#define RSCAN0TMDF127L RSCAN0.TMDF127.UINT16[L]
#define RSCAN0TMDF127LL RSCAN0.TMDF127.UINT8[LL]
#define RSCAN0TMDF127LH RSCAN0.TMDF127.UINT8[LH]
#define RSCAN0TMDF127H RSCAN0.TMDF127.UINT16[H]
#define RSCAN0TMDF127HL RSCAN0.TMDF127.UINT8[HL]
#define RSCAN0TMDF127HH RSCAN0.TMDF127.UINT8[HH]
#define RSCAN0TMID28 RSCAN0.TMID28.UINT32
#define RSCAN0TMID28L RSCAN0.TMID28.UINT16[L]
#define RSCAN0TMID28LL RSCAN0.TMID28.UINT8[LL]
#define RSCAN0TMID28LH RSCAN0.TMID28.UINT8[LH]
#define RSCAN0TMID28H RSCAN0.TMID28.UINT16[H]
#define RSCAN0TMID28HL RSCAN0.TMID28.UINT8[HL]
#define RSCAN0TMID28HH RSCAN0.TMID28.UINT8[HH]
#define RSCAN0TMPTR28 RSCAN0.TMPTR28.UINT32
#define RSCAN0TMPTR28L RSCAN0.TMPTR28.UINT16[L]
#define RSCAN0TMPTR28LL RSCAN0.TMPTR28.UINT8[LL]
#define RSCAN0TMPTR28LH RSCAN0.TMPTR28.UINT8[LH]
#define RSCAN0TMPTR28H RSCAN0.TMPTR28.UINT16[H]
#define RSCAN0TMPTR28HL RSCAN0.TMPTR28.UINT8[HL]
#define RSCAN0TMPTR28HH RSCAN0.TMPTR28.UINT8[HH]
#define RSCAN0TMDF028 RSCAN0.TMDF028.UINT32
#define RSCAN0TMDF028L RSCAN0.TMDF028.UINT16[L]
#define RSCAN0TMDF028LL RSCAN0.TMDF028.UINT8[LL]
#define RSCAN0TMDF028LH RSCAN0.TMDF028.UINT8[LH]
#define RSCAN0TMDF028H RSCAN0.TMDF028.UINT16[H]
#define RSCAN0TMDF028HL RSCAN0.TMDF028.UINT8[HL]
#define RSCAN0TMDF028HH RSCAN0.TMDF028.UINT8[HH]
#define RSCAN0TMDF128 RSCAN0.TMDF128.UINT32
#define RSCAN0TMDF128L RSCAN0.TMDF128.UINT16[L]
#define RSCAN0TMDF128LL RSCAN0.TMDF128.UINT8[LL]
#define RSCAN0TMDF128LH RSCAN0.TMDF128.UINT8[LH]
#define RSCAN0TMDF128H RSCAN0.TMDF128.UINT16[H]
#define RSCAN0TMDF128HL RSCAN0.TMDF128.UINT8[HL]
#define RSCAN0TMDF128HH RSCAN0.TMDF128.UINT8[HH]
#define RSCAN0TMID29 RSCAN0.TMID29.UINT32
#define RSCAN0TMID29L RSCAN0.TMID29.UINT16[L]
#define RSCAN0TMID29LL RSCAN0.TMID29.UINT8[LL]
#define RSCAN0TMID29LH RSCAN0.TMID29.UINT8[LH]
#define RSCAN0TMID29H RSCAN0.TMID29.UINT16[H]
#define RSCAN0TMID29HL RSCAN0.TMID29.UINT8[HL]
#define RSCAN0TMID29HH RSCAN0.TMID29.UINT8[HH]
#define RSCAN0TMPTR29 RSCAN0.TMPTR29.UINT32
#define RSCAN0TMPTR29L RSCAN0.TMPTR29.UINT16[L]
#define RSCAN0TMPTR29LL RSCAN0.TMPTR29.UINT8[LL]
#define RSCAN0TMPTR29LH RSCAN0.TMPTR29.UINT8[LH]
#define RSCAN0TMPTR29H RSCAN0.TMPTR29.UINT16[H]
#define RSCAN0TMPTR29HL RSCAN0.TMPTR29.UINT8[HL]
#define RSCAN0TMPTR29HH RSCAN0.TMPTR29.UINT8[HH]
#define RSCAN0TMDF029 RSCAN0.TMDF029.UINT32
#define RSCAN0TMDF029L RSCAN0.TMDF029.UINT16[L]
#define RSCAN0TMDF029LL RSCAN0.TMDF029.UINT8[LL]
#define RSCAN0TMDF029LH RSCAN0.TMDF029.UINT8[LH]
#define RSCAN0TMDF029H RSCAN0.TMDF029.UINT16[H]
#define RSCAN0TMDF029HL RSCAN0.TMDF029.UINT8[HL]
#define RSCAN0TMDF029HH RSCAN0.TMDF029.UINT8[HH]
#define RSCAN0TMDF129 RSCAN0.TMDF129.UINT32
#define RSCAN0TMDF129L RSCAN0.TMDF129.UINT16[L]
#define RSCAN0TMDF129LL RSCAN0.TMDF129.UINT8[LL]
#define RSCAN0TMDF129LH RSCAN0.TMDF129.UINT8[LH]
#define RSCAN0TMDF129H RSCAN0.TMDF129.UINT16[H]
#define RSCAN0TMDF129HL RSCAN0.TMDF129.UINT8[HL]
#define RSCAN0TMDF129HH RSCAN0.TMDF129.UINT8[HH]
#define RSCAN0TMID30 RSCAN0.TMID30.UINT32
#define RSCAN0TMID30L RSCAN0.TMID30.UINT16[L]
#define RSCAN0TMID30LL RSCAN0.TMID30.UINT8[LL]
#define RSCAN0TMID30LH RSCAN0.TMID30.UINT8[LH]
#define RSCAN0TMID30H RSCAN0.TMID30.UINT16[H]
#define RSCAN0TMID30HL RSCAN0.TMID30.UINT8[HL]
#define RSCAN0TMID30HH RSCAN0.TMID30.UINT8[HH]
#define RSCAN0TMPTR30 RSCAN0.TMPTR30.UINT32
#define RSCAN0TMPTR30L RSCAN0.TMPTR30.UINT16[L]
#define RSCAN0TMPTR30LL RSCAN0.TMPTR30.UINT8[LL]
#define RSCAN0TMPTR30LH RSCAN0.TMPTR30.UINT8[LH]
#define RSCAN0TMPTR30H RSCAN0.TMPTR30.UINT16[H]
#define RSCAN0TMPTR30HL RSCAN0.TMPTR30.UINT8[HL]
#define RSCAN0TMPTR30HH RSCAN0.TMPTR30.UINT8[HH]
#define RSCAN0TMDF030 RSCAN0.TMDF030.UINT32
#define RSCAN0TMDF030L RSCAN0.TMDF030.UINT16[L]
#define RSCAN0TMDF030LL RSCAN0.TMDF030.UINT8[LL]
#define RSCAN0TMDF030LH RSCAN0.TMDF030.UINT8[LH]
#define RSCAN0TMDF030H RSCAN0.TMDF030.UINT16[H]
#define RSCAN0TMDF030HL RSCAN0.TMDF030.UINT8[HL]
#define RSCAN0TMDF030HH RSCAN0.TMDF030.UINT8[HH]
#define RSCAN0TMDF130 RSCAN0.TMDF130.UINT32
#define RSCAN0TMDF130L RSCAN0.TMDF130.UINT16[L]
#define RSCAN0TMDF130LL RSCAN0.TMDF130.UINT8[LL]
#define RSCAN0TMDF130LH RSCAN0.TMDF130.UINT8[LH]
#define RSCAN0TMDF130H RSCAN0.TMDF130.UINT16[H]
#define RSCAN0TMDF130HL RSCAN0.TMDF130.UINT8[HL]
#define RSCAN0TMDF130HH RSCAN0.TMDF130.UINT8[HH]
#define RSCAN0TMID31 RSCAN0.TMID31.UINT32
#define RSCAN0TMID31L RSCAN0.TMID31.UINT16[L]
#define RSCAN0TMID31LL RSCAN0.TMID31.UINT8[LL]
#define RSCAN0TMID31LH RSCAN0.TMID31.UINT8[LH]
#define RSCAN0TMID31H RSCAN0.TMID31.UINT16[H]
#define RSCAN0TMID31HL RSCAN0.TMID31.UINT8[HL]
#define RSCAN0TMID31HH RSCAN0.TMID31.UINT8[HH]
#define RSCAN0TMPTR31 RSCAN0.TMPTR31.UINT32
#define RSCAN0TMPTR31L RSCAN0.TMPTR31.UINT16[L]
#define RSCAN0TMPTR31LL RSCAN0.TMPTR31.UINT8[LL]
#define RSCAN0TMPTR31LH RSCAN0.TMPTR31.UINT8[LH]
#define RSCAN0TMPTR31H RSCAN0.TMPTR31.UINT16[H]
#define RSCAN0TMPTR31HL RSCAN0.TMPTR31.UINT8[HL]
#define RSCAN0TMPTR31HH RSCAN0.TMPTR31.UINT8[HH]
#define RSCAN0TMDF031 RSCAN0.TMDF031.UINT32
#define RSCAN0TMDF031L RSCAN0.TMDF031.UINT16[L]
#define RSCAN0TMDF031LL RSCAN0.TMDF031.UINT8[LL]
#define RSCAN0TMDF031LH RSCAN0.TMDF031.UINT8[LH]
#define RSCAN0TMDF031H RSCAN0.TMDF031.UINT16[H]
#define RSCAN0TMDF031HL RSCAN0.TMDF031.UINT8[HL]
#define RSCAN0TMDF031HH RSCAN0.TMDF031.UINT8[HH]
#define RSCAN0TMDF131 RSCAN0.TMDF131.UINT32
#define RSCAN0TMDF131L RSCAN0.TMDF131.UINT16[L]
#define RSCAN0TMDF131LL RSCAN0.TMDF131.UINT8[LL]
#define RSCAN0TMDF131LH RSCAN0.TMDF131.UINT8[LH]
#define RSCAN0TMDF131H RSCAN0.TMDF131.UINT16[H]
#define RSCAN0TMDF131HL RSCAN0.TMDF131.UINT8[HL]
#define RSCAN0TMDF131HH RSCAN0.TMDF131.UINT8[HH]
#define RSCAN0TMID32 RSCAN0.TMID32.UINT32
#define RSCAN0TMID32L RSCAN0.TMID32.UINT16[L]
#define RSCAN0TMID32LL RSCAN0.TMID32.UINT8[LL]
#define RSCAN0TMID32LH RSCAN0.TMID32.UINT8[LH]
#define RSCAN0TMID32H RSCAN0.TMID32.UINT16[H]
#define RSCAN0TMID32HL RSCAN0.TMID32.UINT8[HL]
#define RSCAN0TMID32HH RSCAN0.TMID32.UINT8[HH]
#define RSCAN0TMPTR32 RSCAN0.TMPTR32.UINT32
#define RSCAN0TMPTR32L RSCAN0.TMPTR32.UINT16[L]
#define RSCAN0TMPTR32LL RSCAN0.TMPTR32.UINT8[LL]
#define RSCAN0TMPTR32LH RSCAN0.TMPTR32.UINT8[LH]
#define RSCAN0TMPTR32H RSCAN0.TMPTR32.UINT16[H]
#define RSCAN0TMPTR32HL RSCAN0.TMPTR32.UINT8[HL]
#define RSCAN0TMPTR32HH RSCAN0.TMPTR32.UINT8[HH]
#define RSCAN0TMDF032 RSCAN0.TMDF032.UINT32
#define RSCAN0TMDF032L RSCAN0.TMDF032.UINT16[L]
#define RSCAN0TMDF032LL RSCAN0.TMDF032.UINT8[LL]
#define RSCAN0TMDF032LH RSCAN0.TMDF032.UINT8[LH]
#define RSCAN0TMDF032H RSCAN0.TMDF032.UINT16[H]
#define RSCAN0TMDF032HL RSCAN0.TMDF032.UINT8[HL]
#define RSCAN0TMDF032HH RSCAN0.TMDF032.UINT8[HH]
#define RSCAN0TMDF132 RSCAN0.TMDF132.UINT32
#define RSCAN0TMDF132L RSCAN0.TMDF132.UINT16[L]
#define RSCAN0TMDF132LL RSCAN0.TMDF132.UINT8[LL]
#define RSCAN0TMDF132LH RSCAN0.TMDF132.UINT8[LH]
#define RSCAN0TMDF132H RSCAN0.TMDF132.UINT16[H]
#define RSCAN0TMDF132HL RSCAN0.TMDF132.UINT8[HL]
#define RSCAN0TMDF132HH RSCAN0.TMDF132.UINT8[HH]
#define RSCAN0TMID33 RSCAN0.TMID33.UINT32
#define RSCAN0TMID33L RSCAN0.TMID33.UINT16[L]
#define RSCAN0TMID33LL RSCAN0.TMID33.UINT8[LL]
#define RSCAN0TMID33LH RSCAN0.TMID33.UINT8[LH]
#define RSCAN0TMID33H RSCAN0.TMID33.UINT16[H]
#define RSCAN0TMID33HL RSCAN0.TMID33.UINT8[HL]
#define RSCAN0TMID33HH RSCAN0.TMID33.UINT8[HH]
#define RSCAN0TMPTR33 RSCAN0.TMPTR33.UINT32
#define RSCAN0TMPTR33L RSCAN0.TMPTR33.UINT16[L]
#define RSCAN0TMPTR33LL RSCAN0.TMPTR33.UINT8[LL]
#define RSCAN0TMPTR33LH RSCAN0.TMPTR33.UINT8[LH]
#define RSCAN0TMPTR33H RSCAN0.TMPTR33.UINT16[H]
#define RSCAN0TMPTR33HL RSCAN0.TMPTR33.UINT8[HL]
#define RSCAN0TMPTR33HH RSCAN0.TMPTR33.UINT8[HH]
#define RSCAN0TMDF033 RSCAN0.TMDF033.UINT32
#define RSCAN0TMDF033L RSCAN0.TMDF033.UINT16[L]
#define RSCAN0TMDF033LL RSCAN0.TMDF033.UINT8[LL]
#define RSCAN0TMDF033LH RSCAN0.TMDF033.UINT8[LH]
#define RSCAN0TMDF033H RSCAN0.TMDF033.UINT16[H]
#define RSCAN0TMDF033HL RSCAN0.TMDF033.UINT8[HL]
#define RSCAN0TMDF033HH RSCAN0.TMDF033.UINT8[HH]
#define RSCAN0TMDF133 RSCAN0.TMDF133.UINT32
#define RSCAN0TMDF133L RSCAN0.TMDF133.UINT16[L]
#define RSCAN0TMDF133LL RSCAN0.TMDF133.UINT8[LL]
#define RSCAN0TMDF133LH RSCAN0.TMDF133.UINT8[LH]
#define RSCAN0TMDF133H RSCAN0.TMDF133.UINT16[H]
#define RSCAN0TMDF133HL RSCAN0.TMDF133.UINT8[HL]
#define RSCAN0TMDF133HH RSCAN0.TMDF133.UINT8[HH]
#define RSCAN0TMID34 RSCAN0.TMID34.UINT32
#define RSCAN0TMID34L RSCAN0.TMID34.UINT16[L]
#define RSCAN0TMID34LL RSCAN0.TMID34.UINT8[LL]
#define RSCAN0TMID34LH RSCAN0.TMID34.UINT8[LH]
#define RSCAN0TMID34H RSCAN0.TMID34.UINT16[H]
#define RSCAN0TMID34HL RSCAN0.TMID34.UINT8[HL]
#define RSCAN0TMID34HH RSCAN0.TMID34.UINT8[HH]
#define RSCAN0TMPTR34 RSCAN0.TMPTR34.UINT32
#define RSCAN0TMPTR34L RSCAN0.TMPTR34.UINT16[L]
#define RSCAN0TMPTR34LL RSCAN0.TMPTR34.UINT8[LL]
#define RSCAN0TMPTR34LH RSCAN0.TMPTR34.UINT8[LH]
#define RSCAN0TMPTR34H RSCAN0.TMPTR34.UINT16[H]
#define RSCAN0TMPTR34HL RSCAN0.TMPTR34.UINT8[HL]
#define RSCAN0TMPTR34HH RSCAN0.TMPTR34.UINT8[HH]
#define RSCAN0TMDF034 RSCAN0.TMDF034.UINT32
#define RSCAN0TMDF034L RSCAN0.TMDF034.UINT16[L]
#define RSCAN0TMDF034LL RSCAN0.TMDF034.UINT8[LL]
#define RSCAN0TMDF034LH RSCAN0.TMDF034.UINT8[LH]
#define RSCAN0TMDF034H RSCAN0.TMDF034.UINT16[H]
#define RSCAN0TMDF034HL RSCAN0.TMDF034.UINT8[HL]
#define RSCAN0TMDF034HH RSCAN0.TMDF034.UINT8[HH]
#define RSCAN0TMDF134 RSCAN0.TMDF134.UINT32
#define RSCAN0TMDF134L RSCAN0.TMDF134.UINT16[L]
#define RSCAN0TMDF134LL RSCAN0.TMDF134.UINT8[LL]
#define RSCAN0TMDF134LH RSCAN0.TMDF134.UINT8[LH]
#define RSCAN0TMDF134H RSCAN0.TMDF134.UINT16[H]
#define RSCAN0TMDF134HL RSCAN0.TMDF134.UINT8[HL]
#define RSCAN0TMDF134HH RSCAN0.TMDF134.UINT8[HH]
#define RSCAN0TMID35 RSCAN0.TMID35.UINT32
#define RSCAN0TMID35L RSCAN0.TMID35.UINT16[L]
#define RSCAN0TMID35LL RSCAN0.TMID35.UINT8[LL]
#define RSCAN0TMID35LH RSCAN0.TMID35.UINT8[LH]
#define RSCAN0TMID35H RSCAN0.TMID35.UINT16[H]
#define RSCAN0TMID35HL RSCAN0.TMID35.UINT8[HL]
#define RSCAN0TMID35HH RSCAN0.TMID35.UINT8[HH]
#define RSCAN0TMPTR35 RSCAN0.TMPTR35.UINT32
#define RSCAN0TMPTR35L RSCAN0.TMPTR35.UINT16[L]
#define RSCAN0TMPTR35LL RSCAN0.TMPTR35.UINT8[LL]
#define RSCAN0TMPTR35LH RSCAN0.TMPTR35.UINT8[LH]
#define RSCAN0TMPTR35H RSCAN0.TMPTR35.UINT16[H]
#define RSCAN0TMPTR35HL RSCAN0.TMPTR35.UINT8[HL]
#define RSCAN0TMPTR35HH RSCAN0.TMPTR35.UINT8[HH]
#define RSCAN0TMDF035 RSCAN0.TMDF035.UINT32
#define RSCAN0TMDF035L RSCAN0.TMDF035.UINT16[L]
#define RSCAN0TMDF035LL RSCAN0.TMDF035.UINT8[LL]
#define RSCAN0TMDF035LH RSCAN0.TMDF035.UINT8[LH]
#define RSCAN0TMDF035H RSCAN0.TMDF035.UINT16[H]
#define RSCAN0TMDF035HL RSCAN0.TMDF035.UINT8[HL]
#define RSCAN0TMDF035HH RSCAN0.TMDF035.UINT8[HH]
#define RSCAN0TMDF135 RSCAN0.TMDF135.UINT32
#define RSCAN0TMDF135L RSCAN0.TMDF135.UINT16[L]
#define RSCAN0TMDF135LL RSCAN0.TMDF135.UINT8[LL]
#define RSCAN0TMDF135LH RSCAN0.TMDF135.UINT8[LH]
#define RSCAN0TMDF135H RSCAN0.TMDF135.UINT16[H]
#define RSCAN0TMDF135HL RSCAN0.TMDF135.UINT8[HL]
#define RSCAN0TMDF135HH RSCAN0.TMDF135.UINT8[HH]
#define RSCAN0TMID36 RSCAN0.TMID36.UINT32
#define RSCAN0TMID36L RSCAN0.TMID36.UINT16[L]
#define RSCAN0TMID36LL RSCAN0.TMID36.UINT8[LL]
#define RSCAN0TMID36LH RSCAN0.TMID36.UINT8[LH]
#define RSCAN0TMID36H RSCAN0.TMID36.UINT16[H]
#define RSCAN0TMID36HL RSCAN0.TMID36.UINT8[HL]
#define RSCAN0TMID36HH RSCAN0.TMID36.UINT8[HH]
#define RSCAN0TMPTR36 RSCAN0.TMPTR36.UINT32
#define RSCAN0TMPTR36L RSCAN0.TMPTR36.UINT16[L]
#define RSCAN0TMPTR36LL RSCAN0.TMPTR36.UINT8[LL]
#define RSCAN0TMPTR36LH RSCAN0.TMPTR36.UINT8[LH]
#define RSCAN0TMPTR36H RSCAN0.TMPTR36.UINT16[H]
#define RSCAN0TMPTR36HL RSCAN0.TMPTR36.UINT8[HL]
#define RSCAN0TMPTR36HH RSCAN0.TMPTR36.UINT8[HH]
#define RSCAN0TMDF036 RSCAN0.TMDF036.UINT32
#define RSCAN0TMDF036L RSCAN0.TMDF036.UINT16[L]
#define RSCAN0TMDF036LL RSCAN0.TMDF036.UINT8[LL]
#define RSCAN0TMDF036LH RSCAN0.TMDF036.UINT8[LH]
#define RSCAN0TMDF036H RSCAN0.TMDF036.UINT16[H]
#define RSCAN0TMDF036HL RSCAN0.TMDF036.UINT8[HL]
#define RSCAN0TMDF036HH RSCAN0.TMDF036.UINT8[HH]
#define RSCAN0TMDF136 RSCAN0.TMDF136.UINT32
#define RSCAN0TMDF136L RSCAN0.TMDF136.UINT16[L]
#define RSCAN0TMDF136LL RSCAN0.TMDF136.UINT8[LL]
#define RSCAN0TMDF136LH RSCAN0.TMDF136.UINT8[LH]
#define RSCAN0TMDF136H RSCAN0.TMDF136.UINT16[H]
#define RSCAN0TMDF136HL RSCAN0.TMDF136.UINT8[HL]
#define RSCAN0TMDF136HH RSCAN0.TMDF136.UINT8[HH]
#define RSCAN0TMID37 RSCAN0.TMID37.UINT32
#define RSCAN0TMID37L RSCAN0.TMID37.UINT16[L]
#define RSCAN0TMID37LL RSCAN0.TMID37.UINT8[LL]
#define RSCAN0TMID37LH RSCAN0.TMID37.UINT8[LH]
#define RSCAN0TMID37H RSCAN0.TMID37.UINT16[H]
#define RSCAN0TMID37HL RSCAN0.TMID37.UINT8[HL]
#define RSCAN0TMID37HH RSCAN0.TMID37.UINT8[HH]
#define RSCAN0TMPTR37 RSCAN0.TMPTR37.UINT32
#define RSCAN0TMPTR37L RSCAN0.TMPTR37.UINT16[L]
#define RSCAN0TMPTR37LL RSCAN0.TMPTR37.UINT8[LL]
#define RSCAN0TMPTR37LH RSCAN0.TMPTR37.UINT8[LH]
#define RSCAN0TMPTR37H RSCAN0.TMPTR37.UINT16[H]
#define RSCAN0TMPTR37HL RSCAN0.TMPTR37.UINT8[HL]
#define RSCAN0TMPTR37HH RSCAN0.TMPTR37.UINT8[HH]
#define RSCAN0TMDF037 RSCAN0.TMDF037.UINT32
#define RSCAN0TMDF037L RSCAN0.TMDF037.UINT16[L]
#define RSCAN0TMDF037LL RSCAN0.TMDF037.UINT8[LL]
#define RSCAN0TMDF037LH RSCAN0.TMDF037.UINT8[LH]
#define RSCAN0TMDF037H RSCAN0.TMDF037.UINT16[H]
#define RSCAN0TMDF037HL RSCAN0.TMDF037.UINT8[HL]
#define RSCAN0TMDF037HH RSCAN0.TMDF037.UINT8[HH]
#define RSCAN0TMDF137 RSCAN0.TMDF137.UINT32
#define RSCAN0TMDF137L RSCAN0.TMDF137.UINT16[L]
#define RSCAN0TMDF137LL RSCAN0.TMDF137.UINT8[LL]
#define RSCAN0TMDF137LH RSCAN0.TMDF137.UINT8[LH]
#define RSCAN0TMDF137H RSCAN0.TMDF137.UINT16[H]
#define RSCAN0TMDF137HL RSCAN0.TMDF137.UINT8[HL]
#define RSCAN0TMDF137HH RSCAN0.TMDF137.UINT8[HH]
#define RSCAN0TMID38 RSCAN0.TMID38.UINT32
#define RSCAN0TMID38L RSCAN0.TMID38.UINT16[L]
#define RSCAN0TMID38LL RSCAN0.TMID38.UINT8[LL]
#define RSCAN0TMID38LH RSCAN0.TMID38.UINT8[LH]
#define RSCAN0TMID38H RSCAN0.TMID38.UINT16[H]
#define RSCAN0TMID38HL RSCAN0.TMID38.UINT8[HL]
#define RSCAN0TMID38HH RSCAN0.TMID38.UINT8[HH]
#define RSCAN0TMPTR38 RSCAN0.TMPTR38.UINT32
#define RSCAN0TMPTR38L RSCAN0.TMPTR38.UINT16[L]
#define RSCAN0TMPTR38LL RSCAN0.TMPTR38.UINT8[LL]
#define RSCAN0TMPTR38LH RSCAN0.TMPTR38.UINT8[LH]
#define RSCAN0TMPTR38H RSCAN0.TMPTR38.UINT16[H]
#define RSCAN0TMPTR38HL RSCAN0.TMPTR38.UINT8[HL]
#define RSCAN0TMPTR38HH RSCAN0.TMPTR38.UINT8[HH]
#define RSCAN0TMDF038 RSCAN0.TMDF038.UINT32
#define RSCAN0TMDF038L RSCAN0.TMDF038.UINT16[L]
#define RSCAN0TMDF038LL RSCAN0.TMDF038.UINT8[LL]
#define RSCAN0TMDF038LH RSCAN0.TMDF038.UINT8[LH]
#define RSCAN0TMDF038H RSCAN0.TMDF038.UINT16[H]
#define RSCAN0TMDF038HL RSCAN0.TMDF038.UINT8[HL]
#define RSCAN0TMDF038HH RSCAN0.TMDF038.UINT8[HH]
#define RSCAN0TMDF138 RSCAN0.TMDF138.UINT32
#define RSCAN0TMDF138L RSCAN0.TMDF138.UINT16[L]
#define RSCAN0TMDF138LL RSCAN0.TMDF138.UINT8[LL]
#define RSCAN0TMDF138LH RSCAN0.TMDF138.UINT8[LH]
#define RSCAN0TMDF138H RSCAN0.TMDF138.UINT16[H]
#define RSCAN0TMDF138HL RSCAN0.TMDF138.UINT8[HL]
#define RSCAN0TMDF138HH RSCAN0.TMDF138.UINT8[HH]
#define RSCAN0TMID39 RSCAN0.TMID39.UINT32
#define RSCAN0TMID39L RSCAN0.TMID39.UINT16[L]
#define RSCAN0TMID39LL RSCAN0.TMID39.UINT8[LL]
#define RSCAN0TMID39LH RSCAN0.TMID39.UINT8[LH]
#define RSCAN0TMID39H RSCAN0.TMID39.UINT16[H]
#define RSCAN0TMID39HL RSCAN0.TMID39.UINT8[HL]
#define RSCAN0TMID39HH RSCAN0.TMID39.UINT8[HH]
#define RSCAN0TMPTR39 RSCAN0.TMPTR39.UINT32
#define RSCAN0TMPTR39L RSCAN0.TMPTR39.UINT16[L]
#define RSCAN0TMPTR39LL RSCAN0.TMPTR39.UINT8[LL]
#define RSCAN0TMPTR39LH RSCAN0.TMPTR39.UINT8[LH]
#define RSCAN0TMPTR39H RSCAN0.TMPTR39.UINT16[H]
#define RSCAN0TMPTR39HL RSCAN0.TMPTR39.UINT8[HL]
#define RSCAN0TMPTR39HH RSCAN0.TMPTR39.UINT8[HH]
#define RSCAN0TMDF039 RSCAN0.TMDF039.UINT32
#define RSCAN0TMDF039L RSCAN0.TMDF039.UINT16[L]
#define RSCAN0TMDF039LL RSCAN0.TMDF039.UINT8[LL]
#define RSCAN0TMDF039LH RSCAN0.TMDF039.UINT8[LH]
#define RSCAN0TMDF039H RSCAN0.TMDF039.UINT16[H]
#define RSCAN0TMDF039HL RSCAN0.TMDF039.UINT8[HL]
#define RSCAN0TMDF039HH RSCAN0.TMDF039.UINT8[HH]
#define RSCAN0TMDF139 RSCAN0.TMDF139.UINT32
#define RSCAN0TMDF139L RSCAN0.TMDF139.UINT16[L]
#define RSCAN0TMDF139LL RSCAN0.TMDF139.UINT8[LL]
#define RSCAN0TMDF139LH RSCAN0.TMDF139.UINT8[LH]
#define RSCAN0TMDF139H RSCAN0.TMDF139.UINT16[H]
#define RSCAN0TMDF139HL RSCAN0.TMDF139.UINT8[HL]
#define RSCAN0TMDF139HH RSCAN0.TMDF139.UINT8[HH]
#define RSCAN0TMID40 RSCAN0.TMID40.UINT32
#define RSCAN0TMID40L RSCAN0.TMID40.UINT16[L]
#define RSCAN0TMID40LL RSCAN0.TMID40.UINT8[LL]
#define RSCAN0TMID40LH RSCAN0.TMID40.UINT8[LH]
#define RSCAN0TMID40H RSCAN0.TMID40.UINT16[H]
#define RSCAN0TMID40HL RSCAN0.TMID40.UINT8[HL]
#define RSCAN0TMID40HH RSCAN0.TMID40.UINT8[HH]
#define RSCAN0TMPTR40 RSCAN0.TMPTR40.UINT32
#define RSCAN0TMPTR40L RSCAN0.TMPTR40.UINT16[L]
#define RSCAN0TMPTR40LL RSCAN0.TMPTR40.UINT8[LL]
#define RSCAN0TMPTR40LH RSCAN0.TMPTR40.UINT8[LH]
#define RSCAN0TMPTR40H RSCAN0.TMPTR40.UINT16[H]
#define RSCAN0TMPTR40HL RSCAN0.TMPTR40.UINT8[HL]
#define RSCAN0TMPTR40HH RSCAN0.TMPTR40.UINT8[HH]
#define RSCAN0TMDF040 RSCAN0.TMDF040.UINT32
#define RSCAN0TMDF040L RSCAN0.TMDF040.UINT16[L]
#define RSCAN0TMDF040LL RSCAN0.TMDF040.UINT8[LL]
#define RSCAN0TMDF040LH RSCAN0.TMDF040.UINT8[LH]
#define RSCAN0TMDF040H RSCAN0.TMDF040.UINT16[H]
#define RSCAN0TMDF040HL RSCAN0.TMDF040.UINT8[HL]
#define RSCAN0TMDF040HH RSCAN0.TMDF040.UINT8[HH]
#define RSCAN0TMDF140 RSCAN0.TMDF140.UINT32
#define RSCAN0TMDF140L RSCAN0.TMDF140.UINT16[L]
#define RSCAN0TMDF140LL RSCAN0.TMDF140.UINT8[LL]
#define RSCAN0TMDF140LH RSCAN0.TMDF140.UINT8[LH]
#define RSCAN0TMDF140H RSCAN0.TMDF140.UINT16[H]
#define RSCAN0TMDF140HL RSCAN0.TMDF140.UINT8[HL]
#define RSCAN0TMDF140HH RSCAN0.TMDF140.UINT8[HH]
#define RSCAN0TMID41 RSCAN0.TMID41.UINT32
#define RSCAN0TMID41L RSCAN0.TMID41.UINT16[L]
#define RSCAN0TMID41LL RSCAN0.TMID41.UINT8[LL]
#define RSCAN0TMID41LH RSCAN0.TMID41.UINT8[LH]
#define RSCAN0TMID41H RSCAN0.TMID41.UINT16[H]
#define RSCAN0TMID41HL RSCAN0.TMID41.UINT8[HL]
#define RSCAN0TMID41HH RSCAN0.TMID41.UINT8[HH]
#define RSCAN0TMPTR41 RSCAN0.TMPTR41.UINT32
#define RSCAN0TMPTR41L RSCAN0.TMPTR41.UINT16[L]
#define RSCAN0TMPTR41LL RSCAN0.TMPTR41.UINT8[LL]
#define RSCAN0TMPTR41LH RSCAN0.TMPTR41.UINT8[LH]
#define RSCAN0TMPTR41H RSCAN0.TMPTR41.UINT16[H]
#define RSCAN0TMPTR41HL RSCAN0.TMPTR41.UINT8[HL]
#define RSCAN0TMPTR41HH RSCAN0.TMPTR41.UINT8[HH]
#define RSCAN0TMDF041 RSCAN0.TMDF041.UINT32
#define RSCAN0TMDF041L RSCAN0.TMDF041.UINT16[L]
#define RSCAN0TMDF041LL RSCAN0.TMDF041.UINT8[LL]
#define RSCAN0TMDF041LH RSCAN0.TMDF041.UINT8[LH]
#define RSCAN0TMDF041H RSCAN0.TMDF041.UINT16[H]
#define RSCAN0TMDF041HL RSCAN0.TMDF041.UINT8[HL]
#define RSCAN0TMDF041HH RSCAN0.TMDF041.UINT8[HH]
#define RSCAN0TMDF141 RSCAN0.TMDF141.UINT32
#define RSCAN0TMDF141L RSCAN0.TMDF141.UINT16[L]
#define RSCAN0TMDF141LL RSCAN0.TMDF141.UINT8[LL]
#define RSCAN0TMDF141LH RSCAN0.TMDF141.UINT8[LH]
#define RSCAN0TMDF141H RSCAN0.TMDF141.UINT16[H]
#define RSCAN0TMDF141HL RSCAN0.TMDF141.UINT8[HL]
#define RSCAN0TMDF141HH RSCAN0.TMDF141.UINT8[HH]
#define RSCAN0TMID42 RSCAN0.TMID42.UINT32
#define RSCAN0TMID42L RSCAN0.TMID42.UINT16[L]
#define RSCAN0TMID42LL RSCAN0.TMID42.UINT8[LL]
#define RSCAN0TMID42LH RSCAN0.TMID42.UINT8[LH]
#define RSCAN0TMID42H RSCAN0.TMID42.UINT16[H]
#define RSCAN0TMID42HL RSCAN0.TMID42.UINT8[HL]
#define RSCAN0TMID42HH RSCAN0.TMID42.UINT8[HH]
#define RSCAN0TMPTR42 RSCAN0.TMPTR42.UINT32
#define RSCAN0TMPTR42L RSCAN0.TMPTR42.UINT16[L]
#define RSCAN0TMPTR42LL RSCAN0.TMPTR42.UINT8[LL]
#define RSCAN0TMPTR42LH RSCAN0.TMPTR42.UINT8[LH]
#define RSCAN0TMPTR42H RSCAN0.TMPTR42.UINT16[H]
#define RSCAN0TMPTR42HL RSCAN0.TMPTR42.UINT8[HL]
#define RSCAN0TMPTR42HH RSCAN0.TMPTR42.UINT8[HH]
#define RSCAN0TMDF042 RSCAN0.TMDF042.UINT32
#define RSCAN0TMDF042L RSCAN0.TMDF042.UINT16[L]
#define RSCAN0TMDF042LL RSCAN0.TMDF042.UINT8[LL]
#define RSCAN0TMDF042LH RSCAN0.TMDF042.UINT8[LH]
#define RSCAN0TMDF042H RSCAN0.TMDF042.UINT16[H]
#define RSCAN0TMDF042HL RSCAN0.TMDF042.UINT8[HL]
#define RSCAN0TMDF042HH RSCAN0.TMDF042.UINT8[HH]
#define RSCAN0TMDF142 RSCAN0.TMDF142.UINT32
#define RSCAN0TMDF142L RSCAN0.TMDF142.UINT16[L]
#define RSCAN0TMDF142LL RSCAN0.TMDF142.UINT8[LL]
#define RSCAN0TMDF142LH RSCAN0.TMDF142.UINT8[LH]
#define RSCAN0TMDF142H RSCAN0.TMDF142.UINT16[H]
#define RSCAN0TMDF142HL RSCAN0.TMDF142.UINT8[HL]
#define RSCAN0TMDF142HH RSCAN0.TMDF142.UINT8[HH]
#define RSCAN0TMID43 RSCAN0.TMID43.UINT32
#define RSCAN0TMID43L RSCAN0.TMID43.UINT16[L]
#define RSCAN0TMID43LL RSCAN0.TMID43.UINT8[LL]
#define RSCAN0TMID43LH RSCAN0.TMID43.UINT8[LH]
#define RSCAN0TMID43H RSCAN0.TMID43.UINT16[H]
#define RSCAN0TMID43HL RSCAN0.TMID43.UINT8[HL]
#define RSCAN0TMID43HH RSCAN0.TMID43.UINT8[HH]
#define RSCAN0TMPTR43 RSCAN0.TMPTR43.UINT32
#define RSCAN0TMPTR43L RSCAN0.TMPTR43.UINT16[L]
#define RSCAN0TMPTR43LL RSCAN0.TMPTR43.UINT8[LL]
#define RSCAN0TMPTR43LH RSCAN0.TMPTR43.UINT8[LH]
#define RSCAN0TMPTR43H RSCAN0.TMPTR43.UINT16[H]
#define RSCAN0TMPTR43HL RSCAN0.TMPTR43.UINT8[HL]
#define RSCAN0TMPTR43HH RSCAN0.TMPTR43.UINT8[HH]
#define RSCAN0TMDF043 RSCAN0.TMDF043.UINT32
#define RSCAN0TMDF043L RSCAN0.TMDF043.UINT16[L]
#define RSCAN0TMDF043LL RSCAN0.TMDF043.UINT8[LL]
#define RSCAN0TMDF043LH RSCAN0.TMDF043.UINT8[LH]
#define RSCAN0TMDF043H RSCAN0.TMDF043.UINT16[H]
#define RSCAN0TMDF043HL RSCAN0.TMDF043.UINT8[HL]
#define RSCAN0TMDF043HH RSCAN0.TMDF043.UINT8[HH]
#define RSCAN0TMDF143 RSCAN0.TMDF143.UINT32
#define RSCAN0TMDF143L RSCAN0.TMDF143.UINT16[L]
#define RSCAN0TMDF143LL RSCAN0.TMDF143.UINT8[LL]
#define RSCAN0TMDF143LH RSCAN0.TMDF143.UINT8[LH]
#define RSCAN0TMDF143H RSCAN0.TMDF143.UINT16[H]
#define RSCAN0TMDF143HL RSCAN0.TMDF143.UINT8[HL]
#define RSCAN0TMDF143HH RSCAN0.TMDF143.UINT8[HH]
#define RSCAN0TMID44 RSCAN0.TMID44.UINT32
#define RSCAN0TMID44L RSCAN0.TMID44.UINT16[L]
#define RSCAN0TMID44LL RSCAN0.TMID44.UINT8[LL]
#define RSCAN0TMID44LH RSCAN0.TMID44.UINT8[LH]
#define RSCAN0TMID44H RSCAN0.TMID44.UINT16[H]
#define RSCAN0TMID44HL RSCAN0.TMID44.UINT8[HL]
#define RSCAN0TMID44HH RSCAN0.TMID44.UINT8[HH]
#define RSCAN0TMPTR44 RSCAN0.TMPTR44.UINT32
#define RSCAN0TMPTR44L RSCAN0.TMPTR44.UINT16[L]
#define RSCAN0TMPTR44LL RSCAN0.TMPTR44.UINT8[LL]
#define RSCAN0TMPTR44LH RSCAN0.TMPTR44.UINT8[LH]
#define RSCAN0TMPTR44H RSCAN0.TMPTR44.UINT16[H]
#define RSCAN0TMPTR44HL RSCAN0.TMPTR44.UINT8[HL]
#define RSCAN0TMPTR44HH RSCAN0.TMPTR44.UINT8[HH]
#define RSCAN0TMDF044 RSCAN0.TMDF044.UINT32
#define RSCAN0TMDF044L RSCAN0.TMDF044.UINT16[L]
#define RSCAN0TMDF044LL RSCAN0.TMDF044.UINT8[LL]
#define RSCAN0TMDF044LH RSCAN0.TMDF044.UINT8[LH]
#define RSCAN0TMDF044H RSCAN0.TMDF044.UINT16[H]
#define RSCAN0TMDF044HL RSCAN0.TMDF044.UINT8[HL]
#define RSCAN0TMDF044HH RSCAN0.TMDF044.UINT8[HH]
#define RSCAN0TMDF144 RSCAN0.TMDF144.UINT32
#define RSCAN0TMDF144L RSCAN0.TMDF144.UINT16[L]
#define RSCAN0TMDF144LL RSCAN0.TMDF144.UINT8[LL]
#define RSCAN0TMDF144LH RSCAN0.TMDF144.UINT8[LH]
#define RSCAN0TMDF144H RSCAN0.TMDF144.UINT16[H]
#define RSCAN0TMDF144HL RSCAN0.TMDF144.UINT8[HL]
#define RSCAN0TMDF144HH RSCAN0.TMDF144.UINT8[HH]
#define RSCAN0TMID45 RSCAN0.TMID45.UINT32
#define RSCAN0TMID45L RSCAN0.TMID45.UINT16[L]
#define RSCAN0TMID45LL RSCAN0.TMID45.UINT8[LL]
#define RSCAN0TMID45LH RSCAN0.TMID45.UINT8[LH]
#define RSCAN0TMID45H RSCAN0.TMID45.UINT16[H]
#define RSCAN0TMID45HL RSCAN0.TMID45.UINT8[HL]
#define RSCAN0TMID45HH RSCAN0.TMID45.UINT8[HH]
#define RSCAN0TMPTR45 RSCAN0.TMPTR45.UINT32
#define RSCAN0TMPTR45L RSCAN0.TMPTR45.UINT16[L]
#define RSCAN0TMPTR45LL RSCAN0.TMPTR45.UINT8[LL]
#define RSCAN0TMPTR45LH RSCAN0.TMPTR45.UINT8[LH]
#define RSCAN0TMPTR45H RSCAN0.TMPTR45.UINT16[H]
#define RSCAN0TMPTR45HL RSCAN0.TMPTR45.UINT8[HL]
#define RSCAN0TMPTR45HH RSCAN0.TMPTR45.UINT8[HH]
#define RSCAN0TMDF045 RSCAN0.TMDF045.UINT32
#define RSCAN0TMDF045L RSCAN0.TMDF045.UINT16[L]
#define RSCAN0TMDF045LL RSCAN0.TMDF045.UINT8[LL]
#define RSCAN0TMDF045LH RSCAN0.TMDF045.UINT8[LH]
#define RSCAN0TMDF045H RSCAN0.TMDF045.UINT16[H]
#define RSCAN0TMDF045HL RSCAN0.TMDF045.UINT8[HL]
#define RSCAN0TMDF045HH RSCAN0.TMDF045.UINT8[HH]
#define RSCAN0TMDF145 RSCAN0.TMDF145.UINT32
#define RSCAN0TMDF145L RSCAN0.TMDF145.UINT16[L]
#define RSCAN0TMDF145LL RSCAN0.TMDF145.UINT8[LL]
#define RSCAN0TMDF145LH RSCAN0.TMDF145.UINT8[LH]
#define RSCAN0TMDF145H RSCAN0.TMDF145.UINT16[H]
#define RSCAN0TMDF145HL RSCAN0.TMDF145.UINT8[HL]
#define RSCAN0TMDF145HH RSCAN0.TMDF145.UINT8[HH]
#define RSCAN0TMID46 RSCAN0.TMID46.UINT32
#define RSCAN0TMID46L RSCAN0.TMID46.UINT16[L]
#define RSCAN0TMID46LL RSCAN0.TMID46.UINT8[LL]
#define RSCAN0TMID46LH RSCAN0.TMID46.UINT8[LH]
#define RSCAN0TMID46H RSCAN0.TMID46.UINT16[H]
#define RSCAN0TMID46HL RSCAN0.TMID46.UINT8[HL]
#define RSCAN0TMID46HH RSCAN0.TMID46.UINT8[HH]
#define RSCAN0TMPTR46 RSCAN0.TMPTR46.UINT32
#define RSCAN0TMPTR46L RSCAN0.TMPTR46.UINT16[L]
#define RSCAN0TMPTR46LL RSCAN0.TMPTR46.UINT8[LL]
#define RSCAN0TMPTR46LH RSCAN0.TMPTR46.UINT8[LH]
#define RSCAN0TMPTR46H RSCAN0.TMPTR46.UINT16[H]
#define RSCAN0TMPTR46HL RSCAN0.TMPTR46.UINT8[HL]
#define RSCAN0TMPTR46HH RSCAN0.TMPTR46.UINT8[HH]
#define RSCAN0TMDF046 RSCAN0.TMDF046.UINT32
#define RSCAN0TMDF046L RSCAN0.TMDF046.UINT16[L]
#define RSCAN0TMDF046LL RSCAN0.TMDF046.UINT8[LL]
#define RSCAN0TMDF046LH RSCAN0.TMDF046.UINT8[LH]
#define RSCAN0TMDF046H RSCAN0.TMDF046.UINT16[H]
#define RSCAN0TMDF046HL RSCAN0.TMDF046.UINT8[HL]
#define RSCAN0TMDF046HH RSCAN0.TMDF046.UINT8[HH]
#define RSCAN0TMDF146 RSCAN0.TMDF146.UINT32
#define RSCAN0TMDF146L RSCAN0.TMDF146.UINT16[L]
#define RSCAN0TMDF146LL RSCAN0.TMDF146.UINT8[LL]
#define RSCAN0TMDF146LH RSCAN0.TMDF146.UINT8[LH]
#define RSCAN0TMDF146H RSCAN0.TMDF146.UINT16[H]
#define RSCAN0TMDF146HL RSCAN0.TMDF146.UINT8[HL]
#define RSCAN0TMDF146HH RSCAN0.TMDF146.UINT8[HH]
#define RSCAN0TMID47 RSCAN0.TMID47.UINT32
#define RSCAN0TMID47L RSCAN0.TMID47.UINT16[L]
#define RSCAN0TMID47LL RSCAN0.TMID47.UINT8[LL]
#define RSCAN0TMID47LH RSCAN0.TMID47.UINT8[LH]
#define RSCAN0TMID47H RSCAN0.TMID47.UINT16[H]
#define RSCAN0TMID47HL RSCAN0.TMID47.UINT8[HL]
#define RSCAN0TMID47HH RSCAN0.TMID47.UINT8[HH]
#define RSCAN0TMPTR47 RSCAN0.TMPTR47.UINT32
#define RSCAN0TMPTR47L RSCAN0.TMPTR47.UINT16[L]
#define RSCAN0TMPTR47LL RSCAN0.TMPTR47.UINT8[LL]
#define RSCAN0TMPTR47LH RSCAN0.TMPTR47.UINT8[LH]
#define RSCAN0TMPTR47H RSCAN0.TMPTR47.UINT16[H]
#define RSCAN0TMPTR47HL RSCAN0.TMPTR47.UINT8[HL]
#define RSCAN0TMPTR47HH RSCAN0.TMPTR47.UINT8[HH]
#define RSCAN0TMDF047 RSCAN0.TMDF047.UINT32
#define RSCAN0TMDF047L RSCAN0.TMDF047.UINT16[L]
#define RSCAN0TMDF047LL RSCAN0.TMDF047.UINT8[LL]
#define RSCAN0TMDF047LH RSCAN0.TMDF047.UINT8[LH]
#define RSCAN0TMDF047H RSCAN0.TMDF047.UINT16[H]
#define RSCAN0TMDF047HL RSCAN0.TMDF047.UINT8[HL]
#define RSCAN0TMDF047HH RSCAN0.TMDF047.UINT8[HH]
#define RSCAN0TMDF147 RSCAN0.TMDF147.UINT32
#define RSCAN0TMDF147L RSCAN0.TMDF147.UINT16[L]
#define RSCAN0TMDF147LL RSCAN0.TMDF147.UINT8[LL]
#define RSCAN0TMDF147LH RSCAN0.TMDF147.UINT8[LH]
#define RSCAN0TMDF147H RSCAN0.TMDF147.UINT16[H]
#define RSCAN0TMDF147HL RSCAN0.TMDF147.UINT8[HL]
#define RSCAN0TMDF147HH RSCAN0.TMDF147.UINT8[HH]
#define RSCAN0THLACC0 RSCAN0.THLACC0.UINT32
#define RSCAN0THLACC0L RSCAN0.THLACC0.UINT16[L]
#define RSCAN0THLACC0LL RSCAN0.THLACC0.UINT8[LL]
#define RSCAN0THLACC0LH RSCAN0.THLACC0.UINT8[LH]
#define RSCAN0THLACC0H RSCAN0.THLACC0.UINT16[H]
#define RSCAN0THLACC0HL RSCAN0.THLACC0.UINT8[HL]
#define RSCAN0THLACC0HH RSCAN0.THLACC0.UINT8[HH]
#define RSCAN0THLACC1 RSCAN0.THLACC1.UINT32
#define RSCAN0THLACC1L RSCAN0.THLACC1.UINT16[L]
#define RSCAN0THLACC1LL RSCAN0.THLACC1.UINT8[LL]
#define RSCAN0THLACC1LH RSCAN0.THLACC1.UINT8[LH]
#define RSCAN0THLACC1H RSCAN0.THLACC1.UINT16[H]
#define RSCAN0THLACC1HL RSCAN0.THLACC1.UINT8[HL]
#define RSCAN0THLACC1HH RSCAN0.THLACC1.UINT8[HH]
#define RSCAN0THLACC2 RSCAN0.THLACC2.UINT32
#define RSCAN0THLACC2L RSCAN0.THLACC2.UINT16[L]
#define RSCAN0THLACC2LL RSCAN0.THLACC2.UINT8[LL]
#define RSCAN0THLACC2LH RSCAN0.THLACC2.UINT8[LH]
#define RSCAN0THLACC2H RSCAN0.THLACC2.UINT16[H]
#define RSCAN0THLACC2HL RSCAN0.THLACC2.UINT8[HL]
#define RSCAN0THLACC2HH RSCAN0.THLACC2.UINT8[HH]
#define RSCAN0RPGACC0 RSCAN0.RPGACC0.UINT32
#define RSCAN0RPGACC0L RSCAN0.RPGACC0.UINT16[L]
#define RSCAN0RPGACC0LL RSCAN0.RPGACC0.UINT8[LL]
#define RSCAN0RPGACC0LH RSCAN0.RPGACC0.UINT8[LH]
#define RSCAN0RPGACC0H RSCAN0.RPGACC0.UINT16[H]
#define RSCAN0RPGACC0HL RSCAN0.RPGACC0.UINT8[HL]
#define RSCAN0RPGACC0HH RSCAN0.RPGACC0.UINT8[HH]
#define RSCAN0RPGACC1 RSCAN0.RPGACC1.UINT32
#define RSCAN0RPGACC1L RSCAN0.RPGACC1.UINT16[L]
#define RSCAN0RPGACC1LL RSCAN0.RPGACC1.UINT8[LL]
#define RSCAN0RPGACC1LH RSCAN0.RPGACC1.UINT8[LH]
#define RSCAN0RPGACC1H RSCAN0.RPGACC1.UINT16[H]
#define RSCAN0RPGACC1HL RSCAN0.RPGACC1.UINT8[HL]
#define RSCAN0RPGACC1HH RSCAN0.RPGACC1.UINT8[HH]
#define RSCAN0RPGACC2 RSCAN0.RPGACC2.UINT32
#define RSCAN0RPGACC2L RSCAN0.RPGACC2.UINT16[L]
#define RSCAN0RPGACC2LL RSCAN0.RPGACC2.UINT8[LL]
#define RSCAN0RPGACC2LH RSCAN0.RPGACC2.UINT8[LH]
#define RSCAN0RPGACC2H RSCAN0.RPGACC2.UINT16[H]
#define RSCAN0RPGACC2HL RSCAN0.RPGACC2.UINT8[HL]
#define RSCAN0RPGACC2HH RSCAN0.RPGACC2.UINT8[HH]
#define RSCAN0RPGACC3 RSCAN0.RPGACC3.UINT32
#define RSCAN0RPGACC3L RSCAN0.RPGACC3.UINT16[L]
#define RSCAN0RPGACC3LL RSCAN0.RPGACC3.UINT8[LL]
#define RSCAN0RPGACC3LH RSCAN0.RPGACC3.UINT8[LH]
#define RSCAN0RPGACC3H RSCAN0.RPGACC3.UINT16[H]
#define RSCAN0RPGACC3HL RSCAN0.RPGACC3.UINT8[HL]
#define RSCAN0RPGACC3HH RSCAN0.RPGACC3.UINT8[HH]
#define RSCAN0RPGACC4 RSCAN0.RPGACC4.UINT32
#define RSCAN0RPGACC4L RSCAN0.RPGACC4.UINT16[L]
#define RSCAN0RPGACC4LL RSCAN0.RPGACC4.UINT8[LL]
#define RSCAN0RPGACC4LH RSCAN0.RPGACC4.UINT8[LH]
#define RSCAN0RPGACC4H RSCAN0.RPGACC4.UINT16[H]
#define RSCAN0RPGACC4HL RSCAN0.RPGACC4.UINT8[HL]
#define RSCAN0RPGACC4HH RSCAN0.RPGACC4.UINT8[HH]
#define RSCAN0RPGACC5 RSCAN0.RPGACC5.UINT32
#define RSCAN0RPGACC5L RSCAN0.RPGACC5.UINT16[L]
#define RSCAN0RPGACC5LL RSCAN0.RPGACC5.UINT8[LL]
#define RSCAN0RPGACC5LH RSCAN0.RPGACC5.UINT8[LH]
#define RSCAN0RPGACC5H RSCAN0.RPGACC5.UINT16[H]
#define RSCAN0RPGACC5HL RSCAN0.RPGACC5.UINT8[HL]
#define RSCAN0RPGACC5HH RSCAN0.RPGACC5.UINT8[HH]
#define RSCAN0RPGACC6 RSCAN0.RPGACC6.UINT32
#define RSCAN0RPGACC6L RSCAN0.RPGACC6.UINT16[L]
#define RSCAN0RPGACC6LL RSCAN0.RPGACC6.UINT8[LL]
#define RSCAN0RPGACC6LH RSCAN0.RPGACC6.UINT8[LH]
#define RSCAN0RPGACC6H RSCAN0.RPGACC6.UINT16[H]
#define RSCAN0RPGACC6HL RSCAN0.RPGACC6.UINT8[HL]
#define RSCAN0RPGACC6HH RSCAN0.RPGACC6.UINT8[HH]
#define RSCAN0RPGACC7 RSCAN0.RPGACC7.UINT32
#define RSCAN0RPGACC7L RSCAN0.RPGACC7.UINT16[L]
#define RSCAN0RPGACC7LL RSCAN0.RPGACC7.UINT8[LL]
#define RSCAN0RPGACC7LH RSCAN0.RPGACC7.UINT8[LH]
#define RSCAN0RPGACC7H RSCAN0.RPGACC7.UINT16[H]
#define RSCAN0RPGACC7HL RSCAN0.RPGACC7.UINT8[HL]
#define RSCAN0RPGACC7HH RSCAN0.RPGACC7.UINT8[HH]
#define RSCAN0RPGACC8 RSCAN0.RPGACC8.UINT32
#define RSCAN0RPGACC8L RSCAN0.RPGACC8.UINT16[L]
#define RSCAN0RPGACC8LL RSCAN0.RPGACC8.UINT8[LL]
#define RSCAN0RPGACC8LH RSCAN0.RPGACC8.UINT8[LH]
#define RSCAN0RPGACC8H RSCAN0.RPGACC8.UINT16[H]
#define RSCAN0RPGACC8HL RSCAN0.RPGACC8.UINT8[HL]
#define RSCAN0RPGACC8HH RSCAN0.RPGACC8.UINT8[HH]
#define RSCAN0RPGACC9 RSCAN0.RPGACC9.UINT32
#define RSCAN0RPGACC9L RSCAN0.RPGACC9.UINT16[L]
#define RSCAN0RPGACC9LL RSCAN0.RPGACC9.UINT8[LL]
#define RSCAN0RPGACC9LH RSCAN0.RPGACC9.UINT8[LH]
#define RSCAN0RPGACC9H RSCAN0.RPGACC9.UINT16[H]
#define RSCAN0RPGACC9HL RSCAN0.RPGACC9.UINT8[HL]
#define RSCAN0RPGACC9HH RSCAN0.RPGACC9.UINT8[HH]
#define RSCAN0RPGACC10 RSCAN0.RPGACC10.UINT32
#define RSCAN0RPGACC10L RSCAN0.RPGACC10.UINT16[L]
#define RSCAN0RPGACC10LL RSCAN0.RPGACC10.UINT8[LL]
#define RSCAN0RPGACC10LH RSCAN0.RPGACC10.UINT8[LH]
#define RSCAN0RPGACC10H RSCAN0.RPGACC10.UINT16[H]
#define RSCAN0RPGACC10HL RSCAN0.RPGACC10.UINT8[HL]
#define RSCAN0RPGACC10HH RSCAN0.RPGACC10.UINT8[HH]
#define RSCAN0RPGACC11 RSCAN0.RPGACC11.UINT32
#define RSCAN0RPGACC11L RSCAN0.RPGACC11.UINT16[L]
#define RSCAN0RPGACC11LL RSCAN0.RPGACC11.UINT8[LL]
#define RSCAN0RPGACC11LH RSCAN0.RPGACC11.UINT8[LH]
#define RSCAN0RPGACC11H RSCAN0.RPGACC11.UINT16[H]
#define RSCAN0RPGACC11HL RSCAN0.RPGACC11.UINT8[HL]
#define RSCAN0RPGACC11HH RSCAN0.RPGACC11.UINT8[HH]
#define RSCAN0RPGACC12 RSCAN0.RPGACC12.UINT32
#define RSCAN0RPGACC12L RSCAN0.RPGACC12.UINT16[L]
#define RSCAN0RPGACC12LL RSCAN0.RPGACC12.UINT8[LL]
#define RSCAN0RPGACC12LH RSCAN0.RPGACC12.UINT8[LH]
#define RSCAN0RPGACC12H RSCAN0.RPGACC12.UINT16[H]
#define RSCAN0RPGACC12HL RSCAN0.RPGACC12.UINT8[HL]
#define RSCAN0RPGACC12HH RSCAN0.RPGACC12.UINT8[HH]
#define RSCAN0RPGACC13 RSCAN0.RPGACC13.UINT32
#define RSCAN0RPGACC13L RSCAN0.RPGACC13.UINT16[L]
#define RSCAN0RPGACC13LL RSCAN0.RPGACC13.UINT8[LL]
#define RSCAN0RPGACC13LH RSCAN0.RPGACC13.UINT8[LH]
#define RSCAN0RPGACC13H RSCAN0.RPGACC13.UINT16[H]
#define RSCAN0RPGACC13HL RSCAN0.RPGACC13.UINT8[HL]
#define RSCAN0RPGACC13HH RSCAN0.RPGACC13.UINT8[HH]
#define RSCAN0RPGACC14 RSCAN0.RPGACC14.UINT32
#define RSCAN0RPGACC14L RSCAN0.RPGACC14.UINT16[L]
#define RSCAN0RPGACC14LL RSCAN0.RPGACC14.UINT8[LL]
#define RSCAN0RPGACC14LH RSCAN0.RPGACC14.UINT8[LH]
#define RSCAN0RPGACC14H RSCAN0.RPGACC14.UINT16[H]
#define RSCAN0RPGACC14HL RSCAN0.RPGACC14.UINT8[HL]
#define RSCAN0RPGACC14HH RSCAN0.RPGACC14.UINT8[HH]
#define RSCAN0RPGACC15 RSCAN0.RPGACC15.UINT32
#define RSCAN0RPGACC15L RSCAN0.RPGACC15.UINT16[L]
#define RSCAN0RPGACC15LL RSCAN0.RPGACC15.UINT8[LL]
#define RSCAN0RPGACC15LH RSCAN0.RPGACC15.UINT8[LH]
#define RSCAN0RPGACC15H RSCAN0.RPGACC15.UINT16[H]
#define RSCAN0RPGACC15HL RSCAN0.RPGACC15.UINT8[HL]
#define RSCAN0RPGACC15HH RSCAN0.RPGACC15.UINT8[HH]
#define RSCAN0RPGACC16 RSCAN0.RPGACC16.UINT32
#define RSCAN0RPGACC16L RSCAN0.RPGACC16.UINT16[L]
#define RSCAN0RPGACC16LL RSCAN0.RPGACC16.UINT8[LL]
#define RSCAN0RPGACC16LH RSCAN0.RPGACC16.UINT8[LH]
#define RSCAN0RPGACC16H RSCAN0.RPGACC16.UINT16[H]
#define RSCAN0RPGACC16HL RSCAN0.RPGACC16.UINT8[HL]
#define RSCAN0RPGACC16HH RSCAN0.RPGACC16.UINT8[HH]
#define RSCAN0RPGACC17 RSCAN0.RPGACC17.UINT32
#define RSCAN0RPGACC17L RSCAN0.RPGACC17.UINT16[L]
#define RSCAN0RPGACC17LL RSCAN0.RPGACC17.UINT8[LL]
#define RSCAN0RPGACC17LH RSCAN0.RPGACC17.UINT8[LH]
#define RSCAN0RPGACC17H RSCAN0.RPGACC17.UINT16[H]
#define RSCAN0RPGACC17HL RSCAN0.RPGACC17.UINT8[HL]
#define RSCAN0RPGACC17HH RSCAN0.RPGACC17.UINT8[HH]
#define RSCAN0RPGACC18 RSCAN0.RPGACC18.UINT32
#define RSCAN0RPGACC18L RSCAN0.RPGACC18.UINT16[L]
#define RSCAN0RPGACC18LL RSCAN0.RPGACC18.UINT8[LL]
#define RSCAN0RPGACC18LH RSCAN0.RPGACC18.UINT8[LH]
#define RSCAN0RPGACC18H RSCAN0.RPGACC18.UINT16[H]
#define RSCAN0RPGACC18HL RSCAN0.RPGACC18.UINT8[HL]
#define RSCAN0RPGACC18HH RSCAN0.RPGACC18.UINT8[HH]
#define RSCAN0RPGACC19 RSCAN0.RPGACC19.UINT32
#define RSCAN0RPGACC19L RSCAN0.RPGACC19.UINT16[L]
#define RSCAN0RPGACC19LL RSCAN0.RPGACC19.UINT8[LL]
#define RSCAN0RPGACC19LH RSCAN0.RPGACC19.UINT8[LH]
#define RSCAN0RPGACC19H RSCAN0.RPGACC19.UINT16[H]
#define RSCAN0RPGACC19HL RSCAN0.RPGACC19.UINT8[HL]
#define RSCAN0RPGACC19HH RSCAN0.RPGACC19.UINT8[HH]
#define RSCAN0RPGACC20 RSCAN0.RPGACC20.UINT32
#define RSCAN0RPGACC20L RSCAN0.RPGACC20.UINT16[L]
#define RSCAN0RPGACC20LL RSCAN0.RPGACC20.UINT8[LL]
#define RSCAN0RPGACC20LH RSCAN0.RPGACC20.UINT8[LH]
#define RSCAN0RPGACC20H RSCAN0.RPGACC20.UINT16[H]
#define RSCAN0RPGACC20HL RSCAN0.RPGACC20.UINT8[HL]
#define RSCAN0RPGACC20HH RSCAN0.RPGACC20.UINT8[HH]
#define RSCAN0RPGACC21 RSCAN0.RPGACC21.UINT32
#define RSCAN0RPGACC21L RSCAN0.RPGACC21.UINT16[L]
#define RSCAN0RPGACC21LL RSCAN0.RPGACC21.UINT8[LL]
#define RSCAN0RPGACC21LH RSCAN0.RPGACC21.UINT8[LH]
#define RSCAN0RPGACC21H RSCAN0.RPGACC21.UINT16[H]
#define RSCAN0RPGACC21HL RSCAN0.RPGACC21.UINT8[HL]
#define RSCAN0RPGACC21HH RSCAN0.RPGACC21.UINT8[HH]
#define RSCAN0RPGACC22 RSCAN0.RPGACC22.UINT32
#define RSCAN0RPGACC22L RSCAN0.RPGACC22.UINT16[L]
#define RSCAN0RPGACC22LL RSCAN0.RPGACC22.UINT8[LL]
#define RSCAN0RPGACC22LH RSCAN0.RPGACC22.UINT8[LH]
#define RSCAN0RPGACC22H RSCAN0.RPGACC22.UINT16[H]
#define RSCAN0RPGACC22HL RSCAN0.RPGACC22.UINT8[HL]
#define RSCAN0RPGACC22HH RSCAN0.RPGACC22.UINT8[HH]
#define RSCAN0RPGACC23 RSCAN0.RPGACC23.UINT32
#define RSCAN0RPGACC23L RSCAN0.RPGACC23.UINT16[L]
#define RSCAN0RPGACC23LL RSCAN0.RPGACC23.UINT8[LL]
#define RSCAN0RPGACC23LH RSCAN0.RPGACC23.UINT8[LH]
#define RSCAN0RPGACC23H RSCAN0.RPGACC23.UINT16[H]
#define RSCAN0RPGACC23HL RSCAN0.RPGACC23.UINT8[HL]
#define RSCAN0RPGACC23HH RSCAN0.RPGACC23.UINT8[HH]
#define RSCAN0RPGACC24 RSCAN0.RPGACC24.UINT32
#define RSCAN0RPGACC24L RSCAN0.RPGACC24.UINT16[L]
#define RSCAN0RPGACC24LL RSCAN0.RPGACC24.UINT8[LL]
#define RSCAN0RPGACC24LH RSCAN0.RPGACC24.UINT8[LH]
#define RSCAN0RPGACC24H RSCAN0.RPGACC24.UINT16[H]
#define RSCAN0RPGACC24HL RSCAN0.RPGACC24.UINT8[HL]
#define RSCAN0RPGACC24HH RSCAN0.RPGACC24.UINT8[HH]
#define RSCAN0RPGACC25 RSCAN0.RPGACC25.UINT32
#define RSCAN0RPGACC25L RSCAN0.RPGACC25.UINT16[L]
#define RSCAN0RPGACC25LL RSCAN0.RPGACC25.UINT8[LL]
#define RSCAN0RPGACC25LH RSCAN0.RPGACC25.UINT8[LH]
#define RSCAN0RPGACC25H RSCAN0.RPGACC25.UINT16[H]
#define RSCAN0RPGACC25HL RSCAN0.RPGACC25.UINT8[HL]
#define RSCAN0RPGACC25HH RSCAN0.RPGACC25.UINT8[HH]
#define RSCAN0RPGACC26 RSCAN0.RPGACC26.UINT32
#define RSCAN0RPGACC26L RSCAN0.RPGACC26.UINT16[L]
#define RSCAN0RPGACC26LL RSCAN0.RPGACC26.UINT8[LL]
#define RSCAN0RPGACC26LH RSCAN0.RPGACC26.UINT8[LH]
#define RSCAN0RPGACC26H RSCAN0.RPGACC26.UINT16[H]
#define RSCAN0RPGACC26HL RSCAN0.RPGACC26.UINT8[HL]
#define RSCAN0RPGACC26HH RSCAN0.RPGACC26.UINT8[HH]
#define RSCAN0RPGACC27 RSCAN0.RPGACC27.UINT32
#define RSCAN0RPGACC27L RSCAN0.RPGACC27.UINT16[L]
#define RSCAN0RPGACC27LL RSCAN0.RPGACC27.UINT8[LL]
#define RSCAN0RPGACC27LH RSCAN0.RPGACC27.UINT8[LH]
#define RSCAN0RPGACC27H RSCAN0.RPGACC27.UINT16[H]
#define RSCAN0RPGACC27HL RSCAN0.RPGACC27.UINT8[HL]
#define RSCAN0RPGACC27HH RSCAN0.RPGACC27.UINT8[HH]
#define RSCAN0RPGACC28 RSCAN0.RPGACC28.UINT32
#define RSCAN0RPGACC28L RSCAN0.RPGACC28.UINT16[L]
#define RSCAN0RPGACC28LL RSCAN0.RPGACC28.UINT8[LL]
#define RSCAN0RPGACC28LH RSCAN0.RPGACC28.UINT8[LH]
#define RSCAN0RPGACC28H RSCAN0.RPGACC28.UINT16[H]
#define RSCAN0RPGACC28HL RSCAN0.RPGACC28.UINT8[HL]
#define RSCAN0RPGACC28HH RSCAN0.RPGACC28.UINT8[HH]
#define RSCAN0RPGACC29 RSCAN0.RPGACC29.UINT32
#define RSCAN0RPGACC29L RSCAN0.RPGACC29.UINT16[L]
#define RSCAN0RPGACC29LL RSCAN0.RPGACC29.UINT8[LL]
#define RSCAN0RPGACC29LH RSCAN0.RPGACC29.UINT8[LH]
#define RSCAN0RPGACC29H RSCAN0.RPGACC29.UINT16[H]
#define RSCAN0RPGACC29HL RSCAN0.RPGACC29.UINT8[HL]
#define RSCAN0RPGACC29HH RSCAN0.RPGACC29.UINT8[HH]
#define RSCAN0RPGACC30 RSCAN0.RPGACC30.UINT32
#define RSCAN0RPGACC30L RSCAN0.RPGACC30.UINT16[L]
#define RSCAN0RPGACC30LL RSCAN0.RPGACC30.UINT8[LL]
#define RSCAN0RPGACC30LH RSCAN0.RPGACC30.UINT8[LH]
#define RSCAN0RPGACC30H RSCAN0.RPGACC30.UINT16[H]
#define RSCAN0RPGACC30HL RSCAN0.RPGACC30.UINT8[HL]
#define RSCAN0RPGACC30HH RSCAN0.RPGACC30.UINT8[HH]
#define RSCAN0RPGACC31 RSCAN0.RPGACC31.UINT32
#define RSCAN0RPGACC31L RSCAN0.RPGACC31.UINT16[L]
#define RSCAN0RPGACC31LL RSCAN0.RPGACC31.UINT8[LL]
#define RSCAN0RPGACC31LH RSCAN0.RPGACC31.UINT8[LH]
#define RSCAN0RPGACC31H RSCAN0.RPGACC31.UINT16[H]
#define RSCAN0RPGACC31HL RSCAN0.RPGACC31.UINT8[HL]
#define RSCAN0RPGACC31HH RSCAN0.RPGACC31.UINT8[HH]
#define RSCAN0RPGACC32 RSCAN0.RPGACC32.UINT32
#define RSCAN0RPGACC32L RSCAN0.RPGACC32.UINT16[L]
#define RSCAN0RPGACC32LL RSCAN0.RPGACC32.UINT8[LL]
#define RSCAN0RPGACC32LH RSCAN0.RPGACC32.UINT8[LH]
#define RSCAN0RPGACC32H RSCAN0.RPGACC32.UINT16[H]
#define RSCAN0RPGACC32HL RSCAN0.RPGACC32.UINT8[HL]
#define RSCAN0RPGACC32HH RSCAN0.RPGACC32.UINT8[HH]
#define RSCAN0RPGACC33 RSCAN0.RPGACC33.UINT32
#define RSCAN0RPGACC33L RSCAN0.RPGACC33.UINT16[L]
#define RSCAN0RPGACC33LL RSCAN0.RPGACC33.UINT8[LL]
#define RSCAN0RPGACC33LH RSCAN0.RPGACC33.UINT8[LH]
#define RSCAN0RPGACC33H RSCAN0.RPGACC33.UINT16[H]
#define RSCAN0RPGACC33HL RSCAN0.RPGACC33.UINT8[HL]
#define RSCAN0RPGACC33HH RSCAN0.RPGACC33.UINT8[HH]
#define RSCAN0RPGACC34 RSCAN0.RPGACC34.UINT32
#define RSCAN0RPGACC34L RSCAN0.RPGACC34.UINT16[L]
#define RSCAN0RPGACC34LL RSCAN0.RPGACC34.UINT8[LL]
#define RSCAN0RPGACC34LH RSCAN0.RPGACC34.UINT8[LH]
#define RSCAN0RPGACC34H RSCAN0.RPGACC34.UINT16[H]
#define RSCAN0RPGACC34HL RSCAN0.RPGACC34.UINT8[HL]
#define RSCAN0RPGACC34HH RSCAN0.RPGACC34.UINT8[HH]
#define RSCAN0RPGACC35 RSCAN0.RPGACC35.UINT32
#define RSCAN0RPGACC35L RSCAN0.RPGACC35.UINT16[L]
#define RSCAN0RPGACC35LL RSCAN0.RPGACC35.UINT8[LL]
#define RSCAN0RPGACC35LH RSCAN0.RPGACC35.UINT8[LH]
#define RSCAN0RPGACC35H RSCAN0.RPGACC35.UINT16[H]
#define RSCAN0RPGACC35HL RSCAN0.RPGACC35.UINT8[HL]
#define RSCAN0RPGACC35HH RSCAN0.RPGACC35.UINT8[HH]
#define RSCAN0RPGACC36 RSCAN0.RPGACC36.UINT32
#define RSCAN0RPGACC36L RSCAN0.RPGACC36.UINT16[L]
#define RSCAN0RPGACC36LL RSCAN0.RPGACC36.UINT8[LL]
#define RSCAN0RPGACC36LH RSCAN0.RPGACC36.UINT8[LH]
#define RSCAN0RPGACC36H RSCAN0.RPGACC36.UINT16[H]
#define RSCAN0RPGACC36HL RSCAN0.RPGACC36.UINT8[HL]
#define RSCAN0RPGACC36HH RSCAN0.RPGACC36.UINT8[HH]
#define RSCAN0RPGACC37 RSCAN0.RPGACC37.UINT32
#define RSCAN0RPGACC37L RSCAN0.RPGACC37.UINT16[L]
#define RSCAN0RPGACC37LL RSCAN0.RPGACC37.UINT8[LL]
#define RSCAN0RPGACC37LH RSCAN0.RPGACC37.UINT8[LH]
#define RSCAN0RPGACC37H RSCAN0.RPGACC37.UINT16[H]
#define RSCAN0RPGACC37HL RSCAN0.RPGACC37.UINT8[HL]
#define RSCAN0RPGACC37HH RSCAN0.RPGACC37.UINT8[HH]
#define RSCAN0RPGACC38 RSCAN0.RPGACC38.UINT32
#define RSCAN0RPGACC38L RSCAN0.RPGACC38.UINT16[L]
#define RSCAN0RPGACC38LL RSCAN0.RPGACC38.UINT8[LL]
#define RSCAN0RPGACC38LH RSCAN0.RPGACC38.UINT8[LH]
#define RSCAN0RPGACC38H RSCAN0.RPGACC38.UINT16[H]
#define RSCAN0RPGACC38HL RSCAN0.RPGACC38.UINT8[HL]
#define RSCAN0RPGACC38HH RSCAN0.RPGACC38.UINT8[HH]
#define RSCAN0RPGACC39 RSCAN0.RPGACC39.UINT32
#define RSCAN0RPGACC39L RSCAN0.RPGACC39.UINT16[L]
#define RSCAN0RPGACC39LL RSCAN0.RPGACC39.UINT8[LL]
#define RSCAN0RPGACC39LH RSCAN0.RPGACC39.UINT8[LH]
#define RSCAN0RPGACC39H RSCAN0.RPGACC39.UINT16[H]
#define RSCAN0RPGACC39HL RSCAN0.RPGACC39.UINT8[HL]
#define RSCAN0RPGACC39HH RSCAN0.RPGACC39.UINT8[HH]
#define RSCAN0RPGACC40 RSCAN0.RPGACC40.UINT32
#define RSCAN0RPGACC40L RSCAN0.RPGACC40.UINT16[L]
#define RSCAN0RPGACC40LL RSCAN0.RPGACC40.UINT8[LL]
#define RSCAN0RPGACC40LH RSCAN0.RPGACC40.UINT8[LH]
#define RSCAN0RPGACC40H RSCAN0.RPGACC40.UINT16[H]
#define RSCAN0RPGACC40HL RSCAN0.RPGACC40.UINT8[HL]
#define RSCAN0RPGACC40HH RSCAN0.RPGACC40.UINT8[HH]
#define RSCAN0RPGACC41 RSCAN0.RPGACC41.UINT32
#define RSCAN0RPGACC41L RSCAN0.RPGACC41.UINT16[L]
#define RSCAN0RPGACC41LL RSCAN0.RPGACC41.UINT8[LL]
#define RSCAN0RPGACC41LH RSCAN0.RPGACC41.UINT8[LH]
#define RSCAN0RPGACC41H RSCAN0.RPGACC41.UINT16[H]
#define RSCAN0RPGACC41HL RSCAN0.RPGACC41.UINT8[HL]
#define RSCAN0RPGACC41HH RSCAN0.RPGACC41.UINT8[HH]
#define RSCAN0RPGACC42 RSCAN0.RPGACC42.UINT32
#define RSCAN0RPGACC42L RSCAN0.RPGACC42.UINT16[L]
#define RSCAN0RPGACC42LL RSCAN0.RPGACC42.UINT8[LL]
#define RSCAN0RPGACC42LH RSCAN0.RPGACC42.UINT8[LH]
#define RSCAN0RPGACC42H RSCAN0.RPGACC42.UINT16[H]
#define RSCAN0RPGACC42HL RSCAN0.RPGACC42.UINT8[HL]
#define RSCAN0RPGACC42HH RSCAN0.RPGACC42.UINT8[HH]
#define RSCAN0RPGACC43 RSCAN0.RPGACC43.UINT32
#define RSCAN0RPGACC43L RSCAN0.RPGACC43.UINT16[L]
#define RSCAN0RPGACC43LL RSCAN0.RPGACC43.UINT8[LL]
#define RSCAN0RPGACC43LH RSCAN0.RPGACC43.UINT8[LH]
#define RSCAN0RPGACC43H RSCAN0.RPGACC43.UINT16[H]
#define RSCAN0RPGACC43HL RSCAN0.RPGACC43.UINT8[HL]
#define RSCAN0RPGACC43HH RSCAN0.RPGACC43.UINT8[HH]
#define RSCAN0RPGACC44 RSCAN0.RPGACC44.UINT32
#define RSCAN0RPGACC44L RSCAN0.RPGACC44.UINT16[L]
#define RSCAN0RPGACC44LL RSCAN0.RPGACC44.UINT8[LL]
#define RSCAN0RPGACC44LH RSCAN0.RPGACC44.UINT8[LH]
#define RSCAN0RPGACC44H RSCAN0.RPGACC44.UINT16[H]
#define RSCAN0RPGACC44HL RSCAN0.RPGACC44.UINT8[HL]
#define RSCAN0RPGACC44HH RSCAN0.RPGACC44.UINT8[HH]
#define RSCAN0RPGACC45 RSCAN0.RPGACC45.UINT32
#define RSCAN0RPGACC45L RSCAN0.RPGACC45.UINT16[L]
#define RSCAN0RPGACC45LL RSCAN0.RPGACC45.UINT8[LL]
#define RSCAN0RPGACC45LH RSCAN0.RPGACC45.UINT8[LH]
#define RSCAN0RPGACC45H RSCAN0.RPGACC45.UINT16[H]
#define RSCAN0RPGACC45HL RSCAN0.RPGACC45.UINT8[HL]
#define RSCAN0RPGACC45HH RSCAN0.RPGACC45.UINT8[HH]
#define RSCAN0RPGACC46 RSCAN0.RPGACC46.UINT32
#define RSCAN0RPGACC46L RSCAN0.RPGACC46.UINT16[L]
#define RSCAN0RPGACC46LL RSCAN0.RPGACC46.UINT8[LL]
#define RSCAN0RPGACC46LH RSCAN0.RPGACC46.UINT8[LH]
#define RSCAN0RPGACC46H RSCAN0.RPGACC46.UINT16[H]
#define RSCAN0RPGACC46HL RSCAN0.RPGACC46.UINT8[HL]
#define RSCAN0RPGACC46HH RSCAN0.RPGACC46.UINT8[HH]
#define RSCAN0RPGACC47 RSCAN0.RPGACC47.UINT32
#define RSCAN0RPGACC47L RSCAN0.RPGACC47.UINT16[L]
#define RSCAN0RPGACC47LL RSCAN0.RPGACC47.UINT8[LL]
#define RSCAN0RPGACC47LH RSCAN0.RPGACC47.UINT8[LH]
#define RSCAN0RPGACC47H RSCAN0.RPGACC47.UINT16[H]
#define RSCAN0RPGACC47HL RSCAN0.RPGACC47.UINT8[HL]
#define RSCAN0RPGACC47HH RSCAN0.RPGACC47.UINT8[HH]
#define RSCAN0RPGACC48 RSCAN0.RPGACC48.UINT32
#define RSCAN0RPGACC48L RSCAN0.RPGACC48.UINT16[L]
#define RSCAN0RPGACC48LL RSCAN0.RPGACC48.UINT8[LL]
#define RSCAN0RPGACC48LH RSCAN0.RPGACC48.UINT8[LH]
#define RSCAN0RPGACC48H RSCAN0.RPGACC48.UINT16[H]
#define RSCAN0RPGACC48HL RSCAN0.RPGACC48.UINT8[HL]
#define RSCAN0RPGACC48HH RSCAN0.RPGACC48.UINT8[HH]
#define RSCAN0RPGACC49 RSCAN0.RPGACC49.UINT32
#define RSCAN0RPGACC49L RSCAN0.RPGACC49.UINT16[L]
#define RSCAN0RPGACC49LL RSCAN0.RPGACC49.UINT8[LL]
#define RSCAN0RPGACC49LH RSCAN0.RPGACC49.UINT8[LH]
#define RSCAN0RPGACC49H RSCAN0.RPGACC49.UINT16[H]
#define RSCAN0RPGACC49HL RSCAN0.RPGACC49.UINT8[HL]
#define RSCAN0RPGACC49HH RSCAN0.RPGACC49.UINT8[HH]
#define RSCAN0RPGACC50 RSCAN0.RPGACC50.UINT32
#define RSCAN0RPGACC50L RSCAN0.RPGACC50.UINT16[L]
#define RSCAN0RPGACC50LL RSCAN0.RPGACC50.UINT8[LL]
#define RSCAN0RPGACC50LH RSCAN0.RPGACC50.UINT8[LH]
#define RSCAN0RPGACC50H RSCAN0.RPGACC50.UINT16[H]
#define RSCAN0RPGACC50HL RSCAN0.RPGACC50.UINT8[HL]
#define RSCAN0RPGACC50HH RSCAN0.RPGACC50.UINT8[HH]
#define RSCAN0RPGACC51 RSCAN0.RPGACC51.UINT32
#define RSCAN0RPGACC51L RSCAN0.RPGACC51.UINT16[L]
#define RSCAN0RPGACC51LL RSCAN0.RPGACC51.UINT8[LL]
#define RSCAN0RPGACC51LH RSCAN0.RPGACC51.UINT8[LH]
#define RSCAN0RPGACC51H RSCAN0.RPGACC51.UINT16[H]
#define RSCAN0RPGACC51HL RSCAN0.RPGACC51.UINT8[HL]
#define RSCAN0RPGACC51HH RSCAN0.RPGACC51.UINT8[HH]
#define RSCAN0RPGACC52 RSCAN0.RPGACC52.UINT32
#define RSCAN0RPGACC52L RSCAN0.RPGACC52.UINT16[L]
#define RSCAN0RPGACC52LL RSCAN0.RPGACC52.UINT8[LL]
#define RSCAN0RPGACC52LH RSCAN0.RPGACC52.UINT8[LH]
#define RSCAN0RPGACC52H RSCAN0.RPGACC52.UINT16[H]
#define RSCAN0RPGACC52HL RSCAN0.RPGACC52.UINT8[HL]
#define RSCAN0RPGACC52HH RSCAN0.RPGACC52.UINT8[HH]
#define RSCAN0RPGACC53 RSCAN0.RPGACC53.UINT32
#define RSCAN0RPGACC53L RSCAN0.RPGACC53.UINT16[L]
#define RSCAN0RPGACC53LL RSCAN0.RPGACC53.UINT8[LL]
#define RSCAN0RPGACC53LH RSCAN0.RPGACC53.UINT8[LH]
#define RSCAN0RPGACC53H RSCAN0.RPGACC53.UINT16[H]
#define RSCAN0RPGACC53HL RSCAN0.RPGACC53.UINT8[HL]
#define RSCAN0RPGACC53HH RSCAN0.RPGACC53.UINT8[HH]
#define RSCAN0RPGACC54 RSCAN0.RPGACC54.UINT32
#define RSCAN0RPGACC54L RSCAN0.RPGACC54.UINT16[L]
#define RSCAN0RPGACC54LL RSCAN0.RPGACC54.UINT8[LL]
#define RSCAN0RPGACC54LH RSCAN0.RPGACC54.UINT8[LH]
#define RSCAN0RPGACC54H RSCAN0.RPGACC54.UINT16[H]
#define RSCAN0RPGACC54HL RSCAN0.RPGACC54.UINT8[HL]
#define RSCAN0RPGACC54HH RSCAN0.RPGACC54.UINT8[HH]
#define RSCAN0RPGACC55 RSCAN0.RPGACC55.UINT32
#define RSCAN0RPGACC55L RSCAN0.RPGACC55.UINT16[L]
#define RSCAN0RPGACC55LL RSCAN0.RPGACC55.UINT8[LL]
#define RSCAN0RPGACC55LH RSCAN0.RPGACC55.UINT8[LH]
#define RSCAN0RPGACC55H RSCAN0.RPGACC55.UINT16[H]
#define RSCAN0RPGACC55HL RSCAN0.RPGACC55.UINT8[HL]
#define RSCAN0RPGACC55HH RSCAN0.RPGACC55.UINT8[HH]
#define RSCAN0RPGACC56 RSCAN0.RPGACC56.UINT32
#define RSCAN0RPGACC56L RSCAN0.RPGACC56.UINT16[L]
#define RSCAN0RPGACC56LL RSCAN0.RPGACC56.UINT8[LL]
#define RSCAN0RPGACC56LH RSCAN0.RPGACC56.UINT8[LH]
#define RSCAN0RPGACC56H RSCAN0.RPGACC56.UINT16[H]
#define RSCAN0RPGACC56HL RSCAN0.RPGACC56.UINT8[HL]
#define RSCAN0RPGACC56HH RSCAN0.RPGACC56.UINT8[HH]
#define RSCAN0RPGACC57 RSCAN0.RPGACC57.UINT32
#define RSCAN0RPGACC57L RSCAN0.RPGACC57.UINT16[L]
#define RSCAN0RPGACC57LL RSCAN0.RPGACC57.UINT8[LL]
#define RSCAN0RPGACC57LH RSCAN0.RPGACC57.UINT8[LH]
#define RSCAN0RPGACC57H RSCAN0.RPGACC57.UINT16[H]
#define RSCAN0RPGACC57HL RSCAN0.RPGACC57.UINT8[HL]
#define RSCAN0RPGACC57HH RSCAN0.RPGACC57.UINT8[HH]
#define RSCAN0RPGACC58 RSCAN0.RPGACC58.UINT32
#define RSCAN0RPGACC58L RSCAN0.RPGACC58.UINT16[L]
#define RSCAN0RPGACC58LL RSCAN0.RPGACC58.UINT8[LL]
#define RSCAN0RPGACC58LH RSCAN0.RPGACC58.UINT8[LH]
#define RSCAN0RPGACC58H RSCAN0.RPGACC58.UINT16[H]
#define RSCAN0RPGACC58HL RSCAN0.RPGACC58.UINT8[HL]
#define RSCAN0RPGACC58HH RSCAN0.RPGACC58.UINT8[HH]
#define RSCAN0RPGACC59 RSCAN0.RPGACC59.UINT32
#define RSCAN0RPGACC59L RSCAN0.RPGACC59.UINT16[L]
#define RSCAN0RPGACC59LL RSCAN0.RPGACC59.UINT8[LL]
#define RSCAN0RPGACC59LH RSCAN0.RPGACC59.UINT8[LH]
#define RSCAN0RPGACC59H RSCAN0.RPGACC59.UINT16[H]
#define RSCAN0RPGACC59HL RSCAN0.RPGACC59.UINT8[HL]
#define RSCAN0RPGACC59HH RSCAN0.RPGACC59.UINT8[HH]
#define RSCAN0RPGACC60 RSCAN0.RPGACC60.UINT32
#define RSCAN0RPGACC60L RSCAN0.RPGACC60.UINT16[L]
#define RSCAN0RPGACC60LL RSCAN0.RPGACC60.UINT8[LL]
#define RSCAN0RPGACC60LH RSCAN0.RPGACC60.UINT8[LH]
#define RSCAN0RPGACC60H RSCAN0.RPGACC60.UINT16[H]
#define RSCAN0RPGACC60HL RSCAN0.RPGACC60.UINT8[HL]
#define RSCAN0RPGACC60HH RSCAN0.RPGACC60.UINT8[HH]
#define RSCAN0RPGACC61 RSCAN0.RPGACC61.UINT32
#define RSCAN0RPGACC61L RSCAN0.RPGACC61.UINT16[L]
#define RSCAN0RPGACC61LL RSCAN0.RPGACC61.UINT8[LL]
#define RSCAN0RPGACC61LH RSCAN0.RPGACC61.UINT8[LH]
#define RSCAN0RPGACC61H RSCAN0.RPGACC61.UINT16[H]
#define RSCAN0RPGACC61HL RSCAN0.RPGACC61.UINT8[HL]
#define RSCAN0RPGACC61HH RSCAN0.RPGACC61.UINT8[HH]
#define RSCAN0RPGACC62 RSCAN0.RPGACC62.UINT32
#define RSCAN0RPGACC62L RSCAN0.RPGACC62.UINT16[L]
#define RSCAN0RPGACC62LL RSCAN0.RPGACC62.UINT8[LL]
#define RSCAN0RPGACC62LH RSCAN0.RPGACC62.UINT8[LH]
#define RSCAN0RPGACC62H RSCAN0.RPGACC62.UINT16[H]
#define RSCAN0RPGACC62HL RSCAN0.RPGACC62.UINT8[HL]
#define RSCAN0RPGACC62HH RSCAN0.RPGACC62.UINT8[HH]
#define RSCAN0RPGACC63 RSCAN0.RPGACC63.UINT32
#define RSCAN0RPGACC63L RSCAN0.RPGACC63.UINT16[L]
#define RSCAN0RPGACC63LL RSCAN0.RPGACC63.UINT8[LL]
#define RSCAN0RPGACC63LH RSCAN0.RPGACC63.UINT8[LH]
#define RSCAN0RPGACC63H RSCAN0.RPGACC63.UINT16[H]
#define RSCAN0RPGACC63HL RSCAN0.RPGACC63.UINT8[HL]
#define RSCAN0RPGACC63HH RSCAN0.RPGACC63.UINT8[HH]
#define CSIH0CTL0 CSIH0.CTL0.UINT8
#define CSIH0MBS CSIH0.CTL0.BIT.MBS
#define CSIH0JOBE CSIH0.CTL0.BIT.JOBE
#define CSIH0RXE CSIH0.CTL0.BIT.RXE
#define CSIH0TXE CSIH0.CTL0.BIT.TXE
#define CSIH0PWR CSIH0.CTL0.BIT.PWR
#define CSIH0STR0 CSIH0.STR0
#define CSIH0STCR0 CSIH0.STCR0
#define CSIH0CTL1 CSIH0.CTL1
#define CSIH0CTL2 CSIH0.CTL2
#define CSIH0EMU CSIH0.EMU
#define CSIH0MCTL1 CSIH0.MCTL1
#define CSIH0MCTL2 CSIH0.MCTL2
#define CSIH0TX0W CSIH0.TX0W
#define CSIH0TX0H CSIH0.TX0H
#define CSIH0RX0W CSIH0.RX0W
#define CSIH0RX0H CSIH0.RX0H
#define CSIH0MRWP0 CSIH0.MRWP0
#define CSIH0MCTL0 CSIH0.MCTL0
#define CSIH0CFG0 CSIH0.CFG0
#define CSIH0CFG1 CSIH0.CFG1
#define CSIH0CFG2 CSIH0.CFG2
#define CSIH0CFG3 CSIH0.CFG3
#define CSIH0CFG4 CSIH0.CFG4
#define CSIH0CFG5 CSIH0.CFG5
#define CSIH0CFG6 CSIH0.CFG6
#define CSIH0CFG7 CSIH0.CFG7
#define CSIH0BRS0 CSIH0.BRS0
#define CSIH0BRS1 CSIH0.BRS1
#define CSIH0BRS2 CSIH0.BRS2
#define CSIH0BRS3 CSIH0.BRS3
#define CSIH1CTL0 CSIH1.CTL0.UINT8
#define CSIH1MBS CSIH1.CTL0.BIT.MBS
#define CSIH1JOBE CSIH1.CTL0.BIT.JOBE
#define CSIH1RXE CSIH1.CTL0.BIT.RXE
#define CSIH1TXE CSIH1.CTL0.BIT.TXE
#define CSIH1PWR CSIH1.CTL0.BIT.PWR
#define CSIH1STR0 CSIH1.STR0
#define CSIH1STCR0 CSIH1.STCR0
#define CSIH1CTL1 CSIH1.CTL1
#define CSIH1CTL2 CSIH1.CTL2
#define CSIH1EMU CSIH1.EMU
#define CSIH1MCTL1 CSIH1.MCTL1
#define CSIH1MCTL2 CSIH1.MCTL2
#define CSIH1TX0W CSIH1.TX0W
#define CSIH1TX0H CSIH1.TX0H
#define CSIH1RX0W CSIH1.RX0W
#define CSIH1RX0H CSIH1.RX0H
#define CSIH1MRWP0 CSIH1.MRWP0
#define CSIH1MCTL0 CSIH1.MCTL0
#define CSIH1CFG0 CSIH1.CFG0
#define CSIH1CFG1 CSIH1.CFG1
#define CSIH1CFG2 CSIH1.CFG2
#define CSIH1CFG3 CSIH1.CFG3
#define CSIH1BRS0 CSIH1.BRS0
#define CSIH1BRS1 CSIH1.BRS1
#define CSIH1BRS2 CSIH1.BRS2
#define CSIH1BRS3 CSIH1.BRS3
#define CSIH2CTL0 CSIH2.CTL0.UINT8
#define CSIH2MBS CSIH2.CTL0.BIT.MBS
#define CSIH2JOBE CSIH2.CTL0.BIT.JOBE
#define CSIH2RXE CSIH2.CTL0.BIT.RXE
#define CSIH2TXE CSIH2.CTL0.BIT.TXE
#define CSIH2PWR CSIH2.CTL0.BIT.PWR
#define CSIH2STR0 CSIH2.STR0
#define CSIH2STCR0 CSIH2.STCR0
#define CSIH2CTL1 CSIH2.CTL1
#define CSIH2CTL2 CSIH2.CTL2
#define CSIH2EMU CSIH2.EMU
#define CSIH2MCTL1 CSIH2.MCTL1
#define CSIH2MCTL2 CSIH2.MCTL2
#define CSIH2TX0W CSIH2.TX0W
#define CSIH2TX0H CSIH2.TX0H
#define CSIH2RX0W CSIH2.RX0W
#define CSIH2RX0H CSIH2.RX0H
#define CSIH2MRWP0 CSIH2.MRWP0
#define CSIH2MCTL0 CSIH2.MCTL0
#define CSIH2CFG0 CSIH2.CFG0
#define CSIH2CFG1 CSIH2.CFG1
#define CSIH2CFG2 CSIH2.CFG2
#define CSIH2CFG3 CSIH2.CFG3
#define CSIH2BRS0 CSIH2.BRS0
#define CSIH2BRS1 CSIH2.BRS1
#define CSIH2BRS2 CSIH2.BRS2
#define CSIH2BRS3 CSIH2.BRS3
#define CSIG0CTL0 CSIG0.CTL0.UINT8
#define CSIG0RXE CSIG0.CTL0.BIT.RXE
#define CSIG0TXE CSIG0.CTL0.BIT.TXE
#define CSIG0PWR CSIG0.CTL0.BIT.PWR
#define CSIG0STR0 CSIG0.STR0
#define CSIG0STCR0 CSIG0.STCR0
#define CSIG0CTL1 CSIG0.CTL1
#define CSIG0CTL2 CSIG0.CTL2
#define CSIG0EMU CSIG0.EMU
#define CSIG0BCTL0 CSIG0.BCTL0.UINT8
#define CSIG0SCE CSIG0.BCTL0.BIT.SCE
#define CSIG0TX0W CSIG0.TX0W
#define CSIG0TX0H CSIG0.TX0H
#define CSIG0RX0 CSIG0.RX0
#define CSIG0CFG0 CSIG0.CFG0
#define PIC0SST PIC0.SST
#define PIC0SSER0 PIC0.SSER0
#define PIC0SSER2 PIC0.SSER2
#define PIC0HIZCEN0 PIC0.HIZCEN0
#define PIC0ADTEN400 PIC0.ADTEN400
#define PIC0ADTEN401 PIC0.ADTEN401
#define PIC0ADTEN402 PIC0.ADTEN402
#define PIC0REG200 PIC0.REG200
#define PIC0REG201 PIC0.REG201
#define PIC0REG202 PIC0.REG202
#define PIC0REG203 PIC0.REG203
#define PIC0REG30 PIC0.REG30
#define PIC0REG31 PIC0.REG31
#define TAUD0CDR0 TAUD0.CDR0
#define TAUD0CDR1 TAUD0.CDR1
#define TAUD0CDR2 TAUD0.CDR2
#define TAUD0CDR3 TAUD0.CDR3
#define TAUD0CDR4 TAUD0.CDR4
#define TAUD0CDR5 TAUD0.CDR5
#define TAUD0CDR6 TAUD0.CDR6
#define TAUD0CDR7 TAUD0.CDR7
#define TAUD0CDR8 TAUD0.CDR8
#define TAUD0CDR9 TAUD0.CDR9
#define TAUD0CDR10 TAUD0.CDR10
#define TAUD0CDR11 TAUD0.CDR11
#define TAUD0CDR12 TAUD0.CDR12
#define TAUD0CDR13 TAUD0.CDR13
#define TAUD0CDR14 TAUD0.CDR14
#define TAUD0CDR15 TAUD0.CDR15
#define TAUD0TOL TAUD0.TOL
#define TAUD0RDT TAUD0.RDT
#define TAUD0RSF TAUD0.RSF
#define TAUD0TRO TAUD0.TRO
#define TAUD0TME TAUD0.TME
#define TAUD0TDL TAUD0.TDL
#define TAUD0TO TAUD0.TO
#define TAUD0TOE TAUD0.TOE
#define TAUD0CNT0 TAUD0.CNT0
#define TAUD0CNT1 TAUD0.CNT1
#define TAUD0CNT2 TAUD0.CNT2
#define TAUD0CNT3 TAUD0.CNT3
#define TAUD0CNT4 TAUD0.CNT4
#define TAUD0CNT5 TAUD0.CNT5
#define TAUD0CNT6 TAUD0.CNT6
#define TAUD0CNT7 TAUD0.CNT7
#define TAUD0CNT8 TAUD0.CNT8
#define TAUD0CNT9 TAUD0.CNT9
#define TAUD0CNT10 TAUD0.CNT10
#define TAUD0CNT11 TAUD0.CNT11
#define TAUD0CNT12 TAUD0.CNT12
#define TAUD0CNT13 TAUD0.CNT13
#define TAUD0CNT14 TAUD0.CNT14
#define TAUD0CNT15 TAUD0.CNT15
#define TAUD0CMUR0 TAUD0.CMUR0
#define TAUD0CMUR1 TAUD0.CMUR1
#define TAUD0CMUR2 TAUD0.CMUR2
#define TAUD0CMUR3 TAUD0.CMUR3
#define TAUD0CMUR4 TAUD0.CMUR4
#define TAUD0CMUR5 TAUD0.CMUR5
#define TAUD0CMUR6 TAUD0.CMUR6
#define TAUD0CMUR7 TAUD0.CMUR7
#define TAUD0CMUR8 TAUD0.CMUR8
#define TAUD0CMUR9 TAUD0.CMUR9
#define TAUD0CMUR10 TAUD0.CMUR10
#define TAUD0CMUR11 TAUD0.CMUR11
#define TAUD0CMUR12 TAUD0.CMUR12
#define TAUD0CMUR13 TAUD0.CMUR13
#define TAUD0CMUR14 TAUD0.CMUR14
#define TAUD0CMUR15 TAUD0.CMUR15
#define TAUD0CSR0 TAUD0.CSR0
#define TAUD0CSR1 TAUD0.CSR1
#define TAUD0CSR2 TAUD0.CSR2
#define TAUD0CSR3 TAUD0.CSR3
#define TAUD0CSR4 TAUD0.CSR4
#define TAUD0CSR5 TAUD0.CSR5
#define TAUD0CSR6 TAUD0.CSR6
#define TAUD0CSR7 TAUD0.CSR7
#define TAUD0CSR8 TAUD0.CSR8
#define TAUD0CSR9 TAUD0.CSR9
#define TAUD0CSR10 TAUD0.CSR10
#define TAUD0CSR11 TAUD0.CSR11
#define TAUD0CSR12 TAUD0.CSR12
#define TAUD0CSR13 TAUD0.CSR13
#define TAUD0CSR14 TAUD0.CSR14
#define TAUD0CSR15 TAUD0.CSR15
#define TAUD0CSC0 TAUD0.CSC0
#define TAUD0CSC1 TAUD0.CSC1
#define TAUD0CSC2 TAUD0.CSC2
#define TAUD0CSC3 TAUD0.CSC3
#define TAUD0CSC4 TAUD0.CSC4
#define TAUD0CSC5 TAUD0.CSC5
#define TAUD0CSC6 TAUD0.CSC6
#define TAUD0CSC7 TAUD0.CSC7
#define TAUD0CSC8 TAUD0.CSC8
#define TAUD0CSC9 TAUD0.CSC9
#define TAUD0CSC10 TAUD0.CSC10
#define TAUD0CSC11 TAUD0.CSC11
#define TAUD0CSC12 TAUD0.CSC12
#define TAUD0CSC13 TAUD0.CSC13
#define TAUD0CSC14 TAUD0.CSC14
#define TAUD0CSC15 TAUD0.CSC15
#define TAUD0TE TAUD0.TE
#define TAUD0TS TAUD0.TS
#define TAUD0TT TAUD0.TT
#define TAUD0CMOR0 TAUD0.CMOR0
#define TAUD0CMOR1 TAUD0.CMOR1
#define TAUD0CMOR2 TAUD0.CMOR2
#define TAUD0CMOR3 TAUD0.CMOR3
#define TAUD0CMOR4 TAUD0.CMOR4
#define TAUD0CMOR5 TAUD0.CMOR5
#define TAUD0CMOR6 TAUD0.CMOR6
#define TAUD0CMOR7 TAUD0.CMOR7
#define TAUD0CMOR8 TAUD0.CMOR8
#define TAUD0CMOR9 TAUD0.CMOR9
#define TAUD0CMOR10 TAUD0.CMOR10
#define TAUD0CMOR11 TAUD0.CMOR11
#define TAUD0CMOR12 TAUD0.CMOR12
#define TAUD0CMOR13 TAUD0.CMOR13
#define TAUD0CMOR14 TAUD0.CMOR14
#define TAUD0CMOR15 TAUD0.CMOR15
#define TAUD0TPS TAUD0.TPS
#define TAUD0BRS TAUD0.BRS
#define TAUD0TOM TAUD0.TOM
#define TAUD0TOC TAUD0.TOC
#define TAUD0TDE TAUD0.TDE
#define TAUD0TDM TAUD0.TDM
#define TAUD0TRE TAUD0.TRE
#define TAUD0TRC TAUD0.TRC
#define TAUD0RDE TAUD0.RDE
#define TAUD0RDM TAUD0.RDM
#define TAUD0RDS TAUD0.RDS
#define TAUD0RDC TAUD0.RDC
#define TAUD0EMU TAUD0.EMU
#define TAUJ0CDR0 TAUJ0.CDR0
#define TAUJ0CDR1 TAUJ0.CDR1
#define TAUJ0CDR2 TAUJ0.CDR2
#define TAUJ0CDR3 TAUJ0.CDR3
#define TAUJ0CNT0 TAUJ0.CNT0
#define TAUJ0CNT1 TAUJ0.CNT1
#define TAUJ0CNT2 TAUJ0.CNT2
#define TAUJ0CNT3 TAUJ0.CNT3
#define TAUJ0CMUR0 TAUJ0.CMUR0
#define TAUJ0CMUR1 TAUJ0.CMUR1
#define TAUJ0CMUR2 TAUJ0.CMUR2
#define TAUJ0CMUR3 TAUJ0.CMUR3
#define TAUJ0CSR0 TAUJ0.CSR0
#define TAUJ0CSR1 TAUJ0.CSR1
#define TAUJ0CSR2 TAUJ0.CSR2
#define TAUJ0CSR3 TAUJ0.CSR3
#define TAUJ0CSC0 TAUJ0.CSC0
#define TAUJ0CSC1 TAUJ0.CSC1
#define TAUJ0CSC2 TAUJ0.CSC2
#define TAUJ0CSC3 TAUJ0.CSC3
#define TAUJ0TE TAUJ0.TE
#define TAUJ0TS TAUJ0.TS
#define TAUJ0TT TAUJ0.TT
#define TAUJ0TO TAUJ0.TO
#define TAUJ0TOE TAUJ0.TOE
#define TAUJ0TOL TAUJ0.TOL
#define TAUJ0RDT TAUJ0.RDT
#define TAUJ0RSF TAUJ0.RSF
#define TAUJ0CMOR0 TAUJ0.CMOR0
#define TAUJ0CMOR1 TAUJ0.CMOR1
#define TAUJ0CMOR2 TAUJ0.CMOR2
#define TAUJ0CMOR3 TAUJ0.CMOR3
#define TAUJ0TPS TAUJ0.TPS
#define TAUJ0BRS TAUJ0.BRS
#define TAUJ0TOM TAUJ0.TOM
#define TAUJ0TOC TAUJ0.TOC
#define TAUJ0RDE TAUJ0.RDE
#define TAUJ0RDM TAUJ0.RDM
#define TAUJ0EMU TAUJ0.EMU
#define PWSA0CTL PWSA0.CTL
#define PWSA0STR PWSA0.STR
#define PWSA0STC PWSA0.STC
#define PWSA0EMU PWSA0.EMU
#define PWSA0QUE0 PWSA0.QUE0
#define PWSA0QUE1 PWSA0.QUE1
#define PWSA0QUE2 PWSA0.QUE2
#define PWSA0QUE3 PWSA0.QUE3
#define PWSA0QUE4 PWSA0.QUE4
#define PWSA0QUE5 PWSA0.QUE5
#define PWSA0QUE6 PWSA0.QUE6
#define PWSA0QUE7 PWSA0.QUE7
#define PWSA0PVCR00_01 PWSA0.PVCR00_01
#define PWSA0PVCR02_03 PWSA0.PVCR02_03
#define PWSA0PVCR04_05 PWSA0.PVCR04_05
#define PWSA0PVCR06_07 PWSA0.PVCR06_07
#define PWSA0PVCR08_09 PWSA0.PVCR08_09
#define PWSA0PVCR10_11 PWSA0.PVCR10_11
#define PWSA0PVCR12_13 PWSA0.PVCR12_13
#define PWSA0PVCR14_15 PWSA0.PVCR14_15
#define PWSA0PVCR16_17 PWSA0.PVCR16_17
#define PWSA0PVCR18_19 PWSA0.PVCR18_19
#define PWSA0PVCR20_21 PWSA0.PVCR20_21
#define PWSA0PVCR22_23 PWSA0.PVCR22_23
#define PWGA0CSDR PWGA0.CSDR
#define PWGA0CRDR PWGA0.CRDR
#define PWGA0CTDR PWGA0.CTDR
#define PWGA0RDT PWGA0.RDT
#define PWGA0RSF PWGA0.RSF
#define PWGA0CNT PWGA0.CNT
#define PWGA0CTL PWGA0.CTL
#define PWGA0CSBR PWGA0.CSBR
#define PWGA0CRBR PWGA0.CRBR
#define PWGA0CTBR PWGA0.CTBR
#define PWGA1CSDR PWGA1.CSDR
#define PWGA1CRDR PWGA1.CRDR
#define PWGA1CTDR PWGA1.CTDR
#define PWGA1RDT PWGA1.RDT
#define PWGA1RSF PWGA1.RSF
#define PWGA1CNT PWGA1.CNT
#define PWGA1CTL PWGA1.CTL
#define PWGA1CSBR PWGA1.CSBR
#define PWGA1CRBR PWGA1.CRBR
#define PWGA1CTBR PWGA1.CTBR
#define PWGA2CSDR PWGA2.CSDR
#define PWGA2CRDR PWGA2.CRDR
#define PWGA2CTDR PWGA2.CTDR
#define PWGA2RDT PWGA2.RDT
#define PWGA2RSF PWGA2.RSF
#define PWGA2CNT PWGA2.CNT
#define PWGA2CTL PWGA2.CTL
#define PWGA2CSBR PWGA2.CSBR
#define PWGA2CRBR PWGA2.CRBR
#define PWGA2CTBR PWGA2.CTBR
#define PWGA3CSDR PWGA3.CSDR
#define PWGA3CRDR PWGA3.CRDR
#define PWGA3CTDR PWGA3.CTDR
#define PWGA3RDT PWGA3.RDT
#define PWGA3RSF PWGA3.RSF
#define PWGA3CNT PWGA3.CNT
#define PWGA3CTL PWGA3.CTL
#define PWGA3CSBR PWGA3.CSBR
#define PWGA3CRBR PWGA3.CRBR
#define PWGA3CTBR PWGA3.CTBR
#define PWGA4CSDR PWGA4.CSDR
#define PWGA4CRDR PWGA4.CRDR
#define PWGA4CTDR PWGA4.CTDR
#define PWGA4RDT PWGA4.RDT
#define PWGA4RSF PWGA4.RSF
#define PWGA4CNT PWGA4.CNT
#define PWGA4CTL PWGA4.CTL
#define PWGA4CSBR PWGA4.CSBR
#define PWGA4CRBR PWGA4.CRBR
#define PWGA4CTBR PWGA4.CTBR
#define PWGA5CSDR PWGA5.CSDR
#define PWGA5CRDR PWGA5.CRDR
#define PWGA5CTDR PWGA5.CTDR
#define PWGA5RDT PWGA5.RDT
#define PWGA5RSF PWGA5.RSF
#define PWGA5CNT PWGA5.CNT
#define PWGA5CTL PWGA5.CTL
#define PWGA5CSBR PWGA5.CSBR
#define PWGA5CRBR PWGA5.CRBR
#define PWGA5CTBR PWGA5.CTBR
#define PWGA6CSDR PWGA6.CSDR
#define PWGA6CRDR PWGA6.CRDR
#define PWGA6CTDR PWGA6.CTDR
#define PWGA6RDT PWGA6.RDT
#define PWGA6RSF PWGA6.RSF
#define PWGA6CNT PWGA6.CNT
#define PWGA6CTL PWGA6.CTL
#define PWGA6CSBR PWGA6.CSBR
#define PWGA6CRBR PWGA6.CRBR
#define PWGA6CTBR PWGA6.CTBR
#define PWGA7CSDR PWGA7.CSDR
#define PWGA7CRDR PWGA7.CRDR
#define PWGA7CTDR PWGA7.CTDR
#define PWGA7RDT PWGA7.RDT
#define PWGA7RSF PWGA7.RSF
#define PWGA7CNT PWGA7.CNT
#define PWGA7CTL PWGA7.CTL
#define PWGA7CSBR PWGA7.CSBR
#define PWGA7CRBR PWGA7.CRBR
#define PWGA7CTBR PWGA7.CTBR
#define PWGA8CSDR PWGA8.CSDR
#define PWGA8CRDR PWGA8.CRDR
#define PWGA8CTDR PWGA8.CTDR
#define PWGA8RDT PWGA8.RDT
#define PWGA8RSF PWGA8.RSF
#define PWGA8CNT PWGA8.CNT
#define PWGA8CTL PWGA8.CTL
#define PWGA8CSBR PWGA8.CSBR
#define PWGA8CRBR PWGA8.CRBR
#define PWGA8CTBR PWGA8.CTBR
#define PWGA9CSDR PWGA9.CSDR
#define PWGA9CRDR PWGA9.CRDR
#define PWGA9CTDR PWGA9.CTDR
#define PWGA9RDT PWGA9.RDT
#define PWGA9RSF PWGA9.RSF
#define PWGA9CNT PWGA9.CNT
#define PWGA9CTL PWGA9.CTL
#define PWGA9CSBR PWGA9.CSBR
#define PWGA9CRBR PWGA9.CRBR
#define PWGA9CTBR PWGA9.CTBR
#define PWGA10CSDR PWGA10.CSDR
#define PWGA10CRDR PWGA10.CRDR
#define PWGA10CTDR PWGA10.CTDR
#define PWGA10RDT PWGA10.RDT
#define PWGA10RSF PWGA10.RSF
#define PWGA10CNT PWGA10.CNT
#define PWGA10CTL PWGA10.CTL
#define PWGA10CSBR PWGA10.CSBR
#define PWGA10CRBR PWGA10.CRBR
#define PWGA10CTBR PWGA10.CTBR
#define PWGA11CSDR PWGA11.CSDR
#define PWGA11CRDR PWGA11.CRDR
#define PWGA11CTDR PWGA11.CTDR
#define PWGA11RDT PWGA11.RDT
#define PWGA11RSF PWGA11.RSF
#define PWGA11CNT PWGA11.CNT
#define PWGA11CTL PWGA11.CTL
#define PWGA11CSBR PWGA11.CSBR
#define PWGA11CRBR PWGA11.CRBR
#define PWGA11CTBR PWGA11.CTBR
#define PWGA12CSDR PWGA12.CSDR
#define PWGA12CRDR PWGA12.CRDR
#define PWGA12CTDR PWGA12.CTDR
#define PWGA12RDT PWGA12.RDT
#define PWGA12RSF PWGA12.RSF
#define PWGA12CNT PWGA12.CNT
#define PWGA12CTL PWGA12.CTL
#define PWGA12CSBR PWGA12.CSBR
#define PWGA12CRBR PWGA12.CRBR
#define PWGA12CTBR PWGA12.CTBR
#define PWGA13CSDR PWGA13.CSDR
#define PWGA13CRDR PWGA13.CRDR
#define PWGA13CTDR PWGA13.CTDR
#define PWGA13RDT PWGA13.RDT
#define PWGA13RSF PWGA13.RSF
#define PWGA13CNT PWGA13.CNT
#define PWGA13CTL PWGA13.CTL
#define PWGA13CSBR PWGA13.CSBR
#define PWGA13CRBR PWGA13.CRBR
#define PWGA13CTBR PWGA13.CTBR
#define PWGA14CSDR PWGA14.CSDR
#define PWGA14CRDR PWGA14.CRDR
#define PWGA14CTDR PWGA14.CTDR
#define PWGA14RDT PWGA14.RDT
#define PWGA14RSF PWGA14.RSF
#define PWGA14CNT PWGA14.CNT
#define PWGA14CTL PWGA14.CTL
#define PWGA14CSBR PWGA14.CSBR
#define PWGA14CRBR PWGA14.CRBR
#define PWGA14CTBR PWGA14.CTBR
#define PWGA15CSDR PWGA15.CSDR
#define PWGA15CRDR PWGA15.CRDR
#define PWGA15CTDR PWGA15.CTDR
#define PWGA15RDT PWGA15.RDT
#define PWGA15RSF PWGA15.RSF
#define PWGA15CNT PWGA15.CNT
#define PWGA15CTL PWGA15.CTL
#define PWGA15CSBR PWGA15.CSBR
#define PWGA15CRBR PWGA15.CRBR
#define PWGA15CTBR PWGA15.CTBR
#define PWGA16CSDR PWGA16.CSDR
#define PWGA16CRDR PWGA16.CRDR
#define PWGA16CTDR PWGA16.CTDR
#define PWGA16RDT PWGA16.RDT
#define PWGA16RSF PWGA16.RSF
#define PWGA16CNT PWGA16.CNT
#define PWGA16CTL PWGA16.CTL
#define PWGA16CSBR PWGA16.CSBR
#define PWGA16CRBR PWGA16.CRBR
#define PWGA16CTBR PWGA16.CTBR
#define PWGA17CSDR PWGA17.CSDR
#define PWGA17CRDR PWGA17.CRDR
#define PWGA17CTDR PWGA17.CTDR
#define PWGA17RDT PWGA17.RDT
#define PWGA17RSF PWGA17.RSF
#define PWGA17CNT PWGA17.CNT
#define PWGA17CTL PWGA17.CTL
#define PWGA17CSBR PWGA17.CSBR
#define PWGA17CRBR PWGA17.CRBR
#define PWGA17CTBR PWGA17.CTBR
#define PWGA18CSDR PWGA18.CSDR
#define PWGA18CRDR PWGA18.CRDR
#define PWGA18CTDR PWGA18.CTDR
#define PWGA18RDT PWGA18.RDT
#define PWGA18RSF PWGA18.RSF
#define PWGA18CNT PWGA18.CNT
#define PWGA18CTL PWGA18.CTL
#define PWGA18CSBR PWGA18.CSBR
#define PWGA18CRBR PWGA18.CRBR
#define PWGA18CTBR PWGA18.CTBR
#define PWGA19CSDR PWGA19.CSDR
#define PWGA19CRDR PWGA19.CRDR
#define PWGA19CTDR PWGA19.CTDR
#define PWGA19RDT PWGA19.RDT
#define PWGA19RSF PWGA19.RSF
#define PWGA19CNT PWGA19.CNT
#define PWGA19CTL PWGA19.CTL
#define PWGA19CSBR PWGA19.CSBR
#define PWGA19CRBR PWGA19.CRBR
#define PWGA19CTBR PWGA19.CTBR
#define PWGA20CSDR PWGA20.CSDR
#define PWGA20CRDR PWGA20.CRDR
#define PWGA20CTDR PWGA20.CTDR
#define PWGA20RDT PWGA20.RDT
#define PWGA20RSF PWGA20.RSF
#define PWGA20CNT PWGA20.CNT
#define PWGA20CTL PWGA20.CTL
#define PWGA20CSBR PWGA20.CSBR
#define PWGA20CRBR PWGA20.CRBR
#define PWGA20CTBR PWGA20.CTBR
#define PWGA21CSDR PWGA21.CSDR
#define PWGA21CRDR PWGA21.CRDR
#define PWGA21CTDR PWGA21.CTDR
#define PWGA21RDT PWGA21.RDT
#define PWGA21RSF PWGA21.RSF
#define PWGA21CNT PWGA21.CNT
#define PWGA21CTL PWGA21.CTL
#define PWGA21CSBR PWGA21.CSBR
#define PWGA21CRBR PWGA21.CRBR
#define PWGA21CTBR PWGA21.CTBR
#define PWGA22CSDR PWGA22.CSDR
#define PWGA22CRDR PWGA22.CRDR
#define PWGA22CTDR PWGA22.CTDR
#define PWGA22RDT PWGA22.RDT
#define PWGA22RSF PWGA22.RSF
#define PWGA22CNT PWGA22.CNT
#define PWGA22CTL PWGA22.CTL
#define PWGA22CSBR PWGA22.CSBR
#define PWGA22CRBR PWGA22.CRBR
#define PWGA22CTBR PWGA22.CTBR
#define PWGA23CSDR PWGA23.CSDR
#define PWGA23CRDR PWGA23.CRDR
#define PWGA23CTDR PWGA23.CTDR
#define PWGA23RDT PWGA23.RDT
#define PWGA23RSF PWGA23.RSF
#define PWGA23CNT PWGA23.CNT
#define PWGA23CTL PWGA23.CTL
#define PWGA23CSBR PWGA23.CSBR
#define PWGA23CRBR PWGA23.CRBR
#define PWGA23CTBR PWGA23.CTBR
#define PWBA0BRS0 PWBA0.BRS0
#define PWBA0BRS1 PWBA0.BRS1
#define PWBA0BRS2 PWBA0.BRS2
#define PWBA0BRS3 PWBA0.BRS3
#define PWBA0TE PWBA0.TE
#define PWBA0TS PWBA0.TS
#define PWBA0TT PWBA0.TT
#define PWBA0EMU PWBA0.EMU
#define ENCA0CCR0 ENCA0.CCR0
#define ENCA0CCR1 ENCA0.CCR1
#define ENCA0CNT ENCA0.CNT
#define ENCA0FLG ENCA0.FLG
#define ENCA0FGC ENCA0.FGC
#define ENCA0TE ENCA0.TE
#define ENCA0TS ENCA0.TS
#define ENCA0TT ENCA0.TT
#define ENCA0IOC0 ENCA0.IOC0
#define ENCA0CTL ENCA0.CTL
#define ENCA0IOC1 ENCA0.IOC1
#define ENCA0EMU ENCA0.EMU
#define TAPA0FLG TAPA0.FLG
#define TAPA0ACWE TAPA0.ACWE
#define TAPA0ACTS TAPA0.ACTS
#define TAPA0ACTT TAPA0.ACTT
#define TAPA0OPHS TAPA0.OPHS
#define TAPA0OPHT TAPA0.OPHT
#define TAPA0CTL0 TAPA0.CTL0
#define TAPA0CTL1 TAPA0.CTL1
#define TAPA0EMU TAPA0.EMU
#define OSTM0CMP OSTM0.CMP
#define OSTM0CNT OSTM0.CNT
#define OSTM0TE OSTM0.TE
#define OSTM0TS OSTM0.TS
#define OSTM0TT OSTM0.TT
#define OSTM0CTL OSTM0.CTL
#define OSTM0EMU OSTM0.EMU
#define WDTA0WDTE WDTA0.WDTE
#define WDTA0EVAC WDTA0.EVAC
#define WDTA0REF WDTA0.REF
#define WDTA0MD WDTA0.MD
#define WDTA1WDTE WDTA1.WDTE
#define WDTA1EVAC WDTA1.EVAC
#define WDTA1REF WDTA1.REF
#define WDTA1MD WDTA1.MD
#define ADCA0VCR00 ADCA0.VCR00.UINT32
#define ADCA0VCR00L ADCA0.VCR00.UINT16[L]
#define ADCA0VCR01 ADCA0.VCR01.UINT32
#define ADCA0VCR01L ADCA0.VCR01.UINT16[L]
#define ADCA0VCR02 ADCA0.VCR02.UINT32
#define ADCA0VCR02L ADCA0.VCR02.UINT16[L]
#define ADCA0VCR03 ADCA0.VCR03.UINT32
#define ADCA0VCR03L ADCA0.VCR03.UINT16[L]
#define ADCA0VCR04 ADCA0.VCR04.UINT32
#define ADCA0VCR04L ADCA0.VCR04.UINT16[L]
#define ADCA0VCR05 ADCA0.VCR05.UINT32
#define ADCA0VCR05L ADCA0.VCR05.UINT16[L]
#define ADCA0VCR06 ADCA0.VCR06.UINT32
#define ADCA0VCR06L ADCA0.VCR06.UINT16[L]
#define ADCA0VCR07 ADCA0.VCR07.UINT32
#define ADCA0VCR07L ADCA0.VCR07.UINT16[L]
#define ADCA0VCR08 ADCA0.VCR08.UINT32
#define ADCA0VCR08L ADCA0.VCR08.UINT16[L]
#define ADCA0VCR09 ADCA0.VCR09.UINT32
#define ADCA0VCR09L ADCA0.VCR09.UINT16[L]
#define ADCA0VCR10 ADCA0.VCR10.UINT32
#define ADCA0VCR10L ADCA0.VCR10.UINT16[L]
#define ADCA0VCR11 ADCA0.VCR11.UINT32
#define ADCA0VCR11L ADCA0.VCR11.UINT16[L]
#define ADCA0VCR12 ADCA0.VCR12.UINT32
#define ADCA0VCR12L ADCA0.VCR12.UINT16[L]
#define ADCA0VCR13 ADCA0.VCR13.UINT32
#define ADCA0VCR13L ADCA0.VCR13.UINT16[L]
#define ADCA0VCR14 ADCA0.VCR14.UINT32
#define ADCA0VCR14L ADCA0.VCR14.UINT16[L]
#define ADCA0VCR15 ADCA0.VCR15.UINT32
#define ADCA0VCR15L ADCA0.VCR15.UINT16[L]
#define ADCA0VCR16 ADCA0.VCR16.UINT32
#define ADCA0VCR16L ADCA0.VCR16.UINT16[L]
#define ADCA0VCR17 ADCA0.VCR17.UINT32
#define ADCA0VCR17L ADCA0.VCR17.UINT16[L]
#define ADCA0VCR18 ADCA0.VCR18.UINT32
#define ADCA0VCR18L ADCA0.VCR18.UINT16[L]
#define ADCA0VCR19 ADCA0.VCR19.UINT32
#define ADCA0VCR19L ADCA0.VCR19.UINT16[L]
#define ADCA0VCR20 ADCA0.VCR20.UINT32
#define ADCA0VCR20L ADCA0.VCR20.UINT16[L]
#define ADCA0VCR21 ADCA0.VCR21.UINT32
#define ADCA0VCR21L ADCA0.VCR21.UINT16[L]
#define ADCA0VCR22 ADCA0.VCR22.UINT32
#define ADCA0VCR22L ADCA0.VCR22.UINT16[L]
#define ADCA0VCR23 ADCA0.VCR23.UINT32
#define ADCA0VCR23L ADCA0.VCR23.UINT16[L]
#define ADCA0VCR24 ADCA0.VCR24.UINT32
#define ADCA0VCR24L ADCA0.VCR24.UINT16[L]
#define ADCA0VCR25 ADCA0.VCR25.UINT32
#define ADCA0VCR25L ADCA0.VCR25.UINT16[L]
#define ADCA0VCR26 ADCA0.VCR26.UINT32
#define ADCA0VCR26L ADCA0.VCR26.UINT16[L]
#define ADCA0VCR27 ADCA0.VCR27.UINT32
#define ADCA0VCR27L ADCA0.VCR27.UINT16[L]
#define ADCA0VCR28 ADCA0.VCR28.UINT32
#define ADCA0VCR28L ADCA0.VCR28.UINT16[L]
#define ADCA0VCR29 ADCA0.VCR29.UINT32
#define ADCA0VCR29L ADCA0.VCR29.UINT16[L]
#define ADCA0VCR30 ADCA0.VCR30.UINT32
#define ADCA0VCR30L ADCA0.VCR30.UINT16[L]
#define ADCA0VCR31 ADCA0.VCR31.UINT32
#define ADCA0VCR31L ADCA0.VCR31.UINT16[L]
#define ADCA0VCR32 ADCA0.VCR32.UINT32
#define ADCA0VCR32L ADCA0.VCR32.UINT16[L]
#define ADCA0VCR33 ADCA0.VCR33.UINT32
#define ADCA0VCR33L ADCA0.VCR33.UINT16[L]
#define ADCA0VCR34 ADCA0.VCR34.UINT32
#define ADCA0VCR34L ADCA0.VCR34.UINT16[L]
#define ADCA0VCR35 ADCA0.VCR35.UINT32
#define ADCA0VCR35L ADCA0.VCR35.UINT16[L]
#define ADCA0VCR36 ADCA0.VCR36.UINT32
#define ADCA0VCR36L ADCA0.VCR36.UINT16[L]
#define ADCA0PWDVCR ADCA0.PWDVCR.UINT32
#define ADCA0PWDVCRL ADCA0.PWDVCR.UINT16[L]
#define ADCA0DR00 ADCA0.DR00
#define ADCA0DR02 ADCA0.DR02
#define ADCA0DR04 ADCA0.DR04
#define ADCA0DR06 ADCA0.DR06
#define ADCA0DR08 ADCA0.DR08
#define ADCA0DR10 ADCA0.DR10
#define ADCA0DR12 ADCA0.DR12
#define ADCA0DR14 ADCA0.DR14
#define ADCA0DR16 ADCA0.DR16
#define ADCA0DR18 ADCA0.DR18
#define ADCA0DR20 ADCA0.DR20
#define ADCA0DR22 ADCA0.DR22
#define ADCA0DR24 ADCA0.DR24
#define ADCA0DR26 ADCA0.DR26
#define ADCA0DR28 ADCA0.DR28
#define ADCA0DR30 ADCA0.DR30
#define ADCA0DR32 ADCA0.DR32
#define ADCA0DR34 ADCA0.DR34
#define ADCA0DR36 ADCA0.DR36
#define ADCA0PWDTSNDR ADCA0.PWDTSNDR
#define ADCA0DIR00 ADCA0.DIR00.UINT32
#define ADCA0DIR00L ADCA0.DIR00.UINT16[L]
#define ADCA0DIR01 ADCA0.DIR01.UINT32
#define ADCA0DIR01L ADCA0.DIR01.UINT16[L]
#define ADCA0DIR02 ADCA0.DIR02.UINT32
#define ADCA0DIR02L ADCA0.DIR02.UINT16[L]
#define ADCA0DIR03 ADCA0.DIR03.UINT32
#define ADCA0DIR03L ADCA0.DIR03.UINT16[L]
#define ADCA0DIR04 ADCA0.DIR04.UINT32
#define ADCA0DIR04L ADCA0.DIR04.UINT16[L]
#define ADCA0DIR05 ADCA0.DIR05.UINT32
#define ADCA0DIR05L ADCA0.DIR05.UINT16[L]
#define ADCA0DIR06 ADCA0.DIR06.UINT32
#define ADCA0DIR06L ADCA0.DIR06.UINT16[L]
#define ADCA0DIR07 ADCA0.DIR07.UINT32
#define ADCA0DIR07L ADCA0.DIR07.UINT16[L]
#define ADCA0DIR08 ADCA0.DIR08.UINT32
#define ADCA0DIR08L ADCA0.DIR08.UINT16[L]
#define ADCA0DIR09 ADCA0.DIR09.UINT32
#define ADCA0DIR09L ADCA0.DIR09.UINT16[L]
#define ADCA0DIR10 ADCA0.DIR10.UINT32
#define ADCA0DIR10L ADCA0.DIR10.UINT16[L]
#define ADCA0DIR11 ADCA0.DIR11.UINT32
#define ADCA0DIR11L ADCA0.DIR11.UINT16[L]
#define ADCA0DIR12 ADCA0.DIR12.UINT32
#define ADCA0DIR12L ADCA0.DIR12.UINT16[L]
#define ADCA0DIR13 ADCA0.DIR13.UINT32
#define ADCA0DIR13L ADCA0.DIR13.UINT16[L]
#define ADCA0DIR14 ADCA0.DIR14.UINT32
#define ADCA0DIR14L ADCA0.DIR14.UINT16[L]
#define ADCA0DIR15 ADCA0.DIR15.UINT32
#define ADCA0DIR15L ADCA0.DIR15.UINT16[L]
#define ADCA0DIR16 ADCA0.DIR16.UINT32
#define ADCA0DIR16L ADCA0.DIR16.UINT16[L]
#define ADCA0DIR17 ADCA0.DIR17.UINT32
#define ADCA0DIR17L ADCA0.DIR17.UINT16[L]
#define ADCA0DIR18 ADCA0.DIR18.UINT32
#define ADCA0DIR18L ADCA0.DIR18.UINT16[L]
#define ADCA0DIR19 ADCA0.DIR19.UINT32
#define ADCA0DIR19L ADCA0.DIR19.UINT16[L]
#define ADCA0DIR20 ADCA0.DIR20.UINT32
#define ADCA0DIR20L ADCA0.DIR20.UINT16[L]
#define ADCA0DIR21 ADCA0.DIR21.UINT32
#define ADCA0DIR21L ADCA0.DIR21.UINT16[L]
#define ADCA0DIR22 ADCA0.DIR22.UINT32
#define ADCA0DIR22L ADCA0.DIR22.UINT16[L]
#define ADCA0DIR23 ADCA0.DIR23.UINT32
#define ADCA0DIR23L ADCA0.DIR23.UINT16[L]
#define ADCA0DIR24 ADCA0.DIR24.UINT32
#define ADCA0DIR24L ADCA0.DIR24.UINT16[L]
#define ADCA0DIR25 ADCA0.DIR25.UINT32
#define ADCA0DIR25L ADCA0.DIR25.UINT16[L]
#define ADCA0DIR26 ADCA0.DIR26.UINT32
#define ADCA0DIR26L ADCA0.DIR26.UINT16[L]
#define ADCA0DIR27 ADCA0.DIR27.UINT32
#define ADCA0DIR27L ADCA0.DIR27.UINT16[L]
#define ADCA0DIR28 ADCA0.DIR28.UINT32
#define ADCA0DIR28L ADCA0.DIR28.UINT16[L]
#define ADCA0DIR29 ADCA0.DIR29.UINT32
#define ADCA0DIR29L ADCA0.DIR29.UINT16[L]
#define ADCA0DIR30 ADCA0.DIR30.UINT32
#define ADCA0DIR30L ADCA0.DIR30.UINT16[L]
#define ADCA0DIR31 ADCA0.DIR31.UINT32
#define ADCA0DIR31L ADCA0.DIR31.UINT16[L]
#define ADCA0DIR32 ADCA0.DIR32.UINT32
#define ADCA0DIR32L ADCA0.DIR32.UINT16[L]
#define ADCA0DIR33 ADCA0.DIR33.UINT32
#define ADCA0DIR33L ADCA0.DIR33.UINT16[L]
#define ADCA0DIR34 ADCA0.DIR34.UINT32
#define ADCA0DIR34L ADCA0.DIR34.UINT16[L]
#define ADCA0DIR35 ADCA0.DIR35.UINT32
#define ADCA0DIR35L ADCA0.DIR35.UINT16[L]
#define ADCA0DIR36 ADCA0.DIR36.UINT32
#define ADCA0DIR36L ADCA0.DIR36.UINT16[L]
#define ADCA0PWDDIR ADCA0.PWDDIR.UINT32
#define ADCA0PWDDIRL ADCA0.PWDDIR.UINT16[L]
#define ADCA0ADHALTR ADCA0.ADHALTR.UINT32
#define ADCA0ADHALTRL ADCA0.ADHALTR.UINT16[L]
#define ADCA0ADHALTRLL ADCA0.ADHALTR.UINT8[LL]
#define ADCA0ADCR ADCA0.ADCR.UINT32
#define ADCA0ADCRL ADCA0.ADCR.UINT16[L]
#define ADCA0ADCRLL ADCA0.ADCR.UINT8[LL]
#define ADCA0SGSTR ADCA0.SGSTR.UINT32
#define ADCA0SGSTRL ADCA0.SGSTR.UINT16[L]
#define ADCA0MPXCURR ADCA0.MPXCURR.UINT32
#define ADCA0MPXCURRL ADCA0.MPXCURR.UINT16[L]
#define ADCA0MPXCURRLL ADCA0.MPXCURR.UINT8[LL]
#define ADCA0THSMPSTCR ADCA0.THSMPSTCR.UINT32
#define ADCA0THSMPSTCRL ADCA0.THSMPSTCR.UINT16[L]
#define ADCA0THSMPSTCRLL ADCA0.THSMPSTCR.UINT8[LL]
#define ADCA0THCR ADCA0.THCR.UINT32
#define ADCA0THCRL ADCA0.THCR.UINT16[L]
#define ADCA0THCRLL ADCA0.THCR.UINT8[LL]
#define ADCA0THAHLDSTCR ADCA0.THAHLDSTCR.UINT32
#define ADCA0THAHLDSTCRL ADCA0.THAHLDSTCR.UINT16[L]
#define ADCA0THAHLDSTCRLL ADCA0.THAHLDSTCR.UINT8[LL]
#define ADCA0THBHLDSTCR ADCA0.THBHLDSTCR.UINT32
#define ADCA0THBHLDSTCRL ADCA0.THBHLDSTCR.UINT16[L]
#define ADCA0THBHLDSTCRLL ADCA0.THBHLDSTCR.UINT8[LL]
#define ADCA0THACR ADCA0.THACR.UINT32
#define ADCA0THACRL ADCA0.THACR.UINT16[L]
#define ADCA0THACRLL ADCA0.THACR.UINT8[LL]
#define ADCA0THBCR ADCA0.THBCR.UINT32
#define ADCA0THBCRL ADCA0.THBCR.UINT16[L]
#define ADCA0THBCRLL ADCA0.THBCR.UINT8[LL]
#define ADCA0THER ADCA0.THER.UINT32
#define ADCA0THERL ADCA0.THER.UINT16[L]
#define ADCA0THERLL ADCA0.THER.UINT8[LL]
#define ADCA0THGSR ADCA0.THGSR.UINT32
#define ADCA0THGSRL ADCA0.THGSR.UINT16[L]
#define ADCA0THGSRLL ADCA0.THGSR.UINT8[LL]
#define ADCA0SFTCR ADCA0.SFTCR.UINT32
#define ADCA0SFTCRL ADCA0.SFTCR.UINT16[L]
#define ADCA0SFTCRLL ADCA0.SFTCR.UINT8[LL]
#define ADCA0ULLMTBR0 ADCA0.ULLMTBR0.UINT32
#define ADCA0ULLMTBR0L ADCA0.ULLMTBR0.UINT16[L]
#define ADCA0ULLMTBR0H ADCA0.ULLMTBR0.UINT16[H]
#define ADCA0ULLMTBR1 ADCA0.ULLMTBR1.UINT32
#define ADCA0ULLMTBR1L ADCA0.ULLMTBR1.UINT16[L]
#define ADCA0ULLMTBR1H ADCA0.ULLMTBR1.UINT16[H]
#define ADCA0ULLMTBR2 ADCA0.ULLMTBR2.UINT32
#define ADCA0ULLMTBR2L ADCA0.ULLMTBR2.UINT16[L]
#define ADCA0ULLMTBR2H ADCA0.ULLMTBR2.UINT16[H]
#define ADCA0ECR ADCA0.ECR.UINT32
#define ADCA0ECRL ADCA0.ECR.UINT16[L]
#define ADCA0ECRLL ADCA0.ECR.UINT8[LL]
#define ADCA0ULER ADCA0.ULER.UINT32
#define ADCA0ULERL ADCA0.ULER.UINT16[L]
#define ADCA0OWER ADCA0.OWER.UINT32
#define ADCA0OWERL ADCA0.OWER.UINT16[L]
#define ADCA0OWERLL ADCA0.OWER.UINT8[LL]
#define ADCA0DGCTL0 ADCA0.DGCTL0.UINT32
#define ADCA0DGCTL0L ADCA0.DGCTL0.UINT16[L]
#define ADCA0DGCTL0LL ADCA0.DGCTL0.UINT8[LL]
#define ADCA0DGCTL1 ADCA0.DGCTL1.UINT32
#define ADCA0DGCTL1L ADCA0.DGCTL1.UINT16[L]
#define ADCA0PDCTL1 ADCA0.PDCTL1.UINT32
#define ADCA0PDCTL1L ADCA0.PDCTL1.UINT16[L]
#define ADCA0PDCTL2 ADCA0.PDCTL2
#define ADCA0SMPCR ADCA0.SMPCR.UINT32
#define ADCA0SMPCRL ADCA0.SMPCR.UINT16[L]
#define ADCA0SMPCRLL ADCA0.SMPCR.UINT8[LL]
#define ADCA0EMU ADCA0.EMU
#define ADCA0SGSTCR1 ADCA0.SGSTCR1.UINT32
#define ADCA0SGSTCR1L ADCA0.SGSTCR1.UINT16[L]
#define ADCA0SGSTCR1LL ADCA0.SGSTCR1.UINT8[LL]
#define ADCA0SGCR1 ADCA0.SGCR1.UINT32
#define ADCA0SGCR1L ADCA0.SGCR1.UINT16[L]
#define ADCA0SGCR1LL ADCA0.SGCR1.UINT8[LL]
#define ADCA0SGVCSP1 ADCA0.SGVCSP1.UINT32
#define ADCA0SGVCSP1L ADCA0.SGVCSP1.UINT16[L]
#define ADCA0SGVCSP1LL ADCA0.SGVCSP1.UINT8[LL]
#define ADCA0SGVCEP1 ADCA0.SGVCEP1.UINT32
#define ADCA0SGVCEP1L ADCA0.SGVCEP1.UINT16[L]
#define ADCA0SGVCEP1LL ADCA0.SGVCEP1.UINT8[LL]
#define ADCA0SGMCYCR1 ADCA0.SGMCYCR1.UINT32
#define ADCA0SGMCYCR1L ADCA0.SGMCYCR1.UINT16[L]
#define ADCA0SGMCYCR1LL ADCA0.SGMCYCR1.UINT8[LL]
#define ADCA0SGSEFCR1 ADCA0.SGSEFCR1.UINT32
#define ADCA0SGSEFCR1L ADCA0.SGSEFCR1.UINT16[L]
#define ADCA0SGSEFCR1LL ADCA0.SGSEFCR1.UINT8[LL]
#define ADCA0SGTSEL1 ADCA0.SGTSEL1.UINT32
#define ADCA0SGTSEL1L ADCA0.SGTSEL1.UINT16[L]
#define ADCA0SGSTCR2 ADCA0.SGSTCR2.UINT32
#define ADCA0SGSTCR2L ADCA0.SGSTCR2.UINT16[L]
#define ADCA0SGSTCR2LL ADCA0.SGSTCR2.UINT8[LL]
#define ADCA0SGCR2 ADCA0.SGCR2.UINT32
#define ADCA0SGCR2L ADCA0.SGCR2.UINT16[L]
#define ADCA0SGCR2LL ADCA0.SGCR2.UINT8[LL]
#define ADCA0SGVCSP2 ADCA0.SGVCSP2.UINT32
#define ADCA0SGVCSP2L ADCA0.SGVCSP2.UINT16[L]
#define ADCA0SGVCSP2LL ADCA0.SGVCSP2.UINT8[LL]
#define ADCA0SGVCEP2 ADCA0.SGVCEP2.UINT32
#define ADCA0SGVCEP2L ADCA0.SGVCEP2.UINT16[L]
#define ADCA0SGVCEP2LL ADCA0.SGVCEP2.UINT8[LL]
#define ADCA0SGMCYCR2 ADCA0.SGMCYCR2.UINT32
#define ADCA0SGMCYCR2L ADCA0.SGMCYCR2.UINT16[L]
#define ADCA0SGMCYCR2LL ADCA0.SGMCYCR2.UINT8[LL]
#define ADCA0SGSEFCR2 ADCA0.SGSEFCR2.UINT32
#define ADCA0SGSEFCR2L ADCA0.SGSEFCR2.UINT16[L]
#define ADCA0SGSEFCR2LL ADCA0.SGSEFCR2.UINT8[LL]
#define ADCA0SGTSEL2 ADCA0.SGTSEL2.UINT32
#define ADCA0SGTSEL2L ADCA0.SGTSEL2.UINT16[L]
#define ADCA0SGSTCR3 ADCA0.SGSTCR3.UINT32
#define ADCA0SGSTCR3L ADCA0.SGSTCR3.UINT16[L]
#define ADCA0SGSTCR3LL ADCA0.SGSTCR3.UINT8[LL]
#define ADCA0SGCR3 ADCA0.SGCR3.UINT32
#define ADCA0SGCR3L ADCA0.SGCR3.UINT16[L]
#define ADCA0SGCR3LL ADCA0.SGCR3.UINT8[LL]
#define ADCA0SGVCSP3 ADCA0.SGVCSP3.UINT32
#define ADCA0SGVCSP3L ADCA0.SGVCSP3.UINT16[L]
#define ADCA0SGVCSP3LL ADCA0.SGVCSP3.UINT8[LL]
#define ADCA0SGVCEP3 ADCA0.SGVCEP3.UINT32
#define ADCA0SGVCEP3L ADCA0.SGVCEP3.UINT16[L]
#define ADCA0SGVCEP3LL ADCA0.SGVCEP3.UINT8[LL]
#define ADCA0SGMCYCR3 ADCA0.SGMCYCR3.UINT32
#define ADCA0SGMCYCR3L ADCA0.SGMCYCR3.UINT16[L]
#define ADCA0SGMCYCR3LL ADCA0.SGMCYCR3.UINT8[LL]
#define ADCA0SGSEFCR3 ADCA0.SGSEFCR3.UINT32
#define ADCA0SGSEFCR3L ADCA0.SGSEFCR3.UINT16[L]
#define ADCA0SGSEFCR3LL ADCA0.SGSEFCR3.UINT8[LL]
#define ADCA0SGTSEL3 ADCA0.SGTSEL3.UINT32
#define ADCA0SGTSEL3L ADCA0.SGTSEL3.UINT16[L]
#define ADCA0PWDSGCR ADCA0.PWDSGCR.UINT32
#define ADCA0PWDSGCRL ADCA0.PWDSGCR.UINT16[L]
#define ADCA0PWDSGCRLL ADCA0.PWDSGCR.UINT8[LL]
#define ADCA0PWDSGSEFCR ADCA0.PWDSGSEFCR.UINT32
#define ADCA0PWDSGSEFCRL ADCA0.PWDSGSEFCR.UINT16[L]
#define ADCA0PWDSGSEFCRLL ADCA0.PWDSGSEFCR.UINT8[LL]
#define DCRA0CIN DCRA0.CIN
#define DCRA0COUT DCRA0.COUT
#define DCRA0CTL DCRA0.CTL
#define DCRA1CIN DCRA1.CIN
#define DCRA1COUT DCRA1.COUT
#define DCRA1CTL DCRA1.CTL
#define DCRA2CIN DCRA2.CIN
#define DCRA2COUT DCRA2.COUT
#define DCRA2CTL DCRA2.CTL
#define DCRA3CIN DCRA3.CIN
#define DCRA3COUT DCRA3.COUT
#define DCRA3CTL DCRA3.CTL
#define KR0KRM KR0.KRM.UINT8
#define KR0KRM0 KR0.KRM.BIT.KRM0
#define KR0KRM1 KR0.KRM.BIT.KRM1
#define KR0KRM2 KR0.KRM.BIT.KRM2
#define KR0KRM3 KR0.KRM.BIT.KRM3
#define KR0KRM4 KR0.KRM.BIT.KRM4
#define KR0KRM5 KR0.KRM.BIT.KRM5
#define KR0KRM6 KR0.KRM.BIT.KRM6
#define KR0KRM7 KR0.KRM.BIT.KRM7
#define CLMA0CTL0 CLMA0.CTL0
#define CLMA0CMPL CLMA0.CMPL
#define CLMA0CMPH CLMA0.CMPH
#define CLMA0PCMD CLMA0.PCMD
#define CLMA0PS CLMA0.PS
#define CLMA0EMU0 CLMA0.EMU0
#define CLMATEST CLMA.TEST
#define CLMATESTS CLMA.TESTS
#define CLMA1CTL0 CLMA1.CTL0
#define CLMA1CMPL CLMA1.CMPL
#define CLMA1CMPH CLMA1.CMPH
#define CLMA1PCMD CLMA1.PCMD
#define CLMA1PS CLMA1.PS
#define CLMA1EMU0 CLMA1.EMU0
#define CLMA2CTL0 CLMA2.CTL0
#define CLMA2CMPL CLMA2.CMPL
#define CLMA2CMPH CLMA2.CMPH
#define CLMA2PCMD CLMA2.PCMD
#define CLMA2PS CLMA2.PS
#define CLMA2EMU0 CLMA2.EMU0
#endif
