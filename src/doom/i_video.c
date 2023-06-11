/*
  SDL Rewrite of i_video

  because x11 sucks ass imo


  and you know what?
  it works
*/

#include "../libc/include/stdlib.h"
#include "../libc/include/unistd.h"
#ifdef __unix__
#include <sys/ipc.h>
#include <sys/shm.h>
#include <netinet/in.h>
#include <errno.h>
#include <signal.h>
#endif



#include "doomstat.h"
#include "i_system.h"
#include "v_video.h"
#include "m_argv.h"
#include "d_main.h"

#include "doomdef.h"


// debug
//#define VIDEODEBUG 1

// window scaling
#define YSCALEFAC 4
#define XSCALEFAC 4
static int lastmousex = 0, lastmousey = 0;

/*
  Init SDL
*/
void I_InitGraphics(void) {
    // init sdl window
    t_out("I_InitGraphics: Init Graphics...");
}
void I_ReadScreen(byte* src) {
    memcpy(src, screens[0], SCREENWIDTH * SCREENHEIGHT);
}

void I_ShutdownGraphics(void) {
 
}

void I_StartFrame(void) {
    // errrm what the guh
}

/*
  Convert SDL Key to doom key
*/
int translatekey() {

}

// ticks
void I_StartTic() {
    
}

/*
  Sets the color pallete
*/
void I_SetPalette(byte* palette) {
    
}

void I_UpdateNoBlit(void) {

}
void I_FinishUpdate(void) {
    // 
    // such a bad hack
    // revamp mouse

    
}