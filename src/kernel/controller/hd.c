#ifndef HD_C
#define HD_C

/*
*	Hard drive controller for DoomOS
* or any other os that uses it i guess
* (pretty bad)
* since DoomOS only runs doom, IO functions (outb, inb) are located here 
* because no other part of the OS needs them right now
* 
* adapted more or less from https://wiki.osdev.org/PCI_IDE_Controller with some fixes
* to make it work
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

void insl(unsigned reg, unsigned int* buffer, int quads)
{
	int index;
	for (index = 0; index < quads; index++)
	{
		buffer[index] = inb(reg);
	}
}
// Status
#define ATA_SR_BSY 0x80 // busy
#define ATA_SR_DRDY 0x40 // Drive ready
#define ATA_SR_DF 0x20 // write fault
#define ATA_SR_DSQ 0x10 // seek complete
#define ATA_SR_DRQ 0x08 // data req ready
#define ATA_SR_CORR 0x04 // corrected data
#define ATA_SR_IDX 0x02 // index
#define ATA_SR_ERR 0x01 // oh no

// Errors
#define ATA_ER_BBK 0x80 // bad bock
#define ATA_ER_UNC 0x40 // uncorrectable data
#define ATA_ER_MC 0x20  // media changed
#define ATA_ER_IDNF 0x10 // ID mark not found
#define ATA_ER_MCR 0x08  // Media change request
#define ATA_ER_ABRT 0x04 // Command aborted
#define ATA_ER_TK0NF 0x02 // Track 0 not found
#define ATA_ER_AMNF 0x01 // No address mark

// Commands
#define ATA_CMD_READ_PIO 0x20
#define ATA_CMD_READ_PIO_EXT 0x24
#define ATA_CMD_READ_DMA 0xC8
#define ATA_CMD_READ_DMA_EXT 0x25
#define ATA_CMD_WRITE_PIO 0x30
#define ATA_CMD_WRITE_PIO_EXT 0x34
#define ATA_CMD_WRITE_DMA 0xCA
#define ATA_CMD_WRITE_DMA_EXT 0x35
#define ATA_CMD_CACHE_FLUSH 0xE7
#define ATA_CMD_CACHE_FLUSH_EXT 0xEA
#define ATA_CMD_PACKET 0xA0
#define ATA_CMD_IDENTIFY_PACKET 0xA1
#define ATA_CMD_IDENTIFY 0xEC

#define ATA_REG_DATA 0x00
#define ATA_REG_ERROR 0x01
#define ATA_REG_FEATURES 0x01
#define ATA_REG_SECCOUNT0 0x02
#define ATA_REG_LBA0 0x03
#define ATA_REG_LBA1 0x04
#define ATA_REG_LBA2 0x05
#define ATA_REG_HDDEVSEL 0x06
#define ATA_REG_COMMAND 0x07
#define ATA_REG_STATUS 0x07
#define ATA_REG_SECCOUNT1 0x08
#define ATA_REG_LBA3 0x09
#define ATA_REG_LBA4 0x0A
#define ATA_REG_LBA5 0x0B
#define ATA_REG_CONTROL 0x0C
#define ATA_REG_ALTSTATUS 0x0C
#define ATA_REG_DEVADDRESS 0x0D


#define IDE_ATA 0x00
#define IDE_ATAPI 0x01

#define ATA_MASTER 0x00
#define ATA_SLAVE 0x01


#define ATA_PRIMARY 0x00
#define ATA_SECONDARY 0x01

// Directions:
#define ATA_READ 0x00
#define ATA_WRITE 0x01


#define ATA_IDENT_DEVICETYPE 0
#define ATA_IDENT_CYLINDERS 2
#define ATA_IDENT_HEADS 6
#define ATA_IDENT_SECTORS 12
#define ATA_IDENT_SERIAL 20
#define ATA_IDENT_MODEL 54
#define ATA_IDENT_CAPABILITIES 98
#define ATA_IDENT_FIELDVALID 106
#define ATA_IDENT_MAX_LBA 120
#define ATA_IDENT_COMMANDSETS 164
#define ATA_IDENT_MAX_LBA_EXT 200

/*
* Ide channel registors
* tells us the start of the IO ports
*/
struct IDEChannelRegs {
	unsigned short base;
	unsigned short ctrl;
	unsigned short bmide;
	unsigned char nIEN;
} channels[2];

