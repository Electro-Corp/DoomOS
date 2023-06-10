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
#ifndef CTYPE_H
#define CTYPE_H
#include "string.h"
static char* toupper(char* str) {
	char tmp[strlen(str)];
	for (int i = 0; i < strlen(str); i++) {
		tmp[i] = str[i] + 32;
	}
	return tmp;
}

static char* tolower(char* str) {
	char tmp[strlen(str)];
	for (int i = 0; i < strlen(str); i++) {
		tmp[i] = str[i] - 32;
	}
	return tmp;
}

#endif