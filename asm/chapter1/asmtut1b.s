@Comments
/* take input of 12 char print 5 char on console*/

.text

.global _start

_start:
	mov r7, #3 /*r7 for system call for  keyboard */
	mov r0, #0 /* input stream */
	mov r2, #12 /* allocating 12 bytes*/
	ldr r1, =msg
	swi 0 /* software interrupt */

_write:
	mov r7, #4
	mov r0, #1
	mov r2, #5
	ldr r1, =msg
	swi 0 /* software interrupt */

end:
	mov r7, #1 /* end to terminal */
	swi 0

.data
msg:
.ascii " "
