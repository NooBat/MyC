#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

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
    int i = 2;
    int times = 0;
    while (times < 20) {
        P3[times] = i * i;
        times++;
        i += 2;
    }

    int P4[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool foundLuggage[4] = { false };
    int k[4] = { 0 };

    //Road 1
    for (int i = 0; i < 9; i++) {
        P1[i] = (P1[i] + E3) % 26 + 65;
        if (P1[i] == 80) {
            k[0] = i + 1;
            foundLuggage[0] = true;
        }
    }
    if (foundLuggage[0]) {
        HP1 -= P1[k[0] - 1] * k[0] * 2;
        EXP1 += (1000 - P1[k[0] - 1] * k[0]) % 101;
        M1 = roundUp(M1 - k[0] * E3 / 9.0); 
    }

    //Road 2
    int sum = 0;
    for (int i = 0; i < 7; i++) {
        P2[i] = (P2[i] + E3) % 26;
        sum += P2[i];
    }
    int avg = roundUp(sum / 7.0);
    for (int i = 0; i < 7; i++) {
        P2[i] = (P2[i] + sum + avg) % 26 + 65;
        if (P2[i] == 80) {
            k[1] = i + 1;
            foundLuggage[1] = true;
        }
    }
    if (foundLuggage[1]) {
        HP1 -= P2[k[1] - 1] * k[1] * 2;
        EXP1 += (1000 - P2[k[1] - 1] * k[1]) % 101;
        M1 = roundUp(M1 - k[1] * E3 / 9.0); 
    }

    //Road 3
    int max = P3[0];
    for (int i = 0; i < 20; i++) {
        P3[i] = (P3[i] + E3 * E3) % 113;
        if (P3[i] > max) {
            max = P3[i];
        }
    }
    for (int i = 19; i >= 0; i--) {
        P3[i] = roundUp((P3[i] + E3) / max) % 26 + 65;
        if (P3[i] == 80) {
            k[2] = 20 - i;
            foundLuggage[2] = true;
        }
    }
    if (foundLuggage[2]) {
        HP1 -= P3[20 - k[2]] * k[2] * 3;
        EXP1 += (3500 - P1[20 - k[2]] * k[2]) % 300;
        M1 = roundUp(M1 - k[2] * E3 / 9.0); 
    }

    //Road 4
    int min = INT_MAX;
    int min_idx = 1;

    for (int i = 0; i < 12; i++) {
        P4[i] = P4[i] + (roundUp(pow(E3 / 29.0, 3)) % 9);
        if (P4[i] < min) {
            min = P4[i];
            min_idx = i + 1;
        }
    }

    for (int i = 11; i >= 0; i--) {
        P4[i] = roundUp((P4[i] + E3) * roundUp(min / min_idx)) % 26 + 65;
        if (P4[i] == 80) {
            k[3] = 12 - i;
            foundLuggage[3] = true;
        }
    }
    if (foundLuggage[3]) {
        HP1 -= P4[12 - k[3]] * k[3] * 4;
        EXP1 += (4500 - P4[12 - k[3]] * k[3]) % 400;
        M1 = roundUp(M1 - k[3] * E3 / 9.0); 
    }

    M1 = M1 - roundUp(!k[0] * (pow(9, 2) + !k[1] * pow(7, 2) + !k[2] * pow(20, 2) + !k[3] * pow(12, 2)) * E3 / 9.0);


    if (!foundLuggage[0] && !foundLuggage[1] && !foundLuggage[2] && !foundLuggage[3]) {
        HP1 -= (59 * E3) % 900;
        EXP1 -= (79 * E3) % 300;
        return -1;
    }

    setHP(HP1);
    setEXP(EXP1);
    setM(M1);

    return HP1 + EXP1 + M1;
}

int main() {
    string a = "Testcase output #1: ";
    string b = "Testcase output #1: ";  

    cout << (a != b) << endl;

    return 0;
}