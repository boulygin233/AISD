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
	cout<<(*p) -> Key<<'\n';
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

void front (Stack **p){
	cout<<(*p) -> Key<<"\n";
}

void clear (Stack *p){
	if(p -> Next != 0){
		clear(p -> Next);
	}
	delete p;
}

void size (int CountR, int CountL){
	cout<<CountR + CountL<<'\n';
}

int main(){
	int m;
	int CountL = 0;
	int CountR = 0;
	Stack *per;
	Stack *pel;
	cin>>m;
	char Instruct[10];
	for (int i = 0; i < m; ++i){
		cin>>Instruct;

		if (strcmp(Instruct, "enqueue") == 0) {
			int Key;
			cin>>Key;
			if (CountL == 0) {
				pel = enqueue (Key, CountL);
			}
			else {
				enqueue (&pel, Key, CountL);
			}
			cout<<"ok\n";
		}
		
		else if (strcmp(Instruct, "dequeue") == 0){
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
		}
		
		else if (strcmp(Instruct, "front") == 0){
			if (CountR != 0){
				front(&per);
			}
			else if (CountL == 0){
				cout<<"error\n";
			}
			else {
				per = enqueue(FLTR (&pel, CountL), CountR);
				int ok = CountL;
				for (int j = 0; j < ok; ++j){
					enqueue(&per, FLTR(&pel, CountL), CountR);
				}
				front (&per);
			}
		}
		
		else if (strcmp(Instruct, "size") == 0) {
			size(CountR, CountL);
		}
		
		else if (strcmp(Instruct, "min") == 0){
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
		}
		else if (strcmp(Instruct, "clear") == 0){
			if (CountL != 0){
				clear(pel);
				CountL = 0;
			}
			if (CountR != 0){
				clear(per);
				CountR = 0;
			}
			cout<<"ok\n";
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
