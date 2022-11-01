 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 ******************************************************************************/

#include "Dio.h"
#include "Dio_Regs.h"
#include "tm4c123gh6pm_registers.h"

#if (DIO_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC const Dio_ConfigChannel * Dio_Channels = NULL_PTR;
STATIC const Port_ConfigType * Dio_Ports = NULL_PTR;
STATIC const Dio_ChannelGroupType * Dio_ChannelGroupId= NULL_PTR;
STATIC uint8 Dio_Status = DIO_NOT_INITIALIZED;

/************************************************************************************
* Service Name: Dio_Init
* Service ID[hex]: 0x10
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Dio module.
************************************************************************************/
void Dio_Init(const Dio_ConfigType * ConfigPtr)
{
#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_INIT_SID,
		     DIO_E_PARAM_CONFIG);
	}
	else
#endif
	{
                uint8 counter=0;
                const Port_ConfigType * Port_Ptr = ConfigPtr->Ports;           
		Dio_Status       = DIO_INITIALIZED;
		Dio_Channels = ConfigPtr->Channels;                              /* address of the first Channels structure --> Channels[0] */
                Dio_Ports = ConfigPtr->Ports;                                   /* address of the first Ports structure --> Ports[0] */
                //Dio_ChannelGroupId = &ConfigPtr->Groups[Dio_PPORTE_NUM];       /* address of the fifth Groups structure Group PortE--> Groups[4] */
                
                /*Init all Pins in TivaC*/
                    while(counter<DIO_CONFIGURED_CHANNLES){
                      
                      Port_Init(Port_Ptr);
                      Port_Ptr++;
                      counter++;
  
                      }
                    
           //testing the functions by simulating
         //Dio_WritePort(Dio_PPORTE_ID,0x15); /* write 0001 0101 to portE*/
        // Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,STD_HIGH);
        // volatile uint8 z= Dio_ReadPort(Dio_PPORTE_ID);
         //z=Dio_ReadChannelGroup(Dio_ChannelGroupId); /*should read portE group from pin1 to pin4 level will be 0x0A */
         //Dio_WriteChannelGroup(Dio_ChannelGroupId,0x03); /*write 0000 0011 starting from the portE group pin1 to pin4 and the port level will be 0000 0111 (0x07)*/
         //volatile uint8 x=10;     
        }
}

/************************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to return the value of the specified DIO channel.
************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	volatile uint32 * Port_Ptr = NULL_PTR;
	Dio_LevelType output = STD_LOW;
	boolean error = FALSE;

#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (DIO_NOT_INITIALIZED == Dio_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_READ_CHANNEL_SID, DIO_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if the used channel is within the valid range */
	if (DIO_CONFIGURED_CHANNLES <= ChannelId)
	{

		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_READ_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif

	/* In-case there are no errors */
	if(FALSE == error)
	{
		/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
		switch(Dio_Channels[ChannelId].Port_Num)
		{
                    case 0:    Port_Ptr = &GPIO_PORTA_DATA_REG;
		               break;
		    case 1:    Port_Ptr = &GPIO_PORTB_DATA_REG;
		               break;
		    case 2:    Port_Ptr = &GPIO_PORTC_DATA_REG;
		               break;
		    case 3:    Port_Ptr = &GPIO_PORTD_DATA_REG;
		               break;
                    case 4:    Port_Ptr = &GPIO_PORTE_DATA_REG;
		               break;
                    case 5:    Port_Ptr = &GPIO_PORTF_DATA_REG;
		               break;
		}
		/* Read the required channel */
		if(BIT_IS_SET(*Port_Ptr,Dio_Channels[ChannelId].Ch_Num))
		{
			output = STD_HIGH;
		}
		else
		{
			output = STD_LOW;
		}
	}
	else
	{
		/* No Action Required */
	}
        return output;
}

