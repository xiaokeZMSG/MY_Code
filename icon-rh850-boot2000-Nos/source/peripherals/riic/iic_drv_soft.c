/*
 * file: iic_drv_soft.c
 * Description:  i2c software driver
 * Change Logs:
 * Date           Author          VER  Notes
 * 2018-07-02    mgd              0.1  First edition
 */
#include <freertos.h>
#include <semphr.h>
#include "r_port.h"
#include "iic_drv_soft.h"
#include "r_device.h"


#define delayTime    (2u)
/* BAIC board hardware: 
   SDA -- PTA2
   SCL -- PTA3
 */	
#define SINGLEADDR         0
#define MULTIADDR          1


#define MUTEX_t                  SemaphoreHandle_t
#define I2C_MUTEX_TAKE(dev)      xSemaphoreTakeRecursive(*dev->master->mutex, 500)
#define I2C_MUTEX_REALSE(dev)    xSemaphoreGiveRecursive(*dev->master->mutex)


#define I2C_SCL_1(i2c_dev)       (i2c_dev->master->SCL_P_Reg |= 1<<i2c_dev->master->sck_gpio_pin)				/* SCL = 1 */
#define I2C_SCL_0(i2c_dev)       (i2c_dev->master->SCL_P_Reg |= 1<<i2c_dev->master->sck_gpio_pin)				/* SCL = 0 */

#define I2C_SDA_1(i2c_dev)       (i2c_dev->master->SDA_P_Reg |= 1<<i2c_dev->master->sda_gpio_pin)				/* SDA = 1 */
#define I2C_SDA_0(i2c_dev)       (i2c_dev->master->SDA_P_Reg |= 1<<i2c_dev->master->sda_gpio_pin)				/* SDA = 0 */

//#define I2C_SDA_IN(i2c_dev)      //s32k14x_pin_dir_set(i2c_dev->master->sda_gpio, i2c_dev->master->sda_gpio_pin, DIR_INPUT);
//#define I2C_SDA_OUT(i2c_dev)     //s32k14x_pin_dir_set(i2c_dev->master->sda_gpio, i2c_dev->master->sda_gpio_pin, DIR_OUTPUT);

#define I2C_SDA_READ(i2c_dev)    (i2c_dev->master->SDA_PPR_Reg & (1<<i2c_dev->master->sda_gpio_pin))	/* Read SDA status */
//#define I2C_SCL_READ(i2c_dev)    (i2c_dev->master->sck_gpio->PDIR & (1<<i2c_dev->master->sck_gpio_pin))	/* Read SCL status */

#define IIC0_SDA_PCC             PCC_PORTA_INDEX
#define IIC0_SDA_PORT_INDEX      PORTA
#define IIC0_SDA_PORT            PTA
#define IIC0_SDA_PIN             2

#define IIC0_SCK_PCC             PCC_PORTA_INDEX
#define IIC0_SCK_PORT_INDEX      PORTA
#define IIC0_SCK_PORT            PTA
#define IIC0_SCK_PIN             3

#define IIC1_SDA_PCC             PCC_PORTE_INDEX
#define IIC1_SDA_PORT_INDEX      PORTE
#define IIC1_SDA_PORT            PTE
#define IIC1_SDA_PIN             7

#define IIC1_SCK_PCC             PCC_PORTE_INDEX
#define IIC1_SCK_PORT_INDEX      PORTE
#define IIC1_SCK_PORT            PTE
#define IIC1_SCK_PIN             8


struct soft_iic_master
{
	//uint8_t sda_peripheral_index;
	//PORT_Type *sda_port_index;	
	//GPIO_Type* sda_gpio;
	//uint32_t sda_gpio_pin; 
	//uint8_t sck_peripheral_index;
	//PORT_Type *sck_port_index;
	//GPIO_Type* sck_gpio;
	//uint32_t sck_gpio_pin;
    uint16_t sda_port;
    volatile uint16_t *SDA_P_Reg；
    uint32_t sda_gpio_pin;	
	volatile const uint16_t *SDA_PPR_Reg;
    uint16_t scl_port;
    volatile uint16_t *SCL_P_Reg；
    uint32_t scl_gpio_pin;	
	volatile const uint16_t *SCL_PPR_Reg;	
    MUTEX_t  *mutex;
};

