#include "disp/vga.h"
#include "controller/file.h"
#include "multiboot.h"
void main(multiboot_info_t* mbd) {
	initTerminal();
	// print out terminal stuff before we launch doom
	t_out("=======================");
	t_out("         Doom Os");
	t_out("          V0.1");
	t_out("=======================");


	initCDFS();

	/*if (!(mbd->flags >> 6 & 0x1)) {
		t_out("Fatal Error: Invalid Memory Map.");
		asm("hlt");
	}
	// Load memory map
	for (int i = 0; i < mbd->mmap_length; i += sizeof(multiboot_memory_map_t)) {
		multiboot_memory_map_t* mmmt = (multiboot_memory_map_t*)(mbd->mmap_addr + i);
		// inform STDLIB where memory is
		if (mmmt->type == MULTIBOOT_MEMORY_AVAILABLE) {
			MEMORYLOC loc = { mmmt->addr_low, mmmt->addr_high, mmmt->len_low, mmmt->len_high, mmmt->type };
			addMemoryLocation(loc);
		}
	}
	processMemoryMap();
	char debugFull[20] = "Allocated blocks: ";
	char debug[5];
	itoa(blocloc, debug, 5, 10);
	reverse(debug, 2);
	strcat(debugFull, debug);
	t_out(debugFull);*/
	//
	t_out("DoomOS: Init complete.");
	t_out("DoomOS: Launching Doom...");
	t_out("=====================================");
	Launchmain();
}