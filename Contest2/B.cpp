#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    map <int, int> mutants;
    int mutantsAmount;
    cin>>mutantsAmount;
    for (int i = 0; i < mutantsAmount; ++i){
        int mutant;
        cin>>mutant;
        mutants[mutant]++;
    }
    int requestsAmount;
    cin>>requestsAmount;
    for(int i = 0; i < requestsAmount; ++i){
        int request;
        cin>>request;
        cout<<mutants[request]<<'\n';
    }
}
