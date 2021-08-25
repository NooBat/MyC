#ifndef VECTOR_CPP
#define VECTOR_CPP

#include<iostream>

using namespace std;

class Vector {
private:
    double *data;
    int dim;

public:
    Vector() {
        data = new double[3];
        dim = 3;

        for (int i = 0; i < 3; i++) {
            data[i] = 0.0;
        }
    }

    Vector(int dim) {
        this->dim = dim;

        data = new double[dim];

        for (int i = 0; i < dim; i++) {
            data[i] = 0.0;
        }
    }
    
    Vector(int dim, double *data) {
        this->dim = dim;

        this->data = new double[dim];

        for (int i = 0; i < dim; i++) {
            this->data[i] = data[i];
        }
    }

    Vector(const Vector& other) {
        this->dim = other.dim;

        data = new double[dim];

        for (int i = 0; i < dim; i++) {
            this->data[i] = other.data[i];
        }
    }   

    ~Vector() {
        delete[] data;
    }

    int getDim() {
        return dim;
    }

    double getData(int pos) {
        if (pos >= dim) {
            throw invalid_argument("Out of range");
        }
        else return data[pos];
    }

    Vector setData(double* data) {
        data = new double[dim];
        for (int i = 0; i < dim; i++) {
            this->data[i] = data[i];
        }

        return *this;
    }

    void setData(int pos, double value) {
        if (pos >= dim) {
            dim++;
            data = new double[dim];
            data[dim - 1] = value; 
            return;
        }
        data = new double[dim];
        data[pos] = value;
    }
    
    Vector operator+ (const Vector& rhs) {
        if (dim != rhs.dim) {
            throw invalid_argument("Two dimensions are not matched");
        }
        Vector result(dim);

        result.data = new double[dim];

        for (int i = 0; i < dim; i++) {
            result.data[i] = this->data[i] + rhs.data[i];
        }

        return result;
    }

    Vector operator- (const Vector& rhs) {
        if (dim != rhs.dim) {
            throw invalid_argument("Two dimensions are not matched");
        }
        Vector result(dim);

        result.data = new double[dim];

        for (int i = 0; i < dim; i++) {
            result.data[i] = this->data[i] - rhs.data[i];
        }

        return result;
    }

    double operator* (const Vector& rhs) {
        if (dim != rhs.dim) {
            throw invalid_argument("Two dimensions are not matched");
        }

        double result = 0.0;

        for (int i = 0; i < dim; i++) {
            result += this->data[i] * rhs.data[i];
        }

        return result;
    }

    void print() {
        for (int i = 0; i < this->dim; i++) {
            cout << this->data[i] << " ";
        }

        cout << endl;
    }
};
#endif