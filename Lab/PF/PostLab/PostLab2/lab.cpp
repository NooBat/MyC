#include<bits/stdc++.h>

using namespace std;

//[Q1.9]
void mostFrequentCharacter(char* str, char& res, int& freq) {
    for (char temp = 'a'; temp <= 'z'; temp++) {
        int count = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            char lowerChar;
            if (str[i] < 'a') {
                lowerChar = str[i] + 32;
            } else {
                lowerChar = str[i];
            }
            
            if (lowerChar == temp) count++;
        }
        
        if (count > freq) {
            freq = count;
            res = temp;
        }
    }
}

//[Q1.8]
int pow(int n, int m) {
    int result = 1;
    
    for (int i = 0; i < m; i++) {
        result *= n;
    }
    
    return result;
}

int convertToBaseM(int n, int m=2) {
    int result = 0;
    
    for (int i = 0; n > 0; i++) {
        result += pow(10, i) * (n % m);
        n /= m;
    }
    
    return result;
}

//[Q2.3]
bool palindromeRecursion(string s)
{
    // BEGIN YOUR IMPLEMENTATION [1]
    // TODO
    if (s.length() <= 1) return true;
    
    return (s[0] == s[s.length() - 1]) && palindromeRecursion(s.substr(1, s.length() - 2));
    // END YOUR EMPLEMENTATION [1]
}

int main()
{
    hiddenCheck();
    // BEGIN YOUR IMPLEMENTATION [2]
    // TODO
    string line;
    while (getline(cin, line)) {
        if (line[0] == '*') break;
        cout << (palindrome(line) ? ("true ") : ("false ")) << (palindromeRecursion(line) ? ("true") : ("false")) << endl;
    }
    // END YOUR EMPLEMENTATION [2]
    return 0;
}

//[Q2.8]
int countWaySumOfSquare(int x)
{
	/*
	* STUDENT ANSWER
	*/
	if (x <= 0) return 0;
    if (x == 1) return 1;
	
	int sqrtInt = sqrt(x);

    if (int(sqrt(x - pow(sqrtInt  - 1, 2))))
    
    if (x - pow(sqrtInt, 2) == 0) return 1 + countWaySumOfSquare(x - pow(sqrtInt - 1, 2));
    else return countWaySumOfSquare(x - pow(sqrtInt, 2));
	
	return 0;
}

//[Q3.5]
int findMax(int *ptr, int n)
{
    int max = *ptr;
    for (int i = 1; i < n; i++) {
        if (*(ptr + i) >  max) {
            max = *(ptr + i);
        }
    }
    
    return max;
}

//[Q3.7]
bool isSymmetry(int *head, int *tail)
{
    if (head >= tail) return true;
    
    return (*head == *tail) && isSymmetry(head + 1, tail - 1);
}

//[Q3.6]
void reverse(int *ptr, int n)
{
    for (int i = 0; i < n / 2; i++) {
        swap(*(ptr + i), *(ptr + n - 1 - i));
    }
}