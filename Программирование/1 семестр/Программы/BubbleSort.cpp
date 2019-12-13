#include<iostream>
using namespace std;
int main(){
	int i,p=1,n,x,c=0;
	cin>>n;
	int a[n];
	for (i=0;i<n;++i)
		cin>>a[i];
	while (p!=0){
		p=0;
		for(i=0;i<n-1;++i){
			if (a[i]>a[i+1]){
				x=a[i];
				a[i]=a[i+1];
				a[i+1]=x;
				p=1;
				++c;
			}
		}
	}
	cout<<c;
}
