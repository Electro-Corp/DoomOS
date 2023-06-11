#ifndef HD_C
#define HD_C
#include "../../libc/include/stdlib.h"
#include "../../libc/include/string.h"
#include "../../libc/include/stdio.h"

/*
*	Hard drive controller for DoomOS
* or any other os that uses it i guess
* since DoomOS only runs doom, IO functions (outb, inb) are located here 
* because no other part of the OS needs them right now
* 
* from https://wiki.osdev.org/ATAPI 
*/

// IO
// read from port
unsigned char inb(unsigned short _port)
{
	unsigned char rv;
	__asm__ __volatile__("inb %1, %0" : "=a" (rv) : "dN" (_port));
	return rv;
}
// write to port
void outb(unsigned short _port, unsigned char _data)
{
	__asm__ __volatile__("outb %1, %0" : : "dN" (_port), "a" (_data));
}




static __inline void insw(uint16_t __port, void* __buf, unsigned long __n) {
	__asm__ __volatile__("cld; rep; insw"
		: "+D"(__buf), "+c"(__n)
		: "d"(__port));
}

static __inline__ void outsw(uint16_t __port, const void* __buf, unsigned long __n) {
	__asm__ __volatile__("cld; rep; outsw"
		: "+S"(__buf), "+c"(__n)
		: "d"(__port));
}

#define DATA 0
#define ERROR_R 1
#define SECTOR_COUNT 2
#define LBA_LOW 3
#define LBA_MID 4
#define LBA_HIGH 5
#define DRIVE_SELECT 6
#define COMMAND_REGISTER 7

// Control register defines
#define CONTROL 0x206

#define ALTERNATE_STATUS 0

static void ata_io_wait(const uint8_t p) {
	inb(p + CONTROL + ALTERNATE_STATUS);
	inb(p + CONTROL + ALTERNATE_STATUS);
	inb(p + CONTROL + ALTERNATE_STATUS);
	inb(p + CONTROL + ALTERNATE_STATUS);
}


int read_cdrom(uint16_t port, int slave, uint32_t lba, uint32_t sectors, uint16_t* buffer) {
#
	t_debug("[read_cdrom] called...");
	// The command
	volatile uint8_t read_cmd[12] = { 0xA8, 0,
									 (lba >> 0x18) & 0xFF, (lba >> 0x10) & 0xFF, (lba >> 0x08) & 0xFF,
									 (lba >> 0x00) & 0xFF,
									 (sectors >> 0x18) & 0xFF, (sectors >> 0x10) & 0xFF, (sectors >> 0x08) & 0xFF,
									 (sectors >> 0x00) & 0xFF,
									 0, 0 };

	outb(port + DRIVE_SELECT, 0xA0 & (slave << 4)); 
	ata_io_wait(port);
	outb(port + ERROR_R, 0x00);
	outb(port + LBA_MID, 2048 & 0xFF);
	outb(port + LBA_HIGH, 2048 >> 8);
	outb(port + COMMAND_REGISTER, 0xA0); 
	ata_io_wait(port); 
	t_debug("[read_cdrom] waiting for status");
	/*int i = 0, portToTry = 0x1f0, good = 0, itrs = 0;
	while (portToTry <= 0x1F7 || good == 1) {
		char portTmp[5];
		char portd[35] = "Testing: ";
		itoa(portToTry, portTmp, 5, 10);
		strcat(portd, portTmp);
		t_out(portd);
		while (i++ < 10000000) {
			uint8_t status = inb(portToTry + COMMAND_REGISTER);
			if ((status & 0x01) == 1) {
				good = 0;
				t_out("Failed.");
				break;
				//return 1;
			}
			if (!(status & 0x80) && (status & 0x08)) {
				good = 1;
				break;
			}
			ata_io_wait(portToTry);
		}
		if (i > 10000000) {
			t_out("Timed out.");
		}
		i = 0;
		portToTry++;
		itrs++;
	}
	char debugTmp[5];
	char debugFull[256] = "Ran through: ";
	itoa(itrs, debugTmp, 5, 10);
	strcat(debugFull, debugTmp);
	t_out(debugFull);
	*/

	while (1) {
		uint8_t status = inb(port + COMMAND_REGISTER);
/*		char debugTmp[5];
		char debugFull[256] = "Status: ";
		itoa(status, debugTmp, 5, 10);
		strcat(debugFull, debugTmp);
		t_sameline(debugFull);*/
		if ((status & 0x01) == 1) {
			return 1;
		}
		if (!(status & 0x80) && (status & 0x08))
			break;
		ata_io_wait(port);
	}


	//
	t_debug("[read_cdrom] sending command...");
	outsw(port + DATA, (uint16_t*)read_cmd, 6);
	t_debug("[read_cdrom] read data back...");
	for (uint32_t i = 0; i < sectors; i++) {
		while (1) {
			uint8_t status = inb(port + COMMAND_REGISTER);
			if (status & 0x01)
				return 1;
			if (!(status & 0x80) && (status & 0x08))
				break;
		}

		int size = inb(port + LBA_HIGH) << 8
			| inb(port + LBA_MID); 

		insw(port + DATA, (uint16_t*)((uint8_t*)buffer + i * 0x800), size / 2); 
	}
	t_debug("[read_cdrom] read finished. thank you");
	return 0;
}

#endif