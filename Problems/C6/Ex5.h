#ifndef _POSTFIX_CALC
#define _POSTFIX_CALC

#include<stack>
#include<string>

using namespace std;

class PostfixCalculator {
private:
    string exp;

    bool isDigit(const char& digit) const;
    bool isOperator(const char& op) const;
public: 
    PostfixCalculator();

    PostfixCalculator(const string& exp);

    int evaluateExp() const;
};

bool PostfixCalculator::isDigit(const char& digit) const {
    if (digit >= '0' && digit <= '9') return true;

    return false;
} 

bool PostfixCalculator::isOperator(const char& op) const {
    if (op == '+' ||op == '-' || op == '*' || op == '/') return true;

    return false;
}

PostfixCalculator::PostfixCalculator() {

}

PostfixCalculator::PostfixCalculator(const string& exp) {
    this->exp = exp;
}

int PostfixCalculator::evaluateExp() const {
    stack<int> st;
    bool isNegative = false;

    for (int i = 0; i < exp.length(); i++) {
        string ch = exp.substr(i, 1);
        if (isDigit(exp[i])) {
            string result;
            if (isNegative) result += "-";
            while (isDigit(exp[i]) && i < exp.length()) {
                string temp = exp.substr(i, 1);
                result += temp;
                i++;
            }
            st.push(stoi(result));
        }
        else if (isOperator(exp[i])) {
            if (i + 1 < exp.length() && isDigit(exp[i + 1])) {
                isNegative = true;
            }
            else {
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();

                int result;
                switch(exp[i]) {
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

                st.push(result);
            }
        }
        else continue;
    }

    return st.top();
}

#endif