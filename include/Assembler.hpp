#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "Parser.hpp"
#include "SymbolTable.hpp"

#include <string>
using namespace std;

class Assembler {
    public:
        Assembler(const string& assemblyFile);
        void assembleProgram();

    private:
        filesystem::path infile;
        string outfile;
        Parser parser;
        SymbolTable symbolTable {};

        void pass1();
        void pass2();
        string lookupAddress(const string& symbol);
        bool strIsDigit(const string& symbol) const;
};

#endif
