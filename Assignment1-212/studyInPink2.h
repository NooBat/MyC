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
    file.open(ntb1);

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

    for (int i = 0; i < n2; i++) {
        getline(file, line);

        
    }

    return "000000000";
}

string notebook3(string ntb3) {
    // Complete this function to gain point
    return "000000000";
}

string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    // Complete this function to gain point
    return "000000000";
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
