irq_handler: ; 4 cycles
	ld ZL, r30 ; 2
	ld ZH, r31 ; 2
	ijmp ; 2

input_change_handler: ; 4 cycles
	rjmp keyboard_handler

graphics_driver:
	timer_interrupt_handler:
		row
		column
		write_column_data:
			75 rows; 9900 cycles -->
			write_row_data:
				500 cycles ->
					100 x {
					ld r, Z+ ; 2
					ori r, 3 ; Set hsync vsync 1
					out PORTA, r ; 1
					nop ; 1
					}
				25 cycles -> # front porch
				ldi r, 3  ; 1
				out PORTA, r ; 1
				nop x 23
				80 cycles -> # sync
				ldi r, 2 ; 1
				out PORTA, r ; 1
				nop x 78
				55 cycles -> # back porch
				ldi r, 3 ; 1
				out PORTA, r ; 1
				nop x 53
		write_front_porch:
			1 row: 660 cycles --->
				525 cycles -> # data + front porch h
				ldi r, 3 ; 1
				out PORTA, r ; 1
				# MAKE MACRO
				ld r31, low(return_front_porch) ; 1
				ld r30, hi(return_front_porch) ; 1
				set timer to 525 - 18
				reti ; 4
				# 10 instructions return
				return_front_porch:
				80 cycles -> # sync
				ldi r, 2 ; 1
				out PORTA, r ; 1
				nop x 78
				55 cycles -> # back porch
				ldi r, 3 ; 1
				out PORTA, r ; 1
				nop x 53
			write_vsync:
			4 row: 2640 cycles --->
				525 cycles -> # data + front porch h
				ldi r, 2 ; 1
				out PORTA, r ; 1
				nop x 523
				80 cycles -> # hsync
				ldi r, 0 ; 1
				out PORTA, r ; 1
				nop x 78
				55 cycles -> # back porch h
				ldi r, 2 ; 1
				out PORTA, r ; 1
				nop x 53
			back_porch_vsync
			23 row: 15180 cycles --->
				525 cycles ->
				ldi r, 3 ; 1
				out PORTA, r ; 1
				nop x 523
				80 cycles -> # hsync
				ldi r, 2 ; 1
				out PORTA, r ; 1
				nop x 78
				55 cycles -> # back porch h
				ldi r, 3 ; 1
				out PORTA, r ; 1
				nop x 53
