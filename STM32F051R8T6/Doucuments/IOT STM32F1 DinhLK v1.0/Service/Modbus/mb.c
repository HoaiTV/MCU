/* 
* FreeModbus Libary: A portable Modbus implementation for Modbus ASCII/RTU.
* Copyright (c) 2006 Christian Walter <wolti@sil.at>
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the distribution.
* 3. The name of the author may not be used to endorse or promote products
*    derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
* NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
* THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* File: $Id: mb.c,v 1.27 2007/02/18 23:45:41 wolti Exp $
*/

/* ----------------------- System includes ----------------------------------*/
#include "stdlib.h"
#include "string.h"

/* ----------------------- Platform includes --------------------------------*/
#include "port.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbconfig.h"
#include "mbframe.h"
#include "mbproto.h"
#include "mbfunc.h"

#ifdef USING_NOVO
#include "novocfg_pic18t3e1ts2.h"
#include "novo.h"
#endif

#include "mbport.h"
#if MB_RTU_ENABLED == 1
#include "mbrtu.h"
#endif
#if MB_ASCII_ENABLED == 1
#include "mbascii.h"
#endif
#if MB_TCP_ENABLED == 1
#include "mbtcp.h"
#endif

#ifndef MB_PORT_HAS_CLOSE
#define MB_PORT_HAS_CLOSE 0
#endif

/* ----------------------- Static variables ---------------------------------*/
static UCHAR    ucMBAddress;
static EMBSTATE eMBState;

/* ----------------------- Start implementation -----------------------------*/
eMBErrorCode eMBInit( UCHAR ucSlaveAddress, UCHAR ucPort, ULONG ulBaudRate, eMBParity eParity )
{
    eMBErrorCode    eStatus = MB_ENOERR;
    
    /* check preconditions */
    if( ( ucSlaveAddress == MB_ADDRESS_BROADCAST ) ||
       ( ucSlaveAddress < MB_ADDRESS_MIN ) || ( ucSlaveAddress > MB_ADDRESS_MAX ) )
    {
        eStatus = MB_EINVAL;
    }
    else
    {
        ucMBAddress = ucSlaveAddress;
        
        eStatus = eMBRTUInit( ucMBAddress, ucPort, ulBaudRate, eParity );
        
        if( eStatus == MB_ENOERR )
        {
            if( !xMBPortEventInit(  ) )
            {
                /* port dependent event module initalization failed. */
                eStatus = MB_EPORTERR;
            }
            else
            {
                eMBState = STATE_DISABLED;
            }
        }
    }
    return eStatus;
}

eMBErrorCode eMBClose( void )
{
    eMBErrorCode    eStatus = MB_ENOERR;
    
    if( eMBState == STATE_DISABLED )
    {
        vMBPortClose(  );
    }
    else
    {
        eStatus = MB_EILLSTATE;
    }
    return eStatus;
}

eMBErrorCode eMBEnable( void )
{
    eMBErrorCode    eStatus = MB_ENOERR;
    
    if( eMBState == STATE_DISABLED )
    {
        /* Activate the protocol stack. */
        eMBRTUStart(  );
        eMBState = STATE_ENABLED;
    }
    else
    {
        eStatus = MB_EILLSTATE;
    }
    return eStatus;
}

eMBErrorCode eMBDisable( void )
{
    eMBErrorCode    eStatus;
    
    if( eMBState == STATE_ENABLED )
    {
        eMBRTUStop(  );
        eMBState = STATE_DISABLED;
        eStatus = MB_ENOERR;
    }
    else if( eMBState == STATE_DISABLED )
    {
        eStatus = MB_ENOERR;
    }
    else
    {
        eStatus = MB_EILLSTATE;
    }
    return eStatus;
}

