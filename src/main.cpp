#include "Assembler.hpp"

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    string filename;

    if (argc == 2) {
        filename = argv[1];
    } else {
        cerr << "Usage: HackAssembler filename.asm\n";
        exit(1);
    }

    Assembler assembler(filename);
    assembler.assembleProgram();

    return 0;
}
