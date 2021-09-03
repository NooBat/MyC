#ifndef _PREFIX_EXP
#define _PREFIX_EXP

#include<string>

using namespace std;

class Prefix {
    string exp;         //stores prefix expression

    static const string Operator;
    static const string Identifier;

    int endPre(const int& first, const int& last) const;
public:

    Prefix();

    Prefix(const string& exp);

    string getExp() const {
        return this->exp;
    }

    bool isPrefix() const;

    string evaluatePrefix(const int& first, const int& last) const;
};

const string Prefix::Operator = "+-*/";

const string Prefix::Identifier = "abcdefghijklmnopqrstuvwxyz";

int Prefix::endPre(const int& first, const int& last) const {
    if (first < 0 || first > last) {
        return -1;
    }
    
    string ch;
    ch += exp[first];

    if ((int)Prefix::Identifier.find(ch) != -1) return first;
    else if ((int)Prefix::Operator.find(ch) != -1) {
        int firstEnd = endPre(first + 1, last);

        if (firstEnd != -1) {
            return endPre(firstEnd + 1, last);
        }
        else return -1;
    }
    else return -1;
}

Prefix::Prefix() {

}

Prefix::Prefix(const string& exp) {
    this->exp = exp;
}

bool Prefix::isPrefix() const {
    if (endPre(0, exp.length() - 1) != -1 && endPre(0, exp.length() - 1) == exp.length() - 1) return true;
    return false;
}

string Prefix::evaluatePrefix(const int& first, const int& last) const {
    int length = last - first + 1;
    if (length == 1) return exp.substr(first, 1);

    string op = exp.substr(first, 1);

    int firstEnd = endPre(first + 1, last);      //index of the end of first prefix expression

    string operand1 = evaluatePrefix(first + 1, firstEnd);

    int secondEnd = length - firstEnd + 1;

    string operand2 = evaluatePrefix(firstEnd + 1, secondEnd);

    return operand1 + op + operand2;
}
#endif