#include "Ex4.h"

#include<vector>
#include<iostream>

void display(const Polynomial& polynomial) {
    vector<vector<int> > v = polynomial.toVector();

    cout << v[0][0] << "x" << v[0][1] << " ";

    for (int i = 1; i < v.size(); i++) {
        if (v[i][1] == 0) {
            if (v[i][0] > 0) cout << "+ " << v[i][0];
            else cout << "- " << -v[i][0];
        }
        else {
            if (v[i][0] > 0) cout << "+ " << v[i][0] << "x" << v[i][1] << " ";
            else cout << "- " << -v[i][0] << "x" << v[i][1] << " ";
        }
    }
    
    cout << endl;
}

void polynomialTester(Polynomial& polynomial) {
    cout << "This should be 1" << endl;
    cout << "Polymial: ";
    display(polynomial);
    cout << endl << endl;

    cout << "changeCoefficient(4, 5)" << endl;;
    polynomial.changeCoefficient(4, 5);
    display(polynomial);
    cout << endl << endl;

    polynomial.changeCoefficient(7, 3);
    polynomial.changeCoefficient(-1, 2);
    polynomial.changeCoefficient(9, 0);
    display(polynomial);
    cout << endl << endl;

    polynomial.changeCoefficient(4, 4);
    display(polynomial);
    cout << endl << endl;

    polynomial.changeCoefficient(100, 2);
    display(polynomial);
    cout << endl << endl;
}

int main() {
    cout << "Testing Polynomial-ADT: " << endl;

    Polynomial polynomial;

    polynomialTester(polynomial);

    cout << "All done!" << endl;

    return 0;
}