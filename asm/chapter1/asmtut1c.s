@Comments
/* take input of 12 char print 5 char on console*/
/* <intruction> <dest>, <operand>, <operand> */

.text

.global _start
_start:
	mov r1, #0xa 
	add r0, r1, #0x14
	mov r7, #1
	swi 0
