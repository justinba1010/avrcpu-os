
test.bin:     file format elf32-avr


Disassembly of section .text:

00000000 <__vectors>:
   0:	0c 94 46 00 	jmp	0x8c	; 0x8c <__ctors_end>
   4:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
   8:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
   c:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  10:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  14:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  18:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  1c:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  20:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  24:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  28:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  2c:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  30:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  34:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  38:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  3c:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  40:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  44:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  48:	0c 94 b3 00 	jmp	0x166	; 0x166 <__vector_18>
  4c:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  50:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  54:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  58:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  5c:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  60:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  64:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  68:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  6c:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  70:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  74:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  78:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  7c:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  80:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  84:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>
  88:	0c 94 65 00 	jmp	0xca	; 0xca <__bad_interrupt>

0000008c <__ctors_end>:
  8c:	11 24       	eor	r1, r1
  8e:	1f be       	out	0x3f, r1	; 63
  90:	cf ef       	ldi	r28, 0xFF	; 255
  92:	d0 e4       	ldi	r29, 0x40	; 64
  94:	de bf       	out	0x3e, r29	; 62
  96:	cd bf       	out	0x3d, r28	; 61

00000098 <__do_copy_data>:
  98:	11 e0       	ldi	r17, 0x01	; 1
  9a:	a0 e0       	ldi	r26, 0x00	; 0
  9c:	b1 e0       	ldi	r27, 0x01	; 1
  9e:	ec e2       	ldi	r30, 0x2C	; 44
  a0:	f2 e0       	ldi	r31, 0x02	; 2
  a2:	00 e0       	ldi	r16, 0x00	; 0
  a4:	0b bf       	out	0x3b, r16	; 59
  a6:	02 c0       	rjmp	.+4      	; 0xac <__do_copy_data+0x14>
  a8:	07 90       	elpm	r0, Z+
  aa:	0d 92       	st	X+, r0
  ac:	a0 33       	cpi	r26, 0x30	; 48
  ae:	b1 07       	cpc	r27, r17
  b0:	d9 f7       	brne	.-10     	; 0xa8 <__do_copy_data+0x10>

000000b2 <__do_clear_bss>:
  b2:	22 e0       	ldi	r18, 0x02	; 2
  b4:	a0 e3       	ldi	r26, 0x30	; 48
  b6:	b1 e0       	ldi	r27, 0x01	; 1
  b8:	01 c0       	rjmp	.+2      	; 0xbc <.do_clear_bss_start>

000000ba <.do_clear_bss_loop>:
  ba:	1d 92       	st	X+, r1

000000bc <.do_clear_bss_start>:
  bc:	a6 33       	cpi	r26, 0x36	; 54
  be:	b2 07       	cpc	r27, r18
  c0:	e1 f7       	brne	.-8      	; 0xba <.do_clear_bss_loop>
  c2:	0e 94 05 01 	call	0x20a	; 0x20a <main>
  c6:	0c 94 14 01 	jmp	0x228	; 0x228 <_exit>

000000ca <__bad_interrupt>:
  ca:	0c 94 00 00 	jmp	0	; 0x0 <__vectors>