// identfy space
unsigned char ide_buf[2048] = { 0 };
volatile unsigned static char ide_irq_invoked = 0;
unsigned static char atapi_packet[12] = { 0xA8, 0, 0,0,0,0,0,0,0,0,0,0 }; 
// device
struct ide_device {
	unsigned char reserv; // 0 (no drive) 1 (drive!)
	unsigned char channel;// 0 (primary) 1 (secondary)
	unsigned char drive; // 0 (master) 1 (slave)
	unsigned short type; // 0 (ata) 1(atapi)
	unsigned short sig;
	unsigned short feat;
	unsigned int commandsets;
	unsigned int size;
	unsigned char model[41];
} ide_devs[4];

// 
unsigned char ide_read(unsigned char channel, unsigned char reg) {
	unsigned char result;
	if (reg > 0x08 && reg < 0x0C)
		ide_write(channel, ATA_REG_CONTROL, 0x80 | channels[channel].nIEN);
	if (reg < 0x08)
		result = inb(channels[channel].base + reg - 0x00);
	else if (reg < 0x0C)
		result = inb(channels[channel].base + reg - 0x06);
	else if (reg < 0x0E)
		result = inb(channels[channel].ctrl + reg - 0x0A);
	else if (reg < 0x16)
		result = inb(channels[channel].bmide + reg - 0x0E);
	if (reg > 0x07 && reg < 0x0C)
		ide_write(channel, ATA_REG_CONTROL, channels[channel].nIEN);
	return result;
}
//
void ide_write(unsigned char channel, unsigned char reg, unsigned char data) {
	if (reg > 0x07 && reg < 0x0C)
		ide_write(channel, ATA_REG_CONTROL, 0x80 | channels[channel].nIEN);
	if (reg < 0x08)
		outb(channels[channel].base + reg - 0x00, data);
	else if (reg < 0x0C)
		outb(channels[channel].base + reg - 0x06, data);
	else if (reg < 0x0E)
		outb(channels[channel].ctrl + reg - 0x0C, data);
	else if (reg < 0x16)
		outb(channels[channel].bmide + reg - 0x0E, data);
	if (reg > 0x07 && reg < 0x0C)
		ide_write(channel, ATA_REG_CONTROL, channels[channel].nIEN);
}
/*
* poll/wait
*/
unsigned char ide_polling(unsigned char channel) {
	for (int i = 0; i < 4; i++) {
		ide_read(channel, ATA_REG_ALTSTATUS); // waste 100ms (x4)
	}

	while (ide_read(channel, ATA_REG_STATUS) & ATA_SR_BSY); // wait for busy to be 0

	return 0;
}

