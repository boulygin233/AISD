#include <iostream>
using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

bool operator > (const Date &d1, const Date &d2){          //переопределение оператора сравнения для типа Date
	if (d1.year > d2.year){
		return 1;
	}
	else if (d1.year < d2.year){
		return 0;
	}
	else if (d1.year == d2.year) {
			if (d1.month > d2.month){
				return 1;
			}
			else if (d1.month < d2.month){
				return 0;
			}
			else if (d1.month == d2.month) {
				if (d1.day > d2.day){
					return 1;
				}
				else {
					return 0;
				}
			}
	}
}


void Sort (Date *dates, int n) {
	int p = 1;
	for (int j = 0; j < n - 1; ++j){
		for(int i = 0; i < n - 1 - j; ++i){
			if (dates[i] > dates[i + 1]){
				swap(dates[i], dates[i + 1]);
				p = 1;
			}
		}
	}
}

int main(){
	int n;
	cin>>n;
	Date dates[n];
	for (int i = 0; i < n; ++i){
		cin>>dates[i].day>>dates[i].month>>dates[i].year;
	}
	Sort(dates, n);
	cout<<'\n';
	for (int i = 0; i < n; ++i){
		cout<<dates[i].day<<'.'<<dates[i].month<<'.'<<dates[i].year<<'\n';
	}
}
