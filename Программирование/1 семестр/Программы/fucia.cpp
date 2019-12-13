#include<iostream>
using namespace std;
int main(){
	int n,i;
	double s=0;
	cin>>n;
	for(i=1;i<n+1;i++){
		s=s+1/(i*i);
	}
	cout<<s;
}
