#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

int main() {
    int maxCashSize;
    cin >> maxCashSize;
    int id;
    list<int> cash;
    unordered_map<int, list<int>::iterator> myMap;
    while (cin >> id) {
        if (myMap.find(id) != myMap.end()) {
            cash.erase(myMap[id]);
            cash.push_front(id);
            myMap[id] = cash.begin();
            cout << 0 << ' ';
            continue;
        }
        if (myMap.size() == maxCashSize) {
            myMap.erase(cash.back());
            cash.pop_back();
        }
        cash.push_front(id);
        myMap[id] = cash.begin();
        cout << 1 << ' ';
    }
}
