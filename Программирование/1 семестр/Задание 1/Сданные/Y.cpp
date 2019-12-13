#include <iostream>
#include <cstring>
using namespace std;

void swap (int *Heap, int a, int b) {
	int t = Heap[a];
	Heap[a] = Heap[b];
	Heap[b] = t;
}

int Min (int a, int b, int c){
	if (a >= b && a >=c){
		return (b < c) ? b : c;
	}
	if (c >= b && c >=a){
		return (b < a) ? b : a;
	}
	if (b >= a && b >=c){
		return (a < c) ? a : c;
	}
}

int Parent (int *Heap, int i){
	return Heap[(i - 1) / 2];
}

int sift_up (int *Heap, int i){
	swap (Heap, i, (i - 1) / 2);
	return ((i - 1) / 2);
}

void sift_down(int *Heap, int &n, int i) {
	int ChildLeft = 2 * i + 1;
	int ChildRight = 2 * i + 2;
	int MinChild = i;
	if ((ChildLeft < n) && (Heap[ChildLeft] < Heap[MinChild])){
		MinChild = ChildLeft; 
	}
	if ((ChildRight < n) && (Heap[ChildRight] < Heap[MinChild])){
		MinChild = ChildRight;
	}
	if (MinChild != i) {
		swap(Heap, MinChild, i);
		sift_down (Heap, n, MinChild);
	}
}

void Insert (int *Heap, int &n, int Add) {
	Heap[n] = Add;
	int i = n;
	++n;
	while (i > 0 && Heap[i] < Parent(Heap, i)){
		i = sift_up(Heap, i);
	}
	cout<<"ok"<<'\n';
}

void Extract_min (int *Heap, int &n){
	int min = Heap[0];
	Heap[0] = Heap[n - 1];
	--n;
	int i = 0;
	sift_down(Heap, n, i);
	cout<<min<<'\n';	
}

void Get_min (int *Heap){
	cout<<Heap[0]<<'\n';
}

void Clear (int &n){
	n = 0;
	cout<<"ok"<<'\n';
}

void Size (int &n){
	cout<<n<<'\n';
}

int main(){
	int M;
	cin>>M;
	int n = 0;
	int *Heap = new int [M];
	char s[12];
	char Ins[] = "insert";
	char Exs[] = "extract_min";
	char Get[] = "get_min";
	char Siz[] = "size";
	char Cle[] = "clear";
	for (int i = 0; i < M; ++i) {
		cin>>s;
		if (strcmp(s, Ins) == 0){
			int Add;
			cin>>Add;
			Insert(Heap, n, Add);
		}
		if (strcmp(s, Exs) == 0) {
			if (n == 0){
				cout<<"error"<<'\n';
			}
			else {
				Extract_min (Heap, n);
			}
		}
		if (strcmp(s, Get) == 0) {
			if (n == 0){
				cout<<"error"<<'\n';
			}
			else {
				Get_min (Heap);
			}
		}
		if (strcmp(s, Siz) == 0){
			Size(n);
		}
		if (strcmp(s, Cle) == 0){
			Clear(n);
		}
	}
	delete [] Heap;
	return 0;
}
