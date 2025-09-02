#include "Assembler.hpp"

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: HackAssembler path/to/file.asm\n";
        exit(1);
    }

    std::string filename { argv[1] };

    HackAssembler::Assembler assembler(filename);
    assembler.assembleProgram();

    return 0;
}

/**
 * Exit codes:
 * 1: Incorrect usage
 * 2: Assembly file not opened
 * 3: Attempted to retrieve symbol of C-instruction
 */
