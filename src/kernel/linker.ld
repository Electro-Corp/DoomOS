ENTRY(_start)


SECTIONS{
	/*sections start at 1mib*/
	. = 1M;
	
	.text BLOCK(4K) : ALIGN(4K){
		. = ALIGN(8);
		KEEP(*(.multiboot))
		/**(.multiboot)*/
		*(.text)
	}
	.rodata BLOCK(4K) : ALIGN(4K){
		*(.rodata)
	}
	.data BLOCK(4K) : ALIGN(4K){
		*(.data)
	}
	.bss BLOCK(4K) : ALIGN(4K){
		*(COMMON)
		*(.bss)
	}
}