#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "Parser.hpp"
#include "SymbolTable.hpp"

#include <string>

namespace HackAssembler {

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
    std::filesystem::path infile;
    std::string outfile;
    Parser parser;
    SymbolTable symbolTable {};

    void pass1();
    void pass2();
    std::string lookupAddress(const std::string& symbol);
    bool strIsDigit(const std::string& symbol) const;
};

}

#endif
