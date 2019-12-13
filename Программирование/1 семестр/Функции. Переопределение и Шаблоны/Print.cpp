#include <iostream>
using namespace std;

void print (int* Array, int Size){
	cout<<"{ ";
	for (int i = 0; i < Size - 1; ++i){
		cout<<Array[i]<<", ";
	}
	cout<<Array[Size - 1]<<" }";
}
void print (int** Matrix, int SizeString, int SizeColumn){
	for (int i = 0; i < SizeColumn; ++i){
		for (int j = 0; j < SizeString; ++j){
			if (Matrix[i][j] < 10){
				cout<<"  "<<Matrix[i][j]<<' ';
			}
			else if (Matrix[i][j] < 100){
				cout<<' '<<Matrix[i][j]<<' ';
			}
			else{
				cout<<Matrix[i][j]<<' ';
			}
		}
		cout<<'\n';
	}
}

int main(){
	int SizeString;
	int SizeColumn;
	cout<<"Put sizes of your table:\n";
	cin>>SizeString>>SizeColumn;
	cout<<"Put your table:\n";
	if(SizeColumn == 1){
		int* Array = new int [SizeString];
		for (int i = 0; i < SizeString; ++i){
			cin>>Array[i];
		}
		print (Array, SizeString);
	}
	else if (SizeString == 1){
		int* Array = new int [SizeColumn];
		for (int i = 0; i < SizeColumn; ++i){
			cin>>Array[i];
		}
		print (Array, SizeColumn);
	}
	else{
		int** Matrix = new int* [SizeString];
		for (int i = 0; i < SizeString; ++i){
			Matrix[i] = new int [SizeColumn];
		}
		for (int i = 0; i < SizeString; ++i){
			for (int j = 0; j < SizeColumn; ++j){
				cin>>Matrix[i][j];
			}
		}
		print(Matrix, SizeString, SizeColumn);
	}
}
