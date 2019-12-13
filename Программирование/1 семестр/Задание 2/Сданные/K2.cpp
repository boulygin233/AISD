#include<iostream>
#include<cstring>
using namespace std;

struct Stack{
	int Key;
	Stack *Next;
};

Stack *enqueue(long long Key, int &Count){
	Stack *pv = new Stack;
	pv -> Key = Key;
	pv -> Next = 0;
	++Count;
	return pv;
}

void enqueue (Stack **p, Stack **f, long long Key, int &Count){
	Stack *pv = new Stack;
	pv -> Key = Key;
	(*p) -> Next = pv;
	pv -> Next = 0;
	++Count;
	(*p) = pv;
} 

long long front (Stack **p, int Count){
	if (Count == 0)  {
		cout<<"error\n";
	}
	else {
		return (*p) -> Key;
	}
}

long long dequeue (Stack **p, int &Count){
	if (Count == 0){
		cout<<"error\n";
	}	
	else {
		Stack *pv = (*p);
		long long x = (*p) -> Key;
		(*p) = (*p) -> Next;
		delete pv;
		--Count;
		return x;
	}
}

void clear (Stack *p){
	if(p -> Next != 0){
		clear(p -> Next);
	}
	delete p;
}

int main(){
	int n, k;
	int Count = 0;
	Stack *pf;
	Stack *pe;
	cin>>n>>k;
	long long Seers;
	for (int i = 0; i < k + 1; ++i){
		cin>>Seers;
		if (Count == 0){
				pf = enqueue(Seers, Count);
				pe = pf;
			}
		else{
			enqueue(&pe, &pf, Seers, Count);
		}
	}
	long long MaxSeers = dequeue(&pf, Count);
	long long Maximum = MaxSeers + Seers;
	for (int i = 0; i < n - k - 1; ++i){
		cin>>Seers;
		if (Count == 0){
				pf = enqueue(Seers, Count);
				pe = pf;
			}
		else{
			enqueue(&pe, &pf, Seers, Count);
		}
		if (MaxSeers < front(&pf, Count)){
			MaxSeers = dequeue(&pf, Count);
		}
		else{
			dequeue(&pf, Count);
		}
		if (Maximum < MaxSeers + Seers){
			Maximum = MaxSeers + Seers;
		}
	}
	if (Count != 0){
		clear(pf);
	}
	cout<<Maximum;
	return 0;
}
