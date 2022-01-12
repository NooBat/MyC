//
// Created by Nhan Nguyen on 01/03/2021.
//
#ifndef MONGOL_H
#define MONGOL_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

// The library here is concretely set, students are not allowed to include any other libraries.

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1);
int decode(const string A, const string B);
string findRoute(const string input3);
string decodeVfunction(const string A, const string B);
string findBetrayals(const string input5[], const int N5);
int attack(const string input6[]);
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k);

////////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER HERE
////////////////////////////////////////////////////////////////////////////
bool findVua(const string ID[], const int NID) {
    for (int i = 0; i < NID; i++) {
        string copy;
        copy = ID[i];

        int pos = copy.find("VUA");

        if (pos == 0) return 1;
    }
    return 0;
}

bool findTHD(const string ID[], const int NID) {
    for (int i = 0; i < NID; i++) {
        string copy;
        copy = ID[i];

        int pos = copy.find("THD");

        if (pos > 0 && pos < ID[i].length()) return 1;
    }
    return 0;
}

string BinarytoDecimal(const char c1, const char c2) {
    if (c1 == '0' && c2 == '0') return "0"; 
    else if (c1 == '0' && c2 == '1') return "1";
    else if (c1 == '1' && c2 == '0') return "2";
    return "3";
}

string reverseStr(string str) {
    reverse(str.begin(), str.end());
    return str;
}

string reverseOddEven(string str) {
    string result;
    if (str.length() % 2 == 0) {
        for (int i = str.length() - 1; i >= 0; i = i - 2) {
            result = result + str[i - 1] + str[i];
        }

        return result;
    }
    reverse(str.begin(), str.end());

    return str;
}

string DecimaltoChar(const string str, int count) {
    char c[4][7] = {{'E', 'F', 'G', 'H', 'I', 'J', 'K'},
                    {'L', 'M', 'N', 'O', 'P', 'Q', 'R'},
                    {'#', 'T', 'U', 'V', 'W', 'X', 'Y'},
                    {'@', 'A', 'S', 'Z', 'B', 'C', 'D'}};

    count %= 7;    //if count > 7 

    string temp;
    if (str[0] == '0') temp += c[0][count - 1];
    else if (str[0] == '1') temp += c[1][count - 1];
    else if (str[0] == '2') temp += c[2][count - 1];
    else temp += c[3][count - 1];

    return temp;
}

string giaiMa(const string str) {
    string result;

    for (int i = 0; i < str.length();) {
        if (str[i] != '#' && str[i] != '@') {
            result += str[i];
            i++;
        }
        else if (str[i] == '#') {
            string temp;
            i++;
            if (i >= str.length()) break;
            while (str[i] != '#' && str[i] != '@') {
                if (i >= str.length()) break;
                temp += str[i];
                i++;
            }
            if (str[i - 1] != 'Z') temp += (char)(str[i - 1] + 1);
            else temp += 'A';
            result += temp;
        }
        else if (str[i] == '@') {
            string temp;
            i++;
            if (i >= str.length()) break;
            while (str[i] != '#' && str[i] != '@') {
                if (i >= str.length()) break;
                temp += str[i];
                i++;
            }
            result += reverseStr(temp);
        }
    }

    return result;
}

string vua(string str) {
    string copy, result;
    copy = reverseOddEven(str);

    for (int i = 0; i < str.length(); i++) {
        if (str[i] > copy[i]) result += str[i];
        else result += copy[i];
    }
    return result;
}

string THD(string str) {
    for (int i = 0; i < str.length(); i = i + 3) {
        str.erase(str.begin() + i);
    }

    sort(str.begin(), str.end());

    return str;
}

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1)
{
    string *dec = new string[N1];     //contains decimal strings
    string *trans = new string[N1];   //contains strings after translated
    string *decoded = new string[N1]; 
    string *result = new string();      //return result

    for (int i = 0; i < N1; i++) {  //translate every binary strings in input1[] to decimal strings
        for (int j = 0; j < input1[i].length(); j = j + 2) {
            if (input1[i][j] == ' ') {
                ++j;
                dec[i] += " ";
            }
            dec[i] += BinarytoDecimal(input1[i][j], input1[i][j + 1]);
        }
    }

    for (int i = 0; i < N1; i++) {  //translate every decimal strings to decoded strings
        string temp;
        for (int j = 0; j < dec[i].length();) {
            int count = 0;
            while (dec[i][j] != ' ') {
                if (j >= dec[i].length()) break;
                temp += dec[i][j];
                ++count;
                ++j;
            }
            trans[i] += DecimaltoChar(temp, count);
            temp.clear();
            ++j;
        }
    }

    if (findVua(ID, NID)) {
        for (int i = 0; i < N1; i++) {
            decoded[i] += vua(giaiMa(trans[i]));
        }
    }
    else if (findTHD(ID, NID)) {
        for (int i = 0; i < N1; i++) {
            decoded[i] += THD(giaiMa(trans[i]));
        }
    }
    else {
        for (int i = 0; i < N1; i++) {
            decoded[i] += giaiMa(trans[i]);
        }
    }
    
    for (int i = 0; i < N1; i++) {
        *result = *result + decoded[i] + " ";
    }

    return *result;
}

