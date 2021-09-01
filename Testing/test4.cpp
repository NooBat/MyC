#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<sstream>
#include<regex>
#include<cmath>
#include<algorithm>
#include<fstream>

using namespace std;

bool checkValid(const string& str) {
    bool in = false;
    bool out = false;
    int countWord = 0;
    int countSpace = 0;
    regex letters("[a-zA-Z0-9]");

    for (int i = 0; i < str.length(); i++) {
        string single = str.substr(i, 1);

        if (single == " ") {
            out = true;
            in = false;
            countSpace++;
        }
        else if (regex_match(single, letters)) {
            out = false;
            if (!in) countWord++;
            in = true;
        }
    }

    return (countSpace == countWord - 1) && (countWord >= 1 && countWord <= 3);
}
bool checkValidId(const string& id) {
    regex letter("[a-zA-Z_0-9]");
    regex digit("[0-9_]*");

    if (regex_match(id, digit)) return false;

    for (int i = 0; i < id.length(); i++) {
        string temp = id.substr(i, 1);

        if (!regex_match(temp, letter)) return false;
    }

    return true;
}
bool checkValidType(const string& type, const string& item) {
    if (type == "number") {
        if (item[0] != 'n') return false;
        regex digit("[0-9]");

        for (int i = 1; i < item.length(); i++) {
            string temp = item.substr(i, 1);
            if (!regex_match(temp, digit)) return false;
        }
    }
    else if (type == "string") {
        if (item[0] != '\'' || item[item.length() - 1] != '\'') return false;
        regex letter("[a-zA-Z0-9 ]");

        for (int i = 1; i < item.length() - 1; i++) {
            string temp = item.substr(i, 1);
            if (!regex_match(temp, letter)) return false;
        }
    }

    return true;
}

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
    // string filename = "/Users/danielnguyen/Repo/C++/Assignment1-2/testcase/test1.txt";
    // ifstream myfile(filename);
    // string tmp;
    // if (myfile.is_open()) {
    //     while (getline(myfile, tmp)) {
    //         cout << checkValid(tmp) << " ";
    //     } 
    // }
    // string a = " \'a b c\'";
    // int start = 0;
    // int end = (int)a.find(" ");

    // while (end != -1) {
    //     start = (int)end + 1;
    //     if (a[start] != '\'') end = (int)a.find(" ", start);
    //     else {
    //         end = (int)a.find("\'", start + 1);
    //         cout << start << " " << end;
    //     }
    // }
    int a = 0;
    string id = "__";
    cout << checkValidId(id);
	return 0;
}
