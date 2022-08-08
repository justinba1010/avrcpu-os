.global add3

; int add3(int x);
add3:
	subi r24, 253 ; adds 3
	ret

.global _pop_stack_change_address

; void _pop_stack_change_address(uint16_t addr);
_pop_stack_change_address:
	cli

