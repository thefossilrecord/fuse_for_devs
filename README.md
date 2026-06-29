# fuse_for_devs

Branch of fuse 1.9.0 with experimental features and changes to improve the debugger on Linux/GTK for people using it to develop code with.

Requirements:

- libspectrum 1.6.2 or newer. https://fuse-emulator.sourceforge.net/libspectrum.php You'll have this already if you've built Fuse from source before. Refer to the README file for compilation instructions. You may need to run 'sudo ldconfig' after installation.

Building:

After cloning the repo or downloading the code from github, cd to the fuse_for_devs folder and compile with:

```
./autogen.sh
./configure
make
```
Changelog:

v0.1

- Added menu accelerators for Debugger (Escape), Hard Reset (Ctrl + Shift F5) and NMI (Shift + F5).
- Restored processing of $xxxx format hexadecimal numbers in the GTK debugger command entry box.
- Added --sym-file <path to .sym file> command line option to load in a .sym file created by SjASMPlus. '`fuse --sym-file bin/main.sym bin/main.tap`'
- Create debugger $ variables from the EQUs defined in the sym file, so you can do things like 't $\_main\_entry' to put a temporary breakpoint on the label \_main\_entry.
- Added m/mem/memory command to dump memory and a memory dump window to the GTK debugger.
- Put the focus into the command entry window when entering the GTK debugger.
- Increased font height in create_disassembly by 2 as commas were being cropped and displaying as full stops in the GTK debugger disassembly view.

Thanks:

- The Fuse team for their original work on the emulator and making the source available. https://fuse-emulator.sourceforge.net/fuse.php
- adam on the spectrumcomputing forum for pointing out some issues with the build process of the initial v0.1 release.

