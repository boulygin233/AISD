#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class SegmentTree {
private:
    vector<long long> tree;
public:
    explicit SegmentTree(vector<long long> data) {
        tree.resize(4 * data.size());
        build(data, 1, 0, data.size() - 1);
    }

    long long get(long long position, long long current_vertex, long long tree_left, long long tree_right) {
        if (tree_left == tree_right) {
            return tree[current_vertex];
        }
        long long mid = (tree_left + tree_right) / 2;
        if (position <= mid) {
            return tree[current_vertex] + get(position, current_vertex * 2, tree_left, mid);
        } else {
            return tree[current_vertex] + get(position, current_vertex * 2 + 1, mid + 1, tree_right);
        }
    }

    void build(std::vector<long long> &a, long long current_vertex, long long left, long long right) {
        if (left == right) {
            tree[current_vertex] = a[left];
        } else {
            long long mid = (left + right) / 2;
            build(a, current_vertex * 2, left, mid);
            build(a, current_vertex * 2 + 1, mid + 1, right);
        }
    }

    void update(long long current_vertex, long long tree_left, long long tree_right, long long left, long long right,
                long long add) {
        if (left > right) {
            return;
        }
        if (left == tree_left && right == tree_right) {
            tree[current_vertex] += add;
        } else {
            long long middle = (tree_left + tree_right) / 2;
            update(current_vertex * 2, tree_left, middle, left, std::min(right, middle), add);
            update(current_vertex * 2 + 1, middle + 1, tree_right, std::max(left, middle + 1), right, add);
        }
    }
};


int main() {
    long long n;
    std::cin >> n;
    vector<long long> data(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> data[i];
    }
    SegmentTree cur_tree(data);
    int m, left, right, add, position;
    std::cin >> m;
    char request;
    for (int i = 0; i < m; ++i) {
        std::cin >> request;
        if (request == 'g') {
            std::cin >> position;
            std::cout << cur_tree.get(position - 1, 1, 0, n - 1) << '\n';
        }
        if (request == 'a') {
            std::cin >> left >> right >> add;
            cur_tree.update(1, 0, n - 1, left - 1, right - 1, add);
        }
    }
}
