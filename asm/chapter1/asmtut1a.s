@Comments
/* Multi line */

.text

.global _start

_start:
	mov r7, #4 /*r7 for system call set for console */
	mov r0, #1 /* output stream on monitor */
	mov r2, #12 /* allocating 12 bytes*/
	ldr r1, =msg
	swi 0 /* software interrupt */

end:
	mov r7, #1 /* end to terminal */
	swi 0

.data
msg:
.ascii "Hello World\n"
