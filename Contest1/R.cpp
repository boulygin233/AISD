#include <math.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>

class BigIntegerOverflow {
};

class BigInteger {
    friend BigInteger operator+(const BigInteger &, const BigInteger &);

    friend BigInteger operator-(const BigInteger &, const BigInteger &);

    friend BigInteger operator*(const BigInteger &, const BigInteger &);

    friend BigInteger operator/(const BigInteger &, const BigInteger &);

    friend BigInteger operator%(const BigInteger &, const BigInteger &);

    friend int operator==(const BigInteger &, const BigInteger &);

    friend int operator<(const BigInteger &, const BigInteger &);

    friend int operator>(const BigInteger &, const BigInteger &);

    friend std::ostream &operator<<(std::ostream &, const BigInteger &);

    friend std::istream &operator>>(std::istream &, BigInteger &);

    friend BigInteger Substraction(const BigInteger &, const BigInteger &);

    friend BigInteger Addition(const BigInteger &, const BigInteger &);

    friend BigInteger abs(const BigInteger &);

private:
    int *Number;
    int Sign;
    int NumberCount;
    int Size = 300;
public:
    BigInteger();

    BigInteger(char *const);

    BigInteger(const long long &);

    BigInteger(const unsigned long long &);

    BigInteger(const int &);

    BigInteger(const unsigned int &);

    BigInteger(const BigInteger &);

    BigInteger &operator=(const BigInteger &);

    ~BigInteger();

    BigInteger &operator++();

    BigInteger &operator+=(const BigInteger &Value);

    BigInteger &operator-=(const BigInteger &Value);

    BigInteger &operator--();

    BigInteger operator++(int i);

    BigInteger operator--(int i);

    BigInteger operator-();
};

int sign(const int &Value) {
    if (Value >= 0) {
        return 1;
    }
    return -1;
}

BigInteger abs(const BigInteger &Value) {
    BigInteger New = Value;
    New.Sign = 1;
    return New;
}

BigInteger Substraction(const BigInteger &Value1, const BigInteger &Value2) {
    BigInteger New = Value1;
    int NewLen = std::max(Value1.NumberCount, Value2.NumberCount);
    for (int i = 0; i < NewLen; ++i) {
        if (New.Number[i] >= Value2.Number[i]) {
            New.Number[i] -= Value2.Number[i];
        } else {
            New.Number[i] -= (Value2.Number[i] - 10);
            New.Number[i + 1] -= 1;
        }
    }
    int zero = NewLen - 1;
    while (!New.Number[zero] && zero) {
        --New.NumberCount;
        --zero;
    }
    return New;
}

BigInteger Addition(const BigInteger &Value1, const BigInteger &Value2) {
    BigInteger New = Value1;
    int NewLen = std::max(Value1.NumberCount, Value2.NumberCount);
    for (int i = 0; i < NewLen; ++i) {
        if (New.Number[i] + Value2.Number[i] >= 10) {
            New.Number[i] = (New.Number[i] + Value2.Number[i]) % 10;
            New.Number[i + 1] += 1;
            if (i + 1 == NewLen) {
                ++New.NumberCount;
            }
        } else {
            New.Number[i] += Value2.Number[i];
        }
    }
    return New;
}

BigInteger::BigInteger() {
    NumberCount = 1;
    Number = new int[Size];
    Number[0] = 0;
    Sign = 1;
    for (int i = NumberCount; i < Size; ++i) {
        Number[i] = 0;
    }
}

BigInteger::BigInteger(const long long &Value) {
    NumberCount = 0;
    Number = new int[Size];
    Sign = sign(Value);
    long long New = std::abs(Value);
    if (!New) {
        NumberCount = 1;
        Number[0] = 0;
    }
    while (New) {
        Number[NumberCount] = New % 10;
        New /= 10;
        ++NumberCount;
    }
    for (int i = NumberCount; i < Size; ++i) {
        Number[i] = 0;
    }
}

