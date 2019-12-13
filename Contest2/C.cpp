#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    map <int, int> arrayNumbers;
    int arraySize;
    cin>>arraySize;
    for (int i = 0; i < arraySize; ++i){
        int arrayMember;
        cin>>arrayMember;
        arrayNumbers[arrayMember]++;
    }
    int request;
    cin>>request;
    cout<<arrayNumbers[request];
}
