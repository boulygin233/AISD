#include <iostream>
using namespace std;

string getSeq(string s, int digitsleft){
	if (digitsleft == 0){
		return s;
	}
	else{
		getSeq(s+"0", digitsleft - 1);
		getSeq(s+"1", digitsleft - 1);
	}
}

int main(){
	int n;
	cin>>n;
	getSeq("", n);
}


