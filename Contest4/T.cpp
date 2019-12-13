#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

int pref_func_count(string working_str) {
    int n = working_str.size();
    vector<int> prefix_function(n, 0);
    for (int i = 1; i < n; ++i) {
        int k = prefix_function[i - 1];
        while (k > 0 && working_str[i] != working_str[k]) {
            k = prefix_function[k - 1];
        }
        prefix_function[i] = (working_str[i] == working_str[k]) ? k + 1 : k;
    }

}

int main() {
    int n;
    std::cin >> n;
    vector<int> pref_func(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> pref_func[i];
    }
    if (n == 0){
        return 0;
    }
    string str = "a";
    for (int i = 1; i < n; ++i) {
        if (pref_func[i] != 0) {
            str += str[pref_func[i] - 1];
        } else {
            str += "a";
            vector<int> allowed_symbols(26, 0);
            allowed_symbols[0] = 1;
            int k = pref_func[i - 1];
            while (k > 0) {
                allowed_symbols[str[k] - 97] = 1;
                k = pref_func[k - 1];
            }
            for (int j = 0; j < allowed_symbols.size(); ++j) {
                if (allowed_symbols[j] == 0) {
                    str[str.size() - 1] = (char) (j + 97);
                    break;
                }
            }
        }
    }
    std::cout << str;
}
