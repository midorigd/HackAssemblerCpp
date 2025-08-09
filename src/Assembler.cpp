#include "Assembler.hpp"
#include "Code.hpp"

#include <bitset>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

Assembler::Assembler(const string& assemblyFile) :
    infile(assemblyFile),
    parser(assemblyFile),
    outfile(infile.replace_extension(".hack").string()) {}

void Assembler::assembleProgram() {
    pass1();
    pass2();

    parser.closeFile();
}

void Assembler::pass1() {
    unsigned int lineCount = 0;

    while (parser.hasMoreCommands()) {
        parser.advance();

        if (parser.commandType() == COMMAND_TYPE::L) {
            symbolTable.addEntry(parser.symbol(), lineCount);
        } else {
            ++lineCount;
        }
    }
}

void Assembler::pass2() {
    ofstream binaryFile(outfile);

    parser.reset();
    Code code;

    while (parser.hasMoreCommands()) {
        parser.advance();

        if (parser.commandType() == COMMAND_TYPE::A) {
            binaryFile << lookupAddress(parser.symbol()) << '\n';
        } else if (parser.commandType() == COMMAND_TYPE::C) {
            binaryFile << code.encode(parser.dest(), parser.comp(), parser.jump()) << '\n';
        }
    }

    binaryFile.close();
}

string Assembler::lookupAddress(const string& symbol) {
    unsigned int address;
    
    if (strIsDigit(symbol)) {
        address = static_cast<unsigned int>(stoi(symbol));
    } else if (symbolTable.contains(symbol)) {
        address = symbolTable.getAddressOf(symbol);
    } else {
        address = symbolTable.addEntry(symbol);
    }

    bitset<16> binary(address);
    return binary.to_string();
}

bool Assembler::strIsDigit(const string& symbol) const {
    for (size_t i = 0; i < symbol.length(); ++i) {
        if (!isdigit(symbol[i])) {
            return false;
        }
    }
    return true;
}
