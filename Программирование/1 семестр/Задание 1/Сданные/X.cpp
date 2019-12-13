#include <iostream>
using namespace std;

int gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; 
		y = 1;
		return b;
	}
	int x1;
	int y1;
	int GCD = gcd (b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return GCD;
}

int main() {
	int a;
	int b;
	int c;
	cin>>a>>b>>c;
	int x0;
	int y0;
	int GCD = gcd (a, b, x0, y0);
	if (c % GCD != 0) {
		cout<<"Impossible";
	}
	else {
		x0 *= c / GCD;
		y0 *= c / GCD;
		if (x0 > 0){
			while ((x0 - (b / GCD)) >= 0) {
				x0 -= b / GCD;
				y0 += a / GCD;
			}
		}
		else {
			while (x0 < 0){
				x0 += b / GCD;
				y0 -= a / GCD;
			}
		}
		cout<<x0<<' '<<y0;
	}
}
