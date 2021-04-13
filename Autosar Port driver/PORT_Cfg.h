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
   
 /* Pre-compile option for Direction unchangable  */
#define PORT_E_DIRECTION_CHANGEABLE        (STD_ON)
   
/* Pre-compile option for Mode changable  */
#define PORT_E_MODE_CHANGEABLE             (STD_ON)

/* Pre-compile option for presence of Port_SetPinDirection Function */
#define PORT_SET_PIN_DIRECTION_API               (STD_ON)

/* Number of the configured Dio Channels */
#define PORT_CONFIGURED_PINS             (39U)

 /* Pin modes */
#define PORT_PIN_MODE_DIO                   (0x00)
/* Analog modes */
#define ADC_MODE	                    (0x0A) /* 10 */
#define PORT_PIN_MODE_C1_POS                (0x0A)
#define PORT_PIN_MODE_C1_NEG                (0x0A)
#define PORT_PIN_MODE_C0_POS                (0x0A)
#define PORT_PIN_MODE_C0_NEG                (0x0A)

#define PORT_PIN_MODE_UART0_RX              (0x01)
#define PORT_PIN_MODE_UART0_TX              (0x01)
#define PORT_PIN_MODE_UART1_RX              (0x01)
#define PORT_PIN_MODE_UART1_TX              (0x01)
#define PORT_PIN_MODE_UART1_RTS             (0x01)
#define PORT_PIN_MODE_UART1_CTS             (0x01)
#define PORT_PIN_MODE_UART2_RX              (0x01)
#define PORT_PIN_MODE_UART2_TX              (0x01)
#define PORT_PIN_MODE_UART3_RX              (0x01)
#define PORT_PIN_MODE_UART3_TX              (0x01)
#define PORT_PIN_MODE_UART4_RX              (0x01)
#define PORT_PIN_MODE_UART4_TX              (0x01)
#define PORT_PIN_MODE_UART5_RX              (0x01)
#define PORT_PIN_MODE_UART5_TX              (0x01)
#define PORT_PIN_MODE_UART6_RX              (0x01)
#define PORT_PIN_MODE_UART6_TX              (0x01)
#define PORT_PIN_MODE_SSI3_CLK              (0x01)
#define PORT_PIN_MODE_SSI3_FSS              (0x01)
#define PORT_PIN_MODE_SSI3_RX               (0x01)
#define PORT_PIN_MODE_SSI3_TX               (0x01)

#define PORT_PIN_MODE_SSI0_CLK              (0x02)
#define PORT_PIN_MODE_SSI0_FSS              (0x02)
#define PORT_PIN_MODE_SSI0_RX               (0x02)
#define PORT_PIN_MODE_SSI0_TX               (0x02)
#define PORT_PIN_MODE_SSI2_CLK              (0x02)
#define PORT_PIN_MODE_SSI2_FSS              (0x02)
#define PORT_PIN_MODE_SSI2_RX               (0x02)
#define PORT_PIN_MODE_SSI2_TX               (0x02)
#define PORT_PIN_MODE_SSI1_CLK              (0x02)
#define PORT_PIN_MODE_SSI1_FSS              (0x02)
#define PORT_PIN_MODE_SSI1_RX               (0x02)
#define PORT_PIN_MODE_SSI1_TX               (0x02)

#define PORT_PIN_MODE_I2C0_SCL               (0x03)
#define PORT_PIN_MODE_I2C0_SDA               (0x03)
#define PORT_PIN_MODE_I2C1_SCL               (0x03)
#define PORT_PIN_MODE_I2C1_SDA               (0x03)
#define PORT_PIN_MODE_I2C2_SCL               (0x03)
#define PORT_PIN_MODE_I2C2_SDA               (0x03)
#define PORT_PIN_MODE_I2C3_SCL               (0x03)
#define PORT_PIN_MODE_I2C3_SDA               (0x03) 

#define PORT_PIN_MODE_M0PWM2                 (0x04)
#define PORT_PIN_MODE_M0PWM3                 (0x04)
#define PORT_PIN_MODE_M0PWM0                 (0x04)
#define PORT_PIN_MODE_M0PWM1                 (0x04)
#define PORT_PIN_MODE_M0PWM4                 (0x04)
#define PORT_PIN_MODE_M0PWM5                 (0x04)
#define PORT_PIN_MODE_M0PWM6                 (0x04)
#define PORT_PIN_MODE_M0PWM7                 (0x04)
#define PORT_PIN_MODE_M0FAULT0               (0x04)