/************************************************************************************
* Service Name: Dio_WriteChannel
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel.
************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	volatile uint32 * Port_Ptr = NULL_PTR;
	boolean error = FALSE;

#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (DIO_NOT_INITIALIZED == Dio_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_WRITE_CHANNEL_SID, DIO_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if the used channel is within the valid range */
	if (DIO_CONFIGURED_CHANNLES <= ChannelId)
	{

		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif

	/* In-case there are no errors */
	if(FALSE == error)
	{
		/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
		switch(Dio_Channels[ChannelId].Port_Num)
		{
                    case 0:    Port_Ptr = &GPIO_PORTA_DATA_REG;
		               break;
		    case 1:    Port_Ptr = &GPIO_PORTB_DATA_REG;
		               break;
		    case 2:    Port_Ptr = &GPIO_PORTC_DATA_REG;
		               break;
		    case 3:    Port_Ptr = &GPIO_PORTD_DATA_REG;
		               break;
                    case 4:    Port_Ptr = &GPIO_PORTE_DATA_REG;
		               break;
                    case 5:    Port_Ptr = &GPIO_PORTF_DATA_REG;
		               break;
		}
		if(Level == STD_HIGH)
		{
			/* Write Logic High */
			SET_BIT(*Port_Ptr,Dio_Channels[ChannelId].Ch_Num);
		}
		else 
		{
			/* Write Logic Low */
			CLEAR_BIT(*Port_Ptr,Dio_Channels[ChannelId].Ch_Num);
		}
	}
	else
	{
		/* No Action Required */
	}

}


/************************************************************************************
* Service Name: Dio_ReadPort
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - ID of DIO Port.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType of Level of all channels of that port
* Description: Function to return the value of all channels of that Port.
************************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	volatile uint32 * Port_Ptr = NULL_PTR;
	Dio_PortLevelType level = STD_LOW;
	boolean error = FALSE;

#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (DIO_NOT_INITIALIZED == Dio_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_READ_PORT_SID, DIO_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if the used PORT is within the valid range */
	if (DIO_CONFIGURED_PORTS <= Dio_Ports[PortId].port_num)
	{

		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_READ_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif

	/* In-case there are no errors */
	if(FALSE == error)
	{
		/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
		switch(Dio_Ports[PortId].port_num)
		{
                    case 0:    Port_Ptr = &GPIO_PORTA_DATA_REG;
		               break;
		    case 1:    Port_Ptr = &GPIO_PORTB_DATA_REG;
		               break;
		    case 2:    Port_Ptr = &GPIO_PORTC_DATA_REG;
		               break;
		    case 3:    Port_Ptr = &GPIO_PORTD_DATA_REG;
		               break;
                    case 4:    Port_Ptr = &GPIO_PORTE_DATA_REG;
		               break;
                    case 5:    Port_Ptr = &GPIO_PORTF_DATA_REG;
		               break;
		}
		/* Read the required Port */
		level =*Port_Ptr;
        
	}
	else
	{
		/* No Action Required */
	}
        return level;
}

