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

int firstMeet(int& EXP1, int& EXP2, const int& E1){
    //Complete this function to gain point on task 1
    
    if ( E1 < 0 || E1 > 999 ) return -999;

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
            EXP1 = ceil(EXP1 + E1 / 10.0);
        } else {
            EXP1 = ceil(EXP1 - E1 / 5.0);
        }
    } else {
        //Case 2
        if ( E1 < 500 ) {
            EXP2 = ceil(EXP2 + E1 / 7.0 + 9);
        } else if ( E1 < 600 ) {
            EXP2 = ceil(EXP2 + E1 / 9.0 + 11);
        } else if ( E1 < 700 ) {
            EXP2 = ceil(EXP2 + E1 / 5.0 + 6);
        } else if ( E1 < 800 ) {
            EXP2 = ceil(EXP2 + E1 / 7.0 + 9);
            if ( EXP2 > 200 ) {
                EXP2 = ceil(EXP2 + E1 / 9.0 + 11);
            }
        } else {
            EXP2 = EXP2 + ceil(E1 / 7.0 + 9) + ceil(E1 / 9.0 + 11);
            if ( EXP2 > 600 ) {
                EXP2 = ceil(EXP2 + E1 / 5.0 + 6);
                EXP2 = ceil(EXP2 * 1.15);
            }
        }
        EXP1 = ceil(EXP1 - 0.1 * E1);
    }

    setEXP(EXP1);
    setEXP(EXP2);

    return EXP1 + EXP2;
}

int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2){
    //Complete this function to gain point on task 2

    if ( E2 < 0 || E2 > 999 ) return -999;

    //Reset the boundary for all inputs
    setEXP(EXP1);
    setEXP(EXP2);
    setHP(HP2);
    setM(M2);

    float d1 = E2 / 9.0 + 10;
    float d2 = 0.35 * E2;
    float d3 = 0.17 * (ceil(d1) + ceil(d2));

    EXP1 = ceil(EXP1 + d1 / 3);
    EXP2 = ceil(EXP2 + d1);
    if ( E2 >= 300 ) {
        EXP1 = ceil(EXP1 + d2 / 3);
        EXP2 = ceil(EXP2 + d2);
    }
    if ( E2 >= 500 ) {
        EXP1 = ceil(EXP1 + d3 / 3);
        EXP2 = ceil(EXP2 + d3);
    }

    HP2 = ceil(HP2 - pow(E2, 3) * 1.0 / pow(2, 23));

    if ( !(E2 & 1) ) {
        M2 = ceil(M2 + pow(E2, 2) / 50.0);
    }

    setEXP(EXP1);
    setEXP(EXP2);
    setHP(HP2);
    setM(M2);

    return EXP2 + HP2 + M2 + EXP1;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3){
    //Complete this function to gain point on task 3
    if (E3 < 0 || E3 > 999) return -999;

    //Reset the boundary for all inputs
    setHP(HP1);
    setEXP(EXP1);
    setM(M1);

    int P1[] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int P2[] = {2, 3, 5, 7, 11, 13, 17};
    
    int P3[20];
    int num = 2;
    int times = 0;
    while (times < 20) {
        P3[times] = pow(num, 2);
        times++;
        num += 2;
    }

    int P4[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool foundLuggage[4] = { false };
    int k[4] = { 0 };

    //Road 1
    for (int i = 0; i < 9; i++) {
        P1[i] = (P1[i] + E3) % 26 + 65;
        if ( P1[i] == 80 && !foundLuggage[0] ) {
            k[0] = i + 1;
            foundLuggage[0] = true;
        }
    }

    //Road 2
    int sum = 0;
    for (int i = 0; i < 7; i++) {
        P2[i] = (P2[i] + E3) % 26;
        sum += P2[i];
    }
    int avg = ceil(sum / 7.0);
    for (int i = 0; i < 7; i++) {
        P2[i] = (P2[i] + sum + avg) % 26 + 65;
        if ( P2[i] == 80 && !foundLuggage[1] ) {
            k[1] = i + 1;
            foundLuggage[1] = true;
        }
    }

    //Road 3
    int max = -1;
    for (int i = 0; i < 20; i++) {
        P3[i] = (P3[i] + E3 * E3) % 113;
        if (P3[i] > max) {
            max = P3[i];
        }
    }

    for (int i = 19; i >= 0; i--) {
        P3[i] = int(ceil((P3[i] + E3) / max)) % 26 + 65;
        if ( P3[i] == 80 && !foundLuggage[2] ) {
            k[2] = 20 - i;
            foundLuggage[2] = true;
        }
    }

    //Road 4
    int min = 10000;
    int min_idx = 1;
    for (int i = 0; i < 12; i++) {
        int a = pow(ceil(E3 / 29.0), 3);
        P4[i] = (P4[i] + a) % 9;
        if (P4[i] < min) {
            min = P4[i];
            min_idx = i + 1;
        }
    }   

    for (int i = 11; i >= 0; i--) {
        P4[i] = ((P4[i] + E3) * int(ceil(min / min_idx))) % 26 + 65;
        if ( P4[i] == 80 && !foundLuggage[3] ) {
            k[3] = 12 - i;
            foundLuggage[3] = true;
        }
    }

    M1 = M1 - ceil(!foundLuggage[0] * pow(9, 2) * E3 / 9.0) - 
              ceil(!foundLuggage[1] * pow(7, 2) * E3 / 9.0) - 
              ceil(!foundLuggage[2] * pow(20, 2) * E3 / 9.0) - 
              ceil(!foundLuggage[3] * pow(12, 2) * E3 / 9.0);

    if (!foundLuggage[0] && !foundLuggage[1] && !foundLuggage[2] && !foundLuggage[3]) {
        HP1 -= (59 * E3) % 900;
        EXP1 -= (79 * E3) % 300;
    } else {
        if (foundLuggage[0]) {
            HP1 -= 80 * k[0] * 2;
            EXP1 += (1000 - 80 * k[0]) % 101;
            M1 = ceil(M1 - k[0] * E3 / 9.0); 
        }
        if (foundLuggage[1]) {
            HP1 -= 80 * k[1] * 2;
            EXP1 += (1000 - 80 * k[1]) % 101;
            M1 = ceil(M1 - k[1] * E3 / 9.0); 
        }
        if (foundLuggage[2]) {
            HP1 -= 80 * k[2] * 3;
            EXP1 += (3500 - 80 * k[2]) % 300;
            M1 = ceil(M1 - k[2] * E3 / 9.0); 
        }
        if (foundLuggage[3]) {
            HP1 -= 80 * k[3] * 4;
            EXP1 += (4500 - 80 * k[3]) % 400;
            M1 = ceil(M1 - k[3] * E3 / 9.0); 
        }
    }

    setHP(HP1);
    setEXP(EXP1);
    setM(M1);

    
    if (!foundLuggage[0] && !foundLuggage[1] && !foundLuggage[2] && !foundLuggage[3]) return -1;
    return HP1 + EXP1 + M1;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
