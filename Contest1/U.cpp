#include <iostream>
#include <cstdlib>
#include <cstring>

class MatrixAllocationError {
};

class MatrixWrongSizeError {
};

class MatrixIndexError {
};

class MatrixIsDegenerateError {
};


//=============== Matrix class ===============//

using namespace std;

template<typename T>
class Matrix {
    friend ostream &operator<<(ostream &out, const Matrix &Value) {
        for (int i = 0; i < Value.RowsNumber; ++i) {
            for (int j = 0; j < Value.ColumnsNumber; ++j) {
                cout << Value.MatrixData[i][j] << " ";
            }
            cout << '\n';
        }
        return out;
    }

    friend istream &operator>>(istream &in, Matrix &Value) {
        for (int i = 0; i < Value.RowsNumber; ++i) {
            for (int j = 0; j < Value.ColumnsNumber; ++j) {
                cin >> Value.MatrixData[i][j];
            }
        }
        return in;
    }

protected:
    int RowsNumber;
    int ColumnsNumber;
    T **MatrixData;

public:
    Matrix(int n, int m) : RowsNumber(n), ColumnsNumber(m) {
        MatrixData = new T *[n];
        for (int i = 0; i < n; ++i) {
            MatrixData[i] = new T[m];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                MatrixData[i][j] = 0;
            }
        }
    }

    Matrix(const Matrix &Value) : RowsNumber(Value.RowsNumber), ColumnsNumber(Value.ColumnsNumber) {
        MatrixData = new T *[RowsNumber];
        for (int i = 0; i < RowsNumber; ++i) {
            MatrixData[i] = new T[ColumnsNumber];
        }
        for (int i = 0; i < RowsNumber; ++i) {
            for (int j = 0; j < ColumnsNumber; ++j) {
                MatrixData[i][j] = Value.MatrixData[i][j];
            }
        }
    }

    Matrix operator=(const Matrix &Value) {
        if (this == &Value) {
            return *this;
        }
        RowsNumber = Value.RowsNumber;
        ColumnsNumber = Value.ColumnsNumber;
        MatrixData = new T *[RowsNumber];
        for (int i = 0; i < RowsNumber; ++i) {
            MatrixData[i] = new T[ColumnsNumber];
        }
        for (int i = 0; i < RowsNumber; ++i) {
            for (int j = 0; j < ColumnsNumber; ++j) {
                MatrixData[i][j] = Value.MatrixData[i][j];
            }
        }
        return *this;
    }

    ~Matrix() {
        for (int i = 0; i < RowsNumber; ++i) {
            delete[] MatrixData[i];
        }
        delete[] MatrixData;
    }

    T &operator()(int i, int j) {
        if (i >= RowsNumber || j >= ColumnsNumber) {
            throw MatrixIndexError();
        }
        return MatrixData[i][j];
    }

    T operator()(int i, int j) const {
        if (i >= RowsNumber || j >= ColumnsNumber) {
            throw MatrixIndexError();
        }
        return MatrixData[i][j];
    }

    template<typename S>
    Matrix &operator*=(S x) {
        for (int i = 0; i < RowsNumber; ++i) {
            for (int j = 0; j < ColumnsNumber; ++j) {
                MatrixData[i][j] *= x;
            }
        }
        return *this;
    }

    Matrix &operator*=(const Matrix &Value) {
        if (ColumnsNumber != Value.RowsNumber) {
            throw MatrixWrongSizeError();
        }
        Matrix New = *this;
        *this = Matrix(New.RowsNumber, Value.ColumnsNumber);
        for (int i = 0; i < RowsNumber; ++i) {
            for (int j = 0; j < ColumnsNumber; ++j) {
                for (int k = 0; k < New.ColumnsNumber; ++k) {
                    MatrixData[i][j] += New.MatrixData[i][k] * Value.MatrixData[k][j];
                }
            }
        }
        return *this;
    }

    friend Matrix operator*(const Matrix &Value1, const Matrix &Value2) {
        Matrix New = Value1;
        New *= Value2;
        return New;
    }

    Matrix &operator+=(const Matrix &Value) {
        if (RowsNumber != Value.RowsNumber || ColumnsNumber != Value.ColumnsNumber) {
            throw MatrixWrongSizeError();
        }
        for (int i = 0; i < RowsNumber; ++i) {
            for (int j = 0; j < ColumnsNumber; ++j) {
                MatrixData[i][j] += Value.MatrixData[i][j];
            }
        }
        return *this;
    }

    Matrix &operator-=(const Matrix &Value) {
        if (RowsNumber != Value.RowsNumber || ColumnsNumber != Value.ColumnsNumber) {
            throw MatrixWrongSizeError();
        }
        for (int i = 0; i < RowsNumber; ++i) {
            for (int j = 0; j < ColumnsNumber; ++j) {
                MatrixData[i][j] -= Value.MatrixData[i][j];
            }
        }
        return *this;
    }

    template<typename S>
    friend Matrix operator*(const Matrix &Value, S x) {
        Matrix New = Value;
        New *= x;
        return New;
    }

    template<typename S>
    friend Matrix operator*(S x, const Matrix &Value) {
        Matrix New = Value;
        New *= x;
        return New;
    }

    friend Matrix operator+(const Matrix &Value1, const Matrix &Value2) {
        Matrix res = Value1;
        res += Value2;
        return res;
    }

    friend Matrix operator-(const Matrix &Value1, const Matrix &Value2) {
        Matrix New = Value1;
        New -= Value2;
        return New;
    }

    Matrix &transpose() {
        Matrix New = *this;
        *this = Matrix(New.ColumnsNumber, New.RowsNumber);
        for (int i = 0; i < RowsNumber; ++i) {
            for (int j = 0; j < ColumnsNumber; ++j) {
                MatrixData[i][j] = New.MatrixData[j][i];
            }
        }
        return *this;
    }

    Matrix getTransposed() {
        Matrix res = *this;
        res.transpose();
        return res;
    }
};
//=============== SquareMatrix class ===============//

