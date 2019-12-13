#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct Node {
    int max = 0;
    int count_max = 0;
};

class SegmentTree {
private:
    vector<Node> tree;
public:
    explicit SegmentTree(vector<int> data) {
        tree.resize(4 * data.size());
        build(data, 1, 0, data.size() - 1);
    }

    Node get(int vertex, int tree_left, int tree_right, int left, int right) {
        if (left > right) {
            Node res;
            return res;
        }
        if (left == tree_left && right == tree_right) {
            return tree[vertex];
        }
        int middle = (tree_left + tree_right) / 2;
        Node first = get(vertex * 2, tree_left, middle, left, std::min(right, middle));
        Node second = get(vertex * 2 + 1, middle + 1, tree_right, std::max(left, middle + 1), right);
        if (first.max > second.max) {
            return first;
        } else if (first.max < second.max) {
            return second;
        } else {
            first.count_max += second.count_max;
            return first;
        }
    }

    void build(vector<int> &data, int vertex, int left, int right) {
        if (left == right) {
            tree[vertex].max = data[left];
            tree[vertex].count_max = 1;
        } else {
            int mid = (left + right) / 2;
            build(data, vertex * 2, left, mid);
            build(data, vertex * 2 + 1, mid + 1, right);
            if (tree[2 * vertex].max > tree[2 * vertex + 1].max) {
                tree[vertex] = tree[2 * vertex];
            } else if (tree[2 * vertex].max < tree[2 * vertex + 1].max) {
                tree[vertex] = tree[2 * vertex + 1];
            } else {
                tree[vertex] = tree[2 * vertex];
                tree[vertex].count_max += tree[2 * vertex + 1].count_max;
            }
        }
    }

};

int main() {
    int n;
    std::cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> data[i];
    }
    SegmentTree tree(data);
    int m, left, right;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        std::cin >> left >> right;
        Node result = tree.get(1, 0, n - 1, left - 1, right - 1);
        std::cout << result.max << ' ' << result.count_max << '\n';
    }
}
