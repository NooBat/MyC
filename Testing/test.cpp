#include<bits/stdc++.h>

using namespace std;
int checkBound(int param) {
    if (param < 0) {
        param = 0;
        return param;
    } 
    else if (param > 1000) {
        param = 1000;
        return param;
    }

    return param;
}


int getReady(int& HP, const int& ID, int& M, const int& E1){
    //Complete this function to gain point on task 1
    
    //if HP goes beyond [0;1000]
    HP = checkBound(HP);

    //if M goes beyond [0;1000] 
    M = checkBound(M);

    if (E1 >= 100 && E1 <= 199) {
        if (ID == 1) return checkBound(HP + 75) + M;
        else if (ID == 2) return HP + M;

        int h = (E1 - 100) % 64;
        int J = HP % 100;

        if (J > h) {
            if (HP >= 500 && M % 2 != 0 && M >= 300) {
                if (ID == 0) {
                    return checkBound(HP + 50) + (M - 300);
                }
            }
            if (M % 2 == 0 && M >= 200) {
                return checkBound(HP + 25) + (M - 200);
            }
        }
        else {
            return HP + M;
        }
    }
    else if (E1 >= 200 && E1 <= 299) {
        int m[4] = {190, 195, 200, 205};
        int hp[4]= {  5,   7,   9,  11};
        int x = (E1 % 4) + 1;
        if (ID == 1 || ID == 2) {
            if (M > m[x - 1]) {
                return checkBound(HP + hp[x - 1]) + (M - m[x - 1]);
            }
        }
        else {
            if (M % 2 == 0 && m[x - 1] % 2 != 0) {
                if (M >= m[x - 1]) {
                    return checkBound(HP + hp[x - 1]) + (M - m[x - 1]);
                }
            }
            if (M % 2 != 0 && m[x - 1] % 2 == 0) {
                if (M >= m[x - 1]) {
                    return checkBound(HP + hp[x - 1]) + (M - m[x - 1]);
                }
            }
        }

        return HP + M;
    }

    return -1;
}

int main() {
    int HP, ID, M, E1;
    
    cout << "HP: ";
    cin >> HP;

    cout << "ID: ";
    cin >> ID;

    cout << "M: ";
    cin >> M;

    cout << "E1: ";
    cin >> E1;


    cout << getReady(HP, ID, M, E1);

    return 0;
}