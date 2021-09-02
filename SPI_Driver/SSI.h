 /******************************************************************************
 *
 * Module: SPI
 *
 * File Name: SPI.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - SPI Driver
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#ifndef SPI_H
#define SPI_H

/* Id for the company in the AUTOSAR */
#define SPI_VENDOR_ID    (1000U)

/* SSI Module Id */
#define SPI_MODULE_ID    (83U)

/* Spi Instance Id */
#define SPI_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define SPI_SW_MAJOR_VERSION           (1U)
#define SPI_SW_MINOR_VERSION           (0U)
#define SPI_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define SPI_AR_RELEASE_MAJOR_VERSION   (4U)
#define SPI_AR_RELEASE_MINOR_VERSION   (0U)
#define SPI_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for Port Status
 */
#define SPI_INITIALIZED                (1U)
#define SPI_NOT_INITIALIZED            (0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and SPI Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != SPI_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != SPI_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != SPI_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* SSI Pre-Compile Configuration Header file */
#include "SSI_Cfg.h"

/* AUTOSAR Version checking between SSI_Cfg.h and SSI.h files */
#if ((SPI_CFG_AR_RELEASE_MAJOR_VERSION != SPI_AR_RELEASE_MAJOR_VERSION)\
 ||  (SPI_CFG_AR_RELEASE_MINOR_VERSION != SPI_AR_RELEASE_MINOR_VERSION)\
 ||  (SPI_CFG_AR_RELEASE_PATCH_VERSION != SPI_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of SSI_Cfg.h does not match the expected version"
#endif

/* Software Version checking between SSI_Cfg.h and SSI.h files */
#if ((SPI_CFG_SW_MAJOR_VERSION != SPI_SW_MAJOR_VERSION)\
 ||  (SPI_CFG_SW_MINOR_VERSION != SPI_SW_MINOR_VERSION)\
 ||  (SPI_CFG_SW_PATCH_VERSION != SPI_SW_PATCH_VERSION))
  #error "The SW version of SSI_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for Spi initialization */
#define Spi_Init_SID                   (uint8)0x00

/* Service ID for Spi Deinitialization */
#define Spi_DeInit_SID                  (uint8)0x01

/* Service ID for Spi write internal buffer */
#define Spi_WriteIB_SID                 (uint8)0x02

/* Service ID for Spi read internal buffer */
#define Spi_ReadIB_SID                  (uint8)0x04

/* Service ID for Spi get status */
#define Spi_GetStatus_SID               (uint8)0x06

/* Service ID for SPI GetVersionInfo */
#define Spi_GetVersionInfo_SID         (uint8)0x09


/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid Channel */
#define SPI_E_PARAM_CHANNEL_ID         (uint8)0x0A
   
 /* DET code to report Invalid data length */
#define SPI_E_PARAM_LENGTH_ID          (uint8)0x0D

/* API service called with NULL pointer parameter */
#define SPI_E_PARAM_POINTER_ID          (uint8)0x10

/*API service used without module initialization*/
#define SPI_E_UNINIT_ID                 (uint8)0x1A

/*API SPI_Init service called while the SPI driver has already been initialized*/
#define SPI_E_ALREADY_INITIALIZED_ID    (uint8)0x4A

/*******************************************************************************
 *			   Module configuration values 					       *
 *******************************************************************************/
      /*SPI Data Width in tiva c datasheet */
#define DATA_LENGTH_4_BITS    (0x3)
#define DATA_LENGTH_5_BITS    (0x4)
#define DATA_LENGTH_6_BITS    (0x5)
#define DATA_LENGTH_7_BITS    (0x6)
#define DATA_LENGTH_8_BITS    (0x7)
#define DATA_LENGTH_9_BITS    (0x8)
#define DATA_LENGTH_10_BITS   (0x9)
#define DATA_LENGTH_11_BITS   (0xA)
#define DATA_LENGTH_12_BITS   (0xB)
#define DATA_LENGTH_13_BITS   (0xC)
#define DATA_LENGTH_14_BITS   (0xD)
#define DATA_LENGTH_15_BITS   (0xE)
#define DATA_LENGTH_16_BITS   (0xF)
   
  /* SPI Channel ID in tiva c datasheet  */
#define SPI_0_CHANNEL_ID      (0x00) 
#define SPI_1_CHANNEL_ID      (0x01)   
#define SPI_2_CHANNEL_ID      (0x02) 
#define SPI_3_CHANNEL_ID      (0x02) 
   
  
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/   
   
   typedef uint8  Spi_ChannelType;
   typedef uint8  Spi_DataBufferType;
   typedef uint8  Spi_DataWidthType;
   typedef uint32 BaudRateType;

   
   typedef enum{
      InternalBuffer,ExternalBuffer   
    }SpiBufferType;
   
    typedef enum{
      LSB,MSB   
    }SpiTransferStartType;
    
    typedef enum{
      SPI_UNINIT ,SPI_IDLE,SPI_BUSY    
    }Spi_StatusType;
    
    typedef enum{
      Master_Mode ,Slave_Mode   
    }Spi_ModeType;
    
    typedef enum{
      System_Clock ,PIOSC=5   
    }Spi_Source_ClockType;
    
    typedef enum{
      Freescale_SPI ,TI_Sync_Serial,MicroWire   
    }Spi_Frame_FormatType;
    
    /*Determine data is captured on which edge transition*/
     typedef enum{
      First_Clock_Edge ,Second_Clock_Edge  
    }Spi_Clock_PhaseType;
    
     /*Determine steady state value of SSInClk*/
     typedef enum{
      Steady_State_LOW ,Steady_State_HIGH  
    }Spi_Clock_PolarityType;
    
   typedef struct{
   Spi_ChannelType        SpiChannelID;
   SpiBufferType          SpiChannelType;
   Spi_DataWidthType      SpiDataWidth;
   SpiTransferStartType   SpiTransferStart;
   BaudRateType           BaudRate;
   Spi_ModeType           Spi_Mode;  
   Spi_Source_ClockType   Spi_Source_Clock;
   Spi_Frame_FormatType   Spi_Frame_Format;
   Spi_Clock_PhaseType    Spi_Clock_Phase;
   Spi_Clock_PolarityType Spi_Clock_Polarity;
   }Spi_ConfigChannel;
   
   /* Data Structure required for initializing the SPI Driver */
   typedef struct Spi_ConfigType
   {
	Spi_ConfigChannel SpiPins[SPI_MAX_CHANNEL];
   } Spi_ConfigType;


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Service for Spi initialization */
void Spi_Init(const Spi_ConfigType* ConfigPtr);
               

/* Service for Spi Deinitialization */
Std_ReturnType Spi_DeInit(void);
              
/* Service for Spi write internal buffer */
Std_ReturnType Spi_WriteIB(Spi_ChannelType Channel,const Spi_DataBufferType* DataBufferPtr);                

/* Service for Spi read internal buffer */
 Std_ReturnType Spi_ReadIB(Spi_ChannelType Channel,Spi_DataBufferType* DataBufferPointer);
               
/* Service for Spi get status */
#if(SPI_HW_STATUS_API == STD_ON)
Spi_StatusType* Spi_GetStatus(void);
#endif
              
/* Function for SPI Get Version Info API */
#if (SPI_VERSION_INFO_API == STD_ON)
void Spi_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif      

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by SPI and other modules */
extern const Spi_ConfigType Spi_Configuration;

#endif /* SPI_H */
