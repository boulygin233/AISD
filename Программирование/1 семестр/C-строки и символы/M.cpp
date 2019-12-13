#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char s[1000];
	cin>>s;
	int i,j,n;
	cin>>i>>j;
	n=j-i+1;
	
	for (int k=0;k<(j-i+1)/2;++k){
		char c=s[i-1+k];
		s[i-1+k]=s[j-1-k];
		s[j-1-k]=c;
	}
	for (i=0;i<strlen(s);++i)
		cout<<s[i];
}
