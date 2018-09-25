.global _start

/* Logical operation 
Instructtion <destination>, <opreand> <operand> */

_start:
    mov r7, #3 @system call
    mov r0, #0 @input stream keyboard
    mov r2, #1 @read 1 char
    ldr r1, =char
    swi 0

uppercase:
    ldr r1, =char
    ldr r0, [r1]

    @a: 0110 0001
    @ : 0010 0000 bit clear
    @A: 0100 0001

    bic r0, r0, #32
    str r0, [r1]

_write:
    mov r7, #4 @syscall output to screen
    mov r0, #1 @output monitor
    mov r2, #1 @ no. of char
    ldr r1, =char
    swi 0

end:
    mov r7, #1
    swi 0

.data
char:
    .ascii " "
