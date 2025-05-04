/*
    Read from CD
*/
#ifndef CD_H
#define CD_H
#include "../../libc/include/stdlib.h"
#include "../../libc/include/string.h"
#include "../../libc/include/stdio.h"


int read_cdrom(uint16_t port, int slave, uint32_t lba, uint32_t sectors, uint16_t* buffer);
#endif