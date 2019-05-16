/*
 * FreeModbus Libary: PIC Port
 * Copyright (C) 2006 Christian Walter <wolti@sil.at>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * File: $Id: port.h,v 1.1 2006/08/22 21:35:13 wolti Exp $
 */

#ifndef _PORT_H
#define _PORT_H

//#include <boostc.h>
//#include <system.h>
//#include <memory.h>
//#include <assert.h>
//#include <inttypes.h>

//#define FOSC 4000000
//#pragma CLOCK_FREQ	FOSC

//#define DIRECTION_485_PORT latc
//#define TRANSMIT_485_BIT 5
//#define DIRECTION_485_TRIS trisc

#define	INLINE                      inline
#define PR_BEGIN_EXTERN_C           extern "C" {
#define	PR_END_EXTERN_C             }
 
#define ENTER_CRITICAL_SECTION( ) vMBPortEnterCritical()  
#define EXIT_CRITICAL_SECTION( )  vMBPortExitCritical()

//#define TRANSMIT_ON_485( ) set_bit(DIRECTION_485_PORT, TRANSMIT_485_BIT)
//#define RECEIVE_ON_485( ) clear_bit(DIRECTION_485_PORT, TRANSMIT_485_BIT)

typedef enum
{
    STATE_ENABLED,
    STATE_DISABLED,
    STATE_NOT_INITIALIZED
}EMBSTATE;


//typedef char BOOL;

typedef unsigned char UCHAR;
//typedef char CHAR;

typedef unsigned short USHORT;
typedef short SHORT;

typedef unsigned long ULONG;
typedef long LONG;

#ifndef TRUE
#define TRUE            1
#endif

#ifndef FALSE
#define FALSE           0
#endif

void            vMBPortEnterCritical( void );
void            vMBPortExitCritical( void );

#endif
