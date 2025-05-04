/*
*	DoomOS FS Implementation
*	
*/
#ifndef FILE_H
#define FILE_H
// includes
#include "../../libc/include/stdlib.h"
#include "../../libc/include/string.h"
#include "../../libc/include/stdio.h"


#define SEEK_END 0 
#define SEEK_SET 0

#define O_RDONLY 1
#define O_WRONLY 0
#define O_CREAT 2
#define O_TRUNC 3


typedef struct{
	int handle, pos, dataLen;
	char name[255];
}FILE;

static int handleLen = 0;


static FILE files[255];

static unsigned int addrForWad;




/*static char* reverse(int num) {
	char full[100];
	int i = 0;
	while (num > 0) {
		itoa(num % 10, full[i++], 1, 10);
		num /= 10;
	}
	return full;
}*/

static void reverse(char str[], int length)
{
	int start = 0;
	int end = length - 1;
	while (start < end) {
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
}
static uint32_t little_endian_to_uint32(uint8_t* bytes) {
	uint32_t value = 0;
	for (int i = 0; i < 4; i++) {
		value |= bytes[i] << (i * 8);
	}
	return value;
}
/*
* Read from the Disk and 
* init the ISO 9660 FS
*/
static void* mountBootDrive() {
	// Read volume descriptor 
	uint16_t volumeDesc[2048];
	//
	
	int c = read_cdrom(0x1F0, 0, 16, 1, &volumeDesc);
	//int c = read_cdrom(0x1F0, 0, 0, 1, &vDTC);
	if (c < 0 || c > 0) {
		t_out("The CD-ROM Read operation failed in some way. Doom will not work!");
	}
	else {
		unsigned char* tmp = &volumeDesc[0];
		if (*tmp = 1) {
			t_out("Primary Volume Descriptor found. Loading..");
		}
	}
}

static void fs_SetWadFile(unsigned int memAddr) {
	addrForWad = memAddr;
}


typedef struct stat {
	int st_size;
}fileinfo;

static FILE* fopen(char* fileName, char* mode) {
	FILE* tmp;
	return (void*)0;
}

static int fseek(FILE* stream, long int offset, int whence) {
	return 1;
}
static long int ftell(FILE* stream) {
	return stream->pos;
}
static int fread(void* ptr, int size, int nmemb, FILE* stream) {
	return 1;
}
static int fclose(FILE* stream) {
	return 1;
}
static int fprintf(FILE* stream, char* text, ...) {
	return 1;
}
static int fscanf(FILE* stream, const char* format, ...) {

}
/*
* FS functions
*/
static int access(const char* pathname, int mode) {
	return 1;
}
static int mkdir(const char* path, int mode) {
	return 1;
}

// important functions

static int FS_open(const char* path, ...) {
	t_out("FS_Open called");
	readFile(path);
	return handleLen;
}
static int FS_close(int handle) {
	t_out("FS_Close called");
	return 1; // remove handle 
}
static int read(int handle, void* buf, int count) {
	t_out("we reading bois");
	uint32_t loc = files[handleLen].pos;
	uint32_t size = files[handleLen].dataLen;

	char debug[5];
	itoa(count, debug, 5, 10);
	//reverse(debug, 2);
	t_out(debug);



	//asm("hlt");

	// detemine buffer size
	

	int sec = 1;
	if (count > 2048) {
		sec = count / 2048;
	}

	uint16_t bufAll[sec * 2048];

	int c = read_cdrom(0x1F0, 0, loc, sec, &bufAll);

	memcpy(buf, bufAll, count);

}
static int write(int handle, void* buf, int count) {
	return 1;
}

typedef long int off_t;
static off_t lseek(int handle, off_t offset, int whence) {
	return 1;
}


static int fstat(int fd, struct fileinfo* buf) {
	return 1;
}
static int feof(FILE* stream) {
	return 1;
}
#endif