template<typename T>
class SquareMatrix : public Matrix<T> {
private:
public:
    SquareMatrix(int n) : Matrix<T>::Matrix(n, n) {
    }

    SquareMatrix(const SquareMatrix &A) : Matrix<T>::Matrix(A) {
    }

    SquareMatrix(const Matrix<T> &A) : Matrix<T>::Matrix(A) {
    }

    SquareMatrix operator=(const SquareMatrix &Value) {
        if (this == &Value) {
            return *this;
        }
        Matrix<T>::RowsNumber = Value.RowsNumber;
        Matrix<T>::ColumnsNumber = Value.ColumnsNumber;
        Matrix<T>::MatrixData = new T *[Matrix<T>::RowsNumber];
        for (int i = 0; i < Value.RowsNumber; ++i) {
            Matrix<T>::MatrixData[i] = new T[Matrix<T>::ColumnsNumber];
        }
        for (int i = 0; i < Matrix<T>::RowsNumber; ++i) {
            for (int j = 0; j < Matrix<T>::ColumnsNumber; ++j) {
                Matrix<T>::MatrixData[i][j] = Value.MatrixData[i][j];
            }
        }
        return *this;
    }

    ~SquareMatrix() {
    }

    int getSize() const {
        return Matrix<T>::RowsNumber;
    }

    SquareMatrix &operator*=(const SquareMatrix Value) {
        if (Matrix<T>::RowsNumber != Value.ColumnsNumber) {
            throw MatrixWrongSizeError();
        }
        SquareMatrix New = *this;
        *this = SquareMatrix(New.RowsNumber);
        for (int i = 0; i < Matrix<T>::RowsNumber; ++i) {
            for (int j = 0; j < Matrix<T>::ColumnsNumber; ++j) {
                for (int k = 0; k < New.ColumnsNumber; ++k) {
                    Matrix<T>::MatrixData[i][j] += New.MatrixData[i][k] * Value.MatrixData[k][j];
                }
            }
        }
        return *this;
    }

