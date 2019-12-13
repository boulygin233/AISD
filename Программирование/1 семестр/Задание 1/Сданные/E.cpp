#include <iostream>
#include <cmath>
using namespace std;

unsigned int DivisiorsSum(unsigned int n){
	int x=1;
	for (int i = 2; i < sqrt(n); ++i){
		if ((n % i) == 0){
			x += i;
			x += n / i;
		}
	}
	int Check = sqrt(n);
	if ((Check * Check) == n){
		x += Check;
	}
	
	return x;
}

int main(){
	unsigned int n;
	unsigned int m;
	cin>>n>>m;
	if ((DivisiorsSum(n) == m) && (DivisiorsSum(m) == n)){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
	return 0;
}
