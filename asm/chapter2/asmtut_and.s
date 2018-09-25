.global _start

/* Logical operation 
Instructtion <destination>, <opreand> <operand> */

_start:
    mov r1, #5 @0101
    mov r2, #9 @1001
    and r0, r1, r2

end:
    mov r7, #1
    swi 0
