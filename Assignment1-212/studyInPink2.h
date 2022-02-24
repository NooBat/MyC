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

    string freq;
    string sn1;
    int n1;

    getline(file, freq);

    if (freq.length() == 14) {
        sn1 = freq.substr(11, 3);

        for (int i = 0; i < sn1.length(); i++) {
            if (sn1[i] < '0' || sn1[i] > '9') {
                return "0000000000";
            }
        }

        n1 = stoi(sn1);
    }

    file.close();
    return "000000000";
}

string notebook2(string ntb2) {
    // Complete this function to gain point
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