/************************************************************************************
* Service Name: Dio_WritePort
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - ID of DIO Port.
                   Level of Dio_PortLevelType
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType of Level of all channels of that port
* Description: Function to return the value of all channels of that Port.
************************************************************************************/
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType level)
{
	volatile uint32 * Port_Ptr = NULL_PTR;
        volatile uint8 PortId_next=0;
	boolean error = FALSE;

#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (DIO_NOT_INITIALIZED == Dio_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_WRITE_PORT_SID, DIO_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if the used PORT is within the valid range */
	if (DIO_CONFIGURED_PORTS <= Dio_Ports[PortId].port_num)
	{

		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_WRITE_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif

	/* In-case there are no errors */
	if(FALSE == error)
	{
          /* Set the variable PortId_next to the next PortId*/
          switch(PortId)
		{
                    case Dio_PPORTA_ID:    PortId_next = Dio_PPORTB_ID;
		               break;
		    case Dio_PPORTB_ID:    PortId_next = Dio_PPORTC_ID;
		               break;
		    case Dio_PPORTC_ID:    PortId_next = Dio_PPORTD_ID;
		               break;
		    case Dio_PPORTD_ID:    PortId_next = Dio_PPORTE_ID;
		               break;
                    case Dio_PPORTE_ID:    PortId_next = Dio_PPORTF_ID;
		               break;
                    case Dio_PPORTF_ID:    PortId_next = Dio_Invalid_Port_Id;
		               break;
		}
          
		/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
		switch(Dio_Ports[PortId].port_num)
		{
                    case 0:    Port_Ptr = &GPIO_PORTA_DATA_REG;
		               break;
		    case 1:    Port_Ptr = &GPIO_PORTB_DATA_REG;
		               break;
		    case 2:    Port_Ptr = &GPIO_PORTC_DATA_REG;
		               break;
		    case 3:    Port_Ptr = &GPIO_PORTD_DATA_REG;
		               break;
                    case 4:    Port_Ptr = &GPIO_PORTE_DATA_REG;
		               break;
                    case 5:    Port_Ptr = &GPIO_PORTF_DATA_REG;
		               break;
		}
		/* Write the level value to Port */
		do{
                     if(Dio_Ports[PortId].direction == OUTPUT) /* if the corresponding pin is output pin*/
                     {
        /* find the corresponding pin then mask the corresponding bit at level variable then check on its value if high set pin high else clear pin*/
                        switch(Dio_Ports[PortId].pin_num)
		              {
                                 case 0:    if(((level&0x01)>>0)==STD_HIGH)
                                              {
                                               SET_BIT(*Port_Ptr,Dio_Ports[PortId].pin_num);
                                              }
                                            else
                                               {
                                                CLEAR_BIT(*Port_Ptr,Dio_Ports[PortId].pin_num);
                                               }
                                           break;
                                 case 1:    if(((level&0x02)>>1)==STD_HIGH)
                                              {
                                               SET_BIT(*Port_Ptr,Dio_Ports[PortId].pin_num);
                                              }
                                            else
                                               {
                                                CLEAR_BIT(*Port_Ptr,Dio_Ports[PortId].pin_num);
                                               }
                                           break;
                                 case 2:    if(((level&0x04)>>2)==STD_HIGH)
                                              {
                                               SET_BIT(*Port_Ptr,Dio_Ports[PortId].pin_num);
                                              }
                                            else
                                               {
                                                CLEAR_BIT(*Port_Ptr,Dio_Ports[PortId].pin_num);
                                               }
                                           break;
                                 case 3:    if(((level&0x08)>>3)==STD_HIGH)
                                              {
                                               SET_BIT(*Port_Ptr,Dio_Ports[PortId].pin_num);
                                              }
                                            else
                                               {
                                                CLEAR_BIT(*Port_Ptr,Dio_Ports[PortId].pin_num);
                                               }
                                           break; 
                                 case 4:    if(((level&0x10)>>4)==STD_HIGH)
                                              {
                                               SET_BIT(*Port_Ptr,Dio_Ports[PortId].pin_num);
                                              }
                                            else
                                               {
                                                CLEAR_BIT(*Port_Ptr,Dio_Ports[PortId].pin_num);
                                               }
                                           break;
                                 case 5:    if(((level&0x20)>>5)==STD_HIGH)
                                              {
                                               SET_BIT(*Port_Ptr,Dio_Ports[PortId].pin_num);
                                              }
                                            else
                                               {
                                                CLEAR_BIT(*Port_Ptr,Dio_Ports[PortId].pin_num);
                                               }
                                           break;
                                 case 6:    if(((level&0x40)>>6)==STD_HIGH)
                                              {
                                               SET_BIT(*Port_Ptr,Dio_Ports[PortId].pin_num);
                                              }
                                            else
                                               {
                                                CLEAR_BIT(*Port_Ptr,Dio_Ports[PortId].pin_num);
                                               }
                                           break;
                                 case 7:    if(((level&0x80)>>7)==STD_HIGH)
                                              {
                                               SET_BIT(*Port_Ptr,Dio_Ports[PortId].pin_num);
                                              }
                                            else
                                               {
                                                CLEAR_BIT(*Port_Ptr,Dio_Ports[PortId].pin_num);
                                               }
                                           break;                                           
		                 }
                 }
               else /*the pin is input and do nothing*/
                   {
                     
                    }
               PortId++; /* increment the PortId till we get to the next PortId configured */      
                }while(PortId<PortId_next);
                
        }
        
	else
	{
		/* No Action Required */
	}
        
}

/************************************************************************************
* Service Name: Dio_ReadChannelGroup
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelGroupIdPtr - Pointer to ChannelGroup.

* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType of Level of a subset of the adjoining bits of a port.
* Description: This Function reads a subset of the adjoining bits of a port.
************************************************************************************/
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr)
{
  
  volatile uint32 * Port_Ptr = NULL_PTR;
  volatile Dio_PortLevelType level= STD_LOW;
	boolean error = FALSE;

#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (DIO_NOT_INITIALIZED == Dio_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_READ_CHANNEL_GROUP_SID, DIO_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if the used Group is within the valid range */
	if (DIO_CONFIGURED_GROUPS <= ChannelGroupIdPtr->PortIndex)
	{

		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_READ_CHANNEL_GROUP_SID, DIO_E_PARAM_INVALID_GROUP);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif

	/* In-case there are no errors */
	if(FALSE == error)
	{
          if(Dio_ChannelGroupId==NULL_PTR){
            return level;
          }
          else{
          
		/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
		switch(ChannelGroupIdPtr->PortIndex)
		{
                    case 0:    Port_Ptr = &GPIO_PORTA_DATA_REG;
		               break;
		    case 1:    Port_Ptr = &GPIO_PORTB_DATA_REG;
		               break;
		    case 2:    Port_Ptr = &GPIO_PORTC_DATA_REG;
		               break;
		    case 3:    Port_Ptr = &GPIO_PORTD_DATA_REG;
		               break;
                    case 4:    Port_Ptr = &GPIO_PORTE_DATA_REG;
		               break;
                    case 5:    Port_Ptr = &GPIO_PORTF_DATA_REG;
		               break;
		}
		/* Read the whole port then & operands with the mask then shift right with the offset value and set the value in variable level*/
		level= ((*Port_Ptr&(ChannelGroupIdPtr->mask))>>ChannelGroupIdPtr->offset);
                 
        
	}
        }
	else
	{
		/* No Action Required */
	}
        return level;
  
}

