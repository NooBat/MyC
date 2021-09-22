#ifndef _POSTFIX_EXP
#define _POSTFIX_EXP

#include<stack>
#include<string>

using namespace std;

class Postfix {
private:
    string exp;

    static const string op;
    static const string id;

public:
    Postfix();

    Postfix(const string& exp);

    string getExp() const;

    string toInfix() const;
};

const string Postfix::op = "+-*/";

const string Postfix::id = "abcdefghijklmnopqrstuvwxyz";

Postfix::Postfix() {

}

Postfix::Postfix(const string& exp) {
    this->exp = exp;
}

string Postfix::getExp() const {
    return exp;
}

string Postfix::toInfix() const {
    stack<string> aStack;

    for (int i = 0; i < exp.length(); i++) {
        string ch = exp.substr(i, 1);

        if ((int)id.find(ch) != -1) {
            aStack.push(ch);
        }
        else if ((int)op.find(ch) != -1) {
            string operand2 = aStack.top();
            aStack.pop();
            string operand1 = aStack.top();
            aStack.pop();

            string temp = "(" + operand1 + ch + operand2 + ")";
            aStack.push(temp);
        }
        else return "Not an expression";
    }

    return aStack.top();
}

#endif