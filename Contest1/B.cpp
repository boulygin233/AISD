#include <iostream>
#include <cmath>
using namespace std;

class Vector{
private:
    double X;
    double Y;
public:
    Vector(double b_x, double b_y, double e_x, double e_y): X(e_x - b_x), Y(e_y - b_y){
    }
    ~Vector() = default;
    friend Vector operator +(const Vector A, const Vector B){
        Vector C(0, 0, A.X + B.X, A.Y + B.Y);
        return C;
    }
    Vector operator =(const Vector A){
        X = A.X;
        Y = A.Y;
        return *this;
    }
    void Print(){
        cout<<X<<' '<<Y<<endl;
    }
    double Scalyar (Vector A){
        double value;
        value = A.X * X + A.Y * Y;
        return value;
    }
    double Len(){
        double Length = sqrt(X * X + Y * Y);
        return Length;
    }
    double Vect(Vector A){
        double value;
        value = sqrt((X * X + Y * Y) * (A.X * A.X + A.Y * A.Y) - Scalyar(A) * Scalyar(A));
        if ((X * A.Y - Y * A.X) < 0) {
            value = (-1) * value;
        }
        return value;
    }
    double Area(Vector A){
        double value;
        value = sqrt((X * X + Y * Y) * (A.X * A.X + A.Y * A.Y) - Scalyar(A) * Scalyar(A)) / 2;
        return value;
    }
};
int main() {
    int b_x1, b_y1, e_x1, e_y1;
    int b_x2, b_y2, e_x2, e_y2;
    cin>>b_x1>>b_y1>>e_x1>>e_y1;
    cin>>b_x2>>b_y2>>e_x2>>e_y2;
    Vector A(b_x1, b_y1, e_x1, e_y1);
    Vector B(b_x2, b_y2, e_x2, e_y2);
    Vector C = A + B;
    cout.setf(ios::fixed);
    cout.precision(10);
    cout<<A.Len()<<' '<<B.Len()<<'\n';
    C.Print();
    cout<<A.Scalyar(B)<<' '<<A.Vect(B)<<'\n';
    cout<<A.Area(B);
}

