 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#include "Port.h"
#include "Port_Regs.h"
#include "tm4c123gh6pm_registers.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC const Port_ConfigPin * Port_PortPins = NULL_PTR;
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;

/************************************************************************************
* Service Name: Port_Init 
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the pin configuration:
*              - Setup the pin as Digital GPIO pin
*              - Setup the direction of the GPIO pin
*              - Setup the internal resistor for i/p pin
*              - Setup Pin Mode Changeability 
*              - Setup Pin Direction Changeability
************************************************************************************/
void Port_Init(const Port_ConfigType * ConfigPtr )
{
    volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    volatile uint32 delay = 0;
  
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_Init_SID,
		     PORT_E_PARAM_CONFIG);
	}
	else
#endif  
        {
            /* Enable clock for PORT and allow time for clock to start*/
            SYSCTL_REGCGC2_REG |= 0x3F; // Enable clock for all pins
            delay = SYSCTL_REGCGC2_REG;
          
            /* updating Port status */
            Port_Status       = PORT_INITIALIZED;
            Port_PortPins     = ConfigPtr->Pins; /* address of the first Channels structure --> Channels[0] */
          
            
            uint8 PinID =  0 ; 
            for(PinID = 0; PinID < PORT_CONFIGURED_PINS; PinID++)  /* Requirment PORT041 */
            {
              uint8 pin_num =  Port_PortPins[PinID].Pin & 0x0F; /* Pin number */
              /* calculating PORT BASE ADDRESS  */
              switch((Port_PortPins[PinID].Pin) >> 4)  //Ex:0xA5  ->  0x0A
              {
                  case  0x0A: 
                           PortGpio_Ptr = &GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                           break;
                  case  0x0B: 
                           PortGpio_Ptr = &GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                           break;
                  case  0x0C:
                           PortGpio_Ptr = &GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                           break;
                  case  0x0D:
                           PortGpio_Ptr = &GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                           break;
                  case  0x0E:
                           PortGpio_Ptr = &GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                           break;
                  case  0x0F:
                            PortGpio_Ptr = &GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                           break;
              }
              
              /* Special cases */
              if( (Port_PortPins[PinID].Pin ==  0xD7 ) || ((Port_PortPins[PinID].Pin ==  0xF0))) /* PD7 or PF0 */
              {
                  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;                     /* Unlock the GPIOCR register */   
                  SET_BIT( *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET) , pin_num    );  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
              }
              else
              {
                  /* Do Nothing ... No need to unlock the commit register for this pin */
              }
                   
              
             /* ADC PIN MODE  -> analog pin */
              if(Port_PortPins[PinID].Mode == PORT_PIN_MODE_ADC)
              {
                /* SET the corresponding bit in the GPIOAMSEL register to Enable analog functionality on this pin */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , pin_num );     
                
              }
              else /* Any other MODE  -> Digital  pin */
              {
                /* Set the corresponding bit in the GPIODEN register to Enable digital functionality on this pin */
                 SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), pin_num );     
                /* Clear the corresponding bit in the GPIOAMSEL register to Disable analog functionality on this pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), pin_num );     
              }
              
              
              /* Alternative function */
              switch(Port_PortPins[PinID].Mode)
              {
              case PORT_PIN_MODE_DIO:
              case PORT_PIN_MODE_ADC:
                /* case PORT_PIN_MODE_DIO_GPT & case PORT_PIN_MODE_DIO_WDG & case PORT_PIN_MODE_ADC:*/
                /* GPIO */
                /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) ,pin_num );    
                /* Clear the PMCx bits for this pin */
                *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << pin_num * 4 );  
                break;
                
              case PORT_PIN_MODE_UART:
              case PORT_PIN_MODE_SPI:
               /* Enable Alternative function for this pin by SET the corresponding bit in GPIOAFSEL register */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) ,pin_num );
                /* Clear the PMCx bits for this pin */
                *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << pin_num * 4 );  
                /* set the PMCx bits with the corresponding funtion mode number */
                *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (Port_PortPins[PinID].Mode << pin_num * 4 ); 
                break;
              }
              
              /* output or input */
             if(Port_PortPins[PinID].Direction == PORT_PIN_OUT) /* OUTPUT*/
              {
                if(Port_PortPins[PinID].Value == STD_HIGH)
                {
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , pin_num);          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
                }
                else
                {
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , pin_num);        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
                }
                /* requirment PORT055 */
                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , pin_num);            
              }
             else if(Port_PortPins[PinID].Direction == PORT_PIN_IN) /*INPUT */
              {
                  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
                
                if(Port_PortPins[PinID].Resistor == PULL_UP)
                {
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , pin_num);       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
                }
                else if(Port_PortPins[PinID].Resistor == PULL_DOWN)
                {
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , pin_num);     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
                }
                else
                {
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) ,   pin_num);     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , pin_num);   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
                }
              }
             else
              {
                /* Do Nothing */
              }
            
        
            }
        }
}


