;
;   Declaration of AN2131xx EZ-USB Registers
;
;
;   Copyright (c) 2004	Martin Langer <martin-langer@gmx.de>
;
;
;   This program is free software; you can redistribute it and/or
;   modify it under the terms of the GNU General Public License
;   as published by the Free Software Foundation; either version 2
;   of the License, or any later version.
;
;   This program is distributed in the hope that it will be useful,
;   but WITHOUT ANY WARRANTY; without even the implied warranty of
;   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
;   GNU General Public License for more details.
;
;   You should have received a copy of the GNU General Public License
;   along with this program; if not, write to the Free Software
;   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
;
;


.equ DPL1,	0x84
.equ DPH1,	0x85
.equ DPS,	0x86		
.equ CKCON,	0x8E
.equ SPC_FNC,	0x8F
.equ EXIF,	0x91
.equ MPAGE,	0x92
.equ SCON0,	0x98
.equ SBUF0,	0x99
.equ SCON1,	0xC0
.equ SBUF1,	0xC1
.equ EICON,	0xD8
.equ EIE,	0xE8		; Interrupt Enables
.equ EIP,	0xF8


.equ OUT1BUF,	0x7E40
.equ IN1BUF,	0x7E80
.equ OUT0BUF,	0x7EC0
.equ IN0BUF,	0x7F00
.equ CPUCS,     0x7F92	
.equ PORTACFG, 	0x7F93
.equ PORTBCFG, 	0x7F94
.equ PORTCCFG, 	0x7F95
.equ OUTA,     	0x7F96	
.equ OUTB,     	0x7F97
.equ OUTC,     	0x7F98
.equ PINSA,    	0x7F99
.equ PINSB,    	0x7F9A
.equ PINSC,    	0x7F9B
.equ OEA,      	0x7F9C
.equ OEB,      	0x7F9D
.equ OEC,      	0x7F9E

.equ I2CS,	0x7FA5		; I2C Control and Status
.equ I2DAT,	0x7FA6		; I2C Data

.equ IN07IRQ,	0x7FA9		; EP IN Interrupt Request
.equ OUT07IRQ,	0x7FAA		; EP OUT Interrupt Request
.equ USBIRQ,	0x7FAB		; USB Interrupt Request
.equ USBIEN,	0x7FAE		; USB Interrupt Enables
.equ USBBAV,	0x7FAF		; Breakpoint and Autovector
.equ EP0CS,	0x7FB4		; Control and Status
.equ IN0BC,	0x7FB5		; Byte Count
.equ IN1CS,	0x7FB6
.equ IN1BC,	0x7FB7
.equ OUT0BC,	0x7FC5		; Byte Count
.equ OUT1CS,	0x7FC6
.equ OUT1BC,	0x7FC7
.equ USBCS,	0x7FD6		; USB Control and Status
.equ SD_BMREQ,	0x7FE8		; Setup Data Byte 1: bmRequest 
					; c0: Vendor Request 'In'
					; 40: Vendor Request 'Out'
.equ SD_BREQ,	0x7FE9		; Setup Data Byte 2: bRequest
					; a0: Internal Firmware Load
					; a3: External Firmware Load ?
.equ SD_VALL,	0x7FEA		; Setup Data Byte 3: Starting address (lo)
.equ SD_VALH,	0x7FEB		; Setup Data Byte 4: Starting address (hi)
.equ SD_INDL,	0x7FEC		; Setup Data Byte 5: 0x00
.equ SD_INDH,	0x7FED		; Setup Data Byte 6: 0x00
.equ SD_LENL,	0x7FEE		; Setup Data Byte 7: Number of Bytes (lo)
.equ SD_LENH,	0x7FEF		; Setup Data Byte 8: Number of Bytes (hi)

;;
