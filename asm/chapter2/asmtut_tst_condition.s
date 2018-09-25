.global _start

_start:
    mov r1, #9 @1001
    mov r2, #8 @1000

    tst r1, r2
    beq _bit_set
    mov r0, #1
    B end;

_bit_set:
    mov r0, #0

end:
    mov r7, #1
    swi 0
