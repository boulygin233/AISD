#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int Fib1=1;
	int Fib2=1;
	if (n <= 2){
		cout<<Fib1;
	}
	else{
		for (int i = 2; i < n; ++i){
			int x = Fib2;
			Fib2 = (Fib1 + Fib2) % 1000;
			Fib1 = x;
		}
		if (n < 17){
			cout<<Fib2;
		}
		else{
			if (Fib2 < 10){
				cout<<0<<0<<Fib2;
			}
			else if (Fib2 < 100){
				cout<<0<<Fib2;
			}
			else{
				cout<<Fib2;
			}
		}
	}
}