BigInteger::BigInteger(const unsigned long long &Value) {
    NumberCount = 0;
    Number = new int[Size];
    Sign = 1;
    unsigned long long New = Value;
    if (!New) {
        NumberCount = 1;
        Number[0] = 0;
    }
    while (New) {
        Number[NumberCount] = New % 10;
        New /= 10;
        ++NumberCount;
    }

    for (int i = NumberCount; i < Size; ++i) {
        Number[i] = 0;
    }
}

BigInteger::BigInteger(const int &Value) {
    NumberCount = 0;
    Number = new int[Size];
    Sign = sign(Value);
    int New = std::abs(Value);
    if (!New) {
        NumberCount = 1;
        Number[0] = 0;
    }
    while (New) {
        Number[NumberCount] = New % 10;
        New /= 10;
        ++NumberCount;
    }

    for (int i = NumberCount; i < Size; ++i) {
        Number[i] = 0;
    }
}

BigInteger::BigInteger(const unsigned int &Value) {
    NumberCount = 0;
    Number = new int[Size];
    Sign = 1;
    unsigned int New = Value;
    if (!New) {
        NumberCount = 1;
        Number[0] = 0;
    }
    while (New) {
        Number[NumberCount] = New % 10;
        New /= 10;
        ++NumberCount;
    }

    for (int i = NumberCount; i < Size; ++i) {
        Number[i] = 0;
    }
}

BigInteger::BigInteger(char *const Str) {
    int size = 0;
    int k = 0;
    while (Str[k] != '\0') {
        ++size;
        ++k;
    }
    NumberCount = size;
    Number = new int[Size];
    if (Str[0] == '-') {
        Sign = -1;
        NumberCount -= 1;
        for (int i = 1; i < size; ++i) {
            Number[NumberCount - i] = Str[i] - 48;
        }
    } else {
        Sign = 1;
        for (int i = 0; i < size; ++i) {
            Number[NumberCount - 1 - i] = Str[i] - 48;
        }
    }

    for (int i = NumberCount; i < Size; ++i) {
        Number[i] = 0;
    }
}

BigInteger::BigInteger(const BigInteger &Value) {
    NumberCount = Value.NumberCount;
    Number = new int[Size];
    Sign = Value.Sign;
    for (int i = 0; i < NumberCount; ++i) {
        Number[i] = Value.Number[i];
    }

    for (int i = NumberCount; i < Size; ++i) {
        Number[i] = 0;
    }
}

BigInteger::~BigInteger() {
    delete[] Number;
}

