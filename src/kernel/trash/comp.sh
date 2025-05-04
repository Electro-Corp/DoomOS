cd disp
i686-elf-gcc -c vga.c -ffreestanding -Wall -Wextra -I../libc/include -Idisp
cd ../controller
i686-elf-gcc -c file.c -ffreestanding -Wall -Wextra -I../libc/include -Idisp
cd ..
i686-elf-gcc -c boot.S -ffreestanding -Wall -Wextra
i686-elf-gcc -c kernel.c -ffreestanding -Wall -Wextra -I../libc/include -Idisp