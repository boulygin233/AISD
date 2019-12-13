#include<iostream>
#include<cstring>
using namespace std;

struct Stack{
	int Key;
	int Min;
	Stack *Next;
};

Stack *enqueue(int Key, int &Count){
	Stack *pv = new Stack;
	pv -> Key = Key;
	pv -> Min = Key;
	pv -> Next = 0;
	++Count;
	return pv;
}

void enqueue(Stack **pe, int Key, int &Count){
	Stack *pv = new Stack;
	pv -> Key = Key;
	pv -> Next = (*pe);
	pv -> Min = ((pv -> Key) < (pv -> Next -> Min)) ? (pv -> Key) : (pv -> Next -> Min);
	++Count;
	(*pe) = pv;
}

void dequeue(Stack **p, int &Count){
	Stack *pv = (*p);
	(*p) = (*p) -> Next;
	delete pv;
	--Count;
}

int FLTR(Stack **p, int &Count){
	Stack *pv = (*p);
	int k = (*p) -> Key;
	(*p) = (*p) -> Next;
	delete pv;
	--Count;
	return k;
}

void clear (Stack *p){
	if(p -> Next != 0){
		clear(p -> Next);
	}
	delete p;
}


int main(){
	int n, k;
	int CountL = 0;
	int CountR = 0;
	Stack *per;
	Stack *pel;
	cin>>n>>k;
	int Data[n];
	for (int i = 0; i < n; ++i){
		cin>>Data[i];
	}
	pel = enqueue (Data[0], CountL);
	for (int i = 1; i < k; ++i){
		enqueue(&pel, Data[i], CountL);
	}
	
	for (int i = k; i < n; ++i){
		if (CountR == 0){
			if (CountL == 0){
				cout<<"error\n";
			}
			else{
				cout<<pel -> Min<<'\n';
			}
		}
		else if (CountL == 0){
			cout<<per->Min<<'\n';
		}
		else{
			if (pel->Min < per->Min) {
				cout<<pel->Min<<'\n';
			}
			else{
				cout<<per->Min<<'\n';
			}
		}
		if (CountR == 0){
			if (CountL == 0){
				cout<<"error\n";
			}
			else{
				per = enqueue (FLTR (&pel, CountL), CountR);
				int ok = CountL;
				for (int j = 0; j < ok; ++j){
					enqueue(&per, FLTR(&pel, CountL), CountR);
				}
				dequeue (&per, CountR);
			}
		}
		else {
			dequeue (&per, CountR);
		}
		if (CountL == 0) {
			pel = enqueue (Data[i], CountL);
		}
		else {
			enqueue (&pel, Data[i], CountL);
		}
	}
	
	if (CountR == 0){
		if (CountL == 0){
			cout<<"error\n";
		}
		else{
			cout<<pel -> Min<<'\n';
		}
	}
	else if (CountL == 0){
		cout<<per->Min<<'\n';
	}
	else{
		if (pel->Min < per->Min) {
			cout<<pel->Min<<'\n';
		}
		else{
			cout<<per->Min<<'\n';
		}
	}	
	
	
	if (CountL != 0){
		clear (pel);
	}
	if (CountR != 0){
		clear (per);
	}
	
	return 0;
}
