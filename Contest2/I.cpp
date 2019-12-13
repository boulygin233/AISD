#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    map <string, string> sinonims;
    int pairsAmount;
    cin>>pairsAmount;
    for (int i = 0; i < pairsAmount; ++i){
        string sin1, sin2;
        cin>>sin1>>sin2;
        sinonims[sin1] = sin2;
        sinonims[sin2] = sin1;
    }
    string word;
    cin>>word;
    cout<<sinonims[word];
}
