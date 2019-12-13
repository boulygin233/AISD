#include<iostream>
#include<cstring>
/*
    strcpy(s1,s); - копирует s в s1
	strcmp(s1,s); - выдает 0, если равны, и нечто иное если не равны
	strcna(s1,s); - если в s есть такая подстрока s1, то возращает указатель на начало этой подстроки
	strncpy(s1,s,n); где n - кол-во символов, которые надо скопировать
*/
using namespace std;
int main(){
	char s[]="hello";
	char s1[]="hallll";
	cout<<strrchr(s,'l');
}
