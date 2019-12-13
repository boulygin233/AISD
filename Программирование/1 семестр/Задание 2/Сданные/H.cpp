#include<iostream>
using namespace std;
struct Queue{
	int Key;
	Queue *Next;
	Queue *Prev;
};

Queue *push(int Key, int &Count){
	Queue *pv = new Queue;
	pv -> Key = Key;
	pv -> Next = 0;
	pv -> Prev = 0;
	++Count;
	return pv;
}

void push (Queue **pe, Queue **pm, int Key, int &Count, char Status){
	Queue *pv = new Queue;
	pv -> Key = Key;
	if (Status == '+' || Count == 1){
		(*pe) -> Prev = pv;
		pv -> Prev = 0;
		pv -> Next = (*pe);
		(*pe) = pv;
	}
	else{
		pv->Next = (*pm);
		pv->Prev = (*pm)->Prev;
		(*pm)->Prev->Next = pv;
		(*pm)->Prev = pv;
	}
	if (Count % 2 == 0){
		(*pm) = (*pm) -> Prev;
	}
	++Count;
} 

void pop (Queue **pf, Queue **pe, Queue **pm, int &Count){
		Queue *pv = (*pf);
		cout<<(*pf) -> Key<<'\n';
		if(Count == 1){
			(*pf) = 0;
			(*pe) = 0;
			(*pm) = 0;
		}
		else{
			(*pf) -> Prev -> Next = 0;
			(*pf) = (*pf) -> Prev;
			if (Count % 2 == 0){
				(*pm) = (*pm) -> Prev;
			}
		}
		delete pv;
		--Count;
}

void clear (Queue *p){
	if(p -> Next != 0){
		clear(p -> Next);
	}
	delete p;
}

int main(){
	int n;
	cin>>n;
	int Count = 0;
	Queue *pf;
	Queue *pe;
	Queue *pm;
	for (int i = 0; i < n; ++i){
		char Comand;
		cin>>Comand;
		if (Comand == '-'){
			pop (&pf, &pe, &pm, Count);
		}
		else{
			int Key;
			cin>>Key;
			if (Count == 0){
				pe = push (Key, Count);
				pf = pe;
				pm = pe;
			}
			else{
				push(&pe, &pm, Key, Count, Comand);
			}
		}
	}
	if (Count != 0){
		clear(pe);
	}
	return 0;
}
