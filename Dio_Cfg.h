 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 ******************************************************************************/

#ifndef DIO_CFG_H
#define DIO_CFG_H

/*
 * Module Version 1.0.0
 */
#define DIO_CFG_SW_MAJOR_VERSION              (1U)
#define DIO_CFG_SW_MINOR_VERSION              (0U)
#define DIO_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define DIO_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define DIO_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define DIO_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define DIO_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define DIO_VERSION_INFO_API                (STD_OFF)

/* Pre-compile option for presence of Dio_FlipChannel API */
#define DIO_FLIP_CHANNEL_API                (STD_ON)

/* Number of the configured Dio Channels, PORTS and Groups */
#define DIO_CONFIGURED_CHANNLES              (39U)
#define DIO_CONFIGURED_PORTS                 (6U)  
#define DIO_CONFIGURED_GROUPS              (6U)

   
/*
 * DIO Ports NUMs
 */
#define Dio_PPORTA_NUM                      (Dio_PortType)0 /* PORTA */ 
#define Dio_PPORTB_NUM                      (Dio_PortType)1 /* PORTB */  
#define Dio_PPORTC_NUM                      (Dio_PortType)2 /* PORTC */  
#define Dio_PPORTD_NUM                      (Dio_PortType)3 /* PORTD */  
#define Dio_PPORTE_NUM                      (Dio_PortType)4 /* PORTE */  
#define Dio_PPORTF_NUM                      (Dio_PortType)5 /* PORTF */ 
 /*
 * DIO Ports IDs
 */  
#define Dio_PPORTA_ID                      (Dio_PortType)0 /* PORTA */ 
#define Dio_PPORTB_ID                      (Dio_PortType)8 /* PORTB */  
#define Dio_PPORTC_ID                      (Dio_PortType)16 /* PORTC */  
#define Dio_PPORTD_ID                      (Dio_PortType)20 /* PORTD */  
#define Dio_PPORTE_ID                      (Dio_PortType)28 /* PORTE */  
#define Dio_PPORTF_ID                      (Dio_PortType)34 /* PORTF */    
#define Dio_Invalid_Port_Id                (Dio_PortType)39 /* PORTF */
/*
 * DIO Channels NUMs
 */
#define Dio_Channel_0_NUM                     (Dio_ChannelType)0 /*Pin 0 in */
#define Dio_Channel_1_NUM                     (Dio_ChannelType)1 /*Pin 1 in */
#define Dio_Channel_2_NUM                     (Dio_ChannelType)2 /*Pin 2 in */
#define Dio_Channel_3_NUM                     (Dio_ChannelType)3 /*Pin 3 in */
#define Dio_Channel_4_NUM                     (Dio_ChannelType)4 /*Pin 4 in */
#define Dio_Channel_5_NUM                     (Dio_ChannelType)5 /*Pin 5 in */
#define Dio_Channel_6_NUM                     (Dio_ChannelType)6 /*Pin 6 in */
#define Dio_Channel_7_NUM                     (Dio_ChannelType)7 /*Pin 7 in */
   
/*
 * DIO Channels IDs
 */
   
//PORTA
#define Dio_Channel_0_PORTA                     (Dio_ChannelType)0 /*Pin 0 in PORTA*/
#define Dio_Channel_1_PORTA                     (Dio_ChannelType)1 /*Pin 1 in PORTA*/
#define Dio_Channel_2_PORTA                     (Dio_ChannelType)2 /*Pin 2 in PORTA*/
#define Dio_Channel_3_PORTA                     (Dio_ChannelType)3 /*Pin 3 in PORTA*/
#define Dio_Channel_4_PORTA                     (Dio_ChannelType)4 /*Pin 4 in PORTA*/
#define Dio_Channel_5_PORTA                     (Dio_ChannelType)5 /*Pin 5 in PORTA*/
#define Dio_Channel_6_PORTA                     (Dio_ChannelType)6 /*Pin 6 in PORTA*/
#define Dio_Channel_7_PORTA                     (Dio_ChannelType)7 /*Pin 7 in PORTA*/
    
