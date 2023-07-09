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

// Include Kernel Memory Managment functions


// memory functions
static void* memset(void* bufptr, int value, int size) {
	unsigned char* buf = (unsigned char*)bufptr;
	for (int i = 0; i < size; i++)
		buf[i] = (unsigned char)value;
	return bufptr;
}

static void* memcpy(void* restrict dstptr, const void* restrict srcptr, int size) {
	unsigned char* dst = (unsigned char*)dstptr;
	const unsigned char* src = (const unsigned char*)srcptr;
	for (int i = 0; i < size; i++)
		dst[i] = src[i];
	return dstptr;
}

//
static int atoi(const char* str) {
	int num = 0;
	for (int i = 0; str[i] != '\0'; i++)
		num = num * 10 + str[i] - '0';
	return num;
}
//
static int itoa(int num, unsigned char* str, int len, int base){
	int sum = num;
	int i = 0;
	int digit;
	if (len == 0)
		return -1;
	do
	{
		digit = sum % base;
		if (digit < 0xA)
			str[i++] = '0' + digit;
		else
			str[i++] = 'A' + digit - 0xA;
		sum /= base;
	} while (sum && (i < (len - 1)));
	if (i == (len - 1) && sum)
		return -1;
	str[i] = '\0';
	return 0;
}

static int abs(int n) {
	if (n < 0) return n * -1;
	return n;
}


static void exit(int code) {
	asm("hlt");
	// to do:

	// 1. Disable graphics mode

	// 2. print out error code

	// 3. panic
}


#endif