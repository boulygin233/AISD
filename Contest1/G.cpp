#include <iostream>
#include <cmath>

using namespace std;

bool Checker(double A_1, double B_1, double C_1, double A_2, double B_2, double C_2, double A_x, double A_y, double B_x, double B_y){
    double D = A_1 * B_2 - B_1 * A_2;
    double D1 = C_1 * B_2 - B_1 * C_2;
    double D2 = C_2 * A_1 - C_1 * A_2;
    double x = -D1 / D;
    double y = -D2 / D;
    bool f1;
    if (B_1 == 0) {
        if (A_y < B_y) {
            if (y <= B_y && y >= A_y) {
                f1 = true;
            } else {
                f1 = false;
            }
        } else {
            if (y >= B_y && y <= A_y) {
                f1 = true;
            } else {
                f1 = false;
            }
        }
    } else {
        if (A_x < B_x) {
            if (x >= A_x && x <= B_x) {
                f1 = true;
            } else {
                f1 = false;
            }
        } else {
            if (x <= A_x && x >= B_x) {
                f1 = true;
            } else {
                f1 = false;
            }
        }
    }
    if (f1) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    cout.setf(ios::fixed);
    cout.precision(10);
    double A_x, A_y, B_x, B_y, C_x, C_y, D_x, D_y;
    cin >> A_x >> A_y >> B_x >> B_y >> C_x >> C_y >> D_x >> D_y;
    double A_1, B_1, C_1;
    if (A_x != B_x) {
        A_1 = 1;
        if (A_y != B_y) {
            B_1 = (A_x - B_x) / (B_y - A_y);
        } else {
            A_1 = 0;
            B_1 = 1;
        }
    } else {
        A_1 = 1;
        B_1 = 0;
    }
    C_1 = -A_1 * A_x - B_1 * A_y;
    double A_2, B_2, C_2;
    if (C_x != D_x) {
        A_2 = 1;
        if (C_y != D_y) {
            B_2 = (C_x - D_x) / (D_y - C_y);
        } else {
            A_2 = 0;
            B_2 = 1;
        }
    } else {
        A_2 = 1;
        B_2 = 0;
    }
    C_2 = -A_2 * C_x - B_2 * C_y;

    if (A_1 == A_2 && B_1 == B_2) {
        if (C_1 == C_2) {
            if (B_1 == 0) {
                if (A_y < B_y) {
                    if ((C_y <= B_y && C_y >= A_y) || (D_y <= B_y && D_y >= A_y)) {
                        cout << 0;
                        return 0;
                    }
                } else {
                    if ((C_y >= B_y && C_y <= A_y) || (D_y >= B_y && D_y <= A_y)) {
                        cout << 0;
                        return 0;
                    }
                }
            } else {
                if (A_x < B_x) {
                    if ((C_x <= B_x && C_x >= A_x) || (D_x <= B_x && D_x >= A_x)) {
                        cout << 0;
                        return 0;
                    }
                } else {
                    if ((C_x >= B_x && C_x <= A_x) || (D_x >= B_x && D_x <= A_x)) {
                        cout << 0;
                        return 0;
                    }
                }
            }
        }
    } else {
        if (Checker(A_1, B_1, C_1, A_2, B_2, C_2, A_x, A_y, B_x, B_y) && Checker(A_2, B_2, C_2, A_1, B_1, C_1, C_x, C_y, D_x, D_y)) {
            cout << 0;
            return 0;
        }
    }

    double A_C_p, B_C_p, C_C_p;
    A_C_p = B_1;
    B_C_p = -A_1;
    C_C_p = -A_C_p * C_x - B_C_p * C_y;
    double A_D_p, B_D_p, C_D_p;
    A_D_p = B_1;
    B_D_p = -A_1;
    C_D_p = -A_D_p * D_x - B_D_p * D_y;
    double A_A_p, B_A_p, C_A_p;
    A_A_p = B_2;
    B_A_p = -A_2;
    C_A_p = -A_A_p * A_x - B_A_p * A_y;
    double A_B_p, B_B_p, C_B_p;
    A_B_p = B_2;
    B_B_p = -A_2;
    C_B_p = -A_B_p * B_x - B_B_p * B_y;
    double R1, R2, R3, R4, R5, R6, R7, R8;
    if (Checker(A_1, B_1, C_1, A_C_p, B_C_p, C_C_p, A_x, A_y, B_x, B_y)){
        double D = A_1 * B_C_p - B_1 * A_C_p;
        double D1 = C_1 * B_C_p - B_1 * C_C_p;
        double D2 = C_C_p * A_1 - C_1 * A_C_p;
        double x = -D1 / D;
        double y = -D2 / D;
        R1 = sqrt((C_x - x) * (C_x - x) + (C_y - y) * (C_y - y));
    }
    else {
        R1 = 40000;
    }
    if (Checker(A_1, B_1, C_1, A_D_p, B_D_p, C_D_p, A_x, A_y, B_x, B_y)){
        double D = A_1 * B_D_p - B_1 * A_D_p;
        double D1 = C_1 * B_D_p - B_1 * C_D_p;
        double D2 = C_D_p * A_1 - C_1 * A_D_p;
        double x = -D1 / D;
        double y = -D2 / D;
        R2 = sqrt((D_x - x) * (D_x - x) + (D_y - y) * (D_y - y));
    }
    else {
        R2 = 40000;
    }
    if (Checker(A_2, B_2, C_2, A_A_p, B_A_p, C_A_p, C_x, C_y, D_x, D_y)){
        double D = A_2 * B_A_p - B_2 * A_A_p;
        double D1 = C_2 * B_A_p - B_2 * C_A_p;
        double D2 = C_A_p * A_2 - C_2 * A_A_p;
        double x = -D1 / D;
        double y = -D2 / D;
        R3 = sqrt((A_x - x) * (A_x - x) + (A_y - y) * (A_y - y));
    }
    else {
        R3 = 40000;
    }
    if (Checker(A_2, B_2, C_2, A_B_p, B_B_p, C_B_p, C_x, C_y, D_x, D_y)){
        double D = A_2 * B_B_p - B_2 * A_B_p;
        double D1 = C_2 * B_B_p - B_2 * C_B_p;
        double D2 = C_B_p * A_2 - C_2 * A_B_p;
        double x = -D1 / D;
        double y = -D2 / D;
        R4 = sqrt((B_x - x) * (B_x - x) + (B_y - y) * (B_y - y));
    }
    else {
        R4 = 40000;
    }
    R5 = sqrt((B_x - C_x) * (B_x - C_x) + (B_y - C_y) * (B_y - C_y));
    R6 = sqrt((B_x - D_x) * (B_x - D_x) + (B_y - D_y) * (B_y - D_y));
    R7 = sqrt((A_x - C_x) * (A_x - C_x) + (A_y - C_y) * (A_y - C_y));
    R8 = sqrt((A_x - D_x) * (A_x - D_x) + (A_y - D_y) * (A_y - D_y));
    cout<<min(min(min(R1, R2), min(R3, R4)), min(min(R5, R6), min(R7, R8)));
}

