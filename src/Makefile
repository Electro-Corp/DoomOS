# Tools
CC=i686-elf-gcc
CFLAGS=-w -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
ASFLAGS=-w
LD=ld
LDFLAGS=-T kernel/linker.ld -melf_i386

# Paths
OBJS=obj
DOOM_OBJS=$(patsubst doom/%.c,$(OBJS)/doom/%.o,$(wildcard doom/*.c))
KERNEL_OBJS=$(OBJS)/boot.o $(OBJS)/vga.o $(OBJS)/cd.o $(OBJS)/file.o $(OBJS)/memory.o $(OBJS)/kernel.o
ALL_OBJS=$(KERNEL_OBJS) $(DOOM_OBJS)

# Output
KERNEL_BIN=boot/kernel
ISO=doomos.iso

# Main target
all: $(ISO)

# Compile Doom sources
$(OBJS)/doom/%.o: doom/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile kernel parts
$(OBJS)/boot.o: kernel/boot.S
	@mkdir -p $(dir $@)
	$(CC) $(ASFLAGS) -c $< -o $@

$(OBJS)/%.o: kernel/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS)/vga.o: kernel/disp/vga.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS)/cd.o: kernel/controller/cd.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS)/file.o: kernel/controller/file.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS)/memory.o: kernel/memory/memory.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS)/kernel.o: kernel/kernel.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Link the kernel
$(KERNEL_BIN): $(ALL_OBJS)
	@mkdir -p $(dir $@)
	$(LD) $(LDFLAGS) $(ALL_OBJS) -o $@

# ISO creation
$(ISO): $(KERNEL_BIN)
	@mkdir -p isodir/boot/grub
	cp $(KERNEL_BIN) isodir/boot/kernel
	cp boot/grub/* isodir/boot/grub/
	cp doom.wad isodir/
	cp bg.png isodir/boot/
	echo 'background_image /boot/bg.png' > isodir/boot/grub/grub.cfg
	echo 'set color_normal=white/black' >> isodir/boot/grub/grub.cfg
	echo 'set color_highlight=black/white' >> isodir/boot/grub/grub.cfg
	echo 'menuentry "DoomOS" {' >> isodir/boot/grub/grub.cfg
	echo '    multiboot /boot/kernel' >> isodir/boot/grub/grub.cfg
	echo '}' >> isodir/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) isodir

# Run in QEMU
run: $(ISO)
	qemu-system-x86_64 -drive file=$(ISO),if=ide,media=cdrom

# Clean
clean:
	rm -rf obj boot/kernel isodir $(ISO)
