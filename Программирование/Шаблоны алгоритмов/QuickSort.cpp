#include <iostream>
using namespace std;
void qs (int *Array, int left, int right){
	int i, j, x, y;
	i = left;
	j = right;
	x = Array[(left + right) / 2];
	do{
		while (Array[i] < x && i < right){
			++i;
		}
		while (Array[j] > x && j > left){
			--j;
		}
		if (i <= j){
			y = Array[i];
			Array[i] = Array[j];
			Array[j] = y;
			++i;
			--j;		
		}
	} while (i <= j);
	if (left < j){
		qs(Array, left, j);
	}
	if (right > i){
		qs(Array, i, right);
	}
}
void QuickSort (int *Array, int Length){
	qs(Array, 0, Length - 1);
}

int main(){
	int n;
	cin>>n;
	int Array[n];
	for (int i = 0; i < n; ++i){
		cin>>Array[i];
	}
	QuickSort(Array, n);
	for (int  i = 0; i < n; ++i){
		cout<<Array[i]<<' ';
	}
}