void TaskMBPoll()
{
    static UCHAR   *ucMBFrame;
    static UCHAR    ucRcvAddress;
    static UCHAR    ucFunctionCode;
    static USHORT   usLength;
    static eMBException eException;
    
//    int             i;
    eMBErrorCode    eStatus = MB_ENOERR;
    eMBEventType    eEvent;
    
    /* Check if the protocol stack is ready. */
    if( eMBState != STATE_ENABLED )
    {       
        return;     
    }

    /* Check if there is a event available. If not return control to caller.
    * Otherwise we will handle the event. */
    if( xMBPortEventGet( &eEvent ) == TRUE )
    {
        switch ( eEvent )
        {
        case EV_READY:
            break;
            
        case EV_FRAME_RECEIVED:
            eStatus = eMBRTUReceive( &ucRcvAddress, &ucMBFrame, &usLength );
            if( eStatus == MB_ENOERR )
            {
                /* Check if the frame is for us. If not ignore the frame. */
                if( ( ucRcvAddress == ucMBAddress ) || ( ucRcvAddress == MB_ADDRESS_BROADCAST ) )
                {
                    ENTER_CRITICAL_SECTION();
                    ( void )xMBPortEventPost( EV_EXECUTE );
                    EXIT_CRITICAL_SECTION();
                }
            }
            break;
            
        case EV_EXECUTE:
            ucFunctionCode = ucMBFrame[MB_PDU_FUNC_OFF];
            eException = MB_EX_ILLEGAL_FUNCTION;
            switch( ucFunctionCode )
            {
#if MB_FUNC_OTHER_REP_SLAVEID_ENABLED > 0
            case MB_FUNC_OTHER_REPORT_SLAVEID:
                eException = eMBFuncReportSlaveID( ucMBFrame, &usLength );
                break;
#endif
#if MB_FUNC_READ_INPUT_ENABLED > 0
            case MB_FUNC_READ_INPUT_REGISTER:
                eException = eMBFuncReadInputRegister( ucMBFrame, &usLength );
                break;
#endif
#if MB_FUNC_READ_HOLDING_ENABLED > 0
            case MB_FUNC_READ_HOLDING_REGISTER:
                eException = eMBFuncReadHoldingRegister( ucMBFrame, &usLength );
                break;
#endif
#if MB_FUNC_WRITE_MULTIPLE_HOLDING_ENABLED > 0
            case MB_FUNC_WRITE_MULTIPLE_REGISTERS:
                eException = eMBFuncWriteMultipleHoldingRegister( ucMBFrame, &usLength );
                break;
#endif
#if MB_FUNC_WRITE_HOLDING_ENABLED > 0
            case MB_FUNC_WRITE_REGISTER:
                eException = eMBFuncWriteHoldingRegister( ucMBFrame, &usLength );
                break;
#endif
#if MB_FUNC_READWRITE_HOLDING_ENABLED > 0
            case MB_FUNC_READWRITE_MULTIPLE_REGISTERS:
                eException = eMBFuncReadWriteMultipleHoldingRegister( ucMBFrame, &usLength );
                break;
#endif
#if MB_FUNC_READ_COILS_ENABLED > 0
            case MB_FUNC_READ_COILS:
                eException = eMBFuncReadCoils( ucMBFrame, &usLength );
                break;                  
#endif
#if MB_FUNC_WRITE_COIL_ENABLED > 0
            case MB_FUNC_WRITE_SINGLE_COIL:
                eException = eMBFuncWriteCoil( ucMBFrame, &usLength );
                break;
#endif
#if MB_FUNC_WRITE_MULTIPLE_COILS_ENABLED > 0
            case MB_FUNC_WRITE_MULTIPLE_COILS:
                eException = eMBFuncWriteMultipleCoils( ucMBFrame, &usLength );
                break;
#endif
#if MB_FUNC_READ_DISCRETE_INPUTS_ENABLED > 0
            case MB_FUNC_READ_DISCRETE_INPUTS:
                eException = eMBFuncReadDiscreteInputs( ucMBFrame, &usLength );
                break;
#endif
            }
            
            /* If the request was not sent to the broadcast address we
            * return a reply. */
            if( ucRcvAddress != MB_ADDRESS_BROADCAST )
            {
                if( eException != MB_EX_NONE )
                {
                    /* An exception occured. Build an error frame. */
                    usLength = 0;
                    ucMBFrame[usLength++] = ( UCHAR )( ucFunctionCode | MB_FUNC_ERROR );
                    ucMBFrame[usLength++] = eException;
                }
                eStatus = eMBRTUSend( ucMBAddress, ucMBFrame, usLength );
            }
            break;
            
        case EV_FRAME_SENT:
            break;
        }
    }    
}