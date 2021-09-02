 /******************************************************************************
 *
 * Module: SSI
 *
 * File Name: SSI_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - SSI Driver
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#include "SSI.h"

/*
 * Module Version 1.0.0
 */
#define SSI_PBCFG_SW_MAJOR_VERSION              (1U)
#define SSI_PBCFG_SW_MINOR_VERSION              (0U)
#define SSI_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define SSI_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define SSI_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define SSI_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* AUTOSAR Version checking between SSI_PBcfg.c and SSI.h files */
#if ((SSI_PBCFG_AR_RELEASE_MAJOR_VERSION != SPI_AR_RELEASE_MAJOR_VERSION)\
 ||  (SSI_PBCFG_AR_RELEASE_MINOR_VERSION != SPI_AR_RELEASE_MINOR_VERSION)\
 ||  (SSI_PBCFG_AR_RELEASE_PATCH_VERSION != SPI_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between SSI_PBcfg.c and SSI.h files */
#if ((SSI_PBCFG_SW_MAJOR_VERSION != SPI_SW_MAJOR_VERSION)\
 ||  (SSI_PBCFG_SW_MINOR_VERSION != SPI_SW_MINOR_VERSION)\
 ||  (SSI_PBCFG_SW_PATCH_VERSION != SPI_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif
   
   
/* PB structure used with SSI_Init API */
const Spi_ConfigType Spi_Configuration = { 
 					    SPI_CHANNEL_0,SPI_CHANNEL_0_BufferType, SPI_CHANNEL_0_DATA_LENGTH, SPI_CHANNEL_0_START_BIT, SPI_CHANNEL_0_Baud_Rate, SPI_CHANNEL_0_MODE, SPI_CHANNEL_0_CLOCK_SOURCE, SPI_CHANNEL_0_FRAME_FORMAT, SPI_CHANNEL_0_CLOCK_PHASE, SPI_CHNNEL_0_CLOCK_POLARITY,
                                            SPI_CHANNEL_1,SPI_CHANNEL_1_BufferType, SPI_CHANNEL_1_DATA_LENGTH, SPI_CHANNEL_1_START_BIT, SPI_CHANNEL_1_Baud_Rate, SPI_CHANNEL_1_MODE, SPI_CHANNEL_1_CLOCK_SOURCE, SPI_CHANNEL_1_FRAME_FORMAT, SPI_CHANNEL_1_CLOCK_PHASE, SPI_CHNNEL_1_CLOCK_POLARITY
				         };