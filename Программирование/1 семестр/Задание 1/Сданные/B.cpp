#include <iostream>
using namespace std;
int main(){
	int a;
	int b;
	int c;
	cin>>a>>b>>c;
	if (a == 0){
		cout<<0;
	}
	else if (b == 0){
		cout<<"IMPOSSIBLE";
	}
	else {
		int x;
		x = a / b;
		if ((a % b) != 0){
			++x;
		}
		cout<<c * x;
	}
	return 0;
}
