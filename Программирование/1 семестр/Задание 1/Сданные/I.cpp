#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int Age[1001] = {0};
	int x;
	for (int i = 0; i < n; ++i){
		cin>>x;
		++Age[x];
	}
	int FrequentestAge = 0;
	for (int i = 0; i < 1001; ++i){
		if (Age[i] > Age[FrequentestAge]){
			FrequentestAge = i;
		}
	}
	cout<<FrequentestAge;
	return 0;
}
