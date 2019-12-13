#include<iostream>
#include <math.h>
using namespace std;
int main(){
	double a,b,c,d;
	label:
	cout<<"Enter a,b and c:\n";
	cin>>a>>b>>c;
	if (a!=0){
		d=b*b-4*a*c;
		if (d>0){
			cout<<"2 solutions\nx1="<<(-b+sqrt(d))/(2*a)<<"\nx2="<<(-b-sqrt(d))/(2*a);
		}
		else if(d==0){
			if(c==0){
				cout<<"1 solution\nx="<<((b)/(2*a));
			}
			else
				cout<<"1 solution\nx="<<((b*(-1))/(2*a));
		}
		else{
			cout<<"No solution";
		}
	}
	else if(b!=0 && c==0){
		cout<<"1 solution\nx="<<(c/b);
	}
	else if(b!=0 && c!=0)
		cout<<"1 solution\nx="<<((-c)/b);
	else if (c==0){
		cout<<"Endless solutions";
	}
	else
		cout<<"No solution";
	goto label;
}
