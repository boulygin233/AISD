#include <iostream>
using namespace std;

struct ShipTime{
	int Time;
	int Status;
};

bool operator > (const ShipTime &S1, const ShipTime &S2){
	if (S1.Time > S2.Time){
		return 1;
	}
	else if (S1.Time == S2.Time){
		if (S1.Status < S2.Status){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		return 0;
	}
}

bool operator < (const ShipTime &S1, const ShipTime &S2){
	if (S1.Time < S2.Time){
		return 1;
	}
	else if (S1.Time == S2.Time){
		if (S1.Status > S2.Status){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{	
		return 0;
	}
}

void Swap (ShipTime *Times, int i, int j){
	int t = Times[i].Time;
	int s = Times[i].Status;
	Times[i].Time = Times[j].Time;
	Times[i].Status = Times[j].Status;
	Times[j].Time = t;
	Times[j].Status = s;
}
int Patrition(ShipTime *Times, int Left, int Right){
	ShipTime Middle = Times[(Left + Right) / 2];
	int i = Left;
	int j = Right;
	while (i <= j){
		while (Times[i] < Middle){
			i++;
		}
		while (Times[j] > Middle){
			j--;
		}
		if (i >= j){
			break;
		}
		Swap(Times, i, j);
		i++;
		j--;
	}
	return j;
}

void quicksort(ShipTime *Times, int Begin, int End){
	if (Begin < End){
		int q = Patrition (Times, Begin, End);
		quicksort (Times, Begin, q);
		quicksort (Times, q + 1, End);
	}
}

int main(){
	int n;
	cin>>n;
	ShipTime *Times = new ShipTime [2 * n];
	for (int  i = 0; i < 2 * n; ++i){
		if (i % 2 == 0){
			cin>>Times[i].Time;
			Times[i].Status = 1;
		}
		else{
			int L;
			cin>>L;
			Times[i].Time = Times[i - 1].Time + L - 1;
			Times[i].Status = -1;
		}
	}
	quicksort(Times, 0, 2 * n - 1);
	int Now = 0;
	int M = 0;
	for (int i = 0; i < 2 * n; ++i){
		Now += Times[i].Status;
		if (Now > M){
			M = Now;
		}
	}
	cout<<M;
}
