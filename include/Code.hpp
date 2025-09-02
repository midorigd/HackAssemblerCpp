#ifndef CODE_H
#define CODE_H

#include <iostream>
#include <string>
#include <unordered_map>

namespace HackAssembler {

class Code {
public:
    /**
     * Creates a new CodeWriter module to translate assembly code to machine code.
     */
    Code() {};

    /**
     * Returns the binary translation of the provided destination code.
     */
    std::string getDest(const std::string& dest) const;

    /**
     * Returns the binary translation of the provided computation code.
     */
    std::string getComp(const std::string& compRef) const;

    /**
     * Returns the binary translation of the provided jump code.
     */
    std::string getJump(const std::string& jump) const;

    /**
     * Returns the machine code for the provided C-instruction.
     */
    std::string encode(const std::string& dest, const std::string& comp, const std::string& jump) const;

private:
    static std::unordered_map<std::string, std::string> compLookup;
    static std::unordered_map<std::string, std::string> destLookup;
    static std::unordered_map<std::string, std::string> jumpLookup;
};

}

#endif
