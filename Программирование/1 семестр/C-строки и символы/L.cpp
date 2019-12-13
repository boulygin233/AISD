#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char s[1000],Desh[1000];
	cin>>s;
	int n=strlen(s),key,d;
	cin>>key;
	for (int i=0;i<n;++i){
		d=s[i]-65;
		d-=key;
		if (d<0)
			d=26+d;
		Desh[i]=d+65;
	}
	for(int i=0;i<n;++i)
		cout<<Desh[i];
}
