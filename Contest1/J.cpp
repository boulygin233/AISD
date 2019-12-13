#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    double x[n], y[n];
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    double area = 0;
    for (int i = 0; i < n; ++i){
        area += x[i] * y[(i + 1) % n] - x[(i + 1) % n] * y[i];
    }
    area /= 2;
    cout.setf(ios::fixed);
    cout.precision(100);
    cout<<abs(area);
}


