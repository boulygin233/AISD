#include <iostream>
using namespace std;
int Sum(int P1, int P2, int len, int n){
	if (len == n){
		return 1;
	}
	else{
		if (P1 + P2 < 2){
			return Sum(0, P1, len + 1, n) + Sum(1, P1, len + 1, n);
		}
		else{
			return Sum(0, P1, len + 1, n);
		}
	}
}

int main(){
	int n;
	cin>>n;
	if (n < 3){
		cout<<n * 2;
		return 0;
	}
	cout<<Sum(0, 0, 2, n) + Sum (0, 1, 2, n) + Sum (1, 0, 2, n) + Sum (1, 1, 2, n);
}
