#include <iostream>
using namespace std;
bool Check (int a, int b, int N){
	int Br = N - a - b;
	return ((Br > -1) && (Br < 10));
}
int main(){
	int i;
	int j;
	int k;
	int l;
	int Counter = 0;
	int N;
	cin>>N;
	if (N > 27){
		cout<<0;
		return 0;
	}
	for (i = 0; i < 10; ++i){
		for (j = 0; j < 10; ++j){
			for (k = 0; k < 10; ++k){
				for (l = 0; l < 10; ++l){
					if(Check(i, j, N) && Check(i, k, N) && Check(l, j, N) && Check(l, k, N) && Check(N, (-k - l), i + j)) {
						++Counter;
					}
				}
			}
		}
	}
	cout<<Counter;
}
