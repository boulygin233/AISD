#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

int main() {
    string str;
    std::cin >> str;
    int n = str.length();
    vector<int> prefix_function(n, 0);
    for (int i = 1; i < n; ++i) {
        int k = prefix_function[i - 1];
        while (k > 0 && str[i] != str[k]) {
            k = prefix_function[k - 1];
        }
        prefix_function[i] = (str[i] == str[k]) ? k + 1 : k;

    }
    for (int i : prefix_function) {
        std::cout << i << ' ';
    }
}
