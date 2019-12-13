#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char s[10000],s1[10000];
	cin.getline(s,10000,'\n');
	cin.getline(s1,10000,'\n');
	if (strlen(s1)==0){
		cout<<"no";
		return 0;
	}
	int i,j,f=0,t;
	for (i=0;i<strlen(s1);++i){
		f=0;
		for (j=0;j<strlen(s);++j){
			if(s1[i+j]!=s[j]){
				f=1;
				break;
			}
		}
		if (f==0){
			break;
		}
	}
	if (f==0)
		cout<<"yes";
	else
		cout<<"no";
}
