#include<iostream>
using namespace std;
int main(){
	int *a = new int[size]; //создание динамического массива размера size
	int x=sizeof(a)/sizeof(a[0]);//количество элементов массива
	delete [] a; //очистка памяти (иначе утечка памяти)
	
	
	
	
		
}
