@Comments
/* take input of 12 char print 5 char on console*/
/* <intruction> <dest>, <operand>, <operand> */

.text

.global _start
_start:
	mov r1, #0x14
	mov r2, #0xa 
	mov r3, #0x5
	mla r0, r1, r2, r3
	mov r7, #1
	swi 0
