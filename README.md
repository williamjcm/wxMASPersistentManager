# wxMASPersistentManager
This program allows users of the Monika After Story mod to easily create and manage backups of their persistent save file, with a GUI built using wxWidgets 3.0.

## Getting the program
Prebuilt, statically-linked 32- and 64-bit binaries are available for Windows, under the "Releases" section.

The program will need to be built from source for Linux and macOS.

## Building from source
1. Clone the repository.
2. Install the required dependencies (`g++`, `make`, wxWidgets 3.0 or higher):
    1. On MSYS2: `pacman -Syu mingw-w64-<arch>-toolchain mingw-w64-<arch>-wxWidgets` (replace `<arch>` with either `i686` or `x86_64`, depending on which architecture (32- or 64-bit, respectively) you want to build for).
    2. On Linux: `sudo apt install g++ make libwxgtk3.0-dev` (for Debian- and/or apt-based distros) or `pacman -Syu base-devel wxgtk` (for Arch Linux). Users of other distros will have to find which packages they need to install.
    3. On macOS: find a way to install `g++`, `make` and wxWidgets 3.0. According to aldoram5 from the MAS dev team, one easy way to get wxWidgets, is installing [Homebrew](https://brew.sh/) (if you don't already have it) and then run `brew install wxmac`.
3. Navigate to the directory where the source is located, then run `make`.

### Notes:
* Built binaries are found in `./bin/<Debug or Release>`.
* Binaries will be dynamically-linked by default. To make a static build, change the following lines in the `Makefile`:
    1. The line which starts with `CFLAGS` becomes  ```CFLAGS = -std=c++11 -Wall -Wno-write-strings `wx-config --cxxflags --unicode --version=3.0 --static```
    2. The line which starts with `LDFLAGS` becomes  ```LDFLAGS = -static `wx-config --libs base,core --unicode --version=3.0 --static```
    * Static builds will only be possible if you have a static build of wxWidgets. MSYS2 provides one, for example.