    friend SquareMatrix operator*(const SquareMatrix &Value1, const SquareMatrix &Value2) {
        SquareMatrix New(Value1);
        New *= Value2;
        return New;
    }

    template<typename S>
    SquareMatrix &operator*=(S x) {
        for (int i = 0; i < Matrix<T>::RowsNumber; ++i) {
            for (int j = 0; j < Matrix<T>::ColumnsNumber; ++j) {
                Matrix<T>::MatrixData[i][j] *= x;
            }
        }
        return *this;
    }

    template<typename S>
    friend SquareMatrix operator*(S x, const SquareMatrix &Value) {
        SquareMatrix New(Value);
        New *= x;
        return New;
    }

    friend Matrix<T> operator*(const Matrix<T> &Value1, const SquareMatrix &Value2) {
        Matrix<T> New1 = Value1;
        Matrix<T> New2 = Value2;
        return New1 * New2;
    }

    friend SquareMatrix operator+(const SquareMatrix &Value1, const SquareMatrix &Value2) {
        SquareMatrix New(Value1);
        if (Value1.RowsNumber != Value2.RowsNumber) {
            throw MatrixWrongSizeError();
        }
        for (int i = 0; i < New.RowsNumber; ++i) {
            for (int j = 0; j < New.ColumnsNumber; ++j) {
                New.MatrixData[i][j] += Value2.MatrixData[i][j];
            }
        }
        return New;
    }

    friend SquareMatrix operator-(const SquareMatrix &Value1, const SquareMatrix &Value2) {
        SquareMatrix New(Value1);
        if (Value1.RowsNumber != Value2.RowsNumber) {
            throw MatrixWrongSizeError();
        }
        for (int i = 0; i < New.RowsNumber; ++i) {
            for (int j = 0; j < New.ColumnsNumber; ++j) {
                New.MatrixData[i][j] -= Value2.MatrixData[i][j];
            }
        }
        return New;
    }

    T getTrace() const {
        T New = 0;
        for (int i = 0; i < Matrix<T>::RowsNumber; ++i) {
            New += Matrix<T>::MatrixData[i][i];
        }
        return New;
    }

    void SwapLine(int a, int b) {
        T x;
        for (int i = 0; i < Matrix<T>::RowsNumber; ++i) {
            x = Matrix<T>::MatrixData[a][i];
            Matrix<T>::MatrixData[a][i] = Matrix<T>::MatrixData[b][i];
            Matrix<T>::MatrixData[b][i] = x;
        }
    }

    T getDeterminant() const {
        SquareMatrix New = *this;
        T Determinant = 1;
        int sign = 1;
        for (int i = 0; i < New.RowsNumber - 1; ++i) {
            int Check = i;
            while (New.MatrixData[Check][i] == 0) {
                ++Check;
                if (Check >= New.RowsNumber) {
                    Determinant = 0;
                    return Determinant;
                }
            }
            if (Check != i) {
                New.SwapLine(Check, i);
                sign *= -1;
            }
            for (int j = i + 1; j < New.RowsNumber; ++j) {
                T x = New.MatrixData[j][i] / New.MatrixData[i][i];
                for (int k = i; k < New.RowsNumber; ++k) {
                    New.MatrixData[j][k] -= New.MatrixData[i][k] * x;
                }
            }
        }
        for (int i = 0; i < New.RowsNumber; ++i) {
            Determinant *= New.MatrixData[i][i];
        }
        Determinant *= sign;
        return Determinant;
    }

