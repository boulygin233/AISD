#include <iostream>
#include <vector>

using std::vector;

class sparseTable {
private:
    vector<vector<long long>> table;
    int column_size;
    int string_size;
    vector<long long> logs;
public:
    sparseTable() : column_size(0), string_size(0) {}

    sparseTable(const vector<long long> &basic_vector) {
        string_size = basic_vector.size();
        int k = 0;
        while ((string_size >> k) != 0) {
            ++k;
        }
        column_size = k;
        table = vector<vector<long long>>(string_size, vector<long long>(column_size, (1ll << 62)));
        logs = vector<long long>(string_size, 0);
        for (int i = 0; i < string_size; ++i) {
            table[i][0] = basic_vector[i];
        }
        for (int i = 1; i < string_size; ++i) {
            if (i <= (1ll << logs[i - 1])) {
                logs[i] = logs[i - 1];
            } else {
                logs[i] = logs[i - 1] + 1;
            }
        }
        for (int i = 1; i < column_size; ++i) {
            for (int j = 0; j < string_size - (1 << i) + 1; ++j) {
                long long first = table[j][i - 1];
                long long second = table[j + (1 << (i - 1))][i - 1];
                table[j][i] = std::min(first, second);
            }
        }
    }

    int getMin(int left, int right) {
        int distance = right - left;
        long long first = table[left][logs[distance] - 1];
        long long second = table[right - (1ll<<(logs[distance] - 1)) + 1][logs[distance] - 1];
        return std::min(first, second);
    }
};

/*class segmentTree{
private:
    vector<int>tree;
    int tree_size;

};*/
int main() {
    long long n, m, a, b, result = 0;
    std::cin >> n >> m >> a >> b;
    while (1) {
        vector<long long> cur_mas;
        for (int i = 1; i <= n; ++i) {
            cur_mas.emplace_back((a * i + b) % (1ll << 32));
        }
        vector<std::pair<int, int>> requests;
        sparseTable cur_table(cur_mas);
        for (int i = 1; i < 2 * m; i += 2) {
            int left = ((a * (n + i) + b) % (1ll << 32)) % n;
            int right = ((a * (n + i + 1) + b) % (1ll << 32)) % n;
            result += cur_table.getMin(std::min(left, right), std::max(left, right));
        }
        std::cout<<result<<'\n';
        std::cin >> n >> m >> a >> b;
        result = 0;
        if (n == 0) {
            break;
        }
    }
}
