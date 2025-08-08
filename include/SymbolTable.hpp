#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class SymbolTable {
    public:
        SymbolTable();
        unsigned int addEntry(const string& symbol);
        void addEntry(const string& symbol, unsigned int address);
        bool contains(const string& symbol) const;
        unsigned int getAddressOf(const string& symbol) const;
        void printTable() const;

    private:
        unsigned int nextAddress;
        unordered_map<string, unsigned int> symbolTable;

        unsigned int getNextFreeAddress();
    };

#endif
