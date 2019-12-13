#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int Mas[n];
	for (int i = 0; i < n; ++i){
		cin>>Mas[i];
	}
	for (int i = 1; i < n; ++i){
		int j = i;
		while ((j > 0) && (Mas[j] < Mas[j - 1])){
			int x = Mas [j - 1];
			Mas[j - 1] = Mas[j];
			Mas[j] = x;
			--j;
		}
	}
	for (int i = 0; i < n; ++i){
		cout<<Mas[i]<<' ';
	}	
}
