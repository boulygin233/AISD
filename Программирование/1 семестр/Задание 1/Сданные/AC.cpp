#include <iostream>
using namespace std;
int main(){
	int n;
	int m;
	cin>>n>>m;
	char a[n][m];
	for (int i = 0; i < n; ++i){
		cin>>a[i];
	}
	
	int Vertical1 = 0;
	int DVertical1 = 0;
	int Vertical2 = 0;
	int DVertical2 = 0;
	int x1 = 0;
	int x2 = 0;
	for (int i = 0; i < m; ++i){
		if (a[0][i] == '1'){
			if (Vertical1 == 1) {
				x1 = DVertical1;
			}
			++Vertical1;
			DVertical1 = 0;
		}
		else {
			++DVertical1;
		}
		if (a[1][i] == '1'){
			if (Vertical2 == 1) {
				x2 = DVertical2;
			}
			++Vertical2;
			DVertical2 = 0;
		}
		else {
			++DVertical2;
		}
	}
	
	int Gorizontal1 = 0;
	int DGorizontal1 = 0;
	int y1 = 0;
	int Gorizontal2 = 0;
	int DGorizontal2 = 0;
	int y2 = 0;
	for (int i = 0; i < n; ++i){
		if (a[i][0] == '1'){
			if (Gorizontal1 == 1) {
				y1 = DGorizontal1;
			}
			++Gorizontal1;
			DGorizontal1 = 0;
		}
		else {
			++DGorizontal1;
		}
		if (a[i][1] == '1'){
			if (Gorizontal2 == 1) {
				y2 = DGorizontal2;
			}
			++Gorizontal2;
			DGorizontal2 = 0;
		}
		else {
			++DGorizontal2;
		}
	}
	
	int Vertical = 0;
	int DVertical = 0;
	if (Vertical1 == m) {
		Vertical = Vertical2;
		DVertical = x2;
	}
	else {
		Vertical = Vertical1;
		DVertical = x1;
	}
	
	int Gorizontal = 0;
	int DGorizontal = 0;
	if (Gorizontal1 == n) {
		Gorizontal = Gorizontal2;
		DGorizontal = y2;
	}
	else {
		Gorizontal = Gorizontal1;
		DGorizontal = y1;
	}
	if ((m == 1) || (n == 1)){
		cout<<'?';
		return 0;
	}
	if (Vertical == 0) {
		if (Gorizontal == 0 || Gorizontal == 1 || ((Gorizontal > 1) && (DGorizontal >= m))){
			cout<<'?';
			return 0;
		}
		else {
			cout<<"Line";
			return 0;
		}		
	}
	
	if (Gorizontal == 0) {
		if (Vertical == 0 || Vertical == 1 || ((Vertical > 1) && (DVertical >= n))){
			cout<<'?';
			return 0;
		}
		else {
			cout<<"Vertical line";
			return 0;
		}		
	}
	
	if ((Gorizontal > 0) && (Vertical > 0)) {
		cout<<"Square";
		return 0;
	}
}
