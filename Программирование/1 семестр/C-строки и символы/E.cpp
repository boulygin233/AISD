#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char s[1000];
	cin.getline(s,1000,'\n');
	int n=strlen(s),i,c=1;
	for (i=0;i<n;++i){
		if (s[i]==' ')
			++c;
	}
	cout<<c;
}
