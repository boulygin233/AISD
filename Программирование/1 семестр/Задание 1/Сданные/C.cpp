#include <iostream>
using namespace std;
int main(){
	int x1;
	int y1;
	int x2;
	int y2;
	cin>>x1>>y1;
	cin>>x2>>y2;
	//Так как уравнение прямой вида Ax+By+C=0 можно домножать на любое число, представим, что мы его домножили так, что B=x1-x2
	int b = x1 - x2;
	int a = y2 - y1;
	int c = x2 * y1 - y2 * x1;
	cout<<a<<' '<<b<<' '<<c;
}
