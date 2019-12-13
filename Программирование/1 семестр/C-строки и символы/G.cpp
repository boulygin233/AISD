#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char s[1000];
	cin>>s;
	int n=strlen(s),f=0;
	for (int i=0;i<n;++i){
		if (s[i]!=s[n-1-i]){
			f=1;
			break;
		}
	}
	if (f==0){
		cout<<"yes";
	}
	else
		cout<<"no";
}
