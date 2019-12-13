#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;

int main() {
    int n;
    std::cin>>n;
    string str;
    std::cin >> str;
    string working_str = str + "#";
    std::reverse(str.begin(), str.end());
    working_str += str;
    n = working_str.length();
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
    std::reverse(z_func_vect.begin(), z_func_vect.end());
    for (int i = 0; i < str.size(); ++i) {
        std::cout << z_func_vect[i] << ' ';
    }
}
