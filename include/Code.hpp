#ifndef CODE_H
#define CODE_H

#include <iostream>
#include <string>
using namespace std;

class Code {
    public:
        Code() {};
        string getDest(const string& dest) const;
        string getComp(const string& compRef) const;
        string getJump(const string& jump) const;
        string encode(const string& dest, const string& comp, const string& jump) const;

    private:
        static unordered_map<string, string> compLookup;
        static unordered_map<string, string> destLookup;
        static unordered_map<string, string> jumpLookup;
};

#endif
