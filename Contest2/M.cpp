#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    map<string, map<string, long long>> clients;
    string name;
    string product;
    long long amount;
    while (cin>>name){
        cin>>product>>amount;
        clients[name][product] += amount;
    }
    /*int x;
    cin>>x;
    for (int i = 0; i < x; ++i){
        cin>>name>>product>>amount;
        clients[name][product] += amount;
    }*/
    for (auto iter = clients.begin(); iter != clients.end(); ++iter){
        cout<<(*iter).first<<":\n";
        for (auto iter2 = (*iter).second.begin(); iter2 != (*iter).second.end(); ++iter2){
            cout<<(*iter2).first<<' '<<(*iter2).second<<'\n';
        }
    }
}
