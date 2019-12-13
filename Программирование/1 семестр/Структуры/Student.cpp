#include <iostream>
#include <cstring>
using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

struct Student {
	char name[100];
	char surname[100];
	Date date;
	double av_grade;
};

int main(){
	int n;
	cout<<"Input your number of your students:\n";
	cin>>n;
	Student students[n];
	char s1[] = "name";
	char s2[] = "surname";
	char s3[] = "date";
	char s4[] = "av_grade";
	cout<<"Input datas of students:\n";
	for (int i = 0; i < n; ++i){
		cin>>students[i].name>>students[i].surname>>students[i].date.day>>students[i].date.month>>students[i].date.year>>students[i].av_grade;
	}
	cout<<"Input your number of your quests:\n";
	int k;
	cin>>k;
	char Quest[9];
	int x;
	cout<<"Input your quests";
	for (int i = 0; i < k; ++i){
		cin>>Quest>>x;
		if ((x > n) || (x < 1)){
			cout<<"Sorry, but I haven't student with number "<<x<<", try again.\n";
		}
		else {
			if (strcmp(Quest, s1) == 0) {
				for (int j = 0; j < strlen(students[x - 1].name); ++j){
					cout<<students[x - 1].name[j];
				}
				cout<<'\n';
			}
			else if (strcmp(Quest, s2) == 0) {
				for (int j = 0; j < strlen(students[x - 1].surname); ++j){
					cout<<students[x - 1].surname[j];
				}
				cout<<'\n';
			}
			else if (strcmp(Quest, s3) == 0) {
				cout<<students[x - 1].date.day<<'.'<<students[x - 1].date.month<<'.'<<students[x - 1].date.year<<'\n';
			}
			else if (strcmp(Quest, s4) == 0) {
				cout<<students[x - 1].av_grade<<'\n';
			}
			else{
				cout<<"Sorry, I'm not understand this instruction, try again\n";
			}
		}
	}
}
