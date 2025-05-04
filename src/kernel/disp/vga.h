/*
    Header for VGA
*/
#ifndef VGA_H
#define VGA_H

#include "../../libc/include/stdlib.h"
#include "../../libc/include/string.h"
#include "../../libc/include/stdio.h"

static int row = 0;

// Terminal
void initTerminal();
void kprintf(char*, ...);
void dkprintf(char* string);

// UTILS
void charAt(char c, int x, int y, unsigned char color);

// Compat with my old dogshit tty file
void t_out(char* s){kprintf(s);}
void t_debug(char* s){
#ifdef DEBUG
	t_out(data);
#endif
}

#endif