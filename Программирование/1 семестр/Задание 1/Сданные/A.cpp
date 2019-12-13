#include<iostream>
using namespace std;
int main(){
	int a;
	int b;
	int c;
	int x;
	int y;
	cin>>a>>b>>c>>x>>y;
	if ((x >= a) && (y >= b)){
		cout<<"YES";
		return 0;
	}
	if ((x >= b) && (y >= a)){
		cout<<"YES";
		return 0;
	}
	if ((x >= a) && (y >= c)){
		cout<<"YES";
		return 0;
	}
	if ((x >= c) && (y >= a)){
		cout<<"YES";
		return 0;
	}
	if ((x >= c) && (y >= b)){
		cout<<"YES";
		return 0;
	}
	if ((x >= b) && (y >= c)){
		cout<<"YES";
		return 0;
	}
	cout<<"NO";
	return 0;
}
