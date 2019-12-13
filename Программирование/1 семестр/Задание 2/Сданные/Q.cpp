#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int n;
	cin>>n;
	if (n == 1){
		return 0;
	}
	if (n == 2){
		cout<<'2';
		return 0;
	}
	if (n == 3){
		cout<<'3';
		return 0;
	}
	int* Prev = new int [n + 1];
	Prev[1] = 0;
	Prev[2] = 1;
	Prev[3] = 1;
	for (int i = 4; i < n + 1; ++i){
		Prev[i] = Prev[i - 1] + 1;
		if (((i % 2) == 0) && ((Prev[i / 2] + 1) < Prev[i])) {
			Prev[i] = Prev[i / 2] + 1;
		}
		if (((i % 3) == 0) && ((Prev[i / 3] + 1) < Prev[i])) {
			Prev[i] = Prev[i / 3] + 1;
		}
	}
	int k = 0;
	int* Way = new int [1000000];
	int i = n;
	while ((i != 3) && (i != 2) && (i != 1)){
		if ((Prev[i] - 1) == Prev[i - 1]){
			Way[k] = 1;
			++k;
			i -= 1;
		}
		else if (((i % 2) == 0) && ((Prev[i / 2]) == (Prev[i] - 1))){
			Way[k] = 2;
			++k;
			i /= 2;
		}
		else if (((i % 3) == 0) && ((Prev[i / 3]) == (Prev[i] - 1))){
			Way[k] = 3;
			++k;
			i /= 3;
		}
	}
	if (i == 1){
		Way[k] = 1;
	}
	if (i == 2){
		Way[k] = 2;
	}
	if (i == 3){
		Way[k] = 3;
	}
	for (int i = k; i >= 0; --i){
		cout<<Way[i];
	}
	return 0;	
}
