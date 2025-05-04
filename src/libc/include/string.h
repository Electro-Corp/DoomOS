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


static int strncmp(const char* str1, const char* str2, int num) {
	for (int i = 0; i < num; i++) {
		if (*(str1 + i) != *(str2 + i)) {
			if (*(str1) > *(str2)) return -1;
			if (*(str1) < *(str2)) return 1;
		}
	}
	return 0;
}


static char* strcat(char *dst, const char *src){
	int n = strlen(src);
	if (n != 0) {
		char *d = dst;
		const char *s = src;
		while (*d != 0)
			d++;
		do {
			if ((*d = *s++) == 0)
				break;
			d++;
		} while (--n != 0);
		*d = 0;
	}
	return (dst);
}
  
static char* strcpy(char *dst, const char *src){
	int n = strlen(src);
	if (n != 0) {
		char *d = dst;
		const char *s = src;
		do {
			if((*d++ = *s++) == 0) {
				/* NUL pad the remaining n-1 bytes */
				while(--n != 0)
					*d++ = 0;
				break;
			}
		}while (--n != 0);
	}
	return (dst);
}
  
static int strcmp(const char *s1, const char *s2){
	while (*s1 == *s2++)
		if (*s1++ == 0)
			return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}

static int strcasecmp(const char* s1, const char* s2) {
	return strcmp(s1, s2); // tmp hack
}
static int strncasecmp(const char* s1, const char* s2, int b) {
	return strncmp(s1, s2, b); // tmp hack
}
#endif