#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

int main() {
    int n;
    string str, pattern;
    std::cin >> n >> str >> pattern;
    string working_str_1 = str + '#' + pattern + '1' + pattern;
    string working_str_0 = str + '#' + pattern + '0' + pattern;
    n = n * 3 + 2;
    vector<int> prefix_function_1(n, 0);
    vector<int> prefix_function_0(n, 0);
    for (int i = 1; i < n; ++i) {
        int k = prefix_function_1[i - 1];
        while (k > 0 && working_str_1[i] != working_str_1[k]) {
            k = prefix_function_1[k - 1];
        }
        prefix_function_1[i] = (working_str_1[i] == working_str_1[k]) ? k + 1 : k;
    }
    for (int i = 1; i < n; ++i) {
        int k = prefix_function_0[i - 1];
        while (k > 0 && working_str_0[i] != working_str_0[k]) {
            k = prefix_function_0[k - 1];
        }
        prefix_function_0[i] = (working_str_0[i] == working_str_0[k]) ? k + 1 : k;
    }
    int is_1 = 0, is_0 = 0;
    for (int i = pattern.size() + 1; i < n; ++i) {
        if (prefix_function_1[i] == pattern.size()) {
            is_1 = 1;
        }
        if (prefix_function_0[i] == pattern.size()) {
            is_0 = 1;
        }
    }
    if (is_1 == 0 && is_0 == 1) {
        std::cout << "No";
    } else if (is_1 == 1 && is_0 == 0) {
        std::cout << "Yes";
    } else {
        std::cout << "Random";
    }
}
