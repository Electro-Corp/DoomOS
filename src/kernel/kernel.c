#include "disp/tty.c"
#include "controller/file.h"
void main() {
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
	mountBootDrive();
	//t_out("Init FS, Test read WAD From boot medium...");
	//t_out("Test results: [not finished] ");
	t_out("DoomOS: Init complete.");
	t_out("DoomOS: Launching Doom...");
	t_out("=====================================");
	Launchmain();
}