/*
*	DoomOS FS Implementation
*	
*/
#ifndef FILE_H
#define FILE_H


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

typedef struct stat {
	int st_size;
}fileinfo;

static FILE* fopen(char* fileName, char* mode) {
	FILE* tmp;
	return tmp;
}

static int fseek(FILE* stream, long int offset, int whence) {
	return -1;
}
static long int ftell(FILE* stream) {
	return stream->pos;
}
static int fread(void* ptr, int size, int nmemb, FILE* stream) {
	return -1;
}
static int fclose(FILE* stream) {
	return -1;
}
static int fprintf(FILE* stream, char* text, ...) {
	return -1;
}
static int fscanf(FILE* stream, const char* format, ...) {

}
/*
* FS functions
*/
static int access(const char* pathname, int mode) {
	return -1;
}
static int mkdir(const char* path, int mode) {
	return -1;
}
static int FS_open(const char* path, ...) {
	return -1; // replace with handle
}
static int FS_close(int handle) {
	return -1; // remove handle
}
static int read(int handle, void* buf, int count) {
	return -1;
}
static int write(int handle, void* buf, int count) {
	return -1;
}

typedef long int off_t;
static off_t lseek(int handle, off_t offset, int whence) {
	return -1;
}


static int fstat(int fd, struct fileinfo* buf) {
	return -1;
}
static int feof(FILE* stream) {
	return -1;
}
#endif