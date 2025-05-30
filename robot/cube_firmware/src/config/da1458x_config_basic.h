/**
 ****************************************************************************************
 *
 * @file da1458x_config_basic.h
 *
 * @brief Basic compile configuration file.
 *
 * Copyright (C) 2015. Dialog Semiconductor Ltd, unpublished work. This computer
 * program includes Confidential, Proprietary Information and is a Trade Secret of
 * Dialog Semiconductor Ltd.  All use, disclosure, and/or reproduction is prohibited
 * unless authorized in writing. All Rights Reserved.
 *
 * <bluetooth.support@diasemi.com> and contributors.
 *
 ****************************************************************************************
 */

#ifndef _DA1458X_CONFIG_BASIC_H_
#define _DA1458X_CONFIG_BASIC_H_

#include "da1458x_stack_config.h"

/***************************************************************************************************************/
/* Integrated or external processor configuration                                                              */
/*    -defined      Integrated processor mode. Host application runs in DA14580 processor. Host application    */
/*                  is the TASK_APP kernel task.                                                               */
/*    -undefined    External processor mode. Host application runs on an external processor. Communicates with */
/*                  BLE application through GTL protocol over a signalling iface (UART, SPi etc)               */
/***************************************************************************************************************/
#define CFG_APP

#define GPIO_DRV_PIN_ALLOC_MON_DISABLED

/****************************************************************************************************************/
/* Enables the BLE security functionality in TASK_APP. If not defined BLE security related code is compiled out.*/
/****************************************************************************************************************/
#undef CFG_APP_SECURITY

/****************************************************************************************************************/
/* Enables WatchDog timer.                                                                                      */
/****************************************************************************************************************/
#define CFG_WDOG

/****************************************************************************************************************/
/* Sleep mode memory map configuration. Only one or none of the following directives must be defined.           */
/* The selection determines the memory map configuration. Sleep mode is determined by host application sleep    */
/* mode by using arch_sleep API functions.                                                                      */
/*      -  CFG_MEM_MAP_EXT_SLEEP    Extended sleep mode                                                         */
/*      -  CFG_MEM_MAP_DEEP_SLEEP   Deep sleep mode                                                             */
/*      -  none                     Always active                                                               */
/****************************************************************************************************************/
#define CFG_MEM_MAP_EXT_SLEEP
#undef CFG_MEM_MAP_DEEP_SLEEP

/****************************************************************************************************************/
/* Determines maximum concurrent connections supported by application. It configures the heap memory allocated  */
/* to service multiple connections. It is used for GAP central role applications. For GAP peripheral role it    */
/* should be set to 1 for optimising memory utilisation.                                                        */
/*      - MAX value for DA14580: 6                                                                              */
/*      - MAX value for DA14581: 8                                                                              */
/*      - MAX value for DA14583: 6                                                                              */
/****************************************************************************************************************/
#define CFG_MAX_CONNECTIONS     (1)

/****************************************************************************************************************/
/* Enables development/debug mode. For production mode builds it must be disabled.                              */
/* When enabled the following debugging features are enabled                                                    */
/*      -   SysRAM is not powered down in deep sleep mode. Allows developer to run applications using Deep      */
/*          Sleep mode without programming OTP memory.                                                          */
/*      -   Validation of GPIOs resrvations.                                                                    */
/*      -   Enables Debug module and sets code execution in breakpoint in Hardfault and NMI (Watcdog) handleres.*/
/*          It allows developer to hot attach debugger and get debug information                                */
/****************************************************************************************************************/
#undef CFG_DEVELOPMENT_DEBUG

#endif // _DA1458X_CONFIG_BASIC_H_
