#include<iostream>
using namespace std;
//есть ли в отсортированном массиве элемент X
//в функции простые переменные просто копируютс€(их значени€), массивы же измен€ютс€
	int BinSearch(int* arr,int l, int r,int x){
		if (r>=l){
			int mid=(r+l)/2;
			if (arr[mid]==x)
				return 1;
			else
				if(arr[mid]<x)
					return BinSearch(arr,mid+1,r,x);
				else
					return BinSearch(arr,l,mid-1,x);
		}
		return 0;
	}
	void Read(int* arr, int n){
		for(int i=0;i<n;++i)
			cin>>arr[i];
	}
int main(){
	int n,k;
	cin>>n>>k;
	int arr[n],brr[k];
	Read(arr,n);
	Read(brr,k);
	for (int i=0;i<k;++i){
		if (BinSearch(arr,0,n,brr[i]))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}
