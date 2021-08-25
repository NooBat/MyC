#ifndef FRACTION_CPP
#define FRACTION_CPP

#include<iostream>
#include<math.h>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction() {

    }

    Fraction(int num, int den) {
        numerator = num;
        setDenominator(den);
    }

    Fraction(const Fraction& other) {
        this->numerator = other.numerator;
        this->setDenominator(other.denominator);
    }

    void setNumerator(const int num) {
        numerator = num;
    }

    void setDenominator(const int den) {
        if (den > 0) {
            denominator = den;
        } 
        else if (den < 0) {
            denominator = -den;
            numerator = -numerator;
        }
        else {
            throw "Denominator cannot be zero!\n";
        }
    }

    int getNumerator() {
        return numerator;
    }

    int getDenominator() {
        return denominator;
    }

    void print() {
        cout << numerator << "/" << denominator << endl;
    }

    void reduce() {
        int k = 1;
        for (int i = 2; i <= abs(min(numerator, denominator)); i++) {
            if (numerator % i == 0 && denominator % i == 0) k = i;
        }

        numerator /= k;
        denominator /= k;
    }

    Fraction getReciprocal() {
        int temp = numerator;
        numerator = denominator;
        denominator = temp;
        reduce();

        return *this;
    }

    Fraction operator+ (const Fraction& other) {
        Fraction temp(other);
        setDenominator(denominator);
        Fraction result;

        if (this->denominator == other.denominator) {
            result.numerator = numerator + temp.numerator;
            result.setDenominator(denominator);

            result.reduce();

            return result;
        }
        else {
            int LCM = max(denominator, temp.denominator);
            int x = 1;
            int y = 1;

            for (int i = 2; i <= min(denominator, temp.denominator); i++) {
                for (int j = i; j <= max(denominator, temp.denominator); j++) {
                    if (min(denominator, temp.denominator) * j > max(denominator, temp.denominator) * i) break;
                    else if (min(denominator, temp.denominator) * j == max(denominator, temp.denominator) * i) {
                        x = i;
                        y = j;
                        break;
                    }
                }
                if (min(denominator, temp.denominator) * y == max(denominator, temp.denominator) * x) break;
            }
            LCM *= x;
            if (denominator > temp.denominator) {
                result.numerator = numerator * x + temp.numerator * y;
            }
            else {
                result.numerator = numerator * y + temp.numerator * x;
            }

            result.denominator = LCM;
        }
        result.reduce();

        return result;
    }

    Fraction operator+ (const int& rhs) {
        this->numerator += rhs * this->denominator;

        reduce();

        return *this;
    }
    
    Fraction operator- (const Fraction& other) {
        Fraction temp(other);
        setDenominator(denominator);

        temp.numerator = -temp.numerator;
        return *this + temp;
    }

    Fraction operator* (const Fraction& other) {
        Fraction result;
        result.setNumerator(numerator * other.numerator);
        result.setDenominator(denominator * other.denominator);

        result.reduce();

        return result;
    }

    Fraction operator/ (const Fraction& other) {
        Fraction result;
        Fraction temp(other);
        temp.getReciprocal();

        result.setNumerator(numerator * temp.numerator);
        result.setDenominator(denominator * temp.denominator);

        result.reduce();

        return result;
    }

    Fraction operator= (const Fraction& other) {
        numerator = other.numerator;
        denominator = other.denominator;

        return *this;
    }

    friend ostream& operator<< (ostream& output, const Fraction& F);

    friend Fraction operator+ (const int& lhs, const Fraction& rhs);
};

ostream& operator<< (ostream& output, const Fraction& F) {
    output << F.numerator << "/" << F.denominator << endl;
    return output;
}

Fraction operator+ (const int& lhs, const Fraction& rhs) {
    Fraction result;
    result.numerator = rhs.numerator + rhs.denominator * lhs;
    result.denominator = rhs.denominator;

    return result;
}
#endif