# fuse_for_devs

Branch of fuse 1.9.0 with experimental features and changes to improve the debugger on Linux/GTK and Windows for people using it to develop code with.

## Requirements:

- libspectrum 1.6.2 or newer. https://fuse-emulator.sourceforge.net/libspectrum.php You'll have this already if you've built Fuse from source before. Refer to the README file for compilation instructions. You may need to run 'sudo ldconfig' after installation.

## Building:

### Linux

After cloning the repo or downloading the code from github, cd to the fuse_for_devs folder and compile with:

```
./autogen.sh
./configure
make
```

### Windows

After cloning the repo or downloading the code from github, use the instructions outlined here:

https://sourceforge.net/p/fuse-emulator/wiki/Building%20Fuse%20on%20Windows%20with%20MinGW-w64%20and%20MSYS2/

Use the fuse_for_devs source package instead of the official fuse source.

## Added features, changes and fixes:

- Added menu accelerators for Debugger (Escape), Hard Reset (Ctrl + Shift F5) and NMI (Shift + F5).
- Restored processing of $xxxx format hexadecimal numbers in the GTK debugger command entry box.
- Added a command history to the debugger (currently 32 entries). Cursor up and down moves you through the previously entered commands. Text entry field is now also cleared when a command is entered.
- Added --sym-file <path to .sym file> command line option to load in a .sym file created by SjASMPlus. `fuse --sym-file bin/main.sym bin/main.tap`
- Create debugger $ variables from the EQUs defined in the sym file, so you can do things like `t $\_main\_entry` to put a temporary breakpoint on the label `\_main\_entry`.
- Added m/mem/memory command to dump memory and a memory dump window to the GTK debugger - `m <address> <bank>`. `<bank>` is an optional value to specify the memory bank on 128k machines (0 - 7 for a specific bank or 8 for the active bank).
- Added watch command to debugger which displays the contents of a specified address inside the watch list in the debugger UI - `watch 16384` or `watch $_sjasm_symbol_name`. An optional parameter specifies how to display the data, e.g. `watch 32768 u8` will show the value as an unsigned 8 bit value or `watch 32768 u16` will show it as an unsigned 16 bit value. If this parameter is not set it will default to u8. Double clicking an entry in the watch list will update the memory view window to display the contents of the watched address.
- Put the focus into the command entry window when entering the GTK debugger.
- Added poke command which works as a more memorable alias for `set <address> <value>`. It also supports poking a 16 bit value, so you can do `poke 40000 16384`.
- Pressing F10 in the debugger text entry will now do a step over.
- Pressing F11 in the debugger text entry will now do a step into.
- If you entered an unknown command into the debugger then the focus was not returned to the debugger after dismissing the error message.
- Auto completion window for SjASMPlus defined $variables. So if you type in `m $_ma` any symbols that contain `_ma` will be listed in an auto complete drop down.

### GTK specific changes and bug fixes:

- Increased font height in create_disassembly by 2 as commas were being cropped and displaying as full stops in the GTK debugger disassembly view.

## Links:

There is also a thread dedicated to this project on the Spectrum Computing forum:

https://spectrumcomputing.co.uk/forums/viewtopic.php?f=23&t=15601

## Thanks:

- The Fuse team for their original work on the emulator and making the source available. https://fuse-emulator.sourceforge.net/fuse.php
- adam on the spectrumcomputing forum for pointing out some issues with the build process of the initial v0.1 release.

