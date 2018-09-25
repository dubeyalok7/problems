@Comments
/* take input of 12 char print 5 char on console*/
/* <intruction> <dest>, <operand>, <operand> */
/* cmp instruction CMP r1, r2 */
.text

.global _start

_start:
	mov r1, #5
	mov r2, #10
	cmp r1, r2
	beq val_equal
	bgt r1_gt
r1_lt:	
	mov r0, #2
	b end

r1_gt:
	mov r0, #3
	b end

val_equal:
	mov r0, #1

end:
	mov r7, #1
	swi 0