void waste() {
	int j = 3;
	for (int i = 0; i < 100; i++) {
		j *= i >> 3;
	}
}
void ide_read_buffer(unsigned char channel, unsigned char reg, unsigned int* buffer, unsigned int quads) {
	if (reg > 0x07 && reg < 0x0C)
		ide_write(channel, ATA_REG_CONTROL, 0x80 | channels[channel].nIEN);
	//asm("pushw %es; movw %ds, %ax; movw %ax, %es");
	asm("pushw %es; pushw %ax; movw %ds, %ax; movw %ax, %es; popw %ax;");
	if (reg < 0x08)
		insl(channels[channel].base + reg - 0x00, buffer, quads);
	else if (reg < 0x0C)
		insl(channels[channel].base + reg - 0x06, buffer, quads);
	else if (reg < 0x0E)
		insl(channels[channel].ctrl + reg - 0x0A, buffer, quads);
	else if (reg < 0x16)
		insl(channels[channel].bmide + reg - 0x0E, buffer, quads);
	asm("popw %es;");
	if (reg > 0x07 && reg < 0x0C)
		ide_write(channel, ATA_REG_CONTROL, channels[channel].nIEN);
}
/*
* init
*/
void ide_init(unsigned int BAR0, unsigned int BAR1, unsigned int BAR2, unsigned int BAR3, unsigned int BAR4) {
	int j, k, count = 0;
	t_out("Init IDE Driver..");
	channels[ATA_PRIMARY].base = (BAR0 & 0xFFFFFFFC) + 0x1F0 * (!BAR0);
	channels[ATA_PRIMARY].ctrl = (BAR1 & 0xFFFFFFFC) + 0x3F6 * (!BAR1);
	channels[ATA_SECONDARY].base = (BAR2 & 0xFFFFFFFC) + 0x170 * (!BAR2);
	channels[ATA_SECONDARY].ctrl = (BAR3 & 0xFFFFFFFC) + 0x376 * (!BAR3);
	channels[ATA_PRIMARY].bmide = (BAR4 & 0xFFFFFFFC) + 0; 
	channels[ATA_SECONDARY].bmide = (BAR4 & 0xFFFFFFFC) + 8; 

	// disable irq
	ide_write(ATA_PRIMARY, ATA_REG_CONTROL, 2);
	ide_write(ATA_SECONDARY, ATA_REG_CONTROL, 2);
	// detect devices (yippee)
	for (int i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			unsigned char err = 0, type = IDE_ATA, status;

			ide_devs[count].reserv = 0;

			ide_write(i, ATA_REG_HDDEVSEL, 0xA0 | (j << 4));
			waste(); 

			ide_write(i, ATA_REG_COMMAND, ATA_CMD_IDENTIFY);
			waste();

			if (ide_read(i, ATA_REG_STATUS) == 0) continue;

			while (1) {
				status = ide_read(i, ATA_REG_STATUS);
				if ((status & ATA_SR_ERR)) { err = 1; break; }
				if (!(status & ATA_SR_BSY) && (status & ATA_SR_DRQ)) break;
			}
			if (err != 0) {
				unsigned char cl = ide_read(i, ATA_REG_LBA1);
				unsigned char ch = ide_read(i, ATA_REG_LBA2);
				if (cl == 0x14 && ch == 0xEB)
					type = IDE_ATAPI;
				else if (cl == 0x69 && ch == 0x96)
					type = IDE_ATAPI;
				else
					continue;
				ide_write(i, ATA_REG_COMMAND, ATA_CMD_IDENTIFY_PACKET);
				waste();
			}

			ide_read_buffer(i, ATA_REG_DATA, (unsigned int)ide_buf, 128);
			ide_devs[count].reserv = 1;
			ide_devs[count].type = type;
			ide_devs[count].channel = i;
			ide_devs[count].drive = j;
			ide_devs[count].sig = *((unsigned short*)(ide_buf + ATA_IDENT_DEVICETYPE));
			ide_devs[count].feat = *((unsigned short*)(ide_buf + ATA_IDENT_CAPABILITIES));
			ide_devs[count].commandsets = *((unsigned int*)(ide_buf + ATA_IDENT_COMMANDSETS));
			if (ide_devs[count].commandsets & (1 << 26))
				ide_devs[count].size = *((unsigned int*)(ide_buf + ATA_IDENT_MAX_LBA_EXT));
			else
				ide_devs[count].size = *((unsigned int*)(ide_buf + ATA_IDENT_MAX_LBA));
			for (k = 0; k < 40; k += 2) {
				ide_devs[count].model[k] = ide_buf[ATA_IDENT_MODEL + k + 1];
				ide_devs[count].model[k + 1] = ide_buf[ATA_IDENT_MODEL + k];
			}
			ide_devs[count].model[40] = 0;
			
			count++;
		}
		
	}

	for (int i = 0; i < 4; i++) {
		if (ide_devs[i].reserv == 1) {
			t_out((char*)ide_devs[i].model);
		}
	}
	t_out("IDE Driver initilized.");
}
#endif