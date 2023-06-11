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
#ifndef STRING_H
#define STRING_H
//#include "ctype.h"
#include "stdlib.h"


static int strlen(char* string) {
	int i = 0;
	while (string[i++]) {}
	return i;
}

static char* strcpy(char* dest, char* src) {
	memcpy(dest, src, strlen(src) + 1);
	return dest;
}

static char* strncpy(char* dest, char* src, int b) {
	for (int i = 0; i < b; i++) {
		*(dest + i) = *(src + i);
	}
	return dest;
}

static int maxlen(const char* str1, const char* str2) {
	if (strlen(str1) > strlen(str2)) return strlen(str1);
	return strlen(str2);
}

static int strcmp(const char* str1, const char* str2) {
	for (int i = 0; i < maxlen(str1, str2); i++) {
		if (*(str1 + i) != *(str2 + i)) {
			if (*(str1) > *(str2)) return -1;
			if (*(str1) < *(str2)) return 1;
		}
	}
	return 0;
}

static int strncmp(const char* str1, const char* str2, int num) {
	for (int i = 0; i < num; i++) {
		if (*(str1 + i) != *(str2 + i)) {
			if (*(str1) > *(str2)) return -1;
			if (*(str1) < *(str2)) return 1;
		}
	}
	return 0;
}

static char* strcat(char* dest, const char* src) {
	for (int i = 0; i < strlen(src); i++) {
		dest[i + (strlen(dest) - 1)] = src[i];
	}
	dest[strlen(dest) + 1] = '\0';
	return dest;
}

static int strcasecmp(const char* s1, const char* s2) {
	return strcmp(s1, s2); // tmp hack
}
static int strncasecmp(const char* s1, const char* s2, int b) {
	return strncmp(s1, s2, b); // tmp hack
}
#endif