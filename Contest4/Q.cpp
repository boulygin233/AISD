#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

int main() {
    string str, pattern;
    std::cin >> str >> pattern;
    string working_str = pattern + '#' + str;
    int n = working_str.length();
    vector<int> prefix_function(n, 0);
    for (int i = 1; i < n; ++i) {
        int k = prefix_function[i - 1];
        while (k > 0 && working_str[i] != working_str[k]) {
            k = prefix_function[k - 1];
        }
        prefix_function[i] = (working_str[i] == working_str[k]) ? k + 1 : k;

    }
    for (int i = pattern.size() + 1; i < prefix_function.size(); ++i) {
        if (prefix_function[i] == pattern.size()){
            std::cout<<i - pattern.size() * 2 << '\n';
        }
    }
}
