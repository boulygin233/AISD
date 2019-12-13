#include <iostream>
#include <cstring>
using namespace std;

int DataSize, Count;

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

void sift_up(Node* Heap, int* Elements, int i){
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

void sift_down(Node* Heap, int* Elements, int i){
    int l = ChildLeft(i);
	int r = ChildRight(i);
	int MinChild;
    if (l <= Count && Heap[l].Key < Heap[i].Key){
        MinChild = l;
    } else {
        MinChild = i;
    }
    if (r <= Count && Heap[r].Key < Heap[MinChild].Key){
        MinChild = r;
    }
    if (MinChild != i){
        Swap(Heap, Elements, MinChild,i);
        sift_down(Heap, Elements, MinChild);
    }
}

void insert(Node* Heap, int* Elements, int Add){
    ++DataSize;
    ++Count;
    Heap[Count].Key = Add;
    Heap[Count].Num = DataSize;
    Elements[DataSize] = Count;
	sift_up(Heap, Elements, Count);
}


void change(Node* Heap, int* Elements, int k, int New){
    int i = Elements[k];
    Heap[i].Key = New;
    if (Count > 1) {
        sift_up(Heap, Elements, i);
        sift_down(Heap, Elements, i);
    }
}

void deleting(Node* Heap, int* Elements, int k){
    int i = Elements[k];
    if (Count > 1){
        Swap(Heap, Elements, i, Count);
	}
    --Count;
    Elements[k] = -1;
    sift_up(Heap, Elements, i);
    sift_down(Heap, Elements, i);
}

int extract_min(Node* Heap, int* Elements){
    int t = Heap[1].Key;
    int k = Heap[1].Num;
    deleting(Heap, Elements, k);
    return t;
}

int main() {
    int M;
    cin >> M;
    Node* Heap = new Node [M + 1];
    int* Elements = new int [M + 1];
    Count = 0;
    DataSize = 0;
    char s[12];
	char Ins[] = "insert";
	char Exs[] = "extract_min";
	char Get[] = "get_min";
	char Siz[] = "size";
	char Cle[] = "clear";
	char Del[] = "delete";
	char Cha[] = "change";
    for (int j = 0; j < M; ++j){
        cin >> s;
        if (strcmp(s, Ins) == 0){
            int Add;
            cin>>Add;
            insert(Heap, Elements, Add);
            cout<<"ok"<<'\n';
        }
        else if (strcmp(s, Exs) == 0){
            if (Count != 0) {
                cout<<extract_min(Heap, Elements)<<'\n';
            } else
                cout<<"error"<<'\n';
        }
        else if (strcmp(s, Get) == 0){
            if (Count != 0) {
                cout <<Heap[1].Key<<'\n';
            } else
                cout<<"error"<<'\n';
        }
        else if (strcmp(s, Del) == 0){
            int k;
            cin>>k;
            if (k <= DataSize) {
                if (Elements[k] != -1) {
                    deleting(Heap, Elements, k);
                    cout<<"ok"<<'\n';
                }
                else
                    cout<<"error"<<'\n';
            }else
                cout<<"error"<<'\n';
        }
        else if (strcmp(s, Cha) == 0){
            int k;
            int New;
            cin>>k>>New;
            if (k <= DataSize) {
                if (Elements[k] != -1) {
                    change(Heap, Elements, k, New);
                    cout<<"ok"<<'\n';
                } else
                    cout<<"error" <<'\n';
            } else{
                cout<<"error"<<'\n';
			}
        }
        else if (strcmp(s, Siz) == 0){
            cout<<Count<<'\n';
        }
        else if (strcmp(s, Cle) == 0){
            Count = 0;
            for (int i = 0; i <= DataSize; ++i)
                Elements[i] = -1;
            cout<<"ok"<<'\n';
        }
    }
	return 0;
}
