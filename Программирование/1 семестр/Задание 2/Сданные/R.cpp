#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int Data[n];
	int Count[n];
	Count[0] = 1;
	cin>>Data[0];
	int Sum = 0;
	for (int i = 1; i < n; ++i){
		cin>>Data[i];
		int CountI = 1;
		for (int j = 0; j < i; ++j){
			if (Data[j] < Data[i]){
				CountI += Count[j];
			}
		}
		Count[i] = CountI;
		Sum += Count[i];
	}
	cout<<Sum;
}
