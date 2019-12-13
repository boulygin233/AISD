#include <iostream>
#include <set>
#include <string>

using namespace std;

class MedianSet {
private:
    set<int> minSet;
    int median, size;
    set<int> maxSet;
public:
    MedianSet() : minSet(set<int>()), maxSet(set<int>()), size(0) {}

    void add(int value) {
        if (size == 0) {
            median = value;
        } else if (value > median) {
            if (minSet.size() == maxSet.size()) {
                maxSet.insert(value);
            } else {
                minSet.insert(median);
                if (value > *maxSet.begin()) {
                    median = *maxSet.begin();
                    maxSet.erase(maxSet.begin());
                    maxSet.insert(value);
                } else {
                    median = value;
                }
            }
        } else {
            if (minSet.size() + 1 == maxSet.size()) {
                minSet.insert(value);
            } else if (maxSet.size() == 0) {
                maxSet.insert(median);
                median = value;
            } else {
                maxSet.insert(median);
                if (value < *(--minSet.end())) {
                    median = *(--minSet.end());
                    minSet.erase(--minSet.end());
                    minSet.insert(value);
                } else {
                    median = value;
                }
            }
        }
        ++size;
    }

    int min() {
        if (minSet.size() == 0) {
            int result = median;
            --size;
            if (size) {
                median = *maxSet.begin();
                maxSet.erase(maxSet.begin());
            }
            return result;
        } else {
            int result = *minSet.begin();
            minSet.erase(minSet.begin());
            --size;
            if (minSet.size() + 2 == maxSet.size()) {
                minSet.insert(median);
                median = *maxSet.begin();
                maxSet.erase(maxSet.begin());
            }
            return result;
        }
    }

    int max() {
        if (maxSet.size() == 0) {
            int result = median;
            --size;
            return result;
        } else {
            int result = *(--maxSet.end());
            maxSet.erase(--maxSet.end());
            --size;
            if (minSet.size() == maxSet.size() + 1) {
                maxSet.insert(median);
                median = *(--minSet.end());
                minSet.erase(--minSet.end());

            }
            return result;
        }
    }

    int mid() {
        if (size == 1) {
            --size;
            return median;
        } else if (minSet.size() + 1 == maxSet.size()) {
            int res = median;
            median = *maxSet.begin();
            maxSet.erase(maxSet.begin());
            --size;
            return res;
        } else {
            int result = median;
            median = *(--minSet.end());
            minSet.erase(--minSet.end());
            --size;
            return result;
        }
    }
};

int main() {
    int commandsAmount, value;
    cin >> commandsAmount;
    MedianSet mySet;
    string command;
    for (int i = 0; i < commandsAmount; ++i) {
        cin >> command;
        if (command == "add") {
            cin >> value;
            mySet.add(value);
        } else if (command == "min") {
            cout << mySet.min() << '\n';
        } else if (command == "max") {
            cout << mySet.max() << '\n';
        } else if (command == "mid") {
            cout << mySet.mid() << '\n';
        }
    }
}
