// Copyright © 2016-2018 The Things Products
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.

/*******************************************************************************
  MPLAB Harmony Project Main Source File

  Company:
    Microchip Technology Inc.
  


  File Name:
    main.c

  Summary:
    This file contains the "main" function for an MPLAB Harmony project.

  Description:
    This file contains the "main" function for an MPLAB Harmony project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all MPLAB Harmony modules in the system and it calls the
    "SYS_Tasks" function from within a system-wide "super" loop to maintain
    their correct operation. These two functions are implemented in
    configuration-specific files (usually "system_init.c" and "system_tasks.c")
    in a configuration-specific folder under the "src/system_config" folder
    within this project's top-level folder.  An MPLAB Harmony project may have
    more than one configuration, each contained within it's own folder under
    the "system_config" folder.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

//Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                   // Defines NULL
#include <stdbool.h>                  // Defines true
#include <stdlib.h>                   // Defines EXIT_FAILURE
#include "system/common/sys_module.h" // SYS function prototypes

#include "subsystem_controller.h"

#include "peripheral/wdt/plib_wdt.h"
#include "peripheral/tmr/plib_tmr.h"
#include "peripheral/reset/plib_reset.h"
#include "peripheral/int/plib_int.h"

#include "trcUser.h"
// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main(void)
{
    // Initialize the WatchDog
    wdt_init();

    // Initialize the FreeRTOS trace recorder
    vTraceInitTraceData();
    uiTraceStart();

    if(wdt_get_reboot_reason() != RESET_REASON_POWERON)
    {
        // Force power off for all modules
        sdSet(false);       // SD card
        wifiSet(false);     // Wifi
        ethernetSet(false); // Ethernet
        loraSet(false);     // LoRa
        bleSet(false);      // BLE

        // Wait before putting modules on (with a busy while-loop as timer is not running yet)
        uint32_t countdown = 100000000;
        for(; countdown > 0; countdown--)
            ;
    }

    statOn();
    sdSet(ON);       // SD card
    wifiSet(ON);     // Wifi
    ethernetSet(ON); // Ethernet
    loraSet(OFF);     // LoRa, will be turned on later
    bleSet(ON);      // BLE

    /* Initialize all MPLAB Harmony modules, including application(s). */
    SYS_Initialize(NULL);

    while(true)
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    /* Execution should not come here during normal operation */

    return (EXIT_FAILURE);
}

/*******************************************************************************
 End of File
*/
