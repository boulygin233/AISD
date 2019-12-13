#include <iostream>
#include <cmath>
using namespace std;

unsigned int count_divisiors(unsigned int n){
	int x=0;
	for (int i = 2; i < sqrt(n); ++i){
		if ((n % i) == 0){
			x += 2;
		}
	}
	int Check = sqrt(n);
	if ((Check * Check) == n){
		++x;
	}
	return x;
}

int main(){
	unsigned int n;
	cin>>n;
	cout<<count_divisiors(n);
	return 0;
}
