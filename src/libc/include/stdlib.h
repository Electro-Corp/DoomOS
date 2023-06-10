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
#ifndef STDLIB_H
#define STDLIB_H

// memory functions
static void memset(void* ptr, int value, int num) {
	unsigned char* dest = (unsigned char*)ptr;
	for (int i = 0; i < num; i++) {
		*(dest + i) = value;
	}
}

static void memcpy(void* to, const void* src, int num) {
	unsigned char* dest = (unsigned char*)to;
	for (int i = 0; i < num; i++) {
		*(dest + i) = ((unsigned char*)src) + i;
	}
}

//
static int atoi(const char* str) {
	int num = 0;
	for (int i = 0; str[i] != '\0'; i++)
		num = num * 10 + str[i] - '0';
	return num;
}

static int abs(int n) {
	if (n < 0) return n * -1;
	return n;
}


static void exit(int code) {
	// to do:

	// 1. Disable graphics mode

	// 2. print out error code

	// 3. return control to OS
}


#endif