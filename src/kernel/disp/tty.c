#ifndef TTY_C
#define TTY_C
#include "../../libc/include/string.h"
//
#define VGA_W 80
#define VGA_H 25


//
static int trow;
static int tcol;
static char* const videoMem = (char*)0xB8000;

void t_init() {
	trow = 0;
	tcol = 0;
	for (int y = 0; y < VGA_H; y++) {
		for (int x = 0; x < VGA_W; x++) {
			t_putAt(' ', x, y);
		}
	}
}

void t_scroll() {
	for (int y = 1; y < VGA_H; y++) {
		for (int x = 0; x < VGA_W; x++) {
			videoMem[2 * x + 160 * (y - 1)] = videoMem[2 * x + 160 * y];
			videoMem[(2 * x + 160 * (y - 1)) + 1] = videoMem[(2 * x + 160 * y) + 1];
		}
	}

	for (int x = 0; x < VGA_W; x++) {
		t_putAt(' ', x, VGA_H - 1);
	}
	trow = VGA_H;
}

void t_delLastLine() {
	int x, *ptr;
	for (x = 0; x < VGA_W * 2; x++) {
		ptr = 0xB8000 + (VGA_W * 2) * (VGA_H - 1) + x;
		*ptr = 0;
	}
}


void t_putAt(unsigned char c, int x, int y) {
	videoMem[2 * x + 160 * y] = c;
	videoMem[(2 * x + 160 * y) + 1] = 0xC;
}

void t_out(char* data) {
	for (int i = 0; i < strlen(data); i++) {
		t_putAt(data[i], tcol++, trow);
	}
	trow++;
	if (trow > VGA_H) t_scroll();
	tcol = 0;
}
#endif