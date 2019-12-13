#include<iostream>
using namespace std;
long long Fibonachi(int n){
	if (n==0 || n==1)
		return 1;
	else
		return Fibonachi(n - 1) + Fibonachi(n - 2);
}
int main(){
	int n;
	cin>>n;
	cout<<Fibonachi(n-1);
	return 0;
}
