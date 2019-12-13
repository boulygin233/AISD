#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char s[1000];
	cin>>s;
	int n=strlen(s);
	int a[52]={0};
	for (int i=0;i<n;++i){
		if (s[i]<91 && s[i]>64)
			a[s[i]-65]+=1;
		else if (s[i]>96 && s[i]<123)
			a[s[i]-71]+=1;
	}
	for(int i=0;i<52;++i){
		if (a[i]==2){
			if(i<26){
				char x=i+65;
				cout<<x;
			}
			else{
				char x=i+71;
				cout<<x;
			}
			break;
		}
	}
}
