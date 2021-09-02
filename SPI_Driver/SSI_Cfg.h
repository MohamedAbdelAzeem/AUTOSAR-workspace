 /******************************************************************************
 *
 * Module: Spi
 *
 * File Name: Spi_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Spi Driver
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#ifndef SPI_CFG_H
#define SPI_CFG_H

/*
 * Module Version 1.0.0
 */
#define SPI_CFG_SW_MAJOR_VERSION              (1U)
#define SPI_CFG_SW_MINOR_VERSION              (0U)
#define SPI_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define SPI_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define SPI_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define SPI_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define SPI_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define SPI_VERSION_INFO_API                (STD_OFF)

/* Pre-compile option for Get SPI Status API */
#define SPI_HW_STATUS_API                   (STD_ON)

/* Number of the configured Spi Channels */
#define SPI_MAX_CHANNEL 			(2U)

/* SPI CHANNEL generated configuration  */
/* Channel Index in the array of structures in SSI_PBcfg.c */
#define SPI_CHANNEL_0_INDEX      	   (uint8)0x00
#define SPI_CHANNEL_1_INDEX                (uint8)0x01

#define SPI_CHANNEL_0       		   (uint8)0x00
#define SPI_CHANNEL_1       		   (uint8)0x01
 
  /* Data width */
#define SPI_CHANNEL_0_DATA_LENGTH	    (DATA_LENGTH_8_BITS)
#define SPI_CHANNEL_1_DATA_LENGTH	    (DATA_LENGTH_8_BITS)
   
   /* SpiBufferType */
#define SPI_CHANNEL_0_BufferType            (InternalBuffer)
#define SPI_CHANNEL_1_BufferType      	    (InternalBuffer)
   
   /* SPI channel start bit  */
#define SPI_CHANNEL_0_START_BIT 	    (MSB)
#define SPI_CHANNEL_1_START_BIT 	    (MSB)
   
   /* SPI Channel Mode */
#define SPI_CHANNEL_0_MODE		    (Master_Mode)
#define SPI_CHANNEL_1_MODE   	            (Slave_Mode)
   
   /* SPI Channel source clock  */
#define SPI_CHANNEL_0_CLOCK_SOURCE  	    (System_Clock)
#define SPI_CHANNEL_1_CLOCK_SOURCE  	    (System_Clock) 
   
   /* SPI Channel Frame format  */
#define SPI_CHANNEL_0_FRAME_FORMAT 	    (Freescale_SPI)
#define SPI_CHANNEL_1_FRAME_FORMAT	    (Freescale_SPI)
   
   /* SPI CHANNEL Clock Phase*/
#define SPI_CHANNEL_0_CLOCK_PHASE 	    (Second_Clock_Edge)
#define SPI_CHANNEL_1_CLOCK_PHASE 	    (Second_Clock_Edge)
   
   /* SPI CHANNEL CLOCK POLARITY */
#define SPI_CHNNEL_0_CLOCK_POLARITY	    (Steady_State_LOW)
#define SPI_CHNNEL_1_CLOCK_POLARITY	    (Steady_State_LOW)
   
   /*SPI Baud Rate*/   
#define SPI_CHANNEL_0_Baud_Rate             (9600.0)  
#define SPI_CHANNEL_1_Baud_Rate             (9600.0)  
   
/*SPI System Clock Source*/
#define SPI_System_Clock_Source       (16000000.0)  
   
#endif /* SPI_CFG_H */
