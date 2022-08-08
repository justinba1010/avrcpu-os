#define __SFR_OFFSET  0x00
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif
#include <avr/io.h>
#include <avr/interrupt.h>
.global G_LINES

#define PE_LOW  0b0001;
#define PE_HIGH  0b010;
#define HSYNC  0b0100;
#define VSYNC  0b1000;

; http://tinyvga.com/vga-timing/800x600@60Hz
; 400 x 300
; 50 x 37

; Visible Area:
	; 400 px <- 20 uS = 400 clocks @ 20 MHz
	; 8 clock cycles per 8 bits
; Front Porch <- 1 uS = 20 clocks
	; 20 px
; Sync Pulse <- 3.2 uS = 64 clocks
	; 64 px
; Back Porch <- 2.2 uS = 44 clocks
	; 44 px

; Vertical Timing
	; 600 px <- Visible
	; 1 <- Front Porch
	; 4 <- Vertical Sync
	; 23 <- Back Porch

.macro ONECHAR
; 8 Clock Cycles; Z: address of char data, X: current VRAM position
ld ZL, X+				; 2cc ZL = (X++)
lpm r21, Z			; 3cc *Z
out PORTD, r21	; 1cc Out 8 bits of prog mem line
out PORTB, r19	; 1cc /PE LOW <- Load Pixel Data to Shift
out PORTB, r18 	; 1cc /PE HIGH <- Clock pumps
.endm

.global TIMER0_COMPA_vect
TIMER0_COMPA:
TIMER0_COMPA_vect: ; 7 - 10 cycles to get
	cli
	push r18
	push r19
	push r24
	push r25
	lds r24, G_LINES
	lds r25, G_LINES+1
	adiw r24, 0x01 ; G_LINES++
	; if G_LINES < 602
	cpi r24, 0x5A ; Compare lower
	ldi r18, 0x02 ; 2
	cpc r25, r18  ; compare higher
	brcc G_LINES_OVER_602
	ldi r18, PE_HIGH;
	ldi r19, PE_LOW;
	ONECHAR
	ONECHAR
	ONECHAR
	ONECHAR
	ONECHAR
	rjmp TIMER0_EXIT
	
G_LINES_OVER_602:
	; If lines == 628
	cpi r24, 0x74; Compare lower
	cpc r25, r18 ; Compare higher
	brne G_LINES_NOT_628
	ldi r24, 0 ; G_LINES = 0
	ldi r25, 0 ; G_LINES = 0
	rjmp TIMER0_EXIT
	

G_LINES_NOT_628:
	; If lines < 605
	cpi r24, 0x5D ; compare lower
	cpc r25, r18 ; compare higher
	brcc G_LINES_OVER_605
	rjmp TIMER0_EXIT

G_LINES_UNDER_605:
	; ...
	rjmp TIMER0_EXIT

TIMER0_EXIT:
	sts G_LINES+1, r25
	sts G_LINES, r24
	pop r25
	pop r24
	pop r19
	pop r18
	sei
	reti
