#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <iostream>
#include <regex>
#include <string>

namespace HackAssembler {

enum class COMMAND_TYPE {
    A, C, L, NONE
};

std::ostream& operator<<(std::ostream& os, COMMAND_TYPE type);

class Parser {
public:
    /**
     * Creates a new Parser module to read and parse assembly instructions from the provided file.
     */
    Parser(const std::string& filename);

    /**
     * Returns whether or not there are more assembly instructions to read from input.
     */
    bool hasMoreCommands();

    /**
     * Reads in and returns the next assembly instruction from input.
     */
    std::string advance();

    /**
     * Resets the cursor's position to the beginning of the input file.
     */
    void reset();
    
    /**
     * Returns the type of the current assembly instruction (A, C, or L).
     */
    COMMAND_TYPE commandType() const;

    /**
     * Returns the symbol of the current assembly instruction. Only applicable to A- and L-instructions
     */
    std::string symbol() const;

    /**
     * Returns the destination code of the current assembly instruction. Only applicable to C-instructions
     */
    std::string dest() const { return destStr; }

    /**
     * Returns the computation code of the current assembly instruction. Only applicable to C-instructions
     */
    std::string comp() const { return compStr; }

    /**
     * Returns the jump code of the current assembly instruction. Only applicable to C-instructions
     */
    std::string jump() const { return jumpStr; }

private:
    static std::regex commentPattern;
    static std::string commentReplace;
    static std::regex compPattern;

    std::ifstream asmFile;
    std::string line;

    std::string destStr;
    std::string compStr;
    std::string jumpStr;

    void splitCommand();
};

}

#endif
