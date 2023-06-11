# DoomOS
Operating System built from the ground up that runs only Doom.


## File structure:

`kernel`: Contains code for the base kernel. The filesystem and display functions are located here. <br>
`doom`: Contains the source code for Doom. Based on the original id-Software Linux version, it has been modified to run on DoomOS. <br>
`libc`: DoomOS C Library, contains standard functions and headers (`stdlib`, `stdio` and such).


## Booting
Grab an ISO from the releases or compile it yourself. You'll need a i686 GCC Crosscompiler.
```bash
sh full.sh
```
and boom, qemu should launch with DoomOS. <br>
If you want to boot on real hardware, burn the generated ISO to a CD or USB. <br>
Personally I like ventoy: https://www.ventoy.net/en/index.html.
