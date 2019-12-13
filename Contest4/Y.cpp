#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;

int main() {
    string interesting_word, jacks_word;
    std::cin >> interesting_word >> jacks_word;
    string working_str = interesting_word + "#" + jacks_word;
    int n = working_str.length();
    vector<int> z_func_vect(n, 0);
    z_func_vect[0] = n;
    int left = 0, right = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= right) {
            z_func_vect[i] = std::min(right - i + 1, z_func_vect[i - left]);
        }
        while (i + z_func_vect[i] < n && working_str[z_func_vect[i]] == working_str[i + z_func_vect[i]]) {
            ++z_func_vect[i];
        }
        if (i + z_func_vect[i] - 1 > right) {
            left = i;
            right = i + z_func_vect[i] - 1;
        }
    }
    int current_size = z_func_vect.size();
    int answer_size = 0;
    std::vector<std::string> answer_str;
    for (int i = z_func_vect.size() - 1; i > interesting_word.size(); --i) {
        if (z_func_vect[i] + i >= current_size) {
            std::string current_prefix;
            for (int j = i; j < current_size; ++j) {
                current_prefix += working_str[j];
                answer_size += 1;
            }
            answer_str.push_back(current_prefix);
            current_size -= (current_size - i);
        }
    }
    if (answer_size == jacks_word.size()) {
        std::cout << "No\n";
        for (int i = answer_str.size() - 1; i >= 0; --i) {
            std::cout << answer_str[i] << ' ';
        }
    } else {
        std::cout << "Yes";
    }
}
