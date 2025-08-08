#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <iostream>
#include <regex>
#include <string>
using namespace std;

enum class COMMAND_TYPE {
    A, C, L, NONE
};

ostream& operator<<(ostream& os, COMMAND_TYPE type);

class Parser {
    public:
        Parser(const string& filename);
        bool hasMoreCommands();
        string advance();
        void reset();
        COMMAND_TYPE commandType() const;
        string symbol() const;
        void writeLine() const;
        void writeContents();
        
        string dest() const { return destStr; }
        string comp() const { return compStr; }
        string jump() const { return jumpStr; }

    private:
        static regex commentPattern;
        static string commentReplace;
        static regex compPattern;

        ifstream asmFile;
        string line;

        string destStr;
        string compStr;
        string jumpStr;

        void splitCommand();
};

#endif