//PORTB
#define Dio_Channel_0_PORTB                     (Dio_ChannelType)8 /*Pin 0 in PORTB*/
#define Dio_Channel_1_PORTB                     (Dio_ChannelType)9 /*Pin 1 in PORTB*/
#define Dio_Channel_2_PORTB                     (Dio_ChannelType)10 /*Pin 2 in PORTB*/
#define Dio_Channel_3_PORTB                     (Dio_ChannelType)11 /*Pin 3 in PORTB*/
#define Dio_Channel_4_PORTB                     (Dio_ChannelType)12 /*Pin 4 in PORTB*/
#define Dio_Channel_5_PORTB                     (Dio_ChannelType)13 /*Pin 5 in PORTB*/
#define Dio_Channel_6_PORTB                     (Dio_ChannelType)14 /*Pin 6 in PORTB*/
#define Dio_Channel_7_PORTB                     (Dio_ChannelType)15 /*Pin 7 in PORTB*/
   
//PORTC  
#define Dio_Channel_4_PORTC                     (Dio_ChannelType)16 /*Pin 4 in PORTC*/
#define Dio_Channel_5_PORTC                     (Dio_ChannelType)17 /*Pin 5 in PORTC*/
#define Dio_Channel_6_PORTC                     (Dio_ChannelType)18 /*Pin 6 in PORTC*/
#define Dio_Channel_7_PORTC                     (Dio_ChannelType)19 /*Pin 7 in PORTC*/
#define Dio_Channel_0_PORTD                     (Dio_ChannelType)20 /*Pin 0 in PORTD*/
   
//PORTD
#define Dio_Channel_1_PORTD                     (Dio_ChannelType)21 /*Pin 1 in PORTD*/
#define Dio_Channel_2_PORTD                     (Dio_ChannelType)22 /*Pin 2 in PORTD*/
#define Dio_Channel_3_PORTD                     (Dio_ChannelType)23 /*Pin 3 in PORTD*/
#define Dio_Channel_4_PORTD                     (Dio_ChannelType)24 /*Pin 4 in PORTD*/
#define Dio_Channel_5_PORTD                     (Dio_ChannelType)25 /*Pin 5 in PORTD*/
#define Dio_Channel_6_PORTD                     (Dio_ChannelType)26 /*Pin 6 in PORTD*/
#define Dio_Channel_7_PORTD                     (Dio_ChannelType)27 /*Pin 7 in PORTD*/
   
//PORTE
#define Dio_Channel_0_PORTE                     (Dio_ChannelType)28 /*Pin 0 in PORTE*/
#define Dio_Channel_1_PORTE                     (Dio_ChannelType)29 /*Pin 1 in PORTE*/
#define Dio_Channel_2_PORTE                     (Dio_ChannelType)30 /*Pin 2 in PORTE*/
#define Dio_Channel_3_PORTE                     (Dio_ChannelType)31 /*Pin 3 in PORTE*/
#define Dio_Channel_4_PORTE                     (Dio_ChannelType)32 /*Pin 4 in PORTE*/
#define Dio_Channel_5_PORTE                     (Dio_ChannelType)33 /*Pin 5 in PORTE*/
   
//PORTF
#define Dio_Channel_0_PORTF                     (Dio_ChannelType)34 /*Pin 0 in PORTF*/
#define Dio_Channel_1_PORTF                     (Dio_ChannelType)35 /*Pin 1 in PORTF*/
#define Dio_Channel_2_PORTF                     (Dio_ChannelType)36 /*Pin 2 in PORTF*/
#define Dio_Channel_3_PORTF                     (Dio_ChannelType)37 /*Pin 3 in PORTF*/
#define Dio_Channel_4_PORTF                     (Dio_ChannelType)38 /*Pin 4 in PORTF*/

