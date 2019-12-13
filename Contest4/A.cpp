#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::min;

class sparseTableMin {
private:
    vector<int> logs;
    vector<vector<long long>> table;
public:
    explicit sparseTableMin(const vector<long long> &data) {
        logs = vector<int>(data.size() + 1, 0);
        for (int i = 2; i < data.size() + 1; ++i) {
            logs[i] = logs[i / 2] + 1;
        }
        table = vector<vector<long long>>(logs[data.size()] + 1, vector<long long>(data.size(), 0));
        table[0] = data;
        for (int i = 1; i < table.size(); ++i) {
            for (int j = 0; j + (1 << i) - 1 < table[0].size(); ++j) {
                table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }

    }

    long long getMin(int l, int r) {
        int k = logs[r - l + 1];
        return min(table[k][l], table[k][r - (1 << k) + 1]);
    }
};


int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> basic_data(n);
    cin >> basic_data[0];
    for (int i = 1; i < n; ++i) {
        basic_data[i] = (basic_data[i - 1] * 23 + 21563) % 16714589;
    }
    sparseTableMin cur_sparse(basic_data);
    int u, v;
    cin >> u >> v;
    int ans;
    for (int i = 0; i < m; ++i) {
        if (u <= v) {
            ans = cur_sparse.getMin(u - 1, v - 1);
        } else {
            ans = cur_sparse.getMin(v - 1, u - 1);
        }
        if (i + 1 != m) {
            u = (17 * u + 751 + ans + 2 * (i + 1)) % n + 1;
            v = (13 * v + 593 + ans + 5 * (i + 1)) % n + 1;
        }
    }
    cout << u << ' ' << v << ' ' << ans << '\n';
}
