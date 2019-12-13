#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int Time[n];
	int H;
	int M;
	int S;
	for (int i = 0; i < n; ++i){
		cin>>H>>M>>S;
		Time[i] = H * 3600 + M * 60 + S;
	}
	for (int i = 1; i < n; ++i){
		int j = i;
		while ((j > 0) && (Time[j] < Time[j - 1])){
			int x = Time[j];
			Time[j] = Time[j - 1];
			Time[j - 1] = x;
			--j;
		}
	}
	for (int i = 0; i < n; ++i){
		H = Time[i] / 3600;
		Time[i] = Time[i] % 3600;
		M = Time[i] / 60;
		S = Time[i] % 60;
		cout<<H<<' '<<M<<' '<<S<<'\n';
	}	
}
