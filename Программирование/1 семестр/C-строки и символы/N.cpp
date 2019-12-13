#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char s[1000];
	int n,i=0,k=0;
	cin.getline(s,1000,'\n');
	for (i;i<strlen(s);++i){
		if (s[i]!=' '){
			cout<<s[i];
			k=0;
		}
		else if (s[i]==' ' && k==0){
			cout<<' ';
			++k;
		}
	}
}
