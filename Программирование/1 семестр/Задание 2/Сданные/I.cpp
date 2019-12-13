#include<iostream>
using namespace std;
void Swap (int *Data, int i, int j){
	int t = Data[i];
	Data[i] = Data[j];
	Data[j] = t;
}
int Patrition(int *Data, int Left, int Right){
	int Middle = Data[(Left + Right) / 2];
	int i = Left;
	int j = Right;
	while (i <= j){
		while (Data[i] < Middle){
			i++;
		}
		while (Data[j] > Middle){
			j--;
		}
		if (i >= j){
			break;
		}
		Swap(Data, i, j);
		i++;
		j--;
	}
	return j;
}

void quicksort(int *Data, int Begin, int End){
	if (Begin < End){
		int q = Patrition (Data, Begin, End);
		quicksort (Data, Begin, q);
		quicksort (Data, q + 1, End);
	}
}

void QuickSort (int *Begin, int *End){
	int Size = End - Begin;
	quicksort(Begin, 0, Size - 1);
}

int main(){
	int Size;
	cin>>Size;
	int Data[Size];
	for (int i = 0; i < Size; ++i){
		cin>>Data[i];
	}
	QuickSort(Data, Data + Size);
	for (int i = 0; i < Size; ++i){
		cout<<Data[i]<<' ';
	}
}
