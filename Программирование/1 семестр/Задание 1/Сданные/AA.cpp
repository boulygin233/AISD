#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int LR[2][2] = {0};
	int L;
	int R;
	for (int i = 0; i < n; ++i) {
		cin>>L>>R;
		++LR[L][R];
	}
	if (LR[0][1] != LR[1][0]){
		cout<<"No";
		return 0;
	}
	if (LR[0][1] == 0) {
		if (LR[0][0] == 0){
			cout<<"Yes";
			return 0;
		}
		if (LR[1][1] == 0){
			if (LR[0][0] % 2 == 0) {
				cout<<"Yes";
			}
			else{
				cout<<"No";
			}
			return 0;
		}
		cout<<"No";
		return 0;
	}
	if ((LR[0][0] % 2) == (LR[0][1] % 2)) {
		cout<<"Yes";
		return 0;
	}
	else {
		cout<<"No";
		return 0;
	}
}
