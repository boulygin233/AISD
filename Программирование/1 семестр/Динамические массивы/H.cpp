#include<iostream>
using namespace std;
int main(){
	int n,x,i,j,z,c=0;
	cin>>x>>n;
	int a[n]={0};
	for(i=0;i<n;++i)
		for(j=0;j<n;++j){
			cin>>z;
			if (z==x){
				a[j]=1;
			}
		}
	for (i=0;i<n;++i){
		if(a[i]){
			cout<<"YES"<<"\n";
		}
		else
			cout<<"NO"<<"\n";	
	}
}
