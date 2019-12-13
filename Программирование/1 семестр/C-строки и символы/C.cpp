#include<iostream>
using namespace std;
int main(){
	char c;
	cin>>c;
	if (c<91 && c>64){
		char x=c+32;
		cout<<x;
	}
	else if (c>96 && c<123){
		char x=c-32;
		cout<<x;
	}
	else
		cout<<c;
}