    SquareMatrix &invert() {
        if (getDeterminant() == 0) {
            throw MatrixIsDegenerateError();
        }
        SquareMatrix New = *this;
        *this = SquareMatrix(New.RowsNumber);
        for (int i = 0; i < New.RowsNumber; ++i) {
            Matrix<T>::MatrixData[i][i] = 1;
        }
        for (int i = 0; i < New.RowsNumber - 1; ++i) {
            int Check = i;
            while (New.MatrixData[Check][i] == 0) {
                ++Check;
            }
            if (Check != i) {
                New.SwapLine(Check, i);
                SwapLine(Check, i);
            }
            for (int j = i + 1; j < New.RowsNumber; ++j) {
                T x = New.MatrixData[j][i] / New.MatrixData[i][i];
                for (int k = i; k < New.RowsNumber; ++k) {
                    New.MatrixData[j][k] -= New.MatrixData[i][k] * x;
                }
                for (int k = 0; k < New.RowsNumber; ++k) {
                    Matrix<T>::MatrixData[j][k] -= Matrix<T>::MatrixData[i][k] * x;
                }
            }
        }
        for (int i = 1; i < New.RowsNumber; ++i) {
            for (int j = 0; j < i; ++j) {
                T x = New.MatrixData[j][i] / New.MatrixData[i][i];
                for (int k = i; k < New.RowsNumber; ++k) {
                    New.MatrixData[j][k] -= New.MatrixData[i][k] * x;
                }
                for (int k = 0; k < New.RowsNumber; ++k) {
                    Matrix<T>::MatrixData[j][k] -= Matrix<T>::MatrixData[i][k] * x;
                }
            }
        }
        for (int i = 0; i < New.RowsNumber; ++i) {
            if (New.MatrixData[i][i] != 1) {
                T x = New.MatrixData[i][i];
                New.MatrixData[i][i] /= x;
                for (int k = 0; k < New.RowsNumber; ++k) {
                    Matrix<T>::MatrixData[i][k] /= x;
                }
            }
        }
        return *this;
    }

    SquareMatrix getInverse() const {
        SquareMatrix New = *this;
        return New.invert();
    }

    SquareMatrix getTransposed() {
        return Matrix<T>::getTransposed();
    }
};




//================ class Rational ===============//

class RationalDivisionByZero {
};

