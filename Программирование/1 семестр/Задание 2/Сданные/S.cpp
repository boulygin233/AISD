#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int Data[n];
	int Count[n];
	Count[0] = 1;
	cin>>Data[0];
	int Sum = 1;
	for (int i = 1; i < n; ++i){
		cin>>Data[i];
		Count[i] = 1;
		for (int j = 0; j < i; ++j){
			if (Data[j] < Data[i]){
				Count[i] = (Count[i] + Count[j]) % 1000000;
			}
		}
		Sum = (Sum + Count[i]) % 1000000;
	}
	cout<<Sum;
}
