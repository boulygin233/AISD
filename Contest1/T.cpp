#include <iostream>
#include <cstdlib>
#include <cstring>

class MatrixAllocationError {
};

class MatrixWrongSizeError {
};

class MatrixIndexError {
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

private:
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

    Matrix operator=(const Matrix Value) {
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

    int GetColumnsNumber() const {
        return ColumnsNumber;
    }

    int GetRowsNumber() const {
        return RowsNumber;
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
        if (RowsNumber != Value.ColumnsNumber || ColumnsNumber != Value.RowsNumber) {
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
        Matrix New = Value1;
        New += Value2;
        return New;
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
        Matrix New = *this;
        New.transpose();
        return New;
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
    int m, n, p, q;
    cin >> m >> n >> p >> q;

    Matrix<int> A(m, n), B(p, q);
    cin >> A >> B;

    A = A;
    try {
        cout << A + B * 2 - m * A << endl;
        cout << (A -= B += A *= 2) << endl;
        cout << (((A -= B) += A) *= 2) << endl;
    } catch (const MatrixWrongSizeError &) {
        cout << "A and B are of different size." << endl;
    }
    B = A;

    {
        Matrix<int> AA(A);
        Matrix<int> AAA(1, 1);
        AAA = A;
        cout << AA << endl;
        cout << (AAA += Matrix<int>(m, n)) + B << endl;
    }

    Rational r;
    cin >> r;
    Matrix<Rational> C(m, n), D(p, q);
    cin >> C >> D;
    try {
        cout << C * D << endl;
        cout << (C *= D) << endl;
        cout << C << endl;
    } catch (const MatrixWrongSizeError &) {
        cout << "C and D have not appropriate sizes for multiplication." << endl;
    }
    cout << C.getTransposed() * (r * C) << endl;
    cout << C.transpose() << endl;
    try {
        (C(0, 0) *= 6) /= 3;
        cout << C(0, 0) << endl;
        cout << C(m, m) << endl;
    } catch (const MatrixIndexError &) {
        cout << "Index out of range." << endl;
    }

    {
        const Matrix<Rational> &rC = C;
        cout << rC << endl;
        cout << rC.GetRowsNumber() << ' ' << rC.GetColumnsNumber() << ' ' << rC(0, 0) << endl;
        cout << (C = C) * (Rational(1, 2) * rC).getTransposed() << endl;
    }
    return 0;
}
