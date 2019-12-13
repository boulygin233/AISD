#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char String1[256];
	cin.getline(String1,256,'\n');
	char* String = new char[strlen(String1)];
	int Nom = 0;
	int i = 0;
	while (String1[i] == ' '){
		++i;
	}
	*(String + Nom) = String1[i];
	++i;
	++Nom;
	for (i; i < strlen(String1) - 1; ++i){
		if (String1[i] != ' '){
			*(String + Nom) = String1[i];
			++Nom;
		}
		else if (String1[i + 1] != ' '){
			*(String + Nom) = String1[i];
			++Nom;
		}
	}
	if (String1[strlen(String1) - 1] != ' '){
		*(String + Nom) = String1[strlen(String1) - 1];
		++Nom;
	}
	for (i = 0; i < Nom; ++i){
		cout<<*(String + i);
	}
	cout<<'\n';
	delete [] String;
}
