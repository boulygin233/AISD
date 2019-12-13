#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char *String1 = new char [10000];
	char *String2 = new char [10000];
	cin>>String1>>String2;
	int Flag = 0;
	if (strlen(String1) ==  0) {
		cout<<"yes";
		return 0;
	}
	if (strlen(String2) == 0){
		cout<<"no";
		return 0;
	}
	for (int i = 0; i < strlen(String2) - strlen (String1) + 1; ++i){
		Flag = 0;
		for (int j = 0; j < strlen (String1); ++j) {
			if (*(String1 + j) != *(String2 + i + j)) {
				Flag = 1;
				break;
			}
			
		}
		if (Flag == 0){
			break;
		}
	}
	if (Flag == 1) {
		cout<<"no";
	}
	else {
		cout<<"yes";
	}
	delete [] String1;
	delete [] String2;
	return 0;
}
