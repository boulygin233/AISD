#include <iostream>
using namespace std;

/*int Max (int a, int b){
	return (a > b) ? a : b;
}
int Min (int a, int b){
	return (a < b) ? a : b;
}


int Patrition(int *Data, int Left, int Right){
	int Middle = Data[(Left + Right) / 2];
	int i = Left;
	int j = Right - 1;
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

int FindStatistic(int *Data, int k, int Begin,  int End){
	int Left = 0;
	int Right = Size;
	int f = 0;
	while (f == 0){
		int Middle = Patrition (Data, Left, Right);
		if (Middle == k){
			cout<<'\n'<<Middle<<"a\n";
			return Data[Middle];
			f = 1;
		}
		else if (k < Middle){
			Right = Middle;
		}
		else {
			k -= Middle + 1;
			Left = Middle + 1;
		}
	}
}
*/
void Swap (int *Data, int i, int j){
	int t = Data[i];
	Data[i] = Data[j];
	Data[j] = t;
}

long long FindStatistic(int *Data, int Begin, int End, int k){
	long long x = Data[(Begin + End) / 2];
	int i = Begin;
	int j = End;
	while(i <= j){ 
		while(Data[i] < x) {
			i++;
		}
		while(Data[j] > x) {
			j--;
		}
		if(i <= j) { 
			Swap(Data, i, j); 
			i++;
			j--;
		} 
	}
	if (Begin <= k && k <= j){
		return FindStatistic(Data, Begin, j, k);
	} 
	if (i <= k && k <= End){
		return FindStatistic(Data, i, End, k);
	}
	return Data[k]; 
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

int main(){
	int Size;
	int k;
	cin>>Size>>k;
	int Data[Size];
	cin>>Data[0];
	if (Size == 1){
		cout<<Data[0];
		return 0;
	}
	cin>>Data[1];
	for (int i = 2; i < Size; ++i){
		Data[i] = (Data[i - 1] * 123 + Data[i - 2] * 45) % 10004321;
	}
	cout<<FindStatistic(Data, 0, Size - 1, k - 1);
	return 0;
}




