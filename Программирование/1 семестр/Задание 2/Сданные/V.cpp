#include<iostream>
using namespace std;
int max(int a, int b){
	return (a > b) ? a : b;
}
int main(){
	int N;
	cin>>N;
	int Arr1[N];
	for(int i = 0; i < N; ++i){
		cin>>Arr1[i];
	}
	int M;
	cin>>M;
	int Arr2[M];
	for(int i = 0; i < M; ++i){
		cin>>Arr2[i];
	}
	int Lens[N + 1][M + 1];
	for (int i = 0; i <= N; ++i){
		for (int j = 0; j <= M; ++j){
			if (i == 0 || j == 0){
				Lens[i][j] = 0;
			}
			else if (Arr1[i - 1] == Arr2[j - 1]){
				Lens[i][j] = Lens[i - 1][j - 1] + 1;
			}
			else{
				Lens[i][j] = max(Lens[i - 1][j], Lens[i][j - 1]);
			}
		}
	}
	int Len = Lens[N][M];
	int Subseq[Len];
	int i = N;
	int j = M;
	while (Len != 0){
		if (Arr1[i - 1] == Arr2[j - 1]){
			Subseq[Len - 1] = Arr1[i - 1];
			--i;
			--j;
			--Len;
		}
		else{
			if (Lens[i][j] == Lens[i - 1][j]){
				--i;
			}
			else{
				--j;
			}
		}
	}
	for (int i = 0; i < Lens[N][M]; ++i){
		cout<<Subseq[i]<<' ';
	}
}
