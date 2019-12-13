#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i){
		cin>>a[i];
	}
	for (int i = 1; i < n; ++i){
		int j = 0;
		int k = a[i];
		while (j < i  && a[j] < k){
			++j;
		}	
		for (int z = i; z > j; --z){
			a[z] = a[z - 1];
		}
		a[j] = k;
	}
	for (int i = 0; i < n; ++i){
		cout<<a[i]<<' ';
	}
}
