#include <iostream>
using namespace std;

template <class R> 
void Sorting (R* Array, int Size){
	int p = 1;
	while (p != 0){
		p = 0;
		for(int i = 0; i < Size - 1; ++i){
			if (Array[i] > Array[i + 1]){
				R x = Array[i];
				Array[i] = Array[i + 1];
				Array [i + 1] = x;
				p = 1;
			}
		}
	}
}
int main(){
	label:
	cout<<"Choose class of your dates:\n 1. Int\n 2. Double\n 3. Char\n";
	int x;
	cin>>x;
	cout<<"Input size of your array\n";
	int Size;
	cin>>Size;
	int* Array = new int [1];
	if (x == 1){
		delete [] Array;
		int* Array = new int [Size];
		cout<<"Input your dates\n";
		for (int i = 0; i < Size; ++i){
			cin>>Array[i];
		}
		Sorting (Array, Size);
		for (int i = 0; i < Size; ++i){
			cout<<Array[i]<<' ';
		}	
	}
	else if (x == 2){
		delete [] Array;
		cout<<"Input your dates\n";
		double* Array = new double [Size];
		for (int i = 0; i < Size; ++i){
			cin>>Array[i];
		}
		Sorting (Array, Size);
		for (int i = 0; i < Size; ++i){
			cout<<Array[i]<<' ';
		}	
	}
	else if (x == 3) {
		delete [] Array;
		char* Array = new char [Size];
		cout<<"Input your dates\n";
		for (int i = 0; i < Size; ++i){
			cin>>Array[i];
		}
		Sorting (Array, Size);
		for (int i = 0; i < Size; ++i){
			cout<<Array[i]<<' ';
		}	
	}
	else{
		cout<<"You lied us about class of your dates. Try Again\n";
		goto label;
	}
}
