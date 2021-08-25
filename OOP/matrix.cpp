#ifndef MATRIX_CPP
#define MATRIX_CPP

#include<bits/stdc++.h>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    double *data;

public:
    Matrix() {
        data = new double[0];
        cols = 0;
        rows = 0;
    }

    Matrix(int col, int row) {
        data = new double[col * row];
        this->cols = col;
        this->rows = row;
    }

    Matrix(const Matrix& other) {
        data = new double[other.rows * other.cols];

        this->cols = other.cols;
        this->rows = other.rows;

        if (other.data != NULL) {
            for (int rows = 0; rows < other.rows; ++rows) {
                for (int cols = 0; cols < other.cols; ++cols) {
                    int index = other.cols * rows + cols;
                    this->data[index] = other.data[index];
                }
            }
        }
    }

    Matrix(int nrows, int ncols, double *data_ptr, int count) {
        data = new double[nrows * ncols];

        cols = ncols;
        rows = nrows;

        for (int i = 0; i < count; i++) {
            this->data[i] = data_ptr[i];
        }
    }

    ~Matrix() {
        delete[] data;
    }

    void set(int x, int y, double value) {
        int index = this->cols * x + y;
        data[index] = value;
    }

    double get(int x, int y) {
        int index = this->cols * x + y;
        return data[index];
    }

    void print()
    {
        if (this->data == NULL) // STUDENT_ANSWER
        {
            cout << "[]" << endl;
            return;
        };
        cout << "[" << endl;
        for (int rows = 0; rows < this->rows; ++rows) // STUDENT_ANSWER
        {
            for (int cols = 0; cols < this->cols; ++cols) // STUDENT_ANSWER
            {
                int index = this->cols * rows + cols;
                cout << fixed << setw(5) << setprecision(2)
                     << this->data[index] // STUDENT_ANSWER
                     << " ";
            }
            cout << endl;
        }
        cout << ']' << endl;
    }

    Matrix operator= (const Matrix& rhs) {
        this->cols = rhs.cols;
        this->rows = rhs.rows;

        this->data = new double[this->cols * this->rows];

        for (int rows = 0; rows < this->rows; ++rows) {
            for (int cols = 0; cols < this->cols; ++cols) {
                int index = this->cols * rows + cols;

                this->data[index] = rhs.data[index];
            }
        }

        return *this;
    }

    Matrix operator+ (const Matrix& rhs) {
        
        if (this->cols != rhs.cols || this->rows != rhs.rows) {
            throw invalid_argument("");
        }

        Matrix result = Matrix(this->cols, this->rows);

        for (int rows = 0; rows < this->rows; ++rows) {
            for (int cols = 0; cols < this->cols; ++cols) {
                int index = this->cols * rows + cols;
                result.data[index] = this->data[index] + rhs.data[index];
            }
        }

        return result;
    }

    Matrix operator+ (const double& rhs) {
        Matrix result = Matrix(this->cols, this->rows);

        for (int rows = 0; rows < this->rows; ++rows) {
            for (int cols = 0; cols < this->cols; ++cols) {
                int index = this->cols * rows + cols;
                result.data[index] = this->data[index] + rhs;
            }
        }

        return result;       
    }

    friend Matrix operator+ (const double& lhs, const Matrix& rhs);

    Matrix T() {
        if (this->data == NULL) return *this;

        Matrix temp = Matrix(this->rows, this->cols);
        for (int rows = 0; rows < this->rows; ++rows) {
            for (int cols = 0; cols < this->cols; ++cols) {
                int index1 = this->cols * rows + cols;
                int index2 = this->rows * cols + rows;
                temp.data[index2] = this->data[index1];
            }
        }
        this->~Matrix();
        *this = Matrix(temp.cols, temp.rows);
        for (int rows = 0; rows < temp.rows; ++rows) {
            for (int cols = 0; cols < temp.cols; ++cols) {
                int index1 = temp.cols * rows + cols;
                this->data[index1] = temp.data[index1];
            }
        }
        return *this;
    }

    static Matrix T(const Matrix& other) {
        Matrix result = Matrix(other.rows, other.cols);
        for (int rows = 0; rows < other.rows; ++rows) {
            for (int cols = 0; cols < other.cols; ++cols) {
                int index1 = other.cols * rows + cols;
                int index2 = other.rows * cols + rows;
                result.data[index2] = other.data[index1];
            }
        }
        return result;
    }  

    friend ostream& operator<< (ostream& output, const Matrix& other);
};

Matrix operator+ (const double& lhs, const Matrix& rhs) {
    Matrix result = Matrix(rhs.cols, rhs.rows);

    for (int rows = 0; rows < result.rows; ++rows) {
        for (int cols = 0; cols < result.cols; ++cols) {
            int index = result.cols * rows + cols;
            result.data[index] = rhs.data[index] + lhs;
        }
    }

    return result;
}

ostream& operator<< (ostream& output, const Matrix& other) {
    if (other.data == NULL) // STUDENT_ANSWER
    {
        output << "[]" << endl;
        return output;
    };
    output << "[" << endl;
    for (int rows = 0; rows < other.rows; ++rows) // STUDENT_ANSWER
    {
        for (int cols = 0; cols < other.cols; ++cols) // STUDENT_ANSWER
        {
            int index = other.cols * rows + cols;
            output << fixed << setw(5) << setprecision(2)
                    << other.data[index] // STUDENT_ANSWER
                    << " ";
        }
        output << endl;
    }
    output << ']' << endl;

    return output;
}
#endif