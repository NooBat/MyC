/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2021
    * Author: Nguyen Thanh Nhan
    * Date: 08.02.2021
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef firstFight_h
#define firstFight_h

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
int bound(int n) {
    if (n > 1000) return 1000;
    else if (n < 0) return 0;
    return n;
}

bool checkPrime(int n) {
    if (n <= 1) return false;
    else if (n == 2 || n == 3 || n == 5 || n == 7) return true;
    else return false;
}

int Case1(int &HP, const int& ID, int& M, const int& E1) { //4.1.1
    if (ID == 1) {  //if vua
        HP += 75;
    }
    else if (ID == 0) { //if !vua
        int h = (E1 - 100) % 64;
        int J = HP % 100;

        if (J > h) {    //if succeed 
            if (HP >= 500 && M % 2 != 0) {  //buy WP1
                if (M >= 300) { //if enough money
                    HP += 50;
                    M -= 300;
                }
            }
            else if(M % 2 == 0) {   //buy WP2
                if (M >= 200) { //if enough money
                    HP += 25;
                    M -= 200;
                }
            }
        }
    }

    return bound(HP) + M;
}

int Case2(int &HP, const int& ID, int& M, const int& E1) {  //4.1.2
    int priceMG[4] = {190, 195, 200, 205};
    int mauMG[4] =   {  5,   7,   9,  11};

    int x = E1 % 4;

    if (ID == 1 || ID == 2) {   //if vua or tuong
        if (M >= priceMG[x]) {  //if enough money
            HP += mauMG[x];
            M -= priceMG[x];
        }
    }
    else {  //if !vua & !tuong
        if (M % 2 == 0) {   //if money is even
            if (M >= priceMG[x] && priceMG[x] % 2 != 0) {
                HP += mauMG[x];
                M -= priceMG[x];
            }
        }
        else {  //if money is odd
            if (M >= priceMG[x] && priceMG[x] % 2 == 0) {
                HP += mauMG[x];
                M -=priceMG[x];
            }
        }
    }

    return bound(HP) + M;
}

int Case3(int &HP, const int& ID, int& M, const int& E1) {  //4.1.3
    int a = 1;
    if (checkPrime(E1 % 10)) {
        a = 2 * (E1 % 10);
    }

    if (HP >= 600 && checkPrime(HP % 10)) { //mua thuong
        if (M >= 500) {  //if enough money
            if (ID == 1) {  //if vua
                HP += 200;
            }
            else {
                a *= 2;
                float temp = (float)(HP * a) / 100;
                if (temp > (int)temp) ++temp;
                HP += temp;
            }
            M -= 500;
        }
    }
    if (HP >= 600 && !checkPrime(HP % 10)) {    //mua dao
        if (M >= 300) {
            float temp = (float)(HP * a) / 100;
            if (temp > (int)temp) ++temp;
            HP += temp;
            M -= 300;
        }
    }
    return bound(HP) + M;
}

int Case4(int &HP, const int& ID, int& M, const int& E1) {  //4.1.4
    if (E1 % 5 == 0) {
        float temp = (float)(HP * 0.9);
        if (temp > (int)temp) ++temp;
        HP = temp;
    }

    return bound(HP) + M;
}

int Case5(int &HP, const int& ID, int& M, const int& E1) {  //4.1.5
    float temp1 = float(HP * 0.75);
    if (temp1 > (int)temp1) ++temp1;
    HP = temp1;

    float temp2 = float(M * 0.75);
    if (temp2 > (int)temp2) ++temp2;
    M = temp2;

    return bound(HP) + M;
}

int getReady(int& HP, const int& ID, int& M, const int& E1){
    //Complete this function to gain point on task 1
    HP = bound(HP);
    M = bound(M);

    if (E1 < 100 || E1 > 500) return -999;
    else if (E1 >= 100 && E1 <= 199) return Case1(HP, ID, M, E1);
    else if (E1 >= 200 && E1 <= 299) return Case2(HP, ID, M, E1);
    else if (E1 >= 300 && E1 <= 399) return Case3(HP, ID, M, E1);
    else if (E1 >= 400 && E1 <= 499) return Case4(HP, ID, M, E1);
    else return Case5(HP, ID, M, E1);

    return -1;
}

//Utility function
int rule(int& HP1, int& HP2, const int& ID1, const int& ID2) {  //4.2
    if (ID1 == 1 && ID2 == 2) return 0;
    else if (ID1 == 1) {
        HP2 = 0;
        return 1;
    }
    else if (ID2 == 2) {
        HP1 = 0;
        return -1;
    }
    return -1;
}

