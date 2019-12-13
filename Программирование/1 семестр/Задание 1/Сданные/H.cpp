#include <iostream>
using namespace std;
int main(){
	int A;
	int B;
	cin>>A>>B;
	long long NumsCount [10] = {0};
	for (int i = A; i < B + 1; ++i){
		int x = i;
		while (x>0) {
			++NumsCount[(x%10)];
			x /= 10;
		}
	}
	for (int i = 0; i < 10; ++i){
		cout<<NumsCount [i] <<' ';
	}
}
