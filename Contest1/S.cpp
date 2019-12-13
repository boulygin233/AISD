#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class RationalDivisionByZero {
};

long long NOD(long long x, long long y) {
    long long a = x, b = y;
    while (a > 0 && b > 0) {
        if (a >= b) {
            a = a % b;
        }
        else {
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
        }
        else {
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

    Rational& operator=(const Rational &Value) {
        p = Value.getNumerator();
        q = Value.getDenominator();
        return *this;
    }

    friend Rational operator+(const Rational &Value1, const Rational &Value2) {
        long long Numerator = Value1.getNumerator() * Value2.getDenominator() + Value2.getNumerator() * Value1.getDenominator();
        long long Denominator = Value1.getDenominator() * Value2.getDenominator();
        Rational New(Numerator, Denominator);
        return New;
    };

    friend Rational operator-(const Rational &Value1, const Rational &Value2) {
        long long Numerator = Value1.getNumerator() * Value2.getDenominator() - Value2.getNumerator() * Value1.getDenominator();
        long long Denominator = Value1.getDenominator() * Value2.getDenominator();
        Rational New(Numerator, Denominator);
        return New;
    };

    friend Rational operator*(const Rational &Value1, const Rational &Value2) {
        long long Numerator = Value1.getNumerator() *  Value2.getNumerator();
        long long Denominator = Value1.getDenominator() * Value2.getDenominator();
        Rational New(Numerator, Denominator);
        return New;
    };

    friend int operator==(const Rational &Value1, const Rational &Value2){
        return (Value1.getNumerator() == Value2.getNumerator() && Value1.getDenominator() == Value2.getDenominator())? 1 : 0;
    };

    friend int operator<(const Rational &Value1, const Rational &Value2) {
        return  ((Value1 - Value2).getNumerator() < 0) ? 1 : 0;
    };

    friend int operator>(const Rational &Value1, const Rational &Value2){
        return (Value2 < Value1)? 1 : 0;
    };

    friend int operator>=(const Rational &Value1, const Rational &Value2){
        return ((Value2 < Value1) || (Value1 == Value2))? 1 : 0;
    };

    friend int operator<=(const Rational &Value1, const Rational &Value2){
        return ((Value2 > Value1) || (Value1 == Value2))? 1 : 0;
    };

    friend int operator!=(const Rational &Value1, const Rational &Value2){
        return ((Value1 == Value2) + 1) % 2;
    }

    friend std::ostream &operator<<(std::ostream &out, const Rational &R) {
        if (R.getNumerator() == 0 || R.getDenominator() == 1) {
            cout<<R.getNumerator();
        }
        else {
            cout<<R.getNumerator()<<'/'<<R.getDenominator();
        }
	return out;
    }

    friend Rational operator/(const Rational &Value1, const Rational &Value2){
        if (Value2 == 0) {
            throw RationalDivisionByZero();
        }
        else {
            long long Numerator = Value1.getNumerator() * Value2.getDenominator();
            long long Denominator = Value1.getDenominator() * Value2.getNumerator();
            return Rational(Numerator, Denominator);
        }
    };

    Rational &operator++(){
        *this = (*this) + 1;
        return *this;
    };

    Rational &operator+=(const Rational &Value){
        *this = *this + Value;
        return *this;
    };

    Rational &operator-=(const Rational &Value){
        *this = *this - Value;
        return *this;
    };

    Rational &operator*=(const Rational &Value){
        *this = *this * Value;
        return *this;
    };

    Rational &operator/=(const Rational &Value){
        *this = *this / Value;
        return *this;
    };

    Rational &operator--(){
        *this = (*this) - 1;
        return *this;
    };

    Rational operator++(int i) {
        Rational New = *this;
        *this = *this + 1;
        return New;
    };

    Rational operator--(int i){
        Rational New = *this;
        *this = *this - 1;
        return New;
    };

    Rational operator-() const{
        Rational New = *this;
        New *= (-1);
        return New;
    };

    Rational operator+() {
        return *this;
    };

    friend std::istream &operator>>(std::istream &in, Rational &R) {
        char Str[15];
        cin>>Str;
        int i = 0;
        for (i = 0; i < strlen(Str); ++i){
            if (Str[i] == '/') {
                break;
            }
        }
        if (i == strlen(Str)){
            R = Rational(atoi(Str));
        }
        else {
            R = Rational(atoi(Str), atoi(Str + i + 1));
        }
        return in;
    };

};

int main(int argc, char **argv) {
    int a;
    cin >> a;

    int p, q;
    cin >> p >> q;
    const Rational rc(p, q); // q != 0 is guaranteed by author of tests
    cout << rc.getNumerator() << ' ' << rc.getDenominator() << endl;

    Rational r1, r2;
    cin >> r1 >> r2;

    cout << r1 << endl;
    cout << r2 << endl;

    try {
        cout << 1 / r1 << endl;
    } catch (const RationalDivisionByZero &ex) {
        cout << "Cannot get reciprocal of r1." << endl;
    }

    try {
        cout << rc / r2 << endl;
    } catch (const RationalDivisionByZero &ex) {
        cout << "Cannot divide by r2." << endl;
    }

    cout << (r1 < r2) << endl;
    cout << (r1 <= r2) << endl;
    cout << (r1 > r2) << endl;
    cout << (r1 >= r2) << endl;
    cout << (r1 == r2) << endl;
    cout << (r1 != r2) << endl;

    cout << (r1 < a) << endl;
    cout << (r1 <= a) << endl;
    cout << (r1 > a) << endl;
    cout << (r1 >= a) << endl;
    cout << (r1 == a) << endl;
    cout << (r1 != a) << endl;

    cout << (a < r2) << endl;
    cout << (a <= r2) << endl;
    cout << (a > r2) << endl;
    cout << (a >= r2) << endl;
    cout << (a == r2) << endl;
    cout << (a != r2) << endl;

    cout << rc + a << endl
         << a + rc << endl
         << -rc * r1 << endl
         << (+r1 - r2 * rc) * a << endl;

    cout << ++r1 << endl;
    cout << r1 << endl;
    cout << r1++ << endl;
    cout << r1 << endl;
    cout << --r1 << endl;
    cout << r1 << endl;
    cout << r1-- << endl;
    cout << r1 << endl;
    cout << ++ ++r1 << endl;
    cout << r1 << endl;

    cout << ((((r1 += r2) /= Rational(-5, 3)) -= rc) *= a) << endl;
    cout << (r1 += r2 /= 3) << endl;
    cout << r1 << endl;
    cout << r2 << endl;
    return 0;
}