static MUTEX_t    iic_mutex[1];
struct soft_iic_master iic_master_dev[]={
  {
    Port0,
    (volatile uint16_t *)&P0,
    11,
    (volatile uint16_t *)&PPR0,
	
	Port0,
    (volatile uint16_t *)&P0,
    12,
    (volatile uint16_t *)&PPR0, 
	
    &iic_mutex[0]
  },

};


struct soft_iic_cli_dev
{
	struct soft_iic_master 	*master;
	uint8_t  iic_addr;
	uint8_t  multiADDR;
};
#define  NOP()    __asm("nop")  /* nop instruction for very short delay */
#if 1
static inline void i2c_delay(void)
{
        NOP();
        NOP();
    //    NOP();
     //   NOP();
   //     NOP();
   //     NOP();
        
     //   NOP();
    //    NOP();
     //   NOP();
      //  NOP();
       // NOP();
       // NOP();
        
       // NOP();
       // NOP();
       // NOP();
       // NOP();
}
#else
#define i2c_delay()  do{ NOP();NOP();NOP();}while(0)//when core clock is 80M , the i2c read in 58us and  write 48us
#endif
/*********************************************************************************************************
** Function name: iic_soft_init
** Description  : Configure iic gpio
** Input        : None         
** Output       : None
** Note         : 
*********************************************************************************************************/

void iic_soft_init(int i2c_master_fd)
{
	struct soft_iic_master *dev = &iic_master_dev[i2c_master_fd];
        
	//s32k14x_clock_enable(dev->sda_peripheral_index, CLOCK_ENABLE);	
	//s32k14x_pin_function_set(dev->sda_port_index, dev->sda_gpio_pin, PIN_FUNCTION_GPIO);
	//s32k14x_pin_dir_set(dev->sda_gpio, dev->sda_gpio_pin, DIR_OUTPUT);
        
	//s32k14x_clock_enable(dev->sck_peripheral_index, CLOCK_ENABLE);
	//s32k14x_pin_function_set(dev->sck_port_index, dev->sck_gpio_pin, PIN_FUNCTION_GPIO);
	//s32k14x_pin_dir_set(dev->sck_gpio, dev->sck_gpio_pin, DIR_OUTPUT);
        
     *dev->mutex = xSemaphoreCreateRecursiveMutex();
}

/*********************************************************************************************************
** Function name: iic_soft_deinit
** Description  : Configure iic gpio
** Input        : None         
** Output       : None
** Note         : 
*********************************************************************************************************/
void iic_soft_deinit(int i2c_master_fd)
{
	struct soft_iic_master *dev = &iic_master_dev[i2c_master_fd];
 #if 0       
	s32k14x_gpio_write(dev->sda_gpio, dev->sda_gpio_pin,  1);
        i2c_delay();	
        s32k14x_pin_dir_set(dev->sda_gpio, dev->sda_gpio_pin, DIR_INPUT);//DIR_INPUT);
	s32k14x_pin_function_set(dev->sda_port_index, dev->sda_gpio_pin, PIN_FUNCTION_ALT0);
	s32k14x_clock_enable(dev->sda_peripheral_index, CLOCK_DISABLE);
        
        s32k14x_gpio_write(dev->sck_gpio, dev->sck_gpio_pin,  0);
        i2c_delay();	
        s32k14x_pin_dir_set(dev->sck_gpio, dev->sck_gpio_pin, DIR_INPUT);//DIR_INPUT);
	s32k14x_pin_function_set(dev->sck_port_index, dev->sck_gpio_pin, PIN_FUNCTION_ALT0);
	s32k14x_clock_enable(dev->sck_peripheral_index, CLOCK_DISABLE);
        
        
        s32k14x_gpio_write(PTB, 14,  0);
        i2c_delay();	
        s32k14x_pin_dir_set(PTB, 14, DIR_INPUT);//DIR_INPUT);
	s32k14x_pin_function_set(PORTB, 14, PIN_FUNCTION_ALT0);
	s32k14x_clock_enable(PCC_PORTB_INDEX, CLOCK_DISABLE);
 #endif       
       // *dev->mutex = xSemaphoreCreateRecursiveMutex();
}
/*********************************************************************************************************
** Function name: iic_start
** Description  : Start iic bus, when SCL is 1, SDA generate a falling edge.
** Input        : None             
** Output       : None
** Note         : 
*********************************************************************************************************/
static void iic_start(const struct soft_iic_cli_dev *dev)
{
	I2C_SDA_1(dev);
	I2C_SCL_1(dev);
	//uDelay(delayTime);
	i2c_delay();
	
	I2C_SDA_0(dev);
	//uDelay(delayTime);
	i2c_delay();
	
	I2C_SCL_0(dev);
	//uDelay(delayTime);
	i2c_delay();
}