/*
 * DIO ChannelGroups NUMs 
 */

#define ChannelsGroup_Num_PORTA                     (uint8)0 /*Group 0 pin in PORTA*/
#define ChannelsGroup_Num_PORTB                     (uint8)0 /*Group 0 pin in PORTB*/
#define ChannelsGroup_Num_PORTC                     (uint8)0 /*Group 0 pin in PORTC*/
#define ChannelsGroup_Num_PORTD                     (uint8)0 /*Group 0 pin in PORTD*/
#define ChannelsGroup_Num_PORTE                     (uint8)4 /*Group 4 pin in PORTE*/ 
#define ChannelsGroup_Num_PORTF                     (uint8)0 /*Group 0 pin in PORTF*/

/*
 * DIO ChannelGroups Desired Mask 
 */

#define ChannelsGroup_PORTA_Mask                     (Dio_PortLevelType)0x01 /*Make pin 1 Mask in PORTA as a Group*/
#define ChannelsGroup_PORTB_Mask                     (Dio_PortLevelType)0x01 /*Make pin 1 Mask in PORTB as a Group*/
#define ChannelsGroup_PORTC_Mask                     (Dio_PortLevelType)0x01 /*Make pin 1 Mask in PORTC as a Group*/
#define ChannelsGroup_PORTD_Mask                     (Dio_PortLevelType)0x01 /*Make pin 1 Mask in PORTD as a Group*/
#define ChannelsGroup_PORTE_Mask                     (Dio_PortLevelType)0x1E /*Make pins 1,2,3,4 Mask in PORTE as a Group*/ 
#define ChannelsGroup_PORTF_Mask                     (Dio_PortLevelType)0x01 /*Make pin 1 Mask in PORTF as a Group*/

/*
 * DIO ChannelGroups Desired OFFSET 
 */

#define ChannelsGroup_PORTA_OFFSET                     (uint8)0 /*will write in pin 1 in PORTA according to the mask*/
#define ChannelsGroup_PORTB_OFFSET                     (uint8)0 /*will write in pin 1 in PORTB according to the mask*/
#define ChannelsGroup_PORTC_OFFSET                     (uint8)0 /*will write in pin 1 in PORTC according to the mask*/
#define ChannelsGroup_PORTD_OFFSET                     (uint8)0 /*will write in pin 1 in PORTD according to the mask*/
#define ChannelsGroup_PORTE_OFFSET                     (uint8)1 /*will write in pin 1 in PORTE according to the mask*/ 
#define ChannelsGroup_PORTF_OFFSET                     (uint8)1 /*will write in pin 2 in PORTF according to the mask*/    
  
/* DIO Configured Port NUM's  */

#define DioConf_LED1_PORT_NUM                Dio_PPORTF_NUM /* PORTF */
#define DioConf_SW1_PORT_NUM                 Dio_PPORTF_NUM /* PORTF */

/* DIO Configured Channel NUM's */
   
#define DioConf_LED1_CHANNEL_NUM             Dio_Channel_1_NUM /* Pin 1 in PORTF */
#define DioConf_SW1_CHANNEL_NUM              Dio_Channel_4_NUM /* Pin 4 in PORTF */   
 

/* DIO Configured Port ID's  */

#define DioConf_LED1_PORT_ID_INDEX                Dio_PPORTF_ID /* index 34 in the array config structure */
#define DioConf_SW1_PORT_ID_INDEX                 Dio_PPORTF_ID /* index 34 in the array config structure */

/* Channel Index in the array of structures in Dio_PBcfg.c */
#define DioConf_LED1_CHANNEL_ID_INDEX         Dio_Channel_1_PORTF /* index 35 in the array config structure*/
#define DioConf_SW1_CHANNEL_ID_INDEX          Dio_Channel_4_PORTF/* index 38 in the array config structure*/

#endif /* DIO_CFG_H */
