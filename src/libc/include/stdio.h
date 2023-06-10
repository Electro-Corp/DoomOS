/*
* DOOM OS C Library
* The DoomOS C Library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
*
* idk why you would use it, its so bad
*/
#ifndef STDIO_H
#define STDIO_H
#include "stdarg.h"
// yes yes i know its stdint stuff but whatever
// from https://sites.uclouvain.be/SystInfo/usr/include/stdint.h.html
typedef signed char                int8_t;
typedef short int                int16_t;
typedef int                        int32_t;
typedef long int                int64_t;

typedef unsigned char                uint8_t;
typedef unsigned short int        uint16_t;
typedef unsigned int                uint32_t;
typedef unsigned long int        uint64_t;
typedef long int                intptr_t;

typedef int fixed_t;

static int sprintf(char* str, ...) {
	return 0;
}

static int sscanf(const char* s, const char* format, ...) {
	return 0;
}
static int printf(char* str, ...) {
	t_out(str);
	return 0;
}

/*
* memory (very sad)
* this will be handled in the future
*/

static void* malloc(int size) {
	unsigned char* g;
	return &g;
}
static void* alloca(int size) {
	unsigned char* g;
	return &g;
}
static void* realloc(void* ptr, int size) {
	return;
}
//
#endif