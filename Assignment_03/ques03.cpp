#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Matrix {
protected:
    int rows;
    int cols;

    vector<vector<T> > data;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows);
        for (int i = 0; i < rows; ++i) {
            data[i].resize(cols);
        }
    }

    void setValue(int row, int col, T value) {
        data[row][col] = value;
    }

    T getValue(int row, int col) {
        return data[row][col];
    }

    Matrix<T> operator+(Matrix<T>& other) {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator-(Matrix<T>& other) {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator*(Matrix<T>& other) {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] * other.data[i][j];
            }
        }
        return result;
    }

    virtual void display() {
        cout << "Matrix Display" << endl << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    };
};

template <typename T>
class IntMatrix : public Matrix<T> {
public:
    IntMatrix(int rows, int cols) : Matrix<T>(rows, cols) {}

    void display() override {
        cout << "Int Matrix Display" << endl << endl;
        for (int i = 0; i < this->rows; ++i) {
            for (int j = 0; j < this->cols; ++j) {
                cout << this->data[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

template <typename T>
class DoubleMatrix : public Matrix<T> {
public:
    DoubleMatrix(int rows, int cols) : Matrix<T>(rows, cols) {}
    void display() override {
        cout << "Double Matrix Display" << endl << endl;
        for (int i = 0; i < this->rows; ++i) {
            for (int j = 0; j < this->cols; ++j) {
                cout << this->data[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    IntMatrix<int> intMatrix1(2, 2);
    IntMatrix<int> intMatrix2(2, 2);

    intMatrix1.setValue(0, 0, 1);
    intMatrix1.setValue(0, 1, 2);
    intMatrix1.setValue(1, 0, 3);
    intMatrix1.setValue(1, 1, 4);

    intMatrix2.setValue(0, 0, 5);
    intMatrix2.setValue(0, 1, 6);
    intMatrix2.setValue(1, 0, 7);
    intMatrix2.setValue(1, 1, 8);

    intMatrix1.display();
    intMatrix2.display();

    Matrix<int> intResultAdd = intMatrix1 + intMatrix2;
    intResultAdd.display();

    Matrix<int> intResultSub = intMatrix1 - intMatrix2;
    intResultSub.display();

    Matrix<int> intResultMul = intMatrix1 * intMatrix2;
    intResultMul.display();

    DoubleMatrix<double> doubleMatrix1(2, 2);
    DoubleMatrix<double> doubleMatrix2(2, 2);

    doubleMatrix1.setValue(0, 0, 1.5);
    doubleMatrix1.setValue(0, 1, 2.5);
    doubleMatrix1.setValue(1, 0, 3.5);
    doubleMatrix1.setValue(1, 1, 4.5);

    doubleMatrix2.setValue(0, 0, 5.5);
    doubleMatrix2.setValue(0, 1, 6.5);
    doubleMatrix2.setValue(1, 0, 7.5);
    doubleMatrix2.setValue(1, 1, 8.5);

    doubleMatrix1.display();
    doubleMatrix2.display();

    Matrix<double> doubleResultAdd = doubleMatrix1 + doubleMatrix2;
    doubleResultAdd.display();

    Matrix<double> doubleResultSub = doubleMatrix1 - doubleMatrix2;
    doubleResultSub.display();

    Matrix<double> doubleResultMul = doubleMatrix1 * doubleMatrix2;
    doubleResultMul.display();

    return 0;
}