/************************************************************************************
* Service Name: Dio_WriteChannelGroup
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelGroupIdPtr - Pointer to ChannelGroup.
                   Level of Dio_PortLevelType
* Parameters (inout): None
* Parameters (out): None
* Return value: None.
* Description: This Function reads a subset of the adjoining bits of a port.
************************************************************************************/

void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level)
{
  
  volatile uint32 * Port_Ptr = NULL_PTR;
  volatile uint8 PortId=0;
	boolean error = FALSE;

#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (DIO_NOT_INITIALIZED == Dio_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_WRITE_CHANNEL_GROUP_SID, DIO_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if the used Group is within the valid range */
	if (DIO_CONFIGURED_GROUPS <= ChannelGroupIdPtr->PortIndex)
	{

		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_WRITE_CHANNEL_GROUP_SID, DIO_E_PARAM_INVALID_GROUP);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif

	/* In-case there are no errors */
	if(FALSE == error)
	{
          if(Dio_ChannelGroupId== NULL_PTR){
            return; 
          }
          
          else{
          
		/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
		switch(ChannelGroupIdPtr->PortIndex)
		{
                    case 0:    Port_Ptr = &GPIO_PORTA_DATA_REG;
                               PortId=Dio_PPORTA_ID;
		               break;
		    case 1:    Port_Ptr = &GPIO_PORTB_DATA_REG;
                               PortId=Dio_PPORTB_ID;                    
		               break;
		    case 2:    Port_Ptr = &GPIO_PORTC_DATA_REG;
                               PortId=Dio_PPORTC_ID;                    
		               break;
		    case 3:    Port_Ptr = &GPIO_PORTD_DATA_REG;
                               PortId=Dio_PPORTD_ID;                    
		               break;
                    case 4:    Port_Ptr = &GPIO_PORTE_DATA_REG;
                               PortId=Dio_PPORTE_ID;                    
		               break;
                    case 5:    Port_Ptr = &GPIO_PORTF_DATA_REG;
                               PortId=Dio_PPORTF_ID;                    
		               break;
		}
                
		/* Write the required value to Group */
                if(Dio_Ports[PortId].ChannelsGroup_Num!=0)
                { 
		*Port_Ptr= (Level<<(ChannelGroupIdPtr->offset))|(*Port_Ptr&~(ChannelGroupIdPtr->mask));
                }
                else{
                      /* No Action Required */
                    }
        
         }
        }
	else
	{
		/* No Action Required */
	}
}
            
