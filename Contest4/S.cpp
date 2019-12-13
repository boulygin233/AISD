#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

int pref_func_count(string working_str){
    int n = working_str.size();
    vector<int>prefix_function(n, 0);
    for (int i = 1; i < n; ++i) {
        int k = prefix_function[i - 1];
        while (k > 0 && working_str[i] != working_str[k]) {
            k = prefix_function[k - 1];
        }
        prefix_function[i] = (working_str[i] == working_str[k]) ? k + 1 : k;
    }
    int pref_func_max = 0;
    for (int i = 0; i < n; ++i){
        pref_func_max = std::max(pref_func_max, prefix_function[i]);
    }
    return pref_func_max;
}

int main() {
    string str;
    std::cin >> str;
    string working_str;
    int counter = 0;
    for (char i : str){
        working_str = i + working_str;
        counter += working_str.size() - pref_func_count(working_str);
    }
    std::cout<<counter;
}
