#include<bits/stdc++.h>

using namespace std;

//[Q1.5]
bool isPalindrome(const char* str) {
    int len = 0;

    for (; *(str + len) != '\0'; len++) {
        
    }

    bool result = true;
    
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            result = false;
            break; 
        }
    }

    return result;
}

//[Q1.6]
bool isPrime(int n) {
    if (n < 2) return false;
    if (n < 4) return true;
    
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}

bool isSpecialNumber(int n) {
    // Write your code 
    int specialSum = 0;
    int nCopy = n;
    
    while (nCopy > 0) {
        specialSum += nCopy % 10;
        nCopy /= 10;
    }
    
    return (isPrime(specialSum) && isPrime(n));
}

//[Q1.7]
bool checkElementsUniqueness(int* arr, int n) {
    // Write your code 
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) return false;
        }
    }
    
    return true;
}

//[Q1.10]
void encrypt(char* text, int shift) {
    // Write your code 
    shift %= 26;
    for (int i = 0; *(text + i) != '\0'; i++) {
        if (*(text + i) >= 'A' && *(text + i) <= 'Z') {
            int newChar = (*(text + i) + shift - 'A') % 26;
            *(text + i) = newChar + 'A';
        } else {
            int newChar = (*(text + i) + shift - 'a') % 26;
            *(text + i) = newChar + 'a';
        }   
    }
}

void decrypt(char* text, int shift) {
    //Write your code
    shift %= 26;
    for (int i = 0; *(text + i) != '\0'; i++) {
        if (*(text + i) >= 'A' && *(text + i) <= 'Z') {
            int newChar = (*(text + i) + 26 - shift - 'A') % 26;
            *(text + i) = newChar + 'A';
        } else {
            int newChar = (*(text + i) + 26 - shift - 'a') % 26;
            *(text + i) = newChar + 'a';
        }   
    }
}

//[Q2.7]
long int decimalToBinary(int decimal_number)
{
    if (decimal_number < 2) return decimal_number;
    
    return decimalToBinary(decimal_number / 2) * 10 + decimal_number % 2;
}

bool checkDuplicate(int* ar, int size) {
    if (size < 2) return true;

    if (checkDuplicate(ar, size - 1)) {
        for (int i = 0; i < size; i++) {
            if (ar[i] == ar[size]) {
                return false;
            }
        }
    }

    return checkDuplicate(ar, size - 1);
}

//[Q2.4]
int recursiveSearch(int& n, int m, int arr[], int index) {
    if (!n) return -1;
    if (index < n) {
        if (m == 0) {
            if (index + 1 < n) arr[index] = arr[index + 1];
            return recursiveSearch(n, 0, arr, index + 1);
        }
        else if (arr[index] == m) {
            recursiveSearch(n, 0, arr, index);
            n--;
            return index;
        } else {
            return recursiveSearch(n, m, arr, index + 1);
        }  
    } else {
        return -1;
    }
}

//[Q3.4]
void add(int *ptr, int n, int k)
{
    *(ptr + n) = k;
}

//[Q3.3]
void add(int *ptr, int n, int k)
{
    *(ptr + n) = k;
}

int main() {
    int arr[] = {1, 5, 3, 4, 5};

    cout << checkDuplicate(arr, 5) << endl;

    return 0;
}

