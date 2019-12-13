#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char c,x;
	cin>>c;
	x=c-32;
	if (c<123 && c>96)
		cout<<x;
	else
		cout<<c;
}
