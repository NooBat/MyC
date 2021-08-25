#include<iostream>

using namespace std;

int sumArray(int a[], int n) {
    int result = 0;
    for (int i = 0;  i < n; i++) {
        result += a[i];
    }
    return result;
}

void copyArray(int dest[], int n, int src[]) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void countCoins(int a[], int n, int b[], int idx, int result[], int money, int& min) {
    if (idx > n - 1) {
        int count = sumArray(b, n);
        if (count < min && money == 0) {
            min = count;
            copyArray(result, n, b);
        }
    }
    else {
        for (int i = 0; i <= money / a[idx]; i++) {
            b[idx] = i;
            countCoins(a, n, b, idx + 1, result, money - (a[idx] * b[idx]), min);
        }
    }
}
void splitMoney(int a[], int n, int money) {
    int* b = new int[n];
    int* result = new int[n];
    int min = money + 1;
    countCoins(a, n, b, 0, result, money, min);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ": " << result[i] << endl;
    }
}

int main() {
    int money;
    cout << "Input money: "; 
    cin >> money;
    
    int n;
    cout << "Input number of currencies: ";
    cin >> n;

    int a[n];
    cout << "Input currencies: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    splitMoney(a, n, money);
    return 0;
}