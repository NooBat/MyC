#ifndef _INFIX_EXP
#define _INFIX_EXP

#include<string>
#include<iostream>

using namespace std;

class Infix {
private:
    string exp;

    static const string letter;
    static const string termOp;
    static const string factorOp;

    int findExp(const int& first, const int& last) const;
    int findTerm(const int& first, const int& last) const;
    int findFact(const int& first, const int& last) const;
public:

    Infix();

    Infix(const string& exp);

    string getExp() const;

    bool isInfix() const;
};

const string Infix::letter = "abcdefghijklmnopqrstuvwxyz";
const string Infix::termOp = "+-";
const string Infix::factorOp = "*/";

int Infix::findExp(const int& first, const int& last) const {
    int firstTerm = findTerm(first, last);

    int secondTerm = firstTerm;

    string temp = exp.substr(firstTerm + 1, 1);
    if (firstTerm > -1 && (int)termOp.find(temp) != -1) secondTerm = findTerm(firstTerm + 2, last);
    
    return (secondTerm == -1 || secondTerm >= exp.length()) ? (firstTerm) : (secondTerm);
}

int Infix::findTerm(const int& first, const int& last) const {
    if (first >= last) return first;
    int firstFact = findFact(first, last);

    int secondFact = firstFact;

    string temp = exp.substr(firstFact + 1, 1);
    if ((int)factorOp.find(temp) != -1) secondFact = findFact(firstFact + 2, last);

    return (secondFact == -1 || secondFact >= exp.length()) ? (firstFact) : (secondFact);
}

int Infix::findFact(const int& first, const int& last) const {
    if (first >= last) return first;
    string ch = exp.substr(first, 1);

    if ((int)letter.find(ch) != -1) return first;
    else if (ch == "(") {
        int firstExp = findExp(first + 1, last);
        if (exp[firstExp + 1] != ')') return -1;
        else return firstExp + 1;
    } 

    return -1;
}

Infix::Infix() {

}

Infix::Infix(const string& exp) {
    this->exp = exp;
}

bool Infix::isInfix() const {
    return findExp(0, exp.length() - 1) == exp.length() - 1;
}

#endif