#include<iostream>
using namespace std;
int main(){
	int x,i;
	double s=1,p=1;
	cin>>x;
	for(i=1;i<101;i++){
		p=p*x/i;
		s+=p;
	}
	cout<<s;
}
