#include <iostream>
using namespace std;
int max (int a, int b){
	return (a > b) ? a : b;
}

int main(){
	int N;
	int M;
	cin>>N>>M;
	int m[N];
	int c[N];
	for (int i = 0; i < N; ++i){
		cin>>m[i];
	}
	for (int i = 0; i < N; ++i){
		cin>>c[i];
	}
	int Table[N + 1][M + 1];
	for(int i = 0; i < N + 1; ++i){
		for (int j = 0; j < M + 1; ++j){
			if (i == 0){
				Table[i][j] = 0;
			}
			else if (j < m[i - 1]){
				Table[i][j] = Table[i - 1][j];
			}
			else{
				Table[i][j] = max (Table[i - 1][j], Table[i - 1][j - m[i - 1]] + c[i - 1]);
			}
		}
	}
	int MaxC = Table[N][M];
	int i = N;
	int j = M;
	while (MaxC > 0){
		if (MaxC == Table[i - 1][j]){
			--i;
		}
		else{
			cout<<i<<'\n';
			j -= m[i - 1];
			MaxC -= c[i - 1];
			--i;
		}
	}
}
