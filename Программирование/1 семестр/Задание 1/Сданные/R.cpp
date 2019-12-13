#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char Word1[256];
	char Word2[256];
	cin>>Word1>>Word2;

	if (strlen(Word1) != strlen(Word2)){
		cout<<"NO";
		return 0;
	}
	int Letters1[36];
	int Letters2[36];
	for (int i = 0; i < 36; ++i){
		Letters1[i] = 0;
		Letters2[i] = 0;
	}
	for (int i = 0; i < strlen(Word1); ++i){
		int x = Word1[i];
		if ((x < 58) && (x > 47)){
			++Letters1[x - 48];
		}
		else{
			++Letters1[x - 87];
		}
		x = Word2[i];
		if ((x < 58) && (x > 47)){
			++Letters2[x - 48];
		}
		else{
			++Letters2[x - 87];
		}
	}
	for (int i = 0; i < 36; ++i){
		if (Letters1[i] != Letters2[i]){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}
