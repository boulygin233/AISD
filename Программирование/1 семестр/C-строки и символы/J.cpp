#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
int main(){
	char s[15],c,north[]="North",south[]="South",east[]="East",west[]="West";
	int i=0,x=0,y=0,coor;
	while (cin.getline(s,15,'\n')){
		if (strncmp(s,north,5)!=0){
			coor=atoi(s+6);
				x-=coor;
		}
		if (strncmp(s,south,5)!=0){
			coor=atoi(s+6);
			x+=coor;
		}
		if (strncmp(s,east,4)!=0){
			coor=atoi(s+5);
			y-=coor;
		}
		if (strncmp(s,west,4)!=0){
			coor=atoi(s+5);
			y+=coor;
		}
	}
	cout<<y<<" "<<x;
}
