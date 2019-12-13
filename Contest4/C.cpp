#include <iostream>
#include <vector>
#include <cmath>

using std::vector;
int ans_to_comp = 1;

int gcd(int first, int second) {
    if (second == 0) {
        return first;
    } else {
        return gcd(second, first % second);
    }
}

class segmentTree {
private:
    vector<int> tree;
    int tree_size;
public:
    explicit segmentTree(vector<int> data) {
        int n = 1 << (int(log2(data.size() - 1)) + 1);
        tree = data;
        tree_size = n * 2;
        tree.resize(tree_size, data[data.size() - 1]);
        for (int i = n; i < tree_size - 1; ++i) {
            tree[i] = tree[i - n];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = gcd(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    int gcd_on_seg(int left, int right) {
        int n = tree.size() / 2;
        int l = left + n - 1;
        int r = right + n - 1;
        int ans = tree[l];
        while (l <= r) {
            if (l & 1) {
                ans = gcd(ans, tree[l]);
            }
            if (!(r & 1)) {
                ans = gcd(ans, tree[r]);
            }
            l = (l + 1) / 2;
            r = (r - 1) / 2;
        }
        return ans;
    }
};

int main() {
    int n;
    std::cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> data[i];
        ans_to_comp *= data[i];
    }
    int left, right;
    int m;
    std::cin >> m;
    segmentTree cur_tree(data);
    for (int i = 0; i < m; ++i) {
        std::cin >> left >> right;
        if (left > right) {
            std::swap(left, right);
        }
        std::cout << cur_tree.gcd_on_seg(left, right) << '\n';
    }
    return 0;
}
