#include <iostream>
using namespace std;
int main(){
	int n;
	int k;
	cin>>n>>k;
	int Squad[n];
	int Nom = 0;
	for (int i = 0; i < n; ++i){
		Squad[i] = 0;
	}
	for (int i = 0; i < n - 1; ++i){
		int x = 0;
		while (x != k - 1){
			if (Squad [Nom] == 0){
				++x;
				Nom = (Nom + 1) % n;
			}
			else {
				Nom = (Nom + 1) % n;
			}
		}
		while (Squad [Nom] != 0){
			Nom = (Nom + 1) % n;
		}
		Squad [Nom] = 1;
		Nom = (Nom + 1) % n;
	}
	for (int i = 0; i < n; ++i){
		if (Squad[i] == 0) {
			cout<<i+1;
			break;
		}
	}
	return 0;
}
