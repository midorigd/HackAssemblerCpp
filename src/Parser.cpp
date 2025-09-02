#include "Parser.hpp"

namespace HackAssembler {

using namespace std;

ostream& operator<<(ostream& os, COMMAND_TYPE type) {
    switch (type) {
        case COMMAND_TYPE::A: os << "A"; break;
        case COMMAND_TYPE::C: os << "C"; break;
        case COMMAND_TYPE::L: os << "L"; break;
        default: break;
    }
    os << "_COMMAND";
    return os;
}

Parser::Parser(const string& filename) : asmFile(filename) {
    if (!asmFile) {
        cerr << "File not opened.\n";
        exit(2);
    }
}

bool Parser::hasMoreCommands() {
    return asmFile.peek() != EOF;
}

string Parser::advance() {
    while (hasMoreCommands()) {
        getline(asmFile >> ws, line);

        line = regex_replace(line, commentPattern, commentReplace);
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());

        if (!line.empty()) {
            if (commandType() == COMMAND_TYPE::C) {
                splitCommand();
            }
            return line;
        }
    }

    return "";
}

void Parser::reset() {
    asmFile.clear();
    asmFile.seekg(0);
}

COMMAND_TYPE Parser::commandType() const {
    if (line.compare(0, 1, "@") == 0) {
        return COMMAND_TYPE::A;
    } else if (line.compare(0, 1, "(") == 0 && line.compare(line.length() - 1, 1, ")") == 0) {
        return COMMAND_TYPE::L;
    } else {
        return COMMAND_TYPE::C;
    }
}

string Parser::symbol() const {
    switch (commandType()) {
        case COMMAND_TYPE::A:
            return line.substr(1, line.length());
        case COMMAND_TYPE::L:
            return line.substr(1, line.length() - 2);
        default:
            cerr << "Type C_COMMAND does not have symbol\n";
            exit(3);
    }
}

void Parser::splitCommand() {
    smatch matches;
    regex_search(line, matches, compPattern);
    destStr = matches[1];
    compStr = matches[2];
    jumpStr = matches[3];
}

regex Parser::commentPattern("//.*");
string Parser::commentReplace = "";
regex Parser::compPattern("(?:([ADM]*)=)?([01AMD!\\|&\\-\\+]*)(?:;([JGTEQLNMP]*))?");

}
