.global _start

@ r0 = 0
@ r1 = 1
@ while(r0 <= 10):
@    r0 = r0 +1

_start:
    mov r0, #0 @1001
    mov r1, #1 @1000
    b _continue_loop

_loop:
    add r0, r0, r1

_continue_loop:
    cmp r0, #9
    ble _loop

end:
    mov r7, #1
    swi 0
