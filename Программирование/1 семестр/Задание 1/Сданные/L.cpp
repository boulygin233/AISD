#include <iostream>
using namespace std;
int main(){
	int N;
	cin>>N;
	int Kantor [N][N];
	Kantor [0][0] = 1;
	int KantNum = 2;
	for (int i = 1; i < N; ++i){
		if (i%2 == 1){
			for (int j = 0; j <= i; ++j){
				Kantor [j][i] = KantNum;
				++KantNum;
			}
			for (int j = i - 1; j >= 0; --j){
				Kantor [i][j] = KantNum;
				++KantNum;
			}
		}
		else{
			for (int j = 0; j <= i; ++j){
				Kantor [i][j] = KantNum;
				++KantNum;
			}
			for (int j = i - 1; j >= 0; --j){
				Kantor [j][i] = KantNum;
				++KantNum;
			}
		}
	}
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			cout<<Kantor[i][j]<<' ';
		}
		cout<<'\n';
	}
}