BigInteger &BigInteger::operator=(const BigInteger &Value) {
    NumberCount = Value.NumberCount;
    Number = new int[Size];
    Sign = Value.Sign;
    for (int i = 0; i < NumberCount; ++i) {
        Number[i] = Value.Number[i];
    }

    for (int i = NumberCount; i < Size; ++i) {
        Number[i] = 0;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const BigInteger &Value) {
    if (Value.Sign == -1) {
        std::cout << '-';
    }
    for (int i = 0; i < Value.NumberCount; ++i) {
        std::cout << Value.Number[Value.NumberCount - i - 1];
    }
    if (Value.NumberCount == 0) {
        std::cout << 0;
    }
    return out;
}

std::istream &operator>>(std::istream &in, BigInteger &Value) {
    char *Str = new char[30010];
    std::cin >> Str;
    int size = strlen(Str);
    Value.NumberCount = size;
    delete[] Value.Number;
    Value.Number = new int[Value.Size];
    if (Str[0] == '-') {
        Value.Sign = -1;
        Value.NumberCount -= 1;
        for (int i = 1; i < size; ++i) {
            Value.Number[Value.NumberCount - i] = Str[i] - 48;
        }
    } else {
        Value.Sign = 1;
        for (int i = 0; i < size; ++i) {
            Value.Number[Value.NumberCount - 1 - i] = Str[i] - 48;
        }
    }
    for (int i = Value.NumberCount; i < Value.Size; ++i) {
        Value.Number[i] = 0;
    }
    delete[] Str;
    return in;
}

int operator<(const BigInteger &Value1, const BigInteger &Value2) {
    if (Value1.Sign > Value2.Sign) {
        return 0;
    } else if (Value1.Sign < Value2.Sign) {
        return 1;
    } else {
        if ((Value1.NumberCount < Value2.NumberCount && Value1.Sign == 1) ||
            (Value1.NumberCount > Value2.NumberCount && Value1.Sign == -1)) {
            return 1;
        } else if ((Value1.NumberCount > Value2.NumberCount && Value1.Sign == 1) ||
                   (Value1.NumberCount < Value2.NumberCount && Value1.Sign == -1)) {
            return 0;
        } else {
            for (int i = Value1.NumberCount - 1; i >= 0; --i) {
                if ((Value1.Number[i] < Value2.Number[i] && Value1.Sign == 1) ||
                    (Value1.Number[i] > Value2.Number[i] && Value1.Sign == -1)) {
                    return 1;
                } else if ((Value1.Number[i] > Value2.Number[i] && Value1.Sign == 1) ||
                           (Value1.Number[i] < Value2.Number[i] && Value1.Sign == -1)) {
                    return 0;
                }
            }
            return 0;
        }
    }
}

int operator>(const BigInteger &Value1, const BigInteger &Value2) {
    return Value2 < Value1;
}

int operator==(const BigInteger &Value1, const BigInteger &Value2) {
    if (Value1.NumberCount != Value2.NumberCount || Value1.Sign != Value2.Sign) {
        return 0;
    } else {
        for (int i = Value1.NumberCount - 1; i >= 0; --i) {
            if (Value1.Number[i] != Value2.Number[i]) {
                return 0;
            }
        }
        return 1;
    }
}

int operator<=(const BigInteger &Value1, const BigInteger &Value2) {
    return (Value1 < Value2 || Value1 == Value2);
}

int operator>=(const BigInteger &Value1, const BigInteger &Value2) {
    return (Value2 <= Value1);
}

int operator!=(const BigInteger &Value1, const BigInteger &Value2) {
    return !(Value2 == Value1);
}

BigInteger operator-(const BigInteger &Value1, const BigInteger &Value2) {
    if (Value1.Sign == 1 && Value1.Sign == Value2.Sign) {
        if (Value1 > Value2 || Value1 == Value2) {
            return Substraction(Value1, Value2);
        } else {
            BigInteger New = Substraction(Value2, Value1);
            New.Sign = -1;
            return New;
        }
    } else if (Value1.Sign == -1 && Value1.Sign == Value2.Sign) {
        if (Value1 < Value2) {
            BigInteger New = Substraction(abs(Value1), abs(Value2));
            New.Sign = -1;
            return New;
        } else {
            return Substraction(abs(Value2), abs(Value1));
        }
    } else if (Value1.Sign == -1) {
        if (abs(Value1) > Value2) {
            BigInteger New = Addition(abs(Value1), abs(Value2));
            New.Sign = -1;
            return New;
        } else {
            BigInteger New = Addition(abs(Value2), abs(Value1));
            New.Sign = -1;
            return New;
        }
    } else {
        if (Value1 > abs(Value2)) {
            return Addition(Value1, abs(Value2));
        } else {
            return Addition(abs(Value2), Value1);
        }
    }
}


BigInteger operator+(const BigInteger &Value1, const BigInteger &Value2) {
    if (Value1.Sign == 1 && Value2.Sign == 1) {
        if (Value1 > Value2) {
            return Addition(Value1, Value2);
        } else {
            return Addition(Value2, Value1);
        }
    } else if (Value1.Sign == -1 && Value2.Sign == -1) {
        if (Value1 < Value2) {
            BigInteger New = Addition(abs(Value1), abs(Value2));
            New.Sign = -1;
            return New;
        } else {
            BigInteger New = Addition(abs(Value2), abs(Value1));
            New.Sign = -1;
            return New;
        }
    } else if (Value1.Sign == 1) {
        return Value1 - abs(Value2);
    } else {
        return Value2 - abs(Value1);
    }
}


BigInteger &BigInteger::operator++() {
    (*this) = (*this) + 1;
    return *this;
}

BigInteger &BigInteger::operator--() {
    (*this) = (*this) - 1;
    return *this;
}

BigInteger BigInteger::operator++(int i) {
    BigInteger New = *this;
    (*this) = (*this) + 1;
    return New;
}

BigInteger BigInteger::operator--(int i) {
    BigInteger New = *this;
    (*this) = (*this) - 1;
    return New;
}

BigInteger &BigInteger::operator+=(const BigInteger &Value) {
    (*this) = (*this) + Value;
    return *this;
}

BigInteger &BigInteger::operator-=(const BigInteger &Value) {
    (*this) = (*this) - Value;
    return *this;
}

BigInteger BigInteger::operator-() {
    BigInteger New = *this;
    if (New != 0) {
        New.Sign *= -1;
    }
    return New;
}

BigInteger operator*(const BigInteger &Value1, const BigInteger &Value2) {
    BigInteger New;
    New.NumberCount = Value1.NumberCount + Value2.NumberCount;
    if (New.NumberCount > New.Size) {
        throw BigIntegerOverflow();
    }
    for (int i = 0; i < Value1.NumberCount + Value2.NumberCount + 2; ++i) {
        New.Number[i] = 0;
    }
    if (Value1 < Value2) {
        for (int i = Value1.NumberCount; i < Value2.NumberCount + 1; ++i) {
            Value1.Number[i] = 0;
        }
    } else if (Value1 > Value2) {
        for (int i = Value2.NumberCount; i < Value1.NumberCount + 1; ++i) {
            Value2.Number[i] = 0;
        }
    }
    for (int i = 0; i < Value1.NumberCount; ++i) {
        for (int j = 0; j < Value2.NumberCount; ++j) {
            New.Number[i + j] += (Value1.Number[i] * Value2.Number[j]) % 10;
            New.Number[i + j + 1] += (Value1.Number[i] * Value2.Number[j]) / 10;
        }
    }
    for (int i = 0; i < New.NumberCount; ++i) {
        New.Number[i + 1] += New.Number[i] / 10;
        New.Number[i] %= 10;
    }
    while (New.Number[New.NumberCount - 1] == 0 && New.NumberCount > 1) {
        --New.NumberCount;
    }

    if (New != 0 && (Value2.Sign * Value1.Sign < 0)) {
        New.Sign = -1;
    }
    return New;
}

BigInteger operator/(const BigInteger &Value1, const BigInteger &Value2) {
    BigInteger Result;
    if (Value1 < Value2) {
        Result = 0;
        return Result;
    }
    BigInteger New = Value1;
    int Size = Value1.NumberCount - Value2.NumberCount;
    Result.NumberCount = Size + 1;
    Result.Number[Result.NumberCount - 1] = 0;
    if (!Size) {
        Result.NumberCount = 1;
    }
    BigInteger SubNew;
    while (New > Value2 || New == Value2) {
        BigInteger Val;
        Val.Sign = Value2.Sign;
        Val.NumberCount = Value2.NumberCount + Size;
        for (int i = 0; i < Size; ++i) {
            Val.Number[i] = 0;
        }
        for (int i = 0; i < Value2.NumberCount; ++i) {
            Val.Number[i + Size] = Value2.Number[i];
        }
        SubNew = Val;
        int i = 0;
        while (New > SubNew || New == SubNew) {
            New = New - SubNew;
            ++i;
        }
        Result.Number[Size] = i;
        --Size;
    }
    while (Result.Number[Result.NumberCount - 1] == 0 && Result.NumberCount > 1) {
        --Result.NumberCount;
    }
    return Result;
}

BigInteger operator%(const BigInteger &Value1, const BigInteger &Value2) {
    return Value1 - (Value1 / Value2) * Value2;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    BigInteger a;
    std::cin >> a;
    BigInteger X;
    BigInteger left = 0, right = a;
    while (left <= right) {
        BigInteger Result = (left + right) / 2;
        if (Result * Result <= a) {
            X = Result;
            left = Result + 1;
        } else {
            right = Result - 1;
        }
    }
    std::cout << X;
}

