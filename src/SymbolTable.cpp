#include "SymbolTable.hpp"

namespace HackAssembler {

using namespace std;

SymbolTable::SymbolTable() :
    nextAddress(16),
    symbolTable({
    {"R0", 0},
    {"R1", 1},
    {"R2", 2},
    {"R3", 3},
    {"R4", 4},
    {"R5", 5},
    {"R6", 6},
    {"R7", 7},
    {"R8", 8},
    {"R9", 9},
    {"R10", 10},
    {"R11", 11},
    {"R12", 12},
    {"R13", 13},
    {"R14", 14},
    {"R15", 15},
    {"SCREEN", 16384},
    {"KBD", 24576},
    {"SP", 0},
    {"LCL", 1},
    {"ARG", 2},
    {"THIS", 3},
    {"THAT", 4}
    }) {}

unsigned int SymbolTable::addEntry(const string& symbol) {
    unsigned int address { getNextFreeAddress() };
    symbolTable[symbol] = address;
    return address;
}

void SymbolTable::addEntry(const string& symbol, unsigned int address) {
    symbolTable[symbol] = address;
}

bool SymbolTable::contains(const string& symbol) const {
    return symbolTable.find(symbol) != symbolTable.end();
}

unsigned int SymbolTable::getAddressOf(const string& symbol) const {
    if (!contains(symbol)) {
        cerr << "Symbol " << symbol << " does not exist.\n";
    }

    return symbolTable.at(symbol);
}

unsigned int SymbolTable::getNextFreeAddress() {
    return nextAddress++;
}

void SymbolTable::printTable() const {
    for (unordered_map<string, unsigned int>::const_iterator it = symbolTable.begin(); it != symbolTable.end(); ++it) {
        cout << it->first << ":\t" << it->second << '\n';
    }
}

}
