#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <iostream>
#include <string>
#include <unordered_map>

namespace HackAssembler {

class SymbolTable {
public:
    /**
     * Creates a new SymbolTable module with the Hack computer's predefined symbol mappings.
     */
    SymbolTable();

    /**
     * Adds the provided symbol to the symbol table using the next free memory address and returns its address.
     * Used to add variables found in program to symbol table.
     */
    unsigned int addEntry(const std::string& symbol);

    /**
     * Adds the provided symbol to the symbol table using the provided memory address.
     * Used to add labels and predefined addresses found in program to symbol table.
     */
    void addEntry(const std::string& symbol, unsigned int address);

    /**
     * Returns whether or not the provided symbol exists in the symbol table.
     */
    bool contains(const std::string& symbol) const;

    /**
     * Returns the memory address of the provided symbol.
     */
    unsigned int getAddressOf(const std::string& symbol) const;

    /**
     * Prints the contents of the symbol table.
     */
    void printTable() const;

private:
    unsigned int nextAddress;
    std::unordered_map<std::string, unsigned int> symbolTable;

    unsigned int getNextFreeAddress();
};

}

#endif
