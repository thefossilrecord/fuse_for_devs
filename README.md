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
Added features, changes and fixes:

- Added menu accelerators for Debugger (Escape), Hard Reset (Ctrl + Shift F5) and NMI (Shift + F5).
- Restored processing of $xxxx format hexadecimal numbers in the GTK debugger command entry box.
- Added a command history to the debugger (currently 32 entries). Cursor up and down moves you through the previously entered commands. Text entry field is now also cleared when a command is entered.
- Added --sym-file <path to .sym file> command line option to load in a .sym file created by SjASMPlus. `fuse --sym-file bin/main.sym bin/main.tap`
- Create debugger $ variables from the EQUs defined in the sym file, so you can do things like 't $\_main\_entry' to put a temporary breakpoint on the label \_main\_entry.
- Auto completion window for SjASMPlus defined $variables. So if you type in `m $_ma` any symbols that contain `_ma` will be listed in an auto complete drop down.
- Added m/mem/memory command to dump memory and a memory dump window to the GTK debugger.
- Put the focus into the command entry window when entering the GTK debugger.
- Added poke command which works as a more memorable alias for `set <address> <value>`. It also supports poking a 16 bit value, so you can do `poke 40000 16384`.
- Pressing F10 in the debugger text entry will now do a step over.
- Pressing F11 in the debugger text entry will now do a step into.
- If you entered an unknown command into the debugger then the focus was not returned to the debugger after dismissing the error message.
- Increased font height in create_disassembly by 2 as commas were being cropped and displaying as full stops in the GTK debugger disassembly view.

There is also a thread dedicated to this project on the Spectrum Computing forum:

https://spectrumcomputing.co.uk/forums/viewtopic.php?f=23&t=15601

Thanks:

- The Fuse team for their original work on the emulator and making the source available. https://fuse-emulator.sourceforge.net/fuse.php
- adam on the spectrumcomputing forum for pointing out some issues with the build process of the initial v0.1 release.

