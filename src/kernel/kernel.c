#include "disp/tty.c"
#include "../doom/i_main.c"
//#include "controller/hd.c"
//extern void* get_file(const char* path, size_t* size);
void main() {
	t_init();
	// print out terminal stuff before we launch doom
	t_out("=======================");
	t_out("       DoomOS");
	t_out("=======================");
	t_out("DoomOS: Launching Doom...");
	t_out("=====================================");

	//while(1){}
	//ide_init(0x1F0, 0x3F6, 0x170, 0x376, 0x000);
	Launchmain();
	// launch doom
	
}