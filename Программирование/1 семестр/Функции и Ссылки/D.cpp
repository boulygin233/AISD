#include<iostream>
using namespace std;
bool Election(bool a, bool b, bool c){
	int x=a+b+c;
	if (x>1)
		return 1;
	else
		return 0;
}
int main(){
	bool a,b,c;
	cin>>a>>b>>c;
	cout<<Election(a,b,c);
}
