#include <iostream>
using namespace std;
int main(){
	int n;
	int m;
	int k;
	cin>>n>>m>>k;
	int A[n][m];
	int B[m][k];
	int Result[n][k];
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin>>A[i][j];
		}
	}
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < k; ++j){
			cin>>B[i][j];
		}
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < k; ++j){
			Result[i][j] = 0;
		}
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < k; ++j){
			for (int t = 0; t < m; ++t){
				Result[i][j] += A[i][t] * B[t][j];
			}
		}
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < k; ++j){
			cout<<Result[i][j]<<' ';
		}
		cout<<'\n';
	}
}
