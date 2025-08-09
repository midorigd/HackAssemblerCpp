# HackAssembler (C++)

This is a C++ implementation of the assembler for the Hack assembly language from project 6 of nand2tetris.

The assembler takes a single `.asm` file as a command-line argument and creates a `.hack` file with the corresponding machine language.

## Modules

Assembler: Drives the assembly process  
Code: Handles translation of C-commands  
main: Program entry point  
Parser: Handles input filestream and categorizes commands  
SymbolTable: Tracks variable names and memory addresses  

## Building the project

Run the following from the terminal:

```zsh
git clone https://github.com/midorigd/HackAssemblerCpp
cd HackAssemblerCpp
mkdir build
cd build
cmake ..
make
```

## Running the project

Run the following from the build directory:

```zsh
./HackAssembler path/to/file.asm
```

## Notes

This is my first project on GitHub and my first project in C++!

I'm very new to all of this so any feedback is welcome :)

## References

[nand2tetris](https://www.nand2tetris.org/course)

