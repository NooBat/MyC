#include <bits/stdc++.h>

using namespace std;

//[Q1.2]
int calculateFactorial(int n) {
    if (n < 2) return 1;
    
    return n * calculateFactorial(n - 1);
}

// int main(int narg, char** argv)
// {
//     int N;
//     cin >> N;
//     long result;
//     result = long(calculateFactorial(N));

//     cout << result << endl;
//     return 0;
// }

//[Q1.3]
int findMax(int *vals, int numEls) {
    if (numEls == 1) return *vals;
    
    int a = *(vals + numEls - 1);
    int b = findMax(vals, numEls - 1);
    
    return (a > b) ? (a) : (b);
}

//[Q1.4]
void sum2(int * array, int numEls, int &result)
{
    if (numEls == 1) {
        result += *array;
        return;
    }
    result += *(array + numEls - 1);
    sum2(array, numEls - 1, result);
}

//[Q1.1]
int sumOfDivisors(int N) {
    if (N < 4) return 1;
    
    int sum = 1;
    
    for (int i = 2; i < N; i++) {
        if (N % i == 0) {
            sum += i;
        }
    }
    
    return sum;
}

bool completeNum(int N)
{
    if (N < 6) return false;
    return sumOfDivisors(N) == N;
}

//[Q2.2]
int gcdRecursion(int p, int q)
{
    if (p > q) {
        int a = p;
        p = q;
        q = a;
    }
    
    if (!p) return q;
    return gcdRecursion(q % p, p);
}

int gcdIteration(int p, int q)
{
    int gcd = 1;
    if (p == q) return p;
    else if (p > q) {
        for (int i = 1; i <= p; i++) {
            if (p % i == 0 && i <= q && q % i == 0) {
                gcd = i;
            }
        }
    } else {
        for (int i = 1; i <= q; i++) {
            if (q % i == 0 && i <= p && p % i == 0) {
                gcd = i;
            }
        }
    }
    
    return gcd;
}

int main() {
    cout << gcdRecursion(10, 0) << " " << gcdIteration(6, 10);
}

//[Q2.5]
int strLen(char* str)     
{      
    if (*str == '\0') return 0;
    
    return 1 + strLen(str + 1);
}

//[Q2.6]
void printPattern(int n)
{
    cout << n << " ";
    if (n > 0) {
        printPattern(n - 5);
    } else if (n <= 0) {
        return;
    }
    
    cout << n << " ";
}

//[Q3.1]
int getValueAtIndex(int *ptr, int k)
{
    if (k == 0) return *ptr;
    
    return getValueAtIndex(ptr + 1, k - 1);
}

//[Q3.2]
void swap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}