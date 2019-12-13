#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    double x[n], y[n];
    for (int i = 0; i < n; ++i){
        cin>>x[i]>>y[i];
    }
    double wp[n];
    for (int i = 0; i < n; ++i){
        double xx1 = x[i] - x[(i + 1) % n];
        double yy1 = y[i] - y[(i + 1) % n];
        double xx2 = x[(i + 1) % n] - x[(i + 2) % n];
        double yy2 = y[(i + 1) % n] - y[(i + 2) % n];
        wp[i] = xx1 * yy2 - xx2 * yy1;
    }
    bool f1 = true, f2 = true;
    for (int i = 0; i < n; ++i){
        if (wp[i] > 0){
            f1 = false;
        }
        if (wp[i] < 0){
            f2 = false;
        }
    }
    if (f1 || f2){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}
