#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    set<int> intSet;
    int operationAmount;
    cin>>operationAmount;
    char operation;
    char lastOperation = '+';
    int lastNum = 0;
    int mod = 1000000000;
    for (int i = 0; i < operationAmount; ++i){
        cin>>operation;
        int number;
        cin>>number;
        if (operation == '+' && lastOperation == '+'){
            intSet.emplace(number);
            lastNum = 0;
        }
        else if (operation == '+' && lastOperation == '?'){
            intSet.emplace((number + lastNum) % mod);
            lastNum = 0;
        } else if (operation == '?'){
            auto iter1 = intSet.find(number);
            if (iter1 != intSet.end()){
                cout<<*iter1<<'\n';
                lastNum = *iter1;
            }
            else {
                auto iter2 = intSet.upper_bound(number);
                if (iter2 == intSet.end()){
                    cout<<-1<<'\n';
                    lastNum = -1;
                }
                else{
                    cout<<*iter2<<'\n';
                    lastNum = *iter2;
                }
            }
        }
        lastOperation = operation;
    }
}
