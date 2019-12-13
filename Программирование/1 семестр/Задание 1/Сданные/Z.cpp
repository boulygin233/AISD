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
	if ((ChildLeft < n) && (Heap[ChildLeft] > Heap[MinChild])){
		MinChild = ChildLeft; 
	}
	if ((ChildRight < n) && (Heap[ChildRight] > Heap[MinChild])){
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
	while (i > 0 && Heap[i] > Parent(Heap, i)){
		i = sift_up(Heap, i);
	}
}

void Extract_min (int *Heap, int &n){
	swap (Heap, 0, n - 1);
	--n;
	sift_down(Heap, n, 0);
}

void Sort (int *Data, int Size){
	int n = Size;
	for (int i = 0; i < Size; ++i){
		Extract_min(Data, n);
	}
}

int main(){
	int size;
	cin>>size;
	int n = 0;
	int *Heap = new int [size];
	for (int i = 0; i < size; ++i){
		int x;
		cin>>x;
		Insert(Heap, n, x);
	}
	Sort(Heap, size);
	for (int i = 0; i < size; ++i){
		cout<<Heap[i]<<' ';
	}
	delete [] Heap;
	return 0;
}
