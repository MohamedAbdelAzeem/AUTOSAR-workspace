/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre_compile switch to enable/disable the use of the function Port_SetPinDirection */
#define PORT_SET_PIN_DIRECTION_API           (STD_ON)    /* Requirment PORT100 */

/* Pre_compile switch to enable/disable the use of the function Port_SetPinMode */
#define PORT_SET_PIN_MODE_API                (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_ON)

/* Pre-compile option for presence of Port_SetPinDirection Function */
#define PORT_SET_PIN_DIRECTION_API               (STD_ON)

/* Number of the configured Dio Channels */
#define PORT_CONFIGURED_PINS             (39U)

 /* Pin modes */
#define PORT_PIN_MODE_DIO               (0x00)
#define PORT_PIN_MODE_DIO_GPT           (0x00)
#define PORT_PIN_MODE_DIO_WDG           (0x00)
#define PORT_PIN_MODE_UART              (0x01)
#define PORT_PIN_MODE_SPI               (0x02)
#define PORT_PIN_MODE_ADC               (0x03)
//#define PORT_PIN_MODE_CAN (0x00)



#define PORT_A         (0x01)
#define PORT_B         (0x02)  
#define PORT_C         (0x03)  
#define PORT_D         (0x04)  
#define PORT_E         (0x05)  
#define PORT_F         (0x06) 

//Requirment (PORT207)
#define PORT_A_PIN_0   (0xA0)
#define PORT_A_PIN_1   (0xA1)
#define PORT_A_PIN_2   (0xA2)
#define PORT_A_PIN_3   (0xA3)
#define PORT_A_PIN_4   (0xA4)
#define PORT_A_PIN_5   (0xA5)
#define PORT_A_PIN_6   (0xA6)
#define PORT_A_PIN_7   (0xA7)
   
#define PORT_B_PIN_0   (0xB0)
#define PORT_B_PIN_1   (0xB1)
#define PORT_B_PIN_2   (0xB2)
#define PORT_B_PIN_3   (0xB3)
#define PORT_B_PIN_4   (0xB4)
#define PORT_B_PIN_5   (0xB5)
#define PORT_B_PIN_6   (0xB6)
#define PORT_B_PIN_7   (0xB7)

#define PORT_C_PIN_4   (0xC4)
#define PORT_C_PIN_5   (0xC5)  
#define PORT_C_PIN_6   (0xC6)  
#define PORT_C_PIN_7   (0xC7)  

#define PORT_D_PIN_0   (0xD0)
#define PORT_D_PIN_1   (0xD1)  
#define PORT_D_PIN_2   (0xD2)  
#define PORT_D_PIN_3   (0xD3)  
#define PORT_D_PIN_4   (0xD4)  
#define PORT_D_PIN_5   (0xD5)  
#define PORT_D_PIN_6   (0xD7)  
#define PORT_D_PIN_7   (0xD8)  

#define PORT_E_PIN_0   (0xE0)
#define PORT_E_PIN_1   (0xE1)  
#define PORT_E_PIN_2   (0xE2)  
#define PORT_E_PIN_3   (0xE3) 
#define PORT_E_PIN_4   (0xE4)
#define PORT_E_PIN_5   (0xE5)  

#define PORT_F_PIN_0   (0xF0)
#define PORT_F_PIN_1   (0xF1)
#define PORT_F_PIN_2   (0xF2)
#define PORT_F_PIN_3   (0xF3)
#define PORT_F_PIN_4   (0xF4)


#endif /* PORT_CFG_H */
