#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(10);
    double C_x, C_y, A_x, A_y, B_x, B_y;
    cin >> C_x >> C_y >> A_x >> A_y >> B_x >> B_y;
    double A, B, C;
    if (A_x != B_x) {
        A = 1;
        if (A_y != B_y) {
            B = (A_x - B_x) / (B_y - A_y);
        } else {
            A = 0;
            B = 1;
        }
    } else {
        A = 1;
        B = 0;
    }
    C = -A * A_x - B * A_y;
    double A_p, B_p, C_p;
    A_p = B;
    B_p = -A;
    C_p = -A_p * C_x - B_p * C_y;
    double D = A * B_p - B * A_p;
    double D1 = C * B_p - B * C_p;
    double D2 = C_p * A - C * A_p;
    double x = - D1 / D;
    double y = - D2 / D;
    double R = sqrt((C_x - x) * (C_x - x) + (C_y - y) * (C_y - y));
    double R1 = sqrt((C_x - A_x) * (C_x - A_x) + (C_y - A_y) * (C_y - A_y));
    double R2 = sqrt((C_x - B_x) * (C_x - B_x) + (C_y - B_y) * (C_y - B_y));
    //cout<<A<<' '<<B<<' '<<C<<'\n'<<A_p<<' '<<B_p<<' '<<C_p<<'\n'<<x<<' '<<y<<'\n';
    cout << R << '\n';
    if (B == 0) {
        if (A_y < B_y) {
            if (y >= A_y) {
                cout << R << "\n";
                if (y <= B_y) {
                    cout << R << "\n";
                } else {
                    if (R1 < R2) {
                        cout << R1 << '\n';
                    } else {
                        cout << R2 << '\n';
                    }
                }
            } else {
                if (R1 < R2) {
                    cout << R1 << '\n' << R1;
                } else {
                    cout << R2 << '\n' << R2;
                }
            }
        } else {
            if (y <= A_y) {
                cout << R << "\n";
                if (y >= B_y) {
                    cout << R << "\n";
                } else {
                    if (R1 < R2) {
                        cout << R1 << '\n';
                    } else {
                        cout << R2 << '\n';
                    }
                }
            } else {
                if (R1 < R2) {
                    cout << R1 << '\n' << R1;
                } else {
                    cout << R2 << '\n' << R2;
                }
            }
        }
    } else if (A_x < B_x) {
        if (x >= A_x) {
            cout << R << "\n";
            if (x <= B_x) {
                cout << R;
            } else {
                if (R1 < R2) {
                    cout << R1 << '\n';
                } else {
                    cout << R2 << '\n';
                }
            }
        } else {
            if (R1 < R2) {
                cout << R1 << '\n' << R1;
            } else {
                cout << R2 << '\n' << R2;
            }
        }
    } else {
        if (x <= A_x) {
            cout << R << "\n";
            if (x >= B_x) {
                cout << R;
            } else {
                if (R1 < R2) {
                    cout << R1 << '\n';
                } else {
                    cout << R2 << '\n';
                }
            }
        } else {
            if (R1 < R2) {
                cout << R1 << '\n' << R1;
            } else {
                cout << R2 << '\n' << R2;
            }
        }
    }
}