int decode(const string A, const string B)
{
    int count = 0;
    int pos = 0;
    while (pos < A.length() && pos >= 0) {
        pos = A.find(B, pos);
        if (pos >= 0 && pos < A.length()) {
            pos++;
            count++;
        }
    }
    return count;
    return -1;
}

string takeInput3(const string input3, int& N, int& B) {
    string S;
    int i = 0;
    string temp;
    while (input3[i] != ' ') {
        temp += input3[i];
        i++;
        if (i >= input3.length()) break;
    }
    N = stoi(temp);
    i++;
    if (i >= input3.length()) return S;
    temp.clear();

    while (input3[i] != ' ') {
        temp += input3[i];
        i++;
        if (i >= input3.length()) break;
    }
    B = stoi(temp);
    i++;
    if (i >= input3.length()) return S;

    while (input3[i] != '\0') {
        S += input3[i];
        i++;
    }

    return S;
}

void leftRotation(string& str, int d) {
    reverse(str.begin(), str.begin() + d);
    reverse(str.begin() + d, str.end());
    reverse(str.begin(), str.end());
}

void rightRotation(string& str, int d) {
    leftRotation(str, str.length() - d);
}

string findRoute(const string input3)
{
    int x = 0;
    int y = 0;
    int N;
    int B;
    string S;
    string result;

    S = takeInput3(input3, N, B); 
    if (B > 0) {
        B = B % S.length();
        rightRotation(S, B);
    } 
    else if (B < 0) {
        B = abs(B);
        B = B % S.length();
        leftRotation(S, B);
    }
    string route;
    for (int i = 0; i < S.length(); i++) {
        int change = abs(N - 2 * i);

        if (change % 4 == 0) {
            route += S[i];
        }
        else if (change % 3 == 0) {
            if (S[i] == 'U') route += 'R';
            else if (S[i] == 'D') route += 'U';
            else if (S[i] == 'L') route += 'D';
            else route += 'L';
        }
        else if (change % 2 == 0) {
            if (S[i] == 'U') route += 'L';
            else if (S[i] == 'D') route += 'R';
            else if (S[i] == 'L') route += 'U';
            else route += 'D';
        }
        else if (change % 1 == 0) {
            if (S[i] == 'U') route += 'D';
            else if (S[i] == 'D') route += 'L';
            else if (S[i] == 'L') route += 'R';
            else route += 'U';
        }
    }
    
    for (int i = 0; i < route.length(); i++) {
        if (route[i] == 'U') ++y;
        else if (route[i] == 'D') --y;
        else if (route[i] == 'R') ++x;
        else --x;
    }
    string a = to_string(x);
    string b = to_string(y);
    result = result + "(" + a + "," + b + ")";

    return result;
}

int countV(const string A) {
    int count = 0;

    for (int i = 0; i < A.length(); i = i + 2) {
        if (A[i] == 'V') count++;
        if (A[i] == '0') break;
    }

    return count;
}

string decodeVfunction(const string A, const string B)
{
    string result;
    if (A == "0" || B == "0") return "0";

    int a = countV(A);
    int b = countV(B);
    int NumberofV = a * b;

    for (int i = 0; i < NumberofV; i++) {
        result += "V(";
    }

    result += "0";

    for (int i = 0; i < NumberofV; i++) {
        result += ")";
    }

    return result;
}

int findIndex(char arr[], char a) {
    for (int i = 0; i < 26; i++) {
        if (a == arr[i]) return i;
    }
    return -1;
}

int findMax(int arr[]) {
    int max = arr[0];
    int k = 0;
    for (int i = 1; i < 26; i++) {
        if (arr[i] > max) {
            max = arr[i];
            k = i;
        }
    }
    arr[k] = 0;
    return k;
}

