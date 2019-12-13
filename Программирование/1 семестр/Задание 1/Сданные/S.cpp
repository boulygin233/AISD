#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char String[256];
	cin>>String;
	int n = strlen(String);
	if (n == 1){
		cout<<0;
		return 0;
	}
	int f = 0;
	int Start;
	int Finish;
	for (int i = 0; i < n - 1; ++i){
		for (int j = n - 1; j > i; --j){
			f = 0;
			int Len = j - i + 1;
			for (int t = 0; t < Len / 2; ++t){
				if (String[i + t] != String [j - t]){
					f = 1;
					break;
				}
			}
			if (f == 0){
				Finish = j;
				Start = i;
				break;
			}
		}
		if (f == 0){
			break;
		}
	}
	if (f == 1) {
		cout<<'0';
	}
	else{
		for (int i = Start; i <= Finish; ++i){
			cout<<String[i];
		}
	}
}
