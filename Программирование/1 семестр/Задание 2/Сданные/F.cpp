#include <iostream>
using namespace std;

struct Calculus{
	int Key;
	Calculus *Next;
};

Calculus *push(int Key, int &Count){
	Calculus *pv = new Calculus;
	pv->Key = Key;
	pv->Next = 0;
	++Count;
	return pv;
}

void push (Calculus **p, int Key, int &Count){
	Calculus *pv = new Calculus;
	pv->Key = Key;
	pv->Next = (*p);
	(*p) = pv;
	++Count;
}

int pop (Calculus **p, int &Count){
	Calculus *pv = (*p);
	(*p) = pv->Next;
	int n = pv->Key;
	delete pv;
	return n;
}

int main(){
	char Sim;
	Calculus *pf;
	int Count = 0;
	while (cin>>Sim){
		if ((int)Sim - 48 >= 0){
			if (Count == 0){
				pf = push ((int)Sim - 48, Count);
			}
			else{
				push (&pf, (int)Sim - 48, Count);
			}
		}
		else{
			if (Sim == '+'){
				int res = pop(&pf, Count) + pop(&pf, Count);
				if (Count == 0){
					pf = push (res, Count);
				}
				else{
					push (&pf, res, Count);
				}
			}
			if (Sim == '-'){
				int res = (pop(&pf, Count) - pop(&pf, Count));
				res = 0 - res;
				if (Count == 0){
					pf = push (res, Count);
				}
				else{
					push (&pf, res, Count);
				}
			}
			if (Sim == '*'){
				int res = pop(&pf, Count) * pop(&pf, Count);
				if (Count == 0){
					pf = push (res, Count);
				}
				else{
					push (&pf, res, Count);
				}
			}
		}
	}
	cout<<pop(&pf, Count);
}
