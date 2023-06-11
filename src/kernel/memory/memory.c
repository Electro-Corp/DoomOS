/*
* Memory managment and paging for DoomOS
*/
#ifndef MEMORY_C
#define MEMORY_C

// paging

void initPageDirectory() {
	t_out("Init Page Directory...");
	__asm__("mov %eax, 0x0\n\t"
			"mov %ebx, 0x100000\n\t"
			);
}

void enablePaging() {
	// create page directory
	initPageDirectory();

	//__asm__("mov %eax, page_directory\n");
	__asm__("mov %cr3, %eax\n");
	__asm__("mov %eax, %cr0\n");
	__asm__("or %eax, 0x80000001\n");
	__asm__("mov %cr0, %eax\n");

	// enable 4 mib pages
	__asm__("mov %eax, %cr4\n");
	__asm__("or %eax, 0x00000010\n");
	__asm__("mov %cr4, %eax\n");
}


#endif