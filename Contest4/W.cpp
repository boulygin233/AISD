#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

vector<int> Z_function(string str){
    vector<int> z_func_vect(str.size(), 0);
    z_func_vect[0] = str.size();
    int left = 0, right = 0;
    for (int i = 1; i < str.size(); ++i) {
        if (i <= right) {
            z_func_vect[i] = std::min(right - i + 1, z_func_vect[i - left]);
        }
        while (i + z_func_vect[i] < str.size() && str[z_func_vect[i]] == str[i + z_func_vect[i]]) {
            ++z_func_vect[i];
        }
        if (i + z_func_vect[i] - 1 > right) {
            left = i;
            right = i + z_func_vect[i] - 1;
        }
    }
    return z_func_vect;
}

int main() {
    string str;
    std::cin >> str;
    vector<int>z_func_vect = Z_function(str);
    for (int i : z_func_vect) {
        std::cout << i << ' ';
    }
}
