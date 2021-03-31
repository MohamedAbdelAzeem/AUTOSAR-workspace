 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mohamed AbdelAzeem
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/*******************************************************
                  Header files
*******************************************************/
/* PORT Pre-Compile Configuration Header file */
#include "Port_Cfg.h"  

/* Standard AUTOSAR types */
#include "Std_Types.h"
   
/* Non AUTOSAR files */
#include "Common_Macros.h"
#include "Common_Macros.h"
#include "Std_Types.h"


/*******************************************************
                  PORT MODULE VERSION
*******************************************************/
#define PORT_VENDOR_ID    (1000U)

/* Dio Module Id */
#define PORT_MODULE_ID    (120U)

/* Dio Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)


/*******************************************************
                 VERSION CHECKING
*******************************************************/
/* AUTOSAR checking between Std Types and Dio Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* AUTOSAR Version checking between Dio_Cfg.h and Dio.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Dio_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Dio_Cfg.h and Dio.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Dio_Cfg.h does not match the expected version"
#endif

 
   
   
 /******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for  PORT init */
#define Port_Init_SID                           (uint8)0x00

/* Service ID for PORT SET PIN DIRECTION */
#define Port_SetPinDirection_SID                (uint8)0x01

/* Service ID for Port refresh port direction */
#define Port_RefreshPortDirection_SID           (uint8)0x02

/* Service ID for Port get version info */
#define Port_GetVersionInfo_SID                 (uint8)0x03

/* Service ID for Port set Pin mode */
#define Port_SetPinMode_SID                     (uint8)0x04

  
/*******************************************************************************
   *                      DET Error Codes     SRS PAGE:25                                   *
 *******************************************************************************/
/* DET code to report Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN                          (uint8)0x0A

/* DET code to report  Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE             (uint8)0x0B

/* DET code to report API Port_Init service called with wrong parameter. */
#define PORT_E_PARAM_CONFIG                       (uint8)0x0C

/* DET code to report API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_PARAM_INVALID_MODE                 (uint8)0x0D
   
/* DET code to report API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_MODE_UNCHANGEABLE                   (uint8)0x0E
 
/* DET code to report API service called without module initialization  */
#define PORT_E_UNINIT                             (uint8)0x0F

 /* DET code to report APIs called with a Null  Pointer */
#define PORT_E_PARAM_POINTER                       (uint8)0x10
   
/*
 * Macros for PORT Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)  
   

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Data type for the symbolic name of a port pin. */
/* requirment (PORT013) & (PORT219) */   
typedef uint8 Port_PinType;

/* data type for port number */
typedef uint8 Port_PinPort;

/* Different port pin modes. */
typedef uint8 Port_PinAltrModeType;

/* data type for Pin Number */
typedef uint8 Port_PinNum;


/* type to set pin Function */
typedef uint8 Port_PinModeType;

/* type for pin initial value */
typedef uint8 Pin_level;

/*Possible directions of a port pin. */
/* requirment (PORT046) & (PORT220) */   
typedef enum {
	PORT_PIN_IN,
	PORT_PIN_OUT
} Port_PinDirectionType;


/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;

/* data type for pin Mode changeable */
typedef uint8 Port_PinModeChangeableType;

/* data type for pin direction changeable */
typedef uint8 Port_PinDirectionChangeableType;

/* Type of the external data structure containing 
 * Description: Structure to configure each individual PIN:
 *	1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *	2. the number of the pin in the PORT.
 *      3. the functionality of the pin DIO, UART, SPI...etc
 *      4. the direction of pin --> INPUT or OUTPUT
 *      5. the initial value  
 *      6. Pin Direction changeability during runtime
 *      7. Pin Mode changeability during runtime
 *      8. the internal resistor --> Disable, Pull up or Pull down
 */  

typedef struct Port_ConfigPin{
        Port_PinType Pin;
	Port_PinModeType Mode;
	Port_PinDirectionType Direction;
	Pin_level Value;
        Port_PinDirectionChangeableType Pin_Direction_changeable;
        Port_PinModeChangeableType Pin_Mode_changeable;	
        Port_InternalResistor Resistor;
}Port_ConfigPin ;



/* Data Structure required for initializing the PORT Driver */
typedef struct Port_ConfigType
{
	Port_ConfigPin Pins[PORT_CONFIGURED_PINS];
} Port_ConfigType;

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Dio and other modules */
extern const Port_ConfigType Port_Configuration;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

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
void Port_Init(const Port_ConfigType *ConfigPtr );

/************************************************************************************
* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in):  Port Pin ID(Pin), Port Pin Direction (Direction) 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Set the direction of the GPIO pin
************************************************************************************/
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction );

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
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode );


/************************************************************************************
* Service Name: Port_GetVersionInfo
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): Pointer to where to store the version information of this module
* Return value: None
* Description: Function to Set the Port Pin Mode
************************************************************************************/
void Por_GetVersionInfo(Std_VersionInfoType * versioninfo);


/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function shall refresh the direction
of all configured ports to the configured direction
************************************************************************************/
void Port_RefreshPortDirection(void);

#endif /* PORT_H */
