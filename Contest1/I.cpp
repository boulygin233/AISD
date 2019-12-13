#include <iostream>
#include <cmath>

using namespace std;


double E = 0.000001;

bool Checker(double A_x, double A_y, double B_x, double B_y, double C_x, double C_y) {
    bool res = false;
    if (abs(B_x - A_x) < E) {
        if (abs(C_x - A_x) < E && C_y > min(A_y, B_y) - E && C_y - E < max(A_y, B_y)){
            res = true;
        }
    } else {
        C_x -= A_x;
        C_y -= A_y;
        B_x -= A_x;
        B_y -= A_y;
        if (C_x - E < max(A_x, B_x) && C_x > min(A_x, B_x) - E && abs(B_x * C_y - B_y * C_x) < E) {
            res = true;
        }
    }
    return res;
}

bool AnotherChecker(double A_x, double A_y, double B_x, double B_y, double C_x, double C_y) {
    return (A_y < C_y && B_y > C_y - E || B_y < C_y && A_y > C_y - E) &&
           (C_y * (A_x - B_x) + A_y * B_x - A_x * B_y) / (A_y - B_y) < C_x;
}

int main() {
    int n;
    double C_x, C_y;
    cin >> n >> C_x >> C_y;
    double x[n], y[n];
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (Checker(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n], C_x, C_y)) {
            count = 1;
            break;
        } else if (AnotherChecker(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n], C_x, C_y)) {
            ++count;
        }
    }
    if (count % 2 == 0) {
        cout << "NO";
    } else {
        cout << "YES";
    }
}


