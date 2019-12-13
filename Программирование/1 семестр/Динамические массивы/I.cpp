#include<iostream>
using namespace std;
int main(){
	int i,j,n,m,c=0;
	cin>>n>>m;
	int a[n][m]={0},stolb[m],strok[n];
	for(i=0;i<n;++i){
		strok[i]=1001;
	}
	for(i=0;i<n;++i){
		strok[i]=1001;
	}
	for(i=0;i<m;++i){
		stolb[i]=-1001;
	}
	for(i=0;i<n;++i)
		for(j=0;j<m;++j){
			cin>>a[i][j];
			if(a[i][j]>stolb[j])
				stolb[j]=a[i][j];
			if (a[i][j]<strok[i])
				strok[i]=a[i][j];
		}
	for(i=0;i<n;++i){
		for(j=0;j<m;++j){
			if (a[i][j]==strok[i] && a[i][j]==stolb[j])
				++c;
		}
	}
	cout<<c;
}
