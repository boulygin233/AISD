#include<iostream>
using namespace std;
void swap1(int* a, int*b){
	int c=*a;
	*a=*b;
	*b=c;
}
void swap2(int& a, int& b){
	int c=a;
	a=b;
	b=c;
}
int main(){
	int x=3,y=5;
	swap1(&x,&y);
	cout<<x<<y;
	swap2(x,y);
	cout<<x<<y;
}