000000ce <keyboardDriver>:
  ce:	81 e0       	ldi	r24, 0x01	; 1
  d0:	82 b9       	out	0x02, r24	; 2
  d2:	88 b1       	in	r24, 0x08	; 8
  d4:	88 23       	and	r24, r24
  d6:	99 f1       	breq	.+102    	; 0x13e <keyboardDriver+0x70>
  d8:	88 b1       	in	r24, 0x08	; 8
  da:	92 e0       	ldi	r25, 0x02	; 2
  dc:	92 b9       	out	0x02, r25	; 2
  de:	98 b1       	in	r25, 0x08	; 8
  e0:	99 23       	and	r25, r25
  e2:	11 f0       	breq	.+4      	; 0xe8 <keyboardDriver+0x1a>
  e4:	88 b1       	in	r24, 0x08	; 8
  e6:	88 5f       	subi	r24, 0xF8	; 248
  e8:	94 e0       	ldi	r25, 0x04	; 4
  ea:	92 b9       	out	0x02, r25	; 2
  ec:	98 b1       	in	r25, 0x08	; 8
  ee:	99 23       	and	r25, r25
  f0:	11 f0       	breq	.+4      	; 0xf6 <keyboardDriver+0x28>
  f2:	88 b1       	in	r24, 0x08	; 8
  f4:	80 5f       	subi	r24, 0xF0	; 240
  f6:	98 e0       	ldi	r25, 0x08	; 8
  f8:	92 b9       	out	0x02, r25	; 2
  fa:	98 b1       	in	r25, 0x08	; 8
  fc:	99 23       	and	r25, r25
  fe:	11 f0       	breq	.+4      	; 0x104 <keyboardDriver+0x36>
 100:	88 b1       	in	r24, 0x08	; 8
 102:	88 5e       	subi	r24, 0xE8	; 232
 104:	90 e1       	ldi	r25, 0x10	; 16
 106:	92 b9       	out	0x02, r25	; 2
 108:	98 b1       	in	r25, 0x08	; 8
 10a:	99 23       	and	r25, r25
 10c:	11 f0       	breq	.+4      	; 0x112 <keyboardDriver+0x44>
 10e:	88 b1       	in	r24, 0x08	; 8
 110:	80 5e       	subi	r24, 0xE0	; 224
 112:	90 e2       	ldi	r25, 0x20	; 32
 114:	92 b9       	out	0x02, r25	; 2
 116:	98 b1       	in	r25, 0x08	; 8
 118:	99 23       	and	r25, r25
 11a:	11 f0       	breq	.+4      	; 0x120 <keyboardDriver+0x52>
 11c:	88 b1       	in	r24, 0x08	; 8
 11e:	88 5d       	subi	r24, 0xD8	; 216
 120:	88 23       	and	r24, r24
 122:	a1 f0       	breq	.+40     	; 0x14c <keyboardDriver+0x7e>
 124:	90 91 33 02 	lds	r25, 0x0233	; 0x800233 <charBufferIndex>
 128:	a9 2f       	mov	r26, r25
 12a:	b0 e0       	ldi	r27, 0x00	; 0
 12c:	ae 5c       	subi	r26, 0xCE	; 206
 12e:	be 4f       	sbci	r27, 0xFE	; 254
 130:	88 30       	cpi	r24, 0x08	; 8
 132:	39 f4       	brne	.+14     	; 0x142 <keyboardDriver+0x74>
 134:	91 50       	subi	r25, 0x01	; 1
 136:	90 93 33 02 	sts	0x0233, r25	; 0x800233 <charBufferIndex>
 13a:	1c 92       	st	X, r1
 13c:	08 95       	ret
 13e:	80 e0       	ldi	r24, 0x00	; 0
 140:	cc cf       	rjmp	.-104    	; 0xda <keyboardDriver+0xc>
 142:	9f 5f       	subi	r25, 0xFF	; 255
 144:	90 93 33 02 	sts	0x0233, r25	; 0x800233 <charBufferIndex>
 148:	8c 93       	st	X, r24
 14a:	08 95       	ret
 14c:	00 00       	nop
 14e:	08 95       	ret

00000150 <reset>:
 150:	10 92 31 01 	sts	0x0131, r1	; 0x800131 <syncFlag>
 154:	10 92 35 02 	sts	0x0235, r1	; 0x800235 <imageFrame+0x1>
 158:	10 92 34 02 	sts	0x0234, r1	; 0x800234 <imageFrame>
 15c:	10 92 32 02 	sts	0x0232, r1	; 0x800232 <DRIVER_LINE>
 160:	10 92 33 02 	sts	0x0233, r1	; 0x800233 <charBufferIndex>
 164:	08 95       	ret

