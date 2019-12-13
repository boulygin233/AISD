#include<iostream>
using namespace std;
void Sum(int k, int n, int &Count, int j){
	if (k != 0){
		if(j < n){
			Sum(k - 1, n, Count, j);
			Sum(k - 1, n, Count, j + 1);
			Sum(k - 1, n, Count, j + 3);
		}
		else if (j == n){
			++Count;
		}
	}
	else{
		if (j == n){
			++Count;
		}
	}
}
int main(){
	int n;
	int k;
	cin>>n;
	cin>>k;
	int Count = 0;
	Sum (k, n, Count, 0);
	cout<<Count;
}