/*********************************************************************************************************
** Function name: iic_stop
** Description  : 
** Input        : None    
** Output       : None
** Note         : 
*********************************************************************************************************/
static void iic_stop(const struct soft_iic_cli_dev *dev)
{
	I2C_SDA_0(dev);
	I2C_SCL_1(dev);
	//uDelay(delayTime);
	i2c_delay();
	
	I2C_SDA_1(dev);
	//uDelay(delayTime);
	i2c_delay();
}

/*********************************************************************************************************
** Function name: iic_send_byte
** Description  : 
** Input        : byte           
** Output       : None
** Note         : 
*********************************************************************************************************/
static void iic_send_byte(const struct soft_iic_cli_dev *dev, uint8_t byte)
{
	uint8_t i;
        
	for (i = 0; i < 8; i++)
	{
		if (byte & 0x80)
		{
			I2C_SDA_1(dev);
		}
		else
		{
			I2C_SDA_0(dev);
		}
		//uDelay(delayTime);
		i2c_delay();
		I2C_SCL_1(dev);
		//uDelay(delayTime);
		i2c_delay();
		I2C_SCL_0(dev);
		byte <<= 1;	
		//uDelay(delayTime);
		i2c_delay();
	}
        I2C_SDA_1(dev); 
        //uDelay(delayTime);
        i2c_delay();
}

/*********************************************************************************************************
** Function name: iic_read_byte
** Description  : 
** Input        : None        
** Output       : value 
** Note         : 
*********************************************************************************************************/
static uint8_t iic_read_byte(const struct soft_iic_cli_dev *dev)
{
	uint8_t i;
	uint8_t value;

	value = 0;
     //   I2C_SDA_IN(dev);
	for (i = 0; i < 8; i++)
	{
		value <<= 1;
		I2C_SCL_1(dev);
		//uDelay(delayTime);
		i2c_delay();
		if (I2C_SDA_READ(dev))
		{
			value++;
		}
		I2C_SCL_0(dev);
		//uDelay(delayTime);
		i2c_delay();
	}
    //I2C_SDA_OUT(dev);
	return value;	
}

/*********************************************************************************************************
** Function name: iic_wait_ack
** Description  : 
** Input        : None 
** Output       : ack/nack
** Note         : 
*********************************************************************************************************/
static uint8_t iic_wait_ack(const struct soft_iic_cli_dev *dev)
{

	uint8_t re;

	I2C_SDA_1(dev);	
	//uDelay(delayTime);
	i2c_delay();
	I2C_SCL_1(dev);	
	//uDelay(delayTime);
	i2c_delay();

    //I2C_SDA_IN(dev);
	
	if (I2C_SDA_READ(dev))
	{
		re = 1;
	}
	else
	{
		re = 0;
	}


	I2C_SCL_0(dev);
	//uDelay(delayTime);
	i2c_delay();
	//I2C_SDA_OUT(dev);
	return re;

}

/*********************************************************************************************************
** Function name: iic_ack
** Description  : 
** Input        : None
** Output       : None
** Note         : 
*********************************************************************************************************/
static void iic_ack(const struct soft_iic_cli_dev *dev)
{
	I2C_SDA_0(dev);	
	//uDelay(delayTime);
	i2c_delay();
	I2C_SCL_1(dev);	
	//uDelay(delayTime);
	i2c_delay();
	I2C_SCL_0(dev);
	//uDelay(delayTime);
	i2c_delay();
	I2C_SDA_1(dev);	
}