#define PORT_PIN_MODE_M1PWM2                 (0x05)
#define PORT_PIN_MODE_M1PWM3                 (0x05)
#define PORT_PIN_MODE_M1PWM0                 (0x05)
#define PORT_PIN_MODE_M1PWM1                 (0x05)
#define PORT_PIN_MODE_M1PWM3                 (0x05)
#define PORT_PIN_MODE_M1PWM4                 (0x05)
#define PORT_PIN_MODE_M1PWM5                 (0x05)
#define PORT_PIN_MODE_M1PWM6                 (0x05)
#define PORT_PIN_MODE_M1PWM7                 (0x05)
#define PORT_PIN_MODE_M1FAULT0               (0x05)

#define PORT_PIN_MODE_IDX1                   (0x06)
#define PORT_PIN_MODE_IDX0                   (0x06)
#define PORT_PIN_MODE_PHA1                   (0x06)
#define PORT_PIN_MODE_PHB1                   (0x06)
#define PORT_PIN_MODE_PHA0                   (0x06)
#define PORT_PIN_MODE_PHB0                   (0x06)

#define PORT_PIN_MODE_T0CCP0                 (0x07)
#define PORT_PIN_MODE_T0CCP1                 (0x07)
#define PORT_PIN_MODE_T1CCP0                 (0x07)
#define PORT_PIN_MODE_T1CCP1                 (0x07)
#define PORT_PIN_MODE_T2CCP0                 (0x07)
#define PORT_PIN_MODE_T2CCP1                 (0x07)
#define PORT_PIN_MODE_T3CCP0                 (0x07)
#define PORT_PIN_MODE_T3CCP1                 (0x07)
#define PORT_PIN_MODE_WT0CCP0                (0x07)
#define PORT_PIN_MODE_WT0CCP1                (0x07)
#define PORT_PIN_MODE_WT1CCP0                (0x07)
#define PORT_PIN_MODE_WT1CCP1                (0x07)
#define PORT_PIN_MODE_WT2CCP0                (0x07)
#define PORT_PIN_MODE_WT2CCP1                (0x07)
#define PORT_PIN_MODE_WT3CCP0                (0x07)
#define PORT_PIN_MODE_WT3CCP1                (0x07)
#define PORT_PIN_MODE_WT4CCP0                (0x07)
#define PORT_PIN_MODE_WT4CCP1                (0x07)
#define PORT_PIN_MODE_WT5CCP0                (0x07)
#define PORT_PIN_MODE_WT5CCP1                (0x07)

#define PORT_PIN_MODE_CAN1_RX                (0x08)
#define PORT_PIN_MODE_CAN1_TX                (0x08)
#define PORT_PIN_MODE_CAN0_RX                (0x08)
#define PORT_PIN_MODE_CAN0_TX                (0x08)
#define PORT_PIN_MODE_USB0_EPEN              (0x08)
#define PORT_PIN_MODE_USB0_PFLT              (0x08)
#define PORT_PIN_MODE_NMI                    (0x08)

#define PORT_PIN_MODE_C0                     (0x09)
#define PORT_PIN_MODE_C1                     (0x09)

#define PORT_PIN_MODE_TRD1                   (0x0E) /* 14 */
#define PORT_PIN_MODE_TRD0                   (0x0E)
#define PORT_PIN_MODE_TRCLK                  (0x0E)
/* Special cases */
#define PORTC_PIN4_MODE_UART1_RX             (0x02)
#define PORTC_PIN5_MODE_UART1_RX             (0x02)

#define PORTF_PIN0_MODE_CAN0_RX              (0x03)
#define PORTF_PIN3_MODE_CAN0_TX              (0x03)

#define PORTC_PIN4_MODE_U1RTS                (0x08)
#define PORTC_PIN5_MODE_U1CTS                (0x08)
              
 /* Ports */
#define PORT_A         (0x01)
#define PORT_B         (0x02)  
#define PORT_C         (0x03)  
#define PORT_D         (0x04)  
#define PORT_E         (0x05)  
#define PORT_F         (0x06) 

/* Requirment (PORT207) */
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
