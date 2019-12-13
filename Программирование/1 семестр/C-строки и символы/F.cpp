#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char s[1000],s1[1000];
	cin.getline(s,1000,'\n');
	int n=strlen(s),i,c=0,j,m=0;
	for (i=0;i<n;++i){
		if (s[i]!=' ')
			++c;
		else{
			if (c>m){
				for (j=i-c;j<i;++j){
					s1[j-i+c]=s[j];
				}
				m=c;
			}
			c=0;
		}
	}
	if (c>m){
		for (j=n-c;j<n;++j){
			s1[j-n+c]=s[j];
		}
		m=c;
	}
	for (i=0;i<strlen(s1);++i){
		cout<<s1[i];
	}
	cout<<'\n'<<m;
}
