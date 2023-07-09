global entry
section .__mbHeader

align 0x4
MAGIC equ 0x1BADB002 
ALIGN_MODULES equ 0x00000001
FLAGS equ 0
SUM equ -(MAGIC + ALIGN_MODULES)

section .text
align 4
        dd MAGIC
        dd ALIGN_MODULES
        dd FLAGS
        dd SUM

CSTACK_SIZE equ 80000 ; This is how big we want our stack to be

entry:
mov esp, cstack + CSTACK_SIZE ; The ESP register holds the current position on the stack

extern main
push ebx
call main

jmp entry 

section .bss:
    
align 16 
cstack:
resb CSTACK_SIZE ; resb == "reserve bytes"