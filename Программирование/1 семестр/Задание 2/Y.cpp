#include<iostream>
using namespace std;
long long max (long long a, long long b){
	return (a > b) ? a : b;
}
int main(){
 	int n;
 	int k;
 	cin>>n>>k;
 	int Floor[n][2];
 	for (int i = 0; i < n; ++i){
 		Floor[i][0] = 0;
 		Floor[i][1] = 0;
	}
	for (int i = 0; i < k; ++i){
		int x;
		int y;
		cin>>x>>y;
		Floor[x - 1][y - 1] = 1;
	}
	for (int i = 0; i < n; ++i){
		cout<<Floor[i][0]<<Floor[i][1];
		cout<<'\n';
	}
	long long End11 = 0;
	long long End12 = 0;
	long long End21 = 0;
	long long End22 = 0;
	long long Count = 1;
	long long f = 1;
	if (Floor[0][0] == 1 && Floor[0][1] == 0){
		End21 = 1;
	}
	if (Floor[0][0] == 0 && Floor[0][1] == 1){
		End12 = 1;
	}
	if (Floor[0][0] == 0 && Floor[0][1] == 0){
		End11 = 1;
		End22 = 1;
		Count = 2;
	}
	if (Floor[0][0] == 1 && Floor[0][1] == 1){
		End22 = 1;
		Count = 0;
	}

	for (int  i = 1; i < n; ++i){
		if (Floor[i][0] == 0 && Floor[i][1] == 0){
			Count = f * (End11 * 5 + End21 * 3 + End12 * 3 + End22 * 2) % 1000000007;
			long long a = (End11 + End12 + End21 + End22) % 1000000007;
			long long b = (End11 + End21) % 1000000007;
			long long c = (End11 + End12) % 1000000007;
			long long d = (2 * End11 + End12 + End21 + End22) % 1000000007;
			End11 = a;
			End12 = b;
			End21 = c;
			End22 = d;
		}
		else if (Floor[i][0] == 1 && Floor[i][1] == 0){
			if (Floor[i - 1][1] == 0){
				Count = f * (End11 * 2 + End21 * 2 + End12 * 1 + End22 * 1) % 1000000007;
				long long a = 0;
				long long b = 0;
				long long c = (End11 + End21 + End22 + End12) % 1000000007;
				long long d = (End11 + End21) % 1000000007;
				End11 = a;
				End12 = b;
				End21 = c;
				End22 = d;
			}
			else{
				f = max(f, Count);
				End12 = 0;
				End11 = 0;
				End22 = 0;
				End21 = 1;
			}
		}
		else if (Floor[i][0] == 0 && Floor[i][1] == 1){
			if(Floor[i - 1][0] == 0){
				Count = f * (End11 * 2 + End21 * 1 + End12 * 2 + End22 * 1) % 1000000007;
				long long a = 0;
				long long b = (End11 + End21 + End22 + End12) % 1000000007;
				long long c = 0;
				long long d = (End11 + End12) % 1000000007;
				End11 = a;
				End12 = b;
				End21 = c;
				End22 = d;
			}
			else{
				f = max(f, Count);
				End21 = 0;
				End22 = 0;
				End11 = 0;
				End12 = 1;
			}
		}
		else if (i < n - 1){
			f = max(f, Count);
			if (Floor[i + 1][0] + Floor[i + 1][1] != 2){
				Count = 1;
			}
			End11 = 0;
			End12 = 0;
			End21 = 0;
			End22 = 1;
		}
	}
	cout<<Count;
 }
