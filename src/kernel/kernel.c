#include "disp/tty.c"
#include "controller/file.h"
#include "multiboot2.h"
void main(unsigned long magic, unsigned long addr) {
	t_init();
	// print out terminal stuff before we launch doom
	t_out("=======================");
	/*t_out("______           ___  ________ _____ ");
	t_out("|  _  \          |  \/  |  _  /  ___|");
	t_out("| | | |___   ___ | .  . | | | \ `--.");
	t_out("| | | / _ \ / _ \| |\/| | | | |`--. \ ");
	t_out("| |/ / (_) | (_) | |  | \ \_/ /\__/ /");
	t_out("|___/ \___/ \___/\_|  |_/\___/\____/ ");*/

	t_out("         Doom Os");
	t_out("          V0.1");
	t_out("=======================");

	// read module
	struct multiboot_tag* tag;
	unsigned size;
	size = *(unsigned*)addr;
	for (tag = (struct multiboot_tag*)(addr + 8); tag->type != MULTIBOOT_TAG_TYPE_END; tag = (struct multiboot_tag*)((multiboot_uint8_t*)tag + ((tag->size + 7) & ~7))) {
		t_out("ran");
		switch (tag->type) {
			case MULTIBOOT_TAG_TYPE_MODULE:
				t_out("Module: ");
				t_out(((struct multiboot_tag_module*)tag)->cmdline);
				break;
			case MULTIBOOT_TAG_TYPE_BOOT_LOADER_NAME:
				t_out("Bootloader: ");
				t_out(((struct multiboot_tag_string*)tag)->string);
				break;
			case MULTIBOOT_TAG_TYPE_END:
				t_out("MULTIBOOT_TAG_TYPE_END");
				break;
			case MULTIBOOT_TAG_TYPE_BOOTDEV:
				t_out("MULTIBOOT_TAG_TYPE_BOOTDEV");
				break;
			case MULTIBOOT_TAG_TYPE_CMDLINE:
				t_out("MULTIBOOT_TAG_TYPE_CMDLINE");
				break;
			case MULTIBOOT_TAG_TYPE_MMAP:
				t_out("MULTIBOOT_TAG_TYPE_MMAP");
				break;
			case MULTIBOOT_TAG_TYPE_FRAMEBUFFER:
				t_out("MULTIBOOT_TAG_TYPE_FRAMEBUFFER");
				break;

			default:
				t_out("Idk: ");
				char t[200];
				itoa(tag->type, t, 200, 10);
				t_out(t);
				break;
		}
	}
	mountBootDrive();
	//t_out("Init FS, Test read WAD From boot medium...");
	//t_out("Test results: [not finished] ");
	t_out("DoomOS: Init complete.");
	t_out("DoomOS: Launching Doom...");
	t_out("=====================================");
	Launchmain();
}