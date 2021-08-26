#include<iostream>
#include<fstream>
#include<vector>

using namespace std;


int sumArray(int a[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += a[i];
    }
    return result;
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void countCoins(int a[], int n, int b[], int idx, int money, int& min, int result[]) {
    if (idx > n - 1) {
        int count = sumArray(b, n);
        if (count < min && money == 0) {
            min = count;

            copyArray(b, result, n);
        }
    }
    else {
        for (int i = 0; i <= (money) / a[idx]; i++) {
            b[idx] = i;
            countCoins(a, n, b, idx + 1, money - (b[idx] * a[idx]), min, result);
        }
    }

}

void splitMoney(int a[], int n, int money) {
    int* b = new int[n];
    int* result = new int[n];
    int min = money + 1;
    countCoins(a, n, b, 0, money, min, result);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ": " << result[i] << endl;
    }
}

// int main() {

// 	ifstream InputFile("input_3.txt");
// 	vector<int> a;
// 	while (true) {
// 		int temp;
// 		InputFile >> temp;
// 		a.push_back(temp);
// 		if (temp == 1) {
// 			break;
// 		}
// 	}
// 	int money;
// 	InputFile >> money;
// 	InputFile.close();

// 	int* arr = new int[a.size()];
// 	for (int i = 0; i < a.size(); i++) {
// 		arr[i] = a[i];
// 	}
// 	int n = a.size();

// 	splitMoney(arr, n, 72); 
// }
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