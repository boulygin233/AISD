#include <iostream>
using namespace std;
int main(){
	int n;
	int m;
	cin>>n>>m;
	int A[n][m];
	int x;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j){
			cin>>x;
			if ((i == 0) && (j == 0)){
				A[i][j] = x;
			}
			else if (i == 0) {
				A[i][j] = x + A[i][j - 1];
			}
			else if (j == 0) {
				A[i][j] = x + A[i - 1][j];
			}
			else {
				A[i][j] = x + A[i][j - 1] + A[i - 1][j] - A[i - 1][j - 1];
			}
		}
	}
	int MaxCross = A[0][m - 1] + A[n - 1][0] - A[0][0];
	for (int r1 = 0; r1 < n; ++r1){
		for (int r2 = r1; r2 < n; ++r2){
			for (int c1 = 0; c1 < m; ++c1){
				for (int c2 = c1; c2 < m; ++c2){
					int Cross =  A[r2][m - 1] + A[n - 1][c2] - A[r2][c2];
					if (r1 == 0){
						if (c1 == 0){
							Cross = Cross;
						}
						else {
							Cross += A[r2][c1 - 1] - A[n - 1][c1 - 1];
						}
					}
					else if (c1 == 0) {
						Cross += A[r1 - 1][c2] - A[r1 - 1][m - 1];
					}
					else {
						Cross += A[r1 - 1][c2] + A[r2][c1 - 1] - A[r1 - 1][c1 - 1] - A[r1 - 1][m - 1] - A[n - 1][c1 - 1];
					}
				
					if (Cross > MaxCross) {
						MaxCross = Cross;
					}
				}
			}
		}
	}
	cout<<MaxCross;
	return 0;
}