/************************************************************************************
* Service Name: Dio_GetVersionInfo
* Service ID[hex]: 0x12
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): VersionInfo - Pointer to where to store the version information of this module.
* Return value: None
* Description: Function to get the version information of this module.
************************************************************************************/
#if (DIO_VERSION_INFO_API == STD_ON)
void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_GET_VERSION_INFO_SID, DIO_E_PARAM_POINTER);
	}
	else
#endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)DIO_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)DIO_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)DIO_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)DIO_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)DIO_SW_PATCH_VERSION;
	}
}
#endif

/************************************************************************************
* Service Name: Dio_FlipChannel
* Service ID[hex]: 0x11
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to flip the level of a channel and return the level of the channel after flip.
************************************************************************************/
#if (DIO_FLIP_CHANNEL_API == STD_ON)
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	volatile uint32 * Port_Ptr = NULL_PTR;
	Dio_LevelType output = STD_LOW;
	boolean error = FALSE;

#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (DIO_NOT_INITIALIZED == Dio_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_FLIP_CHANNEL_SID, DIO_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if the used channel is within the valid range */
	if (DIO_CONFIGURED_CHANNLES <= ChannelId)
	{

		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_FLIP_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif

	/* In-case there are no errors */
	if(FALSE == error)
	{
		/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
		switch(Dio_Channels[ChannelId].Port_Num)
		{
                    case 0:    Port_Ptr = &GPIO_PORTA_DATA_REG;
		               break;
		    case 1:    Port_Ptr = &GPIO_PORTB_DATA_REG;
		               break;
		    case 2:    Port_Ptr = &GPIO_PORTC_DATA_REG;
		               break;
		    case 3:    Port_Ptr = &GPIO_PORTD_DATA_REG;
		               break;
                    case 4:    Port_Ptr = &GPIO_PORTE_DATA_REG;
		               break;
                    case 5:    Port_Ptr = &GPIO_PORTF_DATA_REG;
		               break;
		}
		/* Read the required channel and write the required level */
		if(BIT_IS_SET(*Port_Ptr,Dio_Channels[ChannelId].Ch_Num))
		{
			CLEAR_BIT(*Port_Ptr,Dio_Channels[ChannelId].Ch_Num);
			output = STD_LOW;
		}
		else
		{
			SET_BIT(*Port_Ptr,Dio_Channels[ChannelId].Ch_Num);
			output = STD_HIGH;
		}
	}
	else
	{
		/* No Action Required */
	}
        return output;
}
#endif
