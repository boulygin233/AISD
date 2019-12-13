#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char Password[201];
	cin>>Password;
	char* RealPassword = new char[strlen(Password)];
	int Nom = 0;
	for (int i = 0; i < strlen(Password); ++i){
		if (Password[i] == 35){
			if (Nom != 0){
				--Nom;
			}
		}
		else if (Password[i] == 64){
			if (Nom != 0){
				Nom = 0;

			}
		}
		else {
			*(RealPassword + Nom) = Password[i];
			++Nom;
		}
	}
	for (int i = 0; i < Nom; ++i){
		cout<<*(RealPassword + i);
	}
	delete [] RealPassword;
	return 0;
}
