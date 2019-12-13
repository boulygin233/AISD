#include <iostream>
using namespace std;

int SquaresCount (int a, int b){
	if (a == b){
		return 1;
	}
	else{
		if ((a - b) > b) {
			return 1 + SquaresCount(a - b, b);
		}
		else{
			return 1 + SquaresCount(b, a - b);
		}
	}
}

int main(){
	int a;
	int b;
	cin>>a>>b;
	if (a >= b){
		cout<<SquaresCount(a, b);
	}
	else{
		cout<<SquaresCount(b, a);
	}
	return 0;
}
