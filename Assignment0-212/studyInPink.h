/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

void setHP(int& HP) {
    //Set the boundary for HP
    if ( HP > 999 ) HP = 999;
    if ( HP < 0 ) HP = 0;
}

void setEXP(int& EXP) {
    if ( EXP > 900 ) EXP = 900;
    if ( EXP < 0 ) EXP = 0;
}

void setM(int& M) {
    if ( M > 2000 ) M = 2000;
    if ( M < 0 ) M = 0;
}

int roundUp(double x) {
    if ( int(x) == x ) return x;
    return int(x) + 1;
}

int firstMeet(int& EXP1, int& EXP2, const int& E1){
    //Complete this function to gain point on task 1
    
    //Reset the boundary for EXP1 and EXP2
    setEXP(EXP1);
    setEXP(EXP2);

    if ( E1 < 400 ) {
        //Case 1
        if ( E1 < 50 ) {
            EXP2 += 25;
        } else if ( E1 < 100 ) {
            EXP2 += 50;
        } else if ( E1 < 150 ) {
            EXP2 += 85;
        } else if ( E1 < 200 ) {
            EXP2 += 75;
        } else if ( E1 < 250 ) {
            EXP2 += 110;
        } else if ( E1 < 300 ) {
            EXP2 += 135;
        } else {
            EXP2 += 160;
        } 
        //Check whether E1 is odd or even
        if ( E1 & 1 ) {
            EXP1 = roundUp(EXP1 + E1 / 10.0);
        } else {
            EXP1 = roundUp(EXP1 - E1 / 5.0);
        }
    } else {
        //Case 2
        if ( E1 < 500 ) {
            EXP2 = roundUp(EXP2 + E1 / 7.0 + 9);
        } else if ( E1 < 600 ) {
            EXP2 = roundUp(EXP2 + E1 / 9.0 + 11);
        } else if ( E1 < 700 ) {
            EXP2 = roundUp(EXP2 + E1 / 5.0 + 6);
        } else if ( E1 < 800 ) {
            EXP2 = roundUp(EXP2 + E1 / 7.0 + 9);
            if ( EXP2 > 200 ) {
                EXP2 = roundUp(EXP2 + E1 / 9.0 + 11);
            }
        } else {
            EXP2 = roundUp(EXP2 + E1 / 7.0 + 9 + E1 / 9.0 + 11);
            if ( EXP2 > 600 ) {
                EXP2 = roundUp(EXP2 + E1 / 5.0 + 6);
                EXP2 = roundUp(EXP2 * 1.15);
            }
        }
        EXP1 = roundUp(EXP1 - 0.1 * E1);
    }

    setEXP(EXP1);
    setEXP(EXP2);

    return EXP1 + EXP2;
}

int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2){
    //Complete this function to gain point on task 2

    //Reset the boundary for EXP1 and EXP2
    setEXP(EXP1);
    setEXP(EXP2);
    setHP(HP2);
    setM(M2);

    if ( E2 < 300 ) {
        EXP2 
    }

    setEXP(EXP1);
    setEXP(EXP2);
    setHP(HP2);
    setM(M2);

    return EXP2 + HP2 + M2 + E2 + EXP1;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3){
    //Complete this function to gain point on task 3
    return -1;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
