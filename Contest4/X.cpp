#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> Z_function(vector<int> str) {
    vector<int> z_func_vector(str.size());
    z_func_vector[0] = str.size();
    int left = 0;
    int right = 0;
    for (int i = 1; i < str.size(); ++i) {
        if (i <= right) {
            z_func_vector[i] = std::min(right - i + 1, z_func_vector[i - left]);
        }
        while (i + z_func_vector[i] < str.size() && str[z_func_vector[i]] == str[i + z_func_vector[i]]) {
            ++z_func_vector[i];
        }
        if (i + z_func_vector[i] - 1 > right) {
            left = i, right = i + z_func_vector[i] - 1;
        }
    }
    return z_func_vector;
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<int> str(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> str[i];
    }
    vector<int> new_str(2 * str.size() + 1);
    for (int k = 0; k < str.size(); ++k) {
        new_str[k] = str[k];
    }
    std::reverse(str.begin(), str.end());
    new_str[str.size()] = -1;
    for (int i = 1; i < str.size() + 1; ++i) {
        new_str[i + str.size()] = str[i - 1];
    }
    vector<int> z_func_vector = Z_function(new_str);
    vector<int> possible_variants;
    possible_variants.emplace_back(0);
    for (int i = str.size(); i < new_str.size(); ++i) {
        if (z_func_vector[i] % 2 == 0 && z_func_vector[i] + i == new_str.size()) {
            possible_variants.emplace_back(z_func_vector[i] / 2);
        }
    }
    std::sort(possible_variants.begin(), possible_variants.end(), &cmp);
    for (int i : possible_variants) {
        std::cout << n - i << ' ';
    }
}
