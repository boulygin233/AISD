#include <iostream>
#include <cmath>

using namespace std;

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
                        cout << "YES";
                    } else {
                        cout << "NO";
                    }
                } else {
                    if ((C_y >= B_y && C_y <= A_y) || (D_y >= B_y && D_y <= A_y)) {
                        cout << "YES";
                    } else {
                        cout << "NO";
                    }
                }
            } else {
                if (A_x < B_x) {
                    if ((C_x <= B_x && C_x >= A_x) || (D_x <= B_x && D_x >= A_x)) {
                        cout << "YES";
                    } else {
                        cout << "NO";
                    }
                } else {
                    if ((C_x >= B_x && C_x <= A_x) || (D_x >= B_x && D_x <= A_x)) {
                        cout << "YES";
                    } else {
                        cout << "NO";
                    }
                }
            }
        } else {
            cout << "NO";
        }
    } else {
        double D = A_1 * B_2 - B_1 * A_2;
        double D1 = C_1 * B_2 - B_1 * C_2;
        double D2 = C_2 * A_1 - C_1 * A_2;
        double x = -D1 / D;
        double y = -D2 / D;
        bool f1, f2;
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
        if (B_2 == 0) {
            if (C_y < D_y) {
                if (y <= D_y && y >= C_y) {
                    f2 = true;
                } else {
                    f2 = false;
                }
            } else {
                if (y >= D_y && y <= C_y) {
                    f2 = true;
                } else {
                    f2 = false;
                }
            }
        } else {
            if (C_x < D_x) {
                if (x >= C_x && x <= D_x) {
                    f2 = true;
                } else {
                    f2 = false;
                }
            } else {
                if (x <= C_x && x >= D_x) {
                    f2 = true;
                } else {
                    f2 = false;
                }
            }
        }
        if (f1 && f2) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }
}

