#include <iostream>
using namespace std;
int main(){
	int n;
	int m;
	cin>>n>>m;
	int s[n][m];
	for (int i = 0; i < n; ++i){
		if (i == 0){
			for (int j = 0; j < m; ++j){
				int x;
				cin>>x;
				if (j == 0){
					s[i][j] = x;
				}
				else{
					s[i][j] = s[i][j - 1] + x;
				}
			}	
		}
		else {
			for (int j = 0; j < m; ++j){
				int x;
				cin>>x;
				if (j == 0){
					s[i][j] = s[i - 1][j] + x;
				}
				else{
					s[i][j] = s[i][j - 1] + s[i - 1][j] + x - s[i - 1][j - 1];
				}
			}	
		}
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cout<<s[i][j]<<' ';
		}
		cout<<'\n';
	}
}
