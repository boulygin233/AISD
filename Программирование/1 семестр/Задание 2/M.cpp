#include <iostream>
#include <cstring>
using namespace std;

int DataSizeMin, CountMin, DataSizeMax, CountMax;

int Parent(int i){
    return i / 2;
}

int ChildLeft(int i){
    return i * 2;
}

int ChildRight(int i){
    return 2 * i + 1;
}

struct Node{
    int Num;
    int Key;
};


void Swap(Node* Heap, int* Elements, int Par, int i){
    Elements[Heap[i].Num] = Par;
    Elements[Heap[Par].Num] = i;
    Node t = Heap[Par];
    Heap[Par] = Heap[i];
    Heap[i] = t;
}

void sift_up_min(Node* Heap, int* Elements, int i){
    while (i > 0) {
        int parent = Parent(i);
        if (Heap[i].Key < Heap[parent].Key) {
            Swap(Heap, Elements, Parent(i), i);
            i = parent;
        } else {
            return;
        }
    }
}

void sift_up_max(Node* Heap, int* Elements, int i){
    while (i > 0) {
        int parent = Parent(i);
        if (Heap[i].Key > Heap[parent].Key) {
            Swap(Heap, Elements, Parent(i), i);
            i = parent;
        } else {
            return;
        }
    }
}

void sift_down_min(Node* Heap, int* Elements, int i){
    int l = ChildLeft(i);
	int r = ChildRight(i);
	int MinChild;
    if (l <= CountMin && Heap[l].Key < Heap[i].Key){
        MinChild = l;
    } else {
        MinChild = i;
    }
    if (r <= CountMin && Heap[r].Key < Heap[MinChild].Key){
        MinChild = r;
    }
    if (MinChild != i){
        Swap(Heap, Elements, MinChild,i);
        sift_down_min(Heap, Elements, MinChild);
    }
}

void sift_down_max(Node* Heap, int* Elements, int i){
    int l = ChildLeft(i);
	int r = ChildRight(i);
	int MaxChild;
    if (l <= CountMax && Heap[l].Key > Heap[i].Key){
        MaxChild = l;
    } else {
        MaxChild = i;
    }
    if (r <= CountMax && Heap[r].Key > Heap[MaxChild].Key){
        MaxChild = r;
    }
    if (MaxChild != i){
        Swap(Heap, Elements, MaxChild, i);
        sift_down_max(Heap, Elements, MaxChild);
    }
}

void insert_min(Node* Heap, int* Elements, int Add){
    ++DataSizeMin;
    ++CountMin;
    Heap[CountMin].Key = Add;
    Heap[CountMin].Num = DataSizeMin;
    Elements[DataSizeMin] = CountMin;
	sift_up_min(Heap, Elements, CountMin);
}

void insert_max(Node* Heap, int* Elements, int Add){
    ++DataSizeMax;
    ++CountMax;
    Heap[CountMax].Key = Add;
    Heap[CountMax].Num = DataSizeMax;
    Elements[DataSizeMax] = CountMax;
	sift_up_max(Heap, Elements, CountMax);
}

void change_min(Node* Heap, int* Elements, int k, int New){
    int i = Elements[k];
    Heap[i].Key = New;
    if (CountMin > 1) {
        sift_up_min(Heap, Elements, i);
        sift_down_min(Heap, Elements, i);
    }
}

void change_max(Node* Heap, int* Elements, int k, int New){
    int i = Elements[k];
    Heap[i].Key = New;
    if (CountMax > 1) {
        sift_up_max(Heap, Elements, i);
        sift_down_max(Heap, Elements, i);
    }
}

void deleting_min(Node* Heap, int* Elements, int k){
    int i = Elements[k];
    if (CountMin > 1){
        Swap(Heap, Elements, i, CountMin);
	}
    --CountMin;
    Elements[k] = -1;
    sift_up_min(Heap, Elements, i);
    sift_down_min(Heap, Elements, i);
}

void deleting_max(Node* Heap, int* Elements, int k){
    int i = Elements[k];
    if (CountMax > 1){
        Swap(Heap, Elements, i, CountMax);
	}
    --CountMax;
    Elements[k] = -1;
    sift_up_max(Heap, Elements, i);
    sift_down_max(Heap, Elements, i);
}

int extract_min(Node* HeapMin, Node* HeapMax, int* ElementsMin, int* ElementsMax){
    int t = HeapMin[1].Key;
    int k = HeapMin[1].Num;
    deleting_min(HeapMin, ElementsMin, k);
    deleting_max(HeapMax, ElementsMax, k);
    return t;
}

int extract_max(Node* HeapMax, Node* HeapMin, int* ElementsMax, int* ElementsMin){
    int t = HeapMax[1].Key;
    int k = HeapMax[1].Num;
    deleting_max(HeapMax, ElementsMax, k);
    deleting_min(HeapMin, ElementsMin, k);
    return t;
}

int main() {
    int M;
    cin >> M;
    Node* HeapMin = new Node [M + 1];
    int* ElementsMin = new int [M + 1];
    HeapMin[0].Key = 0;
    HeapMin[0].Num = 0;
    CountMin = 0;
    DataSizeMin = 0;
    Node* HeapMax = new Node [M + 1];
    int* ElementsMax = new int [M + 1];
    HeapMax[0].Key = 1000000001;
    HeapMax[0].Num = 0;
    CountMax = 0;
    DataSizeMax = 0;
    char s[12];
	char Ins[] = "insert";
	char Exs[] = "extract_min";
	char Get[] = "get_min";
	char Siz[] = "size";
	char Cle[] = "clear";
	char ExsM[] = "extract_max";
	char GetM[] = "get_max";
    for (int j = 0; j < M; ++j){
        cin >> s;
        if (strcmp(s, Ins) == 0){
            int Add;
            cin>>Add;
            insert_min(HeapMin, ElementsMin, Add);
            insert_max(HeapMax, ElementsMax, Add);
            cout<<"ok"<<'\n';
        }
        else if (strcmp(s, Exs) == 0){
            if (CountMin != 0) {
                cout<<extract_min(HeapMin, HeapMax, ElementsMin, ElementsMax)<<'\n';
            } 
			else{
                cout<<"error"<<'\n';
            }
        }
        else if (strcmp(s, ExsM) == 0){
            if (CountMax != 0) {
                cout<<extract_max(HeapMax, HeapMin, ElementsMax, ElementsMin)<<'\n';
            } 
			else{
                cout<<"error"<<'\n';
            }
        }
        else if (strcmp(s, Get) == 0){
            if (CountMin != 0) {
                cout <<HeapMin[1].Key<<'\n';
            }
			else{
                cout<<"error"<<'\n';
        	}
        }
        else if (strcmp(s, GetM) == 0){
            if (CountMax != 0) {
                cout<<HeapMax[1].Key<<'\n';
            }
			else{
                cout<<"error"<<'\n';
            }
        }
        else if (strcmp(s, Siz) == 0){
            cout<<CountMin<<'\n';
        }
        else if (strcmp(s, Cle) == 0){
            CountMin = 0;
            CountMax = 0;
            for (int i = 0; i <= DataSizeMin; ++i){
                ElementsMin[i] = -1;
                ElementsMax[i] = -1;
            }
            cout<<"ok\n";
        }
    }
	return 0;
}