/*********************************************************************************************************
** Function name: iic_nack
** Description  : 
** Input        : None
** Output       : None
** Note         : 
*********************************************************************************************************/
static void iic_nack(const struct soft_iic_cli_dev *dev)
{
	I2C_SDA_1(dev);	
	//uDelay(delayTime);
	i2c_delay();
	I2C_SCL_1(dev);	
	//uDelay(delayTime);
	i2c_delay();
	I2C_SCL_0(dev);
	//uDelay(delayTime);
	i2c_delay();
}


#define IIC_WR	0		/* write control bit */
#define IIC_RD  1		/* read  control bit */
static const struct soft_iic_cli_dev iic_cli_dev[]=
{
     {//test slave 
	      &iic_master_dev[0],
	      0x02,//0x64,               
	      SINGLEADDR,
    },
     {//RTC RA8900 0
	      &iic_master_dev[0],
	      0x64,//0x64,               
	      SINGLEADDR,
    },
    {//TPA6404-Q  1
	     &iic_master_dev[0],		
	     0x54,               
	     SINGLEADDR,
    },
    {//TPS43331-Q1  2
	    &iic_master_dev[0],
	    0x10,               
	    SINGLEADDR,
     },
    {//E52400B62C  3
	   &iic_master_dev[1],
	   0xa2,
	   SINGLEADDR,
   },
   {//TCA6408A-Q1 4
	  &iic_master_dev[1],
	  0x40,
	  SINGLEADDR,
   },
   {//elmos-1 5
	  &iic_master_dev[1],
	  0x22,
	  SINGLEADDR,
   },
   {//elmos-2
	  &iic_master_dev[1],
	  0x24,
	  SINGLEADDR,
   },
    {//QBA
	  &iic_master_dev[1],
	  0xDA,
	  SINGLEADDR,
   },
}	;
/*********************************************************************************************************
** Function name: rtc_iic_read_bytes
** Description  : 
** Input        : _pReadBuf
**                _usAddress
**                _usSize
** Output       : None
** Note         : 
*********************************************************************************************************/
static Std_ReturnType _iic_read_bytes(int fd, uint16_t usRegister, uint16_t usSize, uint8_t *pReadBuf)
{
	uint16_t i;
        struct soft_iic_cli_dev *dev = (struct soft_iic_cli_dev *)&iic_cli_dev[fd];
        Std_ReturnType sta = E_OK;
        if(NULL == pReadBuf)
        {
            sta = E_POINT_NULL_ERROR;
            goto cmd_fail_0;
        }
        if(pdTRUE != I2C_MUTEX_TAKE(dev))
        {
            sta = E_OS_MUTEX_ERROR;
            goto cmd_fail_0;
        }
	iic_start(dev);

	iic_send_byte(dev, dev->iic_addr | IIC_WR);	

	if (iic_wait_ack(dev) != 0)
	{
                sta = E_IIC_NOT_ACK;
		goto cmd_fail_1;
	}

        if (dev->multiADDR == SINGLEADDR)
	{
		iic_send_byte(dev,(uint8_t)usRegister);
		if (iic_wait_ack(dev) != 0)
		{
                        sta = E_IIC_NOT_ACK;
			goto cmd_fail_1;	/* Salve device no response. */
		}
	}
	else
	{
		iic_send_byte(dev, usRegister >> 8);
		if (iic_wait_ack(dev) != 0)
		{
                        sta = E_IIC_NOT_ACK;
			goto cmd_fail_1;	/* Salve device no response. */
		}

		iic_send_byte(dev, usRegister);
		if (iic_wait_ack(dev) != 0)
		{
                        sta = E_IIC_NOT_ACK;
			goto cmd_fail_1;	/* Salve device no response. */
		}
	}

	/* Restart iic bus, start to read data.*/
	iic_start(dev);

	/* Send control byte, bit7-bit1 is address, bit0 is read/write control bit(0-write, 1-read)*/
	iic_send_byte(dev, dev->iic_addr | IIC_RD);	

	/* send ACK */
	if (iic_wait_ack(dev) != 0)
	{
                sta = E_IIC_NOT_ACK;
		goto cmd_fail_1;	
	}

	/* read datas */
	for (i = 0; i < usSize; i++)
	{
		pReadBuf[i] = iic_read_byte(dev);

		if (i != usSize - 1)
		{
			iic_ack(dev);	/* if read a byte, send ack(SDA = 0)*/
		}
		else
		{
			iic_nack(dev);	/* if read last byte, send nack(SDA = 1) */
		}
	}
	
	/* stop iic bus.*/
	
	/* success */

	/* if send cmd failed, stop iic bus. */
 cmd_fail_1:  
	iic_stop(dev);
	I2C_MUTEX_REALSE(dev);
 cmd_fail_0:       
	return sta;
}

