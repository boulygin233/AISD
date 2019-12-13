#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char s[1000],c;
	int i=0,f=0;
	while(cin>>c){
		if (c!=' '){
			s[i]=c;
			++i;
		}
	}	
	int n=strlen(s);
	for (i=0;i<n;++i){
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
