 /******************************************************************************
 *
 * Module: SSI
 *
 * File Name: SSI_Regs.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - SSI Driver Registers
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#ifndef SPI_REGS_H
#define SPI_REGS_H

#include "Std_Types.h"

#define SPI0_BASE_ADDRESS               0x40008000
#define SPI1_BASE_ADDRESS               0x40009000
#define SPI2_BASE_ADDRESS               0x4000A000
#define SPI3_BASE_ADDRESS               0x4000B000
#define RCGCSSI_BASE_ADDRESS            0x400FE000


#define SSICR0_OFFSET                     0x000  //SSI Control 0 
#define SSICR1_OFFSET			  0x004  //SSI Control 1 
#define SSIDATA_OFFSET			  0x008  //SSI Data 
#define SSISR_OFFSET			  0x00c  //SSI Status 
#define SSICPSR_OFFSET			  0x010  //SSI Clock Prescale 
#define SSIM_OFFSET			  0x014  //SSI Interrupt Mask 
#define SSIRIS_OFFSET		          0x018  //SSI Raw Interrupt Status 
#define SSIMIS_OFFSET			  0x01c  //SSI Masked Interrupt Status 
#define SSIICR_OFFSET 		          0x020  //SSI Interrupt Clear 
#define SSICC_OFFSET			  0xFC8  //SSI Clock Configuration //0x00 for system clock
#define RCGCSSI_OFFSET                    0x61C  //SSI clock Enable


#endif /* SPI_REGS_H */