/************************************************************************************
* Service Name: Port_SetPinDirection     
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
*              - Setup Pin Mode Changeability 
*              - Setup Pin Direction Changeability
************************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)  /* Requirment PORT086 */
void Port_SetPinDirection( Port_PinType Pin,  Port_PinDirectionType Direction)
{
  	volatile uint32 * PortGpio_Ptr = NULL_PTR;
	boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				Port_SetPinDirection_SID, PORT_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if the used channel is within the valid range */
	if (PORT_CONFIGURED_PINS <= Pin)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				Port_SetPinDirection_SID, PORT_E_PARAM_PIN);
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
    uint8 pin_num =  (Port_PortPins[Pin].Pin & 0x0F); /* Pin number */
    /* calculating PORT BASE ADDRESS  */
    /* Pin parameter must be an index 0 - 38 */
        switch((Port_PortPins[Pin].Pin) >> 4)  //Ex:0xA5  ->  0x0A
        {
            case  0x0A: PortGpio_Ptr = &GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                        break;
            case  0x0B: PortGpio_Ptr = &GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                        break;
            case  0x0C: PortGpio_Ptr = &GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                        break;
            case  0x0D: PortGpio_Ptr = &GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                        break;
            case  0x0E: PortGpio_Ptr = &GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                        break;
            case  0x0F: PortGpio_Ptr = &GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                        break;
        }
    
        if( Port_PortPins[Pin].Pin_Direction_changeable == STD_ON)
        {
          /* Direction can be changed */
          if( Direction == PORT_PIN_OUT)
          {
            /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , pin_num);        
          }
          else
          {
            /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , pin_num);             
          }
        }
        else
        {
          /* Direction can not be changed */
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                          Port_SetPinDirection_SID, PORT_E_DIRECTION_UNCHANGEABLE);
        }
  }
  else
  {
          /* No Action Required */
  }
#endif
}



/************************************************************************************
* Service Name: Port_SetPinMode
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Port Pin ID(Pin), Port Pin Mode (Mode) 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Set the Port Pin Mode
************************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)  /* Requirment PORT086 */
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode )
{
 	volatile uint32 * PortGpio_Ptr = NULL_PTR;
	boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the Driver is initialized before using this function */
    if (PORT_NOT_INITIALIZED == Port_Status)
    {
            Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                            Port_SetPinMode_SID, PORT_E_UNINIT);
            error = TRUE;
    }
    else
    {
            /* No Action Required */
    }
    /* Check if the used channel is within the valid range */
    if (PORT_CONFIGURED_PINS <= Pin)
    {

            Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                            Port_SetPinMode_SID, PORT_E_PARAM_PIN);
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
    uint8 pin_num =  (Port_PortPins[Pin].Pin & 0x0F); /* Pin number */
    /* calculating PORT BASE ADDRESS  */
    /* Pin parameter must be an index 0 - 38 */
        switch((Port_PortPins[Pin].Pin) >> 4)  //Ex:0xA5  ->  0x0A
        {
            case  0x0A: PortGpio_Ptr = &GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                     break;
            case  0x0B: PortGpio_Ptr = &GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                     break;
            case  0x0C: PortGpio_Ptr = &GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                     break;
            case  0x0D: PortGpio_Ptr = &GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                     break;
            case  0x0E: PortGpio_Ptr = &GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                     break;
            case  0x0F: PortGpio_Ptr = &GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                     break;
        }
 
        if( Port_PortPins[Pin].Pin_Mode_changeable == STD_ON)
        {
          /* Mode can be changed */
           /* ADC PIN MODE  -> analog pin */
          if( Mode  == PORT_PIN_MODE_ADC)
          {
            /* SET the corresponding bit in the GPIOAMSEL register to Enable analog functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , pin_num );     
            
          }
          else /* Any other MODE  -> Digital  pin */
          {
            /* Set the corresponding bit in the GPIODEN register to Enable digital functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), pin_num );     
            /* Clear the corresponding bit in the GPIOAMSEL register to Disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), pin_num );     
          }
          
          /* Alternative function */
          switch(Port_PortPins[Pin].Mode)
          {
          case PORT_PIN_MODE_DIO:
            /* case PORT_PIN_MODE_DIO_GPT & case PORT_PIN_MODE_DIO_WDG & case PORT_PIN_MODE_ADC:*/
            /* GPIO */ 
            /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) ,pin_num );    
            /* Clear the PMCx bits for this pin */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << pin_num);  
            break;
            
          case PORT_PIN_MODE_UART:
           /* Enable Alternative function for this pin by SET the corresponding bit in GPIOAFSEL register */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) ,pin_num );
            /* set the PMCx bits with the corresponding funtion mode number */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(PORT_PIN_MODE_UART << pin_num); 
            break;
          case PORT_PIN_MODE_SPI:
             /* Enable Alternative function for this pin by SET the corresponding bit in GPIOAFSEL register */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) ,pin_num );
            /* set the PMCx bits with the corresponding funtion mode number */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(PORT_PIN_MODE_SPI << pin_num); 
            break;
          }
        }
        else
        {
          /* Mode can not be changed */
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                          Port_SetPinMode_SID, PORT_E_MODE_UNCHANGEABLE);
        }
  }
  else
  {
          /* No Action Required */
  }
}
#endif


  /************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x12
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): VersionInfo - Pointer to where to store the version information of this module.
* Return value: None
* Description: Function to get the version information of this module.
************************************************************************************/

#if (PORT_VERSION_INFO_API == STD_ON)  /* Requirment PORT086 */ 
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				Port_GetVersionInfo_SID, PORT_E_PARAM_POINTER);
	}
	else
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}
#endif