/*********************************************************************************************************
** Function name: rtc_iic_write_bytes 
** Description  : 
** Input        : usAddress
**                usSize
**                pBuf
** Output       : None
** Note         : 
*********************************************************************************************************/
static Std_ReturnType _iic_write_bytes(int fd, uint16_t usRegister, uint16_t usSize, uint8_t *pBuf)
{
	struct soft_iic_cli_dev *dev = (struct soft_iic_cli_dev *)&iic_cli_dev[fd];
	Std_ReturnType sta = E_OK;
        if(NULL == pBuf)
        {
            sta = E_POINT_NULL_ERROR;
            goto cmd_fail_0;
        }
        if(pdTRUE != I2C_MUTEX_TAKE(dev))	
	{
          sta = E_OS_MUTEX_ERROR;
          goto cmd_fail_0;	
	}

	//iic_stop(dev);


	iic_start(dev);

	iic_send_byte(dev, dev->iic_addr | IIC_WR);
	if (iic_wait_ack(dev) != 0)
	{
                sta = E_IIC_NOT_ACK;
		goto cmd_fail_1;	
	}

	 if (dev->multiADDR == SINGLEADDR)
	{
		iic_send_byte(dev,(uint8_t)usRegister);
		if (iic_wait_ack(dev) != 0)
		{
                        sta = E_IIC_NOT_ACK;
			goto cmd_fail_1;	/* Salve device no response. */
		}
	}
	else
	{
		iic_send_byte(dev, usRegister >> 8);
		if (iic_wait_ack(dev) != 0)
		{
                        sta = E_IIC_NOT_ACK;
			goto cmd_fail_1;	/* Salve device no response. */
		}

		iic_send_byte(dev, usRegister);
		if (iic_wait_ack(dev) != 0)
		{
                        sta = E_IIC_NOT_ACK;

			goto cmd_fail_1;	/* Salve device no response. */
		}
	}
	while(usSize != 0)
	{
		iic_send_byte(dev, *pBuf);
		if (iic_wait_ack(dev) != 0)
		{
			sta = E_IIC_NOT_ACK;
			goto cmd_fail_1;	/* Salve device no response. */
//			s32k14x_gpio_write(PTD, PIN_INDEX_0, 1);//for test
		}
		pBuf++;
		usSize--;
	}
cmd_fail_1: 
	iic_stop(dev);
	I2C_MUTEX_REALSE(dev);
cmd_fail_0: 
	return sta;
}

Std_ReturnType iic_read_bytes(int fd, uint16_t usRegister, uint16_t usSize, uint8_t *pReadBuf)
{
    int retry =3;
    Std_ReturnType sta ;
    do{
       sta = _iic_read_bytes(fd, usRegister, usSize, pReadBuf);
    } while( (retry--) && (sta != E_OK));
    return sta; 
}
Std_ReturnType iic_write_bytes(int fd, uint16_t usRegister, uint16_t usSize, uint8_t *pBuf)
{
    int retry =3;
    Std_ReturnType sta ;
    do{
       sta = _iic_write_bytes(fd, usRegister, usSize, pBuf);
    } while( (retry--) && (sta != E_OK));
    return sta;      
}

/*********************************************************************************************************
  END
*********************************************************************************************************/






