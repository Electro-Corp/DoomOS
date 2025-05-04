# Boot for DoomOS - GNU Assembler Syntax
.set ALIGN, 1 << 0
.set MEMINFO, 1 << 1
.set FLAGS, ALIGN | MEMINFO
.set MAGIC, 0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

# multiboot
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM
.long 0x36d76289

.section .bss
.align 16
stack_bottom:
.skip 16384
stack_top:

.section .text
.global _start
.type _start, @function
_start:
	movl $stack_top, %esp

	pushl %ebx
	pushl   %eax
	call main
	cli
1:
	hlt
	jmp 1b
.size _start, . - _start