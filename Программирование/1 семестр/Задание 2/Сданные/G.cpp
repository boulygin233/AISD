#include <iostream>
using namespace std;

struct brakets{
	int Key;
	brakets *Next;
};

enum Brakets{RoundO = '(', SquareO = '[', FiguredO = '{', RoundC = ')', SquareC = ']', FiguredC = '}'};

brakets *push(int Key, int &Count){
	brakets *pv = new brakets;
	pv->Key = Key;
	pv->Next = 0;
	++Count;
	return pv;
}

void push (brakets **p, int Key, int &Count){
	brakets *pv = new brakets;
	pv->Key = Key;
	pv->Next = (*p);
	(*p) = pv;
	++Count;
}

int pop (brakets **p, int &Count){
	brakets *pv = (*p);
	(*p) = pv->Next;
	int b = pv->Key;
	delete pv;
	--Count;
	return b;
}

void clear (brakets *p){
	if(p -> Next != 0){
		clear(p -> Next);
	}
	delete p;
}

int main(){
	char braket;
	brakets *pf;
	int Count = 0;
	while (cin>>braket){
		if (braket == RoundO){
			if (Count == 0){
				pf = push (RoundO, Count);
			}
			else{
				push (&pf, RoundO, Count);
			}
		}
		 else if (braket == SquareO){
			if (Count == 0){
				pf = push (SquareO, Count);
			}
			else{
				push (&pf, SquareO, Count);
			}
		}
		else if (braket == FiguredO){
			if (Count == 0){
				pf = push (FiguredO, Count);
			}
			else{
				push (&pf, FiguredO, Count);
			}
		}
		else{
			if (Count == 0){
				cout<<"no";
				return 0;
			}
			else{
				char k = pop (&pf, Count);
				if (k == RoundO && braket != RoundC){
					cout<<"no";
					return 0;
				}
				else if (k == SquareO && braket != SquareC){
					cout<<"no";
					return 0;
				}
				else if (k == FiguredO && braket != FiguredC){
					cout<<"no";
					return 0;
				}
			}
		}
	}
	if (Count == 0){
		cout<<"yes";
	}
	else{
		clear (pf);
		cout<<"no";
	}
}

