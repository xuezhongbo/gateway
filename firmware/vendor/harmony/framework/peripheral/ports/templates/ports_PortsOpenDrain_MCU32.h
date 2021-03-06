/*******************************************************************************
  PORTS Peripheral Library Template Implementation

  File Name:
    ports_PortsOpenDrain_MCU32.h

  Summary:
    PORTS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : PortsOpenDrain
    and its Variant : MCU32
    For following APIs :
        PLIB_PORTS_PinOpenDrainEnable
        PLIB_PORTS_PinOpenDrainDisable
        PLIB_PORTS_OpenDrainEnable
        PLIB_PORTS_OpenDrainDisable
        PLIB_PORTS_ExistsPortsOpenDrain

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
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

//DOM-IGNORE-END

#ifndef _PORTS_PORTSOPENDRAIN_MCU32_H
#define _PORTS_PORTSOPENDRAIN_MCU32_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _PORTS_OPEN_DRAIN_B_VREG(index)
    _PORTS_PIN_MODE_VREG(index)

  MASKs: 
    _PORTS_OPEN_DRAIN_B_MASK(index)
    _PORTS_PIN_MODE_MASK(index)

  POSs: 
    _PORTS_OPEN_DRAIN_B_POS(index)
    _PORTS_PIN_MODE_POS(index)

  LENs: 
    _PORTS_OPEN_DRAIN_B_LEN(index)
    _PORTS_PIN_MODE_LEN(index)

*/


//******************************************************************************
/* Function :  PORTS_PinOpenDrainEnable_MCU32

  Summary:
    Implements MCU32 variant of PLIB_PORTS_PinOpenDrainEnable 

  Description:
    This template implements the MCU32 variant of the PLIB_PORTS_PinOpenDrainEnable function.
*/

PLIB_TEMPLATE void PORTS_PinOpenDrainEnable_MCU32( PORTS_MODULE_ID index , PORTS_CHANNEL channel , PORTS_BIT_POS       bitPos )
{
    _SFR_BIT_SET( _PORTS_OPEN_DRAIN_B_VREG(index) + ((channel-1) * 0x10), bitPos );
}


//******************************************************************************
/* Function :  PORTS_PinOpenDrainDisable_MCU32

  Summary:
    Implements MCU32 variant of PLIB_PORTS_PinOpenDrainDisable 

  Description:
    This template implements the MCU32 variant of the PLIB_PORTS_PinOpenDrainDisable function.
*/

PLIB_TEMPLATE void PORTS_PinOpenDrainDisable_MCU32( PORTS_MODULE_ID index , PORTS_CHANNEL channel , PORTS_BIT_POS       bitPos )
{
     _SFR_BIT_CLEAR( _PORTS_OPEN_DRAIN_B_VREG(index) + ((channel-1) * 0x10), bitPos );
}


//******************************************************************************
/* Function :  PORTS_OpenDrainEnable_MCU32

  Summary:
    Implements MCU32 variant of PLIB_PORTS_OpenDrainEnable 

  Description:
    This template implements the MCU32 variant of the PLIB_PORTS_OpenDrainEnable function.
*/

PLIB_TEMPLATE void PORTS_OpenDrainEnable_MCU32( PORTS_MODULE_ID index , PORTS_CHANNEL channel , PORTS_DATA_MASK mask )
{
    _SFR_SET( _PORTS_OPEN_DRAIN_B_VREG(index) + ((channel-1) * 0x10), mask );
}


//******************************************************************************
/* Function :  PORTS_OpenDrainDisable_MCU32

  Summary:
    Implements MCU32 variant of PLIB_PORTS_OpenDrainDisable 

  Description:
    This template implements the MCU32 variant of the PLIB_PORTS_OpenDrainDisable function.
*/

PLIB_TEMPLATE void PORTS_OpenDrainDisable_MCU32( PORTS_MODULE_ID index , PORTS_CHANNEL channel , PORTS_DATA_MASK mask )
{
    _SFR_CLEAR( _PORTS_OPEN_DRAIN_B_VREG(index) + ((channel-1) * 0x10), mask );
}


//******************************************************************************
/* Function :  PORTS_ExistsPortsOpenDrain_MCU32

  Summary:
    Implements MCU32 variant of PLIB_PORTS_ExistsPortsOpenDrain

  Description:
    This template implements the MCU32 variant of the PLIB_PORTS_ExistsPortsOpenDrain function.
*/

#define PLIB_PORTS_ExistsPortsOpenDrain PLIB_PORTS_ExistsPortsOpenDrain
PLIB_TEMPLATE bool PORTS_ExistsPortsOpenDrain_MCU32( PORTS_MODULE_ID index )
{
    return true;
}


#endif /*_PORTS_PORTSOPENDRAIN_MCU32_H*/

/******************************************************************************
 End of File
*/

