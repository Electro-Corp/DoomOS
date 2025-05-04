/*
    Filesystem handler
    Adapted from an older project of mine: https://github.com/Electro-Corp/T54-OS/blob/main/src/fs.h
*/
#ifndef FILE_H
#define FILE_H

#include "cd.h"

// includes
#include "../../libc/include/stdlib.h"
#include "../../libc/include/string.h"
#include "../../libc/include/stdio.h"

typedef struct {
    // Volume ID
    char CD_volID[32];
} CD_FS;

typedef struct {
    char fileID[256];
    uint32_t locOfExtent;
    uint32_t sizeOfExtent;

    int isDirectory;
} CD_DirectoryEntry;

typedef struct{
	int handle, pos, size;
    CD_DirectoryEntry entry;
	char name[255];
} FILE;

typedef struct stat {
	int st_size;
} fileinfo;

// FS's
static CD_FS rootMedia;

void initFS();

void initCDFS();

int readFile(char* filePath, uint16_t* buffer);

CD_DirectoryEntry* getFile(char* filePath);

int getNumOfDirs();

CD_DirectoryEntry* getDirs();

/*
    UNIX-like file system stuff
*/


#define SEEK_END 0 
#define SEEK_SET 0

#define O_RDONLY 1
#define O_WRONLY 0
#define O_CREAT 2
#define O_TRUNC 3


static int handleLen = 0;

static FILE* fopen(char* fileName, char* mode){

}
static int fseek(FILE* stream, long int offset, int whence){

}
static long int ftell(FILE* stream){}
static int fread(void* ptr, int size, int nmemb, FILE* stream){}
static int fclose(FILE* stream){}
static int fprintf(FILE* stream, char* text, ...){

}
static int fscanf(FILE* stream, const char* format, ...){}
/*
* FS functions
*/
static int access(const char* pathname, int mode){}
static int mkdir(const char* path, int mode){}

// important functions

static int FS_open(const char* path, ...){}
static int FS_close(int handle){}
static int read(int handle, void* buf, int count){}
static int write(int handle, void* buf, int count){}
typedef long int off_t;
static off_t lseek(int handle, off_t offset, int whence){}
static int fstat(int fd, fileinfo* buf){}
static int feof(FILE* stream){}

#endif