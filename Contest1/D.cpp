#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double C_x, C_y, A_x, A_y, B_x, B_y;
    cin >> C_x >> C_y >> A_x >> A_y >> B_x >> B_y;
    double A, B, C;
    if (A_x != B_x) {
        A = 1;
        if (A_y != B_y) {
            B = (A_x - B_x) / (B_y - A_y);
        } else {
            A = 0;
        }
    } else {
        A = 1;
        B = 0;
    }
    C = -A * A_x - B * A_y;
    if (A * C_x + B * C_y + C == 0) {
        cout << "YES\n";
        if (B == 0){
            if (A_y < B_y){
                if (C_y >= A_y){
                    cout<<"YES\n";
                    if (C_y <= B_y){
                        cout<<"YES\n";
                    }
                    else {
                        cout<<"NO\n";
                    }
                }
                else {
                    cout<<"NO\nNO";
                }
            }
            else {
                if (C_y <= A_y){
                    cout<<"YES\n";
                    if (C_y >= B_y){
                        cout<<"YES\n";
                    }
                    else {
                        cout<<"NO\n";
                    }
                }
                else {
                    cout<<"NO\nNO";
                }
            }
        }
        else if (A_x < B_x) {
            if (C_x >= A_x) {
                cout << "YES\n";
                if (C_x <= B_x) {
                    cout << "YES";
                } else {
                    cout << "NO";
                }
            }
            else {
                cout << "NO\nNO";
            }
        }
        else {
            if (C_x <= A_x) {
                cout << "YES\n";
                if (C_x >= B_x) {
                    cout << "YES";
                } else {
                    cout << "NO";
                }
            } else {
                cout << "NO\nNO";
            }
        }
    } else {
        cout << "NO\nNO\nNO";
    }
}

