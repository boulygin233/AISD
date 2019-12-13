#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char s1[1000],s2[1000];
	cin>>s1>>s2;
	if (strcmp(s1,s2)==0)
		cout<<"yes";
	else
		cout<<"no";
}
