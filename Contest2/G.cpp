#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    set<string> stringSet;
    char operation;
    cin>>operation;
    while (operation != '#') {
        string newString;
        cin>>newString;
        if (operation == '+') {
            stringSet.emplace(newString);
        }
        if (operation == '-') {
            stringSet.erase(newString);
        }
        if (operation == '?') {
            auto position = stringSet.find(newString);
            if (position != stringSet.end()){
                cout<<"YES\n";
            }
            else {
                cout<<"NO\n";
            }
        }
        cin>>operation;
    }
}
