#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char s[15];
	int i=1,k=1,x,f=0;
	cin>>s;
	int n=strlen(s);
	if (s[0]=='.' || s[n-1]=='.'){
		cout<<0;
		return 0;
	}
	for(i=1;i<n;++i){
		if (s[i]=='.'){
			++f;
			if (s[i-1]=='.'){
				cout<<0;
				return 0;
			}
			else{
				if(k==1){
					x=s[i-1]-48;
				}
				else if (k==2)
					x=s[i-1]-48+(s[i-2]-48)*10;
				else if (k==3)
					x=s[i-1]-48+(s[i-2]-48)*10+(s[i-3]-48)*100;
				else {
					cout<<0;
					return 0;
				}
				if (x>255 || x<0){
					cout<<0;
					return 0;
				}
			}
			k=0;
		}
		else
			++k;
	}
	if(k==1){
		x=s[i-1]-48;
	}
	else if (k==2)
		x=s[i-1]-48+(s[i-2]-48)*10;
	else if (k==3)
		x=s[i-1]-48+(s[i-2]-48)*10+(s[i-3]-48)*100;
	else {
		cout<<0;
		return 0;
	}
	if(f!=3){
		cout<<0;
		return 0;
	}
	cout<<1;
}