string findBetrayals(const string input5[], const int N5)
{   
    string result;
    char arr[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
                    'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                    'W', 'X', 'Y', 'Z'};
    int b[26] = { 0 };
    for (int i = 0; i < N5; i++) {
        for (int j = 0; j < input5[i].length(); j++) {
            int a = findIndex(arr, input5[i][j]);
            b[a] += (6 - j);
        }
    }
    for (int i = 0; i < 3; i++) {
        int k = findMax(b);
        result += arr[k];
    }

    return result;
}

int calculateStrength(const string str) {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        string temp;
        temp += str[i];
        sum += stoi(temp);
    }
    return sum;
}

bool check2(const string str) {
    for (int i = 0; i < 10; i++) {
        if (str[i] == '2') return true;
    }
    return false;
}

int attack(const string input6[])
{
    int strength[10] = { 0 };
    for (int i = 0; i < 10; i++) {
        if (check2(input6[i])) strength[i] += 21;
        else strength[i] += calculateStrength(input6[i]);
    }

    int k = 0;

    for (int i = 1; i < 10; i++) {
        if (strength[i] <= strength[k]) k = i;
    }
    
    if (strength[k] < 21) return k;
    return -1;
}

void takeInput7Str(const string input7Str, int& N7, int& V, int& i, int& j) {
    string temp;
    int idx = 0;
    while (input7Str[idx] != ' ') {
        temp += input7Str[idx];
        idx++;
        if (idx >= input7Str.length()) break;
    }
    N7 = stoi(temp);
    temp.clear();
    idx++;
    if (idx >= input7Str.length()) return;

    while (input7Str[idx] != ' ') {
        temp += input7Str[idx];
        idx++;
        if (idx >= input7Str.length()) break;
    }
    V = stoi(temp);
    temp.clear();
    idx++;
    if (idx >= input7Str.length()) return;

    while (input7Str[idx] != ' ') {
        temp += input7Str[idx];
        idx++;
        if (idx >= input7Str.length()) break;
    }
    i = stoi(temp);
    temp.clear();
    idx++;
    if (idx >= input7Str.length()) return;

    while (input7Str[idx] != '\0') {
        temp += input7Str[idx];
        idx++;
        if (idx >= input7Str.length()) break;
    }
    j = stoi(temp);
    temp.clear();
    idx++;
    if (idx >= input7Str.length()) return;
}

void multiply(int N7, int **A1, int **A2, int **res) {
    for (int i = 0; i < N7; i++) {
        for (int j = 0; j < N7; j++) {
            *(*(res + i) + j) = 0;
            for (int k = 0; k < N7; k++) {
                *(*(res + i) + j) += *(*(A1 + i) + k) * *(*(A2 + k) + j);
            }
        }
    }
}

void copyArray(int N7, int **A, int **res) {
    for (int i = 0; i < N7; i++) {
        for (int j = 0; j < N7; j++) {
            *(*(res + i) + j) = *(*(A + i) + j);
        }
    }
}

int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k)
{
    int N7 = -1;
    int V = -1;
    int i = -1;
    int j = -1;

    takeInput7Str(input7Str, N7, V, i, j);

    int **A = new int*[N7];
    for (int a = 0; a < N7; a++) {
        A[a] = new int[N7];
    }

    int **B = new int*[N7];
    for (int a = 0; a < N7; a++) {
        B[a] = new int[N7];
    }

    int **copy = new int*[N7];
    for (int a = 0; a < N7; a++) {
        copy[a] = new int[N7];
    }

    string temp;
    for (int a = 0; a < k; a++) {
        int idx = 0;
        for (int b = 0; b < N7; b++) {
            for (int c = 0; c < N7; c++) {
                while (input7Matrix[a][idx] != ' ' && input7Matrix[a][idx] != '\0') {
                    temp += input7Matrix[a][idx];
                    idx++;
                }
                A[b][c] = stoi(temp);
                idx++;
                if (idx >= input7Matrix[a].length()) break;
                temp.clear();
            }
        }
        if (a == 0) copyArray(N7, A, copy);
        if (a > 0) {
            multiply(N7, copy, A, B);
            copyArray(N7, B, copy);
        }
    }

    int R = -1;
    R = *(*(B + i) + j) % V;
    return R;
}

#endif /* MONGOL_H */
