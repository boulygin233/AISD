#include <iostream>
using namespace std;

void Removing (int A, int B, int C, int N){
	if (N == 1) {
		cout<<A<<' '<<B<<'\n';
	}
	else{
		Removing (A, C, B, N-1);
		cout<<A<<' '<<B<<'\n';
		Removing (C, B, A, N-1);
	}
}

int main(){
	int N;
	cin>>N;
	Removing(1, 2, 3, N);
	return 0;
}
