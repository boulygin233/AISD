#include <iostream>
#include <string>
#include <list>


using namespace std;

int main() {
    string header;
    getline(cin, header);
    list<char> resultHeader;
    auto currentPosition = resultHeader.begin();
    for (int i = 0; i < header.size(); ++i) {
        if (header[i] == '<') {
            if (currentPosition != resultHeader.begin()) {
                --currentPosition;
            }
        } else if (header[i] == '>') {
            if (currentPosition != resultHeader.end()) {
                ++currentPosition;
            }
        } else if (header[i] == '^') {
            currentPosition = resultHeader.begin();
        } else if (header[i] == '$') {
            currentPosition = resultHeader.end();
        } else if (header[i] == '#') {
            if (currentPosition != resultHeader.end()) {
                auto erasedSymbol = currentPosition;
                --currentPosition;
                resultHeader.erase(erasedSymbol);
                ++currentPosition;
            }
        } else if (header[i] == '@') {
            if (currentPosition != resultHeader.begin()) {
                auto erasedSymbol = currentPosition;
                --erasedSymbol;
                resultHeader.erase(erasedSymbol);
            }
        } else {
            resultHeader.insert(currentPosition, header[i]);
        }
    }
    for (auto symbol: resultHeader) {
        cout << symbol;
    }
}
