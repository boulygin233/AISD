#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long a[n];
	cin>>a[0];
	long long Max1 = a[0];
	long long Min1 = a[0];
	int imin = 0;
	int imax = 0;
	for (int i = 1; i < n; ++i){
		cin>>a[i];
		if (a[i] > Max1){
			Max1 = a[i];
			imax = i;
		}
		if (a[i] < Min1){
			Min1 = a[i];
			imin = i;
		}
	}
	long long MaxP = a[0] * a[1];
	for (int i = 0; i < n; ++i){
		if ((i != imax) && (a[i] * Max1 > MaxP)){
			MaxP = a[i] * Max1;
		}
		if ((i != imin) && (a[i] * Min1 > MaxP)){
			MaxP = a[i] * Min1;
		}
	}
	cout<<MaxP;
	return 0;
}
