#include<iostream>
using namespace std;
int main(){
	label:
	long long i;
	double x,s=1,p=1;
	cin>>x;
	s=x/1;
	p=s;
	for(i=1;i<101;i++){
		p=p*x*x/(2*i*(2*i+1))*(-1);
		s+=p;
	}
	cout<<s<<"\n";
	goto label;
}
