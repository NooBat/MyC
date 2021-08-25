#include<iostream>

using namespace std;

void indent(int tab) {
    for (int i = 0; i < tab; i++) {
        cout << "\t";
    }
}

int rabbit(int n, int tab = 0) {
    int value;

    indent(tab);
    cout << "Enter rabbit: n = " << n << "\n"; 

    if (n <= 2) { 
        value = 1;  
    } 
    else {
        value = rabbit(n - 1, tab + 1) + rabbit(n - 2, tab + 1);
    }
    
    indent(tab);
    cout << "Leaving rabbit: n = " << n << " value = " << value << endl;
    return value;
}

int main() {
    rabbit(4);

    return 0;
}
