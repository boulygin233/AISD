#include <string>
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main() {
    stack<pair<int, int>> myQue, myQueOut;
    int commandAmount;
    cin >> commandAmount;
    for (int i = 0; i < commandAmount; ++i) {
        string command;
        cin >> command;
        if (command == "enqueue") {
            int value;
            cin >> value;
            if (myQue.empty()) {
                myQue.push({value, value});
            } else {
                myQue.push({value, min(value, myQue.top().second)});
            }
            cout << "ok" << endl;
        } else if (command == "dequeue") {
            if (myQueOut.empty()) {
                if (myQue.empty()) {
                    cout << "error" << endl;
                } else {
                    int firstValue = myQue.top().first;
                    myQueOut.push({firstValue, firstValue});
                    myQue.pop();
                    while (!myQue.empty()) {
                        firstValue = myQue.top().first;
                        myQueOut.push({firstValue, min(firstValue, myQueOut.top().second)});
                        myQue.pop();
                    }
                    firstValue = myQueOut.top().first;
                    myQueOut.pop();
                    cout << firstValue << endl;
                }
            } else {
                int firstValue = myQueOut.top().first;
                myQueOut.pop();
                cout << firstValue << endl;
            }
        } else if (command == "front") {
            if (myQueOut.empty()) {
                if (myQue.empty()) {
                    cout << "error" << endl;
                } else {
                    int topValue = myQue.top().first;
                    myQueOut.push({topValue, topValue});
                    myQue.pop();
                    while (!myQue.empty()) {
                        topValue = myQue.top().first;
                        myQueOut.push({topValue, min(topValue, myQueOut.top().second)});
                        myQue.pop();
                    }
                    topValue = myQueOut.top().first;
                    cout << topValue << endl;
                }
            } else {
                int firstValue = myQueOut.top().first;
                cout << firstValue << endl;
            }
        } else if (command == "size") {
            cout << myQue.size() + myQueOut.size() << endl;
        } else if (command == "clear") {
            while (!myQue.empty()) {
                myQue.pop();
            }
            while (!myQueOut.empty()) {
                myQueOut.pop();
            }
            cout << "ok" << endl;
        } else if (command == "min") {
            if (myQueOut.empty()) {
                if (myQue.empty()) {
                    cout << "error" << endl;
                } else {
                    int firstValue = myQue.top().first;
                    myQueOut.push({firstValue, firstValue});
                    myQue.pop();
                    while (!myQue.empty()) {
                        firstValue = myQue.top().first;
                        myQueOut.push({firstValue, min(firstValue, myQueOut.top().second)});
                        myQue.pop();
                    }
                    firstValue = myQueOut.top().second;
                    cout << firstValue << endl;
                }
            } else {
                if (myQue.empty()) {
                    int firstValue = myQueOut.top().second;
                    cout << firstValue << endl;
                } else {
                    int firstValue = min(myQueOut.top().second, myQue.top().second);
                    cout << firstValue << endl;
                }
            }
        }
    }
}
