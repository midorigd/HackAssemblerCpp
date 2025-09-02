#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "Parser.hpp"
#include "SymbolTable.hpp"

#include <string>

namespace HackAssembler {

namespace fs = std::filesystem;

class Assembler {
public:
    /**
     * Creates a new Assembler module to assemble code from the provided file path.
     */
    Assembler(const std::string& assemblyFile);

    /**
     * Translates the assembly code in the file to machine code and writes it to output.
     */
    void assembleProgram();

private:
    fs::path infile;
    fs::path outfile;
    Parser parser;
    SymbolTable symbolTable {};

    static bool strIsDigit(const std::string& symbol);

    void pass1();
    void pass2();
    std::string lookupAddress(const std::string& symbol);
};

}

#endif
