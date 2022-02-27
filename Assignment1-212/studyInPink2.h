/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

//Helper function for function notebook2
int countOccurences(string str, string s) {
    if (str.length() < s.length()) return 0;
    int result = 0;
    int idx = 0;

    while (idx != -1) {
        idx = str.find(s);
        if (idx != -1) {
            result += 1;
            str.replace(idx, s.length(), "");        
        }
    }

    return result;
}

//Helper functions for function notebook3
bool isPrime(int n) {
    if (n < 2) return false;
    if (n < 4) return true;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }

    return true;
}

bool isSquare(int n) {
    int squareRoot = sqrt(n);

    return (squareRoot * squareRoot == n);
}

bool isFibonacci(int n) {
    return (isSquare(5 * n * n - 4) && isSquare(5 * n * n + 4));
}

//Helper function for function generateListPasswords
int indexOfMax(int *arr) {
    int max = arr[0];
    int index = 0;

    for (int i = 1; i < 10; i++) {
        if (arr[i] >= max) {
            max = arr[i];
            index = i;
        }
    }

    return index;
}


string functionG(string s1, string s2) {
    int temp = 0;
    string result;

    for (int i = 0; i < s1.length(); i++) {
        int digit1 = stoi(s1.substr(i, 1));
        int digit2 = stoi(s2.substr(i, 1));

        int sum = digit1 + digit2 + temp;

        if (sum > 9) {
            sum %= 10;
            temp = 1;
        } else {
            temp = 0;
        }

        result += to_string(sum);
    }

    return result;
}

string notebook1(string ntb1) {
    // Complete this function to gain point
    ifstream file;
    file.open(ntb1);

    string line;
    string sn1;
    int n1;
    int count[10] = { 0 };

    getline(file, line);

    if (line.length() == 14) {
        sn1 = line.substr(11, 3);

        for (int i = 0; i < sn1.length(); i++) {
            if (sn1[i] < '0' || sn1[i] > '9') {
                return "0000000000";
            }
        }

        n1 = stoi(sn1);
        if (!n1) return "0000000000";

        int temp;

        for (int i = 0;  i < n1; i++) {
            file >> temp;

            count[temp] += 1;

            if (count[temp] >= 10) {
                count[temp] %= 10;
            }
        }
    }

    file.close();
    
    string password;

    for (int i = 0; i < 10; i++) {
        password += to_string(count[i]);
    }

    return password;
}

string notebook2(string ntb2) {
    // Complete this function to gain point
    ifstream file;
    file.open(ntb2);

    string result;
    string line;
    int n2;

    getline(file, line);

    if (line.length() == 5) {
        for (int i = 0; i < 5; i++) {
            if (line[i] < '0' || line[i] > '9') {
                return "1111111111";
            }
        }

        n2 = stoi(line);

        if (n2 < 6 || n2 > 100) {
            return "1111111111";
        }
    } else {
        return "1111111111";
    }

    int pinkCount = 0;

    for (int i = 0; i < n2; i++) {
        getline(file, line);
        pinkCount += countOccurences(line, "pink") + countOccurences(line, "Pink");
    }

    if (pinkCount < 10000) {
        pinkCount *= pinkCount;
    }   
    
    result += to_string(pinkCount);

    while (result.length() < 10) {
        result += to_string(9);
    }

    return result;
}

string notebook3(string ntb3) {
    // Complete this function to gain point
    int arr[10][10];

    ifstream file;
    file.open(ntb3);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int temp;
            char line;

            file >> temp;
            
            arr[i][j] = abs(temp);

            if (j < 9) file >> line;
        }
    }

    for (int i = 0; i < 10; i++) {
        while (!isPrime(arr[i][i])) {
            arr[i][i]++;
        }
    }

    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < i; j++) {
            while (!isFibonacci(arr[i][j])) {
                arr[i][j]++;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        if (arr[i][7] > arr[i][8]) swap(arr[i][7], arr[i][8]);
        if (arr[i][8] > arr[i][9]) swap(arr[i][8], arr[i][9]);
        if (arr[i][7] > arr[i][9]) swap(arr[i][7], arr[i][9]);
    }

    string pwd;

    for (int i = 0; i < 10; i++) {
        pwd += to_string(indexOfMax(arr[i]));
    }

    return pwd;
}

string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    // Complete this function to gain point
    string passwordsList = "";

    passwordsList += pwd1 + "," + pwd2 + "," + pwd3 + ",";

    passwordsList += functionG(pwd1, pwd2) + ",";

    passwordsList += functionG(pwd1, pwd3) + ",";

    passwordsList += functionG(pwd2, pwd3) + ",";

    passwordsList += functionG(functionG(pwd1, pwd2), pwd3) + ",";

    passwordsList += functionG(pwd1, functionG(pwd2, pwd3)) + ",";

    passwordsList += functionG(functionG(pwd1, pwd2), functionG(pwd1, pwd3));

    return passwordsList;
}

bool chaseTaxi(
    int arr[100][100],
    string points,
    string moves,
    string & outTimes,
    string & outCatchUps
) {
    // Complete this function to gain point
    return false;
}

string enterLaptop(string tag, string message) {
    // Complete this function to gain point
    return "";
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