00000166 <__vector_18>:
 166:	f8 94       	cli
 168:	e0 91 34 02 	lds	r30, 0x0234	; 0x800234 <imageFrame>
 16c:	f0 91 35 02 	lds	r31, 0x0235	; 0x800235 <imageFrame+0x1>
 170:	f0 5d       	subi	r31, 0xD0	; 208
 172:	80 91 31 01 	lds	r24, 0x0131	; 0x800131 <syncFlag>
 176:	88 23       	and	r24, r24
 178:	29 f0       	breq	.+10     	; 0x184 <__vector_18+0x1e>
 17a:	80 91 32 02 	lds	r24, 0x0232	; 0x800232 <DRIVER_LINE>
 17e:	81 50       	subi	r24, 0x01	; 1
 180:	80 93 32 02 	sts	0x0232, r24	; 0x800232 <DRIVER_LINE>
 184:	2e ef       	ldi	r18, 0xFE	; 254
 186:	8f ef       	ldi	r24, 0xFF	; 255
 188:	3e ee       	ldi	r19, 0xEE	; 238
 18a:	4f ee       	ldi	r20, 0xEF	; 239
 18c:	90 91 32 02 	lds	r25, 0x0232	; 0x800232 <DRIVER_LINE>
 190:	9c 34       	cpi	r25, 0x4C	; 76
 192:	38 f4       	brcc	.+14     	; 0x1a2 <__vector_18+0x3c>
 194:	01 91       	ld	r16, Z+
 196:	03 60       	ori	r16, 0x03	; 3
 198:	0b b9       	out	0x0b, r16	; 11
 19a:	8b b9       	out	0x0b, r24	; 11
 19c:	2b b9       	out	0x0b, r18	; 11
 19e:	8b b9       	out	0x0b, r24	; 11
 1a0:	2d c0       	rjmp	.+90     	; 0x1fc <__vector_18+0x96>
 1a2:	9c 34       	cpi	r25, 0x4C	; 76
 1a4:	79 f4       	brne	.+30     	; 0x1c4 <__vector_18+0x5e>
 1a6:	90 91 31 01 	lds	r25, 0x0131	; 0x800131 <syncFlag>
 1aa:	99 23       	and	r25, r25
 1ac:	29 f0       	breq	.+10     	; 0x1b8 <__vector_18+0x52>
 1ae:	2b b9       	out	0x0b, r18	; 11
 1b0:	8b b9       	out	0x0b, r24	; 11
 1b2:	10 92 31 01 	sts	0x0131, r1	; 0x800131 <syncFlag>
 1b6:	22 c0       	rjmp	.+68     	; 0x1fc <__vector_18+0x96>
 1b8:	8f ef       	ldi	r24, 0xFF	; 255
 1ba:	80 93 31 01 	sts	0x0131, r24	; 0x800131 <syncFlag>
 1be:	0e 94 67 00 	call	0xce	; 0xce <keyboardDriver>
 1c2:	23 c0       	rjmp	.+70     	; 0x20a <main>
 1c4:	91 35       	cpi	r25, 0x51	; 81
 1c6:	68 f4       	brcc	.+26     	; 0x1e2 <__vector_18+0x7c>
 1c8:	90 91 31 01 	lds	r25, 0x0131	; 0x800131 <syncFlag>
 1cc:	99 23       	and	r25, r25
 1ce:	29 f0       	breq	.+10     	; 0x1da <__vector_18+0x74>
 1d0:	3b b9       	out	0x0b, r19	; 11
 1d2:	4b b9       	out	0x0b, r20	; 11
 1d4:	10 92 31 01 	sts	0x0131, r1	; 0x800131 <syncFlag>
 1d8:	11 c0       	rjmp	.+34     	; 0x1fc <__vector_18+0x96>
 1da:	8f ef       	ldi	r24, 0xFF	; 255
 1dc:	80 93 31 01 	sts	0x0131, r24	; 0x800131 <syncFlag>
 1e0:	14 c0       	rjmp	.+40     	; 0x20a <main>
 1e2:	9c 35       	cpi	r25, 0x5C	; 92
 1e4:	48 f4       	brcc	.+18     	; 0x1f8 <__vector_18+0x92>
 1e6:	90 91 31 01 	lds	r25, 0x0131	; 0x800131 <syncFlag>
 1ea:	99 23       	and	r25, r25
 1ec:	39 f0       	breq	.+14     	; 0x1fc <__vector_18+0x96>
 1ee:	2b b9       	out	0x0b, r18	; 11
 1f0:	8b b9       	out	0x0b, r24	; 11
 1f2:	10 92 31 01 	sts	0x0131, r1	; 0x800131 <syncFlag>
 1f6:	02 c0       	rjmp	.+4      	; 0x1fc <__vector_18+0x96>
 1f8:	10 92 32 02 	sts	0x0232, r1	; 0x800232 <DRIVER_LINE>
 1fc:	78 94       	sei
 1fe:	90 91 32 02 	lds	r25, 0x0232	; 0x800232 <DRIVER_LINE>
 202:	9f 5f       	subi	r25, 0xFF	; 255
 204:	90 93 32 02 	sts	0x0232, r25	; 0x800232 <DRIVER_LINE>
 208:	c1 cf       	rjmp	.-126    	; 0x18c <__vector_18+0x26>

0000020a <main>:
 20a:	85 b5       	in	r24, 0x25	; 37
 20c:	82 60       	ori	r24, 0x02	; 2
 20e:	85 bd       	out	0x25, r24	; 37
 210:	ae e6       	ldi	r26, 0x6E	; 110
 212:	b0 e0       	ldi	r27, 0x00	; 0
 214:	8c 91       	ld	r24, X
 216:	81 60       	ori	r24, 0x01	; 1
 218:	8c 93       	st	X, r24
 21a:	10 92 32 02 	sts	0x0232, r1	; 0x800232 <DRIVER_LINE>
 21e:	80 91 02 01 	lds	r24, 0x0102	; 0x800102 <asciiMap+0x2>
 222:	90 91 03 01 	lds	r25, 0x0103	; 0x800103 <asciiMap+0x3>
 226:	08 95       	ret

00000228 <_exit>:
 228:	f8 94       	cli

0000022a <__stop_program>:
 22a:	ff cf       	rjmp	.-2      	; 0x22a <__stop_program>
