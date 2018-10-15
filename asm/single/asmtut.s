/*
.global _start
_start:
  mov r1, #1
  mov r2, #2

  @store 1 in stack pointer, move 4 butes
  @The ! (Write -Back) updates the register so it can be used 
  @for another push onto the stack for example

  str r1, [sp, #-4]!
  str r2, [sp, #-4]!

  @remove the value and ascenf towards the beginning of the stack
  ldr r0, [sp], #+4
  ldr r0, [sp], #+4

end:
  mov r7, #+4
  swi 0
*/

/*
.global _start
_start:
  mov r4, #1
  mov r5, #2

  @ we can refer to the Stack Pointer as SP
  @ decrease SP by 8 bytes and save 4 & r5 in those 8 bytes
  @ The ! (Write-Back) updates the register so it can be used
  @ for another push onto the stack for example

  stmdb SP!, {r4, r5}
  mov r4, #3
  mov r5, #4
  add r0, r4, #0
  add r0, r0 ,r5

  @remove the 8 bytes of data and then increment SP by 8 bytes
  LDMIA SP!, {r4, r5}
  add r0, r0, r4
  add r0, r0, r5

end:
  mov r7, #1
  swi 0
*/

.global _start
_start:
  mov r0, #two

end:
  mov r7, #1
  swi 0

.data
.equ two, 2
