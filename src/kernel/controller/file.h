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


/*
* struct stat {
    dev_t     st_dev;     ID of device containing file
    ino_t     st_ino;     inode number 
    mode_t    st_mode;    protection
    nlink_t   st_nlink;   number of hard links
    uid_t     st_uid;      user ID of owner
    gid_t     st_gid;     group ID of owner 
    dev_t     st_rdev;     device ID (if special file) 
    off_t     st_size;    total size, in bytes 
    blksize_t st_blksize; /blocksize for file system I/O 
    blkcnt_t  st_blocks;  /number of 512B blocks allocated 
    time_t    st_atime;   time of last access 
    time_t    st_mtime;   time of last modification 
    time_t    st_ctime;    time of last status change
};
*/

// internal fs

typedef struct {
	// i could put all of the same 
	// data types on the same line
	// but i want this to be readable
	uint8_t len; //  Length of Directory Record. 
	uint8_t extAttrLen; //  Extended Attribute Record length. 
	uint16_t locOfExt; // Location of extent (LBA) in both-endian format. ( we only use little endian )
	uint16_t dataLen; //  Data length (size of extent) in both-endian format.  ( we only use little endian )
	// time, but we dont care about that
	// file flags ( we dont care )
	uint8_t unitFileSizeInter; // File unit size for files recorded in interleaved mode, zero otherwise. 
	uint8_t fileGapSizeInter; //  Interleave gap size for files recorded in interleaved mode, zero otherwise. 
	// best part
	uint8_t nameLen;
} dirEntry;

#define SECTOR_SIZE 2048
typedef struct {
	char name[32];
	uint8_t attributes;
	uint32_t size;
	uint32_t lba;
} DirectoryRecord;




static void* splitAtCharIndex(const char* string, const char split, int index, char* out) {
	int pos = 0, c = 0;
	char tmp[256];
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] != split) {
			out[c++] = string[i];
		}
		else {
			if (pos == index) return;
			pos++;
			c = 0;
		}
	}
}



static void* readFile(const char* file) {
	// split

	


	// check file existence
#define ROOTOFFSET 156
	// load PVD
	uint8_t pvd[2048];
	int c = read_cdrom(0x1F0, 0, 16, 1, &pvd);
	dirEntry root;
	uint32_t rootLBA, rootExtentLength;
	//rootLBA = (pvd[ROOTOFFSET + 2] & 0xFF) | ((pvd[ROOTOFFSET + 3] << 8) & 0xFF) | ((pvd[ROOTOFFSET + 4] << 16) & 0xFF) | ((pvd[ROOTOFFSET + 5] << 24) & 0xFF);
	//rootExtentLength = (pvd[ROOTOFFSET + 10] & 0xFF) | ((pvd[ROOTOFFSET + 11] << 8) & 0xFF) | ((pvd[ROOTOFFSET + 12] << 16) & 0xFF) | ((pvd[ROOTOFFSET + 13] << 24) & 0xFF);
	uint8_t LBAbytes[] = { pvd[ROOTOFFSET + 2], pvd[ROOTOFFSET + 3], pvd[ROOTOFFSET + 4], pvd[ROOTOFFSET + 5] };
	//uint8_t ExtentBytes[] = { pvd[ROOTOFFSET + 10], pvd[ROOTOFFSET + 11], pvd[ROOTOFFSET + 12], pvd[ROOTOFFSET + 13] };
	rootLBA = little_endian_to_uint32(LBAbytes);
	rootExtentLength = pvd[ROOTOFFSET];//little_endian_to_uint32(ExtentBytes);

	uint32_t newof = (rootLBA);//+ ((rootExtentLength)));

	uint8_t dirEntData[2048];
	c = read_cdrom(0x1F0, 0, newof, 1, &dirEntData);
	int currentpos = 000;
	for (int i = 0; i < 5; i++) {
		

		uint8_t locOfExtent[] = { dirEntData[currentpos + 2], dirEntData[currentpos + 3], dirEntData[currentpos + 4], dirEntData[currentpos + 5] };
		uint32_t loc = little_endian_to_uint32(locOfExtent);

		uint8_t lenBytes[] = { dirEntData[currentpos + 10], dirEntData[currentpos + 11], dirEntData[currentpos + 12], dirEntData[currentpos + 13] };
		uint32_t len = little_endian_to_uint32(lenBytes);

		// Print
		uint8_t nameLength = dirEntData[currentpos + 32];
		char dirName[nameLength + 1];
		for (int i = 0; i < nameLength; i++) {
			dirName[i] = dirEntData[currentpos + 33 + i];
			if (dirName[i] == ';') {
				nameLength = i;
				break;
			}
		}
		dirName[nameLength] = '\0';

		if (nameLength > 1) {
			char split[256];
			splitAtCharIndex(file, '/', 1, split);
			t_debug("GOT DIR: ");
			t_debug(dirName);
			//t_out(split);
			if (strcmp(dirName, split) == 0) {
				char debug[5];
				itoa(i, debug, 5, 10);
				//reverse(debug, 2);
				t_out(debug);

				

				// we're done here. create a file struct and we're off.
				FILE tmp = {handleLen++, loc, len, dirName };
				files[handleLen] = tmp;
				return;
			}
		}

		

		// Next
		currentpos += dirEntData[currentpos];

		
	}
}




/*
* Epic rambling
*
* so like the boot cd is ISO 9660
* so we need to like
* like like load the fs lamo lil c0akfd0 fl
*
* is that enough likes?
*/
/*
// Path Table Entry
typedef struct {
	int extentLoc, parentDirIndex;
	char id[256];

} PathTableEntry;

static void* readFile(const char* file) {
#define ROOTOFFSET 140
	// Path table
	uint8_t pvd[2048];
	int c = read_cdrom(0x1F0, 0, 16, 1, &pvd);
	// get root directorywd
	uint32_t pathTableLBA;
	uint8_t LBAbytes[] = {pvd[ROOTOFFSET], pvd[ROOTOFFSET + 2], pvd[ROOTOFFSET + 3], pvd[ROOTOFFSET + 4] };
	pathTableLBA = little_endian_to_uint32(LBAbytes);
	char debug[5];
	itoa(pathTableLBA, debug, 5, 10);
	reverse(debug, 2);
	t_out(debug);
	// Alright lets read it
	uint8_t pathTable[2048];
	read_cdrom(0x1F0, 0, pathTableLBA, 1, &pathTable);
	char dirName[20];
	for (int i = 0; i < 19; i++) {
		dirName[i] = pathTable[8 + 10 + i];
	}
	t_out(dirName);
}*/
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