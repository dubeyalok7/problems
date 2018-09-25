.global _start

@	EQ : Z Set
@	NE : Z Not Set
@	CS : Carry Set
@	CC : Carry Not Set
@	MI : Negative Set
@	PL : Negative Not Set
@	VS : Overflow Set
@	VC : Overflow Not Set
@	HI : Carry & !Zero
@	LS : !Carry & Zero
@	GE : Negative == Overflow
@	LT : Negative != Overflow
@	GT : !Zero && Negative = Overflow
@	LE : Zero || Negative != V


@ r0 = 50
@ r1 = 2
@ while(r0 > r1):
@    r0 = r0 - 2

_start:
    mov r0, #50 @1001
    mov r1, #2 @1000
    b _loop

_decrement:
    subgt r0, r0, r1


_loop:
    cmp r0, r1
    bne _decrement

end:
    mov r7, #1
    swi 0
