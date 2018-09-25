@Comments
/* take input of 12 char print 5 char on console*/
/* <intruction> <dest>, <operand>, <operand> */

/* branching of instruction */

.text

.global _start
_start:
	mov r0, #0x14
	b _other
	mov r0, #0xb 
_other:	
	mov r7, #1
	swi 0
