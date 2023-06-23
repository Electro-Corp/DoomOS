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
	char* ptr;
	char* _tmpfname;
	long int pos;
	int fd;
}FILE;



/*
* Epic rambling 
* 
* so like the boot cd is ISO 9660
* so we need to like
* like like load the fs lamo lil c0akfd0 fl
* 
* is that enough likes?
*/

// Path Table Entry
typedef struct {
	int dirIndentifierLen, extAttrRecordLen,
		locationOfExtent, dirNumOfPDir;
	char directoryIdentifier[256];

} PathTableEntry ;


static char* reverse(int num) {
	char full[100];
	int i = 0;
	while (num > 0) {
		itoa(num % 10, full[i++], 1, 10);
		num /= 10;
	}
	return full;
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

		
		/*
		int size;
		size += volumeDesc[132] | (volumeDesc[133] << 8) | (volumeDesc[134] << 16) | (volumeDesc[135] << 24);
		size = 420;

		uint32_t lbaLoc;
		lbaLoc += volumeDesc[140] | (volumeDesc[141] << 8) | (volumeDesc[142] << 16) | (volumeDesc[142] << 24);
		char* f = reverse(size);
		char debugFull[512] = "Path table size: ";
		strcat(debugFull, f);
		t_out(debugFull);

		// what ever, move on
		uint16_t pathTableSys[size];
		int c = read_cdrom(0x1F0, 0, lbaLoc, size / 2000, &pathTableSys);
		if (c < 0 || c > 0) {
			// panic!
		}
		*/
		// load entries

	}
	

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

static void* readFile(const char* file) {
/*#define ROOTOFFSET 156
	// load PVD
	uint16_t pvd[2048];
	int c = read_cdrom(0x1F0, 0, 16, 1, &pvd);
	// get root directorywd
	dirEntry root;
	uint32_t rootLBA, rootExtentLength;
	rootLBA = (pvd[ROOTOFFSET + 2] & 0xFF) | ((pvd[ROOTOFFSET + 3] >> 8) & 0xFF) | ((pvd[ROOTOFFSET + 4] >> 16) & 0xFF) | ((pvd[ROOTOFFSET + 5] >> 24) & 0xFF);
	/*rootLBA |= pvd[ROOTOFFSET + 2] & 0xff;
	rootLBA |= (pvd[ROOTOFFSET + 3] << 8) & 0xFF;
	rootLBA |= (pvd[ROOTOFFSET + 4] << 16) & 0xFF;
	rootLBA |= (pvd[ROOTOFFSET + 5] << 24) & 0xFF;
	
	

	//rootExtentLength += pvd[ROOTOFFSET + 10] | (pvd[ROOTOFFSET + 11] << 8) | (pvd[ROOTOFFSET + 12] << 16) | (pvd[ROOTOFFSET + 13] << 24);
	// load
	uint16_t dirEntData[2048];
	c = read_cdrom(0x1F0, 0, rootLBA, 1, &dirEntData);
	char dirName[dirEntData[32]];
	for (int i = 0; i < dirEntData[32]; i++) {
		dirName[i] = dirEntData[33 + i];
	}
	//t_out(dNum);
	t_out(dirName);*/
}



typedef struct stat {
	int st_size;
}fileinfo;

static FILE* fopen(char* fileName, char* mode) {
	FILE* tmp;
	
	// Load file from system
	

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
	t_out(path);
	
	return -1; // replace with handle
}
static int FS_close(int handle) {
	return 1; // remove handle
}
static int read(int handle, void* buf, int count) {
	return 1;
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