long long NOD(long long x, long long y) {
    long long a = x, b = y;
    while (a > 0 && b > 0) {
        if (a >= b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return a + b;
}

class Rational {
private:
    long long p;
    long long q;


public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(long long x, long long y = 1) {
        long long N = NOD(abs(x), abs(y));
        if (x * y >= 0) {
            p = abs(x) / N;
            q = abs(y) / N;
        } else {
            p = -1 * abs(x) / N;
            q = abs(y) / N;
        }
    }


    ~Rational() = default;

    long long getNumerator() const {
        return p;
    }

    long long getDenominator() const {
        return q;
    }

    Rational &operator=(const Rational &Value) {
        p = Value.getNumerator();
        q = Value.getDenominator();
        return *this;
    }

    friend Rational operator+(const Rational &Value1, const Rational &Value2) {
        long long Numerator =
                Value1.getNumerator() * Value2.getDenominator() + Value2.getNumerator() * Value1.getDenominator();
        long long Denominator = Value1.getDenominator() * Value2.getDenominator();
        Rational New(Numerator, Denominator);
        return New;
    };

    friend Rational operator-(const Rational &Value1, const Rational &Value2) {
        long long Numerator =
                Value1.getNumerator() * Value2.getDenominator() - Value2.getNumerator() * Value1.getDenominator();
        long long Denominator = Value1.getDenominator() * Value2.getDenominator();
        Rational New(Numerator, Denominator);
        return New;
    };

    friend Rational operator*(const Rational &Value1, const Rational &Value2) {
        long long Numerator = Value1.getNumerator() * Value2.getNumerator();
        long long Denominator = Value1.getDenominator() * Value2.getDenominator();
        Rational New(Numerator, Denominator);
        return New;
    };

    friend int operator==(const Rational &Value1, const Rational &Value2) {
        return (Value1.getNumerator() == Value2.getNumerator() && Value1.getDenominator() == Value2.getDenominator())
               ? 1 : 0;
    };

    friend int operator<(const Rational &Value1, const Rational &Value2) {
        return ((Value1 - Value2).getNumerator() < 0) ? 1 : 0;
    };

    friend int operator>(const Rational &Value1, const Rational &Value2) {
        return (Value2 < Value1) ? 1 : 0;
    };

    friend int operator>=(const Rational &Value1, const Rational &Value2) {
        return ((Value2 < Value1) || (Value1 == Value2)) ? 1 : 0;
    };

    friend int operator<=(const Rational &Value1, const Rational &Value2) {
        return ((Value2 > Value1) || (Value1 == Value2)) ? 1 : 0;
    };

    friend int operator!=(const Rational &Value1, const Rational &Value2) {
        return ((Value1 == Value2) + 1) % 2;
    }

    friend std::ostream &operator<<(std::ostream &out, const Rational &R) {
        if (R.getNumerator() == 0 || R.getDenominator() == 1) {
            cout << R.getNumerator();
        } else {
            cout << R.getNumerator() << '/' << R.getDenominator();
        }
        return out;
    }

    friend Rational operator/(const Rational &Value1, const Rational &Value2) {
        if (Value2 == 0) {
            throw RationalDivisionByZero();
        } else {
            long long Numerator = Value1.getNumerator() * Value2.getDenominator();
            long long Denominator = Value1.getDenominator() * Value2.getNumerator();
            return Rational(Numerator, Denominator);
        }
    };

    Rational &operator++() {
        *this = (*this) + 1;
        return *this;
    };

    Rational &operator+=(const Rational &Value) {
        *this = *this + Value;
        return *this;
    };

    Rational &operator-=(const Rational &Value) {
        *this = *this - Value;
        return *this;
    };

    Rational &operator*=(const Rational &Value) {
        *this = *this * Value;
        return *this;
    };

    Rational &operator/=(const Rational &Value) {
        *this = *this / Value;
        return *this;
    };

    Rational &operator--() {
        *this = (*this) - 1;
        return *this;
    };

    Rational operator++(int i) {
        Rational New = *this;
        *this = *this + 1;
        return New;
    };

    Rational operator--(int i) {
        Rational New = *this;
        *this = *this - 1;
        return New;
    };

    Rational operator-() const {
        Rational New = *this;
        New *= (-1);
        return New;
    };

    Rational operator+() {
        return *this;
    };

    friend std::istream &operator>>(std::istream &in, Rational &R) {
        char Str[15];
        cin >> Str;
        int i = 0;
        for (i = 0; i < strlen(Str); ++i) {
            if (Str[i] == '/') {
                break;
            }
        }
        if (i == strlen(Str)) {
            R = Rational(atoi(Str));
        } else {
            R = Rational(atoi(Str), atoi(Str + i + 1));
        }
        return in;
    };

};


//=================== main() ===============//

using namespace std;

int main() {
    int m, n, p;
    Rational r;
    cin >> m >> n >> p >> r;

    Matrix<Rational> A(m, n);
    SquareMatrix<Rational> S(p);
    cin >> A >> S;

    try {
        cout << (A * S) * A.getTransposed() << endl;
    } catch (const MatrixWrongSizeError &) {
        cout << "A and S have not appropriate sizes for multiplication." << endl;
    }

    cout << (r * (S = S) * S).getSize() << endl;

    SquareMatrix<Rational> P(S);

    cout << (P * (S + S - 3 * P)).getDeterminant() << endl;

    const SquareMatrix<Rational> &rS = S;

    cout << rS.getSize() << ' ' << rS.getDeterminant() << ' ' << rS.getTrace() << endl;
    cout << (S = S) * (S + rS) << endl;
    cout << (S *= S) << endl;

    try {
        cout << rS.getInverse() << endl;
        cout << P.invert().getTransposed().getDeterminant() << endl;
        cout << P << endl;
    } catch (const MatrixIsDegenerateError &) {
        cout << "Cannot inverse matrix." << endl;
    }

    return 0;
}
