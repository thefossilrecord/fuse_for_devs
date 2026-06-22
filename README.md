# fuse_for_devs

Branch of fuse 1.9.0 with experimental features and changes to improve the debugger on Linux/GTK for people using it to develop code with.

Compile with:

./configure
make

Changelog:

v0.01

- Added menu accelerators for Debugger (Escape), Hard Reset (Ctrl + Shift F5) and NMI (Shift + F5).
- Restored processing of $xxxx format hexadecimal numbers in the GTK debugger command entry box.
- Added --sym-file <path to .sym file> command line option to load in a .sym file created by SjASMPlus.
- Create debugger $ variables from the EQUs defined in the sym file, so you can do things like 't $\_main\_entry' to put a temporary breakpoint on the label \_main\_entry.
- Added m/mem/memory command to dump memory and a memory dump window to the GTK debugger.
- Put the focus into the command entry window when entering the debugger.
- Increased font height in create_disassembly by 2 as commas were being cropped and displaying as full stops.

