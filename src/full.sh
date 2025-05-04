# compile doom
#cd doom
#ls *.c | while read F; do i686-elf-gcc -w -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -o `echo $F | cut -d . -f 1 - ` $F; done

#cd ..

# DOOM

# A
i686-elf-gcc -w -c doom/am_map.c -o obj/doom/am_map.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
# D
i686-elf-gcc -w -c doom/d_items.c -o obj/doom/d_items.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
# i686-elf-gcc -w -c doom/d_event.c -o obj/doom/d_event.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/d_net.c -o obj/doom/d_net.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/doomdef.c -o obj/doom/doomdef.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/dstrings.c -o obj/doom/dstrings.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
# F
i686-elf-gcc -w -c doom/f_finale.c -o obj/doom/f_finale.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/f_wipe.c -o obj/doom/f_wipe.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
# G
i686-elf-gcc -w -c doom/g_game.c -o obj/doom/g_game.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
# H
i686-elf-gcc -w -c doom/hu_lib.c -o obj/doom/hu_lib.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/hu_stuff.c -o obj/doom/hu_stuff.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
# I
i686-elf-gcc -w -c doom/i_main.c -o obj/doom/i_main.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/i_net.c -o obj/doom/i_net.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/i_sound.c -o obj/doom/i_sound.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/i_system.c -o obj/doom/i_system.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/i_video.c -o obj/doom/i_video.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/info.c -o obj/doom/info.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
# M
i686-elf-gcc -w -c doom/m_argv.c -o obj/doom/m_argv.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/m_bbox.c -o obj/doom/m_bbox.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/m_cheat.c -o obj/doom/m_cheat.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/m_fixed.c -o obj/doom/m_fixed.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/m_menu.c -o obj/doom/m_menu.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/m_random.c -o obj/doom/m_random.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/m_swap.c -o obj/doom/m_swap.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/m_misc.c -o obj/doom/m_misc.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include

# P
i686-elf-gcc -w -c doom/p_ceilng.c -o obj/doom/p_ceilng.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/p_doors.c -o obj/doom/p_doors.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/p_mobj.c -o obj/doom/p_mobj.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/p_enemy.c -o obj/doom/p_enemy.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/p_floor.c -o obj/doom/p_floor.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/p_inter.c -o obj/doom/p_inter.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/p_lights.c -o obj/doom/p_lights.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/p_map.c -o obj/doom/p_map.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/p_maputl.c -o obj/doom/p_maputl.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/p_plats.c -o obj/doom/p_plats.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/p_pspr.c -o obj/doom/p_pspr.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/p_saveg.c -o obj/doom/p_saveg.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/p_setup.c -o obj/doom/p_setup.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/p_sight.c -o obj/doom/p_sight.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/p_spec.c -o obj/doom/p_spec.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/p_switch.c -o obj/doom/p_switch.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/p_telept.c -o obj/doom/p_telept.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/p_tick.c -o obj/doom/p_tick.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/p_user.c -o obj/doom/p_user.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
# R
i686-elf-gcc -w -c doom/r_bsp.c -o obj/doom/r_bsp.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/r_data.c -o obj/doom/r_data.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/r_draw.c -o obj/doom/r_draw.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/r_main.c -o obj/doom/r_main.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/r_plane.c -o obj/doom/r_plane.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/r_segs.c -o obj/doom/r_segs.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/r_sky.c -o obj/doom/r_sky.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/r_things.c -o obj/doom/r_things.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
# S
i686-elf-gcc -w -c doom/s_sound.c -o obj/doom/s_sounds.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/sounds.c -o obj/doom/sounds.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/st_lib.c -o obj/doom/st_lib.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/st_stuff.c -o obj/doom/st_stuff.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
# T
i686-elf-gcc -w -c doom/tables.c -o obj/doom/tables.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
# V
i686-elf-gcc -w -c doom/v_video.c -o obj/doom/v_video.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
# W
i686-elf-gcc -w -c doom/w_wad.c -o obj/doom/w_wad.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c doom/wi_stuff.c -o obj/doom/wi_stuff.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
# Z
i686-elf-gcc -w -c doom/z_zone.c -o obj/doom/z_zone.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include

# confirmation to move on
#read varname


# compile core os
i686-elf-gcc -w -c kernel/boot.S -o obj/boot.o 
i686-elf-gcc -w -c kernel/disp/vga.c -o obj/vga.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c kernel/controller/hd.c -o obj/hd.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c kernel/controller/file.c -o obj/file.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include
i686-elf-gcc -w -c kernel/memory/memory.c -o obj/memory.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include

i686-elf-gcc -w -c kernel/kernel.c -o obj/kernel.o -ffreestanding -Wall -Wextra -nostdinc -fno-builtin -I../libc/include




# link -Ttext 0x0
#ld -T kernel/linker.ld -melf_i386 obj/boot.o obj/vga.o obj/hd.o obj/file.o obj/memory.o obj/kernel.o  obj/doom/*.o -o boot/kernel 
ld -T kernel/linker.ld -melf_i386 obj/boot.o obj/vga.o obj/hd.o obj/file.o obj/memory.o obj/kernel.o  obj/doom/*.o -o boot/kernel 

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub
# module doom.wad
cp boot/kernel isodir/boot/kernel
cp boot/grub/* isodir/boot/grub/
cp doom.wad isodir
cp bg.png isodir/boot
cat > isodir/boot/grub/grub.cfg << EOF
background_image /boot/bg.png
set color_normal=white/black
set color_highlight=black/white
menuentry "DoomOS" {
	multiboot /boot/kernel
}
EOF
grub-mkrescue -o doomos.iso isodir
qemu-system-x86_64 -drive file=doomos.iso,if=ide,media=cdrom