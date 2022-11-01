 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

#include "Common_Macros.h"
#include "Std_Types.h"

/*******************************************************************************
 *                              Module Definitions                             *
 *******************************************************************************/

/* GPIO Registers base addresses */
#define GPIO_PORTA_BASE_ADDRESS           0x40004000
#define GPIO_PORTB_BASE_ADDRESS           0x40005000
#define GPIO_PORTC_BASE_ADDRESS           0x40006000
#define GPIO_PORTD_BASE_ADDRESS           0x40007000
#define GPIO_PORTE_BASE_ADDRESS           0x40024000
#define GPIO_PORTF_BASE_ADDRESS           0x40025000

/* GPIO Registers offset addresses */
#define PORT_DATA_REG_OFFSET              0x3FC
#define PORT_DIR_REG_OFFSET               0x400
#define PORT_ALT_FUNC_REG_OFFSET          0x420
#define PORT_PULL_UP_REG_OFFSET           0x510
#define PORT_PULL_DOWN_REG_OFFSET         0x514
#define PORT_DIGITAL_ENABLE_REG_OFFSET    0x51C
#define PORT_LOCK_REG_OFFSET              0x520
#define PORT_COMMIT_REG_OFFSET            0x524
#define PORT_ANALOG_MODE_SEL_REG_OFFSET   0x528
#define PORT_CTL_REG_OFFSET               0x52C

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Description: Enum to hold PIN direction */
typedef enum
{
    INPUT,OUTPUT
}Port_PinDirection;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;

typedef enum{
  GPIO,UART,UARTPC,URTS_PORTC_ONLY,CAN,SPI,SPI3,ISqrC,MPWM0,MPWM1,TCCP,WTCCP,IDX,PHA_OR_B,USB,NMI,TRD,CO,CI,USBD,Ain
}PortMode;
/* Description: Structure to configure each individual PIN:
 *	1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *	2. the number of the pin in the PORT.
 *      3. the direction of pin --> INPUT or OUTPUT
 *      4. the internal resistor --> Disable, Pull up or Pull down
 */
typedef struct 
{
    uint8 port_num; 
    uint8 pin_num; 
    Port_PinDirection direction;
    Port_InternalResistor resistor;
    uint8 initial_value;
    PortMode mode;
    uint8 ChannelsGroup_Num;
}Port_ConfigType; /*39 fy el array*/

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: Port_SetupGpioPin
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the pin configuration:
*              - Setup the pin as Digital GPIO pin
*              - Setup the direction of the GPIO pin
*              - Setup the internal resistor for i/p pin
************************************************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr );
void Port_GPIO_Init(const Port_ConfigType *ConfigPtr, volatile uint32 * PortGpio_Ptr);
void Port_UART_Init(const Port_ConfigType *ConfigPtr, volatile uint32 * PortGpio_Ptr);
void Port_CAN_Init(const Port_ConfigType *ConfigPtr, volatile uint32 * PortGpio_Ptr);
void Port_SPI_Init(const Port_ConfigType *ConfigPtr, volatile uint32 * PortGpio_Ptr);
void Port_I2C_Init(const Port_ConfigType *ConfigPtr, volatile uint32 * PortGpio_Ptr);
void Port_MPWM_Init(const Port_ConfigType *ConfigPtr, volatile uint32 * PortGpio_Ptr);
void Port_TCCP_Init(const Port_ConfigType *ConfigPtr, volatile uint32 * PortGpio_Ptr);
void Port_IDX_Init(const Port_ConfigType *ConfigPtr, volatile uint32 * PortGpio_Ptr);
void Port_USB_Init(const Port_ConfigType *ConfigPtr, volatile uint32 * PortGpio_Ptr);
void Port_NMI_Init(const Port_ConfigType *ConfigPtr, volatile uint32 * PortGpio_Ptr);
void Port_TRD_Init(const Port_ConfigType *ConfigPtr, volatile uint32 * PortGpio_Ptr);
void Port_CO_Init(const Port_ConfigType *ConfigPtr, volatile uint32 * PortGpio_Ptr);
void Port_AnalogMods_Init(const Port_ConfigType *ConfigPtr, volatile uint32 * PortGpio_Ptr);
#endif /* PORT_H */
