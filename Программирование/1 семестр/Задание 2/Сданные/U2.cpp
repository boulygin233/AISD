#include<iostream>
using namespace std;

long long Ways(long long **Desk, int i, int j, int n, int m){
	if ((i >= 0) && (i < n) && (j >= 0) && (j <= m)){
		if (Desk[i][j] == -1){
			Desk[i][j] = Ways(Desk, i - 2, j - 1, n, m) + Ways(Desk, i - 2, j + 1, n, m) + Ways(Desk, i - 1, j - 2, n, m) + Ways(Desk, i + 1, j - 2, n, m);
		}
	}
	else{
		return 0;
	}
	return Desk[i][j];
}

int main(){
	int n;
	int m;
	cin>>n>>m;
	long long **Desk = new long long *[16];
	for (int i = 0; i < n; ++i){
		Desk[i] = new long long [16];
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			Desk[i][j] = -1;
		}
	}
	Desk[0][0] = 1;
	cout<<Ways(Desk, n - 1, m - 1, n, m);
	for (int i = 0; i < n; ++i){
			delete [] Desk[i];
	}
	delete [] Desk;
}
