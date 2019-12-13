#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int min(int a, int b){
	return (a < b) ? a : b;
}
int Check(char a, char b){
	return (a == b) ? 0 : 1;
}
int main(){
	char S1[1001];
	cin>>S1;
	int N = strlen(S1);
	char S2[1001];
	cin>>S2;
	int M = strlen(S2);
	
	int Lens[N + 1][M + 1];
	for (int i = 0; i <= N; ++i){
		for (int j = 0; j <= M; ++j){
			if (i == 0 || j == 0){
				Lens[i][j] = i + j;
			}
			else {
				Lens[i][j] = min(Lens[i - 1][j] + 1, min(Lens[i][j - 1] + 1, Lens[i - 1][j - 1] + Check (S1[i - 1], S2[j - 1])));
			}
		}
	}
	int Len = Lens[N][M];
	cout<<Len;
	
}
