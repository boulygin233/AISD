#include<iostream>
#include<cstring>
using namespace std;

struct Stack{
	int Key;
	Stack *Next;
};

Stack *enqueue(int Key, int &Count){
	Stack *pv = new Stack;
	pv -> Key = Key;
	pv -> Next = 0;
	++Count;
	cout<<"ok"<<'\n';
	return pv;
}

void enqueue (Stack **p, Stack **f, int Key, int &Count){
	Stack *pv = new Stack;
	pv -> Key = Key;
	(*p) -> Next = pv;
	pv -> Next = 0;
	++Count;
	cout<<"ok"<<'\n';
	(*p) = pv;
} 

void dequeue (Stack **p, int &Count){
	if (Count == 0){
		cout<<"error\n";
	}	
	else {
		Stack *pv = (*p);
		cout<<(*p) -> Key<<'\n';
		(*p) = (*p) -> Next;
		delete pv;
		--Count;
	}
}

void front (Stack **p, int Count){
	if (Count == 0)  {
		cout<<"error\n";
	}
	else {
		cout<<(*p) -> Key<<'\n';
	}
}


void size (int Count){
	cout<<Count<<'\n';
}

void clear (Stack *p){
	if(p -> Next != 0){
		clear(p -> Next);
	}
	delete p;
}

int main(){
	char Instruct[10];
	int m;
	int Count = 0;
	Stack *pf; // Первый в очереди
	Stack *pe; // Последний в очереди
	cin>>m;
	for (int i = 0; i < m; ++i){
		cin>>Instruct;
		if (strcmp(Instruct, "enqueue") == 0){
			int Key;
			cin>>Key;
			if (Count == 0){
				pf = enqueue(Key, Count);
				pe = pf;
			}
			else{
				enqueue(&pe, &pf, Key, Count);
			}
		}
		else if (strcmp(Instruct, "dequeue") == 0){
			dequeue (&pf, Count);
		}
		else if (strcmp(Instruct, "size") == 0){
			size(Count);
		}
		else if (strcmp(Instruct, "clear") == 0){
			if (Count != 0){
				clear(pf);
				Count = 0;
			}
			cout<<"ok\n";
		}
		else if (strcmp(Instruct, "front") == 0){
			front(&pf, Count);
		}
	}
	if (Count != 0){
		clear(pf);
	}
	return 0;
}
