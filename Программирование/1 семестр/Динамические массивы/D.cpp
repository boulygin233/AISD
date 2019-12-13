#include<iostream>
using namespace std;
int main(){
	int i,j,p=1,n,x;
	cin>>n;
	long long b[n],a[108]={0},min=2*1000000000+1;
	for (i=0;i<n;++i){
		cin>>b[i];
		if (b[i]<min)
			min=b[i];
	}
	for (i=0;i<n;++i)
		a[b[i]-min]+=1;
	for (i=0;i<108;++i){
		for (j=0;j<a[i];++j)
			cout<<min+i<<" ";
	}			
}
