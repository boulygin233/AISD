#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    map<string, int> dict;
    string word;
    while (cin >> word) {
        dict[word] += 1;
    }
    vector<pair<int, string>> newMap;
    for (auto iter = dict.begin(); iter != dict.end(); ++iter) {
        newMap.push_back({-(*iter).second, (*iter).first});
    }
    sort(newMap.begin(), newMap.end());
    for (auto iter = newMap.begin(); iter != newMap.end(); ++iter){
        cout<<(*iter).second<<'\n';
    }
}
