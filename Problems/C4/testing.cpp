#include "Ex4.h"

#include<vector>
#include<iostream>

void display(const Polynomial& polynomial) {
    vector<vector<int> > v = polynomial.toVector();


    for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
            if (v[i][1] == 0) cout << v[i][0] << " ";
            else if (v[i][1] == 1) cout << v[i][0] << "x ";
            else cout << v[i][0] << "x^" << v[i][1] << " ";
        }
        else {
            if (v[i][1] == 1) {
                if (v[i][0] > 0) cout << "+ " << v[i][0] << "x ";
                else cout << "- " << -v[i][0] << "x ";
            }
            else if (v[i][1] == 0) {
                if (v[i][0] > 0) cout << "+ " << v[i][0] << " ";
                else cout << "- " << -v[i][0] << " ";
            }
            else {
                if (v[i][0] > 0) cout << "+ " << v[i][0] << "x^" << v[i][1] << " ";
                else cout << "- " << -v[i][0] << "x^" << v[i][1] << " ";
            }
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

    cout << "Create a second polynomial: ";
    Polynomial p2;
    p2.changeCoefficient(-7, 6);
    p2.changeCoefficient(-4, 5);
    p2.changeCoefficient(2, 1);
    display(p2);
    cout << endl << endl;

    cout << "The sum of two polynomial is: ";
    Polynomial result(polynomial.sumOfPolynomial(p2));
    display(result);
}

int main() {
    cout << "Testing Polynomial-ADT: " << endl;

    Polynomial polynomial;

    polynomialTester(polynomial);

    cout << "All done!" << endl;

    return 0;
}