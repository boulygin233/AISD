#include<iostream>
using namespace std;
int main(){
    int n,x,max;
    cin>>n;
    cin>>x;
    max=x;
    for (int i=0;i<n-1;i++){
        cin>>x;
        if(x>max){
            max=x;
        }
    }
    cout<<max;
}
