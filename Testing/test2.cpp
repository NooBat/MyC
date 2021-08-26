#include<iostream>

using namespace std;

int main() {
    int money;
    cin >> money;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int min = 10000000;

    for (int i = 0; i <= money / 25; i++) {
        for (int j = 0; j <= money / 10; j++) {
            for (int k = 0; k <= money / 5; k++) {
                for (int l = 0; l <= money / 2; l++) {
                    for (int m = 0; m <= money; m++) {
                        int tmp = money;
                        tmp = tmp - m - (2 * l) - (5 * k) - (10 * j) - (25 * i);
                        if (tmp == 0) {
                            int n = m + l + k + j + i;
                            if (n < min) {
                                min = n;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << min;
    return 0;
}