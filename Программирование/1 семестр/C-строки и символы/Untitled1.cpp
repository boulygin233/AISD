#include<iostream>
#include<cstring>
/*
    strcpy(s1,s); - �������� s � s1
	strcmp(s1,s); - ������ 0, ���� �����, � ����� ���� ���� �� �����
	strcna(s1,s); - ���� � s ���� ����� ��������� s1, �� ��������� ��������� �� ������ ���� ���������
	strncpy(s1,s,n); ��� n - ���-�� ��������, ������� ���� �����������
*/
using namespace std;
int main(){
	char s[]="hello";
	char s1[]="hallll";
	cout<<strrchr(s,'l');
}
