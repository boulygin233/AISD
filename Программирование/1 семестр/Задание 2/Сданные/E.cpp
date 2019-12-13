#include <iostream>
#include<cstring>
using namespace std;

struct Stack{
	int Key;
	Stack *Next;
	Stack *Prev;
};

Stack *push_first (int Key, int &Count){
	Stack *pv = new Stack;
	pv->Key = Key;
	pv->Next = 0;
	pv->Prev = 0;
	++Count;
	cout<<"ok\n";
	return pv;
}

void push_front (Stack **pf, int Key, int &Count){
	Stack *pv = new Stack;
	pv->Key = Key;
	pv->Next = 0;
	pv->Prev = (*pf);
	(*pf)->Next = pv;
	++Count;
	cout<<"ok\n";
	(*pf) = pv;
}

void push_back (Stack **pe, int Key, int &Count){
	Stack *pv = new Stack;
	pv->Key = Key;
	pv->Prev = 0;
	pv->Next = (*pe);
	(*pe)->Prev = pv;
	++Count;
	cout<<"ok\n";
	(*pe) = pv;
}

void pop_front (Stack **pf, int &Count){
	if (Count == 0){
		cout<<"error\n";
	}
	else if (Count == 1){
		Stack *pv = (*pf);
		cout<<pv->Key<<'\n';
		--Count;
		delete pv;
	}
	else{
		Stack *pv = (*pf);
		cout<<pv->Key<<'\n';
		(*pf)->Prev->Next = 0;
		(*pf) = pv->Prev;
		delete pv;
		--Count;
	}
}

void pop_back (Stack **pe, int &Count){
	if (Count == 0){
		cout<<"error\n";
	}
	else if (Count == 1){
		Stack *pv = (*pe);
		cout<<pv->Key<<'\n';
		--Count;
		delete pv;
	}
	else{
		Stack *pv = (*pe);
		cout<<pv->Key<<'\n';
		(*pe)->Next->Prev = 0;
		(*pe) = pv->Next;
		delete pv;
		--Count;
	}
}

void front (Stack *pf, int Count){
	if(Count == 0){
		cout<<"error\n";
	}
	else{
		cout<<pf->Key<<'\n';
	}
}

void back (Stack *pe, int Count){
	if(Count == 0){
		cout<<"error\n";
	}
	else{
		cout<<pe->Key<<'\n';
	}
}

void size(int Count){
	cout<<Count<<'\n';
}

void clear(Stack *pe){
	if(pe->Next != 0){
		clear(pe->Next);
	}
	delete pe;
}

int main(){
	int m;
	cin>>m;
	char Instruct[11];
	int Count = 0;
	Stack *pf;
	Stack *pe;
	for (int i = 0; i < m; ++i){
		cin>>Instruct;
		if (strcmp(Instruct, "push_back") == 0){
			int Key;
			cin>>Key;
			if (Count == 0){
				pe = push_first(Key, Count);
				pf = pe;
			}
			else{
				push_back(&pe, Key, Count);
			}
		}
		else if (strcmp(Instruct, "push_front") == 0){
			int Key;
			cin>>Key;
			if (Count == 0){
				pf = push_first(Key, Count);
				pe = pf;
			}
			else{
				push_front(&pf, Key, Count);
			}
		}
		else if (strcmp(Instruct, "pop_back") == 0){
			pop_back(&pe, Count);
		}
		else if (strcmp(Instruct, "pop_front") == 0){
			pop_front(&pf, Count);
		}
		else if (strcmp(Instruct, "front") == 0){
			front(pf, Count);
		}
		else if (strcmp(Instruct, "back") == 0){
			back(pe, Count);
		}
		else if (strcmp(Instruct, "clear") == 0){
			if(Count != 0){
				clear(pe);
				Count = 0;
			}
			cout<<"ok\n";
		}
		else if (strcmp(Instruct, "size") == 0){
			size(Count);
		}
	}
	if(Count != 0){
		clear(pe);
	}
	return 0;
}
