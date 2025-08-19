#include "Code.hpp"

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string Code::getDest(const string& dest) const {
    return destLookup.at(dest);
}

string Code::getComp(const string& compRef) const {
    string comp { compRef };
    size_t hasM { comp.find('M', 0) };
    size_t hasA { comp.find('A', 0) };
    char registerBit { '0' };
    
    if (hasM != string::npos) {
        registerBit = '1';
        comp.replace(hasM, 1, "X");
    } else if (hasA != string::npos) {
        comp.replace(hasA, 1, "X");
    }

    return registerBit + compLookup.at(comp);
}

string Code::getJump(const string& jump) const {
    return jumpLookup.at(jump);
}

string Code::encode(const string& dest, const string& comp, const string& jump) const {
    return "111" + getComp(comp) + getDest(dest) + getJump(jump);
}

unordered_map<string, string> Code::compLookup {
    {"0", "101010"},
    {"1", "111111"},
    {"-1", "111010"},
    {"D", "001100"},
    {"X", "110000"},
    {"!D", "001101"},
    {"!X", "110001"},
    {"-D", "001111"},
    {"-X", "110011"},
    {"D+1", "011111"},
    {"X+1", "110111"},
    {"D-1", "001110"},
    {"X-1", "110010"},
    {"D+X", "000010"},
    {"D-X", "010011"},
    {"X-D", "000111"},
    {"D&X", "000000"},
    {"D|X", "010101"}
};

unordered_map<string, string> Code::destLookup {
    {"", "000"},
    {"M", "001"},
    {"D", "010"},
    {"DM", "011"},
    {"MD", "011"},
    {"A", "100"},
    {"AM", "101"},
    {"AD", "110"},
    {"ADM", "111"},
    {"AMD", "111"}
};

unordered_map<string, string> Code::jumpLookup {
    {"", "000"},
    {"JGT", "001"},
    {"JEQ", "010"},
    {"JGE", "011"},
    {"JLT", "100"},
    {"JNE", "101"},
    {"JLE", "110"},
    {"JMP", "111"}
};
