#include<iostream>
#include<cstring>

struct Stack{
	int Key;
	int Min;
	Stack *Next;
};

Stack *push(int Key, int &Count){
	Stack *pv = new Stack;
	pv -> Key = Key;
	pv -> Min = Key;
	pv -> Next = 0;
	++Count;
	printf("ok\n");
	return pv;
}

void push (Stack **p, int Key, int &Count){
	Stack *pv = new Stack;
	pv -> Key = Key;
	pv -> Next = *p;
	pv -> Min = ((pv -> Key) < (pv -> Next -> Min)) ? (pv -> Key) : (pv -> Next -> Min);
	++Count;
	printf("ok\n");
	(*p) = pv;
} 

void pop (Stack **p, int &Count){
	if (Count == 0){
		printf("error\n");
	}	
	else {
		Stack *pv = (*p);
		printf("%d\n", (*p) -> Key);
		(*p) = (*p) -> Next;
		delete pv;
		--Count;
	}
}

void back (Stack **p, int Count){
	if (Count == 0)  {
		printf("error\n");
	}
	else {
		printf("%d\n", (*p) -> Key);
	}
}

void min (Stack **p, int Count) {
	if (Count == 0) {
		printf("error\n");
	} 
	else{
		printf("%d\n", (*p) -> Min);
	}
}

void size (int Count){
	printf("%d\n", Count);
}

void clear (Stack *p){
	if(p -> Next != 0){
		clear(p -> Next);
	}
	delete p;
}

int main(){
	char Instruct[6];
	int m;
	int Count = 0;
	Stack *pf;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i){
		std::cin>>Instruct;
		if (strcmp(Instruct, "push") == 0){
			int Key;
			scanf("%d", &Key);
			if (Count == 0){
				pf = push(Key, Count);
			}
			else{
				push(&pf, Key, Count);
			}
		}
		else if (strcmp(Instruct, "pop") == 0){
			pop (&pf, Count);
		}
		else if (strcmp(Instruct, "min") == 0){
			min(&pf, Count);
		}
		else if (strcmp(Instruct, "size") == 0){
			size(Count);
		}
		else if (strcmp(Instruct, "clear") == 0){
			if (Count != 0){
				clear(pf);
				Count = 0;
			}
			printf("ok\n");
		}
		else if (strcmp(Instruct, "back") == 0) {
			back(&pf, Count);
		}
	}
	if (Count != 0){
		clear(pf);
	}
	return 0;
}
