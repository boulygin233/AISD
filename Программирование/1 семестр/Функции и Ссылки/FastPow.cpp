#include <iostream>
using namespace std;
long double pow(double a, int b){
	if (b==0)
		return 1;
	else if(b==1)
		return a;
	else
		if (b%2==0){
			return pow(a*a,b/2);
		}
		else{
			return a*pow(a*a,(b-1)/2);
		}
}
int main(){
	int b;
	double a;
	cin>>a>>b;
	cout<<pow(a,b);	
}