void battle(int &HP1, int& HP2) {   //4.2
    float n = (float)((2 * HP1 * HP2)) / (HP1 + HP2);
    if (n > (int)n) ++n;
    n = (int) n;

    int temp = HP1;

    HP1 = bound(HP1 - abs(HP2 - n));
    HP2 = bound(HP2 - abs(temp - n));
}

int firstBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E2){
    //Complete this function to gain point on task 2
    HP1 = bound(HP1);
    HP2 = bound(HP2);

    float z;

    if (E2 < 100 || E2 >= 500) return -999;
    else if (E2 >= 100 && E2 <= 199) { //4.3.1
        z = (float)(HP1 * 110) / 100;
        if (z > (int)z) ++z;
        HP1 = bound((int)z);

        z = (float)(HP2 * 130) / 100;
        if (z > (int)z) ++z;
        HP2 = bound((int)z);
    }
    else if (E2 >= 200 && E2 <= 299) {  //4.3.2
        z = (float)(HP1 * 170) / 100;
        if (z > (int)z) ++z;
        HP1 = bound((int)z);

        z = (float)(HP2 * 120) / 100;
        if (z > (int)z) ++z;
        HP2 = bound((int)z);
    }
    else if (E2 >= 300 && E2 <= 399) {  //4.3.3 
        if (E2 < 350) {
            HP1 = bound(HP1 + 30);
        }
        else {
            HP1 = bound(HP1 + (E2 % 100));
        }
    }
    else if (E2 >= 400 && E2 <= 499) {  //4.3.4
        z = (float)(HP1 * 65) / 100;
        if (z > (int)z) ++z;
        HP1 = bound((int)z);

        z = (float)(HP2 * 80) / 100;
        if (z > (int)z) ++z;
        HP2 = bound((int)z);
    }

    if (ID1 == 1 || ID2 == 2) { //
        z = (float)(HP1 * 80) / 100;
        if (z > (int)z) ++z;
        HP1 = bound(int(z));
        return rule(HP1, HP2, ID1, ID2);
    }

    battle(HP1, HP2);

    if (HP1 > HP2) {
        z = (float)(HP1 * 80) / 100;
        if (z > (int)z) ++z;
        HP1 = bound(int(z));
        return 1;
    }
    else if (HP1 == HP2) {
        z = (float)(HP1 * 80) / 100;
        if (z > (int)z) ++z;
        HP1 = bound(int(z));
        return 0;
    }
    else {
        z = (float)(HP1 * 80) / 100;
        if (z > (int)z) ++z;
        HP1 = bound(int(z));
        return -1;
    }

    return -1;
}

int secondBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E3){
    //Complete this function to gain point on task 3
    if (E3 < 100 || E3 >= 300) return -999;

    float z;
    int temp;
    HP1 = bound(HP1);
    HP2 = bound(HP2);

    z = (float)(HP1 * 140) / 100;
    if (z > (int)z) ++z;
    HP1 = bound(((int)z));

    z = (float)(HP2 * 160) / 100;
    if (z > (int)z) ++z;
    HP2 = bound((int)z);

    if (ID1 == 1) HP1 = bound(2 * HP1);

    if (E3 >= 100 && E3 <= 199) {   //4.4.1
        if (ID2 != 2) {
            z = (float)(HP2 * 95) / 100;
            if (z > (int)z) ++z;
            HP2 = bound((int)z);
        }
    }
    else if (E3 >= 200 && E3 <= 299) {  //4.4.2
        if (ID2 != 2) {
            z = (float)(HP2 * 95) / 100;
            if (z > (int)z) ++z;
            HP2 = bound((int)z);
        }
        return 0;
    }
    temp = HP1;

    if (ID1 == 1 || ID2 == 2) {
        return rule(HP1, HP2, ID1, ID2);
    }

    battle(HP1, HP2);

    if (HP1 > HP2) {
        return 1;
    }
    else if (HP1 == HP2) {
        return 0;
    }
    else {
        HP1 = temp;
        return -1;
    }

    return -1;
}

int finalBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E4){
    //Complete this function to gain point on task 4
    HP1 = bound(HP1);
    HP2 = bound(HP2);
    float z;
    if (E4 < 100 || E4 >= 300) return -999;
    else if (E4 >= 100 && E4 <= 199) {  //4.5.1
        if (ID2 == 2) { //if tuong
            z = (float)(HP2 * 30) / 100;
            if (z > (int)z) ++z;
            HP2 = bound((int)z);
        }
        else {
            z = (float)(HP2 * 10) / 100;
            if (z > (int)z) ++z;
            HP2 = bound((int)z);
        }
        return 0;
    }
    else if (E4 >= 200 && E4 <= 299) {
        HP2 = 0;
        return 1;
    }

    return -1;
}
////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* firstFight_h */