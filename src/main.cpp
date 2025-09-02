#include "Assembler.hpp"

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::string filename;

    if (argc == 2) {
        filename = argv[1];
    } else {
        std::cerr << "Usage: HackAssembler filename.asm\n";
        exit(1);
    }

    HackAssembler::Assembler assembler(filename);
    assembler.assembleProgram();

    return 0;
}
