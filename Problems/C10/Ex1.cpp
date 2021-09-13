#include<ctime>
#include<iostream>

using namespace std;

void foo1(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10000; j++) {
            int sum = 0;
            sum = sum + j;
        }
    }
}

void foo2(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= 1; k++) {
                int sum = 0;
                sum = sum + k;
            }
        }
    }
}

int main() {
    int n = 100000;

    // clock_t start1 = clock();
    // foo1(n);
    // clock_t end1 = clock();

    // double overallTime1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC;

    clock_t start2 = clock();
    foo2(n);
    clock_t end2 = clock();

    double overallTime2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC;


    cout << overallTime2 << endl;

    return 0;
}