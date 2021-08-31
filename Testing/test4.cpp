#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<sstream>
#include<cmath>
#include<algorithm>

using namespace std;
 
// function to check if character is operator or not
bool isOperator(char x) {
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':
    return true;
  }
  return false;
}
 
// Convert prefix to Infix expression
string preToInfix(string pre_exp) {
  stack<string> s;
 
  // length of expression
 
  // reading from right to left
  for (int i = pre_exp.length() - 1; i >= 0; i--) {
 
    // check if symbol is operator
    if (isOperator(pre_exp[i])) {
 
      // pop two operands from stack
      string op1 = (string)s.top();   s.pop();
      string op2 = (string)s.top();   s.pop();
 
      // concat the operands and operator
      string temp = "(" + op1 + pre_exp[i] + op2 + ")";
 
      // Push string temp back to stack
      s.push(temp);
    }
 
    // if symbol is an operand
    else {
 
      // push the operand to the stack
      s.push(string(1, pre_exp[i]));
    }
  }
 
  // Stack now contains the Infix expression
  return s.top();
}

int main() {
	string a = "*+-/abc*+def*gh";
    cout << a.length() << endl;
	string result = preToInfix(a);

    cout << result;
	return 0;
}
