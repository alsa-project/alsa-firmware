;
;   Second stage AN2131QC (aka EzUSB) loader
;
;	
;   Copyright (c) 2004-2005 Martin Langer <martin-langer@gmx.de>
;
;   Written for Tascam US-122/US-224/US-428 audio/MIDI devices
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

.inc	"an2131.asm"


; ====================================================== interrupt vectors ===

	.org	0x0000			; reset vector
	ljmp    init

	.org	0x0043			; int2 vector (USB)
	ljmp	usb_jump_table		; autovector will replace byte 45


; =================================================================== init ===

init:
	mov	sp, #20h		; move stack pointer to 0x20

	mov	a, EIE
	setb	acc.0			; enable int2 (USB Interrupt)
	mov	EIE, a
	
	mov	dptr, #USBIRQ
	mov	a, #00011111b
	movx	@dptr, a		; clear Interrupt Request

	mov	dptr, #IN07IRQ
	mov	a, #11111111b
	movx	@dptr, a		; clear EP IN Interrupt Request

	mov	dptr, #OUT07IRQ
	mov	a, #11111111b
	movx	@dptr, a		; clear EP OUT Interrupt Request

	mov	dptr, #PORTCCFG
	movx	a, @dptr
	orl	a, #11000000b		; allow read and write on Port C
	movx	@dptr, a

	mov	dptr, #USBBAV
	movx	a, @dptr
	orl	a, #00000001b		; enable Autovector feature
	movx	@dptr, a

	mov	dptr, #USBIEN
	movx	a, @dptr
	orl	a, #00000101b		; enable 'Setup Data Available
	movx    @dptr, a		; Interrupt Request' and 'Setup Token
					; Interrupt Request'

	setb	ea			; enable global 8051 Interrupts

loop:
	sjmp	loop


; ========================================= usb interrupt service routines ===

usb_jump_table:
	ljmp	setup_data_avail_isr	; setup data available 
	.db	0		
	ljmp	start_of_frame_isr	; Start of frame
	.db	0
	ljmp	setup_token_isr		; loading setup data
	.db	0
	ljmp	usb_suspend_isr		; USB suspend
	.db	0
	ljmp	usb_reset_isr		; USB reset
	.db	0
	ljmp	spare_isr
	.db	0
	ljmp	ep0_in_isr
	.db	0
	ljmp	ep0_out_isr
	.db	0
	ljmp	ep1_in_isr
	.db	0
	ljmp	ep1_out_isr
	.db	0
	ljmp	ep2_in_isr
	.db	0
	ljmp	ep2_out_isr
	.db	0
	ljmp	ep3_in_isr
	.db	0
	ljmp	ep3_out_isr
	.db	0
	ljmp	ep4_in_isr
	.db	0
	ljmp	ep4_out_isr
	.db	0
	ljmp	ep5_in_isr
	.db	0
	ljmp	ep5_out_isr
	.db	0
	ljmp	ep6_in_isr
	.db	0
	ljmp	ep6_out_isr
	.db	0
	ljmp	ep7_in_isr
	.db	0
	ljmp	ep7_out_isr
	.db	0

setup_data_avail_isr:
	push	acc
	push	dph
	push	dpl
	push	dph1
	push	dpl1
	push	dps
	mov	a, EXIF
	clr	acc.4			; clear USB Interrupt Request
	mov	EXIF, a
	mov	dptr, #USBIRQ
	mov	a, #00000001b		; Setup Data Avail. Interrupt Request
	movx	@dptr, a
	pop	dps
	pop	dpl1
	pop	dph1
	pop	dpl
	pop	dph
	pop	acc
	reti

start_of_frame_isr:
	push	acc
	push	dph
	push	dpl
	push	dph1
	push	dpl1
	push	dps
	mov	a, EXIF
	clr	acc.4			; clear USB Interrupt Request
	mov	EXIF, a
	mov	dptr, #USBIRQ
	mov	a, #00000010b		; Start of frame Interrupt Request
	movx	@dptr, a
	pop	dps
	pop	dpl1
	pop	dph1
	pop	dpl
	pop	dph
	pop	acc
	reti

setup_token_isr:
	push	acc
	push	dph
	push	dpl
	push	dph1
	push	dpl1
	push	dps
	mov	a, EXIF
	clr	acc.4			; clear USB Interrupt Request
	mov	EXIF, a
	mov	dptr, #USBIRQ
	mov	a, #00000100b		; Setup Token Interrupt Request
	movx	@dptr, a
	pop	dps
	pop	dpl1
	pop	dph1
	pop	dpl
	pop	dph
	pop	acc
	reti

usb_suspend_isr:
	push	acc
	push	dph
	push	dpl
	push	dph1
	push	dpl1
	push	dps
	mov	a, EXIF
	clr	acc.4			; clear USB Interrupt Request
	mov	EXIF, a
	mov	dptr, #USBIRQ
	mov	a, #00001000b		; USB Suspend Interrupt Request
	movx	@dptr, a
	pop	dps
	pop	dpl1
	pop	dph1
	pop	dpl
	pop	dph
	pop	acc
	reti

usb_reset_isr:
	push	acc
	push	dph
	push	dpl
	push	dph1
	push	dpl1
	push	dps
	mov	a, EXIF
	clr	acc.4			; clear USB Interrupt Request
	mov	EXIF, a
	mov	dptr, #USBIRQ
	mov	a, #00010000b		; USB Reset Interrupt Request
	movx	@dptr, a
	pop	dps
	pop	dpl1
	pop	dph1
	pop	dpl
	pop	dph
	pop	acc
	reti
	
spare_isr:
	reti
ep0_in_isr:
	reti
ep0_out_isr:
	reti
ep1_in_isr:
	reti
ep1_out_isr:
	reti
ep2_in_isr:
	reti
ep2_out_isr:
	reti
ep3_in_isr:
	reti
ep3_out_isr:
	reti
ep4_in_isr:
	reti
ep4_out_isr:
	reti
ep5_in_isr:
	reti
ep5_out_isr:
	reti
ep6_in_isr:
	reti
ep6_out_isr:
	reti
ep7_in_isr:
	reti
ep7_out_isr:
	reti
