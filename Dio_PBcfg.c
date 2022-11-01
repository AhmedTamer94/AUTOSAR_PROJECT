 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 ******************************************************************************/

#include "Dio.h"
/*
 * Module Version 1.0.0
 */
#define DIO_PBCFG_SW_MAJOR_VERSION              (1U)
#define DIO_PBCFG_SW_MINOR_VERSION              (0U)
#define DIO_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define DIO_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define DIO_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define DIO_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* AUTOSAR Version checking between Dio_PBcfg.c and Dio.h files */
#if ((DIO_PBCFG_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (DIO_PBCFG_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (DIO_PBCFG_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Dio_PBcfg.c and Dio.h files */
#if ((DIO_PBCFG_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION)\
 ||  (DIO_PBCFG_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION)\
 ||  (DIO_PBCFG_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with Dio_Init API */
const Dio_ConfigType Dio_Configuration = {
                                             /* Dio_ConfigChannel Channels structure members */
  
                                             Dio_PPORTA_NUM,Dio_Channel_0_NUM,/* Dio_ConfigChannel Channels structure members for PORTA*/
                                             Dio_PPORTA_NUM,Dio_Channel_1_NUM,
                                             Dio_PPORTA_NUM,Dio_Channel_2_NUM,
                                             Dio_PPORTA_NUM,Dio_Channel_3_NUM,
                                             Dio_PPORTA_NUM,Dio_Channel_4_NUM,
                                             Dio_PPORTA_NUM,Dio_Channel_5_NUM,
                                             Dio_PPORTA_NUM,Dio_Channel_6_NUM,
                                             Dio_PPORTA_NUM,Dio_Channel_7_NUM,
                                             
                                             Dio_PPORTB_NUM,Dio_Channel_0_NUM,/* Dio_ConfigChannel Channels structure members for PORTB */
                                             Dio_PPORTB_NUM,Dio_Channel_1_NUM,
                                             Dio_PPORTB_NUM,Dio_Channel_2_NUM,
                                             Dio_PPORTB_NUM,Dio_Channel_3_NUM,
                                             Dio_PPORTB_NUM,Dio_Channel_4_NUM,
                                             Dio_PPORTB_NUM,Dio_Channel_5_NUM,
                                             Dio_PPORTB_NUM,Dio_Channel_6_NUM,
                                             Dio_PPORTB_NUM,Dio_Channel_7_NUM,
                                             
                                             Dio_PPORTC_NUM,Dio_Channel_4_NUM,/* Dio_ConfigChannel Channels structure members for PORTC */
                                             Dio_PPORTC_NUM,Dio_Channel_5_NUM,
                                             Dio_PPORTC_NUM,Dio_Channel_6_NUM,
                                             Dio_PPORTC_NUM,Dio_Channel_7_NUM,
                                             
                                             Dio_PPORTD_NUM,Dio_Channel_0_NUM,/* Dio_ConfigChannel Channels structure members for PORTD */
                                             Dio_PPORTD_NUM,Dio_Channel_1_NUM,
                                             Dio_PPORTD_NUM,Dio_Channel_2_NUM,
                                             Dio_PPORTD_NUM,Dio_Channel_3_NUM,
                                             Dio_PPORTD_NUM,Dio_Channel_4_NUM,
                                             Dio_PPORTD_NUM,Dio_Channel_5_NUM,
                                             Dio_PPORTD_NUM,Dio_Channel_6_NUM,
                                             Dio_PPORTD_NUM,Dio_Channel_7_NUM,
                                             
                                             Dio_PPORTE_NUM,Dio_Channel_0_NUM,/* Dio_ConfigChannel Channels structure members for PORTE */
                                             Dio_PPORTE_NUM,Dio_Channel_1_NUM,
                                             Dio_PPORTE_NUM,Dio_Channel_2_NUM,
                                             Dio_PPORTE_NUM,Dio_Channel_3_NUM,
                                             Dio_PPORTE_NUM,Dio_Channel_4_NUM,
                                             Dio_PPORTE_NUM,Dio_Channel_5_NUM,
                                             
                                             Dio_PPORTF_NUM,Dio_Channel_0_NUM,/* Dio_ConfigChannel Channels structure members for PORTF */
                                             DioConf_LED1_PORT_NUM,DioConf_LED1_CHANNEL_NUM,
                                             Dio_PPORTF_NUM,Dio_Channel_2_NUM,
                                             Dio_PPORTF_NUM,Dio_Channel_3_NUM,                                            
				             DioConf_SW1_PORT_NUM,DioConf_SW1_CHANNEL_NUM,
                                             
                                             /* Dio_ConfigChannel Ports structure members */
                                             
                                             Dio_PPORTA_NUM,Dio_Channel_0_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTA, /*Dio_ConfigPort Ports structure members for PORTA*/
                                             Dio_PPORTA_NUM,Dio_Channel_1_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTA,
                                             Dio_PPORTA_NUM,Dio_Channel_2_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTA,
                                             Dio_PPORTA_NUM,Dio_Channel_3_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTA,
                                             Dio_PPORTA_NUM,Dio_Channel_4_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTA,
                                             Dio_PPORTA_NUM,Dio_Channel_5_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTA,
                                             Dio_PPORTA_NUM,Dio_Channel_6_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTA,
                                             Dio_PPORTA_NUM,Dio_Channel_7_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTA,
                                             
                                             Dio_PPORTB_NUM,Dio_Channel_0_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTB,/*Dio_ConfigPort Ports structure members for PORTB*/
                                             Dio_PPORTB_NUM,Dio_Channel_1_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTB,
                                             Dio_PPORTB_NUM,Dio_Channel_2_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTB,
                                             Dio_PPORTB_NUM,Dio_Channel_3_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTB,
                                             Dio_PPORTB_NUM,Dio_Channel_4_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTB,
                                             Dio_PPORTB_NUM,Dio_Channel_5_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTB,
                                             Dio_PPORTB_NUM,Dio_Channel_6_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTB,
                                             Dio_PPORTB_NUM,Dio_Channel_7_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTB,
                                             
                                             Dio_PPORTC_NUM,Dio_Channel_4_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTC,/*Dio_ConfigPort Ports structure members for PORTC*/
                                             Dio_PPORTC_NUM,Dio_Channel_5_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTC,
                                             Dio_PPORTC_NUM,Dio_Channel_6_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTC,
                                             Dio_PPORTC_NUM,Dio_Channel_7_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTC,
                                             
                                             Dio_PPORTD_NUM,Dio_Channel_0_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTD,/*Dio_ConfigPort Ports structure members for PORTD*/
                                             Dio_PPORTD_NUM,Dio_Channel_1_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTD,
                                             Dio_PPORTD_NUM,Dio_Channel_2_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTD,
                                             Dio_PPORTD_NUM,Dio_Channel_3_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTD,
                                             Dio_PPORTD_NUM,Dio_Channel_4_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTD,
                                             Dio_PPORTD_NUM,Dio_Channel_5_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTD,
                                             Dio_PPORTD_NUM,Dio_Channel_6_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTD,
                                             Dio_PPORTD_NUM,Dio_Channel_7_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTD,
                                             
                                             Dio_PPORTE_NUM,Dio_Channel_0_NUM,OUTPUT,OFF,STD_LOW,GPIO,ChannelsGroup_Num_PORTE,/*Dio_ConfigPort Ports structure members for PORTE*/
                                             Dio_PPORTE_NUM,Dio_Channel_1_NUM,OUTPUT,OFF,STD_LOW,GPIO,ChannelsGroup_Num_PORTE,
                                             Dio_PPORTE_NUM,Dio_Channel_2_NUM,OUTPUT,OFF,STD_LOW,GPIO,ChannelsGroup_Num_PORTE,
                                             Dio_PPORTE_NUM,Dio_Channel_3_NUM,OUTPUT,OFF,STD_LOW,GPIO,ChannelsGroup_Num_PORTE,
                                             Dio_PPORTE_NUM,Dio_Channel_4_NUM,OUTPUT,OFF,STD_LOW,GPIO,ChannelsGroup_Num_PORTE,
                                             Dio_PPORTE_NUM,Dio_Channel_5_NUM,OUTPUT,OFF,STD_LOW,GPIO,ChannelsGroup_Num_PORTE,
                                             
                                             Dio_PPORTF_NUM,Dio_Channel_0_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTF,/*Dio_ConfigPort Ports structure members for PORTF*/
                                             Dio_PPORTF_NUM,Dio_Channel_1_NUM,OUTPUT,OFF,STD_LOW,GPIO,ChannelsGroup_Num_PORTF,   /*Config Onput Pin for LED initial value off*/
                                             Dio_PPORTF_NUM,Dio_Channel_2_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTF,
                                             Dio_PPORTF_NUM,Dio_Channel_3_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTF,
                                             Dio_PPORTF_NUM,Dio_Channel_4_NUM,INPUT,PULL_UP,STD_LOW,GPIO,ChannelsGroup_Num_PORTF, /*Config Input Pin for Button*/
                                               
                                            /* Dio_ConfigChannelGroupType structure members */

                                             ChannelsGroup_PORTA_Mask,ChannelsGroup_PORTA_OFFSET,Dio_PPORTA_NUM,
                                             ChannelsGroup_PORTB_Mask,ChannelsGroup_PORTB_OFFSET,Dio_PPORTB_NUM,
                                             ChannelsGroup_PORTC_Mask,ChannelsGroup_PORTC_OFFSET,Dio_PPORTC_NUM,
                                             ChannelsGroup_PORTD_Mask,ChannelsGroup_PORTD_OFFSET,Dio_PPORTD_NUM,
                                             ChannelsGroup_PORTE_Mask,ChannelsGroup_PORTE_OFFSET,Dio_PPORTE_NUM,
                                             ChannelsGroup_PORTF_Mask,ChannelsGroup_PORTF_OFFSET,Dio_PPORTF_NUM

				         };