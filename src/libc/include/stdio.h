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
*/

// When the kernel is given control, we find the size and location of memory 

typedef struct {
	uint32_t addr_low, addr_high, length_low, length_high, size;
	int type;
} MEMORYLOC;

static MEMORYLOC memorylocs[15];
static int memPts = 0;

static void addMemoryLocation(MEMORYLOC location) {
	memorylocs[memPts++] = location;
}

// allocate the memory


typedef struct {
#define MEMORY_FREE 0
	int used;

	int adderess, size;

	struct MEM_BLOCK* next;
} MEM_BLOCK;

static MEM_BLOCK blocs[256];
static int blocloc = 0;

static void processMemoryMap() {
	for (int i = 0; i < memPts; i++) {
		uint64_t size = memorylocs[i].length_high << 32 | memorylocs[i].length_low;
		uint64_t loc = memorylocs[i].addr_high << 32 | memorylocs[i].addr_low;
		int constant = 10; // some random constant

		uint64_t offset = 0;
		for (int j = 0; i < size / constant; i++) {
			MEM_BLOCK tmp = { MEMORY_FREE, loc + offset, size / constant, 0};
			offset += loc + offset;
			if (blocloc > 0) {
				// We're not the first block, so we can set the last one to point to us
				blocs[blocloc - 1].next = &tmp;
				blocs[blocloc - 1].adderess = loc + offset;
			}
			blocs[blocloc++] = tmp;
		}
	}
	
}

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