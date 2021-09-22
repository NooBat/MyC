#ifndef _INFIX_CALC
#define _INFIX_CALC

#include<regex>
#include "Ex5.hpp"
#include<cstring>

class InvalidExpression : public exception {
    string mess;

public:
    virtual ~InvalidExpression() throw() {
        return;
    }
    InvalidExpression(const string& exp) {
        mess = "Invalid expression: " + exp;
    }

    const char* what() const throw() {
        return mess.c_str();
    }
};

class InfixCalculator {
private:    
    string exp;

    bool isDigit(const char& digit) const;
    bool isOperator(const char& op) const;
    bool isBalanced() const;
    int precedence(const char& op) const;

public: 
    InfixCalculator();

    InfixCalculator(const string& exp);

    string infixConverter() const;

    int evaluateInfix() const;
};

bool InfixCalculator::isDigit(const char& digit) const {
    if (digit >= '0' && digit <= '9') return true;

    return false;
} 

bool InfixCalculator::isOperator(const char& op) const {
    if (op == '+' ||op == '-' || op == '*' || op == '/') return true;

    return false;
}

bool InfixCalculator::isBalanced() const {
    stack<char> st;

    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(') {
            st.push(exp[i]);
        }
        else if (exp[i] == ')') {
            if (exp[i] == ')' && st.top() == '(') {
                st.pop();
            }
            else return false;
        }
    }
    if (!st.empty()) return false;

    return true;
}

int InfixCalculator::precedence(const char& op) const {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }

    return 0;
}

InfixCalculator::InfixCalculator() {

};

InfixCalculator::InfixCalculator(const string& exp) {
    this->exp = exp;
}

string InfixCalculator::infixConverter() const {
    if (!isBalanced()) throw InvalidExpression(exp);

    stack<char> st;
    string postfix;

    for (int i = 0; i < exp.length(); i++) {
        if (isDigit(exp[i])) {
            string result;
            while (isDigit(exp[i]) && i < exp.length()) {
                string temp = exp.substr(i, 1);
                result += temp;
                i++;
            }
            postfix += result + " ";
            i--;
        }
        else if (exp[i] == '(') {
            st.push(exp[i]);
        }
        else if (isOperator(exp[i])) {
            while (!st.empty() && st.top() != '(' && precedence(exp[i]) <= precedence(st.top())) {
                postfix.push_back(st.top());
                postfix += " ";
                st.pop();
            }
            st.push(exp[i]);

            if (i + 1 < exp.length()) {
                if (isOperator(exp[i + 1])) {
                    throw InvalidExpression(exp);
                }
            }
            if (i + 1 >= exp.length()) throw InvalidExpression(exp);
        }
        else if (exp[i] == ')') {
            while (st.top() != '(') {
                postfix.push_back(st.top());
                postfix += " ";
                st.pop();
            }
            st.pop();
        }
    }

    if (!st.empty()) {
        postfix.push_back(st.top());
        postfix += " ";
        st.pop();
    }

    postfix = postfix.substr(0, postfix.length() - 1);

    return postfix;
}

int InfixCalculator::evaluateInfix() const {
    if (!isBalanced()) throw InvalidExpression(exp);

    stack<char> opStack;
    stack<int> valStack;

    for (int i = 0; i < exp.length(); i++) {
        if (isDigit(exp[i])) {
            string result;
            while (i < exp.length() && isDigit(exp[i])) {
                result.push_back(exp[i]);
                i++;
            }
            i--;
            valStack.push(stoi(result));
        }
        else if (exp[i] == '(') {
            opStack.push(exp[i]);
        }
        else if (isOperator(exp[i])) {
            if (opStack.empty()) opStack.push(exp[i]);
            else if (precedence(exp[i]) > precedence(opStack.top())) opStack.push(exp[i]);
            else {
                while (!opStack.empty() && precedence(exp[i]) <= precedence(opStack.top())) {
                    int operand2 = valStack.top();
                    valStack.pop();

                    int operand1 = valStack.top();
                    valStack.pop();

                    char op = opStack.top();
                    opStack.pop();
                    int result;

                    switch (op) {
                        case '+': 
                            result = operand1 + operand2;
                            break;
                        case '-':
                            result = operand1 - operand2;
                            break;
                        case '*':
                            result = operand1 * operand2;
                            break;
                        case '/':
                            result = operand1 / operand2;
                            break;
                    }

                    valStack.push(result);
                }

                opStack.push(exp[i]);
            }
        }
        else if (exp[i] == ')') {
            while (opStack.top() != '(') {
                int operand2 = valStack.top();
                valStack.pop();

                int operand1 = valStack.top();
                valStack.pop();

                char op = opStack.top();
                opStack.pop();
                int result;

                switch (op) {
                    case '+': 
                        result = operand1 + operand2;
                        break;
                    case '-':
                        result = operand1 - operand2;
                        break;
                    case '*':
                        result = operand1 * operand2;
                        break;
                    case '/':
                        result = operand1 / operand2;
                        break;
                }

                valStack.push(result);
            }
            opStack.pop();
        }
    }

    while (!opStack.empty()) {
        int operand2 = valStack.top();
        valStack.pop();

        int operand1 = valStack.top();
        valStack.pop();

        char op = opStack.top();
        opStack.pop();
        int result;

        switch (op) {
            case '+': 
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
        }

        valStack.push(result);
    }

    return valStack.top();
}

// 2*-(3+4)

#endif