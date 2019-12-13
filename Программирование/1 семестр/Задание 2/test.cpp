#include <iostream>
using namespace std;
struct Node{
	int Key;
	int Num;
};

int main(){
	Node a = new Node;
	Node b = new Node;
	a.Key = 10;
	a.Num = 1;
	b.Key = 3;
	b.Num = 2;
	a = b;
	cout<<a->Key<<b->Key<<a->Num<<b->Num;
}
