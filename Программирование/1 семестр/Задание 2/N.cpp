#include <iostream>
#include <cstring>
using namespace std;

struct Node{
	int Key;
	Node* Next;
	Node* Prev;
};

Node *Add(int Key, int &Count){
	Node* pv = new Node;
	pv->Key = Key;
	pv->Next = 0;
	pv->Prev = 0;
	++Count;
	return pv;
}

void Add(int Key, int &Count, Node **pf, Node **pe){
	Node* pv = new Node;
	pv->Key = Key;
	if ((*pe)->Key < Key){
		(*pe)->Next = pv;
		pv->Prev = (*pe);
		(*pe) = pv;
		pv->Next = 0;
	}
	else if ((*pf)->Key > Key){
		(*pf)->Prev = pv;
		pv->Next = (*pf);
		pv->Prev = 0;
		(*pf) = pv;
	}
	else{
		Node *pn = *pf;
		while (Key > pn->Key){
			pn = pn->Next;
		}
		pn->Prev->Next = pv;
		pv->Prev = pn->Prev;
		pv->Next = pn;
		pn->Prev = pv;
	}
	++Count;
}

void min (Node **pf, Node ** pe, int &Count){
	if (Count == 1){
		cout<<(*pf)->Key<<'\n';
		--Count;
		delete (*pf);
		(*pf) = 0;
		(*pe) = 0;
	}
	else{
		cout<<(*pf)->Key<<'\n';
		--Count;
		Node *t = (*pf)->Next;
		delete (*pf);
		(*pf) = t;
		(*pf)->Prev = 0;
	}
}

void max (Node **pe, Node ** pf, int &Count){
	if (Count == 1){
		cout<<(*pe)->Key<<'\n';
		--Count;
		delete (*pf);
		(*pe) = 0;
		(*pf) = 0;
	}
	else{
		cout<<(*pe)->Key<<'\n';
		--Count;
		Node *t = (*pe)->Prev;
		delete (*pe);
		(*pe) = t;
		(*pe)->Next = 0;
	}
}

void mid (Node **pf, Node **pe, int &Count){
	if (Count == 1){
		cout<<(*pf)->Key<<'\n';
		--Count;
		delete (*pf);
		(*pf) = 0;
		(*pe) = 0;
	}
	else{
		int n = (Count - 1) / 2;
		Node *t = (*pf);
		for (int i = 0; i < n; ++i){
			t = t->Next;
		}
		cout<<t->Key<<'\n';
		if (t != (*pf)){
			t->Prev->Next = t->Next;
		}
		else{
			*pf = t->Next;
		}
		t->Next->Prev = t->Prev;
		delete t;
		--Count;
	}
}

void print (int Count, Node *pf){
	Node *t = pf;
	for (int i = 0; i < Count; ++i){
		cout<<t->Key<<' ';
		t = t->Next;
	}
	cout<<'\n';
}
int main(){
	int Count = 0;
	int N;
	cin>>N;
	Node *pf;
	Node *pe;
	char s[7];
	for (int i = 0; i < N; ++i){
		cin>>s;
		if (strcmp(s, "add") == 0){
			int Key;
			cin>>Key;
			if (Count == 0){
				pf = Add(Key, Count);
				pe = pf;
			}
			else{
				Add(Key, Count, &pf, &pe);
			}
		}
		else if (strcmp(s, "min") == 0){
			min(&pf, &pe, Count);
		}
		else if (strcmp(s, "max") == 0){
			max(&pe, &pf, Count);
		}
		else if (strcmp(s, "mid") == 0){
			mid(&pf, &pe, Count);
		}
		else if (strcmp(s, "print") == 0){
			print (Count, pf);
		}
	}
}
