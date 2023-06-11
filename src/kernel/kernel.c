#include "disp/tty.c"
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
	t_out("Initlizing IDE Driver...");
	ide_init(0x1F0, 0x3F6, 0x170, 0x376, 0x000);
	//t_out("Init FS, Test read WAD From boot medium...");
	//t_out("Test results: [not finished] ");
	t_out("DoomOS: Init complete.");
	t_out("DoomOS: Launching Doom...");
	t_out("=====================================");
	Launchmain();
}