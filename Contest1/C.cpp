#include <iostream>
#include <cmath>
using namespace std;

class line{
private:
    double A;
    double B;
    double C;
    double k;
    double b;
public:
    line(double A_, double B_, double C_): A(A_), B(B_), C(C_){
        if (B_ != 0){
            k = -1 * (A / B);
            b = -1 * (C / B);
            if (k == 0){
                k = 0;
            }
        }
        else{
            k = 0;
            b = (-1) * C_ / A_;
        }
    }
    ~line() = default;
    void Vect(){
        if (B != 0){
            cout<<double(1)<<' '<<k<<endl;
        }
        else{
            cout<<double(0)<<' '<<double(1)<<endl;
        }
    }
    void Point(line l){
        if (k == l.k && k != 0){
            double Distance;
            Distance = (b - l.b) * (b - l.b) / (k * k + 1);
            Distance = sqrt(Distance);
            cout<<Distance;
        }
        else if (k == l.k && k == 0){
            if ((B == l.B && B == 0) || (A == l.A && A == 0)) {
                cout<< abs(b - l.b);
            }
            else {
                if (B == 0) {
                    cout<<b<<' '<<l.b;
                }
                else {
                    cout<<l.b<<' '<<b;
                }
            }
        }
        else if (k == 0){
            double x;
            double y;
            if (B == 0){
                x = b;
                y = l.k * x + l.b;
            }
            else{
                y = b;
                x = (y - l.b) / l.k;
            }
            cout<<x<<' '<<y;
        }
        else if (l.k == 0){
            double x;
            double y;
            if (l.B == 0){
                x = l.b;
                y = k * x + b;
            }
            else{
                y = l.b;
                x = (y - b) / k;
            }
            cout<<x<<' '<<y;
        }
        else {
            double x = (l.b - b) / (k - l.k);
            double y = k * x + b;
            if (x == 0){
                x = 0;
            }
            if (y == 0){
                y = 0;
            }
            cout<<x<<' '<<y;
        }
    }
};

int main(){
    double A1, B1, C1;
    cin>>A1>>B1>>C1;
    double A2, B2, C2;
    cin>>A2>>B2>>C2;
    line l1(A1, B1, C1);
    line l2(A2, B2, C2);
    cout.setf(ios::fixed);
    cout.precision(6);
    l1.Vect();
    l2.Vect();
    l1.Point(l2);
}
